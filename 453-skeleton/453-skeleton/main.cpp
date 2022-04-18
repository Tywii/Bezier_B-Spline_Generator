#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <limits>
#include <functional>

#include "Geometry.h"
#include "GLDebug.h"
#include "Log.h"
#include "ShaderProgram.h"
#include "Shader.h"
#include "Texture.h"
#include "Window.h"

#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"

#define _USE_MATH_DEFINES
#include <math.h>


// We gave this code in one of the tutorials, so leaving it here too
void updateGPUGeometry(GPU_Geometry &gpuGeom, CPU_Geometry const &cpuGeom) {
	gpuGeom.bind();
	gpuGeom.setVerts(cpuGeom.verts);
	gpuGeom.setCols(cpuGeom.cols);
}


// EXAMPLE CALLBACKS
class Assignment3 : public CallbackInterface {

public:
	Assignment3()
	{
	}

	virtual void keyCallback(int key, int scancode, int action, int mods) {
	}
	virtual void mouseButtonCallback(int button, int action, int mods) {
	}
	virtual void cursorPosCallback(double xpos, double ypos) {
	}
	virtual void scrollCallback(double xoffset, double yoffset) {
	}
	virtual void windowSizeCallback(int width, int height) {
		// The CallbackInterface::windowSizeCallback will call glViewport for us
		CallbackInterface::windowSizeCallback(width,  height);
	}

private:

};

class MyCallbacks : public CallbackInterface {

public:
	MyCallbacks(ShaderProgram& shader, int screenWidth, int screenHeight) :
		screenDim(screenWidth, screenHeight),
		shader(shader),
		leftMousePressed(false),
		rightMousePressed(false),
		upPressed(false),
		downPressed(false),
		rPressed(false),
		scrollPressed(false),
		rightPressed(false),
		leftPressed(false),
		wPressed(false),
		sPressed(false),
		aPressed(false),
		dPressed(false)
	{}

