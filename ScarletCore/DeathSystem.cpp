#include "stdafx.h"
#include "DeathSystem.h"

void DeathSystem::update() const
{
	auto entities = getEntities();
	for (auto& entity : entities)
	{
		auto& life = entity.getComponent<LifeComponent>().life;
		if (life < 0)
			entity.kill();
	}
}
