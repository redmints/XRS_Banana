#include "Utils.hpp"
#include <string>
#include <array>
#include <fstream>
#include <ctime>

using namespace std;
using namespace inja;
using namespace httplib;
using json = nlohmann::json;

#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"

Utils::ret_cmd Utils::exec_cmd(string cmd)
{
    Utils::ret_cmd ret_data;
    array<char, 128> buffer;
    string result;

    FILE *pipe = popen(cmd.c_str(), "r");

    if (!pipe) throw std::runtime_error("popen() failed!");

    while (!feof(pipe))
    {
        if (fgets(buffer.data(), 128, pipe) != nullptr)
        {
            result += buffer.data();
        }
    }

    ret_data.ret_value = pclose(pipe);
    ret_data.output_cmd = result.substr(0, result.size()-1);

    return ret_data;
};

vector<string> Utils::split(string str, string delimiter)
{
    vector<string> elements;
    size_t pos = 0;
    std::string token;

    while ((pos = str.find(delimiter)) != std::string::npos)
    {
        token = str.substr(0, pos);
        elements.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    elements.push_back(str);
    return elements;
};

vector<string> Utils::read_file(string path)
{
    vector<string> lines;
    ifstream file(path.c_str());
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            lines.push_back(line);
        }
        file.close();
    }
    else
    {
        print_err("Can't open file");
    }
    return lines;
};

void Utils::log(string msg)
{
    ofstream file("./banana.log", ios_base::app);
    if(file.is_open())
    {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        string to_log = '['+to_string(ltm->tm_hour)+':'+to_string(ltm->tm_min)+':'+to_string(ltm->tm_sec)+"] "+msg+"\n";
        file << to_log.c_str();
        file.close();
    }
    else
    {
        Utils::print_err("Cannot write log");
    }
};

string Utils::view(string name, json data)
{
    Environment env;
    Template temp = env.parse_template("src/views/"+name+".html");
    return env.render(temp, data);
};

void Utils::set_session(Response* res, map<string, string> payload)
{
    auto maker = jwt::create().set_issuer("auth0").set_type("JWS");
    for(auto& element : payload)
    {
        maker.set_payload_claim(element.first, jwt::claim(element.second));
    }
    string token = maker.sign(jwt::algorithm::hs256{"secret"});

    res->set_header("Set-Cookie", token.c_str());
};

string Utils::get_session(const Request* req, string key)
{
    string ret = "";
    if(req->has_header("Cookie"))
    {
        auto verifier = jwt::verify().allow_algorithm(jwt::algorithm::hs256{"secret"}).with_issuer("auth0");
        string token = req->get_header_value("Cookie");
        auto decode = jwt::decode(token);
        verifier.verify(decode);
        if(decode.has_payload_claim(key))
        {
            ret = decode.get_payload_claim(key).as_string();
        }
    }
    return ret;
};

void Utils::print_log(string msg)
{
    printf("%s[DEBUG] %s\n", KYEL, msg.c_str());
};

void Utils::print_ok(string msg)
{
    printf("%s[OK] %s\n", KGRN, msg.c_str());
};

void Utils::print_err(string msg)
{
    printf("%s[ERROR] %s\n", KRED, msg.c_str());
};
