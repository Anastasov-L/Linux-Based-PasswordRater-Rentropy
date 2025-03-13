# Set the minimum required CMake version
cmake_minimum_required(VERSION 3.10)

# Set the project name
project(EntropyCalculator)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)

# Enable AUTOMOC (automatically handle MOC generation for Qt)
set(CMAKE_AUTOMOC ON)

# Find the Qt5 packages, including Widgets and UIC components
find_package(Qt5 REQUIRED COMPONENTS Widgets)

# Add the source files for the project
set(SOURCES
    main.cpp
    mainwindow.cpp
)

# Add the UI files and process them with UIC
set(UI_FILES
    mainwindow.ui
)

# Automatically generate the ui header files from .ui files
qt5_wrap_ui(UI_HEADERS ${UI_FILES})

# Include the directory where the generated ui_mainwindow.h file will be located
include_directories(${CMAKE_CURRENT_BINARY_DIR})

# Add the executable and link the necessary files (sources, generated UI header files)
add_executable(EntropyCalculator ${SOURCES} ${UI_HEADERS})

# Link the Qt5 Widgets library to the executable
target_link_libraries(EntropyCalculator Qt5::Widgets)

# Optionally: If you want to enable Qt's debug symbols, you can specify the following
# set(CMAKE_BUILD_TYPE Debug)


