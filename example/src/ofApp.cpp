#include "ofApp.h"


void ofApp::createContext(){

	if(pango) delete pango;
	pango = new ofxPango();
	context = pango->createContextWithSurface(ofGetWidth(), ofGetHeight(), CAIRO_FORMAT_ARGB32);

	if(layout) delete layout;
	layout = context->createPangoLayout();
	layout->setWidth(ofGetWidth());
	layout->setJustify(false);

	ofxPCPangoFontDescription fd;
	fd.createFromString("Lucida Grande 22");

	//note font antialias mode supplied here!
	layout->setFontDescription(fd, CAIRO_ANTIALIAS_SUBPIXEL);

	//allocate GPU mem for texture as big as context
	texture.allocate(context->getSurface()->getWidth(), context->getSurface()->getHeight(), GL_RGBA);
}


void ofApp::setup() {

	pango = NULL;
	context = NULL;
	layout = NULL;

	createContext();
}



void ofApp::update() {

	bgColor = (0.5 + 0.5 * sin( 0.5 * ofGetElapsedTimef()));
	float iBgColor = 1.0f - bgColor;

	//clear
	context->clear();
	context->color4f(iBgColor, iBgColor, iBgColor, 0.0f);
	context->paint();

	//add content
	context->color4f(iBgColor, iBgColor, iBgColor, 1.0f);
	layout->setMarkup(
					  "ライブラリーでは、所蔵資料の中からテーマにそった小さな展示を行っています。6月から始まったミニ展示「明治・大正時代の日本ガイドブック」、2回目"
					  "の7月は「古都の旅」と題し、外国人旅行者のために書かれた京都や奈良のガイドブックを展示します。\n\n 한국에서 발매할 PS3는3월에 유럽에서"
					  "\n<span foreground=\"red\" font=\"44.0\">Red text</span> "
					  "<span foreground=\"green\" font=\"44.0\">Green text</span> "
					  "<span foreground=\"blue\" font=\"44.0\">Blue text</span> "
					  "발매한 PS3와 동일한 최신 모델을 사용하여 새롭게 의 대용량 HDD(하드디스크 드라이브)를 표준 탑재하고 있다.  대용량HDD를 탑재함으로써 "
					  "PS3발매와 동시에 실시할 온라인 서비스 “PLAYSTATION®Network”로 선보이게 될 다양한 엔터테인먼트 콘텐츠 다운로드와 온라인 게임 및 온라인 "
					  "서비스를 보다 쾌적하게 사용할 수 있도록 하였다.\n\nHovedgruppen må være på minimum 10 personer, men deltakere kan knytte seg til "
					  "hovedgruppen fra <i>forskjellige</i> destinasjoner. Tilknytningsbillett er gyldig inntil 24 timer før avreise hovedgruppe.\n\nUnicef said 3m "
					  "people had been affected and more than <span font=\"33.0\">1,400</span> had been killed. <b>The government</b> said some 27,000 people remained trapped and awaiting help."
					  + ofGetTimestampString());

	//draw
	layout->show();


	//upload to gpu
	unsigned char * pix = context->getSurface()->getRawPixels();

	texture.loadData(
					pix,
					context->getSurface()->getWidth(),
					context->getSurface()->getHeight(),
					GL_BGRA //note GL_BGRA!
					);

}


void ofApp::draw() {

	ofClear(bgColor * 255);

	glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
	texture.draw(0, 0);
	ofEnableAlphaBlending();
}


void ofApp::windowResized(int w, int h) {
	createContext();
}
