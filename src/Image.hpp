#include <string>

class Image
{
    public:
        Image();
        Image(std::string par_id);
        Image(std::string par_repo, std::string par_tag);

        std::string get_id();
        std::string get_repository();
        std::string get_tag();
        int         rm();

    private:
        std::string m_id;
        std::string m_repository;
        std::string m_tag;
};
