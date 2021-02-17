#include <string>
#include "Image.hpp"

class Container
{
    public:
        Container(std::string par_id);
        Container(Image par_img);
        int start();
        int stop();
        int exec();
        int rm();

        std::string getId();
        std::string getName();
        Image       getImage();
        bool        getStatus();

    private:
        std::string m_id;
        std::string m_name;
        Image       m_image;
        bool        m_status;
};
