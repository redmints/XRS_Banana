#include "accueil.hpp"
#include "../Utils.hpp"

using namespace std;
using namespace inja;
using json = nlohmann::json;

string accueil::get(multimap<string, string> params)
{
    json data;
    data["name"] = "world";
    return Utils::view("index", data);
};

string accueil::post(multimap<string, string> params)
{
    json data;
    data["name"] = "world";

    for(pair<string, string> elem : params)
    {
        printf("%s %s\n", elem.first.c_str(), elem.second.c_str());
    }
    return Utils::view("index", data);
};
