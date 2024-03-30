# Drawing


## Overview

The **Drawing** module provides the functions for 2D graphics rendering, text drawing, and image display.

This module does not provide the pixel unit. The pixel unit to use is consistent with the application context environment. In the ArkUI development environment, the default pixel unit vp is used.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [drawing_bitmap.h](drawing__bitmap_8h.md) | Declares the functions related to the bitmap in the drawing module.| 
| [drawing_brush.h](drawing__brush_8h.md) | Declares the functions related to the brush in the drawing module.| 
| [drawing_canvas.h](drawing__canvas_8h.md) | Declares the functions related to the canvas in the drawing module.| 
| [drawing_color.h](drawing__color_8h.md) | Declares the functions related to the color in the drawing module.| 
| [drawing_color_filter.h](drawing__color__filter_8h.md) | Declares the functions related to the color filter in the drawing module.| 
| [drawing_filter.h](drawing__filter_8h.md) | Declares the functions related to the filter in the drawing module.| 
| [drawing_font.h](drawing__font_8h.md) | Declares the functions related to the font in the drawing module.| 
| [drawing_font_collection.h](drawing__font__collection_8h.md) | Declares the functions related to the font collection in the drawing module.| 
| [drawing_image.h](drawing__image_8h.md) | Declares the functions related to the image in the drawing module.| 
| [drawing_mask_filter.h](drawing__mask__filter_8h.md) | Declares the functions related to the mask filter in the drawing module.| 
| [drawing_matrix.h](drawing__matrix_8h.md) | Declares the functions related to the matrix in the drawing module.| 
| [drawing_memory_stream.h](drawing__memory__stream_8h.md) | Declares the functions related to the memory stream in the drawing module.| 
| [drawing_path.h](drawing__path_8h.md) | Declares the functions related to the path in the drawing module.| 
| [drawing_path_effect.h](drawing__path__effect_8h.md) | Declares the functions related to the bitmap in the drawing module.| 
| [drawing_pen.h](drawing__pen_8h.md) | Declares the functions related to the pen in the drawing module.| 
| [drawing_point.h](drawing__point_8h.md) | Declares the functions related to the coordinate point in the drawing module.| 
| [drawing_rect.h](drawing__rect_8h.md) | Declares the functions related to the rectangle in the drawing module.| 
| [drawing_register_font.h](drawing__register__font_8h.md) | Declares the functions related to the font manager in the drawing module.| 
| [drawing_round_rect.h](drawing__round__rect_8h.md) | Declares the functions related to the rounded rectangle in the drawing module.| 
| [drawing_sampling_options.h](drawing__sampling__options_8h.md) | Declares the functions related to the sampling options in the drawing module. It is used for image or texture sampling.| 
| [drawing_shader_effect.h](drawing__shader__effect_8h.md) | Declares the functions related to the shader effect in the drawing module.| 
| [drawing_text_blob.h](drawing__text__blob_8h.md) | Declares the functions related to the text blob in the drawing module.| 
| [drawing_text_declaration.h](drawing__text__declaration_8h.md) | Declares the structs related to text in 2D drawing.| 
| [drawing_text_typography.h](drawing__text__typography_8h.md) | Declares the functions related to typography in the drawing module.| 
| [drawing_typeface.h](drawing__typeface_8h.md) | Declares the functions related to the typeface in the drawing module. Different platforms have their own default typefaces. You can also parse the .ttf file to obtain the typefaces specified by the third party, such as SimSun and SimHei.| 
| [drawing_types.h](drawing__types_8h.md) | Declares the data types of the canvas, brush, pen, bitmap, and path used to draw 2D graphics.| 


### Structs

