#pragma once

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


class particleSystem
{
public:
	vector<particle> particleVector2;		//Particle System Vector holding particles
	float newPosX2, newPosY2;				//Position of the particles
	int new1Color1, new2Color2, new3Color3;	//Color of the particle system
	float newEmitterX, newEmitterY;			//Emitter point for each particle system

	particleSystem();
	particleSystem(int numOfParticles, int newColor1, int newColor2, int newColor3, int emitterX, int emitterY);
	~particleSystem();
};

