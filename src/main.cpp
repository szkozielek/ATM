#include <app/Bootstrap.h>
#include <app/App.h>

int main(const int argc, const char **const argv)
{
    GetEnv *env;
    App *myApp;

    // pobieranie zmiennych środowiskowych
    env = new GetEnv();
    env->getenv();

    bootstrap(env); // ustawianie stałych globalnych

    myApp = new App(argc, argv, env, &std::cin, &std::cout); // Inicjacja aplikacji
    myApp->run();                                            // uruchomienie aplikacji

    // zwolnienie pamięci
    delete myApp;
    delete env;

    return 0;
}