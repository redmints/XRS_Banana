#include <iostream>
#include "Utils.hpp"
#include "Docker.hpp"
#include <vector>

using namespace std;

int main(int argc, const char * argv[])
{
    //Image debian = Image("debian", "buster");
    //printf("%s\n", debian.getId().c_str());

    //Container container = Container(debian);
    //printf("%s\n", container.getId().c_str());
    vector<Image> images = Docker::listImages();
    for(int i = 0; i < images.size(); i++)
    {
        printf("%s\n", images[i].getId().c_str());
    }

    return 0;
}