| Name| Description| 
| -------- | -------- |
| struct  [OH_Drawing_BitmapFormat](_o_h___drawing___bitmap_format.md) | Describes the pixel format of a bitmap, including the color type and alpha type.| 
| struct  [OH_Drawing_Font_Metrics](_o_h___drawing___font___metrics.md) | Describes the measurement information about a font.| 
| struct  [OH_Drawing_RunBuffer](_o_h___drawing___run_buffer.md) | Describes a run, which provides storage for glyphs and positions.| 
| struct  [OH_Drawing_PlaceholderSpan](_o_h___drawing___placeholder_span.md) | Describes a placeholder that acts as a span.| 
| struct  [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) | Describes the detailed information about a system font.| 
| struct  [OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md) | Describes the measurement information about a line of text.| 
| struct  [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) | Describes a two-dimensional coordinate point.| 
| struct  [OH_Drawing_Point3D](_o_h___drawing___point3_d.md) | Describes a three-dimensional coordinate point.| 
| struct  [OH_Drawing_Image_Info](_o_h___drawing___image___info.md) | Describes the image information.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_Drawing_BitmapFormat](_o_h___drawing___bitmap_format.md)  [OH_Drawing_BitmapFormat](#oh_drawing_bitmapformat) | Defines a struct that describes the pixel format of a bitmap, including the color type and alpha type.| 
| typedef enum [OH_Drawing_CanvasClipOp](#oh_drawing_canvasclipop)  [OH_Drawing_CanvasClipOp](#oh_drawing_canvasclipop) | Defines an enum for canvas clipping modes.| 
| typedef enum [OH_Drawing_CanvasShadowFlags](#oh_drawing_canvasshadowflags)[OH_Drawing_CanvasShadowFlags](#oh_drawing_canvasshadowflags) | Defines an enum for shadow flags.| 
| typedef struct [OH_Drawing_Font_Metrics](_o_h___drawing___font___metrics.md)  [OH_Drawing_Font_Metrics](#oh_drawing_font_metrics) | Defines a struct that describes the measurement information about a font.| 
| typedef enum [OH_Drawing_BlurType](#oh_drawing_blurtype)  [OH_Drawing_BlurType](#oh_drawing_blurtype) | Defines an enum for blur types.| 
| typedef enum [OH_Drawing_PathDirection](#oh_drawing_pathdirection)  [OH_Drawing_PathDirection](#oh_drawing_pathdirection) | Defines an enum for directions of a closed contour.| 
| typedef enum [OH_Drawing_PathFillType](#oh_drawing_pathfilltype)  [OH_Drawing_PathFillType](#oh_drawing_pathfilltype) | Defines an enum for fill types of a path.| 
| typedef enum [OH_Drawing_PenLineCapStyle](#oh_drawing_penlinecapstyle)  [OH_Drawing_PenLineCapStyle](#oh_drawing_penlinecapstyle) | Defines an enum for line cap styles of a pen. The line cap style defines the style of both ends of a line segment drawn by the pen.| 
| typedef enum [OH_Drawing_PenLineJoinStyle](#oh_drawing_penlinejoinstyle)  [OH_Drawing_PenLineJoinStyle](#oh_drawing_penlinejoinstyle) | Defines an enum for line join styles of a pen. The line join style defines the shape of the joints of a polyline segment drawn by the pen.| 
| typedef enum [OH_Drawing_FilterMode](#oh_drawing_filtermode)  [OH_Drawing_FilterMode](#oh_drawing_filtermode) | Defines an enum for filter modes.| 
| typedef enum [OH_Drawing_MipmapMode](#oh_drawing_mipmapmode)  [OH_Drawing_MipmapMode](#oh_drawing_mipmapmode) | Defines an enum for mipmap modes.| 
| typedef enum [OH_Drawing_TileMode](#oh_drawing_tilemode)  [OH_Drawing_TileMode](#oh_drawing_tilemode) | Defines an enum for tile modes of the shader effect.| 
| typedef struct [OH_Drawing_RunBuffer](_o_h___drawing___run_buffer.md)  [OH_Drawing_RunBuffer](#oh_drawing_runbuffer) | Defines a struct that describes a run, which provides storage for glyphs and positions.| 
| typedef struct [OH_Drawing_FontCollection](#oh_drawing_fontcollection)  [OH_Drawing_FontCollection](#oh_drawing_fontcollection) | Defines a struct used to load fonts.| 
| typedef struct [OH_Drawing_Typography](#oh_drawing_typography)  [OH_Drawing_Typography](#oh_drawing_typography) | Defines a struct used to manage the typography layout and display.| 
| typedef struct [OH_Drawing_TextStyle](#oh_drawing_textstyle)  [OH_Drawing_TextStyle](#oh_drawing_textstyle) | Defines a struct used to manage text colors and decorations.| 
| typedef struct [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)  [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) | Defines a struct used to manage the typography style, such as the text direction.| 
| typedef struct [OH_Drawing_TypographyCreate](#oh_drawing_typographycreate)  [OH_Drawing_TypographyCreate](#oh_drawing_typographycreate) | Defines a struct used to create an [OH_Drawing_Typography](#oh_drawing_typography) object.| 
| typedef struct [OH_Drawing_TextBox](#oh_drawing_textbox)  [OH_Drawing_TextBox](#oh_drawing_textbox) | Defines a struct used to receive the rectangle size, direction, and quantity of text boxes.| 
| typedef struct [OH_Drawing_PositionAndAffinity](#oh_drawing_positionandaffinity)  [OH_Drawing_PositionAndAffinity](#oh_drawing_positionandaffinity) | Defines a struct used to receive the position and affinity of a font.| 
| typedef struct [OH_Drawing_Range](#oh_drawing_range)  [OH_Drawing_Range](#oh_drawing_range) | Defines a struct used to receive the start position and end position of a font.| 
| typedef struct [OH_Drawing_TextShadow](#oh_drawing_textshadow)  [OH_Drawing_TextShadow](#oh_drawing_textshadow) | Defines a struct used to manage text shadows.| 
| typedef struct [OH_Drawing_FontParser](#oh_drawing_fontparser)  [OH_Drawing_FontParser](#oh_drawing_fontparser) | Defines a struct used to parse system font files.| 
| typedef enum [OH_Drawing_PlaceholderVerticalAlignment](#oh_drawing_placeholderverticalalignment)  [OH_Drawing_PlaceholderVerticalAlignment](#oh_drawing_placeholderverticalalignment) | Defines an enum for vertical alignment modes of placeholders.| 
| typedef struct [OH_Drawing_PlaceholderSpan](_o_h___drawing___placeholder_span.md)  [OH_Drawing_PlaceholderSpan](#oh_drawing_placeholderspan) | Defines a struct that describes a placeholder, which acts as a span.| 
| typedef enum [OH_Drawing_TextDecorationStyle](#oh_drawing_textdecorationstyle)  [OH_Drawing_TextDecorationStyle](#oh_drawing_textdecorationstyle) | Defines an enum for text decoration styles.| 
| typedef enum [OH_Drawing_EllipsisModal](#oh_drawing_ellipsismodal)  [OH_Drawing_EllipsisModal](#oh_drawing_ellipsismodal) | Defines an enum for ellipsis styles.| 
| typedef enum [OH_Drawing_BreakStrategy](#oh_drawing_breakstrategy)  [OH_Drawing_BreakStrategy](#oh_drawing_breakstrategy) | Defines an enum for text break strategies.| 
| typedef enum [OH_Drawing_WordBreakType](#oh_drawing_wordbreaktype)  [OH_Drawing_WordBreakType](#oh_drawing_wordbreaktype) | Defines an enum for word break types.| 
| typedef enum [OH_Drawing_RectHeightStyle](#oh_drawing_rectheightstyle)  [OH_Drawing_RectHeightStyle](#oh_drawing_rectheightstyle) | Defines an enum for rectangle height styles.| 
| typedef enum [OH_Drawing_RectWidthStyle](#oh_drawing_rectwidthstyle)  [OH_Drawing_RectWidthStyle](#oh_drawing_rectwidthstyle) | Defines an enum for rectangle width styles.| 
| typedef struct [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md)  [OH_Drawing_FontDescriptor](#oh_drawing_fontdescriptor) | Defines a struct that describes the detailed information about a system font.| 
| typedef struct [OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md)  [OH_Drawing_LineMetrics](#oh_drawing_linemetrics) | Defines a struct that describes the measurement information about a line of text.| 
| typedef struct [OH_Drawing_Canvas](#oh_drawing_canvas)  [OH_Drawing_Canvas](#oh_drawing_canvas) | Defines a struct for a rectangular canvas, on which various shapes, images, and texts can be drawn by using the brush and pen.| 
| typedef struct [OH_Drawing_Pen](#oh_drawing_pen)  [OH_Drawing_Pen](#oh_drawing_pen) | Defines a struct for a pen, which is used to describe the style and color to outline a shape.| 
| typedef struct [OH_Drawing_Brush](#oh_drawing_brush)  [OH_Drawing_Brush](#oh_drawing_brush) | Defines a struct for a brush, which is used to describe the style and color to fill in a shape.| 
| typedef struct [OH_Drawing_Path](#oh_drawing_path)  [OH_Drawing_Path](#oh_drawing_path) | Defines a struct for a path, which is used to customize various shapes.| 
| typedef struct [OH_Drawing_Bitmap](#oh_drawing_bitmap)  [OH_Drawing_Bitmap](#oh_drawing_bitmap) | Defines a struct for a bitmap, which is a memory area that contains the pixel data of a shape.| 
| typedef struct [OH_Drawing_Point](#oh_drawing_point)  [OH_Drawing_Point](#oh_drawing_point) | Defines a struct for a coordinate point.| 
| typedef struct [OH_Drawing_Point2D](_o_h___drawing___point2_d.md)  [OH_Drawing_Point2D](#oh_drawing_point2d) | Defines a struct for a two-dimensional coordinate point.| 
| typedef struct [OH_Drawing_Point3D](_o_h___drawing___point3_d.md)  [OH_Drawing_Point3D](#oh_drawing_point3d) | Defines a struct for a three-dimensional coordinate point.| 
| typedef struct [OH_Drawing_PathEffect](#oh_drawing_patheffect)  [OH_Drawing_PathEffect](#oh_drawing_patheffect) | Defines a struct for a path effect that affects the stroke.| 
| typedef struct [OH_Drawing_Rect](#oh_drawing_rect)  [OH_Drawing_Rect](#oh_drawing_rect) | Defines a struct for a rectangle.| 
| typedef struct [OH_Drawing_RoundRect](#oh_drawing_roundrect)  [OH_Drawing_RoundRect](#oh_drawing_roundrect) | Defines a struct for a rounded rectangle.| 
| typedef struct [OH_Drawing_Matrix](#oh_drawing_matrix)  [OH_Drawing_Matrix](#oh_drawing_matrix) | Defines a struct for a matrix, which is used to describe coordinate transformation.| 
| typedef struct [OH_Drawing_ShaderEffect](#oh_drawing_shadereffect)  [OH_Drawing_ShaderEffect](#oh_drawing_shadereffect) | Defines a struct for a shader effect, which is used to describe the source color of the drawn content.| 
| typedef struct [OH_Drawing_Filter](#oh_drawing_filter)  [OH_Drawing_Filter](#oh_drawing_filter) | Defines a struct for a filter, which consists of a color filter and mask filter.| 
| typedef struct [OH_Drawing_MaskFilter](#oh_drawing_maskfilter)  [OH_Drawing_MaskFilter](#oh_drawing_maskfilter) | Defines a struct for a mask filter, which is used to convert a mask into a new one.| 
| typedef struct [OH_Drawing_ColorFilter](#oh_drawing_colorfilter)  [OH_Drawing_ColorFilter](#oh_drawing_colorfilter) | Defines a struct for a color filter, which is used to convert a color into a new one.| 
| typedef struct [OH_Drawing_Font](#oh_drawing_font)  [OH_Drawing_Font](#oh_drawing_font) | Defines a struct for a font.| 
| typedef struct [OH_Drawing_MemoryStream](#oh_drawing_memorystream)  [OH_Drawing_MemoryStream](#oh_drawing_memorystream) | Defines a struct for a memory stream.| 
| typedef struct [OH_Drawing_Typeface](#oh_drawing_typeface)  [OH_Drawing_Typeface](#oh_drawing_typeface) | Defines a struct for a typeface.| 
| typedef struct [OH_Drawing_TextBlob](#oh_drawing_textblob)  [OH_Drawing_TextBlob](#oh_drawing_textblob) | Defines a struct for a text blob, an immutable container that holds multiple texts. Each text blob consists of glyphs and position.| 
| typedef struct [OH_Drawing_Image](#oh_drawing_image)  [OH_Drawing_Image](#oh_drawing_image) | Defines a struct for an image that describes a two-dimensional pixel array.| 
| typedef struct [OH_Drawing_SamplingOptions](#oh_drawing_samplingoptions)  [OH_Drawing_SamplingOptions](#oh_drawing_samplingoptions) | Defines a struct for sampling options, which describe the sampling methods for images and bitmaps.| 
| typedef struct [OH_Drawing_TextBlobBuilder](#oh_drawing_textblobbuilder)  [OH_Drawing_TextBlobBuilder](#oh_drawing_textblobbuilder) | Defines a struct for a text blob builder, which is used to build a text blob.| 
| typedef enum [OH_Drawing_ColorFormat](#oh_drawing_colorformat)  [OH_Drawing_ColorFormat](#oh_drawing_colorformat) | Defines an enum for storage formats of bitmap pixels.| 
| typedef enum [OH_Drawing_AlphaFormat](#oh_drawing_alphaformat)  [OH_Drawing_AlphaFormat](#oh_drawing_alphaformat) | Defines an enum for alpha formats of bitmap pixels.| 
| typedef enum [OH_Drawing_BlendMode](#oh_drawing_blendmode)  [OH_Drawing_BlendMode](#oh_drawing_blendmode) | Defines an enum for blend modes. In blend mode, each operation generates a new color from two colors (source color and target color). These operations are the same on the four channels (red, green, blue, and alpha). The operations for the alpha channel are used as examples.| 
| typedef struct [OH_Drawing_Image_Info](_o_h___drawing___image___info.md)  [OH_Drawing_Image_Info](#oh_drawing_image_info) | Defines a struct that describes the image information.| 
| typedef enum [OH_Drawing_TextEncoding](#oh_drawing_textencoding)  [OH_Drawing_TextEncoding](#oh_drawing_textencoding) | Defines an enum for text encoding types.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [OH_Drawing_CanvasClipOp](#oh_drawing_canvasclipop) { DIFFERENCE, INTERSECT } | Enumerates the canvas clipping modes.| 
| [OH_Drawing_CanvasShadowFlags](#oh_drawing_canvasshadowflags) { SHADOW_FLAGS_NONE, SHADOW_FLAGS_TRANSPARENT_OCCLUDER, SHADOW_FLAGS_GEOMETRIC_ONLY, SHADOW_FLAGS_ALL } | Enumerates the canvas shadow flags.| 
| [OH_Drawing_BlurType](#oh_drawing_blurtype) { NORMAL, SOLID, OUTER, INNER } | Enumerates the blur types.| 
| [OH_Drawing_PathDirection](#oh_drawing_pathdirection) { PATH_DIRECTION_CW, PATH_DIRECTION_CCW } | Enumerates the directions of a closed contour.| 
| [OH_Drawing_PathFillType](#oh_drawing_pathfilltype) { PATH_FILL_TYPE_WINDING, PATH_FILL_TYPE_EVEN_ODD, PATH_FILL_TYPE_INVERSE_WINDING, PATH_FILL_TYPE_INVERSE_EVEN_ODD } | Enumerates the fill types of a path.| 
| [OH_Drawing_PenLineCapStyle](#oh_drawing_penlinecapstyle) { LINE_FLAT_CAP, LINE_SQUARE_CAP, LINE_ROUND_CAP } | Enumerates the line cap styles of a pen. The line cap style defines the style of both ends of a line segment drawn by the pen.| 
| [OH_Drawing_PenLineJoinStyle](#oh_drawing_penlinejoinstyle) { LINE_MITER_JOIN, LINE_ROUND_JOIN, LINE_BEVEL_JOIN } | Enumerates the line join styles of a pen. The line join style defines the shape of the joints of a polyline segment drawn by the pen.| 
| [OH_Drawing_FilterMode](#oh_drawing_filtermode) { FILTER_MODE_NEAREST, FILTER_MODE_LINEAR } | Enumerates the filter modes.| 
| [OH_Drawing_MipmapMode](#oh_drawing_mipmapmode) { MIPMAP_MODE_NONE, MIPMAP_MODE_NEAREST, MIPMAP_MODE_LINEAR } | Enumerates the mipmap modes.| 
| [OH_Drawing_TileMode](#oh_drawing_tilemode) { CLAMP, REPEAT, MIRROR, DECAL } | Enumerates the tile modes of the shader effect.| 
| [OH_Drawing_TextDirection](#oh_drawing_textdirection) { TEXT_DIRECTION_RTL, TEXT_DIRECTION_LTR } | Enumerates the text directions.| 
| [OH_Drawing_TextAlign](#oh_drawing_textalign) {<br>TEXT_ALIGN_LEFT, TEXT_ALIGN_RIGHT, TEXT_ALIGN_CENTER, TEXT_ALIGN_JUSTIFY,<br>TEXT_ALIGN_START, TEXT_ALIGN_END<br>} | Enumerates the text alignment modes.| 
| [OH_Drawing_FontWeight](#oh_drawing_fontweight) {<br>FONT_WEIGHT_100, FONT_WEIGHT_200, FONT_WEIGHT_300, FONT_WEIGHT_400,<br>FONT_WEIGHT_500, FONT_WEIGHT_600, FONT_WEIGHT_700, FONT_WEIGHT_800,<br>FONT_WEIGHT_900<br>} | Enumerates the font weights.| 
| [OH_Drawing_TextBaseline](#oh_drawing_textbaseline) { TEXT_BASELINE_ALPHABETIC, TEXT_BASELINE_IDEOGRAPHIC } | Enumerates the text baselines.| 
| [OH_Drawing_TextDecoration](#oh_drawing_textdecoration) { TEXT_DECORATION_NONE = 0x0, TEXT_DECORATION_UNDERLINE = 0x1, TEXT_DECORATION_OVERLINE = 0x2, TEXT_DECORATION_LINE_THROUGH = 0x4 } | Enumerates the text decorations.| 
| [OH_Drawing_FontStyle](#oh_drawing_fontstyle) { FONT_STYLE_NORMAL, FONT_STYLE_ITALIC } | Enumerates the font styles.| 
| [OH_Drawing_PlaceholderVerticalAlignment](#oh_drawing_placeholderverticalalignment) {<br>ALIGNMENT_OFFSET_AT_BASELINE, ALIGNMENT_ABOVE_BASELINE, ALIGNMENT_BELOW_BASELINE, ALIGNMENT_TOP_OF_ROW_BOX,<br>ALIGNMENT_BOTTOM_OF_ROW_BOX, ALIGNMENT_CENTER_OF_ROW_BOX<br>} | Enumerates the vertical alignment modes of placeholders.| 
| [OH_Drawing_TextDecorationStyle](#oh_drawing_textdecorationstyle) {<br>TEXT_DECORATION_STYLE_SOLID, TEXT_DECORATION_STYLE_DOUBLE, TEXT_DECORATION_STYLE_DOTTED, TEXT_DECORATION_STYLE_DASHED,<br>TEXT_DECORATION_STYLE_WAVY<br>} | Enumerates the text decoration styles.| 
| [OH_Drawing_EllipsisModal](#oh_drawing_ellipsismodal) { ELLIPSIS_MODAL_HEAD = 0, ELLIPSIS_MODAL_MIDDLE = 1, ELLIPSIS_MODAL_TAIL = 2 } | Enumerates the ellipsis styles.| 
| [OH_Drawing_BreakStrategy](#oh_drawing_breakstrategy) { BREAK_STRATEGY_GREEDY = 0, BREAK_STRATEGY_HIGH_QUALITY = 1, BREAK_STRATEGY_BALANCED = 2 } | Enumerates the text break strategies.| 
| [OH_Drawing_WordBreakType](#oh_drawing_wordbreaktype) { WORD_BREAK_TYPE_NORMAL = 0, WORD_BREAK_TYPE_BREAK_ALL = 1, WORD_BREAK_TYPE_BREAK_WORD = 2 } | Enumerates the word break types.| 
| [OH_Drawing_RectHeightStyle](#oh_drawing_rectheightstyle) {<br>RECT_HEIGHT_STYLE_TIGHT, RECT_HEIGHT_STYLE_MAX, RECT_HEIGHT_STYLE_INCLUDELINESPACEMIDDLE, RECT_HEIGHT_STYLE_INCLUDELINESPACETOP,<br>RECT_HEIGHT_STYLE_INCLUDELINESPACEBOTTOM, RECT_HEIGHT_STYLE_STRUCT<br>} | Enumerates the rectangle height styles.| 
| [OH_Drawing_RectWidthStyle](#oh_drawing_rectwidthstyle) { RECT_WIDTH_STYLE_TIGHT, RECT_WIDTH_STYLE_MAX } | Enumerates the rectangle width styles.| 
| [OH_Drawing_ColorFormat](#oh_drawing_colorformat) {<br>COLOR_FORMAT_UNKNOWN, COLOR_FORMAT_ALPHA_8, COLOR_FORMAT_RGB_565, COLOR_FORMAT_ARGB_4444,<br>COLOR_FORMAT_RGBA_8888, COLOR_FORMAT_BGRA_8888<br>} | Enumerates the storage formats of bitmap pixels.| 
| [OH_Drawing_AlphaFormat](#oh_drawing_alphaformat) { ALPHA_FORMAT_UNKNOWN, ALPHA_FORMAT_OPAQUE, ALPHA_FORMAT_PREMUL, ALPHA_FORMAT_UNPREMUL } | Enumerates the alpha formats of bitmap pixels.| 
| [OH_Drawing_BlendMode](#oh_drawing_blendmode) {<br>BLEND_MODE_CLEAR, BLEND_MODE_SRC, BLEND_MODE_DST, BLEND_MODE_SRC_OVER,<br>BLEND_MODE_DST_OVER, BLEND_MODE_SRC_IN, BLEND_MODE_DST_IN, BLEND_MODE_SRC_OUT,<br>BLEND_MODE_DST_OUT, BLEND_MODE_SRC_ATOP, BLEND_MODE_DST_ATOP, BLEND_MODE_XOR,<br>BLEND_MODE_PLUS, BLEND_MODE_MODULATE, BLEND_MODE_SCREEN, BLEND_MODE_OVERLAY,<br>BLEND_MODE_DARKEN, BLEND_MODE_LIGHTEN, BLEND_MODE_COLOR_DODGE, BLEND_MODE_COLOR_BURN,<br>BLEND_MODE_HARD_LIGHT, BLEND_MODE_SOFT_LIGHT, BLEND_MODE_DIFFERENCE, BLEND_MODE_EXCLUSION,<br>BLEND_MODE_MULTIPLY, BLEND_MODE_HUE, BLEND_MODE_SATURATION, BLEND_MODE_COLOR,<br>BLEND_MODE_LUMINOSITY<br>} | Enumerates the blend modes. In blend mode, each operation generates a new color from two colors (source color and target color). These operations are the same on the four channels (red, green, blue, and alpha). The operations for the alpha channel are used as examples.| 
| [OH_Drawing_TextEncoding](#oh_drawing_textencoding) { TEXT_ENCODING_UTF8, TEXT_ENCODING_UTF16, TEXT_ENCODING_UTF32, TEXT_ENCODING_GLYPH_ID } | Enumerates the text encoding types.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_Drawing_Bitmap](#oh_drawing_bitmap) \* [OH_Drawing_BitmapCreate](#oh_drawing_bitmapcreate) (void) | Creates an **OH_Drawing_Bitmap** object.| 
| void [OH_Drawing_BitmapDestroy](#oh_drawing_bitmapdestroy) ([OH_Drawing_Bitmap](#oh_drawing_bitmap) \*) | Destroys an **OH_Drawing_Bitmap** object and reclaims the memory occupied by the object.| 
| [OH_Drawing_Bitmap](#oh_drawing_bitmap) \* [OH_Drawing_BitmapCreateFromPixels](#oh_drawing_bitmapcreatefrompixels) ([OH_Drawing_Image_Info](_o_h___drawing___image___info.md) \*, void \*pixels, uint32_t rowBytes) | Creates an **OH_Drawing_Bitmap** object, with the address of the memory for storing the bitmap pixels set to the memory address that you applied for.| 
| void [OH_Drawing_BitmapBuild](#oh_drawing_bitmapbuild) ([OH_Drawing_Bitmap](#oh_drawing_bitmap) \*, const uint32_t width, const uint32_t height, const [OH_Drawing_BitmapFormat](_o_h___drawing___bitmap_format.md) \*) | Initializes the width and height of a bitmap and sets the pixel format for the bitmap.| 
| uint32_t [OH_Drawing_BitmapGetWidth](#oh_drawing_bitmapgetwidth) ([OH_Drawing_Bitmap](#oh_drawing_bitmap) \*) | Obtains the width of a bitmap.| 
| uint32_t [OH_Drawing_BitmapGetHeight](#oh_drawing_bitmapgetheight) ([OH_Drawing_Bitmap](#oh_drawing_bitmap) \*) | Obtains the height of a bitmap.| 
| void \* [OH_Drawing_BitmapGetPixels](#oh_drawing_bitmapgetpixels) ([OH_Drawing_Bitmap](#oh_drawing_bitmap) \*) | Obtains the pixel address of a bitmap. You can use this address to obtain the pixel data of the bitmap.| 
| [OH_Drawing_Brush](#oh_drawing_brush) \* [OH_Drawing_BrushCreate](#oh_drawing_brushcreate) (void) | Creates an **OH_Drawing_Brush** object.| 
| void [OH_Drawing_BrushDestroy](#oh_drawing_brushdestroy) ([OH_Drawing_Brush](#oh_drawing_brush) \*) | Destroys an **OH_Drawing_Brush** object and reclaims the memory occupied by the object.| 
| bool [OH_Drawing_BrushIsAntiAlias](#oh_drawing_brushisantialias) (const [OH_Drawing_Brush](#oh_drawing_brush) \*) | Checks whether anti-aliasing is enabled for a brush. Anti-aliasing makes the pixels around the shape edges semi-transparent.| 
| void [OH_Drawing_BrushSetAntiAlias](#oh_drawing_brushsetantialias) ([OH_Drawing_Brush](#oh_drawing_brush) \*, bool) | Enables or disables anti-aliasing for a brush. Anti-aliasing makes the pixels around the shape edges semi-transparent.| 
| uint32_t [OH_Drawing_BrushGetColor](#oh_drawing_brushgetcolor) (const [OH_Drawing_Brush](#oh_drawing_brush) \*) | Obtains the color of a brush. The color is used by the brush to fill in a shape.| 
| void [OH_Drawing_BrushSetColor](#oh_drawing_brushsetcolor) ([OH_Drawing_Brush](#oh_drawing_brush) \*, uint32_t color) | Sets the color for a brush. The color is used by the brush to fill in a shape.| 
| uint8_t [OH_Drawing_BrushGetAlpha](#oh_drawing_brushgetalpha) (const [OH_Drawing_Brush](#oh_drawing_brush) \*) | Obtains the alpha value of a brush. This value is used by the alpha channel when the brush fills in a shape.| 
| void [OH_Drawing_BrushSetAlpha](#oh_drawing_brushsetalpha) ([OH_Drawing_Brush](#oh_drawing_brush) \*, uint8_t alpha) | Sets the alpha value for a brush. This value is used by the alpha channel when the brush fills in a shape.| 
| void [OH_Drawing_BrushSetShaderEffect](#oh_drawing_brushsetshadereffect) ([OH_Drawing_Brush](#oh_drawing_brush) \*, [OH_Drawing_ShaderEffect](#oh_drawing_shadereffect) \*) | Sets the shader effect for a brush.| 
| void [OH_Drawing_BrushSetFilter](#oh_drawing_brushsetfilter) ([OH_Drawing_Brush](#oh_drawing_brush) \*, [OH_Drawing_Filter](#oh_drawing_filter) \*) | Sets a filter for a brush. The filter is a container that holds a mask filter and color filter.| 
| void [OH_Drawing_BrushSetBlendMode](#oh_drawing_brushsetblendmode) ([OH_Drawing_Brush](#oh_drawing_brush) \*, [OH_Drawing_BlendMode](#oh_drawing_blendmode)) | Sets a blender for a brush. The blender implements the specified blend mode.| 
| [OH_Drawing_Canvas](#oh_drawing_canvas) \* [OH_Drawing_CanvasCreate](#oh_drawing_canvascreate) (void) | Creates an **OH_Drawing_Canvas** object.| 
| void [OH_Drawing_CanvasDestroy](#oh_drawing_canvasdestroy) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*) | Destroys an **OH_Drawing_Canvas** object and reclaims the memory occupied by the object.| 
| void [OH_Drawing_CanvasBind](#oh_drawing_canvasbind) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, [OH_Drawing_Bitmap](#oh_drawing_bitmap) \*) | Binds a bitmap to a canvas so that the content drawn on the canvas is output to the bitmap. (This process is called CPU rendering.)| 
| void [OH_Drawing_CanvasAttachPen](#oh_drawing_canvasattachpen) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Pen](#oh_drawing_pen) \*) | Attaches a pen to a canvas so that the canvas can use the style and color of the pen to outline a shape.| 
| void [OH_Drawing_CanvasDetachPen](#oh_drawing_canvasdetachpen) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*) | Detaches the pen from a canvas so that the canvas can no longer use the style and color of the pen to outline a shape.| 
| void [OH_Drawing_CanvasAttachBrush](#oh_drawing_canvasattachbrush) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Brush](#oh_drawing_brush) \*) | Attaches a brush to a canvas so that the canvas can use the style and color of the brush to fill in a shape.| 
| void [OH_Drawing_CanvasDetachBrush](#oh_drawing_canvasdetachbrush) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*) | Detaches the brush from a canvas so that the canvas can no longer use the style and color of the brush to fill in a shape.| 
| void [OH_Drawing_CanvasSave](#oh_drawing_canvassave) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*) | Saves the current canvas status (canvas matrix) to the top of the stack.| 
| void [OH_Drawing_CanvasSaveLayer](#oh_drawing_canvassavelayer) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Rect](#oh_drawing_rect) \*, const [OH_Drawing_Brush](#oh_drawing_brush) \*) | Saves the matrix and cropping region, and allocates a bitmap for subsequent drawing. If you call [OH_Drawing_CanvasRestore](#oh_drawing_canvasrestore), the changes made to the matrix and clipping region are discarded, and the bitmap is drawn.| 
| void [OH_Drawing_CanvasRestore](#oh_drawing_canvasrestore) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*) | Restores the canvas status (canvas matrix) saved on the top of the stack.| 
| uint32_t [OH_Drawing_CanvasGetSaveCount](#oh_drawing_canvasgetsavecount) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*) | Obtains the number of canvas statuses (canvas matrices) saved in the stack.| 
| void [OH_Drawing_CanvasRestoreToCount](#oh_drawing_canvasrestoretocount) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, uint32_t saveCount) | Restores to a given number of canvas statuses (canvas matrices).| 
| void [OH_Drawing_CanvasDrawLine](#oh_drawing_canvasdrawline) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, float x1, float y1, float x2, float y2) | Draws a line segment.| 
| void [OH_Drawing_CanvasDrawPath](#oh_drawing_canvasdrawpath) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Path](#oh_drawing_path) \*) | Draws a path.| 
| void [OH_Drawing_CanvasDrawBitmap](#oh_drawing_canvasdrawbitmap) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Bitmap](#oh_drawing_bitmap) \*, float left, float top) | Draws a bitmap. A bitmap, also referred to as a dot matrix image, a pixel map image, or a grid image, includes single points called pixels (image elements).| 
| void [OH_Drawing_CanvasDrawBitmapRect](#oh_drawing_canvasdrawbitmaprect) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Bitmap](#oh_drawing_bitmap) \*, const [OH_Drawing_Rect](#oh_drawing_rect) \*src, const [OH_Drawing_Rect](#oh_drawing_rect) \*dst, const [OH_Drawing_SamplingOptions](#oh_drawing_samplingoptions) \*) | Draws a portion of a bitmap onto a specified area of the canvas.| 
| void [OH_Drawing_CanvasSetMatrix](#oh_drawing_canvassetmatrix) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, [OH_Drawing_Matrix](#oh_drawing_matrix) \*) | Sets the matrix status for a canvas.| 
| void [OH_Drawing_CanvasDrawImageRect](#oh_drawing_canvasdrawimagerect) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, [OH_Drawing_Image](#oh_drawing_image) \*, [OH_Drawing_Rect](#oh_drawing_rect) \*dst, [OH_Drawing_SamplingOptions](#oh_drawing_samplingoptions) \*) | Draws an image onto a specified area of the canvas.| 
| bool [OH_Drawing_CanvasReadPixels](#oh_drawing_canvasreadpixels) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, [OH_Drawing_Image_Info](_o_h___drawing___image___info.md) \*, void \*dstPixels, uint32_t dstRowBytes, int32_t srcX, int32_t srcY) | Copies pixel data from a canvas to a specified address. This function cannot be used for recorded canvases.| 
| bool [OH_Drawing_CanvasReadPixelsToBitmap](#oh_drawing_canvasreadpixelstobitmap) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, [OH_Drawing_Bitmap](#oh_drawing_bitmap) \*, int32_t srcX, int32_t srcY) | Copies pixel data from a canvas to an image. This function cannot be used for recorded canvases.| 
| void [OH_Drawing_CanvasDrawRect](#oh_drawing_canvasdrawrect) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Rect](#oh_drawing_rect) \*) | Draws a rectangle.| 
| void [OH_Drawing_CanvasDrawCircle](#oh_drawing_canvasdrawcircle) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Point](#oh_drawing_point) \*, float radius) | Draws a circle.| 
| void [OH_Drawing_CanvasDrawOval](#oh_drawing_canvasdrawoval) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Rect](#oh_drawing_rect) \*) | Draws an oval.| 
| void [OH_Drawing_CanvasDrawArc](#oh_drawing_canvasdrawarc) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Rect](#oh_drawing_rect) \*, float startAngle, float sweepAngle) | Draws an arc.| 
| void [OH_Drawing_CanvasDrawRoundRect](#oh_drawing_canvasdrawroundrect) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_RoundRect](#oh_drawing_roundrect) \*) | Draws a rounded rectangle.| 
| void [OH_Drawing_CanvasDrawTextBlob](#oh_drawing_canvasdrawtextblob) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_TextBlob](#oh_drawing_textblob) \*, float x, float y) | Draws a text blob.| 
| uint32_t [OH_Drawing_ColorSetArgb](#oh_drawing_colorsetargb) (uint32_t alpha, uint32_t red, uint32_t green, uint32_t blue) | Converts four variables (alpha, red, green, and blue) into a 32-bit (ARGB) variable that describes a color.| 
| [OH_Drawing_ColorFilter](#oh_drawing_colorfilter) \* [OH_Drawing_ColorFilterCreateBlendMode](#oh_drawing_colorfiltercreateblendmode) (uint32_t color, [OH_Drawing_BlendMode](#oh_drawing_blendmode)) | Creates an **OH_Drawing_ColorFilter** object with a given blend mode.| 
| [OH_Drawing_ColorFilter](#oh_drawing_colorfilter) \* [OH_Drawing_ColorFilterCreateCompose](#oh_drawing_colorfiltercreatecompose) ([OH_Drawing_ColorFilter](#oh_drawing_colorfilter) \*colorFilter1, [OH_Drawing_ColorFilter](#oh_drawing_colorfilter) \*colorFilter2) | Creates an **OH_Drawing_ColorFilter** object by combining another two color filters.| 
| [OH_Drawing_ColorFilter](#oh_drawing_colorfilter) \* [OH_Drawing_ColorFilterCreateMatrix](#oh_drawing_colorfiltercreatematrix) (const float matrix[20]) | Creates an **OH_Drawing_ColorFilter** object with a given 5x4 color matrix.| 
| [OH_Drawing_ColorFilter](#oh_drawing_colorfilter) \* [OH_Drawing_ColorFilterCreateLinearToSrgbGamma](#oh_drawing_colorfiltercreatelineartosrgbgamma) (void) | Creates an **OH_Drawing_ColorFilter** object that applies the sRGB gamma curve to the RGB channels.| 
| [OH_Drawing_ColorFilter](#oh_drawing_colorfilter) \* [OH_Drawing_ColorFilterCreateSrgbGammaToLinear](#oh_drawing_colorfiltercreatesrgbgammatolinear) (void) | Creates an **OH_Drawing_ColorFilter** object that applies the RGB channels to the sRGB gamma curve.| 
| [OH_Drawing_ColorFilter](#oh_drawing_colorfilter) \* [OH_Drawing_ColorFilterCreateLuma](#oh_drawing_colorfiltercreateluma) (void) | Creates an **OH_Drawing_ColorFilter** object that multiplies the passed-in luma into the alpha channel and sets the RGB channels to zero.| 
| void [OH_Drawing_ColorFilterDestroy](#oh_drawing_colorfilterdestroy) ([OH_Drawing_ColorFilter](#oh_drawing_colorfilter) \*) | Destroys an **OH_Drawing_ColorFilter** object and reclaims the memory occupied by the object.| 
| [OH_Drawing_Filter](#oh_drawing_filter) \* [OH_Drawing_FilterCreate](#oh_drawing_filtercreate) (void) | Creates an **OH_Drawing_Filter** object.| 
| void [OH_Drawing_FilterSetMaskFilter](#oh_drawing_filtersetmaskfilter) ([OH_Drawing_Filter](#oh_drawing_filter) \*, [OH_Drawing_MaskFilter](#oh_drawing_maskfilter) \*) | Sets an **OH_Drawing_MaskFilter** object for an **OH_Drawing_Filter** object.| 
| void [OH_Drawing_FilterSetColorFilter](#oh_drawing_filtersetcolorfilter) ([OH_Drawing_Filter](#oh_drawing_filter) \*, [OH_Drawing_ColorFilter](#oh_drawing_colorfilter) \*) | Sets an **OH_Drawing_ColorFilter** object for an **OH_Drawing_Filter** object.| 
| void [OH_Drawing_FilterDestroy](#oh_drawing_filterdestroy) ([OH_Drawing_Filter](#oh_drawing_filter) \*) | Destroys an **OH_Drawing_Filter** object and reclaims the memory occupied by the object.| 
| [OH_Drawing_Font](#oh_drawing_font) \* [OH_Drawing_FontCreate](#oh_drawing_fontcreate) (void) | Creates an **OH_Drawing_Font** object.| 
| void [OH_Drawing_FontSetTypeface](#oh_drawing_fontsettypeface) ([OH_Drawing_Font](#oh_drawing_font) \*, [OH_Drawing_Typeface](#oh_drawing_typeface) \*) | Sets the typeface for a font.| 
| [OH_Drawing_Typeface](#oh_drawing_typeface) \* [OH_Drawing_FontGetTypeface](#oh_drawing_fontgettypeface) ([OH_Drawing_Font](#oh_drawing_font) \*) | Obtains the typeface of a font.| 
| void [OH_Drawing_FontSetTextSize](#oh_drawing_fontsettextsize) ([OH_Drawing_Font](#oh_drawing_font) \*, float textSize) | Sets the font size.| 
| int [OH_Drawing_FontCountText](#oh_drawing_fontcounttext) ([OH_Drawing_Font](#oh_drawing_font) \*, const void \*text, size_t byteLength, [OH_Drawing_TextEncoding](#oh_drawing_textencoding) encoding) | Obtains the number of glyphs represented by text.| 
| void [OH_Drawing_FontSetLinearText](#oh_drawing_fontsetlineartext) ([OH_Drawing_Font](#oh_drawing_font) \*, bool isLinearText) | Sets linear scaling for a font.| 
| void [OH_Drawing_FontSetTextSkewX](#oh_drawing_fontsettextskewx) ([OH_Drawing_Font](#oh_drawing_font) \*, float skewX) | Sets a horizontal skew factor for a font.| 
| void [OH_Drawing_FontSetFakeBoldText](#oh_drawing_fontsetfakeboldtext) ([OH_Drawing_Font](#oh_drawing_font) \*, bool isFakeBoldText) | Sets fake bold for a font by increasing the stroke width.| 
| void [OH_Drawing_FontDestroy](#oh_drawing_fontdestroy) ([OH_Drawing_Font](#oh_drawing_font) \*) | Destroys an **OH_Drawing_Font** object and reclaims the memory occupied by the object.| 
| float [OH_Drawing_FontGetMetrics](#oh_drawing_fontgetmetrics) ([OH_Drawing_Font](#oh_drawing_font) \*, [OH_Drawing_Font_Metrics](_o_h___drawing___font___metrics.md) \*) | Obtains the measurement information about a font.| 
| [OH_Drawing_FontCollection](#oh_drawing_fontcollection) \* [OH_Drawing_CreateFontCollection](#oh_drawing_createfontcollection) (void) | Creates an [OH_Drawing_FontCollection](#oh_drawing_fontcollection) object.| 
| void [OH_Drawing_DestroyFontCollection](#oh_drawing_destroyfontcollection) ([OH_Drawing_FontCollection](#oh_drawing_fontcollection) \*) | Destroys an **OH_Drawing_FontCollection** object and reclaims the memory occupied by the object.| 
| void [OH_Drawing_DisableFontCollectionFallback](#oh_drawing_disablefontcollectionfallback) ([OH_Drawing_FontCollection](#oh_drawing_fontcollection) \*fontCollection) | Disables the alternate fonts.| 
| void [OH_Drawing_DisableFontCollectionSystemFont](#oh_drawing_disablefontcollectionsystemfont) ([OH_Drawing_FontCollection](#oh_drawing_fontcollection) \*fontCollection) | Disables the system fonts.| 
| [OH_Drawing_Image](#oh_drawing_image) \* [OH_Drawing_ImageCreate](#oh_drawing_imagecreate) (void) | Creates an **OH_Drawing_Image** object that describes an array of two-dimensional pixels to draw.| 
| void [OH_Drawing_ImageDestroy](#oh_drawing_imagedestroy) ([OH_Drawing_Image](#oh_drawing_image) \*) | Destroys an **OH_Drawing_Image** object and reclaims the memory occupied by the object.| 
| bool [OH_Drawing_ImageBuildFromBitmap](#oh_drawing_imagebuildfrombitmap) ([OH_Drawing_Image](#oh_drawing_image) \*, [OH_Drawing_Bitmap](#oh_drawing_bitmap) \*) | Builds an image from a bitmap by sharing or copying bitmap pixels. If the bitmap is marked as immutable, the pixel memory is shared, not copied.| 
| int32_t [OH_Drawing_ImageGetWidth](#oh_drawing_imagegetwidth) ([OH_Drawing_Image](#oh_drawing_image) \*) | Obtains the image width, that is, the number of pixels in each line.| 
| int32_t [OH_Drawing_ImageGetHeight](#oh_drawing_imagegetheight) ([OH_Drawing_Image](#oh_drawing_image) \*) | Obtains the image height, that is, the number of pixel lines.| 
| void [OH_Drawing_ImageGetImageInfo](#oh_drawing_imagegetimageinfo) ([OH_Drawing_Image](#oh_drawing_image) \*, [OH_Drawing_Image_Info](_o_h___drawing___image___info.md) \*) | Obtains the image information. After this function is called, the passed-in image information object is filled.| 
| [OH_Drawing_MaskFilter](#oh_drawing_maskfilter) \* [OH_Drawing_MaskFilterCreateBlur](#oh_drawing_maskfiltercreateblur) ([OH_Drawing_BlurType](#oh_drawing_blurtype) blurType, float sigma, bool respectCTM) | Creates an **OH_Drawing_MaskFilter** object with a given blur type.| 
| void [OH_Drawing_MaskFilterDestroy](#oh_drawing_maskfilterdestroy) ([OH_Drawing_MaskFilter](#oh_drawing_maskfilter) \*) | Destroys an **OH_Drawing_MaskFilter** object and reclaims the memory occupied by the object.| 
| [OH_Drawing_Matrix](#oh_drawing_matrix) \* [OH_Drawing_MatrixCreate](#oh_drawing_matrixcreate) (void) | Creates an **OH_Drawing_Matrix** object.| 
| [OH_Drawing_Matrix](#oh_drawing_matrix) \* [OH_Drawing_MatrixCreateRotation](#oh_drawing_matrixcreaterotation) (float deg, float x, float y) | Creates an **OH_Drawing_Matrix** with the rotation attribute. The matrix can rotate by a given degree around the rotation point (x, y).| 
| [OH_Drawing_Matrix](#oh_drawing_matrix) \* [OH_Drawing_MatrixCreateScale](#oh_drawing_matrixcreatescale) (float sx, float sy, float px, float py) | Creates an **OH_Drawing_Matrix** with the scale attribute. The matrix can be scaled with the factor (sx, sy) at the rotation point (px, py).| 
| [OH_Drawing_Matrix](#oh_drawing_matrix) \* [OH_Drawing_MatrixCreateTranslation](#oh_drawing_matrixcreatetranslation) (float dx, float dy) | Creates an **OH_Drawing_Matrix** with the translation attribute.|
| void [OH_Drawing_MatrixSetMatrix](#oh_drawing_matrixsetmatrix) ([OH_Drawing_Matrix](#oh_drawing_matrix) \*, float scaleX, float skewX, float transX, float skewY, float scaleY, float transY, float persp0, float persp1, float persp2) | Sets matrix parameters for an **OH_Drawing_Matrix** object.| 
| void [OH_Drawing_MatrixConcat](#oh_drawing_matrixconcat) ([OH_Drawing_Matrix](#oh_drawing_matrix) \*total, const [OH_Drawing_Matrix](#oh_drawing_matrix) \*a, const [OH_Drawing_Matrix](#oh_drawing_matrix) \*b) | Multiplies two matrices to produce a new matrix.| 
| float [OH_Drawing_MatrixGetValue](#oh_drawing_matrixgetvalue) ([OH_Drawing_Matrix](#oh_drawing_matrix) \*, int index) | Obtains a matrix value of a given index. The index ranges from 0 to 8.| 
| void [OH_Drawing_MatrixRotate](#oh_drawing_matrixrotate) ([OH_Drawing_Matrix](#oh_drawing_matrix) \*, float degree, float px, float py) | Sets a matrix as an identity matrix and rotates it by a given degree around the rotation point (px, py).| 
| void [OH_Drawing_MatrixTranslate](#oh_drawing_matrixtranslate) ([OH_Drawing_Matrix](#oh_drawing_matrix) \*, float dx, float dy) | Sets a matrix as an identity matrix and translates it by a given distance (dx, dy).| 
| void [OH_Drawing_MatrixScale](#oh_drawing_matrixscale) ([OH_Drawing_Matrix](#oh_drawing_matrix) \*, float sx, float sy, float px, float py) | Sets a matrix as an identity matrix and scales it with the factor (sx, sy) at the rotation point (px, py).| 
| bool [OH_Drawing_MatrixInvert](#oh_drawing_matrixinvert) ([OH_Drawing_Matrix](#oh_drawing_matrix) \*, [OH_Drawing_Matrix](#oh_drawing_matrix) \*inverse) | Inverts a matrix and returns the result.| 
| bool [OH_Drawing_MatrixIsEqual](#oh_drawing_matrixisequal) ([OH_Drawing_Matrix](#oh_drawing_matrix) \*, [OH_Drawing_Matrix](#oh_drawing_matrix) \*other) | Checks whether two **OH_Drawing_Matrix** objects are the same.| 
| bool [OH_Drawing_MatrixIsIdentity](#oh_drawing_matrixisidentity) ([OH_Drawing_Matrix](#oh_drawing_matrix) \*) | Checks whether an **OH_Drawing_Matrix** object is an identity matrix.| 
| void [OH_Drawing_MatrixDestroy](#oh_drawing_matrixdestroy) ([OH_Drawing_Matrix](#oh_drawing_matrix) \*) | Destroys an **OH_Drawing_Matrix** object and reclaims the memory occupied by the object.| 
| [OH_Drawing_MemoryStream](#oh_drawing_memorystream) \* [OH_Drawing_MemoryStreamCreate](#oh_drawing_memorystreamcreate) (const void \*data, size_t length, bool copyData) | Creates an **OH_Drawing_MemoryStream** object.| 
| void [OH_Drawing_MemoryStreamDestroy](#oh_drawing_memorystreamdestroy) ([OH_Drawing_MemoryStream](#oh_drawing_memorystream) \*) | Destroys an **OH_Drawing_MemoryStream** object and reclaims the memory occupied by the object.| 
| [OH_Drawing_Path](#oh_drawing_path) \* [OH_Drawing_PathCreate](#oh_drawing_pathcreate) (void) | Creates an **OH_Drawing_Path** object.| 
| [OH_Drawing_Path](#oh_drawing_path) \* [OH_Drawing_PathCopy](#oh_drawing_pathcopy) ([OH_Drawing_Path](#oh_drawing_path) \*) | Copies an existing [OH_Drawing_Path](#oh_drawing_path) object to create a new one.| 
| void [OH_Drawing_PathDestroy](#oh_drawing_pathdestroy) ([OH_Drawing_Path](#oh_drawing_path) \*) | Destroys an **OH_Drawing_Path** object and reclaims the memory occupied by the object.| 
| void [OH_Drawing_PathMoveTo](#oh_drawing_pathmoveto) ([OH_Drawing_Path](#oh_drawing_path) \*, float x, float y) | Sets the start point of a path.| 
| void [OH_Drawing_PathLineTo](#oh_drawing_pathlineto) ([OH_Drawing_Path](#oh_drawing_path) \*, float x, float y) | Draws a line segment from the last point of a path to the target point.| 
| void [OH_Drawing_PathArcTo](#oh_drawing_patharcto) ([OH_Drawing_Path](#oh_drawing_path) \*, float x1, float y1, float x2, float y2, float startDeg, float sweepDeg) | Draws an arc to a path. This is done by using angle arc mode. In this mode, a rectangle that encloses an ellipse is specified first, and then a start angle and a sweep angle are specified. The arc is a portion of the ellipse defined by the start angle and the sweep angle. By default, a line segment from the last point of the path to the start point of the arc is also added.| 
| void [OH_Drawing_PathQuadTo](#oh_drawing_pathquadto) ([OH_Drawing_Path](#oh_drawing_path) \*, float ctrlX, float ctrlY, float endX, float endY) | Draws a quadratic Bezier curve from the last point of a path to the target point.| 
| void [OH_Drawing_PathCubicTo](#oh_drawing_pathcubicto) ([OH_Drawing_Path](#oh_drawing_path) \*, float ctrlX1, float ctrlY1, float ctrlX2, float ctrlY2, float endX, float endY) | Draws a cubic Bezier curve from the last point of a path to the target point.| 
| void [OH_Drawing_PathAddRect](#oh_drawing_pathaddrect) ([OH_Drawing_Path](#oh_drawing_path) \*, float left, float top, float right, float bottom, [OH_Drawing_PathDirection](#oh_drawing_pathdirection)) | Adds a rectangle contour to a path in the specified direction.| 
| void [OH_Drawing_PathAddRoundRect](#oh_drawing_pathaddroundrect) ([OH_Drawing_Path](#oh_drawing_path) \*, const [OH_Drawing_RoundRect](#oh_drawing_roundrect) \*roundRect, [OH_Drawing_PathDirection](#oh_drawing_pathdirection)) | Adds a rounded rectangle contour to a path in the specified direction.| 
| void [OH_Drawing_PathAddArc](#oh_drawing_pathaddarc) ([OH_Drawing_Path](#oh_drawing_path) \*, const [OH_Drawing_Rect](#oh_drawing_rect) \*, float startAngle, float sweepAngle) | Adds an arc to a path as the start of a new contour. The arc added is part of the ellipse bounded by oval, from the start angle through the sweep angle, measured in degrees. A positive angle indicates a clockwise sweep, and a negative angle indicates a counterclockwise sweep. If the sweep angle is less than or equal to -360°, or if the sweep angle is greater than or equal to 360° and start angle modulo 90 is nearly zero, an oval instead of an ellipse is added.| 
| void [OH_Drawing_PathAddPath](#oh_drawing_pathaddpath) ([OH_Drawing_Path](#oh_drawing_path) \*, const [OH_Drawing_Path](#oh_drawing_path) \*src, const [OH_Drawing_Matrix](#oh_drawing_matrix) \*) | Adds a copy of src to the path, transformed by matrix.| 
| bool [OH_Drawing_PathContains](#oh_drawing_pathcontains) ([OH_Drawing_Path](#oh_drawing_path) \*, float x, float y) | Checks whether a coordinate point is included in a path.| 
| void [OH_Drawing_PathTransform](#oh_drawing_pathtransform) ([OH_Drawing_Path](#oh_drawing_path) \*, const [OH_Drawing_Matrix](#oh_drawing_matrix) \*) | Transforms the points in a path by matrix.| 
| void [OH_Drawing_PathSetFillType](#oh_drawing_pathsetfilltype) ([OH_Drawing_Path](#oh_drawing_path) \*, [OH_Drawing_PathFillType](#oh_drawing_pathfilltype)) | Sets the fill type for a path.| 
| void [OH_Drawing_PathClose](#oh_drawing_pathclose) ([OH_Drawing_Path](#oh_drawing_path) \*) | Closes a path by drawing a line segment from the current point to the start point of the path.| 
| void [OH_Drawing_PathReset](#oh_drawing_pathreset) ([OH_Drawing_Path](#oh_drawing_path) \*) | Resets path data.| 
| [OH_Drawing_PathEffect](#oh_drawing_patheffect) \* [OH_Drawing_CreateDashPathEffect](#oh_drawing_createdashpatheffect) (float \*intervals, int count, float phase) | Creates an **OH_Drawing_PathEffect** object with a dotted line effect. The dotted line effect is determined by a group of "on" and "off" intervals.| 
| void [OH_Drawing_PathEffectDestroy](#oh_drawing_patheffectdestroy) ([OH_Drawing_PathEffect](#oh_drawing_patheffect) \*) | Destroys an **OH_Drawing_PathEffect** object and reclaims the memory occupied by the object.| 
| [OH_Drawing_Pen](#oh_drawing_pen) \* [OH_Drawing_PenCreate](#oh_drawing_pencreate) (void) | Creates an **OH_Drawing_Pen** object.| 
| void [OH_Drawing_PenDestroy](#oh_drawing_pendestroy) ([OH_Drawing_Pen](#oh_drawing_pen) \*) | Destroys an **OH_Drawing_Pen** object and reclaims the memory occupied by the object.| 
| bool [OH_Drawing_PenIsAntiAlias](#oh_drawing_penisantialias) (const [OH_Drawing_Pen](#oh_drawing_pen) \*) | Checks whether anti-aliasing is enabled for a pen. Anti-aliasing makes the pixels around the shape edges semi-transparent.| 
| void [OH_Drawing_PenSetAntiAlias](#oh_drawing_pensetantialias) ([OH_Drawing_Pen](#oh_drawing_pen) \*, bool) | Enables or disables anti-aliasing for a pen. Anti-aliasing makes the pixels around the shape edges semi-transparent.| 
| uint32_t [OH_Drawing_PenGetColor](#oh_drawing_pengetcolor) (const [OH_Drawing_Pen](#oh_drawing_pen) \*) | Obtains the color of a pen. The color is used by the pen to outline a shape.| 
| void [OH_Drawing_PenSetColor](#oh_drawing_pensetcolor) ([OH_Drawing_Pen](#oh_drawing_pen) \*, uint32_t color) | Sets the color for a pen. The color is used by the pen to outline a shape.| 
| uint8_t [OH_Drawing_PenGetAlpha](#oh_drawing_pengetalpha) (const [OH_Drawing_Pen](#oh_drawing_pen) \*) | Obtains the alpha value of a pen. This value is used by the alpha channel when the pen outlines a shape.| 
| void [OH_Drawing_PenSetAlpha](#oh_drawing_pensetalpha) ([OH_Drawing_Pen](#oh_drawing_pen) \*, uint8_t alpha) | Sets the alpha value for a pen. This value is used by the alpha channel when the pen outlines a shape.| 
| float [OH_Drawing_PenGetWidth](#oh_drawing_pengetwidth) (const [OH_Drawing_Pen](#oh_drawing_pen) \*) | Obtains the thickness of a pen. This thickness determines the width of the outline of a shape.| 
| void [OH_Drawing_PenSetWidth](#oh_drawing_pensetwidth) ([OH_Drawing_Pen](#oh_drawing_pen) \*, float width) | Sets the thickness for a pen. This thickness determines the width of the outline of a shape.| 
| float [OH_Drawing_PenGetMiterLimit](#oh_drawing_pengetmiterlimit) (const [OH_Drawing_Pen](#oh_drawing_pen) \*) | Obtains the stroke miter limit of a polyline drawn by a pen. When the corner type is bevel, a beveled corner is displayed if the miter limit is exceeded, and a mitered corner is displayed if the miter limit is not exceeded.| 
| void [OH_Drawing_PenSetMiterLimit](#oh_drawing_pensetmiterlimit) ([OH_Drawing_Pen](#oh_drawing_pen) \*, float miter) | Sets the stroke miter limit for a polyline drawn by a pen. When the corner type is bevel, a beveled corner is displayed if the miter limit is exceeded, and a mitered corner is displayed if the miter limit is not exceeded.| 
| [OH_Drawing_PenLineCapStyle](#oh_drawing_penlinecapstyle)[OH_Drawing_PenGetCap](#oh_drawing_pengetcap) (const [OH_Drawing_Pen](#oh_drawing_pen) \*) | Obtains the line cap style of a pen.| 
| void [OH_Drawing_PenSetCap](#oh_drawing_pensetcap) ([OH_Drawing_Pen](#oh_drawing_pen) \*, [OH_Drawing_PenLineCapStyle](#oh_drawing_penlinecapstyle)) | Sets the line cap style for a pen.| 
| [OH_Drawing_PenLineJoinStyle](#oh_drawing_penlinejoinstyle)[OH_Drawing_PenGetJoin](#oh_drawing_pengetjoin) (const [OH_Drawing_Pen](#oh_drawing_pen) \*) | Obtains the line join style of a pen.| 
| void [OH_Drawing_PenSetJoin](#oh_drawing_pensetjoin) ([OH_Drawing_Pen](#oh_drawing_pen) \*, [OH_Drawing_PenLineJoinStyle](#oh_drawing_penlinejoinstyle)) | Sets the line join style for a pen.| 
| void [OH_Drawing_PenSetShaderEffect](#oh_drawing_pensetshadereffect) ([OH_Drawing_Pen](#oh_drawing_pen) \*, [OH_Drawing_ShaderEffect](#oh_drawing_shadereffect) \*) | Sets the shader effect for a pen.| 
| void [OH_Drawing_PenSetPathEffect](#oh_drawing_pensetpatheffect) ([OH_Drawing_Pen](#oh_drawing_pen) \*, [OH_Drawing_PathEffect](#oh_drawing_patheffect) \*) | Sets the path effect for a pen.| 
| void [OH_Drawing_PenSetFilter](#oh_drawing_pensetfilter) ([OH_Drawing_Pen](#oh_drawing_pen) \*, [OH_Drawing_Filter](#oh_drawing_filter) \*) | Sets a filter for a pen.| 
| void [OH_Drawing_PenSetBlendMode](#oh_drawing_pensetblendmode) ([OH_Drawing_Pen](#oh_drawing_pen) \*, [OH_Drawing_BlendMode](#oh_drawing_blendmode)) | Sets a blender for a pen. The blender implements the specified blend mode.| 
| [OH_Drawing_Point](#oh_drawing_point) \* [OH_Drawing_PointCreate](#oh_drawing_pointcreate) (float x, float y) | Creates an **OH_Drawing_Point** object.| 
| void [OH_Drawing_PointDestroy](#oh_drawing_pointdestroy) ([OH_Drawing_Point](#oh_drawing_point) \*) | Destroys an **OH_Drawing_Point** object and reclaims the memory occupied by the object.| 
| [OH_Drawing_Rect](#oh_drawing_rect) \* [OH_Drawing_RectCreate](#oh_drawing_rectcreate) (float left, float top, float right, float bottom) | Creates an **OH_Drawing_Rect** object.| 
| void [OH_Drawing_RectDestroy](#oh_drawing_rectdestroy) ([OH_Drawing_Rect](#oh_drawing_rect) \*) | Destroys an **OH_Drawing_Rect** object and reclaims the memory occupied by the object.| 
| uint32_t [OH_Drawing_RegisterFont](#oh_drawing_registerfont) ([OH_Drawing_FontCollection](#oh_drawing_fontcollection) \*, const char \*fontFamily, const char \*familySrc) | Registers a custom font with the font manager.| 
| uint32_t [OH_Drawing_RegisterFontBuffer](#oh_drawing_registerfontbuffer) ([OH_Drawing_FontCollection](#oh_drawing_fontcollection) \*, const char \*fontFamily, uint8_t \*fontBuffer, size_t length) | Registers a font buffer with the font manager.|
| [OH_Drawing_RoundRect](#oh_drawing_roundrect) \* [OH_Drawing_RoundRectCreate](#oh_drawing_roundrectcreate) (const [OH_Drawing_Rect](#oh_drawing_rect) \*, float xRad, float yRad) | Creates an **OH_Drawing_RoundRect** object.| 
| void [OH_Drawing_RoundRectDestroy](#oh_drawing_roundrectdestroy) ([OH_Drawing_RoundRect](#oh_drawing_roundrect) \*) | Destroys an **OH_Drawing_RoundRect** object and reclaims the memory occupied by the object.| 
| [OH_Drawing_SamplingOptions](#oh_drawing_samplingoptions) \* [OH_Drawing_SamplingOptionsCreate](#oh_drawing_samplingoptionscreate) ([OH_Drawing_FilterMode](#oh_drawing_filtermode), [OH_Drawing_MipmapMode](#oh_drawing_mipmapmode)) | Creates an **OH_Drawing_SamplingOptions** object.| 
| void [OH_Drawing_SamplingOptionsDestroy](#oh_drawing_samplingoptionsdestroy) ([OH_Drawing_SamplingOptions](#oh_drawing_samplingoptions) \*) | Destroys an **OH_Drawing_SamplingOptions** object and reclaims the memory occupied by the object.| 
| [OH_Drawing_ShaderEffect](#oh_drawing_shadereffect) \* [OH_Drawing_ShaderEffectCreateLinearGradient](#oh_drawing_shadereffectcreatelineargradient) (const [OH_Drawing_Point](#oh_drawing_point) \*startPt, const [OH_Drawing_Point](#oh_drawing_point) \*endPt, const uint32_t \*colors, const float \*pos, uint32_t size, [OH_Drawing_TileMode](#oh_drawing_tilemode)) | Creates an **OH_Drawing_ShaderEffect** object that generates a linear gradient between two points.| 
| [OH_Drawing_ShaderEffect](#oh_drawing_shadereffect) \* [OH_Drawing_ShaderEffectCreateRadialGradient](#oh_drawing_shadereffectcreateradialgradient) (const [OH_Drawing_Point](#oh_drawing_point) \*centerPt, float radius, const uint32_t \*colors, const float \*pos, uint32_t size, [OH_Drawing_TileMode](#oh_drawing_tilemode)) | Creates an **OH_Drawing_ShaderEffect** object that generates a radial gradient based on the center and radius of a circle. The radial gradient transitions colors from the center to the ending shape in a radial manner.| 
| [OH_Drawing_ShaderEffect](#oh_drawing_shadereffect) \* [OH_Drawing_ShaderEffectCreateSweepGradient](#oh_drawing_shadereffectcreatesweepgradient) (const [OH_Drawing_Point](#oh_drawing_point) \*centerPt, const uint32_t \*colors, const float \*pos, uint32_t size, [OH_Drawing_TileMode](#oh_drawing_tilemode)) | Creates an **OH_Drawing_ShaderEffect** object that generates a sweep gradient based on the center.| 
| void [OH_Drawing_ShaderEffectDestroy](#oh_drawing_shadereffectdestroy) ([OH_Drawing_ShaderEffect](#oh_drawing_shadereffect) \*) | Destroys an **OH_Drawing_ShaderEffect** object and reclaims the memory occupied by the object.| 
| [OH_Drawing_TextBlobBuilder](#oh_drawing_textblobbuilder) \* [OH_Drawing_TextBlobBuilderCreate](#oh_drawing_textblobbuildercreate) (void) | Creates an **OH_Drawing_TextBlobBuilder** object.| 
| [OH_Drawing_TextBlob](#oh_drawing_textblob) \* [OH_Drawing_TextBlobCreateFromText](#oh_drawing_textblobcreatefromtext) (const void \*text, size_t byteLength, const [OH_Drawing_Font](#oh_drawing_font) \*, [OH_Drawing_TextEncoding](#oh_drawing_textencoding)) | Creates an **OH_Drawing_TextBlob** object from the text.| 
| [OH_Drawing_TextBlob](#oh_drawing_textblob) \* [OH_Drawing_TextBlobCreateFromPosText](#oh_drawing_textblobcreatefrompostext) (const void \*text, size_t byteLength, [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*, const [OH_Drawing_Font](#oh_drawing_font) \*, [OH_Drawing_TextEncoding](#oh_drawing_textencoding)) | Creates an **OH_Drawing_TextBlob** object from the text and text position.| 
| [OH_Drawing_TextBlob](#oh_drawing_textblob) \* [OH_Drawing_TextBlobCreateFromString](#oh_drawing_textblobcreatefromstring) (const char \*str, const [OH_Drawing_Font](#oh_drawing_font) \*, [OH_Drawing_TextEncoding](#oh_drawing_textencoding)) | Creates an **OH_Drawing_TextBlob** object from a string.| 
| void [OH_Drawing_TextBlobGetBounds](#oh_drawing_textblobgetbounds) ([OH_Drawing_TextBlob](#oh_drawing_textblob) \*, [OH_Drawing_Rect](#oh_drawing_rect) \*) | Obtains the bounds of an **OH_Drawing_TextBlob** object.| 
| const [OH_Drawing_RunBuffer](_o_h___drawing___run_buffer.md) \* [OH_Drawing_TextBlobBuilderAllocRunPos](#oh_drawing_textblobbuilderallocrunpos) ([OH_Drawing_TextBlobBuilder](#oh_drawing_textblobbuilder) \*, const [OH_Drawing_Font](#oh_drawing_font) \*, int32_t count, const [OH_Drawing_Rect](#oh_drawing_rect) \*) | Allocates a run to store glyphs and positions. The pointer returned does not need to be managed by the caller. It can no longer be used after [OH_Drawing_TextBlobBuilderMake](#oh_drawing_textblobbuildermake) is called.| 
| [OH_Drawing_TextBlob](#oh_drawing_textblob) \* [OH_Drawing_TextBlobBuilderMake](#oh_drawing_textblobbuildermake) ([OH_Drawing_TextBlobBuilder](#oh_drawing_textblobbuilder) \*) | Makes an **OH_Drawing_TextBlob** object from an **OH_Drawing_TextBlobBuilder**.| 
| void [OH_Drawing_TextBlobDestroy](#oh_drawing_textblobdestroy) ([OH_Drawing_TextBlob](#oh_drawing_textblob) \*) | Destroys an **OH_Drawing_TextBlob** object and reclaims the memory occupied by the object.| 
| void [OH_Drawing_TextBlobBuilderDestroy](#oh_drawing_textblobbuilderdestroy) ([OH_Drawing_TextBlobBuilder](#oh_drawing_textblobbuilder) \*) | Destroys an **OH_Drawing_TextBlobBuilder** object and reclaims the memory occupied by the object.| 
| [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \* [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle) (void) | Creates an **OH_Drawing_TypographyStyle** object.| 
| void [OH_Drawing_DestroyTypographyStyle](#oh_drawing_destroytypographystyle) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*) | Destroys an **OH_Drawing_TypographyStyle** object and reclaims the memory occupied by the object.| 
| void [OH_Drawing_SetTypographyTextDirection](#oh_drawing_settypographytextdirection) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, int) | Sets the text direction.| 
| void [OH_Drawing_SetTypographyTextAlign](#oh_drawing_settypographytextalign) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, int) | Sets the text alignment mode.| 
| int [OH_Drawing_TypographyGetEffectiveAlignment](#oh_drawing_typographygeteffectivealignment) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*style) | Obtains the text alignment mode.| 
| void [OH_Drawing_SetTypographyTextMaxLines](#oh_drawing_settypographytextmaxlines) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, int) | Sets the maximum number of lines in the text.| 
| [OH_Drawing_TextStyle](#oh_drawing_textstyle) \* [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle) (void) | Creates an **OH_Drawing_TextStyle** object.| 
| [OH_Drawing_TextStyle](#oh_drawing_textstyle) \* [OH_Drawing_TypographyGetTextStyle](#oh_drawing_typographygettextstyle) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*style) | Obtains the text style.| 
| void [OH_Drawing_DestroyTextStyle](#oh_drawing_destroytextstyle) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*) | Destroys an **OH_Drawing_TextStyle** object and reclaims the memory occupied by the object.| 
| void [OH_Drawing_SetTextStyleColor](#oh_drawing_settextstylecolor) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, uint32_t) | Sets the text color.| 
| void [OH_Drawing_SetTextStyleFontSize](#oh_drawing_settextstylefontsize) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, double) | Sets the font size.| 
| void [OH_Drawing_SetTextStyleFontWeight](#oh_drawing_settextstylefontweight) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, int) | Sets the font weight.| 
| void [OH_Drawing_SetTextStyleBaseLine](#oh_drawing_settextstylebaseline) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, int) | Sets the text baseline.| 
| void [OH_Drawing_SetTextStyleDecoration](#oh_drawing_settextstyledecoration) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, int) | Sets the text decoration.| 
| void [OH_Drawing_SetTextStyleDecorationColor](#oh_drawing_settextstyledecorationcolor) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, uint32_t) | Sets the color for the text decoration.| 
| void [OH_Drawing_SetTextStyleFontHeight](#oh_drawing_settextstylefontheight) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, double) | Sets the font height.| 
| void [OH_Drawing_SetTextStyleFontFamilies](#oh_drawing_settextstylefontfamilies) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, int, const char \*fontFamilies[]) | Sets the font families.| 
| void [OH_Drawing_SetTextStyleFontStyle](#oh_drawing_settextstylefontstyle) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, int) | Sets the font style.| 
| void [OH_Drawing_SetTextStyleLocale](#oh_drawing_settextstylelocale) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, const char \*) | Sets the locale.| 
| void [OH_Drawing_SetTextStyleForegroundBrush](#oh_drawing_settextstyleforegroundbrush) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, [OH_Drawing_Brush](#oh_drawing_brush) \*) | Sets the foreground brush.| 
| void [OH_Drawing_TextStyleGetForegroundBrush](#oh_drawing_textstylegetforegroundbrush) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, [OH_Drawing_Brush](#oh_drawing_brush) \*) | Obtains the foreground brush.| 
| void [OH_Drawing_SetTextStyleForegroundPen](#oh_drawing_settextstyleforegroundpen) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, [OH_Drawing_Pen](#oh_drawing_pen) \*) | Sets the foreground pen.| 
| void [OH_Drawing_TextStyleGetForegroundPen](#oh_drawing_textstylegetforegroundpen) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, [OH_Drawing_Pen](#oh_drawing_pen) \*) | Obtains the foreground pen.| 
| void [OH_Drawing_SetTextStyleBackgroundBrush](#oh_drawing_settextstylebackgroundbrush) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, [OH_Drawing_Brush](#oh_drawing_brush) \*) | Sets the background brush.| 
| void [OH_Drawing_TextStyleGetBackgroundBrush](#oh_drawing_textstylegetbackgroundbrush) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, [OH_Drawing_Brush](#oh_drawing_brush) \*) | Obtains the background brush.| 
| void [OH_Drawing_SetTextStyleBackgroundPen](#oh_drawing_settextstylebackgroundpen) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, [OH_Drawing_Pen](#oh_drawing_pen) \*) | Sets the background pen.| 
| void [OH_Drawing_TextStyleGetBackgroundPen](#oh_drawing_textstylegetbackgroundpen) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, [OH_Drawing_Pen](#oh_drawing_pen) \*) | Obtains the background pen.| 
| [OH_Drawing_TypographyCreate](#oh_drawing_typographycreate) \* [OH_Drawing_CreateTypographyHandler](#oh_drawing_createtypographyhandler) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, [OH_Drawing_FontCollection](#oh_drawing_fontcollection) \*) | Creates an **OH_Drawing_TypographyCreate** object.| 
| void [OH_Drawing_DestroyTypographyHandler](#oh_drawing_destroytypographyhandler) ([OH_Drawing_TypographyCreate](#oh_drawing_typographycreate) \*) | Destroys an **OH_Drawing_TypographyCreate** object and reclaims the memory occupied by the object.| 
| void [OH_Drawing_TypographyHandlerPushTextStyle](#oh_drawing_typographyhandlerpushtextstyle) ([OH_Drawing_TypographyCreate](#oh_drawing_typographycreate) \*, [OH_Drawing_TextStyle](#oh_drawing_textstyle) \*) | Sets the text style.| 
| void [OH_Drawing_TypographyHandlerAddText](#oh_drawing_typographyhandleraddtext) ([OH_Drawing_TypographyCreate](#oh_drawing_typographycreate) \*, const char \*) | Sets the text content.| 
| void [OH_Drawing_TypographyHandlerPopTextStyle](#oh_drawing_typographyhandlerpoptextstyle) ([OH_Drawing_TypographyCreate](#oh_drawing_typographycreate) \*) | Removes the topmost style in the stack, leaving the remaining styles in effect.| 
| [OH_Drawing_Typography](#oh_drawing_typography) \* [OH_Drawing_CreateTypography](#oh_drawing_createtypography) ([OH_Drawing_TypographyCreate](#oh_drawing_typographycreate) \*) | Creates an **OH_Drawing_Typography** object.| 
| void [OH_Drawing_DestroyTypography](#oh_drawing_destroytypography) ([OH_Drawing_Typography](#oh_drawing_typography) \*) | Destroys an **OH_Drawing_Typography** object and reclaims the memory occupied by the object.| 
| void [OH_Drawing_TypographyLayout](#oh_drawing_typographylayout) ([OH_Drawing_Typography](#oh_drawing_typography) \*, double) | Lays out the typography.| 
| void [OH_Drawing_TypographyPaint](#oh_drawing_typographypaint) ([OH_Drawing_Typography](#oh_drawing_typography) \*, [OH_Drawing_Canvas](#oh_drawing_canvas) \*, double, double) | Paints text on the canvas.| 
| double [OH_Drawing_TypographyGetMaxWidth](#oh_drawing_typographygetmaxwidth) ([OH_Drawing_Typography](#oh_drawing_typography) \*) | Obtains the maximum width.| 
| double [OH_Drawing_TypographyGetHeight](#oh_drawing_typographygetheight) ([OH_Drawing_Typography](#oh_drawing_typography) \*) | Obtains the height.| 
| double [OH_Drawing_TypographyGetLongestLine](#oh_drawing_typographygetlongestline) ([OH_Drawing_Typography](#oh_drawing_typography) \*) | Obtains the width of the longest line. You are advised to round up the return value in actual use. When the text content is empty, the minimum float value, that is, -340282346638528859811704183484516925440.000000, is returned.| 
| double [OH_Drawing_TypographyGetMinIntrinsicWidth](#oh_drawing_typographygetminintrinsicwidth) ([OH_Drawing_Typography](#oh_drawing_typography) \*) | Obtains the minimum intrinsic width.| 
| double [OH_Drawing_TypographyGetMaxIntrinsicWidth](#oh_drawing_typographygetmaxintrinsicwidth) ([OH_Drawing_Typography](#oh_drawing_typography) \*) | Obtains the maximum intrinsic width.| 
| double [OH_Drawing_TypographyGetAlphabeticBaseline](#oh_drawing_typographygetalphabeticbaseline) ([OH_Drawing_Typography](#oh_drawing_typography) \*) | Obtains the alphabetic baseline.| 
| double [OH_Drawing_TypographyGetIdeographicBaseline](#oh_drawing_typographygetideographicbaseline) ([OH_Drawing_Typography](#oh_drawing_typography) \*) | Obtains the ideographic baseline.| 
| void [OH_Drawing_TypographyHandlerAddPlaceholder](#oh_drawing_typographyhandleraddplaceholder) ([OH_Drawing_TypographyCreate](#oh_drawing_typographycreate) \*, [OH_Drawing_PlaceholderSpan](_o_h___drawing___placeholder_span.md) \*) | Adds a placeholder.| 
| bool [OH_Drawing_TypographyDidExceedMaxLines](#oh_drawing_typographydidexceedmaxlines) ([OH_Drawing_Typography](#oh_drawing_typography) \*) | Checks whether the maximum number of lines is exceeded.| 
| [OH_Drawing_TextBox](#oh_drawing_textbox) \* [OH_Drawing_TypographyGetRectsForRange](#oh_drawing_typographygetrectsforrange) ([OH_Drawing_Typography](#oh_drawing_typography) \*, size_t, size_t, [OH_Drawing_RectHeightStyle](#oh_drawing_rectheightstyle), [OH_Drawing_RectWidthStyle](#oh_drawing_rectwidthstyle)) | Obtains text boxes in a given range.| 
| [OH_Drawing_TextBox](#oh_drawing_textbox) \* [OH_Drawing_TypographyGetRectsForPlaceholders](#oh_drawing_typographygetrectsforplaceholders) ([OH_Drawing_Typography](#oh_drawing_typography) \*) | Obtains text boxes for placeholders.| 
| float [OH_Drawing_GetLeftFromTextBox](#oh_drawing_getleftfromtextbox) ([OH_Drawing_TextBox](#oh_drawing_textbox) \*, int) | Obtains the left position of a text box.| 
| float [OH_Drawing_GetRightFromTextBox](#oh_drawing_getrightfromtextbox) ([OH_Drawing_TextBox](#oh_drawing_textbox) \*, int) | Obtains the right position of a text box.| 
| float [OH_Drawing_GetTopFromTextBox](#oh_drawing_gettopfromtextbox) ([OH_Drawing_TextBox](#oh_drawing_textbox) \*, int) | Obtains the top position of a text box.| 
| float [OH_Drawing_GetBottomFromTextBox](#oh_drawing_getbottomfromtextbox) ([OH_Drawing_TextBox](#oh_drawing_textbox) \*, int) | Obtains the bottom position of a text box.| 
| int [OH_Drawing_GetTextDirectionFromTextBox](#oh_drawing_gettextdirectionfromtextbox) ([OH_Drawing_TextBox](#oh_drawing_textbox) \*, int) | Obtains the text direction of a text box.| 
| size_t [OH_Drawing_GetSizeOfTextBox](#oh_drawing_getsizeoftextbox) ([OH_Drawing_TextBox](#oh_drawing_textbox) \*) | Obtains the number of text boxes.| 
| [OH_Drawing_PositionAndAffinity](#oh_drawing_positionandaffinity) \* [OH_Drawing_TypographyGetGlyphPositionAtCoordinate](#oh_drawing_typographygetglyphpositionatcoordinate) ([OH_Drawing_Typography](#oh_drawing_typography) \*, double, double) | Obtains the position and affinity of the glyph at the given coordinates.| 
| [OH_Drawing_PositionAndAffinity](#oh_drawing_positionandaffinity) \* [OH_Drawing_TypographyGetGlyphPositionAtCoordinateWithCluster](#oh_drawing_typographygetglyphpositionatcoordinatewithcluster) ([OH_Drawing_Typography](#oh_drawing_typography) \*, double, double) | Obtains the position and affinity of the glyph cluster to which the glyph at the given coordinates belongs. The glyph cluster is a container that holds one or more glyphs.| 
| size_t [OH_Drawing_GetPositionFromPositionAndAffinity](#oh_drawing_getpositionfrompositionandaffinity) ([OH_Drawing_PositionAndAffinity](#oh_drawing_positionandaffinity) \*) | Obtains the position attribute of an **OH_Drawing_PositionAndAffinity** object.| 
| int [OH_Drawing_GetAffinityFromPositionAndAffinity](#oh_drawing_getaffinityfrompositionandaffinity) ([OH_Drawing_PositionAndAffinity](#oh_drawing_positionandaffinity) \*) | Obtains the affinity attribute of an **OH_Drawing_PositionAndAffinity** object. The affinity determines whether the font is close to the front text or rear text.| 
| [OH_Drawing_Range](#oh_drawing_range) \* [OH_Drawing_TypographyGetWordBoundary](#oh_drawing_typographygetwordboundary) ([OH_Drawing_Typography](#oh_drawing_typography) \*, size_t) | Obtains the word boundary.| 
| size_t [OH_Drawing_GetStartFromRange](#oh_drawing_getstartfromrange) ([OH_Drawing_Range](#oh_drawing_range) \*) | Obtains the start position of an **OH_Drawing_Range** object.| 
| size_t [OH_Drawing_GetEndFromRange](#oh_drawing_getendfromrange) ([OH_Drawing_Range](#oh_drawing_range) \*) | Obtains the end position of an **OH_Drawing_Range** object.| 
| size_t [OH_Drawing_TypographyGetLineCount](#oh_drawing_typographygetlinecount) ([OH_Drawing_Typography](#oh_drawing_typography) \*) | Obtains the number of lines.| 
| void [OH_Drawing_SetTextStyleDecorationStyle](#oh_drawing_settextstyledecorationstyle) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, int) | Sets the text decoration style.| 
| void [OH_Drawing_SetTextStyleDecorationThicknessScale](#oh_drawing_settextstyledecorationthicknessscale) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, double) | Sets the thickness scale factor of the text decoration line.| 
| void [OH_Drawing_SetTextStyleLetterSpacing](#oh_drawing_settextstyleletterspacing) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, double) | Sets the letter spacing for text.| 
| void [OH_Drawing_SetTextStyleWordSpacing](#oh_drawing_settextstylewordspacing) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, double) | Sets the word spacing for text.| 
| void [OH_Drawing_SetTextStyleHalfLeading](#oh_drawing_settextstylehalfleading) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, bool) | Sets half leading for text.| 
| void [OH_Drawing_SetTextStyleEllipsis](#oh_drawing_settextstyleellipsis) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, const char \*) | Sets the ellipsis content for text.| 
| void [OH_Drawing_SetTextStyleEllipsisModal](#oh_drawing_settextstyleellipsismodal) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, int) | Sets the ellipsis style for text.| 
| void [OH_Drawing_SetTypographyTextBreakStrategy](#oh_drawing_settypographytextbreakstrategy) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, int) | Sets the text break strategy.| 
| void [OH_Drawing_SetTypographyTextWordBreakType](#oh_drawing_settypographytextwordbreaktype) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, int) | Sets the word break type.| 
| void [OH_Drawing_SetTypographyTextEllipsisModal](#oh_drawing_settypographytextellipsismodal) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, int) | Sets the ellipsis style for text.| 
| void [OH_Drawing_SetTypographyTextEllipsis](#oh_drawing_settypographytextellipsis) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*style, const char \*ellipsis) | Sets the ellipsis style.| 
| double [OH_Drawing_TypographyGetLineHeight](#oh_drawing_typographygetlineheight) ([OH_Drawing_Typography](#oh_drawing_typography) \*, int) | Obtains the height of a line.| 
| double [OH_Drawing_TypographyGetLineWidth](#oh_drawing_typographygetlinewidth) ([OH_Drawing_Typography](#oh_drawing_typography) \*, int) | Obtains the width of a line.| 
| void [OH_Drawing_SetTypographyTextSplitRatio](#oh_drawing_settypographytextsplitratio) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*style, float textSplitRatio) | Sets the text split ratio.| 
| bool [OH_Drawing_TypographyIsLineUnlimited](#oh_drawing_typographyislineunlimited) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*style) | Checks whether the maximum number of lines is limited for text.| 
| bool [OH_Drawing_TypographyIsEllipsized](#oh_drawing_typographyisellipsized) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*style) | Checks whether the text has an ellipsis.| 
| void [OH_Drawing_SetTypographyTextLocale](#oh_drawing_settypographytextlocale) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*style, const char \*locale) | Sets the text locale.| 
| bool [OH_Drawing_TextStyleGetFontMetrics](#oh_drawing_textstylegetfontmetrics) ([OH_Drawing_Typography](#oh_drawing_typography) \*,[OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, [OH_Drawing_Font_Metrics](_o_h___drawing___font___metrics.md) \*) | Obtains the font metrics.| 
| void [OH_Drawing_SetTypographyTextStyle](#oh_drawing_settypographytextstyle) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, [OH_Drawing_TextStyle](#oh_drawing_textstyle) \*) | Sets the text style.| 
| [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) \* [OH_Drawing_CreateFontDescriptor](#oh_drawing_createfontdescriptor) (void) | Creates a font descriptor object to describe the detailed information about a system font.| 
| void [OH_Drawing_DestroyFontDescriptor](#oh_drawing_destroyfontdescriptor) ([OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) \*) | Reclaims the memory occupied by a font descriptor object.| 
| [OH_Drawing_FontParser](#oh_drawing_fontparser) \* [OH_Drawing_CreateFontParser](#oh_drawing_createfontparser) (void) | Creates a font parser object to parse a system font.| 
| void [OH_Drawing_DestroyFontParser](#oh_drawing_destroyfontparser) ([OH_Drawing_FontParser](#oh_drawing_fontparser) \*) | Reclaims the memory occupied by a font parser object.| 
| char \*\* [OH_Drawing_FontParserGetSystemFontList](#oh_drawing_fontparsergetsystemfontlist) ([OH_Drawing_FontParser](#oh_drawing_fontparser) \*, size_t \*) | Obtains the list of system fonts.| 
| void [OH_Drawing_DestroySystemFontList](#oh_drawing_destroysystemfontlist) (char \*\*, size_t) | Reclaims the memory occupied by the system font list.| 
| [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) \* [OH_Drawing_FontParserGetFontByName](#oh_drawing_fontparsergetfontbyname) ([OH_Drawing_FontParser](#oh_drawing_fontparser) \*, const char \*) | Obtains the descriptor of a system font based on the font name.| 
| [OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md) \* [OH_Drawing_TypographyGetLineMetrics](#oh_drawing_typographygetlinemetrics) ([OH_Drawing_Typography](#oh_drawing_typography) \*) | Obtains the line metrics.| 
| size_t [OH_Drawing_LineMetricsGetSize](#oh_drawing_linemetricsgetsize) ([OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md) \*) | Obtains the number of lines.| 
| void [OH_Drawing_DestroyLineMetrics](#oh_drawing_destroylinemetrics) ([OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md) \*) | Reclaims the memory occupied by a line metrics object.| 
| bool [OH_Drawing_TypographyGetLineMetricsAt](#oh_drawing_typographygetlinemetricsat) ([OH_Drawing_Typography](#oh_drawing_typography) \*, int, [OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md) \*) | Obtains the metrics object at a given line.| 
| bool [OH_Drawing_TypographyGetLineInfo](#oh_drawing_typographygetlineinfo) ([OH_Drawing_Typography](#oh_drawing_typography) \*, int, bool, bool, [OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md) \*) | Obtains the metrics of a given line or the metrics of the first character in a given line.| 
| void [OH_Drawing_SetTypographyTextFontWeight](#oh_drawing_settypographytextfontweight) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, int) | Sets the font weight for text.| 
| void [OH_Drawing_SetTypographyTextFontStyle](#oh_drawing_settypographytextfontstyle) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, int) | Sets the font style.| 
| void [OH_Drawing_SetTypographyTextFontFamily](#oh_drawing_settypographytextfontfamily) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, const char \*) | Sets the font family name for text.| 
| void [OH_Drawing_SetTypographyTextFontSize](#oh_drawing_settypographytextfontsize) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, double) | Sets the font size for text.| 
| void [OH_Drawing_SetTypographyTextLineStyleFontSize](#oh_drawing_settypographytextlinestylefontsize) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, double) | Sets the font size for a text line.| 
| void [OH_Drawing_SetTypographyTextFontHeight](#oh_drawing_settypographytextfontheight) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, double) | Sets the font height for text.| 
| void [OH_Drawing_SetTypographyTextHalfLeading](#oh_drawing_settypographytexthalfleading) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, bool) | Sets whether half leading is used for text.| 
| void [OH_Drawing_SetTypographyTextUseLineStyle](#oh_drawing_settypographytextuselinestyle) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, bool) | Sets whether to enable the line style for text.| 
| void [OH_Drawing_SetTypographyTextLineStyleFontWeight](#oh_drawing_settypographytextlinestylefontweight) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, int) | Sets the font weight of the text line style.| 
| void [OH_Drawing_SetTypographyTextLineStyleFontStyle](#oh_drawing_settypographytextlinestylefontstyle) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, int) | Sets the font style of the text line style.| 
| void [OH_Drawing_SetTypographyTextLineStyleFontFamilies](#oh_drawing_settypographytextlinestylefontfamilies) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, int, const char \*fontFamilies[]) | Sets the font families of the text line style.| 
| void [OH_Drawing_SetTypographyTextLineStyleFontHeight](#oh_drawing_settypographytextlinestylefontheight) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, double) | Sets the font height of the text line style.| 
| void [OH_Drawing_SetTypographyTextLineStyleHalfLeading](#oh_drawing_settypographytextlinestylehalfleading) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, bool) | Sets whether half leading is used for the text line style.| 
| void [OH_Drawing_SetTypographyTextLineStyleSpacingScale](#oh_drawing_settypographytextlinestylespacingscale) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, double) | Sets the spacing ratio of the text line style.| 
| void [OH_Drawing_SetTypographyTextLineStyleOnly](#oh_drawing_settypographytextlinestyleonly) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, bool) | Sets whether only the text line style is enabled.| 
| [OH_Drawing_TextShadow](#oh_drawing_textshadow) \* [OH_Drawing_CreateTextShadow](#oh_drawing_createtextshadow) (void) | Creates a pointer to a text shadow object.| 
| void [OH_Drawing_DestroyTextShadow](#oh_drawing_destroytextshadow) ([OH_Drawing_TextShadow](#oh_drawing_textshadow) \*) | Reclaims the memory occupied by a text shadow object.| 
| [OH_Drawing_TextShadow](#oh_drawing_textshadow) \* [OH_Drawing_TextStyleGetShadows](#oh_drawing_textstylegetshadows) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*) | Obtains a text shadow container.| 
| int [OH_Drawing_TextStyleGetShadowCount](#oh_drawing_textstylegetshadowcount) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*) | Obtains the size of a text shadow container.| 
| void [OH_Drawing_TextStyleAddShadow](#oh_drawing_textstyleaddshadow) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, const [OH_Drawing_TextShadow](#oh_drawing_textshadow) \*) | Add a shadow to a text shadow container.| 
| void [OH_Drawing_TextStyleClearShadows](#oh_drawing_textstyleclearshadows) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*) | Clears all shadows in a text shadow container.| 
| [OH_Drawing_TextShadow](#oh_drawing_textshadow) \* [OH_Drawing_TextStyleGetShadowWithIndex](#oh_drawing_textstylegetshadowwithindex) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, int) | Obtains a shadow with a given index in a text shadow container.| 
| void [OH_Drawing_TypographySetIndents](#oh_drawing_typographysetindents) ([OH_Drawing_Typography](#oh_drawing_typography) \*, int, const float indents[]) | Sets the indents for typography.| 
| float [OH_Drawing_TypographyGetIndentsWithIndex](#oh_drawing_typographygetindentswithindex) ([OH_Drawing_Typography](#oh_drawing_typography) \*, int) | Obtains indents with a given index.| 
| [OH_Drawing_Range](#oh_drawing_range) \* [OH_Drawing_TypographyGetLineTextRange](#oh_drawing_typographygetlinetextrange) ([OH_Drawing_Typography](#oh_drawing_typography) \*, int, bool) | Obtains the line boundary.| 
| void [OH_Drawing_DestroyTextShadows](#oh_drawing_destroytextshadows) ([OH_Drawing_TextShadow](#oh_drawing_textshadow) \*) | Reclaims the memory occupied by the vector consisting of the **OH_Drawing_TextShadow** objects.| 
| [OH_Drawing_Typeface](#oh_drawing_typeface) \* [OH_Drawing_TypefaceCreateDefault](#oh_drawing_typefacecreatedefault) (void) | Creates a default **OH_Drawing_Typeface** object.| 
| [OH_Drawing_Typeface](#oh_drawing_typeface) \* [OH_Drawing_TypefaceCreateFromFile](#oh_drawing_typefacecreatefromfile) (const char \*path, int index) | Creates an **OH_Drawing_Typeface** object through a file.| 
| [OH_Drawing_Typeface](#oh_drawing_typeface) \* [OH_Drawing_TypefaceCreateFromStream](#oh_drawing_typefacecreatefromstream) ([OH_Drawing_MemoryStream](#oh_drawing_memorystream) \*, int32_t index) | Creates an **OH_Drawing_Typeface** object through a memory stream. If the memory stream is an invalid font file, a null pointer is returned. After the memory stream is passed in, the ownership is transferred and you cannot release it.| 
| void [OH_Drawing_TypefaceDestroy](#oh_drawing_typefacedestroy) ([OH_Drawing_Typeface](#oh_drawing_typeface) \*) | Destroys an **OH_Drawing_Typeface** object and reclaims the memory occupied by the object.| 
| void [OH_Drawing_CanvasClipRect](#oh_drawing_canvascliprect) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Rect](#oh_drawing_rect) \*, [OH_Drawing_CanvasClipOp](#oh_drawing_canvasclipop) clipOp, bool doAntiAlias) | Clips a rectangle.| 
| void [OH_Drawing_CanvasClipPath](#oh_drawing_canvasclippath) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Path](#oh_drawing_path) \*, [OH_Drawing_CanvasClipOp](#oh_drawing_canvasclipop) clipOp, bool doAntiAlias) | Clips a path.| 
| void [OH_Drawing_CanvasRotate](#oh_drawing_canvasrotate) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, float degrees, float px, float py) | Rotates a canvas by a given angle. A positive number indicates a clockwise rotation, and a negative number indicates a counterclockwise rotation.| 
| void [OH_Drawing_CanvasTranslate](#oh_drawing_canvastranslate) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, float dx, float dy) | Translates a canvas by a given distance.| 
| void [OH_Drawing_CanvasScale](#oh_drawing_canvasscale) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, float sx, float sy) | Scales a canvas.| 
| void [OH_Drawing_CanvasClear](#oh_drawing_canvasclear) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, uint32_t color) | Clears a canvas by using a given color.| 
| int32_t [OH_Drawing_CanvasGetWidth](#oh_drawing_canvasgetwidth) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*) | Obtains the canvas width.| 
| int32_t [OH_Drawing_CanvasGetHeight](#oh_drawing_canvasgetheight) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*) | Obtains the canvas height.| 
| void [OH_Drawing_CanvasGetLocalClipBounds](#oh_drawing_canvasgetlocalclipbounds) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, [OH_Drawing_Rect](#oh_drawing_rect) \*) | Obtains the bounds of the cropping region of a canvas. This function cannot be used for recorded canvases.| 
| void [OH_Drawing_CanvasGetTotalMatrix](#oh_drawing_canvasgettotalmatrix) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, [OH_Drawing_Matrix](#oh_drawing_matrix) \*) | Obtains the 3x3 matrix of a canvas.| 
| void [OH_Drawing_CanvasConcatMatrix](#oh_drawing_canvasconcatmatrix) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, [OH_Drawing_Matrix](#oh_drawing_matrix) \*) | Preconcats the existing matrix with the passed-in matrix. The drawing operation triggered before this function is called is not affected.| 
| void [OH_Drawing_CanvasDrawShadow](#oh_drawing_canvasdrawshadow) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, [OH_Drawing_Path](#oh_drawing_path) \*, [OH_Drawing_Point3D](_o_h___drawing___point3_d.md) planeParams, [OH_Drawing_Point3D](_o_h___drawing___point3_d.md) devLightPos, float lightRadius, uint32_t ambientColor, uint32_t spotColor, [OH_Drawing_CanvasShadowFlags](#oh_drawing_canvasshadowflags) flag) | Draws an offset spot shadow and uses a given path to outline the ambient shadow.| 


## Type Description


### OH_Drawing_AlphaFormat

```
typedef enum OH_Drawing_AlphaFormat OH_Drawing_AlphaFormat
```

**Description**

Defines an enum for alpha formats of bitmap pixels.

**Since**: 8


### OH_Drawing_Bitmap

```
typedef struct OH_Drawing_Bitmap OH_Drawing_Bitmap
```

**Description**

Defines a struct for a bitmap, which is a memory area that contains the pixel data of a shape.

**Since**: 8


### OH_Drawing_BitmapFormat

```
typedef struct OH_Drawing_BitmapFormat OH_Drawing_BitmapFormat
```

**Description**

Defines a struct that describes the pixel format of a bitmap, including the color type and alpha type.

**Since**: 8


### OH_Drawing_BlendMode

```
typedef enum OH_Drawing_BlendMode OH_Drawing_BlendMode
```

**Description**

Defines an enum for blend modes. In blend mode, each operation generates a new color from two colors (source color and target color). These operations are the same on the four channels (red, green, blue, and alpha). The operations for the alpha channel are used as examples.

For brevity, the following abbreviations are used:

**s**: source.

**d**: destination.

**sa**: source alpha.

**da**: destination alpha.

The following abbreviations are used in the calculation result:

**r**: The calculation methods of the four channels are the same.

**ra**: Only the alpha channel is manipulated.

**rc**: The other three color channels are manipulated.

**Since**: 11


### OH_Drawing_BlurType

```
typedef enum OH_Drawing_BlurType OH_Drawing_BlurType
```

**Description**

Defines an enum for blur types.

**Since**: 11


### OH_Drawing_BreakStrategy

```
typedef enum OH_Drawing_BreakStrategy OH_Drawing_BreakStrategy
```

**Description**

Defines an enum for text break strategies.

**Since**: 11


### OH_Drawing_Brush

```
typedef struct OH_Drawing_Brush OH_Drawing_Brush
```

**Description**

Defines a struct for a brush, which is used to describe the style and color to fill in a shape.

**Since**: 8


### OH_Drawing_Canvas

```
typedef struct OH_Drawing_Canvas OH_Drawing_Canvas
```

**Description**

Defines a struct for a rectangular canvas, on which various shapes, images, and texts can be drawn by using the brush and pen.

**Since**: 8


### OH_Drawing_CanvasClipOp

```
typedef enum OH_Drawing_CanvasClipOp OH_Drawing_CanvasClipOp
```

**Description**

Defines an enum for canvas clipping modes.

**Since**: 11


### OH_Drawing_CanvasShadowFlags

```
typedef enum OH_Drawing_CanvasShadowFlags OH_Drawing_CanvasShadowFlags
```

**Description**

Defines an enum for canvas shadow flags.

**Since**: 12


### OH_Drawing_ColorFilter

```
typedef struct OH_Drawing_ColorFilter OH_Drawing_ColorFilter
```

**Description**

Defines a struct for a color filter, which is used to convert a color into a new one.

**Since**: 11


### OH_Drawing_ColorFormat

```
typedef enum OH_Drawing_ColorFormat OH_Drawing_ColorFormat
```

**Description**

Defines an enum for storage formats of bitmap pixels.

**Since**: 8


### OH_Drawing_EllipsisModal

```
typedef enum OH_Drawing_EllipsisModal OH_Drawing_EllipsisModal
```

**Description**

Defines an enum for ellipsis styles.

**Since**: 11


### OH_Drawing_Filter

```
typedef struct OH_Drawing_Filter OH_Drawing_Filter
```

**Description**

Defines a struct for a filter, which consists of a color filter and mask filter.

**Since**: 11


### OH_Drawing_FilterMode

```
typedef enum OH_Drawing_FilterMode OH_Drawing_FilterMode
```

**Description**

Defines an enum for filter modes.

**Since**: 12


### OH_Drawing_Font

```
typedef struct OH_Drawing_Font OH_Drawing_Font
```

**Description**

Defines a struct for a font.

**Since**: 11


### OH_Drawing_Font_Metrics

```
typedef struct OH_Drawing_Font_Metrics OH_Drawing_Font_Metrics
```

**Description**

Defines a struct that describes the measurement information about a font.

**Since**: 12


### OH_Drawing_FontCollection

```
typedef struct OH_Drawing_FontCollection OH_Drawing_FontCollection
```

**Description**

Defines a struct used to load fonts.

**Since**: 8


### OH_Drawing_FontDescriptor

```
typedef struct OH_Drawing_FontDescriptor OH_Drawing_FontDescriptor
```

**Description**

Defines a struct that describes the detailed information about a system font.

**Since**: 12


### OH_Drawing_FontParser

```
typedef struct OH_Drawing_FontParser OH_Drawing_FontParser
```

**Description**

Defines a struct used to parse system font files.

**Since**: 12


### OH_Drawing_Image

```
typedef struct OH_Drawing_Image OH_Drawing_Image
```

**Description**

Defines a struct for an image that describes a two-dimensional pixel array.

**Since**: 12


### OH_Drawing_Image_Info

```
typedef struct OH_Drawing_Image_Info OH_Drawing_Image_Info
```

**Description**

Defines a struct that describes the image information.

**Since**: 12


### OH_Drawing_LineMetrics

```
typedef struct OH_Drawing_LineMetrics OH_Drawing_LineMetrics
```

**Description**

Defines a struct that describes the measurement information about a line of text.

**Since**: 12


### OH_Drawing_MaskFilter

```
typedef struct OH_Drawing_MaskFilter OH_Drawing_MaskFilter
```

**Description**

Defines a struct for a mask filter, which is used to convert a mask into a new one.

**Since**: 11


### OH_Drawing_Matrix

```
typedef struct OH_Drawing_Matrix OH_Drawing_Matrix
```

**Description**

Defines a struct for a matrix, which is used to describe coordinate transformation.

**Since**: 11


### OH_Drawing_MemoryStream

```
typedef struct OH_Drawing_MemoryStream OH_Drawing_MemoryStream
```

**Description**

Defines a struct for a memory stream.

**Since**: 12


### OH_Drawing_MipmapMode

```
typedef enum OH_Drawing_MipmapMode OH_Drawing_MipmapMode
```

**Description**

Defines an enum for mipmap modes.

**Since**: 12


### OH_Drawing_Path

```
typedef struct OH_Drawing_Path OH_Drawing_Path
```

**Description**

Defines a struct for a path, which is used to customize various shapes.

**Since**: 8


### OH_Drawing_PathDirection

```
typedef enum OH_Drawing_PathDirection OH_Drawing_PathDirection
```

**Description**

Defines an enum for directions of a closed contour.

**Since**: 12


### OH_Drawing_PathEffect

```
typedef struct OH_Drawing_PathEffect OH_Drawing_PathEffect
```

**Description**

Defines a struct for a path effect that affects the stroke.

**Since**: 12


### OH_Drawing_PathFillType

```
typedef enum OH_Drawing_PathFillType OH_Drawing_PathFillType
```

**Description**

Defines an enum for fill types of a path.

**Since**: 12


### OH_Drawing_Pen

```
typedef struct OH_Drawing_Pen OH_Drawing_Pen
```

**Description**

Defines a struct for a pen, which is used to describe the style and color to outline a shape.

**Since**: 8


### OH_Drawing_PenLineCapStyle

```
typedef enum OH_Drawing_PenLineCapStyle OH_Drawing_PenLineCapStyle
```

**Description**

Defines an enum for line cap styles of a pen. The line cap style defines the style of both ends of a line segment drawn by the pen.

**Since**: 8


### OH_Drawing_PenLineJoinStyle

```
typedef enum OH_Drawing_PenLineJoinStyle OH_Drawing_PenLineJoinStyle
```

**Description**

Defines an enum for line join styles of a pen. The line join style defines the shape of the joints of a polyline segment drawn by the pen.

**Since**: 8


### OH_Drawing_PlaceholderSpan

```
typedef struct OH_Drawing_PlaceholderSpan OH_Drawing_PlaceholderSpan
```

**Description**

Defines a struct for a placeholder that acts as a span.

**Since**: 11


### OH_Drawing_PlaceholderVerticalAlignment

```
typedef enum OH_Drawing_PlaceholderVerticalAlignment OH_Drawing_PlaceholderVerticalAlignment
```

**Description**

Defines an enum for vertical alignment modes of placeholders.

**Since**: 11


### OH_Drawing_Point

```
typedef struct OH_Drawing_Point OH_Drawing_Point
```

**Description**

Defines a struct for a coordinate point.

**Since**: 11


### OH_Drawing_Point2D

```
typedef struct OH_Drawing_Point2D OH_Drawing_Point2D
```

**Description**

Defines a struct for a two-dimensional coordinate point.

**Since**: 12


### OH_Drawing_Point3D

```
typedef struct OH_Drawing_Point3D OH_Drawing_Point3D
```

**Description**

Defines a struct for a three-dimensional coordinate point.

**Since**: 12


### OH_Drawing_PositionAndAffinity

```
typedef struct OH_Drawing_PositionAndAffinity OH_Drawing_PositionAndAffinity
```

**Description**

Defines a struct used to receive the position and affinity of the graph.

**Since**: 11


### OH_Drawing_Range

```
typedef struct OH_Drawing_Range OH_Drawing_Range
```

**Description**

Defines a struct for a range, which is used to receive the start position and end position of the font.

**Since**: 11


### OH_Drawing_Rect

```
typedef struct OH_Drawing_Rect OH_Drawing_Rect
```

**Description**

Defines a struct for a rectangle.

**Since**: 11


### OH_Drawing_RectHeightStyle

```
typedef enum OH_Drawing_RectHeightStyle OH_Drawing_RectHeightStyle
```

**Description**

Defines an enum for rectangle height styles.

**Since**: 11


### OH_Drawing_RectWidthStyle

```
typedef enum OH_Drawing_RectWidthStyle OH_Drawing_RectWidthStyle
```

**Description**

Defines an enum for rectangle width styles.

**Since**: 11


### OH_Drawing_RoundRect

```
typedef struct OH_Drawing_RoundRect OH_Drawing_RoundRect
```

**Description**

Defines a struct for a rounded rectangle.

**Since**: 11


### OH_Drawing_RunBuffer

```
typedef struct OH_Drawing_RunBuffer OH_Drawing_RunBuffer
```

**Description**

Defines a struct that describes a run, which provides storage for glyphs and positions.

**Since**: 11


### OH_Drawing_SamplingOptions

```
typedef struct OH_Drawing_SamplingOptions OH_Drawing_SamplingOptions
```

**Description**

Defines a struct for sampling options, which describe the sampling methods for images and bitmaps.

**Since**: 12


### OH_Drawing_ShaderEffect

```
typedef struct OH_Drawing_ShaderEffect OH_Drawing_ShaderEffect
```

**Description**

Defines a struct for a shader effect, which is used to describe the source color of the drawn content.

**Since**: 11


### OH_Drawing_TextBlob

```
typedef struct OH_Drawing_TextBlob OH_Drawing_TextBlob
```

**Description**

Defines a struct for a text blob, an immutable container that holds multiple texts. Each text blob consists of glyphs and position.

**Since**: 11


### OH_Drawing_TextBlobBuilder

```
typedef struct OH_Drawing_TextBlobBuilder OH_Drawing_TextBlobBuilder
```

**Description**

Defines a struct for a text blob builder, which is used to build a text blob.

**Since**: 11


### OH_Drawing_TextBox

```
typedef struct OH_Drawing_TextBox OH_Drawing_TextBox
```

**Description**

Defines a struct for a text box, which is used to receive the rectangle size, direction, and quantity.

**Since**: 11


### OH_Drawing_TextDecorationStyle

```
typedef enum OH_Drawing_TextDecorationStyle OH_Drawing_TextDecorationStyle
```

**Description**

Defines an enum for text decoration styles.

**Since**: 11


### OH_Drawing_TextEncoding

```
typedef enum OH_Drawing_TextEncoding OH_Drawing_TextEncoding
```

**Description**

Defines an enum for text encoding types.

**Since**: 12


### OH_Drawing_TextShadow

```
typedef struct OH_Drawing_TextShadow OH_Drawing_TextShadow
```

**Description**

Defines a struct used to manage text shadows.

**Since**: 12


### OH_Drawing_TextStyle

```
typedef struct OH_Drawing_TextStyle OH_Drawing_TextStyle
```

**Description**

Defines a struct used to manage text colors and decorations.

**Since**: 8


### OH_Drawing_TileMode

```
typedef enum OH_Drawing_TileMode OH_Drawing_TileMode
```

**Description**

Defines an enum for tile modes of the shader effect.

**Since**: 11


### OH_Drawing_Typeface

```
typedef struct OH_Drawing_Typeface OH_Drawing_Typeface
```

**Description**

Defines a struct for a typeface.

**Since**: 11


### OH_Drawing_Typography

```
typedef struct OH_Drawing_Typography OH_Drawing_Typography
```

**Description**

Defines a struct used to manage the typography layout and display.

**Since**: 8


### OH_Drawing_TypographyCreate

```
typedef struct OH_Drawing_TypographyCreate OH_Drawing_TypographyCreate
```

**Description**

Defines a struct used to create an [OH_Drawing_Typography](#oh_drawing_typography) object.

**Since**: 8


### OH_Drawing_TypographyStyle

```
typedef struct OH_Drawing_TypographyStyle OH_Drawing_TypographyStyle
```

**Description**

Defines a struct used to manage the typography style, such as the text direction.

**Since**: 8


### OH_Drawing_WordBreakType

```
typedef enum OH_Drawing_WordBreakType OH_Drawing_WordBreakType
```

**Description**

Defines an enum for word break types.

**Since**: 11


## Enum Description


### OH_Drawing_AlphaFormat

```
enum OH_Drawing_AlphaFormat
```

**Description**

Enumerates the alpha formats of bitmap pixels.

**Since**: 8

| Value| Description| 
| -------- | -------- |
| ALPHA_FORMAT_UNKNOWN | Unknown format.| 
| ALPHA_FORMAT_OPAQUE | The bitmap does not have the alpha component.| 
| ALPHA_FORMAT_PREMUL | The color component of each pixel is premultiplied by the alpha component.| 
| ALPHA_FORMAT_UNPREMUL | The color component of each pixel is not premultiplied by the alpha component.| 


### OH_Drawing_BlendMode

```
enum OH_Drawing_BlendMode
```

**Description**

Enumerates the blend modes. In blend mode, each operation generates a new color from two colors (source color and target color). These operations are the same on the four channels (red, green, blue, and alpha). The operations for the alpha channel are used as examples.

For brevity, the following abbreviations are used:

**s**: source.

**d**: destination.

**sa**: source alpha.

**da**: destination alpha.

The following abbreviations are used in the calculation result:

**r**: The calculation methods of the four channels are the same.

**ra**: Only the alpha channel is manipulated.

**rc**: The other three color channels are manipulated.

**Since**: 11

| Value| Description| 
| -------- | -------- |
| BLEND_MODE_CLEAR | Clear mode. r = 0.| 
| BLEND_MODE_SRC | r = s (The four channels of **result** are equal to the four channels of **source**, that is, the result is equal to the source.)| 
| BLEND_MODE_DST | r = d (The four channels of **result** are equal to the four channels of **destination**, that is, the result is equal to the destination.)| 
| BLEND_MODE_SRC_OVER | r = s + (1 - sa) \* d. | 
| BLEND_MODE_DST_OVER | r = d + (1 - da) \* s. | 
| BLEND_MODE_SRC_IN | r = s \* da. | 
| BLEND_MODE_DST_IN | r = d \* sa. | 
| BLEND_MODE_SRC_OUT | r = s \* (1 - da). | 
| BLEND_MODE_DST_OUT | r = d \* (1 - sa). | 
| BLEND_MODE_SRC_ATOP | r = s \* da + d \* (1 - sa). | 
| BLEND_MODE_DST_ATOP | r = d \* sa + s \* (1 - da). | 
| BLEND_MODE_XOR | r = s \* (1 - da) + d \* (1 - sa). | 
| BLEND_MODE_PLUS | r = min(s + d, 1). | 
| BLEND_MODE_MODULATE | r = s \* d. | 
| BLEND_MODE_SCREEN | Screen mode. r = s + d - s \* d| 
| BLEND_MODE_OVERLAY | Overlay mode.| 
| BLEND_MODE_DARKEN | Darken mode. rc = s + d - max(s \* da, d \* sa), ra = s + (1 - sa) \* d| 
| BLEND_MODE_LIGHTEN | Lighten mode. rc = s + d - min(s \* da, d \* sa), ra = s + (1 - sa) \* d| 
| BLEND_MODE_COLOR_DODGE | Color dodge mode.| 
| BLEND_MODE_COLOR_BURN | Color burn mode.| 
| BLEND_MODE_HARD_LIGHT | Hard light mode.| 
| BLEND_MODE_SOFT_LIGHT | Soft light mode.| 
| BLEND_MODE_DIFFERENCE | Difference mode. rc = s + d - 2 \* (min(s \* da, d \* sa)), ra = s + (1 - sa) \* d| 
| BLEND_MODE_EXCLUSION | Exclusion mode. rc = s + d - two(s \* d), ra = s + (1 - sa) \* d| 
| BLEND_MODE_MULTIPLY | Multiply mode. r = s \* (1 - da) + d \* (1 - sa) + s \* d| 
| BLEND_MODE_HUE | Hue mode.| 
| BLEND_MODE_SATURATION | Saturation mode.| 
| BLEND_MODE_COLOR | Color mode.| 
| BLEND_MODE_LUMINOSITY | Luminosity mode.| 


### OH_Drawing_BlurType

```
enum OH_Drawing_BlurType
```

**Description**

Enumerates the blur types.

**Since**: 11

| Value| Description| 
| -------- | -------- |
| NORMAL | Blurs both inside and outside the original border.| 
| SOLID | Draws solid inside the border, and blurs outside.| 
| OUTER | Draws nothing inside the border, and blurs outside.| 
| INNER | Blurs inside the border, and draws nothing outside.| 


### OH_Drawing_BreakStrategy

```
enum OH_Drawing_BreakStrategy
```

**Description**

Enumerates the text break strategies.

**Since**: 11

| Value| Description| 
| -------- | -------- |
| BREAK_STRATEGY_GREEDY | Each line is filled as much as possible during line break.| 
| BREAK_STRATEGY_HIGH_QUALITY | Text continuity is preferentially considered during line break.| 
| BREAK_STRATEGY_BALANCED | Line breaks are performed at the word boundary.| 


### OH_Drawing_CanvasClipOp

```
enum OH_Drawing_CanvasClipOp
```

**Description**

Enumerates the canvas clipping modes.

**Since**: 11

| Value| Description| 
| -------- | -------- |
| DIFFERENCE | Clips a specified area. That is, the difference set is obtained.| 
| INTERSECT | Retains a specified area. That is, the intersection is obtained.| 


### OH_Drawing_CanvasShadowFlags

```
enum OH_Drawing_CanvasShadowFlags
```

**Description**

Enumerates the canvas shadow flags.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| SHADOW_FLAGS_NONE | There is no shadow flag.| 
| SHADOW_FLAGS_TRANSPARENT_OCCLUDER | The occluding object is transparent.| 
| SHADOW_FLAGS_GEOMETRIC_ONLY | No analysis on the shadows is required.| 
| SHADOW_FLAGS_ALL | All the preceding shadow flags are used.| 


### OH_Drawing_ColorFormat

```
enum OH_Drawing_ColorFormat
```

**Description**

Enumerates the storage formats of bitmap pixels.

**Since**: 8

| Value| Description| 
| -------- | -------- |
| COLOR_FORMAT_UNKNOWN | Unknown format.| 
| COLOR_FORMAT_ALPHA_8 | Each pixel is represented by 8 bits, which together indicate alpha.| 
| COLOR_FORMAT_RGB_565 | Each pixel is represented by 16 bits. From the most significant bit to the least significant bit, the first 5 bits indicate red, the subsequent 6 bits indicate green, and the last 5 bits indicate blue.| 
| COLOR_FORMAT_ARGB_4444 | Each pixel is represented by 16 bits. From the most significant bit to the least significant bit, every 4 bits indicate alpha, red, green, and blue, respectively.| 
| COLOR_FORMAT_RGBA_8888 | Each pixel is represented by 32 bits. From the most significant bit to the least significant bit, every 8 bits indicate alpha, red, green, and blue, respectively.| 
| COLOR_FORMAT_BGRA_8888 | Each pixel is represented by 32 bits. From the most significant bit to the least significant bit, every 8 bits indicate blue, green, red, and alpha, respectively.| 


### OH_Drawing_EllipsisModal

```
enum OH_Drawing_EllipsisModal
```

**Description**

Enumerates the ellipsis styles.

**Since**: 11

| Value| Description| 
| -------- | -------- |
| ELLIPSIS_MODAL_HEAD | Places the ellipsis in the text header.| 
| ELLIPSIS_MODAL_MIDDLE | Places the ellipsis in the middle of the text.| 
| ELLIPSIS_MODAL_TAIL | Places the ellipsis at the end of the text.| 


### OH_Drawing_FilterMode

```
enum OH_Drawing_FilterMode
```

**Description**

Enumerates the filter modes.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| FILTER_MODE_NEAREST | Nearest filter mode.| 
| FILTER_MODE_LINEAR | Linear filter mode.| 


### OH_Drawing_FontStyle

```
enum OH_Drawing_FontStyle
```

**Description**

Enumerates the font styles.

| Value| Description| 
| -------- | -------- |
| FONT_STYLE_NORMAL | Normal style.| 
| FONT_STYLE_ITALIC | Italic.| 


### OH_Drawing_FontWeight

```
enum OH_Drawing_FontWeight
```

**Description**

Enumerates the font weights.

| Value| Description| 
| -------- | -------- |
| FONT_WEIGHT_100 | Thin.| 
| FONT_WEIGHT_200 | Extra-light.| 
| FONT_WEIGHT_300 | Light.| 
| FONT_WEIGHT_400 | Normal/Regular.| 
| FONT_WEIGHT_500 | Medium.| 
| FONT_WEIGHT_600 | Semi-bold.| 
| FONT_WEIGHT_700 | Bold.| 
| FONT_WEIGHT_800 | Extra-bold.| 
| FONT_WEIGHT_900 | Black.| 


### OH_Drawing_MipmapMode

```
enum OH_Drawing_MipmapMode
```

**Description**

Enumerates the mipmap modes.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| MIPMAP_MODE_NONE | Mipmap level ignored.| 
| MIPMAP_MODE_NEAREST | Nearest sampling from two adjacent mipmap levels.| 
| MIPMAP_MODE_LINEAR | Linear interpolation sampling between two adjacent mipmap levels.| 


### OH_Drawing_PathDirection

```
enum OH_Drawing_PathDirection
```

**Description**

Enumerates the directions of a closed contour.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| PATH_DIRECTION_CW | Adds a closed contour clockwise.| 
| PATH_DIRECTION_CCW | Adds a closed contour counterclockwise.| 


### OH_Drawing_PathFillType

```
enum OH_Drawing_PathFillType
```

**Description**

Enumerates the fill types of a path.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| PATH_FILL_TYPE_WINDING | Draws inside of the area surrounded by all line segments.| 
| PATH_FILL_TYPE_EVEN_ODD | Draws inside of the area surrounded by all line segments by odd times.| 
| PATH_FILL_TYPE_INVERSE_WINDING | Same as **PATH_FILL_TYPE_WINDING**, but draws outside of the area surrounded by all line segments.| 
| PATH_FILL_TYPE_INVERSE_EVEN_ODD | Same as **PATH_FILL_TYPE_EVEN_ODD**, but draws outside of the area surrounded by all line segments by odd times.| 


### OH_Drawing_PenLineCapStyle

```
enum OH_Drawing_PenLineCapStyle
```

**Description**

Enumerates the line cap styles of a pen. The line cap style defines the style of both ends of a line segment drawn by the pen.

**Since**: 8

| Value| Description| 
| -------- | -------- |
| LINE_FLAT_CAP | There is no cap style. Both ends of the line segment are cut off square.| 
| LINE_SQUARE_CAP | Square cap style. Both ends have a square, the height of which is half of the width of the line segment, with the same width.| 
| LINE_ROUND_CAP | Round cap style. Both ends have a semicircle centered, the diameter of which is the same as the width of the line segment.| 


### OH_Drawing_PenLineJoinStyle

```
enum OH_Drawing_PenLineJoinStyle
```

**Description**

Enumerates the line join styles of a pen. The line join style defines the shape of the joints of a polyline segment drawn by the pen.

**Since**: 8

| Value| Description| 
| -------- | -------- |
| LINE_MITER_JOIN | Mitered corner. If the angle of a polyline is small, its miter length may be inappropriate. In this case, you need to use the miter limit to limit the miter length.| 
| LINE_ROUND_JOIN | Round corner.| 
| LINE_BEVEL_JOIN | Beveled corner.| 


### OH_Drawing_PlaceholderVerticalAlignment

```
enum OH_Drawing_PlaceholderVerticalAlignment
```

**Description**

Enumerates the vertical alignment modes of placeholders.

**Since**: 11

| Value| Description| 
| -------- | -------- |
| ALIGNMENT_OFFSET_AT_BASELINE | Aligned to the baseline.| 
| ALIGNMENT_ABOVE_BASELINE | Aligned above the baseline.| 
| ALIGNMENT_BELOW_BASELINE | Aligned below the baseline.| 
| ALIGNMENT_TOP_OF_ROW_BOX | Aligned to the top of the row box.| 
| ALIGNMENT_BOTTOM_OF_ROW_BOX | Aligned to the bottom of the row box.| 
| ALIGNMENT_CENTER_OF_ROW_BOX | Aligned to the center of the row box.| 


### OH_Drawing_RectHeightStyle

```
enum OH_Drawing_RectHeightStyle
```

**Description**

Enumerates the rectangle height styles.

**Since**: 11

| Value| Description| 
| -------- | -------- |
| RECT_HEIGHT_STYLE_TIGHT | Tight style.| 
| RECT_HEIGHT_STYLE_MAX | Maximum style.| 
| RECT_HEIGHT_STYLE_INCLUDELINESPACEMIDDLE | Middle style that includes the line spacing.| 
| RECT_HEIGHT_STYLE_INCLUDELINESPACETOP | Top style that includes the line spacing.| 
| RECT_HEIGHT_STYLE_INCLUDELINESPACEBOTTOM | Bottom style that includes the line spacing.| 
| RECT_HEIGHT_STYLE_STRUCT | Structure style.| 


### OH_Drawing_RectWidthStyle

```
enum OH_Drawing_RectWidthStyle
```

**Description**

Enumerates the rectangle width styles.

**Since**: 11

| Value| Description| 
| -------- | -------- |
| RECT_WIDTH_STYLE_TIGHT | Tight style.| 
| RECT_WIDTH_STYLE_MAX | Maximum style.| 


### OH_Drawing_TextAlign

```
enum OH_Drawing_TextAlign
```

**Description**

Enumerates the text alignment modes.

| Value| Description| 
| -------- | -------- |
| TEXT_ALIGN_LEFT | Left-aligned.| 
| TEXT_ALIGN_RIGHT | Right-aligned.| 
| TEXT_ALIGN_CENTER | Center-aligned.| 
| TEXT_ALIGN_JUSTIFY | Justified, which means that each line (except the last line) is stretched so that every line has equal width, and the left and right margins are straight.| 
| TEXT_ALIGN_START | **TEXT_ALIGN_START** achieves the same effect as **TEXT_ALIGN_LEFT** when **OH_Drawing_TextDirection** is **TEXT_DIRECTION_LTR**; it achieves the same effect as **TEXT_ALIGN_RIGHT** when **OH_Drawing_TextDirection** is **TEXT_DIRECTION_RTL**.| 
| TEXT_ALIGN_END | **TEXT_ALIGN_END** achieves the same effect as **TEXT_ALIGN_RIGHT** when **OH_Drawing_TextDirection** is **TEXT_DIRECTION_LTR**; it achieves the same effect as **TEXT_ALIGN_LEFT** when **OH_Drawing_TextDirection** is **TEXT_DIRECTION_RTL**.| 


### OH_Drawing_TextBaseline

```
enum OH_Drawing_TextBaseline
```

**Description**

Enumerates the text baselines.

| Value| Description| 
| -------- | -------- |
| TEXT_BASELINE_ALPHABETIC | Alphabetic, where the letters in alphabets like English sit on.| 
| TEXT_BASELINE_IDEOGRAPHIC | Ideographic. The baseline is at the bottom of the text area.| 


### OH_Drawing_TextDecoration

```
enum OH_Drawing_TextDecoration
```

**Description**

Enumerates the text decorations.

| Value| Description| 
| -------- | -------- |
| TEXT_DECORATION_NONE | No decoration.| 
| TEXT_DECORATION_UNDERLINE | An underline is used for decoration.| 
| TEXT_DECORATION_OVERLINE | An overline is used for decoration.| 
| TEXT_DECORATION_LINE_THROUGH | A strikethrough is used for decoration.| 


### OH_Drawing_TextDecorationStyle

```
enum OH_Drawing_TextDecorationStyle
```

**Description**

Enumerates the text decoration styles.

**Since**: 11

| Value| Description| 
| -------- | -------- |
| TEXT_DECORATION_STYLE_SOLID | Solid style.| 
| TEXT_DECORATION_STYLE_DOUBLE | Double style.| 
| TEXT_DECORATION_STYLE_DOTTED | Dotted style.| 
| TEXT_DECORATION_STYLE_DASHED | Dashed style.| 
| TEXT_DECORATION_STYLE_WAVY | Wavy style.| 


### OH_Drawing_TextDirection

```
enum OH_Drawing_TextDirection
```

**Description**

Enumerates the text directions.

| Value| Description| 
| -------- | -------- |
| TEXT_DIRECTION_RTL | Right to left (RTL).| 
| TEXT_DIRECTION_LTR | Left to right (LTR).| 


### OH_Drawing_TextEncoding

```
enum OH_Drawing_TextEncoding
```

**Description**

Enumerates the text encoding types.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| TEXT_ENCODING_UTF8 | One byte used to indicate UTF-8 or ASCII characters.| 
| TEXT_ENCODING_UTF16 | Two bytes used to indicate most Unicode characters.| 
| TEXT_ENCODING_UTF32 | Four bytes used to indicate all Unicode characters.| 
| TEXT_ENCODING_GLYPH_ID | Two bytes used to indicate the glyph index.| 


### OH_Drawing_TileMode

```
enum OH_Drawing_TileMode
```

**Description**

Enumerates the tile modes of the shader effect.

**Since**: 11

| Value| Description| 
| -------- | -------- |
| CLAMP | Replicates the edge color if the shader effect draws outside of its original boundary.| 
| REPEAT | Repeats the shader effect's image in both horizontal and vertical directions.| 
| MIRROR | Repeats the shader effect's image in both horizontal and vertical directions, alternating mirror images.| 
| DECAL | Renders the shader effect's image only within the original boundary, and returns transparent black elsewhere.| 


### OH_Drawing_WordBreakType

```
enum OH_Drawing_WordBreakType
```

**Description**

Enumerates the word break types.

**Since**: 11

| Value| Description| 
| -------- | -------- |
| WORD_BREAK_TYPE_NORMAL | Normal mode.| 
| WORD_BREAK_TYPE_BREAK_ALL | Breaks the words at any character to prevent overflow.| 
| WORD_BREAK_TYPE_BREAK_WORD | Breaks the words at arbitrary points to prevent overflow.| 


## Function Description


### OH_Drawing_BitmapBuild()

```
void OH_Drawing_BitmapBuild (OH_Drawing_Bitmap* , const uint32_t width, const uint32_t height, const OH_Drawing_BitmapFormat*  )
```

**Description**

Initializes the width and height of a bitmap and sets the pixel format for the bitmap.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Bitmap | Pointer to an **OH_Drawing_Bitmap** object.| 
| width | Width of the bitmap to be initialized.| 
| height | Height of the bitmap to be initialized.| 
| [OH_Drawing_BitmapFormat](_o_h___drawing___bitmap_format.md) | Pointer to the pixel format of the bitmap to be initialized, including the pixel color type and alpha type.| 


### OH_Drawing_BitmapCreate()

```
OH_Drawing_Bitmap* OH_Drawing_BitmapCreate (void )
```

**Description**

Creates an **OH_Drawing_Bitmap** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Returns**

Returns the pointer to the **OH_Drawing_Bitmap** object created.


### OH_Drawing_BitmapCreateFromPixels()

```
OH_Drawing_Bitmap* OH_Drawing_BitmapCreateFromPixels (OH_Drawing_Image_Info* , void* pixels, uint32_t rowBytes )
```

**Description**

Creates an **OH_Drawing_Bitmap** object, with the address of the memory for storing the bitmap pixels set to the memory address that you applied for.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| [OH_Drawing_Image_Info](_o_h___drawing___image___info.md) | Pointer to an [OH_Drawing_Image_Info](_o_h___drawing___image___info.md) object.| 
| pixels | Pointer to the start address of the memory for storing the bitmap pixels. You need to apply for the memory and ensure its validity.| 
| rowBytes | Size of pixels per row.| 

**Returns**

Returns the pointer to the [OH_Drawing_Bitmap](#oh_drawing_bitmap) object created.


### OH_Drawing_BitmapDestroy()

```
void OH_Drawing_BitmapDestroy (OH_Drawing_Bitmap* )
```

**Description**

Destroys an **OH_Drawing_Bitmap** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Bitmap | Pointer to an **OH_Drawing_Bitmap** object.| 


### OH_Drawing_BitmapGetHeight()

```
uint32_t OH_Drawing_BitmapGetHeight (OH_Drawing_Bitmap* )
```

**Description**

Obtains the height of a bitmap.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Bitmap | Pointer to an **OH_Drawing_Bitmap** object.| 

**Returns**

Returns the height.


### OH_Drawing_BitmapGetPixels()

```
void* OH_Drawing_BitmapGetPixels (OH_Drawing_Bitmap* )
```

**Description**

Obtains the pixel address of a bitmap. You can use this address to obtain the pixel data of the bitmap.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Bitmap | Pointer to an **OH_Drawing_Bitmap** object.| 

**Returns**

Returns the pixel address.


### OH_Drawing_BitmapGetWidth()

```
uint32_t OH_Drawing_BitmapGetWidth (OH_Drawing_Bitmap* )
```

**Description**

Obtains the width of a bitmap.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Bitmap | Pointer to an **OH_Drawing_Bitmap** object.| 

**Returns**

Returns the width.


### OH_Drawing_BrushCreate()

```
OH_Drawing_Brush* OH_Drawing_BrushCreate (void )
```

**Description**

Creates an **OH_Drawing_Brush** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Returns**

Returns the pointer to the **OH_Drawing_Brush** object created.


### OH_Drawing_BrushDestroy()

```
void OH_Drawing_BrushDestroy (OH_Drawing_Brush* )
```

**Description**

Destroys an **OH_Drawing_Brush** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Brush | Pointer to an **OH_Drawing_Brush** object.| 


### OH_Drawing_BrushGetAlpha()

```
uint8_t OH_Drawing_BrushGetAlpha (const OH_Drawing_Brush* )
```

**Description**

Obtains the alpha value of a brush. This value is used by the alpha channel when the brush fills in a shape.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Brush | Pointer to an **OH_Drawing_Brush** object.| 

**Returns**

Returns an 8-bit variable that describes the alpha value.


### OH_Drawing_BrushGetColor()

```
uint32_t OH_Drawing_BrushGetColor (const OH_Drawing_Brush* )
```

**Description**

Obtains the color of a brush. The color is used by the brush to fill in a shape.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Brush | Pointer to an **OH_Drawing_Brush** object.| 

**Returns**

Returns a 32-bit (ARGB) variable that describes the color.


### OH_Drawing_BrushIsAntiAlias()

```
bool OH_Drawing_BrushIsAntiAlias (const OH_Drawing_Brush* )
```

**Description**

Checks whether anti-aliasing is enabled for a brush. Anti-aliasing makes the pixels around the shape edges semi-transparent.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Brush | Pointer to an **OH_Drawing_Brush** object.| 

**Returns**

Returns **true** if anti-aliasing is enabled; returns **false** otherwise.


### OH_Drawing_BrushSetAlpha()

```
void OH_Drawing_BrushSetAlpha (OH_Drawing_Brush* , uint8_t alpha )
```

**Description**

Sets the alpha value for a brush. This value is used by the alpha channel when the brush fills in a shape.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Brush | Pointer to an **OH_Drawing_Brush** object.| 
| alpha | Alpha value, which is an 8-bit variable.| 


### OH_Drawing_BrushSetAntiAlias()

```
void OH_Drawing_BrushSetAntiAlias (OH_Drawing_Brush* , bool  )
```

**Description**

Enables or disables anti-aliasing for a brush. Anti-aliasing makes the pixels around the shape edges semi-transparent.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Brush | Pointer to an **OH_Drawing_Brush** object.| 
| bool | Whether to enable anti-aliasing. The value **true** means to enable anti-aliasing, and **false** means the opposite.| 


### OH_Drawing_BrushSetBlendMode()

```
void OH_Drawing_BrushSetBlendMode (OH_Drawing_Brush* , OH_Drawing_BlendMode  )
```

**Description**

Sets a blender for a brush. The blender implements the specified blend mode.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Brush | Pointer to an [OH_Drawing_Brush](#oh_drawing_brush) object.| 
| OH_Drawing_BlendMode | Blend mode. For details about the available options, see [OH_Drawing_BlendMode](#oh_drawing_blendmode).| 


### OH_Drawing_BrushSetColor()

```
void OH_Drawing_BrushSetColor (OH_Drawing_Brush* , uint32_t color )
```

**Description**

Sets the color for a brush. The color is used by the brush to fill in a shape.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Brush | Pointer to an **OH_Drawing_Brush** object.| 
| color | Color, which is a 32-bit (ARGB) variable.| 


### OH_Drawing_BrushSetFilter()

```
void OH_Drawing_BrushSetFilter (OH_Drawing_Brush* , OH_Drawing_Filter*  )
```

**Description**

Sets a filter for a brush. The filter is a container that holds a mask filter and color filter.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Brush | Pointer to an **OH_Drawing_Brush** object.| 
| OH_Drawing_Filter | Pointer to an **OH_Drawing_Filter** object.| 


### OH_Drawing_BrushSetShaderEffect()

```
void OH_Drawing_BrushSetShaderEffect (OH_Drawing_Brush* , OH_Drawing_ShaderEffect*  )
```

**Description**

Sets the shader effect for a brush.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Brush | Pointer to an **OH_Drawing_Brush** object.| 
| OH_Drawing_ShaderEffect | Pointer to an **OH_Drawing_ShaderEffect** object.| 


### OH_Drawing_CanvasAttachBrush()

```
void OH_Drawing_CanvasAttachBrush (OH_Drawing_Canvas* , const OH_Drawing_Brush*  )
```

**Description**

Attaches a brush to a canvas so that the canvas can use the style and color of the brush to fill in a shape.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object.| 
| OH_Drawing_Brush | Pointer to an **OH_Drawing_Brush** object.| 


### OH_Drawing_CanvasAttachPen()

```
void OH_Drawing_CanvasAttachPen (OH_Drawing_Canvas* , const OH_Drawing_Pen*  )
```

**Description**

Attaches a pen to a canvas so that the canvas can use the style and color of the pen to outline a shape.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object.| 
| OH_Drawing_Pen | Pointer to an **OH_Drawing_Pen** object.| 


### OH_Drawing_CanvasBind()

```
void OH_Drawing_CanvasBind (OH_Drawing_Canvas* , OH_Drawing_Bitmap*  )
```

**Description**

Binds a bitmap to a canvas so that the content drawn on the canvas is output to the bitmap. (This process is called CPU rendering.)

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object.| 
| OH_Drawing_Bitmap | Pointer to an **OH_Drawing_Bitmap** object.| 


### OH_Drawing_CanvasClear()

```
void OH_Drawing_CanvasClear (OH_Drawing_Canvas* , uint32_t color )
```

**Description**

Clears a canvas by using a given color.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object.| 
| color | Color, which is a 32-bit (ARGB) variable.| 


### OH_Drawing_CanvasClipPath()

```
void OH_Drawing_CanvasClipPath (OH_Drawing_Canvas* , const OH_Drawing_Path* , OH_Drawing_CanvasClipOp clipOp, bool doAntiAlias )
```

**Description**

Clips a path.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object.| 
| OH_Drawing_Path | Pointer to an **OH_Drawing_Path** object.| 
| clipOp | Clip mode. For details about the available options, see [OH_Drawing_CanvasClipOp](#oh_drawing_canvasclipop).| 
| doAntiAlias | Whether to enable anti-aliasing. The value **true** means to enable anti-aliasing, and **false** means the opposite.| 


### OH_Drawing_CanvasClipRect()

```
void OH_Drawing_CanvasClipRect (OH_Drawing_Canvas* , const OH_Drawing_Rect* , OH_Drawing_CanvasClipOp clipOp, bool doAntiAlias )
```

**Description**

Clips a rectangle.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object.| 
| OH_Drawing_Rect | Pointer to an **OH_Drawing_Rect** object.| 
| clipOp | Clip mode. For details about the available options, see [OH_Drawing_CanvasClipOp](#oh_drawing_canvasclipop).| 
| doAntiAlias | Whether to enable anti-aliasing. The value **true** means to enable anti-aliasing, and **false** means the opposite.| 


### OH_Drawing_CanvasConcatMatrix()

```
void OH_Drawing_CanvasConcatMatrix (OH_Drawing_Canvas* , OH_Drawing_Matrix*  )
```

**Description**

Preconcats the existing matrix with the passed-in matrix. The drawing operation triggered before this function is called is not affected.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an [OH_Drawing_Canvas](#oh_drawing_canvas) object.| 
| OH_Drawing_Matrix | Pointer to an [OH_Drawing_Matrix](#oh_drawing_matrix) object.| 


### OH_Drawing_CanvasCreate()

```
OH_Drawing_Canvas* OH_Drawing_CanvasCreate (void )
```

**Description**

Creates an **OH_Drawing_Canvas** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Returns**

Returns the pointer to the **OH_Drawing_Canvas** object created.


### OH_Drawing_CanvasDestroy()

```
void OH_Drawing_CanvasDestroy (OH_Drawing_Canvas* )
```

**Description**

Destroys an **OH_Drawing_Canvas** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object.| 


### OH_Drawing_CanvasDetachBrush()

```
void OH_Drawing_CanvasDetachBrush (OH_Drawing_Canvas* )
```

**Description**

Detaches the brush from a canvas so that the canvas can no longer use the style and color of the brush to fill in a shape.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object.| 


### OH_Drawing_CanvasDetachPen()

```
void OH_Drawing_CanvasDetachPen (OH_Drawing_Canvas* )
```

**Description**

Detaches the pen from a canvas so that the canvas can no longer use the style and color of the pen to outline a shape.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object.| 


### OH_Drawing_CanvasDrawArc()

```
void OH_Drawing_CanvasDrawArc (OH_Drawing_Canvas* , const OH_Drawing_Rect* , float startAngle, float sweepAngle )
```

**Description**

Draws an arc.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object.| 
| OH_Drawing_Rect | Pointer to an **OH_Drawing_Rect** object.| 
| startAngle | Start angle of the arc.| 
| sweepAngle | Sweep angle of the arc.| 


### OH_Drawing_CanvasDrawBitmap()

```
void OH_Drawing_CanvasDrawBitmap (OH_Drawing_Canvas* , const OH_Drawing_Bitmap* , float left, float top )
```

**Description**

Draws a bitmap. A bitmap, also referred to as a dot matrix image, a pixel map image, or a grid image, includes single points called pixels (image elements).

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object.| 
| OH_Drawing_Bitmap | Pointer to an **OH_Drawing_Bitmap** object.| 
| left | X coordinate of the upper left corner of the bitmap.| 
| top | Y coordinate of the upper left corner of the bitmap.| 


### OH_Drawing_CanvasDrawBitmapRect()

```
void OH_Drawing_CanvasDrawBitmapRect (OH_Drawing_Canvas* , const OH_Drawing_Bitmap* , const OH_Drawing_Rect* src, const OH_Drawing_Rect* dst, const OH_Drawing_SamplingOptions*  )
```

**Description**

Draws a portion of a bitmap onto a specified area of the canvas.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an [OH_Drawing_Canvas](#oh_drawing_canvas) object.| 
| OH_Drawing_Bitmap | Pointer to an [OH_Drawing_Bitmap](#oh_drawing_bitmap) object.| 
| src | Pointer to a rectangle on the bitmap. This parameter can be left empty.| 
| dst | Pointer to a rectangle on the canvas.| 
| OH_Drawing_SamplingOptions | Pointer to an [OH_Drawing_SamplingOptions](#oh_drawing_samplingoptions) object.| 


### OH_Drawing_CanvasDrawCircle()

```
void OH_Drawing_CanvasDrawCircle (OH_Drawing_Canvas* , const OH_Drawing_Point* , float radius )
```

**Description**

Draws a circle.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object.| 
| OH_Drawing_Point | Pointer to an **OH_Drawing_Point** object, which indicates the center of the circle.| 
| radius | Radius of the circle.| 


### OH_Drawing_CanvasDrawImageRect()

```
void OH_Drawing_CanvasDrawImageRect (OH_Drawing_Canvas* , OH_Drawing_Image* , OH_Drawing_Rect* dst, OH_Drawing_SamplingOptions*  )
```

**Description**

Draws an image onto a specified area of the canvas.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an [OH_Drawing_Canvas](#oh_drawing_canvas) object.| 
| OH_Drawing_Image | Pointer to an [OH_Drawing_Image](#oh_drawing_image) object.| 
| OH_Drawing_Rect | Pointer to an [OH_Drawing_Rect](#oh_drawing_rect) object.| 
| OH_Drawing_SamplingOptions | Pointer to an [OH_Drawing_SamplingOptions](#oh_drawing_samplingoptions) object.| 


### OH_Drawing_CanvasDrawLine()

```
void OH_Drawing_CanvasDrawLine (OH_Drawing_Canvas* , float x1, float y1, float x2, float y2 )
```

**Description**

Draws a line segment.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object.| 
| x1 | X coordinate of the start point of the line segment.| 
| y1 | Y coordinate of the start point of the line segment.| 
| x2 | X coordinate of the end point of the line segment.| 
| y2 | Y coordinate of the end point of the line segment.| 


### OH_Drawing_CanvasDrawOval()

```
void OH_Drawing_CanvasDrawOval (OH_Drawing_Canvas* , const OH_Drawing_Rect*  )
```

**Description**

Draws an oval.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object.| 
| OH_Drawing_Rect | Pointer to an **OH_Drawing_Rect** object.| 


### OH_Drawing_CanvasDrawPath()

```
void OH_Drawing_CanvasDrawPath (OH_Drawing_Canvas* , const OH_Drawing_Path*  )
```

**Description**

Draws a path.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object.| 
| OH_Drawing_Path | Pointer to an **OH_Drawing_Path** object.| 


### OH_Drawing_CanvasDrawRect()

```
void OH_Drawing_CanvasDrawRect (OH_Drawing_Canvas* , const OH_Drawing_Rect*  )
```

**Description**

Draws a rectangle.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object.| 
| OH_Drawing_Rect | Pointer to an **OH_Drawing_Rect** object.| 


### OH_Drawing_CanvasDrawRoundRect()

```
void OH_Drawing_CanvasDrawRoundRect (OH_Drawing_Canvas* , const OH_Drawing_RoundRect*  )
```

**Description**

Draws a rounded rectangle.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object.| 
| OH_Drawing_RoundRect | Pointer to an **OH_Drawing_RoundRect** object.| 


### OH_Drawing_CanvasDrawShadow()

```
void OH_Drawing_CanvasDrawShadow (OH_Drawing_Canvas* , OH_Drawing_Path* , OH_Drawing_Point3D planeParams, OH_Drawing_Point3D devLightPos, float lightRadius, uint32_t ambientColor, uint32_t spotColor, OH_Drawing_CanvasShadowFlags flag )
```

**Description**

Draws an offset spot shadow and uses a given path to outline the ambient shadow.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an [OH_Drawing_Canvas](#oh_drawing_canvas) object.| 
| OH_Drawing_Path | Pointer to an [OH_Drawing_Path](#oh_drawing_path) object, which is used to generate the shadow.| 
| planeParams | Value of the function that returns the Z-axis of the occluding object from the canvas based on the x-axis and y-axis.| 
| devLightPos | Position of the light relative to the canvas.| 
| lightRadius | Radius of the light.| 
| ambientColor | Color of the ambient shadow.| 
| spotColor | Color of the spot shadow.| 
| flag | Shadow flag. For details about the available options, see [OH_Drawing_CanvasShadowFlags](#oh_drawing_canvasshadowflags).| 


### OH_Drawing_CanvasDrawTextBlob()

```
void OH_Drawing_CanvasDrawTextBlob (OH_Drawing_Canvas* , const OH_Drawing_TextBlob* , float x, float y )
```

**Description**

Draws a text blob.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object.| 
| OH_Drawing_TextBlob | Pointer to an **OH_Drawing_TextBlob** object.| 
| x | X coordinate of the lower left corner of the text blob.| 
| y | Y coordinate of the lower left corner of the text blob.| 


### OH_Drawing_CanvasGetHeight()

```
int32_t OH_Drawing_CanvasGetHeight (OH_Drawing_Canvas* )
```

**Description**

Obtains the canvas height.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an [OH_Drawing_Canvas](#oh_drawing_canvas) object.| 

**Returns**

Returns the canvas height, in pixels.


### OH_Drawing_CanvasGetLocalClipBounds()

```
void OH_Drawing_CanvasGetLocalClipBounds (OH_Drawing_Canvas* , OH_Drawing_Rect*  )
```

**Description**

Obtains the bounds of the cropping region of a canvas. This function cannot be used for recorded canvases.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an [OH_Drawing_Canvas](#oh_drawing_canvas) object.| 
| OH_Drawing_Rect | Pointer to an [OH_Drawing_Rect](#oh_drawing_rect) object, which is obtained by calling [OH_Drawing_RectCreate](#oh_drawing_rectcreate).| 


### OH_Drawing_CanvasGetSaveCount()

```
uint32_t OH_Drawing_CanvasGetSaveCount (OH_Drawing_Canvas* )
```

**Description**

Obtains the number of canvas statuses (canvas matrices) saved in the stack.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object.| 

**Returns**

Returns a 32-bit value that describes the number of canvas statuses (canvas matrices).


### OH_Drawing_CanvasGetTotalMatrix()

```
void OH_Drawing_CanvasGetTotalMatrix (OH_Drawing_Canvas* , OH_Drawing_Matrix*  )
```

**Description**

Obtains the 3x3 matrix of a canvas.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an [OH_Drawing_Canvas](#oh_drawing_canvas) object.| 
| OH_Drawing_Matrix | Pointer to an [OH_Drawing_Matrix](#oh_drawing_matrix) object, which is obtained by calling [OH_Drawing_MatrixCreate](#oh_drawing_matrixcreate).| 


### OH_Drawing_CanvasGetWidth()

```
int32_t OH_Drawing_CanvasGetWidth (OH_Drawing_Canvas* )
```

**Description**

Obtains the canvas width.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an [OH_Drawing_Canvas](#oh_drawing_canvas) object.| 

**Returns**

Returns the canvas width, in px.


### OH_Drawing_CanvasReadPixels()

```
bool OH_Drawing_CanvasReadPixels (OH_Drawing_Canvas* , OH_Drawing_Image_Info* , void* dstPixels, uint32_t dstRowBytes, int32_t srcX, int32_t srcY )
```

**Description**

Copies pixel data from a canvas to a specified address. This function cannot be used for recorded canvases.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an [OH_Drawing_Canvas](#oh_drawing_canvas) object.| 
| [OH_Drawing_Image_Info](_o_h___drawing___image___info.md) | Pointer to an [OH_Drawing_Image_Info](_o_h___drawing___image___info.md) object.| 
| dstPixels | Pointer to the start address for storing the pixel data.| 
| dstRowBytes | Size of pixels per row.| 
| srcX | X-axis offset of the pixels on the canvas, in px.| 
| srcY | Y-axis offset of the pixels on the canvas, in px.| 

**Returns**

Returns **true** if the pixel data is copied to the start address of the storage; returns **false** otherwise.


### OH_Drawing_CanvasReadPixelsToBitmap()

```
bool OH_Drawing_CanvasReadPixelsToBitmap (OH_Drawing_Canvas* , OH_Drawing_Bitmap* , int32_t srcX, int32_t srcY )
```

**Description**

Copies pixel data from a canvas to an image. This function cannot be used for recorded canvases.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an [OH_Drawing_Canvas](#oh_drawing_canvas) object.| 
| OH_Drawing_Bitmap | Pointer to an [OH_Drawing_Bitmap](#oh_drawing_bitmap) object.| 
| srcX | X-axis offset of the pixels on the canvas, in px.| 
| srcY | Y-axis offset of the pixels on the canvas, in px.| 

**Returns**

Returns **true** if the pixel data is copied to the image; returns **false** otherwise.


### OH_Drawing_CanvasRestore()

```
void OH_Drawing_CanvasRestore (OH_Drawing_Canvas* )
```

**Description**

Restores the canvas status (canvas matrix) saved on the top of the stack.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object.| 


### OH_Drawing_CanvasRestoreToCount()

```
void OH_Drawing_CanvasRestoreToCount (OH_Drawing_Canvas* , uint32_t saveCount )
```

**Description**

Restores to a given number of canvas statuses (canvas matrices).

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object.| 
| saveCount | Number of canvas statuses (canvas matrices).| 


### OH_Drawing_CanvasRotate()

```
void OH_Drawing_CanvasRotate (OH_Drawing_Canvas* , float degrees, float px, float py )
```

**Description**

Rotates a canvas by a given angle. A positive number indicates a clockwise rotation, and a negative number indicates a counterclockwise rotation.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object.| 
| degrees | Angle to rotate.| 
| px | X coordinate of the rotation center.| 
| py | Y coordinate of the rotation center.| 


### OH_Drawing_CanvasSave()

```
void OH_Drawing_CanvasSave (OH_Drawing_Canvas* )
```

**Description**

Saves the current canvas status (canvas matrix) to the top of the stack.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object.| 


### OH_Drawing_CanvasSaveLayer()

```
void OH_Drawing_CanvasSaveLayer (OH_Drawing_Canvas* , const OH_Drawing_Rect* , const OH_Drawing_Brush*  )
```

**Description**

Saves the matrix and cropping region, and allocates a bitmap for subsequent drawing. If you call [OH_Drawing_CanvasRestore](#oh_drawing_canvasrestore), the changes made to the matrix and clipping region are discarded, and the bitmap is drawn.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an [OH_Drawing_Canvas](#oh_drawing_canvas) object.| 
| OH_Drawing_Rect | Pointer to an [OH_Drawing_Rect](#oh_drawing_rect) object.| 
| OH_Drawing_Brush | Pointer to an [OH_Drawing_Brush](#oh_drawing_brush) object.| 


### OH_Drawing_CanvasScale()

```
void OH_Drawing_CanvasScale (OH_Drawing_Canvas* , float sx, float sy )
```

**Description**

Scales a canvas.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object.| 
| sx | Horizontal scale factor.| 
| sy | Vertical scale factor.| 


### OH_Drawing_CanvasSetMatrix()

```
void OH_Drawing_CanvasSetMatrix (OH_Drawing_Canvas* , OH_Drawing_Matrix*  )
```

**Description**

Sets the matrix status for a canvas.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an [OH_Drawing_Canvas](#oh_drawing_canvas) object.| 
| OH_Drawing_Matrix | Pointer to an [OH_Drawing_Matrix](#oh_drawing_matrix) object, which is obtained by calling [OH_Drawing_MatrixCreate](#oh_drawing_matrixcreate).| 


### OH_Drawing_CanvasTranslate()

```
void OH_Drawing_CanvasTranslate (OH_Drawing_Canvas* , float dx, float dy )
```

**Description**

Translates a canvas by a given distance.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object.| 
| dx | Distance to translate in the horizontal direction.| 
| dy | Distance to translate in the vertical direction.| 


### OH_Drawing_ColorFilterCreateBlendMode()

```
OH_Drawing_ColorFilter* OH_Drawing_ColorFilterCreateBlendMode (uint32_t color, OH_Drawing_BlendMode  )
```

**Description**

Creates an **OH_Drawing_ColorFilter** object with a given blend mode.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| color | Color, which is a 32-bit (ARGB) variable.| 
| OH_Drawing_BlendMode | Blend mode. For details about the available options, see [OH_Drawing_BlendMode](#oh_drawing_blendmode).| 

**Returns**

Returns the pointer to the **OH_Drawing_ColorFilter** object created.


### OH_Drawing_ColorFilterCreateCompose()

```
OH_Drawing_ColorFilter* OH_Drawing_ColorFilterCreateCompose (OH_Drawing_ColorFilter* colorFilter1, OH_Drawing_ColorFilter* colorFilter2 )
```

**Description**

Creates an **OH_Drawing_ColorFilter** object by combining another two color filters.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_ColorFilter | Pointer to the first color filter.| 
| OH_Drawing_ColorFilter | Pointer to the second color filter.| 

**Returns**

Returns the pointer to the **OH_Drawing_ColorFilter** object created.


### OH_Drawing_ColorFilterCreateLinearToSrgbGamma()

```
OH_Drawing_ColorFilter* OH_Drawing_ColorFilterCreateLinearToSrgbGamma (void )
```

**Description**

Creates an **OH_Drawing_ColorFilter** object that applies the sRGB gamma curve to the RGB channels.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Returns**

Returns the pointer to the **OH_Drawing_ColorFilter** object created.


### OH_Drawing_ColorFilterCreateLuma()

```
OH_Drawing_ColorFilter* OH_Drawing_ColorFilterCreateLuma (void )
```

**Description**

Creates an **OH_Drawing_ColorFilter** object that multiplies the passed-in luma into the alpha channel and sets the RGB channels to zero.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Returns**

Returns the pointer to the **OH_Drawing_ColorFilter** object created.


### OH_Drawing_ColorFilterCreateMatrix()

```
OH_Drawing_ColorFilter* OH_Drawing_ColorFilterCreateMatrix (const float matrix[20])
```

**Description**

Creates an **OH_Drawing_ColorFilter** object with a given 5x4 color matrix.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| matrix | Matrix, which is represented by a floating-point array with a length of 20.| 

**Returns**

Returns the pointer to the **OH_Drawing_ColorFilter** object created.


### OH_Drawing_ColorFilterCreateSrgbGammaToLinear()

```
OH_Drawing_ColorFilter* OH_Drawing_ColorFilterCreateSrgbGammaToLinear (void )
```

**Description**

Creates an **OH_Drawing_ColorFilter** object that applies the RGB channels to the sRGB gamma curve.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Returns**

Returns the pointer to the **OH_Drawing_ColorFilter** object created.


### OH_Drawing_ColorFilterDestroy()

```
void OH_Drawing_ColorFilterDestroy (OH_Drawing_ColorFilter* )
```

**Description**

Destroys an **OH_Drawing_ColorFilter** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_ColorFilter | Pointer to an **OH_Drawing_ColorFilter** object.| 


### OH_Drawing_ColorSetArgb()

```
uint32_t OH_Drawing_ColorSetArgb (uint32_t alpha, uint32_t red, uint32_t green, uint32_t blue )
```

**Description**

Converts four variables (alpha, red, green, and blue) into a 32-bit (ARGB) variable that describes a color.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| alpha | Alpha, which is a variable ranging from 0x00 to 0xFF.| 
| red | Read, which is a variable ranging from 0x00 to 0xFF.| 
| green | Green, which is a variable ranging from 0x00 to 0xFF.| 
| blue | Blue, which is a variable ranging from 0x00 to 0xFF.| 

**Returns**

Returns a 32-bit (ARGB) variable that describes the color.


### OH_Drawing_CreateDashPathEffect()

```
OH_Drawing_PathEffect* OH_Drawing_CreateDashPathEffect (float* intervals, int count, float phase )
```

**Description**

Creates an **OH_Drawing_PathEffect** object with a dashed line effect. The dashed line effect is determined by a group of "on" and "off" intervals.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| intervals | Pointer to the start address of the dashed line interval array. In the array, an even entry indicates an "on" interval and an odd entry indicates an "off" interval. The unit is px.| 
| count | Number of entries in the dashed line interval array. The value must be an even number greater than 0.| 
| phase | Offset in the dashed line interval array.| 

**Returns**

Returns the pointer to the [OH_Drawing_PathEffect](#oh_drawing_patheffect) object created.


### OH_Drawing_CreateFontCollection()

```
OH_Drawing_FontCollection* OH_Drawing_CreateFontCollection (void )
```

**Description**

Creates an [OH_Drawing_FontCollection](#oh_drawing_fontcollection) object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Returns**

Returns the pointer to the **OH_Drawing_FontCollection** object created.


### OH_Drawing_CreateFontDescriptor()

```
OH_Drawing_FontDescriptor* OH_Drawing_CreateFontDescriptor (void )
```

**Description**

Creates an **OH_Drawing_FontDescriptor** object to describe the detailed information about a system font.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Returns**

Returns the pointer to the [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) object created.


### OH_Drawing_CreateFontParser()

```
OH_Drawing_FontParser* OH_Drawing_CreateFontParser (void )
```

**Description**

Creates an **OH_Drawing_FontParser** object to parse a system font.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Returns**

Returns the pointer to the [OH_Drawing_FontParser](#oh_drawing_fontparser) object created.


### OH_Drawing_CreateTextShadow()

```
OH_Drawing_TextShadow* OH_Drawing_CreateTextShadow (void )
```

**Description**

Creates an **OH_Drawing_TextShadow** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Returns**

Returns the pointer to the **OH_Drawing_TextShadow** object created.


### OH_Drawing_CreateTextStyle()

```
OH_Drawing_TextStyle* OH_Drawing_CreateTextStyle (void )
```

**Description**

Creates an **OH_Drawing_TextStyle** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Returns**

Returns the pointer to the **OH_Drawing_TextStyle** object created.


### OH_Drawing_CreateTypography()

```
OH_Drawing_Typography* OH_Drawing_CreateTypography (OH_Drawing_TypographyCreate* )
```

**Description**

Creates an **OH_Drawing_Typography** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TypographyCreate | Pointer to an **OH_Drawing_TypographyCreate** object. The pointer is obtained by [OH_Drawing_CreateTypographyHandler](#oh_drawing_createtypographyhandler).| 

**Returns**

Returns the pointer to the **OH_Drawing_Typography** object created.


### OH_Drawing_CreateTypographyHandler()

```
OH_Drawing_TypographyCreate* OH_Drawing_CreateTypographyHandler (OH_Drawing_TypographyStyle* , OH_Drawing_FontCollection*  )
```

**Description**

Creates an **OH_Drawing_TypographyCreate** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TypographyStyle | Pointer to an **OH_Drawing_TypographyStyle** object, which is obtained by [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle).| 
| OH_Drawing_FontCollection | Pointer to an **OH_Drawing_FontCollection** object, which is obtained by [OH_Drawing_CreateFontCollection](#oh_drawing_createfontcollection).| 

**Returns**

Returns the pointer to the **OH_Drawing_TypographyCreate** object created.


### OH_Drawing_CreateTypographyStyle()

```
OH_Drawing_TypographyStyle* OH_Drawing_CreateTypographyStyle (void )
```

**Description**

Creates an **OH_Drawing_TypographyStyle** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Returns**

Returns the pointer to the **OH_Drawing_TypographyStyle** object created.


### OH_Drawing_DestroyFontCollection()

```
void OH_Drawing_DestroyFontCollection (OH_Drawing_FontCollection* )
```

**Description**

Destroys an **OH_Drawing_FontCollection** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_FontCollection | Pointer to an **OH_Drawing_FontCollection** object.| 


### OH_Drawing_DestroyFontDescriptor()

```
void OH_Drawing_DestroyFontDescriptor (OH_Drawing_FontDescriptor* )
```

**Description**

Destroys an **OH_Drawing_FontDescriptor** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) | Pointer to a [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) object, which is obtained by calling [OH_Drawing_CreateFontDescriptor](#oh_drawing_createfontdescriptor).| 


### OH_Drawing_DestroyFontParser()

```
void OH_Drawing_DestroyFontParser (OH_Drawing_FontParser* )
```

**Description**

Destroys an **OH_Drawing_FontParser** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_FontParser | Pointer to an [OH_Drawing_FontParser](#oh_drawing_fontparser) object, which is obtained by calling [OH_Drawing_CreateFontParser](#oh_drawing_createfontparser).| 


### OH_Drawing_DestroyLineMetrics()

```
void OH_Drawing_DestroyLineMetrics (OH_Drawing_LineMetrics* )
```

**Description**

Destroys an **OH_Drawing_LineMetrics** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| [OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md) | Pointer to an [OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md) object, which is obtained by calling [OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md).| 


### OH_Drawing_DestroySystemFontList()

```
void OH_Drawing_DestroySystemFontList (char** , size_t  )
```

**Description**

Reclaims the memory occupied by the system font list.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| char\*\* | Double pointer to the list of system font names.| 
| size_t\* | Number of system font names.| 


### OH_Drawing_DestroyTextShadow()

```
void OH_Drawing_DestroyTextShadow (OH_Drawing_TextShadow* )
```

**Description**

Destroys an **OH_Drawing_TextShadow** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TextShadow | Pointer to an [OH_Drawing_TextShadow](#oh_drawing_textshadow) object, which is obtained by calling [OH_Drawing_CreateTextShadow](#oh_drawing_createtextshadow).| 


### OH_Drawing_DestroyTextShadows()

```
void OH_Drawing_DestroyTextShadows (OH_Drawing_TextShadow* )
```

**Description**

Reclaims the memory occupied by the vector consisting of the **OH_Drawing_TextShadow** objects.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TextShadow | Pointer to an [OH_Drawing_TextShadow](#oh_drawing_textshadow) object, which is obtained by calling [OH_Drawing_CreateTextShadow](#oh_drawing_createtextshadow).| 


### OH_Drawing_DestroyTextStyle()

```
void OH_Drawing_DestroyTextStyle (OH_Drawing_TextStyle* )
```

**Description**

Destroys an **OH_Drawing_TextStyle** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object, which is obtained by [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle).| 


### OH_Drawing_DestroyTypography()

```
void OH_Drawing_DestroyTypography (OH_Drawing_Typography* )
```

**Description**

Destroys an **OH_Drawing_Typography** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Typography | Pointer to an **OH_Drawing_Typography** object, which is obtained by [OH_Drawing_CreateTypography](#oh_drawing_createtypography).| 


### OH_Drawing_DestroyTypographyHandler()

```
void OH_Drawing_DestroyTypographyHandler (OH_Drawing_TypographyCreate* )
```

**Description**

Destroys an **OH_Drawing_TypographyCreate** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TypographyCreate | Pointer to an **OH_Drawing_TypographyCreate** object. The pointer is obtained by [OH_Drawing_CreateTypographyHandler](#oh_drawing_createtypographyhandler).| 


### OH_Drawing_DestroyTypographyStyle()

```
void OH_Drawing_DestroyTypographyStyle (OH_Drawing_TypographyStyle* )
```

**Description**

Destroys an **OH_Drawing_TypographyStyle** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TypographyStyle | Pointer to an **OH_Drawing_TypographyStyle** object, which is obtained by [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle).| 


### OH_Drawing_DisableFontCollectionFallback()

```
void OH_Drawing_DisableFontCollectionFallback (OH_Drawing_FontCollection* fontCollection)
```

**Description**

Disables the alternate fonts.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_FontCollection | Pointer to an [OH_Drawing_FontCollection](#oh_drawing_fontcollection) object.| 


### OH_Drawing_DisableFontCollectionSystemFont()

```
void OH_Drawing_DisableFontCollectionSystemFont (OH_Drawing_FontCollection* fontCollection)
```

**Description**

Disables the system fonts.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_FontCollection | Pointer to an [OH_Drawing_FontCollection](#oh_drawing_fontcollection) object.| 


### OH_Drawing_FilterCreate()

```
OH_Drawing_Filter* OH_Drawing_FilterCreate (void )
```

**Description**

Creates an **OH_Drawing_Filter** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Returns**

Returns the pointer to the **OH_Drawing_Filter** object created.


### OH_Drawing_FilterDestroy()

```
void OH_Drawing_FilterDestroy (OH_Drawing_Filter* )
```

**Description**

Destroys an **OH_Drawing_Filter** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Filter | Pointer to an **OH_Drawing_Filter** object.| 


### OH_Drawing_FilterSetColorFilter()

```
void OH_Drawing_FilterSetColorFilter (OH_Drawing_Filter* , OH_Drawing_ColorFilter*  )
```

**Description**

Sets an **OH_Drawing_ColorFilter** object for an **OH_Drawing_Filter** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Filter | Pointer to an **OH_Drawing_Filter** object.| 
| OH_Drawing_ColorFilter | Pointer to an **OH_Drawing_ColorFilter** object.| 


### OH_Drawing_FilterSetMaskFilter()

```
void OH_Drawing_FilterSetMaskFilter (OH_Drawing_Filter* , OH_Drawing_MaskFilter*  )
```

**Description**

Sets an **OH_Drawing_MaskFilter** object for an **OH_Drawing_Filter** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Filter | Pointer to an **OH_Drawing_Filter** object.| 
| OH_Drawing_MaskFilter | Pointer to an **OH_Drawing_MaskFilter** object.| 


### OH_Drawing_FontCountText()

```
int OH_Drawing_FontCountText (OH_Drawing_Font* , const void* text, size_t byteLength, OH_Drawing_TextEncoding encoding )
```

**Description**

Obtains the number of glyphs represented by text.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Font | Pointer to an [OH_Drawing_Font](#oh_drawing_font) object.| 
| text | Pointer to the start address of the storage.| 
| byteLength | Text length, in bytes.| 
| encoding | Encoding type of the text. For details about the available options, see [OH_Drawing_TextEncoding](#oh_drawing_textencoding).| 


### OH_Drawing_FontCreate()

```
OH_Drawing_Font* OH_Drawing_FontCreate (void )
```

**Description**

Creates an **OH_Drawing_Font** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Returns**

Returns the pointer to the **OH_Drawing_Font** object created.


### OH_Drawing_FontDestroy()

```
void OH_Drawing_FontDestroy (OH_Drawing_Font* )
```

**Description**

Destroys an **OH_Drawing_Font** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Font | Pointer to an **OH_Drawing_Font** object.| 


### OH_Drawing_FontGetMetrics()

```
float OH_Drawing_FontGetMetrics (OH_Drawing_Font* , OH_Drawing_Font_Metrics*  )
```

**Description**

Obtains the measurement information about a font.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Font | Pointer to an [OH_Drawing_Font](#oh_drawing_font) object.| 
| [OH_Drawing_Font_Metrics](_o_h___drawing___font___metrics.md) | Pointer to an [OH_Drawing_Font_Metrics](_o_h___drawing___font___metrics.md) object.| 

**Returns**

Returns a floating-point variable that indicates the recommended interline spacing.


### OH_Drawing_FontGetTypeface()

```
OH_Drawing_Typeface* OH_Drawing_FontGetTypeface (OH_Drawing_Font* )
```

**Description**

Obtains the typeface of a font.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Font | Pointer to an [OH_Drawing_Font](#oh_drawing_font) object.| 

**Returns**

Returns the pointer to the [OH_Drawing_Typeface](#oh_drawing_typeface) object.


### OH_Drawing_FontParserGetFontByName()

```
OH_Drawing_FontDescriptor* OH_Drawing_FontParserGetFontByName (OH_Drawing_FontParser* , const char*  )
```

**Description**

Obtains information about a system font based on the font name.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_FontParser | Pointer to an [OH_Drawing_FontParser](#oh_drawing_fontparser) object, which is obtained by calling [OH_Drawing_CreateFontParser](#oh_drawing_createfontparser).| 
| char\* | Pointer to the system font name.| 

**Returns**

Returns the system font.


### OH_Drawing_FontParserGetSystemFontList()

```
char** OH_Drawing_FontParserGetSystemFontList (OH_Drawing_FontParser* , size_t*  )
```

**Description**

Obtains the list of system fonts.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_FontParser | Pointer to an [OH_Drawing_FontParser](#oh_drawing_fontparser) object, which is obtained by calling [OH_Drawing_CreateFontParser](#oh_drawing_createfontparser).| 
| size_t | Pointer to the number of system font names.| 

**Returns**

Returns the system font list.


### OH_Drawing_FontSetFakeBoldText()

```
void OH_Drawing_FontSetFakeBoldText (OH_Drawing_Font* , bool isFakeBoldText )
```

**Description**

Sets fake bold for a font by increasing the stroke width.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Font | Pointer to an **OH_Drawing_Font** object.| 
| isFakeBoldText | Whether to set fake bold. The value **true** means to set fake bold, and **false** means the opposite.| 


### OH_Drawing_FontSetLinearText()

```
void OH_Drawing_FontSetLinearText (OH_Drawing_Font* , bool isLinearText )
```

**Description**

Sets linear scaling for a font.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Font | Pointer to an **OH_Drawing_Font** object.| 
| isLinearText | Whether to set linear scaling. The value **true** means to set linear scaling, and **false** means the opposite.| 


### OH_Drawing_FontSetTextSize()

```
void OH_Drawing_FontSetTextSize (OH_Drawing_Font* , float textSize )
```

**Description**

Sets the font size.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Font | Pointer to an **OH_Drawing_Font** object.| 
| textSize | Font size.| 


### OH_Drawing_FontSetTextSkewX()

```
void OH_Drawing_FontSetTextSkewX (OH_Drawing_Font* , float skewX )
```

**Description**

Sets a horizontal skew factor for a font.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Font | Pointer to an **OH_Drawing_Font** object.| 
| skewX | Skew of the X axis relative to the Y axis.| 


### OH_Drawing_FontSetTypeface()

```
void OH_Drawing_FontSetTypeface (OH_Drawing_Font* , OH_Drawing_Typeface*  )
```

**Description**

Sets the typeface for a font.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Font | Pointer to an **OH_Drawing_Font** object.| 
| OH_Drawing_Typeface | Pointer to an **OH_Drawing_Typeface** object.| 


### OH_Drawing_GetAffinityFromPositionAndAffinity()

```
int OH_Drawing_GetAffinityFromPositionAndAffinity (OH_Drawing_PositionAndAffinity* )
```

**Description**

Obtains the affinity attribute of an **OH_Drawing_PositionAndAffinity** object. The affinity determines whether the font is close to the front text or rear text.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_PositionAndAffinity | Pointer to an **OH_Drawing_PositionAndAffinity** object, which is obtained by [OH_Drawing_TypographyGetGlyphPositionAtCoordinate](#oh_drawing_typographygetglyphpositionatcoordinate) or [OH_Drawing_TypographyGetGlyphPositionAtCoordinateWithCluster](#oh_drawing_typographygetglyphpositionatcoordinatewithcluster).| 

**Returns**

Returns the affinity attribute.


### OH_Drawing_GetBottomFromTextBox()

```
float OH_Drawing_GetBottomFromTextBox (OH_Drawing_TextBox* , int  )
```

**Description**

Obtains the bottom position of a text box.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TextBox | Pointer to an **OH_Drawing_TextBox** object, which is obtained by [OH_Drawing_TypographyGetRectsForRange](#oh_drawing_typographygetrectsforrange) or [OH_Drawing_TypographyGetRectsForPlaceholders](#oh_drawing_typographygetrectsforplaceholders).| 
| int | Index of the text box.| 

**Returns**

Returns the bottom position.


### OH_Drawing_GetEndFromRange()

```
size_t OH_Drawing_GetEndFromRange (OH_Drawing_Range* )
```

**Description**

Obtains the end position of an **OH_Drawing_Range** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Range | Pointer to an **OH_Drawing_Range** object, which is obtained by [OH_Drawing_TypographyGetWordBoundary](#oh_drawing_typographygetwordboundary).| 

**Returns**

Returns the end position.


### OH_Drawing_GetLeftFromTextBox()

```
float OH_Drawing_GetLeftFromTextBox (OH_Drawing_TextBox* , int  )
```

**Description**

Obtains the left position of a text box.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TextBox | Pointer to an **OH_Drawing_TextBox** object, which is obtained by [OH_Drawing_TypographyGetRectsForRange](#oh_drawing_typographygetrectsforrange) or [OH_Drawing_TypographyGetRectsForPlaceholders](#oh_drawing_typographygetrectsforplaceholders).| 
| int | Index of the text box.| 

**Returns**

Returns the left position.


### OH_Drawing_GetPositionFromPositionAndAffinity()

```
size_t OH_Drawing_GetPositionFromPositionAndAffinity (OH_Drawing_PositionAndAffinity* )
```

**Description**

Obtains the position attribute of an **OH_Drawing_PositionAndAffinity** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_PositionAndAffinity | Pointer to an **OH_Drawing_PositionAndAffinity** object, which is obtained by [OH_Drawing_TypographyGetGlyphPositionAtCoordinate](#oh_drawing_typographygetglyphpositionatcoordinate) or [OH_Drawing_TypographyGetGlyphPositionAtCoordinateWithCluster](#oh_drawing_typographygetglyphpositionatcoordinatewithcluster).| 

**Returns**

Returns the position attribute.


### OH_Drawing_GetRightFromTextBox()

```
float OH_Drawing_GetRightFromTextBox (OH_Drawing_TextBox* , int  )
```

**Description**

Obtains the right position of a text box.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TextBox | Pointer to an **OH_Drawing_TextBox** object, which is obtained by [OH_Drawing_TypographyGetRectsForRange](#oh_drawing_typographygetrectsforrange) or [OH_Drawing_TypographyGetRectsForPlaceholders](#oh_drawing_typographygetrectsforplaceholders).| 
| int | Index of the text box.| 

**Returns**

Returns the right position.


### OH_Drawing_GetSizeOfTextBox()

```
size_t OH_Drawing_GetSizeOfTextBox (OH_Drawing_TextBox* )
```

**Description**

Obtains the number of text boxes.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TextBox | Pointer to an **OH_Drawing_TextBox** object, which is obtained by [OH_Drawing_TypographyGetRectsForRange](#oh_drawing_typographygetrectsforrange) or [OH_Drawing_TypographyGetRectsForPlaceholders](#oh_drawing_typographygetrectsforplaceholders).| 

**Returns**

Returns the number of text boxes.


### OH_Drawing_GetStartFromRange()

```
size_t OH_Drawing_GetStartFromRange (OH_Drawing_Range* )
```

**Description**

Obtains the start position of an **OH_Drawing_Range** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Range | Pointer to an **OH_Drawing_Range** object, which is obtained by [OH_Drawing_TypographyGetWordBoundary](#oh_drawing_typographygetwordboundary).| 

**Returns**

Returns the start position.


### OH_Drawing_GetTextDirectionFromTextBox()

```
int OH_Drawing_GetTextDirectionFromTextBox (OH_Drawing_TextBox* , int  )
```

**Description**

Obtains the text direction of a text box.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TextBox | Pointer to an **OH_Drawing_TextBox** object, which is obtained by [OH_Drawing_TypographyGetRectsForRange](#oh_drawing_typographygetrectsforrange) or [OH_Drawing_TypographyGetRectsForPlaceholders](#oh_drawing_typographygetrectsforplaceholders).| 
| int | Index of the text box.| 

**Returns**

Returns the text direction.


### OH_Drawing_GetTopFromTextBox()

```
float OH_Drawing_GetTopFromTextBox (OH_Drawing_TextBox* , int  )
```

**Description**

Obtains the top position of a text box.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TextBox | Pointer to an **OH_Drawing_TextBox** object, which is obtained by [OH_Drawing_TypographyGetRectsForRange](#oh_drawing_typographygetrectsforrange) or [OH_Drawing_TypographyGetRectsForPlaceholders](#oh_drawing_typographygetrectsforplaceholders).| 
| int | Index of the text box.| 

**Returns**

Returns the top position.


### OH_Drawing_ImageBuildFromBitmap()

```
bool OH_Drawing_ImageBuildFromBitmap (OH_Drawing_Image* , OH_Drawing_Bitmap*  )
```

**Description**

Builds an image from a bitmap by sharing or copying bitmap pixels. If the bitmap is marked as immutable, the pixel memory is shared, not copied.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Image | Pointer to an [OH_Drawing_Image](#oh_drawing_image) object.| 
| OH_Drawing_Bitmap | Pointer to an [OH_Drawing_Bitmap](#oh_drawing_bitmap) object.| 

**Returns**

Returns **true** if the image is built; returns **false** otherwise.


### OH_Drawing_ImageCreate()

```
OH_Drawing_Image* OH_Drawing_ImageCreate (void )
```

**Description**

Creates an **OH_Drawing_Image** object that describes an array of two-dimensional pixels to draw.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Returns**

Returns the pointer to the [OH_Drawing_Image](#oh_drawing_image) object created.


### OH_Drawing_ImageDestroy()

```
void OH_Drawing_ImageDestroy (OH_Drawing_Image* )
```

**Description**

Destroys an **OH_Drawing_Image** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Image | Pointer to an [OH_Drawing_Image](#oh_drawing_image) object.| 


### OH_Drawing_ImageGetHeight()

```
int32_t OH_Drawing_ImageGetHeight (OH_Drawing_Image* )
```

**Description**

Obtains the image height, that is, the number of pixel lines.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Image | Pointer to an [OH_Drawing_Image](#oh_drawing_image) object.| 

**Returns**

Returns the height.


### OH_Drawing_ImageGetImageInfo()

```
void OH_Drawing_ImageGetImageInfo (OH_Drawing_Image* , OH_Drawing_Image_Info*  )
```

**Description**

Obtains the image information. After this function is called, the passed-in image information object is filled.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Image | Pointer to an [OH_Drawing_Image](#oh_drawing_image) object.| 
| OH_Drawing_Image_Info | Pointer to an [OH_Drawing_Image_Info](_o_h___drawing___image___info.md) object, which is created by calling [OH_Drawing_Image_Info](_o_h___drawing___image___info.md).| 


### OH_Drawing_ImageGetWidth()

```
int32_t OH_Drawing_ImageGetWidth (OH_Drawing_Image* )
```

**Description**

Obtains the image width, that is, the number of pixels in each line.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Image | Pointer to an [OH_Drawing_Image](#oh_drawing_image) object.| 

**Returns**

Returns the width.


### OH_Drawing_LineMetricsGetSize()

```
size_t OH_Drawing_LineMetricsGetSize (OH_Drawing_LineMetrics* )
```

**Description**

Obtains the number of lines.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| [OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md) | Pointer to an [OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md) object, which is obtained by calling [OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md).| 

**Returns**

Returns the number of lines.


### OH_Drawing_MaskFilterCreateBlur()

```
OH_Drawing_MaskFilter* OH_Drawing_MaskFilterCreateBlur (OH_Drawing_BlurType blurType, float sigma, bool respectCTM )
```

**Description**

Creates an **OH_Drawing_MaskFilter** object with a given blur type.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| blurType | Blur type.| 
| sigma | Standard deviation of the Gaussian blur to apply. The value must be greater than **0**.| 
| respectCTM | Whether the blur's sigma is modified by the CTM. The default value is **true**.| 

**Returns**

Returns the pointer to the **OH_Drawing_MaskFilter** object created.


### OH_Drawing_MaskFilterDestroy()

```
void OH_Drawing_MaskFilterDestroy (OH_Drawing_MaskFilter* )
```

**Description**

Destroys an **OH_Drawing_MaskFilter** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_MaskFilter | Pointer to an **OH_Drawing_MaskFilter** object.| 


### OH_Drawing_MatrixConcat()

```
void OH_Drawing_MatrixConcat (OH_Drawing_Matrix* total, const OH_Drawing_Matrix* a, const OH_Drawing_Matrix* b )
```

**Description**

Multiplies two matrices to produce a new matrix.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| total | Pointer to the new matrix, which is an [OH_Drawing_Matrix](#oh_drawing_matrix) object.| 
| a | Pointer to the first matrix, which is an [OH_Drawing_Matrix](#oh_drawing_matrix) object.| 
| b | Pointer to the second matrix, which is an [OH_Drawing_Matrix](#oh_drawing_matrix) object.| 


### OH_Drawing_MatrixCreate()

```
OH_Drawing_Matrix* OH_Drawing_MatrixCreate (void )
```

**Description**

Creates an **OH_Drawing_Matrix** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Returns**

Returns the pointer to the **OH_Drawing_Matrix** object created.


### OH_Drawing_MatrixCreateRotation()

```
OH_Drawing_Matrix* OH_Drawing_MatrixCreateRotation (float deg, float x, float y )
```

**Description**

Creates an **OH_Drawing_Matrix** with the rotation attribute. The matrix can rotate by a given degree around the rotation point (x, y).

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Matrix | Pointer to an [OH_Drawing_Matrix](#oh_drawing_matrix) object.| 
| deg | Angle to rotate, in degrees. A positive number indicates a clockwise rotation, and a negative number indicates a counterclockwise rotation.| 
| x | Coordinate point on the X axis.| 
| y | Coordinate point on the Y axis.| 


### OH_Drawing_MatrixCreateScale()

```
OH_Drawing_Matrix* OH_Drawing_MatrixCreateScale (float sx, float sy, float px, float py )
```

**Description**

Creates an **OH_Drawing_Matrix** with the scale attribute. The matrix can be scaled with the factor (sx, sy) at the rotation point (px, py).

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| sx | Horizontal scale factor.| 
| sy | Vertical scale factor.| 
| px | Coordinate point on the X axis.| 
| py | Coordinate point on the Y axis.| 

**Returns**

Returns the pointer to the [OH_Drawing_Matrix](#oh_drawing_matrix) object created.


### OH_Drawing_MatrixCreateTranslation()

```
OH_Drawing_Matrix* OH_Drawing_MatrixCreateTranslation (float dx, float dy )
```

**Description**

Creates an **OH_Drawing_Matrix** with the translation attribute.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| dx | Horizontal distance to translate.| 
| dy | Vertical distance to translate.| 

**Returns**

Returns the pointer to the [OH_Drawing_Matrix](#oh_drawing_matrix) object created.


### OH_Drawing_MatrixDestroy()

```
void OH_Drawing_MatrixDestroy (OH_Drawing_Matrix* )
```

**Description**

Destroys an **OH_Drawing_Matrix** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Matrix | Pointer to an **OH_Drawing_Font** object.| 


### OH_Drawing_MatrixGetValue()

```
float OH_Drawing_MatrixGetValue (OH_Drawing_Matrix* , int index )
```

**Description**

Obtains a matrix value of a given index. The index ranges from 0 to 8.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Matrix | Pointer to an [OH_Drawing_Matrix](#oh_drawing_matrix) object.| 
| index | Index. The value ranges from 0 to 8.| 

**Returns**

Returns the matrix value.


### OH_Drawing_MatrixInvert()

```
bool OH_Drawing_MatrixInvert (OH_Drawing_Matrix* , OH_Drawing_Matrix* inverse )
```

**Description**

Inverts a matrix and returns the result.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Matrix | Pointer to an [OH_Drawing_Matrix](#oh_drawing_matrix) object.| 
| inverse | Pointer to the matrix to invert, which is an [OH_Drawing_Matrix](#oh_drawing_matrix) object. The object can be created by calling [OH_Drawing_MatrixCreate](#oh_drawing_matrixcreate).| 

**Returns**

Returns **true** if the matrix is reversible and the passed-in **inverse** is inverted; returns **false** otherwise.


### OH_Drawing_MatrixIsEqual()

```
bool OH_Drawing_MatrixIsEqual (OH_Drawing_Matrix* , OH_Drawing_Matrix* other )
```

**Description**

Checks whether two **OH_Drawing_Matrix** objects are equal.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Matrix | Pointer to a matrix, which is an [OH_Drawing_Matrix](#oh_drawing_matrix) object.| 
| other | Pointer to the other matrix, which is an [OH_Drawing_Matrix](#oh_drawing_matrix) object.| 

**Returns**

Returns **true** if the two matrices are equal; returns **false** otherwise.


### OH_Drawing_MatrixIsIdentity()

```
bool OH_Drawing_MatrixIsIdentity (OH_Drawing_Matrix* )
```

**Description**

Checks whether an **OH_Drawing_Matrix** object is an identity matrix.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Matrix | Pointer to an [OH_Drawing_Matrix](#oh_drawing_matrix) object.| 

**Returns**

Returns **true** if the matrix is an identity matrix; returns **false** otherwise.


### OH_Drawing_MatrixRotate()

```
void OH_Drawing_MatrixRotate (OH_Drawing_Matrix* , float degree, float px, float py )
```

**Description**

Sets a matrix as an identity matrix and rotates it by a given degree around the rotation point (px, py).

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Matrix | Pointer to an [OH_Drawing_Matrix](#oh_drawing_matrix) object.| 
| degree | Angle to rotate, in degrees. A positive number indicates a clockwise rotation, and a negative number indicates a counterclockwise rotation.| 
| px | Coordinate point on the X axis.| 
| py | Coordinate point on the Y axis.| 


### OH_Drawing_MatrixScale()

```
void OH_Drawing_MatrixScale (OH_Drawing_Matrix* , float sx, float sy, float px, float py )
```

**Description**

Sets a matrix as an identity matrix and scales it with the factor (sx, sy) at the rotation point (px, py).

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Matrix | Pointer to an [OH_Drawing_Matrix](#oh_drawing_matrix) object.| 
| sx | Horizontal scale factor.| 
| sy | Vertical scale factor.| 
| px | Coordinate point on the X axis.| 
| py | Coordinate point on the Y axis.| 


### OH_Drawing_MatrixSetMatrix()

```
void OH_Drawing_MatrixSetMatrix (OH_Drawing_Matrix* , float scaleX, float skewX, float transX, float skewY, float scaleY, float transY, float persp0, float persp1, float persp2 )
```

**Description**

Sets matrix parameters for an **OH_Drawing_Matrix** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Matrix | Pointer to an **OH_Drawing_Matrix** object.| 
| scaleX | Horizontal scale factor.| 
| skewX | Horizontal skew coefficient.| 
| transX | Horizontal translation coefficient.| 
| skewY | Vertical skew coefficient.| 
| scaleY | Vertical scale factor.| 
| transY | Vertical translation coefficient.| 
| persp0 | Perspective coefficient of the X axis.| 
| persp1 | Perspective coefficient of the Y axis.| 
| persp2 | Perspective scale coefficient.| 


### OH_Drawing_MatrixTranslate()

```
void OH_Drawing_MatrixTranslate (OH_Drawing_Matrix* , float dx, float dy )
```

**Description**

Sets a matrix as an identity matrix and translates it by a given distance (dx, dy).

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Matrix | Pointer to an [OH_Drawing_Matrix](#oh_drawing_matrix) object.| 
| dx | Horizontal distance to translate.| 
| dy | Vertical distance to translate.| 


### OH_Drawing_MemoryStreamCreate()

```
OH_Drawing_MemoryStream* OH_Drawing_MemoryStreamCreate (const void * data, size_t length, bool copyData )
```

**Description**

Creates an **OH_Drawing_MemoryStream** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| data | Pointer to the data.| 
| length | Length of the data.| 
| copyData | Whether to copy data. The value **true** means that the **OH_Drawing_MemoryStream** object copies the data, and **false** means that the **OH_Drawing_MemoryStream** object directly uses the data without copying.| 

**Returns**

Returns the pointer to the [OH_Drawing_MemoryStream](#oh_drawing_memorystream) object created.


### OH_Drawing_MemoryStreamDestroy()

```
void OH_Drawing_MemoryStreamDestroy (OH_Drawing_MemoryStream* )
```

**Description**

Destroys an **OH_Drawing_MemoryStream** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_MemoryStream | Pointer to an [OH_Drawing_MemoryStream](#oh_drawing_memorystream) object.| 


### OH_Drawing_PathAddArc()

```
void OH_Drawing_PathAddArc (OH_Drawing_Path* , const OH_Drawing_Rect* , float startAngle, float sweepAngle )
```

**Description**

Adds an arc to a path as the start of a new contour. The arc added is part of the ellipse bounded by oval, from the start angle through the sweep angle, measured in degrees. A positive angle indicates a clockwise sweep, and a negative angle indicates a counterclockwise sweep. If the sweep angle is less than or equal to -360°, or if the sweep angle is greater than or equal to 360° and start angle modulo 90 is nearly zero, an oval instead of an ellipse is added.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Path | Pointer to an [OH_Drawing_Path](#oh_drawing_path) object.| 
| OH_Drawing_Rect | Pointer to an [OH_Drawing_Rect](#oh_drawing_rect) object.| 
| startAngle | Start angle of the arc, in degrees.| 
| sweepAngle | Angle to sweep, in degrees. A positive number indicates a clockwise sweep, and a negative number indicates a counterclockwise sweep.| 


### OH_Drawing_PathAddPath()

```
void OH_Drawing_PathAddPath (OH_Drawing_Path* , const OH_Drawing_Path* src, const OH_Drawing_Matrix*  )
```

**Description**

Adds a copy of src to the path, transformed by matrix.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Path | Pointer to the current path, which is an [OH_Drawing_Path](#oh_drawing_path) object.| 
| src | Pointer to an [OH_Drawing_Path](#oh_drawing_path) object.| 
| OH_Drawing_Matrix | Pointer to an [OH_Drawing_Matrix](#oh_drawing_matrix) object.| 


### OH_Drawing_PathAddRect()

```
void OH_Drawing_PathAddRect (OH_Drawing_Path* , float left, float top, float right, float bottom, OH_Drawing_PathDirection  )
```

**Description**

Adds a rectangle contour to a path in the specified direction.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Path | Pointer to an [OH_Drawing_Path](#oh_drawing_path) object.| 
| left | X coordinate of the upper left corner of the rectangle.| 
| top | Y coordinate of the upper left corner of the rectangle.| 
| right | X coordinate of the lower right corner of the rectangle.| 
| bottom | Y coordinate of the lower right corner of the rectangle.| 
| OH_Drawing_PathDirection | Path direction. For details about the available options, see [OH_Drawing_PathDirection](#oh_drawing_pathdirection).| 


### OH_Drawing_PathAddRoundRect()

```
void OH_Drawing_PathAddRoundRect (OH_Drawing_Path* , const OH_Drawing_RoundRect* roundRect, OH_Drawing_PathDirection  )
```

**Description**

Adds a rounded rectangle contour to a path in the specified direction.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Path | Pointer to an [OH_Drawing_Path](#oh_drawing_path) object.| 
| OH_Drawing_RoundRect | Pointer to an [OH_Drawing_RoundRect](#oh_drawing_roundrect) object.| 
| OH_Drawing_PathDirection | Path direction. For details about the available options, see [OH_Drawing_PathDirection](#oh_drawing_pathdirection).| 


### OH_Drawing_PathArcTo()

```
void OH_Drawing_PathArcTo (OH_Drawing_Path* , float x1, float y1, float x2, float y2, float startDeg, float sweepDeg )
```

**Description**

Draws an arc to a path. This is done by using angle arc mode. In this mode, a rectangle that encloses an ellipse is specified first, and then a start angle and a sweep angle are specified. The arc is a portion of the ellipse defined by the start angle and the sweep angle. By default, a line segment from the last point of the path to the start point of the arc is also added.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Path | Pointer to an **OH_Drawing_Path** object.| 
| x1 | X coordinate of the upper left corner of the rectangle.| 
| y1 | Y coordinate of the upper left corner of the rectangle.| 
| x2 | X coordinate of the lower right corner of the rectangle.| 
| y2 | Y coordinate of the lower right corner of the rectangle.| 
| startDeg | Start angle.| 
| sweepDeg | Sweep degree.| 


### OH_Drawing_PathClose()

```
void OH_Drawing_PathClose (OH_Drawing_Path* )
```

**Description**

Closes a path by drawing a line segment from the current point to the start point of the path.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Path | Pointer to an **OH_Drawing_Path** object.| 


### OH_Drawing_PathContains()

```
bool OH_Drawing_PathContains (OH_Drawing_Path* , float x, float y )
```

**Description**

Checks whether a coordinate point is included in a path.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Path | Pointer to an [OH_Drawing_Path](#oh_drawing_path) object.| 
| x | Coordinate point on the X axis.| 
| y | Coordinate point on the X axis.| 

**Returns**

Returns **true** if the coordinate point is included in the path; returns **false** otherwise.


### OH_Drawing_PathCopy()

```
OH_Drawing_Path* OH_Drawing_PathCopy (OH_Drawing_Path* )
```

**Description**

Copies an existing [OH_Drawing_Path](#oh_drawing_path) object to create a new one.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Path | Pointer to an [OH_Drawing_Path](#oh_drawing_path) object.| 

**Returns**

Returns the pointer to the [OH_Drawing_Path](#oh_drawing_path) object created.


### OH_Drawing_PathCreate()

```
OH_Drawing_Path* OH_Drawing_PathCreate (void )
```

**Description**

Creates an **OH_Drawing_Path** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Returns**

Returns the pointer to the **OH_Drawing_Path** object created.


### OH_Drawing_PathCubicTo()

```
void OH_Drawing_PathCubicTo (OH_Drawing_Path* , float ctrlX1, float ctrlY1, float ctrlX2, float ctrlY2, float endX, float endY )
```

**Description**

Draws a cubic Bezier curve from the last point of a path to the target point.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Path | Pointer to an **OH_Drawing_Path** object.| 
| ctrlX1 | X coordinate of the first control point.| 
| ctrlY1 | Y coordinate of the first control point.| 
| ctrlX2 | X coordinate of the second control point.| 
| ctrlY2 | Y coordinate of the second control point.| 
| endX | X coordinate of the target point.| 
| endY | Y coordinate of the target point.| 


### OH_Drawing_PathDestroy()

```
void OH_Drawing_PathDestroy (OH_Drawing_Path* )
```

**Description**

Destroys an **OH_Drawing_Path** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Path | Pointer to an **OH_Drawing_Path** object.| 


### OH_Drawing_PathEffectDestroy()

```
void OH_Drawing_PathEffectDestroy (OH_Drawing_PathEffect* )
```

**Description**

Destroys an **OH_Drawing_PathEffect** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_PathEffect | Pointer to an [OH_Drawing_PathEffect](#oh_drawing_patheffect) object.| 


### OH_Drawing_PathLineTo()

```
void OH_Drawing_PathLineTo (OH_Drawing_Path* , float x, float y )
```

**Description**

Draws a line segment from the last point of a path to the target point.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Path | Pointer to an **OH_Drawing_Path** object.| 
| x | X coordinate of the target point.| 
| y | Y coordinate of the target point.| 


### OH_Drawing_PathMoveTo()

```
void OH_Drawing_PathMoveTo (OH_Drawing_Path* , float x, float y )
```

**Description**

Sets the start point of a path.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Path | Pointer to an **OH_Drawing_Path** object.| 
| x | X coordinate of the start point.| 
| y | Y coordinate of the start point.| 


### OH_Drawing_PathQuadTo()

```
void OH_Drawing_PathQuadTo (OH_Drawing_Path* , float ctrlX, float ctrlY, float endX, float endY )
```

**Description**

Draws a quadratic Bezier curve from the last point of a path to the target point.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Path | Pointer to an **OH_Drawing_Path** object.| 
| ctrlX | X coordinate of the control point.| 
| ctrlY | Y coordinate of the control point.| 
| endX | X coordinate of the target point.| 
| endY | Y coordinate of the target point.| 


### OH_Drawing_PathReset()

```
void OH_Drawing_PathReset (OH_Drawing_Path* )
```

**Description**

Resets path data.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Path | Pointer to an **OH_Drawing_Path** object.| 


### OH_Drawing_PathSetFillType()

```
void OH_Drawing_PathSetFillType (OH_Drawing_Path* , OH_Drawing_PathFillType  )
```

**Description**

Sets the fill type for a path.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Path | Pointer to an [OH_Drawing_Path](#oh_drawing_path) object.| 
| OH_Drawing_PathFillType | Fill type of the path. For details about the available options, see [OH_Drawing_PathFillType](#oh_drawing_pathfilltype).| 


### OH_Drawing_PathTransform()

```
void OH_Drawing_PathTransform (OH_Drawing_Path* , const OH_Drawing_Matrix*  )
```

**Description**

Transforms the points in a path by matrix.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Path | Pointer to an [OH_Drawing_Path](#oh_drawing_path) object.| 
| OH_Drawing_Matrix | Pointer to an [OH_Drawing_Matrix](#oh_drawing_matrix) object.| 


### OH_Drawing_PenCreate()

```
OH_Drawing_Pen* OH_Drawing_PenCreate (void )
```

**Description**

Creates an **OH_Drawing_Pen** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Returns**

Returns the pointer to the **OH_Drawing_Pen** object created.


### OH_Drawing_PenDestroy()

```
void OH_Drawing_PenDestroy (OH_Drawing_Pen* )
```

**Description**

Destroys an **OH_Drawing_Path** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Pen | Pointer to an **OH_Drawing_Pen** object.| 


### OH_Drawing_PenGetAlpha()

```
uint8_t OH_Drawing_PenGetAlpha (const OH_Drawing_Pen* )
```

**Description**

Obtains the alpha value of a pen. This value is used by the alpha channel when the pen outlines a shape.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Pen | Pointer to an **OH_Drawing_Pen** object.| 

**Returns**

Returns an 8-bit variable that describes the alpha value.


### OH_Drawing_PenGetCap()

```
OH_Drawing_PenLineCapStyle OH_Drawing_PenGetCap (const OH_Drawing_Pen* )
```

**Description**

Obtains the line cap style of a pen.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Pen | Pointer to an **OH_Drawing_Pen** object.| 

**Returns**

Returns the line cap style.


### OH_Drawing_PenGetColor()

```
uint32_t OH_Drawing_PenGetColor (const OH_Drawing_Pen* )
```

**Description**

Obtains the color of a pen. The color is used by the pen to outline a shape.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Pen | Pointer to an **OH_Drawing_Pen** object.| 

**Returns**

Returns a 32-bit (ARGB) variable that describes the color.


### OH_Drawing_PenGetJoin()

```
OH_Drawing_PenLineJoinStyle OH_Drawing_PenGetJoin (const OH_Drawing_Pen* )
```

**Description**

Obtains the line join style of a pen.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Pen | Pointer to an **OH_Drawing_Pen** object.| 

**Returns**

Returns the line join style.


### OH_Drawing_PenGetMiterLimit()

```
float OH_Drawing_PenGetMiterLimit (const OH_Drawing_Pen* )
```

**Description**

Obtains the stroke miter limit of a polyline drawn by a pen. When the corner type is bevel, a beveled corner is displayed if the miter limit is exceeded, and a mitered corner is displayed if the miter limit is not exceeded.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Pen | Pointer to an **OH_Drawing_Pen** object.| 

**Returns**

Returns the miter limit.


### OH_Drawing_PenGetWidth()

```
float OH_Drawing_PenGetWidth (const OH_Drawing_Pen* )
```

**Description**

Obtains the thickness of a pen. This thickness determines the width of the outline of a shape.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Pen | Pointer to an **OH_Drawing_Pen** object.| 

**Returns**

Returns the thickness.


### OH_Drawing_PenIsAntiAlias()

```
bool OH_Drawing_PenIsAntiAlias (const OH_Drawing_Pen* )
```

**Description**

Checks whether anti-aliasing is enabled for a pen. Anti-aliasing makes the pixels around the shape edges semi-transparent.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Pen | Pointer to an **OH_Drawing_Pen** object.| 

**Returns**

Returns **true** if anti-aliasing is enabled; returns **false** otherwise.


### OH_Drawing_PenSetAlpha()

```
void OH_Drawing_PenSetAlpha (OH_Drawing_Pen* , uint8_t alpha )
```

**Description**

Sets the alpha value for a pen. This value is used by the alpha channel when the pen outlines a shape.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Pen | Pointer to an **OH_Drawing_Pen** object.| 
| alpha | Alpha value, which is an 8-bit variable.| 


### OH_Drawing_PenSetAntiAlias()

```
void OH_Drawing_PenSetAntiAlias (OH_Drawing_Pen* , bool  )
```

**Description**

Enables or disables anti-aliasing for a pen. Anti-aliasing makes the pixels around the shape edges semi-transparent.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Pen | Pointer to an **OH_Drawing_Pen** object.| 
| bool | Whether to enable anti-aliasing. The value **true** means to enable anti-aliasing, and **false** means the opposite.| 


### OH_Drawing_PenSetBlendMode()

```
void OH_Drawing_PenSetBlendMode (OH_Drawing_Pen* , OH_Drawing_BlendMode  )
```

**Description**

Sets a blender for a pen. The blender implements the specified blend mode.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Pen | Pointer to an [OH_Drawing_Pen](#oh_drawing_pen) object.| 
| OH_Drawing_BlendMode | Blend mode. For details about the available options, see [OH_Drawing_BlendMode](#oh_drawing_blendmode).| 


### OH_Drawing_PenSetCap()

```
void OH_Drawing_PenSetCap (OH_Drawing_Pen* , OH_Drawing_PenLineCapStyle  )
```

**Description**

Sets the line cap style for a pen.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Pen | Pointer to an **OH_Drawing_Pen** object.| 
| OH_Drawing_PenLineCapStyle | Line cap style, which is a variable.| 


### OH_Drawing_PenSetColor()

```
void OH_Drawing_PenSetColor (OH_Drawing_Pen* , uint32_t color )
```

**Description**

Sets the color for a pen. The color is used by the pen to outline a shape.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Pen | Pointer to an **OH_Drawing_Pen** object.| 
| color | Color, which is a 32-bit (ARGB) variable.| 


### OH_Drawing_PenSetFilter()

```
void OH_Drawing_PenSetFilter (OH_Drawing_Pen* , OH_Drawing_Filter*  )
```

**Description**

Sets a filter for a pen.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Pen | Pointer to an [OH_Drawing_Pen](#oh_drawing_pen) object.| 
| OH_Drawing_Filter | Pointer to an [OH_Drawing_Filter](#oh_drawing_filter) object.| 


### OH_Drawing_PenSetJoin()

```
void OH_Drawing_PenSetJoin (OH_Drawing_Pen* , OH_Drawing_PenLineJoinStyle  )
```

**Description**

Sets the line join style for a pen.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Pen | Pointer to an **OH_Drawing_Pen** object.| 
| OH_Drawing_PenLineJoinStyle | Line join style.| 


### OH_Drawing_PenSetMiterLimit()

```
void OH_Drawing_PenSetMiterLimit (OH_Drawing_Pen* , float miter )
```

**Description**

Sets the stroke miter limit for a polyline drawn by a pen. When the corner type is bevel, a beveled corner is displayed if the miter limit is exceeded, and a mitered corner is displayed if the miter limit is not exceeded.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Pen | Pointer to an **OH_Drawing_Pen** object.| 
| miter | Stroke miter limit, which is a variable.| 


### OH_Drawing_PenSetPathEffect()

```
void OH_Drawing_PenSetPathEffect (OH_Drawing_Pen* , OH_Drawing_PathEffect*  )
```

**Description**

Sets the path effect for a pen.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Pen | Pointer to an [OH_Drawing_Pen](#oh_drawing_pen) object.| 
| OH_Drawing_PathEffect | Pointer to an [OH_Drawing_PathEffect](#oh_drawing_patheffect) object.| 


### OH_Drawing_PenSetShaderEffect()

```
void OH_Drawing_PenSetShaderEffect (OH_Drawing_Pen* , OH_Drawing_ShaderEffect*  )
```

**Description**

Sets the shader effect for a pen.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Pen | Pointer to an [OH_Drawing_Pen](#oh_drawing_pen) object.| 
| OH_Drawing_ShaderEffect | Pointer to an [OH_Drawing_ShaderEffect](#oh_drawing_shadereffect) object.| 


### OH_Drawing_PenSetWidth()

```
void OH_Drawing_PenSetWidth (OH_Drawing_Pen* , float width )
```

**Description**

Sets the thickness for a pen. This thickness determines the width of the outline of a shape.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Pen | Pointer to an **OH_Drawing_Pen** object.| 
| width | Thickness, which is a variable.| 


### OH_Drawing_PointCreate()

```
OH_Drawing_Point* OH_Drawing_PointCreate (float x, float y )
```

**Description**

Creates an **OH_Drawing_Point** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| x | X coordinate of the point.| 
| y | Y coordinate of the point.| 

**Returns**

Returns the pointer to the **OH_Drawing_Point** object created.


### OH_Drawing_PointDestroy()

```
void OH_Drawing_PointDestroy (OH_Drawing_Point* )
```

**Description**

Destroys an **OH_Drawing_Point** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Point | Pointer to an **OH_Drawing_Point** object.| 


### OH_Drawing_RectCreate()

```
OH_Drawing_Rect* OH_Drawing_RectCreate (float left, float top, float right, float bottom )
```

**Description**

Creates an **OH_Drawing_Rect** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| left | X coordinate of the upper left corner of the rectangle.| 
| top | Y coordinate of the upper left corner of the rectangle.| 
| right | X coordinate of the lower right corner of the rectangle.| 
| bottom | Y coordinate of the lower right corner of the rectangle.| 

**Returns**

Returns the pointer to the **OH_Drawing_Rect** object created.


### OH_Drawing_RectDestroy()

```
void OH_Drawing_RectDestroy (OH_Drawing_Rect* )
```

**Description**

Destroys an **OH_Drawing_Rect** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Rect | Pointer to an **OH_Drawing_Rect** object.| 

### OH_Drawing_RegisterFont()

```
uint32_t OH_Drawing_RegisterFont (OH_Drawing_FontCollection* , const char* fontFamily, const char* familySrc )
```

**Description**

Registers a custom font with the font manager.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_FontCollection | Pointer to an [OH_Drawing_FontCollection](#oh_drawing_fontcollection) object.| 
| fontFamily | Pointer to the family name of the font to register.| 
| familySrc | Pointer to the path of the font file.| 

**Returns**

Returns **0** if the font is registered; returns **1** if the file does not exist; returns **2** if the file fails to be opened; returns **3** if the file fails to be read; returns **4** if the file fails to be found; returns **5** if the file size fails to be obtained.


### OH_Drawing_RegisterFontBuffer()

```
uint32_t OH_Drawing_RegisterFontBuffer (OH_Drawing_FontCollection* , const char* fontFamily, uint8_t* fontBuffer, size_t length )
```

**Description**

Registers a font buffer with the font manager.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_FontCollection | Pointer to an [OH_Drawing_FontCollection](#oh_drawing_fontcollection) object.| 
| fontFamily | Pointer to the family name of the font to register.| 
| fontBuffer | Pointer to the buffer of the font file.| 
| length | Length of the font file.| 

**Returns**

Returns **0** if the font is registered; returns **6** if the buffer size is zero; returns **7** if the font set is empty.

### OH_Drawing_RoundRectCreate()

```
OH_Drawing_RoundRect* OH_Drawing_RoundRectCreate (const OH_Drawing_Rect* , float xRad, float yRad )
```

**Description**

Creates an **OH_Drawing_RoundRect** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Rect | Pointer to an **OH_Drawing_Rect** object.| 
| xRad | Radius of the rounded corner on the X axis.| 
| yRad | Radius of the rounded corner on the Y axis.| 

**Returns**

Returns the pointer to the **OH_Drawing_RoundRect** object created.


### OH_Drawing_RoundRectDestroy()

```
void OH_Drawing_RoundRectDestroy (OH_Drawing_RoundRect* )
```

**Description**

Destroys an **OH_Drawing_RoundRect** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_RoundRect | Pointer to an **OH_Drawing_RoundRect** object.| 


### OH_Drawing_SamplingOptionsCreate()

```
OH_Drawing_SamplingOptions* OH_Drawing_SamplingOptionsCreate (OH_Drawing_FilterMode , OH_Drawing_MipmapMode  )
```

**Description**

Creates an **OH_Drawing_SamplingOptions** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_FilterMode | Filter mode. For details about the available options, see [OH_Drawing_FilterMode](#oh_drawing_filtermode).| 
| OH_Drawing_MipmapMode | Mipmap mode. For details about the available options, see [OH_Drawing_MipmapMode](#oh_drawing_mipmapmode).| 

**Returns**

Returns the pointer to the [OH_Drawing_SamplingOptions](#oh_drawing_samplingoptions) object created.


### OH_Drawing_SamplingOptionsDestroy()

```
void OH_Drawing_SamplingOptionsDestroy (OH_Drawing_SamplingOptions* )
```

**Description**

Destroys an **OH_Drawing_SamplingOptions** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_SamplingOptions | Pointer to an [OH_Drawing_SamplingOptions](#oh_drawing_samplingoptions) object.| 


### OH_Drawing_SetTextStyleBackgroundBrush()

```
void OH_Drawing_SetTextStyleBackgroundBrush (OH_Drawing_TextStyle* , OH_Drawing_Brush*  )
```

**Description**

Sets the background brush.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TextStyle | Pointer to an [OH_Drawing_TextStyle](#oh_drawing_textstyle) object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle).| 
| OH_Drawing_Brush | Pointer to an [OH_Drawing_Brush](#oh_drawing_brush) object, which is obtained by calling [OH_Drawing_BrushCreate](#oh_drawing_brushcreate).| 


### OH_Drawing_SetTextStyleBackgroundPen()

```
void OH_Drawing_SetTextStyleBackgroundPen (OH_Drawing_TextStyle* , OH_Drawing_Pen*  )
```

**Description**

Sets the background pen.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TextStyle | Pointer to an [OH_Drawing_TextStyle](#oh_drawing_textstyle) object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle).| 
| OH_Drawing_Pen | Pointer to an [OH_Drawing_Pen](#oh_drawing_pen) object, which is obtained by calling [OH_Drawing_PenCreate](#oh_drawing_pencreate).| 


### OH_Drawing_SetTextStyleBaseLine()

```
void OH_Drawing_SetTextStyleBaseLine (OH_Drawing_TextStyle* , int  )
```

**Description**

Sets the text baseline.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object, which is obtained by [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle).| 
| int | Text baseline. For details about the available options, see [OH_Drawing_TextBaseline](#oh_drawing_textbaseline).| 


### OH_Drawing_SetTextStyleColor()

```
void OH_Drawing_SetTextStyleColor (OH_Drawing_TextStyle* , uint32_t  )
```

**Description**

Sets the text color.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object, which is obtained by [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle).| 
| uint32_t | Color.| 


### OH_Drawing_SetTextStyleDecoration()

```
void OH_Drawing_SetTextStyleDecoration (OH_Drawing_TextStyle* , int  )
```

**Description**

Sets the text decoration.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object, which is obtained by [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle).| 
| int | Text decoration. For details about the available options, see [OH_Drawing_TextDecoration](#oh_drawing_textdecoration).| 


### OH_Drawing_SetTextStyleDecorationColor()

```
void OH_Drawing_SetTextStyleDecorationColor (OH_Drawing_TextStyle* , uint32_t  )
```

**Description**

Sets the color for the text decoration.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object, which is obtained by [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle).| 
| uint32_t | Color.| 


### OH_Drawing_SetTextStyleDecorationStyle()

```
void OH_Drawing_SetTextStyleDecorationStyle (OH_Drawing_TextStyle* , int  )
```

**Description**

Sets the text decoration style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object, which is obtained by [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle).| 
| int | Text decoration style. For details about the available options, see [OH_Drawing_TextDecorationStyle](#oh_drawing_textdecorationstyle).| 


### OH_Drawing_SetTextStyleDecorationThicknessScale()

```
void OH_Drawing_SetTextStyleDecorationThicknessScale (OH_Drawing_TextStyle* , double  )
```

**Description**

Sets the thickness scale factor of the text decoration line.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object, which is obtained by [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle).| 
| double | Scale factor.| 


### OH_Drawing_SetTextStyleEllipsis()

```
void OH_Drawing_SetTextStyleEllipsis (OH_Drawing_TextStyle* , const char *  )
```

**Description**

Sets the ellipsis content for text.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object, which is obtained by [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle).| 
| char\* | Pointer to the ellipsis content. The data type is a pointer pointing to char.| 


### OH_Drawing_SetTextStyleEllipsisModal()

```
void OH_Drawing_SetTextStyleEllipsisModal (OH_Drawing_TextStyle* , int  )
```

**Description**

Sets the ellipsis style for text.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object, which is obtained by [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle).| 
| int | Ellipsis style. For details about the available options, see [OH_Drawing_EllipsisModal](#oh_drawing_ellipsismodal).| 


### OH_Drawing_SetTextStyleFontFamilies()

```
void OH_Drawing_SetTextStyleFontFamilies (OH_Drawing_TextStyle* , int , const char * fontFamilies[] )
```

**Description**

Sets the font families.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object, which is obtained by [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle).| 
| int | Number of font families.| 
| char | Pointer to the font families.| 


### OH_Drawing_SetTextStyleFontHeight()

```
void OH_Drawing_SetTextStyleFontHeight (OH_Drawing_TextStyle* , double  )
```

**Description**

Sets the font height.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object, which is obtained by [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle).| 
| double | Font height.| 


### OH_Drawing_SetTextStyleFontSize()

```
void OH_Drawing_SetTextStyleFontSize (OH_Drawing_TextStyle* , double  )
```

**Description**

Sets the font size.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object, which is obtained by [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle).| 
| double | Font size.| 


### OH_Drawing_SetTextStyleFontStyle()

```
void OH_Drawing_SetTextStyleFontStyle (OH_Drawing_TextStyle* , int  )
```

**Description**

Sets the font style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object, which is obtained by [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle).| 
| int | Font style. For details about the available options, see [OH_Drawing_FontStyle](#oh_drawing_fontstyle).| 


### OH_Drawing_SetTextStyleFontWeight()

```
void OH_Drawing_SetTextStyleFontWeight (OH_Drawing_TextStyle* , int  )
```

**Description**

Sets the font weight.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object, which is obtained by [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle).| 
| int | Font weight. For details about the available options, see [OH_Drawing_FontWeight](#oh_drawing_fontweight).| 


### OH_Drawing_SetTextStyleForegroundBrush()

```
void OH_Drawing_SetTextStyleForegroundBrush (OH_Drawing_TextStyle* , OH_Drawing_Brush*  )
```

**Description**

Sets the foreground brush.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TextStyle | Pointer to an [OH_Drawing_TextStyle](#oh_drawing_textstyle) object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle).| 
| OH_Drawing_Brush | Pointer to an [OH_Drawing_Brush](#oh_drawing_brush) object, which is obtained by calling [OH_Drawing_BrushCreate](#oh_drawing_brushcreate).| 


### OH_Drawing_SetTextStyleForegroundPen()

```
void OH_Drawing_SetTextStyleForegroundPen (OH_Drawing_TextStyle* , OH_Drawing_Pen*  )
```

**Description**

Sets the foreground pen.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TextStyle | Pointer to an [OH_Drawing_TextStyle](#oh_drawing_textstyle) object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle).| 
| OH_Drawing_Pen | Pointer to an [OH_Drawing_Pen](#oh_drawing_pen) object, which is obtained by calling [OH_Drawing_PenCreate](#oh_drawing_pencreate).| 
### OH_Drawing_SetTextStyleHalfLeading()

```
void OH_Drawing_SetTextStyleHalfLeading (OH_Drawing_TextStyle* , bool  )
```

**Description**

Sets half leading for text.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object, which is obtained by [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle).| 
| bool | Whether to enable half leading. The value **true** means to enable half lading, and **false** means the opposite.| 


### OH_Drawing_SetTextStyleLetterSpacing()

```
void OH_Drawing_SetTextStyleLetterSpacing (OH_Drawing_TextStyle* , double  )
```

**Description**

Sets the letter spacing for text.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object, which is obtained by [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle).| 
| double | Letter spacing.| 


### OH_Drawing_SetTextStyleLocale()

```
void OH_Drawing_SetTextStyleLocale (OH_Drawing_TextStyle* , const char*  )
```

**Description**

Sets the locale.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object, which is obtained by [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle).| 
| char | Pointer to the locale.| 


### OH_Drawing_SetTextStyleWordSpacing()

```
void OH_Drawing_SetTextStyleWordSpacing (OH_Drawing_TextStyle* , double  )
```

**Description**

Sets the word spacing for text.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object, which is obtained by [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle).| 
| double | Word spacing.| 


### OH_Drawing_SetTypographyTextAlign()

```
void OH_Drawing_SetTypographyTextAlign (OH_Drawing_TypographyStyle* , int  )
```

**Description**

Sets the text alignment mode.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TypographyStyle | Pointer to an **OH_Drawing_TypographyStyle** object, which is obtained by [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle).| 
| int | Text alignment mode. For details about the available options, see [OH_Drawing_TextAlign](#oh_drawing_textalign).| 


### OH_Drawing_SetTypographyTextBreakStrategy()

```
void OH_Drawing_SetTypographyTextBreakStrategy (OH_Drawing_TypographyStyle* , int  )
```

**Description**

Sets the text break strategy.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TypographyStyle | Pointer to an **OH_Drawing_TypographyStyle** object, which is obtained by [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle).| 
| int | Text break strategy. For details about the available options, see [OH_Drawing_BreakStrategy](#oh_drawing_breakstrategy).| 


### OH_Drawing_SetTypographyTextDirection()

```
void OH_Drawing_SetTypographyTextDirection (OH_Drawing_TypographyStyle* , int  )
```

**Description**

Sets the text direction.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TypographyStyle | Pointer to an **OH_Drawing_TypographyStyle** object, which is obtained by [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle).| 
| int | Text direction. For details about the available options, see [OH_Drawing_TextDirection](#oh_drawing_textdirection).| 


### OH_Drawing_SetTypographyTextEllipsis()

```
void OH_Drawing_SetTypographyTextEllipsis (OH_Drawing_TypographyStyle* style, const char* ellipsis )
```

**Description**

Sets the ellipsis style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle).| 
| char | Pinter to an ellipsis style.| 


### OH_Drawing_SetTypographyTextEllipsisModal()

```
void OH_Drawing_SetTypographyTextEllipsisModal (OH_Drawing_TypographyStyle* , int  )
```

**Description**

Sets the ellipsis style for text.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TypographyStyle | Pointer to an **OH_Drawing_TypographyStyle** object, which is obtained by [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle).| 
| int | Ellipsis style. For details about the available options, see [OH_Drawing_EllipsisModal](#oh_drawing_ellipsismodal).| 


### OH_Drawing_SetTypographyTextFontFamily()

```
void OH_Drawing_SetTypographyTextFontFamily (OH_Drawing_TypographyStyle* , const char*  )
```

**Description**

Sets the font family name for text.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle).| 
| char | Pointer to the name of the font family.| 


### OH_Drawing_SetTypographyTextFontHeight()

```
void OH_Drawing_SetTypographyTextFontHeight (OH_Drawing_TypographyStyle* , double  )
```

**Description**

Sets the font height for text.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle).| 
| double | Font height.| 


### OH_Drawing_SetTypographyTextFontSize()

```
void OH_Drawing_SetTypographyTextFontSize (OH_Drawing_TypographyStyle* , double  )
```

**Description**

Sets the font size for text.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle).| 
| double | Font size, which must be greater than 0.| 

### OH_Drawing_SetTypographyTextLineStyleFontSize()

```
void OH_Drawing_SetTypographyTextLineStyleFontSize (OH_Drawing_TypographyStyle* , double  )
```

**Description**

Sets the font size for a text line.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle).| 
| double | Font size, which must be greater than 0.| 

### OH_Drawing_SetTypographyTextFontStyle()

```
void OH_Drawing_SetTypographyTextFontStyle (OH_Drawing_TypographyStyle* , int  )
```

**Description**

Sets the font style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle).| 
| int | Font style. For details about the available options, see [OH_Drawing_FontStyle](#oh_drawing_fontstyle).| 


### OH_Drawing_SetTypographyTextFontWeight()

```
void OH_Drawing_SetTypographyTextFontWeight (OH_Drawing_TypographyStyle* , int  )
```

**Description**

Sets the font weight for text.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle).| 
| int | Font weight. For details about the available options, see [OH_Drawing_FontWeight](#oh_drawing_fontweight).| 


### OH_Drawing_SetTypographyTextHalfLeading()

```
void OH_Drawing_SetTypographyTextHalfLeading (OH_Drawing_TypographyStyle* , bool  )
```

**Description**

Sets whether half leading is used for text.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle).| 
| bool | Whether to enable half leading. The value **true** means to enable half lading, and **false** means the opposite.| 


### OH_Drawing_SetTypographyTextLineStyleFontFamilies()

```
void OH_Drawing_SetTypographyTextLineStyleFontFamilies (OH_Drawing_TypographyStyle* , int , const char * fontFamilies[] )
```

**Description**

Sets the font families of the text line style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle).| 
| int | Number of font families.| 
| char | Pointer to the font families.| 


### OH_Drawing_SetTypographyTextLineStyleFontHeight()

```
void OH_Drawing_SetTypographyTextLineStyleFontHeight (OH_Drawing_TypographyStyle* , double  )
```

**Description**

Sets the font height of the text line style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle).| 
| double | Font height.| 


### OH_Drawing_SetTypographyTextLineStyleFontStyle()

```
void OH_Drawing_SetTypographyTextLineStyleFontStyle (OH_Drawing_TypographyStyle* , int  )
```

**Description**

Sets the font style of the text line style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle).| 
| int | Font style. For details about the available options, see [OH_Drawing_FontStyle](#oh_drawing_fontstyle).| 


### OH_Drawing_SetTypographyTextLineStyleFontWeight()

```
void OH_Drawing_SetTypographyTextLineStyleFontWeight (OH_Drawing_TypographyStyle* , int  )
```

**Description**

Sets the font weight of the text line style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle).| 
| int | Font weight. For details about the available options, see [OH_Drawing_FontWeight](#oh_drawing_fontweight).| 


### OH_Drawing_SetTypographyTextLineStyleHalfLeading()

```
void OH_Drawing_SetTypographyTextLineStyleHalfLeading (OH_Drawing_TypographyStyle* , bool  )
```

**Description**

Sets whether half leading is used for the text line style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle).| 
| bool | Whether to enable half leading. The value **true** means to enable half lading, and **false** means the opposite.| 


### OH_Drawing_SetTypographyTextLineStyleOnly()

```
void OH_Drawing_SetTypographyTextLineStyleOnly (OH_Drawing_TypographyStyle* , bool  )
```

**Description**

Sets whether to enable the text line style only.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle).| 
| bool | Whether to enable the text line style only. The value **true** means to enable the text line style only, and **false** means the opposite.| 


### OH_Drawing_SetTypographyTextLineStyleSpacingScale()

```
void OH_Drawing_SetTypographyTextLineStyleSpacingScale (OH_Drawing_TypographyStyle* , double  )
```

**Description**

Sets the spacing ratio of the text line style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle).| 
| double | Spacing ratio.| 


### OH_Drawing_SetTypographyTextLocale()

```
void OH_Drawing_SetTypographyTextLocale (OH_Drawing_TypographyStyle* style, const char * locale )
```

**Description**

Sets the text locale.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle).| 
| char | Pointer to the text locale.| 


### OH_Drawing_SetTypographyTextMaxLines()

```
void OH_Drawing_SetTypographyTextMaxLines (OH_Drawing_TypographyStyle* , int  )
```

**Description**

Sets the maximum number of lines in the text.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TypographyStyle | Pointer to an **OH_Drawing_TypographyStyle** object, which is obtained by [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle).| 
| int | Maximum number of lines.| 


### OH_Drawing_SetTypographyTextSplitRatio()

```
void OH_Drawing_SetTypographyTextSplitRatio (OH_Drawing_TypographyStyle* style, float textSplitRatio )
```

**Description**

Sets the text split ratio.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle).| 
| float | Text split ratio.| 


### OH_Drawing_SetTypographyTextStyle()

```
void OH_Drawing_SetTypographyTextStyle (OH_Drawing_TypographyStyle* , OH_Drawing_TextStyle*  )
```

**Description**

Sets the text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle).| 
| OH_Drawing_TextStyle | Pointer to an [OH_Drawing_TextStyle](#oh_drawing_textstyle) object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle).| 


### OH_Drawing_SetTypographyTextUseLineStyle()

```
void OH_Drawing_SetTypographyTextUseLineStyle (OH_Drawing_TypographyStyle* , bool  )
```

**Description**

Sets whether to enable the line style for text.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle).| 
| bool | Whether to enable the line style for text. The value **true** means to enable the line style for text, and **false** means the opposite.| 


### OH_Drawing_SetTypographyTextWordBreakType()

```
void OH_Drawing_SetTypographyTextWordBreakType (OH_Drawing_TypographyStyle* , int  )
```

**Description**

Sets the word break type.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TypographyStyle | Pointer to an **OH_Drawing_TypographyStyle** object, which is obtained by [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle).| 
| int | Word break type. For details about the available options, see [OH_Drawing_WordBreakType](#oh_drawing_wordbreaktype).| 


### OH_Drawing_ShaderEffectCreateLinearGradient()

```
OH_Drawing_ShaderEffect* OH_Drawing_ShaderEffectCreateLinearGradient (const OH_Drawing_Point* startPt, const OH_Drawing_Point* endPt, const uint32_t* colors, const float* pos, uint32_t size, OH_Drawing_TileMode  )
```

**Description**

Creates an **OH_Drawing_ShaderEffect** object that generates a linear gradient between two points.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| startPt | Start point.| 
| endPt | End point.| 
| colors | Colors to distribute.| 
| pos | Relative position of each color in the color array.| 
| size | Number of colors and positions.| 
| OH_Drawing_TileMode | Tile mode of the shader effect. For details about the available options, see {\@Link OH_Drawing_TileMoe}.| 

**Returns**

Returns the pointer to the **OH_Drawing_ShaderEffect** object created.


### OH_Drawing_ShaderEffectCreateRadialGradient()

```
OH_Drawing_ShaderEffect* OH_Drawing_ShaderEffectCreateRadialGradient (const OH_Drawing_Point* centerPt, float radius, const uint32_t* colors, const float* pos, uint32_t size, OH_Drawing_TileMode  )
```

**Description**

Creates an **OH_Drawing_ShaderEffect** object that generates a radial gradient based on the center and radius of a circle. The radial gradient transitions colors from the center to the ending shape in a radial manner.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| centerPt | Center of the circle.| 
| radius | Radius of the circle.| 
| colors | Colors to distribute.| 
| pos | Relative position of each color in the color array.| 
| size | Number of colors and positions.| 
| OH_Drawing_TileMode | Tile mode of the shader effect. For details about the available options, see {\@Link OH_Drawing_TileMoe}.| 

**Returns**

Returns the pointer to the **OH_Drawing_ShaderEffect** object created.

### OH_Drawing_ShaderEffectCreateSweepGradient()

```
OH_Drawing_ShaderEffect* OH_Drawing_ShaderEffectCreateSweepGradient (const OH_Drawing_Point* centerPt, const uint32_t* colors, const float* pos, uint32_t size, OH_Drawing_TileMode  )
```

**Description**

Creates an **OH_Drawing_ShaderEffect** object that generates a sweep gradient based on the center.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| centerPt | Center of the circle.| 
| colors | Colors to distribute.| 
| pos | Relative position of each color in the color array.| 
| size | Number of colors and positions.| 
| OH_Drawing_TileMode | Tile mode of the shader effect. For details about the available options, see {\@Link OH_Drawing_TileMoe}.| 

**Returns**

Returns the pointer to the **OH_Drawing_ShaderEffect** object created.


### OH_Drawing_ShaderEffectDestroy()

```
void OH_Drawing_ShaderEffectDestroy (OH_Drawing_ShaderEffect* )
```

**Description**

Destroys an **OH_Drawing_ShaderEffect** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_ShaderEffect | Pointer to an **OH_Drawing_ShaderEffect** object.| 


### OH_Drawing_TextBlobBuilderAllocRunPos()

```
const OH_Drawing_RunBuffer* OH_Drawing_TextBlobBuilderAllocRunPos (OH_Drawing_TextBlobBuilder* , const OH_Drawing_Font* , int32_t count, const OH_Drawing_Rect*  )
```

**Description**

Allocates a run to store glyphs and positions. The pointer returned does not need to be managed by the caller. It can no longer be used after [OH_Drawing_TextBlobBuilderMake](#oh_drawing_textblobbuildermake) is called.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TextBlobBuilder | Pointer to an **OH_Drawing_TextBlobBuilder** object.| 
| OH_Drawing_Font | Pointer to an **OH_Drawing_Font** object.| 
| count | Number of text blobs.| 
| OH_Drawing_Rect | Rectangle of the text blob.| 


### OH_Drawing_TextBlobBuilderCreate()

```
OH_Drawing_TextBlobBuilder* OH_Drawing_TextBlobBuilderCreate (void )
```

**Description**

Creates an **OH_Drawing_TextBlobBuilder** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Returns**

Returns the pointer to the **OH_Drawing_TextBlobBuilder** object created.


### OH_Drawing_TextBlobBuilderDestroy()

```
void OH_Drawing_TextBlobBuilderDestroy (OH_Drawing_TextBlobBuilder* )
```

**Description**

Destroys an **OH_Drawing_TextBlobBuilder** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TextBlobBuilder | Pointer to an **OH_Drawing_TextBlobBuilder** object.| 


### OH_Drawing_TextBlobBuilderMake()

```
OH_Drawing_TextBlob* OH_Drawing_TextBlobBuilderMake (OH_Drawing_TextBlobBuilder* )
```

**Description**

Makes an **OH_Drawing_TextBlob** object from an **OH_Drawing_TextBlobBuilder**.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TextBlobBuilder | Pointer to an **OH_Drawing_TextBlobBuilder** object.| 

**Returns**

Returns the pointer to the **OH_Drawing_TextBlob** object created.


### OH_Drawing_TextBlobCreateFromPosText()

```
OH_Drawing_TextBlob* OH_Drawing_TextBlobCreateFromPosText (const void* text, size_t byteLength, OH_Drawing_Point2D* , const OH_Drawing_Font* , OH_Drawing_TextEncoding  )
```

**Description**

Creates an **OH_Drawing_TextBlob** object from the text and text position.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| text | Pointer to the text.| 
| byteLength | Length of the text, in bytes.| 
| [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) | Pointer to the start address of an [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) array. The number of entries in the array is the value obtained by calling [OH_Drawing_FontCountText](#oh_drawing_fontcounttext).| 
| OH_Drawing_Font | Pointer to an [OH_Drawing_Font](#oh_drawing_font) object.| 
| OH_Drawing_TextEncoding | Encoding type of the text. For details about the available options, see [OH_Drawing_TextEncoding](#oh_drawing_textencoding).| 

**Returns**

Returns the pointer to the [OH_Drawing_TextBlob](#oh_drawing_textblob) object created.


### OH_Drawing_TextBlobCreateFromString()

```
OH_Drawing_TextBlob* OH_Drawing_TextBlobCreateFromString (const char* str, const OH_Drawing_Font* , OH_Drawing_TextEncoding  )
```

**Description**

Creates an **OH_Drawing_TextBlob** object from a string.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| str | Pointer to a string.| 
| OH_Drawing_Font | Pointer to an [OH_Drawing_Font](#oh_drawing_font) object.| 
| OH_Drawing_TextEncoding | Encoding type of the text. For details about the available options, see [OH_Drawing_TextEncoding](#oh_drawing_textencoding).| 

**Returns**

Returns the pointer to the [OH_Drawing_TextBlob](#oh_drawing_textblob) object created.


### OH_Drawing_TextBlobCreateFromText()

```
OH_Drawing_TextBlob* OH_Drawing_TextBlobCreateFromText (const void* text, size_t byteLength, const OH_Drawing_Font* , OH_Drawing_TextEncoding  )
```

**Description**

Creates an **OH_Drawing_TextBlob** object from the text.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| text | Pointer to the text.| 
| byteLength | Length of the text, in bytes.| 
| OH_Drawing_Font | Pointer to an [OH_Drawing_Font](#oh_drawing_font) object.| 
| OH_Drawing_TextEncoding | Encoding type of the text. For details about the available options, see [OH_Drawing_TextEncoding](#oh_drawing_textencoding).| 

**Returns**

Returns the pointer to the [OH_Drawing_TextBlob](#oh_drawing_textblob) object created.


### OH_Drawing_TextBlobDestroy()

```
void OH_Drawing_TextBlobDestroy (OH_Drawing_TextBlob* )
```

**Description**

Destroys an **OH_Drawing_TextBlob** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TextBlob | Pointer to an **OH_Drawing_TextBlob** object.| 


### OH_Drawing_TextBlobGetBounds()

```
void OH_Drawing_TextBlobGetBounds (OH_Drawing_TextBlob* , OH_Drawing_Rect*  )
```

**Description**

Obtains the bounds of an **OH_Drawing_TextBlob** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TextBlob | Pointer to an [OH_Drawing_TextBlob](#oh_drawing_textblob) object.| 
| OH_Drawing_Rect | Pointer to an [OH_Drawing_Rect](#oh_drawing_rect) object, which is obtained by calling [OH_Drawing_RectCreate](#oh_drawing_rectcreate).| 


### OH_Drawing_TextStyleAddShadow()

```
void OH_Drawing_TextStyleAddShadow (OH_Drawing_TextStyle* , const OH_Drawing_TextShadow*  )
```

**Description**

Adds a shadow to a text shadow container.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TextStyle | Pointer to an [OH_Drawing_TextStyle](#oh_drawing_textstyle) object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle).| 
| OH_Drawing_TextShadow | Pointer to an [OH_Drawing_TextShadow](#oh_drawing_textshadow) object, which is obtained by calling [OH_Drawing_CreateTextShadow](#oh_drawing_createtextshadow).| 


### OH_Drawing_TextStyleClearShadows()

```
void OH_Drawing_TextStyleClearShadows (OH_Drawing_TextStyle* )
```

**Description**

Clears all shadows in a text shadow container.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TextStyle | Pointer to an [OH_Drawing_TextStyle](#oh_drawing_textstyle) object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle).| 


### OH_Drawing_TextStyleGetBackgroundBrush()

```
void OH_Drawing_TextStyleGetBackgroundBrush (OH_Drawing_TextStyle* , OH_Drawing_Brush*  )
```

**Description**

Obtains the background brush.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TextStyle | Pointer to an [OH_Drawing_TextStyle](#oh_drawing_textstyle) object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle).| 
| OH_Drawing_Brush | Pointer to an [OH_Drawing_Brush](#oh_drawing_brush) object, which is obtained by calling [OH_Drawing_BrushCreate](#oh_drawing_brushcreate).| 


### OH_Drawing_TextStyleGetBackgroundPen()

```
void OH_Drawing_TextStyleGetBackgroundPen (OH_Drawing_TextStyle* , OH_Drawing_Pen*  )
```

**Description**

Obtains the background pen.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TextStyle | Pointer to an [OH_Drawing_TextStyle](#oh_drawing_textstyle) object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle).| 
| OH_Drawing_Pen | Pointer to an [OH_Drawing_Pen](#oh_drawing_pen) object, which is obtained by calling [OH_Drawing_PenCreate](#oh_drawing_pencreate).| 


### OH_Drawing_TextStyleGetFontMetrics()

```
bool OH_Drawing_TextStyleGetFontMetrics (OH_Drawing_Typography* , OH_Drawing_TextStyle* , OH_Drawing_Font_Metrics*  )
```

**Description**

Obtains the font metrics.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Typography | Pointer to an [OH_Drawing_Typography](#oh_drawing_typography) object, which is obtained by calling [OH_Drawing_CreateTypography](#oh_drawing_createtypography).| 
| OH_Drawing_TextStyle | Pointer to an [OH_Drawing_TextStyle](#oh_drawing_textstyle) object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle).| 
| [OH_Drawing_Font_Metrics](_o_h___drawing___font___metrics.md) | Pointer to an [OH_Drawing_Font_Metrics](_o_h___drawing___font___metrics.md) object, which is obtained by calling [OH_Drawing_Font_Metrics](_o_h___drawing___font___metrics.md).| 

**Returns**

Returns **true** if the font metrics is obtained; returns **false** otherwise.


### OH_Drawing_TextStyleGetForegroundBrush()

```
void OH_Drawing_TextStyleGetForegroundBrush (OH_Drawing_TextStyle* , OH_Drawing_Brush*  )
```

**Description**

Obtains the foreground brush.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TextStyle | Pointer to an [OH_Drawing_TextStyle](#oh_drawing_textstyle) object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle).| 
| OH_Drawing_Brush | Pointer to an [OH_Drawing_Brush](#oh_drawing_brush) object, which is obtained by calling [OH_Drawing_BrushCreate](#oh_drawing_brushcreate).| 


### OH_Drawing_TextStyleGetForegroundPen()

```
void OH_Drawing_TextStyleGetForegroundPen (OH_Drawing_TextStyle* , OH_Drawing_Pen*  )
```

**Description**

Obtains the foreground pen.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TextStyle | Pointer to an [OH_Drawing_TextStyle](#oh_drawing_textstyle) object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle).| 
| OH_Drawing_Pen | Pointer to an [OH_Drawing_Pen](#oh_drawing_pen) object, which is obtained by calling [OH_Drawing_PenCreate](#oh_drawing_pencreate).| 


### OH_Drawing_TextStyleGetShadowCount()

```
int OH_Drawing_TextStyleGetShadowCount (OH_Drawing_TextStyle* )
```

**Description**

Obtains the size of a text shadow container.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TextStyle | Pointer to an [OH_Drawing_TextStyle](#oh_drawing_textstyle) object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle).| 

**Returns**

Returns the size.


### OH_Drawing_TextStyleGetShadows()

```
OH_Drawing_TextShadow* OH_Drawing_TextStyleGetShadows (OH_Drawing_TextStyle* )
```

**Description**

Obtains a text shadow container.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TextStyle | Pointer to an [OH_Drawing_TextStyle](#oh_drawing_textstyle) object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle).| 

**Returns**

Returns the pointer to the [OH_Drawing_TextShadow](#oh_drawing_textshadow) object.


### OH_Drawing_TextStyleGetShadowWithIndex()

```
OH_Drawing_TextShadow* OH_Drawing_TextStyleGetShadowWithIndex (OH_Drawing_TextStyle* , int  )
```

**Description**

Obtains a shadow with a given index in a text shadow container.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TextStyle | Pointer to an [OH_Drawing_TextStyle](#oh_drawing_textstyle) object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle).| 
| int | Index.| 

**Returns**

Returns the pointer to the [OH_Drawing_TextShadow](#oh_drawing_textshadow) object.


### OH_Drawing_TypefaceCreateDefault()

```
OH_Drawing_Typeface* OH_Drawing_TypefaceCreateDefault (void )
```

**Description**

Creates a default **OH_Drawing_Typeface** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Returns**

Returns the pointer to the **OH_Drawing_Typeface** object created.


### OH_Drawing_TypefaceCreateFromFile()

```
OH_Drawing_Typeface* OH_Drawing_TypefaceCreateFromFile (const char* path, int index )
```

**Description**

Creates an **OH_Drawing_Typeface** object through a file.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| path | Pointer to the file path.| 
| index | File index.| 

**Returns**

Returns the pointer to the [OH_Drawing_Typeface](#oh_drawing_typeface) object created.


### OH_Drawing_TypefaceCreateFromStream()

```
OH_Drawing_Typeface* OH_Drawing_TypefaceCreateFromStream (OH_Drawing_MemoryStream* , int32_t index )
```

**Description**

Creates an **OH_Drawing_Typeface** object through a memory stream. If the memory stream is an invalid font file, a null pointer is returned. After the memory stream is passed in, the ownership is transferred and you cannot release it.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_MemoryStream | Pointer to an [OH_Drawing_MemoryStream](#oh_drawing_memorystream) object.| 
| index | Index of the memory stream.| 

**Returns**

Returns the pointer to the [OH_Drawing_Typeface](#oh_drawing_typeface) object created.


### OH_Drawing_TypefaceDestroy()

```
void OH_Drawing_TypefaceDestroy (OH_Drawing_Typeface* )
```

**Description**

Destroys an **OH_Drawing_Typeface** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Typeface | Pointer to an **OH_Drawing_Typeface** object.| 


### OH_Drawing_TypographyDidExceedMaxLines()

```
bool OH_Drawing_TypographyDidExceedMaxLines (OH_Drawing_Typography* )
```

**Description**

Checks whether the maximum number of lines is exceeded.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Typography | Pointer to an **OH_Drawing_Typography** object, which is obtained by [OH_Drawing_CreateTypography](#oh_drawing_createtypography).| 

**Returns**

Returns **true** if the maximum number of lines is exceeded; returns **false** otherwise.


### OH_Drawing_TypographyGetAlphabeticBaseline()

```
double OH_Drawing_TypographyGetAlphabeticBaseline (OH_Drawing_Typography* )
```

**Description**

Obtains the alphabetic baseline.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Typography | Pointer to an **OH_Drawing_Typography** object, which is obtained by [OH_Drawing_CreateTypography](#oh_drawing_createtypography).| 

**Returns**

Returns the alphabetic baseline.


### OH_Drawing_TypographyGetEffectiveAlignment()

```
int OH_Drawing_TypographyGetEffectiveAlignment (OH_Drawing_TypographyStyle* style)
```

**Description**

Obtains the text alignment mode.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle).| 

**Returns**

Returns the text alignment mode.


### OH_Drawing_TypographyGetGlyphPositionAtCoordinate()

```
OH_Drawing_PositionAndAffinity* OH_Drawing_TypographyGetGlyphPositionAtCoordinate (OH_Drawing_Typography* , double , double  )
```

**Description**

Obtains the position and affinity of the glyph at the given coordinates.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Typography | Pointer to an **OH_Drawing_Typography** object, which is obtained by [OH_Drawing_CreateTypography](#oh_drawing_createtypography).| 
| double | X coordinate.| 
| double | Y coordinate.| 

**Returns**

Returns the [OH_Drawing_PositionAndAffinity](#oh_drawing_positionandaffinity) struct that holds the position and affinity of the glyph.


### OH_Drawing_TypographyGetGlyphPositionAtCoordinateWithCluster()

```
OH_Drawing_PositionAndAffinity* OH_Drawing_TypographyGetGlyphPositionAtCoordinateWithCluster (OH_Drawing_Typography* , double , double  )
```

**Description**

Obtains the position and affinity of the glyph cluster to which the glyph at the given coordinates belongs. The glyph cluster is a container that holds one or more glyphs.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Typography | Pointer to an **OH_Drawing_Typography** object, which is obtained by [OH_Drawing_CreateTypography](#oh_drawing_createtypography).| 
| double | X coordinate.| 
| double | Y coordinate.| 

**Returns**

Returns the [OH_Drawing_PositionAndAffinity](#oh_drawing_positionandaffinity) struct that holds the position and affinity of the glyph cluster.


### OH_Drawing_TypographyGetHeight()

```
double OH_Drawing_TypographyGetHeight (OH_Drawing_Typography* )
```

**Description**

Obtains the height.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Typography | Pointer to an **OH_Drawing_Typography** object, which is obtained by [OH_Drawing_CreateTypography](#oh_drawing_createtypography).| 

**Returns**

Returns the height.


### OH_Drawing_TypographyGetIdeographicBaseline()

```
double OH_Drawing_TypographyGetIdeographicBaseline (OH_Drawing_Typography* )
```

**Description**

Obtains the ideographic baseline.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Typography | Pointer to an **OH_Drawing_Typography** object, which is obtained by [OH_Drawing_CreateTypography](#oh_drawing_createtypography).| 

**Returns**

Returns the ideographic baseline.


### OH_Drawing_TypographyGetIndentsWithIndex()

```
float OH_Drawing_TypographyGetIndentsWithIndex (OH_Drawing_Typography* , int  )
```

**Description**

Obtains indents with a given index.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Typography | Pointer to an [OH_Drawing_Typography](#oh_drawing_typography) object, which is obtained by calling [OH_Drawing_CreateTypography](#oh_drawing_createtypography).| 
| int | Index.| 

**Returns**

Returns the indents.


### OH_Drawing_TypographyGetLineCount()

```
size_t OH_Drawing_TypographyGetLineCount (OH_Drawing_Typography* )
```

**Description**

Obtains the number of lines.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Typography | Pointer to an **OH_Drawing_Typography** object, which is obtained by [OH_Drawing_CreateTypography](#oh_drawing_createtypography).| 

**Returns**

Returns the number of lines.


### OH_Drawing_TypographyGetLineHeight()

```
double OH_Drawing_TypographyGetLineHeight (OH_Drawing_Typography* , int  )
```

**Description**

Obtains the height of a line.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Typography | Pointer to an **OH_Drawing_Typography** object, which is obtained by [OH_Drawing_CreateTypography](#oh_drawing_createtypography).| 
| int | Target line.| 

**Returns**

Returns the height.


### OH_Drawing_TypographyGetLineInfo()

```
bool OH_Drawing_TypographyGetLineInfo (OH_Drawing_Typography* , int , bool , bool , OH_Drawing_LineMetrics*  )
```

**Description**

Obtains the metrics of a given line or the metrics of the first character in a given line.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Typography | Pointer to an [OH_Drawing_Typography](#oh_drawing_typography) object, which is obtained by calling [OH_Drawing_CreateTypography](#oh_drawing_createtypography).| 
| int | Row No.| 
| bool | Whether to obtain the metrics of the entire line. The value **true** means to obtain the metrics of the entire line, and **false** means to obtain the metrics of the first character in the line.| 
| bool | Whether whitespace characters are included in the text width. The value **true** means that whitespace characters are not included, **false** means the opposite.| 
| [OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md) | Pointer to an [OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md) object, which is obtained by calling [OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md).| 

**Returns**

Returns **true** if the metrics of the given line or the metrics of the first character in the given line is obtained; returns **false** otherwise.


### OH_Drawing_TypographyGetLineMetrics()

```
OH_Drawing_LineMetrics* OH_Drawing_TypographyGetLineMetrics (OH_Drawing_Typography* )
```

**Description**

Obtains the line metrics.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Typography | Pointer to an [OH_Drawing_Typography](#oh_drawing_typography) object, which is obtained by calling [OH_Drawing_CreateTypography](#oh_drawing_createtypography).| 

**Returns**

Returns the pointer to the [OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md) object.


### OH_Drawing_TypographyGetLineMetricsAt()

```
bool OH_Drawing_TypographyGetLineMetricsAt (OH_Drawing_Typography* , int , OH_Drawing_LineMetrics*  )
```

**Description**

Obtains the metrics of a given line.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Typography | Pointer to an [OH_Drawing_Typography](#oh_drawing_typography) object, which is obtained by calling [OH_Drawing_CreateTypography](#oh_drawing_createtypography).| 
| int | Line No.| 
| [OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md) | Pointer to an [OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md) object, which is obtained by calling [OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md).| 

**Returns**

Returns **true** if the metrics of the given line is obtained; returns **false** otherwise.


### OH_Drawing_TypographyGetLineTextRange()

```
OH_Drawing_Range* OH_Drawing_TypographyGetLineTextRange (OH_Drawing_Typography* , int , bool  )
```

**Description**

Obtains the line bounds.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Typography | Pointer to an [OH_Drawing_Typography](#oh_drawing_typography) object, which is obtained by calling [OH_Drawing_CreateTypography](#oh_drawing_createtypography).| 
| int | Row index.| 
| bool | Whether the returned bounds contain spaces. The value **true** means that the bounds contain spaces, and **false** means the opposite.| 

**Returns**

Returns the pointer to the [OH_Drawing_Range](#oh_drawing_range) object.


### OH_Drawing_TypographyGetLineWidth()

```
double OH_Drawing_TypographyGetLineWidth (OH_Drawing_Typography* , int  )
```

**Description**

Obtains the width of a line.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Typography | Pointer to an **OH_Drawing_Typography** object, which is obtained by [OH_Drawing_CreateTypography](#oh_drawing_createtypography).| 
| int | Target line.| 

**Returns**

Returns the width.


### OH_Drawing_TypographyGetLongestLine()

```
double OH_Drawing_TypographyGetLongestLine (OH_Drawing_Typography* )
```

**Description**

Obtains the width of the longest line. You are advised to round up the return value in actual use. When the text content is empty, the minimum float value, that is, -340282346638528859811704183484516925440.000000, is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Typography | Pointer to an **OH_Drawing_Typography** object, which is obtained by [OH_Drawing_CreateTypography](#oh_drawing_createtypography).| 

**Returns**

Returns the width of the longest line.


### OH_Drawing_TypographyGetMaxIntrinsicWidth()

```
double OH_Drawing_TypographyGetMaxIntrinsicWidth (OH_Drawing_Typography* )
```

**Description**

Obtains the maximum intrinsic width.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Typography | Pointer to an **OH_Drawing_Typography** object, which is obtained by [OH_Drawing_CreateTypography](#oh_drawing_createtypography).| 

**Returns**

Returns the maximum intrinsic width.


### OH_Drawing_TypographyGetMaxWidth()

```
double OH_Drawing_TypographyGetMaxWidth (OH_Drawing_Typography* )
```

**Description**

Obtains the maximum width.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Typography | Pointer to an **OH_Drawing_Typography** object, which is obtained by [OH_Drawing_CreateTypography](#oh_drawing_createtypography).| 

**Returns**

Returns the maximum width.


### OH_Drawing_TypographyGetMinIntrinsicWidth()

```
double OH_Drawing_TypographyGetMinIntrinsicWidth (OH_Drawing_Typography* )
```

**Description**

Obtains the minimum intrinsic width.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Typography | Pointer to an **OH_Drawing_Typography** object, which is obtained by [OH_Drawing_CreateTypography](#oh_drawing_createtypography).| 

**Returns**

Returns the minimum intrinsic width.


### OH_Drawing_TypographyGetRectsForPlaceholders()

```
OH_Drawing_TextBox* OH_Drawing_TypographyGetRectsForPlaceholders (OH_Drawing_Typography* )
```

**Description**

Obtains text boxes for placeholders.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Typography | Pointer to an **OH_Drawing_Typography** object, which is obtained by [OH_Drawing_CreateTypography](#oh_drawing_createtypography).| 

**Returns**

Returns the [OH_Drawing_TextBox](#oh_drawing_textbox) struct that holds the text boxes.


### OH_Drawing_TypographyGetRectsForRange()

```
OH_Drawing_TextBox* OH_Drawing_TypographyGetRectsForRange (OH_Drawing_Typography* , size_t , size_t , OH_Drawing_RectHeightStyle , OH_Drawing_RectWidthStyle  )
```

**Description**

Obtains text boxes in a given range.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Typography | Pointer to an **OH_Drawing_Typography** object, which is obtained by [OH_Drawing_CreateTypography](#oh_drawing_createtypography).| 
| size_t | Start position.| 
| size_t | End position.| 
| OH_Drawing_RectHeightStyle | Height style. For details about the available options, see [OH_Drawing_RectHeightStyle](#oh_drawing_rectheightstyle).| 
| OH_Drawing_RectWidthStyle | Width style. For details about the available options, see [OH_Drawing_RectWidthStyle](#oh_drawing_rectwidthstyle).| 

**Returns**

Returns the [OH_Drawing_TextBox](#oh_drawing_textbox) struct that holds the text boxes.


### OH_Drawing_TypographyGetTextStyle()

```
OH_Drawing_TextStyle* OH_Drawing_TypographyGetTextStyle (OH_Drawing_TypographyStyle* style)
```

**Description**

Obtains the text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle).| 

**Returns**

Returns the pointer to the [OH_Drawing_TextStyle](#oh_drawing_textstyle) object.


### OH_Drawing_TypographyGetWordBoundary()

```
OH_Drawing_Range* OH_Drawing_TypographyGetWordBoundary (OH_Drawing_Typography* , size_t  )
```

**Description**

Obtains the word boundary.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Typography | Pointer to an **OH_Drawing_Typography** object, which is obtained by [OH_Drawing_CreateTypography](#oh_drawing_createtypography).| 
| size_t | Index of the word.| 

**Returns**

Returns the [OH_Drawing_Range](#oh_drawing_range) struct that holds the word boundary.


### OH_Drawing_TypographyHandlerAddPlaceholder()

```
void OH_Drawing_TypographyHandlerAddPlaceholder (OH_Drawing_TypographyCreate* , OH_Drawing_PlaceholderSpan*  )
```

**Description**

Adds a placeholder.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TypographyCreate | Pointer to an **OH_Drawing_TypographyCreate** object. The pointer is obtained by [OH_Drawing_CreateTypographyHandler](#oh_drawing_createtypographyhandler).| 
| OH_Drawing_PlaceholderSpan | Pointer to an [OH_Drawing_PlaceholderSpan](_o_h___drawing___placeholder_span.md) object.| 


### OH_Drawing_TypographyHandlerAddText()

```
void OH_Drawing_TypographyHandlerAddText (OH_Drawing_TypographyCreate* , const char*  )
```

**Description**

Sets the text content.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TypographyCreate | Pointer to an **OH_Drawing_TypographyCreate** object. The pointer is obtained by [OH_Drawing_CreateTypographyHandler](#oh_drawing_createtypographyhandler).| 
| char | Pointer to the text content.| 


### OH_Drawing_TypographyHandlerPopTextStyle()

```
void OH_Drawing_TypographyHandlerPopTextStyle (OH_Drawing_TypographyCreate* )
```

**Description**

Removes the topmost style in the stack, leaving the remaining styles in effect.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TypographyCreate | Pointer to an **OH_Drawing_TypographyCreate** object. The pointer is obtained by [OH_Drawing_CreateTypographyHandler](#oh_drawing_createtypographyhandler).| 


### OH_Drawing_TypographyHandlerPushTextStyle()

```
void OH_Drawing_TypographyHandlerPushTextStyle (OH_Drawing_TypographyCreate* , OH_Drawing_TextStyle*  )
```

**Description**

Sets the text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TypographyCreate | Pointer to an **OH_Drawing_TypographyCreate** object. The pointer is obtained by [OH_Drawing_CreateTypographyHandler](#oh_drawing_createtypographyhandler).| 
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object, which is obtained by [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle).| 


### OH_Drawing_TypographyIsEllipsized()

```
bool OH_Drawing_TypographyIsEllipsized (OH_Drawing_TypographyStyle* style)
```

**Description**

Checks whether the text has an ellipsis.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle).| 

**Returns**

Returns **true** if the text has an ellipsis; returns **false** otherwise.


### OH_Drawing_TypographyIsLineUnlimited()

```
bool OH_Drawing_TypographyIsLineUnlimited (OH_Drawing_TypographyStyle* style)
```

**Description**

Checks whether the maximum number of lines is limited for text.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle).| 

**Returns**

Returns **true** if that the maximum number of lines is limited; returns **false** otherwise.


### OH_Drawing_TypographyLayout()

```
void OH_Drawing_TypographyLayout (OH_Drawing_Typography* , double  )
```

**Description**

Lays out the typography.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Typography | Pointer to an **OH_Drawing_Typography** object, which is obtained by [OH_Drawing_CreateTypography](#oh_drawing_createtypography).| 
| double | Maximum text width.| 


### OH_Drawing_TypographyPaint()

```
void OH_Drawing_TypographyPaint (OH_Drawing_Typography* , OH_Drawing_Canvas* , double , double  )
```

**Description**

Paints text on the canvas.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Typography | Pointer to an **OH_Drawing_Typography** object, which is obtained by [OH_Drawing_CreateTypography](#oh_drawing_createtypography).| 
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object, which is obtained by [OH_Drawing_CanvasCreate](#oh_drawing_canvascreate).| 
| double | X coordinate.| 
| double | Y coordinate. | 


### OH_Drawing_TypographySetIndents()

```
void OH_Drawing_TypographySetIndents (OH_Drawing_Typography* , int , const float indents[] )
```

**Description**

Sets the indents for typography.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| OH_Drawing_Typography | Pointer to an [OH_Drawing_Typography](#oh_drawing_typography) object, which is obtained by calling [OH_Drawing_CreateTypography](#oh_drawing_createtypography).| 
| int | Number of indents.| 
| float | Array holding the indents.| 
