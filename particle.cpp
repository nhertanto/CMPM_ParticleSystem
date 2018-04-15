
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

//Constructor for particle: All the things each particle needs.
particle::particle(float newPosX, float newPosY, Vector2f newVel, float newAngle, float lifeTime, float start_size2, float final_size2, int color1, int color2, int color3, int emitterX, int emitterY)
{
	size = start_size2 - final_size2;
	eachParticle.setSize(Vector2f(size, size));	// Size of particle
	eachParticle.setFillColor(Color(color1, color2, color3));
	pos.x = newPosX;
	pos.y = newPosY;
	eachParticle.setPosition(Vector2f(emitterX, emitterY));
	vel = newVel;
	angle = newAngle;
	newLifetime = lifeTime;
	start_size = start_size2;
	final_size = final_size2;
}

particle::particle()
{

}

particle::~particle()
{
	
}

//Gets each particle's current position
Vector2f particle::getParticlePos()
{
	return eachParticle.getPosition();
}

//Updates and moves the particles during it's lifetime with deltaTime.
sf::RectangleShape *particle::moveParticle(float dt)
{
	Clock clock;

	Vector2f pos = getParticlePos();
	
	vel.x += newLifetime * dt; //To increase the velocity of the particle over time
	vel.y += newLifetime * dt; //To increase the velocity of the particle over time
	//vel.x -= newLifetime * dt; //To decrease the velocity of the particle over time
	//vel.y -= newLifetime * dt; //To decrease the velocity of the particle over time
	
	pos.x += vel.x * angle * dt;
	pos.y += vel.y * angle * dt;
	eachParticle.setPosition(pos.x, pos.y);
	newLifetime -= dt;
	
	size += final_size * dt; // To increase the size of the particle over time
	//size -= final_size * dt; // To decrease the size of the particle over time
	eachParticle.setSize(Vector2f(size, size));

	return &eachParticle;

}