/**
 * \class Utils
 *
 * \brief Provide usefull features
 *
 * This class provides usefull features
 * by static methods. They are independant
 * from a specific feature and can be used
 * by any classes
 *
 * \author $Author: Mathias HANNA $
 *
 * \version $Revision: 1.0 $
 *
 * \date $Date: 2021/02/20 $
 *
 * Contact: mathias.hanna3@gmail.com
 *
 */

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

        /// Executes shell command on running machine
        static Utils::ret_cmd           exec_cmd(std::string cmd);
        /// Splits a string by delimiter
        static std::vector<std::string> split(std::string str, std::string delimiter);
        /// Prints log debug message
        static void                     print_log(std::string msg);
        /// Prints success message
        static void                     print_ok(std::string msg);
        /// Prints error message
        static void                     print_err(std::string msg);
};
