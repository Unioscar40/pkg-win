#include <Workstation.hpp>
#include <Project.hpp>
#include <filesystem>
#include <iostream>

Workstation* Workstation::instance = nullptr;

Workstation* Workstation::getInstance() {
    if(instance == nullptr)
        instance = new Workstation();

    return instance;
}

void Workstation::CreateNewProject(StringView path, StringView projectName) {
    Project project(path,projectName);
} 

void Workstation::MainMenu() {

}