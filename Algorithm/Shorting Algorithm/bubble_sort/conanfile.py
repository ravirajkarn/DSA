from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout, CMakeDeps


class pkgRecipe(ConanFile):
    name = "bubble sort"
    version = "0.1"
    package_type = "application"

    # Optional metadata
    license = "non"
    author = "Ravirajkarn ravirajkarn@outlook.com"
    url = "<Package recipe repository url here, for issues about the package>"
    description = "<Description of bubble sort package here>"
    topics = ("Sorting Method", "Bubble Sort")

    # Binary configuration
    settings = "os", "compiler", "build_type", "arch"

    # Sources are located in the same place as this recipe, copy them to the recipe
    exports_sources = "CMakeLists.txt", "src/*"

    def requirements(self):
        self.requires("fmt/8.0.1")

    def layout(self):
        cmake_layout(self)

    def generate(self):
        deps = CMakeDeps(self)
        deps.generate()
        tc = CMakeToolchain(self)
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()