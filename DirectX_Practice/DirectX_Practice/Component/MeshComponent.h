#pragma once

#include "Component.h"
#include "../Utility/Math.h"
#include <string>

class Actor;
class Mesh;

class MeshComponent : public Component {
public:
    MeshComponent(Actor* owner, const std::string& filename);
    virtual void update() override;
    void draw(Matrix4 world) const;

    void setEnable(bool set);
    bool getEnable() const;

private:
    std::shared_ptr<Mesh> mMesh;
    bool mEnabled;
};

