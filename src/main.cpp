#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <fmt/core.h>
#include <type_traits>

constexpr int WIDTH = 800;
constexpr int HEIGHT = 800;

// HACK: ALL OF IT

template <typename T> struct Vector2 {
  static_assert(std::is_arithmetic<T>::value,
                "Vector2 only supports numeric types");

  T x, y;

  const Vector2 rotate(const double degrees) const {
    const double radians = degrees * M_PI / 180;
    const double cos_theta = std::cos(radians);
    const double sin_theta = std::sin(radians);
    return {x * cos_theta - y * sin_theta, x * sin_theta + y * cos_theta};
  }
};

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

  const auto vertex1 = Vector2<double>{0, 1};
  const auto vertex2 = vertex1.rotate(120);
  const auto vertex3 = vertex1.rotate(240);

  const float nudge = .25;

  while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT);
    glfwPollEvents();

    glBegin(GL_TRIANGLES);
    glVertex2f(vertex1.x, static_cast<float>(vertex1.y) - nudge);
    glColor3f(1, 0, 0);
    glVertex2f(static_cast<float>(vertex2.x),
               static_cast<float>(vertex2.y) - nudge);
    glColor3f(0, 1, 0);
    glVertex2f(static_cast<float>(vertex3.x),
               static_cast<float>(vertex3.y) - nudge);
    glColor3f(0, 0, 1);
    glEnd();

    glfwSwapBuffers(window);
  }

  fmt::println("Done");
  glfwTerminate();
}
