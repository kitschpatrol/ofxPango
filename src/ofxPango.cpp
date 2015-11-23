#include "ofxPango.h"
#include "ofxPCContext.h"
#include "ofxPCSurface.h"

ofxPango::ofxPango() {
}

ofxPCContext *ofxPango::createContextWithSurface(float fWidth, float fHeight) {
  ofxPCSurface *surface = new ofxPCSurface(fWidth, fHeight);
  ofxPCContext *context = new ofxPCContext(surface);
  return context;
}

/**
 * A layout is used to align text onto a surface. For example if you want to
 * right align text, you can use a layout together with a surface. This method
 * sets up exactly what you need for this.
 *
 */
ofxPCPangoLayout *ofxPango::createLayout(float fWidth, float fHeight) {
  ofxPCContext *context = createContextWithSurface(fWidth, fHeight);
  ofxPCPangoLayout *layout = context->createPangoLayout();
  layout->setWidth(fWidth);
  return layout;
}

void ofxPango::listFonts() {
http: // www.lemoda.net/pango/list-fonts/
  int i;
  PangoFontFamily **families;
  int n_families;
  PangoFontMap *fontmap;

  fontmap = pango_cairo_font_map_get_default();
  pango_font_map_list_families(fontmap, &families, &n_families);
  printf("There are %d families\n", n_families);
  for (i = 0; i < n_families; i++) {
    PangoFontFamily *family = families[i];
    const char *family_name;

    family_name = pango_font_family_get_name(family);
    printf("Family %d: %s\n", i, family_name);
  }
  g_free(families);
}