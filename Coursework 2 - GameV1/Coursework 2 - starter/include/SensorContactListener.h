/*!
@file SensorContactListener.h
*/
#pragma once

#include <Box2D\Box2D.h>

#include "HitSensor.h"

class SensorContactListener : public b2ContactListener
{
public:
	void BeginContact(b2Contact* contact); //!< Called when two fixtures begin to touch
};