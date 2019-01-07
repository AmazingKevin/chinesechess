
#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "ChessM.hpp"
USING_NS_CC;
class StartScene : public cocos2d::Scene
{
public:
    CREATE_FUNC(StartScene)
    virtual bool init();
    CC_SYNTHESIZE(Vec2,_origin,Origin)
    CC_SYNTHESIZE(Size,_vsize,VSize)
private:
    ChessM * _chessM;//棋子管理类

};

#endif // __HELLOWORLD_SCENE_H__
