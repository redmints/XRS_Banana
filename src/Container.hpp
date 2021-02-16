#include <string>
#include "Image.hpp"

class Container
{
    public:
        Container(Image par_img);
        int start();
        int stop();
        int exec();

        std::string getId();
        std::string getName();
        std::string getImage();
        bool        getStatus();

    private:
        std::string m_id;
        std::string m_name;
        Image       m_image;
        bool        m_status;
};
