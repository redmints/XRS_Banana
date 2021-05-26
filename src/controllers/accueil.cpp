#include "accueil.hpp"
#include "../Utils.hpp"

using namespace std;
using namespace inja;
using namespace httplib;
using json = nlohmann::json;

string accueil::get(const Request* req, Response* res)
{
    json data;
    data["name"] = "world";
    Utils::set_session(res, "banana");
    printf("%s\n", Utils::get_session(req).c_str());
    return Utils::view("index", data);
};

string accueil::post(const Request* req, Response* res)
{
    json data;
    data["name"] = "world";

    for(pair<string, string> elem : req->params)
    {
        printf("%s %s\n", elem.first.c_str(), elem.second.c_str());
    }
    return Utils::view("index", data);
};
