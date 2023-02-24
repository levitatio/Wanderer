#ifndef WANDERER_TRANSFORM_H
#define WANDERER_TRANSFORM_H

#include "Vector2D.h"

class Transform {
public:
    Vector2D position;
    Vector2D localPosition;

    // counter-clockwise from horizontal line (trig. func. like)
    float rotation;
    float localRotation;
    
    Vector2D scale;
    Vector2D localScale;

    float indexZ;

};



#endif //WANDERER_TRANSFORM_H