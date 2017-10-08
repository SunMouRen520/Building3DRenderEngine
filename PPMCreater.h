//
// Copyright (c) 2017 ikkiChung
// Licensed under the MIT (https://github.com/ikkiChung/Building3DRenderEngine/blob/master/LICENSE.md) license.
//
#ifndef __PPMCREATER_H__
#define __PPMCREATER_H__

struct Colour
{
	char r,g,b;
};

class PPMCreater
{
public:
  PPMCreater(int width, int height);
  ~PPMCreater();

	//set individual pixels
	void setPixel(Colour inputcolor, int xposition, int yposition);
	void WriteImage(const char * filename);

private:
  int m_width;
  int m_height;
  //store the pixels
  Colour * m_pixels;

	//convert 2D to 1D indexing
	int convert2dto1d(int x, int y);
};

#endif