	virtual void keyCallback(int key, int scancode, int action, int mods) {
		if (key == GLFW_KEY_UP && action == GLFW_PRESS) {
			shader.recompile();
			upPressed = true;
		}
		if (key == GLFW_KEY_UP && action == GLFW_RELEASE) {
			shader.recompile();
			upPressed = false;
		}
		if (key == GLFW_KEY_DOWN && action == GLFW_PRESS) {
			shader.recompile();
			downPressed = true;
		}
		if (key == GLFW_KEY_DOWN && action == GLFW_RELEASE) {
			shader.recompile();
			downPressed = false;
		}
		if (key == GLFW_KEY_R && action == GLFW_PRESS) {
			shader.recompile();
			rPressed = true;
		}
		if (key == GLFW_KEY_R && action == GLFW_RELEASE) {
			shader.recompile();
			rPressed = false;
		}
		if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS) {
			shader.recompile();
			rightPressed = true;
		}
		if (key == GLFW_KEY_RIGHT && action == GLFW_RELEASE) {
			shader.recompile();
			rightPressed = false;
		}
		if (key == GLFW_KEY_LEFT && action == GLFW_PRESS) {
			shader.recompile();
			leftPressed = true;
		}
		if (key == GLFW_KEY_LEFT && action == GLFW_RELEASE) {
			shader.recompile();
			leftPressed = false;
		}
		if (key == GLFW_KEY_W && action == GLFW_PRESS) {
			shader.recompile();
			wPressed = true;
		}
		if (key == GLFW_KEY_W && action == GLFW_RELEASE) {
			shader.recompile();
			wPressed = false;
		}
		if (key == GLFW_KEY_S && action == GLFW_PRESS) {
			shader.recompile();
			sPressed = true;
		}
		if (key == GLFW_KEY_S && action == GLFW_RELEASE) {
			shader.recompile();
			sPressed = false;
		}
		if (key == GLFW_KEY_A && action == GLFW_PRESS) {
			shader.recompile();
			aPressed = true;
		}
		if (key == GLFW_KEY_A && action == GLFW_RELEASE) {
			shader.recompile();
			aPressed = false;
		}
		if (key == GLFW_KEY_D && action == GLFW_PRESS) {
			shader.recompile();
			dPressed = true;
		}
		if (key == GLFW_KEY_D && action == GLFW_RELEASE) {
			shader.recompile();
			dPressed = false;
		}
	}

	virtual void mouseButtonCallback(int button, int action, int mods) {
		if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
			shader.recompile();
			leftMousePressed = true;
		}
		if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE) {
			shader.recompile();
			leftMousePressed = false;
		}
		if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS) {
			shader.recompile();
			rightMousePressed = true;
		}
		if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE) {
			shader.recompile();
			rightMousePressed = false;
		}
		if (button == GLFW_MOUSE_BUTTON_MIDDLE && action == GLFW_PRESS) {
			shader.recompile();
			scrollPressed = true;
		}
		if (button == GLFW_MOUSE_BUTTON_MIDDLE && action == GLFW_RELEASE) {
			shader.recompile();
			scrollPressed = false;
		}
	}

	void refreshStatuses() {
		leftMousePressed = false;
		scrollPressed = false;
		upPressed = false;
		downPressed = false;
		rPressed = false;
		rightPressed = false;
		leftPressed = false;
	}

	bool buttonDown(int button) {
		if (button == GLFW_MOUSE_BUTTON_LEFT) {
			return leftMousePressed;
		}
		if (button == GLFW_MOUSE_BUTTON_RIGHT) {
			return rightMousePressed;
		}
		if (button == GLFW_MOUSE_BUTTON_MIDDLE) {
			return scrollPressed;
		}
		if (button == GLFW_KEY_UP) {
			return upPressed;
		}
		if (button == GLFW_KEY_DOWN) {
			return downPressed;
		}
		if (button == GLFW_KEY_R) {
			return rPressed;
		}
		if (button == GLFW_KEY_RIGHT) {
			return rightPressed;
		}
		if (button == GLFW_KEY_LEFT) {
			return leftPressed;
		}
		if (button == GLFW_KEY_W) {
			return wPressed;
		}
		if (button == GLFW_KEY_S) {
			return sPressed;
		}
		if (button == GLFW_KEY_A) {
			return aPressed;
		}
		if (button == GLFW_KEY_D) {
			return dPressed;
		}
		return false;
	}

	glm::vec2 mouseGL() {
		glm::vec2 startingVec(xScreenPos, yScreenPos);
		glm::vec2 shiftedVec = startingVec + glm::vec2(0.5f);
		glm::vec2 scaled = shiftedVec / glm::vec2(screenDim);
		glm::vec2 flippedY = glm::vec2(scaled.x, 1.0f - scaled.y);
		glm::vec2 final = flippedY * 2.0f - glm::vec2(1.0f);
		return final;
	}

	virtual void cursorPosCallback(double xpos, double ypos) {
		xScreenPos = xpos;
		yScreenPos = ypos;
	}

	//virtual void inRangeCallback()

private:
	bool leftMousePressed;
	bool rightMousePressed;
	bool upPressed;
	bool downPressed;
	bool rPressed;
	bool scrollPressed;
	bool rightPressed;
	bool leftPressed;
	bool wPressed;
	bool sPressed;
	bool aPressed;
	bool dPressed;

	glm::ivec2 screenDim;

	double xScreenPos;
	double yScreenPos;

	ShaderProgram& shader;

};
//Window window(1800, 1800, "CPSC 453"); // can set callbacks at construction if desired
//ShaderProgram shader("shaders/test.vert", "shaders/test.frag");
//
std::shared_ptr<MyCallbacks> inputManager;
float yaw = -90.0f;
float pitch = 0.0f;
bool revolved = false;
bool surfaceMade = false;
//CPU_Geometry square;
//GPU_Geometry pointsGPUGeom;
//GPU_Geometry linesGPUGeom;


