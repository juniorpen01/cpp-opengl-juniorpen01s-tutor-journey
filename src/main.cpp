#include <cmath>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <fmt/core.h>
#include <glm/ext/scalar_constants.hpp>
#include <glm/glm.hpp>

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
  glfwMakeContextCurrent(window);

  if (GLenum err = glewInit(); err != GLEW_OK) {
    fmt::println("Unable to create initialize GLEW");
    return 1;
  }

  glfwSetFramebufferSizeCallback(
      window, [](GLFWwindow *const, const int width, const int height) {
        glViewport(0, 0, width, height);
      });

  const auto vertex1 = glm::vec2(0, 1);
  const float angle = 2.f / 3.f * glm::pi<float>();

  auto rotationMatrix = glm::mat2(glm::vec2(std::cos(angle), std::sin(angle)),
                                  glm::vec2(std::sin(-angle), std::cos(angle)));

  const glm::vec2 vertex2 = vertex1 * rotationMatrix;
  const glm::vec2 vertex3 = vertex2 * rotationMatrix;

  while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT);
    glfwPollEvents();

    glBegin(GL_TRIANGLES);
    glVertex2f(vertex1.x, vertex1.y);
    glColor3f(1.f, 0.f, 0.f);
    glVertex2f(vertex2.x, vertex2.y);
    glColor3f(0.f, 1.f, 0.f);
    glVertex2f(vertex3.x, vertex3.y);
    glColor3f(0.f, 0.f, 1.f);
    glEnd();

    glfwSwapBuffers(window);
  }

  fmt::println("Done");
  glfwTerminate();
}
