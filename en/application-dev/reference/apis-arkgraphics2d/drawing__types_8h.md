# drawing_types.h


## Overview

The **drawing_types.h** file declares the data types of the canvas, brush, pen, bitmap, and path used to draw 2D graphics.

**File to include**: &lt;native_drawing/drawing_types.h&gt;

**Library**: libnative_drawing.so

**Since**: 8

**Related module**: [Drawing](_drawing.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct  [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) | Describes a two-dimensional coordinate point.| 
| struct  [OH_Drawing_Point3D](_o_h___drawing___point3_d.md) | Describes a three-dimensional coordinate point.| 
| struct  [OH_Drawing_Image_Info](_o_h___drawing___image___info.md) | Describes the image information.| 
| struct  [OH_Drawing_RectStyle_Info](_o_h___drawing___rect_style___info.md) | Describes the style of a rectangle.| 
| struct  [OH_Drawing_String](_o_h___drawing___string.md) | Describes a string of characters encoded in UTF-16. | 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_Drawing_Array](_drawing.md#oh_drawing_array) [OH_Drawing_Array](_drawing.md#oh_drawing_array) | Defines a struct for an array object, which is used to store multiple objects of the same type. | 
| typedef struct [OH_Drawing_String](_o_h___drawing___string.md) [OH_Drawing_String](_drawing.md#oh_drawing_string) | Defines a struct for a string of characters encoded in UTF-16. | 
| typedef struct [OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas)  [OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) | Defines a struct for a rectangular canvas, on which various shapes, images, and texts can be drawn by using the brush and pen.| 
| typedef struct [OH_Drawing_Pen](_drawing.md#oh_drawing_pen)  [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) | Defines a struct for a pen, which is used to describe the style and color to outline a shape.| 
| typedef struct [OH_Drawing_Region](_drawing.md#oh_drawing_region)  [OH_Drawing_Region](_drawing.md#oh_drawing_region) | Defines a struct for a region, which represents a closed area on the canvas for more accurate graphic control.| 
| typedef struct [OH_Drawing_Brush](_drawing.md#oh_drawing_brush)  [OH_Drawing_Brush](_drawing.md#oh_drawing_brush) | Defines a struct for a brush, which is used to describe the style and color to fill in a shape.| 
| typedef struct [OH_Drawing_Path](_drawing.md#oh_drawing_path)  [OH_Drawing_Path](_drawing.md#oh_drawing_path) | Defines a struct for a path, which is used to customize various shapes.| 
| typedef struct [OH_Drawing_PixelMap](_drawing.md#oh_drawing_pixelmap)  [OH_Drawing_PixelMap](_drawing.md#oh_drawing_pixelmap) | Defines a struct for a pixel map, which is used to wrap the real pixel map supported by the image framework.| 
| typedef struct [OH_Drawing_Bitmap](_drawing.md#oh_drawing_bitmap)  [OH_Drawing_Bitmap](_drawing.md#oh_drawing_bitmap) | Defines a struct for a bitmap, which is a memory area that contains the pixel data of a shape.| 
| typedef struct [OH_Drawing_Point](_drawing.md#oh_drawing_point)  [OH_Drawing_Point](_drawing.md#oh_drawing_point) | Defines a struct for a coordinate point.| 
| typedef struct [OH_Drawing_ColorSpace](_drawing.md#oh_drawing_colorspace)  [OH_Drawing_ColorSpace](_drawing.md#oh_drawing_colorspace) | Defines a struct for a color space, which is used to describe the color information.| 
| typedef struct [OH_Drawing_Point2D](_o_h___drawing___point2_d.md)  [OH_Drawing_Point2D](_drawing.md#oh_drawing_point2d) | Defines a struct for a two-dimensional coordinate point.| 
| typedef [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) [OH_Drawing_Corner_Radii](_drawing.md#oh_drawing_corner_radii) | Defines a struct for the radii of a rounded corner. The radii consist of the radius in the x-axis direction and that in the y-axis direction.| 
| typedef struct [OH_Drawing_Point3D](_o_h___drawing___point3_d.md)  [OH_Drawing_Point3D](_drawing.md#oh_drawing_point3d) | Defines a struct for a three-dimensional coordinate point.| 
| typedef struct [OH_Drawing_PathEffect](_drawing.md#oh_drawing_patheffect)  [OH_Drawing_PathEffect](_drawing.md#oh_drawing_patheffect) | Defines a struct for a path effect that affects the stroke.| 
| typedef struct [OH_Drawing_Rect](_drawing.md#oh_drawing_rect)  [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) | Defines a struct for a rectangle.| 
| typedef struct [OH_Drawing_RoundRect](_drawing.md#oh_drawing_roundrect)  [OH_Drawing_RoundRect](_drawing.md#oh_drawing_roundrect) | Defines a struct for a rounded rectangle.| 
| typedef struct [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix)  [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) | Defines a struct for a matrix, which is used to describe coordinate transformation.| 
| typedef struct [OH_Drawing_ShaderEffect](_drawing.md#oh_drawing_shadereffect)  [OH_Drawing_ShaderEffect](_drawing.md#oh_drawing_shadereffect) | Defines a struct for a shader effect, which is used to describe the source color of the drawn content.| 
| typedef struct [OH_Drawing_ShadowLayer](_drawing.md#oh_drawing_shadowlayer) [OH_Drawing_ShadowLayer](_drawing.md#oh_drawing_shadowlayer) | Defines a struct for a shadow, which is used to describe the shadow layer of the drawn content.| 
| typedef struct [OH_Drawing_Filter](_drawing.md#oh_drawing_filter)  [OH_Drawing_Filter](_drawing.md#oh_drawing_filter) | Defines a struct for a filter, which consists of a color filter, mask filter, and image filter.| 
| typedef struct [OH_Drawing_MaskFilter](_drawing.md#oh_drawing_maskfilter)  [OH_Drawing_MaskFilter](_drawing.md#oh_drawing_maskfilter) | Defines a struct for a mask filter.| 
| typedef struct [OH_Drawing_ColorFilter](_drawing.md#oh_drawing_colorfilter)  [OH_Drawing_ColorFilter](_drawing.md#oh_drawing_colorfilter) | Defines a struct for a color filter, which is used to convert a color into a new one.| 
| typedef struct [OH_Drawing_ImageFilter](_drawing.md#oh_drawing_imagefilter)  [OH_Drawing_ImageFilter](_drawing.md#oh_drawing_imagefilter) | Defines a struct for an image filter, which is used to operate all color bits that make up image pixels.| 
| typedef struct [OH_Drawing_Font](_drawing.md#oh_drawing_font)  [OH_Drawing_Font](_drawing.md#oh_drawing_font) | Defines a struct for a font.| 
| typedef struct [OH_Drawing_MemoryStream](_drawing.md#oh_drawing_memorystream)  [OH_Drawing_MemoryStream](_drawing.md#oh_drawing_memorystream) | Defines a struct for a memory stream.| 
| typedef struct [OH_Drawing_FontArguments](_drawing.md#oh_drawing_fontarguments) [OH_Drawing_FontArguments](_drawing.md#oh_drawing_fontarguments) | Defines a struct for font arguments.| 
| typedef struct [OH_Drawing_Typeface](_drawing.md#oh_drawing_typeface)  [OH_Drawing_Typeface](_drawing.md#oh_drawing_typeface) | Defines a struct for a typeface.| 
| typedef struct [OH_Drawing_TextBlob](_drawing.md#oh_drawing_textblob)  [OH_Drawing_TextBlob](_drawing.md#oh_drawing_textblob) | Defines a struct for a text blob, an immutable container that holds multiple texts. Each text blob consists of glyphs and position.| 
| typedef struct [OH_Drawing_Image](_drawing.md#oh_drawing_image)  [OH_Drawing_Image](_drawing.md#oh_drawing_image) | Defines a struct for an image that describes a two-dimensional pixel array.| 
| typedef struct [OH_Drawing_SamplingOptions](_drawing.md#oh_drawing_samplingoptions)  [OH_Drawing_SamplingOptions](_drawing.md#oh_drawing_samplingoptions) | Defines a struct for sampling options, which describe the sampling methods for images and bitmaps.| 
| typedef struct [OH_Drawing_TextBlobBuilder](_drawing.md#oh_drawing_textblobbuilder)  [OH_Drawing_TextBlobBuilder](_drawing.md#oh_drawing_textblobbuilder) | Defines a struct for a text blob builder, which is used to build a text blob.| 
| typedef struct [OH_Drawing_GpuContext](_drawing.md#oh_drawing_gpucontext)  [OH_Drawing_GpuContext](_drawing.md#oh_drawing_gpucontext) | Defines a struct for the GPU context, which is used to describe the GPU backend context.| 
| typedef struct [OH_Drawing_Surface](_drawing.md#oh_drawing_surface)  [OH_Drawing_Surface](_drawing.md#oh_drawing_surface) | Defines a struct for a surface, which is used to manage the content drawn on the canvas.| 
| typedef enum [OH_Drawing_ColorFormat](_drawing.md#oh_drawing_colorformat)  [OH_Drawing_ColorFormat](_drawing.md#oh_drawing_colorformat) | Defines an enum for storage formats of bitmap pixels.| 
| typedef enum [OH_Drawing_AlphaFormat](_drawing.md#oh_drawing_alphaformat)  [OH_Drawing_AlphaFormat](_drawing.md#oh_drawing_alphaformat) | Defines an enum for alpha formats of bitmap pixels.| 
| typedef enum [OH_Drawing_BlendMode](_drawing.md#oh_drawing_blendmode)  [OH_Drawing_BlendMode](_drawing.md#oh_drawing_blendmode) | Defines an enum for blend modes. In blend mode, each operation generates a new color for the two colors (source color and target color). These operations are the same for the red, green, and blue color channels (the alpha channel follows a different rule).| 
| typedef struct [OH_Drawing_Image_Info](_o_h___drawing___image___info.md)  [OH_Drawing_Image_Info](_drawing.md#oh_drawing_image_info) | Defines a struct that describes the image information.| 
| typedef struct [OH_Drawing_RectStyle_Info](_o_h___drawing___rect_style___info.md)  [OH_Drawing_RectStyle_Info](_drawing.md#oh_drawing_rectstyle_info) | Defines a struct for the style of a rectangle.| 
| typedef enum [OH_Drawing_TextEncoding](_drawing.md#oh_drawing_textencoding)  [OH_Drawing_TextEncoding](_drawing.md#oh_drawing_textencoding) | Defines an enum for text encoding types.| 
| typedef struct [OH_Drawing_FontMgr](_drawing.md#oh_drawing_fontmgr)  [OH_Drawing_FontMgr](_drawing.md#oh_drawing_fontmgr) | Defines a struct for the font manager, which is used for font management.| 
| typedef struct [OH_Drawing_FontStyleSet](_drawing.md#oh_drawing_fontstyleset)  [OH_Drawing_FontStyleSet](_drawing.md#oh_drawing_fontstyleset) | Defines a struct for a font style set, which is used for font style family matching.| 
| typedef struct [OH_Drawing_RecordCmdUtils](_drawing.md#oh_drawing_recordcmdutils) [OH_Drawing_RecordCmdUtils](_drawing.md#oh_drawing_recordcmdutils) | Defines the recording command tool, which is used to generate recording commands.| 
| typedef struct [OH_Drawing_RecordCmd](_drawing.md#oh_drawing_recordcmd) [OH_Drawing_RecordCmd](_drawing.md#oh_drawing_recordcmd) | Defines the recording command class, which is used to store the set of recording commands.|

### Enums

| Name| Description| 
| -------- | -------- |
| [OH_Drawing_ColorFormat](_drawing.md#oh_drawing_colorformat) {<br>COLOR_FORMAT_UNKNOWN, COLOR_FORMAT_ALPHA_8, COLOR_FORMAT_RGB_565, COLOR_FORMAT_ARGB_4444,<br>COLOR_FORMAT_RGBA_8888, COLOR_FORMAT_BGRA_8888<br>} | Enumerates the storage formats of bitmap pixels.| 
| [OH_Drawing_AlphaFormat](_drawing.md#oh_drawing_alphaformat) { ALPHA_FORMAT_UNKNOWN, ALPHA_FORMAT_OPAQUE, ALPHA_FORMAT_PREMUL, ALPHA_FORMAT_UNPREMUL } | Enumerates the alpha formats of bitmap pixels.| 
| [OH_Drawing_BlendMode](_drawing.md#oh_drawing_blendmode) {<br>BLEND_MODE_CLEAR, BLEND_MODE_SRC, BLEND_MODE_DST, BLEND_MODE_SRC_OVER,<br>BLEND_MODE_DST_OVER, BLEND_MODE_SRC_IN, BLEND_MODE_DST_IN, BLEND_MODE_SRC_OUT,<br>BLEND_MODE_DST_OUT, BLEND_MODE_SRC_ATOP, BLEND_MODE_DST_ATOP, BLEND_MODE_XOR,<br>BLEND_MODE_PLUS, BLEND_MODE_MODULATE, BLEND_MODE_SCREEN, BLEND_MODE_OVERLAY,<br>BLEND_MODE_DARKEN, BLEND_MODE_LIGHTEN, BLEND_MODE_COLOR_DODGE, BLEND_MODE_COLOR_BURN,<br>BLEND_MODE_HARD_LIGHT, BLEND_MODE_SOFT_LIGHT, BLEND_MODE_DIFFERENCE, BLEND_MODE_EXCLUSION,<br>BLEND_MODE_MULTIPLY, BLEND_MODE_HUE, BLEND_MODE_SATURATION, BLEND_MODE_COLOR,<br>BLEND_MODE_LUMINOSITY<br>} | Enumerates the blend modes. In blend mode, each operation generates a new color for the two colors (source color and target color). These operations are the same for the red, green, and blue color channels (the alpha channel follows a different rule).| 
| [OH_Drawing_TextEncoding](_drawing.md#oh_drawing_textencoding) { TEXT_ENCODING_UTF8, TEXT_ENCODING_UTF16, TEXT_ENCODING_UTF32, TEXT_ENCODING_GLYPH_ID } | Enumerates the text encoding types.| 
