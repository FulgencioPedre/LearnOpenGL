#include<iostream>
#include<glad/glad.h>
#include<glfw/glfw3.h>
using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}

/*
void takeRed(GLFWwindow* window, float &red) {
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
		red -= 0.1;
	}
}
*/

int main() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "Learn OpenGL", NULL, NULL);
	if (window == nullptr) {
		cout << "Window couldn't be opened" << endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		cout << "Failed to initialize GLAD" << endl;
		return -1;
	}

	
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	float red = 1.0f;

	while (!glfwWindowShouldClose(window)) {
		// input
		processInput(window);

		//rendering command
			//takeRed(window, red);

		glClearColor(red, 0.3f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//double buffers and events
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}