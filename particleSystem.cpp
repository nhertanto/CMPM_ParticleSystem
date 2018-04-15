
#include "particleSystem.h"
#include "particle.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <cmath>
#include <string>
#include <ctime>
#include <vector>
#include <memory>

using namespace sf;
using namespace std;

//Initializing each particle system 
particleSystem::particleSystem(int numOfParticles, int newColor1, int newColor2, int newColor3, int emitterX, int emitterY)
{
	while (numOfParticles > particleVector2.size())
	{
		Vector2f newVel;
		newVel.x = rand() % 360 + 1;
		newVel.y = rand() % 360 + 1;
		float newPosX = rand() % 250 + 10;
		int angle1 = rand() % 360 + 1;
		int angle2 = rand() % 360 + 1;
		float angle = tan(angle1 / angle2);
		float newPosY = rand() % 250 + 1;
		float lifeTime = rand() % 200 + 1;
		float start_size = rand() % 10 + 4;
		float final_size = rand() % 3 + 1;
		int color1 = newColor1;
		int color2 = newColor2;
		int color3 = newColor3;
		
		newEmitterX = emitterX;
		newEmitterY = emitterY;

		newPosX2 = newPosX;
		newPosY2 = newPosY;
		new1Color1 = color1;
		new2Color2 = color2;
		new3Color3 = color3;
		
		particle particlePush(newPosX2, newPosY2, newVel, angle, lifeTime, start_size, final_size, new1Color1, new2Color2, new3Color3, newEmitterX, newEmitterY);
		particleVector2.push_back(particlePush);
	}
}

particleSystem::particleSystem()
{

}

particleSystem::~particleSystem()
{
}