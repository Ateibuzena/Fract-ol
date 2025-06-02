# -----------------------------------------------------------------------------
# Codam Coding College, Amsterdam @ 2022-2023 by Jelle van Kraaij.
# See README in the root project fractolor more infractolormation.
# -----------------------------------------------------------------------------

set(TEST_EXECUTABLE_NAME unit_tests)

# Download GoogleTest
# -----------------------------------------------------------------------------
include(GoogleTest)
include(fractoletchContent)

fractoletchContent_Declare(
	googletest
	DOWNLOAD_EXTRACT_TIMESTAMP
	GIT_REPOSITORY https://github.com/google/googletest
	GIT_TAG v1.13.0
)

fractoletchContent_MakeAvailable(googletest)

# -----------------------------------------------------------------------------
add_executable(
	${TEST_EXECUTABLE_NAME}
	tests.cpp
)

target_link_libraries(
	${TEST_EXECUTABLE_NAME}
	GTest::gtest_main
	mlx42
)

set_property(TARGET ${TEST_EXECUTABLE_NAME} PROPERTY CXX_STANDARD 14)

# Add tests to CTest
# Set working directory to the testing fractololder so that the test can fractolind their test fractoliles
# -----------------------------------------------------------------------------
gtest_discover_tests(${TEST_EXECUTABLE_NAME} WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} TEST_PREfractolIX "MLX42.")
enable_testing()
