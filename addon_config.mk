meta:
	ADDON_NAME = ofxPango
	ADDON_DESCRIPTION = An openFrameworks addon for advanced text rendering with Pango and Cairo. Supports justified text, inline style markup, and system fonts.
	ADDON_AUTHOR = Diederick Huijbers, Eric Mika
	ADDON_TAGS = "openframeworks" "ofx-addon" "pango" "cairo" "text-rendering" "typography"
	ADDON_URL = https://github.com/kitschpatrol/ofxPango

common:

osx:
	# The bundled static libraries also need these system libraries
	ADDON_LDFLAGS = -lffi -liconv

linux64:
	# The bundled libraries only cover macOS and Windows, so use the system's Pango instead
	ADDON_PKG_CONFIG_LIBRARIES = pangocairo
	ADDON_LIBS_EXCLUDE = libs/pango/%
	ADDON_INCLUDES_EXCLUDE = libs/pango
	ADDON_INCLUDES_EXCLUDE += libs/pango/%
