#include "Docker.hpp"
#include <string>
#include <array>
#include <vector>
#include <sstream>

using namespace std;

vector<Image> Docker::list_images()
{
    vector<Image> images;
    string command = "docker images --format '{{.ID}}'";
    Utils::ret_cmd images_list = Utils::exec_cmd(command);
    if(images_list.ret_value == 0)
    {
        vector<string> tmp;
        istringstream str(images_list.output_cmd);
        string line;
        while (std::getline(str, line))
        {
            if(std::find(tmp.begin(), tmp.end(), line) == tmp.end())
            {
                Image img = Image(line);
                images.push_back(img);
                tmp.push_back(line);
            }
        }
    }
    else
    {
        printf("Error while listing images\n");
    }
    return images;
};

vector<Container> Docker::list_containers()
{
    vector<Container> containers;
    string command = "docker ps --format '{{.ID}}'";
    Utils::ret_cmd containers_list = Utils::exec_cmd(command);
    if(containers_list.ret_value == 0)
    {
        istringstream str(containers_list.output_cmd);
        string line;
        while (std::getline(str, line))
        {
            Container container = Container(line);
            containers.push_back(container);
        }
    }
    else
    {
        printf("Error while listing containers\n");
    }
    return containers;
};
