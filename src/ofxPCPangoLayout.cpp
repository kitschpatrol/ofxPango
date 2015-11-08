#include "ofxPCPangoLayout.h"
#include "ofxPCContext.h"
#include "ofxPCPangoFontDescription.h"
#include "ofxPCSurface.h"

ofxPCPangoLayout::ofxPCPangoLayout(ofxPCContext *pContext) : context(pContext) {
  pa_layout = pango_cairo_create_layout(pContext->cr_context);
}

ofxPCPangoLayout::~ofxPCPangoLayout() {
  // std::cout << "~~~~ ofxPCPangoLayout" << std::endl;
  delete context;
  g_object_unref(pa_layout);
}

void ofxPCPangoLayout::setJustify(bool bJustify) {
  pango_layout_set_justify(pa_layout, true);
}

void ofxPCPangoLayout::setWidth(int nWidth) {
  pango_layout_set_width(pa_layout, nWidth * PANGO_SCALE);
}

void ofxPCPangoLayout::setText(std::string sText) {
  setText(sText.c_str());
}

void ofxPCPangoLayout::setText(const char *pText, int nLen) {
  pango_layout_set_text(pa_layout, pText, nLen);
}

void ofxPCPangoLayout::setMarkup(std::string sText) {
  setMarkup(sText.c_str());
}

void ofxPCPangoLayout::setMarkup(const char *pText, int nLen) {
  pango_layout_set_markup(pa_layout, pText, nLen);
}

void ofxPCPangoLayout::show() {
  pango_cairo_show_layout(context->cr_context, pa_layout);
}

float ofxPCPangoLayout::getTextHeight() {
  PangoRectangle rect = getPixelExtents();
  return rect.height;
}

void ofxPCPangoLayout::setFontDescription(ofxPCPangoFontDescription oFont) {

  PangoContext *pc = pango_layout_get_context(pa_layout);
  cairo_font_options_t *options = cairo_font_options_create();
  cairo_font_options_set_antialias(options, CAIRO_ANTIALIAS_DEFAULT);
  cairo_font_options_set_hint_style(options, CAIRO_HINT_STYLE_FULL);
  cairo_font_options_set_hint_metrics(options, CAIRO_HINT_METRICS_ON);

  pango_cairo_context_set_font_options(pc, options);
  cairo_font_options_destroy(options);

  pango_layout_set_font_description(pa_layout, oFont.pa_description);
}

void ofxPCPangoLayout::setFontDescription(ofxPCPangoFontDescription oFont, cairo_antialias_t _antialias_type) {

  PangoContext *pc = pango_layout_get_context(pa_layout);
  cairo_font_options_t *options = cairo_font_options_create();
  cairo_font_options_set_antialias(options, _antialias_type);
  cairo_font_options_set_hint_style(options, CAIRO_HINT_STYLE_FULL);
  cairo_font_options_set_hint_metrics(options, CAIRO_HINT_METRICS_ON);

  pango_cairo_context_set_font_options(pc, options);
  cairo_font_options_destroy(options);

  pango_layout_set_font_description(pa_layout, oFont.pa_description);
}

unsigned char *ofxPCPangoLayout::getPixels() {
  return context->getSurface()->getPixels();
}

ofImage ofxPCPangoLayout::getImage() {
  unsigned char *pix = getPixels();
  ofImage img;
  img.allocate(getWidth(), getHeight(), OF_IMAGE_COLOR_ALPHA);
  img.setFromPixels(pix, img.getWidth(), img.getHeight(), OF_IMAGE_COLOR_ALPHA);
  delete[] pix;
  return img;
}

int ofxPCPangoLayout::getWidth() {
  return context->getSurface()->getWidth();
}

int ofxPCPangoLayout::getHeight() {
  return context->getSurface()->getHeight();
}

void ofxPCPangoLayout::setFont(std::string sFontDesc) {
  ofxPCPangoFontDescription fd;
  fd.createFromString(sFontDesc);
  setFontDescription(fd);
}

void ofxPCPangoLayout::fill(float fR, float fG, float fB, float fA) {
  context->color4f(fR, fG, fB, fA);
  context->paint();
}

void ofxPCPangoLayout::setTextColor(float fR, float fG, float fB, float fA) {
  context->color4f(fR, fG, fB, fA);
}

void ofxPCPangoLayout::setPangoAlign(int _pangoalign) {
  pango_layout_set_alignment(pa_layout, (PangoAlignment)_pangoalign);
}

void ofxPCPangoLayout::setAlignLeft() {
  pango_layout_set_alignment(pa_layout, PANGO_ALIGN_LEFT);
}

void ofxPCPangoLayout::setAlignCenter() {
  pango_layout_set_alignment(pa_layout, PANGO_ALIGN_CENTER);
}

void ofxPCPangoLayout::setAlignRight() {
  pango_layout_set_alignment(pa_layout, PANGO_ALIGN_RIGHT);
}

PangoRectangle ofxPCPangoLayout::getPixelExtents() {
  PangoRectangle rect;
  pango_layout_get_pixel_extents(pa_layout, &rect, NULL);
  return rect;
}

void ofxPCPangoLayout::setSpacing(int _spacing) {
  pango_layout_set_spacing(pa_layout, _spacing * PANGO_SCALE);
}

void ofxPCPangoLayout::setTabs(vector<int> _tabpositions) {

  PangoTabArray *pta = pango_tab_array_new(_tabpositions.size(), true);
  for (int i = 0; i < _tabpositions.size(); i++) {
    pango_tab_array_set_tab(pta, i, PANGO_TAB_LEFT, _tabpositions[i]);
  }
  pango_layout_set_tabs(pa_layout, pta);
  pango_tab_array_free(pta);
}

void ofxPCPangoLayout::setIndent(int _indent) {
  pango_layout_set_indent(pa_layout, _indent * PANGO_SCALE);
}

ofPoint ofxPCPangoLayout::getPixelSize() {
  ofPoint b;
  int w, h;
  pango_layout_get_pixel_size(pa_layout, &w, &h);
  b.x = w;
  b.y = h;
  return b;
}

void ofxPCPangoLayout::setSingleParagraphMode(bool single) {
  pango_layout_set_single_paragraph_mode(pa_layout, single);
}

int ofxPCPangoLayout::getLineCount() {
  return pango_layout_get_line_count(pa_layout);
}

ofPoint ofxPCPangoLayout::getPosAtIndex(int _index) {
  PangoRectangle pos;
  pango_layout_index_to_pos(pa_layout, _index, &pos);

  ofPoint p;
  p.x = pos.x / PANGO_SCALE;
  p.y = pos.y / PANGO_SCALE;

  return p;
}

int ofxPCPangoLayout::getIndexAtPos(ofPoint _pos) {
  int index;
  int trailing;
  pango_layout_xy_to_index(pa_layout, _pos.x, _pos.y, &index, &trailing);

  return index;
}