#include "Utils.hpp"
#include <string>
#include <array>

using namespace std;

Utils::ret_cmd Utils::exec_cmd(string cmd)
{
    Utils::ret_cmd ret_data;
    array<char, 128> buffer;
    string result;

    FILE *pipe = popen(cmd.c_str(), "r");

    if (!pipe) throw std::runtime_error("popen() failed!");

    while (!feof(pipe))
    {
        if (fgets(buffer.data(), 128, pipe) != nullptr)
        {
            result += buffer.data();
        }
    }

    ret_data.ret_value = pclose(pipe);
    ret_data.output_cmd = result;

    return ret_data;
};
