/*!
@file HitSensor.cpp
*/
#pragma once

#include "HitSensor.h"

HitSensor::HitSensor(b2World * world)
{
	//! goalFlag Properties
	goalFlag.setSize(sf::Vector2f(1.0, 0.1));
	goalFlag.setOrigin(goalFlag.getSize() * 0.5f);
	goalFlag.setPosition(7.0f, 4.70);
	goalFlag.setFillColor(sf::Color::White);
	goalFlag.setOutlineColor(sf::Color::Black);
	goalFlag.setOutlineThickness(-0.02);

	//! set up goalFlag body
	b2BodyDef l_bodyDef;
	b2PolygonShape l_boxShape;
	b2FixtureDef l_fixtureDef;

	l_bodyDef.position.Set(goalFlag.getPosition().x, goalFlag.getPosition().y);
	l_bodyDef.angle = 0.f;

	goalFlagBody = world->CreateBody(&l_bodyDef);

	l_boxShape.SetAsBox(0.3, 0.05);

	l_fixtureDef.shape = &l_boxShape;
	l_fixtureDef.isSensor = true;

	goalFlagBody->SetUserData(this);

	goalFlagBody->CreateFixture(&l_fixtureDef);
}

bool HitSensor::endLevel()
{
	return m_endLevel;
}

void HitSensor::setEndLevelFalse()
{
	m_endLevel = false;
}

void HitSensor::hit()
{
	m_endLevel = true;
}

void HitSensor::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	//! Sensor is drawn, sensor has a graphic primarily to assist with debugging
	target.draw(goalFlag);
}