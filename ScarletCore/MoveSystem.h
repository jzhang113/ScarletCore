#pragma once
#include "PositionComponent.h"
#include "VelocityComponent.h"

struct MoveSystem : anax::System<anax::Requires<PositionComponent, VelocityComponent>>
{
	void update(double dt) const;
};
