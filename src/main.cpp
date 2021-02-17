#include <iostream>
#include "Utils.hpp"
#include "Docker.hpp"
#include <vector>

using namespace std;

int main(int argc, const char * argv[])
{
    //Image debian = Image("debian", "buster");
    //printf("%s\n", debian.getId().c_str());

    //Container container = Container("b60b33af9a0d");
    //printf("%s\n", container.getImage().getRepository().c_str());

    vector<Container> containers = Docker::listContainers();
    for(int i = 0; i < containers.size(); i++)
    {
        printf("%s\n", containers[i].getImage().getRepository().c_str());
    }

    return 0;
}
