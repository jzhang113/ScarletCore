#include "stdafx.h"
#include "RenderingSystem.h"

RenderingSystem::RenderingSystem(): render_target_(nullptr)
{
}

RenderingSystem::RenderingSystem(sf::RenderTarget& render_target): render_target_(&render_target)
{
}

void RenderingSystem::render() const
{
	auto entities = getEntities();
	for (auto& entity : entities)
	{
		auto& position = entity.getComponent<PositionComponent>();
		auto& life = entity.getComponent<LifeComponent>().life;
		auto& color = entity.getComponent<ColorComponent>().color;

		sf::CircleShape circle(life);
		circle.setFillColor(color);
		circle.setPosition(position.x, position.y);
		get_render_target().draw(circle);
	}
}

void RenderingSystem::set_render_target(sf::RenderTarget& render_target)
{
	render_target_ = &render_target;
}

sf::RenderTarget& RenderingSystem::get_render_target() const
{
	assert(is_valid());
	return *render_target_;
}

bool RenderingSystem::is_valid() const
{
	return render_target_ != nullptr;
}
