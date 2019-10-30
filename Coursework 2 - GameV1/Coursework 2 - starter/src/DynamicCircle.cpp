/*!
@file DynamicCircle.cpp
*/
#pragma once

#include "DynamicCircle.h"

DynamicCircle::DynamicCircle(b2World * world)
{
	//! m_ball properties
	m_ball.setRadius(0.2f);
	m_ball.setFillColor(sf::Color::White);
	m_ball.setOutlineColor(sf::Color::Black);
	m_ball.setOutlineThickness(-0.05f);
	m_ball.setOrigin(0.2f, 0.2f);
	m_ball.setPosition(0.3f, 1.9f);

	l_bodyDef.type = b2_dynamicBody;
	l_bodyDef.position.Set(m_ball.getPosition().x, m_ball.getPosition().y);
	l_bodyDef.angle = 0;

	m_ballBody = world->CreateBody(&l_bodyDef);

	l_shape.m_radius = 0.2;
	
	l_fixtureDef.density = 3;
	l_fixtureDef.friction = 0.2;
	l_fixtureDef.restitution = 0.3;
	l_fixtureDef.shape = &l_shape;

	m_ballBody->CreateFixture(&l_fixtureDef);
}

void DynamicCircle::update()
{
	//! m_ball update position
	b2Vec2 pos = m_ballBody->GetPosition();
	m_ball.setPosition(pos.x, pos.y);
	float angle = -m_ballBody->GetAngle()* RAD2DEG;
	m_ball.setRotation(angle);
}

void DynamicCircle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//! draw object
	target.draw(m_ball);
}

void DynamicCircle::reset(b2World * world)
{
	//! Reset block positions
	cout << "Reset Circle" << endl;

	//! Destroy body to prevent duplicates
	world->DestroyBody(m_ballBody);
	
	m_ball.setPosition(0.3f, 1.9f);

	l_bodyDef.type = b2_dynamicBody;
	l_bodyDef.position.Set(m_ball.getPosition().x, m_ball.getPosition().y);
	l_bodyDef.angle = 0;

	m_ballBody = world->CreateBody(&l_bodyDef);

	l_shape.m_radius = 0.2;

	l_fixtureDef.density = 3;
	l_fixtureDef.friction = 0.2;
	l_fixtureDef.restitution = 0.3;
	l_fixtureDef.shape = &l_shape;

	m_ballBody->CreateFixture(&l_fixtureDef);
}
