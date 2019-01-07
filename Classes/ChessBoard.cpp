//
//  ChessBoard.cpp
//  MyCppGame-mobile
//
//  Created by Jinlong Wu on 2019/1/5.
//

#include "ChessBoard.hpp"
#include "Common.h"
bool ChessBoard::init()
{
    if(!Sprite::init()){
        return false;
    }
    initWithFile("chinesechessboard.png");
    //setRotation(90.0);
    setContentSize(Size(GAME_HEIGHT,GAME_HEIGHT));
   
    
    
    return true;
}

