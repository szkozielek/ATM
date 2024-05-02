#include "HelloWorld.h"

void helloworld::sayHello(std::ostream & out, const std::string & who = "World"){
    out << "Hello " << who << std::endl; 
}