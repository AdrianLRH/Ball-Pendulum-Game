/*!
@file DynamicBlock.h
*/
#pragma once

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <iostream>

using namespace std;

//! For calculating rotation angles
#define DEG2RAD 0.017453f;
#define RAD2DEG 57.29577f;

class DynamicBlock : public sf::Drawable
{
public:
	DynamicBlock() {}; //!< Default constructor
	DynamicBlock(b2World * world, b2Body * fixedBody, b2Body * fixedBody2, b2Body * dynamicBody); //!< b2 World constructor
	
	void update(); //!< Update moving objects
	void draw(sf::RenderTarget& target, sf::RenderStates states) const; //!< Draw function
	void mouseClick(sf::Vector2f mousePosition, b2World * world, b2Body * fixedBody, b2Body * fixedBody2); //!< Handles mouse input
	void reset(b2World * world, b2Body * fixedBody, b2Body * fixedBody2, b2Body * dynamicBody); //!< Resets block positions when a button is pressed

private:
	//! 4 joints that connect to various objects
	b2Joint * m_joint;
	b2Joint * m_joint2;
	b2Joint * m_joint3;
	b2Joint * m_joint4;

	//! Game world contains 3 dynamic blocks, each with a body
	sf::RectangleShape m_block;
	sf::RectangleShape m_block2;
	sf::RectangleShape m_block3;

	//! box2d defs are global for use in multiple functions
	b2Body * m_body;
	b2BodyDef l_bodyDef;
	b2PolygonShape l_shape;
	b2FixtureDef l_fixtureDef;

	b2Body * m_body2;
	b2BodyDef l_bodyDef2;
	b2PolygonShape l_shape2;
	b2FixtureDef l_fixtureDef2;

	b2Body * m_body3;
	b2BodyDef l_bodyDef3;
	b2PolygonShape l_shape3;
	b2FixtureDef l_fixtureDef3;

	b2Vec2 anchor;
	b2RevoluteJointDef jd;
};