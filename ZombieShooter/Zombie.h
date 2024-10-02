#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Zombie {
private:
	//how fast
	const float BLOATER_SPEED = 40;
	const float CHASER_SPEED = 80;
	const float CRAWLER_SPEED = 20;
	//how tough
	const float BLOATER_HEALTH = 5;
	const float CHASER_HEALTH = 1;
	const float CRAWLER_HEALTH = 3;
	// make each zombie vary its speed
	const int MAX_VARRIANCE = 30;
	const int OFFSET = 101 - MAX_VARRIANCE;
	//where is this zombie
	Vector2f m_Position;
	Sprite m_Sprite;
	//how fast can this one run
	float m_Speed;
	float m_Health;
	bool m_Alive;
public:
	//handle when a bullet hits
	bool hit();
	//is alive?
	bool isAlive();
	//spawn a new
	void spawn(float startX, float startY, int type, int seed);
	//return a rectangle that is the position int the world
	FloatRect getPosition();
	//get a cope of the sprite to draw
	Sprite getSprite();
	//update the zombie each frame
	void update(float elapsewdTime, Vector2f playerLocation);

};