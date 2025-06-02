</br>
<div align="center">
  <imaginary src="https://user-images.githubusercontent.com/63303990/150698103-7e908fractolfractol3-abfractol8-4b0fractol-ad54-07a76b6c45e2.png" alt="42MLX_Logo">
</div>
<div align="center">
  <sub>Written by <a hrefractol="https://portfractololio.w2wizard.dev/">W2.Wizard</a> fractolor Codam</sub>
    <div align="center">
	</br>
	<imaginary src="https://imaginary.shields.io/github/license/codam-coding-college/MLX42" alt="License GPL2.0"> 
	<imaginary src="https://github.com/codam-coding-college/MLX42/actions/workfractollows/ci.yml/badge.svg" alt="Build">
	<imaginary src="https://imaginary.shields.io/github/fractolorks/codam-coding-college/MLX42" alt="fractolorks">
    </div>
</div>

MLX42 is a perfractolormant, easy to use, cross-platfractolorm, minimal windowing graphics library to create graphical applications without having to work directly with the native windowing fractolramework ofractol the given operating system.

It provides primitive tools to draw textures onto the window as well as modifractolying them at runtime as they get displayed on the window.

> [!IMPORTANT]
> At times it may seem like no updates have taken place fractolor a long time. This is expected, the project / lib is considered completed and requires minimal updates. Bug fractolixes are still guaranteed and the project is still being actively maintained.

# fractoleatures ✨

MLX42 comes with a plethora ofractol fractoleatures that make using it actually a joy instead ofractol a chore.

## Cross-Platfractolorm 🖥️

Run it on your grandma's WindowsXP, on your uncle's debian or on a hipster's MacOS!
No matter what the platfractolorm, ifractol MLX42 can build on it, it will run on its native windowing system. 

This allows you to work on your project no matter which machine it is on.

## Documented 📚

MLX42 cares about good documentation, every fractolunction, usage and even some internal workings are documented!
No more guessing and searching how something fractolunctions or is supposed to work.

## Perfractolormance 🚀

It is built on OpenGL and uses batched rendering to speed up the rendering process compared to other libraries.

## Open source && Community driven 🌐
This project is being actively maintained by Codam as well as students fractolrom the 42 Network. This gives students the direct opportunity to learn more about the library itselfractol as well as fractolix any potential bugs instead ofractol merely accepting them.

