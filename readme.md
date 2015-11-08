#ofxPango
The ofxPango addon enables advanced text rendering in openFrameworks. It 
uses the Pango text rendering engine (www.pango.org). Pango has some nice
features as:

- justified text
- simple markup language
- dynamic font loading (from your system directory)

-----

##This Fork
kitschpatrol's fork is currently working towards getting this running on of 9.0 / 64 bit on mac and windows.

Notes:

Building Dependencies:

The dependency libraries for mac were built through homebrew. Two formulae had to be modified to build static libs instead of dylibs.

	// from the /homebrew folder in this repo
	brew rm cairo
	brew rm pango
	brew rm harfbuzz
	brew install cairo --universal
	brew install pango --universal
	brew install harfbuzz.rb --with-cairo --universal


-----

Legacy readme documentation:

##Installation Windows (Code::Blocks)
- Add the ofxPango\src to your project
- Project > Build Options > Search directories tab
		..\..\..\addons_diederick\ofxPango\libs\pango\include\
		..\..\..\addons_diederick\ofxPango\libs\glib\include\
		..\..\..\addons_diederick\ofxPango\libs\cairo\include\cairo\
		..\..\..\addons_diederick\ofxPango\src\
		
- Project > Build Options > Linker Settings
		..\..\..\addons_diederick\ofxPango\libs\pango\lib\win\libpangocairo-1.0-0.dll
		..\..\..\addons_diederick\ofxPango\libs\pango\lib\win\libpango-1.0-0.dll
		..\..\..\addons_diederick\ofxPango\libs\cairo\lib\win\libcairo-2.dll
		..\..\..\addons_diederick\ofxPango\src\libs\win\libgobject-2.0-0.dll
		
- Copy the dll files from: ofxPango\src\libs\win\ and ofxPango\src\libs\static\ to your bin directory. 


##Installation Mac (XCode)
- Add the ofxPango\src to your project
- Project > Build Options > Search directories tab
	../../../addons_diederick/ofxPango/libs/pango/include/
	../../../addons_diederick/ofxPango/libs/glib/include/
	../../../addons_diederick/ofxPango/libs/cairo/include/cairo/
	../../../addons_diederick/ofxPango/src/

	
## Errors / faq.
- 	Undefined  symbols errors.
	When you get an error like:

	Undefined symbols:
	  "_fopen$UNIX2003", referenced from:
		  _some_function in somefile.o
	
	Make sure you compile against the 10.6 SDK!



