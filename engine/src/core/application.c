#include "game_types.h"
#include "application.h"
#include <GLFW/glfw3.h>

GLFWwindow* window;

b8 application_create(game* game_inst) {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  window = glfwCreateWindow(800, 600, "Test", NULL, NULL);
  glfwMakeContextCurrent(window);

  return TRUE;
}

b8 application_run() {
  while (!glfwWindowShouldClose(window))
  {
    glfwPollEvents();
    glfwSwapBuffers(window);
  }
  return TRUE;
}