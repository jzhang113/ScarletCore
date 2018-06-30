#include "stdafx.h"
#include "Game.h"
#include "SpriteComponent.h"

const std::string PLAYER_ID("player");
const sf::Color BASE_COLOR(sf::Color::Black);
const double MAX_FRAME_TIME(0.2);
const double FPS(60.);
const double DELTA_TIME(1 / FPS);

Game::Game(sf::RenderTarget& render_target)
: render_target_(&render_target), rendering_system_(render_target), running_(true)
{
}

void Game::init()
{
	load_resources();

	world_.addSystem(health_system_);
	world_.addSystem(death_system_);
	world_.addSystem(rendering_system_);
	world_.addSystem(move_system_);

	for (auto i = 0; i < 1000; i++)
	{
		auto unit = world_.createEntity();

		auto& particle_position = unit.addComponent<PositionComponent>();
		particle_position.x = 200;
		particle_position.y = 200;

		auto& particle_velocity = unit.addComponent<VelocityComponent>();
		particle_velocity.dx = std::rand() % 1000 - 500;
		particle_velocity.dy = std::rand() % 1000 - 500;

		auto& particle_life = unit.addComponent<LifeComponent>();
		particle_life.life = 100;

		auto& particle_color = unit.addComponent<ColorComponent>();
		particle_color.color = sf::Color(std::rand() % 256, std::rand() % 256, std::rand() % 256);

		unit.activate();
	}
}

void Game::update(const double dt)
{
	world_.refresh();
	health_system_.update(dt);
	move_system_.update(dt);
	death_system_.update();
}

void Game::run(sf::RenderWindow& render_window)
{
	auto current_time = std::chrono::system_clock::now();
	double accumulator = 0;

	sf::Event event;
	while (is_running())
	{
		while (render_window.pollEvent(event))
		{
			handle_events(event);
		}

		const auto new_time = std::chrono::system_clock::now();
		auto frame_time = std::chrono::duration_cast<std::chrono::duration<double>>(new_time - current_time).count();
		current_time = new_time;

		// cap the loop delta time
		if (frame_time >= MAX_FRAME_TIME)
			frame_time = MAX_FRAME_TIME;

		accumulator += frame_time;

		// update the game
		while (accumulator >= DELTA_TIME)
		{
			update(DELTA_TIME);
			accumulator -= DELTA_TIME;
		}

		render();
		render_window.display();
	}
}

void Game::render() const
{
	render_target_->clear(BASE_COLOR);
	rendering_system_.render();
}

void Game::handle_events(const sf::Event event)
{
	switch (event.type)
	{
	case sf::Event::Closed:
		quit();
		break;
	case sf::Event::KeyPressed:
		switch (event.key.code)
		{
		case sf::Keyboard::Key::Escape:
			quit();
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

void Game::load_resources()
{
	if (!texture_map_[PLAYER_ID].loadFromFile("images/playerSpriteSheet.png"))
	{
		std::cerr << "player texture cannot be loaded" << std::endl;
		quit();
	}
}
