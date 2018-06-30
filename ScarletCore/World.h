#pragma once
#include "IComponent.h"

class World
{
public:
	World();

	template <typename T>
	void register_component<T>();

	IComponent* get_component(int component_id);

private:
	std::vector<IComponent&> component_list_{};
};

