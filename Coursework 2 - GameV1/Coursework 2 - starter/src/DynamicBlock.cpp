/*!
@file DynamicBlock.cpp
*/
#pragma once

#include "DynamicBlock.h"

DynamicBlock::DynamicBlock(b2World * world, b2Body * fixedBody, b2Body * fixedBody2, b2Body * dynamicBody)
{
	//! m_block (mid-screen pendulum) properties
	m_block.setSize(sf::Vector2f(1.5, 0.2));
	m_block.setFillColor(sf::Color::Blue);
	m_block.setOrigin(m_block.getSize() * 0.5f);
	m_block.setPosition(3.3, 0.5);

	l_bodyDef.type = b2_dynamicBody;
	l_bodyDef.position.Set(m_block.getPosition().x, m_block.getPosition().y);
	l_bodyDef.angle = 0;

	m_body = world->CreateBody(&l_bodyDef);

	l_shape.SetAsBox(m_block.getSize().x * 0.5, m_block.getSize().y * 0.5);

	l_fixtureDef.density = 1;
	l_fixtureDef.friction = 0.2;
	l_fixtureDef.restitution = 0.6;
	l_fixtureDef.shape = &l_shape;

	m_body->CreateFixture(&l_fixtureDef);


	//! m_block2 (hole filler) properties
	m_block2.setSize(sf::Vector2f(1.0, 0.6));
	m_block2.setFillColor(sf::Color::Yellow);
	m_block2.setOrigin(m_block2.getSize() * 0.5f);
	m_block2.setPosition(2.6, 0.5);

	l_bodyDef2.type = b2_dynamicBody;
	l_bodyDef2.position.Set(m_block2.getPosition().x, m_block2.getPosition().y);
	l_bodyDef2.angle = 0;

	m_body2 = world->CreateBody(&l_bodyDef2);

	l_shape2.SetAsBox(m_block2.getSize().x * 0.5, m_block2.getSize().y * 0.5);

	l_fixtureDef2.density = 5;
	l_fixtureDef2.friction = 0.1;
	l_fixtureDef2.restitution = 0.1;
	l_fixtureDef2.shape = &l_shape2;

	m_body2->CreateFixture(&l_fixtureDef2);


	//! m_block3 (left-screen pendulum) properties
	m_block3.setSize(sf::Vector2f(0.15, 1.5));
	m_block3.setFillColor(sf::Color::Blue);
	m_block3.setOrigin(m_block3.getSize() * 0.5f);
	m_block3.setPosition(0.3, 1.2);

	l_bodyDef3.type = b2_dynamicBody;
	l_bodyDef3.position.Set(m_block3.getPosition().x, m_block3.getPosition().y);
	l_bodyDef3.angle = 0;

	m_body3 = world->CreateBody(&l_bodyDef3);

	l_shape3.SetAsBox(m_block3.getSize().x * 0.5, m_block3.getSize().y * 0.5);

	l_fixtureDef3.density = 1;
	l_fixtureDef3.friction = 0.2;
	l_fixtureDef3.restitution = 0.6;
	l_fixtureDef3.shape = &l_shape3;

	m_body3->CreateFixture(&l_fixtureDef3);


	//! m_joints set up 
	jd.collideConnected = false;

	anchor.Set(m_block2.getPosition().x, m_block2.getPosition().y);
	jd.Initialize(m_body, m_body2, anchor);
	m_joint = world->CreateJoint(&jd);

	anchor = fixedBody->GetPosition();
	jd.Initialize(m_body, fixedBody, anchor);
	m_joint2 = world->CreateJoint(&jd);

	anchor = fixedBody2->GetPosition();
	jd.Initialize(fixedBody2, m_body3, anchor);
	m_joint3 = world->CreateJoint(&jd);

	anchor = dynamicBody->GetPosition();
	jd.Initialize(m_body3, dynamicBody, anchor);
	m_joint4 = world->CreateJoint(&jd);
}

void DynamicBlock::update()
{
	//! m_block update position
	b2Vec2 pos = m_body->GetPosition();
	m_block.setPosition(pos.x, pos.y);
	float angle = m_body->GetAngle()* RAD2DEG;
	m_block.setRotation(angle);

	//! m_block2 update position
	b2Vec2 pos2 = m_body2->GetPosition();
	m_block2.setPosition(pos2.x, pos2.y);
	float angle2 = m_body2->GetAngle()* RAD2DEG;
	m_block2.setRotation(angle2);
	
	//! m_block3 update position
	b2Vec2 pos3 = m_body3->GetPosition();
	m_block3.setPosition(pos3.x, pos3.y);
	float angle3 = m_body3->GetAngle()* RAD2DEG;
	m_block3.setRotation(angle3);
}

