#include <Builder.hpp>
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

void Builder::CreateCmakeFile() {
    std::filesystem::copy(std::filesystem::current_path()/"files/genericCmakeFile.txt", path/"CMakeLists.txt");
}

void Builder::CreateDirectoryStructure() {
 
    FilesystemPath srcPath = path/"src";
    FilesystemPath includePath = path/"include";


    std::cout << "Creando directorios..." << std::endl;

    std::filesystem::create_directories(path);
    std::filesystem::create_directories(srcPath);
    std::filesystem::create_directories(includePath);

    std::filesystem::copy(std::filesystem::current_path()/"files/genericMain.txt", srcPath/"main.cpp"); 
}

void Builder::CreateConanFile() {
    std::filesystem::copy(std::filesystem::current_path()/"files/genericConanfile.txt",path/"conanfile.py");
}

void Builder::CreateSeedFile() {
    json jsonSeed {{"project_name", projectName}};
    std::ofstream seed(path/"seed.json");

    // Comprobar si el archivo se abrió correctamente
    if (!seed.is_open()) {
        std::cerr << "Can't open a file." << std::endl;
        return;
    }

    // Escribir en el archivo
    seed << jsonSeed;
    seed.close();

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
    CreateSeedFile();
}