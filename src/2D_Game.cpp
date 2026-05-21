#include "raylib.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "GameObjectFactory.h"
#include <iostream>
#include <stdlib.h>
#include <ctime>  
#include <vector>

int main()
{
    std::cout << "========================================" << std::endl;
    std::cout << "[測試] 程式已順利啟動！進入 main 函式..." << std::endl;
    std::cout << "========================================" << std::endl;
    //設定視窗
    int screenWidth = 800;
    int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "2D Game");

    //創建玩家
    GameObject* player = GameObjectFactory::creatGameObject("player");

    //創建敵人
    std::vector<GameObject*> enemies;

    //使用當前時間作為隨機數種子
    srand(static_cast<unsigned int>(time(0))); 
    int enemyCount = 5; //敵人數量
    for(int i = 0; i < enemyCount; ++i)
    { enemies.push_back(GameObjectFactory::creatGameObject("enemy"));}

    //遊戲主循環
    while (!WindowShouldClose())
    {
        //----更新----//
        //計算deltaTime
        float deltaTime = GetFrameTime();

        //更新玩家
        player->update(deltaTime);

        //更新每一隻敵人
        for(GameObject*& enemy : enemies)
        { enemy->update(deltaTime); }

        //----繪製----//
        BeginDrawing();
        ClearBackground(DARKGREEN);

        //繪製玩家
        player->draw();

        //繪製每一隻敵人
        for(GameObject*& enemy : enemies)
        { enemy->draw(); }

        EndDrawing();
    }

    //----釋放資源----//
    //刪除玩家
    delete player;
    //刪除敵人
    //刪除每一隻敵人
    for(GameObject*& enemy : enemies)
    { delete enemy; }
    //清空敵人容器
    enemies.clear();
    //關閉視窗
    CloseWindow();

    return 0;
}