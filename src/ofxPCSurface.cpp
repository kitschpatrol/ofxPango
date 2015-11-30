#include "ofxPCSurface.h"
#include "ofMain.h"

ofxPCSurface::ofxPCSurface(float fWidth, float fHeight, cairo_format_t nType) {
  cr_surface = cairo_image_surface_create(nType, fWidth, fHeight);
  pixels = getWidth() * getHeight(); // we assume RGBA for now!
  new_data = new unsigned char[pixels * 4];
}

ofxPCSurface::~ofxPCSurface() {
  cairo_surface_destroy(cr_surface);
  cairo_surface_finish(cr_surface);
  delete[] new_data;
}

void ofxPCSurface::ref(std::string s) {
  cout << "+ ofxPCSurface (" << s << ")"
       << "ref count: " << cairo_surface_get_reference_count(cr_surface) << " on this: " << this << std::endl;
}

int ofxPCSurface::getWidth() {
  return cairo_image_surface_get_width(cr_surface);
}

int ofxPCSurface::getHeight() {
  return cairo_image_surface_get_height(cr_surface);
}

unsigned char *ofxPCSurface::getPixels() {
  return cairo_image_surface_get_data(cr_surface);
}