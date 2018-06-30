#include "stdafx.h"
#include "HealthSystem.h"

void HealthSystem::update(const double dt) const
{
	auto entities = getEntities();
	for (auto& entity : entities)
	{
		auto& life = entity.getComponent<LifeComponent>();
		life.life -= 20 * dt;
	}
}
