#pragma once
#include "LifeComponent.h"

struct DeathSystem : anax::System<anax::Requires<LifeComponent>>
{
	void update() const;
};

