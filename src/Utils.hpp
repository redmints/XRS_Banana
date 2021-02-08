#include <string>

class Utils
{
    public:
        struct ret_cmd
        {
            int ret_value;
            std::string output_cmd;
        };
        static Utils::ret_cmd exec_cmd(std::string cmd);
};
