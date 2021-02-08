#include "Container.hpp"
#include "Utils.hpp"
#include <string>
using namespace std;


Container::Container()
{
    string image_id = "debian";
    string command = "docker run -d -it " + image_id;
    Utils::ret_cmd cont_create = Utils::exec_cmd(command);
    if(cont_create.ret_value == 0)
    {
        m_id = cont_create.output_cmd;
    }
    else
    {
        printf("Error while creating container\n");
    }
};

string Container::getId()
{
    return m_id;
};
