#include <string>

class Container
{
    public:
        Container();
        Container(std::string par_id);
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
        std::string m_image;
        bool        m_status;
};
