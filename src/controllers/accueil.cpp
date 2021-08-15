#include "accueil.hpp"
#include "../Utils.hpp"
#include "../models/user.hpp"

using namespace std;
using namespace inja;
using namespace httplib;
using json = nlohmann::json;
using namespace sqlite_orm;

string accueil::get(const Request* req, Response* res)
{
    json data;
    data["name"] = "world";

    map<string, string> session;
    session["id"] = "56";
    Utils::set_session(res, session);

    printf("%s\n", Utils::get_session(req, "id").c_str());
    return Utils::view("index", data);
};

string accueil::post(const Request* req, Response* res)
{
    json data;
    data["name"] = "world";

    for(pair<string, string> elem : req->params)
    {
        printf("%s %s\n", elem.first.c_str(), elem.second.c_str());
        //storage.sync_schema();
        //storage.remove_all<User>();

        try {
            storage.insert(User{
                -1,
                33,
                elem.second,
            });
        }
        catch(const std::system_error &e) {
            std::cout << e.what() << std::endl;
        }
    }
    return Utils::view("index", data);
};
