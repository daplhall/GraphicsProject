# The Graphics Project
This project is a redoing and futhere implementation of a simple terminal based [rasterizer](https://github.com/daplhall/Terminal-Rastrorizer) that i wrote many years ago.
## Goals
1. To have a Software rasterizor that i can use to visualize my future physics projects.
2. To learn about computer graphics.
3. To practice optimiztion.
4. To practice project management.
5. To learn countinous integration.
## The resources used for this project

### Books
1. Foundations of Game Engine Development
2. Real-time Rendering 4th edition
3. Physically Based Rendering From Theory To Implementation 4th Edition

### Tutorials
1. [SDL and Vulkan](https://github.com/AndreVallestero/sdl-vulkan-tutorial)
2. [Github and Jenkins](https://stackoverflow.com/questions/70989970/how-to-block-the-ability-to-merge-the-feature-branch-into-the-main-branch-when-a)

### Third Party Libaries
Third party libraries are downloaded and used with CMake
1. [SDL3](https://github.com/libsdl-org/SDL)
2. [Googletest](https://github.com/google/googletest)
3. [glfw](https://www.glfw.org/) (Alternative for SDL3 that needs to be supported)

### Requirements
1. CMake
2. GNU Compiler

# Build
With presets defined one can build with
```
mkdir build && cd build
cmake --presets <preset>
cmake --build --preset <preset>
```


# Tests
Follow Build section
```
ctest --presets <preset>
```

# Listing presets
```
cmake --list-presets # for config presets
cmake --build --list-presets # for build presets
ctest --list-presets # for test presets
```

## Externals
Externals are all saved to the External folder, and then build indivudally with the following steps
```
mkdir build && cd build
cmake -DCMAKE_INSTALL_PREFIX:PATH=../.install .. 
cmake --build . --target install
```
This will install the targets in a ./install folder at the root of that external projects directory.
We will target this with our CMake files 

Benefits, this allows the project to be self contained and we avoid having to build the libraries everytime we clean our own objects.

# Making stuff small
https://www.muppetlabs.com/~breadbox/software/tiny/teensy.html