void curves(CPU_Geometry& square) {
	if (inputManager->buttonDown(GLFW_MOUSE_BUTTON_LEFT)) {
		glm::vec2 mousePos = inputManager->mouseGL();
		square.verts.push_back(glm::vec3{ mousePos[0], mousePos[1], 0.0f });
		revolved = false;
	}

	if (inputManager->buttonDown(GLFW_MOUSE_BUTTON_RIGHT)) {
		glm::vec2 mousePos = inputManager->mouseGL();
		//square.verts.push_back(glm::vec3{ mousePos[0], mousePos[1], 0 });
		for (int i = 0; i < square.verts.size(); i++) {
			if (sqrt(pow(mousePos[0] - square.verts[i][0], 2) + pow(mousePos[1] - square.verts[i][1], 2)) <= 0.01f) {
				square.verts[i] = glm::vec3(mousePos[0], mousePos[1], 0.0f);
			}
		}
		revolved = false;
	}

	if (inputManager->buttonDown(GLFW_MOUSE_BUTTON_MIDDLE)) {
		glm::vec2 mousePos = inputManager->mouseGL();
		//square.verts.push_back(glm::vec3{ mousePos[0], mousePos[1], 0 });
		for (int i = 0; i < square.verts.size(); i++) {
			if (sqrt(pow(mousePos[0] - square.verts[i][0], 2) + pow(mousePos[1] - square.verts[i][1], 2)) <= 0.01f) {
				square.verts.erase(square.verts.begin() + i);
				//std::cout << square.verts.size() << std::endl;
			}
		}
		revolved = false;
	}

	if (inputManager->buttonDown(GLFW_KEY_R)) {
		square.verts.clear();
		revolved = false;
	}
}

void Bezier(CPU_Geometry points, CPU_Geometry& curve) {
	//de Casteljau
	//if (inputManager->buttonDown(GLFW_MOUSE_BUTTON_LEFT) || inputManager->buttonDown(GLFW_MOUSE_BUTTON_RIGHT) || inputManager->buttonDown(GLFW_MOUSE_BUTTON_MIDDLE)) {
		curve.verts.clear();
		int degree = points.verts.size();
		//std::cout << degree << std::endl;
		if (degree >= 3) {
			for (float u = 0; u < 1; u += 0.01) {
				for (int i = 1; i < degree; i++) {
					for (int j = 0; j < (degree - i); j++) {
						//int j2 = j + 1;
						points.verts[j] = (1.f - u) * points.verts[j] + u * points.verts[j + 1];
					}
				}
				curve.verts.push_back(points.verts[0]);
			}
		}
	//}
	if (inputManager->buttonDown(GLFW_KEY_R)) {
		curve.verts.clear();
	}
}


glm::vec3 BezierU(CPU_Geometry points, float u) {
	//de Casteljau
	//if (inputManager->buttonDown(GLFW_MOUSE_BUTTON_LEFT) || inputManager->buttonDown(GLFW_MOUSE_BUTTON_RIGHT) || inputManager->buttonDown(GLFW_MOUSE_BUTTON_MIDDLE)) {
	
	int degree = points.verts.size();
	//std::cout << degree << std::endl;
	if (degree >= 3) {
		for (int i = 1; i < degree; i++) {
			for (int j = 0; j < (degree - i); j++) {
				//int j2 = j + 1;
				points.verts[j] = (1.f - u) * points.verts[j] + u * points.verts[j + 1];
			}
		}

		return points.verts[0];
	}
	
}

void bSpline(CPU_Geometry points, CPU_Geometry& curve, int pointsDegree) {
	// Chaikin
	
	int degree = points.verts.size() - 1;
	if (degree < 3) {
		curve.verts.clear();
	}
	if (degree >= 3 && degree < pointsDegree * 10) {
		curve.verts.clear();

		int j = 0;
		
		curve.verts.push_back(points.verts[0]);
		curve.verts.push_back(0.5f * (points.verts[0] + points.verts[1]));

		for (int i = 1; i < degree - 1; i++) {
			curve.verts.push_back(0.75f * points.verts[i] + 0.25f * points.verts[i + 1]);
			curve.verts.push_back(0.25f * points.verts[i] + 0.75f * points.verts[i + 1]);
			j += 2;
		}

		curve.verts.push_back(0.5f * (points.verts[degree - 1] + points.verts[degree]));
		curve.verts.push_back(points.verts[degree]);
		CPU_Geometry p2 = curve;
		bSpline(p2, curve, pointsDegree);
	}
	else if (inputManager->buttonDown(GLFW_KEY_R)) {
		curve.verts.clear();
	}
}

