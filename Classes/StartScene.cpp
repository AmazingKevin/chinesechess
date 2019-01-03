
#include "StartScene.h"

USING_NS_CC;



// on "init" you need to initialize your instance
bool StartScene::init()
{
    if ( !Scene::init() )
    {
        return false;
    }
    _vsize  = Director::getInstance()->getVisibleSize();
    _origin = Director::getInstance()->getVisibleOrigin();

     auto sprite = Sprite::create("HelloWorld.png");
     sprite->setPosition(Vec2(_vsize.width/2 + _origin.x, _vsize.height/2 + _origin.y));

     this->addChild(sprite, 0);

    return true;
}
