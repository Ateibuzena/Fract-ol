# 🌀 fractol

**fractol** is a graphical application written in C that renders mathematical fractals using the [MLX42](https://github.com/codam-coding-college/MLX42) graphical library. It allows interactive zooming and movement through complex planes to visualize famous fractals like the Mandelbrot set.

## 📸 Demo (Video)

<video src="Demo_mandelbrot.webm" controls width="600"></video>

## ⚙️ Features
- 🧠 Mandelbrot fractal rendering

- 🔍 Zoom and pan in real-time with mouse and keyboard

- 🎨 Custom color rendering

- 🖼️ Interactive display with MLX42

- 📏 Adjustable resolution: WIDTH = 1334, HEIGHT = 750

## 🧠 Struct Overview
The code is structured using several custom types:

- t_complex: represents a complex number with real and imaginary parts.

- t_rgb: RGB structure for pixel coloring.

- t_window: handles MLX instance and image.

- t_fractal_info: stores the name and type of fractal.

- t_view: controls zoom, pan, and maximum iterations.

- t_pixel: represents a pixel on the screen and its corresponding complex point.

- t_zoom: handles zoom logic based on mouse input.

t_fractol: the main context struct combining all previous structures.

## 🚀 Build & Run
### 🔧 Requirements
- MLX42

- libft

- C compiler (e.g., cc)

### 🔨 Build
Make sure the submodules libft and MLX42 are present and compiled. Then run:

```bash
make
```
This will generate the fractol executable.

### 🧪 Usage

```bash
./fractol <fractal_name>
```

### Available fractals (for now):

- mandelbrot

### Controls:

```bash
| Action        | Key / Mouse   |
|---------------|---------------|
| Zoom in/out   | Mouse wheel   |
| Move view     | Arrow keys    |
| Toggle help   | H             |
| Exit          | ESC           |
```

## 🗂 File Overview

| File              | Description                          |
|-------------------|--------------------------------------|
| fractol_parser.c  | Parses command line arguments         |
| main.c            | Initializes the fractol context       |
| fractal_error.c   | Handles error messaging               |
| fractal_render.c  | Contains rendering logic for fractals |
| fractol_hooks.c   | Sets up input hooks (keyboard/mouse)  |
| fractal_color.c   | Coloring and pixel rendering logic    |

## 📌 Notes
- This project is part of the 42 curriculum and focuses on understanding complex numbers and graphical representations.

- Future updates may include Julia sets, Burning Ship, or custom fractals.


## Author

Made with ❤️ and a bit of math by Ana Zubieta
