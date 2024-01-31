#pragma once
#include <Types.hpp>
#include <Project.hpp>

class Workstation {
    private:
        static Workstation* instance;
        StringView projectName;
        StringView projectPath;
        Workstation() = default;
        /**
         * @brief Set the Project, if not exist a pkg-win project, create a new pkg-win project
         * 
         * @param project path project
         */

        void LoadExistProject(StringView project);

    public:

        void SetProjectName(StringView name);

        void SetProjectPath(StringView path);

        void CreateNewProject();

        static Workstation* getInstance();

        void MainMenu();

        const String& GetProjectPath(); 

};