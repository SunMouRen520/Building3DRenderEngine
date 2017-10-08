//
// Copyright (c) 2017 ikkiChung
// Licensed under the MIT (https://github.com/ikkiChung/Building3DRenderEngine/blob/master/LICENSE.md) license.
//
#include <iostream>
#include "PPMCreater.h"

using namespace std;

main()
{
    cout << "Hello 3D World!"<<endl;

    PPMCreater * pImage = new PPMCreater(3,2);

    Colour inputcolor;
    inputcolor.r = 255;
    inputcolor.g = 0;
    inputcolor.b = 0;
    pImage->setPixel(inputcolor, 0, 0);

    inputcolor.r = 0;
    inputcolor.g = 255;
    inputcolor.b = 0;
    pImage->setPixel(inputcolor, 1, 0);

    inputcolor.r = 0;
    inputcolor.g = 0;
    inputcolor.b = 255;
    pImage->setPixel(inputcolor, 2, 0);

    inputcolor.r = 255;
    inputcolor.g = 255;
    inputcolor.b = 0;
    pImage->setPixel(inputcolor, 0, 1);

    inputcolor.r = 255;
    inputcolor.g = 255;
    inputcolor.b = 255;
    pImage->setPixel(inputcolor, 1, 1);

    inputcolor.r = 0;
    inputcolor.g = 0;
    inputcolor.b = 0;
    pImage->setPixel(inputcolor, 2, 1);

    pImage->WriteImage("output.ppm");

    delete pImage;
    return 0;
}
