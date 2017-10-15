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

    Point2Di Pt1(0,0);
    Point2Di Pt2(1023,0);
    Point2Di Pt3(1023,767);
    Point2Di Pt4(0,767);
    DrawLine(pImage, Pt1, Pt2, inputcolor);
    DrawLine(pImage, Pt2, Pt3, inputcolor);
    DrawLine(pImage, Pt3, Pt4, inputcolor);
    DrawLine(pImage, Pt4, Pt1, inputcolor);

    pImage->WriteImage("output.ppm");

    delete pImage;
    return 0;
}

int DrawLine(PPMCreater * pImage, Point2Di startPt, Point2Di endPt, Colour lineColor)
{
  int leftX = startPt.x;
  int rightX = endPt.x;
  int leftY = startPt.y;
  int rightY = endPt.y;

  if (leftX > rightX)
  {
    leftX = endPt.x;
    rightX = startPt.x;
    leftY = endPt.y;
    rightY = startPt.y;
  }

  if ((rightX - leftX) == 0)
  {
    if (leftY > rightY)
    {
      leftY = endPt.y;
      rightY = startPt.y;
    }
    //Vertical line
    for(int Y=leftY;Y<rightY;Y++)
    {
      pImage->setPixel(lineColor, leftX, Y);
    }
  }
  else
  {
    float Slope = (float)(rightY - leftY)/(float)(rightX - leftX);
    for(int X=leftX;X<rightX;X++)
    {
      int Y = leftY + (int)(Slope * (float)(X - leftX));
      pImage->setPixel(lineColor, X, Y);
    }
  }
  return 0;
}
