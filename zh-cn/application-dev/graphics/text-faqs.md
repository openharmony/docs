# 文本开发常见问题

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @oh_wangxk; @gmiao522; @Lem0nC-->
<!--Designer: @liumingxiang-->
<!--Tester: @yhl0101-->
<!--Adviser: @ge-yafang-->

## 如何对找不到字形的字符进行显示优化

目前对于找不到字形的字符默认显示为空白，可能让用户感到困惑。

系统提供开关，开启后，未找到字形的字符会显示为豆腐块。

- 在ArkTS环境中，可以使用setTextUndefinedGlyphDisplay接口开启开关，找不到字形的字符会强制显示为豆腐块。

  ```ts
  import { text } from "@kit.ArkGraphics2D";

  text.setTextUndefinedGlyphDisplay(text.TextUndefinedGlyphDisplay.USE_TOFU);
  ```

  

- 在C/C++环境中，可以使用OH_Drawing_SetTextUndefinedGlyphDisplay接口开启开关，找不到字形的字符会强制显示为豆腐块。

  ```c
  #include "drawing/drawing_text_global.h"

  OH_Drawing_SetTextUndefinedGlyphDisplay(TEXT_NO_GLYPH_USE_TOFU);
  ```


上述两个接口控制同一个开关，使用其一即可。

以`"\uffffHello World\uffff"`文本为例，其中`\uffff `表示一个找不到字形的字符。

对比效果如下：

| 是否开启显示优化 | 示意效果                                                     |
| ---------------- | ------------------------------------------------------------ |
| 未开启           | ![zh-cn_image_undefined_off_ts](figures/zh-cn_image_undefined_off_ts.png) |
| 开启             | ![zh-cn_image_undefined_on_ts](figures/zh-cn_image_undefined_on_ts.png) |