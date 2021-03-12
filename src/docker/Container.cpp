#include "Container.hpp"
#include <string>
using namespace std;

Container::Container(string par_id)
{
    this->m_id = par_id;
    string command = "docker ps -a --format '{{.ID}}:{{.Image}}:{{.Status}}:{{.Names}}' | grep " + this->m_id;
    Utils::ret_cmd cont_infos = Utils::exec_cmd(command);
    if(cont_infos.ret_value == 0)
    {
        vector<string> res = Utils::split(cont_infos.output_cmd, ":");
        this->m_name = res[3];
        this->m_image = Image(res[1]);
    }
    else
    {
        Utils::print_err("Error while getting container information");
    }
};

Container::Container(Image par_img)
{
    this->m_image = par_img;
    string command = "docker run -d -it " + this->m_image.get_id();
    Utils::ret_cmd cont_create = Utils::exec_cmd(command);
    if(cont_create.ret_value == 0)
    {
        this->m_id = cont_create.output_cmd;
        string command = "docker ps -a --format '{{.ID}}:{{.Image}}:{{.Status}}:{{.Names}}' | grep " + this->m_id;
        Utils::ret_cmd cont_infos = Utils::exec_cmd(command);
        if(cont_infos.ret_value == 0)
        {
            vector<string> res = Utils::split(cont_infos.output_cmd, ":");
            this->m_name = res[3];
        }
        else
        {
            Utils::print_err("Error while getting container information");
        }
    }
    else
    {
        Utils::print_err("Error while creating container");
    }
};

int Container::start()
{
    string command = "docker start " + this->m_id;
    Utils::ret_cmd ret = Utils::exec_cmd(command);
    if(ret.ret_value == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
};

int Container::stop()
{
    string command = "docker stop " + this->m_id;
    Utils::ret_cmd ret = Utils::exec_cmd(command);
    if(ret.ret_value == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
};

int Container::rm()
{
    if(this->stop() == 0)
    {
        string command = "docker rm " + this->m_id;
        Utils::ret_cmd ret = Utils::exec_cmd(command);
        if(ret.ret_value == 0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 1;
    }
};

Utils::ret_cmd Container::exec(string par_cmd)
{
    string command = "docker exec " + this->m_id + " bash -c " + par_cmd;
    return Utils::exec_cmd(command);
};

bool Container::get_status()
{
    bool status = false;
    string command = "docker ps -a --format '{{.Status}}' | grep " + this->m_id;
    Utils::ret_cmd cont_infos = Utils::exec_cmd(command);
    if(cont_infos.ret_value == 0)
    {
        if(cont_infos.output_cmd.find("Up") != std::string::npos)
        {
            status = true;
        }
    }
    else
    {
        Utils::print_err("Error while getting container information");
    }
    return status;
};

string Container::get_id()
{
    return this->m_id;
};

string Container::get_name()
{
    return this->m_name;
};

Image Container::get_image()
{
    return this->m_image;
};
