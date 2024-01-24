#pragma once
#include <filesystem>
#include <Types.hpp>


class Builder {
    private:
        FilesystemPath path;
        String projectName;
        void CreateCmakeFile();
        void CreateDirectoryStructure();
        void CreateConanFile();
    
    public:
        Builder() = default;
        Builder(FilesystemPath path,StringView projectName);
        void SetBuildPath(FilesystemPath path);
        void SetProjectName(StringView projectName);
        void Build();

};