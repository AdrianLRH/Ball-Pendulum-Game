/*!
@file StaticBlock.cpp
*/
#pragma once

#include "StaticBlock.h"

using namespace std;

StaticBlock::StaticBlock(b2World * world)
{
	//! m_block properties
	m_block.setSize(sf::Vector2f(0.3, 0.3));
	m_block.setFillColor(sf::Color::Red);
	m_block.setOrigin(0.15, 0.15);
	m_block.setPosition(4, 0.5);

	b2BodyDef l_bodyDef;
	b2PolygonShape l_shape;
	b2FixtureDef l_fixtureDef;

	l_bodyDef.type = b2_staticBody;
	l_bodyDef.position.Set(m_block.getPosition().x, m_block.getPosition().y);
	l_bodyDef.angle = 0;

	m_body = world->CreateBody(&l_bodyDef);

	l_shape.SetAsBox(0.15, 0.15);

	l_fixtureDef.density = 1;
	l_fixtureDef.shape = &l_shape;


	//! m_block2 properties
	m_block2.setSize(sf::Vector2f(0.3, 0.3));
	m_block2.setFillColor(sf::Color::Red);
	m_block2.setOrigin(0.15, 0.15);
	m_block2.setPosition(0.3, 0.5);

	b2BodyDef l_bodyDef2;
	b2PolygonShape l_shape2;
	b2FixtureDef l_fixtureDef2;

	l_bodyDef2.type = b2_staticBody;
	l_bodyDef2.position.Set(m_block2.getPosition().x, m_block2.getPosition().y);
	l_bodyDef2.angle = 0;

	m_body2 = world->CreateBody(&l_bodyDef2);

	l_shape2.SetAsBox(0.15, 0.15);

	l_fixtureDef2.density = 1;
	l_fixtureDef2.shape = &l_shape2;
}

void StaticBlock::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//! draw object
	target.draw(m_block);
	target.draw(m_block2);
}