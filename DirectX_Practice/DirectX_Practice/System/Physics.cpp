//#include "Physics.h"
//#include "../Component/Collider/BoxComponent.h"
//#include <algorithm>
//
//bool Physics::rayCast(const Ray& ray, CollisionInfo* outColl) {
//    bool collided = false;
//    //closestTは、無限大で初期化
//    // intersection will always update closestT
//    float closestT = Math::infinity;
//    Vector3 norm;
//    //すべてのボックスコンポーネントをテスト
//    for (const auto& box : mBoxes) {
//        float t;
//        //レイがボックスと交差するか
//        if (box->getEnable() && intersect(ray, box->getCollision(), &t, &norm)) {
//            //前の交差より近いか
//            if (t < closestT) {
//                closestT = t;
//                outColl->mPoint = ray.pointOnSegment(t);
//                outColl->mNormal = norm;
//                outColl->mBox = box;
//                outColl->mActor = box->getOwner();
//                collided = true;
//            }
//        }
//    }
//    return collided;
//}
//
//void Physics::sweepAndPrune(std::function<void(Actor*, Actor*)> f) {
//    //min.xが小さい順にソート
//    std::sort(mBoxes.begin(), mBoxes.end(),
//        [](BoxComponent* a, BoxComponent* b) {
//            return a->getCollision().mMin.x < b->getCollision().mMin.x;
//        });
//
//    for (size_t i = 0; i < mBoxes.size(); i++) {
//        //mBoxes[i]のmax.xを取得
//        BoxComponent* a = mBoxes[i];
//        if (!a->getEnable()) {
//            break;
//        }
//        float max = a->getCollision().mMax.x;
//        for (size_t j = i + 1; j < mBoxes.size(); j++) {
//            BoxComponent* b = mBoxes[j];
//            if (!b->getEnable()) {
//                break;
//            }
//            //もしmBoxes[j]のmin.xが、mBoxes[i]のmax.x境界を超えていたら、
//            //mBoxes[i]と交差する可能性があるボックスは存在しない
//            if (b->getCollision().mMin.x > max) {
//                break;
//            } else if (intersect(a->getCollision(), b->getCollision())) {
//                f(a->getOwner(), b->getOwner());
//            }
//        }
//    }
//}
//
//void Physics::addBox(BoxComponent* box) {
//    mBoxes.emplace_back(box);
//}
//
//void Physics::removeBox(BoxComponent* box) {
//    auto itr = std::find(mBoxes.begin(), mBoxes.end(), box);
//    if (itr != mBoxes.end()) {
//        std::iter_swap(itr, mBoxes.end() - 1);
//        mBoxes.pop_back();
//    }
//}
//
//const std::vector<BoxComponent*>& Physics::getBoxes() const {
//    return mBoxes;
//}
