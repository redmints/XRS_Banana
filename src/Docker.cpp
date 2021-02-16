#include "Utils.hpp"
#include "Docker.hpp"
#include <string>
#include <array>
#include <vector>
#include <sstream>

using namespace std;

vector<Image> Docker::listImages()
{
    vector<Image> images;
    string command = "docker images --format '{{.Repository}}:{{.Tag}}'";
    Utils::ret_cmd images_list = Utils::exec_cmd(command);
    if(images_list.ret_value == 0)
    {
        istringstream str(images_list.output_cmd);
        string line;
        while (std::getline(str, line))
        {
            vector<string> res = Utils::split(line, ":");
            if(res[1] != "<none>")
            {
                Image img = Image(res[0], res[1]);
                images.push_back(img);
            }
        }
    }
    else
    {
        printf("Error while listing images\n");
    }
    return images;
};
