# Fractol

This is my first graphical project. It introduces window management, event handling, images and colours.  
The point of the project is to display [fractals](https://en.wikipedia.org/wiki/Fractal), in particular the mandelbrot and julia sets on a window.

## Functionality



## I. Foreword

The project is not related to hydraulic fracturing and focuses on generating fractals.

## II. Introduction

A fractal is an abstract mathematical object that exhibits patterns at every scale. The project involves creating various fractals using the school graphical library, MiniLibX.

## III. Objectives

The objectives of this project are to become familiar with the MiniLibX, work with complex numbers, explore optimization in computer graphics, and practice event handling.

## IV. Common Instructions

- Project must be written in C.
- Follow the Norm requirements.
- Avoid unexpected program termination and memory leaks.
- Submit a Makefile for compiling with specified flags.
- Use the MiniLibX library provided by the school.
- Create test programs to ensure proper functionality.

## V. Mandatory Part

- Program Name: fractol
- Arguments: The type of fractal to display and other options.
- External Functions: open, close, read, write, malloc, free, perror, strerror, exit, math library functions, MiniLibX functions, ft_printf (or equivalent).
- Description: Create a small fractal exploration program, offering Julia set and Mandelbrot set. Use mouse wheel for zooming and different parameters for Julia sets. Display in a window with smooth graphic management. Close window with ESC key or window's cross.

### V.1 Rendering

- Must support Julia set and Mandelbrot set.
- Mouse wheel for infinite zooming.
- Different Julia sets with different parameters.
- At least a few colors to show fractal depth.

### V.2 Graphic Management

- Display the fractal image in a window.
- Smooth window management (switching, minimizing, etc.).
- Close window and quit program cleanly with ESC key or window's cross.

## VI. Bonus Part

Bonus features that can earn extra points:

- Implement one more different fractal.
- Zoom follows the actual mouse position.
- Move the view using arrow keys.
- Shift color range.

Bonus part will only be evaluated if the mandatory part is perfect.

## VII. Submission and Peer-Evaluation

Submit your assignment in your Git repository. Organize files as you wish, but ensure mandatory files are included and comply with the requirements.
