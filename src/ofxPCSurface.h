#pragma once

#include <pango/pangocairo.h>
#include <string> // tmp
class ofxPCSurface {
public:
  ofxPCSurface(float fWidth, float fHeight, cairo_format_t nType = CAIRO_FORMAT_ARGB32);
  ~ofxPCSurface();
  int getWidth();
  int getHeight();
  unsigned char *getRawPixels(); ///no conversion, you get what you asked for when creating the surface
  unsigned char *getPixels(); /// this converts ARGB to RGBA so its expensive
  void ref(std::string s = "");
  cairo_surface_t *cr_surface;

private:
  unsigned char *new_data;
  int pixels;
};
