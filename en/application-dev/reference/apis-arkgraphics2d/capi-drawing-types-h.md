# drawing_types.h
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphic-->
<!--Owner: @hangmengxin-->
<!--Designer: @wangyanglan-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->

## Overview

The **drawing_types.h** file declares the data types of the canvas, brush, pen, bitmap, and path used to draw 2D graphics.

**Header file**: <native_drawing/drawing_types.h>

**Library**: libnative_drawing.so

**Since**: 8

**Related module**: [Drawing](capi-drawing.md)

## Total

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_Drawing_Point2D](capi-drawing-oh-drawing-point2d.md) | OH_Drawing_Point2D | Describes a two-dimensional coordinate point.|
| [OH_Drawing_Point3D](capi-drawing-oh-drawing-point3d.md) | OH_Drawing_Point3D | Describes a three-dimensional coordinate point.|
| [OH_Drawing_Image_Info](capi-drawing-oh-drawing-image-info.md) | OH_Drawing_Image_Info | Describes the image information.|
| [OH_Drawing_RectStyle_Info](capi-drawing-oh-drawing-rectstyle-info.md) | OH_Drawing_RectStyle_Info | Describes the style of a rectangle.|
| [OH_Drawing_String](capi-drawing-oh-drawing-string.md) | OH_Drawing_String | Describes a string of characters encoded in UTF-16.|
| [OH_Drawing_Canvas](capi-drawing-oh-drawing-canvas.md) | OH_Drawing_Canvas | Defines a struct for a rectangular canvas, on which various shapes, images, and texts can be drawn by using the brush and pen.|
| [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md) | OH_Drawing_Pen | Defines a struct for a pen, which is used to describe the style and color to outline a shape.|
| [OH_Drawing_Region](capi-drawing-oh-drawing-region.md) | OH_Drawing_Region | Defines a struct for a region, which represents a closed area on the canvas for more accurate graphic control.|
| [OH_Drawing_Brush](capi-drawing-oh-drawing-brush.md) | OH_Drawing_Brush | Defines a struct for a brush, which is used to describe the style and color to fill in a shape.|
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md) | OH_Drawing_Path | Defines a struct for a path, which is used to customize various shapes.|
| [OH_Drawing_Bitmap](capi-drawing-oh-drawing-bitmap.md) | OH_Drawing_Bitmap | Defines a struct for a bitmap, which is a memory area that contains the pixel data of a shape.|
| [OH_Drawing_Point](capi-drawing-oh-drawing-point.md) | OH_Drawing_Point | Defines a struct for a coordinate point.|
| [OH_Drawing_PixelMap](capi-drawing-oh-drawing-pixelmap.md) | OH_Drawing_PixelMap | Defines a struct for a pixel map, which is used to wrap the real pixel map supported by the image framework.|
| [OH_Drawing_ColorSpace](capi-drawing-oh-drawing-colorspace.md) | OH_Drawing_ColorSpace | Defines a struct for a color space, which is used to describe the color information.|
| [OH_Drawing_PathEffect](capi-drawing-oh-drawing-patheffect.md) | OH_Drawing_PathEffect | Defines a struct for a path effect that affects the stroke.|
| [OH_Drawing_Rect](capi-drawing-oh-drawing-rect.md) | OH_Drawing_Rect | Defines a struct for a rectangle.|
| [OH_Drawing_RoundRect](capi-drawing-oh-drawing-roundrect.md) | OH_Drawing_RoundRect | Defines a struct for a rounded rectangle.|
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md) | OH_Drawing_Matrix | Defines a struct for a matrix, which is used to describe coordinate transformation.|
| [OH_Drawing_ShaderEffect](capi-drawing-oh-drawing-shadereffect.md) | OH_Drawing_ShaderEffect | Defines a struct for a shader effect, which is used to describe the source color of the drawn content.|
| [OH_Drawing_ShadowLayer](capi-drawing-oh-drawing-shadowlayer.md) | OH_Drawing_ShadowLayer | Defines a struct for a shadow, which is used to describe the shadow layer of the drawn content.|
| [OH_Drawing_Filter](capi-drawing-oh-drawing-filter.md) | OH_Drawing_Filter | Defines a struct for a filter, which consists of a color filter, mask filter, and image filter.|
| [OH_Drawing_MaskFilter](capi-drawing-oh-drawing-maskfilter.md) | OH_Drawing_MaskFilter | Defines a struct for a mask filter.|
| [OH_Drawing_ColorFilter](capi-drawing-oh-drawing-colorfilter.md) | OH_Drawing_ColorFilter | Defines a struct for a color filter, which is used to convert a color into a new one.|
| [OH_Drawing_Font](capi-drawing-oh-drawing-font.md) | OH_Drawing_Font | Defines a struct for a font.|
| [OH_Drawing_FontFeatures](capi-drawing-oh-drawing-fontfeatures.md) | OH_Drawing_FontFeatures | Defines a struct for font features, which are typesetting rules within a font that determine how glyphs look, For example, ligatures, alternative glyphs, and superscripts and subscripts.|
| [OH_Drawing_MemoryStream](capi-drawing-oh-drawing-memorystream.md) | OH_Drawing_MemoryStream | Defines a struct for a memory stream.|
| [OH_Drawing_FontArguments](capi-drawing-oh-drawing-fontarguments.md) | OH_Drawing_FontArguments | Defines a struct for font arguments.|
| [OH_Drawing_Typeface](capi-drawing-oh-drawing-typeface.md) | OH_Drawing_Typeface | Defines a struct for a typeface.|
| [OH_Drawing_TextBlob](capi-drawing-oh-drawing-textblob.md) | OH_Drawing_TextBlob | Defines a struct for a text blob, an immutable container that holds multiple texts. Each text blob consists of glyphs and position.|
| [OH_Drawing_Image](capi-drawing-oh-drawing-image.md) | OH_Drawing_Image | Defines a struct for an image that describes a two-dimensional pixel array.|
| [OH_Drawing_ImageFilter](capi-drawing-oh-drawing-imagefilter.md) | OH_Drawing_ImageFilter | Defines an image filter, which is used to operate all color bits that constitute image pixels.|
| [OH_Drawing_SamplingOptions](capi-drawing-oh-drawing-samplingoptions.md) | OH_Drawing_SamplingOptions | Defines a struct for sampling options, which describe the sampling methods for images and bitmaps.|
| [OH_Drawing_TextBlobBuilder](capi-drawing-oh-drawing-textblobbuilder.md) | OH_Drawing_TextBlobBuilder | Defines a struct for a text blob builder, which is used to build a text blob.|
| [OH_Drawing_GpuContext](capi-drawing-oh-drawing-gpucontext.md) | OH_Drawing_GpuContext | Defines a struct for the GPU context, which is used to describe the GPU backend context.|
| [OH_Drawing_Surface](capi-drawing-oh-drawing-surface.md) | OH_Drawing_Surface | Defines a struct for a surface, which is used to manage the content drawn on the canvas.|
| [OH_Drawing_FontMgr](capi-drawing-oh-drawing-fontmgr.md) | OH_Drawing_FontMgr | Defines a struct for the font manager, which is used for font management.|
| [OH_Drawing_FontStyleSet](capi-drawing-oh-drawing-fontstyleset.md) | OH_Drawing_FontStyleSet | Defines a struct for a font style set, which is used for font style family matching.|
| [OH_Drawing_RecordCmdUtils](capi-drawing-oh-drawing-recordcmdutils.md) | OH_Drawing_RecordCmdUtils | Defines the recording command tool, which is used to generate recording commands.|
| [OH_Drawing_RecordCmd](capi-drawing-oh-drawing-recordcmd.md) | OH_Drawing_RecordCmd | Defines the recording command class, which is used to store the set of recording commands.|
| [OH_Drawing_Array](capi-drawing-oh-drawing-array.md) | OH_Drawing_Array | Defines a struct for an array object, which is used to store multiple objects of the same type.|

