# Fract-ol
This project aims to create visually appealing fractals.
![](URL_DE_LA_IMAGEN)

# Table of Contents

I. Introduction ............................................... 3  
II. Objectives ................................................ 4  
III. General Instructions ....................................... 5  
IV. Required Part ............................................... 7  
  IV.1. Rendering ............................................... 8  
  IV.2. Graphical Representation ................................ 8  
V. Optional Part .............................................. 9  
VI. Resources .................................................. 10

## Chapter I

### Introduction

The term "fractal" was first used by mathematician Benoît Mandelbrot in 1974. It is based on the Latin word *fractus*, which means "broken" or "fractured." 

A fractal is a mathematical abstraction, such as a curve or surface, that retains a similar pattern regardless of scale.

Several natural phenomena—such as Romanesque architecture—exhibit some of the characteristics of fractals.

![](URL_DE_LA_IMAGEN)

Now it's your turn to generate some majestic fractals.

## Chapter II

### Objectives

It is time for you to create a basic computer graphics project. You will use the campus's graphics library: [MLX42](https://github.com/codam-coding-college/MLX42). This library has been internally created and includes the basic tools necessary to open a window, create images, and handle keyboard and mouse events.

This new project will be your opportunity to familiarize yourself with miniLibX, explore or use the mathematical concept of complex numbers, and take a look at the concept of optimization in CGI, as well as practice event handling.

![](URL_DE_LA_IMAGEN)

## Chapter III

### General Instructions

- Your project must be written in C.
- Your project must adhere to the Norm. If you have additional files or functions, they are included in the Norm check, and you will receive a 0 if there are any Norm errors in any of them.
- Your functions must not terminate unexpectedly (segfault, bus error, double free, etc.), except in cases of undefined behavior. If this occurs, your project will be considered non-functional, and you will receive a 0 during evaluation.
- All memory allocated on the heap must be properly freed when necessary. Memory leaks are not allowed.
- If required by the statement, you must provide a Makefile that compiles your source files to the required output with the flags -Wall, -Werror, and -Wextra, use `cc`, and your Makefile must not perform relinking.
- Your Makefile must include at least the targets `$(NAME)`, `all`, `clean`, `fclean`, and `re`.
- To submit the bonus parts of your project, you must include a `bonus` rule in your Makefile, adding all headers, libraries, or functions that are prohibited in the main part of the project. Bonuses should be in separate files named `_bonus.{c/h}`. The main part and the bonuses are evaluated separately.
- If your project allows the use of libft, you must copy its source and its associated Makefiles into a `libft` directory with its corresponding Makefile. Your project's Makefile must first compile the library using its Makefile and then compile the project.
- It is recommended to create test programs for your project, although this work will not be submitted or evaluated. This will give you the opportunity to verify that your program works correctly during your evaluation and that of your peers. And yes, you are allowed to use these tests during your evaluation or that of others.
- Submit your work in your assigned Git repository. Only the work in your Git repository will be evaluated. If Deepthought evaluates your work, it will be after your peers. If an error is found during the Deepthought evaluation, the evaluation will be terminated.

## Chapter IV

### Required Part

**Program Name:**  
`fractol`

**Files to Submit:**  
Makefile, `*.h`, `*.c`  
Makefile targets: `all`, `clean`, `fclean`, `re`, `bonus`

**Arguments:**  
The type of fractal to display and any other available options

**Authorized Functions:**  
- `open`, `close`, `read`, `write`,  
  `malloc`, `free`, `perror`,  
  `strerror`, `exit`
- All functions from the math library (`-lm`, see man page 3 math)
- All functions from MLX42
- `ft_printf` and any equivalent functions you have written

**Use of libft:**  
Yes

**Description:**  
The goal of this project is to create a small fractal exploration program.

Your project must follow these rules:
- You must use MLX42, either the version available on campus computers or the one you install from the original sources.
- You must submit a Makefile that compiles your source files. It must not perform relinking.
- Global variables are prohibited.

### IV.1. Rendering
- Your program must provide the Julia and Mandelbrot sets.
- The mouse wheel should perform zoom in and zoom out, nearly infinitely (within the computer's limits). This is the concept of a fractal.
- You should be able to create a different Julia set using the program parameters.
- One parameter will be passed through the CLI to define the type of fractal to be visualized.
  - You can use additional parameters as rendering options.
  - If no parameter is provided or if the parameter is invalid, the program should display a list of available parameters and exit cleanly.
- You must use at least a few colors to show the depth of each fractal. It is even better if you delve into psychedelic effects.

### IV.2. Graphical Representation
- Your program must display the image in a window.
- The handling of your window should be smooth (switching to another window, minimizing, etc.).
- Pressing `ESC` should close the window and exit the program cleanly.
- Clicking the close button on the window frame should also close the window and exit the program cleanly.
- The use of MLX42 images is mandatory.

## Chapter V

### Optional Part

Usually, we would encourage you to develop additional features. However, there will be much more interesting graphical projects later on. They are waiting for you! Don’t spend too much time on this exercise!

You can earn some extra points with the following:
- Add one more different fractal (there are over a hundred references to different types of fractals online).
- Make the zoom follow the current mouse position.
- In addition to zooming, implement movement with arrow keys.
- Make the color range change.

![](URL_DE_LA_IMAGEN)

## Chapter VI

## Resources

In this repository, you will find my solution to this project along with a detailed explanation of what each function does.

![](URL_DE_LA_IMAGEN)
