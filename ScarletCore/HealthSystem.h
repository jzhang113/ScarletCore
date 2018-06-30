#pragma once
#include "LifeComponent.h"

struct HealthSystem : anax::System<anax::Requires<LifeComponent>>
{
	void update(double dt) const;
};

