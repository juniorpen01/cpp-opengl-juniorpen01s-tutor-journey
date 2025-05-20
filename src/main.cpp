#include <iostream>

#include <GLFW/glfw3.h>

constexpr int WIDTH = 800;
constexpr int HEIGHT = 800;

int main(void) {
  std::cout << "hello juniorpen01s template\n";

  if (!glfwInit()) {
    std::cerr << "Unable to initialize GLFW";
    return EXIT_FAILURE;
  }

  GLFWwindow *const window = glfwCreateWindow(
      WIDTH, HEIGHT, "juniorpen01's Tutor Journey", nullptr, nullptr);
  if (window == nullptr) {
    std::cerr << "Unable to create window\n";
    return EXIT_FAILURE;
  }

  while (!glfwWindowShouldClose(window))
    ;
}
