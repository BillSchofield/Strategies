#pragma once

class Vector
{
public:
    static const Vector Zero;
    static const Vector MinusX;
    static const Vector PlusX;
    
    Vector(float x, float y, float z)
    :x(x)
    ,y(y)
    ,z(z)
    {
    }

    Vector(const Vector& source)
    :x(source.x)
    ,y(source.y)
    ,z(source.z)
    {
    }
    
    Vector operator+(const Vector& that)
    {
        Vector temp(
                    x + that.x,
                    y + that.y,
                    z + that.z
                    );
        return temp;
    }
    
    Vector operator-(const Vector& that)
    {
        Vector temp(
                    x - that.x,
                    y - that.y,
                    z - that.z
                    );
        return temp;
    }
    
    Vector operator*(float scale)
    {
        Vector temp(
                    x * scale,
                    y * scale,
                    z * scale
                    );
        return temp;
    }
    
    Vector operator*(float scale) const
    {
        Vector temp(
                    x * scale,
                    y * scale,
                    z * scale
                    );
        return temp;
    }
    
    Vector& operator+=(const Vector& that)
    {
        x += that.x;
        y += that.y;
        z += that.z;
        
        return *this;
    }
    
    float x;
    float y;
    float z;
};