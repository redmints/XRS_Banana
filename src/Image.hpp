#include <string>

class Image
{
    public:
        Image();
        Image(std::string par_id);

        std::string getId();
        std::string getRepository();
        std::string getTag();

    private:
        std::string m_id;
        std::string m_Repository;
        std::string m_Tag;
};
