# Studium Game Engine

> _studium_, n.
> study (mental effort to acquire knowledge or learning).

Studium is a modern engine for building 2D and Pixel Art games in C++.

## About the Project

Studium is a game engine for 2D games, based on everything I've learned so far about game development, while developing other engines.
This engine is being designed to be used by me for a long period of time, be it professionally or for quick sketches.
While this may seem ambitions, I do believe that, if one could take the time needed studying good programming patterns and being extra
careful while building its own game engine, it is possible to build something robust and easy to hack into, if new features are needed.
Though this engine really is supposed to be monolithic, the coding structure and documentation should provide easier means to debug
issues and add new features.

Most of the design, documentation and coding principles applied here remount back to my brief and ongoing experience with the Rust
language, so even though I opted to write this engine in C++, these principles help make the code easy to read by programmers of any
level.

Studium tries to use a modern C++ while still remaining as close as possible to C itself, without breaking coding consistency. That
means trying to avoid an overuse of object-oriented programming and STL, though it is not a forbidden resource to use, since the
game programming industry favors C++ anyway. Despite that, this engine is primarily developed for Linux systems, so that's where it
should be running first. However, other operational systems are not excluded from the equation; favoring cross-platform libraries is
a must.

The exceeding engine features are also supposed to be kept optional on compilation, though it is best if the engine is used at its
full potential.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

The following libraries and software are required to build `studium`:

- OpenGL 3.3 support or higher
- GLFW >= 3.2
- Epoxy >= 1.4.3
- GLM >= 0.9.8

Consult your trusted repositories for the packages for developing software with these libraries.

### Building

Building Studium is pretty much straightforward.

Given that you already have the dependencies installed, you can build it using CMake:

```bash
$ cd path/to/repository
$ mkdir build && cd build
$ cmake ..
$ make
```

This will create a `libstudium.a` file, which is our library, and the `engine_test` binary, which is the general test project.

### Installing

After building the software using the instructions from previous section, just use the following command to install the software.

```bash
$ sudo make install
```

On a Linux distribution, this will install the header files on `/usr/local/include/studium`, and the actual library will be
installed to `/usr/local/lib`.

## Contributing

If you wish to help with the development of this software, please check the [CONTRIBUTING](CONTRIBUTING.md) file for coding and commit
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
This list will be updated as I advance on this project's development.

- Emacs


## Related links

Links to help follow good practices and whatever.

- [Game Programming Patterns](http://gameprogrammingpatterns.com/), an awesome book by Bob Nystrom, which should help influence some design decisions.
- [How to Write a Git Commit Message](https://chris.beams.io/posts/git-commit/) by Chris Beams.
- [Real-Time Collision Detection](https://www.amazon.com/exec/obidos/tg/detail/-/1558607323), Christer Ericson's great book which serves as guideline for this game's collision detection system.
- [Entity Systems are the future of MMOG development](http://t-machine.org/index.php/2007/09/03/entity-systems-are-the-future-of-mmog-development-part-1/), a series of articles by Adam Martin which should inspire the view of entity usage in this engine. Continuation and more very useful links in the end of the blog post.

## Licensing

The code in this project is licensed under MIT license. For more details, check the [LICENSE](LICENSE) file.
