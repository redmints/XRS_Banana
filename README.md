# Banana

### Introduction

Banana is a web framework in C++ based on MVC achitecture.

### Dependencies

First of all, you will have to install :

- g++
- make
- libssl-dev
- doxygen (only if you want to generate documentation)
- pdflatex (only if you want to generate documentation)

### Compilation
----
First, you have to clone the project and submodules :

`$ git clone https://github.com/redmints/XRS_Banana.git`

`$ cd XRS_Banana/`

`$ git submodule init`

`$ git submodule update`

Then, please apply patches to git submodules :

`$ cd include/jwt-cpp`

`$ git apply ../jwt-cpp.patch`

`$ cd ../inja`

`$ git apply ../inja.patch`

Then, if you want to build, please run :

`$ make binary`

Binary is available in out/ directory :

`$ ./out/banana`

You also can generate documentation using :

`$ make docu`

And then, find PDF generated in doc/ directory.
