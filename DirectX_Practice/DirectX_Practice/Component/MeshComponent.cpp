#include "MeshComponent.h"
#include "Mesh.h"
#include "../System/GameSystem.h"
#include "../System/Renderer.h"
#include <string>

MeshComponent::MeshComponent(Actor* owner, const std::string& filename) :
    Component(owner),
    mEnabled(true) {
    mMesh = Singleton<GameSystem>::instance().getRenderer()->getMesh(filename);
}

void MeshComponent::update() {
}

void MeshComponent::draw(Matrix4 world) const {
    if (mEnabled) {
        mMesh->Render(world.toD3DXMATRIX());
    }
}

std::shared_ptr<Mesh> MeshComponent::getMesh() const {
    return mMesh;
}

void MeshComponent::setEnable(bool set) {
    mEnabled = set;
}

bool MeshComponent::getEnable() const {
    return mEnabled;
}
