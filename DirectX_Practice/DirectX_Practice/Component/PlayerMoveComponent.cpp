#include "PlayerMoveComponent.h"
//#include "Collider/BoxComponent.h"
#include "TransformComponent.h"
#include "../Actor/Actor.h"
#include "../Actor/ComponentManagementOfActor.h"
#include "../System/GameSystem.h"
//#include "../System/Physics.h"
//#include "../Utility/Collision.h"
#include "../Utility/Input.h"

PlayerMoveComponent::PlayerMoveComponent(Actor* owner, int updateOrder) :
    Component(owner, updateOrder),
    mSpeed(0.f)/*,
    mBox(nullptr)*/ {
}

void PlayerMoveComponent::start() {
    //mBox = mOwner->getComponentManager()->getComponent<BoxComponent>();
}

void PlayerMoveComponent::update() {
    float rotation = Input::horizontal();
    if (!Math::nearZero(rotation)) {
        mOwner->getTransform()->rotate(Vector3::up, rotation);
    }

    mSpeed = Input::vertical() * 0.05f;
    if (!Math::nearZero(mSpeed) && canMovement()) {
        mOwner->getTransform()->translete(mOwner->getTransform()->forward() * mSpeed);
    }
}

bool PlayerMoveComponent::canMovement() {
    //自身の当たり判定が無効になってれば問答無用でtrue
    //if (!mBox->getEnable()) {
    //    return true;
    //}

    //mOwner->computeWorldTransform();

    ////コピーで大丈夫
    //AABB playerBox = mBox->getCollision();
    //playerBox.mMin += mOwner->getTransform()->forward() * mSpeed;
    //playerBox.mMax += mOwner->getTransform()->forward() * mSpeed;

    //const auto& boxes = Singleton<GameSystem>::instance().getPhysics()->getBoxes();
    //for (const auto& box : boxes) {
    //    if (box->getIsTrigger() || !box->getEnable() || box->getOwner()->getTag() == "Player") {
    //        continue;
    //    }
    //    //このアクターと衝突するか？
    //    const AABB& otherBox = box->getCollision();
    //    if (intersect(playerBox, otherBox)) {
    //        return false;
    //    }
    //}

    //誰ともぶつかっていないから動ける
    return true;
}
