
#include <iostream>
#include "docker/Docker.hpp"
#include <vector>
#include "../include/cpp-httplib/httplib.h"

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

    string content = "";
    vector<string> vec = Utils::read_file("src/views/index.html");
    for(long unsigned int i = 0; i < vec.size(); i++)
    {
        content += vec[i];
    }
    
    svr.Get("/", [&content](const httplib::Request &req, httplib::Response &res)
    {
        Utils::log("Request from "+req.remote_addr);
        res.set_content(content, "text/html");
    });

    svr.listen("127.0.0.1", 8888);

    return 0;
}
