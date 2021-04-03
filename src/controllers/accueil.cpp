#include "accueil.hpp"
#include "../Utils.hpp"

using namespace std;

string accueil::get(multimap<string, string> params)
{
    return Utils::view("index");
};

string accueil::post(multimap<string, string> params)
{
    for(pair<string, string> elem : params)
    {
        printf("%s %s\n", elem.first.c_str(), elem.second.c_str());
    }
    return Utils::view("index");
};
