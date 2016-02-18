#ofxPango
The ofxPango addon enables advanced text rendering in openFrameworks. It 
uses the Pango text rendering engine (www.pango.org). Pango has some nice
features as:

- justified text
- simple markup language
- dynamic font loading (from your system directory)

-----

##Note

The [Cinder-Pango block](https://github.com/kitschpatrol/Cinder-Pango) has a much more friendly / abstracted API. It would be easy to back-port into this OF addon.

##This Fork
Kitschpatrol's fork adds openFrameworks 9.0 and 64-bit support for Mac and Windows.

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


On Windows:

64 bit libs via
http://tschoonj.github.io/blog/2014/09/29/gtk2-64-bit-windows-runtime-environment-installer-now-on-github had some issues... missing lib files.


gtk+-bundle_3.6.4-20130513_win64.zip
from http://www.tarnyko.net/dl/gtk.htm worked.

Also
http://lvserver.ugent.be/gtk-win64/


##TODO
- Bring over [Cinder-Pango](https://github.com/kitschpatrol/Cinder-Pango) API improvements and optimizations.
- Create addon_config.mk
- Visual Studio 2015 example
