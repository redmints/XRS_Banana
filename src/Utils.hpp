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
#include "../include/inja.hpp"

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
        /// Read given file line by line
        static std::vector<std::string> read_file(std::string path);
        /// Compute view using given variables
        static std::string              view(std::string name, nlohmann::json data);
        /// Send log message
        static void                     log(std::string msg);
        /// Prints log debug message
        static void                     print_log(std::string msg);
        /// Prints success message
        static void                     print_ok(std::string msg);
        /// Prints error message
        static void                     print_err(std::string msg);
};
