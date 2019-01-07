//
//  Step.cpp
//  MyCppGame-mobile
//
//  Created by Jinlong Wu on 2019/1/6.
//

#include "Step.hpp"
Step* Step::create(int fromX,int fromY,int toX,int toY,int moveId,int killId)
{
    Step* pRet = new Step();
    if(pRet&&pRet->init(fromX,fromY,toX,toY,moveId,killId))
    {
        pRet->autorelease();
        return pRet;
    }else{
        delete pRet;
        pRet = NULL;
        return NULL;
    }
   
}
bool Step::init(int fromX,int fromY,int toX,int toY,int moveId,int killId)
{
    _fromX = fromX;
    _fromY = fromY;
    _toX  = toX;
    _toY  = toY;
    _moveId = moveId;
    _killId = killId;
    return true;
}
