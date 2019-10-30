/*!
@file SensorContactListener.cpp
*/
#include "SensorContactListener.h"

void SensorContactListener::BeginContact(b2Contact * contact)
{
	//! Assigning fixtures
	b2Fixture* fixtureA = contact->GetFixtureA();
	b2Fixture* fixtureB = contact->GetFixtureB();


	bool isSensorA = fixtureA->IsSensor();
	bool isSensorB = fixtureB->IsSensor();

	HitSensor * sensor = nullptr;

	//! Listens for contact
	if (isSensorA)
	{
		sensor = static_cast<HitSensor*>(fixtureA->GetBody()->GetUserData());
	}
	else if (isSensorB)
	{
		sensor = static_cast<HitSensor*>(fixtureA->GetBody()->GetUserData());
	}

	if (sensor != nullptr)
	{
		sensor->hit();
	}
}
