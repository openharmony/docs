# Text Development FAQs

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @gmiao522-->
<!--Designer: @liumingxiang-->
<!--Tester: @yhl0101-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=3c9498a5af1cedc12000d743f1689bf266862723 translatedAt=2026-08-03T11:23:28.164Z pushedAt=2026-08-04T07:40:17.407Z -->

## How Do I Optimize the Display of Text with an Undefined Glyph?

Currently, the undefined glyphs are displayed as blanks by default, which may confuse users.

The system provides a switch, which can display undefined glyphs as tofu blocks once enabled.

- In ArkTS, you can use the **setTextUndefinedGlyphDisplay** API to enable the display of undefined glyphs as tofu blocks.

  ```ts
  import { text } from "@kit.ArkGraphics2D";

  text.setTextUndefinedGlyphDisplay(text.TextUndefinedGlyphDisplay.USE_TOFU);
  ```

- In C/C++, you can use the **OH_Drawing_SetTextUndefinedGlyphDisplay** API to enable the display of undefined glyphs as tofu blocks.

  ```c
  #include "drawing/drawing_text_global.h"

  OH_Drawing_SetTextUndefinedGlyphDisplay(TEXT_NO_GLYPH_USE_TOFU);
  ```

The preceding two APIs control the same switch. You can use either of them.

Take the text `"\uffffHello World\uffff"` as an example, where `\uffff` represents a character with a missing glyph.

The following figures show the comparison.

| Display Optimization Enabled or Not| Effect                                                    |
| ---------------- | ------------------------------------------------------------ |
| Disabled           | ![undefined-off-ts](figures/undefined-off-ts.png) |
| Enabled             | ![undefined-on-ts](figures/undefined-on-ts.png) |