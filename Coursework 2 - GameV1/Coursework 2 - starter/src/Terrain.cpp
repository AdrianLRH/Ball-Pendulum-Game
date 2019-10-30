/*!
@file Terrain.cpp
*/
#pragma once

#include "Terrain.h"

Terrain::Terrain(b2World * world)
{
	//! Defining array which stores terrain coordinates
	int numPoints = 28;
	m_terrain = sf::VertexArray(sf::TriangleStrip, numPoints);

	//! coordinates that make up the shape of the terrain
	m_terrain[0].position = sf::Vector2f(0.0,  3.00);
	m_terrain[1].position = sf::Vector2f(0.0,  6.00);
	m_terrain[2].position = sf::Vector2f(0.50, 3.20);
	m_terrain[3].position = sf::Vector2f(0.50, 6.00);
	m_terrain[4].position = sf::Vector2f(1.00, 3.40);
	m_terrain[5].position = sf::Vector2f(1.00, 6.00);
	m_terrain[6].position = sf::Vector2f(2.00, 4.00);
	m_terrain[7].position = sf::Vector2f(2.00, 6.00);
	m_terrain[8].position = sf::Vector2f(3.25, 4.50);
	m_terrain[9].position = sf::Vector2f(3.25, 6.00);
	m_terrain[10].position = sf::Vector2f(4.30, 4.50);
	m_terrain[11].position = sf::Vector2f(4.30, 6.00);
	m_terrain[12].position = sf::Vector2f(4.30, 5.10);
	m_terrain[13].position = sf::Vector2f(4.30, 6.00);
	m_terrain[14].position = sf::Vector2f(5.50, 5.10);
	m_terrain[15].position = sf::Vector2f(5.50, 6.00);
	m_terrain[16].position = sf::Vector2f(5.50, 4.50);
	m_terrain[17].position = sf::Vector2f(5.50, 6.00);
	m_terrain[18].position = sf::Vector2f(6.50, 4.50);
	m_terrain[19].position = sf::Vector2f(6.50, 6.00);
	m_terrain[20].position = sf::Vector2f(6.50, 4.75);
	m_terrain[21].position = sf::Vector2f(6.50, 6.00);
	m_terrain[22].position = sf::Vector2f(7.50, 4.75);
	m_terrain[23].position = sf::Vector2f(7.50, 6.00);
	m_terrain[24].position = sf::Vector2f(7.50, 4.00);
	m_terrain[25].position = sf::Vector2f(7.50, 6.00);
	m_terrain[26].position = sf::Vector2f(8.00, 4.00);
	m_terrain[27].position = sf::Vector2f(8.00, 6.00);


	for (int i = 0; i < numPoints; i++)
	{
		m_terrain[i].color = sf::Color::Green;
	}

	//! creating a body and collision for terrain
	b2BodyDef bd;
	m_body = world->CreateBody(&bd);

	b2EdgeShape shape;

	b2FixtureDef fd;
	fd.shape = &shape;
	fd.density = 0.0f;
	fd.friction = 0.6f;

	for (size_t i = 0; i < numPoints - 2; i=i+1)
	{
		shape.Set(b2Vec2(m_terrain[i].position.x, m_terrain[i].position.y), b2Vec2(m_terrain[i+2].position.x, m_terrain[i+2].position.y));
		m_body->CreateFixture(&fd);
	}

}

void Terrain::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//! Drawing terrain
	target.draw(m_terrain);
}