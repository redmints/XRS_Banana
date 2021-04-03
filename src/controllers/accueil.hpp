#include <string>
#include <vector>
#include <string>
#include <map>

class accueil
{
    public:
        static std::string get(std::multimap<std::string, std::string> params);
        static std::string post(std::multimap<std::string, std::string> params);
};
