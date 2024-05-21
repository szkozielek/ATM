#include "HelloWorld.h"

std::string helloworld::sayHello(const std::string &who = "World")
{
    return "Hello " + who;
}