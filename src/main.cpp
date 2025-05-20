#include <GLFW/glfw3.h>
#include <fmt/core.h>

constexpr int WIDTH = 800;
constexpr int HEIGHT = 800;

int main(void) {
  glfwSetErrorCallback([](const int error, const char *const description) {
    fmt::println(stderr, "GLFW Error [{}]: {}", error, description);
  });

  if (!glfwInit()) {
    fmt::println("Unable to create initialize GLFW");
    return 1;
  }

  GLFWwindow *const window = glfwCreateWindow(
      WIDTH, HEIGHT, "juniorpen01's Tutor Journey", nullptr, nullptr);
  if (window == nullptr) {
    fmt::println("Unable to create GLFW window");
    return 1;
  }

  while (!glfwWindowShouldClose(window))
    glfwPollEvents();

  fmt::println("Done");
  glfwTerminate();
}
