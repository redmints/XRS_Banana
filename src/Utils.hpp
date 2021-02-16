#include <string>
#include <vector>

class Utils
{
    public:
        struct ret_cmd
        {
            int ret_value;
            std::string output_cmd;
        };
        static Utils::ret_cmd exec_cmd(std::string cmd);
        static std::vector<std::string> split(std::string str, std::string delimiter);
};