glm::vec3 bSplineU(CPU_Geometry points, int pointsDegree, float u) {
	// Chaikin
	CPU_Geometry curve;
	int degree = points.verts.size() - 1;
	if (degree < 3) {
		curve.verts.clear();
	}
	if (degree >= 3 && degree < pointsDegree * 10) {
		curve.verts.clear();

		int j = 0;

		curve.verts.push_back(points.verts[0]);
		curve.verts.push_back(0.5f * (points.verts[0] + points.verts[1]));

		for (int i = 1; i < degree - 1; i++) {
			curve.verts.push_back(0.75f * points.verts[i] + 0.25f * points.verts[i + 1]);
			curve.verts.push_back(0.25f * points.verts[i] + 0.75f * points.verts[i + 1]);
			j += 2;
		}

		curve.verts.push_back(0.5f * (points.verts[degree - 1] + points.verts[degree]));
		curve.verts.push_back(points.verts[degree]);
		CPU_Geometry p2 = curve;
		bSpline(p2, curve, pointsDegree);
	}
	else {
		int increment = u * pointsDegree * 10;
		return points.verts[increment];
	}

}


void move(glm::vec3& cameraPos, glm::vec3 cameraFront, glm::vec3 cameraUp, float cameraSpeed) { //	Adapted from https://learnopengl.com/Getting-started/Camera
	if (inputManager->buttonDown(GLFW_KEY_W)) {
		cameraPos += cameraSpeed * cameraFront;
	}
	else if (inputManager->buttonDown(GLFW_KEY_S)) {
		cameraPos -= cameraSpeed * cameraFront;
	}
	else if (inputManager->buttonDown(GLFW_KEY_A)) {
		cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
	}
	else if (inputManager->buttonDown(GLFW_KEY_D)) {
		cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
	}
}

void look(glm::vec3& cameraFront, float sensitivity) {	// Adapted from https://learnopengl.com/Getting-started/Camera
	glm::vec2 mousePos = inputManager->mouseGL();
	float mouseX = mousePos[0];
	float mouseY = mousePos[1];
	mouseX *= sensitivity;
	mouseY *= sensitivity;

	yaw += mouseX;
	pitch += mouseY;

	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;

	glm::vec3 direction;
	direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	direction.y = sin(glm::radians(pitch));
	direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	cameraFront = glm::normalize(direction);
}

void applyShader(glm::mat4 model, glm::mat4 view, glm::mat4 projection, GLuint shaderProgram) {
	unsigned int modelLoc = glGetUniformLocation(shaderProgram, "model");
	unsigned int viewLoc = glGetUniformLocation(shaderProgram, "view");
	unsigned int projectionLoc = glGetUniformLocation(shaderProgram, "projection");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
}

void revolution(CPU_Geometry& curve) {

	CPU_Geometry revolve;
	int size = curve.verts.size() - 1;
	for (int u = 0; u < 100; u++) {
		for (float v = 0; v < 2 * M_PI; v += 0.1) {
			int increment = (u * size) / 100;
			revolve.verts.push_back(glm::vec3(curve.verts[increment][0] * cos(v), curve.verts[increment][1], curve.verts[increment][0] * sin(v)));
		}
	}
	curve.verts.clear();
	for (int i = 0; i < 99; i++) {
		for (int j = 0; j < 20 * M_PI; j++) {
			curve.verts.push_back(revolve.verts[i * 63 + j]);
			curve.verts.push_back(revolve.verts[i * 63 + j + 63]);
			curve.verts.push_back(revolve.verts[i * 63 + j + 63]);
			curve.verts.push_back(revolve.verts[i * 63 + j + 1]);
			curve.verts.push_back(revolve.verts[i * 63 + j + 1]);
			curve.verts.push_back(revolve.verts[i * 63 + j]);
			if (i == 98) {
				curve.verts.push_back(revolve.verts[i * 63 + j + 63]);
				curve.verts.push_back(revolve.verts[i * 63 + j + 62]);
			}
		}
	}
	revolved = true;
}

