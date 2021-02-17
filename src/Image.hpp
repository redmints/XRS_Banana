#include <string>

class Image
{
    public:
        Image();
        Image(std::string par_id);
        Image(std::string par_repo, std::string par_tag);

        std::string getId();
        std::string getRepository();
        std::string getTag();
        int rm();

    private:
        std::string m_id;
        std::string m_Repository;
        std::string m_Tag;
};
