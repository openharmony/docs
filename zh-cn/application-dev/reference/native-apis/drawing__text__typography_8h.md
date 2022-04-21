# drawing_text_typography.h


## **Overview**

**Related Modules:**

[Drawing](_drawing.md)

**Description:**

定义绘制模块中排版相关的函数

**Since:**
8
**Version:**
1.0

## **Summary**


### Enumerations

  | Enumeration&nbsp;Name | Description | 
| -------- | -------- |
| [OH_Drawing_TextDirection](_drawing.md#ga7dc9803407c3fea32075122c7605ffb2)&nbsp;{&nbsp;[TEXT_DIRECTION_RTL](_drawing.md#gga7dc9803407c3fea32075122c7605ffb2a7b4debd0a116bc438085a43efa3824cf),&nbsp;[TEXT_DIRECTION_LTR](_drawing.md#gga7dc9803407c3fea32075122c7605ffb2a81d702a35ec4d3482ea5ff10edd8cab7)&nbsp;} | 文字方向 | 
| [OH_Drawing_TextAlign](_drawing.md#ga3fee1a3916c2376e62e7957be15a1b02)&nbsp;{&nbsp;&nbsp;&nbsp;[TEXT_ALIGN_LEFT](_drawing.md#gga3fee1a3916c2376e62e7957be15a1b02a3b85bc4d8cfda6b273b534eb2e1cebfc),&nbsp;[TEXT_ALIGN_RIGHT](_drawing.md#gga3fee1a3916c2376e62e7957be15a1b02abc81ce8623a972fc7b97f497189c494b),&nbsp;[TEXT_ALIGN_CENTER](_drawing.md#gga3fee1a3916c2376e62e7957be15a1b02a4da3c85cde615e7442df8ef17d0753ba),&nbsp;[TEXT_ALIGN_JUSTIFY](_drawing.md#gga3fee1a3916c2376e62e7957be15a1b02a3e3185762a0ae703ae1eab769eb3191d),&nbsp;&nbsp;&nbsp;[TEXT_ALIGN_START](_drawing.md#gga3fee1a3916c2376e62e7957be15a1b02a72f2441e221a61374bd891dc2b75bcb0),&nbsp;[TEXT_ALIGN_END](_drawing.md#gga3fee1a3916c2376e62e7957be15a1b02a17b99fff762deffd75c0de66cd27d219)&nbsp;} | 文字对齐方式 | 
| [OH_Drawing_FontWeight](_drawing.md#ga7a1d4dd0ce9dd97bf3bbbad3b87f7f21)&nbsp;{&nbsp;&nbsp;&nbsp;[FONT_WEIGHT_100](_drawing.md#gga7a1d4dd0ce9dd97bf3bbbad3b87f7f21a23b26a36963095342fe2e0697910a6e6),&nbsp;[FONT_WEIGHT_200](_drawing.md#gga7a1d4dd0ce9dd97bf3bbbad3b87f7f21a4f29ce93f64a0085ca2154ee25d9e138),&nbsp;[FONT_WEIGHT_300](_drawing.md#gga7a1d4dd0ce9dd97bf3bbbad3b87f7f21a093d1106fec67eebea0dbcb2ebbe9a64),&nbsp;[FONT_WEIGHT_400](_drawing.md#gga7a1d4dd0ce9dd97bf3bbbad3b87f7f21a62367da70683540c34ddaf2a519f22a3),&nbsp;&nbsp;&nbsp;[FONT_WEIGHT_500](_drawing.md#gga7a1d4dd0ce9dd97bf3bbbad3b87f7f21aef238378a2c00c698e269b052d31d904),&nbsp;[FONT_WEIGHT_600](_drawing.md#gga7a1d4dd0ce9dd97bf3bbbad3b87f7f21a63eebceda71bb1ffdae4a5503d63bbd9),&nbsp;[FONT_WEIGHT_700](_drawing.md#gga7a1d4dd0ce9dd97bf3bbbad3b87f7f21ae6abaa1dc57d487006cbe6c8e0f87bc6),&nbsp;[FONT_WEIGHT_800](_drawing.md#gga7a1d4dd0ce9dd97bf3bbbad3b87f7f21ad34b21ce514a03d6d98b75341bb5726e),&nbsp;&nbsp;&nbsp;[FONT_WEIGHT_900](_drawing.md#gga7a1d4dd0ce9dd97bf3bbbad3b87f7f21ac3f4c8f2d6a6922780166cc08df83461)&nbsp;} | 字重 | 
| [OH_Drawing_TextBaseline](_drawing.md#ga23be0106a439e7498cbbb1d048733ec5)&nbsp;{&nbsp;[TEXT_BASELINE_ALPHABETIC](_drawing.md#gga23be0106a439e7498cbbb1d048733ec5ad436b9da96a5246e75e785a0585963f9),&nbsp;[TEXT_BASELINE_IDEOGRAPHIC](_drawing.md#gga23be0106a439e7498cbbb1d048733ec5a723ba0ba56cd7106deb97c95f51febcf)&nbsp;} | 基线位置 | 
| [OH_Drawing_TextDecoration](_drawing.md#ga11b405dddb93d91c3a5b4482d8a9165b)&nbsp;{&nbsp;[TEXT_DECORATION_NONE](_drawing.md#gga11b405dddb93d91c3a5b4482d8a9165ba2b42614c2c9b73ffecf31769cfd60f28)&nbsp;=&nbsp;0x0,&nbsp;[TEXT_DECORATION_UNDERLINE](_drawing.md#gga11b405dddb93d91c3a5b4482d8a9165ba0fc17108b6c8a91d840889336c669dda)&nbsp;=&nbsp;0x1,&nbsp;[TEXT_DECORATION_OVERLINE](_drawing.md#gga11b405dddb93d91c3a5b4482d8a9165bad8415c121f9b656cd5c6cab927d78802)&nbsp;=&nbsp;0x2,&nbsp;[TEXT_DECORATION_LINE_THROUGH](_drawing.md#gga11b405dddb93d91c3a5b4482d8a9165ba25692d42e0a907af878d99a0a31f7f47)&nbsp;=&nbsp;0x4&nbsp;} | 文本装饰 | 
| [OH_Drawing_FontStyle](_drawing.md#ga9cd0177d2561ccef51adbae0f8a42eec)&nbsp;{&nbsp;[FONT_STYLE_NORMAL](_drawing.md#gga9cd0177d2561ccef51adbae0f8a42eeca307e676fb5de5c785e856272b2f0e8ce),&nbsp;[FONT_STYLE_ITALIC](_drawing.md#gga9cd0177d2561ccef51adbae0f8a42eeca6054e24016c46486668dd42e4b86c036)&nbsp;} | 区分字体是否为斜体 | 


### Functions

  | Function | Description | 
| -------- | -------- |
| [OH_Drawing_CreateTypographyStyle](_drawing.md#ga19561093a2d5ec17f2c73b40f0d97376)&nbsp;(void) | [OH_Drawing_TypographyStyle](_drawing.md#ga270cc54313a929ea90235840668daef9)&nbsp;\*<br/>创建OH_Drawing_TypographyStyle | 
| [OH_Drawing_DestroyTypographyStyle](_drawing.md#ga9bd838c0d86136e16faca0ada643d87e)&nbsp;([OH_Drawing_TypographyStyle](_drawing.md#ga270cc54313a929ea90235840668daef9)&nbsp;\*) | void<br/>释放被OH_Drawing_TypographyStyle对象占据的内存 | 
| [OH_Drawing_SetTypographyTextDirection](_drawing.md#ga9e96b89ffc3f06f50ab38f05689e766e)&nbsp;([OH_Drawing_TypographyStyle](_drawing.md#ga270cc54313a929ea90235840668daef9)&nbsp;\*,&nbsp;int) | void<br/>设置文本方向 | 
| [OH_Drawing_SetTypographyTextAlign](_drawing.md#gaa1a8b20a882ae6aa4e2ad442a18423da)&nbsp;([OH_Drawing_TypographyStyle](_drawing.md#ga270cc54313a929ea90235840668daef9)&nbsp;\*,&nbsp;int) | void<br/>设置文本对齐方式 | 
| [OH_Drawing_SetTypographyTextMaxLines](_drawing.md#gab74fd8ef23005bf584f87357147fa379)&nbsp;([OH_Drawing_TypographyStyle](_drawing.md#ga270cc54313a929ea90235840668daef9)&nbsp;\*,&nbsp;int) | void<br/>设置文本最大行数 | 
| [OH_Drawing_CreateTextStyle](_drawing.md#ga9041c35231647ed34306ef26f21037f9)&nbsp;(void) | [OH_Drawing_TextStyle](_drawing.md#gad731266accf168a6b50e1fa33ce90528)&nbsp;\*<br/>创建OH_Drawing_TextStyle | 
| [OH_Drawing_DestroyTextStyle](_drawing.md#ga2550946ac8d3c8c9ddc548e128175020)&nbsp;([OH_Drawing_TextStyle](_drawing.md#gad731266accf168a6b50e1fa33ce90528)&nbsp;\*) | void<br/>释放被OH_Drawing_TextStyle对象占据的内存 | 
| [OH_Drawing_SetTextStyleColor](_drawing.md#ga4c03826dd970defade08b67ed1861fc8)&nbsp;([OH_Drawing_TextStyle](_drawing.md#gad731266accf168a6b50e1fa33ce90528)&nbsp;\*,&nbsp;uint32_t) | void<br/>设置文本颜色 | 
| [OH_Drawing_SetTextStyleFontSize](_drawing.md#ga4f435be1d8b20bd0abac441ac91bb81d)&nbsp;([OH_Drawing_TextStyle](_drawing.md#gad731266accf168a6b50e1fa33ce90528)&nbsp;\*,&nbsp;double) | void<br/>设置字号 | 
| [OH_Drawing_SetTextStyleFontWeight](_drawing.md#ga751dd287f984367c18de6ca3a3a304ec)&nbsp;([OH_Drawing_TextStyle](_drawing.md#gad731266accf168a6b50e1fa33ce90528)&nbsp;\*,&nbsp;int) | void<br/>设置字重 | 
| [OH_Drawing_SetTextStyleBaseLine](_drawing.md#gacb93fa7c791e719cf9c5d218981f61ee)&nbsp;([OH_Drawing_TextStyle](_drawing.md#gad731266accf168a6b50e1fa33ce90528)&nbsp;\*,&nbsp;int) | void<br/>设置字体基线位置 | 
| [OH_Drawing_SetTextStyleDecoration](_drawing.md#ga2f029e23749fcd121aaae6e233202ded)&nbsp;([OH_Drawing_TextStyle](_drawing.md#gad731266accf168a6b50e1fa33ce90528)&nbsp;\*,&nbsp;int) | void<br/>设置装饰 | 
| [OH_Drawing_SetTextStyleDecorationColor](_drawing.md#ga22304942171ce4548b50057bd7d606be)&nbsp;([OH_Drawing_TextStyle](_drawing.md#gad731266accf168a6b50e1fa33ce90528)&nbsp;\*,&nbsp;uint32_t) | void<br/>设置装饰颜色 | 
| [OH_Drawing_SetTextStyleFontHeight](_drawing.md#gab96b5567c05f34e6ba7d48a4dd75eab4)&nbsp;([OH_Drawing_TextStyle](_drawing.md#gad731266accf168a6b50e1fa33ce90528)&nbsp;\*,&nbsp;double) | void<br/>设置字体高度 | 
| [OH_Drawing_SetTextStyleFontFamilies](_drawing.md#ga3f46d90176575f24040828264ce18a90)&nbsp;([OH_Drawing_TextStyle](_drawing.md#gad731266accf168a6b50e1fa33ce90528)&nbsp;\*,&nbsp;int,&nbsp;const&nbsp;char&nbsp;\*fontFamilies[]) | void<br/>设置字体类型 | 
| [OH_Drawing_SetTextStyleFontStyle](_drawing.md#ga67afa0910007fa3d8b15f2b6df61712c)&nbsp;([OH_Drawing_TextStyle](_drawing.md#gad731266accf168a6b50e1fa33ce90528)&nbsp;\*,&nbsp;int) | void<br/>设置字体风格 | 
| [OH_Drawing_SetTextStyleLocale](_drawing.md#ga7eb6f2da34059c013cfb0567c44813d4)&nbsp;([OH_Drawing_TextStyle](_drawing.md#gad731266accf168a6b50e1fa33ce90528)&nbsp;\*,&nbsp;const&nbsp;char&nbsp;\*) | void<br/>设置语言区域 | 
| [OH_Drawing_CreateTypographyHandler](_drawing.md#gae72088abf73419c0c8e8e524602a317e)&nbsp;([OH_Drawing_TypographyStyle](_drawing.md#ga270cc54313a929ea90235840668daef9)&nbsp;\*,&nbsp;[OH_Drawing_FontCollection](_drawing.md#ga4ce31d04a1580d4f50e87b8695fcebc7)&nbsp;\*) | [OH_Drawing_TypographyCreate](_drawing.md#gaedefc2b3d226b0b07abcbce76be4cdb9)&nbsp;\*<br/>创建指向OH_Drawing_TypographyCreate对象的指针 | 
| [OH_Drawing_DestroyTypographyHandler](_drawing.md#ga211dced7f1eaed0c5bd507cd75d003c8)&nbsp;([OH_Drawing_TypographyCreate](_drawing.md#gaedefc2b3d226b0b07abcbce76be4cdb9)&nbsp;\*) | void<br/>释放被OH_Drawing_TypographyCreate对象占据的内存 | 
| [OH_Drawing_TypographyHandlerPushStyle](_drawing.md#ga5aff793cec1b58c171817649b01f35d1)&nbsp;([OH_Drawing_TypographyCreate](_drawing.md#gaedefc2b3d226b0b07abcbce76be4cdb9)&nbsp;\*,&nbsp;[OH_Drawing_TextStyle](_drawing.md#gad731266accf168a6b50e1fa33ce90528)&nbsp;\*) | void<br/>设置排版风格 | 
| [OH_Drawing_TypographyHandlerAddText](_drawing.md#ga0bb4f9730faa77f6ed8cdce25e7965f2)&nbsp;([OH_Drawing_TypographyCreate](_drawing.md#gaedefc2b3d226b0b07abcbce76be4cdb9)&nbsp;\*,&nbsp;const&nbsp;char&nbsp;\*) | void<br/>设置文本内容 | 
| [OH_Drawing_TypographyHandlerPop](_drawing.md#gabe9b81431e1a7ca473fc0659c150bb6b)&nbsp;([OH_Drawing_TypographyCreate](_drawing.md#gaedefc2b3d226b0b07abcbce76be4cdb9)&nbsp;\*) | void<br/>排版弹出 | 
| [OH_Drawing_CreateTypography](_drawing.md#gaf996ac9db09b8d7c21b8ea4797ea0c19)&nbsp;([OH_Drawing_TypographyCreate](_drawing.md#gaedefc2b3d226b0b07abcbce76be4cdb9)&nbsp;\*) | [OH_Drawing_Typography](_drawing.md#ga70d06422fc84eb1ba49e35f525573007)&nbsp;\*<br/>创建OH_Drawing_Typography | 
| [OH_Drawing_DestroyTypography](_drawing.md#ga2d0d1b715931c104042c75e4d21a86a3)&nbsp;([OH_Drawing_Typography](_drawing.md#ga70d06422fc84eb1ba49e35f525573007)&nbsp;\*) | void<br/>释放OH_Drawing_Typography对象占据的内存 | 
| [OH_Drawing_TypographyLayout](_drawing.md#ga9032552c1d8d8e258f86832190223843)&nbsp;([OH_Drawing_Typography](_drawing.md#ga70d06422fc84eb1ba49e35f525573007)&nbsp;\*,&nbsp;double) | void<br/>排版布局 | 
| [OH_Drawing_TypographyPaint](_drawing.md#ga8b12b7dc251b3a2bb71f7e289a27e174)&nbsp;([OH_Drawing_Typography](_drawing.md#ga70d06422fc84eb1ba49e35f525573007)&nbsp;\*,&nbsp;[OH_Drawing_Canvas](_drawing.md#ga086e2de47ef7bfe6c96e6b09e87da33a)&nbsp;\*,&nbsp;double,&nbsp;double) | void<br/>显示文本 | 
