from conan import ConanFile

from os import path

class CompressorRecipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps"

    def requirements(self):
        self.requires("nlohmann_json/3.11.3")

    def build_requirements(self):
        self.tool_requires("cmake/3.22.6")

    def layout(self):
        self.folders.generators = path.join("build","generators")
        self.folders.build = "build"