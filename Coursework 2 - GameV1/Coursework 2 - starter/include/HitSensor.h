/*!
@file HitSensor.h
*/
#pragma once

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

class HitSensor : public sf::Drawable
{
public:
	HitSensor(){} //!< Default constructor
	HitSensor(b2World * world); //!< b2World constructor

	bool endLevel(); //!< Returns boolean "m_endlevel"
	void setEndLevelFalse(); //!< Sets boolean "m_endlevel" to false
	void hit(); //!< Sets boolean "m_endlevel" to true
	void draw(sf::RenderTarget& target, sf::RenderStates states) const; //!< Draw function

private:
	//! Boolean ends the level when true
	bool m_endLevel = false;

	//! "goalFlagBody" is a visible object and a sensor
	sf::RectangleShape goalFlag;
	b2Body * goalFlagBody;

};