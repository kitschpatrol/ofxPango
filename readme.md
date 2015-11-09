#ofxPango
The ofxPango addon enables advanced text rendering in openFrameworks. It 
uses the Pango text rendering engine (www.pango.org). Pango has some nice
features as:

- justified text
- simple markup language
- dynamic font loading (from your system directory)

-----

##This Fork
Kitschpatrol's fork adds openFrameworks 9.0 and 64-bit support. (64 bit support on Windows pending.)

Notes:

Building Dependencies:

Compiled libraries are included in this addon to fulfill all required dependencies. For OSX, these were built through [homebrew](http://brew.sh). For the record, two formulae had to be modified to build static libs instead of dylibs. The modified formulae are included in this repo.

	// from the /docs/homebrew folder in this repo
	brew rm cairo
	brew rm pango
	brew rm harfbuzz
	brew install cairo --universal
	brew install pango.rb --universal
	brew install harfbuzz.rb --with-cairo --universal


Link system frameworks:  

- ibffi
- libiconv

##TODO

- Create addon_config.mk
- 64-bit support on windows
- Visual Studio 2015 example