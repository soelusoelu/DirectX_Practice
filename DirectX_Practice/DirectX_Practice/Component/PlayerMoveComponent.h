#pragma once

#include "Component.h"
#include <memory>

class Actor;
class BoxComponent;

class PlayerMoveComponent : public Component {
public:
    PlayerMoveComponent(Actor* owner, int updateOrder = 10);
    virtual void start() override;
    virtual void update() override;

private:
    bool canMovement();

    float mSpeed;
    //std::shared_ptr<BoxComponent> mBox;
};
