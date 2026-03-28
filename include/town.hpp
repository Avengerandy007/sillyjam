#pragma once
#include "../include/custom_entities.hpp"

class Town : public EventTiedEntity{
public:
	uint32_t riches;
	uint32_t policePresence;
	void Update() override;
};
