# Drawing


## Overview

The Drawing module provides the functions for 2D graphics rendering, text drawing, and image display. It uses the physical pixel unit, px. The module operates under a single-threaded model. The caller needs to manage thread safety and context state transitions.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8


## Summary


### Files

| Name| Description|
| -------- | -------- |
| [drawing_bitmap.h](drawing__bitmap_8h.md) | Declares the functions related to the bitmap in the drawing module.|
| [drawing_brush.h](drawing__brush_8h.md) | Declares the functions related to the brush in the drawing module.|
| [drawing_canvas.h](drawing__canvas_8h.md) | Declares the functions related to the canvas in the drawing module. By default, the canvas has a black brush with anti-aliasing enabled but no any other style. This default brush takes effect only when no brush or pen is proactively set in the canvas. Canvases that are not set for recording will immediately draw the commands onto the bound bitmap, whereas canvases designated for recording will store the drawing commands for future replay.|
| [drawing_color.h](drawing__color_8h.md) | Declares the functions related to the color in the drawing module.|
| [drawing_color_filter.h](drawing__color__filter_8h.md) | Declares the functions related to the color filter in the drawing module.|
| [drawing_error_code.h](drawing__error__code_8h.md) | Declares the functions related to the error code in the drawing module.|
| [drawing_color_space.h](drawing__color__space_8h.md) | Declares the functions related to the color space in the drawing module.|
| [drawing_filter.h](drawing__filter_8h.md) | Declares the functions related to the filter in the drawing module.|
| [drawing_font.h](drawing__font_8h.md) | Declares the functions related to the font in the drawing module.|
| [drawing_font_collection.h](drawing__font__collection_8h.md) | Declares the functions related to the font collection in the drawing module.|
| [drawing_font_mgr.h](drawing__font__mgr_8h.md) | Declares the functions related to font management in the drawing module. The functions can be used to load fonts and match available fonts in the system.|
| [drawing_gpu_context.h](drawing__gpu__context_8h.md) | Declares the functions related to the GPU context in the drawing module.|
| [drawing_image.h](drawing__image_8h.md) | Declares the functions related to the image in the drawing module.|
| [drawing_image_filter.h](drawing__image__filter_8h.md) | Declares the functions related to the image filter in the drawing module.|
| [drawing_mask_filter.h](drawing__mask__filter_8h.md) | Declares the functions related to the mask filter in the drawing module.|
| [drawing_matrix.h](drawing__matrix_8h.md) | Declares the functions related to the matrix in the drawing module.|
| [drawing_memory_stream.h](drawing__memory__stream_8h.md) | Declares the functions related to the memory stream in the drawing module.|
| [drawing_path.h](drawing__path_8h.md) | Declares the functions related to the path in the drawing module.|
| [drawing_path_effect.h](drawing__path__effect_8h.md) | Declares the functions related to the bitmap in the drawing module.|
| [drawing_pen.h](drawing__pen_8h.md) | Declares the functions related to the pen in the drawing module.|
| [drawing_pixel_map.h](drawing__pixel__map_8h.md) | Declares the functions related to the pixel map in the drawing module.|
| [drawing_point.h](drawing__point_8h.md) | Declares the functions related to the coordinate point in the drawing module.|
| [drawing_record_cmd.h](drawing__record__cmd_8h.md) | Declares the functions related to a recording command object.|
| [drawing_rect.h](drawing__rect_8h.md) | Declares the functions related to the rectangle in the drawing module.|
| [drawing_region.h](drawing__region_8h.md) | Declares the functions related to the region in the drawing module, including creating a region, setting the boundary, and destroying a region.|
| [drawing_register_font.h](drawing__register__font_8h.md) | Declares the functions related to the font manager in the drawing module.|
| [drawing_round_rect.h](drawing__round__rect_8h.md) | Declares the functions related to the rounded rectangle in the drawing module.|
| [drawing_sampling_options.h](drawing__sampling__options_8h.md) | Declares the functions related to the sampling options in the drawing module. It is used for image or texture sampling.|
| [drawing_shader_effect.h](drawing__shader__effect_8h.md) | Declares the functions related to the shader effect in the drawing module.|
| [drawing_shadow_layer.h](drawing__shadow__layer_8h.md) | Declares the functions related to the shadow in the drawing module.|
| [drawing_surface.h](drawing__surface_8h.md) | Declares the functions related to the surface in the drawing module, including creating, destroying, and using the surface.|
| [drawing_text_blob.h](drawing__text__blob_8h.md) | Declares the functions related to the text blob in the drawing module.|
| [drawing_text_declaration.h](drawing__text__declaration_8h.md) | Declares the structs related to text in 2D drawing.|
| [drawing_text_font_descriptor.h](drawing__text__font__descriptor_8h.md) | Declares the capabilities of font information, such as obtaining font information and searching for a font.|
| [drawing_text_line.h](drawing__text__line_8h.md) | Declares the capabilities for obtaining the character position in a text line, obtaining the run information, and truncating text by line.|
| [drawing_text_run.h](drawing__text__run_8h.md) | Declares the capabilities of runs, such as obtaining the typographic boundary and drawing. |
| [drawing_text_typography.h](drawing__text__typography_8h.md) | Declares the functions related to typography in the drawing module.|
| [drawing_typeface.h](drawing__typeface_8h.md) | Declares the functions related to the typeface in the drawing module. Different platforms have their own default typefaces. You can also parse the .ttf file to obtain the typefaces specified by the third party, such as SimSun and SimHei.|
| [drawing_types.h](drawing__types_8h.md) | Declares the data types of the canvas, brush, pen, bitmap, and path used to draw 2D graphics.|


### Structs

| Name| Description|
| -------- | -------- |
| struct  [OH_Drawing_String](_o_h___drawing___string.md) | Describes a string of characters encoded in UTF-16BE (big-endian mode).|
| struct  [OH_Drawing_BitmapFormat](_o_h___drawing___bitmap_format.md) | Describes the pixel format of a bitmap, including the color type and alpha type.|
| struct  [OH_Drawing_Font_Metrics](_o_h___drawing___font___metrics.md) | Describes the measurement information about a font.|
| struct  [OH_Drawing_GpuContextOptions](_o_h___drawing___gpu_context_options.md) | Describes the options about the GPU context.|
| struct  [OH_Drawing_RunBuffer](_o_h___drawing___run_buffer.md) | Describes a run, which provides storage for glyphs and positions.|
| struct  [OH_Drawing_PlaceholderSpan](_o_h___drawing___placeholder_span.md) | Describes the placeholder that acts as a span.|
| struct  [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) | Describes the detailed information about a system font.|
| struct  [OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md) | Describes the measurement information about a line of text.|
| struct  [OH_Drawing_FontFallbackInfo](_o_h___drawing___font_fallback_info.md) | Describes the information about a font fallback.|
| struct  [OH_Drawing_FontFallbackGroup](_o_h___drawing___font_fallback_group.md) | Describes the information about a font fallback group.|
| struct  [OH_Drawing_FontAdjustInfo](_o_h___drawing___font_adjust_info.md) | Describes the information about a font weight mapping.|
| struct  [OH_Drawing_FontAliasInfo](_o_h___drawing___font_alias_info.md) | Describes the information about a font alias.|
| struct  [OH_Drawing_FontGenericInfo](_o_h___drawing___font_generic_info.md) | Describes the information about generic fonts supported by the system.|
| struct  [OH_Drawing_FontConfigInfo](_o_h___drawing___font_config_info.md) | Describes the information about a system font configuration.|
| struct  [OH_Drawing_FontStyleStruct](_o_h___drawing___font_style_struct.md) | Describes a font style.|
| struct  [OH_Drawing_FontFeature](_o_h___drawing___font_feature.md) | Describes a font feature.|
| struct  [OH_Drawing_StrutStyle](_o_h___drawing___strut_style.md) | Describes a strut style. The strut style determines the line spacing, baseline alignment mode, and other properties related to the line height when drawing texts.|
| struct  [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) | Describes a two-dimensional coordinate point.|
| struct  [OH_Drawing_Point3D](_o_h___drawing___point3_d.md) | Describes a three-dimensional coordinate point.|
| struct  [OH_Drawing_Image_Info](_o_h___drawing___image___info.md) | Describes the image information.|
| struct  [OH_Drawing_RectStyle_Info](_o_h___drawing___rect_style___info.md) | Describes the style of a rectangle.|


### Types

| Name| Description|
| -------- | -------- |
| typedef struct [OH_Drawing_String](_o_h___drawing___string.md) [OH_Drawing_String](#oh_drawing_string) | Defines a struct for a string of characters encoded in UTF-16BE (big-endian mode).|
| typedef enum [OH_Drawing_SystemFontType](#oh_drawing_systemfonttype) [OH_Drawing_SystemFontType](#oh_drawing_systemfonttype) | Defines an enum for the system font types.|
| typedef bool(\* [Drawing_CaretOffsetsCallback](#drawing_caretoffsetscallback)) (double offset, int32_t index, bool leadingEdge) | Defines a custom callback used to receive the offset and index of each character in a text line object as its parameters.|
| typedef struct [OH_Drawing_LineTypography](#oh_drawing_linetypography) [OH_Drawing_LineTypography](#oh_drawing_linetypography) | Defines a struct used to extract a single line of data from a piece of text for typography.|
| typedef struct [OH_Drawing_TextTab](#oh_drawing_texttab) [OH_Drawing_TextTab](#oh_drawing_texttab) | Defines a struct used to manage text tabs.|
| typedef struct [OH_Drawing_Array](#oh_drawing_array) [OH_Drawing_Array](#oh_drawing_array) | Defines a struct for an array object, which is used to store multiple objects of the same type.|
| typedef struct [OH_Drawing_FontArguments](#oh_drawing_fontarguments) [OH_Drawing_FontArguments](#oh_drawing_fontarguments) | Defines a struct for font arguments.|
| typedef struct [OH_Drawing_RecordCmdUtils](#oh_drawing_recordcmdutils) [OH_Drawing_RecordCmdUtils](#oh_drawing_recordcmdutils) | Defines the recording command tool, which is used to generate recording commands.|
| typedef struct [OH_Drawing_RecordCmd](#oh_drawing_recordcmd) [OH_Drawing_RecordCmd](#oh_drawing_recordcmd) | Defines the recording command class, which is used to store the set of recording commands.|
| typedef enum [OH_Drawing_ErrorCode](#oh_drawing_errorcode)  [OH_Drawing_ErrorCode](#oh_drawing_errorcode) | Defines an enum for the error codes that may be generated by the module.|
| typedef enum [OH_Drawing_PathOpMode](#oh_drawing_pathopmode)  [OH_Drawing_PathOpMode](#oh_drawing_pathopmode) | Defines an enum for the operation modes available for a path.|
| typedef enum [OH_Drawing_PathMeasureMatrixFlags](#oh_drawing_pathmeasurematrixflags)  [OH_Drawing_PathMeasureMatrixFlags](#oh_drawing_pathmeasurematrixflags) | Defines an enum for the types of matrix information obtained during path measurement.|
| typedef enum [OH_Drawing_RegionOpMode](#oh_drawing_regionopmode)  [OH_Drawing_RegionOpMode](#oh_drawing_regionopmode) | Defines an enum for the operation modes available for a region.|
| typedef struct [OH_Drawing_ImageFilter](#oh_drawing_imagefilter)  [OH_Drawing_ImageFilter](#oh_drawing_imagefilter) | Defines a struct for an image filter, which is used to operate all color bits that make up image pixels.|
| typedef struct [OH_Drawing_Filter](#oh_drawing_filter)  [OH_Drawing_Filter](#oh_drawing_filter) | Defines a struct for a filter, which consists of a color filter, mask filter, and image filter.|
| typedef struct [OH_Drawing_BitmapFormat](_o_h___drawing___bitmap_format.md)  [OH_Drawing_BitmapFormat](#oh_drawing_bitmapformat) | Defines a struct for the pixel format of a bitmap, including the color type and alpha type.|
| typedef enum [OH_Drawing_SrcRectConstraint](#oh_drawing_srcrectconstraint)  [OH_Drawing_SrcRectConstraint](#oh_drawing_srcrectconstraint) | Defines an enum for the constraint types of the source rectangle.|
| typedef enum [OH_Drawing_PointMode](#oh_drawing_pointmode)  [OH_Drawing_PointMode](#oh_drawing_pointmode) | Defines an enum for the modes of drawing multiple points. The modes include discrete points, line segments, and open polygons.|
| typedef enum [OH_Drawing_VertexMode](#oh_drawing_vertexmode)  [OH_Drawing_VertexMode](#oh_drawing_vertexmode) | Defines an enum for the modes of interpreting the geometry of a given vertex.|
| typedef enum [OH_Drawing_CanvasClipOp](#oh_drawing_canvasclipop)  [OH_Drawing_CanvasClipOp](#oh_drawing_canvasclipop) | Defines an enum for the canvas clipping modes.|
| typedef enum [OH_Drawing_FontEdging](#oh_drawing_fontedging)  [OH_Drawing_FontEdging](#oh_drawing_fontedging) | Defines an enum for the font edging types.|
| typedef enum [OH_Drawing_FontHinting](#oh_drawing_fonthinting)  [OH_Drawing_FontHinting](#oh_drawing_fonthinting) | Defines an enum for the font hinting types.|
| typedef struct [OH_Drawing_Font_Metrics](_o_h___drawing___font___metrics.md)  [OH_Drawing_Font_Metrics](#oh_drawing_font_metrics) | Defines a struct for the measurement information about a font.|
| typedef struct [OH_Drawing_GpuContextOptions](_o_h___drawing___gpu_context_options.md)  [OH_Drawing_GpuContextOptions](#oh_drawing_gpucontextoptions) | Defines a struct for the options about the GPU context.|
| typedef enum [OH_Drawing_BlurType](#oh_drawing_blurtype)  [OH_Drawing_BlurType](#oh_drawing_blurtype) | Defines an enum for the blur types.|
| typedef enum [OH_Drawing_ScaleToFit](#oh_drawing_scaletofit)  [OH_Drawing_ScaleToFit](#oh_drawing_scaletofit) | Defines an enum for the matrix scaling modes.|
| typedef enum [OH_Drawing_PathDirection](#oh_drawing_pathdirection)  [OH_Drawing_PathDirection](#oh_drawing_pathdirection) | Defines an enum for the directions of a closed contour.|
| typedef enum [OH_Drawing_PathFillType](#oh_drawing_pathfilltype)  [OH_Drawing_PathFillType](#oh_drawing_pathfilltype) | Defines an enum for the fill types of a path.|
| typedef enum [OH_Drawing_PathAddMode](#oh_drawing_pathaddmode)  [OH_Drawing_PathAddMode](#oh_drawing_pathaddmode) | Defines an enum for the path adding modes.|
| typedef enum [OH_Drawing_PenLineCapStyle](#oh_drawing_penlinecapstyle)  [OH_Drawing_PenLineCapStyle](#oh_drawing_penlinecapstyle) | Defines an enum for the line cap styles of a pen. The line cap style defines the style of both ends of a line segment drawn by the pen.|
| typedef enum [OH_Drawing_PenLineJoinStyle](#oh_drawing_penlinejoinstyle)  [OH_Drawing_PenLineJoinStyle](#oh_drawing_penlinejoinstyle) | Defines an enum for the line join styles of a pen. The line join style defines the shape of the joints of a polyline segment drawn by the pen.|
| typedef enum [OH_Drawing_CornerPos](#oh_drawing_cornerpos)  [OH_Drawing_CornerPos](#oh_drawing_cornerpos) | Defines an enum for the corner positions of a rounded rectangle.|
| typedef enum [OH_Drawing_FilterMode](#oh_drawing_filtermode)  [OH_Drawing_FilterMode](#oh_drawing_filtermode) | Defines an enum for the filter modes.|
| typedef enum [OH_Drawing_MipmapMode](#oh_drawing_mipmapmode)  [OH_Drawing_MipmapMode](#oh_drawing_mipmapmode) | Defines an enum for the mipmap modes.|
| typedef enum [OH_Drawing_TileMode](#oh_drawing_tilemode)  [OH_Drawing_TileMode](#oh_drawing_tilemode) | Defines an enum for the tile modes of the shader effect.|
| typedef struct [OH_Drawing_RunBuffer](_o_h___drawing___run_buffer.md)  [OH_Drawing_RunBuffer](#oh_drawing_runbuffer) | Defines a struct for a run, which provides storage for glyphs and positions.|
| typedef struct [OH_Drawing_FontCollection](#oh_drawing_fontcollection)  [OH_Drawing_FontCollection](#oh_drawing_fontcollection) | Defines a struct used to load fonts.|
| typedef struct [OH_Drawing_Typography](#oh_drawing_typography)  [OH_Drawing_Typography](#oh_drawing_typography) | Defines a struct used to manage the typography layout and display.|
| typedef struct [OH_Drawing_TextStyle](#oh_drawing_textstyle)  [OH_Drawing_TextStyle](#oh_drawing_textstyle) | Defines a struct used to manage text colors and decorations.|
| typedef struct [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)  [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) | Defines a struct used to manage the typography style, such as the text direction.|
| typedef struct [OH_Drawing_TypographyCreate](#oh_drawing_typographycreate)  [OH_Drawing_TypographyCreate](#oh_drawing_typographycreate) | Defines a struct used to create an [OH_Drawing_Typography](#oh_drawing_typography) object.|
| typedef struct [OH_Drawing_TextBox](#oh_drawing_textbox)  [OH_Drawing_TextBox](#oh_drawing_textbox) | Defines a struct for a text box, which is used to receive the rectangle size, direction, and quantity.|
| typedef struct [OH_Drawing_PositionAndAffinity](#oh_drawing_positionandaffinity)  [OH_Drawing_PositionAndAffinity](#oh_drawing_positionandaffinity) | Defines a struct used to receive the position and affinity of a glyph.|
| typedef struct [OH_Drawing_Range](#oh_drawing_range)  [OH_Drawing_Range](#oh_drawing_range) | Defines a struct for a range, which is used to receive the start position and end position of a glyph.|
| typedef struct [OH_Drawing_TextShadow](#oh_drawing_textshadow)  [OH_Drawing_TextShadow](#oh_drawing_textshadow) | Defines a struct used to manage text shadows.|
| typedef struct [OH_Drawing_FontParser](#oh_drawing_fontparser)  [OH_Drawing_FontParser](#oh_drawing_fontparser) | Defines a struct used to parse system font files.|
| typedef enum [OH_Drawing_PlaceholderVerticalAlignment](#oh_drawing_placeholderverticalalignment)  [OH_Drawing_PlaceholderVerticalAlignment](#oh_drawing_placeholderverticalalignment) | Defines an enum for the vertical alignment modes of placeholders.|
| typedef struct [OH_Drawing_PlaceholderSpan](_o_h___drawing___placeholder_span.md)  [OH_Drawing_PlaceholderSpan](#oh_drawing_placeholderspan) | Defines a struct for the placeholder that acts as a span.|
| typedef enum [OH_Drawing_TextDecorationStyle](#oh_drawing_textdecorationstyle)  [OH_Drawing_TextDecorationStyle](#oh_drawing_textdecorationstyle) | Defines an enum for the text decoration styles.|
| typedef enum [OH_Drawing_EllipsisModal](#oh_drawing_ellipsismodal)  [OH_Drawing_EllipsisModal](#oh_drawing_ellipsismodal) | Defines an enum for the text ellipsis styles.|
| typedef enum [OH_Drawing_BreakStrategy](#oh_drawing_breakstrategy)  [OH_Drawing_BreakStrategy](#oh_drawing_breakstrategy) | Defines an enum for the text break strategies.|
| typedef enum [OH_Drawing_WordBreakType](#oh_drawing_wordbreaktype)  [OH_Drawing_WordBreakType](#oh_drawing_wordbreaktype) | Defines an enum for the word break types.|
| typedef enum [OH_Drawing_RectHeightStyle](#oh_drawing_rectheightstyle)  [OH_Drawing_RectHeightStyle](#oh_drawing_rectheightstyle) | Defines an enum for the rectangle height styles.|
| typedef enum [OH_Drawing_RectWidthStyle](#oh_drawing_rectwidthstyle)  [OH_Drawing_RectWidthStyle](#oh_drawing_rectwidthstyle) | Defines an enum for the rectangle width styles.|
| typedef struct [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md)  [OH_Drawing_FontDescriptor](#oh_drawing_fontdescriptor) | Defines a struct for the detailed information about a system font.|
| typedef struct [OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md)  [OH_Drawing_LineMetrics](#oh_drawing_linemetrics) | Defines a struct for the measurement information about a line of text.|
| typedef struct [OH_Drawing_FontFallbackInfo](_o_h___drawing___font_fallback_info.md)  [OH_Drawing_FontFallbackInfo](#oh_drawing_fontfallbackinfo) | Defines a struct for the information about a font fallback.|
| typedef struct [OH_Drawing_FontFallbackGroup](_o_h___drawing___font_fallback_group.md)  [OH_Drawing_FontFallbackGroup](#oh_drawing_fontfallbackgroup) | Defines a struct for the information about a font fallback group.|
| typedef struct [OH_Drawing_FontAdjustInfo](_o_h___drawing___font_adjust_info.md)  [OH_Drawing_FontAdjustInfo](#oh_drawing_fontadjustinfo) | Defines a struct for the information about a font weight mapping.|
| typedef struct [OH_Drawing_FontAliasInfo](_o_h___drawing___font_alias_info.md)  [OH_Drawing_FontAliasInfo](#oh_drawing_fontaliasinfo) | Defines a struct for the information about a font alias.|
| typedef struct [OH_Drawing_FontGenericInfo](_o_h___drawing___font_generic_info.md)  [OH_Drawing_FontGenericInfo](#oh_drawing_fontgenericinfo) | Defines a struct for the information about generic fonts supported by the system.|
| typedef struct [OH_Drawing_FontConfigInfo](_o_h___drawing___font_config_info.md)  [OH_Drawing_FontConfigInfo](#oh_drawing_fontconfiginfo) | Defines a struct for the information about a system font configuration.|
| typedef struct [OH_Drawing_FontStyleStruct](_o_h___drawing___font_style_struct.md)  [OH_Drawing_FontStyleStruct](#oh_drawing_fontstylestruct) | Defines a struct for a font style.|
| typedef struct [OH_Drawing_StrutStyle](_o_h___drawing___strut_style.md)  [OH_Drawing_StrutStyle](#oh_drawing_strutstyle) | Defines a struct for a strut style. The strut style determines the line spacing, baseline alignment mode, and other properties related to the line height when drawing texts.|
| typedef struct [OH_Drawing_Canvas](#oh_drawing_canvas)  [OH_Drawing_Canvas](#oh_drawing_canvas) | Defines a struct for a rectangular canvas, on which various shapes, images, and texts can be drawn by using the brush and pen.|
| typedef struct [OH_Drawing_Pen](#oh_drawing_pen)  [OH_Drawing_Pen](#oh_drawing_pen) | Defines a struct for a pen, which is used to describe the style and color to outline a shape.|
| typedef struct [OH_Drawing_Region](#oh_drawing_region)  [OH_Drawing_Region](#oh_drawing_region) | Defines a struct for a region, which represents a closed area on the canvas for more accurate graphic control.|
| typedef struct [OH_Drawing_Brush](#oh_drawing_brush)  [OH_Drawing_Brush](#oh_drawing_brush) | Defines a struct for a brush, which is used to describe the style and color to fill in a shape.|
| typedef struct [OH_Drawing_Path](#oh_drawing_path)  [OH_Drawing_Path](#oh_drawing_path) | Defines a struct for a path, which is used to customize various shapes.|
| typedef struct [OH_Drawing_PixelMap](#oh_drawing_pixelmap)  [OH_Drawing_PixelMap](#oh_drawing_pixelmap) | Defines a struct for a pixel map, which is used to wrap the real pixel map supported by the image framework.|
| typedef struct [OH_Drawing_Bitmap](#oh_drawing_bitmap)  [OH_Drawing_Bitmap](#oh_drawing_bitmap) | Defines a struct for a bitmap, which is a memory area that contains the pixel data of a shape.|
| typedef struct [OH_Drawing_Point](#oh_drawing_point)  [OH_Drawing_Point](#oh_drawing_point) | Defines a struct for a coordinate point.|
| typedef struct [OH_Drawing_ColorSpace](#oh_drawing_colorspace)  [OH_Drawing_ColorSpace](#oh_drawing_colorspace) | Defines a struct for a color space, which is used to describe the color information.|
| typedef struct [OH_Drawing_Point2D](_o_h___drawing___point2_d.md)  [OH_Drawing_Point2D](#oh_drawing_point2d) | Defines a struct for a two-dimensional coordinate point.|
| typedef [OH_Drawing_Point2D](_o_h___drawing___point2_d.md)  [OH_Drawing_Corner_Radii](#oh_drawing_corner_radii) | Defines a struct for the radii of a rounded corner. The radii consist of the radius in the x-axis direction and that in the y-axis direction.|
| typedef struct [OH_Drawing_Point3D](_o_h___drawing___point3_d.md)  [OH_Drawing_Point3D](#oh_drawing_point3d) | Defines a struct for a three-dimensional coordinate point.|
| typedef struct [OH_Drawing_PathEffect](#oh_drawing_patheffect)  [OH_Drawing_PathEffect](#oh_drawing_patheffect) | Defines a struct for a path effect that affects the stroke.|
| typedef struct [OH_Drawing_Rect](#oh_drawing_rect)  [OH_Drawing_Rect](#oh_drawing_rect) | Defines a struct for a rectangle.|
| typedef struct [OH_Drawing_RoundRect](#oh_drawing_roundrect)  [OH_Drawing_RoundRect](#oh_drawing_roundrect) | Defines a struct for a rounded rectangle.|
| typedef struct [OH_Drawing_Matrix](#oh_drawing_matrix)  [OH_Drawing_Matrix](#oh_drawing_matrix) | Defines a struct for a matrix, which is used to describe coordinate transformation.|
| typedef struct [OH_Drawing_ShaderEffect](#oh_drawing_shadereffect)  [OH_Drawing_ShaderEffect](#oh_drawing_shadereffect) | Defines a struct for a shader effect, which is used to describe the source color of the drawn content.|
| typedef struct [OH_Drawing_ShadowLayer](#oh_drawing_shadowlayer)  [OH_Drawing_ShadowLayer](#oh_drawing_shadowlayer) | Defines a struct for a shadow, which is used to describe the shadow layer of the drawn content.|
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
| typedef struct [OH_Drawing_GpuContext](#oh_drawing_gpucontext)  [OH_Drawing_GpuContext](#oh_drawing_gpucontext) | Defines a struct for the GPU context, which is used to describe the GPU backend context.|
| typedef struct [OH_Drawing_Surface](#oh_drawing_surface)  [OH_Drawing_Surface](#oh_drawing_surface) | Defines a struct for a surface, which is used to manage the content drawn on the canvas.|
| typedef enum [OH_Drawing_ColorFormat](#oh_drawing_colorformat)  [OH_Drawing_ColorFormat](#oh_drawing_colorformat) | Defines an enum for the storage formats of bitmap pixels.|
| typedef enum [OH_Drawing_AlphaFormat](#oh_drawing_alphaformat)  [OH_Drawing_AlphaFormat](#oh_drawing_alphaformat) | Defines an enum for the alpha formats of bitmap pixels.|
| typedef enum [OH_Drawing_BlendMode](#oh_drawing_blendmode)  [OH_Drawing_BlendMode](#oh_drawing_blendmode) | Defines an enum for the blend modes. In blend mode, each operation generates a new color from two colors (source color and target color). These operations are the same on the four channels (red, green, blue, and alpha). The operations for the alpha channel are used as examples.|
| typedef struct [OH_Drawing_Image_Info](_o_h___drawing___image___info.md)  [OH_Drawing_Image_Info](#oh_drawing_image_info) | Defines a struct for the image information.|
| typedef struct [OH_Drawing_RectStyle_Info](_o_h___drawing___rect_style___info.md)  [OH_Drawing_RectStyle_Info](#oh_drawing_rectstyle_info) | Defines a struct for the style of a rectangle.|
| typedef enum [OH_Drawing_TextEncoding](#oh_drawing_textencoding)  [OH_Drawing_TextEncoding](#oh_drawing_textencoding) | Defines an enum for the text encoding types.|
| typedef struct [OH_Drawing_FontMgr](#oh_drawing_fontmgr)  [OH_Drawing_FontMgr](#oh_drawing_fontmgr) | Defines a struct for the font manager, which is used for font management.|
| typedef struct [OH_Drawing_FontStyleSet](#oh_drawing_fontstyleset)  [OH_Drawing_FontStyleSet](#oh_drawing_fontstyleset) | Defines a struct for a font style set, which is used for font style family matching.|
| typedef enum [OH_Drawing_CanvasShadowFlags](#oh_drawing_canvasshadowflags) [OH_Drawing_CanvasShadowFlags](#oh_drawing_canvasshadowflags) | Defines an enum for the shadow flags.|

### Enums

| Name| Description|
| -------- | -------- |
| [OH_Drawing_SystemFontType](#oh_drawing_systemfonttype-1) { ALL = 1 &lt;&lt; 0, GENERIC = 1 &lt;&lt; 1, STYLISH = 1 &lt;&lt; 2, INSTALLED = 1 &lt;&lt; 3 } | Enumerates the system font types.|
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode-1) { OH_DRAWING_SUCCESS = 0, OH_DRAWING_ERROR_NO_PERMISSION = 201, OH_DRAWING_ERROR_INVALID_PARAMETER = 401, OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE = 26200001,OH_DRAWING_ERROR_ALLOCATION_FAILED = 26200002 } | Enumerates the error codes that may be generated by the module.|
| [OH_Drawing_PathOpMode](#oh_drawing_pathopmode-1) {<br>PATH_OP_MODE_DIFFERENCE, PATH_OP_MODE_INTERSECT, PATH_OP_MODE_UNION, PATH_OP_MODE_XOR,<br>PATH_OP_MODE_REVERSE_DIFFERENCE<br>} | Enumerates the operation modes available for a path.|
| [OH_Drawing_PathMeasureMatrixFlags](#oh_drawing_pathmeasurematrixflags-1) { GET_POSITION_MATRIX, GET_TANGENT_MATRIX, GET_POSITION_AND_TANGENT_MATRIX } | Enumerates the types of matrix information obtained during path measurement.|
| [OH_Drawing_RegionOpMode](#oh_drawing_regionopmode-1) {<br>REGION_OP_MODE_DIFFERENCE, REGION_OP_MODE_INTERSECT, REGION_OP_MODE_UNION, REGION_OP_MODE_XOR,<br>REGION_OP_MODE_REVERSE_DIFFERENCE, REGION_OP_MODE_REPLACE<br>} | Enumerates the operation modes available for a region.|
| [OH_Drawing_SrcRectConstraint](#oh_drawing_srcrectconstraint-1) { STRICT_SRC_RECT_CONSTRAINT, FAST_SRC_RECT_CONSTRAINT } | Enumerates the constraint types of the source rectangle.|
| [OH_Drawing_PointMode](#oh_drawing_pointmode-1) { POINT_MODE_POINTS, POINT_MODE_LINES, POINT_MODE_POLYGON } | Enumerates the modes of drawing multiple points. The modes include discrete points, line segments, and open polygons.|
| [OH_Drawing_VertexMode](#oh_drawing_vertexmode-1) { VERTEX_MODE_TRIANGLES, VERTEX_MODE_TRIANGLESSTRIP, VERTEX_MODE_TRIANGLEFAN } | Enumerates the modes of interpreting the geometry of a given vertex.|
| [OH_Drawing_CanvasClipOp](#oh_drawing_canvasclipop-1) { DIFFERENCE, INTERSECT } | Enumerates the canvas clipping modes.|
| [OH_Drawing_FontEdging](#oh_drawing_fontedging-1) { FONT_EDGING_ALIAS, FONT_EDGING_ANTI_ALIAS, FONT_EDGING_SUBPIXEL_ANTI_ALIAS } | Enumerates the font edging types.|
| [OH_Drawing_FontHinting](#oh_drawing_fonthinting-1) { FONT_HINTING_NONE, FONT_HINTING_SLIGHT, FONT_HINTING_NORMAL, FONT_HINTING_FULL } | Enumerates the font hinting types.|
| [OH_Drawing_BlurType](#oh_drawing_blurtype-1) { NORMAL, SOLID, OUTER, INNER } | Enumerates the blur types.|
| [OH_Drawing_ScaleToFit](#oh_drawing_scaletofit-1) { SCALE_TO_FIT_FILL, SCALE_TO_FIT_START, SCALE_TO_FIT_CENTER, SCALE_TO_FIT_END } | Enumerates the matrix scaling modes.|
| [OH_Drawing_PathDirection](#oh_drawing_pathdirection-1) { PATH_DIRECTION_CW, PATH_DIRECTION_CCW } | Enumerates the directions of a closed contour.|
| [OH_Drawing_PathFillType](#oh_drawing_pathfilltype-1) { PATH_FILL_TYPE_WINDING, PATH_FILL_TYPE_EVEN_ODD, PATH_FILL_TYPE_INVERSE_WINDING, PATH_FILL_TYPE_INVERSE_EVEN_ODD } | Enumerates the fill types of a path.|
| [OH_Drawing_PathAddMode](#oh_drawing_pathaddmode-1) { PATH_ADD_MODE_APPEND, PATH_ADD_MODE_EXTEND } | Enumerates the path adding modes.|
| [OH_Drawing_PenLineCapStyle](#oh_drawing_penlinecapstyle-1) { LINE_FLAT_CAP, LINE_SQUARE_CAP, LINE_ROUND_CAP } | Enumerates the line cap styles of a pen. The line cap style defines the style of both ends of a line segment drawn by the pen.|
| [OH_Drawing_PenLineJoinStyle](#oh_drawing_penlinejoinstyle-1) { LINE_MITER_JOIN, LINE_ROUND_JOIN, LINE_BEVEL_JOIN } | Enumerates the line join styles of a pen. The line join style defines the shape of the joints of a polyline segment drawn by the pen.|
| [OH_Drawing_CornerPos](#oh_drawing_cornerpos-1) { CORNER_POS_TOP_LEFT, CORNER_POS_TOP_RIGHT, CORNER_POS_BOTTOM_RIGHT, CORNER_POS_BOTTOM_LEFT } | Enumerates the corner positions of a rounded rectangle.|
| [OH_Drawing_FilterMode](#oh_drawing_filtermode-1) { FILTER_MODE_NEAREST, FILTER_MODE_LINEAR } | Enumerates the filter modes.|
| [OH_Drawing_MipmapMode](#oh_drawing_mipmapmode-1) { MIPMAP_MODE_NONE, MIPMAP_MODE_NEAREST, MIPMAP_MODE_LINEAR } | Enumerates the mipmap modes.|
| [OH_Drawing_TileMode](#oh_drawing_tilemode-1) { CLAMP, REPEAT, MIRROR, DECAL } | Enumerates the tile modes of the shader effect.|
| [OH_Drawing_TextDirection](#oh_drawing_textdirection) { TEXT_DIRECTION_RTL, TEXT_DIRECTION_LTR } | Enumerates the text directions.|
| [OH_Drawing_TextAlign](#oh_drawing_textalign) {<br>TEXT_ALIGN_LEFT, TEXT_ALIGN_RIGHT, TEXT_ALIGN_CENTER, TEXT_ALIGN_JUSTIFY,<br>TEXT_ALIGN_START, TEXT_ALIGN_END<br>} | Enumerates the text alignment modes.|
| [OH_Drawing_FontWeight](#oh_drawing_fontweight) {<br>FONT_WEIGHT_100, FONT_WEIGHT_200, FONT_WEIGHT_300, FONT_WEIGHT_400,<br>FONT_WEIGHT_500, FONT_WEIGHT_600, FONT_WEIGHT_700, FONT_WEIGHT_800,<br>FONT_WEIGHT_900<br>} | Enumerates the font weights.|
| [OH_Drawing_TextBaseline](#oh_drawing_textbaseline) { TEXT_BASELINE_ALPHABETIC, TEXT_BASELINE_IDEOGRAPHIC } | Enumerates the text baselines.|
| [OH_Drawing_TextDecoration](#oh_drawing_textdecoration) { TEXT_DECORATION_NONE = 0x0, TEXT_DECORATION_UNDERLINE = 0x1, TEXT_DECORATION_OVERLINE = 0x2, TEXT_DECORATION_LINE_THROUGH = 0x4 } | Enumerates the text decorations.|
| [OH_Drawing_FontStyle](#oh_drawing_fontstyle) { FONT_STYLE_NORMAL, FONT_STYLE_ITALIC, FONT_STYLE_OBLIQUE } | Enumerates the font styles.|
| [OH_Drawing_PlaceholderVerticalAlignment](#oh_drawing_placeholderverticalalignment-1) {<br>ALIGNMENT_OFFSET_AT_BASELINE, ALIGNMENT_ABOVE_BASELINE, ALIGNMENT_BELOW_BASELINE, ALIGNMENT_TOP_OF_ROW_BOX,<br>ALIGNMENT_BOTTOM_OF_ROW_BOX, ALIGNMENT_CENTER_OF_ROW_BOX<br>} | Enumerates the vertical alignment modes of placeholders.|
| [OH_Drawing_TextDecorationStyle](#oh_drawing_textdecorationstyle-1) {<br>TEXT_DECORATION_STYLE_SOLID, TEXT_DECORATION_STYLE_DOUBLE, TEXT_DECORATION_STYLE_DOTTED, TEXT_DECORATION_STYLE_DASHED,<br>TEXT_DECORATION_STYLE_WAVY<br>} | Enumerates the text decoration styles.|
| [OH_Drawing_EllipsisModal](#oh_drawing_ellipsismodal-1) { ELLIPSIS_MODAL_HEAD = 0, ELLIPSIS_MODAL_MIDDLE = 1, ELLIPSIS_MODAL_TAIL = 2 } | Enumerates the text ellipsis styles.|
| [OH_Drawing_BreakStrategy](#oh_drawing_breakstrategy-1) { BREAK_STRATEGY_GREEDY = 0, BREAK_STRATEGY_HIGH_QUALITY = 1, BREAK_STRATEGY_BALANCED = 2 } | Enumerates the text break strategies.|
| [OH_Drawing_WordBreakType](#oh_drawing_wordbreaktype-1) { WORD_BREAK_TYPE_NORMAL = 0, WORD_BREAK_TYPE_BREAK_ALL = 1, WORD_BREAK_TYPE_BREAK_WORD = 2 } | Enumerates the word break types.|
| [OH_Drawing_RectHeightStyle](#oh_drawing_rectheightstyle-1) {<br>RECT_HEIGHT_STYLE_TIGHT, RECT_HEIGHT_STYLE_MAX, RECT_HEIGHT_STYLE_INCLUDELINESPACEMIDDLE, RECT_HEIGHT_STYLE_INCLUDELINESPACETOP,<br>RECT_HEIGHT_STYLE_INCLUDELINESPACEBOTTOM, RECT_HEIGHT_STYLE_STRUCT<br>} | Enumerates the rectangle height styles.|
| [OH_Drawing_RectWidthStyle](#oh_drawing_rectwidthstyle-1) { RECT_WIDTH_STYLE_TIGHT, RECT_WIDTH_STYLE_MAX } | Enumerates the rectangle width styles.|
| [OH_Drawing_FontConfigInfoErrorCode](#oh_drawing_fontconfiginfoerrorcode) {<br>SUCCESS_FONT_CONFIG_INFO = 0, ERROR_FONT_CONFIG_INFO_UNKNOWN = 1, ERROR_FONT_CONFIG_INFO_PARSE_FILE = 2, ERROR_FONT_CONFIG_INFO_ALLOC_MEMORY = 3,<br>ERROR_FONT_CONFIG_INFO_COPY_STRING_DATA = 4<br>} | Enumerates the error codes that may be used during the obtaining of system font configurations.|
| [OH_Drawing_FontWidth](#oh_drawing_fontwidth) {<br>ULTRA_CONDENSED_WIDTH = 1, EXTRA_CONDENSED_WIDTH = 2, CONDENSED_WIDTH = 3, SEMI_CONDENSED_WIDTH = 4,<br>NORMAL_WIDTH = 5, SEMI_EXPANDED_WIDTH = 6, EXPANDED_WIDTH = 7, EXTRA_EXPANDED_WIDTH = 8,<br>ULTRA_EXPANDED_WIDTH = 9<br>} | Enumerates the font widths.|
| [OH_Drawing_TextHeightBehavior](#oh_drawing_textheightbehavior) { TEXT_HEIGHT_ALL = 0x0, TEXT_HEIGHT_DISABLE_FIRST_ASCENT = 0x1, TEXT_HEIGHT_DISABLE_LAST_ASCENT = 0x2, TEXT_HEIGHT_DISABLE_ALL = 0x1 \| 0x2 } | Enumerates the text height modifier patterns.|
| [OH_Drawing_TextStyleType](#oh_drawing_textstyletype) {<br>TEXT_STYLE_NONE, TEXT_STYLE_ALL_ATTRIBUTES, TEXT_STYLE_FONT, TEXT_STYLE_FOREGROUND,<br>TEXT_STYLE_BACKGROUND, TEXT_STYLE_SHADOW, TEXT_STYLE_DECORATIONS, TEXT_STYLE_LETTER_SPACING,<br>TEXT_STYLE_WORD_SPACING<br>} | Enumerates the text style types.|
| [OH_Drawing_ColorFormat](#oh_drawing_colorformat-1) {<br>COLOR_FORMAT_UNKNOWN, COLOR_FORMAT_ALPHA_8, COLOR_FORMAT_RGB_565, COLOR_FORMAT_ARGB_4444,<br>COLOR_FORMAT_RGBA_8888, COLOR_FORMAT_BGRA_8888<br>} | Enumerates the storage formats of bitmap pixels.|
| [OH_Drawing_AlphaFormat](#oh_drawing_alphaformat-1) { ALPHA_FORMAT_UNKNOWN, ALPHA_FORMAT_OPAQUE, ALPHA_FORMAT_PREMUL, ALPHA_FORMAT_UNPREMUL } | Enumerates the alpha formats of bitmap pixels.|
| [OH_Drawing_BlendMode](#oh_drawing_blendmode-1) {<br>BLEND_MODE_CLEAR, BLEND_MODE_SRC, BLEND_MODE_DST, BLEND_MODE_SRC_OVER,<br>BLEND_MODE_DST_OVER, BLEND_MODE_SRC_IN, BLEND_MODE_DST_IN, BLEND_MODE_SRC_OUT,<br>BLEND_MODE_DST_OUT, BLEND_MODE_SRC_ATOP, BLEND_MODE_DST_ATOP, BLEND_MODE_XOR,<br>BLEND_MODE_PLUS, BLEND_MODE_MODULATE, BLEND_MODE_SCREEN, BLEND_MODE_OVERLAY,<br>BLEND_MODE_DARKEN, BLEND_MODE_LIGHTEN, BLEND_MODE_COLOR_DODGE, BLEND_MODE_COLOR_BURN,<br>BLEND_MODE_HARD_LIGHT, BLEND_MODE_SOFT_LIGHT, BLEND_MODE_DIFFERENCE, BLEND_MODE_EXCLUSION,<br>BLEND_MODE_MULTIPLY, BLEND_MODE_HUE, BLEND_MODE_SATURATION, BLEND_MODE_COLOR,<br>BLEND_MODE_LUMINOSITY<br>} | Enumerates the blend modes. In blend mode, each operation generates a new color from two colors (source color and target color). These operations are the same on the four channels (red, green, blue, and alpha). The operations for the alpha channel are used as examples.|
| [OH_Drawing_TextEncoding](#oh_drawing_textencoding-1) { TEXT_ENCODING_UTF8, TEXT_ENCODING_UTF16, TEXT_ENCODING_UTF32, TEXT_ENCODING_GLYPH_ID } | Enumerates the text encoding types.|
| [OH_Drawing_CanvasShadowFlags](#oh_drawing_canvasshadowflags-1) { SHADOW_FLAGS_NONE, SHADOW_FLAGS_TRANSPARENT_OCCLUDER, SHADOW_FLAGS_GEOMETRIC_ONLY, SHADOW_FLAGS_ALL } | Enumerates the shadow flags.|

### Functions

| Name| Description|
| -------- | -------- |
| [OH_Drawing_Bitmap](#oh_drawing_bitmap) \* [OH_Drawing_BitmapCreate](#oh_drawing_bitmapcreate) (void) | Creates an **OH_Drawing_Bitmap** object.|
| void [OH_Drawing_BitmapDestroy](#oh_drawing_bitmapdestroy) ([OH_Drawing_Bitmap](#oh_drawing_bitmap) \*) | Destroys an **OH_Drawing_Bitmap** object and reclaims the memory occupied by the object.|
| [OH_Drawing_Bitmap](#oh_drawing_bitmap) \* [OH_Drawing_BitmapCreateFromPixels](#oh_drawing_bitmapcreatefrompixels) ([OH_Drawing_Image_Info](_o_h___drawing___image___info.md) \*, void \*pixels, uint32_t rowBytes) | Creates an **OH_Drawing_Bitmap** object, with the address of the memory for storing the bitmap pixels set to the memory address that you applied for.|
| void [OH_Drawing_BitmapBuild](#oh_drawing_bitmapbuild) ([OH_Drawing_Bitmap](#oh_drawing_bitmap) \*, const uint32_t width, const uint32_t height, const [OH_Drawing_BitmapFormat](_o_h___drawing___bitmap_format.md) \*) | Initializes the width and height of a bitmap and sets the pixel format for the bitmap.|
| uint32_t [OH_Drawing_BitmapGetWidth](#oh_drawing_bitmapgetwidth) ([OH_Drawing_Bitmap](#oh_drawing_bitmap) \*) | Obtains the width of a bitmap.|
| uint32_t [OH_Drawing_BitmapGetHeight](#oh_drawing_bitmapgetheight) ([OH_Drawing_Bitmap](#oh_drawing_bitmap) \*) | Obtains the height of a bitmap.|
| [OH_Drawing_ColorFormat](#oh_drawing_colorformat) [OH_Drawing_BitmapGetColorFormat](#oh_drawing_bitmapgetcolorformat) ([OH_Drawing_Bitmap](#oh_drawing_bitmap) \*) | Obtains the pixel format of a bitmap.|
| [OH_Drawing_AlphaFormat](#oh_drawing_alphaformat) [OH_Drawing_BitmapGetAlphaFormat](#oh_drawing_bitmapgetalphaformat) ([OH_Drawing_Bitmap](#oh_drawing_bitmap) \*) | Obtains the alpha component of a bitmap.|
| void \* [OH_Drawing_BitmapGetPixels](#oh_drawing_bitmapgetpixels) ([OH_Drawing_Bitmap](#oh_drawing_bitmap) \*) | Obtains the pixel address of a bitmap. You can use this address to obtain the pixel data of the bitmap.|
| void [OH_Drawing_BitmapGetImageInfo](#oh_drawing_bitmapgetimageinfo) ([OH_Drawing_Bitmap](#oh_drawing_bitmap) \*, [OH_Drawing_Image_Info](_o_h___drawing___image___info.md) \*) | Obtains the image information of a bitmap.|
| bool [OH_Drawing_BitmapReadPixels](#oh_drawing_bitmapreadpixels) ([OH_Drawing_Bitmap](#oh_drawing_bitmap) \*, const [OH_Drawing_Image_Info](_o_h___drawing___image___info.md) \*dstInfo, void \*dstPixels, size_t dstRowBytes, int32_t srcX, int32_t srcY) | Reads pixels of a rectangle in a bitmap to the specified buffer.|
| [OH_Drawing_Brush](#oh_drawing_brush) \* [OH_Drawing_BrushCreate](#oh_drawing_brushcreate) (void) | Creates an **OH_Drawing_Brush** object.|
| [OH_Drawing_Brush](#oh_drawing_brush) \* [OH_Drawing_BrushCopy](#oh_drawing_brushcopy) ([OH_Drawing_Brush](#oh_drawing_brush) \*brush) | Copies an existing [OH_Drawing_Brush](#oh_drawing_brush) object to create a new one.|
| void [OH_Drawing_BrushDestroy](#oh_drawing_brushdestroy) ([OH_Drawing_Brush](#oh_drawing_brush) \*) | Destroys an **OH_Drawing_Brush** object and reclaims the memory occupied by the object.|
| bool [OH_Drawing_BrushIsAntiAlias](#oh_drawing_brushisantialias) (const [OH_Drawing_Brush](#oh_drawing_brush) \*) | Checks whether anti-aliasing is enabled for a brush. Anti-aliasing makes the pixels around the shape edges semi-transparent.|
| void [OH_Drawing_BrushSetAntiAlias](#oh_drawing_brushsetantialias) ([OH_Drawing_Brush](#oh_drawing_brush) \*, bool) | Enables or disables anti-aliasing for a brush. Anti-aliasing makes the pixels around the shape edges semi-transparent.|
| uint32_t [OH_Drawing_BrushGetColor](#oh_drawing_brushgetcolor) (const [OH_Drawing_Brush](#oh_drawing_brush) \*) | Obtains the color of a brush. The color is used by the brush to fill in a shape.|
| void [OH_Drawing_BrushSetColor](#oh_drawing_brushsetcolor) ([OH_Drawing_Brush](#oh_drawing_brush) \*, uint32_t color) | Sets the color for a brush. The color is used by the brush to fill in a shape.|
| uint8_t [OH_Drawing_BrushGetAlpha](#oh_drawing_brushgetalpha) (const [OH_Drawing_Brush](#oh_drawing_brush) \*) | Obtains the alpha value of a brush. This value is used by the alpha channel when the brush fills in a shape.|
| void [OH_Drawing_BrushSetAlpha](#oh_drawing_brushsetalpha) ([OH_Drawing_Brush](#oh_drawing_brush) \*, uint8_t alpha) | Sets the alpha value for a brush. This value is used by the alpha channel when the brush fills in a shape.|
| void [OH_Drawing_BrushSetShaderEffect](#oh_drawing_brushsetshadereffect) ([OH_Drawing_Brush](#oh_drawing_brush) \*, [OH_Drawing_ShaderEffect](#oh_drawing_shadereffect) \*) | Sets the shader effect for a brush.|
| void [OH_Drawing_BrushSetShadowLayer](#oh_drawing_brushsetshadowlayer) ([OH_Drawing_Brush](#oh_drawing_brush) \*, [OH_Drawing_ShadowLayer](#oh_drawing_shadowlayer) \*) | Sets the shadow layer for a brush. The shadow layer effect takes effect only when text is drawn.|
| void [OH_Drawing_BrushSetFilter](#oh_drawing_brushsetfilter) ([OH_Drawing_Brush](#oh_drawing_brush) \*, [OH_Drawing_Filter](#oh_drawing_filter) \*) | Sets a filter for a brush. The filter is a container that holds a mask filter and color filter.|
| void [OH_Drawing_BrushGetFilter](#oh_drawing_brushgetfilter) ([OH_Drawing_Brush](#oh_drawing_brush) \*, [OH_Drawing_Filter](#oh_drawing_filter) \*) | Obtains the filter of a brush. The filter is a container that holds a mask filter and color filter.|
| void [OH_Drawing_BrushSetBlendMode](#oh_drawing_brushsetblendmode) ([OH_Drawing_Brush](#oh_drawing_brush) \*, [OH_Drawing_BlendMode](#oh_drawing_blendmode)) | Sets a blender for a brush. The blender implements the specified blend mode.|
| void [OH_Drawing_BrushReset](#oh_drawing_brushreset) ([OH_Drawing_Brush](#oh_drawing_brush) \*) | Resets a brush to the initial state. All configured attributes are cleared.|
| [OH_Drawing_Canvas](#oh_drawing_canvas) \* [OH_Drawing_CanvasCreate](#oh_drawing_canvascreate) (void) | Creates an **OH_Drawing_Canvas** object.|
| void [OH_Drawing_CanvasDestroy](#oh_drawing_canvasdestroy) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*) | Destroys an **OH_Drawing_Canvas** object and reclaims the memory occupied by the object.|
| void [OH_Drawing_CanvasBind](#oh_drawing_canvasbind) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, [OH_Drawing_Bitmap](#oh_drawing_bitmap) \*) | Binds a bitmap to a canvas so that the content drawn on the canvas is output to the bitmap. (This process is called CPU rendering.)|
| void [OH_Drawing_CanvasAttachPen](#oh_drawing_canvasattachpen) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Pen](#oh_drawing_pen) \*) | Attaches a pen to a canvas so that the canvas can use the style and color of the pen to outline a shape.|
| void [OH_Drawing_CanvasDetachPen](#oh_drawing_canvasdetachpen) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*) | Detaches the pen from a canvas so that the canvas can no longer use the style and color of the pen to outline a shape.|
| void [OH_Drawing_CanvasAttachBrush](#oh_drawing_canvasattachbrush) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Brush](#oh_drawing_brush) \*) | Attaches a brush to a canvas so that the canvas can use the style and color of the brush to fill in a shape.|
| void [OH_Drawing_CanvasDetachBrush](#oh_drawing_canvasdetachbrush) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*) | Detaches the brush from a canvas so that the canvas can no longer use the previously set brush to fill in a shape.|
| void [OH_Drawing_CanvasSave](#oh_drawing_canvassave) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*) | Saves the current canvas status (canvas matrix) to the top of the stack.|
| void [OH_Drawing_CanvasSaveLayer](#oh_drawing_canvassavelayer) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Rect](#oh_drawing_rect) \*, const [OH_Drawing_Brush](#oh_drawing_brush) \*) | Saves the matrix and cropping region, and allocates a bitmap for subsequent drawing. If you call [OH_Drawing_CanvasRestore](#oh_drawing_canvasrestore), the changes made to the matrix and clipping region are discarded, and the bitmap is drawn.|
| void [OH_Drawing_CanvasRestore](#oh_drawing_canvasrestore) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*) | Restores the canvas status (canvas matrix) saved on the top of the stack.|
| uint32_t [OH_Drawing_CanvasGetSaveCount](#oh_drawing_canvasgetsavecount) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*) | Obtains the number of canvas statuses (canvas matrices) saved in the stack.|
| void [OH_Drawing_CanvasRestoreToCount](#oh_drawing_canvasrestoretocount) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, uint32_t saveCount) | Restores to a given number of canvas statuses (canvas matrices).|
| void [OH_Drawing_CanvasDrawLine](#oh_drawing_canvasdrawline) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, float x1, float y1, float x2, float y2) | Draws a line segment.|
| void [OH_Drawing_CanvasDrawPath](#oh_drawing_canvasdrawpath) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Path](#oh_drawing_path) \*) | Draws a path.|
| void [OH_Drawing_CanvasDrawPixelMapRect](#oh_drawing_canvasdrawpixelmaprect) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, [OH_Drawing_PixelMap](#oh_drawing_pixelmap) \*, const [OH_Drawing_Rect](#oh_drawing_rect) \*src, const [OH_Drawing_Rect](#oh_drawing_rect) \*dst, const [OH_Drawing_SamplingOptions](#oh_drawing_samplingoptions) \*) | Draws a portion of a pixel map onto a specified area of the canvas.|
| void [OH_Drawing_CanvasDrawBackground](#oh_drawing_canvasdrawbackground) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Brush](#oh_drawing_brush) \*) | Draws a background filled with a brush.|
| void [OH_Drawing_CanvasDrawRegion](#oh_drawing_canvasdrawregion) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Region](#oh_drawing_region) \*) | Draws a region.|
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_CanvasDrawPoint](#oh_drawing_canvasdrawpoint) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*canvas, const [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*point) | Draws a point.|
| void [OH_Drawing_CanvasDrawPoints](#oh_drawing_canvasdrawpoints) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, [OH_Drawing_PointMode](#oh_drawing_pointmode) mode, uint32_t count, const [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*) | Draws multiple points. You can draw a single point, a line segment, or an open polygon.|
| void [OH_Drawing_CanvasDrawBitmap](#oh_drawing_canvasdrawbitmap) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Bitmap](#oh_drawing_bitmap) \*, float left, float top) | Draws a bitmap. A bitmap, also referred to as a dot matrix image, a pixel map image, or a grid image, includes single points called pixels (image elements).|
| void [OH_Drawing_CanvasDrawBitmapRect](#oh_drawing_canvasdrawbitmaprect) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Bitmap](#oh_drawing_bitmap) \*, const [OH_Drawing_Rect](#oh_drawing_rect) \*src, const [OH_Drawing_Rect](#oh_drawing_rect) \*dst, const [OH_Drawing_SamplingOptions](#oh_drawing_samplingoptions) \*) | Draws a portion of a bitmap onto a specified area of the canvas.|
| void [OH_Drawing_CanvasSetMatrix](#oh_drawing_canvassetmatrix) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, [OH_Drawing_Matrix](#oh_drawing_matrix) \*) | Sets the matrix status for a canvas.|
| void [OH_Drawing_CanvasResetMatrix](#oh_drawing_canvasresetmatrix) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*) | Resets the matrix of a canvas to an identity matrix.|
| void [OH_Drawing_CanvasDrawImageRectWithSrc](#oh_drawing_canvasdrawimagerectwithsrc) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Image](#oh_drawing_image) \*, const [OH_Drawing_Rect](#oh_drawing_rect) \*src, const [OH_Drawing_Rect](#oh_drawing_rect) \*dst, const [OH_Drawing_SamplingOptions](#oh_drawing_samplingoptions) \*, [OH_Drawing_SrcRectConstraint](#oh_drawing_srcrectconstraint)) | Draws a portion of an image onto a specified area of the canvas. The area selected by the source rectangle is scaled and translated to the destination rectangle.|
| void [OH_Drawing_CanvasDrawImageRect](#oh_drawing_canvasdrawimagerect) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, [OH_Drawing_Image](#oh_drawing_image) \*, [OH_Drawing_Rect](#oh_drawing_rect) \*dst, [OH_Drawing_SamplingOptions](#oh_drawing_samplingoptions) \*) | Draws an image onto a specified area of the canvas.|
| void [OH_Drawing_CanvasDrawVertices](#oh_drawing_canvasdrawvertices) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, [OH_Drawing_VertexMode](#oh_drawing_vertexmode) vertexMmode, int32_t vertexCount, const [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*positions, const [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*texs, const uint32_t \*colors, int32_t indexCount, const uint16_t \*indices, [OH_Drawing_BlendMode](#oh_drawing_blendmode) mode) | Draws a triangular grid described by a vertex array.|
| bool [OH_Drawing_CanvasReadPixels](#oh_drawing_canvasreadpixels) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, [OH_Drawing_Image_Info](_o_h___drawing___image___info.md) \*, void \*dstPixels, uint32_t dstRowBytes, int32_t srcX, int32_t srcY) | Copies pixel data from a canvas to a specified address. This function cannot be used for recorded canvases.|
| bool [OH_Drawing_CanvasReadPixelsToBitmap](#oh_drawing_canvasreadpixelstobitmap) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, [OH_Drawing_Bitmap](#oh_drawing_bitmap) \*, int32_t srcX, int32_t srcY) | Copies pixel data from a canvas to an image. This function cannot be used for recorded canvases.|
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_CanvasIsClipEmpty](#oh_drawing_canvasisclipempty) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*canvas, bool \*isClipEmpty) | Checks whether the region that can be drawn is empty after cropping.|
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_CanvasGetImageInfo](#oh_drawing_canvasgetimageinfo) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*canvas, [OH_Drawing_Image_Info](_o_h___drawing___image___info.md) \*imageInfo) | Obtains the image information of a canvas.|
| void [OH_Drawing_CanvasDrawRect](#oh_drawing_canvasdrawrect) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Rect](#oh_drawing_rect) \*) | Draws a rectangle.|
| void [OH_Drawing_CanvasDrawCircle](#oh_drawing_canvasdrawcircle) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Point](#oh_drawing_point) \*, float radius) | Draws a circle.|
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_CanvasDrawColor](#oh_drawing_canvasdrawcolor) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*canvas, uint32_t color, [OH_Drawing_BlendMode](#oh_drawing_blendmode) blendMode) | Fills the entire canvas with the specified color and blend mode.|
| void [OH_Drawing_CanvasDrawOval](#oh_drawing_canvasdrawoval) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Rect](#oh_drawing_rect) \*) | Draws an oval.|
| void [OH_Drawing_CanvasDrawArc](#oh_drawing_canvasdrawarc) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Rect](#oh_drawing_rect) \*, float startAngle, float sweepAngle) | Draws an arc.|
| void [OH_Drawing_CanvasDrawRoundRect](#oh_drawing_canvasdrawroundrect) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_RoundRect](#oh_drawing_roundrect) \*) | Draws a rounded rectangle.|
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_CanvasDrawSingleCharacter](#oh_drawing_canvasdrawsinglecharacter) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*canvas, const char \*str, const [OH_Drawing_Font](#oh_drawing_font) \*font, float x, float y) | Draws a single character. If the typeface of the current font does not support the character to draw, the system typeface is used to draw the character.|
| void [OH_Drawing_CanvasDrawTextBlob](#oh_drawing_canvasdrawtextblob) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_TextBlob](#oh_drawing_textblob) \*, float x, float y) | Draws a text blob. If the typeface used to construct **OH_Drawing_TextBlob** does not support a character, that character will not be drawn.|
| uint32_t [OH_Drawing_ColorSetArgb](#oh_drawing_colorsetargb) (uint32_t alpha, uint32_t red, uint32_t green, uint32_t blue) | Converts four variables (alpha, red, green, and blue) into a 32-bit (ARGB) variable that describes a color.|
| [OH_Drawing_ColorFilter](#oh_drawing_colorfilter) \* [OH_Drawing_ColorFilterCreateBlendMode](#oh_drawing_colorfiltercreateblendmode) (uint32_t color, [OH_Drawing_BlendMode](#oh_drawing_blendmode)) | Creates an **OH_Drawing_ColorFilter** object with a given blend mode.|
| [OH_Drawing_ColorFilter](#oh_drawing_colorfilter) \* [OH_Drawing_ColorFilterCreateCompose](#oh_drawing_colorfiltercreatecompose) ([OH_Drawing_ColorFilter](#oh_drawing_colorfilter) \*colorFilter1, [OH_Drawing_ColorFilter](#oh_drawing_colorfilter) \*colorFilter2) | Creates an **OH_Drawing_ColorFilter** object by combining another two color filters.|
| [OH_Drawing_ColorFilter](#oh_drawing_colorfilter) \* [OH_Drawing_ColorFilterCreateMatrix](#oh_drawing_colorfiltercreatematrix) (const float matrix[20]) | Creates an **OH_Drawing_ColorFilter** object with a given 5x4 color matrix.|
| [OH_Drawing_ColorFilter](#oh_drawing_colorfilter) \* [OH_Drawing_ColorFilterCreateLinearToSrgbGamma](#oh_drawing_colorfiltercreatelineartosrgbgamma) (void) | Creates an **OH_Drawing_ColorFilter** object that applies the sRGB gamma curve to the RGB channels.|
| [OH_Drawing_ColorFilter](#oh_drawing_colorfilter) \* [OH_Drawing_ColorFilterCreateSrgbGammaToLinear](#oh_drawing_colorfiltercreatesrgbgammatolinear) (void) | Creates an **OH_Drawing_ColorFilter** object that applies the RGB channels to the sRGB gamma curve.|
| [OH_Drawing_ColorFilter](#oh_drawing_colorfilter) \* [OH_Drawing_ColorFilterCreateLuma](#oh_drawing_colorfiltercreateluma) (void) | Creates an **OH_Drawing_ColorFilter** object that multiplies the passed-in luma into the alpha channel and sets the RGB channels to zero.|
| void [OH_Drawing_ColorFilterDestroy](#oh_drawing_colorfilterdestroy) ([OH_Drawing_ColorFilter](#oh_drawing_colorfilter) \*) | Destroys an **OH_Drawing_ColorFilter** object and reclaims the memory occupied by the object.|
| [OH_Drawing_ColorSpace](#oh_drawing_colorspace) \* [OH_Drawing_ColorSpaceCreateSrgb](#oh_drawing_colorspacecreatesrgb) (void) | Creates an sRGB color space.|
| [OH_Drawing_ColorSpace](#oh_drawing_colorspace) \* [OH_Drawing_ColorSpaceCreateSrgbLinear](#oh_drawing_colorspacecreatesrgblinear) (void) | Creates an sRGB linear (Gamma 1.0) color space.|
| void [OH_Drawing_ColorSpaceDestroy](#oh_drawing_colorspacedestroy) ([OH_Drawing_ColorSpace](#oh_drawing_colorspace) \*) | Destroys an **OH_Drawing_ColorSpace** object and reclaims the memory occupied by the object.|
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget) () | Obtains the error code of the module.|
| [OH_Drawing_Filter](#oh_drawing_filter) \* [OH_Drawing_FilterCreate](#oh_drawing_filtercreate) (void) | Creates an **OH_Drawing_Filter** object.|
| void [OH_Drawing_FilterSetImageFilter](#oh_drawing_filtersetimagefilter) ([OH_Drawing_Filter](#oh_drawing_filter) \*, [OH_Drawing_ImageFilter](#oh_drawing_imagefilter) \*) | Sets an **OH_Drawing_ImageFilter** object for an **OH_Drawing_Filter** object.|
| void [OH_Drawing_FilterSetMaskFilter](#oh_drawing_filtersetmaskfilter) ([OH_Drawing_Filter](#oh_drawing_filter) \*, [OH_Drawing_MaskFilter](#oh_drawing_maskfilter) \*) | Sets an **OH_Drawing_MaskFilter** object for an **OH_Drawing_Filter** object.|
| void [OH_Drawing_FilterSetColorFilter](#oh_drawing_filtersetcolorfilter) ([OH_Drawing_Filter](#oh_drawing_filter) \*, [OH_Drawing_ColorFilter](#oh_drawing_colorfilter) \*) | Sets an **OH_Drawing_ColorFilter** object for an **OH_Drawing_Filter** object.|
| void [OH_Drawing_FilterGetColorFilter](#oh_drawing_filtergetcolorfilter) ([OH_Drawing_Filter](#oh_drawing_filter) \*, [OH_Drawing_ColorFilter](#oh_drawing_colorfilter) \*) | Obtains an **OH_Drawing_ColorFilter** object from an **OH_Drawing_Filter** object.|
| void [OH_Drawing_FilterDestroy](#oh_drawing_filterdestroy) ([OH_Drawing_Filter](#oh_drawing_filter) \*) | Destroys an **OH_Drawing_Filter** object and reclaims the memory occupied by the object.|
| void [OH_Drawing_FontSetBaselineSnap](#oh_drawing_fontsetbaselinesnap) ([OH_Drawing_Font](#oh_drawing_font) \*, bool baselineSnap) | Sets whether to request that baselines be snapped to pixels when the current canvas matrix is axis aligned.|
| bool [OH_Drawing_FontIsBaselineSnap](#oh_drawing_fontisbaselinesnap) (const [OH_Drawing_Font](#oh_drawing_font) \*) | Checks whether baselines are requested to be snapped to pixels when the current canvas matrix is axis aligned.|
| void [OH_Drawing_FontSetEdging](#oh_drawing_fontsetedging) ([OH_Drawing_Font](#oh_drawing_font) \*, [OH_Drawing_FontEdging](#oh_drawing_fontedging)) | Sets a font edging effect.|
| [OH_Drawing_FontEdging](#oh_drawing_fontedging) [OH_Drawing_FontGetEdging](#oh_drawing_fontgetedging) (const [OH_Drawing_Font](#oh_drawing_font) \*) | Obtains the font edging effect.|
| void [OH_Drawing_FontSetForceAutoHinting](#oh_drawing_fontsetforceautohinting) ([OH_Drawing_Font](#oh_drawing_font) \*, bool isForceAutoHinting) | Sets whether to forcibly use auto hinting, that is, whether to always hint glyphs.|
| bool [OH_Drawing_FontIsForceAutoHinting](#oh_drawing_fontisforceautohinting) (const [OH_Drawing_Font](#oh_drawing_font) \*) | Checks whether auto hinting is forcibly used.|
| void [OH_Drawing_FontSetSubpixel](#oh_drawing_fontsetsubpixel) ([OH_Drawing_Font](#oh_drawing_font) \*, bool isSubpixel) | Sets whether to use sub-pixel rendering for a font.|
| bool [OH_Drawing_FontIsSubpixel](#oh_drawing_fontissubpixel) (const [OH_Drawing_Font](#oh_drawing_font) \*) | Checks whether sub-pixel rendering is used for a font.|
| [OH_Drawing_Font](#oh_drawing_font) \* [OH_Drawing_FontCreate](#oh_drawing_fontcreate) (void) | Creates an **OH_Drawing_Font** object.|
| void [OH_Drawing_FontSetTypeface](#oh_drawing_fontsettypeface) ([OH_Drawing_Font](#oh_drawing_font) \*, [OH_Drawing_Typeface](#oh_drawing_typeface) \*) | Sets the typeface for a font.|
| [OH_Drawing_Typeface](#oh_drawing_typeface) \* [OH_Drawing_FontGetTypeface](#oh_drawing_fontgettypeface) ([OH_Drawing_Font](#oh_drawing_font) \*) | Obtains the typeface of a font.|
| void [OH_Drawing_FontSetTextSize](#oh_drawing_fontsettextsize) ([OH_Drawing_Font](#oh_drawing_font) \*, float textSize) | Sets the font size.|
| float [OH_Drawing_FontGetTextSize](#oh_drawing_fontgettextsize) (const [OH_Drawing_Font](#oh_drawing_font) \*) | Obtains the text size.|
| int [OH_Drawing_FontCountText](#oh_drawing_fontcounttext) ([OH_Drawing_Font](#oh_drawing_font) \*, const void \*text, size_t byteLength, [OH_Drawing_TextEncoding](#oh_drawing_textencoding) encoding) | Obtains the number of glyphs represented by text.|
| uint32_t [OH_Drawing_FontTextToGlyphs](#oh_drawing_fonttexttoglyphs) (const [OH_Drawing_Font](#oh_drawing_font) \*, const void \*text, uint32_t byteLength, [OH_Drawing_TextEncoding](#oh_drawing_textencoding) encoding, uint16_t \*glyphs, int maxGlyphCount) | Converts text into glyph indices.|
| void [OH_Drawing_FontGetWidths](#oh_drawing_fontgetwidths) (const [OH_Drawing_Font](#oh_drawing_font) \*, const uint16_t \*glyphs, int count, float \*widths) | Obtains the width of each glyph in a string of text.|
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_FontMeasureSingleCharacter](#oh_drawing_fontmeasuresinglecharacter) (const [OH_Drawing_Font](#oh_drawing_font) \*font, const char \*str, float \*textWidth) | Measures the width of a single character. If the typeface of the current font does not support the character to measure, the system typeface is used to measure the character width.|
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_FontMeasureText](#oh_drawing_fontmeasuretext) (const [OH_Drawing_Font](#oh_drawing_font) \*font, const void \*text, size_t byteLength, [OH_Drawing_TextEncoding](#oh_drawing_textencoding) encoding, [OH_Drawing_Rect](#oh_drawing_rect) \*bounds, float \*textWidth) | Obtains the text width and bounding box.|
| void [OH_Drawing_FontSetLinearText](#oh_drawing_fontsetlineartext) ([OH_Drawing_Font](#oh_drawing_font) \*, bool isLinearText) | Sets linear scaling for a font.|
| bool [OH_Drawing_FontIsLinearText](#oh_drawing_fontislineartext) (const [OH_Drawing_Font](#oh_drawing_font) \*) | Checks whether linear scaling is used for a font.|
| void [OH_Drawing_FontSetTextSkewX](#oh_drawing_fontsettextskewx) ([OH_Drawing_Font](#oh_drawing_font) \*, float skewX) | Sets a horizontal skew factor for a font.|
| float [OH_Drawing_FontGetTextSkewX](#oh_drawing_fontgettextskewx) (const [OH_Drawing_Font](#oh_drawing_font) \*) | Obtains the horizontal skew factor of a font.|
| void [OH_Drawing_FontSetFakeBoldText](#oh_drawing_fontsetfakeboldtext) ([OH_Drawing_Font](#oh_drawing_font) \*, bool isFakeBoldText) | Sets fake bold for a font by increasing the stroke width.|
| bool [OH_Drawing_FontIsFakeBoldText](#oh_drawing_fontisfakeboldtext) (const [OH_Drawing_Font](#oh_drawing_font) \*) | Checks whether fake bold is used for a font.|
| void [OH_Drawing_FontSetScaleX](#oh_drawing_fontsetscalex) ([OH_Drawing_Font](#oh_drawing_font) \*, float scaleX) | Sets a horizontal scale factor for a font.|
| float [OH_Drawing_FontGetScaleX](#oh_drawing_fontgetscalex) (const [OH_Drawing_Font](#oh_drawing_font) \*) | Obtains the horizontal scale factor of a font.|
| void [OH_Drawing_FontSetHinting](#oh_drawing_fontsethinting) ([OH_Drawing_Font](#oh_drawing_font) \*, [OH_Drawing_FontHinting](#oh_drawing_fonthinting)) | Sets a font hinting effect.|
| [OH_Drawing_FontHinting](#oh_drawing_fonthinting) [OH_Drawing_FontGetHinting](#oh_drawing_fontgethinting) (const [OH_Drawing_Font](#oh_drawing_font) \*) | Obtains the font hinting effect.|
| void [OH_Drawing_FontSetEmbeddedBitmaps](#oh_drawing_fontsetembeddedbitmaps) ([OH_Drawing_Font](#oh_drawing_font) \*, bool isEmbeddedBitmaps) | Sets whether to use bitmaps in a font.|
| bool [OH_Drawing_FontIsEmbeddedBitmaps](#oh_drawing_fontisembeddedbitmaps) (const [OH_Drawing_Font](#oh_drawing_font) \*) | Checks whether bitmaps are used in a font.|
| void [OH_Drawing_FontDestroy](#oh_drawing_fontdestroy) ([OH_Drawing_Font](#oh_drawing_font) \*) | Destroys an **OH_Drawing_Font** object and reclaims the memory occupied by the object.|
| float [OH_Drawing_FontGetMetrics](#oh_drawing_fontgetmetrics) ([OH_Drawing_Font](#oh_drawing_font) \*, [OH_Drawing_Font_Metrics](_o_h___drawing___font___metrics.md) \*) | Obtains the measurement information about a font.|
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_FontGetBounds](#oh_drawing_fontgetbounds) (const [OH_Drawing_Font](#oh_drawing_font) \*font, const uint16_t \*glyphs, uint32_t count, [OH_Drawing_Array](#oh_drawing_array) \*bounds) | Obtains the rectangular bounding box for each glyph in the glyph array.|
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_FontGetPathForGlyph](#oh_drawing_fontgetpathforglyph) (const [OH_Drawing_Font](#oh_drawing_font) \*font, uint16_t glyph, [OH_Drawing_Path](#oh_drawing_path) \*path) | Obtains the path of a glyph.|
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_FontGetTextPath](#oh_drawing_fontgettextpath) (const [OH_Drawing_Font](#oh_drawing_font) \*font, const void \*text, size_t byteLength, [OH_Drawing_TextEncoding](#oh_drawing_textencoding) encoding, float x, float y, [OH_Drawing_Path](#oh_drawing_path) \*path) | Obtains the text outline path.|
| [OH_Drawing_FontCollection](#oh_drawing_fontcollection) \* [OH_Drawing_CreateFontCollection](#oh_drawing_createfontcollection) (void) | Creates an [OH_Drawing_FontCollection](#oh_drawing_fontcollection) object.|
| void [OH_Drawing_DestroyFontCollection](#oh_drawing_destroyfontcollection) ([OH_Drawing_FontCollection](#oh_drawing_fontcollection) \*) | Destroys an **OH_Drawing_FontCollection** object and reclaims the memory occupied by the object.|
| void [OH_Drawing_DisableFontCollectionFallback](#oh_drawing_disablefontcollectionfallback) ([OH_Drawing_FontCollection](#oh_drawing_fontcollection) \*fontCollection) | Disables the alternate fonts.|
| void [OH_Drawing_DisableFontCollectionSystemFont](#oh_drawing_disablefontcollectionsystemfont) ([OH_Drawing_FontCollection](#oh_drawing_fontcollection) \*fontCollection) | Disables the system fonts.|
| [OH_Drawing_FontCollection](#oh_drawing_fontcollection) \* [OH_Drawing_CreateSharedFontCollection](#oh_drawing_createsharedfontcollection) (void) | Creates an [OH_Drawing_FontCollection](#oh_drawing_fontcollection) object that is shareable.|
| void [OH_Drawing_ClearFontCaches](#oh_drawing_clearfontcaches) ([OH_Drawing_FontCollection](#oh_drawing_fontcollection) \*) | Clears the font cache. (The font cache has a memory limit and a clearing mechanism. It occupies limited memory. You are not advised to clear it unless otherwise required.)|
| [OH_Drawing_FontMgr](#oh_drawing_fontmgr) \* [OH_Drawing_FontMgrCreate](#oh_drawing_fontmgrcreate) (void) | Creates an **OH_Drawing_FontMgr** object.|
| void [OH_Drawing_FontMgrDestroy](#oh_drawing_fontmgrdestroy) ([OH_Drawing_FontMgr](#oh_drawing_fontmgr) \*) | Destroys an **OH_Drawing_FontMgr** object and reclaims the memory occupied by the object.|
| int [OH_Drawing_FontMgrGetFamilyCount](#oh_drawing_fontmgrgetfamilycount) ([OH_Drawing_FontMgr](#oh_drawing_fontmgr) \*) | Obtains the number of font families.|
| char \* [OH_Drawing_FontMgrGetFamilyName](#oh_drawing_fontmgrgetfamilyname) ([OH_Drawing_FontMgr](#oh_drawing_fontmgr) \*, int index) | Obtains the font family name based on an index.|
| void [OH_Drawing_FontMgrDestroyFamilyName](#oh_drawing_fontmgrdestroyfamilyname) (char \*familyName) | Reclaims the memory occupied by a font family name.|
| [OH_Drawing_FontStyleSet](#oh_drawing_fontstyleset) \* [OH_Drawing_FontMgrCreateFontStyleSet](#oh_drawing_fontmgrcreatefontstyleset) ([OH_Drawing_FontMgr](#oh_drawing_fontmgr) \*, int index) | Creates a font style set from an **OH_Drawing_FontMgr** object.|
| void [OH_Drawing_FontMgrDestroyFontStyleSet](#oh_drawing_fontmgrdestroyfontstyleset) ([OH_Drawing_FontStyleSet](#oh_drawing_fontstyleset) \*) | Reclaims the memory occupied by a font style set.|
| [OH_Drawing_FontStyleSet](#oh_drawing_fontstyleset) \* [OH_Drawing_FontMgrMatchFamily](#oh_drawing_fontmgrmatchfamily) ([OH_Drawing_FontMgr](#oh_drawing_fontmgr) \*, const char \*familyName) | Obtains a font style set based on a font family name.|
| [OH_Drawing_Typeface](#oh_drawing_typeface) \* [OH_Drawing_FontMgrMatchFamilyStyle](#oh_drawing_fontmgrmatchfamilystyle) ([OH_Drawing_FontMgr](#oh_drawing_fontmgr) \*, const char \*familyName, [OH_Drawing_FontStyleStruct](_o_h___drawing___font_style_struct.md)) | Obtains a typeface based on the font style information and font family name.|
| [OH_Drawing_Typeface](#oh_drawing_typeface) \* [OH_Drawing_FontMgrMatchFamilyStyleCharacter](#oh_drawing_fontmgrmatchfamilystylecharacter) ([OH_Drawing_FontMgr](#oh_drawing_fontmgr) \*, const char \*familyName, [OH_Drawing_FontStyleStruct](_o_h___drawing___font_style_struct.md), const char \*bcp47[], int bcp47Count, int32_t character) | Obtains a typeface for the specified character.|
| [OH_Drawing_Typeface](#oh_drawing_typeface) \* [OH_Drawing_FontStyleSetCreateTypeface](#oh_drawing_fontstylesetcreatetypeface) ([OH_Drawing_FontStyleSet](#oh_drawing_fontstyleset) \*, int index) | Creates a typeface for the specified index.|
| [OH_Drawing_FontStyleStruct](_o_h___drawing___font_style_struct.md) [OH_Drawing_FontStyleSetGetStyle](#oh_drawing_fontstylesetgetstyle) ([OH_Drawing_FontStyleSet](#oh_drawing_fontstyleset) \*, int32_t index, char \*\*styleName) | Obtains the font style.|
| void [OH_Drawing_FontStyleSetFreeStyleName](#oh_drawing_fontstylesetfreestylename) (char \*\*styleName) | Reclaims the memory occupied by a font style.|
| [OH_Drawing_Typeface](#oh_drawing_typeface) \* [OH_Drawing_FontStyleSetMatchStyle](#oh_drawing_fontstylesetmatchstyle) ([OH_Drawing_FontStyleSet](#oh_drawing_fontstyleset) \*, [OH_Drawing_FontStyleStruct](_o_h___drawing___font_style_struct.md) fontStyleStruct) | Obtains the typeface closest to the font style.|
| int [OH_Drawing_FontStyleSetCount](#oh_drawing_fontstylesetcount) ([OH_Drawing_FontStyleSet](#oh_drawing_fontstyleset) \*) | Obtains the number of fonts in the font style set.|
| [OH_Drawing_GpuContext](#oh_drawing_gpucontext) \* [OH_Drawing_GpuContextCreateFromGL](#oh_drawing_gpucontextcreatefromgl) ([OH_Drawing_GpuContextOptions](_o_h___drawing___gpu_context_options.md)) | Creates an **OH_Drawing_GpuContext** object that uses OpenGL as the backend interface.|
| void [OH_Drawing_GpuContextDestroy](#oh_drawing_gpucontextdestroy) ([OH_Drawing_GpuContext](#oh_drawing_gpucontext) \*) | Destroys an **OH_Drawing_GpuContext** object and reclaims the memory occupied by the object.|
| [OH_Drawing_Image](#oh_drawing_image) \* [OH_Drawing_ImageCreate](#oh_drawing_imagecreate) (void) | Creates an **OH_Drawing_Image** object that describes an array of two-dimensional pixels to draw.|
| void [OH_Drawing_ImageDestroy](#oh_drawing_imagedestroy) ([OH_Drawing_Image](#oh_drawing_image) \*) | Destroys an **OH_Drawing_Image** object and reclaims the memory occupied by the object.|
| bool [OH_Drawing_ImageBuildFromBitmap](#oh_drawing_imagebuildfrombitmap) ([OH_Drawing_Image](#oh_drawing_image) \*, [OH_Drawing_Bitmap](#oh_drawing_bitmap) \*) | Builds an image from a bitmap by sharing or copying bitmap pixels. If the bitmap is marked as immutable, the pixel memory is shared, not copied.|
| int32_t [OH_Drawing_ImageGetWidth](#oh_drawing_imagegetwidth) ([OH_Drawing_Image](#oh_drawing_image) \*) | Obtains the image width, that is, the number of pixels in each line.|
| int32_t [OH_Drawing_ImageGetHeight](#oh_drawing_imagegetheight) ([OH_Drawing_Image](#oh_drawing_image) \*) | Obtains the image height, that is, the number of pixel lines.|
| void [OH_Drawing_ImageGetImageInfo](#oh_drawing_imagegetimageinfo) ([OH_Drawing_Image](#oh_drawing_image) \*, [OH_Drawing_Image_Info](_o_h___drawing___image___info.md) \*) | Obtains the image information. After this function is called, the passed-in image information object is filled.|
| [OH_Drawing_ImageFilter](#oh_drawing_imagefilter) \* [OH_Drawing_ImageFilterCreateBlur](#oh_drawing_imagefiltercreateblur) (float sigmaX, float sigmaY, [OH_Drawing_TileMode](#oh_drawing_tilemode), [OH_Drawing_ImageFilter](#oh_drawing_imagefilter) \*input) | Creates an **OH_Drawing_ImageFilter** object with a given blur type.|
| [OH_Drawing_ImageFilter](#oh_drawing_imagefilter) \* [OH_Drawing_ImageFilterCreateFromColorFilter](#oh_drawing_imagefiltercreatefromcolorfilter) ([OH_Drawing_ColorFilter](#oh_drawing_colorfilter) \*colorFilter, [OH_Drawing_ImageFilter](#oh_drawing_imagefilter) \*input) | Creates an **OH_Drawing_ImageFilter** object with a color filter effect.|
| void [OH_Drawing_ImageFilterDestroy](#oh_drawing_imagefilterdestroy) ([OH_Drawing_ImageFilter](#oh_drawing_imagefilter) \*) | Destroys an **OH_Drawing_ImageFilter** object and reclaims the memory occupied by the object.|
| [OH_Drawing_MaskFilter](#oh_drawing_maskfilter) \* [OH_Drawing_MaskFilterCreateBlur](#oh_drawing_maskfiltercreateblur) ([OH_Drawing_BlurType](#oh_drawing_blurtype) blurType, float sigma, bool respectCTM) | Creates an **OH_Drawing_MaskFilter** object with a given blur type.|
| void [OH_Drawing_MaskFilterDestroy](#oh_drawing_maskfilterdestroy) ([OH_Drawing_MaskFilter](#oh_drawing_maskfilter) \*) | Destroys an **OH_Drawing_MaskFilter** object and reclaims the memory occupied by the object.|
| [OH_Drawing_Matrix](#oh_drawing_matrix) \* [OH_Drawing_MatrixCreate](#oh_drawing_matrixcreate) (void) | Creates an **OH_Drawing_Matrix** object.|
| [OH_Drawing_Matrix](#oh_drawing_matrix) \* [OH_Drawing_MatrixCreateRotation](#oh_drawing_matrixcreaterotation) (float deg, float x, float y) | Creates an **OH_Drawing_Matrix** with the rotation attribute. The matrix is obtained by rotating an identity matrix by a given degree around the rotation point (x, y).|
| [OH_Drawing_Matrix](#oh_drawing_matrix) \* [OH_Drawing_MatrixCreateScale](#oh_drawing_matrixcreatescale) (float sx, float sy, float px, float py) | Creates an **OH_Drawing_Matrix** with the scale attribute. The matrix is obtained by scaling an identity matrix with the factor (sx, sy) at the rotation point (px, py).|
| [OH_Drawing_Matrix](#oh_drawing_matrix) \* [OH_Drawing_MatrixCreateTranslation](#oh_drawing_matrixcreatetranslation) (float dx, float dy) | Creates an **OH_Drawing_Matrix** with the translation attribute. The matrix is obtained by translating the identity matrix by the distance (dx, dy).|
| void [OH_Drawing_MatrixSetMatrix](#oh_drawing_matrixsetmatrix) ([OH_Drawing_Matrix](#oh_drawing_matrix) \*, float scaleX, float skewX, float transX, float skewY, float scaleY, float transY, float persp0, float persp1, float persp2) | Sets matrix parameters for an **OH_Drawing_Matrix** object.|
| bool [OH_Drawing_MatrixSetRectToRect](#oh_drawing_matrixsetrecttorect) ([OH_Drawing_Matrix](#oh_drawing_matrix) \*, const [OH_Drawing_Rect](#oh_drawing_rect) \*src, const [OH_Drawing_Rect](#oh_drawing_rect) \*dst, [OH_Drawing_ScaleToFit](#oh_drawing_scaletofit) stf) | Scales a matrix to map a source rectangle to a destination rectangle.|
| void [OH_Drawing_MatrixPreRotate](#oh_drawing_matrixprerotate) ([OH_Drawing_Matrix](#oh_drawing_matrix) \*, float degree, float px, float py) | Premultiplies a matrix by an identity matrix that rotates by a given degree around the rotation point (px, py).  |
| void [OH_Drawing_MatrixPreScale](#oh_drawing_matrixprescale) ([OH_Drawing_Matrix](#oh_drawing_matrix) \*, float sx, float sy, float px, float py) | Premultiplies a matrix by an identity matrix that scales with the factor (sx, sy) at the scale point (px, py).  |
| void [OH_Drawing_MatrixPreTranslate](#oh_drawing_matrixpretranslate) ([OH_Drawing_Matrix](#oh_drawing_matrix) \*, float dx, float dy) | Premultiplies a matrix by an identity matrix that translates by a given distance (dx, dy).  |
| void [OH_Drawing_MatrixPostRotate](#oh_drawing_matrixpostrotate) ([OH_Drawing_Matrix](#oh_drawing_matrix) \*, float degree, float px, float py) | Post multiplies a matrix by an identity matrix that rotates a given degree around the rotation point (px, py).  |
| void [OH_Drawing_MatrixPostScale](#oh_drawing_matrixpostscale) ([OH_Drawing_Matrix](#oh_drawing_matrix) \*, float sx, float sy, float px, float py) | Post multiplies a matrix by an identity matrix that scales with the factor (sx, sy) at the scale point (px, py).  |
| void [OH_Drawing_MatrixPostTranslate](#oh_drawing_matrixposttranslate) ([OH_Drawing_Matrix](#oh_drawing_matrix) \*, float dx, float dy) | Post multiplies a matrix by an identity matrix that translates by a given distance (dx, dy).  |
| void [OH_Drawing_MatrixReset](#oh_drawing_matrixreset) ([OH_Drawing_Matrix](#oh_drawing_matrix) \*) | Resets a matrix to an identity matrix: \| 1 0 0 \| \| 0 1 0 \| \| 0 0 1 \| |
| void [OH_Drawing_MatrixConcat](#oh_drawing_matrixconcat) ([OH_Drawing_Matrix](#oh_drawing_matrix) \*total, const [OH_Drawing_Matrix](#oh_drawing_matrix) \*a, const [OH_Drawing_Matrix](#oh_drawing_matrix) \*b) | Multiplies two matrices to produce a new matrix. For example, if a given matrix a and a given matrix b are shown as follows:\| A B C \| \| J K L \| a = \| D E F \|, b = \| M N O \| \| G H I \| \| P Q R \| then the final matrix total is as follows:\| A B C \| \| J K L \| \| AJ+BM+CP AK+BN+CQ AL+BO+CR \| total = a \* b = \| D E F \| \* \| M N O \| = \| DJ+EM+FP DK+EN+FQ DL+EO+FR \| \| G H I \| \| P Q R \| \| GJ+HM+IP GK+HN+IQ GL+HO+IR \| |
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_MatrixGetAll](#oh_drawing_matrixgetall) ([OH_Drawing_Matrix](#oh_drawing_matrix) \*matrix, float value[9]) | Obtains all element values of a matrix.|
| float [OH_Drawing_MatrixGetValue](#oh_drawing_matrixgetvalue) ([OH_Drawing_Matrix](#oh_drawing_matrix) \*, int index) | Obtains a matrix value of a given index, which ranges from 0 to 8.|
| void [OH_Drawing_MatrixRotate](#oh_drawing_matrixrotate) ([OH_Drawing_Matrix](#oh_drawing_matrix) \*, float degree, float px, float py) | Sets a matrix as an identity matrix and rotates it by a given degree around the rotation point (px, py).|
| void [OH_Drawing_MatrixTranslate](#oh_drawing_matrixtranslate) ([OH_Drawing_Matrix](#oh_drawing_matrix) \*, float dx, float dy) | Sets a matrix as an identity matrix and translates it by a given distance (dx, dy).|
| void [OH_Drawing_MatrixScale](#oh_drawing_matrixscale) ([OH_Drawing_Matrix](#oh_drawing_matrix) \*, float sx, float sy, float px, float py) | Sets a matrix as an identity matrix and scales it with the factor (sx, sy) at the rotation point (px, py).|
| bool [OH_Drawing_MatrixInvert](#oh_drawing_matrixinvert) ([OH_Drawing_Matrix](#oh_drawing_matrix) \*, [OH_Drawing_Matrix](#oh_drawing_matrix) \*inverse) | Inverts a matrix and returns the result.|
| bool [OH_Drawing_MatrixSetPolyToPoly](#oh_drawing_matrixsetpolytopoly) ([OH_Drawing_Matrix](#oh_drawing_matrix) \*, const [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*src, const [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*dst, uint32_t count) | Generates a transformation matrix by setting source points and destination points. Both the number of source points and that of destination points must be in the range [0, 4].|
| void [OH_Drawing_MatrixMapPoints](#oh_drawing_matrixmappoints) (const [OH_Drawing_Matrix](#oh_drawing_matrix) \*, const [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*src, [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*dst, int count) | Maps a source point array to a destination point array by means of matrix transformation.|
| bool [OH_Drawing_MatrixMapRect](#oh_drawing_matrixmaprect) (const [OH_Drawing_Matrix](#oh_drawing_matrix) \*, const [OH_Drawing_Rect](#oh_drawing_rect) \*src, [OH_Drawing_Rect](#oh_drawing_rect) \*dst) | Maps a rectangle to the smallest rectangle that can enclose the vertices to which the four source vertices are mapped by means of matrix transformation.|
| bool [OH_Drawing_MatrixIsEqual](#oh_drawing_matrixisequal) ([OH_Drawing_Matrix](#oh_drawing_matrix) \*, [OH_Drawing_Matrix](#oh_drawing_matrix) \*other) | Checks whether two **OH_Drawing_Matrix** objects are equal.|
| bool [OH_Drawing_MatrixIsIdentity](#oh_drawing_matrixisidentity) ([OH_Drawing_Matrix](#oh_drawing_matrix) \*) | Checks whether an **OH_Drawing_Matrix** object is an identity matrix: \| 1 0 0 \| \| 0 1 0 \| \| 0 0 1 \| |
| void [OH_Drawing_MatrixDestroy](#oh_drawing_matrixdestroy) ([OH_Drawing_Matrix](#oh_drawing_matrix) \*) | Destroys an **OH_Drawing_Matrix** object and reclaims the memory occupied by the object.|
| [OH_Drawing_MemoryStream](#oh_drawing_memorystream) \* [OH_Drawing_MemoryStreamCreate](#oh_drawing_memorystreamcreate) (const void \*data, size_t length, bool copyData) | Creates an **OH_Drawing_MemoryStream** object.|
| void [OH_Drawing_MemoryStreamDestroy](#oh_drawing_memorystreamdestroy) ([OH_Drawing_MemoryStream](#oh_drawing_memorystream) \*) | Destroys an **OH_Drawing_MemoryStream** object and reclaims the memory occupied by the object.|
| [OH_Drawing_Path](#oh_drawing_path) \* [OH_Drawing_PathCreate](#oh_drawing_pathcreate) (void) | Creates an **OH_Drawing_Path** object.|
| [OH_Drawing_Path](#oh_drawing_path) \* [OH_Drawing_PathCopy](#oh_drawing_pathcopy) ([OH_Drawing_Path](#oh_drawing_path) \*) | Copies an existing [OH_Drawing_Path](#oh_drawing_path) object to create a new one.|
| void [OH_Drawing_PathDestroy](#oh_drawing_pathdestroy) ([OH_Drawing_Path](#oh_drawing_path) \*) | Destroys an **OH_Drawing_Path** object and reclaims the memory occupied by the object.|
| void [OH_Drawing_PathMoveTo](#oh_drawing_pathmoveto) ([OH_Drawing_Path](#oh_drawing_path) \*, float x, float y) | Sets the start point of a path.|
| void [OH_Drawing_PathLineTo](#oh_drawing_pathlineto) ([OH_Drawing_Path](#oh_drawing_path) \*, float x, float y) | Draws a line segment from the last point of a path to the target point. If the path is empty, the start point (0, 0) is used.|
| void [OH_Drawing_PathArcTo](#oh_drawing_patharcto) ([OH_Drawing_Path](#oh_drawing_path) \*, float x1, float y1, float x2, float y2, float startDeg, float sweepDeg) | Draws an arc to a path. This is done by using angle arc mode. In this mode, a rectangle is specified first, and then a start angle and a sweep angle are specified. The inscribed ellipse of the rectangle will be used to intercept the arc. The arc is a portion of the ellipse defined by the start angle and the sweep angle. If the path is empty, a line segment from the last point of the path to the start point of the arc is also added.|
| void [OH_Drawing_PathQuadTo](#oh_drawing_pathquadto) ([OH_Drawing_Path](#oh_drawing_path) \*, float ctrlX, float ctrlY, float endX, float endY) | Draws a quadratic Bezier curve from the last point of a path to the target point. If the path is empty, the start point (0, 0) is used.|
| void [OH_Drawing_PathConicTo](#oh_drawing_pathconicto) ([OH_Drawing_Path](#oh_drawing_path) \*, float ctrlX, float ctrlY, float endX, float endY, float weight) | Draws a conic curve from the last point of a path to the target point. If the path is empty, the start point (0, 0) is used.|
| void [OH_Drawing_PathCubicTo](#oh_drawing_pathcubicto) ([OH_Drawing_Path](#oh_drawing_path) \*, float ctrlX1, float ctrlY1, float ctrlX2, float ctrlY2, float endX, float endY) | Draws a cubic Bezier curve from the last point of a path to the target point. If the path is empty, the start point (0, 0) is used.|
| void [OH_Drawing_PathRMoveTo](#oh_drawing_pathrmoveto) ([OH_Drawing_Path](#oh_drawing_path) \*, float x, float y) | Sets the start position relative to the last point of a path. If the path is empty, the start point (0, 0) is used.|
| void [OH_Drawing_PathRLineTo](#oh_drawing_pathrlineto) ([OH_Drawing_Path](#oh_drawing_path) \*, float x, float y) | Draws a line segment from the last point of a path to a point relative to the last point. If the path is empty, the start point (0, 0) is used.|
| void [OH_Drawing_PathRQuadTo](#oh_drawing_pathrquadto) ([OH_Drawing_Path](#oh_drawing_path) \*, float ctrlX, float ctrlY, float endX, float endY) | Draws a quadratic Bezier curve from the last point of a path to a point relative to the last point. If the path is empty, the start point (0, 0) is used.|
| void [OH_Drawing_PathRConicTo](#oh_drawing_pathrconicto) ([OH_Drawing_Path](#oh_drawing_path) \*, float ctrlX, float ctrlY, float endX, float endY, float weight) | Draws a conic curve from the last point of a path to a point relative to the last point. If the path is empty, the start point (0, 0) is used.|
| void [OH_Drawing_PathRCubicTo](#oh_drawing_pathrcubicto) ([OH_Drawing_Path](#oh_drawing_path) \*, float ctrlX1, float ctrlY1, float ctrlX2, float ctrlY2, float endX, float endY) | Draws a cubic Bezier curve from the last point of a path to a point relative to the last point. If the path is empty, the start point (0, 0) is used.|
| void [OH_Drawing_PathAddRect](#oh_drawing_pathaddrect) ([OH_Drawing_Path](#oh_drawing_path) \*, float left, float top, float right, float bottom, [OH_Drawing_PathDirection](#oh_drawing_pathdirection)) | Adds a rectangle contour to a path in the specified direction.|
| void [OH_Drawing_PathAddRectWithInitialCorner](#oh_drawing_pathaddrectwithinitialcorner) ([OH_Drawing_Path](#oh_drawing_path) \*, const [OH_Drawing_Rect](#oh_drawing_rect) \*, [OH_Drawing_PathDirection](#oh_drawing_pathdirection), uint32_t start) | Adds a rectangle contour to a path in the specified direction.|
| void [OH_Drawing_PathAddRoundRect](#oh_drawing_pathaddroundrect) ([OH_Drawing_Path](#oh_drawing_path) \*, const [OH_Drawing_RoundRect](#oh_drawing_roundrect) \*roundRect, [OH_Drawing_PathDirection](#oh_drawing_pathdirection)) | Adds a rounded rectangle to a path in the specified direction.|
| void [OH_Drawing_PathAddOvalWithInitialPoint](#oh_drawing_pathaddovalwithinitialpoint) ([OH_Drawing_Path](#oh_drawing_path) \*, const [OH_Drawing_Rect](#oh_drawing_rect) \*, uint32_t start, [OH_Drawing_PathDirection](#oh_drawing_pathdirection)) | Adds an oval to a path. **OH_Drawing_Rect** specifies the outer tangent rectangle of the oval, and **OH_Drawing_PathDirection** specifies whether the drawing is clockwise or anticlockwise.|
| void [OH_Drawing_PathAddArc](#oh_drawing_pathaddarc) ([OH_Drawing_Path](#oh_drawing_path) \*, const [OH_Drawing_Rect](#oh_drawing_rect) \*, float startAngle, float sweepAngle) | Adds an arc to a path as the start of a new contour. The arc added is part of the inscribed ellipse of the rectangle, from the start angle through the sweep angle. If the sweep angle is less than or equal to -360°, or if the sweep angle is greater than or equal to 360°, and start angle modulo 90 is nearly zero, an oval instead of an ellipse is added.|
| void [OH_Drawing_PathAddPath](#oh_drawing_pathaddpath) ([OH_Drawing_Path](#oh_drawing_path) \*, const [OH_Drawing_Path](#oh_drawing_path) \*src, const [OH_Drawing_Matrix](#oh_drawing_matrix) \*) | Transforms the points in a **src** path by a matrix and adds the new one to the current path.|
| void [OH_Drawing_PathAddPathWithMatrixAndMode](#oh_drawing_pathaddpathwithmatrixandmode) ([OH_Drawing_Path](#oh_drawing_path) \*path, const [OH_Drawing_Path](#oh_drawing_path) \*src, const [OH_Drawing_Matrix](#oh_drawing_matrix) \*, [OH_Drawing_PathAddMode](#oh_drawing_pathaddmode)) | Transforms the points in a **src** path by a matrix and adds the new one to the current path with the specified adding mode.|
| void [OH_Drawing_PathAddPathWithMode](#oh_drawing_pathaddpathwithmode) ([OH_Drawing_Path](#oh_drawing_path) \*path, const [OH_Drawing_Path](#oh_drawing_path) \*src, [OH_Drawing_PathAddMode](#oh_drawing_pathaddmode)) | Adds a **src** path to the current path with the specified adding mode.|
| void [OH_Drawing_PathAddPathWithOffsetAndMode](#oh_drawing_pathaddpathwithoffsetandmode) ([OH_Drawing_Path](#oh_drawing_path) \*path, const [OH_Drawing_Path](#oh_drawing_path) \*src, float dx, float dy, [OH_Drawing_PathAddMode](#oh_drawing_pathaddmode)) | Translates a **src** path by an offset and adds the new one to the current path with the specified adding mode.|
| void [OH_Drawing_PathAddPolygon](#oh_drawing_pathaddpolygon) ([OH_Drawing_Path](#oh_drawing_path) \*path, const [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*points, uint32_t count, bool isClosed) | Adds a polygon to a path.|
| void [OH_Drawing_PathAddCircle](#oh_drawing_pathaddcircle) ([OH_Drawing_Path](#oh_drawing_path) \*path, float x, float y, float radius, [OH_Drawing_PathDirection](#oh_drawing_pathdirection)) | Adds a circle to a path in the specified direction.|
| void [OH_Drawing_PathAddOval](#oh_drawing_pathaddoval) ([OH_Drawing_Path](#oh_drawing_path) \*, const [OH_Drawing_Rect](#oh_drawing_rect) \*, [OH_Drawing_PathDirection](#oh_drawing_pathdirection)) | Adds an oval to a path in the specified direction.|
| bool [OH_Drawing_PathBuildFromSvgString](#oh_drawing_pathbuildfromsvgstring) ([OH_Drawing_Path](#oh_drawing_path) \*path, const char \*str) | Parses the path represented by an SVG string.|
| bool [OH_Drawing_PathContains](#oh_drawing_pathcontains) ([OH_Drawing_Path](#oh_drawing_path) \*, float x, float y) | Checks whether a coordinate point is included in this path. For details, see [OH_Drawing_PathFillType](#oh_drawing_pathfilltype).|
| void [OH_Drawing_PathTransform](#oh_drawing_pathtransform) ([OH_Drawing_Path](#oh_drawing_path) \*, const [OH_Drawing_Matrix](#oh_drawing_matrix) \*) | Transforms the points in a path by a matrix.|
| void [OH_Drawing_PathTransformWithPerspectiveClip](#oh_drawing_pathtransformwithperspectiveclip) ([OH_Drawing_Path](#oh_drawing_path) \*src, const [OH_Drawing_Matrix](#oh_drawing_matrix) \*, [OH_Drawing_Path](#oh_drawing_path) \*dst, bool applyPerspectiveClip) | Transforms the points in a **src** path by a matrix and uses the new one to replace the **dst** path. If **dst** is NULL, the **src** path is replaced.|
| void [OH_Drawing_PathSetFillType](#oh_drawing_pathsetfilltype) ([OH_Drawing_Path](#oh_drawing_path) \*, [OH_Drawing_PathFillType](#oh_drawing_pathfilltype)) | Sets the fill type for a path.|
| float [OH_Drawing_PathGetLength](#oh_drawing_pathgetlength) ([OH_Drawing_Path](#oh_drawing_path) \*, bool forceClosed) | Obtains the length of a path.|
| void [OH_Drawing_PathGetBounds](#oh_drawing_pathgetbounds) ([OH_Drawing_Path](#oh_drawing_path) \*, [OH_Drawing_Rect](#oh_drawing_rect) \*) | Obtains the minimum bounds that enclose a path.|
| void [OH_Drawing_PathClose](#oh_drawing_pathclose) ([OH_Drawing_Path](#oh_drawing_path) \*) | Closes a path by drawing a line segment from the current point to the start point of the path.|
| bool [OH_Drawing_PathIsClosed](#oh_drawing_pathisclosed) ([OH_Drawing_Path](#oh_drawing_path) \*path, bool forceClosed) | Checks whether a path is closed.|
| bool [OH_Drawing_PathGetPositionTangent](#oh_drawing_pathgetpositiontangent) ([OH_Drawing_Path](#oh_drawing_path) \*path, bool forceClosed, float distance, [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*position, [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*tangent) | Obtains the coordinates and tangent at a distance from the start point of a path.|
| bool [OH_Drawing_PathOp](#oh_drawing_pathop) ([OH_Drawing_Path](#oh_drawing_path) \*path, const [OH_Drawing_Path](#oh_drawing_path) \*other, [OH_Drawing_PathOpMode](#oh_drawing_pathopmode) op) | Combines two paths based on the specified operation mode.|
| bool [OH_Drawing_PathGetMatrix](#oh_drawing_pathgetmatrix) ([OH_Drawing_Path](#oh_drawing_path) \*path, bool forceClosed, float distance, [OH_Drawing_Matrix](#oh_drawing_matrix) \*matrix, [OH_Drawing_PathMeasureMatrixFlags](#oh_drawing_pathmeasurematrixflags) flag) | Obtains a transformation matrix at a distance from the start point of a path.|
| void [OH_Drawing_PathOffset](#oh_drawing_pathoffset) ([OH_Drawing_Path](#oh_drawing_path) \*path, [OH_Drawing_Path](#oh_drawing_path) \*dst, float dx, float dy) | Translates a path by an offset along the X axis and Y axis and adds the new one to the **dst** path.|
| void [OH_Drawing_PathReset](#oh_drawing_pathreset) ([OH_Drawing_Path](#oh_drawing_path) \*) | Resets path data.|
| [OH_Drawing_PathEffect](#oh_drawing_patheffect) \* [OH_Drawing_CreateDashPathEffect](#oh_drawing_createdashpatheffect) (float \*intervals, int count, float phase) | Creates an **OH_Drawing_PathEffect** object with a dashed line effect. The dashed line effect is determined by a group of "on" and "off" intervals.|
| void [OH_Drawing_PathEffectDestroy](#oh_drawing_patheffectdestroy) ([OH_Drawing_PathEffect](#oh_drawing_patheffect) \*) | Destroys an **OH_Drawing_PathEffect** object and reclaims the memory occupied by the object.|
| [OH_Drawing_Pen](#oh_drawing_pen) \* [OH_Drawing_PenCreate](#oh_drawing_pencreate) (void) | Creates an **OH_Drawing_Pen** object.|
| [OH_Drawing_Pen](#oh_drawing_pen) \* [OH_Drawing_PenCopy](#oh_drawing_pencopy) ([OH_Drawing_Pen](#oh_drawing_pen) \*pen) | Copies an existing [OH_Drawing_Pen](#oh_drawing_pen) object to create a new one.|
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
| [OH_Drawing_PenLineCapStyle](#oh_drawing_penlinecapstyle) [OH_Drawing_PenGetCap](#oh_drawing_pengetcap) (const [OH_Drawing_Pen](#oh_drawing_pen) \*) | Obtains the line cap style of a pen.|
| void [OH_Drawing_PenSetCap](#oh_drawing_pensetcap) ([OH_Drawing_Pen](#oh_drawing_pen) \*, [OH_Drawing_PenLineCapStyle](#oh_drawing_penlinecapstyle)) | Sets the line cap style for a pen.|
| [OH_Drawing_PenLineJoinStyle](#oh_drawing_penlinejoinstyle) [OH_Drawing_PenGetJoin](#oh_drawing_pengetjoin) (const [OH_Drawing_Pen](#oh_drawing_pen) \*) | Obtains the line join style of a pen.|
| void [OH_Drawing_PenSetJoin](#oh_drawing_pensetjoin) ([OH_Drawing_Pen](#oh_drawing_pen) \*, [OH_Drawing_PenLineJoinStyle](#oh_drawing_penlinejoinstyle)) | Sets the line join style for a pen.|
| void [OH_Drawing_PenSetShaderEffect](#oh_drawing_pensetshadereffect) ([OH_Drawing_Pen](#oh_drawing_pen) \*, [OH_Drawing_ShaderEffect](#oh_drawing_shadereffect) \*) | Sets the shader effect for a pen.|
| void [OH_Drawing_PenSetShadowLayer](#oh_drawing_pensetshadowlayer) ([OH_Drawing_Pen](#oh_drawing_pen) \*, [OH_Drawing_ShadowLayer](#oh_drawing_shadowlayer) \*) | Sets the shadow layer for a pen. The shadow layer effect takes effect only when text is drawn.|
| void [OH_Drawing_PenSetPathEffect](#oh_drawing_pensetpatheffect) ([OH_Drawing_Pen](#oh_drawing_pen) \*, [OH_Drawing_PathEffect](#oh_drawing_patheffect) \*) | Sets the path effect for a pen.|
| void [OH_Drawing_PenSetFilter](#oh_drawing_pensetfilter) ([OH_Drawing_Pen](#oh_drawing_pen) \*, [OH_Drawing_Filter](#oh_drawing_filter) \*) | Sets a filter for a pen.|
| void [OH_Drawing_PenGetFilter](#oh_drawing_pengetfilter) ([OH_Drawing_Pen](#oh_drawing_pen) \*, [OH_Drawing_Filter](#oh_drawing_filter) \*) | Obtains the filter of a pen. The filter is a container that holds a mask filter and color filter.|
| void [OH_Drawing_PenSetBlendMode](#oh_drawing_pensetblendmode) ([OH_Drawing_Pen](#oh_drawing_pen) \*, [OH_Drawing_BlendMode](#oh_drawing_blendmode)) | Sets a blender for a pen. The blender implements the specified blend mode.|
| bool [OH_Drawing_PenGetFillPath](#oh_drawing_pengetfillpath) ([OH_Drawing_Pen](#oh_drawing_pen) \*, const [OH_Drawing_Path](#oh_drawing_path) \*src, [OH_Drawing_Path](#oh_drawing_path) \*dst, const [OH_Drawing_Rect](#oh_drawing_rect) \*, const [OH_Drawing_Matrix](#oh_drawing_matrix) \*) | Obtains the source path outline drawn using a pen and represents it using a destination path.|
| void [OH_Drawing_PenReset](#oh_drawing_penreset) ([OH_Drawing_Pen](#oh_drawing_pen) \*) | Resets a pen to the initial state.|
| [OH_Drawing_PixelMap](#oh_drawing_pixelmap) \* [OH_Drawing_PixelMapGetFromNativePixelMap](#oh_drawing_pixelmapgetfromnativepixelmap) (NativePixelMap_ \*) | Obtains the pixel map defined by this module from a pixel map defined by the image framework.|
| [OH_Drawing_PixelMap](#oh_drawing_pixelmap) \* [OH_Drawing_PixelMapGetFromOhPixelMapNative](#oh_drawing_pixelmapgetfromohpixelmapnative) (OH_PixelmapNative \*) | Obtains the pixel map defined by this module from a pixel map defined by the image framework.|
| void [OH_Drawing_PixelMapDissolve](#oh_drawing_pixelmapdissolve) ([OH_Drawing_PixelMap](#oh_drawing_pixelmap) \*) | Removes the relationship between a pixel map defined by this module and a pixel map defined by the image framework. The relationship is established by calling [OH_Drawing_PixelMapGetFromNativePixelMap](#oh_drawing_pixelmapgetfromnativepixelmap) or [OH_Drawing_PixelMapGetFromOhPixelMapNative](#oh_drawing_pixelmapgetfromohpixelmapnative).|
| [OH_Drawing_Point](#oh_drawing_point) \* [OH_Drawing_PointCreate](#oh_drawing_pointcreate) (float x, float y) | Creates an **OH_Drawing_Point** object.|
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_PointGetX](#oh_drawing_pointgetx) (const [OH_Drawing_Point](#oh_drawing_point) \*point, float \*x) | Obtains the X coordinate of a point.|
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_PointGetY](#oh_drawing_pointgety) (const [OH_Drawing_Point](#oh_drawing_point) \*point, float \*y) | Obtains the Y coordinate of a point.|
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_PointSet](#oh_drawing_pointset) ([OH_Drawing_Point](#oh_drawing_point) \*point, float x, float y) | Sets the X and Y coordinates of a point.|
| void [OH_Drawing_PointDestroy](#oh_drawing_pointdestroy) ([OH_Drawing_Point](#oh_drawing_point) \*) | Destroys an **OH_Drawing_Point** object and reclaims the memory occupied by the object.|
| [OH_Drawing_RecordCmdUtils](#oh_drawing_recordcmdutils) \* [OH_Drawing_RecordCmdUtilsCreate](#oh_drawing_recordcmdutilscreate) (void) | Creates an **OH_Drawing_RecordCmdUtils** object.|
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_RecordCmdUtilsDestroy](#oh_drawing_recordcmdutilsdestroy) ([OH_Drawing_RecordCmdUtils](#oh_drawing_recordcmdutils) \*recordCmdUtils) | Destroys an **OH_Drawing_RecordCmdUtils** object and reclaims the memory occupied by the object.|
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_RecordCmdUtilsBeginRecording](#oh_drawing_recordcmdutilsbeginrecording) ([OH_Drawing_RecordCmdUtils](#oh_drawing_recordcmdutils) \*recordCmdUtils, int32_t width, int32_t height, [OH_Drawing_Canvas](#oh_drawing_canvas) \*\*canvas) | Starts recording. This function must be used in pair with [OH_Drawing_RecordCmdUtilsFinishRecording](#oh_drawing_recordcmdutilsfinishrecording).<br>The **OH_Drawing_RecordCmdUtils** object generates a canvas object of the recording type and calls the interface of the drawing object to record all drawing commands.|
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_RecordCmdUtilsFinishRecording](#oh_drawing_recordcmdutilsfinishrecording) ([OH_Drawing_RecordCmdUtils](#oh_drawing_recordcmdutils) \*recordCmdUtils, [OH_Drawing_RecordCmd](#oh_drawing_recordcmd) \*\*recordCmd) | Ends recording. This function must be called after [OH_Drawing_RecordCmdUtilsBeginRecording](#oh_drawing_recordcmdutilsbeginrecording).<br>The **OH_Drawing_RecordCmdUtils** object ends recording and stores the drawing commands recorded by the canvas object of the recording type into the generated [OH_Drawing_RecordCmdUtilsBeginRecording](#oh_drawing_recordcmdutilsbeginrecording) object.|
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_RecordCmdDestroy](#oh_drawing_recordcmddestroy) ([OH_Drawing_RecordCmd](#oh_drawing_recordcmd) \*recordCmd) | Destroys an **OH_Drawing_RecordCmd** object and reclaims the memory occupied by the object.|
| [OH_Drawing_Rect](#oh_drawing_rect) \* [OH_Drawing_RectCreate](#oh_drawing_rectcreate) (float left, float top, float right, float bottom) | Creates an **OH_Drawing_Rect** object, without sorting the coordinates passed in. This means that the coordinates of the upper left corner of the rectangle can be greater than those of the lower right corner.|
| float [OH_Drawing_RectGetHeight](#oh_drawing_rectgetheight) ([OH_Drawing_Rect](#oh_drawing_rect) \*) | Obtains the height of a rectangle. The height is calculated by using the Y coordinate of the lower right corner of the rectangle minus the Y coordinate of the upper left corner.|
| float [OH_Drawing_RectGetWidth](#oh_drawing_rectgetwidth) ([OH_Drawing_Rect](#oh_drawing_rect) \*) | Obtains the width of a rectangle. The width is calculated by using the X coordinate of the lower right corner of the rectangle minus the X coordinate of the upper left corner.|
| float [OH_Drawing_RectGetLeft](#oh_drawing_rectgetleft) ([OH_Drawing_Rect](#oh_drawing_rect) \*) | Obtains the X coordinate of the upper left corner of a rectangle.|
| float [OH_Drawing_RectGetTop](#oh_drawing_rectgettop) ([OH_Drawing_Rect](#oh_drawing_rect) \*) | Obtains the Y coordinate of the upper left corner of a rectangle.|
| float [OH_Drawing_RectGetRight](#oh_drawing_rectgetright) ([OH_Drawing_Rect](#oh_drawing_rect) \*) | Obtains the X coordinate of the lower right corner of a rectangle.|
| float [OH_Drawing_RectGetBottom](#oh_drawing_rectgetbottom) ([OH_Drawing_Rect](#oh_drawing_rect) \*) | Obtains the Y coordinate of the lower right corner of a rectangle.|
| bool [OH_Drawing_RectIntersect](#oh_drawing_rectintersect) ([OH_Drawing_Rect](#oh_drawing_rect) \*rect, const [OH_Drawing_Rect](#oh_drawing_rect) \*other) | Checks whether two rectangles intersect and if yes, sets **rect** to the area of intersection.|
| bool [OH_Drawing_RectJoin](#oh_drawing_rectjoin) ([OH_Drawing_Rect](#oh_drawing_rect) \*rect, const [OH_Drawing_Rect](#oh_drawing_rect) \*other) | Obtains the union of two rectangles.|
| void [OH_Drawing_RectSetLeft](#oh_drawing_rectsetleft) ([OH_Drawing_Rect](#oh_drawing_rect) \*rect, float left) | Sets the horizontal coordinate of the upper left corner of a rectangle.|
| void [OH_Drawing_RectSetTop](#oh_drawing_rectsettop) ([OH_Drawing_Rect](#oh_drawing_rect) \*rect, float top) | Sets the vertical coordinate of the upper left corner of a rectangle.|
| void [OH_Drawing_RectSetRight](#oh_drawing_rectsetright) ([OH_Drawing_Rect](#oh_drawing_rect) \*rect, float right) | Sets the horizontal coordinate of the lower right corner of a rectangle.|
| void [OH_Drawing_RectSetBottom](#oh_drawing_rectsetbottom) ([OH_Drawing_Rect](#oh_drawing_rect) \*rect, float bottom) | Sets the vertical coordinate of the lower right corner of a rectangle.|
| void [OH_Drawing_RectCopy](#oh_drawing_rectcopy) ([OH_Drawing_Rect](#oh_drawing_rect) \*sRect, [OH_Drawing_Rect](#oh_drawing_rect) \*dRect) | Copies a source rectangle to create a new one.|
| void [OH_Drawing_RectDestroy](#oh_drawing_rectdestroy) ([OH_Drawing_Rect](#oh_drawing_rect) \*) | Destroys an **OH_Drawing_Rect** object and reclaims the memory occupied by the object.|
| [OH_Drawing_Array](#oh_drawing_array) \* [OH_Drawing_RectCreateArray](#oh_drawing_rectcreatearray) (size_t size) | Creates a rectangle array object to store multiple rectangle objects.|
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_RectGetArraySize](#oh_drawing_rectgetarraysize) ([OH_Drawing_Array](#oh_drawing_array) \*rectArray, size_t \*pSize) | Obtains the size of a rectangle array, which is an [OH_Drawing_Array](#oh_drawing_array) object.|
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_RectGetArrayElement](#oh_drawing_rectgetarrayelement) ([OH_Drawing_Array](#oh_drawing_array) \*rectArray, size_t index, [OH_Drawing_Rect](#oh_drawing_rect) \*\*rect) | Obtains the rectangle with the specified index in a rectangle array.|
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_RectDestroyArray](#oh_drawing_rectdestroyarray) ([OH_Drawing_Array](#oh_drawing_array) \*rectArray) | Destroys an **OH_Drawing_Array** object and reclaims the memory occupied by the object.|
| [OH_Drawing_Region](#oh_drawing_region) \* [OH_Drawing_RegionCreate](#oh_drawing_regioncreate) (void) | Creates an **OH_Drawing_Region** object for more accurate graphical control.|
| bool [OH_Drawing_RegionContains](#oh_drawing_regioncontains) ([OH_Drawing_Region](#oh_drawing_region) \*region, int32_t x, int32_t y) | Checks whether a region contains the specified point.|
| bool [OH_Drawing_RegionOp](#oh_drawing_regionop) ([OH_Drawing_Region](#oh_drawing_region) \*region, const [OH_Drawing_Region](#oh_drawing_region) \*other, [OH_Drawing_RegionOpMode](#oh_drawing_regionopmode) op) | Combines two regions based on the specified operation mode.|
| bool [OH_Drawing_RegionSetRect](#oh_drawing_regionsetrect) ([OH_Drawing_Region](#oh_drawing_region) \*region, const [OH_Drawing_Rect](#oh_drawing_rect) \*rect) | Sets the boundary for an **OH_Drawing_Region** object.|
| bool [OH_Drawing_RegionSetPath](#oh_drawing_regionsetpath) ([OH_Drawing_Region](#oh_drawing_region) \*region, const [OH_Drawing_Path](#oh_drawing_path) \*path, const [OH_Drawing_Region](#oh_drawing_region) \*clip) | Sets a region to the area described by the path.|
| void [OH_Drawing_RegionDestroy](#oh_drawing_regiondestroy) ([OH_Drawing_Region](#oh_drawing_region) \*) | Destroys an **OH_Drawing_Region** object and reclaims the memory occupied by the object.|
| uint32_t [OH_Drawing_RegisterFont](#oh_drawing_registerfont) ([OH_Drawing_FontCollection](#oh_drawing_fontcollection) \*, const char \*fontFamily, const char \*familySrc) | Registers a custom font with the font manager. The supported font file formats are .ttf and .otf.|
| uint32_t [OH_Drawing_RegisterFontBuffer](#oh_drawing_registerfontbuffer) ([OH_Drawing_FontCollection](#oh_drawing_fontcollection) \*, const char \*fontFamily, uint8_t \*fontBuffer, size_t length) | Registers a font buffer with the font manager.|
| [OH_Drawing_RoundRect](#oh_drawing_roundrect) \* [OH_Drawing_RoundRectCreate](#oh_drawing_roundrectcreate) (const [OH_Drawing_Rect](#oh_drawing_rect) \*, float xRad, float yRad) | Creates an **OH_Drawing_RoundRect** object.|
| void [OH_Drawing_RoundRectSetCorner](#oh_drawing_roundrectsetcorner) ([OH_Drawing_RoundRect](#oh_drawing_roundrect) \*, [OH_Drawing_CornerPos](#oh_drawing_cornerpos) pos, [OH_Drawing_Corner_Radii](#oh_drawing_corner_radii)) | Sets the radii of the specified rounded corner in a rounded rectangle.|
| [OH_Drawing_Corner_Radii](#oh_drawing_corner_radii) [OH_Drawing_RoundRectGetCorner](#oh_drawing_roundrectgetcorner) ([OH_Drawing_RoundRect](#oh_drawing_roundrect) \*, [OH_Drawing_CornerPos](#oh_drawing_cornerpos) pos) | Obtains the radii of the specified rounded corner in a rounded rectangle.|
| void [OH_Drawing_RoundRectDestroy](#oh_drawing_roundrectdestroy) ([OH_Drawing_RoundRect](#oh_drawing_roundrect) \*) | Destroys an **OH_Drawing_RoundRect** object and reclaims the memory occupied by the object.|
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_RoundRectOffset](#oh_drawing_roundrectoffset) ([OH_Drawing_RoundRect](#oh_drawing_roundrect) \*roundRect, float dx, float dy) | Translates a rounded rectangle by an offset along the X axis and Y axis.|
| [OH_Drawing_SamplingOptions](#oh_drawing_samplingoptions) \* [OH_Drawing_SamplingOptionsCreate](#oh_drawing_samplingoptionscreate) ([OH_Drawing_FilterMode](#oh_drawing_filtermode), [OH_Drawing_MipmapMode](#oh_drawing_mipmapmode)) | Creates an **OH_Drawing_SamplingOptions** object.|
| void [OH_Drawing_SamplingOptionsDestroy](#oh_drawing_samplingoptionsdestroy) ([OH_Drawing_SamplingOptions](#oh_drawing_samplingoptions) \*) | Destroys an **OH_Drawing_SamplingOptions** object and reclaims the memory occupied by the object.|
| [OH_Drawing_ShaderEffect](#oh_drawing_shadereffect) \* [OH_Drawing_ShaderEffectCreateColorShader](#oh_drawing_shadereffectcreatecolorshader) (const uint32_t color) | Creates an **OH_Drawing_ShaderEffect** object with a single color.|
| [OH_Drawing_ShaderEffect](#oh_drawing_shadereffect) \* [OH_Drawing_ShaderEffectCreateLinearGradient](#oh_drawing_shadereffectcreatelineargradient) (const [OH_Drawing_Point](#oh_drawing_point) \*startPt, const [OH_Drawing_Point](#oh_drawing_point) \*endPt, const uint32_t \*colors, const float \*pos, uint32_t size, [OH_Drawing_TileMode](#oh_drawing_tilemode)) | Creates an **OH_Drawing_ShaderEffect** object that generates a linear gradient between two points.|
| [OH_Drawing_ShaderEffect](#oh_drawing_shadereffect) \* [OH_Drawing_ShaderEffectCreateLinearGradientWithLocalMatrix](#oh_drawing_shadereffectcreatelineargradientwithlocalmatrix) (const [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*startPt, const [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*endPt, const uint32_t \*colors, const float \*pos, uint32_t size, [OH_Drawing_TileMode](#oh_drawing_tilemode), const [OH_Drawing_Matrix](#oh_drawing_matrix) \*) | Creates an **OH_Drawing_ShaderEffect** object that generates a linear gradient between two points.|
| [OH_Drawing_ShaderEffect](#oh_drawing_shadereffect) \* [OH_Drawing_ShaderEffectCreateRadialGradient](#oh_drawing_shadereffectcreateradialgradient) (const [OH_Drawing_Point](#oh_drawing_point) \*centerPt, float radius, const uint32_t \*colors, const float \*pos, uint32_t size, [OH_Drawing_TileMode](#oh_drawing_tilemode)) | Creates an **OH_Drawing_ShaderEffect** object that generates a radial gradient based on the center and radius of a circle. The radial gradient transitions colors from the center to the ending shape in a radial manner.|
| [OH_Drawing_ShaderEffect](#oh_drawing_shadereffect) \* [OH_Drawing_ShaderEffectCreateRadialGradientWithLocalMatrix](#oh_drawing_shadereffectcreateradialgradientwithlocalmatrix) (const [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*centerPt, float radius, const uint32_t \*colors, const float \*pos, uint32_t size, [OH_Drawing_TileMode](#oh_drawing_tilemode), const [OH_Drawing_Matrix](#oh_drawing_matrix) \*) | Creates an **OH_Drawing_ShaderEffect** object that generates a radial gradient based on the center and radius of a circle. The radial gradient transitions colors from the center to the ending shape in a radial manner.|
| [OH_Drawing_ShaderEffect](#oh_drawing_shadereffect) \* [OH_Drawing_ShaderEffectCreateSweepGradient](#oh_drawing_shadereffectcreatesweepgradient) (const [OH_Drawing_Point](#oh_drawing_point) \*centerPt, const uint32_t \*colors, const float \*pos, uint32_t size, [OH_Drawing_TileMode](#oh_drawing_tilemode)) | Creates an **OH_Drawing_ShaderEffect** object that generates a sweep gradient based on the center. A sweep gradient paints a gradient in a sweeping arc ranging from 0° to 360°.|
| [OH_Drawing_ShaderEffect](#oh_drawing_shadereffect) \* [OH_Drawing_ShaderEffectCreateImageShader](#oh_drawing_shadereffectcreateimageshader) ([OH_Drawing_Image](#oh_drawing_image) \*, [OH_Drawing_TileMode](#oh_drawing_tilemode) tileX, [OH_Drawing_TileMode](#oh_drawing_tilemode) tileY, const [OH_Drawing_SamplingOptions](#oh_drawing_samplingoptions) \*, const [OH_Drawing_Matrix](#oh_drawing_matrix) \*) | Creates an **OH_Drawing_ShaderEffect** object for an image shader. You are advised not to use the API for the canvas of the capture type because it affects the performance.|
| [OH_Drawing_ShaderEffect](#oh_drawing_shadereffect) \* [OH_Drawing_ShaderEffectCreateTwoPointConicalGradient](#oh_drawing_shadereffectcreatetwopointconicalgradient) (const [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*startPt, float startRadius, const [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*endPt, float endRadius, const uint32_t \*colors, const float \*pos, uint32_t size, [OH_Drawing_TileMode](#oh_drawing_tilemode), const [OH_Drawing_Matrix](#oh_drawing_matrix) \*) | Creates an **OH_Drawing_ShaderEffect** object that generates a gradient between two given circles.|
| void [OH_Drawing_ShaderEffectDestroy](#oh_drawing_shadereffectdestroy) ([OH_Drawing_ShaderEffect](#oh_drawing_shadereffect) \*) | Destroys an **OH_Drawing_ShaderEffect** object and reclaims the memory occupied by the object.|
| [OH_Drawing_ShadowLayer](#oh_drawing_shadowlayer) \* [OH_Drawing_ShadowLayerCreate](#oh_drawing_shadowlayercreate) (float blurRadius, float x, float y, uint32_t color) | Creates an **OH_Drawing_ShadowLayer** object.|
| void [OH_Drawing_ShadowLayerDestroy](#oh_drawing_shadowlayerdestroy) ([OH_Drawing_ShadowLayer](#oh_drawing_shadowlayer) \*) | Destroys an **OH_Drawing_ShadowLayer** object and reclaims the memory occupied by the object.|
| [OH_Drawing_Surface](#oh_drawing_surface) \* [OH_Drawing_SurfaceCreateFromGpuContext](#oh_drawing_surfacecreatefromgpucontext) ([OH_Drawing_GpuContext](#oh_drawing_gpucontext) \*, bool budgeted, [OH_Drawing_Image_Info](_o_h___drawing___image___info.md)) | Creates an **OH_Drawing_Surface** object using the GPU context to manage the content drawn on the canvas.|
| [OH_Drawing_Canvas](#oh_drawing_canvas) \* [OH_Drawing_SurfaceGetCanvas](#oh_drawing_surfacegetcanvas) ([OH_Drawing_Surface](#oh_drawing_surface) \*) | Obtains a canvas from an **OH_Drawing_Surface** object.|
| void [OH_Drawing_SurfaceDestroy](#oh_drawing_surfacedestroy) ([OH_Drawing_Surface](#oh_drawing_surface) \*) | Destroys an **OH_Drawing_Surface** object and reclaims the memory occupied.|
| [OH_Drawing_TextBlobBuilder](#oh_drawing_textblobbuilder) \* [OH_Drawing_TextBlobBuilderCreate](#oh_drawing_textblobbuildercreate) (void) | Creates an **OH_Drawing_TextBlobBuilder** object.|
| [OH_Drawing_TextBlob](#oh_drawing_textblob) \* [OH_Drawing_TextBlobCreateFromText](#oh_drawing_textblobcreatefromtext) (const void \*text, size_t byteLength, const [OH_Drawing_Font](#oh_drawing_font) \*, [OH_Drawing_TextEncoding](#oh_drawing_textencoding)) | Creates an **OH_Drawing_TextBlob** object from the text.|
| [OH_Drawing_TextBlob](#oh_drawing_textblob) \* [OH_Drawing_TextBlobCreateFromPosText](#oh_drawing_textblobcreatefrompostext) (const void \*text, size_t byteLength, [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*, const [OH_Drawing_Font](#oh_drawing_font) \*, [OH_Drawing_TextEncoding](#oh_drawing_textencoding)) | Creates an **OH_Drawing_TextBlob** object from the text. The coordinates of each character in the **OH_Drawing_TextBlob** object are determined by the coordinate information in the **OH_Drawing_Point2D** array.|
| [OH_Drawing_TextBlob](#oh_drawing_textblob) \* [OH_Drawing_TextBlobCreateFromString](#oh_drawing_textblobcreatefromstring) (const char \*str, const [OH_Drawing_Font](#oh_drawing_font) \*, [OH_Drawing_TextEncoding](#oh_drawing_textencoding)) | Creates an **OH_Drawing_TextBlob** object from a string.|
| void [OH_Drawing_TextBlobGetBounds](#oh_drawing_textblobgetbounds) ([OH_Drawing_TextBlob](#oh_drawing_textblob) \*, [OH_Drawing_Rect](#oh_drawing_rect) \*) | Obtains the bounds of an **OH_Drawing_TextBlob** object.|
| uint32_t [OH_Drawing_TextBlobUniqueID](#oh_drawing_textblobuniqueid) (const [OH_Drawing_TextBlob](#oh_drawing_textblob) \*) | Obtains the unique identifier of a text blob. The identifier is a non-zero value.|
| const [OH_Drawing_RunBuffer](_o_h___drawing___run_buffer.md) \* [OH_Drawing_TextBlobBuilderAllocRunPos](#oh_drawing_textblobbuilderallocrunpos) ([OH_Drawing_TextBlobBuilder](#oh_drawing_textblobbuilder) \*, const [OH_Drawing_Font](#oh_drawing_font) \*, int32_t count, const [OH_Drawing_Rect](#oh_drawing_rect) \*) | Allocates a run to store glyphs and positions. The pointer returned does not need to be managed by the caller. It can no longer be used after [OH_Drawing_TextBlobBuilderMake](#oh_drawing_textblobbuildermake) is called.|
| [OH_Drawing_TextBlob](#oh_drawing_textblob) \* [OH_Drawing_TextBlobBuilderMake](#oh_drawing_textblobbuildermake) ([OH_Drawing_TextBlobBuilder](#oh_drawing_textblobbuilder) \*) | Makes an **OH_Drawing_TextBlob** object from an **OH_Drawing_TextBlobBuilder**.|
| void [OH_Drawing_TextBlobDestroy](#oh_drawing_textblobdestroy) ([OH_Drawing_TextBlob](#oh_drawing_textblob) \*) | Destroys an **OH_Drawing_TextBlob** object and reclaims the memory occupied by the object.|
| void [OH_Drawing_TextBlobBuilderDestroy](#oh_drawing_textblobbuilderdestroy) ([OH_Drawing_TextBlobBuilder](#oh_drawing_textblobbuilder) \*) | Destroys an **OH_Drawing_TextBlobBuilder** object and reclaims the memory occupied by the object.|
| [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) \* [OH_Drawing_MatchFontDescriptors](#oh_drawing_matchfontdescriptors) ([OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) \*, size_t \*) | Obtains all system font descriptors that match a font descriptor. In the [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) struct, the **path** field is not used for matching, and other fields are valid only when they are not set to their default values. If all fields in [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) are set to their default values, all system font descriptors are obtained. If no matching is found, NULL is returned.|
| void [OH_Drawing_DestroyFontDescriptors](#oh_drawing_destroyfontdescriptors) ([OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) \*, size_t) | Releases an array of [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) objects.|
| [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) \* [OH_Drawing_GetFontDescriptorByFullName](#oh_drawing_getfontdescriptorbyfullname) (const [OH_Drawing_String](_o_h___drawing___string.md) \*, [OH_Drawing_SystemFontType](#oh_drawing_systemfonttype)) | Obtains a font descriptor based on the font name and type. System fonts, style fonts, and user-installed fonts are supported. A font descriptor is a data structure that describes font features. It contains details of the font appearance and properties.|
| [OH_Drawing_Array](#oh_drawing_array) \* [OH_Drawing_GetSystemFontFullNamesByType](#oh_drawing_getsystemfontfullnamesbytype) ([OH_Drawing_SystemFontType](#oh_drawing_systemfonttype)) | Obtains an array of font names by font type.|
| const [OH_Drawing_String](_o_h___drawing___string.md) \* [OH_Drawing_GetSystemFontFullNameByIndex](#oh_drawing_getsystemfontfullnamebyindex) ([OH_Drawing_Array](#oh_drawing_array) \*, size_t) | Obtains the font name with the specified index in the font name array.|
| void [OH_Drawing_DestroySystemFontFullNames](#oh_drawing_destroysystemfontfullnames) ([OH_Drawing_Array](#oh_drawing_array) \*) | Releases the memory occupied by the font name array obtained by font type.|
| [OH_Drawing_Array](#oh_drawing_array) \* [OH_Drawing_TypographyGetTextLines](#oh_drawing_typographygettextlines) ([OH_Drawing_Typography](#oh_drawing_typography) \*typography) | Obtains the array of text lines in a typography object. This array contains one or more text line objects.|
| void [OH_Drawing_DestroyTextLines](#oh_drawing_destroytextlines) ([OH_Drawing_Array](#oh_drawing_array) \*lines) | Releases the memory occupied by a text line array.|
| void [OH_Drawing_DestroyTextLine](#oh_drawing_destroytextline) (OH_Drawing_TextLine \*line) | Releases the memory occupied by a text line object. This is applicable only to text line objects that have requested memory on their own and not to a particular text line object within a text line array.|
| OH_Drawing_TextLine \* [OH_Drawing_GetTextLineByIndex](#oh_drawing_gettextlinebyindex) ([OH_Drawing_Array](#oh_drawing_array) \*lines, size_t index) | Obtains the text line object with the specified index in a text line array.|
| double [OH_Drawing_TextLineGetGlyphCount](#oh_drawing_textlinegetglyphcount) (OH_Drawing_TextLine \*line) | Obtains the number of glyphs in a text line object.|
| void [OH_Drawing_TextLineGetTextRange](#oh_drawing_textlinegettextrange) (OH_Drawing_TextLine \*line, size_t \*start, size_t \*end) | Obtains the range of the text in a text line object in the entire paragraph.|
| [OH_Drawing_Array](#oh_drawing_array) \* [OH_Drawing_TextLineGetGlyphRuns](#oh_drawing_textlinegetglyphruns) (OH_Drawing_TextLine \*line) | Obtains the array of glyph runs in a text line object.|
| void [OH_Drawing_DestroyRuns](#oh_drawing_destroyruns) ([OH_Drawing_Array](#oh_drawing_array) \*runs) | Releases the memory occupied by a glyph run array.|
| OH_Drawing_Run \* [OH_Drawing_GetRunByIndex](#oh_drawing_getrunbyindex) ([OH_Drawing_Array](#oh_drawing_array) \*runs, size_t index) | Obtains the glyph run object with the specified index in a glyph run array.|
| void [OH_Drawing_TextLinePaint](#oh_drawing_textlinepaint) (OH_Drawing_TextLine \*line, [OH_Drawing_Canvas](#oh_drawing_canvas) \*canvas, double x, double y) | Paints a text line on the canvas with the coordinate point (x, y) as the upper left corner.|
| OH_Drawing_TextLine \* [OH_Drawing_TextLineCreateTruncatedLine](#oh_drawing_textlinecreatetruncatedline) (OH_Drawing_TextLine \*line, double width, int mode, const char \*ellipsis) | Creates a truncated text line object.|
| double [OH_Drawing_TextLineGetTypographicBounds](#oh_drawing_textlinegettypographicbounds) (OH_Drawing_TextLine \*line, double \*ascent, double \*descent, double \*leading) | Obtains the typographic boundary of a text line object. The typographic boundary is related to the font and font size used for typography, but not the characters within the text. For example, for the string " a b " (which has a space before "a" and a space after "b"), the typographic boundary encompasses the spaces at the beginning and end. For the strings "j" and "E", the typographic boundaries are the same, indicating that they are irrelevant to specific characters.|
| [OH_Drawing_Rect](#oh_drawing_rect) \* [OH_Drawing_TextLineGetImageBounds](#oh_drawing_textlinegetimagebounds) (OH_Drawing_TextLine \*line) | Obtains the image boundary of a text line object. The image boundary, equivalent to a visual boundary, is related to the font, font size, and characters. For example, for the string " a b " (which has a space before "a" and a space after "b"), only "a b" are visible to users, and therefore the image boundary does not include these spaces at the beginning and end. For the strings "j" and "E", their image boundaries are different. Specifically, the width of the boundary for "j" is narrower than that for "E", and the height of the boundary for "j" is taller than that for "E".|
| double [OH_Drawing_TextLineGetTrailingSpaceWidth](#oh_drawing_textlinegettrailingspacewidth) (OH_Drawing_TextLine \*line) | Obtains the width of the spaces at the end of a text line object.|
| int32_t [OH_Drawing_TextLineGetStringIndexForPosition](#oh_drawing_textlinegetstringindexforposition) (OH_Drawing_TextLine \*line, [OH_Drawing_Point](#oh_drawing_point) \*point) | Obtains the index of a string at a specified position in a text line object.|
| double [OH_Drawing_TextLineGetOffsetForStringIndex](#oh_drawing_textlinegetoffsetforstringindex) (OH_Drawing_TextLine \*line, int32_t index) | Obtains the offset of a string with the specified index in a text line object.|
| void [OH_Drawing_TextLineEnumerateCaretOffsets](#oh_drawing_textlineenumeratecaretoffsets) (OH_Drawing_TextLine \*line, [Drawing_CaretOffsetsCallback](#drawing_caretoffsetscallback) callback) | Enumerates the offset and index of each character in a text line object and passes them to a custom callback function. You can use the offset and index array for other operations.|
| double [OH_Drawing_TextLineGetAlignmentOffset](#oh_drawing_textlinegetalignmentoffset) (OH_Drawing_TextLine \*line, double alignmentFactor, double alignmentWidth) | Obtains the offset of a text line object after alignment based on the alignment factor and alignment width.|
| [OH_Drawing_Array](#oh_drawing_array) \* [OH_Drawing_GetRunStringIndices](#oh_drawing_getrunstringindices) (OH_Drawing_Run \*run, int64_t start, int64_t length) | Obtains character indices of glyphs within a specified range of a run, where the indices are offsets relative to the entire paragraph.|
| uint64_t [OH_Drawing_GetRunStringIndicesByIndex](#oh_drawing_getrunstringindicesbyindex) ([OH_Drawing_Array](#oh_drawing_array) \*stringIndices, size_t index) | Obtains character indices of glyphs in a run by index.|
| void [OH_Drawing_DestroyRunStringIndices](#oh_drawing_destroyrunstringindices) ([OH_Drawing_Array](#oh_drawing_array) \*stringIndices) | Releases the pointer to a character index array.|
| void [OH_Drawing_GetRunStringRange](#oh_drawing_getrunstringrange) (OH_Drawing_Run \*run, uint64_t \*location, uint64_t \*length) | Obtains the range of glyphs generated by a run.|
| float [OH_Drawing_GetRunTypographicBounds](#oh_drawing_getruntypographicbounds) (OH_Drawing_Run \*run, float \*ascent, float \*descent, float \*leading) | Obtains the typographic boundary of a run. The typographic boundary is related to the font and font size used for typography, but not the characters within the text.|
| void [OH_Drawing_RunPaint](#oh_drawing_runpaint) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*canvas, OH_Drawing_Run \*run, double x, double y) | Paints the text contained in a run on the canvas.|
| [OH_Drawing_Rect](#oh_drawing_rect) \* [OH_Drawing_GetRunImageBounds](#oh_drawing_getrunimagebounds) (OH_Drawing_Run \*run) | Obtains the image boundary of a run. The image boundary is related to characters and is equivalent to the visual boundary.|
| void [OH_Drawing_DestroyRunImageBounds](#oh_drawing_destroyrunimagebounds) ([OH_Drawing_Rect](#oh_drawing_rect) \*rect) | Releases the pointer to an image boundary object of a run.|
| [OH_Drawing_Array](#oh_drawing_array) \* [OH_Drawing_GetRunGlyphs](#oh_drawing_getrunglyphs) (OH_Drawing_Run \*run, int64_t start, int64_t length) | Obtains an array of glyphs within the specified range of a run.|
| uint16_t [OH_Drawing_GetRunGlyphsByIndex](#oh_drawing_getrunglyphsbyindex) ([OH_Drawing_Array](#oh_drawing_array) \*glyphs, size_t index) | Obtains individual glyphs in a run by index.|
| void [OH_Drawing_DestroyRunGlyphs](#oh_drawing_destroyrunglyphs) ([OH_Drawing_Array](#oh_drawing_array) \*glyphs) | Releases the pointer to a glyph array in a run.|
| [OH_Drawing_Array](#oh_drawing_array) \* [OH_Drawing_GetRunPositions](#oh_drawing_getrunpositions) (OH_Drawing_Run \*run, int64_t start, int64_t length) | Obtains the positions of glyphs within the specified range of a run.|
| [OH_Drawing_Point](#oh_drawing_point) \* [OH_Drawing_GetRunPositionsByIndex](#oh_drawing_getrunpositionsbyindex) ([OH_Drawing_Array](#oh_drawing_array) \*positions, size_t index) | Obtains the positions of individual glyphs in a run by index.|
| void [OH_Drawing_DestroyRunPositions](#oh_drawing_destroyrunpositions) ([OH_Drawing_Array](#oh_drawing_array) \*positions) | Releases the pointer to a glyph position array in a run.|
| uint32_t [OH_Drawing_GetRunGlyphCount](#oh_drawing_getrunglyphcount) (OH_Drawing_Run \*run) | Obtains the number of glyphs in a run.|
| [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \* [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle) (void) | Creates an **OH_Drawing_TypographyStyle** object.|
| void [OH_Drawing_DestroyTypographyStyle](#oh_drawing_destroytypographystyle) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*) | Destroys an **OH_Drawing_TypographyStyle** object and reclaims the memory occupied by the object.|
| void [OH_Drawing_SetTypographyTextDirection](#oh_drawing_settypographytextdirection) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, int) | Sets the text direction.|
| void [OH_Drawing_SetTypographyTextAlign](#oh_drawing_settypographytextalign) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, int) | Sets the text alignment mode.|
| int [OH_Drawing_TypographyGetEffectiveAlignment](#oh_drawing_typographygeteffectivealignment) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*style) | Obtains the text alignment mode.|
| void [OH_Drawing_SetTypographyTextMaxLines](#oh_drawing_settypographytextmaxlines) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, int) | Sets the maximum number of lines in the text.|
| [OH_Drawing_TextStyle](#oh_drawing_textstyle) \* [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle) (void) | Creates an **OH_Drawing_TextStyle** object.|
| [OH_Drawing_TextStyle](#oh_drawing_textstyle) \* [OH_Drawing_TypographyGetTextStyle](#oh_drawing_typographygettextstyle) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*style) | Obtains the text style of a typography style.|
| void [OH_Drawing_DestroyTextStyle](#oh_drawing_destroytextstyle) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*) | Destroys an **OH_Drawing_TextStyle** object and reclaims the memory occupied by the object.|
| void [OH_Drawing_SetTextStyleColor](#oh_drawing_settextstylecolor) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, uint32_t) | Sets the color for a text style.|
| void [OH_Drawing_SetTextStyleFontSize](#oh_drawing_settextstylefontsize) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, double) | Sets the font size for a text style.|
| void [OH_Drawing_SetTextStyleFontWeight](#oh_drawing_settextstylefontweight) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, int) | Sets the font weight for a text style. Currently, only the default system font supports font weight adjustment. For other fonts, if the weight is less than semi-bold, there is no variation in stroke thickness. If the weight is greater than or equal to semi-bold, it might result in a fake bold effect.|
| void [OH_Drawing_SetTextStyleBaseLine](#oh_drawing_settextstylebaseline) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, int) | Sets the baseline for a text style.|
| void [OH_Drawing_SetTextStyleDecoration](#oh_drawing_settextstyledecoration) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, int) | Sets the decoration for a text style.|
| void [OH_Drawing_AddTextStyleDecoration](#oh_drawing_addtextstyledecoration) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, int) | Adds the decoration for a text style. Multiple decoration lines can be displayed.|
| void [OH_Drawing_RemoveTextStyleDecoration](#oh_drawing_removetextstyledecoration) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, int) | Removes the decoration for a text style.|
| void [OH_Drawing_SetTextStyleDecorationColor](#oh_drawing_settextstyledecorationcolor) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, uint32_t) | Sets the decoration color for a text style.|
| void [OH_Drawing_SetTextStyleFontHeight](#oh_drawing_settextstylefontheight) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, double) | Sets the line height based on the multiple of the font size.|
| void [OH_Drawing_SetTextStyleFontFamilies](#oh_drawing_settextstylefontfamilies) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, int, const char \*fontFamilies[]) | Sets the font families for a text style.|
| void [OH_Drawing_SetTextStyleFontStyle](#oh_drawing_settextstylefontstyle) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, int) | Sets the font style for a text style.|
| void [OH_Drawing_SetTextStyleLocale](#oh_drawing_settextstylelocale) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, const char \*) | Sets the locale for a text style.|
| void [OH_Drawing_SetTextStyleForegroundBrush](#oh_drawing_settextstyleforegroundbrush) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, [OH_Drawing_Brush](#oh_drawing_brush) \*) | Sets the foreground brush for a text style.|
| void [OH_Drawing_TextStyleGetForegroundBrush](#oh_drawing_textstylegetforegroundbrush) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, [OH_Drawing_Brush](#oh_drawing_brush) \*) | Obtains the foreground brush of a text style.|
| void [OH_Drawing_SetTextStyleForegroundPen](#oh_drawing_settextstyleforegroundpen) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, [OH_Drawing_Pen](#oh_drawing_pen) \*) | Sets the foreground pen for a text style.|
| void [OH_Drawing_TextStyleGetForegroundPen](#oh_drawing_textstylegetforegroundpen) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, [OH_Drawing_Pen](#oh_drawing_pen) \*) | Obtains the foreground pen of a text style.|
| void [OH_Drawing_SetTextStyleBackgroundBrush](#oh_drawing_settextstylebackgroundbrush) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, [OH_Drawing_Brush](#oh_drawing_brush) \*) | Sets the background brush for a text style.|
| void [OH_Drawing_TextStyleGetBackgroundBrush](#oh_drawing_textstylegetbackgroundbrush) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, [OH_Drawing_Brush](#oh_drawing_brush) \*) | Obtains the background brush of a text style.|
| void [OH_Drawing_SetTextStyleBackgroundPen](#oh_drawing_settextstylebackgroundpen) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, [OH_Drawing_Pen](#oh_drawing_pen) \*) | Sets the background pen for a text style.|
| void [OH_Drawing_TextStyleGetBackgroundPen](#oh_drawing_textstylegetbackgroundpen) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, [OH_Drawing_Pen](#oh_drawing_pen) \*) | Obtains the background pen of a text style.|
| [OH_Drawing_TypographyCreate](#oh_drawing_typographycreate) \* [OH_Drawing_CreateTypographyHandler](#oh_drawing_createtypographyhandler) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, [OH_Drawing_FontCollection](#oh_drawing_fontcollection) \*) | Creates an **OH_Drawing_TypographyCreate** object.|
| void [OH_Drawing_DestroyTypographyHandler](#oh_drawing_destroytypographyhandler) ([OH_Drawing_TypographyCreate](#oh_drawing_typographycreate) \*) | Destroys an **OH_Drawing_TypographyCreate** object and reclaims the memory occupied by the object.|
| void [OH_Drawing_TypographyHandlerPushTextStyle](#oh_drawing_typographyhandlerpushtextstyle) ([OH_Drawing_TypographyCreate](#oh_drawing_typographycreate) \*, [OH_Drawing_TextStyle](#oh_drawing_textstyle) \*) | Pushes the text style.|
| void [OH_Drawing_TypographyHandlerAddText](#oh_drawing_typographyhandleraddtext) ([OH_Drawing_TypographyCreate](#oh_drawing_typographycreate) \*, const char \*) | Adds text.|
| void [OH_Drawing_TypographyHandlerPopTextStyle](#oh_drawing_typographyhandlerpoptextstyle) ([OH_Drawing_TypographyCreate](#oh_drawing_typographycreate) \*) | Removes the topmost text style in the stack, leaving the remaining styles in effect.|
| [OH_Drawing_Typography](#oh_drawing_typography) \* [OH_Drawing_CreateTypography](#oh_drawing_createtypography) ([OH_Drawing_TypographyCreate](#oh_drawing_typographycreate) \*) | Creates an **OH_Drawing_Typography** object.|
| void [OH_Drawing_DestroyTypography](#oh_drawing_destroytypography) ([OH_Drawing_Typography](#oh_drawing_typography) \*) | Destroys an **OH_Drawing_Typography** object and reclaims the memory occupied by the object.|
| void [OH_Drawing_TypographyLayout](#oh_drawing_typographylayout) ([OH_Drawing_Typography](#oh_drawing_typography) \*, double) | Lays out the typography.|
| void [OH_Drawing_TypographyPaint](#oh_drawing_typographypaint) ([OH_Drawing_Typography](#oh_drawing_typography) \*, [OH_Drawing_Canvas](#oh_drawing_canvas) \*, double, double) | Paints text on the canvas.|
| void [OH_Drawing_TypographyPaintOnPath](#oh_drawing_typographypaintonpath) ([OH_Drawing_Typography](#oh_drawing_typography) \*, [OH_Drawing_Canvas](#oh_drawing_canvas) \*, [OH_Drawing_Path](#oh_drawing_path) \*, double, double) | Draws text along a path.|
| double [OH_Drawing_TypographyGetMaxWidth](#oh_drawing_typographygetmaxwidth) ([OH_Drawing_Typography](#oh_drawing_typography) \*) | Obtains the maximum width.|
| double [OH_Drawing_TypographyGetHeight](#oh_drawing_typographygetheight) ([OH_Drawing_Typography](#oh_drawing_typography) \*) | Obtains the height.|
| double [OH_Drawing_TypographyGetLongestLine](#oh_drawing_typographygetlongestline) ([OH_Drawing_Typography](#oh_drawing_typography) \*) | Obtains the width of the longest line. You are advised to round up the return value in actual use. When the text content is empty, the minimum float value, that is, -340282346638528859811704183484516925440.000000, is returned.|
| double [OH_Drawing_TypographyGetLongestLineWithIndent](#oh_drawing_typographygetlongestlinewithindent) ([OH_Drawing_Typography](#oh_drawing_typography) \*) | Obtains the width of the longest line, including its indentation. You are advised to round up the return value in actual use. If the text content is empty, **0.0** is returned.|
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
| void [OH_Drawing_SetTextStyleDecorationStyle](#oh_drawing_settextstyledecorationstyle) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, int) | Sets the decoration style for a text style.|
| void [OH_Drawing_SetTextStyleDecorationThicknessScale](#oh_drawing_settextstyledecorationthicknessscale) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, double) | Sets the thickness scale factor for the decoration style of a text style.|
| void [OH_Drawing_SetTextStyleLetterSpacing](#oh_drawing_settextstyleletterspacing) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, double) | Sets the letter spacing for a text style.|
| void [OH_Drawing_SetTextStyleWordSpacing](#oh_drawing_settextstylewordspacing) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, double) | Sets the word spacing for a text style.|
| void [OH_Drawing_SetTextStyleHalfLeading](#oh_drawing_settextstylehalfleading) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, bool) | Sets whether to enable half leading for a text style.|
| void [OH_Drawing_SetTextStyleEllipsis](#oh_drawing_settextstyleellipsis) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, const char \*) | Sets the ellipsis content for a text style.|
| void [OH_Drawing_SetTextStyleEllipsisModal](#oh_drawing_settextstyleellipsismodal) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, int) | Sets the ellipsis style for a text style.|
| void [OH_Drawing_SetTypographyTextBreakStrategy](#oh_drawing_settypographytextbreakstrategy) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, int) | Sets the text break strategy.|
| void [OH_Drawing_SetTypographyTextWordBreakType](#oh_drawing_settypographytextwordbreaktype) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, int) | Sets the word break type.|
| void [OH_Drawing_SetTypographyTextEllipsisModal](#oh_drawing_settypographytextellipsismodal) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, int) | Sets the text ellipsis style.|
| void [OH_Drawing_SetTypographyTextEllipsis](#oh_drawing_settypographytextellipsis) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*style, const char \*ellipsis) | Sets the text ellipsis content.|
| double [OH_Drawing_TypographyGetLineHeight](#oh_drawing_typographygetlineheight) ([OH_Drawing_Typography](#oh_drawing_typography) \*, int) | Obtains the line height.|
| double [OH_Drawing_TypographyGetLineWidth](#oh_drawing_typographygetlinewidth) ([OH_Drawing_Typography](#oh_drawing_typography) \*, int) | Obtains the line width.|
| void [OH_Drawing_SetTypographyTextSplitRatio](#oh_drawing_settypographytextsplitratio) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*style, float textSplitRatio) | Sets the text split ratio.|
| bool [OH_Drawing_TypographyIsLineUnlimited](#oh_drawing_typographyislineunlimited) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*style) | Checks whether the maximum number of lines is limited for text.|
| bool [OH_Drawing_TypographyIsEllipsized](#oh_drawing_typographyisellipsized) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*style) | Checks whether the text has an ellipsis.|
| void [OH_Drawing_SetTypographyTextLocale](#oh_drawing_settypographytextlocale) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*style, const char \*locale) | Sets the locale for text.|
| bool [OH_Drawing_TextStyleGetFontMetrics](#oh_drawing_textstylegetfontmetrics) ([OH_Drawing_Typography](#oh_drawing_typography) \*, [OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, [OH_Drawing_Font_Metrics](_o_h___drawing___font___metrics.md) \*) | Obtains the font metrics of a text style.|
| void [OH_Drawing_SetTypographyTextStyle](#oh_drawing_settypographytextstyle) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, [OH_Drawing_TextStyle](#oh_drawing_textstyle) \*) | Sets a text style.|
| [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) \* [OH_Drawing_CreateFontDescriptor](#oh_drawing_createfontdescriptor) (void) | Creates an **OH_Drawing_FontDescriptor** object to describe the detailed information about a system font.|
| void [OH_Drawing_DestroyFontDescriptor](#oh_drawing_destroyfontdescriptor) ([OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) \*) | Destroys an **OH_Drawing_FontDescriptor** object and reclaims the memory occupied by the object.|
| [OH_Drawing_FontParser](#oh_drawing_fontparser) \* [OH_Drawing_CreateFontParser](#oh_drawing_createfontparser) (void) | Creates an **OH_Drawing_FontParser** object to parse a system font.|
| void [OH_Drawing_DestroyFontParser](#oh_drawing_destroyfontparser) ([OH_Drawing_FontParser](#oh_drawing_fontparser) \*) | Destroys an **OH_Drawing_FontParser** object and reclaims the memory occupied by the object.|
| char \*\* [OH_Drawing_FontParserGetSystemFontList](#oh_drawing_fontparsergetsystemfontlist) ([OH_Drawing_FontParser](#oh_drawing_fontparser) \*, size_t \*) | Obtains the list of system fonts. This function can be used only on 2-in-1 devices.|
| void [OH_Drawing_DestroySystemFontList](#oh_drawing_destroysystemfontlist) (char \*\*, size_t) | Reclaims the memory occupied by the system font list.|
| [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) \* [OH_Drawing_FontParserGetFontByName](#oh_drawing_fontparsergetfontbyname) ([OH_Drawing_FontParser](#oh_drawing_fontparser) \*, const char \*) | Obtains the descriptor of a system font based on the font name.|
| [OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md) \* [OH_Drawing_TypographyGetLineMetrics](#oh_drawing_typographygetlinemetrics) ([OH_Drawing_Typography](#oh_drawing_typography) \*) | Obtains the line metrics.|
| size_t [OH_Drawing_LineMetricsGetSize](#oh_drawing_linemetricsgetsize) ([OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md) \*) | Obtains the number of lines.|
| void [OH_Drawing_DestroyLineMetrics](#oh_drawing_destroylinemetrics) ([OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md) \*) | Destroys an **OH_Drawing_LineMetrics** object and reclaims the memory occupied by the object.|
| bool [OH_Drawing_TypographyGetLineMetricsAt](#oh_drawing_typographygetlinemetricsat) ([OH_Drawing_Typography](#oh_drawing_typography) \*, int, [OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md) \*) | Obtains the metrics of a given line.|
| bool [OH_Drawing_TypographyGetLineInfo](#oh_drawing_typographygetlineinfo) ([OH_Drawing_Typography](#oh_drawing_typography) \*, int, bool, bool, [OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md) \*) | Obtains the metrics of a given line or the metrics of the first character in a given line.|
| void [OH_Drawing_SetTypographyTextFontWeight](#oh_drawing_settypographytextfontweight) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, int) | Sets the font weight for text. Currently, only the default system font supports font weight adjustment. For other fonts, if the weight is less than semi-bold, there is no variation in stroke thickness. If the weight is greater than or equal to semi-bold, it might result in a fake bold effect.|
| void [OH_Drawing_SetTypographyTextFontStyle](#oh_drawing_settypographytextfontstyle) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, int) | Sets the font style for text.|
| void [OH_Drawing_SetTypographyTextFontFamily](#oh_drawing_settypographytextfontfamily) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, const char \*) | Sets the font family name for text.|
| void [OH_Drawing_SetTypographyTextFontSize](#oh_drawing_settypographytextfontsize) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, double) | Sets the font size for text.|
| void [OH_Drawing_SetTypographyTextFontHeight](#oh_drawing_settypographytextfontheight) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, double) | Sets the font height for text.|
| void [OH_Drawing_SetTypographyTextHalfLeading](#oh_drawing_settypographytexthalfleading) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, bool) | Sets whether to enable half leading for text.|
| void [OH_Drawing_SetTypographyTextUseLineStyle](#oh_drawing_settypographytextuselinestyle) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, bool) | Sets whether to enable the text line style.|
| void [OH_Drawing_SetTypographyTextLineStyleFontWeight](#oh_drawing_settypographytextlinestylefontweight) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, int) | Sets the font weight for a text line style. Currently, only the default system font supports font weight adjustment. For other fonts, if the weight is less than semi-bold, there is no variation in stroke thickness. If the weight is greater than or equal to semi-bold, it might result in a fake bold effect.|
| void [OH_Drawing_SetTypographyTextLineStyleFontStyle](#oh_drawing_settypographytextlinestylefontstyle) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, int) | Sets the font style for a text line style.|
| void [OH_Drawing_SetTypographyTextLineStyleFontFamilies](#oh_drawing_settypographytextlinestylefontfamilies) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, int, const char \*fontFamilies[]) | Sets the font families for a text line style.|
| void [OH_Drawing_SetTypographyTextLineStyleFontSize](#oh_drawing_settypographytextlinestylefontsize) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, double) | Sets the font size for a text line style.|
| void [OH_Drawing_SetTypographyTextLineStyleFontHeight](#oh_drawing_settypographytextlinestylefontheight) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, double) | Sets the font height for a text line style.|
| void [OH_Drawing_SetTypographyTextLineStyleHalfLeading](#oh_drawing_settypographytextlinestylehalfleading) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, bool) | Sets whether to enable half leading for a text line style.|
| void [OH_Drawing_SetTypographyTextLineStyleSpacingScale](#oh_drawing_settypographytextlinestylespacingscale) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, double) | Sets the spacing scale factor for a text line style.|
| void [OH_Drawing_SetTypographyTextLineStyleOnly](#oh_drawing_settypographytextlinestyleonly) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, bool) | Sets whether to enable the text line style only.|
| [OH_Drawing_TextShadow](#oh_drawing_textshadow) \* [OH_Drawing_CreateTextShadow](#oh_drawing_createtextshadow) (void) | Creates an **OH_Drawing_TextShadow** object.|
| void [OH_Drawing_DestroyTextShadow](#oh_drawing_destroytextshadow) ([OH_Drawing_TextShadow](#oh_drawing_textshadow) \*) | Destroys an **OH_Drawing_TextShadow** object and reclaims the memory occupied by the object.|
| [OH_Drawing_TextShadow](#oh_drawing_textshadow) \* [OH_Drawing_TextStyleGetShadows](#oh_drawing_textstylegetshadows) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*) | Obtains a text shadow container.|
| int [OH_Drawing_TextStyleGetShadowCount](#oh_drawing_textstylegetshadowcount) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*) | Obtains the size of a text shadow container.|
| void [OH_Drawing_TextStyleAddShadow](#oh_drawing_textstyleaddshadow) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, const [OH_Drawing_TextShadow](#oh_drawing_textshadow) \*) | Adds a shadow to a text shadow container.|
| void [OH_Drawing_TextStyleClearShadows](#oh_drawing_textstyleclearshadows) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*) | Clears all shadows in a text shadow container.|
| [OH_Drawing_TextShadow](#oh_drawing_textshadow) \* [OH_Drawing_TextStyleGetShadowWithIndex](#oh_drawing_textstylegetshadowwithindex) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, int) | Obtains a shadow with a given index in a text shadow container.|
| void [OH_Drawing_TypographySetIndents](#oh_drawing_typographysetindents) ([OH_Drawing_Typography](#oh_drawing_typography) \*, int, const float indents[]) | Sets indents for typography. If this function is not called, texts will have no indentation applied.|
| float [OH_Drawing_TypographyGetIndentsWithIndex](#oh_drawing_typographygetindentswithindex) ([OH_Drawing_Typography](#oh_drawing_typography) \*, int) | Obtains indents with a given index.|
| [OH_Drawing_Range](#oh_drawing_range) \* [OH_Drawing_TypographyGetLineTextRange](#oh_drawing_typographygetlinetextrange) ([OH_Drawing_Typography](#oh_drawing_typography) \*, int, bool) | Obtains the line bounds.|
| void [OH_Drawing_DestroyTextShadows](#oh_drawing_destroytextshadows) ([OH_Drawing_TextShadow](#oh_drawing_textshadow) \*) | Reclaims the memory occupied by the vector consisting of the **OH_Drawing_TextShadow** objects.|
| [OH_Drawing_FontConfigInfo](_o_h___drawing___font_config_info.md) \* [OH_Drawing_GetSystemFontConfigInfo](#oh_drawing_getsystemfontconfiginfo) ([OH_Drawing_FontConfigInfoErrorCode](#oh_drawing_fontconfiginfoerrorcode) \*) | Obtains the system font configuration.|
| void [OH_Drawing_DestroySystemFontConfigInfo](#oh_drawing_destroysystemfontconfiginfo) ([OH_Drawing_FontConfigInfo](_o_h___drawing___font_config_info.md) \*) | Reclaims the memory occupied by the system font configuration.|
| void [OH_Drawing_SetTextStyleFontStyleStruct](#oh_drawing_settextstylefontstylestruct) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*drawingTextStyle, [OH_Drawing_FontStyleStruct](_o_h___drawing___font_style_struct.md) fontStyle) | Sets the font style, including the font weight, width, and slant, for a text style.|
| [OH_Drawing_FontStyleStruct](_o_h___drawing___font_style_struct.md) [OH_Drawing_TextStyleGetFontStyleStruct](#oh_drawing_textstylegetfontstylestruct) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*drawingTextStyle) | Obtains the font style, including the font weight, width, and slant, of a text style.|
| void [OH_Drawing_SetTypographyStyleFontStyleStruct](#oh_drawing_settypographystylefontstylestruct) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*drawingStyle, [OH_Drawing_FontStyleStruct](_o_h___drawing___font_style_struct.md) fontStyle) | Sets the font style, including the font weight, width, and slant, for a typography style.|
| [OH_Drawing_FontStyleStruct](_o_h___drawing___font_style_struct.md) [OH_Drawing_TypographyStyleGetFontStyleStruct](#oh_drawing_typographystylegetfontstylestruct) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*drawingStyle) | Obtains the font style, including the font weight, width, and slant, of a typography style.|
| void [OH_Drawing_TextStyleSetBackgroundRect](#oh_drawing_textstylesetbackgroundrect) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, const [OH_Drawing_RectStyle_Info](_o_h___drawing___rect_style___info.md) \*, int styleId) | Sets a background rectangle and style ID for a text style. The style ID is valid only when the background box is a rounded rectangle.|
| void [OH_Drawing_TypographyHandlerAddSymbol](#oh_drawing_typographyhandleraddsymbol) ([OH_Drawing_TypographyCreate](#oh_drawing_typographycreate) \*, uint32_t symbol) | Adds the symbol to use in the typography creation process.|
| void [OH_Drawing_TextStyleAddFontFeature](#oh_drawing_textstyleaddfontfeature) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, const char \*tag, int value) | Adds a font feature for a text style.|
| void [OH_Drawing_TextStyleAddFontVariation](#oh_drawing_textstyleaddfontvariation) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, const char \*, const float) | Adds a font variation. This function takes effect only when the corresponding font file (.ttf file) supports variable adjustment. Otherwise, calling this function does not take effect.|
| [OH_Drawing_FontFeature](_o_h___drawing___font_feature.md) \* [OH_Drawing_TextStyleGetFontFeatures](#oh_drawing_textstylegetfontfeatures) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*) | Obtains all the contents in a font feature map container.|
| void [OH_Drawing_TextStyleDestroyFontFeatures](#oh_drawing_textstyledestroyfontfeatures) ([OH_Drawing_FontFeature](_o_h___drawing___font_feature.md) \*, size_t fontFeatureSize) | Reclaims the memory occupied by the struct array that holds all the font features.|
| size_t [OH_Drawing_TextStyleGetFontFeatureSize](#oh_drawing_textstylegetfontfeaturesize) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*) | Obtains the size of a font feature map container.|
| void [OH_Drawing_TextStyleClearFontFeature](#oh_drawing_textstyleclearfontfeature) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*) | Clears all the contents in a font feature map container.|
| double [OH_Drawing_TextStyleGetBaselineShift](#oh_drawing_textstylegetbaselineshift) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*) | Obtains the baseline drift of a text style.|
| void [OH_Drawing_TextStyleSetBaselineShift](#oh_drawing_textstylesetbaselineshift) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, double lineShift) | Sets a baseline drift for a text style.|
| void [OH_Drawing_TypographyTextSetHeightBehavior](#oh_drawing_typographytextsetheightbehavior) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, [OH_Drawing_TextHeightBehavior](#oh_drawing_textheightbehavior) heightMode) | Sets a text height modifier pattern.|
| [OH_Drawing_TextHeightBehavior](#oh_drawing_textheightbehavior) [OH_Drawing_TypographyTextGetHeightBehavior](#oh_drawing_typographytextgetheightbehavior) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*) | Obtains the text height modifier pattern.|
| [OH_Drawing_Font_Metrics](_o_h___drawing___font___metrics.md) \* [OH_Drawing_TypographyGetLineFontMetrics](#oh_drawing_typographygetlinefontmetrics) ([OH_Drawing_Typography](#oh_drawing_typography) \*, size_t lineNumber, size_t \*fontMetricsSize) | Obtains all font metrics from a given line.|
| void [OH_Drawing_TypographyDestroyLineFontMetrics](#oh_drawing_typographydestroylinefontmetrics) ([OH_Drawing_Font_Metrics](_o_h___drawing___font___metrics.md) \*) | Reclaims the memory occupied by the struct array that holds all the font metrics of a given line.|
| bool [OH_Drawing_TextStyleIsEqual](#oh_drawing_textstyleisequal) (const [OH_Drawing_TextStyle](#oh_drawing_textstyle) \*style, const [OH_Drawing_TextStyle](#oh_drawing_textstyle) \*comparedStyle) | Checks whether two text styles are equal.|
| bool [OH_Drawing_TextStyleIsEqualByFont](#oh_drawing_textstyleisequalbyfont) (const [OH_Drawing_TextStyle](#oh_drawing_textstyle) \*style, const [OH_Drawing_TextStyle](#oh_drawing_textstyle) \*comparedStyle) | Checks whether the font style properties of two text styles are equal.|
| bool [OH_Drawing_TextStyleIsAttributeMatched](#oh_drawing_textstyleisattributematched) (const [OH_Drawing_TextStyle](#oh_drawing_textstyle) \*style, const [OH_Drawing_TextStyle](#oh_drawing_textstyle) \*comparedStyle, [OH_Drawing_TextStyleType](#oh_drawing_textstyletype) textStyleType) | Checks whether two text styles have the same text style type.|
| void [OH_Drawing_TextStyleSetPlaceholder](#oh_drawing_textstylesetplaceholder) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*style) | Sets a placeholder for a text style.|
| bool [OH_Drawing_TextStyleIsPlaceholder](#oh_drawing_textstyleisplaceholder) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*style) | Checks whether a placeholder is set for a text style.|
| [OH_Drawing_TextAlign](#oh_drawing_textalign) [OH_Drawing_TypographyStyleGetEffectiveAlignment](#oh_drawing_typographystylegeteffectivealignment) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*style) | Obtains the text alignment mode.|
| bool [OH_Drawing_TypographyStyleIsHintEnabled](#oh_drawing_typographystyleishintenabled) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*style) | Checks whether font hinting is enabled for a typography style. Font hinting is used to improve the readability and appearance of small-sized text when rendering it.|
| void [OH_Drawing_SetTypographyStyleTextStrutStyle](#oh_drawing_settypographystyletextstrutstyle) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, [OH_Drawing_StrutStyle](_o_h___drawing___strut_style.md) \*) | Sets the strut style for a typography style.|
| [OH_Drawing_StrutStyle](_o_h___drawing___strut_style.md) \* [OH_Drawing_TypographyStyleGetStrutStyle](#oh_drawing_typographystylegetstrutstyle) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*) | Obtains the strut style of a typography style.|
| void [OH_Drawing_TypographyStyleDestroyStrutStyle](#oh_drawing_typographystyledestroystrutstyle) ([OH_Drawing_StrutStyle](_o_h___drawing___strut_style.md) \*) | Reclaims the memory occupied by a strut style.|
| bool [OH_Drawing_TypographyStyleStrutStyleEquals](#oh_drawing_typographystylestrutstyleequals) ([OH_Drawing_StrutStyle](_o_h___drawing___strut_style.md) \*from, [OH_Drawing_StrutStyle](_o_h___drawing___strut_style.md) \*to) | Checks whether two strut styles are equal.|
| void [OH_Drawing_TypographyStyleSetHintsEnabled](#oh_drawing_typographystylesethintsenabled) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*style, bool hintsEnabled) | Sets whether to enable font hinting for a typography style. Font hinting is used to improve the readability and appearance of small-sized text when rendering it.|
| void [OH_Drawing_TypographyMarkDirty](#oh_drawing_typographymarkdirty) ([OH_Drawing_Typography](#oh_drawing_typography) \*) | Marks a typography object as dirty data. This function is used to initialize the typography state.|
| int32_t [OH_Drawing_TypographyGetUnresolvedGlyphsCount](#oh_drawing_typographygetunresolvedglyphscount) ([OH_Drawing_Typography](#oh_drawing_typography) \*) | Obtains the number of unresolved glyphs in a typography object.|
| void [OH_Drawing_TypographyUpdateFontSize](#oh_drawing_typographyupdatefontsize) ([OH_Drawing_Typography](#oh_drawing_typography) \*, size_t from, size_t to, float fontSize) | Updates the font size in a typography object.|
| bool [OH_Drawing_TypographyTextGetLineStyle](#oh_drawing_typographytextgetlinestyle) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*) | Checks whether the text line style is enabled for a typography style.|
| [OH_Drawing_FontWeight](#oh_drawing_fontweight) [OH_Drawing_TypographyTextlineStyleGetFontWeight](#oh_drawing_typographytextlinestylegetfontweight) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*) | Obtains the font weight of a text line style.|
| [OH_Drawing_FontStyle](#oh_drawing_fontstyle) [OH_Drawing_TypographyTextlineStyleGetFontStyle](#oh_drawing_typographytextlinestylegetfontstyle) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*) | Obtains the font style of a text line style.|
| char \*\* [OH_Drawing_TypographyTextlineStyleGetFontFamilies](#oh_drawing_typographytextlinestylegetfontfamilies) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*) | Obtains the font families of a text line style.|
| void [OH_Drawing_TypographyTextlineStyleDestroyFontFamilies](#oh_drawing_typographytextlinestyledestroyfontfamilies) (char \*\*fontFamilies, size_t fontFamiliesNum) | Reclaims the memory occupied by the font families.|
| double [OH_Drawing_TypographyTextlineStyleGetFontSize](#oh_drawing_typographytextlinestylegetfontsize) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*) | Obtains the font size of a text line style.|
| double [OH_Drawing_TypographyTextlineStyleGetHeightScale](#oh_drawing_typographytextlinestylegetheightscale) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*) | Obtains the height scale factor of a text line style.|
| bool [OH_Drawing_TypographyTextlineStyleGetHeightOnly](#oh_drawing_typographytextlinestylegetheightonly) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*) | Checks whether only the font height is used for a text line style.|
| bool [OH_Drawing_TypographyTextlineStyleGetHalfLeading](#oh_drawing_typographytextlinestylegethalfleading) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*) | Checks whether half leading is enabled for a text line style.|
| double [OH_Drawing_TypographyTextlineStyleGetSpacingScale](#oh_drawing_typographytextlinestylegetspacingscale) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*) | Obtains the spacing scale factor of a text line style.|
| bool [OH_Drawing_TypographyTextlineGetStyleOnly](#oh_drawing_typographytextlinegetstyleonly) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*) | Checks whether only the text line style is enabled for a typography style.|
| [OH_Drawing_TextAlign](#oh_drawing_textalign) [OH_Drawing_TypographyGetTextAlign](#oh_drawing_typographygettextalign) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*) | Obtains the text alignment mode.|
| [OH_Drawing_TextDirection](#oh_drawing_textdirection) [OH_Drawing_TypographyGetTextDirection](#oh_drawing_typographygettextdirection) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*) | Obtains the text direction.|
| size_t [OH_Drawing_TypographyGetTextMaxLines](#oh_drawing_typographygettextmaxlines) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*) | Obtains the maximum number of lines.|
| char \* [OH_Drawing_TypographyGetTextEllipsis](#oh_drawing_typographygettextellipsis) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*) | Obtains the text ellipsis content.|
| void [OH_Drawing_TypographyDestroyEllipsis](#oh_drawing_typographydestroyellipsis) (char \*ellipsis) | Reclaims the memory occupied by the text ellipsis names.|
| bool [OH_Drawing_TypographyStyleEquals](#oh_drawing_typographystyleequals) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*from, [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*to) | Checks whether two typography styles are the same.|
| uint32_t [OH_Drawing_TextStyleGetColor](#oh_drawing_textstylegetcolor) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*) | Obtains the color of a text style.|
| [OH_Drawing_TextDecorationStyle](#oh_drawing_textdecorationstyle) [OH_Drawing_TextStyleGetDecorationStyle](#oh_drawing_textstylegetdecorationstyle) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*) | Obtains the decoration style of a text style.|
| [OH_Drawing_FontWeight](#oh_drawing_fontweight) [OH_Drawing_TextStyleGetFontWeight](#oh_drawing_textstylegetfontweight) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*) | Obtains the font weight of a text style.|
| [OH_Drawing_FontStyle](#oh_drawing_fontstyle) [OH_Drawing_TextStyleGetFontStyle](#oh_drawing_textstylegetfontstyle) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*) | Obtains the font style of a text style.|
| [OH_Drawing_TextBaseline](#oh_drawing_textbaseline) [OH_Drawing_TextStyleGetBaseline](#oh_drawing_textstylegetbaseline) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*) | Obtains the baseline of a text style.|
| char \*\* [OH_Drawing_TextStyleGetFontFamilies](#oh_drawing_textstylegetfontfamilies) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, size_t \*num) | Obtains the font families of a text style.|
| void [OH_Drawing_TextStyleDestroyFontFamilies](#oh_drawing_textstyledestroyfontfamilies) (char \*\*fontFamilies, size_t num) | Reclaims the memory occupied by the font families.|
| double [OH_Drawing_TextStyleGetFontSize](#oh_drawing_textstylegetfontsize) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*) | Obtains the font size of a text style.|
| double [OH_Drawing_TextStyleGetLetterSpacing](#oh_drawing_textstylegetletterspacing) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*) | Obtains the letter spacing of a text style.|
| double [OH_Drawing_TextStyleGetWordSpacing](#oh_drawing_textstylegetwordspacing) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*) | Obtains the word spacing of a text style.|
| double [OH_Drawing_TextStyleGetFontHeight](#oh_drawing_textstylegetfontheight) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*) | Obtains the font height of a text style.|
| bool [OH_Drawing_TextStyleGetHalfLeading](#oh_drawing_textstylegethalfleading) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*) | Checks whether half leading is enabled for a text style.|
| const char \* [OH_Drawing_TextStyleGetLocale](#oh_drawing_textstylegetlocale) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*) | Obtains the locale of a text style.|
| void [OH_Drawing_TypographyDestroyTextBox](#oh_drawing_typographydestroytextbox) ([OH_Drawing_TextBox](#oh_drawing_textbox) \*) | Releases the memory occupied by a text box.|
| void [OH_Drawing_SetTextShadow](#oh_drawing_settextshadow) ([OH_Drawing_TextShadow](#oh_drawing_textshadow) \*shadow, uint32_t color, [OH_Drawing_Point](#oh_drawing_point) \*offset, double blurRadius) | Sets a text shadow.|
| [OH_Drawing_LineTypography](#oh_drawing_linetypography) \* [OH_Drawing_CreateLineTypography](#oh_drawing_createlinetypography) ([OH_Drawing_TypographyCreate](#oh_drawing_typographycreate) \*handler) | Creates a pointer to an [OH_Drawing_LineTypography](#oh_drawing_linetypography) object, which stores the text content and style and can be used to compute typography details for individual lines of text.|
| void [OH_Drawing_DestroyLineTypography](#oh_drawing_destroylinetypography) ([OH_Drawing_LineTypography](#oh_drawing_linetypography) \*lineTypography) | Releases the memory occupied by an [OH_Drawing_LineTypography](#oh_drawing_linetypography) object.|
| size_t [OH_Drawing_LineTypographyGetLineBreak](#oh_drawing_linetypographygetlinebreak) ([OH_Drawing_LineTypography](#oh_drawing_linetypography) \*lineTypography, size_t startIndex, double width) | Obtains the number of characters that can fit in the layout from the specified position within a limited layout width.|
| OH_Drawing_TextLine \* [OH_Drawing_LineTypographyCreateLine](#oh_drawing_linetypographycreateline) ([OH_Drawing_LineTypography](#oh_drawing_linetypography) \*lineTypography, size_t startIndex, size_t count) | Creates a pointer to an **OH_Drawing_TextLine** object based on the text content in a specified range.|
| [OH_Drawing_TextTab](#oh_drawing_texttab) \* [OH_Drawing_CreateTextTab](#oh_drawing_createtexttab) ([OH_Drawing_TextAlign](#oh_drawing_textalign) alignment, float location) | Creates a text tab object.|
| void [OH_Drawing_DestroyTextTab](#oh_drawing_destroytexttab) ([OH_Drawing_TextTab](#oh_drawing_texttab) \*) | Releases the memory occupied by a text tab object.|
| [OH_Drawing_TextAlign](#oh_drawing_textalign) [OH_Drawing_GetTextTabAlignment](#oh_drawing_gettexttabalignment) ([OH_Drawing_TextTab](#oh_drawing_texttab) \*) | Obtains the alignment mode of a text tab.|
| float [OH_Drawing_GetTextTabLocation](#oh_drawing_gettexttablocation) ([OH_Drawing_TextTab](#oh_drawing_texttab) \*) | Obtains the location of a text tab.|
| void [OH_Drawing_SetTypographyTextTab](#oh_drawing_settypographytexttab) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, [OH_Drawing_TextTab](#oh_drawing_texttab) \*TextTab) | Sets the alignment mode and location of a text tab. When the text alignment mode or ellipsis style is set, the tab does not take effect. When the tab location is less than 1.0, the tab is replaced with a space.|
| size_t [OH_Drawing_GetDrawingArraySize](#oh_drawing_getdrawingarraysize) ([OH_Drawing_Array](#oh_drawing_array) \*drawingArray) | Obtains the number of objects in an [OH_Drawing_Array](#oh_drawing_array).|
| [OH_Drawing_Typeface](#oh_drawing_typeface) \* [OH_Drawing_TypefaceCreateDefault](#oh_drawing_typefacecreatedefault) (void) | Creates a default **OH_Drawing_Typeface** object.|
| [OH_Drawing_Typeface](#oh_drawing_typeface) \* [OH_Drawing_TypefaceCreateFromFile](#oh_drawing_typefacecreatefromfile) (const char \*path, int index) | Creates an **OH_Drawing_Typeface** object through a file.|
| [OH_Drawing_Typeface](#oh_drawing_typeface) \* [OH_Drawing_TypefaceCreateFromFileWithArguments](#oh_drawing_typefacecreatefromfilewitharguments) (const char \*path, const [OH_Drawing_FontArguments](#oh_drawing_fontarguments) \*fontArguments) | Creates an **OH_Drawing_Typeface** object with font arguments through a file. If the **OH_Drawing_Typeface** object does not support the variation described in the font arguments, this function creates an **OH_Drawing_Typeface** object with the default font arguments. In this case, this function provides the same capability as [OH_Drawing_TypefaceCreateFromFile](#oh_drawing_typefacecreatefromfile).|
| [OH_Drawing_Typeface](#oh_drawing_typeface) \* [OH_Drawing_TypefaceCreateFromCurrent](#oh_drawing_typefacecreatefromcurrent) (const [OH_Drawing_Typeface](#oh_drawing_typeface) \*current, const [OH_Drawing_FontArguments](#oh_drawing_fontarguments) \*fontArguments) | Creates an **OH_Drawing_Typeface** object with font arguments based on an existing **OH_Drawing_Typeface** object.|
| [OH_Drawing_Typeface](#oh_drawing_typeface) \* [OH_Drawing_TypefaceCreateFromStream](#oh_drawing_typefacecreatefromstream) ([OH_Drawing_MemoryStream](#oh_drawing_memorystream) \*, int32_t index) | Creates an **OH_Drawing_Typeface** object through a memory stream. If the memory stream is an invalid font file, a null pointer is returned. After the memory stream is passed in, the ownership is transferred and you cannot release it.|
| void [OH_Drawing_TypefaceDestroy](#oh_drawing_typefacedestroy) ([OH_Drawing_Typeface](#oh_drawing_typeface) \*) | Destroys an **OH_Drawing_Typeface** object and reclaims the memory occupied by the object.|
| [OH_Drawing_FontArguments](#oh_drawing_fontarguments) \* [OH_Drawing_FontArgumentsCreate](#oh_drawing_fontargumentscreate) (void) | Creates an **OH_Drawing_FontArguments** object. The font arguments are used to create an **OH_Drawing_Typeface** object with custom attributes.|
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_FontArgumentsAddVariation](#oh_drawing_fontargumentsaddvariation) ([OH_Drawing_FontArguments](#oh_drawing_fontarguments) \*fontArguments, const char \*axis, float value) | Adds a variation to an **OH_Drawing_FontArguments** object.|
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_FontArgumentsDestroy](#oh_drawing_fontargumentsdestroy) ([OH_Drawing_FontArguments](#oh_drawing_fontarguments) \*fontArguments) | Destroys an **OH_Drawing_FontArguments** object.|
| enum&nbsp;&nbsp;[OH_Drawing_CanvasShadowFlags](#oh_drawing_canvasshadowflags) { SHADOW_FLAGS_NONE, SHADOW_FLAGS_TRANSPARENT_OCCLUDER, SHADOW_FLAGS_GEOMETRIC_ONLY, SHADOW_FLAGS_ALL } | Defines an enum for the shadow flags.|
| typedef enum [OH_Drawing_CanvasShadowFlags](#oh_drawing_canvasshadowflags) [OH_Drawing_CanvasShadowFlags](#oh_drawing_canvasshadowflags) | Defines an enum for the shadow flags.|
| void [OH_Drawing_CanvasClipRect](#oh_drawing_canvascliprect) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Rect](#oh_drawing_rect) \*, [OH_Drawing_CanvasClipOp](#oh_drawing_canvasclipop) clipOp, bool doAntiAlias) | Clips a rectangle.|
| void [OH_Drawing_CanvasClipRoundRect](#oh_drawing_canvascliproundrect) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_RoundRect](#oh_drawing_roundrect) \*, [OH_Drawing_CanvasClipOp](#oh_drawing_canvasclipop) clipOp, bool doAntiAlias) | Clips a rounded rectangle.|
| void [OH_Drawing_CanvasClipPath](#oh_drawing_canvasclippath) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Path](#oh_drawing_path) \*, [OH_Drawing_CanvasClipOp](#oh_drawing_canvasclipop) clipOp, bool doAntiAlias) | Clips a path.|
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_CanvasClipRegion](#oh_drawing_canvasclipregion) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*canvas, const [OH_Drawing_Region](#oh_drawing_region) \*region, [OH_Drawing_CanvasClipOp](#oh_drawing_canvasclipop) clipOp) | Clips a rectangle.|
| void [OH_Drawing_CanvasRotate](#oh_drawing_canvasrotate) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, float degrees, float px, float py) | Rotates a canvas by a given angle. A positive value indicates a clockwise rotation, and a negative value indicates a counterclockwise rotation.|
| void [OH_Drawing_CanvasTranslate](#oh_drawing_canvastranslate) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, float dx, float dy) | Translates a canvas by a given distance.|
| void [OH_Drawing_CanvasScale](#oh_drawing_canvasscale) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, float sx, float sy) | Scales a canvas.|
| void [OH_Drawing_CanvasSkew](#oh_drawing_canvasskew) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, float sx, float sy) | Skews a canvas. This function premultiplies the current canvas matrix by a skew transformation matrix and applies the resulting matrix to the canvas. The skew transformation matrix is as follows: \|1 sx 0\| \|sy 1 0\| \|0 0 1\| |
| void [OH_Drawing_CanvasClear](#oh_drawing_canvasclear) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, uint32_t color) | Clears a canvas by using a given color.|
| int32_t [OH_Drawing_CanvasGetWidth](#oh_drawing_canvasgetwidth) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*) | Obtains the canvas width.|
| int32_t [OH_Drawing_CanvasGetHeight](#oh_drawing_canvasgetheight) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*) | Obtains the canvas height.|
| void [OH_Drawing_CanvasGetLocalClipBounds](#oh_drawing_canvasgetlocalclipbounds) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, [OH_Drawing_Rect](#oh_drawing_rect) \*) | Obtains the bounds of the cropping region of a canvas. This function cannot be used for recorded canvases.|
| void [OH_Drawing_CanvasGetTotalMatrix](#oh_drawing_canvasgettotalmatrix) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, [OH_Drawing_Matrix](#oh_drawing_matrix) \*) | Obtains the 3x3 matrix of a canvas.|
| void [OH_Drawing_CanvasConcatMatrix](#oh_drawing_canvasconcatmatrix) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, [OH_Drawing_Matrix](#oh_drawing_matrix) \*) | Preconcats the existing matrix with the passed-in matrix. The drawing operation triggered before this function is called is not affected.|
| void [OH_Drawing_CanvasDrawShadow](#oh_drawing_canvasdrawshadow) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, [OH_Drawing_Path](#oh_drawing_path) \*, [OH_Drawing_Point3D](_o_h___drawing___point3_d.md) planeParams, [OH_Drawing_Point3D](_o_h___drawing___point3_d.md) devLightPos, float lightRadius, uint32_t ambientColor, uint32_t spotColor, [OH_Drawing_CanvasShadowFlags](#oh_drawing_canvasshadowflags) flag) | Draws a spot shadow and uses a given path to outline the ambient shadow.|
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_CanvasDrawRecordCmd](#oh_drawing_canvasdrawrecordcmd) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*canvas, [OH_Drawing_RecordCmd](#oh_drawing_recordcmd) \*recordCmd) | Draws a recording command object.|

## Type Description


### OH_Drawing_Array

```
typedef struct OH_Drawing_ArrayOH_Drawing_Array
```

**Description**

Defines a struct for an array object, which is used to store multiple objects of the same type.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

### OH_Drawing_LineTypography

```
typedef struct OH_Drawing_LineTypographyOH_Drawing_LineTypography
```

**Description**

Defines a struct used to extract a single line of data from a piece of text for typography.

**Since**: 14

### OH_Drawing_TextTab

```
typedef struct OH_Drawing_TextTabOH_Drawing_TextTab
```

**Description**

Defines a struct used to manage text tabs.

**Since**: 14

### Drawing_CaretOffsetsCallback

```
typedef bool(* Drawing_CaretOffsetsCallback) (double offset, int32_t index, bool leadingEdge)
```

**Description**

Defines a custom callback used to receive the offset and index of each character in a text line object as its parameters.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| offset | Offset of each character in the text line object.|
| index | Index of each character in the text line object.|
| leadingEdge | Whether the cursor is located at the front of the character. The value **true** means that the cursor is located at the front of the character, that is, the offset does not contain the character width. The value **false** means that the cursor is located at the rear of the character, that is, the offset contains the character width.|

**Returns**

Returns the result indicating whether to stop calling the callback. The value **true** means to stop calling the callback, and **false** means to continue calling the callback.

### OH_Drawing_String

```
typedef struct OH_Drawing_StringOH_Drawing_String
```

**Description**

Defines a struct for a string of characters encoded in UTF-16BE (big-endian mode).

**Since**: 14


### OH_Drawing_SystemFontType

```
typedef enum OH_Drawing_SystemFontType OH_Drawing_SystemFontType
```

**Description**

Defines an enum for the system font types.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14


### OH_Drawing_FontArguments

```
typedef struct OH_Drawing_FontArguments OH_Drawing_FontArguments
```

**Description**

Defines a struct for font arguments.

**Since**: 13

### OH_Drawing_RecordCmd

```
typedef struct OH_Drawing_RecordCmd OH_Drawing_RecordCmd
```

**Description**

Defines the recording command class, which is used to store the set of recording commands.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 13


### OH_Drawing_RecordCmdUtils

```
typedef struct OH_Drawing_RecordCmdUtils OH_Drawing_RecordCmdUtils
```

**Description**

Defines the recording command tool, which is used to generate recording commands.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 13


### OH_Drawing_ErrorCode

```
typedef enum OH_Drawing_ErrorCode OH_Drawing_ErrorCode
```


**Description**

Defines an enum for the error codes that may be generated by the module.

**Since**: 12


### OH_Drawing_PathOpMode

```
typedef enum OH_Drawing_PathOpMode OH_Drawing_PathOpMode
```

**Description**

Defines an enum for the operation modes available for a path.

**Since**: 12


### OH_Drawing_PathMeasureMatrixFlags

```
typedef enum OH_Drawing_PathMeasureMatrixFlags OH_Drawing_PathMeasureMatrixFlags
```

**Description**

Defines an enum for the types of matrix information obtained during path measurement.

**Since**: 12


### OH_Drawing_RegionOpMode

```
typedef enum OH_Drawing_RegionOpMode OH_Drawing_RegionOpMode
```

**Description**

Defines an enum for the operation modes available for a region.

**Since**: 12


### OH_Drawing_ImageFilter

```
typedef struct OH_Drawing_ImageFilter OH_Drawing_ImageFilter
```

**Description**

Defines a struct for an image filter, which is used to operate all color bits that make up image pixels.

**Since**: 12


### OH_Drawing_Filter

```
typedef struct OH_Drawing_Filter OH_Drawing_Filter
```

**Description**

Defines a struct for a filter, which consists of a color filter, mask filter, and image filter.

**Since**: 11

### OH_Drawing_AlphaFormat

```
typedef enum OH_Drawing_AlphaFormat OH_Drawing_AlphaFormat
```

**Description**

Defines an enum for the alpha formats of bitmap pixels.

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

Defines a struct for the pixel format of a bitmap, including the color type and alpha type.

**Since**: 8


### OH_Drawing_BlendMode

```
typedef enum OH_Drawing_BlendMode OH_Drawing_BlendMode
```

**Description**

Defines an enum for the blend modes. In blend mode, each operation generates a new color from two colors (source color and target color). These operations are the same on the four channels (red, green, blue, and alpha). The operations for the alpha channel are used as examples.

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

Defines an enum for the blur types.

**Since**: 11


### OH_Drawing_BreakStrategy

```
typedef enum OH_Drawing_BreakStrategy OH_Drawing_BreakStrategy
```

**Description**

Defines an enum for the text break strategies.

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

Defines an enum for the canvas clipping modes.

**Since**: 11


### OH_Drawing_CanvasShadowFlags

```
typedef enum OH_Drawing_CanvasShadowFlags OH_Drawing_CanvasShadowFlags
```

**Description**

Defines an enum for the shadow flags.

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

Defines an enum for the storage formats of bitmap pixels.

**Since**: 8


### OH_Drawing_ColorSpace

```
typedef struct OH_Drawing_ColorSpace OH_Drawing_ColorSpace
```

**Description**

Defines a struct for a color space, which is used to describe the color information.

**Since**: 12


### OH_Drawing_Corner_Radii

```
typedef OH_Drawing_Point2D OH_Drawing_Corner_Radii
```

**Description**

Defines a struct for the radii of a rounded corner. The radii consist of the radius in the x-axis direction and that in the y-axis direction.

**Since**: 12


### OH_Drawing_CornerPos

```
typedef enum OH_Drawing_CornerPos OH_Drawing_CornerPos
```

**Description**

Defines an enum for the corner positions of a rounded rectangle.

**Since**: 12


### OH_Drawing_EllipsisModal

```
typedef enum OH_Drawing_EllipsisModal OH_Drawing_EllipsisModal
```

**Description**

Defines an enum for the text ellipsis styles.

**Since**: 11


### OH_Drawing_FilterMode

```
typedef enum OH_Drawing_FilterMode OH_Drawing_FilterMode
```

**Description**

Defines an enum for the filter modes.

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

Defines a struct for the measurement information about a font.

**Since**: 12


### OH_Drawing_FontAdjustInfo

```
typedef struct OH_Drawing_FontAdjustInfo OH_Drawing_FontAdjustInfo
```

**Description**

Defines a struct for the information about a font weight mapping.

**Since**: 12


### OH_Drawing_FontAliasInfo

```
typedef struct OH_Drawing_FontAliasInfo OH_Drawing_FontAliasInfo
```

**Description**

Defines a struct for the information about a font alias.

**Since**: 12


### OH_Drawing_FontCollection

```
typedef struct OH_Drawing_FontCollection OH_Drawing_FontCollection
```

**Description**

Defines a struct used to load fonts.

**Since**: 8


### OH_Drawing_FontConfigInfo

```
typedef struct OH_Drawing_FontConfigInfo OH_Drawing_FontConfigInfo
```

**Description**

Defines a struct for the information about a system font configuration.

**Since**: 12


### OH_Drawing_FontDescriptor

```
typedef struct OH_Drawing_FontDescriptor OH_Drawing_FontDescriptor
```

**Description**

Defines a struct for the detailed information about a system font.

**Since**: 12


### OH_Drawing_FontEdging

```
typedef enum OH_Drawing_FontEdging OH_Drawing_FontEdging
```

**Description**

Defines an enum for the font edging types.

**Since**: 12


### OH_Drawing_FontFallbackGroup

```
typedef struct OH_Drawing_FontFallbackGroup OH_Drawing_FontFallbackGroup
```

**Description**

Defines a struct for the information about a font fallback group.

**Since**: 12


### OH_Drawing_FontFallbackInfo

```
typedef struct OH_Drawing_FontFallbackInfo OH_Drawing_FontFallbackInfo
```

**Description**

Defines a struct for the information about a font fallback.

**Since**: 12


### OH_Drawing_FontGenericInfo

```
typedef struct OH_Drawing_FontGenericInfo OH_Drawing_FontGenericInfo
```

**Description**

Defines a struct for the information about generic fonts supported by the system.

**Since**: 12


### OH_Drawing_FontHinting

```
typedef enum OH_Drawing_FontHinting OH_Drawing_FontHinting
```

**Description**

Defines an enum for the font hinting types.

**Since**: 12


### OH_Drawing_FontMgr

```
typedef struct OH_Drawing_FontMgr OH_Drawing_FontMgr
```

**Description**

Defines a struct for the font manager, which is used for font management.

**Since**: 12


### OH_Drawing_FontParser

```
typedef struct OH_Drawing_FontParser OH_Drawing_FontParser
```

**Description**

Defines a struct used to parse system font files.

**Since**: 12


### OH_Drawing_FontStyleSet

```
typedef struct OH_Drawing_FontStyleSet OH_Drawing_FontStyleSet
```

**Description**

Defines a struct for a font style set, which is used for font style family matching.

**Since**: 12


### OH_Drawing_FontStyleStruct

```
typedef struct OH_Drawing_FontStyleStruct OH_Drawing_FontStyleStruct
```

**Description**

Defines a struct for a font style.

**Since**: 12


### OH_Drawing_GpuContext

```
typedef struct OH_Drawing_GpuContext OH_Drawing_GpuContext
```

**Description**

Defines a struct for the GPU context, which is used to describe the GPU backend context.

**Since**: 12


### OH_Drawing_GpuContextOptions

```
typedef struct OH_Drawing_GpuContextOptions OH_Drawing_GpuContextOptions
```

**Description**

Defines a struct for the options about the GPU context.

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

Defines a struct for the image information.

**Since**: 12


### OH_Drawing_LineMetrics

```
typedef struct OH_Drawing_LineMetrics OH_Drawing_LineMetrics
```

**Description**

Defines a struct for the measurement information about a line of text.

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

Defines an enum for the mipmap modes.

**Since**: 12


### OH_Drawing_Path

```
typedef struct OH_Drawing_Path OH_Drawing_Path
```

**Description**

Defines a struct for a path, which is used to customize various shapes.

**Since**: 8


### OH_Drawing_PathAddMode

```
typedef enum OH_Drawing_PathAddMode OH_Drawing_PathAddMode
```

**Description**

Defines an enum for the path adding modes.

**Since**: 12


### OH_Drawing_PathDirection

```
typedef enum OH_Drawing_PathDirection OH_Drawing_PathDirection
```

**Description**

Defines an enum for the directions of a closed contour.

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

Defines an enum for the fill types of a path.

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

Defines an enum for the line cap styles of a pen. The line cap style defines the style of both ends of a line segment drawn by the pen.

**Since**: 8


### OH_Drawing_PenLineJoinStyle

```
typedef enum OH_Drawing_PenLineJoinStyle OH_Drawing_PenLineJoinStyle
```

**Description**

Defines an enum for the line join styles of a pen. The line join style defines the shape of the joints of a polyline segment drawn by the pen.

**Since**: 8


### OH_Drawing_PixelMap

```
typedef struct OH_Drawing_PixelMap OH_Drawing_PixelMap
```

**Description**

Defines a struct for a pixel map, which is used to wrap the real pixel map supported by the image framework.

**Since**: 12


### OH_Drawing_PlaceholderSpan

```
typedef struct OH_Drawing_PlaceholderSpan OH_Drawing_PlaceholderSpan
```

**Description**

Defines a struct for the placeholder that acts as a span.

**Since**: 11


### OH_Drawing_PlaceholderVerticalAlignment

```
typedef enum OH_Drawing_PlaceholderVerticalAlignment OH_Drawing_PlaceholderVerticalAlignment
```

**Description**

Defines an enum for the vertical alignment modes of placeholders.

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


### OH_Drawing_PointMode

```
typedef enum OH_Drawing_PointMode OH_Drawing_PointMode
```

**Description**

Defines an enum for the modes of drawing multiple points. The modes include discrete points, line segments, and open polygons.

**Since**: 12


### OH_Drawing_PositionAndAffinity

```
typedef struct OH_Drawing_PositionAndAffinity OH_Drawing_PositionAndAffinity
```

**Description**

Defines a struct used to receive the position and affinity of a glyph.

**Since**: 11


### OH_Drawing_Range

```
typedef struct OH_Drawing_Range OH_Drawing_Range
```

**Description**

Defines a struct for a range, which is used to receive the start position and end position of a glyph.

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

Defines an enum for the rectangle height styles.

**Since**: 11


### OH_Drawing_RectStyle_Info

```
typedef struct OH_Drawing_RectStyle_Info OH_Drawing_RectStyle_Info
```

**Description**

Defines a struct for the style of a rectangle.

**Since**: 12


### OH_Drawing_RectWidthStyle

```
typedef enum OH_Drawing_RectWidthStyle OH_Drawing_RectWidthStyle
```

**Description**

Defines an enum for the rectangle width styles.

**Since**: 11


### OH_Drawing_Region

```
typedef struct OH_Drawing_Region OH_Drawing_Region
```

**Description**

Defines a struct for a region, which represents a closed area on the canvas for more accurate graphic control.

**Since**: 12


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

Defines a struct for a run, which provides storage for glyphs and positions.

**Since**: 11


### OH_Drawing_SamplingOptions

```
typedef struct OH_Drawing_SamplingOptions OH_Drawing_SamplingOptions
```

**Description**

Defines a struct for sampling options, which describe the sampling methods for images and bitmaps.

**Since**: 12


### OH_Drawing_ScaleToFit

```
typedef enum OH_Drawing_ScaleToFit OH_Drawing_ScaleToFit
```

**Description**

Defines an enum for the matrix scaling modes.

**Since**: 12


### OH_Drawing_ShaderEffect

```
typedef struct OH_Drawing_ShaderEffect OH_Drawing_ShaderEffect
```

**Description**

Defines a struct for a shader effect, which is used to describe the source color of the drawn content.

**Since**: 11


### OH_Drawing_ShadowLayer

```
typedef struct OH_Drawing_ShadowLayer OH_Drawing_ShadowLayer
```

**Description**

Defines a struct for a shadow, which is used to describe the shadow layer of the drawn content.

**Since**: 12


### OH_Drawing_SrcRectConstraint

```
typedef enum OH_Drawing_SrcRectConstraint OH_Drawing_SrcRectConstraint
```

**Description**

Defines an enum for the constraint types of the source rectangle.

**Since**: 12


### OH_Drawing_StrutStyle

```
typedef struct OH_Drawing_StrutStyle OH_Drawing_StrutStyle
```

**Description**

Defines a struct for a strut style. The strut style determines the line spacing, baseline alignment mode, and other properties related to the line height when drawing texts.

**Since**: 12


### OH_Drawing_Surface

```
typedef struct OH_Drawing_Surface OH_Drawing_Surface
```

**Description**

Defines a struct for a surface, which is used to manage the content drawn on the canvas.

**Since**: 12


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

Defines an enum for the text decoration styles.

**Since**: 11


### OH_Drawing_TextEncoding

```
typedef enum OH_Drawing_TextEncoding OH_Drawing_TextEncoding
```

**Description**

Defines an enum for the text encoding types.

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

Defines an enum for the tile modes of the shader effect.

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


### OH_Drawing_VertexMode

```
typedef enum OH_Drawing_VertexMode OH_Drawing_VertexMode
```

**Description**

Defines an enum for the modes of interpreting the geometry of a given vertex.

**Since**: 12


### OH_Drawing_WordBreakType

```
typedef enum OH_Drawing_WordBreakType OH_Drawing_WordBreakType
```

**Description**

Defines an enum for the word break types.

**Since**: 11


## Enum Description

### OH_Drawing_SystemFontType

```
enum OH_Drawing_SystemFontType
```

**Description**

Enumerates the system font types.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

| Value| Description|
| -------- | -------- |
| ALL | All font types.|
| GENERIC | System font type.|
| STYLISH | Style font type.|
| INSTALLED | User-installed font type.|

### OH_Drawing_ErrorCode

```
enum OH_Drawing_ErrorCode
```

**Description**

Enumerates the error codes that may be generated by the module.

**Since**: 12

| Value| Description|
| -------- | -------- |
| OH_DRAWING_SUCCESS | Operation successful.|
| OH_DRAWING_ERROR_NO_PERMISSION | Permission verification fails.|
| OH_DRAWING_ERROR_INVALID_PARAMETER | Invalid input parameter. For example, NULL is passed in.|
| OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE | The input parameter is not in the valid range.|
| OH_DRAWING_ERROR_ALLOCATION_FAILED<sup>13+</sup> | Failed to allocate memory.|

### OH_Drawing_PathMeasureMatrixFlags

```
enum OH_Drawing_PathMeasureMatrixFlags
```

**Description**

Enumerates the types of matrix information obtained during path measurement.

**Since**: 12

| Value| Description|
| -------- | -------- |
| GET_POSITION_MATRIX | Obtains the matrix corresponding to the location information.|
| GET_TANGENT_MATRIX | Obtains the matrix corresponding to the tangent information.|
| GET_POSITION_AND_TANGENT_MATRIX | Obtains the matrix corresponding to the location and tangent information.|


### OH_Drawing_PathOpMode

```
enum OH_Drawing_PathOpMode
```

**Description**

Enumerates the operation modes available for a path.

**Since**: 12

| Value| Description|
| -------- | -------- |
| PATH_OP_MODE_DIFFERENCE | Difference operation.|
| PATH_OP_MODE_INTERSECT | Intersection operation.|
| PATH_OP_MODE_UNION | Union operation.|
| PATH_OP_MODE_XOR | XOR operation.|
| PATH_OP_MODE_REVERSE_DIFFERENCE | Reverse difference operation.|


### OH_Drawing_RegionOpMode

```
enum OH_Drawing_RegionOpMode
```

**Description**

Enumerates the operation modes available for a region.

**Since**: 12

| Value| Description|
| -------- | -------- |
| REGION_OP_MODE_DIFFERENCE | Difference operation.|
| REGION_OP_MODE_INTERSECT | Intersection operation.|
| REGION_OP_MODE_UNION | Union operation.|
| REGION_OP_MODE_XOR | XOR operation.|
| REGION_OP_MODE_REVERSE_DIFFERENCE | Reverse difference operation.|
| REGION_OP_MODE_REPLACE | Replacement operation.|


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

Enumerates the shadow flags.

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


### OH_Drawing_CornerPos

```
enum OH_Drawing_CornerPos
```

**Description**

Enumerates the corner positions of a rounded rectangle.

**Since**: 12

| Value| Description|
| -------- | -------- |
| CORNER_POS_TOP_LEFT | Top left corner of the rounded rectangle.|
| CORNER_POS_TOP_RIGHT | Top right corner of the rounded rectangle.|
| CORNER_POS_BOTTOM_RIGHT | Bottom right corner of the rounded rectangle.|
| CORNER_POS_BOTTOM_LEFT | Bottom left corner of the rounded rectangle.|


### OH_Drawing_EllipsisModal

```
enum OH_Drawing_EllipsisModal
```

**Description**

Enumerates the text ellipsis styles.

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


### OH_Drawing_FontConfigInfoErrorCode

```
enum OH_Drawing_FontConfigInfoErrorCode
```

**Description**

Enumerates the error codes that may be used during the obtaining of system font configurations.

**Since**: 12

| Value| Description|
| -------- | -------- |
| SUCCESS_FONT_CONFIG_INFO | Operation successful.|
| ERROR_FONT_CONFIG_INFO_UNKNOWN | Unknown error.|
| ERROR_FONT_CONFIG_INFO_PARSE_FILE | Failed to parse the system configuration file.|
| ERROR_FONT_CONFIG_INFO_ALLOC_MEMORY | Failed to apply for a buffer.|
| ERROR_FONT_CONFIG_INFO_COPY_STRING_DATA | Failed to copy the string data.|


### OH_Drawing_FontEdging

```
enum OH_Drawing_FontEdging
```

**Description**

Enumerates the font edging types.

**Since**: 12

| Value| Description|
| -------- | -------- |
| FONT_EDGING_ALIAS | No anti-aliasing processing is used.|
| FONT_EDGING_ANTI_ALIAS | Uses anti-aliasing to smooth the jagged edges.|
| FONT_EDGING_SUBPIXEL_ANTI_ALIAS | Uses sub-pixel anti-aliasing to provide a smoother effect for jagged edges.|


### OH_Drawing_FontHinting

```
enum OH_Drawing_FontHinting
```

**Description**

Enumerates the font hinting types.

**Since**: 12

| Value| Description|
| -------- | -------- |
| FONT_HINTING_NONE | No font hinting is used.|
| FONT_HINTING_SLIGHT | Slight font hinting is used to improve contrast.|
| FONT_HINTING_NORMAL | Normal font hinting is used to improve contrast.|
| FONT_HINTING_FULL | Full font hinting is used to improve contrast.|


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
| FONT_STYLE_OBLIQUE | Oblique.<br>Since:<br>12 |


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


### OH_Drawing_FontWidth

```
enum OH_Drawing_FontWidth
```

**Description**

Enumerates the font widths.

**Since**: 12


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


### OH_Drawing_PathAddMode

```
enum OH_Drawing_PathAddMode
```

**Description**

Enumerates the path adding modes.

**Since**: 12

| Value| Description|
| -------- | -------- |
| PATH_ADD_MODE_APPEND | Adds a path in append mode.|
| PATH_ADD_MODE_EXTEND | Adds a line segment to close the path if the previous path is not closed.|


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
| PATH_FILL_TYPE_WINDING | Specifies that "inside" is computed by a non-zero sum of signed edge crossings. Specifically, draws a point and emits a ray in any direction. A count is used to record the number of intersection points of the ray and path, and the initial count is 0. When encountering a clockwise intersection point (the path passes from the left to the right of the ray), the count increases by 1. When encountering a counterclockwise intersection point (the path passes from the right to the left of the ray), the count decreases by 1. If the final count is not 0, the point is inside the path and needs to be colored. If the final count is 0, the point is not colored.|
| PATH_FILL_TYPE_EVEN_ODD | Specifies that "inside" is computed by an odd number of edge crossings. Specifically, draws a point and emits a ray in any direction. If the number of intersection points of the ray and path is an odd number, the point is considered to be inside the path and needs to be colored. If the number is an even number, the point is not colored.|
| PATH_FILL_TYPE_INVERSE_WINDING | Same as **PATH_FILL_TYPE_WINDING**, but draws outside of the path, rather than inside.|
| PATH_FILL_TYPE_INVERSE_EVEN_ODD | Same as **PATH_FILL_TYPE_EVEN_ODD**, but draws outside of the path, rather than inside.|


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


### OH_Drawing_PointMode

```
enum OH_Drawing_PointMode
```

**Description**

Enumerates the modes of drawing multiple points. The modes include discrete points, line segments, and open polygons.

**Since**: 12

| Value| Description|
| -------- | -------- |
| POINT_MODE_POINTS | Draws each point separately.|
| POINT_MODE_LINES | Draws every two points as a line segment.|
| POINT_MODE_POLYGON | Draws an array of points as an open polygon.|


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


### OH_Drawing_ScaleToFit

```
enum OH_Drawing_ScaleToFit
```

**Description**

Enumerates the matrix scaling modes.

**Since**: 12

| Value| Description|
| -------- | -------- |
| SCALE_TO_FIT_FILL | Scales the source rectangle both horizontally and vertically to exactly match the destination rectangle.|
| SCALE_TO_FIT_START | Scales the source rectangle and aligns it to the left and top edges of the destination rectangle.|
| SCALE_TO_FIT_CENTER | Scales the source rectangle and aligns it to the center of the destination rectangle.|
| SCALE_TO_FIT_END | Scales the source rectangle and aligns it to the right and bottom edges of the destination rectangle.|


### OH_Drawing_SrcRectConstraint

```
enum OH_Drawing_SrcRectConstraint
```

**Description**

Enumerates the constraint types of the source rectangle.

**Since**: 12

| Value| Description|
| -------- | -------- |
| STRICT_SRC_RECT_CONSTRAINT | The source rectangle must be completely contained in the image.|
| FAST_SRC_RECT_CONSTRAINT | The source rectangle can be partly outside the image.|


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
| TEXT_BASELINE_IDEOGRAPHIC | Ideographic, where the baseline is at the bottom of the text area.|


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


### OH_Drawing_TextHeightBehavior

```
enum OH_Drawing_TextHeightBehavior
```

**Description**

Enumerates the text height modifier patterns.

**Since**: 12

| Value| Description|
| -------- | -------- |
| TEXT_HEIGHT_ALL | Enables ascent for the first and last rows of a paragraph.|
| TEXT_HEIGHT_DISABLE_FIRST_ASCENT | Disables ascent for the first row of a paragraph.|
| TEXT_HEIGHT_DISABLE_LAST_ASCENT | Disables ascent for the last row of a paragraph.|
| TEXT_HEIGHT_DISABLE_ALL | Disables ascent for the first and last rows of a paragraph.|


### OH_Drawing_TextStyleType

```
enum OH_Drawing_TextStyleType
```

**Description**

Enumerates the text style types.

**Since**: 12

| Value| Description|
| -------- | -------- |
| TEXT_STYLE_NONE | No text style.|
| TEXT_STYLE_ALL_ATTRIBUTES | All text styles.|
| TEXT_STYLE_FONT | Font style.|
| TEXT_STYLE_FOREGROUND | Text foreground style.|
| TEXT_STYLE_BACKGROUND | Text background style.|
| TEXT_STYLE_SHADOW | Text shadow style.|
| TEXT_STYLE_DECORATIONS | Text decoration style.|
| TEXT_STYLE_LETTER_SPACING | Text letter spacing style.|
| TEXT_STYLE_WORD_SPACING | Text word spacing style.|


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


### OH_Drawing_VertexMode

```
enum OH_Drawing_VertexMode
```

**Description**

Enumerates the modes of interpreting the geometry of a given vertex.

**Since**: 12

| Value| Description|
| -------- | -------- |
| VERTEX_MODE_TRIANGLES | Draws a triangle list. Specifically, a list of isolated triangles are drawn using every three vertices. If the number of vertices is not a multiple of 3, the extra vertices will be ignored. |
| VERTEX_MODE_TRIANGLESSTRIP | Draws a triangle strip. Specifically, the first triangle is drawn between the first 3 vertices, and all subsequent triangles use the previous 2 vertices plus the next additional vertex.|
| VERTEX_MODE_TRIANGLEFAN | Draws a triangle fan. A triangle fan is similar to a triangle strip, except that all the triangles share one vertex (the first vertex).|


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


### OH_Drawing_CreateLineTypography()

```
OH_Drawing_LineTypography* OH_Drawing_CreateLineTypography (OH_Drawing_TypographyCreate* handler)
```

**Description**

Creates a pointer to an [OH_Drawing_LineTypography](#oh_drawing_linetypography) object, which stores the text content and style and can be used to compute typography details for individual lines of text.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| handler | Pointer to an [OH_Drawing_TypographyCreate](#oh_drawing_typographycreate) object. The pointer is obtained by calling [OH_Drawing_CreateTypographyHandler](#oh_drawing_createtypographyhandler).|

**Returns**

Returns the pointer to the [OH_Drawing_LineTypography](#oh_drawing_linetypography) object created.

### OH_Drawing_DestroyLineTypography()

```
void OH_Drawing_DestroyLineTypography (OH_Drawing_LineTypography* lineTypography)
```

**Description**

Releases the memory occupied by an [OH_Drawing_LineTypography](#oh_drawing_linetypography) object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| lineTypography | Pointer to an [OH_Drawing_LineTypography](#oh_drawing_linetypography) object, which is obtained by calling [OH_Drawing_CreateLineTypography](#oh_drawing_createlinetypography).|

### OH_Drawing_LineTypographyGetLineBreak()

```
size_t OH_Drawing_LineTypographyGetLineBreak (OH_Drawing_LineTypography* lineTypography, size_t startIndex, double width )
```

**Description**

Obtains the number of characters that can fit in the layout from the specified position within a limited layout width.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| lineTypography | Pointer to an [OH_Drawing_LineTypography](#oh_drawing_linetypography) object, which is obtained by calling [OH_Drawing_CreateLineTypography](#oh_drawing_createlinetypography).|
| startIndex | Start position (inclusive) for layout calculation. The value must be an integer in the range [0, total number of text characters].|
| width | Layout width. The value is a floating point number greater than 0, in px.|

**Returns**

Returns the number of characters.

### OH_Drawing_LineTypographyCreateLine()

```
OH_Drawing_TextLine* OH_Drawing_LineTypographyCreateLine (OH_Drawing_LineTypography* lineTypography, size_t startIndex, size_t count )
```

**Description**

Creates a pointer to an **OH_Drawing_TextLine** object based on the text content in a specified range.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| lineTypography | Pointer to an [OH_Drawing_LineTypography](#oh_drawing_linetypography) object, which is obtained by calling [OH_Drawing_CreateLineTypography](#oh_drawing_createlinetypography).|
| startIndex | Start position for layout calculation. The value is an integer in the range [0, total number of text characters).|
| count | Number of characters from the specified start position. The value is an integer in the range [0, total number of text characters). The sum of **startIndex** and **count** cannot be greater than the total number of text characters. You can use [OH_Drawing_LineTypographyGetLineBreak](#oh_drawing_linetypographygetlinebreak) to obtain the number of characters that can fit in the layout. If **count** is set to 0, a null pointer is returned.|

**Returns**

Returns the pointer to the **OH_Drawing_TextLine** object created.

### OH_Drawing_CreateTextTab()

```
OH_Drawing_TextTab* OH_Drawing_CreateTextTab (OH_Drawing_TextAlign alignment, float location )
```

**Description**

Creates a text tab object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| alignment | Alignment mode of the text following the tab character. The value 1 means right alignment, 2 means center alignment, and 0 or other values mean left alignment.|
| float | Alignment position of the text following the tab character. The unit is px. The minimum value is 1.0.|

**Returns**

Returns the pointer to the **OH_Drawing_TextTab** object created. If a null pointer is returned, the creation fails. A possible cause is that no memory is available.

### OH_Drawing_DestroyTextTab()

```
void OH_Drawing_DestroyTextTab (OH_Drawing_TextTab* )
```

**Description**

Releases the memory occupied by a text tab object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_TextTab | Pointer to an **OH_Drawing_TextTab** object.|

### OH_Drawing_GetTextTabAlignment()

```
OH_Drawing_TextAlign OH_Drawing_GetTextTabAlignment (OH_Drawing_TextTab* )
```

**Description**

Obtains the alignment mode of a text tab.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_TextTab | Pointer to an **OH_Drawing_TextTab** object.|

**Returns**

Returns the alignment mode. The value 1 means right alignment, 2 means center alignment, and 0 or other values mean left alignment.

### OH_Drawing_GetTextTabLocation()

```
float OH_Drawing_GetTextTabLocation (OH_Drawing_TextTab* )
```

**Description**

Obtains the location of a text tab.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_TextTab | Pointer to an **OH_Drawing_TextTab** object.|

**Returns**

Returns the position of the text tab.

### OH_Drawing_SetTypographyTextTab()

```
void OH_Drawing_SetTypographyTextTab (OH_Drawing_TypographyStyle* , OH_Drawing_TextTab* TextTab )
```

**Description**

Sets the alignment mode and location of a text tab. When the text alignment mode or ellipsis style is set, the tab does not take effect. When the tab location is less than 1.0, the tab is replaced with a space.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object.|
| OH_Drawing_TextTab | Pointer to an **OH_Drawing_TextTab** object.|

### OH_Drawing_FontGetBounds()

```
OH_Drawing_ErrorCode OH_Drawing_FontGetBounds (const OH_Drawing_Font* font, const uint16_t* glyphs, uint32_t count, OH_Drawing_Array* bounds )
```

**Description**

Obtains the rectangular bounding box for each glyph in the glyph array.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| font | Pointer to an [OH_Drawing_Font](#oh_drawing_font) object.|
| glyphs | Pointer to a glyph array.|
| count | Length of the glyph array.|
| bounds | Pointer to a rectangular bounding box array.|

**Returns**

Returns one of the following result codes: 
- **OH_DRAWING_SUCCESS** if the operation is successful. 
- **OH_DRAWING_ERROR_INVALID_PARAMETER** if **font**, **glyphs**, or **bounds** is NULL or **count** is **0**.

### OH_Drawing_FontGetPathForGlyph()

```
OH_Drawing_ErrorCode OH_Drawing_FontGetPathForGlyph (const OH_Drawing_Font* font, uint16_t glyph, OH_Drawing_Path* path )
```

**Description**

Obtains the path of a glyph.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| font | Pointer to an [OH_Drawing_Font](#oh_drawing_font) object.|
| glyph | Glyph index.|
| path | Pointer to an [OH_Drawing_Path](#oh_drawing_path) object, which is used to store the glyph path.|

**Returns**

Returns one of the following result codes:
- **OH_DRAWING_SUCCESS** if the operation is successful. 
- **OH_DRAWING_ERROR_INVALID_PARAMETER** if **font** or **path** is NULL or the specified glyph does not exist.

### OH_Drawing_RectCreateArray()

```
OH_Drawing_Array* OH_Drawing_RectCreateArray (size_t size)
```

**Description**

Creates a rectangle array object to store multiple rectangle objects.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| size | Size of the rectangle array. The value cannot exceed 65536, which is the maximum number of glyph indices.|

**Returns**

Returns the pointer to the [OH_Drawing_Array](#oh_drawing_array) object created. If the returned object pointer is null, the creation fails. Possible causes are that no memory is available or an input parameter is incorrect.

### OH_Drawing_RectGetArraySize()

```
OH_Drawing_ErrorCode OH_Drawing_RectGetArraySize (OH_Drawing_Array* rectArray, size_t* pSize )
```

**Description**

Obtains the size of a rectangle array, which is an [OH_Drawing_Array](#oh_drawing_array) object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| rectArray | Pointer to an [OH_Drawing_Array](#oh_drawing_array) object.|
| pSize | Pointer to the size_t type, which is used as an output parameter to store the size of the rectangle array.|

**Returns**

Returns one of the following result codes:
- **OH_DRAWING_SUCCESS** if the operation is successful.
- **OH_DRAWING_ERROR_INVALID_PARAMETER** if either **rectArray** or **pSize** is NULL.

### OH_Drawing_RectGetArrayElement()

```
OH_Drawing_ErrorCode OH_Drawing_RectGetArrayElement (OH_Drawing_Array* rectArray, size_t index, OH_Drawing_Rect** rect )
```

**Description**

Obtains the rectangle with the specified index in a rectangle array.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| rectArray | Pointer to an [OH_Drawing_Array](#oh_drawing_array) object.|
| index | Index of the rectangle array.|
| rect | Double pointer to [OH_Drawing_Rect](#oh_drawing_rect), which is returned to the caller as an output parameter.|

**Returns**

Returns one of the following result codes:
- **OH_DRAWING_SUCCESS** if the operation is successful.
- **OH_DRAWING_ERROR_INVALID_PARAMETER** if **rectArray** or **rect** is null or **index** is out of range.

### OH_Drawing_RectDestroyArray()

```
OH_Drawing_ErrorCode OH_Drawing_RectDestroyArray (OH_Drawing_Array* rectArray)
```

**Description**

Destroys an **OH_Drawing_Array** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| rectArray | Pointer to an [OH_Drawing_Array](#oh_drawing_array) object.|

**Returns**

Returns one of the following result codes:
- **OH_DRAWING_SUCCESS** if the operation is successful.
- **OH_DRAWING_ERROR_INVALID_PARAMETER** if **rectArray** is NULL.

### OH_Drawing_TypographyGetTextLines()

```
OH_Drawing_Array* OH_Drawing_TypographyGetTextLines (OH_Drawing_Typography* typography)
```

**Description**

Obtains the array of text lines in a typography object. This array contains one or more text line objects.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| typography | Pointer to an [OH_Drawing_Typography](#oh_drawing_typography) object.|

**Returns**

Returns the pointer to the [OH_Drawing_Array](#oh_drawing_array) object obtained.

### OH_Drawing_DestroyTextLines()

```
void OH_Drawing_DestroyTextLines (OH_Drawing_Array* lines)
```

**Description**

Releases the memory occupied by a text line array.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| lines | Pointer to an [OH_Drawing_Array](#oh_drawing_array) object.|

### OH_Drawing_DestroyTextLine()

```
void OH_Drawing_DestroyTextLine (OH_Drawing_TextLine* line)
```

**Description**

Releases the memory occupied by a text line object. This is applicable only to text line objects that have requested memory on their own and not to a particular text line object within a text line array.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| line | Pointer to an **OH_Drawing_TextLine** object.|

### OH_Drawing_GetTextLineByIndex()

```
OH_Drawing_TextLine* OH_Drawing_GetTextLineByIndex (OH_Drawing_Array* lines, size_t index )
```

**Description**

Obtains the text line object with the specified index in a text line array.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| lines | Pointer to an [OH_Drawing_Array](#oh_drawing_array) object.|
| index | Index of the text line array.|

**Returns**

Returns the pointer to the **OH_Drawing_TextLine** object obtained.

### OH_Drawing_TextLineGetGlyphCount()

```
double OH_Drawing_TextLineGetGlyphCount (OH_Drawing_TextLine* line)
```

**Description**

Obtains the number of glyphs in a text line object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| line | Pointer to an **OH_Drawing_TextLine** object.|

**Returns**

Returns the number of glyphs in the text line object.

### OH_Drawing_TextLineGetTextRange()

```
void OH_Drawing_TextLineGetTextRange (OH_Drawing_TextLine* line, size_t* start, size_t* end )
```

**Description**

Obtains the range of the text in a text line object in the entire paragraph.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| line | Pointer to an **OH_Drawing_TextLine** object.|
| start | Pointer to the start of the range.|
| end | Pointer to the end of the range.|

### OH_Drawing_TextLineGetGlyphRuns()

```
OH_Drawing_Array* OH_Drawing_TextLineGetGlyphRuns (OH_Drawing_TextLine* line)
```

**Description**

Obtains the array of glyph runs in a text line object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| line | Pointer to an **OH_Drawing_TextLine** object.|

**Returns**

Returns the pointer to the [OH_Drawing_Array](#oh_drawing_array), which holds multiple **OH_Drawing_Run** objects.

### OH_Drawing_DestroyRuns()

```
void OH_Drawing_DestroyRuns (OH_Drawing_Array* runs)
```

**Description**

Releases the memory occupied by a glyph run array.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| runs | Pointer to an [OH_Drawing_Array](#oh_drawing_array), which holds multiple **OH_Drawing_Run** objects.|

### OH_Drawing_GetRunByIndex()

```
OH_Drawing_Run* OH_Drawing_GetRunByIndex (OH_Drawing_Array* runs, size_t index )
```

**Description**

Obtains the glyph run object with the specified index in a glyph run array.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| runs | Pointer to an [OH_Drawing_Array](#oh_drawing_array), which holds multiple **OH_Drawing_Run** objects.|
| index | Index of the glyph run array.|

**Returns**

Returns the pointer to the **OH_Drawing_Run** object obtained.

### OH_Drawing_TextLinePaint()

```
void OH_Drawing_TextLinePaint (OH_Drawing_TextLine* line, OH_Drawing_Canvas* canvas, double x, double y )
```

**Description**

Paints a text line on the canvas with the coordinate point (x, y) as the upper left corner.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| line | Pointer to an **OH_Drawing_TextLine** object.|
| canvas | Pointer to an [OH_Drawing_Canvas](#oh_drawing_canvas) object.|
| x | Horizontal coordinate of the upper left corner, in px.|
| y | Vertical coordinate of the upper left corner, in px.|

### OH_Drawing_TextLineCreateTruncatedLine()

```
OH_Drawing_TextLine* OH_Drawing_TextLineCreateTruncatedLine (OH_Drawing_TextLine* line, double width, int mode, const char* ellipsis )
```

**Description**

Creates a truncated text line object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| line | Pointer to an **OH_Drawing_TextLine** object.|
| width | Line width after truncation.|
| mode | Truncation type. The value is an enumerated value of [OH_Drawing_EllipsisModal](#oh_drawing_ellipsismodal). Currently, only **ELLIPSIS_MODAL_HEAD** and **ELLIPSIS_MODAL_TAIL** are supported.|
| ellipsis | Pointer to the string used to mark a truncation.|

**Returns**

Returns the pointer to the **OH_Drawing_TextLine** object created.

### OH_Drawing_TextLineGetTypographicBounds()

```
double OH_Drawing_TextLineGetTypographicBounds (OH_Drawing_TextLine* line, double* ascent, double* descent, double* leading )
```

**Description**

Obtains the typographic boundary of a text line object. The typographic boundary is related to the font and font size used for typography, but not the characters within the text. For example, for the string " a b " (which has a space before "a" and a space after "b"), the typographic boundary encompasses the spaces at the beginning and end. For the strings "j" and "E", the typographic boundaries are the same, indicating that they are irrelevant to specific characters.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| line | Pointer to an **OH_Drawing_TextLine** object. height = ascent + descent + leading.|
| ascent | Pointer to the ascent of the text line object.|
| descent | Pointer to the descent of the text line object.|
| leading | Pointer to the leading of the text line object.|

**Returns**

Returns the total width of the layout boundary.

### OH_Drawing_TextLineGetImageBounds()

```
OH_Drawing_Rect* OH_Drawing_TextLineGetImageBounds (OH_Drawing_TextLine* line)
```

**Description**

Obtains the image boundary of a text line object.

The image boundary, equivalent to a visual boundary, is related to the font, font size, and characters. For example, for the string " a b " (which has a space before "a" and a space after "b"), only "a b" are visible to users, and therefore the image boundary does not include these spaces at the beginning and end. For the strings "j" and "E", their image boundaries are different. Specifically, the width of the boundary for "j" is narrower than that for "E", and the height of the boundary for "j" is taller than that for "E".

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| line | Pointer to an **OH_Drawing_TextLine** object.|

**Returns**

Returns the pointer to the [OH_Drawing_Rect](#oh_drawing_rect) of the text line object.

### OH_Drawing_TextLineGetTrailingSpaceWidth()

```
double OH_Drawing_TextLineGetTrailingSpaceWidth (OH_Drawing_TextLine* line)
```

**Description**

Obtains the width of the spaces at the end of a text line object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| line | Pointer to an **OH_Drawing_TextLine** object.|

**Returns**

Returns the pointer to the width of the spaces.

### OH_Drawing_TextLineGetStringIndexForPosition()

```
int32_t OH_Drawing_TextLineGetStringIndexForPosition (OH_Drawing_TextLine* line, OH_Drawing_Point* point )
```

**Description**

Obtains the index of a character at the specified position in a text line object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| line | Pointer to an **OH_Drawing_TextLine** object.|
| point | Pointer to the position, which is an [OH_Drawing_Point](#oh_drawing_point) object.|

**Returns**

Returns the index of the character. For example, for the string "abc", the index of "a" is 0, the index of "b" is 1, and the index of "c" is 2. If the specified position is at "a", then **0** is returned.

### OH_Drawing_TextLineGetOffsetForStringIndex()

```
double OH_Drawing_TextLineGetOffsetForStringIndex (OH_Drawing_TextLine* line, int32_t index )
```

**Description**

Obtains the offset of a character with the specified index in a text line object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| line | Pointer to an **OH_Drawing_TextLine** object.|
| index | Index of the character.|

**Returns**

Returns the offset.

### OH_Drawing_TextLineEnumerateCaretOffsets()

```
void OH_Drawing_TextLineEnumerateCaretOffsets (OH_Drawing_TextLine* line, Drawing_CaretOffsetsCallback callback )
```

**Description**

Enumerates the offset and index of each character in a text line object and passes them to a custom callback function. You can use the offset and index array for other operations.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| line | Pointer to an **OH_Drawing_TextLine** object.|
| callback | User-defined function, which is [Drawing_CaretOffsetsCallback](#drawing_caretoffsetscallback).|

### OH_Drawing_TextLineGetAlignmentOffset()

```
double OH_Drawing_TextLineGetAlignmentOffset (OH_Drawing_TextLine* line, double alignmentFactor, double alignmentWidth )
```

**Description**

Obtains the offset of a text line object after alignment based on the alignment factor and alignment width.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| line | Pointer to an **OH_Drawing_TextLine** object.|
| alignmentFactor | Alignment factor, which determines how text is aligned. A value less than or equal to 0.0 means that the text is left-aligned; a value between 0.0 and 0.5 means that the text is slightly left-aligned; the value 0.5 means that is text is centered; a value between 0.5 and 1 means that the text is slightly right-aligned; a value greater than or equal to 1.0 means that the text is right-aligned.|
| alignmentWidth | Alignment width, that is, the offset of the lower right corner of the text line object relative to the start position. If the specified alignment width is less than the actual width of the text line object, **0** is returned.|

**Returns**

Returns the offset obtained.

### OH_Drawing_AddTextStyleDecoration()

```
void OH_Drawing_AddTextStyleDecoration (OH_Drawing_TextStyle* , int  )
```

**Description**

Adds the decoration for a text style. Multiple decoration lines can be displayed.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_TextStyle | Pointer to an [OH_Drawing_TextStyle](#oh_drawing_textstyle) object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle).|
| int | Decoration to add. The value **1** means to add an underline, **2** means to add an overline, and 4 means to add a strikethrough. You can add various text decorations in a single operation using bitwise OR. If you set decoration styles that are not defined in [OH_Drawing_TextDecoration](#oh_drawing_textdecoration), the existing decorations remain unchanged.|

### OH_Drawing_RemoveTextStyleDecoration()

```
void OH_Drawing_RemoveTextStyleDecoration (OH_Drawing_TextStyle* , int  )
```

**Description**

Removes the decoration for a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_TextStyle | Pointer to an [OH_Drawing_TextStyle](#oh_drawing_textstyle) object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle).|
| int | Decoration to remove. The value **1** means to remove an underline, **2** means to remove an overline, and 4 means to remove a strikethrough. You can remove various text decorations in a single operation using bitwise OR.  If you set decoration styles that are not defined in [OH_Drawing_TextDecoration](#oh_drawing_textdecoration), the existing decorations remain unchanged.|

### OH_Drawing_FontGetTextPath()

```
OH_Drawing_ErrorCode OH_Drawing_FontGetTextPath (const OH_Drawing_Font* font, const void* text, size_t byteLength, OH_Drawing_TextEncoding encoding, float x, float y, OH_Drawing_Path* path )
```

**Description**

Obtains the text outline path.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| font | Pointer to an [OH_Drawing_Font](#oh_drawing_font) object.|
| text | Pointer to the text string.|
| byteLength | Length of the text path. If the length is greater than the length of the text string, undefined behavior occurs.|
| encoding | Text encoding format. UTF-8, UTF-16, UTF-32, and glyph indices are supported.|
| x | X coordinate of the text in the drawing area, with the origin as the start point.|
| y | Y coordinate of the text in the drawing area, with the origin as the start point.|
| path | Pointer to the text outline path.|

**Returns**

Returns one of the following error codes: **IMAGE_RESULT_SUCCESS** if the operation is successful. **OH_DRAWING_ERROR_INVALID_PARAMETER** if any of **font**, **text**, and **path** is a null pointer.

### OH_Drawing_GetDrawingArraySize()

```
size_t OH_Drawing_GetDrawingArraySize (OH_Drawing_Array* drawingArray)
```

**Description**

Obtains the number of objects in an [OH_Drawing_Array](#oh_drawing_array).

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| drawingArray | Pointer to an [OH_Drawing_Array](#oh_drawing_array) object.|

**Returns**

Returns the number of objects in the array.


### OH_Drawing_GetRunStringIndices()

```
OH_Drawing_Array* OH_Drawing_GetRunStringIndices (OH_Drawing_Run* run, int64_t start, int64_t length )
```

**Description**

Obtains an array of character indices for glyphs within a specified range of a run, where the indices are offsets relative to the entire paragraph.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| run | Pointer to an **OH_Drawing_Run** object.|
| start | Start position in the run. If a negative number is passed, a null pointer is returned.|
| length | Length of the range in the run. If the length is 0, all character indexes of the run are obtained. If the length is less than 0, a null pointer is returned.|

**Returns**

Returns the character index array.


### OH_Drawing_GetRunStringIndicesByIndex()

```
uint64_t OH_Drawing_GetRunStringIndicesByIndex (OH_Drawing_Array* stringIndices, size_t index )
```

**Description**

Obtains character indices of glyphs in a run by index.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| stringIndices | Pointer to a character index array.|
| index | Index of the character index array.|

**Returns**

Returns the character indices.


### OH_Drawing_DestroyRunStringIndices()

```
void OH_Drawing_DestroyRunStringIndices (OH_Drawing_Array* stringIndices)
```

**Description**

Releases the pointer to a character index array object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| stringIndices | Pointer to a character index array.|


### OH_Drawing_GetRunStringRange()

```
void OH_Drawing_GetRunStringRange (OH_Drawing_Run* run, uint64_t* location, uint64_t* length )
```

**Description**

Obtains the range of glyphs generated by a run.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| run | Pointer to an **OH_Drawing_Run** object.|
| location | Start position of the range in the run, which is an offset relative to the entire paragraph.|
| length | Length of the range.|


### OH_Drawing_GetRunTypographicBounds()

```
float OH_Drawing_GetRunTypographicBounds (OH_Drawing_Run* run, float* ascent, float* descent, float* leading )
```

**Description**

Obtains the typographic boundary of a run.

The typographic boundary is related to the font and font size used for typography, but not the characters within the text.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| run | Pointer to an **OH_Drawing_Run** object.|
| ascent | Distance from the top of the tallest character to the baseline in the run.|
| descent | Distance from the bottom of the lowest character to the baseline in the run.|
| leading | Vertical space between lines in the run.|

**Returns**

Returns the layout width of the run.


### OH_Drawing_RunPaint()

```
void OH_Drawing_RunPaint (OH_Drawing_Canvas* canvas, OH_Drawing_Run* run, double x, double y )
```

**Description**

Paints the text contained in a run on the canvas.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| canvas | Pointer to an [OH_Drawing_Canvas](#oh_drawing_canvas) object.|
| run | Pointer to an **OH_Drawing_Run** object.|
| x | X coordinate of the run.|
| y | Y coordinate of the run.|


### OH_Drawing_GetRunImageBounds()

```
OH_Drawing_Rect* OH_Drawing_GetRunImageBounds (OH_Drawing_Run* run)
```

**Description**

Obtains the image boundary of a run.

The image boundary is related to characters and is equivalent to the visual boundary.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| run | Pointer to an **OH_Drawing_Run** object.|

**Returns**

Returns the pointer to an [OH_Drawing_Rect](#oh_drawing_rect) object, which describes the image boundary of the run.


### OH_Drawing_DestroyRunImageBounds()

```
void OH_Drawing_DestroyRunImageBounds (OH_Drawing_Rect* rect)
```

**Description**

Releases the pointer to an image boundary object of a run.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| rect | Pointer to the image boundary, which is an [OH_Drawing_Rect](#oh_drawing_rect) object.|


### OH_Drawing_GetRunGlyphs()

```
OH_Drawing_Array* OH_Drawing_GetRunGlyphs (OH_Drawing_Run* run, int64_t start, int64_t length )
```

**Description**

Obtains an array of glyphs within the specified range of a run.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| run | Pointer to an **OH_Drawing_Run** object.|
| start | Start position of the run. If a negative number is passed, a null pointer is returned.|
| length | Length of the range in the run. If the length is 0, all character indices of the run are obtained. If the length is less than 0, a null pointer is returned.|

**Returns**

Returns the pointer to an [OH_Drawing_Array](#oh_drawing_array) object, which holds the glyphs.


### OH_Drawing_GetRunGlyphsByIndex()

```
uint16_t OH_Drawing_GetRunGlyphsByIndex (OH_Drawing_Array* glyphs, size_t index )
```

**Description**

Obtains individual glyphs in a run by index.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| glyphs | Pointer to the glyph array, which is an [OH_Drawing_Array](#oh_drawing_array) object.|
| index | Index of the glyph array.|

**Returns**

Returns the individual glyphs.


### OH_Drawing_DestroyRunGlyphs()

```
void OH_Drawing_DestroyRunGlyphs (OH_Drawing_Array* glyphs)
```

**Description**

Releases the pointer to a glyph array in a run.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| glyphs | Pointer to the glyph array, which is an [OH_Drawing_Array](#oh_drawing_array) object.|

### OH_Drawing_GetRunPositions()

```
OH_Drawing_Array* OH_Drawing_GetRunPositions (OH_Drawing_Run* run, int64_t start, int64_t length )
```

**Description**

Obtains the positions of glyphs within the specified range of a run.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| run | Pointer to an **OH_Drawing_Run** object.|
| start | Start position in the run. If a negative number is passed, a null pointer is returned.|
| length | Length of the range in the run. If the length is 0, all character indices of the run are obtained. If the length is less than 0, a null pointer is returned.|

**Returns**

Returns the pointer to an [OH_Drawing_Array](#oh_drawing_array) object, which holds the glyph positions.

### OH_Drawing_GetRunPositionsByIndex()

```
OH_Drawing_Point* OH_Drawing_GetRunPositionsByIndex (OH_Drawing_Array* positions, size_t index )
```

**Description**

Obtains the positions of individual glyphs in a run by index.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| positions | Pointer to the glyph position array, which is an [OH_Drawing_Array](#oh_drawing_array) object.|
| index | Index of the glyph position array in the run.|

**Returns**

Returns the pointer to an [OH_Drawing_Point](#oh_drawing_point) object, which holds the positions of individual glyphs in the run.


### OH_Drawing_DestroyRunPositions()

```
void OH_Drawing_DestroyRunPositions (OH_Drawing_Array* positions)
```

**Description**

Releases the pointer to a glyph position array in a run.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| positions | Pointer to the glyph position array, which is an [OH_Drawing_Array](#oh_drawing_array) object.|

### OH_Drawing_GetRunGlyphCount()

```
uint32_t OH_Drawing_GetRunGlyphCount (OH_Drawing_Run* run)
```

**Description**

Obtains the number of glyphs in a run.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| run | Pointer to an **OH_Drawing_Run** object.|

**Returns**

Returns the number of glyphs.

### OH_Drawing_MatchFontDescriptors()

```
OH_Drawing_FontDescriptor* OH_Drawing_MatchFontDescriptors (OH_Drawing_FontDescriptor* , size_t*  )
```

**Description**

Obtains all system font descriptors that match a font descriptor. In the [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) struct, the **path** field is not used for matching, and other fields are valid only when they are not set to their default values. If all fields in [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) are set to their default values, all system font descriptors are obtained. If no matching is found, NULL is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) | Pointer to [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md). You are advised to use [OH_Drawing_CreateFontDescriptor](#oh_drawing_createfontdescriptor) to obtain a valid [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) instance. If you create a [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) instance, ensure that the fields that are not used for matching are set to their default values.|
| size_t                                                       | Pointer to the number of elements in the array.                                  |

**Returns**

Returns an [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) array, which must be released by calling [OH_Drawing_DestroyFontDescriptors](#oh_drawing_destroyfontdescriptors).

### OH_Drawing_DestroyFontDescriptors()

```
void OH_Drawing_DestroyFontDescriptors (OH_Drawing_FontDescriptor* , size_t  )
```

**Description**

Releases an array of [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) objects.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) | Pointer to an array of [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) objects.|
| size_t | Number of [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) objects in the array.|

### OH_Drawing_DestroySystemFontFullNames()

```
void OH_Drawing_DestroySystemFontFullNames (OH_Drawing_Array* )
```

**Description**

Releases the memory occupied by the font name array obtained by font type.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Array | Pointer to an [OH_Drawing_Array](#oh_drawing_array) that holds the font names.|

### OH_Drawing_GetSystemFontFullNameByIndex()

```
const OH_Drawing_String* OH_Drawing_GetSystemFontFullNameByIndex (OH_Drawing_Array* , size_t  )
```

**Description**

Obtains the font name with the specified index in the font name array.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Array | Pointer to an [OH_Drawing_Array](#oh_drawing_array) that holds the font names.|
| size_t | Index of the font in the array.|

**Returns**

Returns the pointer to the font name, which is an [OH_Drawing_String](_o_h___drawing___string.md) object.

### OH_Drawing_GetSystemFontFullNamesByType()

```
OH_Drawing_Array* OH_Drawing_GetSystemFontFullNamesByType (OH_Drawing_SystemFontType )
```

**Description**

Obtains an array of font names by font type.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_SystemFontType | Font type, which is defined in [OH_Drawing_SystemFontType](#oh_drawing_systemfonttype).|

**Returns**

Returns the pointer to an [OH_Drawing_Array](#oh_drawing_array), which holds the font names.

### OH_Drawing_GetFontDescriptorByFullName()

```
OH_Drawing_FontDescriptor* OH_Drawing_GetFontDescriptorByFullName (const OH_Drawing_String* , OH_Drawing_SystemFontType  )
```

**Description**

Obtains a font descriptor based on the font name and type. System fonts, style fonts, and user-installed fonts are supported. A font descriptor is a data structure that describes font features. It contains details of the font appearance and properties.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| [OH_Drawing_String](_o_h___drawing___string.md) | Pointer to the font name, which is [OH_Drawing_String](_o_h___drawing___string.md).|
| OH_Drawing_SystemFontType | Font type, which is defined in [OH_Drawing_SystemFontType](#oh_drawing_systemfonttype).|

**Returns**

Returns the pointer to an [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) object.

### OH_Drawing_TypefaceCreateFromFileWithArguments()

```
OH_Drawing_Typeface* OH_Drawing_TypefaceCreateFromFileWithArguments (const char* path, const OH_Drawing_FontArguments* fontArguments )
```

**Description**

Creates an **OH_Drawing_Typeface** object with font arguments through a file. If the **OH_Drawing_Typeface** object does not support the variation described in the font arguments, this function creates an **OH_Drawing_Typeface** object with the default font arguments. In this case, this function provides the same capability as [OH_Drawing_TypefaceCreateFromFile](#oh_drawing_typefacecreatefromfile).

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| path | Pointer to the file path.|
| fontArguments | Pointer to an [OH_Drawing_FontArguments](#oh_drawing_fontarguments) object.|

**Returns**

Returns the pointer to the [OH_Drawing_Typeface](#oh_drawing_typeface) object created. If a null pointer is returned, the creation fails. Possible causes are that no memory is available, the passed-in **path** or **fontArguments** is NULL, or the path is invalid.


### OH_Drawing_TypefaceCreateFromCurrent()

```
OH_Drawing_Typeface* OH_Drawing_TypefaceCreateFromCurrent (const OH_Drawing_Typeface* current, const OH_Drawing_FontArguments* fontArguments )
```

**Description**

Creates an **OH_Drawing_Typeface** object with font arguments based on an existing **OH_Drawing_Typeface** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| current | Pointer to an [OH_Drawing_Typeface](#oh_drawing_typeface) object.|
| fontArguments | Pointer to an [OH_Drawing_FontArguments](#oh_drawing_fontarguments) object.|

**Returns**

Returns the pointer to the [OH_Drawing_Typeface](#oh_drawing_typeface) object created. If a null pointer is returned, the creation fails. Possible causes are that no memory is available, the passed-in **path** or **fontArguments** is NULL, or the existing **OH_Drawing_FontArguments** object does not support the variation described in the font arguments.


### OH_Drawing_FontArgumentsAddVariation()

```
OH_Drawing_ErrorCode OH_Drawing_FontArgumentsAddVariation (OH_Drawing_FontArguments* fontArguments, const char* axis, float value )
```

**Description**

Adds a variation to an **OH_Drawing_FontArguments** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| fontArguments | Pointer to an [OH_Drawing_FontArguments](#oh_drawing_fontarguments) object.|
| axis | Pointer to the label of the variation. The value must contain four ASCII characters. The supported labels depend on the loaded font file. For example, **'wght'** is the font weight label.|
| value | Value of the variation label.|

**Returns**

Returns one of the following result codes:
- **OH_DRAWING_SUCCESS** if the operation is successful.
- **OH_DRAWING_ERROR_INVALID_PARAMETER** if either **fontArguments** or **axis** is NULL or the length of **axis** is not 4.


### OH_Drawing_FontArgumentsCreate()

```
OH_Drawing_FontArguments* OH_Drawing_FontArgumentsCreate (void)
```

**Description**

Creates an **OH_Drawing_FontArguments** object. The font arguments are used to create an **OH_Drawing_Typeface** object with custom attributes.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 13

**Returns**

Returns the pointer to the **OH_Drawing_FontArguments** object created.


### OH_Drawing_FontArgumentsDestroy()

```
OH_Drawing_ErrorCode OH_Drawing_FontArgumentsDestroy (OH_Drawing_FontArguments* fontArguments)
```

**Description**

Destroys an **OH_Drawing_FontArguments** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| fontArguments | Pointer to an [OH_Drawing_FontArguments](#oh_drawing_fontarguments) object.|

**Returns**

Returns one of the following result codes:
- **OH_DRAWING_SUCCESS** if the operation is successful.
- **OH_DRAWING_ERROR_INVALID_PARAMETER** if **fontArguments** is NULL.


### OH_Drawing_TypographyGetLongestLineWithIndent()

```
double OH_Drawing_TypographyGetLongestLineWithIndent (OH_Drawing_Typography* )
```

**Description**

Obtains the width of the longest line, including its indentation. You are advised to round up the return value in actual use. If the text content is empty, **0.0** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Typography | Pointer to an [OH_Drawing_Typography](#oh_drawing_typography) object, which is obtained by calling [OH_Drawing_CreateTypography](#oh_drawing_createtypography).|

**Returns**

Returns the width of the longest line, including its indentation, in px.



### OH_Drawing_RecordCmdDestroy()

```
OH_Drawing_ErrorCode OH_Drawing_RecordCmdDestroy (OH_Drawing_RecordCmd* recordCmd)
```

**Description**

Destroys an **OH_Drawing_RecordCmd** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| recordCmd | Pointer to an [OH_Drawing_RecordCmd](#oh_drawing_recordcmd) object.|

**Returns**

Returns one of the following result codes:
- **OH_DRAWING_SUCCESS** if the operation is successful.
- **OH_DRAWING_ERROR_INVALID_PARAMETER** if **recordCmd** is NULL.


### OH_Drawing_RecordCmdUtilsBeginRecording()

```
OH_Drawing_ErrorCode OH_Drawing_RecordCmdUtilsBeginRecording (OH_Drawing_RecordCmdUtils* recordCmdUtils, int32_t width, int32_t height, OH_Drawing_Canvas** canvas )
```

**Description**

Starts recording. This function must be used in pair with [OH_Drawing_RecordCmdUtilsFinishRecording](#oh_drawing_recordcmdutilsfinishrecording).

The **OH_Drawing_RecordCmdUtils** object generates a canvas object of the recording type and calls the interface of the drawing object to record all drawing commands.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| recordCmdUtils | Pointer to an [OH_Drawing_RecordCmdUtils](#oh_drawing_recordcmdutils) object.|
| width | Width of the canvas.|
| height | Height of the canvas.|
| canvas | Double pointer to the [OH_Drawing_Canvas](#oh_drawing_canvas) object. You do not need to release this pointer. This object does not support nested calling of [OH_Drawing_CanvasDrawRecordCmd](#oh_drawing_canvasdrawrecordcmd).|

**Returns**

Returns one of the following result codes:
- **OH_DRAWING_SUCCESS** if the operation is successful.
- **OH_DRAWING_ERROR_INVALID_PARAMETER** if either **recordCmdUtils** or **canvas** is NULL.
- **OH_DRAWING_ERROR_INVALID_PARAMETER** if either **width** or **height** is less than 0.
- **OH_DRAWING_ERROR_ALLOCATION_FAILED** if the system memory is insufficient.


### OH_Drawing_RecordCmdUtilsCreate()

```
OH_Drawing_RecordCmdUtils* OH_Drawing_RecordCmdUtilsCreate (void )
```

**Description**

Creates an **OH_Drawing_RecordCmdUtils** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 13

**Returns**

Returns the pointer to the **OH_Drawing_RecordCmdUtils** object created.


### OH_Drawing_RecordCmdUtilsDestroy()

```
OH_Drawing_ErrorCode OH_Drawing_RecordCmdUtilsDestroy (OH_Drawing_RecordCmdUtils* recordCmdUtils)
```

**Description**

Destroys an **OH_Drawing_RecordCmdUtils** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| recordCmdUtils | Pointer to an [OH_Drawing_RecordCmdUtils](#oh_drawing_recordcmdutils) object.|

**Returns**

Returns one of the following result codes:
- **OH_DRAWING_SUCCESS** if the operation is successful.
- **OH_DRAWING_ERROR_INVALID_PARAMETER** if **recordCmdUtils** is NULL.


### OH_Drawing_RecordCmdUtilsFinishRecording()

```
OH_Drawing_ErrorCode OH_Drawing_RecordCmdUtilsFinishRecording (OH_Drawing_RecordCmdUtils* recordCmdUtils, OH_Drawing_RecordCmd** recordCmd )
```

**Description**

Ends recording. This function must be called after [OH_Drawing_RecordCmdUtilsBeginRecording](#oh_drawing_recordcmdutilsbeginrecording).

The **OH_Drawing_RecordCmdUtils** object ends recording and stores the drawing commands recorded by the canvas object of the recording type into the generated [OH_Drawing_RecordCmdUtilsBeginRecording](#oh_drawing_recordcmdutilsbeginrecording) object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| recordCmdUtils | Pointer to an [OH_Drawing_RecordCmdUtils](#oh_drawing_recordcmdutils) object.|
| recordCmd | Double pointer to the [OH_Drawing_RecordCmd](#oh_drawing_recordcmd) object. You need to call [OH_Drawing_CanvasDrawRecordCmd](#oh_drawing_canvasdrawrecordcmd) to draw the object, and call [OH_Drawing_RecordCmdDestroy](#oh_drawing_recordcmddestroy) to release it.|

**Returns**

Returns one of the following result codes:
- **OH_DRAWING_SUCCESS** if the operation is successful.
- **OH_DRAWING_ERROR_INVALID_PARAMETER** if either **recordCmdUtils** or **recordCmd** is NULL.
- **OH_DRAWING_ERROR_ALLOCATION_FAILED** if the system memory is insufficient.


### OH_Drawing_CanvasDrawRecordCmd()

```
OH_Drawing_ErrorCode OH_Drawing_CanvasDrawRecordCmd (OH_Drawing_Canvas* canvas, OH_Drawing_RecordCmd* recordCmd )
```

**Description**

Draws an **OH_Drawing_RecordCmd** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| canvas | Pointer to an [OH_Drawing_Canvas](#oh_drawing_canvas) object. Only a canvas of the recording type is supported.|
| recordCmd | Pointer to the [OH_Drawing_RecordCmd](#oh_drawing_recordcmd) object.|

**Returns**

Returns one of the following result codes:
- **OH_DRAWING_SUCCESS** if the operation is successful.
- **OH_DRAWING_ERROR_INVALID_PARAMETER** if either **canvas** or **recordCmd** is NULL.



### OH_Drawing_TypographyDestroyTextBox()

```
void OH_Drawing_TypographyDestroyTextBox (OH_Drawing_TextBox* )
```

**Description**

Releases the memory occupied by a text box.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_TextBox | Pointer to an [OH_Drawing_TextBox](#oh_drawing_textbox) object.|


### OH_Drawing_SetTextShadow()

```
void OH_Drawing_SetTextShadow (OH_Drawing_TextShadow* shadow, uint32_t color, OH_Drawing_Point* offset, double blurRadius )
```

**Description**

Sets a text shadow.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_TextShadow | Pointer to an [OH_Drawing_TextShadow](#oh_drawing_textshadow) object, which is obtained by calling [OH_Drawing_CreateTextShadow](#oh_drawing_createtextshadow).|
| color | Color of the text shadow. For example, if the input parameter is 0xAABBCCDD, AA indicates opacity, BB indicates the value of the red component, CC indicates the value of the green component, and DD indicates the value of the blue component.|
| OH_Drawing_Point | Pointer to an [OH_Drawing_Point](#oh_drawing_point) object, which is the position of the text shadow relative to the text.|
| blurRadius | Blur radius. The value is a floating point number and has no unit. The value **0.0** means that there is no blur effect.|



### OH_Drawing_CanvasDrawSingleCharacter()

```
OH_Drawing_ErrorCode OH_Drawing_CanvasDrawSingleCharacter (OH_Drawing_Canvas* canvas, const char* str, const OH_Drawing_Font* font, float x, float y )
```

**Description**

Draws a single character. If the typeface of the current font does not support the character to draw, the system typeface is used to draw the character.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| canvas | Pointer to an [OH_Drawing_Canvas](#oh_drawing_canvas) object.|
| str | Pointer to the single character to draw. A string can be passed in, but only the first character in the string is parsed and drawn in UTF-8 encoding.|
| font | Pointer to an [OH_Drawing_Font](#oh_drawing_font) object.|
| x | X coordinate of the left point of the character baseline.|
| y | Y coordinate of the left point of the character baseline.|

**Returns**

Returns one of the following result codes:
- **OH_DRAWING_SUCCESS** if the operation is successful.
- **OH_DRAWING_ERROR_INVALID_PARAMETER** if at least one of the parameters **canvas**, **str**, or **font** is NULL, or the length of **str** is **0**.



### OH_Drawing_FontMeasureSingleCharacter()

```
OH_Drawing_ErrorCode OH_Drawing_FontMeasureSingleCharacter (const OH_Drawing_Font* font, const char* str, float* textWidth )
```

**Description**

Measures the width of a single character. If the typeface of the current font does not support the character to measure, the system typeface is used to measure the character width.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| font | Pointer to an [OH_Drawing_Font](#oh_drawing_font) object.|
| str | Pointer to the single character to measure. A string can be passed in, but only the first character in the string is parsed and measured in UTF-8 encoding.|
| textWidth | Pointer to the character width obtained.|

**Returns**

Returns one of the following result codes:
- **OH_DRAWING_SUCCESS** if the operation is successful.
- **OH_DRAWING_ERROR_INVALID_PARAMETER** if at least one of the parameters **font**, **str**, or **textWidth** is NULL, or the length of **str** is **0**.


 
### OH_Drawing_TypographyPaintOnPath()

```
void OH_Drawing_TypographyPaintOnPath (OH_Drawing_Typography* , OH_Drawing_Canvas* , OH_Drawing_Path* , double , double  )
```

**Description**

Draws text along a path.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Typography | Pointer to an **OH_Drawing_Typography** object, which is obtained by calling [OH_Drawing_CreateTypography](#oh_drawing_createtypography).|
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object, which is obtained by calling [OH_Drawing_CanvasCreate](#oh_drawing_canvascreate).|
| OH_Drawing_Path | Pointer to an **OH_Drawing_Path** object, which is obtained by calling [OH_Drawing_PathCreate](#oh_drawing_pathcreate).|
| double | Horizontal offset along the path direction. A positive number indicates a position that is ahead along the path from its start point, and a negative number indicates a position that is behind from the start point.|
| double | Vertical offset along the path direction. A positive number indicates a position on the left side of the path, and a negative number indicates a position on the right side of the path.|


### OH_Drawing_RoundRectOffset()

```
OH_Drawing_ErrorCode OH_Drawing_RoundRectOffset (OH_Drawing_RoundRect* roundRect, float dx, float dy )
```

**Description**

Translates a rounded rectangle by an offset along the X axis and Y axis.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| roundRect | Pointer to an [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) object.|
| dx | X offset.|
| dy | Y offset.|

**Returns**

Returns one of the following result codes:
- **OH_DRAWING_SUCCESS** if the operation is successful.
- **OH_DRAWING_ERROR_INVALID_PARAMETER** if **roundRect** is NULL.


### OH_Drawing_PointGetX()

```
OH_Drawing_ErrorCode OH_Drawing_PointGetX (const OH_Drawing_Point* point, float* x )
```

**Description**

Obtains the X coordinate of a point.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| point | Pointer to an [OH_Drawing_Point](#oh_drawing_point) object.|
| x | Pointer to the X coordinate.|

**Returns**

Returns one of the following result codes:
- **OH_DRAWING_SUCCESS** if the operation is successful.
- **OH_DRAWING_ERROR_INVALID_PARAMETER** if either **point** or **x** is NULL.


### OH_Drawing_PointGetY()

```
OH_Drawing_ErrorCode OH_Drawing_PointGetY (const OH_Drawing_Point* point, float* y )
```

**Description**

Obtains the Y coordinate of a point.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| point | Pointer to an [OH_Drawing_Point](#oh_drawing_point) object.|
| y | Pointer to the Y coordinate.|

**Returns**

Returns one of the following result codes: 
- **OH_DRAWING_SUCCESS** if the operation is successful.
- **OH_DRAWING_ERROR_INVALID_PARAMETER** if either **point** or **y** is NULL.


### OH_Drawing_PointSet()

```
OH_Drawing_ErrorCode OH_Drawing_PointSet (OH_Drawing_Point* point, float x, float y )
```

**Description**

Sets the X and Y coordinates of a point.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| point | Pointer to an [OH_Drawing_Point](#oh_drawing_point) object.|
| x | Pointer to the X coordinate.|
| y | Pointer to the Y coordinate.|

**Returns**

Returns one of the following result codes:
- **OH_DRAWING_SUCCESS** if the operation is successful.
- **OH_DRAWING_ERROR_INVALID_PARAMETER** if **point** is NULL.


### OH_Drawing_FontMeasureText()

```
OH_Drawing_ErrorCode OH_Drawing_FontMeasureText (const OH_Drawing_Font* font, const void* text, size_t byteLength, OH_Drawing_TextEncoding encoding, OH_Drawing_Rect* bounds, float* textWidth )
```

**Description**

Obtains the text width and bounding box.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| font | Pointer to an [OH_Drawing_Font](#oh_drawing_font) object.|
| text | Pointer to the text.|
| byteLength | Length of the text, in bytes.|
| encoding | Encoding type of the text.|
| bounds | Pointer to the bounding box. The value can be NULL.|
| textWidth | Pointer to the text width.|

**Returns**

Returns one of the following result codes: 
- **OH_DRAWING_SUCCESS** if the operation is successful. 
- **OH_DRAWING_ERROR_INVALID_PARAMETER** if at least one of the parameters **font**, **text**, and **textWidth** is NULL, or **byteLength** is **0**.


### OH_Drawing_CanvasClipRegion()

```
OH_Drawing_ErrorCode OH_Drawing_CanvasClipRegion (OH_Drawing_Canvas* canvas, const OH_Drawing_Region* region, OH_Drawing_CanvasClipOp clipOp )
```

**Description**

Clips a rectangle.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| canvas | Pointer to an [OH_Drawing_Canvas](#oh_drawing_canvas) object.|
| region | Pointer to an [OH_Drawing_Region](#oh_drawing_region) object.|
| clipOp | Clip mode.|

**Returns**

Returns one of the following result codes:
- **OH_DRAWING_SUCCESS** if the operation is successful.
- **OH_DRAWING_ERROR_INVALID_PARAMETER** if either **canvas** or **region** is NULL.
- **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** if **clipOp** is not set to one of the enumerated values.


### OH_Drawing_CanvasDrawColor()

```
OH_Drawing_ErrorCode OH_Drawing_CanvasDrawColor (OH_Drawing_Canvas* canvas, uint32_t color, OH_Drawing_BlendMode blendMode )
```

**Description**

Fills the entire canvas with the specified color and blend mode.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| canvas | Pointer to an [OH_Drawing_Canvas](#oh_drawing_canvas) object.|
| color | Color.|
| blendMode | Blend mode.|

**Returns**

Returns one of the following result codes: 
- **OH_DRAWING_SUCCESS** if the operation is successful.
- **OH_DRAWING_ERROR_INVALID_PARAMETER** if **canvas** is NULL.
- **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** if **blendMode** is not set to one of the enumerated values.


### OH_Drawing_CanvasGetImageInfo()

```
OH_Drawing_ErrorCode OH_Drawing_CanvasGetImageInfo (OH_Drawing_Canvas* canvas, OH_Drawing_Image_Info* imageInfo )
```

**Description**

Obtains the image information of a canvas.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| canvas | Pointer to an [OH_Drawing_Canvas](#oh_drawing_canvas) object.|
| imageInfo | Pointer to an [OH_Drawing_Image_Info](_o_h___drawing___image___info.md) object.|

**Returns**

Returns one of the following result codes:
- **OH_DRAWING_SUCCESS** if the operation is successful.
- **OH_DRAWING_ERROR_INVALID_PARAMETER** if either **canvas** or **imageInfo** is NULL.


### OH_Drawing_CanvasIsClipEmpty()

```
OH_Drawing_ErrorCode OH_Drawing_CanvasIsClipEmpty (OH_Drawing_Canvas* canvas, bool* isClipEmpty )
```

**Description**

Checks whether the region that can be drawn is empty after cropping.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| canvas | Pointer to an [OH_Drawing_Canvas](#oh_drawing_canvas) object.|
| isClipEmpty | Pointer to the variable that specifies whether the region is empty. The value **true** means that the region is empty, and **false** means the opposite.|

**Returns**

Returns one of the following result codes:
- **OH_DRAWING_SUCCESS** if the operation is successful.
- **OH_DRAWING_ERROR_INVALID_PARAMETER** if either **canvas** or **isClipEmpty** is NULL.


### OH_Drawing_CanvasDrawPoint()

```
OH_Drawing_ErrorCode OH_Drawing_CanvasDrawPoint (OH_Drawing_Canvas* canvas, const OH_Drawing_Point2D* point )
```

**Description**

Draws a point.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| canvas | Pointer to an [OH_Drawing_Canvas](#oh_drawing_canvas) object.|
| point | Pointer to an [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) object.|

**Returns**

Returns one of the following result codes:
- **OH_DRAWING_SUCCESS** if the operation is successful.
- **OH_DRAWING_ERROR_INVALID_PARAMETER** if either **canvas** or **point** is NULL.


### OH_Drawing_MatrixGetAll()

```
OH_Drawing_ErrorCode OH_Drawing_MatrixGetAll (OH_Drawing_Matrix* matrix, float value[9] )
```

**Description**

Obtains all element values of a matrix.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| matrix | Pointer to an [OH_Drawing_Matrix](#oh_drawing_matrix) object.|
| value | Array used to store the obtained element values.|

**Returns**

Returns one of the following result codes:
- **OH_DRAWING_SUCCESS** if all element values of the matrix are successfully obtained.
- **OH_DRAWING_ERROR_INVALID_PARAMETER** if the matrix element values fail to be obtained. The failure cause is that **matrix** or **value** is NULL.



### OH_Drawing_ErrorCodeGet()

```
OH_Drawing_ErrorCode OH_Drawing_ErrorCodeGet ()
```

**Description**

Obtains the error code of the module.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Returns**

Returns the enumerated values of the error code.

### OH_Drawing_BrushCopy()

```
OH_Drawing_Brush* OH_Drawing_BrushCopy (OH_Drawing_Brush* brush)
```

**Description**

Copies an existing [OH_Drawing_Brush](#oh_drawing_brush) object to create a new one.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **brush** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| brush | Pointer to an **OH_Drawing_Brush** object.|

**Returns**

Returns the pointer to the [OH_Drawing_Brush](#oh_drawing_brush) object created. If NULL is returned, the creation fails. The possible failure cause is that no memory is available or **brush** is NULL.



### OH_Drawing_FilterSetImageFilter()

```
void OH_Drawing_FilterSetImageFilter (OH_Drawing_Filter* , OH_Drawing_ImageFilter* )
```

**Description**

Sets an **OH_Drawing_ImageFilter** object for an **OH_Drawing_Filter** object.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Filter** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Filter | Pointer to an [OH_Drawing_Filter](#oh_drawing_filter) object.|
| OH_Drawing_ImageFilter | Pointer to an [OH_Drawing_ImageFilter](#oh_drawing_imagefilter) object. If NULL is passed in, the image filter effect of the object will be cleared.|


### OH_Drawing_ImageFilterCreateBlur()

```
OH_Drawing_ImageFilter* OH_Drawing_ImageFilterCreateBlur (float sigmaX, float sigmaY, OH_Drawing_TileMode , OH_Drawing_ImageFilter* input )
```

**Description**

Creates an **OH_Drawing_ImageFilter** object with a given blur type.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| sigmaX | Deviation of the Gaussian blur to apply along the X axis.|
| sigmaY | Deviation of the Gaussian blur to apply along the Y axis.|
| OH_Drawing_TileMode | Tile mode of the shader effect. For details about the available options, see [OH_Drawing_TileMode](#oh_drawing_tilemode).|
| input | Pointer to the filter to which the image filter will be applied. If NULL is passed in, the image filter is directly applied to the original image.|

**Returns**

Returns the pointer to the [OH_Drawing_ImageFilter](#oh_drawing_imagefilter) object created. If NULL is returned, the creation fails. The possible failure cause is that no memory is available.


### OH_Drawing_ImageFilterCreateFromColorFilter()

```
OH_Drawing_ImageFilter* OH_Drawing_ImageFilterCreateFromColorFilter (OH_Drawing_ColorFilter* colorFilter, OH_Drawing_ImageFilter* input )
```

**Description**

Creates an **OH_Drawing_ImageFilter** object with a color filter effect.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **colorFilter** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| colorFilter | Pointer to an [OH_Drawing_ColorFilter](#oh_drawing_colorfilter) object.|
| input | Pointer to the filter to which the image filter will be applied. If NULL is passed in, the image filter is directly applied to the original image.|

**Returns**

Returns the pointer to the [OH_Drawing_ImageFilter](#oh_drawing_imagefilter) object created. If NULL is returned, the creation fails. The possible failure cause is that no memory is available or **colorFilter** is NULL.


### OH_Drawing_ImageFilterDestroy()

```
void OH_Drawing_ImageFilterDestroy (OH_Drawing_ImageFilter* )
```

**Description**

Destroys an **OH_Drawing_ImageFilter** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_ImageFilter | Pointer to an [OH_Drawing_ImageFilter](#oh_drawing_imagefilter) object.|


### OH_Drawing_MatrixMapPoints()

```
void OH_Drawing_MatrixMapPoints (const OH_Drawing_Matrix* , const OH_Drawing_Point2D* src, OH_Drawing_Point2D* dst, int count )
```

**Description**

Maps a source point array to a destination point array by means of matrix transformation.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If any of **OH_Drawing_Matrix**, **src**, and **dst** is NULL or **count** is less than or equal to 0, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Matrix | Pointer to an [OH_Drawing_Matrix](#oh_drawing_matrix) object.|
| src | Array of source points.|
| dst | Array of destination points. The number of destination points must be the same as that of source points.|
| count | Number of source points or destination points.|


### OH_Drawing_MatrixMapRect()

```
bool OH_Drawing_MatrixMapRect (const OH_Drawing_Matrix* , const OH_Drawing_Rect* src, OH_Drawing_Rect* dst )
```

**Description**

Maps a rectangle to the smallest rectangle that can enclose the vertices to which the four source vertices are mapped by means of matrix transformation.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If any of **OH_Drawing_Matrix**, **src**, and **dst** is NULL, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Matrix | Pointer to an [OH_Drawing_Matrix](#oh_drawing_matrix) object.|
| src | Pointer to the source rectangle.|
| dst | Pointer to the destination rectangle.|

**Returns**

Returns **true** if the source rectangle is equal to the destination rectangle; returns **false** otherwise.


### OH_Drawing_PathAddPolygon()

```
void OH_Drawing_PathAddPolygon (OH_Drawing_Path* path, const OH_Drawing_Point2D* points, uint32_t count, bool isClosed )
```

**Description**

Adds a polygon to a path.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **path** or **points** is NULL or **count** is **0**, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| path | Pointer to the current path, which is an [OH_Drawing_Path](#oh_drawing_path) object.|
| points | Pointer to an array that holds the vertex coordinates of the polygon.|
| count | Size of the array.|
| isClosed | Whether the path is closed. The value **true** means that the path is closed, and **false** means the opposite.|


### OH_Drawing_PathAddCircle()

```
void OH_Drawing_PathAddCircle (OH_Drawing_Path* path, float x, float y, float radius, OH_Drawing_PathDirection  )
```

**Description**

Adds a circle to a path in the specified direction.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **path** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

If **radius** is less than or equal to 0, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

If **OH_Drawing_PathDirection** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| path | Pointer to an [OH_Drawing_Path](#oh_drawing_path) object.|
| x | X coordinate of the circle center.|
| y | Y coordinate of the circle center.|
| radius | Radius of the circle.|
| OH_Drawing_PathDirection | Path direction. For details about the available options, see [OH_Drawing_PathDirection](#oh_drawing_pathdirection).|


### OH_Drawing_PathBuildFromSvgString()

```
bool OH_Drawing_PathBuildFromSvgString (OH_Drawing_Path* path, const char* str )
```

**Description**

Parses the path represented by an SVG string.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **path** or **str** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| path | Pointer to an [OH_Drawing_Path](#oh_drawing_path) object.|
| str | Pointer to the SVG string.|

**Returns**

Returns **true** if the SVG string is parsed successfully; returns **false** otherwise.


### OH_Drawing_PathGetBounds()

```
void OH_Drawing_PathGetBounds (OH_Drawing_Path* , OH_Drawing_Rect*  )
```

**Description**

Obtains the minimum bounds that enclose a path.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **OH_Drawing_Path** or **OH_Drawing_Rect** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Path | Pointer to an [OH_Drawing_Path](#oh_drawing_path) object.|
| OH_Drawing_Rect | Pointer to an [OH_Drawing_Rect](#oh_drawing_rect) object.|


### OH_Drawing_PathIsClosed()

```
bool OH_Drawing_PathIsClosed (OH_Drawing_Path* path, bool forceClosed )
```

**Description**

Checks whether a path is closed.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **path** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| path | Pointer to an [OH_Drawing_Path](#oh_drawing_path) object.|
| forceClosed | Whether the path is measured as a closed path. The value **true** means that the path is considered closed during measurement, and **false** means that the path is measured based on the actual closed status.|

**Returns**

Returns **true** if the path is closed; returns **false** otherwise.


### OH_Drawing_PathGetPositionTangent()

```
bool OH_Drawing_PathGetPositionTangent (OH_Drawing_Path* path, bool forceClosed, float distance, OH_Drawing_Point2D* position, OH_Drawing_Point2D* tangent )
```

**Description**

Obtains the coordinates and tangent at a distance from the start point of a path.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If any of **path**, **position**, or **tangent** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| path | Pointer to an [OH_Drawing_Path](#oh_drawing_path) object.|
| forceClosed | Whether the path is measured as a closed path. The value **true** means that the path is considered closed during measurement, and **false** means that the path is measured based on the actual closed status.|
| distance | Distance from the start point.|
| position | Pointer to the coordinates.|
| tangent | Pointer to the tangent.|

**Returns**

Returns **true** if the operation is successful; returns **false** otherwise.


### OH_Drawing_PathOp()

```
bool OH_Drawing_PathOp (OH_Drawing_Path* path, const OH_Drawing_Path* other, OH_Drawing_PathOpMode op )
```

**Description**

Combines two paths based on the specified operation mode.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **path** or **other** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

If **op** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| path | Pointer to an [OH_Drawing_Path](#oh_drawing_path) object, in which the resulting path is saved.|
| other | Pointer to an [OH_Drawing_Path](#oh_drawing_path) object.|
| op | Operation mode of the path. For details about the available options, see [OH_Drawing_PathOpMode](#oh_drawing_pathopmode).|

**Returns**

Returns **true** if the resulting path is not empty; returns **false** otherwise.


### OH_Drawing_PathGetMatrix()

```
bool OH_Drawing_PathGetMatrix (OH_Drawing_Path* path, bool forceClosed, float distance, OH_Drawing_Matrix* matrix, OH_Drawing_PathMeasureMatrixFlags flag )
```

**Description**

Obtains a transformation matrix at a distance from the start point of a path.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **path** or **matrix** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

If **flag** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| path | Pointer to an [OH_Drawing_Path](#oh_drawing_path) object.|
| forceClosed | Whether the path is measured as a closed path. The value **true** means that the path is considered closed during measurement, and **false** means that the path is measured based on the actual closed status.|
| distance | Distance from the start point.|
| matrix | Pointer to the transformation matrix.|
| flag | Type of the matrix information. For details about the available options, see [OH_Drawing_PathMeasureMatrixFlags](#oh_drawing_pathmeasurematrixflags).|

**Returns**

Returns **true** if the transformation matrix is obtained successfully; returns **false** otherwise. The possible failure cause is that **path** is NULL or the path length is 0.


### OH_Drawing_PenGetFillPath()

```
bool OH_Drawing_PenGetFillPath (OH_Drawing_Pen* , const OH_Drawing_Path* src, OH_Drawing_Path* dst, const OH_Drawing_Rect* , const OH_Drawing_Matrix*  )
```

**Description**

Obtains the source path outline drawn using a pen and represents it using a destination path.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If any of **OH_Drawing_Pen**, **src**, and **dst** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Pen | Pointer to an [OH_Drawing_Pen](#oh_drawing_pen) object.|
| src | Pointer to a source path, which is an [OH_Drawing_Path](#oh_drawing_path) object.|
| dst | Pointer to a destination path, which is an [OH_Drawing_Path](#oh_drawing_path) object.|
| OH_Drawing_Rect | Pointer to an [OH_Drawing_Rect](#oh_drawing_rect) object. NULL is recommended.|
| OH_Drawing_Matrix | Pointer to an [OH_Drawing_Matrix](#oh_drawing_matrix) object. NULL is recommended. The default value is an identity matrix.|

**Returns**

Returns **true** if the destination path is obtained; returns **false** otherwise.


### OH_Drawing_PenCopy()

```
OH_Drawing_Pen* OH_Drawing_PenCopy (OH_Drawing_Pen* pen)
```

**Description**

Copies an existing [OH_Drawing_Pen](#oh_drawing_pen) object to create a new one.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pen | Pointer to an **OH_Drawing_Pen** object.|

**Returns**

Returns the pointer to the [OH_Drawing_Pen](#oh_drawing_pen) object created. If NULL is returned, the creation fails. The possible failure cause is that no memory is available or **pen** is NULL.


### OH_Drawing_PixelMapGetFromNativePixelMap()

```
OH_Drawing_PixelMap* OH_Drawing_PixelMapGetFromNativePixelMap (NativePixelMap_* )
```

**Description**

Obtains the pixel map defined by this module from a pixel map defined by the image framework.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| NativePixelMap_ | Pointer to a **NativePixelMap_** object, which is the pixel map defined by the image framework.|

**Returns**

Returns the pointer to an [OH_Drawing_PixelMap](#oh_drawing_pixelmap) object, which is the pixel map defined by this module. If NULL is returned, the creation fails. The possible failure cause is that **NativePixelMap_** is NULL.


### OH_Drawing_PixelMapGetFromOhPixelMapNative()

```
OH_Drawing_PixelMap* OH_Drawing_PixelMapGetFromOhPixelMapNative (OH_PixelmapNative* )
```

**Description**

Obtains the pixel map defined by this module from a pixel map defined by the image framework.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_PixelmapNative | Pointer to an **OH_PixelmapNative** object, which is the pixel map defined by the image framework.|

**Returns**

Returns the pointer to an [OH_Drawing_PixelMap](#oh_drawing_pixelmap) object, which is the pixel map defined by this module. If NULL is returned, the creation fails. The possible failure cause is that **OH_PixelmapNative** is NULL.


### OH_Drawing_PixelMapDissolve()

```
void OH_Drawing_PixelMapDissolve (OH_Drawing_PixelMap* )
```

**Description**

Removes the relationship between a pixel map defined by this module and a pixel map defined by the image framework. The relationship is established by calling [OH_Drawing_PixelMapGetFromNativePixelMap](#oh_drawing_pixelmapgetfromnativepixelmap) or [OH_Drawing_PixelMapGetFromOhPixelMapNative](#oh_drawing_pixelmapgetfromohpixelmapnative).

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_PixelMap | Pointer to an [OH_Drawing_PixelMap](#oh_drawing_pixelmap) object.|


### OH_Drawing_RectJoin()

```
bool OH_Drawing_RectJoin (OH_Drawing_Rect* rect, const OH_Drawing_Rect* other )
```

**Description**

Obtains the union of two rectangles.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **rect** or **other** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| rect | Pointer to an **OH_Drawing_Rect** object.|
| other | Pointer to an **OH_Drawing_Rect** object.|

**Returns**

Returns **true** if the union is obtained; returns **false** otherwise. The possible failure cause is that at least one of the parameters **rect** and **other** is NULL or the size of the rectangle specified by **other** is empty.


### OH_Drawing_RegionContains()

```
bool OH_Drawing_RegionContains (OH_Drawing_Region* region, int32_t x, int32_t y )
```

**Description**

Checks whether a region contains the specified point.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **region** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| region | Pointer to an [OH_Drawing_Region](#oh_drawing_region) object.|
| int32_t | X coordinate of the point.|
| int32_t | Y coordinate of the point.|

**Returns**

Returns **true** if the region contains the specified point; returns **false** otherwise.


### OH_Drawing_RegionOp()

```
bool OH_Drawing_RegionOp (OH_Drawing_Region* region, const OH_Drawing_Region* other, OH_Drawing_RegionOpMode op )
```

**Description**

Combines two regions based on the specified operation mode.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **region** or **other** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

If **op** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| region | Pointer to an [OH_Drawing_Region](#oh_drawing_region) object, in which the resulting region is saved.|
| other | Pointer to an [OH_Drawing_Region](#oh_drawing_region) object.|
| op | Operation mode of the region. For details about the available options, see [OH_Drawing_RegionOpMode](#oh_drawing_regionopmode).|

**Returns**

Returns **true** if the resulting region is not empty; returns false otherwise.


### OH_Drawing_RegionSetPath()

```
bool OH_Drawing_RegionSetPath (OH_Drawing_Region* region, const OH_Drawing_Path* path, const OH_Drawing_Region* clip )
```

**Description**

Sets a region to the area described by the path.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **region**, **path**, or **clip** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| region | Pointer to an [OH_Drawing_Region](#oh_drawing_region) object.|
| path | Pointer to an [OH_Drawing_Path](#oh_drawing_path) object.|
| clip | Pointer to an [OH_Drawing_Region](#oh_drawing_region) object.|

**Returns**

Returns **true** if the resulting region is not empty; returns false otherwise.


### OH_Drawing_ShaderEffectCreateColorShader()

```
OH_Drawing_ShaderEffect* OH_Drawing_ShaderEffectCreateColorShader (const uint32_t color)
```

**Description**

Creates an **OH_Drawing_ShaderEffect** object with a single color.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| color | Color of the shader.|

**Returns**

Returns the pointer to the [OH_Drawing_ShaderEffect](#oh_drawing_shadereffect) object created. If NULL is returned, the creation fails. The possible failure cause is that no memory is available.


### OH_Drawing_ShaderEffectCreateLinearGradientWithLocalMatrix()

```
OH_Drawing_ShaderEffect* OH_Drawing_ShaderEffectCreateLinearGradientWithLocalMatrix (const OH_Drawing_Point2D* startPt, const OH_Drawing_Point2D* endPt, const uint32_t* colors, const float* pos, uint32_t size, OH_Drawing_TileMode , const OH_Drawing_Matrix*  )
```

**Description**

Creates an **OH_Drawing_ShaderEffect** object that generates a linear gradient between two points.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If any of **startPt**, **endPt**, and **colors** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

If **OH_Drawing_TileMode** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| startPt | Start point.|
| endPt | End point.|
| colors | Colors to distribute between the two points.|
| pos | Relative position of each color in the color array. If **pos** is NULL, colors are evenly distributed between the start point and end point.|
| size | Number of colors and positions (if **pos** is not NULL).|
| OH_Drawing_TileMode | Tile mode of the shader effect. For details about the available options, see [OH_Drawing_TileMode](#oh_drawing_tilemode).|
| OH_Drawing_Matrix | Matrix applied on the shader effect. If **matrix** is NULL, an identity matrix is applied by default.|

**Returns**

Returns the pointer to the [OH_Drawing_ShaderEffect](#oh_drawing_shadereffect) object created. If NULL is returned, the creation fails. The possible failure cause is that no memory is available or at least one of the parameters **startPt**, **endPt**, and **colors** is NULL.


### OH_Drawing_ShaderEffectCreateRadialGradientWithLocalMatrix()

```
OH_Drawing_ShaderEffect* OH_Drawing_ShaderEffectCreateRadialGradientWithLocalMatrix (const OH_Drawing_Point2D* centerPt, float radius, const uint32_t* colors, const float* pos, uint32_t size, OH_Drawing_TileMode , const OH_Drawing_Matrix*  )
```

**Description**

Creates an **OH_Drawing_ShaderEffect** object that generates a radial gradient based on the center and radius of a circle. The radial gradient transitions colors from the center to the ending shape in a radial manner.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **centerPt** or **colors** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

If **OH_Drawing_TileMode** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| centerPt | Center of the circle.|
| radius | Radius of the gradient.|
| colors | Colors to distribute in the radial direction.|
| pos | Relative position of each color in the color array. If **pos** is NULL, colors are evenly distributed in the radial direction.|
| size | Number of colors and positions (if **pos** is not NULL).|
| OH_Drawing_TileMode | Tile mode of the shader effect. For details about the available options, see [OH_Drawing_TileMode](#oh_drawing_tilemode).|
| OH_Drawing_Matrix | Matrix applied on the shader effect. If **matrix** is NULL, an identity matrix is applied by default.|

**Returns**

Returns the pointer to the [OH_Drawing_ShaderEffect](#oh_drawing_shadereffect) object created. If NULL is returned, the creation fails. The possible failure cause is that no memory is available or at least one of the parameters **centerPt** and **colors** is NULL.


### OH_Drawing_ShaderEffectCreateTwoPointConicalGradient()

```
OH_Drawing_ShaderEffect* OH_Drawing_ShaderEffectCreateTwoPointConicalGradient (const OH_Drawing_Point2D* startPt, float startRadius, const OH_Drawing_Point2D* endPt, float endRadius, const uint32_t* colors, const float* pos, uint32_t size, OH_Drawing_TileMode , const OH_Drawing_Matrix*  )
```

**Description**

Creates an **OH_Drawing_ShaderEffect** object that generates a gradient between two given circles.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If any of **startPt**, **endPt**, and **colors** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

If **OH_Drawing_TileMode** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| startPt | Pointer to the center of the start circle.|
| startRadius | Radius of the start circle.|
| endPt | Pointer to the center of the end circle.|
| endRadius | Radius of the end circle.|
| colors | Colors to distribute between the two circles.|
| pos | Relative position of each color in the color array. If **pos** is NULL, colors are evenly distributed between the two circles.|
| size | Number of colors and positions (if **pos** is not NULL).|
| OH_Drawing_TileMode | Tile mode of the shader effect. For details about the available options, see [OH_Drawing_TileMode](#oh_drawing_tilemode-1).|
| OH_Drawing_Matrix | Matrix applied on the shader effect. If **matrix** is NULL, an identity matrix is applied by default.|

**Returns**

Returns the pointer to the [OH_Drawing_ShaderEffect](#oh_drawing_shadereffect) object created. If NULL is returned, the creation fails. The possible failure cause is that no memory is available or at least one of the parameters **startPt**, **endPt**, and **colors** is NULL.



### OH_Drawing_TextBlobUniqueID()

```
uint32_t OH_Drawing_TextBlobUniqueID (const OH_Drawing_TextBlob* )
```

**Description**

Obtains the unique identifier of a text blob. The identifier is a non-zero value.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_TextBlob** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_TextBlob | Pointer to an [OH_Drawing_TextBlob](#oh_drawing_textblob) object.|

**Returns**

Returns the unique identifier of the text blob.


### OH_Drawing_PenSetShadowLayer()

```
void OH_Drawing_PenSetShadowLayer (OH_Drawing_Pen* , OH_Drawing_ShadowLayer* )
```

**Description**

Sets the shadow layer for a pen. The shadow layer effect takes effect only when text is drawn.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Pen | Pointer to an [OH_Drawing_Pen](#oh_drawing_pen) object.|
| OH_Drawing_ShadowLayer | Pointer to an [OH_Drawing_ShadowLayer](#oh_drawing_shadowlayer) object. If NULL is passed in, the shadow layer effect will be cleared.|


### OH_Drawing_BrushSetShadowLayer()

```
void OH_Drawing_BrushSetShadowLayer (OH_Drawing_Brush* , OH_Drawing_ShadowLayer* )
```

**Description**

Sets the shadow layer for a brush. The shadow layer effect takes effect only when text is drawn.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Brush** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Brush | Pointer to an **OH_Drawing_Brush** object.|
| OH_Drawing_ShadowLayer | Pointer to an **OH_Drawing_ShadowLayer** object. If NULL is passed in, the shadow layer effect of the brush will be cleared.|


### OH_Drawing_ShadowLayerCreate()

```
OH_Drawing_ShadowLayer* OH_Drawing_ShadowLayerCreate (float blurRadius, float x, float y, uint32_t color )
```

**Description**

Creates an **OH_Drawing_ShadowLayer** object.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **blurRadius** is less than or equal to **0**, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| blurRadius | Radius of the shadow layer. The value must be greater than 0.|
| x | Offset on the X axis.|
| y | Offset on the Y axis.|
| color | Color of the shadow.|

**Returns**

Returns the pointer to the **OH_Drawing_ShadowLayer** object created.


### OH_Drawing_ShadowLayerDestroy()

```
void OH_Drawing_ShadowLayerDestroy (OH_Drawing_ShadowLayer* )
```

**Description**

Destroys an **OH_Drawing_ShadowLayer** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_ShadowLayer | Pointer to the shadow layer.|


### OH_Drawing_FontSetBaselineSnap()

```
void OH_Drawing_FontSetBaselineSnap (OH_Drawing_Font* , bool baselineSnap )
```

**Description**

Sets whether to request that baselines be snapped to pixels when the current canvas matrix is axis aligned.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Font | Pointer to an [OH_Drawing_Font](#oh_drawing_font) object.|
| baselineSnap | Whether to request that baselines be snapped to pixels. The value **true** means to request that baselines be snapped to pixels, and **false** means the opposite.|


### OH_Drawing_FontIsBaselineSnap()

```
bool OH_Drawing_FontIsBaselineSnap (const OH_Drawing_Font* )
```

**Description**

Checks whether baselines are requested to be snapped to pixels when the current canvas matrix is axis aligned.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Font | Pointer to an [OH_Drawing_Font](#oh_drawing_font) object.|

**Returns**

Returns **true** if baselines are requested to be snapped to pixels when the current canvas matrix is axis aligned; returns **false** otherwise.


### OH_Drawing_FontSetEdging()

```
void OH_Drawing_FontSetEdging (OH_Drawing_Font* , OH_Drawing_FontEdging  )
```

**Description**

Sets a font edging effect.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

If **OH_Drawing_FontEdging** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Font | Pointer to an [OH_Drawing_Font](#oh_drawing_font) object.|
| OH_Drawing_FontEdging | Font edging effect.|


### OH_Drawing_FontGetEdging()

```
OH_Drawing_FontEdging OH_Drawing_FontGetEdging (const OH_Drawing_Font* )
```

**Description**

Obtains the font edging effect.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Font | Pointer to an [OH_Drawing_Font](#oh_drawing_font) object.|

**Returns**

Returns the font edging effect.



### OH_Drawing_FontSetForceAutoHinting()

```
void OH_Drawing_FontSetForceAutoHinting (OH_Drawing_Font* , bool isForceAutoHinting )
```

**Description**

Sets whether to forcibly use auto hinting, that is, whether to always hint glyphs.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Font | Pointer to an [OH_Drawing_Font](#oh_drawing_font) object.|
| isForceAutoHinting | Whether to forcibly use auto hinting. The value **true** means to forcibly use auto hinting, and **false** means the opposite.|


### OH_Drawing_FontIsForceAutoHinting()

```
bool OH_Drawing_FontIsForceAutoHinting (const OH_Drawing_Font* )
```

**Description**

Checks whether auto hinting is forcibly used.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Font | Pointer to an [OH_Drawing_Font](#oh_drawing_font) object.|

**Returns**

Returns **true** if auto hinting is forcibly used; returns **false** otherwise.


### OH_Drawing_FontSetSubpixel()

```
void OH_Drawing_FontSetSubpixel (OH_Drawing_Font* , bool isSubpixel )
```

**Description**

Sets whether to use sub-pixel rendering for a font.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Font | Pointer to an [OH_Drawing_Font](#oh_drawing_font) object.|
| isSubpixel | Whether to use sub-pixel rendering for the font. The value **true** means to use sub-pixel rendering for the font, and **false** means the opposite.|


### OH_Drawing_FontIsSubpixel()

```
bool OH_Drawing_FontIsSubpixel (const OH_Drawing_Font* )
```

**Description**

Checks whether sub-pixel rendering is used for a font.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Font | Pointer to an [OH_Drawing_Font](#oh_drawing_font) object.|

**Returns**

Returns **true** if sub-pixel rendering is used for the font; returns **false** otherwise.


### OH_Drawing_FontGetTextSize()

```
float OH_Drawing_FontGetTextSize (const OH_Drawing_Font* )
```

**Description**

Obtains the text size.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Font | Pointer to an [OH_Drawing_Font](#oh_drawing_font) object.|

**Returns**

Returns a floating point number representing the text size.


### OH_Drawing_FontTextToGlyphs()

```
uint32_t OH_Drawing_FontTextToGlyphs (const OH_Drawing_Font* , const void* text, uint32_t byteLength, OH_Drawing_TextEncoding encoding, uint16_t* glyphs, int maxGlyphCount )
```

**Description**

Converts text into glyph indices.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If any of **OH_Drawing_Font**, **text**, and **glyphs** is NULL, **byteLength** is **0**, or **maxGlyphCount** is less than or equal to 0, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Font | Pointer to an [OH_Drawing_Font](#oh_drawing_font) object.|
| text | Pointer to the start address of the storage.|
| byteLength | Text length, in bytes.|
| encoding | Encoding type of the text. For details about the available options, see [OH_Drawing_TextEncoding](#oh_drawing_textencoding).|
| glyphs | Pointer to the start address for storing the glyph indices.|
| maxGlyphCount | Maximum number of glyphs.|

**Returns**

Returns the number of glyph indices.


### OH_Drawing_FontGetWidths()

```
void OH_Drawing_FontGetWidths (const OH_Drawing_Font* , const uint16_t* glyphs, int count, float* widths )
```

**Description**

Obtains the width of each glyph in a string of text.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If any of **OH_Drawing_Font**, **glyphs**, and **widths** is NULL or **count** is less than or equal to 0, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Font | Pointer to an [OH_Drawing_Font](#oh_drawing_font) object.|
| glyphs | Pointer to the start address for storing the glyph indices.|
| count | Number of glyph indices.|
| widths | Pointer to the start address for storing the glyph widths.|


### OH_Drawing_FontIsLinearText()

```
bool OH_Drawing_FontIsLinearText (const OH_Drawing_Font* )
```

**Description**

Checks whether linear scaling is used for a font.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Font | Pointer to an [OH_Drawing_Font](#oh_drawing_font) object.|

**Returns**

Returns **true** if linear scaling is used; returns **false** otherwise.


### OH_Drawing_FontGetTextSkewX()

```
float OH_Drawing_FontGetTextSkewX (const OH_Drawing_Font* )
```

**Description**

Obtains the horizontal skew factor of a font.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Font | Pointer to an [OH_Drawing_Font](#oh_drawing_font) object.|

**Returns**

Returns a floating point number representing the horizontal skew factor.


### OH_Drawing_FontIsFakeBoldText()

```
bool OH_Drawing_FontIsFakeBoldText (const OH_Drawing_Font* )
```

**Description**

Checks whether fake bold is used for a font.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Font | Pointer to an [OH_Drawing_Font](#oh_drawing_font) object.|

**Returns**

Returns **true** if fake bold is used; returns **false** otherwise.


### OH_Drawing_FontSetScaleX()

```
void OH_Drawing_FontSetScaleX (OH_Drawing_Font* , float scaleX )
```

**Description**

Sets a horizontal scale factor for a font.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Font | Pointer to an [OH_Drawing_Font](#oh_drawing_font) object.|
| scaleX | Horizontal scale factor.|


### OH_Drawing_FontGetScaleX()

```
float OH_Drawing_FontGetScaleX (const OH_Drawing_Font* )
```

**Description**

Obtains the horizontal scale factor of a font.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Font | Pointer to an [OH_Drawing_Font](#oh_drawing_font) object.|

**Returns**

Returns the horizontal scale factor.


### OH_Drawing_FontSetHinting()

```
void OH_Drawing_FontSetHinting (OH_Drawing_Font* , OH_Drawing_FontHinting  )
```

**Description**

Sets a font hinting effect.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

If **OH_Drawing_FontHinting** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Font | Pointer to an [OH_Drawing_Font](#oh_drawing_font) object.|
| OH_Drawing_FontHinting | Font hinting effect. For details about the available options, see [OH_Drawing_FontHinting](#oh_drawing_fonthinting).|


### OH_Drawing_FontGetHinting()

```
OH_Drawing_FontHinting OH_Drawing_FontGetHinting (const OH_Drawing_Font* )
```

**Description**

Obtains the font hinting effect.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Font | Pointer to an [OH_Drawing_Font](#oh_drawing_font) object.|

**Returns**

Returns the font hinting effect. For details about the available options, see [OH_Drawing_FontHinting](#oh_drawing_fonthinting).


### OH_Drawing_FontSetEmbeddedBitmaps()

```
void OH_Drawing_FontSetEmbeddedBitmaps (OH_Drawing_Font* , bool isEmbeddedBitmaps )
```

**Description**

Sets whether to use bitmaps in a font.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Font | Pointer to an [OH_Drawing_Font](#oh_drawing_font) object.|
| isEmbeddedBitmaps | Whether to use bitmaps in the font. The value **true** means to use bitmaps in the font, and **false** means the opposite.|


### OH_Drawing_FontIsEmbeddedBitmaps()

```
bool OH_Drawing_FontIsEmbeddedBitmaps (const OH_Drawing_Font* )
```

**Description**

Checks whether bitmaps are used in a font.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Font | Pointer to an [OH_Drawing_Font](#oh_drawing_font) object.|

**Returns**

Returns **true** if bitmaps are used; returns **false** otherwise.


### OH_Drawing_BitmapBuild()

```
void OH_Drawing_BitmapBuild (OH_Drawing_Bitmap* , const uint32_t width, const uint32_t height, const OH_Drawing_BitmapFormat*  )
```

**Description**

Initializes the width and height of a bitmap and sets the pixel format for the bitmap.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **OH_Drawing_Bitmap** or **OH_Drawing_BitmapFormat** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

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

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **OH_Drawing_Image_Info** or **pixels** is NULL or **rowBytes** is **0**, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Image_Info | Pointer to an [OH_Drawing_Image_Info](_o_h___drawing___image___info.md) object.|
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


### OH_Drawing_BitmapGetAlphaFormat()

```
OH_Drawing_AlphaFormat OH_Drawing_BitmapGetAlphaFormat (OH_Drawing_Bitmap* )
```

**Description**

Obtains the alpha component of a bitmap.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Bitmap** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Bitmap | Pointer to an **OH_Drawing_Bitmap** object.|

**Returns**

Returns the alpha component. For details about the supported formats, see [OH_Drawing_AlphaFormat](#oh_drawing_alphaformat).


### OH_Drawing_BitmapGetColorFormat()

```
OH_Drawing_ColorFormat OH_Drawing_BitmapGetColorFormat (OH_Drawing_Bitmap* )
```

**Description**

Obtains the pixel format of a bitmap.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Bitmap** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Bitmap | Pointer to an **OH_Drawing_Bitmap** object.|

**Returns**

Returns the pixel format. For details about the supported formats, see [OH_Drawing_ColorFormat](#oh_drawing_colorformat).


### OH_Drawing_BitmapGetHeight()

```
uint32_t OH_Drawing_BitmapGetHeight (OH_Drawing_Bitmap* )
```

**Description**

Obtains the height of a bitmap.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Bitmap** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Bitmap | Pointer to an **OH_Drawing_Bitmap** object.|

**Returns**

Returns the height.


### OH_Drawing_BitmapGetImageInfo()

```
void OH_Drawing_BitmapGetImageInfo (OH_Drawing_Bitmap* , OH_Drawing_Image_Info*  )
```

**Description**

Obtains the image information of a bitmap.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **OH_Drawing_Bitmap** or **OH_Drawing_Image_Info** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Bitmap | Pointer to an [OH_Drawing_Bitmap](#oh_drawing_bitmap) object.|
| OH_Drawing_Image_Info | Pointer to an [OH_Drawing_Image_Info](_o_h___drawing___image___info.md) object.|


### OH_Drawing_BitmapGetPixels()

```
void* OH_Drawing_BitmapGetPixels (OH_Drawing_Bitmap* )
```

**Description**

Obtains the pixel address of a bitmap. You can use this address to obtain the pixel data of the bitmap.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Bitmap** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

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

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Bitmap** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Bitmap | Pointer to an **OH_Drawing_Bitmap** object.|

**Returns**

Returns the width.

### OH_Drawing_BitmapReadPixels()

```
bool OH_Drawing_BitmapReadPixels (OH_Drawing_Bitmap* , const OH_Drawing_Image_Info* dstInfo, void* dstPixels, size_t dstRowBytes, int32_t srcX, int32_t srcY )
```

**Description**

Reads pixels of a rectangle in a bitmap to the specified buffer.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If any of **OH_Drawing_Bitmap**, **dstInfo**, and **dstPixels** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Bitmap | Pointer to an [OH_Drawing_Bitmap](#oh_drawing_bitmap) object.|
| OH_Drawing_Image_Info | Pointer to an [OH_Drawing_Image_Info](_o_h___drawing___image___info.md) object.|
| dstPixels | Pointer to the buffer for storing the pixels read.|
| dstRowBytes | Number of bytes in each row of the pixel data read. The value must be greater than or equal to the minimum number of bytes in each row in the [OH_Drawing_Image_Info](_o_h___drawing___image___info.md) object.|
| srcX | Start X coordinate of the pixel data to read from the bitmap. The value must be less than the width of the bitmap.|
| srcY | Start Y coordinate of the pixel data to read from the bitmap. The value must be less than the height of the bitmap.|

**Returns**

Returns **true** if the pixels are read; returns **false** otherwise.


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

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Brush** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

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

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Brush** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Brush | Pointer to an **OH_Drawing_Brush** object.|

**Returns**

Returns a 32-bit (ARGB) variable that describes the color.


### OH_Drawing_BrushGetFilter()

```
void OH_Drawing_BrushGetFilter (OH_Drawing_Brush* , OH_Drawing_Filter*  )
```

**Description**

Obtains the filter of a brush. The filter is a container that holds a mask filter and color filter.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **OH_Drawing_Brush** or **OH_Drawing_Filter** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Brush | Pointer to an [OH_Drawing_Brush](#oh_drawing_brush) object.|
| OH_Drawing_Filter | Pointer to the [OH_Drawing_Filter](#oh_drawing_filter) object obtained.|


### OH_Drawing_BrushIsAntiAlias()

```
bool OH_Drawing_BrushIsAntiAlias (const OH_Drawing_Brush* )
```

**Description**

Checks whether anti-aliasing is enabled for a brush. Anti-aliasing makes the pixels around the shape edges semi-transparent.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Brush** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Brush | Pointer to an **OH_Drawing_Brush** object.|

**Returns**

Returns **true** if anti-aliasing is enabled; returns **false** otherwise.


### OH_Drawing_BrushReset()

```
void OH_Drawing_BrushReset (OH_Drawing_Brush* )
```

**Description**

Resets a brush to the initial state. All configured attributes are cleared.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Brush** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Brush | Pointer to an [OH_Drawing_Brush](#oh_drawing_brush) object.|


### OH_Drawing_BrushSetAlpha()

```
void OH_Drawing_BrushSetAlpha (OH_Drawing_Brush* , uint8_t alpha )
```

**Description**

Sets the alpha value for a brush. This value is used by the alpha channel when the brush fills in a shape.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Brush** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

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

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Brush** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

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

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Brush** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

If **OH_Drawing_BlendMode** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

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

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Brush** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

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

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Brush** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Brush | Pointer to an **OH_Drawing_Brush** object.|
| OH_Drawing_Filter | Pointer to an **OH_Drawing_Filter** object. If null is passed in, the filter will be cleared.|


### OH_Drawing_BrushSetShaderEffect()

```
void OH_Drawing_BrushSetShaderEffect (OH_Drawing_Brush* , OH_Drawing_ShaderEffect*  )
```

**Description**

Sets the shader effect for a brush.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Brush** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Brush | Pointer to an **OH_Drawing_Brush** object.|
| OH_Drawing_ShaderEffect | Pointer to an **OH_Drawing_ShaderEffect** object. If NULL is passed in, the shader effect of the brush will be cleared.|


### OH_Drawing_CanvasAttachBrush()

```
void OH_Drawing_CanvasAttachBrush (OH_Drawing_Canvas* , const OH_Drawing_Brush*  )
```

**Description**

Attaches a brush to a canvas so that the canvas can use the style and color of the brush to fill in a shape.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **OH_Drawing_Canvas** or **OH_Drawing_Brush** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

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

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **OH_Drawing_Canvas** or **OH_Drawing_Pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

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

Binds a bitmap to a canvas so that the content drawn on the canvas is output to the bitmap. (This process is called CPU rendering.) A canvas bound to a bitmap is a non-recording canvas.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **OH_Drawing_Canvas** or **OH_Drawing_Bitmap** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

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

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Canvas** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

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

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **OH_Drawing_Canvas** or **OH_Drawing_Path** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

If **clipOp** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

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

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **OH_Drawing_Canvas** or **OH_Drawing_Rect** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

If **clipOp** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object.|
| OH_Drawing_Rect | Pointer to an **OH_Drawing_Rect** object.|
| clipOp | Clip mode. For details about the available options, see [OH_Drawing_CanvasClipOp](#oh_drawing_canvasclipop).|
| doAntiAlias | Whether to enable anti-aliasing. The value **true** means to enable anti-aliasing, and **false** means the opposite.|

### OH_Drawing_CanvasClipRoundRect()

```
void OH_Drawing_CanvasClipRoundRect (OH_Drawing_Canvas* , const OH_Drawing_RoundRect* , OH_Drawing_CanvasClipOp clipOp, bool doAntiAlias )
```

**Description**

Clips a rounded rectangle.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **OH_Drawing_Canvas** or **OH_Drawing_RoundRect** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

If **clipOp** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object.|
| OH_Drawing_RoundRect | Pointer to an **OH_Drawing_RoundRect** object.|
| clipOp | Clip mode. For details about the available options, see [OH_Drawing_CanvasClipOp](#oh_drawing_canvasclipop).|
| doAntiAlias | Whether to perform anti-aliasing. The value **true** means to perform anti-aliasing, and **false** means the opposite.|

### OH_Drawing_CanvasConcatMatrix()

```
void OH_Drawing_CanvasConcatMatrix (OH_Drawing_Canvas* , OH_Drawing_Matrix*  )
```

**Description**

Preconcats the existing matrix with the passed-in matrix. The drawing operation triggered before this function is called is not affected.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **OH_Drawing_Canvas** or **OH_Drawing_Matrix** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

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

Detaches the brush from a canvas so that the canvas can no longer use the previously set brush to fill in a shape.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Canvas** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

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

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Canvas** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

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

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **OH_Drawing_Canvas** or **OH_Drawing_Rect** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object.|
| OH_Drawing_Rect | Pointer to an **OH_Drawing_Rect** object.|
| startAngle | Start angle of the arc.|
| sweepAngle | Sweep angle of the arc.|


### OH_Drawing_CanvasDrawBackground()

```
void OH_Drawing_CanvasDrawBackground (OH_Drawing_Canvas* , const OH_Drawing_Brush*  )
```

**Description**

Draws a background filled with a brush.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **OH_Drawing_Canvas** or **OH_Drawing_Brush** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object.|
| OH_Drawing_Brush | Pointer to an **OH_Drawing_Brush** object.|


### OH_Drawing_CanvasDrawBitmap()

```
void OH_Drawing_CanvasDrawBitmap (OH_Drawing_Canvas* , const OH_Drawing_Bitmap* , float left, float top )
```

**Description**

Draws a bitmap. A bitmap, also referred to as a dot matrix image, a pixel map image, or a grid image, includes single points called pixels (image elements).

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **OH_Drawing_Canvas** or **OH_Drawing_Bitmap** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

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

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If any of **OH_Drawing_Canvas**, **OH_Drawing_Bitmap**, and **dst** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an [OH_Drawing_Canvas](#oh_drawing_canvas) object.|
| OH_Drawing_Bitmap | Pointer to an [OH_Drawing_Bitmap](#oh_drawing_bitmap) object.|
| src | Pointer to a rectangle on the bitmap. If NULL is passed in, it refers to the entire bitmap.|
| dst | Pointer to a rectangle on the canvas.|
| OH_Drawing_SamplingOptions | Pointer to an [OH_Drawing_SamplingOptions](#oh_drawing_samplingoptions) object. If NULL is passed in, the default sampling options are used.|


### OH_Drawing_CanvasDrawCircle()

```
void OH_Drawing_CanvasDrawCircle (OH_Drawing_Canvas* , const OH_Drawing_Point* , float radius )
```

**Description**

Draws a circle.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **OH_Drawing_Canvas** or **OH_Drawing_Point** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

If **radius** is less than or equal to 0, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

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

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If any of **OH_Drawing_Canvas**, **OH_Drawing_Image**, and **dst** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an [OH_Drawing_Canvas](#oh_drawing_canvas) object.|
| OH_Drawing_Image | Pointer to an [OH_Drawing_Image](#oh_drawing_image) object.|
| dst | Pointer to an [OH_Drawing_Rect](#oh_drawing_rect) object.|
| OH_Drawing_SamplingOptions | Pointer to an [OH_Drawing_SamplingOptions](#oh_drawing_samplingoptions) object. If NULL is passed in, the default sampling options are used.|


### OH_Drawing_CanvasDrawImageRectWithSrc()

```
void OH_Drawing_CanvasDrawImageRectWithSrc (OH_Drawing_Canvas* , const OH_Drawing_Image* , const OH_Drawing_Rect* src, const OH_Drawing_Rect* dst, const OH_Drawing_SamplingOptions* , OH_Drawing_SrcRectConstraint  )
```

**Description**

Draws a portion of an image onto a specified area of the canvas. The area selected by the source rectangle is scaled and translated to the destination rectangle.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If any of **OH_Drawing_Canvas**, **OH_Drawing_Image**, **src**, and **dst** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an [OH_Drawing_Canvas](#oh_drawing_canvas) object.|
| OH_Drawing_Image | Pointer to an [OH_Drawing_Image](#oh_drawing_image) object.|
| src | Pointer to a source rectangle, which is an [OH_Drawing_Rect](#oh_drawing_rect) object.|
| dst | Pointer to a destination rectangle, which is an [OH_Drawing_Rect](#oh_drawing_rect) object.|
| OH_Drawing_SamplingOptions | Pointer to an [OH_Drawing_SamplingOptions](#oh_drawing_samplingoptions) object. If NULL is passed in, the default sampling options are used.|
| OH_Drawing_SrcRectConstraint | Constraint type. For details about the available options, see [OH_Drawing_SrcRectConstraint](#oh_drawing_srcrectconstraint-1).|


### OH_Drawing_CanvasDrawLine()

```
void OH_Drawing_CanvasDrawLine (OH_Drawing_Canvas* , float x1, float y1, float x2, float y2 )
```

**Description**

Draws a line segment.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Canvas** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

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

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **OH_Drawing_Canvas** or **OH_Drawing_Rect** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

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

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **OH_Drawing_Canvas** or **OH_Drawing_Path** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object.|
| OH_Drawing_Path | Pointer to an **OH_Drawing_Path** object.|


### OH_Drawing_CanvasDrawPixelMapRect()

```
void OH_Drawing_CanvasDrawPixelMapRect (OH_Drawing_Canvas* , OH_Drawing_PixelMap* , const OH_Drawing_Rect* src, const OH_Drawing_Rect* dst, const OH_Drawing_SamplingOptions*  )
```

**Description**

Draws a portion of a pixel map onto a specified area of the canvas.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If any of **OH_Drawing_Canvas**, **OH_Drawing_PixelMap**, and **dst** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an [OH_Drawing_Canvas](#oh_drawing_canvas) object.|
| OH_Drawing_PixelMap | Pointer to an [OH_Drawing_PixelMap](#oh_drawing_pixelmap) object.|
| src | Pointer to a rectangle on the pixel map. If NULL is passed in, it refers to the entire pixel map.|
| dst | Pointer to a rectangle on the canvas.|
| OH_Drawing_SamplingOptions | Pointer to an [OH_Drawing_SamplingOptions](#oh_drawing_samplingoptions) object. If NULL is passed in, the default sampling options are used.|


### OH_Drawing_CanvasDrawPoints()

```
void OH_Drawing_CanvasDrawPoints (OH_Drawing_Canvas* , OH_Drawing_PointMode mode, uint32_t count, const OH_Drawing_Point2D*  )
```

**Description**

Draws multiple points. You can draw a single point, a line segment, or an open polygon.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **OH_Drawing_Canvas** or **OH_Drawing_Point2D** is NULL or **count** is **0**, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

If **mode** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object.|
| mode | Mode of drawing multiple points. For details about the available options, see [OH_Drawing_PointMode](#oh_drawing_pointmode).|
| count | Number of vertices, that is, the number of vertices in the vertex array.|
| [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) | Pointer to an array holding the vertices.|


### OH_Drawing_CanvasDrawRect()

```
void OH_Drawing_CanvasDrawRect (OH_Drawing_Canvas* , const OH_Drawing_Rect*  )
```

**Description**

Draws a rectangle.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **OH_Drawing_Canvas** or **OH_Drawing_Rect** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object.|
| OH_Drawing_Rect | Pointer to an **OH_Drawing_Rect** object.|


### OH_Drawing_CanvasDrawRegion()

```
void OH_Drawing_CanvasDrawRegion (OH_Drawing_Canvas* , const OH_Drawing_Region*  )
```

**Description**

Draws a region.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **OH_Drawing_Canvas** or **OH_Drawing_Region** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object.|
| OH_Drawing_Region | Pointer to an **OH_Drawing_Region** object.|


### OH_Drawing_CanvasDrawRoundRect()

```
void OH_Drawing_CanvasDrawRoundRect (OH_Drawing_Canvas* , const OH_Drawing_RoundRect*  )
```

**Description**

Draws a rounded rectangle.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **OH_Drawing_Canvas** or **OH_Drawing_RoundRect** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

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

Draws a spot shadow and uses a given path to outline the ambient shadow.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **OH_Drawing_Canvas** or **OH_Drawing_Path** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

If **flag** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an [OH_Drawing_Canvas](#oh_drawing_canvas) object.|
| OH_Drawing_Path | Pointer to an [OH_Drawing_Path](#oh_drawing_path) object, which is used to generate the shadow.|
| planeParams | Value of the function that returns the Z axis of the occluding object from the canvas based on the X axis and Y axis.|
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

Draws a text blob. If the typeface used to construct **OH_Drawing_TextBlob** does not support a character, that character will not be drawn.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **OH_Drawing_Canvas** or **OH_Drawing_TextBlob** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object.|
| OH_Drawing_TextBlob | Pointer to an **OH_Drawing_TextBlob** object.|
| x | X coordinate of the lower left corner of the text blob.|
| y | Y coordinate of the lower left corner of the text blob.|


### OH_Drawing_CanvasDrawVertices()

```
void OH_Drawing_CanvasDrawVertices (OH_Drawing_Canvas* , OH_Drawing_VertexMode vertexMmode, int32_t vertexCount, const OH_Drawing_Point2D* positions, const OH_Drawing_Point2D* texs, const uint32_t* colors, int32_t indexCount, const uint16_t* indices, OH_Drawing_BlendMode mode )
```

**Description**

Draws a triangular grid described by a vertex array.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **OH_Drawing_Canvas** or **positions** is NULL, **vertexCount** is less than 3, or **indexCount** is less than 3 but not 0, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

If either **vertexMmode** or **mode** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object.|
| vertexMmode | Vertex drawing mode. For details about the available options, see [OH_Drawing_VertexMode](#oh_drawing_vertexmode).|
| vertexCount | Number of elements in the vertex array. The value must be greater than or equal to 3.|
| positions | Pointer to the array that holds the position of every vertex. The array cannot be null and its length must be equal to the value of **vertexCount**.|
| texs | Pointer to the array that holds the texture space coordinate corresponding to each vertex. The array can be null. If the array is not null, its length must be equal to the value of **vertexCount**.|
| colors | Pointer to the array that holds the color corresponding to each vertex. It is used for interpolation in a triangle. The array can be null. If the array is not null, its length must be equal to the value of **vertexCount**.|
| indexCount | Number of indexes. The value can be 0 or a value greater than or equal to 3.|
| indices | Pointer to the array that holds the index of each vertex. The array can be null. If the array is not null, its length must be equal to the value of **indexCount**.|
| mode | Blend mode. For details about the available options, see [OH_Drawing_BlendMode](#oh_drawing_blendmode).|


### OH_Drawing_CanvasGetHeight()

```
int32_t OH_Drawing_CanvasGetHeight (OH_Drawing_Canvas* )
```

**Description**

Obtains the canvas height.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Canvas** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

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

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **OH_Drawing_Canvas** or **OH_Drawing_Rect** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

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

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Canvas** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object.|

**Returns**

Returns a 32-bit value that describes the number of canvas statuses (canvas matrices). The initial number is **1**.


### OH_Drawing_CanvasGetTotalMatrix()

```
void OH_Drawing_CanvasGetTotalMatrix (OH_Drawing_Canvas* , OH_Drawing_Matrix*  )
```

**Description**

Obtains the 3x3 matrix of a canvas.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **OH_Drawing_Canvas** or **OH_Drawing_Matrix** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

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

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Canvas** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

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

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If any of **OH_Drawing_Canvas**, **OH_Drawing_Image_Info**, and **dstPixels** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an [OH_Drawing_Canvas](#oh_drawing_canvas) object.|
| [OH_Drawing_Image_Info](_o_h___drawing___image___info.md) | Pointer to an [OH_Drawing_Image_Info](_o_h___drawing___image___info.md) object.|
| dstPixels | Pointer to the start address for storing the pixel data.|
| dstRowBytes | Size of pixels per row.|
| srcX | X offset of the pixels on the canvas, in px.|
| srcY | Y offset of the pixels on the canvas, in px.|

**Returns**

Returns **true** if the pixel data is copied to the start address of the storage; returns **false** otherwise.


### OH_Drawing_CanvasReadPixelsToBitmap()

```
bool OH_Drawing_CanvasReadPixelsToBitmap (OH_Drawing_Canvas* , OH_Drawing_Bitmap* , int32_t srcX, int32_t srcY )
```

**Description**

Copies pixel data from a canvas to an image. This function cannot be used for recorded canvases.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **OH_Drawing_Canvas** or **OH_Drawing_Bitmap** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an [OH_Drawing_Canvas](#oh_drawing_canvas) object.|
| OH_Drawing_Bitmap | Pointer to an [OH_Drawing_Bitmap](#oh_drawing_bitmap) object.|
| srcX | X offset of the pixels on the canvas, in px.|
| srcY | Y offset of the pixels on the canvas, in px.|

**Returns**

Returns **true** if the pixel data is copied to the image; returns **false** otherwise.


### OH_Drawing_CanvasResetMatrix()

```
void OH_Drawing_CanvasResetMatrix (OH_Drawing_Canvas* )
```

**Description**

Resets the matrix of a canvas to an identity matrix.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Canvas** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| OH_Drawing_Canvas | Pointer to an [OH_Drawing_Canvas](#oh_drawing_canvas) object.|


### OH_Drawing_CanvasRestore()

```
void OH_Drawing_CanvasRestore (OH_Drawing_Canvas* )
```

**Description**

Restores the canvas status (canvas matrix) saved on the top of the stack.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Canvas** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name              | Description                                 |
| ----------------- | ------------------------------------------- |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object. |


### OH_Drawing_CanvasRestoreToCount()

```
void OH_Drawing_CanvasRestoreToCount (OH_Drawing_Canvas* , uint32_t saveCount )
```

**Description**

Restores to a given number of canvas statuses (canvas matrices).

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Canvas** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name              | Description                                                  |
| ----------------- | ------------------------------------------------------------ |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object.                  |
| saveCount         | Number of canvas statuses (canvas matrices). If the value is less than or equal to 1, the canvas is restored to the initial state. If the value is greater than the number of canvas statuses that have been saved, no operation is performed. |


### OH_Drawing_CanvasRotate()

```
void OH_Drawing_CanvasRotate (OH_Drawing_Canvas* , float degrees, float px, float py )
```

**Description**

Rotates a canvas by a given angle. A positive value indicates a clockwise rotation, and a negative value indicates a counterclockwise rotation.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Canvas** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name              | Description                                 |
| ----------------- | ------------------------------------------- |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object. |
| degrees           | Angle to rotate.                            |
| px                | X coordinate of the rotation point.         |
| py                | Y coordinate of the rotation point.         |


### OH_Drawing_CanvasSave()

```
void OH_Drawing_CanvasSave (OH_Drawing_Canvas* )
```

**Description**

Saves the current canvas status (canvas matrix) to the top of the stack.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Canvas** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name              | Description                                 |
| ----------------- | ------------------------------------------- |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object. |


### OH_Drawing_CanvasSaveLayer()

```
void OH_Drawing_CanvasSaveLayer (OH_Drawing_Canvas* , const OH_Drawing_Rect* , const OH_Drawing_Brush*  )
```

**Description**

Saves the matrix and cropping region, and allocates a bitmap for subsequent drawing. If you call [OH_Drawing_CanvasRestore](#oh_drawing_canvasrestore), the changes made to the matrix and clipping region are discarded, and the bitmap is drawn.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Canvas** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name              | Description                                                  |
| ----------------- | ------------------------------------------------------------ |
| OH_Drawing_Canvas | Pointer to an [OH_Drawing_Canvas](#oh_drawing_canvas) object. |
| OH_Drawing_Rect   | Pointer to an [OH_Drawing_Rect](#oh_drawing_rect) object, which is used to limit the size of the graphics layer. If NULL is passed in, the size is not limited. |
| OH_Drawing_Brush  | Pointer to an [OH_Drawing_Brush](#oh_drawing_brush) object. The alpha value, filter effect, and blend mode of the brush are applied when the bitmap is drawn. If NULL is passed in, no effect is applied. |


### OH_Drawing_CanvasScale()

```
void OH_Drawing_CanvasScale (OH_Drawing_Canvas* , float sx, float sy )
```

**Description**

Scales a canvas.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Canvas** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name              | Description                                 |
| ----------------- | ------------------------------------------- |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object. |
| sx                | Scale ratio on the X axis.                  |
| sy                | Scale ratio on the Y axis.                  |


### OH_Drawing_CanvasSetMatrix()

```
void OH_Drawing_CanvasSetMatrix (OH_Drawing_Canvas* , OH_Drawing_Matrix*  )
```

**Description**

Sets the matrix status for a canvas.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **OH_Drawing_Canvas** or **OH_Drawing_Matrix** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name              | Description                                                  |
| ----------------- | ------------------------------------------------------------ |
| OH_Drawing_Canvas | Pointer to an [OH_Drawing_Canvas](#oh_drawing_canvas) object. |
| OH_Drawing_Matrix | Pointer to an [OH_Drawing_Matrix](#oh_drawing_matrix) object, which is obtained by calling [OH_Drawing_MatrixCreate](#oh_drawing_matrixcreate). |


### OH_Drawing_CanvasSkew()

```
void OH_Drawing_CanvasSkew (OH_Drawing_Canvas* , float sx, float sy )
```

**Description**

Skews a canvas. This function premultiplies the current canvas matrix by a skew transformation matrix and applies the resulting matrix to the canvas. The skew transformation matrix is as follows: \|1 sx 0\| \|sy 1 0\| \|0 0 1\|

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Canvas** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name              | Description                                                  |
| ----------------- | ------------------------------------------------------------ |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object.                  |
| sx                | Amount of tilt on the X axis. A positive number tilts the drawing rightwards along the positive direction of the Y axis, and a negative number tilts the drawing leftwards along the positive direction of the Y axis. |
| sy                | Amount of tilt on the Y axis. A positive number tilts the drawing downwards along the positive direction of the X axis, and a negative number tilts the drawing upwards along the positive direction of the X axis. |


### OH_Drawing_CanvasTranslate()

```
void OH_Drawing_CanvasTranslate (OH_Drawing_Canvas* , float dx, float dy )
```

**Description**

Translates a canvas by a given distance.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Canvas** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name              | Description                                 |
| ----------------- | ------------------------------------------- |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object. |
| dx                | Distance to translate on the X axis.        |
| dy                | Distance to translate on the Y axis.        |


### OH_Drawing_ColorFilterCreateBlendMode()

```
OH_Drawing_ColorFilter* OH_Drawing_ColorFilterCreateBlendMode (uint32_t color, OH_Drawing_BlendMode  )
```

**Description**

Creates an **OH_Drawing_ColorFilter** object with a given blend mode.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| color                | Color, which is a 32-bit (ARGB) variable.                    |
| OH_Drawing_BlendMode | Blend mode. For details about the available options, see [OH_Drawing_BlendMode](#oh_drawing_blendmode). |

**Returns**

Returns the pointer to the **OH_Drawing_ColorFilter** object created.


### OH_Drawing_ColorFilterCreateCompose()

```
OH_Drawing_ColorFilter* OH_Drawing_ColorFilterCreateCompose (OH_Drawing_ColorFilter* colorFilter1, OH_Drawing_ColorFilter* colorFilter2 )
```

**Description**

Creates an **OH_Drawing_ColorFilter** object by combining another two color filters.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **colorFilter1** or **colorFilter2** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name         | Description                         |
| ------------ | ----------------------------------- |
| colorFilter1 | Pointer to the first color filter.  |
| colorFilter2 | Pointer to the second color filter. |

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

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **matrix** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name   | Description                                                  |
| ------ | ------------------------------------------------------------ |
| matrix | Matrix, which is represented by a floating-point array with a length of 20. |

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

| Name                   | Description                                      |
| ---------------------- | ------------------------------------------------ |
| OH_Drawing_ColorFilter | Pointer to an **OH_Drawing_ColorFilter** object. |


### OH_Drawing_ColorSetArgb()

```
uint32_t OH_Drawing_ColorSetArgb (uint32_t alpha, uint32_t red, uint32_t green, uint32_t blue )
```

**Description**

Converts four variables (alpha, red, green, and blue) into a 32-bit (ARGB) variable that describes a color.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name  | Description                                           |
| ----- | ----------------------------------------------------- |
| alpha | Alpha, which is a variable ranging from 0x00 to 0xFF. |
| red   | Read, which is a variable ranging from 0x00 to 0xFF.  |
| green | Green, which is a variable ranging from 0x00 to 0xFF. |
| blue  | Blue, which is a variable ranging from 0x00 to 0xFF.  |

**Returns**

Returns a 32-bit (ARGB) variable that describes the color.


### OH_Drawing_ColorSpaceCreateSrgb()

```
OH_Drawing_ColorSpace* OH_Drawing_ColorSpaceCreateSrgb (void )
```

**Description**

Creates an sRGB color space.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Returns**

Returns the pointer to the [OH_Drawing_ColorSpace](#oh_drawing_colorspace) object created.


### OH_Drawing_ColorSpaceCreateSrgbLinear()

```
OH_Drawing_ColorSpace* OH_Drawing_ColorSpaceCreateSrgbLinear (void )
```

**Description**

Creates an sRGB linear (Gamma 1.0) color space.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Returns**

Returns the pointer to the [OH_Drawing_ColorSpace](#oh_drawing_colorspace) object created.


### OH_Drawing_ColorSpaceDestroy()

```
void OH_Drawing_ColorSpaceDestroy (OH_Drawing_ColorSpace* )
```

**Description**

Destroys an **OH_Drawing_ColorSpace** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                  | Description                                                  |
| --------------------- | ------------------------------------------------------------ |
| OH_Drawing_ColorSpace | Pointer to an [OH_Drawing_ColorSpace](#oh_drawing_colorspace) object. |


### OH_Drawing_CreateDashPathEffect()

```
OH_Drawing_PathEffect* OH_Drawing_CreateDashPathEffect (float* intervals, int count, float phase )
```

**Description**

Creates an **OH_Drawing_PathEffect** object with a dashed line effect. The dashed line effect is determined by a group of "on" and "off" intervals.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **intervals** is NULL or **count** is less than or equal to 0, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name      | Description                                                  |
| --------- | ------------------------------------------------------------ |
| intervals | Pointer to the start address of the dashed line interval array. In the array, an even entry indicates an "on" interval and an odd entry indicates an "off" interval. The unit is px. |
| count     | Number of entries in the dashed line interval array. The value must be an even number greater than 0. |
| phase     | Offset in the dashed line interval array.                    |

**Returns**

Returns the pointer to the [OH_Drawing_PathEffect](#oh_drawing_patheffect) object created.


### OH_Drawing_CreateFontCollection()

```
OH_Drawing_FontCollection* OH_Drawing_CreateFontCollection (void )
```

**Description**

Creates an [OH_Drawing_FontCollection](#oh_drawing_fontcollection) object. The [OH_Drawing_FontCollection](#oh_drawing_fontcollection) object created by this function can be used by only one [OH_Drawing_TypographyCreate](#oh_drawing_typographycreate) object. To share an [OH_Drawing_FontCollection](#oh_drawing_fontcollection) object among multiple [OH_Drawing_TypographyCreate](#oh_drawing_typographycreate) objects, use [OH_Drawing_CreateSharedFontCollection](#oh_drawing_createsharedfontcollection) to create it.

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


### OH_Drawing_CreateSharedFontCollection()

```
OH_Drawing_FontCollection* OH_Drawing_CreateSharedFontCollection (void )
```

**Description**

Creates an [OH_Drawing_FontCollection](#oh_drawing_fontcollection) object that is shareable.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Returns**

Returns the pointer to the **OH_Drawing_FontCollection** object created.

### OH_Drawing_ClearFontCaches()

```
void OH_Drawing_ClearFontCaches (OH_Drawing_FontCollection* )
```

**Description**

Clears the font cache. (The font cache has a memory limit and a clearing mechanism. It occupies limited memory. You are not advised to clear it unless otherwise required.)

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                      | Description                                                  |
| ------------------------- | ------------------------------------------------------------ |
| OH_Drawing_FontCollection | Pointer to an [OH_Drawing_FontCollection](#oh_drawing_fontcollection) object. |

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

| Name                        | Description                                                  |
| --------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyCreate | Pointer to an **OH_Drawing_TypographyCreate** object. The pointer is obtained by [OH_Drawing_CreateTypographyHandler](#oh_drawing_createtypographyhandler). |

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

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle | Pointer to an **OH_Drawing_TypographyStyle** object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |
| OH_Drawing_FontCollection  | Pointer to an **OH_Drawing_FontCollection** object, which is obtained by calling [OH_Drawing_CreateFontCollection](#oh_drawing_createfontcollection) or [OH_Drawing_CreateSharedFontCollection](#oh_drawing_createsharedfontcollection) (recommended). |

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

| Name                      | Description                                         |
| ------------------------- | --------------------------------------------------- |
| OH_Drawing_FontCollection | Pointer to an **OH_Drawing_FontCollection** object. |


### OH_Drawing_DestroyFontDescriptor()

```
void OH_Drawing_DestroyFontDescriptor (OH_Drawing_FontDescriptor* )
```

**Description**

Destroys an **OH_Drawing_FontDescriptor** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                                                         | Description                                                  |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) | Pointer to an [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) object, which is obtained by calling [OH_Drawing_CreateFontDescriptor](#oh_drawing_createfontdescriptor). |


### OH_Drawing_DestroyFontParser()

```
void OH_Drawing_DestroyFontParser (OH_Drawing_FontParser* )
```

**Description**

Destroys an **OH_Drawing_FontParser** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                  | Description                                                  |
| --------------------- | ------------------------------------------------------------ |
| OH_Drawing_FontParser | Pointer to an [OH_Drawing_FontParser](#oh_drawing_fontparser) object, which is obtained by calling [OH_Drawing_CreateFontParser](#oh_drawing_createfontparser). |


### OH_Drawing_DestroyLineMetrics()

```
void OH_Drawing_DestroyLineMetrics (OH_Drawing_LineMetrics* )
```

**Description**

Destroys an **OH_Drawing_LineMetrics** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                   | Description                                                  |
| ---------------------- | ------------------------------------------------------------ |
| OH_Drawing_LineMetrics | Pointer to an [OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md) object, which is obtained by calling [OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md). |


### OH_Drawing_DestroySystemFontConfigInfo()

```
void OH_Drawing_DestroySystemFontConfigInfo (OH_Drawing_FontConfigInfo* )
```

**Description**

Reclaims the memory occupied by the system font configuration.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                      | Description                                                  |
| ------------------------- | ------------------------------------------------------------ |
| OH_Drawing_FontConfigInfo | Pointer to an [OH_Drawing_FontConfigInfo](_o_h___drawing___font_config_info.md) object, which is obtained by calling [OH_Drawing_GetSystemFontConfigInfo](#oh_drawing_getsystemfontconfiginfo). |


### OH_Drawing_DestroySystemFontList()

```
void OH_Drawing_DestroySystemFontList (char** , size_t  )
```

**Description**

Reclaims the memory occupied by the system font list.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name     | Description                                      |
| -------- | ------------------------------------------------ |
| char\*\* | Double pointer to the list of system font names. |
| size_t\* | Number of system font names.                     |


### OH_Drawing_DestroyTextShadow()

```
void OH_Drawing_DestroyTextShadow (OH_Drawing_TextShadow* )
```

**Description**

Destroys an **OH_Drawing_TextShadow** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                  | Description                                                  |
| --------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextShadow | Pointer to an [OH_Drawing_TextShadow](#oh_drawing_textshadow) object, which is obtained by calling [OH_Drawing_CreateTextShadow](#oh_drawing_createtextshadow). |


### OH_Drawing_DestroyTextShadows()

```
void OH_Drawing_DestroyTextShadows (OH_Drawing_TextShadow* )
```

**Description**

Reclaims the memory occupied by the vector consisting of the **OH_Drawing_TextShadow** objects.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                  | Description                                                  |
| --------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextShadow | Pointer to an [OH_Drawing_TextShadow](#oh_drawing_textshadow) object, which is obtained by calling [OH_Drawing_CreateTextShadow](#oh_drawing_createtextshadow). |


### OH_Drawing_DestroyTextStyle()

```
void OH_Drawing_DestroyTextStyle (OH_Drawing_TextStyle* )
```

**Description**

Destroys an **OH_Drawing_TextStyle** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |


### OH_Drawing_DestroyTypography()

```
void OH_Drawing_DestroyTypography (OH_Drawing_Typography* )
```

**Description**

Destroys an **OH_Drawing_Typography** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name                  | Description                                                  |
| --------------------- | ------------------------------------------------------------ |
| OH_Drawing_Typography | Pointer to an **OH_Drawing_Typography** object, which is obtained by calling [OH_Drawing_CreateTypography](#oh_drawing_createtypography). |


### OH_Drawing_DestroyTypographyHandler()

```
void OH_Drawing_DestroyTypographyHandler (OH_Drawing_TypographyCreate* )
```

**Description**

Destroys an **OH_Drawing_TypographyCreate** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name                        | Description                                                  |
| --------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyCreate | Pointer to an **OH_Drawing_TypographyCreate** object. The pointer is obtained by [OH_Drawing_CreateTypographyHandler](#oh_drawing_createtypographyhandler). |


### OH_Drawing_DestroyTypographyStyle()

```
void OH_Drawing_DestroyTypographyStyle (OH_Drawing_TypographyStyle* )
```

**Description**

Destroys an **OH_Drawing_TypographyStyle** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle | Pointer to an **OH_Drawing_TypographyStyle** object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |


### OH_Drawing_DisableFontCollectionFallback()

```
void OH_Drawing_DisableFontCollectionFallback (OH_Drawing_FontCollection* fontCollection)
```

**Description**

Disables the alternate fonts.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                      | Description                                                  |
| ------------------------- | ------------------------------------------------------------ |
| OH_Drawing_FontCollection | Pointer to an [OH_Drawing_FontCollection](#oh_drawing_fontcollection) object. |


### OH_Drawing_DisableFontCollectionSystemFont()

```
void OH_Drawing_DisableFontCollectionSystemFont (OH_Drawing_FontCollection* fontCollection)
```

**Description**

Disables the system fonts.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                      | Description                                                  |
| ------------------------- | ------------------------------------------------------------ |
| OH_Drawing_FontCollection | Pointer to an [OH_Drawing_FontCollection](#oh_drawing_fontcollection) object. |


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

| Name              | Description                                 |
| ----------------- | ------------------------------------------- |
| OH_Drawing_Filter | Pointer to an **OH_Drawing_Filter** object. |


### OH_Drawing_FilterGetColorFilter()

```
void OH_Drawing_FilterGetColorFilter (OH_Drawing_Filter* , OH_Drawing_ColorFilter*  )
```

**Description**

Obtains an **OH_Drawing_ColorFilter** object from an **OH_Drawing_Filter** object.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **OH_Drawing_Filter** or **OH_Drawing_ColorFilter** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                   | Description                                                  |
| ---------------------- | ------------------------------------------------------------ |
| OH_Drawing_Filter      | Pointer to an [OH_Drawing_Filter](#oh_drawing_filter) object. |
| OH_Drawing_ColorFilter | Pointer to an [OH_Drawing_ColorFilter](#oh_drawing_colorfilter) object. |


### OH_Drawing_FilterSetColorFilter()

```
void OH_Drawing_FilterSetColorFilter (OH_Drawing_Filter* , OH_Drawing_ColorFilter*  )
```

**Description**

Sets an **OH_Drawing_ColorFilter** object for an **OH_Drawing_Filter** object.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Filter** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name                   | Description                                                  |
| ---------------------- | ------------------------------------------------------------ |
| OH_Drawing_Filter      | Pointer to an **OH_Drawing_Filter** object.                  |
| OH_Drawing_ColorFilter | Pointer to an **OH_Drawing_ColorFilter** object. If NULL is passed in, the color filter effect of the object will be cleared. |


### OH_Drawing_FilterSetMaskFilter()

```
void OH_Drawing_FilterSetMaskFilter (OH_Drawing_Filter* , OH_Drawing_MaskFilter*  )
```

**Description**

Sets an **OH_Drawing_MaskFilter** object for an **OH_Drawing_Filter** object.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Filter** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name                  | Description                                                  |
| --------------------- | ------------------------------------------------------------ |
| OH_Drawing_Filter     | Pointer to an **OH_Drawing_Filter** object.                  |
| OH_Drawing_MaskFilter | Pointer to an **OH_Drawing_MaskFilter** object. If NULL is passed in, the mask filter effect of the object will be cleared. |


### OH_Drawing_FontCountText()

```
int OH_Drawing_FontCountText (OH_Drawing_Font* , const void* text, size_t byteLength, OH_Drawing_TextEncoding encoding )
```

**Description**

Obtains the number of glyphs represented by text.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **OH_Drawing_Font** or **text** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name            | Description                                                  |
| --------------- | ------------------------------------------------------------ |
| OH_Drawing_Font | Pointer to an [OH_Drawing_Font](#oh_drawing_font) object.    |
| text            | Pointer to the start address of the storage.                 |
| byteLength      | Text length, in bytes.                                       |
| encoding        | Encoding type of the text. For details about the available options, see [OH_Drawing_TextEncoding](#oh_drawing_textencoding). |


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

| Name            | Description                               |
| --------------- | ----------------------------------------- |
| OH_Drawing_Font | Pointer to an **OH_Drawing_Font** object. |


### OH_Drawing_FontGetMetrics()

```
float OH_Drawing_FontGetMetrics (OH_Drawing_Font* , OH_Drawing_Font_Metrics*  )
```

**Description**

Obtains the measurement information about a font.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **OH_Drawing_Font** or **OH_Drawing_Font_Metrics** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                    | Description                                                  |
| ----------------------- | ------------------------------------------------------------ |
| OH_Drawing_Font         | Pointer to an [OH_Drawing_Font](#oh_drawing_font) object.    |
| OH_Drawing_Font_Metrics | Pointer to an [OH_Drawing_Font_Metrics](_o_h___drawing___font___metrics.md) object. |

**Returns**

Returns a floating-point variable that indicates the recommended interline spacing.


### OH_Drawing_FontGetTypeface()

```
OH_Drawing_Typeface* OH_Drawing_FontGetTypeface (OH_Drawing_Font* )
```

**Description**

Obtains the typeface of a font.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name            | Description                                               |
| --------------- | --------------------------------------------------------- |
| OH_Drawing_Font | Pointer to an [OH_Drawing_Font](#oh_drawing_font) object. |

**Returns**

Returns the pointer to the [OH_Drawing_Typeface](#oh_drawing_typeface) object.


### OH_Drawing_FontMgrCreate()

```
OH_Drawing_FontMgr* OH_Drawing_FontMgrCreate (void )
```

**Description**

Creates an **OH_Drawing_FontMgr** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Returns**

Returns the pointer to the [OH_Drawing_FontMgr](#oh_drawing_fontmgr) object created.


### OH_Drawing_FontMgrCreateFontStyleSet()

```
OH_Drawing_FontStyleSet* OH_Drawing_FontMgrCreateFontStyleSet (OH_Drawing_FontMgr* , int index )
```

**Description**

Creates a font style set from an **OH_Drawing_FontMgr** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name               | Description                                                  |
| ------------------ | ------------------------------------------------------------ |
| OH_Drawing_FontMgr | Pointer to an [OH_Drawing_FontMgr](#oh_drawing_fontmgr) object, which is obtained by calling [OH_Drawing_FontMgrCreate](#oh_drawing_fontmgrcreate). |
| index              | Index of the font style set.                                 |

**Returns**

Returns the pointer to the [OH_Drawing_FontStyleSet](#oh_drawing_fontstyleset) object created.


### OH_Drawing_FontMgrDestroy()

```
void OH_Drawing_FontMgrDestroy (OH_Drawing_FontMgr* )
```

**Description**

Destroys an **OH_Drawing_FontMgr** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name               | Description                                                  |
| ------------------ | ------------------------------------------------------------ |
| OH_Drawing_FontMgr | Pointer to an [OH_Drawing_FontMgr](#oh_drawing_fontmgr) object, which is obtained by calling [OH_Drawing_FontMgrCreate](#oh_drawing_fontmgrcreate). |


### OH_Drawing_FontMgrDestroyFamilyName()

```
void OH_Drawing_FontMgrDestroyFamilyName (char* familyName)
```

**Description**

Reclaims the memory occupied by a font family name.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name       | Description                    |
| ---------- | ------------------------------ |
| familyName | Pointer to a font family name. |


### OH_Drawing_FontMgrDestroyFontStyleSet()

```
void OH_Drawing_FontMgrDestroyFontStyleSet (OH_Drawing_FontStyleSet* )
```

**Description**

Reclaims the memory occupied by a font style set.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                    | Description                                                  |
| ----------------------- | ------------------------------------------------------------ |
| OH_Drawing_FontStyleSet | Pointer to an [OH_Drawing_FontStyleSet](#oh_drawing_fontstyleset) object. |


### OH_Drawing_FontMgrGetFamilyCount()

```
int OH_Drawing_FontMgrGetFamilyCount (OH_Drawing_FontMgr* )
```

**Description**

Obtains the number of font families.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name               | Description                                                  |
| ------------------ | ------------------------------------------------------------ |
| OH_Drawing_FontMgr | Pointer to an [OH_Drawing_FontMgr](#oh_drawing_fontmgr) object, which is obtained by calling [OH_Drawing_FontMgrCreate](#oh_drawing_fontmgrcreate). |

**Returns**

Returns the number of font families.


### OH_Drawing_FontMgrGetFamilyName()

```
char* OH_Drawing_FontMgrGetFamilyName (OH_Drawing_FontMgr* , int index )
```

**Description**

Obtains the font family name based on an index.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name               | Description                                                  |
| ------------------ | ------------------------------------------------------------ |
| OH_Drawing_FontMgr | Pointer to an [OH_Drawing_FontMgr](#oh_drawing_fontmgr) object, which is obtained by calling [OH_Drawing_FontMgrCreate](#oh_drawing_fontmgrcreate). |
| index              | Index of the font family name.                               |

**Returns**

Returns the font family name.


### OH_Drawing_FontMgrMatchFamily()

```
OH_Drawing_FontStyleSet* OH_Drawing_FontMgrMatchFamily (OH_Drawing_FontMgr* , const char* familyName )
```

**Description**

Obtains a font style set based on a font family name.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name               | Description                                                  |
| ------------------ | ------------------------------------------------------------ |
| OH_Drawing_FontMgr | Pointer to an [OH_Drawing_FontMgr](#oh_drawing_fontmgr) object, which is obtained by calling [OH_Drawing_FontMgrCreate](#oh_drawing_fontmgrcreate). |
| familyName         | Pointer to a font family name.                               |

**Returns**

Returns the pointer to the [OH_Drawing_FontStyleSet](#oh_drawing_fontstyleset) object obtained.


### OH_Drawing_FontMgrMatchFamilyStyle()

```
OH_Drawing_Typeface* OH_Drawing_FontMgrMatchFamilyStyle (OH_Drawing_FontMgr* , const char* familyName, OH_Drawing_FontStyleStruct  )
```

**Description**

Obtains a typeface based on the font style information and font family name.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                                                         | Description                                                  |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| OH_Drawing_FontMgr                                           | Pointer to an [OH_Drawing_FontMgr](#oh_drawing_fontmgr) object, which is obtained by calling [OH_Drawing_FontMgrCreate](#oh_drawing_fontmgrcreate). |
| familyName                                                   | Pointer to a font family name.                               |
| [OH_Drawing_FontStyleStruct](_o_h___drawing___font_style_struct.md) | Font style, including the font weight, width, and slant.     |

**Returns**

Returns the pointer to the [OH_Drawing_Typeface](#oh_drawing_typeface) object obtained.


### OH_Drawing_FontMgrMatchFamilyStyleCharacter()

```
OH_Drawing_Typeface* OH_Drawing_FontMgrMatchFamilyStyleCharacter (OH_Drawing_FontMgr* , const char* familyName, OH_Drawing_FontStyleStruct , const char* bcp47[], int bcp47Count, int32_t character )
```

**Description**

Obtains a typeface for the specified character.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                                                         | Description                                                  |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| OH_Drawing_FontMgr                                           | Pointer to an [OH_Drawing_FontMgr](#oh_drawing_fontmgr) object, which is obtained by calling [OH_Drawing_FontMgrCreate](#oh_drawing_fontmgrcreate). |
| familyName                                                   | Pointer to a font family name.                               |
| [OH_Drawing_FontStyleStruct](_o_h___drawing___font_style_struct.md) | Font style, including the font weight, width, and slant.     |
| bcp47                                                        | Pointer to the character language code array, which is a combination of ISO 639, 15924, and 3166-1 language codes. |
| bcp47Count                                                   | Size of the character language code array.                   |
| character                                                    | UTF8 character used for matching.                            |

**Returns**

Returns the pointer to the [OH_Drawing_Typeface](#oh_drawing_typeface) object obtained.


### OH_Drawing_FontParserGetFontByName()

```
OH_Drawing_FontDescriptor* OH_Drawing_FontParserGetFontByName (OH_Drawing_FontParser* , const char*  )
```

**Description**

Obtains the descriptor of a system font based on the font name.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                  | Description                                                  |
| --------------------- | ------------------------------------------------------------ |
| OH_Drawing_FontParser | Pointer to an [OH_Drawing_FontParser](#oh_drawing_fontparser) object, which is obtained by calling [OH_Drawing_CreateFontParser](#oh_drawing_createfontparser). |
| char\*                | Pointer to the system font name.                             |

**Returns**

Returns the system font.


### OH_Drawing_FontParserGetSystemFontList()

```
char** OH_Drawing_FontParserGetSystemFontList (OH_Drawing_FontParser* , size_t*  )
```

**Description**

Obtains the list of system fonts. This function can be used only on 2-in-1 devices.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                  | Description                                                  |
| --------------------- | ------------------------------------------------------------ |
| OH_Drawing_FontParser | Pointer to an [OH_Drawing_FontParser](#oh_drawing_fontparser) object, which is obtained by calling [OH_Drawing_CreateFontParser](#oh_drawing_createfontparser). |
| size_t                | Pointer to the number of system font names.                  |

**Returns**

Returns the system font list.


### OH_Drawing_FontSetFakeBoldText()

```
void OH_Drawing_FontSetFakeBoldText (OH_Drawing_Font* , bool isFakeBoldText )
```

**Description**

Sets fake bold for a font by increasing the stroke width.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name            | Description                                                  |
| --------------- | ------------------------------------------------------------ |
| OH_Drawing_Font | Pointer to an **OH_Drawing_Font** object.                    |
| isFakeBoldText  | Whether to set fake bold. The value **true** means to set fake bold, and **false** means the opposite. |


### OH_Drawing_FontSetLinearText()

```
void OH_Drawing_FontSetLinearText (OH_Drawing_Font* , bool isLinearText )
```

**Description**

Sets linear scaling for a font.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name            | Description                                                  |
| --------------- | ------------------------------------------------------------ |
| OH_Drawing_Font | Pointer to an **OH_Drawing_Font** object.                    |
| isLinearText    | Whether to enable linear scaling. The value **true** means to enable linear scaling, and **false** means the opposite. |


### OH_Drawing_FontSetTextSize()

```
void OH_Drawing_FontSetTextSize (OH_Drawing_Font* , float textSize )
```

**Description**

Sets the font size.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name            | Description                               |
| --------------- | ----------------------------------------- |
| OH_Drawing_Font | Pointer to an **OH_Drawing_Font** object. |
| textSize        | Font size.                                |


### OH_Drawing_FontSetTextSkewX()

```
void OH_Drawing_FontSetTextSkewX (OH_Drawing_Font* , float skewX )
```

**Description**

Sets a horizontal skew factor for a font.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name            | Description                                |
| --------------- | ------------------------------------------ |
| OH_Drawing_Font | Pointer to an **OH_Drawing_Font** object.  |
| skewX           | Skew of the X axis relative to the Y axis. |


### OH_Drawing_FontSetTypeface()

```
void OH_Drawing_FontSetTypeface (OH_Drawing_Font* , OH_Drawing_Typeface*  )
```

**Description**

Sets the typeface for a font.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name                | Description                                                  |
| ------------------- | ------------------------------------------------------------ |
| OH_Drawing_Font     | Pointer to an **OH_Drawing_Font** object.                    |
| OH_Drawing_Typeface | Pointer to an **OH_Drawing_Typeface** object. If NULL is passed in, the default **OH_Drawing_Typeface** object is used. |


### OH_Drawing_FontStyleSetCount()

```
int OH_Drawing_FontStyleSetCount (OH_Drawing_FontStyleSet* )
```

**Description**

Obtains the number of fonts in the font style set.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                    | Description                                                  |
| ----------------------- | ------------------------------------------------------------ |
| OH_Drawing_FontStyleSet | Pointer to an [OH_Drawing_FontStyleSet](#oh_drawing_fontstyleset) object. |

**Returns**

Returns the number of fonts.


### OH_Drawing_FontStyleSetCreateTypeface()

```
OH_Drawing_Typeface* OH_Drawing_FontStyleSetCreateTypeface (OH_Drawing_FontStyleSet* , int index )
```

**Description**

Creates a typeface for the specified index.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                    | Description                                                  |
| ----------------------- | ------------------------------------------------------------ |
| OH_Drawing_FontStyleSet | Pointer to an [OH_Drawing_FontStyleSet](#oh_drawing_fontstyleset) object. |
| index                   | Index of the typeface.                                       |

**Returns**

Returns the pointer to the [OH_Drawing_Typeface](#oh_drawing_typeface) object created if the operation is successful; returns a null pointer otherwise.


### OH_Drawing_FontStyleSetFreeStyleName()

```
void OH_Drawing_FontStyleSetFreeStyleName (char** styleName)
```

**Description**

Reclaims the memory occupied by a font style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name      | Description                                                  |
| --------- | ------------------------------------------------------------ |
| styleName | Double pointer to the string that specifies the font style name. |


### OH_Drawing_FontStyleSetGetStyle()

```
OH_Drawing_FontStyleStruct OH_Drawing_FontStyleSetGetStyle (OH_Drawing_FontStyleSet* , int32_t index, char** styleName )
```

**Description**

Obtains the font style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                    | Description                                                  |
| ----------------------- | ------------------------------------------------------------ |
| OH_Drawing_FontStyleSet | Pointer to an [OH_Drawing_FontStyleSet](#oh_drawing_fontstyleset) object. |
| index                   | Index of the font style.                                     |
| styleName               | Double pointer to the string that specifies the font style name. |

**Returns**

Returns the font style.


### OH_Drawing_FontStyleSetMatchStyle()

```
OH_Drawing_Typeface* OH_Drawing_FontStyleSetMatchStyle (OH_Drawing_FontStyleSet* , OH_Drawing_FontStyleStruct fontStyleStruct )
```

**Description**

Obtains the typeface closest to the font style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                    | Description                                                  |
| ----------------------- | ------------------------------------------------------------ |
| OH_Drawing_FontStyleSet | Pointer to an [OH_Drawing_FontStyleSet](#oh_drawing_fontstyleset) object. |
| fontStyleStruct         | Font style, including the font weight, width, and slant.     |

**Returns**

Returns the pointer to the [OH_Drawing_Typeface](#oh_drawing_typeface) object obtained.


### OH_Drawing_GetAffinityFromPositionAndAffinity()

```
int OH_Drawing_GetAffinityFromPositionAndAffinity (OH_Drawing_PositionAndAffinity* )
```

**Description**

Obtains the affinity attribute of an **OH_Drawing_PositionAndAffinity** object. The affinity determines whether the font is close to the front text or rear text.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name                           | Description                                                  |
| ------------------------------ | ------------------------------------------------------------ |
| OH_Drawing_PositionAndAffinity | Pointer to an **OH_Drawing_PositionAndAffinity** object, which is obtained by calling [OH_Drawing_TypographyGetGlyphPositionAtCoordinate](#oh_drawing_typographygetglyphpositionatcoordinate) or [OH_Drawing_TypographyGetGlyphPositionAtCoordinateWithCluster](#oh_drawing_typographygetglyphpositionatcoordinatewithcluster). |

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

| Name               | Description                                                  |
| ------------------ | ------------------------------------------------------------ |
| OH_Drawing_TextBox | Pointer to an **OH_Drawing_TextBox** object, which is obtained by calling [OH_Drawing_TypographyGetRectsForRange](#oh_drawing_typographygetrectsforrange) or [OH_Drawing_TypographyGetRectsForPlaceholders](#oh_drawing_typographygetrectsforplaceholders). |
| int                | Index of the text box.                                       |

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

| Name             | Description                                                  |
| ---------------- | ------------------------------------------------------------ |
| OH_Drawing_Range | Pointer to an **OH_Drawing_Range** object, which is obtained by calling [OH_Drawing_TypographyGetWordBoundary](#oh_drawing_typographygetwordboundary). |

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

| Name               | Description                                                  |
| ------------------ | ------------------------------------------------------------ |
| OH_Drawing_TextBox | Pointer to an **OH_Drawing_TextBox** object, which is obtained by calling [OH_Drawing_TypographyGetRectsForRange](#oh_drawing_typographygetrectsforrange) or [OH_Drawing_TypographyGetRectsForPlaceholders](#oh_drawing_typographygetrectsforplaceholders). |
| int                | Index of the text box.                                       |

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

| Name                           | Description                                                  |
| ------------------------------ | ------------------------------------------------------------ |
| OH_Drawing_PositionAndAffinity | Pointer to an **OH_Drawing_PositionAndAffinity** object, which is obtained by calling [OH_Drawing_TypographyGetGlyphPositionAtCoordinate](#oh_drawing_typographygetglyphpositionatcoordinate) or [OH_Drawing_TypographyGetGlyphPositionAtCoordinateWithCluster](#oh_drawing_typographygetglyphpositionatcoordinatewithcluster). |

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

| Name               | Description                                                  |
| ------------------ | ------------------------------------------------------------ |
| OH_Drawing_TextBox | Pointer to an **OH_Drawing_TextBox** object, which is obtained by calling [OH_Drawing_TypographyGetRectsForRange](#oh_drawing_typographygetrectsforrange) or [OH_Drawing_TypographyGetRectsForPlaceholders](#oh_drawing_typographygetrectsforplaceholders). |
| int                | Index of the text box.                                       |

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

| Name               | Description                                                  |
| ------------------ | ------------------------------------------------------------ |
| OH_Drawing_TextBox | Pointer to an **OH_Drawing_TextBox** object, which is obtained by calling [OH_Drawing_TypographyGetRectsForRange](#oh_drawing_typographygetrectsforrange) or [OH_Drawing_TypographyGetRectsForPlaceholders](#oh_drawing_typographygetrectsforplaceholders). |

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

| Name             | Description                                                  |
| ---------------- | ------------------------------------------------------------ |
| OH_Drawing_Range | Pointer to an **OH_Drawing_Range** object, which is obtained by calling [OH_Drawing_TypographyGetWordBoundary](#oh_drawing_typographygetwordboundary). |

**Returns**

Returns the start position.


### OH_Drawing_GetSystemFontConfigInfo()

```
OH_Drawing_FontConfigInfo* OH_Drawing_GetSystemFontConfigInfo (OH_Drawing_FontConfigInfoErrorCode* )
```

**Description**

Obtains the system font configuration.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                              | Description                                                  |
| --------------------------------- | ------------------------------------------------------------ |
| OH_Drawing_FontConfigJsonInfoCode | Pointer to the error code. For details about the available options, see [OH_Drawing_FontConfigInfoErrorCode](#oh_drawing_fontconfiginfoerrorcode). |

**Returns**

Returns the pointer to the system font configuration.


### OH_Drawing_GetTextDirectionFromTextBox()

```
int OH_Drawing_GetTextDirectionFromTextBox (OH_Drawing_TextBox* , int  )
```

**Description**

Obtains the text direction of a text box.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name               | Description                                                  |
| ------------------ | ------------------------------------------------------------ |
| OH_Drawing_TextBox | Pointer to an **OH_Drawing_TextBox** object, which is obtained by calling [OH_Drawing_TypographyGetRectsForRange](#oh_drawing_typographygetrectsforrange) or [OH_Drawing_TypographyGetRectsForPlaceholders](#oh_drawing_typographygetrectsforplaceholders). |
| int                | Index of the text box.                                       |

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

| Name               | Description                                                  |
| ------------------ | ------------------------------------------------------------ |
| OH_Drawing_TextBox | Pointer to an **OH_Drawing_TextBox** object, which is obtained by calling [OH_Drawing_TypographyGetRectsForRange](#oh_drawing_typographygetrectsforrange) or [OH_Drawing_TypographyGetRectsForPlaceholders](#oh_drawing_typographygetrectsforplaceholders). |
| int                | Index of the text box.                                       |

**Returns**

Returns the top position.


### OH_Drawing_GpuContextCreateFromGL()

```
OH_Drawing_GpuContext* OH_Drawing_GpuContextCreateFromGL (OH_Drawing_GpuContextOptions )
```

**Description**

Creates an **OH_Drawing_GpuContext** object that uses OpenGL as the backend interface.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                         | Description                                                  |
| ---------------------------- | ------------------------------------------------------------ |
| OH_Drawing_GpuContextOptions | GPU context option, which is an [OH_Drawing_GpuContextOptions](_o_h___drawing___gpu_context_options.md) object. |

**Returns**

Returns the pointer to the [OH_Drawing_GpuContext](#oh_drawing_gpucontext) object created.


### OH_Drawing_GpuContextDestroy()

```
void OH_Drawing_GpuContextDestroy (OH_Drawing_GpuContext* )
```

**Description**

Destroys an **OH_Drawing_GpuContext** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                  | Description                                                  |
| --------------------- | ------------------------------------------------------------ |
| OH_Drawing_GpuContext | Pointer to an [OH_Drawing_GpuContext](#oh_drawing_gpucontext) object. |


### OH_Drawing_ImageBuildFromBitmap()

```
bool OH_Drawing_ImageBuildFromBitmap (OH_Drawing_Image* , OH_Drawing_Bitmap*  )
```

**Description**

Builds an image from a bitmap by sharing or copying bitmap pixels. If the bitmap is marked as immutable, the pixel memory is shared, not copied.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **OH_Drawing_Image** or **OH_Drawing_Bitmap** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name              | Description                                                  |
| ----------------- | ------------------------------------------------------------ |
| OH_Drawing_Image  | Pointer to an [OH_Drawing_Image](#oh_drawing_image) object.  |
| OH_Drawing_Bitmap | Pointer to an [OH_Drawing_Bitmap](#oh_drawing_bitmap) object. |

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

| Name             | Description                                                 |
| ---------------- | ----------------------------------------------------------- |
| OH_Drawing_Image | Pointer to an [OH_Drawing_Image](#oh_drawing_image) object. |


### OH_Drawing_ImageGetHeight()

```
int32_t OH_Drawing_ImageGetHeight (OH_Drawing_Image* )
```

**Description**

Obtains the image height, that is, the number of pixel lines.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Image** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name             | Description                                                 |
| ---------------- | ----------------------------------------------------------- |
| OH_Drawing_Image | Pointer to an [OH_Drawing_Image](#oh_drawing_image) object. |

**Returns**

Returns the height.


### OH_Drawing_ImageGetImageInfo()

```
void OH_Drawing_ImageGetImageInfo (OH_Drawing_Image* , OH_Drawing_Image_Info*  )
```

**Description**

Obtains the image information. After this function is called, the passed-in image information object is filled.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **OH_Drawing_Image** or **OH_Drawing_Image_Info** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                  | Description                                                  |
| --------------------- | ------------------------------------------------------------ |
| OH_Drawing_Image      | Pointer to an [OH_Drawing_Image](#oh_drawing_image) object.  |
| OH_Drawing_Image_Info | Pointer to an [OH_Drawing_Image_Info](_o_h___drawing___image___info.md) object, which is created by calling [OH_Drawing_Image_Info](_o_h___drawing___image___info.md). |


### OH_Drawing_ImageGetWidth()

```
int32_t OH_Drawing_ImageGetWidth (OH_Drawing_Image* )
```

**Description**

Obtains the image width, that is, the number of pixels in each line.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Image** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name             | Description                                                 |
| ---------------- | ----------------------------------------------------------- |
| OH_Drawing_Image | Pointer to an [OH_Drawing_Image](#oh_drawing_image) object. |

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

| Name                                                       | Description                                                  |
| ---------------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md) | Pointer to an [OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md) object, which is obtained by calling [OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md). |

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

| Name       | Description                                                  |
| ---------- | ------------------------------------------------------------ |
| blurType   | Blur type.                                                   |
| sigma      | Standard deviation of the Gaussian blur to apply. The value must be greater than 0. |
| respectCTM | Whether the blur's sigma is modified by the CTM. The default value is **true**. |

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

| Name                  | Description                                     |
| --------------------- | ----------------------------------------------- |
| OH_Drawing_MaskFilter | Pointer to an **OH_Drawing_MaskFilter** object. |


### OH_Drawing_MatrixConcat()

```
void OH_Drawing_MatrixConcat (OH_Drawing_Matrix* total, const OH_Drawing_Matrix* a, const OH_Drawing_Matrix* b )
```

**Description**

Multiplies two matrices to produce a new matrix.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If any of **total**, **a**, and **b** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name  | Description                                                  |
| ----- | ------------------------------------------------------------ |
| total | Pointer to the new matrix, which is an [OH_Drawing_Matrix](#oh_drawing_matrix) object. |
| a     | Pointer to the first matrix, which is an [OH_Drawing_Matrix](#oh_drawing_matrix) object. |
| b     | Pointer to the second matrix, which is an [OH_Drawing_Matrix](#oh_drawing_matrix) object. |


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

Creates an **OH_Drawing_Matrix** with the rotation attribute. The matrix is obtained by rotating an identity matrix by a given degree around the rotation point (x, y).

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name | Description                                                  |
| ---- | ------------------------------------------------------------ |
| deg  | Angle to rotate, in degrees. A positive value indicates a clockwise rotation, and a negative value indicates a counterclockwise rotation. |
| x    | Coordinate point on the X axis.                              |
| y    | Coordinate point on the Y axis.                              |

**Returns**

Returns the pointer to the [OH_Drawing_Matrix](#oh_drawing_matrix) object created.


### OH_Drawing_MatrixCreateScale()

```
OH_Drawing_Matrix* OH_Drawing_MatrixCreateScale (float sx, float sy, float px, float py )
```

**Description**

Creates an **OH_Drawing_Matrix** with the scale attribute. The matrix is obtained by scaling an identity matrix with the factor (sx, sy) at the rotation point (px, py).

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name | Description                     |
| ---- | ------------------------------- |
| sx   | Scale factor on the X axis.     |
| sy   | Scale factor on the Y axis.     |
| px   | Coordinate point on the X axis. |
| py   | Coordinate point on the Y axis. |

**Returns**

Returns the pointer to the [OH_Drawing_Matrix](#oh_drawing_matrix) object created.


### OH_Drawing_MatrixCreateTranslation()

```
OH_Drawing_Matrix* OH_Drawing_MatrixCreateTranslation (float dx, float dy )
```

**Description**

Creates an **OH_Drawing_Matrix** with the translation attribute. The matrix is obtained by translating the identity matrix by the distance (dx, dy).

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name | Description                          |
| ---- | ------------------------------------ |
| dx   | Distance to translate on the X axis. |
| dy   | Distance to translate on the Y axis. |

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

| Name              | Description                               |
| ----------------- | ----------------------------------------- |
| OH_Drawing_Matrix | Pointer to an **OH_Drawing_Font** object. |


### OH_Drawing_MatrixGetValue()

```
float OH_Drawing_MatrixGetValue (OH_Drawing_Matrix* , int index )
```

**Description**

Obtains a matrix value of a given index, which ranges from 0 to 8.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Matrix** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

If **index** is less than 0 or greater than 8, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name              | Description                                                  |
| ----------------- | ------------------------------------------------------------ |
| OH_Drawing_Matrix | Pointer to an [OH_Drawing_Matrix](#oh_drawing_matrix) object. |
| index             | Index, which ranges from 0 to 8.                             |

**Returns**

Returns the matrix value.


### OH_Drawing_MatrixInvert()

```
bool OH_Drawing_MatrixInvert (OH_Drawing_Matrix* , OH_Drawing_Matrix* inverse )
```

**Description**

Inverts a matrix and returns the result.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **OH_Drawing_Matrix** or **inverse** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name              | Description                                                  |
| ----------------- | ------------------------------------------------------------ |
| OH_Drawing_Matrix | Pointer to an [OH_Drawing_Matrix](#oh_drawing_matrix) object. |
| inverse           | Pointer to the matrix to invert, which is an [OH_Drawing_Matrix](#oh_drawing_matrix) object. The object can be created by calling [OH_Drawing_MatrixCreate](#oh_drawing_matrixcreate). |

**Returns**

Returns **true** if the matrix is reversible and the passed-in **inverse** is inverted; returns **false** otherwise.


### OH_Drawing_MatrixIsEqual()

```
bool OH_Drawing_MatrixIsEqual (OH_Drawing_Matrix* , OH_Drawing_Matrix* other )
```

**Description**

Checks whether two **OH_Drawing_Matrix** objects are equal.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **OH_Drawing_Matrix** or **other** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name              | Description                                                  |
| ----------------- | ------------------------------------------------------------ |
| OH_Drawing_Matrix | Pointer to a matrix, which is an [OH_Drawing_Matrix](#oh_drawing_matrix) object. |
| other             | Pointer to the other matrix, which is an [OH_Drawing_Matrix](#oh_drawing_matrix) object. |

**Returns**

Returns **true** if the two matrices are equal; returns **false** otherwise.


### OH_Drawing_MatrixIsIdentity()

```
bool OH_Drawing_MatrixIsIdentity (OH_Drawing_Matrix* )
```

**Description**

Checks whether an **OH_Drawing_Matrix** object is an identity matrix.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Matrix** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name              | Description                                                  |
| ----------------- | ------------------------------------------------------------ |
| OH_Drawing_Matrix | Pointer to an [OH_Drawing_Matrix](#oh_drawing_matrix) object. |

**Returns**

Returns **true** if the matrix is an identity matrix; returns **false** otherwise.


### OH_Drawing_MatrixPostRotate()

```
void OH_Drawing_MatrixPostRotate (OH_Drawing_Matrix* , float degree, float px, float py )
```

**Description**

Post multiplies a matrix by an identity matrix that rotates a given degree around the rotation point (px, py).

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Matrix** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name              | Description                                                  |
| ----------------- | ------------------------------------------------------------ |
| OH_Drawing_Matrix | Pointer to an [OH_Drawing_Matrix](#oh_drawing_matrix) object. |
| degree            | Angle to rotate, in degrees. A positive value indicates a clockwise rotation, and a negative value indicates a counterclockwise rotation. |
| px                | X coordinate of the rotation point.                          |
| py                | Y coordinate of the rotation point.                          |


### OH_Drawing_MatrixPostScale()

```
void OH_Drawing_MatrixPostScale (OH_Drawing_Matrix* , float sx, float sy, float px, float py )
```

**Description**

Post multiplies a matrix by an identity matrix that scales with the factor (sx, sy) at the scale point (px, py).

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Matrix** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.


**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name              | Description                                                  |
| ----------------- | ------------------------------------------------------------ |
| OH_Drawing_Matrix | Pointer to an [OH_Drawing_Matrix](#oh_drawing_matrix) object. |
| sx                | Scale factor on the X axis.                                  |
| sy                | Scale factor on the Y axis.                                  |
| px                | X coordinate of the scale point.                             |
| py                | Y coordinate of the scale point.                             |


### OH_Drawing_MatrixPostTranslate()

```
void OH_Drawing_MatrixPostTranslate (OH_Drawing_Matrix* , float dx, float dy )
```

**Description**

Post multiplies a matrix by an identity matrix that translates by a given distance (dx, dy).

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Matrix** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.


**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name              | Description                                                  |
| ----------------- | ------------------------------------------------------------ |
| OH_Drawing_Matrix | Pointer to an [OH_Drawing_Matrix](#oh_drawing_matrix) object. |
| dx                | Distance to translate on the X axis.                         |
| dy                | Distance to translate on the Y axis.                         |


### OH_Drawing_MatrixPreRotate()

```
void OH_Drawing_MatrixPreRotate (OH_Drawing_Matrix* , float degree, float px, float py )
```

**Description**

Premultiplies a matrix by an identity matrix that rotates by a given degree around the rotation point (px, py).

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Matrix** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.


**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name              | Description                                                  |
| ----------------- | ------------------------------------------------------------ |
| OH_Drawing_Matrix | Pointer to an [OH_Drawing_Matrix](#oh_drawing_matrix) object. |
| degree            | Angle to rotate, in degrees. A positive value indicates a clockwise rotation, and a negative value indicates a counterclockwise rotation. |
| px                | X coordinate of the rotation point.                          |
| py                | Y coordinate of the rotation point.                          |


### OH_Drawing_MatrixPreScale()

```
void OH_Drawing_MatrixPreScale (OH_Drawing_Matrix* , float sx, float sy, float px, float py )
```

**Description**

Premultiplies a matrix by an identity matrix that scales with the factor (sx, sy) at the scale point (px, py).

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Matrix** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.


**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name              | Description                                                  |
| ----------------- | ------------------------------------------------------------ |
| OH_Drawing_Matrix | Pointer to an [OH_Drawing_Matrix](#oh_drawing_matrix) object. |
| sx                | Scale factor on the X axis.                                  |
| sy                | Scale factor on the Y axis.                                  |
| px                | X coordinate of the scale point.                             |
| py                | Y coordinate of the scale point.                             |


### OH_Drawing_MatrixPreTranslate()

```
void OH_Drawing_MatrixPreTranslate (OH_Drawing_Matrix* , float dx, float dy )
```

**Description**

Premultiplies a matrix by an identity matrix that translates by a given distance (dx, dy).

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Matrix** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name              | Description                                                  |
| ----------------- | ------------------------------------------------------------ |
| OH_Drawing_Matrix | Pointer to an [OH_Drawing_Matrix](#oh_drawing_matrix) object. |
| dx                | Distance to translate on the X axis.                         |
| dy                | Distance to translate on the Y axis.                         |


### OH_Drawing_MatrixReset()

```
void OH_Drawing_MatrixReset (OH_Drawing_Matrix* )
```

**Description**

Resets a matrix to an identity matrix: | 1 0 0 | | 0 1 0 | | 0 0 0 1 |.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Matrix** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name              | Description                                                  |
| ----------------- | ------------------------------------------------------------ |
| OH_Drawing_Matrix | Pointer to an [OH_Drawing_Matrix](#oh_drawing_matrix) object. |


### OH_Drawing_MatrixRotate()

```
void OH_Drawing_MatrixRotate (OH_Drawing_Matrix* , float degree, float px, float py )
```

**Description**

Sets a matrix as an identity matrix and rotates it by a given degree around the rotation point (px, py).

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Matrix** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name              | Description                                                  |
| ----------------- | ------------------------------------------------------------ |
| OH_Drawing_Matrix | Pointer to an [OH_Drawing_Matrix](#oh_drawing_matrix) object. |
| degree            | Angle to rotate, in degrees. A positive value indicates a clockwise rotation, and a negative value indicates a counterclockwise rotation. |
| px                | Coordinate point on the X axis.                              |
| py                | Coordinate point on the Y axis.                              |


### OH_Drawing_MatrixScale()

```
void OH_Drawing_MatrixScale (OH_Drawing_Matrix* , float sx, float sy, float px, float py )
```

**Description**

Sets a matrix as an identity matrix and scales it with the factor (sx, sy) at the rotation point (px, py).

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Matrix** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name              | Description                                                  |
| ----------------- | ------------------------------------------------------------ |
| OH_Drawing_Matrix | Pointer to an [OH_Drawing_Matrix](#oh_drawing_matrix) object. |
| sx                | Scale factor on the X axis.                                  |
| sy                | Scale factor on the Y axis.                                  |
| px                | Coordinate point on the X axis.                              |
| py                | Coordinate point on the Y axis.                              |


### OH_Drawing_MatrixSetMatrix()

```
void OH_Drawing_MatrixSetMatrix (OH_Drawing_Matrix* , float scaleX, float skewX, float transX, float skewY, float scaleY, float transY, float persp0, float persp1, float persp2 )
```

**Description**

Sets matrix parameters for an **OH_Drawing_Matrix** object.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Matrix** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name              | Description                                 |
| ----------------- | ------------------------------------------- |
| OH_Drawing_Matrix | Pointer to an **OH_Drawing_Matrix** object. |
| scaleX            | Scale factor on the X axis.                 |
| skewX             | Skew factor on the X axis.                  |
| transX            | Translation coefficient on the X axis.      |
| skewY             | Skew factor on the Y axis.                  |
| scaleY            | Scale factor on the Y axis.                 |
| transY            | Translation coefficient on the Y axis.      |
| persp0            | Perspective coefficient of the X axis.      |
| persp1            | Perspective coefficient of the Y axis.      |
| persp2            | Perspective scale coefficient.              |


### OH_Drawing_MatrixSetPolyToPoly()

```
bool OH_Drawing_MatrixSetPolyToPoly (OH_Drawing_Matrix* , const OH_Drawing_Point2D* src, const OH_Drawing_Point2D* dst, uint32_t count )
```

**Description**

Generates a transformation matrix by setting source points and destination points. Both the number of source points and that of destination points must be in the range [0, 4].

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Matrix** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

If **count** is less than 0 or greater than 4, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name              | Description                                                  |
| ----------------- | ------------------------------------------------------------ |
| OH_Drawing_Matrix | Pointer to an [OH_Drawing_Matrix](#oh_drawing_matrix) object. |
| src               | Array of source points. If NULL is passed in, **count** must be 0. |
| dst               | Array of destination points. The number of destination points must be the same as that of source points. If NULL is passed in, **count** must be 0. |
| count             | Number of source points or destination points. If 0 is passed in, the matrix is set to an identity matrix. |

**Returns**

Returns **true** if the matrix is generated; returns **false** otherwise.


### OH_Drawing_MatrixSetRectToRect()

```
bool OH_Drawing_MatrixSetRectToRect (OH_Drawing_Matrix* , const OH_Drawing_Rect* src, const OH_Drawing_Rect* dst, OH_Drawing_ScaleToFit stf )
```

**Description**

Scales a matrix to map a source rectangle to a destination rectangle.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If any of **OH_Drawing_Matrix**, **src**, and **dst** is NULL, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name              | Description                                                  |
| ----------------- | ------------------------------------------------------------ |
| OH_Drawing_Matrix | Pointer to an [OH_Drawing_Matrix](#oh_drawing_matrix) object. |
| src               | Pointer to a source rectangle, which is an [OH_Drawing_Rect](#oh_drawing_rect) object. |
| dst               | Pointer to a destination rectangle, which is an [OH_Drawing_Rect](#oh_drawing_rect) object. |
| stf               | Scaling mode. For details about the available options, see [OH_Drawing_ScaleToFit](#oh_drawing_scaletofit). |

**Returns**

Returns **true** if the operation is successful; returns **false** if the operation fails; returns **true** and sets the matrix to |0 0 0| |0 0 0| |0 0 1| if the passed-in matrix is empty.

### OH_Drawing_MatrixTranslate()

```
void OH_Drawing_MatrixTranslate (OH_Drawing_Matrix* , float dx, float dy )
```

**Description**

Sets a matrix as an identity matrix and translates it by a given distance (dx, dy).

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Matrix** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name              | Description                                                  |
| ----------------- | ------------------------------------------------------------ |
| OH_Drawing_Matrix | Pointer to an [OH_Drawing_Matrix](#oh_drawing_matrix) object. |
| dx                | Distance to translate on the X axis.                         |
| dy                | Distance to translate on the Y axis.                         |


### OH_Drawing_MemoryStreamCreate()

```
OH_Drawing_MemoryStream* OH_Drawing_MemoryStreamCreate (const void* data, size_t length, bool copyData )
```

**Description**

Creates an **OH_Drawing_MemoryStream** object.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **data** is NULL or **length** is **0**, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name     | Description                                                  |
| -------- | ------------------------------------------------------------ |
| data     | Pointer to the data.                                         |
| length   | Length of the data.                                          |
| copyData | Whether to copy data. The value **true** means that the **OH_Drawing_MemoryStream** object copies the data, and **false** means that the **OH_Drawing_MemoryStream** object directly uses the data without copying. |

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

| Name                    | Description                                                  |
| ----------------------- | ------------------------------------------------------------ |
| OH_Drawing_MemoryStream | Pointer to an [OH_Drawing_MemoryStream](#oh_drawing_memorystream) object. |


### OH_Drawing_PathAddArc()

```
void OH_Drawing_PathAddArc (OH_Drawing_Path* , const OH_Drawing_Rect* , float startAngle, float sweepAngle )
```

**Description**

Adds an arc to a path as the start of a new contour. The arc added is part of the ellipse bounded by oval, from the start angle through the sweep angle, measured in degrees. A positive angle indicates a clockwise sweep, and a negative angle indicates a counterclockwise sweep. If the sweep angle is less than or equal to -360°, or if the sweep angle is greater than or equal to 360° and start angle modulo 90 is nearly zero, an oval instead of an ellipse is added.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **OH_Drawing_Path** or **OH_Drawing_Rect** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name            | Description                                                  |
| --------------- | ------------------------------------------------------------ |
| OH_Drawing_Path | Pointer to an [OH_Drawing_Path](#oh_drawing_path) object.    |
| OH_Drawing_Rect | Pointer to an [OH_Drawing_Rect](#oh_drawing_rect) object.    |
| startAngle      | Start angle of the arc, in degrees.                          |
| sweepAngle      | Angle to sweep, in degrees. A positive number indicates a clockwise sweep, and a negative value indicates a counterclockwise swipe. The actual swipe degree is the modulo operation result of the input parameter by 360. |

### OH_Drawing_PathAddOval()

```
void OH_Drawing_PathAddOval (OH_Drawing_Path* , const OH_Drawing_Rect* , OH_Drawing_PathDirection  )
```

**Description**

Adds an oval to a path in the specified direction.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **OH_Drawing_Path** or **OH_Drawing_Rect** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

If **OH_Drawing_PathDirection** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                     | Description                                                  |
| ------------------------ | ------------------------------------------------------------ |
| OH_Drawing_Path          | Pointer to an [OH_Drawing_Path](#oh_drawing_path) object.    |
| OH_Drawing_Rect          | Pointer to an [OH_Drawing_Rect](#oh_drawing_rect) object.    |
| OH_Drawing_PathDirection | Path direction. For details about the available options, see [OH_Drawing_PathDirection](#oh_drawing_pathdirection). |

### OH_Drawing_PathAddOvalWithInitialPoint()

```
void OH_Drawing_PathAddOvalWithInitialPoint (OH_Drawing_Path* , const OH_Drawing_Rect* , uint32_t start, OH_Drawing_PathDirection  )
```

**Description**

Adds an oval to a path. **OH_Drawing_Rect** specifies the outer tangent rectangle of the oval, and **OH_Drawing_PathDirection** specifies whether the drawing is clockwise or anticlockwise.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **OH_Drawing_Path** or **OH_Drawing_Rect** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

If **OH_Drawing_PathDirection** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                     | Description                                                  |
| ------------------------ | ------------------------------------------------------------ |
| OH_Drawing_Path          | Pointer to an [OH_Drawing_Path](#oh_drawing_path) object.    |
| OH_Drawing_Rect          | Pointer to an [OH_Drawing_Rect](#oh_drawing_rect) object.    |
| start                    | Start point of the oval.                                     |
| OH_Drawing_PathDirection | Direction. For details about the available options, see [OH_Drawing_PathDirection](#oh_drawing_pathdirection). |


### OH_Drawing_PathAddPath()

```
void OH_Drawing_PathAddPath (OH_Drawing_Path* , const OH_Drawing_Path* src, const OH_Drawing_Matrix*  )
```

**Description**

Transforms the points in a **src** path by a matrix and adds the new one to the current path.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **OH_Drawing_Path** or **src** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name              | Description                                                  |
| ----------------- | ------------------------------------------------------------ |
| OH_Drawing_Path   | Pointer to the current path, which is an [OH_Drawing_Path](#oh_drawing_path) object. |
| src               | Pointer to a source path, which is an [OH_Drawing_Path](#oh_drawing_path) object. |
| OH_Drawing_Matrix | Pointer to an [OH_Drawing_Matrix](#oh_drawing_matrix) object. If NULL is passed in, it is the identity matrix. |


### OH_Drawing_PathAddPathWithMatrixAndMode()

```
void OH_Drawing_PathAddPathWithMatrixAndMode (OH_Drawing_Path* path, const OH_Drawing_Path* src, const OH_Drawing_Matrix* , OH_Drawing_PathAddMode  )
```

**Description**

Transforms the points in a **src** path by a matrix and adds the new one to the current path with the specified adding mode.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **path** or **src** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

If **OH_Drawing_PathAddMode** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                   | Description                                                  |
| ---------------------- | ------------------------------------------------------------ |
| path                   | Pointer to the current path, which is an [OH_Drawing_Path](#oh_drawing_path) object. |
| src                    | Pointer to a source path, which is an [OH_Drawing_Path](#oh_drawing_path) object. |
| OH_Drawing_Matrix      | Pointer to an [OH_Drawing_Matrix](#oh_drawing_matrix) object. If NULL is passed in, it is the identity matrix. |
| OH_Drawing_PathAddMode | Path adding mode. For details about the available options, see [OH_Drawing_PathAddMode](#oh_drawing_pathaddmode). |


### OH_Drawing_PathAddPathWithMode()

```
void OH_Drawing_PathAddPathWithMode (OH_Drawing_Path* path, const OH_Drawing_Path* src, OH_Drawing_PathAddMode  )
```

**Description**

Adds a **src** path to the current path with the specified adding mode.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **path** or **src** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

If **OH_Drawing_PathAddMode** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                   | Description                                                  |
| ---------------------- | ------------------------------------------------------------ |
| path                   | Pointer to the current path, which is an [OH_Drawing_Path](#oh_drawing_path) object. |
| src                    | Pointer to a source path, which is an [OH_Drawing_Path](#oh_drawing_path) object. |
| OH_Drawing_PathAddMode | Path adding mode. For details about the available options, see [OH_Drawing_PathAddMode](#oh_drawing_pathaddmode). |


### OH_Drawing_PathAddPathWithOffsetAndMode()

```
void OH_Drawing_PathAddPathWithOffsetAndMode (OH_Drawing_Path* path, const OH_Drawing_Path* src, float dx, float dy, OH_Drawing_PathAddMode  )
```

**Description**

Translates a **src** path by an offset and adds the new one to the current path with the specified adding mode.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **path** or **src** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

If **OH_Drawing_PathAddMode** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                   | Description                                                  |
| ---------------------- | ------------------------------------------------------------ |
| path                   | Pointer to the current path, which is an [OH_Drawing_Path](#oh_drawing_path) object. |
| src                    | Pointer to a source path, which is an [OH_Drawing_Path](#oh_drawing_path) object. |
| dx                     | X offset.                                                    |
| dy                     | Y offset.                                                    |
| OH_Drawing_PathAddMode | Path adding mode. For details about the available options, see [OH_Drawing_PathAddMode](#oh_drawing_pathaddmode). |


### OH_Drawing_PathAddRect()

```
void OH_Drawing_PathAddRect (OH_Drawing_Path* , float left, float top, float right, float bottom, OH_Drawing_PathDirection  )
```

**Description**

Adds a rectangle contour to a path in the specified direction.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Path** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

If **OH_Drawing_PathDirection** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                     | Description                                                  |
| ------------------------ | ------------------------------------------------------------ |
| OH_Drawing_Path          | Pointer to an [OH_Drawing_Path](#oh_drawing_path) object.    |
| left                     | X coordinate of the upper left corner of the rectangle.      |
| top                      | Y coordinate of the upper left corner of the rectangle.      |
| right                    | X coordinate of the lower right corner of the rectangle.     |
| bottom                   | Y coordinate of the lower right corner of the rectangle.     |
| OH_Drawing_PathDirection | Path direction. For details about the available options, see [OH_Drawing_PathDirection](#oh_drawing_pathdirection). |


### OH_Drawing_PathAddRectWithInitialCorner()

```
void OH_Drawing_PathAddRectWithInitialCorner (OH_Drawing_Path* , const OH_Drawing_Rect* , OH_Drawing_PathDirection , uint32_t start )
```

**Description**

Adds a rectangle contour to a path in the specified direction.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **OH_Drawing_Path** or **OH_Drawing_Rect** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

If **OH_Drawing_PathDirection** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                     | Description                                                  |
| ------------------------ | ------------------------------------------------------------ |
| OH_Drawing_Path          | Pointer to an [OH_Drawing_Path](#oh_drawing_path) object.    |
| OH_Drawing_Rect          | Pointer to an [OH_Drawing_Rect](#oh_drawing_rect) object.    |
| OH_Drawing_PathDirection | Direction. For details about the available options, see [OH_Drawing_PathDirection](#oh_drawing_pathdirection). |
| start                    | Start point, indicating the corner of the rectangle from which the path is drawn. The value **0** means the upper left corner, **1** means the upper right corner, **2** means the lower right corner, and **3** means the lower left corner. |


### OH_Drawing_PathAddRoundRect()

```
void OH_Drawing_PathAddRoundRect (OH_Drawing_Path* , const OH_Drawing_RoundRect* roundRect, OH_Drawing_PathDirection  )
```

**Description**

Adds a rounded rectangle to a path in the specified direction.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **OH_Drawing_Path** or **roundRect** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

If **OH_Drawing_PathDirection** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                     | Description                                                  |
| ------------------------ | ------------------------------------------------------------ |
| OH_Drawing_Path          | Pointer to an [OH_Drawing_Path](#oh_drawing_path) object.    |
| roundRect                | Pointer to an [OH_Drawing_RoundRect](#oh_drawing_roundrect) object. |
| OH_Drawing_PathDirection | Path direction. For details about the available options, see [OH_Drawing_PathDirection](#oh_drawing_pathdirection). |


### OH_Drawing_PathArcTo()

```
void OH_Drawing_PathArcTo (OH_Drawing_Path* , float x1, float y1, float x2, float y2, float startDeg, float sweepDeg )
```

**Description**

Draws an arc to a path. This is done by using angle arc mode. In this mode, a rectangle that encloses an ellipse is specified first, and then a start angle and a sweep angle are specified. The arc is a portion of the ellipse defined by the start angle and the sweep angle. By default, a line segment from the last point of the path to the start point of the arc is also added.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Path** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name            | Description                                                  |
| --------------- | ------------------------------------------------------------ |
| OH_Drawing_Path | Pointer to an **OH_Drawing_Path** object.                    |
| x1              | X coordinate of the upper left corner of the rectangle.      |
| y1              | Y coordinate of the upper left corner of the rectangle.      |
| x2              | X coordinate of the lower right corner of the rectangle.     |
| y2              | Y coordinate of the lower right corner of the rectangle.     |
| startDeg        | Start angle. The start direction (0°) of the angle is the positive direction of the X axis. |
| sweepDeg        | Angle to sweep, in degrees. A positive number indicates a clockwise sweep, and a negative value indicates a counterclockwise swipe. The actual swipe degree is the modulo operation result of the input parameter by 360. |


### OH_Drawing_PathClose()

```
void OH_Drawing_PathClose (OH_Drawing_Path* )
```

**Description**

Closes a path by drawing a line segment from the current point to the start point of the path.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Path** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name            | Description                               |
| --------------- | ----------------------------------------- |
| OH_Drawing_Path | Pointer to an **OH_Drawing_Path** object. |


### OH_Drawing_PathConicTo()

```
void OH_Drawing_PathConicTo (OH_Drawing_Path* , float ctrlX, float ctrlY, float endX, float endY, float weight )
```

**Description**

Draws a conic curve from the last point of a path to the target point. If the path is empty, the start point (0, 0) is used.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Path** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name            | Description                                                  |
| --------------- | ------------------------------------------------------------ |
| OH_Drawing_Path | Pointer to an [OH_Drawing_Path](#oh_drawing_path) object.    |
| ctrlX           | X coordinate of the control point.                           |
| ctrlY           | Y coordinate of the control point.                           |
| endX            | X coordinate of the target point.                            |
| endY            | Y coordinate of the target point.                            |
| weight          | Weight of the curve, which determines its shape. The larger the value, the closer of the curve to the control point. If the value is less than or equal to 0, this function is equivalent to [OH_Drawing_PathLineTo](#oh_drawing_pathlineto), that is, adding a line segment from the last point of the path to the target point. If the value is 1, this function is equivalent to [OH_Drawing_PathQuadTo](#oh_drawing_pathquadto). |


### OH_Drawing_PathContains()

```
bool OH_Drawing_PathContains (OH_Drawing_Path* , float x, float y )
```

**Description**

Checks whether a coordinate point is included in this path. For details, see [OH_Drawing_PathFillType](#oh_drawing_pathfilltype-1).

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Path** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name            | Description                                               |
| --------------- | --------------------------------------------------------- |
| OH_Drawing_Path | Pointer to an [OH_Drawing_Path](#oh_drawing_path) object. |
| x               | Coordinate point on the X axis.                           |
| y               | Coordinate point on the Y axis.                           |

**Returns**

Returns **true** if the coordinate point is included in the path; returns **false** otherwise.


### OH_Drawing_PathCopy()

```
OH_Drawing_Path* OH_Drawing_PathCopy (OH_Drawing_Path* )
```

**Description**

Copies an existing [OH_Drawing_Path](#oh_drawing_path) object to create a new one.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Path** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name            | Description                                               |
| --------------- | --------------------------------------------------------- |
| OH_Drawing_Path | Pointer to an [OH_Drawing_Path](#oh_drawing_path) object. |

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

Draws a cubic Bezier curve from the last point of a path to the target point. If the path is empty, the start point (0, 0) is used.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Path** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name            | Description                               |
| --------------- | ----------------------------------------- |
| OH_Drawing_Path | Pointer to an **OH_Drawing_Path** object. |
| ctrlX1          | X coordinate of the first control point.  |
| ctrlY1          | Y coordinate of the first control point.  |
| ctrlX2          | X coordinate of the second control point. |
| ctrlY2          | Y coordinate of the second control point. |
| endX            | X coordinate of the target point.         |
| endY            | Y coordinate of the target point.         |


### OH_Drawing_PathDestroy()

```
void OH_Drawing_PathDestroy (OH_Drawing_Path* )
```

**Description**

Destroys an **OH_Drawing_Path** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name            | Description                               |
| --------------- | ----------------------------------------- |
| OH_Drawing_Path | Pointer to an **OH_Drawing_Path** object. |


### OH_Drawing_PathEffectDestroy()

```
void OH_Drawing_PathEffectDestroy (OH_Drawing_PathEffect* )
```

**Description**

Destroys an **OH_Drawing_PathEffect** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                  | Description                                                  |
| --------------------- | ------------------------------------------------------------ |
| OH_Drawing_PathEffect | Pointer to an [OH_Drawing_PathEffect](#oh_drawing_patheffect) object. |


### OH_Drawing_PathGetLength()

```
float OH_Drawing_PathGetLength (OH_Drawing_Path* , bool forceClosed )
```

**Description**

Obtains the length of a path.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Path** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name            | Description                                                  |
| --------------- | ------------------------------------------------------------ |
| OH_Drawing_Path | Pointer to an [OH_Drawing_Path](#oh_drawing_path) object.    |
| forceClosed     | Whether the path can be modified or deleted freely after the function is called. The value **true** means that the path can be modified or deleted freely, and **false** means the opposite. |

**Returns**

Returns the length of the path.


### OH_Drawing_PathLineTo()

```
void OH_Drawing_PathLineTo (OH_Drawing_Path* , float x, float y )
```

**Description**

Draws a line segment from the last point of a path to the target point. If the path is empty, the start point (0, 0) is used.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Path** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name            | Description                               |
| --------------- | ----------------------------------------- |
| OH_Drawing_Path | Pointer to an **OH_Drawing_Path** object. |
| x               | X coordinate of the target point.         |
| y               | Y coordinate of the target point.         |


### OH_Drawing_PathMoveTo()

```
void OH_Drawing_PathMoveTo (OH_Drawing_Path* , float x, float y )
```

**Description**

Sets the start point of a path.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Path** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name            | Description                               |
| --------------- | ----------------------------------------- |
| OH_Drawing_Path | Pointer to an **OH_Drawing_Path** object. |
| x               | X coordinate of the start point.          |
| y               | Y coordinate of the start point.          |


### OH_Drawing_PathOffset()

```
void OH_Drawing_PathOffset (OH_Drawing_Path* path, OH_Drawing_Path* dst, float dx, float dy )
```

**Description**

Translates a path by an offset along the X axis and Y axis and adds the new one to the **dst** path.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **path** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name | Description                                                  |
| ---- | ------------------------------------------------------------ |
| path | Pointer to the current path, which is an [OH_Drawing_Path](#oh_drawing_path) object. |
| dst  | Pointer to a destination path, which is an [OH_Drawing_Path](#oh_drawing_path) object. If NULL is passed in, the result is stored in the current path. |
| dx   | X offset.                                                    |
| dy   | Y offset.                                                    |


### OH_Drawing_PathQuadTo()

```
void OH_Drawing_PathQuadTo (OH_Drawing_Path* , float ctrlX, float ctrlY, float endX, float endY )
```

**Description**

Draws a quadratic Bezier curve from the last point of a path to the target point. If the path is empty, the start point (0, 0) is used.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Path** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name            | Description                               |
| --------------- | ----------------------------------------- |
| OH_Drawing_Path | Pointer to an **OH_Drawing_Path** object. |
| ctrlX           | X coordinate of the control point.        |
| ctrlY           | Y coordinate of the control point.        |
| endX            | X coordinate of the target point.         |
| endY            | Y coordinate of the target point.         |


### OH_Drawing_PathRConicTo()

```
void OH_Drawing_PathRConicTo (OH_Drawing_Path* , float ctrlX, float ctrlY, float endX, float endY, float weight )
```

**Description**

Draws a conic curve from the last point of a path to a point relative to the last point. If the path is empty, the start point (0, 0) is used.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Path** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name            | Description                                                  |
| --------------- | ------------------------------------------------------------ |
| OH_Drawing_Path | Pointer to an [OH_Drawing_Path](#oh_drawing_path) object.    |
| ctrlX           | X offset relative to the last point, which is used to specify the X coordinate of the control point. |
| ctrlY           | Y offset relative to the last point, which is used to specify the Y coordinate of the control point. |
| endX            | X offset relative to the last point, which is used to specify the X coordinate of the target point. |
| endY            | Y offset relative to the last point, which is used to specify the Y coordinate of the target point. |
| weight          | Weight of the curve, which determines its shape. The larger the value, the closer of the curve to the control point. If the value is less than or equal to 0, this function is equivalent to [OH_Drawing_PathRLineTo](#oh_drawing_pathrlineto), that is, adding a line segment from the last point of the path to the target point. If the value is 1, this function is equivalent to [OH_Drawing_PathRQuadTo](#oh_drawing_pathrquadto). |


### OH_Drawing_PathRCubicTo()

```
void OH_Drawing_PathRCubicTo (OH_Drawing_Path* , float ctrlX1, float ctrlY1, float ctrlX2, float ctrlY2, float endX, float endY )
```

**Description**

Draws a cubic Bezier curve from the last point of a path to a point relative to the last point. If the path is empty, the start point (0, 0) is used.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Path** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name            | Description                                                  |
| --------------- | ------------------------------------------------------------ |
| OH_Drawing_Path | Pointer to an [OH_Drawing_Path](#oh_drawing_path) object.    |
| ctrlX1          | X offset relative to the last point, which is used to specify the X coordinate of the first control point. |
| ctrlY1          | Y offset relative to the last point, which is used to specify the Y coordinate of the first control point. |
| ctrlX2          | X offset relative to the last point, which is used to specify the X coordinate of the second control point. |
| ctrlY2          | Y offset relative to the last point, which is used to specify the Y coordinate of the second control point. |
| endX            | X offset relative to the last point, which is used to specify the X coordinate of the target point. |
| endY            | Y offset relative to the last point, which is used to specify the Y coordinate of the target point. |


### OH_Drawing_PathReset()

```
void OH_Drawing_PathReset (OH_Drawing_Path* )
```

**Description**

Resets path data.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Path** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name            | Description                               |
| --------------- | ----------------------------------------- |
| OH_Drawing_Path | Pointer to an **OH_Drawing_Path** object. |


### OH_Drawing_PathRLineTo()

```
void OH_Drawing_PathRLineTo (OH_Drawing_Path* , float x, float y )
```

**Description**

Draws a line segment from the last point of a path to a point relative to the last point. If the path is empty, the start point (0, 0) is used.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Path** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name            | Description                                                  |
| --------------- | ------------------------------------------------------------ |
| OH_Drawing_Path | Pointer to an [OH_Drawing_Path](#oh_drawing_path) object.    |
| x               | X offset relative to the last point, which is used to specify the X coordinate of the target point. |
| y               | Y offset relative to the last point, which is used to specify the X coordinate of the target point. |


### OH_Drawing_PathRMoveTo()

```
void OH_Drawing_PathRMoveTo (OH_Drawing_Path* , float x, float y )
```

**Description**

Sets the start position relative to the last point of a path. If the path is empty, the start point (0, 0) is used.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Path** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name            | Description                                                  |
| --------------- | ------------------------------------------------------------ |
| OH_Drawing_Path | Pointer to an [OH_Drawing_Path](#oh_drawing_path) object.    |
| x               | X offset relative to the last point, which is used to specify the X coordinate of the start point. |
| y               | Y offset relative to the last point, which is used to specify the Y coordinate of the start point. |


### OH_Drawing_PathRQuadTo()

```
void OH_Drawing_PathRQuadTo (OH_Drawing_Path* , float ctrlX, float ctrlY, float endX, float endY )
```

**Description**

Draws a quadratic Bezier curve from the last point of a path to a point relative to the last point. If the path is empty, the start point (0, 0) is used.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Path** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name            | Description                                                  |
| --------------- | ------------------------------------------------------------ |
| OH_Drawing_Path | Pointer to an [OH_Drawing_Path](#oh_drawing_path) object.    |
| ctrlX           | X offset relative to the last point, which is used to specify the X coordinate of the control point. |
| ctrlY           | Y offset relative to the last point, which is used to specify the Y coordinate of the control point. |
| endX            | X offset relative to the last point, which is used to specify the X coordinate of the target point. |
| endY            | Y offset relative to the last point, which is used to specify the Y coordinate of the target point. |


### OH_Drawing_PathSetFillType()

```
void OH_Drawing_PathSetFillType (OH_Drawing_Path* , OH_Drawing_PathFillType  )
```

**Description**

Sets the fill type for a path.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Path** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

If **OH_Drawing_PathFillType** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                    | Description                                                  |
| ----------------------- | ------------------------------------------------------------ |
| OH_Drawing_Path         | Pointer to an [OH_Drawing_Path](#oh_drawing_path) object.    |
| OH_Drawing_PathFillType | Fill type of the path. For details about the available options, see [OH_Drawing_PathFillType](#oh_drawing_pathfilltype). |


### OH_Drawing_PathTransform()

```
void OH_Drawing_PathTransform (OH_Drawing_Path* , const OH_Drawing_Matrix*  )
```

**Description**

Transforms the points in a path by a matrix.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **OH_Drawing_Path** or **OH_Drawing_Matrix** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name              | Description                                                  |
| ----------------- | ------------------------------------------------------------ |
| OH_Drawing_Path   | Pointer to an [OH_Drawing_Path](#oh_drawing_path) object.    |
| OH_Drawing_Matrix | Pointer to an [OH_Drawing_Matrix](#oh_drawing_matrix) object. |


### OH_Drawing_PathTransformWithPerspectiveClip()

```
void OH_Drawing_PathTransformWithPerspectiveClip (OH_Drawing_Path* src, const OH_Drawing_Matrix* , OH_Drawing_Path* dst, bool applyPerspectiveClip )
```

**Description**

Transforms the points in a **src** path by a matrix and uses the new one to replace the **dst** path. If the **dst** path does not exist, the **src** path is replaced.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **src** or **OH_Drawing_Matrix** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| src                  | Pointer to an [OH_Drawing_Path](#oh_drawing_path) object.    |
| OH_Drawing_Matrix    | Pointer to an [OH_Drawing_Matrix](#oh_drawing_matrix) object. |
| dst                  | Pointer to a destination path, which is an [OH_Drawing_Path](#oh_drawing_path) object. |
| applyPerspectiveClip | Whether to apply perspective cropping to the new path. The value **true** means to apply perspective cropping, and **false** means the opposite. |


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

Destroys an **OH_Drawing_Pen** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name           | Description                              |
| -------------- | ---------------------------------------- |
| OH_Drawing_Pen | Pointer to an **OH_Drawing_Pen** object. |


### OH_Drawing_PenGetAlpha()

```
uint8_t OH_Drawing_PenGetAlpha (const OH_Drawing_Pen* )
```

**Description**

Obtains the alpha value of a pen. This value is used by the alpha channel when the pen outlines a shape.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name           | Description                              |
| -------------- | ---------------------------------------- |
| OH_Drawing_Pen | Pointer to an **OH_Drawing_Pen** object. |

**Returns**

Returns an 8-bit variable that describes the alpha value.


### OH_Drawing_PenGetCap()

```
OH_Drawing_PenLineCapStyle OH_Drawing_PenGetCap (const OH_Drawing_Pen* )
```

**Description**

Obtains the line cap style of a pen.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name           | Description                              |
| -------------- | ---------------------------------------- |
| OH_Drawing_Pen | Pointer to an **OH_Drawing_Pen** object. |

**Returns**

Returns the line cap style.


### OH_Drawing_PenGetColor()

```
uint32_t OH_Drawing_PenGetColor (const OH_Drawing_Pen* )
```

**Description**

Obtains the color of a pen. The color is used by the pen to outline a shape.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name           | Description                              |
| -------------- | ---------------------------------------- |
| OH_Drawing_Pen | Pointer to an **OH_Drawing_Pen** object. |

**Returns**

Returns a 32-bit (ARGB) variable that describes the color.


### OH_Drawing_PenGetFilter()

```
void OH_Drawing_PenGetFilter (OH_Drawing_Pen* , OH_Drawing_Filter*  )
```

**Description**

Obtains the filter of a pen. The filter is a container that holds a mask filter and color filter.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **OH_Drawing_Pen** or **OH_Drawing_Filter** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name              | Description                                                  |
| ----------------- | ------------------------------------------------------------ |
| OH_Drawing_Pen    | Pointer to an [OH_Drawing_Pen](#oh_drawing_pen) object.      |
| OH_Drawing_Filter | Pointer to an [OH_Drawing_Filter](#oh_drawing_filter) object. |


### OH_Drawing_PenGetJoin()

```
OH_Drawing_PenLineJoinStyle OH_Drawing_PenGetJoin (const OH_Drawing_Pen* )
```

**Description**

Obtains the line join style of a pen.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name           | Description                              |
| -------------- | ---------------------------------------- |
| OH_Drawing_Pen | Pointer to an **OH_Drawing_Pen** object. |

**Returns**

Returns the line join style.

### OH_Drawing_PenGetMiterLimit()

```
float OH_Drawing_PenGetMiterLimit (const OH_Drawing_Pen* )
```

**Description**

Obtains the stroke miter limit of a polyline drawn by a pen. When the corner type is bevel, a beveled corner is displayed if the miter limit is exceeded, and a mitered corner is displayed if the miter limit is not exceeded.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name           | Description                              |
| -------------- | ---------------------------------------- |
| OH_Drawing_Pen | Pointer to an **OH_Drawing_Pen** object. |

**Returns**

Returns the miter limit.


### OH_Drawing_PenGetWidth()

```
float OH_Drawing_PenGetWidth (const OH_Drawing_Pen* )
```

**Description**

Obtains the width of a pen. The width describes the thickness of the outline of a shape.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name           | Description                              |
| -------------- | ---------------------------------------- |
| OH_Drawing_Pen | Pointer to an **OH_Drawing_Pen** object. |

**Returns**

Returns the width of the pen.


### OH_Drawing_PenIsAntiAlias()

```
bool OH_Drawing_PenIsAntiAlias (const OH_Drawing_Pen* )
```

**Description**

Checks whether anti-aliasing is enabled for a pen. Anti-aliasing makes the pixels around the shape edges semi-transparent.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name           | Description                              |
| -------------- | ---------------------------------------- |
| OH_Drawing_Pen | Pointer to an **OH_Drawing_Pen** object. |

**Returns**

Returns **true** if anti-aliasing is enabled; returns **false** otherwise.


### OH_Drawing_PenReset()

```
void OH_Drawing_PenReset (OH_Drawing_Pen* )
```

**Description**

Resets a pen to the initial state.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name           | Description                                             |
| -------------- | ------------------------------------------------------- |
| OH_Drawing_Pen | Pointer to an [OH_Drawing_Pen](#oh_drawing_pen) object. |


### OH_Drawing_PenSetAlpha()

```
void OH_Drawing_PenSetAlpha (OH_Drawing_Pen* , uint8_t alpha )
```

**Description**

Sets the alpha value for a pen. This value is used by the alpha channel when the pen outlines a shape.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name           | Description                              |
| -------------- | ---------------------------------------- |
| OH_Drawing_Pen | Pointer to an **OH_Drawing_Pen** object. |
| alpha          | Alpha value, which is an 8-bit variable. |


### OH_Drawing_PenSetAntiAlias()

```
void OH_Drawing_PenSetAntiAlias (OH_Drawing_Pen* , bool  )
```

**Description**

Enables or disables anti-aliasing for a pen. Anti-aliasing makes the pixels around the shape edges semi-transparent.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name           | Description                                                  |
| -------------- | ------------------------------------------------------------ |
| OH_Drawing_Pen | Pointer to an **OH_Drawing_Pen** object.                     |
| bool           | Whether to enable anti-aliasing. The value **true** means to enable anti-aliasing, and **false** means the opposite. |


### OH_Drawing_PenSetBlendMode()

```
void OH_Drawing_PenSetBlendMode (OH_Drawing_Pen* , OH_Drawing_BlendMode  )
```

**Description**

Sets a blender for a pen. The blender implements the specified blend mode.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

If **OH_Drawing_BlendMode** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_Pen       | Pointer to an [OH_Drawing_Pen](#oh_drawing_pen) object.      |
| OH_Drawing_BlendMode | Blend mode. For details about the available options, see [OH_Drawing_BlendMode](#oh_drawing_blendmode). |


### OH_Drawing_PenSetCap()

```
void OH_Drawing_PenSetCap (OH_Drawing_Pen* , OH_Drawing_PenLineCapStyle  )
```

**Description**

Sets the line cap style for a pen.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

If **OH_Drawing_PenLineCapStyle** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name                       | Description                              |
| -------------------------- | ---------------------------------------- |
| OH_Drawing_Pen             | Pointer to an **OH_Drawing_Pen** object. |
| OH_Drawing_PenLineCapStyle | Line cap style, which is a variable.     |


### OH_Drawing_PenSetColor()

```
void OH_Drawing_PenSetColor (OH_Drawing_Pen* , uint32_t color )
```

**Description**

Sets the color for a pen. The color is used by the pen to outline a shape.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name           | Description                               |
| -------------- | ----------------------------------------- |
| OH_Drawing_Pen | Pointer to an **OH_Drawing_Pen** object.  |
| color          | Color, which is a 32-bit (ARGB) variable. |


### OH_Drawing_PenSetFilter()

```
void OH_Drawing_PenSetFilter (OH_Drawing_Pen* , OH_Drawing_Filter*  )
```

**Description**

Sets a filter for a pen.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name              | Description                                                  |
| ----------------- | ------------------------------------------------------------ |
| OH_Drawing_Pen    | Pointer to an [OH_Drawing_Pen](#oh_drawing_pen) object.      |
| OH_Drawing_Filter | Pointer to an [OH_Drawing_Filter](#oh_drawing_filter) object. If NULL is passed in, the filter will be cleared. |


### OH_Drawing_PenSetJoin()

```
void OH_Drawing_PenSetJoin (OH_Drawing_Pen* , OH_Drawing_PenLineJoinStyle  )
```

**Description**

Sets the line join style for a pen.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

If **OH_Drawing_PenLineJoinStyle** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name                        | Description                              |
| --------------------------- | ---------------------------------------- |
| OH_Drawing_Pen              | Pointer to an **OH_Drawing_Pen** object. |
| OH_Drawing_PenLineJoinStyle | Line join style.                         |


### OH_Drawing_PenSetMiterLimit()

```
void OH_Drawing_PenSetMiterLimit (OH_Drawing_Pen* , float miter )
```

**Description**

Sets the stroke miter limit for a polyline drawn by a pen. When the corner type is bevel, a beveled corner is displayed if the miter limit is exceeded, and a mitered corner is displayed if the miter limit is not exceeded.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name           | Description                              |
| -------------- | ---------------------------------------- |
| OH_Drawing_Pen | Pointer to an **OH_Drawing_Pen** object. |
| miter          | Stroke miter limit, which is a variable. |


### OH_Drawing_PenSetPathEffect()

```
void OH_Drawing_PenSetPathEffect (OH_Drawing_Pen* , OH_Drawing_PathEffect*  )
```

**Description**

Sets the path effect for a pen.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                  | Description                                                  |
| --------------------- | ------------------------------------------------------------ |
| OH_Drawing_Pen        | Pointer to an [OH_Drawing_Pen](#oh_drawing_pen) object.      |
| OH_Drawing_PathEffect | Pointer to an [OH_Drawing_PathEffect](#oh_drawing_patheffect) object. If NULL is passed in, the path effect will be cleared. |


### OH_Drawing_PenSetShaderEffect()

```
void OH_Drawing_PenSetShaderEffect (OH_Drawing_Pen* , OH_Drawing_ShaderEffect*  )
```

**Description**

Sets the shader effect for a pen.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name                    | Description                                                  |
| ----------------------- | ------------------------------------------------------------ |
| OH_Drawing_Pen          | Pointer to an [OH_Drawing_Pen](#oh_drawing_pen) object.      |
| OH_Drawing_ShaderEffect | Pointer to an [OH_Drawing_ShaderEffect](#oh_drawing_shadereffect) object. If NULL is passed in, the shader effect will be cleared. |


### OH_Drawing_PenSetWidth()

```
void OH_Drawing_PenSetWidth (OH_Drawing_Pen* , float width )
```

**Description**

Sets the width for a pen. The value **0** is treated as an unusually thin width. During drawing, the width of 0 is always drawn as 1 pixel wide, regardless of any scaling applied to the canvas. Negative values are also regarded as the value **0** during the drawing process.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name           | Description                              |
| -------------- | ---------------------------------------- |
| OH_Drawing_Pen | Pointer to an **OH_Drawing_Pen** object. |
| width          | Width, which is a variable.              |


### OH_Drawing_PointCreate()

```
OH_Drawing_Point* OH_Drawing_PointCreate (float x, float y )
```

**Description**

Creates an **OH_Drawing_Point** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name | Description                |
| ---- | -------------------------- |
| x    | X coordinate of the point. |
| y    | Y coordinate of the point. |

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

| Name             | Description                                |
| ---------------- | ------------------------------------------ |
| OH_Drawing_Point | Pointer to an **OH_Drawing_Point** object. |


### OH_Drawing_RectCopy()

```
void OH_Drawing_RectCopy (OH_Drawing_Rect* sRect, OH_Drawing_Rect* dRect )
```

**Description**

Copies a source rectangle to create a new one.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **sRect** or **dRect** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name  | Description                                                  |
| ----- | ------------------------------------------------------------ |
| sRect | Pointer to a source rectangle, which is an **OH_Drawing_Rect** object. |
| dRect | Pointer to a destination rectangle, which is an **OH_Drawing_Rect** object. |


### OH_Drawing_RectCreate()

```
OH_Drawing_Rect* OH_Drawing_RectCreate (float left, float top, float right, float bottom )
```

**Description**

Creates an **OH_Drawing_Rect** object, without sorting the coordinates passed in. This means that the coordinates of the upper left corner of the rectangle can be greater than those of the lower right corner.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name   | Description                                              |
| ------ | -------------------------------------------------------- |
| left   | X coordinate of the upper left corner of the rectangle.  |
| top    | Y coordinate of the upper left corner of the rectangle.  |
| right  | X coordinate of the lower right corner of the rectangle. |
| bottom | Y coordinate of the lower right corner of the rectangle. |

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

| Name            | Description                               |
| --------------- | ----------------------------------------- |
| OH_Drawing_Rect | Pointer to an **OH_Drawing_Rect** object. |


### OH_Drawing_RectGetBottom()

```
float OH_Drawing_RectGetBottom (OH_Drawing_Rect* )
```

**Description**

Obtains the Y coordinate of the lower right corner of a rectangle.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Rect** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name            | Description                               |
| --------------- | ----------------------------------------- |
| OH_Drawing_Rect | Pointer to an **OH_Drawing_Rect** object. |

**Returns**

Returns the Y coordinate of the lower right corner of the rectangle.


### OH_Drawing_RectGetHeight()

```
float OH_Drawing_RectGetHeight (OH_Drawing_Rect* )
```

**Description**

Obtains the height of a rectangle. The height is calculated by using the Y coordinate of the lower right corner of the rectangle minus the Y coordinate of the upper left corner.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Rect** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name            | Description                               |
| --------------- | ----------------------------------------- |
| OH_Drawing_Rect | Pointer to an **OH_Drawing_Rect** object. |

**Returns**

Returns the height.


### OH_Drawing_RectGetLeft()

```
float OH_Drawing_RectGetLeft (OH_Drawing_Rect* )
```

**Description**

Obtains the X coordinate of the upper left corner of a rectangle.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Rect** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name            | Description                               |
| --------------- | ----------------------------------------- |
| OH_Drawing_Rect | Pointer to an **OH_Drawing_Rect** object. |

**Returns**

Returns the X coordinate of the upper left corner of the rectangle.


### OH_Drawing_RectGetRight()

```
float OH_Drawing_RectGetRight (OH_Drawing_Rect* )
```

**Description**

Obtains the X coordinate of the lower right corner of a rectangle.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Rect** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name            | Description                               |
| --------------- | ----------------------------------------- |
| OH_Drawing_Rect | Pointer to an **OH_Drawing_Rect** object. |

**Returns**

Returns the X coordinate of the lower right corner of the rectangle.


### OH_Drawing_RectGetTop()

```
float OH_Drawing_RectGetTop (OH_Drawing_Rect* )
```

**Description**

Obtains the Y coordinate of the upper left corner of a rectangle.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Rect** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name            | Description                               |
| --------------- | ----------------------------------------- |
| OH_Drawing_Rect | Pointer to an **OH_Drawing_Rect** object. |

**Returns**

Returns the Y coordinate of the upper left corner of the rectangle.


### OH_Drawing_RectGetWidth()

```
float OH_Drawing_RectGetWidth (OH_Drawing_Rect* )
```

**Description**

Obtains the width of a rectangle. The width is calculated by using the X coordinate of the lower right corner of the rectangle minus the X coordinate of the upper left corner.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Rect** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name            | Description                               |
| --------------- | ----------------------------------------- |
| OH_Drawing_Rect | Pointer to an **OH_Drawing_Rect** object. |

**Returns**

Returns the width.


### OH_Drawing_RectIntersect()

```
bool OH_Drawing_RectIntersect (OH_Drawing_Rect* rect, const OH_Drawing_Rect* other )
```

**Description**

Checks whether two rectangles intersect and if yes, sets **rect** to the area of intersection.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **rect** or **other** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name  | Description                                                  |
| ----- | ------------------------------------------------------------ |
| rect  | Pointer to the first rectangle, which is an **OH_Drawing_Rect** object. |
| other | Pointer to the second rectangle, which is an **OH_Drawing_Rect** object. |

**Returns**

Returns **true** if they intersect (**rect** is set to the intersection area); returns **false** otherwise (**rect** remains unchanged).


### OH_Drawing_RectSetBottom()

```
void OH_Drawing_RectSetBottom (OH_Drawing_Rect* rect, float bottom )
```

**Description**

Sets the vertical coordinate of the lower right corner of a rectangle.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **rect** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name   | Description                                              |
| ------ | -------------------------------------------------------- |
| rect   | Pointer to an **OH_Drawing_Rect** object.                |
| bottom | Y coordinate of the lower right corner of the rectangle. |


### OH_Drawing_RectSetLeft()

```
void OH_Drawing_RectSetLeft (OH_Drawing_Rect* rect, float left )
```

**Description**

Sets the horizontal coordinate of the upper left corner of a rectangle.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **rect** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name | Description                                             |
| ---- | ------------------------------------------------------- |
| rect | Pointer to an **OH_Drawing_Rect** object.               |
| left | X coordinate of the upper left corner of the rectangle. |


### OH_Drawing_RectSetRight()

```
void OH_Drawing_RectSetRight (OH_Drawing_Rect* rect, float right )
```

**Description**

Sets the horizontal coordinate of the lower right corner of a rectangle.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **rect** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name  | Description                                              |
| ----- | -------------------------------------------------------- |
| rect  | Pointer to an **OH_Drawing_Rect** object.                |
| right | X coordinate of the lower right corner of the rectangle. |


### OH_Drawing_RectSetTop()

```
void OH_Drawing_RectSetTop (OH_Drawing_Rect* rect, float top )
```

**Description**

Sets the vertical coordinate of the upper left corner of a rectangle.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **rect** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name | Description                                             |
| ---- | ------------------------------------------------------- |
| rect | Pointer to an **OH_Drawing_Rect** object.               |
| top  | Y coordinate of the upper left corner of the rectangle. |


### OH_Drawing_RegionCreate()

```
OH_Drawing_Region* OH_Drawing_RegionCreate (void )
```

**Description**

Creates an **OH_Drawing_Region** object for more accurate graphical control.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Returns**

Returns the pointer to the **OH_Drawing_Region** object created.


### OH_Drawing_RegionDestroy()

```
void OH_Drawing_RegionDestroy (OH_Drawing_Region* )
```

**Description**

Destroys an **OH_Drawing_Region** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name              | Description                                 |
| ----------------- | ------------------------------------------- |
| OH_Drawing_Region | Pointer to an **OH_Drawing_Region** object. |


### OH_Drawing_RegionSetRect()

```
bool OH_Drawing_RegionSetRect (OH_Drawing_Region* region, const OH_Drawing_Rect* rect )
```

**Description**

Sets the boundary for an **OH_Drawing_Region** object.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **region** or **rect** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name   | Description                                 |
| ------ | ------------------------------------------- |
| region | Pointer to an **OH_Drawing_Region** object. |
| rect   | Pointer to an **OH_Drawing_Rect** object.   |

**Returns**

Returns **true** if the setting is successful; returns **false** otherwise.


### OH_Drawing_RegisterFont()

```
uint32_t OH_Drawing_RegisterFont (OH_Drawing_FontCollection* , const char* fontFamily, const char* familySrc )
```

**Description**

Registers a custom font with the font manager. The supported font file formats are .ttf and .otf.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name                      | Description                                         |
| ------------------------- | --------------------------------------------------- |
| OH_Drawing_FontCollection | Pointer to an **OH_Drawing_FontCollection** object. |
| fontFamily                | Pointer to the family name of the font to register. |
| familySrc                 | Pointer to the path of the font file.               |

**Returns**

Returns **0** if the font is registered; returns **1** if the file does not exist; returns **2** if opening the file fails; returns **3** if reading the file fails; returns **4** if the file is not found; returns **5** if the file size is not obtained; returns **9** if the file is damaged.


### OH_Drawing_RegisterFontBuffer()

```
uint32_t OH_Drawing_RegisterFontBuffer (OH_Drawing_FontCollection* , const char* fontFamily, uint8_t* fontBuffer, size_t length )
```

**Description**

Registers a font buffer with the font manager.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name                      | Description                                         |
| ------------------------- | --------------------------------------------------- |
| OH_Drawing_FontCollection | Pointer to an **OH_Drawing_FontCollection** object. |
| fontFamily                | Pointer to the family name of the font to register. |
| fontBuffer                | Pointer to the buffer of the font file.             |
| length                    | Length of the font file.                            |

**Returns**

Returns **0** if the font is registered; returns **6** if the buffer size is zero; returns **7** if the font set is empty; returns **9** if the file is damaged.


### OH_Drawing_RoundRectCreate()

```
OH_Drawing_RoundRect* OH_Drawing_RoundRectCreate (const OH_Drawing_Rect* , float xRad, float yRad )
```

**Description**

Creates an **OH_Drawing_RoundRect** object.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Rect** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name            | Description                                 |
| --------------- | ------------------------------------------- |
| OH_Drawing_Rect | Pointer to an **OH_Drawing_Rect** object.   |
| xRad            | Radius of the rounded corner on the X axis. |
| yRad            | Radius of the rounded corner on the Y axis. |

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

| Name                 | Description                                    |
| -------------------- | ---------------------------------------------- |
| OH_Drawing_RoundRect | Pointer to an **OH_Drawing_RoundRect** object. |


### OH_Drawing_RoundRectGetCorner()

```
OH_Drawing_Corner_Radii OH_Drawing_RoundRectGetCorner (OH_Drawing_RoundRect* , OH_Drawing_CornerPos pos )
```

**Description**

Obtains the radii of the specified rounded corner in a rounded rectangle.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_RoundRect** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_RoundRect | Pointer to an **OH_Drawing_RoundRect** object.               |
| pos                  | Position of the rounded corner. For details about the available options, see [OH_Drawing_CornerPos](#oh_drawing_cornerpos). |

**Returns**

Returns an [OH_Drawing_Corner_Radii](#oh_drawing_corner_radii) struct, including the radii on the X axis and Y axis.


### OH_Drawing_RoundRectSetCorner()

```
void OH_Drawing_RoundRectSetCorner (OH_Drawing_RoundRect* , OH_Drawing_CornerPos pos, OH_Drawing_Corner_Radii  )
```

**Description**

Sets the radii of the specified rounded corner in a rounded rectangle.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_RoundRect** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                    | Description                                                  |
| ----------------------- | ------------------------------------------------------------ |
| OH_Drawing_RoundRect    | Pointer to an **OH_Drawing_RoundRect** object.               |
| pos                     | Position of the rounded corner. For details about the available options, see [OH_Drawing_CornerPos](#oh_drawing_cornerpos). |
| OH_Drawing_Corner_Radii | [OH_Drawing_Corner_Radii](#oh_drawing_corner_radii) struct, including the radii on the X axis and Y axis. |


### OH_Drawing_SamplingOptionsCreate()

```
OH_Drawing_SamplingOptions* OH_Drawing_SamplingOptionsCreate (OH_Drawing_FilterMode , OH_Drawing_MipmapMode  )
```

**Description**

Creates an **OH_Drawing_SamplingOptions** object.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_MipmapMode** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                  | Description                                                  |
| --------------------- | ------------------------------------------------------------ |
| OH_Drawing_FilterMode | Filter mode. For details about the available options, see [OH_Drawing_FilterMode](#oh_drawing_filtermode). |
| OH_Drawing_MipmapMode | Mipmap mode. For details about the available options, see [OH_Drawing_MipmapMode](#oh_drawing_mipmapmode). |

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

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_SamplingOptions | Pointer to an [OH_Drawing_SamplingOptions](#oh_drawing_samplingoptions) object. |


### OH_Drawing_SetTextStyleBackgroundBrush()

```
void OH_Drawing_SetTextStyleBackgroundBrush (OH_Drawing_TextStyle* , OH_Drawing_Brush*  )
```

**Description**

Sets the background brush for a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextStyle | Pointer to an [OH_Drawing_TextStyle](#oh_drawing_textstyle) object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |
| OH_Drawing_Brush     | Pointer to an [OH_Drawing_Brush](#oh_drawing_brush) object, which is obtained by calling [OH_Drawing_BrushCreate](#oh_drawing_brushcreate). |


### OH_Drawing_SetTextStyleBackgroundPen()

```
void OH_Drawing_SetTextStyleBackgroundPen (OH_Drawing_TextStyle* , OH_Drawing_Pen*  )
```

**Description**

Sets the background pen for a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextStyle | Pointer to an [OH_Drawing_TextStyle](#oh_drawing_textstyle) object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |
| OH_Drawing_Pen       | Pointer to an [OH_Drawing_Pen](#oh_drawing_pen) object, which is obtained by calling [OH_Drawing_PenCreate](#oh_drawing_pencreate). |


### OH_Drawing_SetTextStyleBaseLine()

```
void OH_Drawing_SetTextStyleBaseLine (OH_Drawing_TextStyle* , int  )
```

**Description**

Sets the baseline for a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |
| int                  | Text baseline. For details about the available options, see [OH_Drawing_TextBaseline](#oh_drawing_textbaseline). |


### OH_Drawing_SetTextStyleColor()

```
void OH_Drawing_SetTextStyleColor (OH_Drawing_TextStyle* , uint32_t  )
```

**Description**

Sets the color for a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |
| uint32_t             | Color.                                                       |


### OH_Drawing_SetTextStyleDecoration()

```
void OH_Drawing_SetTextStyleDecoration (OH_Drawing_TextStyle* , int  )
```

**Description**

Sets the decoration for a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |
| int                  | Text decoration. For details about the available options, see [OH_Drawing_TextDecoration](#oh_drawing_textdecoration). |


### OH_Drawing_SetTextStyleDecorationColor()

```
void OH_Drawing_SetTextStyleDecorationColor (OH_Drawing_TextStyle* , uint32_t  )
```

**Description**

Sets the decoration color for a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |
| uint32_t             | Color.                                                       |


### OH_Drawing_SetTextStyleDecorationStyle()

```
void OH_Drawing_SetTextStyleDecorationStyle (OH_Drawing_TextStyle* , int  )
```

**Description**

Sets the decoration style for a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |
| int                  | Text decoration style. For details about the available options, see [OH_Drawing_TextDecorationStyle](#oh_drawing_textdecorationstyle). |


### OH_Drawing_SetTextStyleDecorationThicknessScale()

```
void OH_Drawing_SetTextStyleDecorationThicknessScale (OH_Drawing_TextStyle* , double  )
```

**Description**

Sets the thickness scale factor for the decoration style of a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |
| double               | Scale factor.                                                |


### OH_Drawing_SetTextStyleEllipsis()

```
void OH_Drawing_SetTextStyleEllipsis (OH_Drawing_TextStyle* , const char*  )
```

**Description**

Sets the ellipsis content for a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |
| char\*               | Pointer to the ellipsis content. The data type is a pointer pointing to char. |


### OH_Drawing_SetTextStyleEllipsisModal()

```
void OH_Drawing_SetTextStyleEllipsisModal (OH_Drawing_TextStyle* , int  )
```

**Description**

Sets the ellipsis style for a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |
| int                  | Ellipsis style. For details about the available options, see [OH_Drawing_EllipsisModal](#oh_drawing_ellipsismodal). |


### OH_Drawing_SetTextStyleFontFamilies()

```
void OH_Drawing_SetTextStyleFontFamilies (OH_Drawing_TextStyle* , int , const char* fontFamilies[] )
```

**Description**

Sets the font families for a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |
| int                  | Number of font families.                                     |
| char                 | Pointer to the font families.                                |


### OH_Drawing_SetTextStyleFontHeight()

```
void OH_Drawing_SetTextStyleFontHeight (OH_Drawing_TextStyle* , double  )
```

**Description**

Sets the line height based on the multiple of the font size.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |
| double               | Multiple of the font size.                                   |


### OH_Drawing_SetTextStyleFontSize()

```
void OH_Drawing_SetTextStyleFontSize (OH_Drawing_TextStyle* , double  )
```

**Description**

Sets the font size for a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |
| double               | Font size.                                                   |


### OH_Drawing_SetTextStyleFontStyle()

```
void OH_Drawing_SetTextStyleFontStyle (OH_Drawing_TextStyle* , int  )
```

**Description**

Sets the font style for a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |
| int                  | Font style. For details about the available options, see [OH_Drawing_FontStyle](#oh_drawing_fontstyle). |


### OH_Drawing_SetTextStyleFontStyleStruct()

```
void OH_Drawing_SetTextStyleFontStyleStruct (OH_Drawing_TextStyle* drawingTextStyle, OH_Drawing_FontStyleStruct fontStyle )
```

**Description**

Sets the font style, including the font weight, width, and slant, for a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                                                         | Description                                                  |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| OH_Drawing_TextStyle                                         | Pointer to an [OH_Drawing_TextStyle](#oh_drawing_textstyle) object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |
| [OH_Drawing_FontStyleStruct](_o_h___drawing___font_style_struct.md) | Font style, including the font weight, width, and slant.     |


### OH_Drawing_SetTextStyleFontWeight()

```
void OH_Drawing_SetTextStyleFontWeight (OH_Drawing_TextStyle* , int  )
```

**Description**

Sets the font weight for a text style. Currently, only the default system font supports font weight adjustment. For other fonts, if the weight is less than semi-bold, there is no variation in stroke thickness. If the weight is greater than or equal to semi-bold, it might result in a fake bold effect.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |
| int                  | Font weight. For details about the available options, see [OH_Drawing_FontWeight](#oh_drawing_fontweight). |


### OH_Drawing_SetTextStyleForegroundBrush()

```
void OH_Drawing_SetTextStyleForegroundBrush (OH_Drawing_TextStyle* , OH_Drawing_Brush*  )
```

**Description**

Sets the foreground brush for a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextStyle | Pointer to an [OH_Drawing_TextStyle](#oh_drawing_textstyle) object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |
| OH_Drawing_Brush     | Pointer to an [OH_Drawing_Brush](#oh_drawing_brush) object, which is obtained by calling [OH_Drawing_BrushCreate](#oh_drawing_brushcreate). |


### OH_Drawing_SetTextStyleForegroundPen()

```
void OH_Drawing_SetTextStyleForegroundPen (OH_Drawing_TextStyle* , OH_Drawing_Pen*  )
```

**Description**

Sets the foreground pen for a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextStyle | Pointer to an [OH_Drawing_TextStyle](#oh_drawing_textstyle) object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |
| OH_Drawing_Pen       | Pointer to an [OH_Drawing_Pen](#oh_drawing_pen) object, which is obtained by calling [OH_Drawing_PenCreate](#oh_drawing_pencreate). |


### OH_Drawing_SetTextStyleHalfLeading()

```
void OH_Drawing_SetTextStyleHalfLeading (OH_Drawing_TextStyle* , bool  )
```

**Description**

Sets whether to enable half leading for a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |
| bool                 | Whether to enable half leading. The value **true** means to enable half lading, and **false** means the opposite. |


### OH_Drawing_SetTextStyleLetterSpacing()

```
void OH_Drawing_SetTextStyleLetterSpacing (OH_Drawing_TextStyle* , double  )
```

**Description**

Sets the letter spacing for a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |
| double               | Letter spacing.                                              |


### OH_Drawing_SetTextStyleLocale()

```
void OH_Drawing_SetTextStyleLocale (OH_Drawing_TextStyle* , const char*  )
```

**Description**

Sets the locale for a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |
| char                 | Pointer to the locale. For example, **'en'** indicates English, **'zh-Hans'** indicates Simplified Chinese, and **'zh-Hant'** indicates Traditional Chinese. |


### OH_Drawing_SetTextStyleWordSpacing()

```
void OH_Drawing_SetTextStyleWordSpacing (OH_Drawing_TextStyle* , double  )
```

**Description**

Sets the word spacing for a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |
| double               | Letter spacing.                                              |


### OH_Drawing_SetTypographyStyleFontStyleStruct()

```
void OH_Drawing_SetTypographyStyleFontStyleStruct (OH_Drawing_TypographyStyle* drawingStyle, OH_Drawing_FontStyleStruct fontStyle )
```

**Description**

Sets the font style, including the font weight, width, and slant, for a typography style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                                                         | Description                                                  |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle                                   | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |
| [OH_Drawing_FontStyleStruct](_o_h___drawing___font_style_struct.md) | Font style, including the font weight, width, and slant.     |


### OH_Drawing_SetTypographyStyleTextStrutStyle()

```
void OH_Drawing_SetTypographyStyleTextStrutStyle (OH_Drawing_TypographyStyle* , OH_Drawing_StrutStyle*  )
```

**Description**

Sets the strut style for a typography style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                                                     | Description                                                  |
| -------------------------------------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle                               | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |
| [OH_Drawing_StrutStyle](_o_h___drawing___strut_style.md) | Pointer to an [OH_Drawing_StrutStyle](_o_h___drawing___strut_style.md) object, which is obtained by calling [OH_Drawing_TypographyStyleGetStrutStyle](#oh_drawing_typographystylegetstrutstyle). |


### OH_Drawing_SetTypographyTextAlign()

```
void OH_Drawing_SetTypographyTextAlign (OH_Drawing_TypographyStyle* , int  )
```

**Description**

Sets the text alignment mode.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle | Pointer to an **OH_Drawing_TypographyStyle** object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |
| int                        | Text alignment mode. For details about the available options, see [OH_Drawing_TextAlign](#oh_drawing_textalign). |


### OH_Drawing_SetTypographyTextBreakStrategy()

```
void OH_Drawing_SetTypographyTextBreakStrategy (OH_Drawing_TypographyStyle* , int  )
```

**Description**

Sets the text break strategy.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle | Pointer to an **OH_Drawing_TypographyStyle** object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |
| int                        | Text break strategy. For details about the available options, see [OH_Drawing_BreakStrategy](#oh_drawing_breakstrategy). |


### OH_Drawing_SetTypographyTextDirection()

```
void OH_Drawing_SetTypographyTextDirection (OH_Drawing_TypographyStyle* , int  )
```

**Description**

Sets the text direction.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle | Pointer to an **OH_Drawing_TypographyStyle** object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |
| int                        | Text direction. For details about the available options, see [OH_Drawing_TextDirection](#oh_drawing_textdirection). |


### OH_Drawing_SetTypographyTextEllipsis()

```
void OH_Drawing_SetTypographyTextEllipsis (OH_Drawing_TypographyStyle* style, const char* ellipsis )
```

**Description**

Sets the text ellipsis content.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |
| char                       | Pinter to the ellipsis content.                              |


### OH_Drawing_SetTypographyTextEllipsisModal()

```
void OH_Drawing_SetTypographyTextEllipsisModal (OH_Drawing_TypographyStyle* , int  )
```

**Description**

Sets the text ellipsis style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle | Pointer to an **OH_Drawing_TypographyStyle** object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |
| int                        | Ellipsis style. For details about the available options, see [OH_Drawing_EllipsisModal](#oh_drawing_ellipsismodal). |


### OH_Drawing_SetTypographyTextFontFamily()

```
void OH_Drawing_SetTypographyTextFontFamily (OH_Drawing_TypographyStyle* , const char*  )
```

**Description**

Sets the font family name for text.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |
| char                       | Pointer to the name of the font family.                      |


### OH_Drawing_SetTypographyTextFontHeight()

```
void OH_Drawing_SetTypographyTextFontHeight (OH_Drawing_TypographyStyle* , double  )
```

**Description**

Sets the font height for text.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |
| double                     | Font height.                                                 |


### OH_Drawing_SetTypographyTextFontSize()

```
void OH_Drawing_SetTypographyTextFontSize (OH_Drawing_TypographyStyle* , double  )
```

**Description**

Sets the font size for text.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |
| double                     | Font size, which must be greater than 0.                     |


### OH_Drawing_SetTypographyTextFontStyle()

```
void OH_Drawing_SetTypographyTextFontStyle (OH_Drawing_TypographyStyle* , int  )
```

**Description**

Sets the font style for text.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |
| int                        | Font style. For details about the available options, see [OH_Drawing_FontStyle](#oh_drawing_fontstyle). |


### OH_Drawing_SetTypographyTextFontWeight()

```
void OH_Drawing_SetTypographyTextFontWeight (OH_Drawing_TypographyStyle* , int  )
```

**Description**

Sets the font weight for text. Currently, only the default system font supports font weight adjustment. For other fonts, if the weight is less than semi-bold, there is no variation in stroke thickness. If the weight is greater than or equal to semi-bold, it might result in a fake bold effect.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |
| int                        | Font weight. For details about the available options, see [OH_Drawing_FontWeight](#oh_drawing_fontweight). |


### OH_Drawing_SetTypographyTextHalfLeading()

```
void OH_Drawing_SetTypographyTextHalfLeading (OH_Drawing_TypographyStyle* , bool  )
```

**Description**

Sets whether to enable half leading for text.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |
| bool                       | Whether to enable half leading. The value **true** means to enable half lading, and **false** means the opposite. |


### OH_Drawing_SetTypographyTextLineStyleFontFamilies()

```
void OH_Drawing_SetTypographyTextLineStyleFontFamilies (OH_Drawing_TypographyStyle* , int , const char* fontFamilies[] )
```

**Description**

Sets the font families for a text line style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |
| int                        | Number of font families.                                     |
| char                       | Pointer to the font families.                                |


### OH_Drawing_SetTypographyTextLineStyleFontHeight()

```
void OH_Drawing_SetTypographyTextLineStyleFontHeight (OH_Drawing_TypographyStyle* , double  )
```

**Description**

Sets the font height for a text line style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |
| double                     | Font height.                                                 |


### OH_Drawing_SetTypographyTextLineStyleFontSize()

```
void OH_Drawing_SetTypographyTextLineStyleFontSize (OH_Drawing_TypographyStyle* , double  )
```

**Description**

Sets the font size for a text line style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |
| double                     | Font size, which must be greater than 0.                     |


### OH_Drawing_SetTypographyTextLineStyleFontStyle()

```
void OH_Drawing_SetTypographyTextLineStyleFontStyle (OH_Drawing_TypographyStyle* , int  )
```

**Description**

Sets the font style for a text line style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |
| int                        | Font style. For details about the available options, see [OH_Drawing_FontStyle](#oh_drawing_fontstyle). |


### OH_Drawing_SetTypographyTextLineStyleFontWeight()

```
void OH_Drawing_SetTypographyTextLineStyleFontWeight (OH_Drawing_TypographyStyle* , int  )
```

**Description**

Sets the font weight for a text line style. Currently, only the default system font supports font weight adjustment. For other fonts, if the weight is less than semi-bold, there is no variation in stroke thickness. If the weight is greater than or equal to semi-bold, it might result in a fake bold effect.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |
| int                        | Font weight. For details about the available options, see [OH_Drawing_FontWeight](#oh_drawing_fontweight). |


### OH_Drawing_SetTypographyTextLineStyleHalfLeading()

```
void OH_Drawing_SetTypographyTextLineStyleHalfLeading (OH_Drawing_TypographyStyle* , bool  )
```

**Description**

Sets whether to enable half leading for a text line style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |
| bool                       | Whether to enable half leading. The value **true** means to enable half lading, and **false** means the opposite. |


### OH_Drawing_SetTypographyTextLineStyleOnly()

```
void OH_Drawing_SetTypographyTextLineStyleOnly (OH_Drawing_TypographyStyle* , bool  )
```

**Description**

Sets whether to enable the text line style only.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |
| bool                       | Whether to enable the text line style only. The value **true** means to enable the text line style only, and **false** means the opposite. |


### OH_Drawing_SetTypographyTextLineStyleSpacingScale()

```
void OH_Drawing_SetTypographyTextLineStyleSpacingScale (OH_Drawing_TypographyStyle* , double  )
```

**Description**

Sets the spacing scale factor for a text line style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |
| double                     | Spacing ratio.                                               |


### OH_Drawing_SetTypographyTextLocale()

```
void OH_Drawing_SetTypographyTextLocale (OH_Drawing_TypographyStyle* style, const char* locale )
```

**Description**

Sets the locale for text.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |
| char                       | Pointer to the locale. For example, **'en'** indicates English, **'zh-Hans'** indicates Simplified Chinese, and **'zh-Hant'** indicates Traditional Chinese. |


### OH_Drawing_SetTypographyTextMaxLines()

```
void OH_Drawing_SetTypographyTextMaxLines (OH_Drawing_TypographyStyle* , int  )
```

**Description**

Sets the maximum number of lines in the text.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle | Pointer to an **OH_Drawing_TypographyStyle** object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |
| int                        | Maximum number of lines.                                     |

### OH_Drawing_SetTypographyTextSplitRatio()

```
void OH_Drawing_SetTypographyTextSplitRatio (OH_Drawing_TypographyStyle* style, float textSplitRatio )
```

**Description**

Sets the text split ratio.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |
| float                      | Text split ratio.                                            |


### OH_Drawing_SetTypographyTextStyle()

```
void OH_Drawing_SetTypographyTextStyle (OH_Drawing_TypographyStyle* , OH_Drawing_TextStyle*  )
```

**Description**

Sets a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |
| OH_Drawing_TextStyle       | Pointer to an [OH_Drawing_TextStyle](#oh_drawing_textstyle) object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |


### OH_Drawing_SetTypographyTextUseLineStyle()

```
void OH_Drawing_SetTypographyTextUseLineStyle (OH_Drawing_TypographyStyle* , bool  )
```

**Description**

Sets whether to enable the text line style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |
| bool                       | Whether to enable the text line style. The value **true** means to enable the text line style, and **false** means the opposite. |


### OH_Drawing_SetTypographyTextWordBreakType()

```
void OH_Drawing_SetTypographyTextWordBreakType (OH_Drawing_TypographyStyle* , int  )
```

**Description**

Sets the word break type.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle | Pointer to an **OH_Drawing_TypographyStyle** object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |
| int                        | Word break type. For details about the available options, see [OH_Drawing_WordBreakType](#oh_drawing_wordbreaktype). |


### OH_Drawing_ShaderEffectCreateImageShader()

```
OH_Drawing_ShaderEffect* OH_Drawing_ShaderEffectCreateImageShader (OH_Drawing_Image* , OH_Drawing_TileMode tileX, OH_Drawing_TileMode tileY, const OH_Drawing_SamplingOptions* , const OH_Drawing_Matrix*  )
```

**Description**

Creates an **OH_Drawing_ShaderEffect** object for an image shader. You are advised not to use the API for the canvas of the capture type because it affects the performance.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **OH_Drawing_Image** or **OH_Drawing_SamplingOptions** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

If either **tileX** or **tileY** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_Image           | Pointer to an [OH_Drawing_Image](#oh_drawing_image) object.  |
| tileX                      | Tile mode of the shader effect in the horizontal direction. For details about the available options, see [OH_Drawing_TileMode](#oh_drawing_tilemode-1). |
| tileY                      | Tile mode of the shader effect in the vertical direction. For details about the available options, see [OH_Drawing_TileMode](#oh_drawing_tilemode-1). |
| OH_Drawing_SamplingOptions | Pointer to an [OH_Drawing_SamplingOptions](#oh_drawing_samplingoptions) object. |
| OH_Drawing_Matrix          | Pointer to an [OH_Drawing_Matrix](#oh_drawing_matrix) object. If the pointer array is empty, the identity matrix is passed in. |

**Returns**

Returns the pointer to the **OH_Drawing_ShaderEffect** object created.


### OH_Drawing_ShaderEffectCreateLinearGradient()

```
OH_Drawing_ShaderEffect* OH_Drawing_ShaderEffectCreateLinearGradient (const OH_Drawing_Point* startPt, const OH_Drawing_Point* endPt, const uint32_t* colors, const float* pos, uint32_t size, OH_Drawing_TileMode  )
```

**Description**

Creates an **OH_Drawing_ShaderEffect** object that generates a linear gradient between two points.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If any of **startPt**, **endPt**, and **colors** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

If **OH_Drawing_TileMode** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name                | Description                                                  |
| ------------------- | ------------------------------------------------------------ |
| startPt             | Start point.                                                 |
| endPt               | End point.                                                   |
| colors              | Colors to distribute.                                        |
| pos                 | Relative position of each color in the color array. If **pos** is NULL, colors are evenly distributed between the start point and end point. |
| size                | Number of colors and positions (if **pos** is not NULL).     |
| OH_Drawing_TileMode | Tile mode of the shader effect. For details about the available options, see [OH_Drawing_TileMode](#oh_drawing_tilemode-1). |

**Returns**

Returns the pointer to the **OH_Drawing_ShaderEffect** object created.


### OH_Drawing_ShaderEffectCreateRadialGradient()

```
OH_Drawing_ShaderEffect* OH_Drawing_ShaderEffectCreateRadialGradient (const OH_Drawing_Point* centerPt, float radius, const uint32_t* colors, const float* pos, uint32_t size, OH_Drawing_TileMode  )
```

**Description**

Creates an **OH_Drawing_ShaderEffect** object that generates a radial gradient based on the center and radius of a circle. The radial gradient transitions colors from the center to the ending shape in a radial manner.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **centerPt** or **colors** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

If **OH_Drawing_TileMode** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name                | Description                                                  |
| ------------------- | ------------------------------------------------------------ |
| centerPt            | Center of the circle.                                        |
| radius              | Radius of the circle.                                        |
| colors              | Colors to distribute in the radial direction.                |
| pos                 | Relative position of each color in the color array. If **pos** is NULL, colors are evenly distributed in the radial direction. |
| size                | Number of colors and positions (if **pos** is not NULL).     |
| OH_Drawing_TileMode | Tile mode of the shader effect. For details about the available options, see [OH_Drawing_TileMode](#oh_drawing_tilemode-1). |

**Returns**

Returns the pointer to the **OH_Drawing_ShaderEffect** object created.


### OH_Drawing_ShaderEffectCreateSweepGradient()

```
OH_Drawing_ShaderEffect* OH_Drawing_ShaderEffectCreateSweepGradient (const OH_Drawing_Point* centerPt, const uint32_t* colors, const float* pos, uint32_t size, OH_Drawing_TileMode  )
```

**Description**

Creates an **OH_Drawing_ShaderEffect** object that generates a sweep gradient based on the center. A sweep gradient paints a gradient in a sweeping arc ranging from 0° to 360°.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **centerPt** or **colors** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

If **OH_Drawing_TileMode** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name                | Description                                                  |
| ------------------- | ------------------------------------------------------------ |
| centerPt            | Center of the circle.                                        |
| colors              | Colors to distribute.                                        |
| pos                 | Relative position of each color in the color array. If **pos** is NULL, colors are evenly distributed between the start angle (0°) and end angle (360°). |
| size                | Number of colors and positions (if **pos** is not NULL).     |
| OH_Drawing_TileMode | Tile mode of the shader effect. For details about the available options, see [OH_Drawing_TileMode](#oh_drawing_tilemode-1). |

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

| Name                    | Description                                       |
| ----------------------- | ------------------------------------------------- |
| OH_Drawing_ShaderEffect | Pointer to an **OH_Drawing_ShaderEffect** object. |


### OH_Drawing_SurfaceCreateFromGpuContext()

```
OH_Drawing_Surface* OH_Drawing_SurfaceCreateFromGpuContext (OH_Drawing_GpuContext* , bool budgeted, OH_Drawing_Image_Info  )
```

**Description**

Creates an **OH_Drawing_Surface** object using the GPU context to manage the content drawn on the canvas.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_GpuContext** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                                                      | Description                                                  |
| --------------------------------------------------------- | ------------------------------------------------------------ |
| OH_Drawing_GpuContext                                     | Pointer to an [OH_Drawing_GpuContext](#oh_drawing_gpucontext) object. |
| budgeted                                                  | Whether memory allocation is included in the cache budget. The value **true** means that memory allocation is included in the cache budget, and **false** means the opposite. |
| [OH_Drawing_Image_Info](_o_h___drawing___image___info.md) | [OH_Drawing_Image_Info](_o_h___drawing___image___info.md) object. |

**Returns**

Returns the pointer to the [OH_Drawing_Surface](#oh_drawing_surface) object created.


### OH_Drawing_SurfaceDestroy()

```
void OH_Drawing_SurfaceDestroy (OH_Drawing_Surface* )
```

**Description**

Destroys an **OH_Drawing_Surface** object and reclaims the memory occupied.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name               | Description                                  |
| ------------------ | -------------------------------------------- |
| OH_Drawing_Surface | Pointer to an **OH_Drawing_Surface** object. |


### OH_Drawing_SurfaceGetCanvas()

```
OH_Drawing_Canvas* OH_Drawing_SurfaceGetCanvas (OH_Drawing_Surface* )
```

**Description**

Obtains a canvas from an **OH_Drawing_Surface** object.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_Surface** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name               | Description                                  |
| ------------------ | -------------------------------------------- |
| OH_Drawing_Surface | Pointer to an **OH_Drawing_Surface** object. |

**Returns**

Returns the pointer to the [OH_Drawing_Canvas](#oh_drawing_canvas) object created. The pointer returned does not need to be managed by the caller. 


### OH_Drawing_TextBlobBuilderAllocRunPos()

```
const OH_Drawing_RunBuffer* OH_Drawing_TextBlobBuilderAllocRunPos (OH_Drawing_TextBlobBuilder* , const OH_Drawing_Font* , int32_t count, const OH_Drawing_Rect*  )
```

**Description**

Allocates a run to store glyphs and positions. The pointer returned does not need to be managed by the caller. It can no longer be used after [OH_Drawing_TextBlobBuilderMake](#oh_drawing_textblobbuildermake) is called.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **OH_Drawing_TextBlobBuilder** or **OH_Drawing_Font** is NULL or **count** is less than or equal to 0, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextBlobBuilder | Pointer to an **OH_Drawing_TextBlobBuilder** object.         |
| OH_Drawing_Font            | Pointer to an **OH_Drawing_Font** object.                    |
| count                      | Number of text blobs.                                        |
| OH_Drawing_Rect            | Rectangle of the text blob. The value NULL means that no rectangle is set. |


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

| Name                       | Description                                          |
| -------------------------- | ---------------------------------------------------- |
| OH_Drawing_TextBlobBuilder | Pointer to an **OH_Drawing_TextBlobBuilder** object. |


### OH_Drawing_TextBlobBuilderMake()

```
OH_Drawing_TextBlob* OH_Drawing_TextBlobBuilderMake (OH_Drawing_TextBlobBuilder* )
```

**Description**

Makes an **OH_Drawing_TextBlob** object from an **OH_Drawing_TextBlobBuilder**.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_TextBlobBuilder** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name                       | Description                                          |
| -------------------------- | ---------------------------------------------------- |
| OH_Drawing_TextBlobBuilder | Pointer to an **OH_Drawing_TextBlobBuilder** object. |

**Returns**

Returns the pointer to the **OH_Drawing_TextBlob** object created.


### OH_Drawing_TextBlobCreateFromPosText()

```
OH_Drawing_TextBlob* OH_Drawing_TextBlobCreateFromPosText (const void * text, size_t byteLength, OH_Drawing_Point2D* , const OH_Drawing_Font* , OH_Drawing_TextEncoding  )
```

**Description**

Creates an **OH_Drawing_TextBlob** object from the text. The coordinates of each character in the **OH_Drawing_TextBlob** object are determined by the coordinate information in the **OH_Drawing_Point2D** array.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If any of **text**, **OH_Drawing_Point2D**, and **OH_Drawing_Font** is NULL or **byteLength** is **0**, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

If **OH_Drawing_TextEncoding** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                                               | Description                                                  |
| -------------------------------------------------- | ------------------------------------------------------------ |
| text                                               | Pointer to the text.                                         |
| byteLength                                         | Length of the text, in bytes.                                |
| [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) | Pointer to the start address of an [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) array. The number of entries in the array is the value obtained by calling [OH_Drawing_FontCountText](#oh_drawing_fontcounttext). |
| OH_Drawing_Font                                    | Pointer to an [OH_Drawing_Font](#oh_drawing_font) object.    |
| OH_Drawing_TextEncoding                            | Encoding type of the text. For details about the available options, see [OH_Drawing_TextEncoding](#oh_drawing_textencoding). |

**Returns**

Returns the pointer to the [OH_Drawing_TextBlob](#oh_drawing_textblob) object created.


### OH_Drawing_TextBlobCreateFromString()

```
OH_Drawing_TextBlob* OH_Drawing_TextBlobCreateFromString (const char* str, const OH_Drawing_Font* , OH_Drawing_TextEncoding  )
```

**Description**

Creates an **OH_Drawing_TextBlob** object from a string.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **str** or **OH_Drawing_Font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

If **OH_Drawing_TextEncoding** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                    | Description                                                  |
| ----------------------- | ------------------------------------------------------------ |
| str                     | Pointer to a string.                                         |
| OH_Drawing_Font         | Pointer to an [OH_Drawing_Font](#oh_drawing_font) object.    |
| OH_Drawing_TextEncoding | Encoding type of the text. For details about the available options, see [OH_Drawing_TextEncoding](#oh_drawing_textencoding). Currently, only **TEXT_ENCODING_UTF8** takes effect, and other encoding types are treated as **TEXT_ENCODING_UTF8**. |

**Returns**

Returns the pointer to the [OH_Drawing_TextBlob](#oh_drawing_textblob) object created.


### OH_Drawing_TextBlobCreateFromText()

```
OH_Drawing_TextBlob* OH_Drawing_TextBlobCreateFromText (const void * text, size_t byteLength, const OH_Drawing_Font* , OH_Drawing_TextEncoding  )
```

**Description**

Creates an **OH_Drawing_TextBlob** object from the text.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **text** or **OH_Drawing_Font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

If **OH_Drawing_TextEncoding** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                    | Description                                                  |
| ----------------------- | ------------------------------------------------------------ |
| text                    | Pointer to the text.                                         |
| byteLength              | Length of the text, in bytes.                                |
| OH_Drawing_Font         | Pointer to an [OH_Drawing_Font](#oh_drawing_font) object.    |
| OH_Drawing_TextEncoding | Encoding type of the text. For details about the available options, see [OH_Drawing_TextEncoding](#oh_drawing_textencoding). |

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

| Name                | Description                                   |
| ------------------- | --------------------------------------------- |
| OH_Drawing_TextBlob | Pointer to an **OH_Drawing_TextBlob** object. |


### OH_Drawing_TextBlobGetBounds()

```
void OH_Drawing_TextBlobGetBounds (OH_Drawing_TextBlob* , OH_Drawing_Rect*  )
```

**Description**

Obtains the bounds of an **OH_Drawing_TextBlob** object.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If either **OH_Drawing_TextBlob** or **OH_Drawing_Rect** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                | Description                                                  |
| ------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextBlob | Pointer to an [OH_Drawing_TextBlob](#oh_drawing_textblob) object. |
| OH_Drawing_Rect     | Pointer to an [OH_Drawing_Rect](#oh_drawing_rect) object, which is obtained by calling [OH_Drawing_RectCreate](#oh_drawing_rectcreate). |


### OH_Drawing_TextStyleAddFontFeature()

```
void OH_Drawing_TextStyleAddFontFeature (OH_Drawing_TextStyle* , const char* tag, int value )
```

**Description**

Adds a font feature for a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |
| char                 | Pointer to the string identified by the keyword in the font feature key-value pair. |
| int                  | Value of the font feature key-value pair.                    |


### OH_Drawing_TextStyleAddFontVariation()

```
void OH_Drawing_TextStyleAddFontVariation (OH_Drawing_TextStyle* , const char* , const float  )
```

**Description**

Adds a font variation. This function takes effect only when the corresponding font file (.ttf file) supports variable adjustment. Otherwise, calling this function does not take effect.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |
| char\*               | Pointer to the key in the font variation key-value pair. Currently, only **'wght'** is supported, indicating the font weight. |
| float                | Value of the font variation key-value pair. Currently, the value range of **'wght'** for the default font is \[0,900\]. |


### OH_Drawing_TextStyleAddShadow()

```
void OH_Drawing_TextStyleAddShadow (OH_Drawing_TextStyle* , const OH_Drawing_TextShadow*  )
```

**Description**

Adds a shadow to a text shadow container.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                  | Description                                                  |
| --------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextStyle  | Pointer to an [OH_Drawing_TextStyle](#oh_drawing_textstyle) object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |
| OH_Drawing_TextShadow | Pointer to an [OH_Drawing_TextShadow](#oh_drawing_textshadow) object, which is obtained by calling [OH_Drawing_CreateTextShadow](#oh_drawing_createtextshadow). |


### OH_Drawing_TextStyleClearFontFeature()

```
void OH_Drawing_TextStyleClearFontFeature (OH_Drawing_TextStyle* )
```

**Description**

Clears all the contents in a font feature map container.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |


### OH_Drawing_TextStyleClearShadows()

```
void OH_Drawing_TextStyleClearShadows (OH_Drawing_TextStyle* )
```

**Description**

Clears all shadows in a text shadow container.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextStyle | Pointer to an [OH_Drawing_TextStyle](#oh_drawing_textstyle) object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |


### OH_Drawing_TextStyleDestroyFontFamilies()

```
void OH_Drawing_TextStyleDestroyFontFamilies (char** fontFamilies, size_t num )
```

**Description**

Reclaims the memory occupied by the font families.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name     | Description                          |
| -------- | ------------------------------------ |
| char\*\* | Double pointer to the font families. |
| size_t   | Number of font families.             |


### OH_Drawing_TextStyleDestroyFontFeatures()

```
void OH_Drawing_TextStyleDestroyFontFeatures (OH_Drawing_FontFeature* , size_t fontFeatureSize )
```

**Description**

Reclaims the memory occupied by the struct array that holds all the font features.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                                                       | Description                                                  |
| ---------------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Drawing_FontFeature](_o_h___drawing___font_feature.md) | Pointer to the struct array that holds all the font features. The pointer is obtained by calling [OH_Drawing_TextStyleGetFontFeatures](#oh_drawing_textstylegetfontfeatures). |
| fontFeatureSize                                            | Size of the struct array that holds all the font features.   |


### OH_Drawing_TextStyleGetBackgroundBrush()

```
void OH_Drawing_TextStyleGetBackgroundBrush (OH_Drawing_TextStyle* , OH_Drawing_Brush*  )
```

**Description**

Obtains the background brush of a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextStyle | Pointer to an [OH_Drawing_TextStyle](#oh_drawing_textstyle) object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |
| OH_Drawing_Brush     | Pointer to an [OH_Drawing_Brush](#oh_drawing_brush) object, which is obtained by calling [OH_Drawing_BrushCreate](#oh_drawing_brushcreate). |


### OH_Drawing_TextStyleGetBackgroundPen()

```
void OH_Drawing_TextStyleGetBackgroundPen (OH_Drawing_TextStyle* , OH_Drawing_Pen*  )
```

**Description**

Obtains the background pen of a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextStyle | Pointer to an [OH_Drawing_TextStyle](#oh_drawing_textstyle) object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |
| OH_Drawing_Pen       | Pointer to an [OH_Drawing_Pen](#oh_drawing_pen) object, which is obtained by calling [OH_Drawing_PenCreate](#oh_drawing_pencreate). |


### OH_Drawing_TextStyleGetBaseline()

```
OH_Drawing_TextBaseline OH_Drawing_TextStyleGetBaseline (OH_Drawing_TextStyle* )
```

**Description**

Obtains the baseline of a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextStyle | Pointer to an [OH_Drawing_TextStyle](#oh_drawing_textstyle) object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |

**Returns**

Returns the text baseline. For details about the available options, see [OH_Drawing_TextBaseline](#oh_drawing_textbaseline).


### OH_Drawing_TextStyleGetBaselineShift()

```
double OH_Drawing_TextStyleGetBaselineShift (OH_Drawing_TextStyle* )
```

**Description**

Obtains the baseline drift of a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |

**Returns**

Returns the baseline drift.


### OH_Drawing_TextStyleGetColor()

```
uint32_t OH_Drawing_TextStyleGetColor (OH_Drawing_TextStyle* )
```

**Description**

Obtains the color of a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextStyle | Pointer to an [OH_Drawing_TextStyle](#oh_drawing_textstyle) object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |

**Returns**

Returns the text color.


### OH_Drawing_TextStyleGetDecorationStyle()

```
OH_Drawing_TextDecorationStyle OH_Drawing_TextStyleGetDecorationStyle (OH_Drawing_TextStyle* )
```

**Description**

Obtains the decoration style of a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextStyle | Pointer to an [OH_Drawing_TextStyle](#oh_drawing_textstyle) object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |

**Returns**

Returns the text decoration style. For details about the available options, see [OH_Drawing_TextDecorationStyle](#oh_drawing_textdecorationstyle).


### OH_Drawing_TextStyleGetFontFamilies()

```
char** OH_Drawing_TextStyleGetFontFamilies (OH_Drawing_TextStyle* , size_t* num )
```

**Description**

Obtains the font families of a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextStyle | Pointer to an [OH_Drawing_TextStyle](#oh_drawing_textstyle) object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |
| size_t               | Pointer to the number of font families.                      |

**Returns**

Returns the font families.


### OH_Drawing_TextStyleGetFontFeatures()

```
OH_Drawing_FontFeature* OH_Drawing_TextStyleGetFontFeatures (OH_Drawing_TextStyle* )
```

**Description**

Obtains all the contents in a font feature map container.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |

**Returns**

Returns the pointer to the [OH_Drawing_FontFeature](_o_h___drawing___font_feature.md) struct, which stores all the contents obtained.


### OH_Drawing_TextStyleGetFontFeatureSize()

```
size_t OH_Drawing_TextStyleGetFontFeatureSize (OH_Drawing_TextStyle* )
```

**Description**

Obtains the size of a font feature map container.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |

**Returns**

Returns the size.


### OH_Drawing_TextStyleGetFontHeight()

```
double OH_Drawing_TextStyleGetFontHeight (OH_Drawing_TextStyle* )
```

**Description**

Obtains the font height of a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextStyle | Pointer to an [OH_Drawing_TextStyle](#oh_drawing_textstyle) object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |

**Returns**

Returns the font height.


### OH_Drawing_TextStyleGetFontMetrics()

```
bool OH_Drawing_TextStyleGetFontMetrics (OH_Drawing_Typography* , OH_Drawing_TextStyle* , OH_Drawing_Font_Metrics*  )
```

**Description**

Obtains the font metrics of a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                    | Description                                                  |
| ----------------------- | ------------------------------------------------------------ |
| OH_Drawing_Typography   | Pointer to an [OH_Drawing_Typography](#oh_drawing_typography) object, which is obtained by calling [OH_Drawing_CreateTypography](#oh_drawing_createtypography). |
| OH_Drawing_TextStyle    | Pointer to an [OH_Drawing_TextStyle](#oh_drawing_textstyle) object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |
| OH_Drawing_Font_Metrics | Pointer to an [OH_Drawing_Font_Metrics](_o_h___drawing___font___metrics.md) object, which is obtained by calling [OH_Drawing_Font_Metrics](_o_h___drawing___font___metrics.md). |

**Returns**

Returns **true** if the font metrics are obtained; returns **false** otherwise.


### OH_Drawing_TextStyleGetFontSize()

```
double OH_Drawing_TextStyleGetFontSize (OH_Drawing_TextStyle* )
```

**Description**

Obtains the font size of a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextStyle | Pointer to an [OH_Drawing_TextStyle](#oh_drawing_textstyle) object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |

**Returns**

Returns the font size.


### OH_Drawing_TextStyleGetFontStyle()

```
OH_Drawing_FontStyle OH_Drawing_TextStyleGetFontStyle (OH_Drawing_TextStyle* )
```

**Description**

Obtains the font style of a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextStyle | Pointer to an [OH_Drawing_TextStyle](#oh_drawing_textstyle) object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |

**Returns**

Returns the font style. For details about the available options, see [OH_Drawing_FontStyle](#oh_drawing_fontstyle).


### OH_Drawing_TextStyleGetFontStyleStruct()

```
OH_Drawing_FontStyleStruct OH_Drawing_TextStyleGetFontStyleStruct (OH_Drawing_TextStyle* drawingTextStyle)
```

**Description**

Obtains the font style, including the font weight, width, and slant, of a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextStyle | Pointer to an [OH_Drawing_TextStyle](#oh_drawing_textstyle) object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |

**Returns**

Returns the font style, including the font weight, width, and slant.


### OH_Drawing_TextStyleGetFontWeight()

```
OH_Drawing_FontWeight OH_Drawing_TextStyleGetFontWeight (OH_Drawing_TextStyle* )
```

**Description**

Obtains the font weight of a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextStyle | Pointer to an [OH_Drawing_TextStyle](#oh_drawing_textstyle) object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |

**Returns**

Returns the font weight. For details about the available options, see [OH_Drawing_FontWeight](#oh_drawing_fontweight).


### OH_Drawing_TextStyleGetForegroundBrush()

```
void OH_Drawing_TextStyleGetForegroundBrush (OH_Drawing_TextStyle* , OH_Drawing_Brush*  )
```

**Description**

Obtains the foreground brush of a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextStyle | Pointer to an [OH_Drawing_TextStyle](#oh_drawing_textstyle) object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |
| OH_Drawing_Brush     | Pointer to an [OH_Drawing_Brush](#oh_drawing_brush) object, which is obtained by calling [OH_Drawing_BrushCreate](#oh_drawing_brushcreate). |


### OH_Drawing_TextStyleGetForegroundPen()

```
void OH_Drawing_TextStyleGetForegroundPen (OH_Drawing_TextStyle* , OH_Drawing_Pen*  )
```

**Description**

Obtains the foreground pen of a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextStyle | Pointer to an [OH_Drawing_TextStyle](#oh_drawing_textstyle) object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |
| OH_Drawing_Pen       | Pointer to an [OH_Drawing_Pen](#oh_drawing_pen) object, which is obtained by calling [OH_Drawing_PenCreate](#oh_drawing_pencreate). |


### OH_Drawing_TextStyleGetHalfLeading()

```
bool OH_Drawing_TextStyleGetHalfLeading (OH_Drawing_TextStyle* )
```

**Description**

Checks whether half leading is enabled for a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextStyle | Pointer to an [OH_Drawing_TextStyle](#oh_drawing_textstyle) object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |

**Returns**

Returns **true** if half leading is enabled; returns **false** otherwise.


### OH_Drawing_TextStyleGetLetterSpacing()

```
double OH_Drawing_TextStyleGetLetterSpacing (OH_Drawing_TextStyle* )
```

**Description**

Obtains the letter spacing of a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextStyle | Pointer to an [OH_Drawing_TextStyle](#oh_drawing_textstyle) object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |

**Returns**

Returns the letter spacing.


### OH_Drawing_TextStyleGetLocale()

```
const char* OH_Drawing_TextStyleGetLocale (OH_Drawing_TextStyle* )
```

**Description**

Obtains the locale of a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextStyle | Pointer to an [OH_Drawing_TextStyle](#oh_drawing_textstyle) object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |

**Returns**

Returns the pointer to the locale, in the format of language-country. For example, zh-CN indicates Chinese (China), and en-US indicates English (United States). For details, see BCP 47.


### OH_Drawing_TextStyleGetShadowCount()

```
int OH_Drawing_TextStyleGetShadowCount (OH_Drawing_TextStyle* )
```

**Description**

Obtains the size of a text shadow container.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextStyle | Pointer to an [OH_Drawing_TextStyle](#oh_drawing_textstyle) object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |

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

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextStyle | Pointer to an [OH_Drawing_TextStyle](#oh_drawing_textstyle) object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |

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

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextStyle | Pointer to an [OH_Drawing_TextStyle](#oh_drawing_textstyle) object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |
| int                  | Index.                                                       |

**Returns**

Returns the pointer to the [OH_Drawing_TextShadow](#oh_drawing_textshadow) object.


### OH_Drawing_TextStyleGetWordSpacing()

```
double OH_Drawing_TextStyleGetWordSpacing (OH_Drawing_TextStyle* )
```

**Description**

Obtains the word spacing of a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextStyle | Pointer to an [OH_Drawing_TextStyle](#oh_drawing_textstyle) object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |

**Returns**

Returns the word spacing.


### OH_Drawing_TextStyleIsAttributeMatched()

```
bool OH_Drawing_TextStyleIsAttributeMatched (const OH_Drawing_TextStyle* style, const OH_Drawing_TextStyle* comparedStyle, OH_Drawing_TextStyleType textStyleType )
```

**Description**

Checks whether two text styles have the same text style type.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name          | Description                                                  |
| ------------- | ------------------------------------------------------------ |
| style         | Pointer to the first text style.                             |
| comparedStyle | Pointer to the second text style.                            |
| textStyleType | Text style type. For details about the available options, see [OH_Drawing_TextStyleType](#oh_drawing_textstyletype). |

**Returns**

Returns **true** if the two are the same; returns **false** otherwise.


### OH_Drawing_TextStyleIsEqual()

```
bool OH_Drawing_TextStyleIsEqual (const OH_Drawing_TextStyle* style, const OH_Drawing_TextStyle* comparedStyle )
```

**Description**

Checks whether two text styles are equal.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name          | Description                       |
| ------------- | --------------------------------- |
| style         | Pointer to the first text style.  |
| comparedStyle | Pointer to the second text style. |

**Returns**

Returns **true** if the two are equal; returns **false** otherwise.


### OH_Drawing_TextStyleIsEqualByFont()

```
bool OH_Drawing_TextStyleIsEqualByFont (const OH_Drawing_TextStyle* style, const OH_Drawing_TextStyle* comparedStyle )
```

**Description**

Checks whether the font style properties of two text styles are equal.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name          | Description                       |
| ------------- | --------------------------------- |
| style         | Pointer to the first text style.  |
| comparedStyle | Pointer to the second text style. |

**Returns**

Returns **true** if the two are equal; returns **false** otherwise.


### OH_Drawing_TextStyleIsPlaceholder()

```
bool OH_Drawing_TextStyleIsPlaceholder (OH_Drawing_TextStyle* style)
```

**Description**

Checks whether a placeholder is set for a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextStyle | Pointer to an [OH_Drawing_TextStyle](#oh_drawing_textstyle) object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |

**Returns**

Returns **true** if a placeholder is set; returns **false** otherwise.


### OH_Drawing_TextStyleSetBackgroundRect()

```
void OH_Drawing_TextStyleSetBackgroundRect (OH_Drawing_TextStyle* , const OH_Drawing_RectStyle_Info* , int styleId )
```

**Description**

Sets a background rectangle and style ID for a text style. The style ID is valid only when the background box is a rounded rectangle.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                                                         | Description                                                  |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| OH_Drawing_TextStyle                                         | Pointer to an **OH_Drawing_TextStyle** object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |
| [OH_Drawing_RectStyle_Info](_o_h___drawing___rect_style___info.md) | Pointer to an [OH_Drawing_RectStyle_Info](_o_h___drawing___rect_style___info.md) object. |
| int                                                          | Style ID. The style ID is valid only when the background box is a rounded rectangle. Text processing is divided into multiple segments. Each segment has its own text style. **id** indicates the sequence number of the background box in which the segment is drawn. If the ID of each segment in a row is 0, all segments are drawn in the same background box. If the IDs in a row are 0 and 1, the segment whose ID is 0 is drawn in a background box, the segment whose ID is 1 is drawn in another background box. Other cases can be deduced in the same way. |


### OH_Drawing_TextStyleSetBaselineShift()

```
void OH_Drawing_TextStyleSetBaselineShift (OH_Drawing_TextStyle* , double lineShift )
```

**Description**

Sets a baseline drift for a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |
| double               | Baseline drift of the text style.                            |


### OH_Drawing_TextStyleSetPlaceholder()

```
void OH_Drawing_TextStyleSetPlaceholder (OH_Drawing_TextStyle* style)
```

**Description**

Sets a placeholder for a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                 | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| OH_Drawing_TextStyle | Pointer to an [OH_Drawing_TextStyle](#oh_drawing_textstyle) object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |


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

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **path** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name  | Description               |
| ----- | ------------------------- |
| path  | Pointer to the file path. |
| index | File index.               |

**Returns**

Returns the pointer to the [OH_Drawing_Typeface](#oh_drawing_typeface) object created.


### OH_Drawing_TypefaceCreateFromStream()

```
OH_Drawing_Typeface* OH_Drawing_TypefaceCreateFromStream (OH_Drawing_MemoryStream* , int32_t index )
```

**Description**

Creates an **OH_Drawing_Typeface** object through a memory stream. If the memory stream is an invalid font file, a null pointer is returned. After the memory stream is passed in, the ownership is transferred and you cannot release it.

Error codes may be generated in the call. You can view the error code by calling [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget).

If the operation is successful, **OH_DRAWING_SUCCESS** is returned.

If **OH_Drawing_MemoryStream** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                    | Description                                                  |
| ----------------------- | ------------------------------------------------------------ |
| OH_Drawing_MemoryStream | Pointer to an [OH_Drawing_MemoryStream](#oh_drawing_memorystream) object. |
| index                   | Index of the memory stream.                                  |

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

| Name                | Description                                   |
| ------------------- | --------------------------------------------- |
| OH_Drawing_Typeface | Pointer to an **OH_Drawing_Typeface** object. |


### OH_Drawing_TypographyDestroyEllipsis()

```
void OH_Drawing_TypographyDestroyEllipsis (char* ellipsis)
```

**Description**

Reclaims the memory occupied by the text ellipsis names.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name     | Description                         |
| -------- | ----------------------------------- |
| ellipsis | Pointer to the text ellipsis names. |


### OH_Drawing_TypographyDestroyLineFontMetrics()

```
void OH_Drawing_TypographyDestroyLineFontMetrics (OH_Drawing_Font_Metrics* )
```

**Description**

Reclaims the memory occupied by the struct array that holds all the font metrics of a given line.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                                                         | Description                                       |
| ------------------------------------------------------------ | ------------------------------------------------- |
| [OH_Drawing_Font_Metrics](_o_h___drawing___font___metrics.md) | Pointer to the first address of the struct array. |


### OH_Drawing_TypographyDidExceedMaxLines()

```
bool OH_Drawing_TypographyDidExceedMaxLines (OH_Drawing_Typography* )
```

**Description**

Checks whether the maximum number of lines is exceeded.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name                  | Description                                                  |
| --------------------- | ------------------------------------------------------------ |
| OH_Drawing_Typography | Pointer to an **OH_Drawing_Typography** object, which is obtained by calling [OH_Drawing_CreateTypography](#oh_drawing_createtypography). |

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

| Name                  | Description                                                  |
| --------------------- | ------------------------------------------------------------ |
| OH_Drawing_Typography | Pointer to an **OH_Drawing_Typography** object, which is obtained by calling [OH_Drawing_CreateTypography](#oh_drawing_createtypography). |

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

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |

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

| Name                  | Description                                                  |
| --------------------- | ------------------------------------------------------------ |
| OH_Drawing_Typography | Pointer to an **OH_Drawing_Typography** object, which is obtained by calling [OH_Drawing_CreateTypography](#oh_drawing_createtypography). |
| double                | X coordinate.                                                |
| double                | Y coordinate.                                                |

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

| Name                  | Description                                                  |
| --------------------- | ------------------------------------------------------------ |
| OH_Drawing_Typography | Pointer to an **OH_Drawing_Typography** object, which is obtained by calling [OH_Drawing_CreateTypography](#oh_drawing_createtypography). |
| double                | X coordinate.                                                |
| double                | Y coordinate.                                                |

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

| Name                  | Description                                                  |
| --------------------- | ------------------------------------------------------------ |
| OH_Drawing_Typography | Pointer to an **OH_Drawing_Typography** object, which is obtained by calling [OH_Drawing_CreateTypography](#oh_drawing_createtypography). |

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

| Name                  | Description                                                  |
| --------------------- | ------------------------------------------------------------ |
| OH_Drawing_Typography | Pointer to an **OH_Drawing_Typography** object, which is obtained by calling [OH_Drawing_CreateTypography](#oh_drawing_createtypography). |

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

| Name                  | Description                                                  |
| --------------------- | ------------------------------------------------------------ |
| OH_Drawing_Typography | Pointer to an [OH_Drawing_Typography](#oh_drawing_typography) object, which is obtained by calling [OH_Drawing_CreateTypography](#oh_drawing_createtypography). |
| int                   | Index.                                                       |

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

| Name                  | Description                                                  |
| --------------------- | ------------------------------------------------------------ |
| OH_Drawing_Typography | Pointer to an **OH_Drawing_Typography** object, which is obtained by calling [OH_Drawing_CreateTypography](#oh_drawing_createtypography). |

**Returns**

Returns the number of lines.


### OH_Drawing_TypographyGetLineFontMetrics()

```
OH_Drawing_Font_Metrics* OH_Drawing_TypographyGetLineFontMetrics (OH_Drawing_Typography* , size_t lineNumber, size_t* fontMetricsSize )
```

**Description**

Obtains all font metrics from a given line.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                  | Description                                                  |
| --------------------- | ------------------------------------------------------------ |
| OH_Drawing_Typography | Pointer to an [OH_Drawing_Typography](#oh_drawing_typography) object, which is obtained by calling [OH_Drawing_CreateTypography](#oh_drawing_createtypography). |
| lineNumber            | Line number, which is an integer. The minimum value is 1, and the maximum value depends on the number of lines parsed by the font engine after text input. If a value greater than the maximum number is passed in, an error value is returned and an error message is printed. |
| fontMetricsSize       | Pointer to the size of the struct.                           |

**Returns**

Returns all the font metrics.


### OH_Drawing_TypographyGetLineHeight()

```
double OH_Drawing_TypographyGetLineHeight (OH_Drawing_Typography* , int  )
```

**Description**

Obtains the line height.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name                  | Description                                                  |
| --------------------- | ------------------------------------------------------------ |
| OH_Drawing_Typography | Pointer to an **OH_Drawing_Typography** object, which is obtained by calling [OH_Drawing_CreateTypography](#oh_drawing_createtypography). |
| int                   | Target line.                                                 |

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

| Name                   | Description                                                  |
| ---------------------- | ------------------------------------------------------------ |
| OH_Drawing_Typography  | Pointer to an [OH_Drawing_Typography](#oh_drawing_typography) object, which is obtained by calling [OH_Drawing_CreateTypography](#oh_drawing_createtypography). |
| int                    | Row No.                                                      |
| bool                   | Whether to obtain the metrics of the entire line. The value **true** means to obtain the metrics of the entire line, and **false** means to obtain the metrics of the first character in the line. |
| bool                   | Whether whitespace characters are included in the text width. The value **true** means that whitespace characters are not included, **false** means the opposite. |
| OH_Drawing_LineMetrics | Pointer to an [OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md) object, which is obtained by calling [OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md). |

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

| Name                  | Description                                                  |
| --------------------- | ------------------------------------------------------------ |
| OH_Drawing_Typography | Pointer to an [OH_Drawing_Typography](#oh_drawing_typography) object, which is obtained by calling [OH_Drawing_CreateTypography](#oh_drawing_createtypography). |

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

| Name                                                       | Description                                                  |
| ---------------------------------------------------------- | ------------------------------------------------------------ |
| OH_Drawing_Typography                                      | Pointer to an [OH_Drawing_Typography](#oh_drawing_typography) object, which is obtained by calling [OH_Drawing_CreateTypography](#oh_drawing_createtypography). |
| int                                                        | Line No.                                                     |
| [OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md) | Pointer to an [OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md) object, which is obtained by calling [OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md). |

**Returns**

Returns **true** if the metrics of the given line are obtained; returns **false** otherwise.


### OH_Drawing_TypographyGetLineTextRange()

```
OH_Drawing_Range* OH_Drawing_TypographyGetLineTextRange (OH_Drawing_Typography* , int , bool  )
```

**Description**

Obtains the line bounds.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                  | Description                                                  |
| --------------------- | ------------------------------------------------------------ |
| OH_Drawing_Typography | Pointer to an [OH_Drawing_Typography](#oh_drawing_typography) object, which is obtained by calling [OH_Drawing_CreateTypography](#oh_drawing_createtypography). |
| int                   | Row index.                                                   |
| bool                  | Whether the returned bounds contain spaces. The value **true** means that the bounds contain spaces, and **false** means the opposite. |

**Returns**

Returns the pointer to the [OH_Drawing_Range](#oh_drawing_range) object.


### OH_Drawing_TypographyGetLineWidth()

```
double OH_Drawing_TypographyGetLineWidth (OH_Drawing_Typography* , int  )
```

**Description**

Obtains the line width.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name                  | Description                                                  |
| --------------------- | ------------------------------------------------------------ |
| OH_Drawing_Typography | Pointer to an **OH_Drawing_Typography** object, which is obtained by calling [OH_Drawing_CreateTypography](#oh_drawing_createtypography). |
| int                   | Target line.                                                 |

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

| Name                  | Description                                                  |
| --------------------- | ------------------------------------------------------------ |
| OH_Drawing_Typography | Pointer to an **OH_Drawing_Typography** object, which is obtained by calling [OH_Drawing_CreateTypography](#oh_drawing_createtypography). |

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

| Name                  | Description                                                  |
| --------------------- | ------------------------------------------------------------ |
| OH_Drawing_Typography | Pointer to an **OH_Drawing_Typography** object, which is obtained by calling [OH_Drawing_CreateTypography](#oh_drawing_createtypography). |

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

| Name                  | Description                                                  |
| --------------------- | ------------------------------------------------------------ |
| OH_Drawing_Typography | Pointer to an **OH_Drawing_Typography** object, which is obtained by calling [OH_Drawing_CreateTypography](#oh_drawing_createtypography). |

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

| Name                  | Description                                                  |
| --------------------- | ------------------------------------------------------------ |
| OH_Drawing_Typography | Pointer to an **OH_Drawing_Typography** object, which is obtained by calling [OH_Drawing_CreateTypography](#oh_drawing_createtypography). |

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

| Name                  | Description                                                  |
| --------------------- | ------------------------------------------------------------ |
| OH_Drawing_Typography | Pointer to an **OH_Drawing_Typography** object, which is obtained by calling [OH_Drawing_CreateTypography](#oh_drawing_createtypography). |

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

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_Typography      | Pointer to an **OH_Drawing_Typography** object, which is obtained by calling [OH_Drawing_CreateTypography](#oh_drawing_createtypography). |
| size_t                     | Start position.                                              |
| size_t                     | End position.                                                |
| OH_Drawing_RectHeightStyle | Height style. For details about the available options, see [OH_Drawing_RectHeightStyle](#oh_drawing_rectheightstyle). |
| OH_Drawing_RectWidthStyle  | Width style. For details about the available options, see [OH_Drawing_RectWidthStyle](#oh_drawing_rectwidthstyle). |

**Returns**

Returns the [OH_Drawing_TextBox](#oh_drawing_textbox) struct that holds the text boxes.


### OH_Drawing_TypographyGetTextAlign()

```
OH_Drawing_TextAlign OH_Drawing_TypographyGetTextAlign (OH_Drawing_TypographyStyle* )
```

**Description**

Obtains the text alignment mode.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |

**Returns**

Returns the text alignment mode. For details about the available options, see [OH_Drawing_TextAlign](#oh_drawing_textalign).


### OH_Drawing_TypographyGetTextDirection()

```
OH_Drawing_TextDirection OH_Drawing_TypographyGetTextDirection (OH_Drawing_TypographyStyle* )
```

**Description**

Obtains the text direction.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |

**Returns**

Returns the text direction. For details about the available options, see [OH_Drawing_TextDirection](#oh_drawing_textdirection).


### OH_Drawing_TypographyGetTextEllipsis()

```
char* OH_Drawing_TypographyGetTextEllipsis (OH_Drawing_TypographyStyle* )
```

**Description**

Obtains the text ellipsis content.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |

**Returns**

Returns the pointer to the text ellipsis content obtained.


### OH_Drawing_TypographyGetTextMaxLines()

```
size_t OH_Drawing_TypographyGetTextMaxLines (OH_Drawing_TypographyStyle* )
```

**Description**

Obtains the maximum number of lines.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |

**Returns**

Returns the maximum number of lines.


### OH_Drawing_TypographyGetTextStyle()

```
OH_Drawing_TextStyle* OH_Drawing_TypographyGetTextStyle (OH_Drawing_TypographyStyle* style)
```

**Description**

Obtains the text style of a typography style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |

**Returns**

Returns the pointer to the [OH_Drawing_TextStyle](#oh_drawing_textstyle) object.


### OH_Drawing_TypographyGetUnresolvedGlyphsCount()

```
int32_t OH_Drawing_TypographyGetUnresolvedGlyphsCount (OH_Drawing_Typography* )
```

**Description**

Obtains the number of unresolved glyphs in a typography object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                  | Description                                                  |
| --------------------- | ------------------------------------------------------------ |
| OH_Drawing_Typography | Pointer to an [OH_Drawing_Typography](#oh_drawing_typography) object, which is obtained by calling [OH_Drawing_CreateTypography](#oh_drawing_createtypography). |

**Returns**

Returns the number of unresolved glyphs.


### OH_Drawing_TypographyGetWordBoundary()

```
OH_Drawing_Range* OH_Drawing_TypographyGetWordBoundary (OH_Drawing_Typography* , size_t  )
```

**Description**

Obtains the word boundary.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Parameters**

| Name                  | Description                                                  |
| --------------------- | ------------------------------------------------------------ |
| OH_Drawing_Typography | Pointer to an **OH_Drawing_Typography** object, which is obtained by calling [OH_Drawing_CreateTypography](#oh_drawing_createtypography). |
| size_t                | Index of the word.                                           |

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

| Name                                                         | Description                                                  |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| OH_Drawing_TypographyCreate                                  | Pointer to an **OH_Drawing_TypographyCreate** object. The pointer is obtained by [OH_Drawing_CreateTypographyHandler](#oh_drawing_createtypographyhandler). |
| [OH_Drawing_PlaceholderSpan](_o_h___drawing___placeholder_span.md) | Pointer to an **OH_Drawing_PlaceholderSpan** object.         |


### OH_Drawing_TypographyHandlerAddSymbol()

```
void OH_Drawing_TypographyHandlerAddSymbol (OH_Drawing_TypographyCreate* , uint32_t symbol )
```

**Description**

Adds the symbol to use in the typography creation process.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                        | Description                                                  |
| --------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyCreate | Pointer to an **OH_Drawing_TypographyCreate** object. The pointer is obtained by [OH_Drawing_CreateTypographyHandler](#oh_drawing_createtypographyhandler). |
| uint32_t                    | Symbol. For details about the supported symbols, see the value in the JSON file. [https://gitee.com/openharmony/global_system_resources/blob/master/systemres/main/resources/base/element/symbol.json](https://gitee.com/openharmony/global_system_resources/blob/master/systemres/main/resources/base/element/symbol.json) |


### OH_Drawing_TypographyHandlerAddText()

```
void OH_Drawing_TypographyHandlerAddText (OH_Drawing_TypographyCreate* , const char*  )
```

**Description**

Adds text.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name                        | Description                                                  |
| --------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyCreate | Pointer to an **OH_Drawing_TypographyCreate** object. The pointer is obtained by [OH_Drawing_CreateTypographyHandler](#oh_drawing_createtypographyhandler). |
| char                        | Pointer to the text content.                                 |


### OH_Drawing_TypographyHandlerPopTextStyle()

```
void OH_Drawing_TypographyHandlerPopTextStyle (OH_Drawing_TypographyCreate* )
```

**Description**

Removes the topmost text style in the stack, leaving the remaining styles in effect.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name                        | Description                                                  |
| --------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyCreate | Pointer to an **OH_Drawing_TypographyCreate** object. The pointer is obtained by [OH_Drawing_CreateTypographyHandler](#oh_drawing_createtypographyhandler). |


### OH_Drawing_TypographyHandlerPushTextStyle()

```
void OH_Drawing_TypographyHandlerPushTextStyle (OH_Drawing_TypographyCreate* , OH_Drawing_TextStyle*  )
```

**Description**

Pushes the text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name                        | Description                                                  |
| --------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyCreate | Pointer to an **OH_Drawing_TypographyCreate** object. The pointer is obtained by [OH_Drawing_CreateTypographyHandler](#oh_drawing_createtypographyhandler). |
| OH_Drawing_TextStyle        | Pointer to an **OH_Drawing_TextStyle** object, which is obtained by calling [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle). |


### OH_Drawing_TypographyIsEllipsized()

```
bool OH_Drawing_TypographyIsEllipsized (OH_Drawing_TypographyStyle* style)
```

**Description**

Checks whether the text has an ellipsis.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |

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

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |

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

| Name                  | Description                                                  |
| --------------------- | ------------------------------------------------------------ |
| OH_Drawing_Typography | Pointer to an **OH_Drawing_Typography** object, which is obtained by calling [OH_Drawing_CreateTypography](#oh_drawing_createtypography). |
| double                | Maximum text width.                                          |


### OH_Drawing_TypographyMarkDirty()

```
void OH_Drawing_TypographyMarkDirty (OH_Drawing_Typography* )
```

**Description**

Marks a typography object as dirty data. This function is used to initialize the typography state.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                  | Description                                                  |
| --------------------- | ------------------------------------------------------------ |
| OH_Drawing_Typography | Pointer to an [OH_Drawing_Typography](#oh_drawing_typography) object, which is obtained by calling [OH_Drawing_CreateTypography](#oh_drawing_createtypography). |


### OH_Drawing_TypographyPaint()

```
void OH_Drawing_TypographyPaint (OH_Drawing_Typography* , OH_Drawing_Canvas* , double , double  )
```

**Description**

Paints text on the canvas.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Parameters**

| Name                  | Description                                                  |
| --------------------- | ------------------------------------------------------------ |
| OH_Drawing_Typography | Pointer to an **OH_Drawing_Typography** object, which is obtained by calling [OH_Drawing_CreateTypography](#oh_drawing_createtypography). |
| OH_Drawing_Canvas     | Pointer to an **OH_Drawing_Canvas** object, which is obtained by calling **OH_Drawing_CanvasCreate()**. |
| double                | X coordinate.                                                |
| double                | Y coordinate.                                                |


### OH_Drawing_TypographySetIndents()

```
void OH_Drawing_TypographySetIndents (OH_Drawing_Typography* , int , const float indents[] )
```

**Description**

Sets indents for typography. If this function is not called, texts will have no indentation applied.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                  | Description                                                  |
| --------------------- | ------------------------------------------------------------ |
| OH_Drawing_Typography | Pointer to an [OH_Drawing_Typography](#oh_drawing_typography) object, which is obtained by calling [OH_Drawing_CreateTypography](#oh_drawing_createtypography). |
| int                   | Number of indents. The value must be less than or equal to the length of the indents array to avoid display exceptions caused by access to the out-of-bounds array. |
| float                 | Pointer to a floating-point array, in which each element indicates an indentation width, in px. Before using [OH_Drawing_Typography](#oh_drawing_typography), you must declare and initialize the floating-point array. |


### OH_Drawing_TypographyStyleDestroyStrutStyle()

```
void OH_Drawing_TypographyStyleDestroyStrutStyle (OH_Drawing_StrutStyle* )
```

**Description**

Reclaims the memory occupied by a strut style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                                                     | Description                                                  |
| -------------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Drawing_StrutStyle](_o_h___drawing___strut_style.md) | Pointer to an [OH_Drawing_StrutStyle](_o_h___drawing___strut_style.md) object, which is obtained by calling [OH_Drawing_TypographyStyleGetStrutStyle](#oh_drawing_typographystylegetstrutstyle). |


### OH_Drawing_TypographyStyleEquals()

```
bool OH_Drawing_TypographyStyleEquals (OH_Drawing_TypographyStyle* from, OH_Drawing_TypographyStyle* to )
```

**Description**

Checks whether two typography styles are the same.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name | Description                             |
| ---- | --------------------------------------- |
| from | Pointer to the first typography style.  |
| to   | Pointer to the second typography style. |

**Returns**

Returns **true** if the two are the same; returns **false** otherwise.


### OH_Drawing_TypographyStyleGetEffectiveAlignment()

```
OH_Drawing_TextAlign OH_Drawing_TypographyStyleGetEffectiveAlignment (OH_Drawing_TypographyStyle* style)
```

**Description**

Obtains the text alignment mode.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |

**Returns**

Returns the text alignment mode. For details about the available options, see [OH_Drawing_TextAlign](#oh_drawing_textalign).


### OH_Drawing_TypographyStyleGetFontStyleStruct()

```
OH_Drawing_FontStyleStruct OH_Drawing_TypographyStyleGetFontStyleStruct (OH_Drawing_TypographyStyle* drawingStyle)
```

**Description**

Obtains the font style, including the font weight, width, and slant, of a typography style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |

**Returns**

Returns the font style, including the font weight, width, and slant.


### OH_Drawing_TypographyStyleGetStrutStyle()

```
OH_Drawing_StrutStyle* OH_Drawing_TypographyStyleGetStrutStyle (OH_Drawing_TypographyStyle* )
```

**Description**

Obtains the strut style of a typography style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |

**Returns**

Returns the pointer to the strut style, which is an [OH_Drawing_StrutStyle](_o_h___drawing___strut_style.md) object.


### OH_Drawing_TypographyStyleIsHintEnabled()

```
bool OH_Drawing_TypographyStyleIsHintEnabled (OH_Drawing_TypographyStyle* style)
```

**Description**

Checks whether font hinting is enabled for a typography style. Font hinting is used to improve the readability and appearance of small-sized text when rendering it.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |

**Returns**

Returns **true** if font hinting is enabled; returns **false** otherwise.


### OH_Drawing_TypographyStyleSetHintsEnabled()

```
void OH_Drawing_TypographyStyleSetHintsEnabled (OH_Drawing_TypographyStyle* style, bool hintsEnabled )
```

**Description**

Sets whether to enable font hinting for a typography style. Font hinting is used to improve the readability and appearance of small-sized text when rendering it.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |
| hintsEnabled               | Whether to enable font hinting. The value **true** means to enable font hinting, and **false** means the opposite. |


### OH_Drawing_TypographyStyleStrutStyleEquals()

```
bool OH_Drawing_TypographyStyleStrutStyleEquals (OH_Drawing_StrutStyle* from, OH_Drawing_StrutStyle* to )
```

**Description**

Checks whether two strut styles are equal.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name | Description                        |
| ---- | ---------------------------------- |
| from | Pointer to the first strut style.  |
| to   | Pointer to the second strut style. |

**Returns**

Returns **true** if the two strut styles are the same; returns **false** otherwise.

### OH_Drawing_TypographyTextGetHeightBehavior()

```
OH_Drawing_TextHeightBehavior OH_Drawing_TypographyTextGetHeightBehavior (OH_Drawing_TypographyStyle* )
```

**Description**

Obtains the text height modifier pattern.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle | Pointer to an **OH_Drawing_TypographyStyle** object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |

**Returns**

Returns the text height modifier pattern. For details about the available options, see [OH_Drawing_TextHeightBehavior](#oh_drawing_textheightbehavior).


### OH_Drawing_TypographyTextGetLineStyle()

```
bool OH_Drawing_TypographyTextGetLineStyle (OH_Drawing_TypographyStyle* )
```

**Description**

Checks whether the text line style is enabled for a typography style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |

**Returns**

Returns **true** if the text line style is enabled; returns **false** otherwise.


### OH_Drawing_TypographyTextlineGetStyleOnly()

```
bool OH_Drawing_TypographyTextlineGetStyleOnly (OH_Drawing_TypographyStyle* )
```

**Description**

Checks whether only the text line style is enabled for a typography style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |

**Returns**

Returns **true** if only the text line style is enabled; returns **false** otherwise.


### OH_Drawing_TypographyTextlineStyleDestroyFontFamilies()

```
void OH_Drawing_TypographyTextlineStyleDestroyFontFamilies (char** fontFamilies, size_t fontFamiliesNum )
```

**Description**

Reclaims the memory occupied by the font families.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name            | Description                          |
| --------------- | ------------------------------------ |
| fontFamilies    | Double pointer to the font families. |
| fontFamiliesNum | Number of font families.             |


### OH_Drawing_TypographyTextlineStyleGetFontFamilies()

```
char** OH_Drawing_TypographyTextlineStyleGetFontFamilies (OH_Drawing_TypographyStyle* )
```

**Description**

Obtains the font families of a text line style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |

**Returns**

Returns the font families.


### OH_Drawing_TypographyTextlineStyleGetFontSize()

```
double OH_Drawing_TypographyTextlineStyleGetFontSize (OH_Drawing_TypographyStyle* )
```

**Description**

Obtains the font size of a text line style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |

**Returns**

Returns the font size.


### OH_Drawing_TypographyTextlineStyleGetFontStyle()

```
OH_Drawing_FontStyle OH_Drawing_TypographyTextlineStyleGetFontStyle (OH_Drawing_TypographyStyle* )
```

**Description**

Obtains the font style of a text line style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |

**Returns**

Returns the font style. For details about the available options, see [OH_Drawing_FontStyle](#oh_drawing_fontstyle).


### OH_Drawing_TypographyTextlineStyleGetFontWeight()

```
OH_Drawing_FontWeight OH_Drawing_TypographyTextlineStyleGetFontWeight (OH_Drawing_TypographyStyle* )
```

**Description**

Obtains the font weight of a text line style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |

**Returns**

Returns the font weight. For details about the available options, see [OH_Drawing_FontWeight](#oh_drawing_fontweight).


### OH_Drawing_TypographyTextlineStyleGetHalfLeading()

```
bool OH_Drawing_TypographyTextlineStyleGetHalfLeading (OH_Drawing_TypographyStyle* )
```

**Description**

Checks whether half leading is enabled for a text line style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |

**Returns**

Returns **true** if half leading is enabled; returns **false** otherwise.


### OH_Drawing_TypographyTextlineStyleGetHeightOnly()

```
bool OH_Drawing_TypographyTextlineStyleGetHeightOnly (OH_Drawing_TypographyStyle* )
```

**Description**

Checks whether only the font height is used for a text line style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |

**Returns**

Returns **true** if only the font height is used; returns false otherwise.


### OH_Drawing_TypographyTextlineStyleGetHeightScale()

```
double OH_Drawing_TypographyTextlineStyleGetHeightScale (OH_Drawing_TypographyStyle* )
```

**Description**

Obtains the height scale factor of a text line style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |

**Returns**

Returns the font height scale factor.


### OH_Drawing_TypographyTextlineStyleGetSpacingScale()

```
double OH_Drawing_TypographyTextlineStyleGetSpacingScale (OH_Drawing_TypographyStyle* )
```

**Description**

Obtains the spacing scale factor of a text line style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle | Pointer to an [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |

**Returns**

Returns the spacing scale factor.


### OH_Drawing_TypographyTextSetHeightBehavior()

```
void OH_Drawing_TypographyTextSetHeightBehavior (OH_Drawing_TypographyStyle* , OH_Drawing_TextHeightBehavior heightMode )
```

**Description**

Sets a text height modifier pattern.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| OH_Drawing_TypographyStyle | Pointer to an **OH_Drawing_TypographyStyle** object, which is obtained by calling [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle). |
| heightMode                 | Text height modifier pattern. For details about the available options, see [OH_Drawing_TextHeightBehavior](#oh_drawing_textheightbehavior). |


### OH_Drawing_TypographyUpdateFontSize()

```
void OH_Drawing_TypographyUpdateFontSize (OH_Drawing_Typography* , size_t from, size_t to, float fontSize )
```

**Description**

Updates the font size in a typography object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name                  | Description                                                  |
| --------------------- | ------------------------------------------------------------ |
| OH_Drawing_Typography | Pointer to an [OH_Drawing_Typography](#oh_drawing_typography) object, which is obtained by calling [OH_Drawing_CreateTypography](#oh_drawing_createtypography). |
| from                  | Original font size.                                          |
| to                    | New font size.                                               |
| fontSize              | Font size.                                                   |