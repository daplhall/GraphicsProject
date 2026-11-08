# The Graphics Project
The endgoal of this project is to redo and futhere implementation of a simple terminal based [rasterizer](https://github.com/daplhall/Terminal-Rastrorizer) that i wrote many years ago.

It is also used to learn a lot of new design practices, and in general writing a larger C language project.

It will likely also pivot into a computer simulation project before the graphics stuff.

# Table of Contents
1. [State of project](#state-of-project)
2. [Goals](#goals)
3. [Getting started](#getting-started)
4. [Development](#development)
    - [Learning Resources](#learning-resources)
    - [Script Ideas](#ideas-for-helper-programs)
    - [Helper scripts](#helper-scripts)

# State of project
currently i am building the framework/tools for the project:

1. [x] Arena allocators - The base allocator for the entire project _(will be expaned as needed)_
2. [ ] Config module - Config files and stuff
3. [ ] Logging Module - Logging
4. [ ] Python embedding - This could be a fun one _(Not sure, would be fun though)_
5. [ ] CLI interface - Parser for easy creating CLI _(Not sure, but would be so much fun)_

# Goals
1. To have a Software rasterizor that i can use to visualize my future physics projects.
2. To learn about computer graphics.
3. To practice optimiztion.
4. To practice project management.
5. To learn countinous integration.

# Getting started
This projects depends on various external dependecies.

## Requirements
Currently the project need the following
1. CMake
2. GNU Compiler (gcc)

### Third Party Libaries
Third party libraries are downloaded and used with CMake
1. [SDL3](https://github.com/libsdl-org/SDL)
2. [Googletest](https://github.com/google/googletest)
3. [glfw](https://www.glfw.org/) (Alternative for SDL3 that needs to be supported)

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

# Development
The repo is hosted [here](https://github.com/daplhall/GraphicsProject)

I have a home CI/CD setup, which can be found [here](https://github.com/daplhall/jenkins-playground-cicd). Should have SonarCube community & CI/CD base env.

## Helper Scripts
This project contains a few helper scripts that makes some small things faster and more frictionless.

Current scripts are 

- `cit`
- `vroom`

To initialize the scripts you just have to
```
source scripts/init.sh
```
### Using Cit
`cit` is just a script that calls other scripts, there are currently 2 modes

- `module` or `m` - helps create new folders in `include`, `src` and `test`
- `header` or `h` - creates a header file in a given module

All modes can be seen with just invoking `cit`

so if you want to create a new `module` and a new assosiated `header` you do
```bash
cit m add <module name>
cit h <module name> <header name>.<extension>
```

### Using Vroom
`vroom` is a script that runs `cmake` config, build and then `ctest`. If no inputs
it will just run release. You can specify the build type with
```bash
vroom <build type>
```

## Documentation
- Plantuml (for C4)
- Sphinx? (HTML pages for APIs)

### TODO
- [ ] By a PC with a GPU (not relevant until)
    - [ ] implement CI with GPU features

## Learning Resources

### Books
1. Foundations of Game Engine Development - Coulkd be interesting to see if i can use some technegues in the engine for computer simulations

### Graphics stuff
#### Books
1. Real-time Rendering 4th edition
2. Physically Based Rendering From Theory To Implementation 4th Edition

#### Tutorials

1. [SDL and Vulkan](https://github.com/AndreVallestero/sdl-vulkan-tutorial)
2. [Github and Jenkins](https://stackoverflow.com/questions/70989970/how-to-block-the-ability-to-merge-the-feature-branch-into-the-main-branch-when-a)

### Hash maps
1. [Writing a hash map](https://benhoyt.com/writings/hash-table-in-c/)
2. [Technigues for hashmaps](https://sio.mataroa.blog/blog/hashmap-implementation-techniques-for-fun-profit/)
3. [Wikipedia](https://en.wikipedia.org/wiki/Hash_table)
4. [Wikipedia 2](https://en.wikipedia.org/wiki/Associative_array)

### Arenas
1. [Blog post about arenas](https://www.bytesbeneath.com/p/the-arena-custom-memory-allocators)
2. [Blog](https://www.bytesbeneath.com/p/the-arena-custom-memory-allocators)
3. [Ryans blog](https://www.bytesbeneath./p/the-arena-custom-memory-allocators)
4. [A Good blog](https://www.williamfedele.com/blog/arena-allocators)
5. [Blog from odin lead](https://www.gingerbill.org/series/memory-allocation-strategies/)
6. [Ryans Talk](https://www.youtube.com/watch?v=TZ5a3gCCZYo)

### Thinking in C
1. [The Lost art of structure packing](http://www.catb.org/esr/structure-packing/)
2. [Tips for writing C](https://zackoverflow.dev/writing/how-to-actually-write-c/#grouping-allocations)

### Data orientated design
- [ ] [CppCon 2014](https://www.youtube.com/watch?v=rX0ItVEVjHc)
- [ ] [Andrew kelley talk](https://www.youtube.com/watch?v=rX0ItVEVjHc)

### Memory
1. [What every programmer should know about programming](https://people.freebsd.org/~lstewart/articles/cpumemory.pdf) - From HPPC course

### SOLID Principles
- [Test driven development in embedded C](https://pragprog.com/titles/jgade/test-driven-development-for-embedded-c/) - Has a section of SOLID principles related to TDD and execution in C, over a great book 
- [Solid Relevance](https://blog.cleancoder.com/uncle-bob/2020/10/18/Solid-Relevance.html) - Robert C Martins (uncle bob) blog, lot of good stuff here.
- [Webpage with examples of each principle](https://www.lowleveldesignmastery.com/blog/solid-principles/)

### Fun technical details
- [Making a program smaller](https://www.muppetlabs.com/~breadbox/software/tiny/teensy.html)
- [A Good numerical analysis book](https://blog.cleancoder.com/uncle-bob/2020/10/18/Solid-Relevance.html) - From NUME, need to remeber it


## Things i tend to forget
To List presets do for the various cmake stages
```
cmake --list-presets # for config presets
cmake --build --list-presets # for build presets
ctest --list-presets # for test presets
```

## Ideas for helper programs
- As this program is modular, it could be fun if i could write a script that allows me to write `extract-lib . mem`
    
    Then i get the source code extracted out in correct structure

    - Src
    - Tests
    - Mocks
    - ...

    and maybe even the CMakeFile for it
    
- Script as above that copies a module

- Script as above to rename

# Useful Micro Patterns for C
C Systems Engineering Micro-Patterns

1. Opaque Pointers (Pimpl / Abstract Data Types)
2. Intrusive Linked Lists
3. Flexible Array Members (FAM)
4. Upcasting via Struct Embedding (Pseudo-Inheritance)
5. X-Macros (Code-Gen / Single-Source of Truth)
6. Arena / Region-Based Memory Allocation
7. Compile-Time Assertions (_Static_assert)
8. Bitmask Enums & Bitfields (Compact State Flags)
9. Function Pointer Vtables (C-Style Polymorphism)
10. Container-Of Macro (Pointer Arithmetic Upcasting)
11. Designated Initializers for Interface Drivers
12. Tagged Unions / Variant Types
13. String Views (Pointer + Length Structs)
14. Handle-Based Lookups (ID Indices instead of Raw Pointers)
15. Do-While(0) Macro Block Scoping
16. Static Sentinel Nodes (Branchless Data Structures)
17. Copy-On-Write (COW) Data References
18. Pool Allocators (Fixed-Size Block Management)

# Structure
src -- buisness logic  
modules -- generic code that can be copied to other projects

# TODO
rename foundations to cotainer_of and intrusivelist to intrusive_list
