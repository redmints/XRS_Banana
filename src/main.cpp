
#include <iostream>
#include "../include/cpp-httplib/httplib.h"
#include "Utils.hpp"

#include "controllers/accueil.hpp"

using namespace std;

int main(int argc, const char * argv[])
{
    httplib::Server svr;

    svr.Get("/", [](const httplib::Request &req, httplib::Response &res)
    {
        Utils::log("Request from "+req.remote_addr);
        Utils::log("Request from "+to_string(req.remote_port));
        res.set_content(accueil::get(&req, &res), "text/html");
    });

    svr.Post("/", [](const httplib::Request &req, httplib::Response &res)
    {
        Utils::log("Request from "+req.remote_addr);
        res.set_content(accueil::post(&req, &res), "text/html");
    });

    auto ret = svr.set_mount_point("/", "./public");
    if(!ret)
    {
        Utils::print_err("Error while mounting public directory");
    }

    svr.listen("127.0.0.1", 8888);

    return 0;
}
