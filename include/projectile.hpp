#pragma once
#include "custom_entities.hpp"
#include "player.hpp"

class Projectile : public MovingEntity{
    float acceleration, projectileRadius;
    std::shared_ptr<Player> Player;
    void Move() override;

    protected:
    
    public:
    
    Projectile(float acceleration, float speed, GameFr::Vector2 direction, float projectileRadius, std::shared_ptr<GameFr::Entity2D> Player);
    void Update() override;
    //event
};