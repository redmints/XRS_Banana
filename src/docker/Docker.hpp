/**
 * \class Docker
 *
 * \brief Provide a piece of Docker services
 *
 * This class allows the developer to manipulate
 * Docker services by providing it the basic
 * functionalities of a Docker running service.
 *
 * \author $Author: Mathias HANNA $
 *
 * \version $Revision: 1.0 $
 *
 * \date $Date: 2021/02/20 $
 *
 * Contact: mathias.hanna3@gmail.com
 *
 */

#include <string>
#include "Container.hpp"

class Docker
{
    public:
        /// Returns the list of existing Images
        static std::vector<Image>     list_images();
        /// Returns the list of existing Containers
        static std::vector<Container> list_containers();
};
