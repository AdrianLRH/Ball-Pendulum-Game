/*!
@file DynamicCircle.h
*/
#pragma once

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <iostream>

using namespace std;

//! For calculating rotation angles
#define DEG2RAD 0.017453f;
#define RAD2DEG 57.29577f;

class DynamicCircle : public sf::Drawable
{
public:
	DynamicCircle() {} //!< default constructor
	DynamicCircle(b2World * world); //!< b2World constructor
	
	void update(); //!< Update moving object
	void draw(sf::RenderTarget& target, sf::RenderStates states) const; //!< draw function
	b2Body * getBody() { return m_ballBody; } //!< Returns body for use in joints in DynamicBlock class
	void reset(b2World * world); //!< Resets ball position when a button is pressed

private:
	//! Visible ball shape
	sf::CircleShape m_ball;

	//! Ball body
	b2Body * m_ballBody;

	//! b2 defs declared here for use in multiple functions
	b2BodyDef l_bodyDef;
	b2CircleShape l_shape;
	b2FixtureDef l_fixtureDef;
};