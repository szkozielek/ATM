#include <iostream>
#include <FileManager/FileNotFound.h>
#include <bootstrap/Init.h>
#include <bootstrap/App.h>

int main(const int argc, const char **const argv)
{
    GetEnv *env;
    App *myApp;

    // loading environment variables
    env = new GetEnv();

    try
    {
        env->getenv();
    }
    catch (const except::FileNotFound &e)
    {
        std::cerr << e.what() << std::endl;
        delete env;
        return 1;
    }

    init(env); // setting global variables

    myApp = new App(argc, argv, env, &std::cin, &std::cout); // application initialization
    try
    {
        myApp->run(); // launching the application
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        delete env;
        delete myApp;
        return 1;
    }

    // free memory
    delete myApp;
    delete env;

    return 0;
}