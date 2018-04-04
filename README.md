# Studium Game Engine

> _studium_, n.
> study (mental effort to acquire knowledge or learning).

Studium is a modern engine for building 2D and Pixel Art games in C++.

## About the Project

Studium is a game engine for 2D games, based on everything I've learned so far about game development while developing using other engines.
This engine has been designed to be used by me for a long time, that being professionally or for quick sketches.
While this may seem ambitious, I do believe that, if one could take the time needed studying good programming patterns and being extra
careful while building their own game engine, it is possible to build something robust and easy to hack into, in case new features are needed.
Though this engine really is supposed to be monolithic, the coding structure and documentation should provide better means to debug
issues and add new features.

Most of the design, documentation and coding principles applied here remount back to my brief and ongoing experience with the Rust
language, so even though I opted to write this engine in C++, I believe that the Rust principles help make the code easier to read by programmers of
different levels.

Studium tries to use modern C++ while still remaining as close as possible to C itself, without breaking coding consistency. That
means trying to avoid an overuse of object-oriented programming and STL, though they are not forbidden resources to use, since the
game programming industry favors C++ anyways. Despite that, this engine is primarily developed for Linux systems, so that's where it
should be running first. However, other operational systems are not excluded from the equation; favoring cross-platform libraries is
a must.

The exceeding engine features are also supposed to be kept optional on compilation, however, the best is that the engine is used at its
full potential.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

The following libraries and software are required to build `studium`:

- OpenGL 3.3 support or higher
- GLFW >= 3.2
- Epoxy >= 1.4.3
- GLM >= 0.9.8

The following libraries are optional, but recommended, to build `studium`:

- ChickenScheme >= 4.12

Consult your trusted repositories for the packages for developing software with these libraries.

### Building

given that you already have the dependencies installed, Building Studium is very straightforward. You may build it by using CMake:

```bash
$ cd path/to/repository
$ mkdir build && cd build
$ cmake ..
$ make
```

This will create a `libstudium.a` file, which is our library, and a `engine_test` binary file, which is the general test project.

#### Using Emacs

This project has an out-of-the-box support for [`cmake-ide`](https://github.com/atilaneves/cmake-ide) on Emacs. Simply open any
code file on any subdirectory, and the `.dir-locals.el` will set the `cmake-ide` variables for you (this process may result on
Emacs specifically asking you if you really want to run unsafe code, since the bindings rely on the usage of the `eval` form).
Once it is done, you can run them build commands directly from Emacs:

```
M-x cmake-ide-run-cmake
M-x cmake-ide-compile
```

This will create a `*compilation*` buffer in which you may be able to look at the actual compilation process.

### Installing

After building the software using the instructions from previous section, use the following command to install the software:

```bash
$ sudo make install
```

On a Linux distribution, this will install the header files on `/usr/local/include/studium`, and the actual library will be
installed to `/usr/local/lib`.

## Contributing

If you wish to help with the development of this software, please check the [CONTRIBUTING](CONTRIBUTING.md) file for coding and committing
guidelines.

You can also refer to the [ongoing projects page](https://github.com/luksamuk/studium/projects) of this repository, so you can more
easily look out for what to contribute with.

### Documentation

To properly document any code you might write to contribute with this project, please check the [CONTRIBUTING](CONTRIBUTING.md)
file also.

### Testing

This project still lacks a proper way to perform unit tests. Once it is added, this section will be updated.

## Recommended Tools 

Below is a list of suggested software to work with this project. Most of them are used by me on a daily basis.
This list will be updated as I advance on the development of this project.

- Emacs


## Related links

Links to help follow good practices and whatever.

- [Game Programming Patterns](http://gameprogrammingpatterns.com/), an awesome book by Bob Nystrom, which should help influence some design decisions.
- [How to Write a Git Commit Message](https://chris.beams.io/posts/git-commit/) by Chris Beams.
- [Real-Time Collision Detection](https://www.amazon.com/exec/obidos/tg/detail/-/1558607323), Christer Ericson's great book which serves as guideline for this game's collision detection system.
- [Entity Systems are the future of MMOG development](http://t-machine.org/index.php/2007/09/03/entity-systems-are-the-future-of-mmog-development-part-1/), a series of articles by Adam Martin which should inspire the view of entity usage in this engine. Continuation and more very useful links in the end of the blog post.

## Licensing

The code in this project is licensed under MIT license. For more details, check out the [LICENSE](LICENSE) file.
