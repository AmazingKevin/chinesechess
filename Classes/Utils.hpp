//
//  AppUtils.hpp
//  mygame-mobile
//
//  Created by Jinlong Wu on 2018/12/9.
//

#ifndef AppUtils_hpp
#define AppUtils_hpp
#include "cocos2d.h"
#include "ui/UIImageView.h"
#include "Common.h"
#define ARIAL_FONT "fonts/arial.ttf"
#define SIMHEI "fonts/simhei.ttf"


USING_NS_CC;

class Utils
{
public:
    //用于创建背景
    static void makeBackgroud(Scene* scene,int r,int g,int b,int o);
    static void addGobackItem(Scene* scene,const ui::Widget::ccWidgetClickCallback&  callback);
};

#endif /* AppUtils_hpp */
