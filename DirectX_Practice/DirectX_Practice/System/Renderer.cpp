#include "Renderer.h"
#include "../Component/Mesh.h"
#include "../System/IDManager.h"

Renderer::Renderer() :
    mIDManager(std::make_unique<IDManager>()) {
}

Renderer::~Renderer() = default;

std::shared_ptr<Mesh> Renderer::getMesh(const std::string& filename) {
    std::shared_ptr<Mesh> mesh;
    auto itr = mMeshes.find(filename);
    if (itr != mMeshes.end()) { //既に読み込まれている
        mesh = itr->second;
    } else { //初読み込み
        mesh = std::make_shared<Mesh>();
        mesh->Init(filename);
        mMeshes.emplace(filename, mesh);
    }
    return mesh;
}

unsigned Renderer::getSkeleton(const std::string& filename) {
    unsigned id;
    auto itr = mSkeletons.find(filename);
    if (itr != mSkeletons.end()) { //既に読み込まれている
        id = itr->second;
    } else { //初読み込み
        id = mIDManager->pop(IDManager::Type::Skeleton);
        //gsLoadSkeleton(id, filename.c_str());
        mSkeletons.emplace(filename, id);
    }
    return id;
}

unsigned Renderer::getAnimation(const std::string& filename) {
    unsigned id;
    auto itr = mAnimations.find(filename);
    if (itr != mAnimations.end()) { //既に読み込まれている
        id = itr->second;
    } else { //初読み込み
        id = mIDManager->pop(IDManager::Type::Animation);
        //gsLoadAnimation(id, filename.c_str());
        mAnimations.emplace(filename, id);
    }
    return id;
}

unsigned Renderer::getTexture(const std::string& filename) {
    unsigned id;
    auto itr = mTextures.find(filename);
    if (itr != mTextures.end()) { //既に読み込まれている
        id = itr->second;
    } else { //初読み込み
        id = mIDManager->pop(IDManager::Type::Texture);
        //gsLoadTexture(id, filename.c_str());
        mTextures.emplace(filename, id);
    }
    return id;
}

void Renderer::clear() {
    for (const auto& mesh : mMeshes) {
        //gsDeleteMesh(mesh.second);
    }
    mMeshes.clear();
    for (const auto& skeleton : mSkeletons) {
        //gsDeleteSkeleton(skeleton.second);
        mIDManager->push(skeleton.second, IDManager::Type::Skeleton);
    }
    mSkeletons.clear();
    for (const auto& animation : mAnimations) {
        //gsDeleteAnimation(animation.second);
        mIDManager->push(animation.second, IDManager::Type::Animation);
    }
    mAnimations.clear();
    for (const auto& texture : mTextures) {
        //gsDeleteTexture(texture.second);
        mIDManager->push(texture.second, IDManager::Type::Texture);
    }
    mTextures.clear();

    mIDManager->clear();
}
