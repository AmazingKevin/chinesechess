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
    static Chess* create(ChessPlayer player,ChessJob job);
    bool init(ChessPlayer player,ChessJob job);

private:
    CC_SYNTHESIZE(ChessJob,_job,Job)
    CC_SYNTHESIZE(ChessPlayer,_player,Player)
};


#endif //PROJ_ANDROID_CHESS_H
