#pragma once
#include "raylib.h"
#include "rlgl.h"
#include "GameObject.h"
#include <cmath>

#ifndef PI
#define PI 3.14159265358979323846f
#endif

class Player : public GameObject 
{
    private:
        int health;
        float speed;
        int rank;
        float rotation;
    public:
        // Constructor
        Player(Vector2 pos, int hp, float spd, int rn)
        : GameObject(pos, BLUE), health(hp), speed(spd), rank(rn), rotation(0.0f) {}

        //Destructor
        ~Player() = default;

        // Override update
        void update(float deltaTime) override
        {
            // //----move----//
            // if(IsKeyDown(KEY_W)) position.y -= speed * deltaTime;
            // if(IsKeyDown(KEY_S)) position.y += speed * deltaTime;
            // if(IsKeyDown(KEY_A)) position.x -= speed * deltaTime;
            // if(IsKeyDown(KEY_D)) position.x += speed * deltaTime;
            // //----rotate----//
            // if(IsKeyDown(KEY_W)) rotation = PI * 1.5f;
            // if(IsKeyDown(KEY_S)) rotation = PI * 0.5f;
            // if(IsKeyDown(KEY_A)) rotation = PI;
            // if(IsKeyDown(KEY_D)) rotation = 0.0f;

            //----move & rotate----//
            //計算移動方向
            float moveX = 0.0f;
            float moveY = 0.0f;

            if(IsKeyDown(KEY_W)) moveY -= 1.0f;
            if(IsKeyDown(KEY_S)) moveY += 1.0f;
            if(IsKeyDown(KEY_A)) moveX -= 1.0f;
            if(IsKeyDown(KEY_D)) moveX += 1.0f;

            if(moveX != 0.0f || moveY != 0.0f)
            {
                //計算旋轉角度
                rotation = atan2f(moveY, moveX);
                //計算移動距離
                float length = sqrtf(moveX * moveX + moveY * moveY);
                moveX /= length; //正規化
                moveY /= length; //正規化
                position.x += moveX * speed * deltaTime;
                position.y += moveY * speed * deltaTime;
            }
        }

        // Override draw
        void draw() override
        {
            //----draw circle----//
            DrawCircleV(position, 20, color);
            //----draw triangle----//
            //1.抓三角形三頂點
                //利用極座標算出三角形頂點角度
                //三角形頂點位置 x = position + 三角形的高 * cos
                //              y = position + 三角形的高 * sin
                float adjust = 1.0f * PI / 3.0f;
                Vector2 tip = {
                    position.x + 30 * cosf(rotation),
                    position.y + 30 * sinf(rotation) };
                Vector2 rightTip = {
                    position.x + 20 * cosf(rotation + adjust),
                    position.y + 20 * sinf(rotation + adjust) };
                Vector2 leftTip = {
                    position.x + 20 * cosf(rotation - adjust),
                    position.y + 20 * sinf(rotation - adjust) };
            //2.draw triangle
                rlDisableBackfaceCulling(); // 暫時關閉背面淘汰
                DrawTriangle(tip, leftTip, rightTip, BLUE); // 改為白色
                rlEnableBackfaceCulling();  // 畫完馬上開啟背面淘汰
            
        }
};