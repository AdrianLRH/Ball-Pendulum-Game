/*!
@file StaticBlock.h
*/
#pragma once

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <iostream>

using namespace std;

class StaticBlock : public sf::Drawable
{
public:
	StaticBlock() {} //!< Default constructor
	StaticBlock(b2World * world); //!< b2World constructor
	
	void draw(sf::RenderTarget& target, sf::RenderStates states) const; //!< Draw function
	
	//! Returns bodies for use in joints in DynamicBlock class
	b2Body * getBody() { return m_body; }
	b2Body * getBody2() { return m_body2; }
private:
	//! Bodies for object collision
	b2Body * m_body;
	b2Body * m_body2;

	//! Visible shape object
	sf::RectangleShape m_block;
	sf::RectangleShape m_block2;
};