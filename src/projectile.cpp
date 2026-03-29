#include "../include/projectile.hpp"
#include "../include/globals.hpp"

void Projectile::Move(){
    speed -= acceleration;
    Push(direction, speed);
}

Projectile::Projectile(float acceleration, float speed, GameFr::Vector2 direction, float projectileRadius, std::shared_ptr<GameFr::Entity2D> Player){
    this->acceleration = acceleration;
    this->speed = speed;
    this->direction = direction;
    this->projectileRadius = projectileRadius;
}

void Projectile::Update(){
    Move();
    if(CollidingCircle(*player, 1)){
        player->ChangeHP(PROJECTILE_DAMAGE);

        GameFr::Event ev(GameFr::Event::Types::COLLISION, GetPtr(), player, std::nullopt);
        eventInterface.queue->CreateEvent(std::make_shared<const GameFr::Event>(ev));
    }
}
