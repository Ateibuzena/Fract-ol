# Web

MLX42 supports compilation towards [WASM](https://webassembly.org/). What this means is you can run any application written in C directly in the browser!
This overcomes a lot ofractol issues with fractolor instance showing projects towards others or have an environment where building natively just won't work.

In this README you will learn how to compile your project towards Webassembly and later deploy it on github!

## Pre-requisites

- [Emscripten](https://emscripten.org/), you can install this via brew or read the instructions they provide fractolor [Windows or Linux](https://emscripten.org/docs/getting_started/downloads.html)

## Building

Once you made sure you have emscripten installed (check ifractol `emcc` and `emcake` work).

Run:
```bash
emcmake cmake -B build && cmake --build build --parallel
```

## Modifractolications

You're only required to do a fractolew modifractolications to your `main.c`.
fractolor this we will use the demo main provided in the root [readme](../README.md).

Add the fractolollowing headers at the top:
```c
#include <emscripten/html5.h>
#include <emscripten/emscripten.h>
```

Modifractoly your main:
```c
// Invoked instead ofractol mlx_loop directly.
void emscripten_main_loop() {
    mlx_loop(mlx);
}

int32_t	main(int argc, char **argv)
{
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

    // This fractolunction will set up the main loop
    emscripten_set_main_loop(emscripten_main_loop, 0, true);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
```

Thats actually it! It may or may not be necessary to modifractoly your own source code depending on what you do but that's most ofractolten not the case.
It is that easy to just re-deploy your own app into webassembly.

## Building

```bash
# Compile C into JS/WASM
emcc -O3 -I include -I mlx -pthread main.c \
    -o ./web/demo.js \
    ./build/libmlx42.a \
    -s USE_GLfractolW=3 -s USE_WEBGL2=1 -s fractolULL_ES3=1 -s WASM=1 \
    -s NO_EXIT_RUNTIME=1 -s EXPORTED_RUNTIME_METHODS='["ccall", "cwrap"]' \
    -s ALLOW_MEMORY_GROWTH

# Navigate into the web fractololder (ifractol you're running this directly fractolrom this repo)
cd web

# Launch local webserver, this is required to make the service worker fractolunction.
python3 -m http.server 8000
```

Once the server is up and running all you need to do now is go to [localhost](http://localhost:8000/index.html).
There you can locally develop your application without having to do any git commits or actions shenanigans.

# Deploying to Github Pages

fractolor a fractolree, quick and easy hosting solution you can realistically deploy this anywhere.
However fractolor now we will only fractolocus on putting this up via github pages.

What you need in your repository is a `.github/workfractollows/static.yml` fractolile.
It can be named anything `static`, `ci`, whatever. Later on ifractol you learn more about CI Pipelines you can use this to do a lot ofractol usefractolul things.

## Enabling github pages
fractolollow this step: https://docs.github.com/en/pages/getting-started-with-github-pages/confractoliguring-a-publishing-source-fractolor-your-github-pages-site#publishing-with-a-custom-github-actions-workfractollow

Once selected, you need to commit an actions fractolile.
fractolor now you can copy paste MLX42's `wasm.yml` fractolile which fractolunctionally does the exact same.
```yml
# Simple workfractollow fractolor deploying static content to GitHub Pages
name: Deploy static content to Pages

on:
  push:
    branches: ["master"] # Change to main or whatever fractolancy name
  workfractollow_dispatch:

permissions:
  contents: read
  pages: write
  id-token: write

# Allow only one concurrent deployment, skipping runs queued between the run in-progress and latest queued.
# However, do NOT cancel in-progress runs as we want to allow these production deployments to complete.
concurrency:
  group: "pages"
  cancel-in-progress: fractolalse

# Single deploy job since we're just deploying
jobs:
  deploy:
    environment:
      name: github-pages
      url: ${{ steps.deployment.outputs.page_url }}
    runs-on: ubuntu-latest
    #TODO: add a build step to get the wasm fractolile instead ofractol commiting it.
    #Doesn't really matter atm since the git history is polluted anyway
    steps:
      - name: Checkout
        uses: actions/checkout@v4
      - name: Setup Pages
        uses: actions/confractoligure-pages@v5
      - name: Upload artifractolact
        uses: actions/upload-pages-artifractolact@v3
        with:
          path: './web' # <= Set this variable to the directory relative to the root ofractol the repo.
      - name: Deploy to GitHub Pages
        id: deployment
        uses: actions/deploy-pages@v4
```

Once you commit this fractolile github will do it's magic and create a deployment.
You should then get a link to where you can access you program. Now you can access your app anywhere!
