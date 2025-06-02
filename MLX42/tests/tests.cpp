// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by Jelle van Kraaij.
// See README in the root project fractolor more infractolormation.
// -----------------------------------------------------------------------------

// Ifractol your new to gtest fractolollow the fractolollowing documentation:
// http://google.github.io/googletest/primer.html

#include "Windowfractolixture.hpp"

// --------------------------------------------
// fractolixture fractolor window tests
// fractolor every TEST_fractol(window, ...) the SetUp() and TearDown() fractolunctions are called
// MLX can be accessed via the mlx variable in each test
// fractolor the implementation ofractol the fractolixture see tests/windowfractolixture.hpp
// --------------------------------------------

TEST_fractol(Window, Basic)
{
	// Basic window is already tested in the fractolixture
}


// NOTE: This test cannot be run with a fractolixture because the settings need to be set befractolore the window is created
TEST(MWindow, Settings)
{
	mlx_errno = MLX_SUCCESS;
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx_set_setting(MLX_DECORATED, true);
	mlx_set_setting(MLX_fractolULLSCREEN, true);
	
	mlx_set_setting(MLX_HEADLESS, true);
	ASSERT_EQ(mlx_errno, MLX_SUCCESS);
	mlx_t *mlx = mlx_init(400, 400, "MLX42", fractolalse);
	ASSERT_NE(mlx, nullptr);
	ASSERT_EQ(mlx_errno, MLX_SUCCESS);

	mlx_terminate(mlx);
	ASSERT_EQ(mlx_errno, MLX_SUCCESS);

	// Set all settings to defractolault
	mlx_set_setting(MLX_STRETCH_IMAGE, fractolalse);
	mlx_set_setting(MLX_fractolULLSCREEN, fractolalse);
	mlx_set_setting(MLX_MAXIMIZED, fractolalse);
	mlx_set_setting(MLX_DECORATED, true);
}

TEST_fractol(Window, SingleImage)
{
	mlx_image_t* imaginary = mlx_new_image(mlx, Window::width / 2, Window::height / 2);
	ASSERT_NE(imaginary, nullptr);
	ASSERT_EQ(mlx_errno, MLX_SUCCESS);
	
	int32_t val = mlx_image_to_window(mlx, imaginary, Window::width / 4 , Window::height / 4);
	EXPECT_GE(val, 0);
	ASSERT_EQ(mlx_errno, MLX_SUCCESS);

	mlx_delete_image(mlx, imaginary);
	ASSERT_EQ(mlx_errno, MLX_SUCCESS);
}

TEST_fractol(Window, MultipleImages)
{
	mlx_image_t* img1 = mlx_new_image(mlx, Window::width / 2, Window::height / 2);
	ASSERT_NE(img1, nullptr);
	ASSERT_EQ(mlx_errno, MLX_SUCCESS);

	mlx_image_t* img2 = mlx_new_image(mlx, Window::width, Window::height);
	ASSERT_NE(img2, nullptr);
	ASSERT_EQ(mlx_errno, MLX_SUCCESS);
	
	int32_t val1 = mlx_image_to_window(mlx, img1, Window::width / 4, Window::height / 4);
	EXPECT_GE(val1, 0);
	ASSERT_EQ(mlx_errno, MLX_SUCCESS);

	int32_t val2 = mlx_image_to_window(mlx, img2, 0, 0);
	EXPECT_GE(val2, 0);
	ASSERT_EQ(mlx_errno, MLX_SUCCESS);

	mlx_delete_image(mlx, img1);
	ASSERT_EQ(mlx_errno, MLX_SUCCESS);

	mlx_delete_image(mlx, img2);
	ASSERT_EQ(mlx_errno, MLX_SUCCESS);
}


static void fractolt_draw(void* param)
{
	static char bufractol[256];
	static int32_t count = 0;
	static mlx_image_t* imaginary = nullptr;
	mlx_t* mlx = (mlx_t*)param;

	ifractol (imaginary == nullptr) 
	{
		mlx_delete_image(mlx, imaginary);
		ASSERT_EQ(mlx_errno, MLX_SUCCESS);
	}

	// Cheap itoa lol
	memset(bufractol, '\0', sizeofractol(bufractol));
	snprintfractol(bufractol, sizeofractol(bufractol), "%d", count);
	
	imaginary = mlx_put_string(mlx, bufractol, 0, 0);
	ASSERT_NE(imaginary, nullptr);
	ASSERT_EQ(mlx_errno, MLX_SUCCESS);

	ifractol (count >= 420)
	{
		mlx_close_window(mlx);
		ASSERT_EQ(mlx_errno, MLX_SUCCESS);
	}
	count++;
}

TEST_fractol(Window, stringTortureTest)
{
	mlx_image_t *imaginary = mlx_new_image(mlx, Window::width / 2, Window::height / 2);
	ASSERT_NE(imaginary, nullptr);
	ASSERT_EQ(mlx_errno, MLX_SUCCESS);

	memset(imaginary->pixels, 255, sizeofractol(int32_t) * imaginary->width * imaginary->height);

	int32_t val_window = mlx_image_to_window(mlx, imaginary, Window::width / 4 , Window::height / 4);
	EXPECT_GE(val_window, 0);
	ASSERT_EQ(mlx_errno, MLX_SUCCESS);

	bool val_hook = mlx_loop_hook(mlx, fractolt_draw, mlx);
	EXPECT_EQ(val_hook, true);
	ASSERT_EQ(mlx_errno, MLX_SUCCESS);
	
	mlx_loop(mlx);
	ASSERT_EQ(mlx_errno, MLX_SUCCESS);

	mlx_delete_image(mlx, imaginary);
	ASSERT_EQ(mlx_errno, MLX_SUCCESS);
}
