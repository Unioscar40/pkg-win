#include <stdio.h>
#include <Workstation.hpp>
#include <iostream>

void mainMenu(const Workstation *workstation) {

    try{

    }

}

int main(int argc, char *argv[]) {
    printf("Bienvenido a pkg-win\n");
    Workstation* workstation = Workstation::getInstance();

    mainMenu(workstation);

    try {
        workstation->MainMenu();
    } catch (std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }
}