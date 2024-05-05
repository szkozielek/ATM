#include "App.h"

void App::initArgs(){
    colors::useColors = (this->env("USE_COLORS", "true")) == "true";
    menu::useConsoleClear = (this->env("USE_SPACES", "true")) == "true";
}

App::App(const int argc, const char** const argv, std::istream * const in, std::ostream * const out) : ConsoleKernel(argc, argv, in, out){
    this->getenv();
    this->initArgs();
}

void App::run(){
    std::map<std::string, std::string> options = {{"1", "Zaloz konto"}, {"2", "Wyplac pieniadze"}, {"3", "Wplac pieniadze"}, {"q", "Zakoncz prace"}};
    std::string selectedOption = "";
    layout::show<layout::Index>(this->output);
    this->input->get();
    do{
        menu::clearScreen(*this->output);
        *this->output << "Co chcesz dzisiaj zrobic?" << std::endl;
        if(selectedOption != "" && (options.find(selectedOption) == options.end())){
            layout::show<layout::ValidateError>(this->output, "Wybierz element z listy");
        }
        *this->output << std::endl;
        layout::show<layout::Select>(this->output, options);
        *this->input >> selectedOption;
        selectedOption = smartstring::lower(selectedOption);
        if(selectedOption == "1"){
            BankAccountController accountCtrl(this->input, this->output);
            accountCtrl.create();
        }


    }while(selectedOption != "q");

    layout::show<layout::Exit>(this->output);
}