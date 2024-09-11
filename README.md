# fractol: Fractal Visualization in 2D
[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://opensource.org/licenses/GPL-3.0)
[![Build Status](https://travis-ci.org/username/fractol.svg?branch=main)](https://travis-ci.org/username/fractol)
The goal of the project was to draw Mandelbrot, Julia and 
Pythagoras tree fractals using 2D programming

## Installation

<!-- start:code block -->
#### Clone this repository
git clone https://github.com/aklimchu/fractol.git

cd fractol

<!-- end:code block -->

## Running the tests

<!-- start:code block -->
### Create the program with Makefile
make

### Run the program to start drawing the fractals
Correct input for mandelbrot: ./fractol mandelbrot

Correct input for julia: ./fractol julia x-value y-value (x and y values should be between -2 and 2)

Correct input for pythagoras: ./fractol pythagoras


Controls:

Use mouse wheel for zooming

Use arrows for moving the view

Use z and x buttons for changing the colors for mandelbrot and julia fractals

Use q button for expanding the pythagoras tree

Use r button for changing the color of the pythagoras tree

Use Esc button or cross in the top right corner for exiting the program

### Clean the object files and library file
make fclean
<!-- end:code block -->

## License
This project is licensed under the GNU GENERAL PUBLIC LICENSE - see the LICENSE.md file for details
