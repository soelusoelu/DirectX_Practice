#include "ActorManager.h"
#include "Actor.h"
#include "PlayerActor.h"
#include "../Component/TransformComponent.h"
#include "../DirectXIncLib.h"

ActorManager::ActorManager() :
    mUpdatingActors(false) {
}

ActorManager::~ActorManager() = default;

void ActorManager::update() {
    mUpdatingActors = true;
    for (auto&& actor : mActors) {
        actor->update();
    }
    mUpdatingActors = false;

    for (auto&& pending : mPendingActors) {
        mActors.emplace(pending);
    }
    mPendingActors.clear();

    removeDeadActor();
}

void ActorManager::draw() const {
    for (const auto& actor : mActors) {
        actor->drawActor();
    }
}

void ActorManager::addActor(Actor* actor) {
    if (mUpdatingActors) {
        mPendingActors.emplace(actor);
    } else {
        mActors.emplace(actor);
    }
    //最初に必ず座標計算
    actor->computeWorldTransform();
}

void ActorManager::clear() {
    mPendingActors.clear();
    mActors.clear();
}

std::shared_ptr<PlayerActor> ActorManager::getPlayer() const {
    std::shared_ptr<PlayerActor> p = nullptr;
    for (const auto& actor : mActors) {
        p = std::dynamic_pointer_cast<PlayerActor>(actor);
        if (p) {
            return p;
        }
    }
    //最後まで見つからなければnullptrを返す
    return p;
}

void ActorManager::removeDeadActor() {
    auto itr = mActors.begin();
    while (itr != mActors.end()) {
        if ((*itr)->getState() == Actor::State::Dead) {
            itr = mActors.erase(itr);
        } else {
            ++itr;
        }
    }
}
