//
// Created by admin on 2019/1/4.
//

#ifndef PROJ_ANDROID_COMMON_H
#define PROJ_ANDROID_COMMON_H

//确定游戏高度 1280 宽度 720
#define GAME_WIDTH 1280
#define GAME_HEIGHT 720

//每个棋子 高度 70 宽度 70
#define CHESS_SIDE 70

//象棋 宽 9 高是10
#define CHESS_GAME_COL 9
#define CHESS_GAME_ROW 10
 

enum ChessJob
{
    JOB_CHE=0,
    JOB_MA,
    JOB_PAO,
    JOB_BING,
    JOB_XIANG,
    JOB_SHI,
    JOB_JIANG,
};

typedef struct gamePosition
{
    int gameX;
    int gameY;
}GamePosition;



#endif //PROJ_ANDROID_COMMON_H
