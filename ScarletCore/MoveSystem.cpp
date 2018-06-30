#include "stdafx.h"
#include "MoveSystem.h"

void MoveSystem::update(const double dt) const
{
	auto entities = getEntities();
	for (auto& entity : entities)
	{
		auto& position = entity.getComponent<PositionComponent>();
		auto& velocity = entity.getComponent<VelocityComponent>();

		position.x += dt * velocity.dx;
		position.y += dt * velocity.dy;
	}
}
