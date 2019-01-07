//
//  Step.hpp
//  MyCppGame-mobile
//
//  Created by Jinlong Wu on 2019/1/6.
//

#ifndef Step_hpp
#define Step_hpp

#include "cocos2d.h"
USING_NS_CC;

class Step:public Ref
{
    static Step* create(int fromX,int fromY,int toX,int toY,int moveId,int killId);
    CC_SYNTHESIZE(int,_fromX,FromX)
    CC_SYNTHESIZE(int,_fromY,FromY)
    CC_SYNTHESIZE(int,_toX,ToX)
    CC_SYNTHESIZE(int,_toY,ToY)
    CC_SYNTHESIZE(int, _moveId, MoveId)
    CC_SYNTHESIZE(int, _killId, KillId)
    bool init(int fromX,int fromY,int toX,int toY,int moveId,int killId);

    
};

#endif /* Step_hpp */
