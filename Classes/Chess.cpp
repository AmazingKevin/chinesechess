//
// Created by admin on 2019/1/4.
//
/**
 id:0  红色 车1
 id:1  红色 马1
 id:2  红色 相1
 id:3  红色 士1
 id:4  红色 帅
 id:5  红色 士2
 id:6  红色 相2
 id:7  红色 马2
 id:8  红色 车2
 id:9 红色 炮1
 id:10 红色 炮2
 id:11 红色 兵1
 id:12 红色 兵2
 id:13 红色 兵3
 id:14 红色 兵4
 id:15 红色 兵5
 id:16 黑色 卒1
 id:17 黑色 卒2
 id:18 黑色 卒3
 id:19 黑色 卒4
 id:20 黑色 卒5
 id:21 黑色 炮1
 id:22 黑色 炮2
 id:23 黑色 车1
 id:24 黑色 马1
 id:25 黑色 相1
 id:26 黑色 士1
 id:27 黑色 将
 id:28 黑色 士2
 id:29 黑色 相2
 id:30 黑色 马2
 id:31 黑色 车2
 
 

 
 
 */
#include "Chess.h"
Chess* Chess::create(int cid, std::string name,std::string filesrc,bool isRed,ChessJob job,int originX,int originY)
{
    Chess * pRet = new Chess();
    if(pRet && pRet->init(cid,name,filesrc,isRed,job,originX,originY))
    {
        pRet->autorelease();
        return pRet;
    }
    else{
        delete pRet;
        pRet = NULL;
        return NULL;
    }
}

bool Chess::init(int cid, std::string name,std::string filesrc,bool isRed,ChessJob job,int originX,int originY)
{
    if(!Sprite::init())
    {
        return false;
    }
    
    _cid = cid;
    _name = name;
    _isRed = isRed;
    _job = job;
    _origin_gameX = originX;
    _origin_gameY = originY;
    
    initWithFile(filesrc);
    setContentSize(Size(CHESS_SIDE, CHESS_SIDE));
    setAnchorPoint(Vec2(0,0));
    
    resetPosition();


    return true;
}


Vec2 Chess::getPositionByGameLocation(int gameX,int gameY)
{
    float padding = 2.0f;
    float board_start_x = CHESS_SIDE/2;
    float board_start_y = padding;
    // 横列 0-8 纵列 0-9
    return Vec2( board_start_x + gameX*padding + gameX*CHESS_SIDE , board_start_y + gameY*padding + gameY*CHESS_SIDE );
}


void Chess::resetPosition()
{
    _current_gameX = _origin_gameX;
    _current_gameY = _origin_gameY;
    
    Vec2 position = Chess::getPositionByGameLocation(_origin_gameX, _origin_gameY);
    setPosition(position);
    
}



















