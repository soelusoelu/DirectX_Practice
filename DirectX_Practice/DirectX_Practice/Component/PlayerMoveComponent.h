#pragma once

#include "Component.h"
#include <memory>

class Actor;
class BoxComponent;

class PlayerMoveComponent : public Component {
    enum State {
        OnGround,
        FlyingUp,
        FlyingDown
    };
public:
    PlayerMoveComponent(Actor* owner, int updateOrder = 10);
    virtual void start() override;
    virtual void update() override;

private:
    bool canMovement();

    float mSpeed;
    float mJumpPower;
    float mBreakPower;
    const float FALL_SPEED;
    State mState;
    //std::shared_ptr<BoxComponent> mBox;
};
