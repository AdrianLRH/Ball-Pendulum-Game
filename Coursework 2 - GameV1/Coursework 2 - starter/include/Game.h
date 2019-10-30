/*!
@file Game.h
*/
#pragma once

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <vector>
#include <iostream>
#include "DynamicBlock.h"
#include "DynamicCircle.h"
#include "HitSensor.h"
#include "StaticBlock.h"
#include "Terrain.h"
#include "SensorContactListener.h"

using namespace std;

class Game : public sf::Drawable
{
public:
	Game(); //!< Default constructor

	void update(float time); //!< Update moving objects
	void draw(sf::RenderTarget& target, sf::RenderStates states) const; //!< Draw function

	void keyPress(sf::Keyboard::Key key); //!< Handles key input
	void mouseClick(sf::Vector2f mousePosition); //!< Handles mouse input

private:
	//! Different views for game and HUD
	sf::View m_gameView;
	sf::View m_HudView;

	//! box2D world object and gravity value
	b2World * m_world;
	const b2Vec2 mk_gravity = b2Vec2(0.f, 10.0f);

	//! Game class associates with all other classes
	Terrain m_Terrain;
	DynamicCircle m_DynamicCircle;
	DynamicBlock m_DynamicBlocks;
	StaticBlock m_StaticBlock;
	HitSensor m_HitSensor;
	SensorContactListener listener;

	//! UI text
	sf::Text m_victoryText; //!< Displays when level is cleared
	sf::Text m_goalSign; //!< Shows the objective
	sf::Text m_instructionRB; //!< Reset button instruction
	sf::Text m_instructionMC; //!< Mouse click instruction
	sf::Font font; //!< Stores font for text
};
