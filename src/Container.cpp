#include "Container.hpp"
#include "Utils.hpp"
#include <string>
using namespace std;

Container::Container(string par_id)
{
    m_id = par_id;
    string command = "docker ps --format '{{.ID}}:{{.Image}}:{{.Status}}:{{.Names}}' | grep " + m_id;
    Utils::ret_cmd cont_infos = Utils::exec_cmd(command);
    if(cont_infos.ret_value == 0)
    {
        cont_infos.output_cmd.erase(remove(cont_infos.output_cmd.begin(), cont_infos.output_cmd.end(), '\n'), cont_infos.output_cmd.end());
        vector<string> res = Utils::split(cont_infos.output_cmd, ":");
        m_name = res[3];
        m_status = false;

        if(res[2].find("Up") != std::string::npos)
        {
            m_status = true;
        }

        m_image = Image(res[1]);
    }
    else
    {
        printf("Error while getting container information\n");
    }
};

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

string Container::getName()
{
    return m_name;
};

Image Container::getImage()
{
    return m_image;
};

bool Container::getStatus()
{
    return m_status;
};
