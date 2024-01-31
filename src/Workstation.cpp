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

void Workstation::SetProjectName(StringView name) {
    projectName = name;
}

void Workstation::SetProjectPath(StringView path) {
    projectPath = path;
}

void Workstation::CreateNewProject() {
    Project project(projectPath,projectName);
} 

