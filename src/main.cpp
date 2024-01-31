#include <stdio.h>
#include <Workstation.hpp>
#include <iostream>

int main(int argc, char *argv[]) {
    printf("Bienvenido a pkg-win\n");
    Workstation* workstation = Workstation::getInstance();

    try {
        
        std::cout << "----- Welcome to pkg-win ------ " << std::endl;
        std::cout << "Select a option: " << std::endl;

        int option;
        String projectPath;
        String projectName;


        do{
            std::cout << "1-. Create a new pkg-win project. " << std::endl;
            std::cout << "2-. Load an exist project. " << std::endl;
            std::cout << "3-. Exit. " << std::endl;
            std::cin >> option;

            if(option == 1) {
                std::cout << "Select project path: ";
                std::cin >> projectPath;
                workstation->SetProjectPath(projectPath);
                std::cout << "Select project name: ";
                std::cin >> projectName; 
                workstation->SetProjectName(projectName);
                workstation->CreateNewProject();
            }


            if(option != 1 && option != 2 && option != 3)
                std::cout << "This isn't a correct option, please try again: " << std::endl;

        } while(option != 3);


    } catch (std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }
}