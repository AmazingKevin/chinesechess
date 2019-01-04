//
// Created by admin on 2019/1/4.
//

#include "Chess.h"
  Chess* Chess::create(ChessPlayer player,ChessJob job)
  {
      Chess * pRet = new Chess();
      if(pRet && pRet->init(player,job))
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
bool Chess::init(ChessPlayer player,ChessJob job)
{
    if(!Sprite::init())
    {
        return false;
    }
    _player = player;
    _job = job;



    return true;
}

