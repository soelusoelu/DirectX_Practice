#include "PlayerActor.h"
#include "../Component/MeshComponent.h"
#include "../Component/PlayerMoveComponent.h"
#include "../Component/TransformComponent.h"

PlayerActor::PlayerActor(const char* tag) :
    Actor(tag),
    mPlayerMove(new PlayerMoveComponent(this)),
    mMesh(new MeshComponent(this, "Chips.obj")) {
    //getTransform()->setScale(0.25f);
}

void PlayerActor::updateActor() {
}

void PlayerActor::drawActor() const {
    mMesh->draw(getWorldTransform());
}
