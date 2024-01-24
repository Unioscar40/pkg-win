#pragma once

#include <Types.hpp>

class Project {
    private:
        StringView path;
        StringView projectName;

    
    public:
        Project(StringView projectPath, StringView projectName);

};