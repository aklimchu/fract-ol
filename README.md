# fractol: Fractal Visualization in 2D
[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://opensource.org/licenses/GPL-3.0)
Explore Mandelbrot, Julia and Pythagoras tree fractals using 2D programming!

## Preview
![Fractol Preview](link-to-screenshot.png)

## 🚀 Installation

Clone the repository and navigate to the project directory:
```bash
git clone https://github.com/aklimchu/fractol.git
cd fractol
```
## 🛠️ Build the Program

### Use `make` command to create the program:
```bash
make
```
## 🎮 Running the Program

* #### Mandelbrot:
```bash
./fractol mandelbrot
```
* #### Julia:
```bash
./fractol julia x-value y-value
```
*(x and y values should be between -2 and 2)*

* #### Pythagoras Tree:
```bash
./fractol pythagoras
```

🎮 Controls

* <big> Mouse Wheel:</big> <small> Zoom in/out </small>
* <big> Arrow Keys: <small> Move the view
* <big> Z / X: <small> Change colors for Mandelbrot and Julia fractals
* <big> Q: <small> Expand the Pythagoras tree
* <big> R: <small> Change the Pythagoras tree color
* <big> Esc: <small> Exit the program

## 🧹 Cleaning Up

To remove object files and libraries:
```bash
make fclean
```
## License

This project is licensed under the GNU GENERAL PUBLIC LICENSE - see the LICENSE.md file for details
