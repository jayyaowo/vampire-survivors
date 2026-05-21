#pragma once
#include "raylib.h"
#include "GameObject.h"

class Enemy : public GameObject
{
    private:
        int health;
        int attack;
        int attackType;//0:近戰 1:遠程
        float speed;
    public:
        // Constructor
        Enemy(Vector2 pos, int hp, int atk, int atkType, float spd)
        : GameObject(pos, RED), health(hp), attack(atk), attackType(atkType), speed(spd)
        { if(attackType == 1) color = PURPLE; }

        // Destructor
        ~Enemy() = default;

        // Override update
        void update(float deltaTime) override
        {
            
        }
        //override draw
        void draw() override
        {
            float length = 30.0f;
            Vector2 topLeft = { position.x - length / 2.0f, position.y - length / 2.0f };
            Vector2 boxSize = { length, length };
            DrawRectangleV(topLeft, boxSize, color);
        }

};