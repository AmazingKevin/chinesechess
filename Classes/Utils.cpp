//
//  AppUtils.cpp
//  mygame-mobile
//
//  Created by Jinlong Wu on 2018/12/9.
//

#include "Utils.hpp"


void Utils::makeBackgroud(Scene* scene,int r,int g,int b,int o)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    
    ccColor4B color = ccc4(r, g, b, o);
    CCLayerColor *color_layer = CCLayerColor::create(color);
    
//    auto bg = Sprite::create();
//    bg->setColor(Color3B(r,g,b));
//    bg->setPosition(Vec2(origin.x,origin.y));
//    bg->setContentSize(visibleSize);
//    scene->addChild(bg,-1);

    CCSize c_size( visibleSize.width,  visibleSize.height);    //宽和高
    color_layer->setPosition(Vec2(origin.x, origin.y));    //设置位置，注意，CCLayerColor 的贴图点是左下角，而且还改不了……
    color_layer->setContentSize(c_size);    //设置这块区域的大小
    scene->addChild(color_layer,-1);

}

void Utils::addGobackItem(Scene* scene,const  ui::Widget::ccWidgetClickCallback&  callback)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto imageView = ui::ImageView::create("CloseNormal.png");
    auto x = origin.x + visibleSize.width - 10;
    auto y = origin.y + visibleSize.height - 10;
    imageView->setPosition(Vec2(x, y));
    imageView->setContentSize(Size(20,20));
    imageView->setTouchEnabled(true);
    imageView->ignoreContentAdaptWithSize(false);
    imageView->addClickEventListener(callback);


    

    scene->addChild(imageView,9);
}

