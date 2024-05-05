#include "App.h"

void App::initArgs(){
    colors::useColors = (this->env("USE_COLORS", "true")) == "true" ;
    menu::useConsoleClear = (this->env("USE_SPACES", "true")) == "true";
}

App::App(std::istream * in, std::ostream * out) : ConsoleKernel(0, nullptr, in, out){
    this->getenv();
    this->initArgs();
}

void App::run(){
    layout::Index idx(this->output);
    layout::Exit ext(this->output);
    std::map<std::string, std::string> options = {{"1", "Zaloz konto"}, {"2", "Wyplac pieniadze"}, {"3", "Wplac pieniadze"}, {"q", "Zakoncz prace"}};
    layout::Select sel(this->output, options);
    std::string selectedOption = "";
    idx.show();
    this->input->get();
    while(true){
        menu::clearScreen(*this->output);
        *this->output << "Co chcesz dzisiaj zrobic?" << std::endl;
        if(selectedOption != ""){
            *this->output << colors::red << "* Wybierz element z listy" << colors::white << std::endl;
        }
        *this->output << std::endl;
        sel.show();
        *this->input >> selectedOption;
        
        if(selectedOption == "q"){
            break;
        }
    }

    ext.show();
}