CPU_Geometry getRow(CPU_Geometry square, int row, int degree) {
	CPU_Geometry rowPoints;
	for (int j = 0; j <= degree; j++) {
		rowPoints.verts.push_back(square.verts[row * (degree + 1) + j]);
	}
	return rowPoints;
}

CPU_Geometry tensor(CPU_Geometry& square, CPU_Geometry& curve, int surfaceSwitcher) {
	int degree = square.verts.size() - 1;
	CPU_Geometry copy = square;

	square.verts.clear();
	float multiplier = 0;
	float x = -1.0f;
	float y = -1.0f;
	float increment = 2.0f / degree;
	for (int i = 0; i <= degree; i++) {
		x = -1.0f;
		x += (i / (degree - 1)) * 2;
		multiplier = 8 * ((float)rand() / RAND_MAX) - 1.5;
		for (int j = 0; j <= degree; j++) {
			square.verts.push_back(glm::vec3(-1.0f + i * degree, -1.0f + j * degree, copy.verts[j][0] * multiplier));
		}
	}
	CPU_Geometry R;
	if (surfaceSwitcher <= 1) {
		curve.verts.clear();
		R.verts.clear();
		for (float u = 0; u <= 1.01; u += 0.1) {
			for (float v = 0; v <= 1.01; v += 0.1) {
				for (int i = 0; i <= degree; i++) {
					R.verts.push_back(BezierU(getRow(square, i, degree), v));
				}
				curve.verts.push_back(BezierU(R, u));
				R.verts.clear();
				}
			}
	}
	else {
		curve.verts.clear();
		R.verts.clear();
		CPU_Geometry row;
		for (float u = 0; u <= 1.01; u += 0.1) {
			for (float v = 0; v <= 1.01; v += 0.1) {
				for (int i = 0; i <= degree; i++) {
					row = getRow(square, i, degree);
					R.verts.push_back(bSplineU(row, row.verts.size(), v));
				}
				curve.verts.push_back(bSplineU(R, R.verts.size(), u));
				R.verts.clear();
			}
		}
	}


	copy = curve;
	curve.verts.clear();
	for (int i = 0; i <= 10; i++) {
		for (int j = 0; j < 10; j++) {
			curve.verts.push_back(copy.verts[i * (11) + j]);
			curve.verts.push_back(copy.verts[i * (11) + j + 1]);
		}
	}

	for (int i = 0; i <= 10; i++) {
		for (int j = 0; j < 10; j++) {
			curve.verts.push_back(copy.verts[j * (11) + i]);
			curve.verts.push_back(copy.verts[(j + 1) * (11) + i]);
		}
	}

	CPU_Geometry lines;
	for (int i = 0; i <= degree; i++) {
		for (int j = 0; j < degree; j++) {
			lines.verts.push_back(square.verts[i * (degree+1) + j]);
			lines.verts.push_back(square.verts[i * (degree+1) + j + 1]);
		}
	}

	for (int i = 0; i <= degree; i++) {
		for (int j = 0; j < degree; j++) {
			lines.verts.push_back(square.verts[j * (degree + 1) + i]);
			lines.verts.push_back(square.verts[(j + 1) * (degree + 1) + i]);
		}
	}

	return lines;
	surfaceMade = true;
}
// CALLBACKS  
//window.setCallbacks(inputManager); // can also update callbacks to new ones
int main() {
	Log::debug("Starting main");

	// WINDOW
	glfwInit();
	Window window(1800, 1800, "CPSC 453"); // can set callbacks at construction if desired


	GLDebug::enable();
	glEnable(GL_DEPTH_TEST);

	//// CALLBACKS
	//auto a3 = std::make_shared<Assignment3>();
	//window.setCallbacks(a3);


	ShaderProgram shader("shaders/test.vert", "shaders/test.frag");

	// SHADERS
	//ShaderProgram shader("shaders/test.vert", "shaders/test.frag");

	//std::shared_ptr<MyCallbacks> inputManager = std::make_shared<MyCallbacks>(shader, 1800, 1800);
	inputManager = std::make_shared<MyCallbacks>(shader, 1800, 1800);

	//// CALLBACKS  
	window.setCallbacks(inputManager); // can also update callbacks to new ones

	// The current CPU_Geometry and GPU_Geometry classes are defined in
	// Geometry.h/Geometry.cpp They will work for this assignment, but for some of
	// the bonuses you may have to modify them.
	CPU_Geometry square;
	//square.verts.push_back(glm::vec3{-0.5, 0.5, 0});
	//square.verts.push_back(glm::vec3{-0.5, -0.5, 0});
	//square.verts.push_back(glm::vec3{0.5, -0.5, 0});
	//square.verts.push_back(glm::vec3{0.5, 0.5, 0});
	//square.cols.resize(square.verts.size(), glm::vec3{1.0, 0.0, 0.0});
	GPU_Geometry pointsGPUGeom;
	//updateGPUGeometry(pointsGPUGeom, square);

	// Reset the colors to green
	//square.cols.clear();
	//square.cols.resize(square.verts.size(), glm::vec3{0.0, 1.0, 0.0});

	GPU_Geometry linesGPUGeom;
	//updateGPUGeometry(linesGPUGeom, square);

	glPointSize(10.0f);

	CPU_Geometry curve;
	GPU_Geometry curveGPUGeom;

	CPU_Geometry revolvedCurve;
	CPU_Geometry tensorSurface;
	CPU_Geometry tensorLines;
	CPU_Geometry tensorSquare;
	// Note this call only work on some systems, unfortunately.
	// In order for them to work, you have to comment out line 60
	// If you're on a mac, you can't comment out line 60, so you
	// these will have no effect. :(
	//glLineWidth(5.0f);

	int curveSwitcher = 0;
	int sceneSwitcher = 0;
	int surfaceSwitcher = 0;

	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 2.0f);
	glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::mat4 model = glm::mat4(1.0f);
	glm::mat4 projection = glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 100.0f);
	
	//CPU_Geometry revolved;
	//CPU_Geometry mesh;
	
	// RENDER LOOP
	while (!window.shouldClose()) {
		inputManager->refreshStatuses();
		glfwPollEvents();

	
		if (inputManager->buttonDown(GLFW_KEY_UP)) {
			curveSwitcher++;
			surfaceSwitcher++;
			surfaceMade = false;
		}
		if (inputManager->buttonDown(GLFW_KEY_DOWN)) {
			curveSwitcher--;
			surfaceSwitcher--;
			if (curveSwitcher < 0) {
				curveSwitcher += 2;
			}
			if (surfaceSwitcher < 0) {
				surfaceSwitcher += 3;
			}
			surfaceMade = false;
		}
		if (inputManager->buttonDown(GLFW_KEY_RIGHT)) {
			sceneSwitcher++;
		}
		if (inputManager->buttonDown(GLFW_KEY_LEFT)) {
			sceneSwitcher--;
			if (sceneSwitcher < 0) {
				sceneSwitcher += 4;
			}
		}
		if (sceneSwitcher % 4 == 0 && curveSwitcher % 2 == 0) {
			curves(square);
			Bezier(square, curve);
			applyShader(glm::mat4(1.0f), glm::mat4(1.0f), glm::mat4(1.0f), shader.getProgram());
		}
		else if (sceneSwitcher % 4 == 0 && curveSwitcher % 2 == 1) {
			curves(square);
			bSpline(square, curve, square.verts.size());
			applyShader(glm::mat4(1.0f), glm::mat4(1.0f), glm::mat4(1.0f), shader.getProgram());
		}
		else if (sceneSwitcher % 4 == 1) {
			glm::vec3 cameraDirection = glm::normalize(cameraPos - cameraTarget);
			glm::vec3 cameraRight = glm::normalize(glm::cross(up, cameraDirection));
			move(cameraPos, cameraFront, cameraUp, 0.0005f);
			look(cameraFront, 0.005f);
			glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
			applyShader(model, view, projection, shader.getProgram());
		}

		else if (sceneSwitcher % 4 == 2) {
			if (revolved == false) {
				revolvedCurve = curve;
				revolution(revolvedCurve);
			}
			revolved = true;
			glm::vec3 cameraDirection = glm::normalize(cameraPos - cameraTarget);
			glm::vec3 cameraRight = glm::normalize(glm::cross(up, cameraDirection));
			move(cameraPos, cameraFront, cameraUp, 0.0005f);
			look(cameraFront, 0.001f);
			glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
			applyShader(model, view, projection, shader.getProgram());
		}

		else if (sceneSwitcher % 4 == 3) {
			if (surfaceMade == false) {
				tensorSquare = square;
				tensorLines = tensor(tensorSquare, tensorSurface, surfaceSwitcher % 2);
			}
			surfaceMade = true;
			glm::vec3 cameraDirection = glm::normalize(cameraPos - cameraTarget);
			glm::vec3 cameraRight = glm::normalize(glm::cross(up, cameraDirection));
			move(cameraPos, cameraFront, cameraUp, 0.0005f);
			look(cameraFront, 0.005f);
			glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
			applyShader(glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f)), glm::translate(view, glm::vec3(-.5f, 0.0f, -5.0f)), projection, shader.getProgram());
		}

		glEnable(GL_LINE_SMOOTH);
		glEnable(GL_FRAMEBUFFER_SRGB);
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		shader.use();
		
		if (sceneSwitcher % 4 == 0) {
			square.cols.clear();
			square.cols.resize(square.verts.size(), glm::vec3{ 0.0, 1.0, 0.0 });
			updateGPUGeometry(linesGPUGeom, square);
			linesGPUGeom.bind();
			glDrawArrays(GL_LINE_STRIP, 0, GLsizei(square.verts.size()));

			square.cols.clear();
			square.cols.resize(square.verts.size(), glm::vec3{ 1.0, 0.0, 0.0 });
			//GPU_Geometry pointsGPUGeom;
			updateGPUGeometry(pointsGPUGeom, square);
			pointsGPUGeom.bind();
			glDrawArrays(GL_POINTS, 0, GLsizei(square.verts.size()));
		}
		
		if (sceneSwitcher % 4 <= 1) {
			curve.cols.clear();
			curve.cols.resize(curve.verts.size(), glm::vec3{ 0.0, 0.0, 0.0 });
			updateGPUGeometry(curveGPUGeom, curve);
			curveGPUGeom.bind();
			glDrawArrays(GL_LINE_STRIP, 0, GLsizei(curve.verts.size()));
		}
		else if (sceneSwitcher % 4 == 2) {
			revolvedCurve.cols.clear();
			revolvedCurve.cols.resize(revolvedCurve.verts.size(), glm::vec3{ 0.0, 0.0, 0.0 });
			updateGPUGeometry(curveGPUGeom, revolvedCurve);
			curveGPUGeom.bind();
			glDrawArrays(GL_LINES, 0, GLsizei(revolvedCurve.verts.size()));
		}
		else if (sceneSwitcher % 4 == 3) {
			tensorSquare.cols.clear();
			tensorSquare.cols.resize(tensorSquare.verts.size(), glm::vec3{ 1.0, 0.0, 0.0 });
			//GPU_Geometry pointsGPUGeom;
			updateGPUGeometry(pointsGPUGeom, tensorSquare);
			pointsGPUGeom.bind();
			glDrawArrays(GL_POINTS, 0, GLsizei(tensorSquare.verts.size()));

			tensorLines.cols.clear();
			tensorLines.cols.resize(tensorLines.verts.size(), glm::vec3{ 0.0, 1.0, 0.0 });
			updateGPUGeometry(linesGPUGeom, tensorLines);
			linesGPUGeom.bind();
			glDrawArrays(GL_LINES, 0, GLsizei(tensorLines.verts.size()));

			tensorSurface.cols.clear();
			tensorSurface.cols.resize(tensorSurface.verts.size(), glm::vec3{ 0.0, 0.0, 0.0 });
			updateGPUGeometry(curveGPUGeom, tensorSurface);
			curveGPUGeom.bind();
			glDrawArrays(GL_LINES, 0, GLsizei(tensorSurface.verts.size()));
		}

		glDisable(GL_FRAMEBUFFER_SRGB); // disable sRGB for things like imgui

		window.swapBuffers();
	}

	glfwTerminate();
	return 0;
}

