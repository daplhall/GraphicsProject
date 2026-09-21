# The Graphics Project
This project is a redoing and futhere implementation of a simple terminal based [rasterizer](https://github.com/daplhall/Terminal-Rastrorizer) that i wrote many years ago.
# Goals
1. To have a Software rasterizor that i can use to visualize my future physics projects.
2. To learn about computer graphics.
3. To practice optimiztion.
4. To practice project management.
5. To learn countinous integration.

# Getting started
This projects depends on various external dependecies.

## Requirements
1. CMake
2. GNU Compiler

### Third Party Libaries
Third party libraries are downloaded and used with CMake
1. [SDL3](https://github.com/libsdl-org/SDL)
2. [Googletest](https://github.com/google/googletest)
3. [glfw](https://www.glfw.org/) (Alternative for SDL3 that needs to be supported)

## Building
With presets defined one can build with
```
mkdir build && cd build
cmake --presets <preset>
cmake --build --preset <preset>
```

## Testing
Follow Build section
```
ctest --presets <preset>
```

## Externals
The project assumes that **ATM** that external libraries are located in the `external` folder.
The onces that where previouly listed can be build with cmake in the following way:
```
mkdir build && cd build
cmake -DCMAKE_INSTALL_PREFIX:PATH=../.install .. 
cmake --build . --target install
```
This will install the targets in a ./install folder at the root of that external projects directory. These are targeted in the `cmake/find*.cmake` files which adds them to the project. This allows the project to be isolated and allow the project to not be system dependent.

Note: They are currently hinted, meaning that if you don't do the above but just install them in the system/env, then it should still find them.



# The resources used for this project

## Books
1. Foundations of Game Engine Development
2. Real-time Rendering 4th edition
3. Physically Based Rendering From Theory To Implementation 4th Edition

## Tutorials
1. [SDL and Vulkan](https://github.com/AndreVallestero/sdl-vulkan-tutorial)
2. [Github and Jenkins](https://stackoverflow.com/questions/70989970/how-to-block-the-ability-to-merge-the-feature-branch-into-the-main-branch-when-a)

## Blog posts

### Hash map

1. [Writing a hash map](https://benhoyt.com/writings/hash-table-in-c/)
2. [Technigues for hashmaps](https://sio.mataroa.blog/blog/hashmap-implementation-techniques-for-fun-profit/)



## Fun random stuff
[Making a program smaller](https://www.muppetlabs.com/~breadbox/software/tiny/teensy.html)

# Dev Notes
To List presets do for the various cmake stages
```
cmake --list-presets # for config presets
cmake --build --list-presets # for build presets
ctest --list-presets # for test presets
```