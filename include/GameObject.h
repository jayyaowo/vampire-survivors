#pragma once
#include "raylib.h"

class GameObject {
    protected:
        Vector2 position;
        Color color;
    public:
        // Constructor
        GameObject(Vector2 pos, Color col) : position(pos), color(col) {}
        
        // Virtual Destructor
        virtual ~GameObject() = default;
        //Virtual update
        virtual void update(float deltaTime) = 0; 
        
        //Virtual draw
        virtual void draw() = 0;

        // Getters
        Vector2 getPosition() const { return position; }
};