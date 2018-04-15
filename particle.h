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

class particle
{

public:

	RectangleShape eachParticle;	// Each particle
	Vector2f vel;					// Particle's velocity
	Vector2f pos;					// Particle's position
	float angle;					// Angle of particle
	float speed;					// Speed of particle
	float newLifetime;				// Particle's lifetime
	float size;						// Particle's size
	float dt;						// Delta Time
	float start_size;				// To determine the size of the particle
	float final_size;				// The amount to increase/decrease the size of the particle

	particle();
	particle(float newPosX, float newPosY, Vector2f newVel, float angle, float lifeTime, float start_size, float final_size, int color1, int color2, int color3, int emitterX, int emitterY);
	~particle();
	Vector2f getParticlePos();
	sf::RectangleShape *moveParticle(float dt);
};