void DynamicBlock::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//! m_blocks are drawn, m_block is drawn on top of m_block2 to help with joint debugging
	target.draw(m_block2);
	target.draw(m_block);
	target.draw(m_block3);
}

void DynamicBlock::mouseClick(sf::Vector2f mousePosition, b2World * world, b2Body * fixedBody, b2Body * fixedBody2)
{
	mousePosition = mousePosition * 0.01f;

	if (m_block.getGlobalBounds().contains(mousePosition))
	{
		world->DestroyJoint(m_joint);
		jd.Initialize(m_body, fixedBody, anchor);
		m_joint = world->CreateJoint(&jd);
	}
		
	if (m_block3.getGlobalBounds().contains(mousePosition))
	{
		world->DestroyJoint(m_joint4);
		jd.Initialize(m_body3, fixedBody2, anchor);
		m_joint4 = world->CreateJoint(&jd);
	}
	
	

}

void DynamicBlock::reset(b2World * world, b2Body * fixedBody, b2Body * fixedBody2, b2Body * dynamicBody)
{
	//! Reset block positions and joints
	cout << "Reset Block" << endl;

	//! Destroy bodies to prevent duplicates
	world->DestroyBody(m_body);
	world->DestroyBody(m_body2);
	world->DestroyBody(m_body3);

	//! m_block (mid-screen pendulum) reset
	m_block.setPosition(3.3, 0.5);

	l_bodyDef.type = b2_dynamicBody;
	l_bodyDef.position.Set(m_block.getPosition().x, m_block.getPosition().y);
	l_bodyDef.angle = 0;

	m_body = world->CreateBody(&l_bodyDef);

	l_shape.SetAsBox(m_block.getSize().x * 0.5, m_block.getSize().y * 0.5);

	l_fixtureDef.density = 1;
	l_fixtureDef.friction = 0.2;
	l_fixtureDef.restitution = 0.6;
	l_fixtureDef.shape = &l_shape;

	m_body->CreateFixture(&l_fixtureDef);


	//! m_block2 (hole filler) reset
	m_block2.setPosition(2.6, 0.5);

	l_bodyDef2.type = b2_dynamicBody;
	l_bodyDef2.position.Set(m_block2.getPosition().x, m_block2.getPosition().y);
	l_bodyDef2.angle = 0;

	m_body2 = world->CreateBody(&l_bodyDef2);

	l_shape2.SetAsBox(m_block2.getSize().x * 0.5, m_block2.getSize().y * 0.5);

	l_fixtureDef2.density = 5;
	l_fixtureDef2.friction = 0.1;
	l_fixtureDef2.restitution = 0.1;
	l_fixtureDef2.shape = &l_shape2;

	m_body2->CreateFixture(&l_fixtureDef2);


	//! m_block3 (left-screen pendulum) reset
	m_block3.setPosition(0.3, 1.2);

	l_bodyDef3.type = b2_dynamicBody;
	l_bodyDef3.position.Set(m_block3.getPosition().x, m_block3.getPosition().y);
	l_bodyDef3.angle = 0;

	m_body3 = world->CreateBody(&l_bodyDef3);

	l_shape3.SetAsBox(m_block3.getSize().x * 0.5, m_block3.getSize().y * 0.5);

	l_fixtureDef3.density = 1;
	l_fixtureDef3.friction = 0.2;
	l_fixtureDef3.restitution = 0.6;
	l_fixtureDef3.shape = &l_shape3;

	m_body3->CreateFixture(&l_fixtureDef3);


	//! m_joints set up 
	jd.collideConnected = false;

	b2Vec2 anchor;

	anchor.Set(m_block2.getPosition().x, m_block2.getPosition().y);
	jd.Initialize(m_body, m_body2, anchor);
	m_joint = world->CreateJoint(&jd);

	anchor = fixedBody->GetPosition();
	jd.Initialize(m_body, fixedBody, anchor);
	m_joint2 = world->CreateJoint(&jd);

	anchor = fixedBody2->GetPosition();
	jd.Initialize(fixedBody2, m_body3, anchor);
	m_joint3 = world->CreateJoint(&jd);

	anchor = dynamicBody->GetPosition();
	jd.Initialize(m_body3, dynamicBody, anchor);
	m_joint4 = world->CreateJoint(&jd);
}
