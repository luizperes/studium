# Contributing to Studium Engine

This contribution guideline may change in the future. I'll make sure to highlight whatever I consider new for some time.

Please read this file fully and carefully, preferably before contributing. For any questions and suggestions, you may also file an issue.

## Bug reporting
You are free to file issues on the repository if you find any bugs.
You can also submit your own patches to the software. That being the case, take a look at the
coding guidelines below.


## Pull requests
You may send your pull requests anytime with hotfixes for anything that I might
not have noticed or anything that could improve this software. However, I would
appreciate if you follow the following coding conventions which I have tailored
to make the code more elegant and more readable. You may also notice that most
of this coding style comes from the Rust language's general coding style:

### Indentation and style

#### Coding
- Always use SPACES instead of tabs, and make the tab stop at FOUR SPACES.
- We use a variant of Kernighan & Ritchie (K&R) style, adapted to C++, for coding blocks in general. This means that, when writing a function or an implementation to a method, always start the curly braces in the next line. Inside of scopes, though, you can optionally start them in front of a statement, but go ahead and start it on a new line if you think it helps with visually identifying where things start.
- Functions and methods should always be `in_snake_case`.
- Classes, Structures, Enumerations (and its values) should always be `InCamelCase`.
- Constant values should always be in `UPPER_CASE`.
- Make use of namespaces every once and a while. Instead of creating a new class for a singleton, prefer declaring its fields in a `.cpp` file and exposing what would be its methods in a nested namespace for that module.
- Studium is divided into namespaces which work as modules: `studium::render`, `studium::input`, and so on. If you think your code fits inside such a module, please declare your class, function or whatever inside of it.
- It is preferable to keep the header files readable, should you need to check again for the existence of a method, class or function. With that said, documentation<sup>[1](#docsnote)</sup> should be properly formatted so it does not hurt the reader's eyes.
- Header files should use the `.hpp` extension instead of `.h`. Let's keep clear what is C and what is C++.
- Also regarding headers, make sure that whatever important functions, methods, enums, structs and classes have a clear name and a clear description of its parameters. Even though external documentation can be generated, no documentation method should be better than reading the header files.
- In `.cpp` files only, when implementing a method or function, make sure you put the modifiers and the return type ABOVE the rest of the function signature.
- Be it in the headers or source files, if the parameter list of a function or method is too long, break it in more than one line, preferably in one line per parameter. Aligning types and parameter names in a column is also good practice.
- In headers, if you have declared a method or function that is NOT IMPORTANT to the end user (e.g. cannot be called by the user, such as a private function for a class, or only exists in the header so it can be called from another namespace), you may omit the names of variables, but you still need to explicitly tell the user that it shouldn't be called directly. If your function does not need to be exported to another namespace, though, consider declaring it inside the module's `.cpp` file so it stays invisible to the end user and doesn't fill up space on header files,


<a id="docsnote">1</a>: I want a better way to document code than Doxygen, so give me a heads up if you know of any.

#### Documentation
This project uses Doxygen for documentation, along with Qt-style documentation comment
blocks. Here are some guidelines to keep the code clean and well-documented.

- Keep the documentation on headers.
- Anything defined on source (`.cpp`) files should not be visible to the end user. Therefore, there is no need to document them.
- As mentioned before, it is ideal to keep the documentation in a Qt style.

Here is an example of a documented class.

```cpp
      //! A class that does something
      class Foo {
      public:
       /*!
        * \brief Brief description for my method.
        *
        * Elaborate description for my method and etc.
        * \param parameter A parameter.
        * \return Whatever it returns.
        * \note A note about the last docs field.
        * \warning A warning.
        * \todo Whatever still needs to be done.
        */
        int my_method(int parameter);
        
        //! Brief description of one line.
        void brief_method();
      };
  ```


### Commit
It is advisable to follow good commit messages practices for this project. You may [read more about thats here](https://chris.beams.io/posts/git-commit/). I'll also use this very same resource and cite what the best practices are:

- Separate subject from body with a blank line
- Limit the subject line to 50 characters
- Capitalize the subject line
- Do not end the subject line with a period
- Use the imperative mood in the subject line
- Wrap the body at 72 characters
- Use the body to explain __what__ and __why__ vs. __how__


# Anything else?

If something is missing or if you have a question, please fill an issue on the repository and I'll gladly provide an answer. If I feel it is very important question, I will make sure the answer is on this file.
