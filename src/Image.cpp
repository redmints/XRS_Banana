#include "Image.hpp"
#include "Utils.hpp"
#include <string>
using namespace std;

Image::Image()
{
    this->m_repository = "";
    this->m_tag = "";
    this->m_id = "";
};

Image::Image(string par_id)
{
    this->m_id = par_id;
    string command = "docker images --format '{{.ID}}:{{.Repository}}:{{.Tag}}' | grep " + this->m_id;
    Utils::ret_cmd img_infos = Utils::exec_cmd(command);
    if(img_infos.ret_value == 0)
    {
        vector<string> tmp = Utils::split(img_infos.output_cmd, "\n");
        vector<string> res = Utils::split(tmp[0], ":");
        this->m_repository = res[1];
        this->m_tag = res[2];
    }
    else
    {
        Utils::print_err("Error while getting image information");
    }
};

Image::Image(string par_repo, string par_tag)
{
    this->m_repository = par_repo;
    this->m_tag = par_tag;
    string command = "docker pull " + this->m_repository + ":" + this->m_tag;
    Utils::ret_cmd img_create = Utils::exec_cmd(command);
    if(img_create.ret_value == 0)
    {
        string command = "docker images --filter=reference=" + this->m_repository + ":" + this->m_tag + " --format '{{.ID}}'";
        Utils::ret_cmd img_infos = Utils::exec_cmd(command);
        if(img_infos.ret_value == 0)
        {
            this->m_id = img_infos.output_cmd;
        }
        else
        {
            Utils::print_err("Error while checking IMAGE ID");
        }
    }
    else
    {
        Utils::print_err("Error while pulling image");
    }
};

int Image::rm()
{
    string command = "docker image rm -f " + this->m_id;
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

string Image::get_id()
{
    return this->m_id;
};

string Image::get_repository()
{
    return this->m_repository;
};

string Image::get_tag()
{
    return this->m_tag;
};
