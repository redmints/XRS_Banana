# Banana

### Introduction

Banana is a web framework in C++ based on MVC achitecture. A docker API is available too in this repo.

Examples of use are in the main.

### Dependencies

First of all, you will have to install :

- g++
- make
- pdflatex (only if you want to generate documentation)

### Compilation
----
First, you have to clone the project and submodules :

`$ git clone https://github.com/redmints/XRS_Banana.git`

`$ cd XRS_Banana/`

`$ git submodule init`

`$ git submodule update`

Then, if you want to build, please run :

`$ make build`

Binary is available in out/ directory :

`$ ./out/banana`

You also can generate documentation using :

`$ make docu`

And then, find PDF generated in doc/ directory.
