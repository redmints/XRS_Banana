
#include <iostream>
#include "docker/Docker.hpp"
#include <vector>
#include "../include/cpp-httplib/httplib.h"

#include "controllers/accueil.hpp"

using namespace std;

void list_containers()
{
    vector<Container> containers = Docker::list_containers();
    for(long unsigned int i = 0; i < containers.size(); i++)
    {
        printf("%s %s\n", containers[i].get_id().c_str(), containers[i].get_name().c_str());
    }
}

void list_images()
{
    vector<Image> images = Docker::list_images();
    for(long unsigned int i = 0; i < images.size(); i++)
    {
        printf("%s %s\n", images[i].get_id().c_str(), images[i].get_repository().c_str());
    }
}

int main(int argc, const char * argv[])
{
    //list_containers();
    //list_images();

    httplib::Server svr;

    svr.Get("/", [](const httplib::Request &req, httplib::Response &res)
    {
        Utils::log("Request from "+req.remote_addr);
        Utils::log("Request from "+to_string(req.remote_port));
        res.set_content(accueil::get(req.params), "text/html");
    });

    svr.Post("/", [](const httplib::Request &req, httplib::Response &res)
    {
        Utils::log("Request from "+req.remote_addr);
        res.set_content(accueil::post(req.params), "text/html");
    });

    auto ret = svr.set_mount_point("/", "./public");
    if(!ret)
    {
        Utils::print_err("Error while mounting public directory");
    }

    svr.listen("127.0.0.1", 8888);

    return 0;
}
