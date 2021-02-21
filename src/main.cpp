#include <iostream>
#include "Docker.hpp"
#include <vector>

using namespace std;

void list_containers()
{
    vector<Container> containers = Docker::list_containers();
    for(int i = 0; i < containers.size(); i++)
    {
        printf("%s %s\n", containers[i].get_id().c_str(), containers[i].get_name().c_str());
    }
}

void list_images()
{
    vector<Image> images = Docker::list_images();
    for(int i = 0; i < images.size(); i++)
    {
        printf("%s %s\n", images[i].get_id().c_str(), images[i].get_repository().c_str());
    }
}

int main(int argc, const char * argv[])
{
    list_containers();
    list_images();

    return 0;
}
