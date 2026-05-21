#pragma once
#include "raylib.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include <string>
#include <cstdlib>

class GameObjectFactory
{
    private:
    public:
    // Constructor
    static GameObject* creatGameObject(const std::string& type)
    {
        //------創建玩家------//
        if(type == "player")
        {
            //玩家誕生於地圖中央         血量100 速度200 等級1
            return new Player({400, 300}, 100, 200.0f, 1);
        }
        //------創建敵人------//
        else if(type == "enemy")
        {
            //敵人誕生於地圖隨機位置,擁有隨機攻擊方式
            //隨機位置
            float x = static_cast<float>(rand() % 700 + 50); 
            float y = static_cast<float>(rand() % 550 + 50);
            Vector2 pos = {x, y};
            //隨機攻擊方式
            int attackType = rand() % 2; //0或1
            //----生成敵人----//
            //           隨機位置 血量30  攻擊力5     速度0
            return new Enemy(pos, 30, 5, attackType, 0.0f);
        }
        return nullptr;
    }
    // Destructor
    ~GameObjectFactory() = default;
};