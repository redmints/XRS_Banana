#include <string>
#include <vector>
#include <string>
#include <map>
#include "../../include/inja.hpp"
#include "../../include/cpp-httplib/httplib.h"

class accueil
{
    public:
        static std::string get(const httplib::Request* req, httplib::Response* res);
        static std::string post(const httplib::Request* req, httplib::Response* res);
};
