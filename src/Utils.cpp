#include "Utils.hpp"
#include <string>
#include <array>

using namespace std;

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
