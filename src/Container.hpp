#include <string>
#include "Utils.hpp"
#include "Image.hpp"

class Container
{
    public:
        Container(std::string par_id);
        Container(Image par_img);
        
        int            start();
        int            stop();
        int            rm();
        Utils::ret_cmd exec(std::string par_cmd);
        bool           get_status();
        std::string    get_id();
        std::string    get_name();
        Image          get_image();

    private:
        std::string m_id;
        std::string m_name;
        Image       m_image;
};
