#include <Builder.hpp>
#include <iostream>
#include <fstream>
#include <regex>

void Builder::CreateCmakeFile() {
    std::string projectName(this->projectName);
    std::regex pattern("\\{name\\}");
    std::filesystem::path filePath = std::filesystem::current_path()/"files/genericCmakeFile.txt";
    std::filesystem::path tempFilePath = std::filesystem::temp_directory_path() / "temp_file.txt";

    std::ifstream inputFile(filePath);
    if (!inputFile.is_open()) {
        std::cerr << "Unable to open file: " << filePath << std::endl;
        return;
    }

    std::string content((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
    inputFile.close();

    std::ofstream outputFile(tempFilePath);
    if (!outputFile.is_open()) {
        std::cerr << "Unable to open file: " << filePath << std::endl;
        return;
    }
    outputFile << std::regex_replace(content, pattern, projectName);
    outputFile.close();

    std::filesystem::copy(tempFilePath, path/"CMakeLists.txt");

    if (std::filesystem::remove(tempFilePath)) {
        std::cout << "Temporary file " << tempFilePath << " has been removed." << std::endl;
    } else {
        std::cerr << "Failed to remove temporary file " << tempFilePath << "." << std::endl;
    }
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