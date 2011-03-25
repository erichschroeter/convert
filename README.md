# convert

Contributors:	Erich Schroeter

A collection of simple programs that convert units.

## Description

These apps were intended to get me back into C++, and in particular with
implementing quick command line interfaces. I wanted to write simple apps
that have been sitting in the back of my head for a while, which could
later be used as a library of source code for bigger projects.

## Usage

Examples:

####length
    ./convert-length -h
    ./convert-length 1.0 m in
    ./convert-length 1.0 meter inch

#### temperature
    ./convert-temperature -h
    ./convert-temperature 0.0 c f
    ./convert-temperature 0.0 celsius fahrenheit

## Installation

I developed this project in Linux (Ubuntu 10.04).

### Prerequisites

The following libraries or programs were what I used.

- **libboost-program-options-dev** _(Ubuntu package - Boost version 1.40)_
- **CMake**    _(cmake version 2.8.0)_
- **make**     _(Make 3.81 built for i486-pc-linux-gnu)__
- **g++**      _(gcc version 4.4.3 (Ubuntu 4.4.3-4ubuntu5))_

### To build:

 1. cd /path/to/respective/app
        example:
            cd /usr/src/convert/length
 2. mkdir build
 3. cd build
 4. cmake ..
 5. make
