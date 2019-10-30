/*!
@file Game.cpp
*/
#pragma once

#include "Game.h"

Game::Game()
{
	m_gameView.setCenter(4.f, 3.f);
	m_gameView.setSize(8.0, 6.0);

	m_HudView.setCenter(400.f, 300.f);
	m_HudView.setSize(800.f, 600.f);

	//! class objects created, including box2d world
	m_world = new b2World(mk_gravity);
	m_world->SetContactListener(&listener);
	m_DynamicCircle = DynamicCircle(m_world);
	m_StaticBlock = StaticBlock(m_world);
	m_DynamicBlocks = DynamicBlock(m_world, m_StaticBlock.getBody(), m_StaticBlock.getBody2(), m_DynamicCircle.getBody());
	m_HitSensor = HitSensor(m_world);
	m_Terrain = Terrain(m_world);
	
	//! victoryText data
	if (!font.loadFromFile("..\\Fonts\\spaceage.ttf"))
	{
		cout << "Error Loading Font" << endl;

		system("pause");
	}

	m_victoryText.setFont(font);
	m_victoryText.setString("YOU DID IT!!!");
	m_victoryText.setCharacterSize(30);
	m_victoryText.setFillColor(sf::Color::Transparent);
	m_victoryText.setPosition(300.f, 250.f);	

	m_goalSign.setFont(font);
	m_goalSign.setString("Ball\ngoes\nhere");
	m_goalSign.setCharacterSize(15);
	m_goalSign.setFillColor(sf::Color::Black);
	m_goalSign.setPosition(670.f, 350.f);

	m_instructionRB.setFont(font);
	m_instructionRB.setString("Press (R) to reset");
	m_instructionRB.setCharacterSize(15);
	m_instructionRB.setFillColor(sf::Color::Black);
	m_instructionRB.setPosition(575.f, 25.f);

	m_instructionMC.setFont(font);
	m_instructionMC.setString("Click pendulums \nto release objects");
	m_instructionMC.setCharacterSize(15);
	m_instructionMC.setFillColor(sf::Color::Black);
	m_instructionMC.setPosition(75.f, 25.f);
}

void Game::update(float time)
{
	HitSensor * scl = new HitSensor(m_world);

	//! world and dynamic objects updated
	m_world->Step(time, 7, 5);
	m_DynamicCircle.update();
	m_DynamicBlocks.update();

	if (scl->endLevel())
	{
		//! display victory text
		m_victoryText.setFillColor(sf::Color::Red);
	}
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.setView(m_gameView);

	//! draw functions from other classes called
	target.draw(m_Terrain);
	target.draw(m_HitSensor);
	target.draw(m_DynamicCircle);
	target.draw(m_StaticBlock);
	target.draw(m_DynamicBlocks);

	//! draw UI text
	target.setView(m_HudView);

	target.draw(m_victoryText);
	target.draw(m_goalSign);
	target.draw(m_instructionRB);
	target.draw(m_instructionMC);
}

void Game::keyPress(sf::Keyboard::Key key)
{
	//! key press to reset level
	if (key == sf::Keyboard::R)
	{
		//! reset level
		cout << "Reset" << endl;
		m_DynamicCircle.reset(m_world);
		m_DynamicBlocks.reset(m_world, m_StaticBlock.getBody(), m_StaticBlock.getBody2(), m_DynamicCircle.getBody());
		m_HitSensor.setEndLevelFalse();
		m_victoryText.setFillColor(sf::Color::Transparent);
	}
}

void Game::mouseClick(sf::Vector2f mousePosition)
{
	//! click on objects to remove joints in-game
	m_DynamicBlocks.mouseClick(mousePosition, m_world, m_StaticBlock.getBody(), m_StaticBlock.getBody2());
}
