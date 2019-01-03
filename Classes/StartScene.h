
#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;
class StartScene : public cocos2d::Scene
{
public:
    CREATE_FUNC(StartScene)
    virtual bool init();
    CC_SYNTHESIZE(Vec2,_origin,Origin)
    CC_SYNTHESIZE(Size,_vsize,VSize)


};

#endif // __HELLOWORLD_SCENE_H__
