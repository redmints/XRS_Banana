/**
 * \class Container
 *
 * \brief Provide a container
 *
 * This class allows the developer to manipulate
 * a container by providing it the basic
 * functionalities of a Docker container.
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
#include "../Utils.hpp"
#include "Image.hpp"

class Container
{
    public:
        /// Instanciate a Container by ID
        Container(std::string par_id);
        /// Create a new Container by Image
        Container(Image par_img);

        /// Starts the container
        int            start();
        /// Stops the container
        int            stop();
        /// Removes the container
        int            rm();
        /// Executes a bash command on the container
        Utils::ret_cmd exec(std::string par_cmd);
        /// Returns the status container
        bool           get_status();
        /// Returns the ID container
        std::string    get_id();
        /// Returns the name container
        std::string    get_name();
        /// Returns the Image container
        Image          get_image();

    private:
        std::string m_id; ///< Container ID
        std::string m_name; ///< Container name
        Image       m_image; ///< Container Image created with
};
