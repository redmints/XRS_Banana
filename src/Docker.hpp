#include <string>
#include "Container.hpp"

class Docker
{
    public:
        static std::vector<Image> listImages();
        static std::vector<Container> listContainers();
};
