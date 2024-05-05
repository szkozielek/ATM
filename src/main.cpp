#include "app/App.h"
#include "app/App.cpp"

int main(const int argc, const char** const argv){
    App * myApp;
    myApp = new App(argc, argv, &std::cin, &std::cout);
    myApp->run();
    delete myApp;
    return 0;
}