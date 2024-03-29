﻿#include "GamePlay.h"
#include "../Actor/ActorManager.h"
#include "../Actor/EnemyActor.h"
#include "../Actor/FieldActor.h"
#include "../Actor/PlayerActor.h"
#include "../Camera.h"
#include "../Component/TransformComponent.h"
#include "../System/GameSystem.h"
#include "../System/Physics.h"
#include "../UI/Pause.h"
#include "../UI/UIManager.h"
#include "../Utility/Input.h"
#include "../Utility/Collision.h"

GamePlay::GamePlay() :
    SceneBase(),
    mState(GameState::Play) {
    auto p = Actor::instantiate<PlayerActor>();
    p->getTransform()->setPosition(Vector3(0.f, 10.f, 0.f));
    Actor::instantiate<FieldActor>();
    auto e = Actor::instantiate<EnemyActor>();
    e->getTransform()->setPosition(Vector3(0.f, 0.3f, 2.f));
}

GamePlay::~GamePlay() {
    Singleton<ActorManager>::instance().clear();
    Singleton<UIManager>::instance().clear();
    Singleton<GameSystem>::instance().clear();
}

void GamePlay::update() {
    if (mState == GameState::Play) {
        Singleton<ActorManager>::instance().update();

        //if (Input::getKeyDown(Input::KeyCode::Space)) {
        //    new Pause(this);
        //}
    }

    Singleton<GameSystem>::instance().getPhysics()->hit();

    //UIは最後に必ず
    Singleton<UIManager>::instance().update();
}

void GamePlay::draw() const {
    Singleton<ActorManager>::instance().draw();
    Singleton<UIManager>::instance().draw();
    Singleton<Camera>::instance().update(Singleton<ActorManager>::instance().getPlayer());
}

GamePlay::GameState GamePlay::getState() const {
    return mState;
}

void GamePlay::setState(GameState state) {
    mState = state;
}
