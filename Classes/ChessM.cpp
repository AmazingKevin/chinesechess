//
//  ChessM.cpp
//  MyCppGame-mobile
//
//  Created by Jinlong Wu on 2019/1/5.
//

#include "ChessM.hpp"
bool ChessM::init()
{
    if(!Node::init())
    {
        return false;
    }
    setAnchorPoint(Vec2(0, 0));
    
    
    //布置棋盘
    
    Chess * chess;
    ValueMap item;
    ValueMap location;
    int cid;
    std::string name;
    bool isRedPlayer;
    std::string fileSrc;
    const char * testPlistPath = "chess.plist";
    int job;
    int game_x;
    int game_y;
    ChessJob  chooseJob;
    
    ValueVector plist = FileUtils::getInstance()->getValueVectorFromFile(testPlistPath);
    for (int i=0; i<plist.size(); i++) {
        item = plist[i].asValueMap();
        cid = item["id"].asInt();
        name = item["name"].asString();
        isRedPlayer = item["is_red_player"].asBool();
        fileSrc = item["file_src"].asString();
        location = item["first_game_location"].asValueMap();
        job = item["job"].asInt();
        game_x = location["game_x"].asInt();
        game_y = location["game_y"].asInt();
        
        switch (job) {
            case 0:
                chooseJob = JOB_CHE;
                break;
            case 1:
                chooseJob = JOB_MA;
                break;
            case 2:
                chooseJob = JOB_PAO;
                break;
            case 3:
                chooseJob = JOB_BING;
                break;
            case 4:
                chooseJob = JOB_XIANG;
                break;
            case 5:
                chooseJob = JOB_SHI;
                break;
            case 6:
                chooseJob = JOB_JIANG;
                break;
            default:
                break;
        }
        
        chess = Chess::create(cid, name, fileSrc, isRedPlayer, chooseJob, game_x, game_y);
        addChild(chess);
        _chessBoard[chess->getORIGIN_GAMEX()][chess->getORIGIN_GAMEY()] = chess;
    }
    
    //点击事件
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan=CC_CALLBACK_2(ChessM::onTouchBegin , this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
    //选中框
    _selectRect = Sprite::create("selected.png");
    _selectRect->setAnchorPoint(Vec2::ZERO);
    _selectRect->setContentSize(Size(CHESS_SIDE,CHESS_SIDE));
    _selectRect->setVisible(false);
    addChild(_selectRect);
    
    _selected = false;
    _selectChess = NULL;
    
    //未选中框
    _unselectRect = Sprite::create("un_selected.png");
    _unselectRect->setAnchorPoint(Vec2::ZERO);
    _unselectRect->setContentSize(Size(CHESS_SIDE,CHESS_SIDE));
    _unselectRect->setVisible(false);
    addChild(_unselectRect);
    
    
    return true;
}

//重置棋局
void ChessM::resetGame()
{
    Chess * chess;
    for (int i=0; i < CHESS_GAME_COL; i++) {
        for (int j=0; j < CHESS_GAME_ROW; j++) {
            
            chess = _chessBoard[i][j];
            if(chess!=NULL)
            {
                chess->resetPosition();
            }
        }
    }
    
    
}

bool ChessM::onTouchBegin(Touch * touch,Event * event)
{
    
    Vec2 touchLoc = touch->getLocation();
    log("x:%f,y:%f",touchLoc.x,touchLoc.y);
    //首先如果选在棋盘 框外 可以不用管
    if(touchLoc.x>GAME_HEIGHT)
    {
        dismissSelectRect();
        dismissUnSelectRect();
        return true;
    }

   //得到选中游戏行列
    GamePosition gameLoc = getGamePositionByLocation(touchLoc);
    if(gameLoc.gameX<0 || gameLoc.gameY<0 || gameLoc.gameX>8 || gameLoc.gameY>9)
    {//未选中棋盘
        dismissSelectRect();
        dismissUnSelectRect();
        return true;
    }
     //点击 选中某个棋子
    if(_selected)
    {
        //如果选中的棋子再点击一次.什么都不要处理
        if(_selectChess->getCURRENT_GAMEX() == gameLoc.gameX && _selectChess->getCURRENT_GAMEY() == gameLoc.gameY)
        {
            log("选中的棋子再点击一次");
            return true;
        }
        
        log("选中的棋子要移动");
        if(canMoveSelected(_selectChess, gameLoc))
        {//1.可以移动 移动棋子
            Vec2 targetPos = Chess::getPositionByGameLocation(gameLoc.gameX, gameLoc.gameY);
            _selectChess->setPosition(targetPos);
            
        }else{ //2.不可以移动 选中取消,显示未选中
            dismissSelectRect();
            showUnSelectRect(gameLoc);
        }

    }
    else{
        Chess* chess = _chessBoard[gameLoc.gameX][gameLoc.gameY];
        if(chess == NULL)
        {// 没有选中棋子  未选显示
            showUnSelectRect(gameLoc);
        }
        else{//没有选中棋子,现在选中棋子
            dismissUnSelectRect();
            showSelectRect(chess);
        }
    }
    
    
    return true;
}
//展示 选中框
void ChessM::showSelectRect(Chess* chess)
{
    _selectRect->setPosition(chess->getPosition());
    _selectRect->setVisible(true);
    _selected = true;
    _selectChess = chess;
}
//选中框消失
void ChessM::dismissSelectRect()
{
    _selected = false;
    _selectChess = NULL;
    _selectRect->setVisible(false);
}
void ChessM::showUnSelectRect(GamePosition pos)
{
    Vec2 unPos = Chess::getPositionByGameLocation(pos.gameX, pos.gameY);
    _unselectRect->setPosition(unPos);
    _unselectRect->setVisible(true);
}
void ChessM::dismissUnSelectRect()
{
    _unselectRect->setVisible(false);
}

//根据点击获取点击的游戏位置
 GamePosition ChessM::getGamePositionByLocation(Vec2 location)
{
   
    int targetGameX=-1;
    int targetGameY=-1;
    
    float padding = 2.0f;
    float board_start_x = CHESS_SIDE/2;
    float board_start_y = padding;
    float itemXStart;
    float itemXEnd;
    float itemYStart;
    float itemYEnd;
    
    float targetX = location.x;
    float targetY = location.y;
   
    for (int i =0 ; i<GAME_WIDTH; i++) {
        itemXStart = board_start_x + i*padding + i*CHESS_SIDE;
        itemXEnd   = board_start_x+(i+1)*padding+(i+1)*CHESS_SIDE;
       if( targetX >= itemXStart && targetX < itemXEnd )
       {
           targetGameX = i;
       }
    }
    for (int j =0 ; j<GAME_HEIGHT; j++) {
        itemYStart = board_start_y + j*padding + j*CHESS_SIDE;
        itemYEnd   = board_start_y+(j+1)*padding+(j+1)*CHESS_SIDE;
        if( targetY >= itemYStart && targetY < itemYEnd )
        {
            targetGameY = j;
        }
    }
    
   
    
    GamePosition gamePos;
    gamePos.gameX = targetGameX;
    gamePos.gameY = targetGameY;
    log("gameX:%d,gameY:%d",targetGameX,targetGameY);
    return gamePos;
}


bool ChessM::canMoveSelected(Chess* chess,GamePosition pos)
{
    bool canMove = false;
    switch (chess->getJob()) {
        case JOB_CHE:
            canMove = canMoveChe(chess->getCURRENT_GAMEX(), chess->getCURRENT_GAMEY(), pos);
            break;
            
        default:
            break;
    }
    
    
    
    return canMove;
}

bool ChessM::canMoveChe(int gameX,int gameY,GamePosition pos)
{
    
    if(gameX != pos.gameX && gameY!=pos.gameY)
    {//满足 同时 不在x轴 和同时不在y轴,就可以判断 不能移动
        return false;
    }
    
    Chess * existChess;
    if(gameY == pos.gameY)
    {//在同一行 从棋子列的开始点到移动目标点如果有棋子就不能移动
        int startX = MIN(gameX,pos.gameX);
        int endX = MAX(gameX,pos.gameX);
        
        if(endX-startX == 1)
        {//相邻一格可以移动
            return true;
        }
       
        for (int i=startX+1; i<endX; i++) {
            existChess = _chessBoard[i][gameY];
            if(existChess!=NULL)
            {
                return false;
            }
        }
      
        return true;
    }
    else{
         //在同一列,从棋子行的开始点到移动目标点如果有棋子就不能移动
        int startY = MIN(gameY,pos.gameY);
        int endY = MAX(gameY,pos.gameY);
        if(endY-startY==1)
        {//相邻一个格子 可以移动
            return true;
        }
        for (int j=startY+1; j<endY; j++) {
            existChess = _chessBoard[gameX][j];
            if(existChess!=NULL)
            {
                return false;
            }
        }
       
        return true;
    }
   
}







