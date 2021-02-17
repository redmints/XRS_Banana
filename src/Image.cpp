#include "Image.hpp"
#include "Utils.hpp"
#include <string>
using namespace std;

Image::Image()
{
    m_Repository = "null";
    m_Tag = "null";
    m_id = "null";
};

Image::Image(string par_id)
{
    m_id = par_id;
    string command = "docker images --format '{{.ID}}:{{.Repository}}:{{.Tag}}' | grep " + m_id;
    Utils::ret_cmd img_infos = Utils::exec_cmd(command);
    if(img_infos.ret_value == 0)
    {
        vector<string> tmp = Utils::split(img_infos.output_cmd, "\n");
        vector<string> res = Utils::split(tmp[0], ":");
        m_Repository = res[1];
        m_Tag = res[2];
    }
    else
    {
        printf("Error while getting image information\n");
    }
};

Image::Image(string par_repo, string par_tag)
{
    m_Repository = par_repo;
    m_Tag = par_tag;
    string command = "docker pull " + m_Repository + ":" + m_Tag;
    Utils::ret_cmd img_create = Utils::exec_cmd(command);
    if(img_create.ret_value == 0)
    {
        string command = "docker images --filter=reference=" + m_Repository + ":" + m_Tag + " --format '{{.ID}}'";
        Utils::ret_cmd img_infos = Utils::exec_cmd(command);
        if(img_infos.ret_value == 0)
        {
            img_infos.output_cmd.erase(remove(img_infos.output_cmd.begin(), img_infos.output_cmd.end(), '\n'), img_infos.output_cmd.end());
            m_id = img_infos.output_cmd;
        }
        else
        {
            printf("Error while checking IMAGE ID\n");
        }
    }
    else
    {
        printf("Error while pulling image\n");
    }
};

string Image::getId()
{
    return m_id;
};

string Image::getRepository()
{
    return m_Repository;
};

string Image::getTag()
{
    return m_Tag;
};
