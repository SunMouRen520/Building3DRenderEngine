//
// Copyright (c) 2017 ikkiChung
// Licensed under the MIT (https://github.com/ikkiChung/Building3DRenderEngine/blob/master/LICENSE.md) license.
//
#include <iostream>
#include "PPMCreater.h"

using namespace std;

main()
{
    PPMCreater * pImage = new PPMCreater(1024,768);

    Colour inputcolor;
    inputcolor.r = 255;
    inputcolor.g = 0;
    inputcolor.b = 0;
    int X = 1024/2;
    int Y = 768/2;
    pImage->setPixel(inputcolor, X-1, Y-1);
    pImage->setPixel(inputcolor, X-1,   Y);
    pImage->setPixel(inputcolor, X-1, Y+1);
    pImage->setPixel(inputcolor,   X, Y-1);
    pImage->setPixel(inputcolor,   X,   Y);
    pImage->setPixel(inputcolor,   X, Y+1);
    pImage->setPixel(inputcolor, X+1, Y-1);
    pImage->setPixel(inputcolor, X+1,   Y);
    pImage->setPixel(inputcolor, X+1, Y+1);

    pImage->WriteImage("output.ppm");

    delete pImage;
    return 0;
}
