#pragma once
#include "PositionComponent.h"
#include "LifeComponent.h"
#include "ColorComponent.h"

struct RenderingSystem : anax::System<anax::Requires<PositionComponent, LifeComponent, ColorComponent>>
{
	RenderingSystem();
	explicit RenderingSystem(sf::RenderTarget& render_target);

	void render() const;
	void set_render_target(sf::RenderTarget& render_target);
	sf::RenderTarget& get_render_target() const;
	bool is_valid() const;

private:
	sf::RenderTarget* render_target_;
};