### Enumerated value

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_Drawing_ColorFormat](#oh_drawing_colorformat) | OH_Drawing_ColorFormat | Defines an enum for the storage formats of bitmap pixels.|
| [OH_Drawing_AlphaFormat](#oh_drawing_alphaformat) | OH_Drawing_AlphaFormat | Defines an enum for the alpha formats of bitmap pixels.|
| [OH_Drawing_BlendMode](#oh_drawing_blendmode) | OH_Drawing_BlendMode | Defines an enum for blend modes. In blend mode, each operation generates a new color from two colors (source color and destination color).<br>These operations are the same for the red, green, and blue color channels (the alpha channel follows a different rule).<br>For simplicity, the following description uses the alpha channel as an example rather than naming each channel individually. For brevity, the following abbreviations are used:<br>s: source<br>d: destination<br>**sa**: source alpha.<br>**da**: destination alpha.<br>The following abbreviations are used in the calculation result:<br>r: If the four channels are calculated in the same way, r is used.<br>**ra**: used when only the alpha channel is manipulated.<br>rc: If three color channels are operated, rc is used.|
| [OH_Drawing_TextEncoding](#oh_drawing_textencoding) | OH_Drawing_TextEncoding | Defines an enum for the text encoding types.|

## Enum Description

### OH_Drawing_ColorFormat

```
enum OH_Drawing_ColorFormat
```

**Description**

Enumerates the storage formats of bitmap pixels.

**Since**: 8

| Value| Description|
| -- | -- |
| COLOR_FORMAT_UNKNOWN | Unknown format.|
| COLOR_FORMAT_ALPHA_8 | Each pixel is represented by an 8-bit value, and the 8 bits indicate the alpha component.|
| COLOR_FORMAT_RGB_565 | Each pixel is represented by 16 bits. From the most significant bit to the least significant bit, the first 5 bits indicate red, the subsequent 6 bits indicate green, and the last 5 bits indicate blue.|
| COLOR_FORMAT_ARGB_4444 | Each pixel is represented by 16 bits. From the most significant bit to the least significant bit, every 4 bits indicate alpha, red, green, and blue, respectively.|
| COLOR_FORMAT_RGBA_8888 | Each pixel is represented by 32 bits. From the most significant bit to the least significant bit, every 8 bits indicate alpha, red, green, and blue, respectively.|
| COLOR_FORMAT_BGRA_8888 | Each pixel is represented by 32 bits. From the most significant bit to the least significant bit, every 8 bits indicate blue, green, red, and alpha, respectively.|

### OH_Drawing_AlphaFormat

```
enum OH_Drawing_AlphaFormat
```

**Description**

Enumerates the alpha formats of bitmap pixels.

**Since**: 8

| Value| Description|
| -- | -- |
| ALPHA_FORMAT_UNKNOWN | Unknown format.|
| ALPHA_FORMAT_OPAQUE | The bitmap does not have the alpha component.|
| ALPHA_FORMAT_PREMUL | The color component of each pixel is premultiplied by the alpha component.|
| ALPHA_FORMAT_UNPREMUL | The color component of each pixel is not premultiplied by the alpha component.|

### OH_Drawing_BlendMode

```
enum OH_Drawing_BlendMode
```

**Description**

Defines an enum for blend modes. In blend mode, each operation generates a new color from two colors (source color and destination color).<br>These operations are the same for the red, green, and blue color channels (the alpha channel follows a different rule).<br>For simplicity, the following description uses the alpha channel as an example rather than naming each channel individually. For brevity, the following abbreviations are used:<br>s: source<br>d: destination<br>**sa**: source alpha.<br>**da**: destination alpha.<br>The following abbreviations are used in the calculation result:<br>r: If the calculation methods of the four channels are the same, r is used.<br>**ra**: used when only the alpha channel is manipulated.<br>**rc**: used when the other three color channels are manipulated.

**Since**: 11

| Value| Description|
| -- | -- |
| BLEND_MODE_CLEAR | Clear mode. r = 0.|
| BLEND_MODE_SRC | r = s (The four channels of **result** are equal to the four channels of **source**, that is, the result is equal to the source.)|
| BLEND_MODE_DST | r = d (The four channels of **result** are equal to the four channels of **destination**, that is, the result is equal to the destination.)|
| BLEND_MODE_SRC_OVER | r = s + (1 - sa) * d.|
| BLEND_MODE_DST_OVER | r = d + (1 - da) * s.|
| BLEND_MODE_SRC_IN | r = s * da.|
| BLEND_MODE_DST_IN | r = d * sa.|
| BLEND_MODE_SRC_OUT | r = s * (1 - da).|
| BLEND_MODE_DST_OUT | r = d * (1 - sa).|
| BLEND_MODE_SRC_ATOP | r = s * da + d * (1 - sa).|
| BLEND_MODE_DST_ATOP | r = d * sa + s * (1 - da).|
| BLEND_MODE_XOR | r = s * (1 - da) + d * (1 - sa).|
| BLEND_MODE_PLUS | r = min(s + d, 1).|
| BLEND_MODE_MODULATE | r = s * d.|
| BLEND_MODE_SCREEN | Screen mode, r = s + d – s x d.|
| BLEND_MODE_OVERLAY | Overlay mode.|
| BLEND_MODE_DARKEN | Darken mode. rc = s + d – max(s * da, d * sa), ra = s + (1 – sa) * d.|
| BLEND_MODE_LIGHTEN | Lighten mode. rc = s + d – min(s * da, d * sa), ra = s + (1 – sa) * d.|
| BLEND_MODE_COLOR_DODGE | Color dodge mode.|
| BLEND_MODE_COLOR_BURN | Color burn mode.|
| BLEND_MODE_HARD_LIGHT | Hard light mode.|
| BLEND_MODE_SOFT_LIGHT | Soft light mode.|
| BLEND_MODE_DIFFERENCE | Difference mode. rc = s + d – 2 * (min(s * da, d * sa)), ra = s + (1 – sa) * d.|
| BLEND_MODE_EXCLUSION | Exclusion mode. rc = s + d – two(s * d), ra = s + (1 – sa) * d.|
| BLEND_MODE_MULTIPLY | Multiply mode. r = s * (1 – da) + d * (1 – sa) + s * d.|
| BLEND_MODE_HUE | Hue mode.|
| BLEND_MODE_SATURATION | Saturation mode.|
| BLEND_MODE_COLOR | Color mode.|
| BLEND_MODE_LUMINOSITY | Luminosity mode.|

### OH_Drawing_TextEncoding

```
enum OH_Drawing_TextEncoding
```

**Description**

Enumerates the text encoding types.

**Since**: 12

| Value| Description|
| -- | -- |
| TEXT_ENCODING_UTF8 | One byte used to indicate UTF-8 or ASCII characters.|
| TEXT_ENCODING_UTF16 | Two bytes used to indicate most Unicode characters.|
| TEXT_ENCODING_UTF32 | Four bytes used to indicate all Unicode characters.|
| TEXT_ENCODING_GLYPH_ID | Two bytes used to indicate the glyph index.|
