
#include "StartScene.h"

USING_NS_CC;
#include "Utils.hpp"
#include "Chess.h"
#include "ChessBoard.hpp"
#include "ChessM.hpp"
// on "init" you need to initialize your instance
bool StartScene::init()
{
    if ( !Scene::init() )
    {
        return false;
    }
    _vsize  = Director::getInstance()->getVisibleSize();
    _origin = Director::getInstance()->getVisibleOrigin();
    log("width:%f,height:%f",_vsize.width,_vsize.height);
    log("origin.x:%f,origin.y:%f",_origin.x,_origin.y);

    //Utils::makeBackgroud(this, 230, 230, 10, 255);
    
    
    //棋盘
    auto board = ChessBoard::create();
    board->setAnchorPoint(Vec2(0,0));
    board->setPosition(Vec2(_origin.x , _origin.y ));
    this->addChild(board);
    
    _chessM = ChessM::create();
    _chessM->setPosition(Vec2(0,0));
    _chessM->resetGame();
    this->addChild(_chessM);
    
    
   
    

    return true;
}
