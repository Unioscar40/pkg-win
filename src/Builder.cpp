#include <Builder.hpp>
#include <iostream>
#include <fstream>
#include <regex>

void Builder::CreateCmakeFile() {
    std::string projectName(this->projectName);
    std::regex pattern("\\{name\\}");
    FilesystemPath filePath = std::filesystem::current_path() / "files" / "genericCmakeFile.txt";

    std::ifstream inputFile(filePath);
    if (!inputFile.is_open()) {
        std::cerr << "Unable to open file: " << filePath << std::endl;
        return;
    }
    
    std::string fileContent((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
    inputFile.close();
    // Replace all "pattern" matches in fileContent with projectName
    fileContent = std::regex_replace(fileContent, pattern, projectName);

    FilesystemPath cmakeFilePath = path / "CMakeLists.txt";
    std::ofstream outputFile(cmakeFilePath);
    if (!outputFile.is_open()) {
        std::cerr << "Unable to open file: " << cmakeFilePath << std::endl;
        return;
    }

    outputFile << fileContent;
    outputFile.close();

    std::cout << "CMakeLists.txt has been created/updated successfully." << std::endl;
}

void Builder::CreateDirectoryStructure() {
 
    FilesystemPath srcPath = path/"src";
    FilesystemPath includePath = path/"include";


    std::cout << "Creando directorios..." << std::endl;

    std::filesystem::create_directories(path);
    std::filesystem::create_directories(srcPath);
    std::filesystem::create_directories(includePath);
    // TODO: only works if you are in pkg-win folder
    FilesystemPath genericMainPath = std::filesystem::current_path() / "files" / "genericMain.txt";
    FilesystemPath mainCppPath = srcPath / "main.cpp";
    std::filesystem::copy(genericMainPath, mainCppPath); 
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