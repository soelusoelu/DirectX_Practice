#pragma once

#include <string>
#include <unordered_map>
#include <memory>

class IDManager;
class Mesh;

class Renderer {
public:
    Renderer();
    ~Renderer();

    std::shared_ptr<Mesh> getMesh(const std::string& filename);
    unsigned getSkeleton(const std::string& filename);
    unsigned getAnimation(const std::string& filename);
    unsigned getTexture(const std::string& filename);

    void clear();

private:
    std::unordered_map<std::string, std::shared_ptr<Mesh>> mMeshes;
    std::unordered_map<std::string, unsigned> mSkeletons;
    std::unordered_map<std::string, unsigned> mAnimations;
    std::unordered_map<std::string, unsigned> mTextures;
    std::unique_ptr<IDManager> mIDManager;
    const int mWordCount = 16;
    const int mWidth = 16;
    const int mHeight = 16;
};

