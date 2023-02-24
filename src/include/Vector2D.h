#ifndef WANDERER_VECTOR2D_H
#define WANDERER_VECTOR2D_H

 #include <cmath>

class Vector2D {
public:
    float x = 0;
    float y = 0;
    float magnitude = 0;

    inline Vector2D()
    {
        x = 0;
        y = 0;
        magnitude = 0;
    }
    
    inline Vector2D(float x, float y) 
    {
        this->x = x;
        this->y = y;
        magnitude = sqrt(x * x + y * y);
    }

    inline Vector2D(const Vector2D& vec)
    {
        x = vec.x;
        y = vec.y;
        magnitude = vec.magnitude;
    }
};


#endif // WANDERER_VECTOR2D_H