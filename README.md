# fractol: Fractal Visualization in 2D
[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://opensource.org/licenses/GPL-3.0)
Explore Mandelbrot, Julia and Pythagoras tree fractals using 2D programming!

## Preview
![Fractol Preview](link-to-screenshot.png)

## 🚀 Installation

Clone the repository and navigate to the project directory:

git clone https://github.com/aklimchu/fractol.git
cd fractol

## 🛠️ Build the Program

### Use make to create the program:

make

### ✨ Run the Program
To draw the fractals, use the following commands:

Mandelbrot:

./fractol mandelbrot

Julia:

./fractol julia x-value y-value 
(x and y values should be between -2 and 2)

Pythagoras Tree:

```bash
./fractol pythagoras

🎮 Controls

Mouse Wheel: Zoom in/out
Arrow Keys: Move the view

Z / X: Change colors for Mandelbrot and Julia fractals

Q: Expand the Pythagoras tree

R: Change the Pythagoras tree color

Esc: Exit the program

### 🧹 Cleaning Up

To remove object files and libraries:

make fclean

## License

This project is licensed under the GNU GENERAL PUBLIC LICENSE - see the LICENSE.md file for details
