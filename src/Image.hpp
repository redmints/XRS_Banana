/**
 * \class Image
 *
 * \brief Provide an Image
 *
 * This class allows the developer to manipulate
 * an Image by providing it the basic
 * functionalities of a Docker Image.
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

class Image
{
    public:
        /// Instanciate an Image
        Image();
        /// Instanciate an Image by ID
        Image(std::string par_id);
        /// Instanciate a new Image by Repository name and tag
        Image(std::string par_repo, std::string par_tag);

        /// Returns Image ID
        std::string get_id();
        /// Returns Image Repository
        std::string get_repository();
        /// Returns Image Tag
        std::string get_tag();
        /// Removes Image
        int         rm();

    private:
        std::string m_id; ///< Image ID
        std::string m_repository; ///< Image Repository
        std::string m_tag; ///< Image Tag
};
