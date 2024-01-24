#include <Project.hpp>
#include <Builder.hpp>

Project::Project(StringView projectPath, StringView projectName) {
    FilesystemPath path(projectPath);
    if(!std::filesystem::is_directory(path)) {
        throw std::invalid_argument{"The path is not a directory"};
    }

    
    Builder builder(FilesystemPath(projectPath), projectName);
    builder.Build();
    
}