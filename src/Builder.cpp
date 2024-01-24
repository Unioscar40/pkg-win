#include <Builder.hpp>
#include <iostream>
#include <fstream>

void Builder::CreateCmakeFile() {
    std::ofstream cmakeFile(path/"CMakeLists.txt");
}

void Builder::CreateDirectoryStructure() {
 
    FilesystemPath srcPath = path/"src";
    FilesystemPath includePath = path/"include";

    std::filesystem::copy(std::filesystem::current_path()/"files/genericMain.txt", srcPath/"main.cpp");

    std::cout << "Creando directorios..." << std::endl;
    std::cout << std::filesystem::current_path() << std::endl;

    std::filesystem::create_directories(path);
    std::filesystem::create_directories(srcPath);
    std::filesystem::create_directories(includePath);
}

void Builder::CreateConanFile() {
    std::filesystem::copy(std::filesystem::current_path()/"files/genericConanfile.txt",path/"conanfile.py");
}

Builder::Builder(FilesystemPath path, StringView projectName) {
    this->path = path/projectName;
    this->projectName = projectName;
}

void Builder::SetBuildPath(FilesystemPath path) {
    this->path = path/projectName;
}

void Builder::Build() {
    
    CreateDirectoryStructure();
    CreateCmakeFile();
    CreateConanFile();
}