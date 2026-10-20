<!-- title -->

# ofxPango

<!-- /title -->

<!-- short-description -->

**An openFrameworks addon for advanced text rendering with Pango and Cairo. Supports justified text, inline style markup, and system fonts.**

<!-- /short-description -->

## Overview

An [openFrameworks](https://openframeworks.cc/) addon that wraps Pango for text layout and Cairo for rendering. It supports justified text, inline markup for mixing fonts and styles, and fonts installed on your system. The rendered text can be read as pixels or uploaded to an openFrameworks image or texture.

Originally created by [Diederick Huijbers](https://github.com/diederickh/ofxPango). This fork added openFrameworks 0.9.0 compatibility and 64-bit support on macOS and Windows. The included Xcode and Visual Studio 2015 projects are from that era; compatibility with current openFrameworks releases has not been verified.

## Getting started

### Dependencies

Requires openFrameworks, Pango, and Cairo. Headers and prebuilt dependencies for macOS and Windows are included in [`libs/pango`](libs/pango):

- **macOS:** Static libraries for Intel (`i386` and `x86_64`) in [`libs/pango/lib/osx`](libs/pango/lib/osx). Apple silicon (`arm64`) builds require rebuilding the dependencies. [`addon_config.mk`](addon_config.mk) also links the system libraries `libffi` and `libiconv`.
- **Windows:** Import libraries and DLLs for 32-bit and 64-bit builds in [`libs/pango/lib/vs`](libs/pango/lib/vs). The [32-bit bundle's note](libs/pango/lib/vs/Win32/readme.md) lists missing `libharfbuzz-0.dll` and `libwinpthread-1.dll`; both are included in the 64-bit bundle.
- **Linux (64-bit):** Install the system Pango and Cairo development packages and `pkg-config`. The `linux64` section of `addon_config.mk` uses `pangocairo` through pkg-config and excludes the bundled headers and libraries. No Linux binaries are bundled.

The modified Homebrew formulae in [`docs/homebrew`](docs/homebrew) record how the bundled macOS static libraries were built. They are historical build recipes.

### Installation

Clone the repository into your openFrameworks `addons` folder:

```sh
cd openFrameworks/addons
git clone https://github.com/kitschpatrol/ofxPango.git
```

Add `ofxPango` to your project's `addons.make`, or select it in the openFrameworks Project Generator. To try the included [`example`](example), update its project files with the Project Generator for your openFrameworks installation.

## Usage

Create a layout, choose a font, set its text, and render it to an image:

```cpp
#include "ofMain.h"
#include "ofxPango.h"

ofxPango pango;
ofxPCPangoLayout *layout = pango.createLayout(640, 240);
layout->setFont("Sans 24");
layout->setJustify(true);
layout->setMarkup("<b>Bold</b>, <i>italic</i>, and <span foreground=\"red\">red</span> text.");
layout->context->clear();
layout->setTextColor(1.0f, 1.0f, 1.0f);
layout->show();

ofImage image = layout->getImage();
delete layout; // Also deletes the layout's context and surface.
```

Use `setText()` for plain text, or `setMarkup()` for Pango markup. Call `pango.listFonts()` to list the available font families.

Cairo produces pixels with premultiplied alpha. When drawing the resulting image or texture, use the blending setup shown in [`example/src/ofApp.cpp`](example/src/ofApp.cpp):

```cpp
glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
image.draw(0, 0);
ofEnableAlphaBlending();
```

The example also shows multilingual text, window resizing, and uploading `getRawPixels()` directly to a texture with `GL_BGRA` to avoid the conversion performed by `getPixels()` and `getImage()`.

[`example-NoOpenFrameworks`](example-NoOpenFrameworks) is a separate Pango/Cairo sanity check that writes a PNG without using the addon or openFrameworks.

## Related project

[Cinder-Pango](https://github.com/kitschpatrol/Cinder-Pango) provides a higher-level API for the same libraries in Cinder. Its API improvements have not been ported to this addon.

## License

This repository does not include a license file for the addon source since no license was declared in the [original implementation](https://github.com/diederickh/ofxPango).

The bundled dependencies have their own license notices in [`libs/pango/include`](libs/pango/include).
