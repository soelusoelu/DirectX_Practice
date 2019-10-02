#pragma once

#include <memory>

class Actor;

class Component {
public:
    Component(Actor* owner, int updateOrder = 100);
    virtual ~Component() {};
    //getComponent�͂����ł���
    virtual void start() {};
    virtual void update() = 0;
    //�I�[�i�[��Transform���X�V���ꂽ��
    virtual void onUpdateWorldTransform() {};

    int getUpdateOrder() const;
    Actor* getOwner() const;

protected:
    Actor* mOwner;
    int mUpdateOrder;
};
