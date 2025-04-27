#include "RayLibTranslator.h"


Vector2 RayVec(Vec2 vec)
{
    Vector2 rayVec = Vector2();
    rayVec.x = vec.x;
    rayVec.y = vec.y;
    return rayVec;
}

Rectangle RayRec(Transform* transform)
{
    Rectangle rayRec = Rectangle();
    rayRec.x = transform->WorldPos().x;
    rayRec.y = transform->WorldPos().y;
    rayRec.width = transform->scale.x;
    rayRec.height = transform->scale.y;
    return rayRec;
}