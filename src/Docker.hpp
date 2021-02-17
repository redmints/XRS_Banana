#include <string>
#include "Container.hpp"

class Docker
{
    public:
        static std::vector<Image>     list_images();
        static std::vector<Container> list_containers();
};
