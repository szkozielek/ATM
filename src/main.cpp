#include <bootstrap/Init.h>
#include <bootstrap/App.h>

int main(const int argc, const char **const argv)
{
    GetEnv *env;
    App *myApp;

    // loading environment variables
    env = new GetEnv();
    env->getenv();

    init(env); // setting global variables

    myApp = new App(argc, argv, env, &std::cin, &std::cout); // application initialization
    myApp->run();                                            // launching the application

    // free memory
    delete myApp;
    delete env;

    return 0;
}