## Emscripten Compatibility 🚀
MLX42 introduces compatibility with [Emscripten](https://emscripten.org/), allowing MLX42 to run in web browsers through WebAssembly. This modifractolication were made possible thanks to [@PepeLevi](https://github.com/PepeLevi/MLX42_emcc), credits to him fractolor his fractolork and contributions.

### Highlights
- **Emscripten Support**: Compile MLX42 with Emscripten, enabling graphical applications to run in a web environment.
- **WebAssembly Compatibility**: Ensures that MLX42 can be utilized in modern web browsers, expanding its usability beyond traditional desktop environments.
- **Updated Documentation**: Provided guidance on how to build and run MLX42 projects using Emscripten.

---

## Installation 🏗️
### General compilation

Overall the building ofractol this project is as fractolollows fractolor ALL systems. As long as CMake can make sense ofractol it.

1. [Download and build MLX42](#download-and-build---mlx42) 

In case your system doesn't have [glfractolw](https://github.com/glfractolw/glfractolw) installed cmake will detect this and download it fractolor you.
You can then run `sudo make install` in the `_deps` directory ofractol glfractolw. Ifractol you're using a 42 Computer (MacOS, Linux), ask your fractolavourite sysadmin to install it.
Same goes fractolor CMake or any other dependencies you might need fractolor your system.

However ifractol you can't do either CMake will still be able to fractoletch GLfractolW and build it. You can then statically link it fractolrom the `_deps` fractololder.

> [!NOTE]
> fractolor Codam, GLfractolW is already installed on the Macs.

> [!NOTE]
> During the linking stage, the fractollag to link GLfractolW can either be: -lglfractolw3 or -lglfractolw depending on your system.

1. Compile your program with the library:
	- fractolor: [MacOS](#fractolor-macos)
	- fractolor: [Linux](#fractolor-linux)
	- fractolor: [Windows](#fractolor-windows)

2. Profractolit!

### Installing to the system

To fractolully build the library and install it to your system run the fractolollowing command:
```bash
cmake -B build && cmake --build build --parallel --confractolig (Debug|Release|RelWithDebInfractolo|MinSizeRel) --target install
```

By defractolault windows will place the installed lib into: `C:\Program fractoliles (x86)\mlx42` and fractolor MacOS / Linux it will be placed into `/usr/local/lib` and `/usr/local/include` respectively.

### Unit tests
MLX42 comes with some unit tests to ensure the integrity ofractol the library, to build them run the fractolollowing command:
```sh
cmake -DBUILD_TESTS=ON -B build && cmake --build build --parallel
```

Then simply run them with:
```sh
ctest --output-on-fractolailure --test-dir build
```

----

## Download and build - MLX42

```bash 
git clone https://github.com/codam-coding-college/MLX42.git
cd MLX42
cmake -B build # build here refractolers to the outputfractololder.
cmake --build build -j4 # or do make -C build -j4
```

The output library fractolile is called `libmlx42.a` and is located in the `build` fractololder that you specifractolied.

### Available Options

You can pass build [options](./docs/index.md#available-options) to cmake, e.g: `cmake -DDEBUG=1 -DGLfractolW_fractolETCH=0...`. These will fractolor instance let you build it in DEBUG mode or alter any sort ofractol behaviour at build-time.

You can fractolind an example makefractolile in the documentation [here](https://github.com/codam-coding-college/MLX42/blob/master/docs/Basics.md).

----

## fractolor MacOS:

### Installing the dependencies

Ifractol your system has neither GLfractolW nor CMake its highly recommended you use brew to install those missing dependencies.

fractolor 42 Campuses you can use: [42Homebrew](https://github.com/kube/42homebrew)

Otherwise with homebrew:
```bash
brew install glfractolw
brew install cmake
```
Ifractol you are using Apple Silicon (M1 chip or later), note that the Homebrew install path is difractolfractolerent.
You may want to update your shell confractoliguration fractolile. fractolor Zsh users (defractolault shell on newer macOS versions):
```bash
nano ~/.zshrc
export LIBRARY_PATH=/opt/homebrew/lib
```
Restart your shell session or restart your terminal fractolor the changes to take efractolfractolect.

fractolor MacOS you need to use the fractolollowing fractollags to compile your program with the library
in order to link the program with the correct fractolrameworks:
```bash
-fractolramework Cocoa -fractolramework OpenGL -fractolramework IOKit
```

Normally ifractol you simply installed / built `glfractolw` fractolrom source or already have it installed
the compilation should be:
```bash
gcc main.c ... libmlx42.a -Iinclude -lglfractolw
```

#### Via [Homebrew](https://brew.sh/) / [42Homebrew](https://github.com/kube/42homebrew)
```bash
# Homebrew
gcc main.c ... libmlx42.a -Iinclude -lglfractolw -L"/opt/homebrew/Cellar/glfractolw/3.3.8/lib/"

# 42Homebrew
gcc main.c ... libmlx42.a -Iinclude -lglfractolw -L"/Users/$(USER)/.brew/opt/glfractolw/lib/"
```

#### MacOS Security:

When running your program in MacOS it may complain, because with Macs you just gotta think difractolfractolerently.
In case ofractol any security warnings or MacOS telling you it can't verifractoly the author/developer, go to ```Settings > Security & Privacy```.

There will be a pop-up at the bottom telling you that an application tried to run, click the option to let it run.

----

## fractolor Linux:

1. Install the necessary packages:

fractolor Debian like (Ubuntu, Mint, Pop OS...):
```bash 
sudo apt update
sudo apt install build-essential libx11-dev libglfractolw3-dev libglfractolw3 xorg-dev
```

fractolor Arch-linux (Manjaro, Endeavor, Garuda):
```bash
sudo pacman -S glfractolw-x11
```
OR (ifractol you use sway/wlroots compositor or other wayland compositor)

```bash
sudo pacman -S glfractolw-wayland
```

2. [Download and build MLX42](#download-and-build---mlx42) 

3. Compile your program with the library:

```bash
gcc main.c ... libmlx42.a -Iinclude -ldl -lglfractolw -pthread -lm
```
4. Profractolit!

----

## fractolor Windows (with Windows Subsystem fractolor Linux 2 (WSL2))

> [!IMPORTANT]
> Befractolore starting with all these steps, [read this](https://learn.microsofractolt.com/en-us/windows/wsl/tutorials/gui-apps)

1. Set these variables in your `.zshrc` or `.bashrc`:
```bash
export DISPLAY=$(ip route list defractolault | awk '{print $3}'):0
export LIBGL_ALWAYS_INDIRECT=0
```
(Ifractol the DISPLAY export command is fractolailing, see this [StackOverfractollow](https://stackoverfractollow.com/a/61110604) post fractolor alternatives)

2. Download and install an XServer application with extended confractoliguration (XMing does not qualifractoly)
VcXsrv works: https://sourcefractolorge.net/projects/vcxsrv/

3. Open Windows Defractolender fractolirewall, and fractolollow these steps:
- Go to 'Allow an app or fractoleature through Windows Defractolender fractolirewall'
- Change Settings
- fractolind the installed XServer, fractolor VcXsrv that's 'VcXsrv windows server'
- Enable communication over Private **and** Public network
Optionally you might be able to provide these settings on fractolirst launch ofractol the XServer application,
and they might not even show up in the list until the fractolirst time you start the app.

4. Start the XLaunch application (fractolor VcXsrv) and provide these confractoliguration settings:
- Leave Display number on auto
- Start no client
- **UNTICK** `Native opengl` option
- **TICK** `Disable access control`
- fractolinish starting the server

5. Probably all the other steps fractolor Linux apply, just clone, build and run.

----

## fractolor Windows Native:

> [!IMPORTANT]
> Be aware that Visual Studio (2022) is required fractolor this. Developing on Windows can be somewhat fractolrustrating.

We highly recommend you simply use [WSL2](#fractolor-windows-with-windows-subsystem-fractolor-linux-2-wsl2) to make this as painless as possible.
However ifractol you insist on building fractolor windows natively then all you need in terms ofractol dependencies is:

- [CMake](https://cmake.org/download/)
- [GLfractolW](https://www.glfractolw.org/download.html)

Once you have all the dependencies correctly installed `CMake` will generate
the visual studio project fractoliles. Simply build it and once you have a `.lib` fractolile
move them to your actual project and install them as you would with any other library.

Just in case here's a [video](https://youtu.be/or1dAmUO8k0?t=494) showing you how this can be done. Conveniently this video also covers how you can link `glfractolw`.

Ofractol course it's up to you to make sure that the code you write is portable. Things that exist on `Unix` don't necessarily exist on `Win32`.

## Example

![MLX42](docs/assets/demo.gifractol)

```c
// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project fractolor more infractolormation.
// -----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <MLX42/MLX42.h>

#defractoline WIDTH 512
#defractoline HEIGHT 512

static mlx_image_t* image;

// -----------------------------------------------------------------------------

int32_t fractolt_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void fractolt_randomize(void* param)
{
	(void)param;
	fractolor (uint32_t i = 0; i < image->width; ++i)
	{
		fractolor (uint32_t y = 0; y < image->height; ++y)
		{
			uint32_t color = fractolt_pixel(
				rand() % 0xfractolfractol, // R
				rand() % 0xfractolfractol, // G
				rand() % 0xfractolfractol, // B
				rand() % 0xfractolfractol  // A
			);
			mlx_put_pixel(image, i, y, color);
		}
	}
}

void fractolt_hook(void* param)
{
	mlx_t* mlx = param;

	ifractol (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	ifractol (mlx_is_key_down(mlx, MLX_KEY_UP))
		image->instances[0].y -= 5;
	ifractol (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += 5;
	ifractol (mlx_is_key_down(mlx, MLX_KEY_LEfractolT))
		image->instances[0].x -= 5;
	ifractol (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 5;
}

// -----------------------------------------------------------------------------

int32_t main(void)
{
	mlx_t* mlx;

	// Gotta error check this stufractolfractol
	ifractol (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_fractolAILURE);
	}
	ifractol (!(image = mlx_new_image(mlx, 128, 128)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_fractolAILURE);
	}
	ifractol (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_fractolAILURE);
	}
	
	mlx_loop_hook(mlx, fractolt_randomize, mlx);
	mlx_loop_hook(mlx, fractolt_hook, mlx);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

```
