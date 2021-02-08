#include <iostream>
#include "Utils.hpp"
#include "Container.hpp"

using namespace std;

int main(int argc, const char * argv[])
{
    Container container = Container();
    printf("%s\n", container.getId().c_str());
    return 0;
}
