//
// Copyright (c) 2017 ikkiChung
// Licensed under the MIT (https://github.com/ikkiChung/Building3DRenderEngine/blob/master/LICENSE.md) license.
//
#include <iostream>
#include <fstream>
#include "PPMCreater.h"

using namespace std;

PPMCreater::PPMCreater(int width, int height)
  : m_width(width), m_height(height)
{
  m_pixels = new Colour[m_width*m_height];
}

PPMCreater::~PPMCreater()
{
  delete [] m_pixels;
}

//Set indivdual pixels
void PPMCreater::setPixel(Colour inputcolor, int x, int y)
{
	m_pixels[convert2dto1d(x,y)] = inputcolor;
}

void PPMCreater::WriteImage(const char * filename)
{


	//Error checking
	if (m_width <= 0 || m_height <= 0)
	{
		cout << "Image size is not set properly" << endl;
		return;
	}
  int imgSize = 3*m_width*m_height;

	char * img = new char[imgSize];

	int x, y;

	for(int i=0; i<m_width; i++)
	{
	  for(int j=0; j<m_height; j++)
		{
		    x=i;
        y=j;
		    img[(x+y*m_width)*3+0] = m_pixels[i+j*m_width].r;
		    img[(x+y*m_width)*3+1] = m_pixels[i+j*m_width].g;
		    img[(x+y*m_width)*3+2] = m_pixels[i+j*m_width].b;
		}
	}

  ofstream ofile;
	ofile.open(filename, ios::out | ios::binary);

  ofile <<"P6"<<endl;
  ofile <<m_width<<" "<<m_height<<" 255"<<endl;

  for(int i=0; i<m_height; i++)
	{
      ofile.write(img+(m_width*i*3), 3*m_width);
  }
	ofile.close();
	delete [] img;
}

//Convert 2d array indexing to 1d indexing
int PPMCreater::convert2dto1d(int x, int y)
{
	return m_width * y + x;
}
