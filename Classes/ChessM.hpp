//
//  ChessM.hpp
//  MyCppGame-mobile
//
//  Created by Jinlong Wu on 2019/1/5.
//

#ifndef ChessM_hpp
#define ChessM_hpp

#include "cocos2d.h"
#include "Chess.h"
#include "Step.hpp"
USING_NS_CC;
class ChessM:public Node
{
public:
    CREATE_FUNC(ChessM);
    bool init();
    void resetGame();
    bool onTouchBegin(Touch * touch,Event * event);
    GamePosition getGamePositionByLocation(Vec2 location);

private:
    Chess* _chessBoard[CHESS_GAME_COL][CHESS_GAME_ROW];//棋子
    Vector<Step*> _stepList;//下棋步骤
    Sprite * _selectRect;//选中框
    Sprite * _unselectRect;//未选中框
    bool _selected;//是否选中棋子
    Chess * _selectChess;
    
    void showSelectRect(Chess* chess);
    void dismissSelectRect();
    void showUnSelectRect(GamePosition pos);
    void dismissUnSelectRect();
    
    bool canMoveSelected(Chess* chess,GamePosition pos);
    bool canMoveChe(int gameX,int gameY,GamePosition pos);
};


#endif /* ChessM_hpp */
