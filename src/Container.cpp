#include "Container.hpp"
#include "Utils.hpp"
#include <string>
using namespace std;


Container::Container(Image par_img)
{
    m_image = Image();
    m_image = par_img;
    string command = "docker run -d -it " + m_image.getId();
    Utils::ret_cmd cont_create = Utils::exec_cmd(command);
    if(cont_create.ret_value == 0)
    {
        cont_create.output_cmd.erase(remove(cont_create.output_cmd.begin(), cont_create.output_cmd.end(), '\n'), cont_create.output_cmd.end());
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
