//
// Created by admin on 2019/1/4.
//

#ifndef PROJ_ANDROID_CHESS_H
#define PROJ_ANDROID_CHESS_H

#include "cocos2d.h"
#include "Common.h"
USING_NS_CC;

class Chess:public Sprite {
public:
    static Chess* create(int cid, std::string name,std::string filesrc,bool isRed,ChessJob job,int originX,int originY);
    bool init(int cid, std::string name,std::string filesrc,bool isRed,ChessJob job,int originX,int originY);
    
    CC_SYNTHESIZE(ChessJob,_job,Job)//什么类型的棋
    CC_SYNTHESIZE(bool,_isRed,IsRed)//红方还是黑方
    CC_SYNTHESIZE(bool,_dead,Dead)//是否被吃掉
    CC_SYNTHESIZE(bool, _cid, CID)//棋子的id 0~31
    CC_SYNTHESIZE(int, _current_gameX, CURRENT_GAMEX)
    CC_SYNTHESIZE(int, _current_gameY, CURRENT_GAMEY)
    CC_SYNTHESIZE(int, _origin_gameX, ORIGIN_GAMEX)
    CC_SYNTHESIZE(int, _origin_gameY, ORIGIN_GAMEY)
    CC_SYNTHESIZE(std::string, _name, NAME)
    
    static Vec2 getPositionByGameLocation(int gameX,int gameY);
    
    void resetPosition();

private:
   
   
    

};


#endif //PROJ_ANDROID_CHESS_H
