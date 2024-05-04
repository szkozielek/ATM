#include "app/App.h"
#include "app/App.cpp"

int main(int argc, char* argv[]){
    App * myApp;
    myApp = new App(&std::cin, &std::cout);
    myApp->run();
    delete myApp;
    return 0;
}