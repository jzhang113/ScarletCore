#pragma once
#include "RenderingSystem.h"
#include "HealthSystem.h"
#include "DeathSystem.h"
#include "MoveSystem.h"

class Game
{
public:
	explicit Game(sf::RenderTarget& render_target);

	void init();
	void update(double dt);
	void run(sf::RenderWindow& render_window);
	void render() const;
	void handle_events(sf::Event event);
	void load_resources();

	bool is_running() const
	{
		return running_;
	}

	void quit()
	{
		running_ = false;
	}

private:
	sf::RenderTarget* render_target_{};
	std::map<std::string, sf::Texture> texture_map_{};

	anax::World world_{};
	RenderingSystem rendering_system_;
	HealthSystem health_system_;
	DeathSystem death_system_;
	MoveSystem move_system_;

	bool running_;
};

