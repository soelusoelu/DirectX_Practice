#pragma once

#include "../Utility/Math.h"
#include "../Utility/Collision.h"
#include <vector>
#include <functional>
#include <memory>

class GamePlay;
class BoxComponent;
class Actor;

class Physics {
public:
    struct CollisionInfo {
        //衝突した点
        Vector3 mPoint;
        //衝突した点の法線
        Vector3 mNormal;
        //交差したコンポーネント
        //BoxComponent* mBox;
        //コンポーネントを所有するアクター
        //Actor* mActor;
        float mLength;
    };

    bool rayCast(Ray* ray, CollisionInfo* outColl);
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
private:
    void calcPlane(D3DXPLANE* plane, D3DXVECTOR3* a, D3DXVECTOR3* b, D3DXVECTOR3* c);
    bool intersect(D3DXPLANE plane, Ray* ray, D3DXVECTOR3 v1, D3DXVECTOR3 v2, D3DXVECTOR3 v3, CollisionInfo* outColl);
    bool isInside(D3DXVECTOR3* intersect, D3DXVECTOR3* a, D3DXVECTOR3* b, D3DXVECTOR3* c);
//    std::vector<BoxComponent*> mBoxes;
};
