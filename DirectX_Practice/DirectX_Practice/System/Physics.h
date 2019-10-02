#pragma once

#include "../Utility/Math.h"
//#include "../Utility/Collision.h"
#include <vector>
#include <functional>
#include <memory>

class GamePlay;
class BoxComponent;
class Actor;

class Physics {
//public:
//    struct CollisionInfo {
//        //衝突した点
//        Vector3 mPoint;
//        //衝突した点の法線
//        Vector3 mNormal;
//        //交差したコンポーネント
//        BoxComponent* mBox;
//        //コンポーネントを所有するアクター
//        Actor* mActor;
//    };
//
//    bool rayCast(const Ray& ray, CollisionInfo* outColl);
//    //総当たり判定
//    void sweepAndPrune(std::function<void(Actor*, Actor*)> f);
//
//    //ボックスコンポーネントの追加・削除
//    void addBox(BoxComponent* box);
//    void removeBox(BoxComponent* box);
//
//    //全当たり判定の取得
//    const std::vector<BoxComponent*>& getBoxes() const;
//
//private:
//    std::vector<BoxComponent*> mBoxes;
};
