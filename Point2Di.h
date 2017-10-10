//
// Copyright (c) 2017 ikkiChung
// Licensed under the MIT (https://github.com/ikkiChung/Building3DRenderEngine/blob/master/LICENSE.md) license.
//

#ifndef __Point2Di_H_
#define __Point2Di_H_

class Point2Di
{
public:
    Point2Di()
    {
        x = 0;
        y = 0;
    };
    Point2Di(int inX, int inY)
    {
        x = inX;
        y = inY;
    };
    int x;
    int y;
};

#endif
