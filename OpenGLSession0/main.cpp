#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <cstdlib> 
#include <ctime> 


#include "Resources/Shaders/shaderClass.h"
#include "Resources/Shaders/VAO.h"
#include "Resources/Shaders/VBO.h"
#include "Resources/Shaders/EBO.h"
#include "Camera.h"
#include "Pokal.h"
#include "Player.h"
#include "LSM.h"
#include "SphereCollition.h"
#include "stb_image.h"



const unsigned int width = 1920;
const unsigned int height = 1080;
using namespace std;

void processInput(GLFWwindow* window);


int main()
{
	// Initialize GLFW
	glfwInit();

	// Tell GLFW what version of OpenGL we are using 
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	
	GLFWwindow* window = glfwCreateWindow(width, height, "OpenGLProject", NULL, NULL);
	// Error check if the window fails to create
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);
	
	//Load GLAD so it configures OpenGL
	gladLoadGL();
	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800

	
	glViewport(0, 0, width, height);

	Shader shaderProgram("default.vert", "default.frag");
	shaderProgram.Activate();

	
	
	std::vector<Player> myPokaler;
	std::srand(static_cast<unsigned>(std::time(nullptr)));
	float maxX = 18;
	float minX = -18;
	float maxZ = 18;
	float minZ = -18;
	const int maxPokals = 8;
	int score = 0;
	float scale = -7;

	// creating objects
	
	Player myPlayer(1.0f, glm::vec3(0,0,20), 1, 1, 1, 1);
	
	Player myPlane(20.0f, glm::vec3(0, -21, 0), 0.f, 1.f, 0.f, 4);
	
	Player NPC(1.0f, glm::vec3(0, 0, -5), 1, 1, 1, 1);

	Player Object(1.0f, glm::vec3(0, 0, 0), 1, 1, 1, 1);

	



	unsigned int texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	// set the texture wrapping/filtering options (on the currently bound texture object)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	// load and generate the texture
	int texWidth, texHeight, nrChannels;
	unsigned char* data = stbi_load("Textures/texture.jpg", &texWidth, &texHeight, &nrChannels, 0);
	if (data)
	{
		GLenum format = (nrChannels == 3) ? GL_RGB : GL_RGBA; // Adjust format based on number of channels
		glTexImage2D(GL_TEXTURE_2D, 0, format, texWidth, texHeight, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}

	// Check for OpenGL errors
	GLenum error = glGetError();
	if (error != GL_NO_ERROR)
	{
		std::cerr << "OpenGL error after texture creation: " << error << std::endl;
	}
	stbi_image_free(data);





	shaderProgram.Activate();
	shaderProgram.setInt("ourTexture", 0);

	GLuint uniID = glGetUniformLocation(shaderProgram.ID, "scale");
	float scaleValue = 100.0f;
	

	// Enables the Depth Buffer
	glEnable(GL_DEPTH_TEST);

	
	
	//Camera object
	Camera camera(width, height, glm::vec3(0.0f, 3.0f, 35.0f));
	
	//speed of cube
	float translationSpeed = 0.05f;
	//Collison 
	bool isColldingx = false;
	bool isColldingNegativeX = false;
	bool isColldingz = false;
	bool isColldingNegativeZ = false;
	bool isInHouse = false;


	std::vector<double> patrolPoints = { -1 , 2, 1, -2, 2, 2 }; // points for patrolling
	LSM PatrolPath(patrolPoints, patrolPoints.size() / 2); // the degree of the function, f.exa x^2

	//SphereCollition sc(myPlayer, NPC);
	glfwSwapInterval(1);
	glEnable(GL_DEPTH_TEST);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	while (!glfwWindowShouldClose(window))
	{
		//camera.Position = glm::vec3(myPlayer.position.x, myPlayer.position.y + 5, myPlayer.position.z + 20);
		// Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// Tell OpenGL which Shader Program we want to use
		shaderProgram.Activate();

		NPC.Patrol(PatrolPath.getCoefficients());

		myPlane.calculateBarycentricCoordinates(myPlayer.position, myPlane.planePoints[0], myPlane.planePoints[1], myPlane.planePoints[2], true);
		myPlane.calculateBarycentricCoordinates(myPlayer.position, myPlane.planePoints[2], myPlane.planePoints[3], myPlane.planePoints[0], true);

		myPlane.calculateBarycentricCoordinates(NPC.position, myPlane.planePoints[0], myPlane.planePoints[1], myPlane.planePoints[2], true);
		myPlane.calculateBarycentricCoordinates(NPC.position, myPlane.planePoints[2], myPlane.planePoints[3], myPlane.planePoints[0], true);

		NPC.calculateBarycentricCoordinates(myPlayer.position, NPC.planePoints[0], NPC.planePoints[1], NPC.planePoints[2], false);
		NPC.calculateBarycentricCoordinates(myPlayer.position, NPC.planePoints[2], NPC.planePoints[3], NPC.planePoints[0], false);

		Object.calculateBarycentricCoordinates(myPlayer.position, Object.planePoints[0], Object.planePoints[1], Object.planePoints[2], false);
		Object.calculateBarycentricCoordinates(myPlayer.position, Object.planePoints[2], Object.planePoints[3], Object.planePoints[0], false);

		myPlane.calculateBarycentricCoordinates(Object.position, myPlane.planePoints[0], myPlane.planePoints[1], myPlane.planePoints[2], true);
		myPlane.calculateBarycentricCoordinates(Object.position, myPlane.planePoints[2], myPlane.planePoints[3], myPlane.planePoints[0], true);


		processInput(window);
		myPlayer.inputs(window);
		camera.Inputs(window);


		//Set render distance and FOV
		glm::mat4 viewproj= camera.Matrix(45.0f, 0.1f, 100.0f, shaderProgram, "camMatrix");

		// Drawing player

		glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, texture);
		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, myPlayer.position);
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "camMatrix"), 1, GL_FALSE, glm::value_ptr(viewproj*model));
		myPlayer.BindVAO();
		myPlayer.GetVBO().Bind();
		glDrawArrays(GL_TRIANGLES, 0, myPlayer.mVertecies.size());
		myPlayer.UnbindVAO();

		// Drawing main floor
		glm::mat4 planeModel = glm::mat4(1.0f);
		planeModel = glm::translate(planeModel, myPlane.position);
		planeModel = glm::scale(planeModel, glm::vec3(20, 20, 20));
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "camMatrix"), 1, GL_FALSE, glm::value_ptr(viewproj * planeModel));
		myPlane.BindVAO();
		glDrawArrays(GL_TRIANGLES, 0, myPlane.mVertecies.size());
		myPlane.UnbindVAO();

		// Draw NPC
		glm::mat4 npcModel = glm::mat4(1.0f);
		npcModel = glm::translate(npcModel, NPC.position);
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "camMatrix"), 1, GL_FALSE, glm::value_ptr(viewproj * npcModel));
		NPC.BindVAO();
		NPC.GetVBO().Bind();
		glDrawArrays(GL_TRIANGLES, 0, NPC.mVertecies.size());
		NPC.UnbindVAO();

		// Draw extra object
		glm::mat4 objectModel = glm::mat4(1.0f);
		objectModel = glm::translate(objectModel, Object.position);
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "camMatrix"), 1, GL_FALSE, glm::value_ptr(viewproj * objectModel));
		Object.BindVAO();
		Object.GetVBO().Bind();
		glDrawArrays(GL_TRIANGLES, 0, Object.mVertecies.size());
		Object.UnbindVAO();

		//glUniform1f(uniID, scaleValue);
		//
		//for (int i = 0; i < maxPokals; ++i) {
		//	myPokaler[i].BindVAO();
		//	glDrawArrays(GL_TRIANGLES, 0, myPokaler[i].mVertecies.size());
		//	myPokaler[i].UnbindVAO();
		//}
		
		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}

	
	// Delete all the objects we've created
	
	myPlayer.VAO5.Delete();
	myPlane.VAO5.Delete();
	NPC.VAO5.Delete();

	shaderProgram.Delete();
	
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}