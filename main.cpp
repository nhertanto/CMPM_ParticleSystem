
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

//Function Prototypes
//void update_state(float dt);
//void render_frame();

//Variables
RenderWindow window;						//Creating the window
vector <particleSystem> particleSysVec;		//Vector holding particles						
int numOfParticles = 100;					//Number of particles in a system
int color1, color2, color3;
int emitterX, emitterY;
float start_size, final_size;

int main()
{
	//Create the window
	window.create(sf::VideoMode(500, 500), "Particle System!");	
	
	//Setting the clock
	Clock clock;

	//Set random number seed
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	
	while (window.isOpen())
	{	
		//Adds or substracts number of particles in the system
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			numOfParticles = numOfParticles + 25;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			numOfParticles = numOfParticles - 25;
		}

		//Initialize each particle system with it's own color and emitter point. Push this information into a vector
		while (3 > particleSysVec.size())
		{
			//Adjusting the color for each particle system
			color1 = rand() & 250 + 1;
			color2 = rand() % 250 + 1;
			color3 = rand() % 250 + 1;

			//Adjusting emitter for each particle system
			emitterX = rand() % 250 + 1;
			emitterY = rand() % 250 + 1;

			//Setting the start and final size of the particle
			float start_size = rand() % 10 + 4;
			float final_size = rand() % 3 + 1;

			//Creates one particle system
			particleSystem particleSys(numOfParticles, color1, color2, color3, emitterX, emitterY);
			particleSysVec.push_back(particleSys);
		}

		//Initialize Delta time
		float dt = clock.restart().asSeconds();

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		} 
		
		window.clear(Color(255, 198, 216));
		
		//Drawing each particle systems
		for (int j = 0; j < particleSysVec.size(); j++)
		{
			//Drawing each particle for each particle systems. Removes particles when the particle's lifetime is less than 0
			for (int i = 0; i < particleSysVec[j].particleVector2.size(); i++)
			{

				if (particleSysVec[j].particleVector2[i].newLifetime > 0)
				{
					window.draw(*particleSysVec[j].particleVector2[i].moveParticle(dt));
				}
				else
				{
					particleSysVec[j].particleVector2.erase(particleSysVec[j].particleVector2.begin() + j);
				}
			}
			//Updates and makes new particles whenever a particle dies
			while (numOfParticles > particleSysVec[j].particleVector2.size())
			{
				Vector2f newVel;
				newVel.x = rand() % 360 + 1;
				newVel.y = rand() % 360 + 1;
				int angle1 = rand() % 360 + 1;
				int angle2 = rand() % 360 + 1;
				float angle = tan(angle1 / angle2);
				float lifeTime = rand() % 200 + 1;
				float start_size = rand() % 10 + 4;
				float final_size = rand() % 3 + 1;

				particle particlePush(particleSysVec[j].newPosX2, particleSysVec[j].newPosY2, newVel, angle, lifeTime, start_size, final_size, particleSysVec[j].new1Color1, particleSysVec[j].new2Color2, particleSysVec[j].new3Color3, particleSysVec[j].newEmitterX, particleSysVec[j].newEmitterY);
				particleSysVec[j].particleVector2.push_back(particlePush);
			}
		}
		window.display();
	}
	return 0;
}
