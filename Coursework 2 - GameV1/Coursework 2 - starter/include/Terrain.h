/*!
@file Terrain.h
*/
#pragma once

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

class Terrain : public sf::Drawable
{
public:
	Terrain() {} //!< Default constructor
	Terrain(b2World * world); //!< b2World constructor
	
	void draw(sf::RenderTarget& target, sf::RenderStates states) const; //!< Draws objects

private:
	//! Stores coordinates for drawing terrain
	sf::VertexArray m_terrain;
	//! Body for collision
	b2Body * m_body;	
};