#pragma once
#include <Types.hpp>
#include <Project.hpp>

class Workstation {
    private:
        static Workstation* instance;
        String project;
        Workstation() = default;
        /**
         * @brief Set the Project, if not exist a pkg-win project, create a new pkg-win project
         * 
         * @param project path project
         */
        void CreateNewProject(StringView project, StringView projectName);

        void LoadExistProject(StringView project);

    public:

        static Workstation* getInstance();

        void MainMenu();

        const String& GetProjectPath(); 

};