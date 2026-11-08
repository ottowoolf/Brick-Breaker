#[[------------------------------------------------------------------------------
    This CMakeLists.txt file is used to configure the build process for a C++ project that uses the SFML (Simple and Fast Multimedia Library) library. It specifies the minimum required version of CMake, sets the project name and version, defines the C++ standard to be used, and includes the necessary source files for building the project.
------------------------------------------------------------------------------]]

#[[------------------------------------------------------------------------------
// Specify the minimum required version of CMake. This ensures that the project can be built with a compatible version of CMake.
------------------------------------------------------------------------------]]
cmake_minimum_required(VERSION 3.28)
project (Brick_Breaker CXX) 

#[[------------------------------------------------------------------------------
// FetchContent is a CMake module that allows you to download and include external content in your project.
------------------------------------------------------------------------------]]

include(FetchContent)

#[[------------------------------------------------------------------------------
// Specify the version of SFML you want to use. You can change this to a different version if needed.
------------------------------------------------------------------------------]]

FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.2) 

#[[------------------------------------------------------------------------------
// This command downloads and makes the SFML library available for your project.
------------------------------------------------------------------------------]]
 
FetchContent_MakeAvailable(SFML)

#[[------------------------------------------------------------------------------
// This command collects all the .cpp source files in the "Source" directory and stores their paths in the SOURCES variable. The CONFIGURE_DEPENDS option ensures that CMake re-evaluates the list of source files if any changes occur in the specified directory.
------------------------------------------------------------------------------]]

file(GLOB SOURCES CONFIGURE_DEPENDS Source/*.cpp) 

#[[------------------------------------------------------------------------------
// Create an executable target named "Brick_Breaker" using the source files specified in the SOURCES variable.
------------------------------------------------------------------------------]]

add_executable(Brick_Breaker ${SOURCES})
#[[------------------------------------------------------------------------------
// Add the "Include" directory to the include path for the "Brick_Breaker" target. This allows the compiler to find header files located in the "Include" directory when compiling the source files.
------------------------------------------------------------------------------]]
target_include_directories(Brick_Breaker PRIVATE Include)

#[[------------------------------------------------------------------------------
// This line specifies that the target "Brick_Breaker" requires C++20 features. It ensures that the compiler uses the appropriate standard when compiling the source files.
------------------------------------------------------------------------------]]

target_compile_features(Brick_Breaker PRIVATE cxx_std_20)

#[[------------------------------------------------------------------------------
// This line links the SFML libraries (Graphics and Audio) to the "Brick_Breaker" target. It allows your project to use SFML's graphics and audio functionalities.
------------------------------------------------------------------------------]]

target_link_libraries(Brick_Breaker PRIVATE SFML::Graphics SFML::Audio)
