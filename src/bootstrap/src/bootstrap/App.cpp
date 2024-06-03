#include "App.h"

App::App(
    const int argc,
    const char **const argv,
    const GetEnv *const config,
    std::istream *const in,
    std::ostream *const out) : ConsoleKernel(argc, argv, config, in, out)
{
}

void App::run()
{
    StartController start(this->config, this->input, this->output);
    start.index();
    layout::show<layout::Exit>(this->output);
}