//
// Copyright (c) 2017 ikkiChung
// Licensed under the MIT (https://github.com/ikkiChung/Building3DRenderEngine/blob/master/LICENSE.md) license.
//
#include <iostream>
#include "PPMCreater.h"
#include "Point2Di.h"

using namespace std;

int DrawLine(PPMCreater * pImage, Point2Di startPt, Point2Di endPt, Colour lineColor);

main()
{
    PPMCreater * pImage = new PPMCreater(1024,768);

    Point2Di startPt(100,100);
    Point2Di endPt(600,500);

    Colour inputcolor;
    inputcolor.r = 255;
    inputcolor.g = 0;
    inputcolor.b = 0;

    DrawLine(pImage, startPt, endPt, inputcolor);

    pImage->WriteImage("output.ppm");

    delete pImage;
    return 0;
}

int DrawLine(PPMCreater * pImage, Point2Di startPt, Point2Di endPt, Colour lineColor)
{
  float Slope = (float)(endPt.y - startPt.y)/(float)(endPt.x - startPt.x);
  for(int X=startPt.x;X<endPt.x;X++)
  {
    int Y = startPt.y + (int)(Slope * (float)X);
    pImage->setPixel(lineColor, X, Y);
  }
  return 0;
}
