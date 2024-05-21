#include "Controller.h"

Controller::Controller(
    const GetEnv *const config,
    std::istream *const input,
    std::ostream *const output) : config(config), input(input), output(output) {}