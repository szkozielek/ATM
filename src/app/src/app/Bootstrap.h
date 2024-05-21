#pragma once

#include <GetEnv/GetEnv.h>

#include <Menu/Colors.h>
#include <Menu/Menu.h>

inline void bootstrap(const GetEnv *const config)
{
    colors::useColors = (config->env("USE_COLORS", "true")) == "true";
    menu::useConsoleClear = (config->env("USE_SPACES", "true")) == "true";
}