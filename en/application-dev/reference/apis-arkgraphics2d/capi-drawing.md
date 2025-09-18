# Drawing

## Overview

The Drawing module provides the functions for 2D graphics rendering, text drawing, and image display.<br>It uses the physical pixel unit, px.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8
## Files

| Name| Description|
| -- | -- |
| [drawing_bitmap.h](capi-drawing-bitmap-h.md) | Declares the functions related to the bitmap in the drawing module.|
| [drawing_brush.h](capi-drawing-brush-h.md) | Declares the functions related to the brush in the drawing module.|
| [drawing_canvas.h](capi-drawing-canvas-h.md) | This file declares the functions related to the canvas in the drawing module.<br>By default, the canvas has a black brush with anti-aliasing enabled but no any other style. This default brush takes effect only when no brush or pen is proactively set in the canvas.|
| [drawing_color.h](capi-drawing-color-h.md) | Declares the functions related to the color in the drawing module.|
| [drawing_color_filter.h](capi-drawing-color-filter-h.md) | Declares the functions related to the color filter in the drawing module.|
| [drawing_color_space.h](capi-drawing-color-space-h.md) | Declares the functions related to the color space in the drawing module.|
| [drawing_error_code.h](capi-drawing-error-code-h.md) | The **drawing_error_code.h** file declares the functions related to the error code in the drawing module.include native_drawing/drawing_error_code.h |
| [drawing_filter.h](capi-drawing-filter-h.md) | Declares the functions related to the filter in the drawing module.|
| [drawing_font.h](capi-drawing-font-h.md) | Declares the functions related to the font in the drawing module.|
| [drawing_font_collection.h](capi-drawing-font-collection-h.md) | Declares the functions related to the font collection in the drawing module.|
| [drawing_font_mgr.h](capi-drawing-font-mgr-h.md) | Declares the functions related to font management in the drawing module. The functions can be used to load fonts and match available fonts in the system.|
| [drawing_gpu_context.h](capi-drawing-gpu-context-h.md) | Declares the functions related to the GPU context in the drawing module.|
| [drawing_image.h](capi-drawing-image-h.md) | Declares the functions related to the image in the drawing module.|
| [drawing_image_filter.h](capi-drawing-image-filter-h.md) | Declares the functions related to the image filter in the drawing module.|
| [drawing_mask_filter.h](capi-drawing-mask-filter-h.md) | Declares the functions related to the mask filter in the drawing module.|
| [drawing_matrix.h](capi-drawing-matrix-h.md) | Declares the functions related to the matrix in the drawing module.|
| [drawing_memory_stream.h](capi-drawing-memory-stream-h.md) | Declares the functions related to the memory stream in the drawing module.|
| [drawing_path.h](capi-drawing-path-h.md) | Declares the functions related to the path in the drawing module.|
| [drawing_path_effect.h](capi-drawing-path-effect-h.md) | Declares the functions related to the bitmap in the drawing module.|
| [drawing_pen.h](capi-drawing-pen-h.md) | Declares the functions related to the pen in the drawing module.|
| [drawing_pixel_map.h](capi-drawing-pixel-map-h.md) | Declares the functions related to the pixel map in the drawing module.|
| [drawing_point.h](capi-drawing-point-h.md) | Declares the functions related to the coordinate point in the drawing module.|
| [drawing_record_cmd.h](capi-drawing-record-cmd-h.md) | Declares the functions related to a recording command object.|
| [drawing_rect.h](capi-drawing-rect-h.md) | Declares the functions related to the rectangle in the drawing module.|
| [drawing_region.h](capi-drawing-region-h.md) | Declares the functions related to the region in the drawing module, including creating a region, setting the boundary, and destroying a region.|
| [drawing_register_font.h](capi-drawing-register-font-h.md) | Declares the functions related to the font manager in the drawing module.|
| [drawing_round_rect.h](capi-drawing-round-rect-h.md) | Declares the functions related to the rounded rectangle in the drawing module.|
| [drawing_sampling_options.h](capi-drawing-sampling-options-h.md) | Declares the functions related to the sampling options in the drawing module. It is used for image or texture sampling.|
| [drawing_shader_effect.h](capi-drawing-shader-effect-h.md) | Declares the functions related to the shader effect in the drawing module.|
| [drawing_shadow_layer.h](capi-drawing-shadow-layer-h.md) | Declares the functions related to the shadow in the drawing module.|
| [drawing_surface.h](capi-drawing-surface-h.md) | Declares the functions related to the surface in the drawing module, including creating, destroying, and using the surface.|
| [drawing_text_blob.h](capi-drawing-text-blob-h.md) | Declares the functions related to the text blob in the drawing module.|
| [drawing_text_declaration.h](capi-drawing-text-declaration-h.md) | Declares the structs related to text in 2D drawing.|
| [drawing_text_font_descriptor.h](capi-drawing-text-font-descriptor-h.md) | Declares the capabilities of font information, such as obtaining font information and searching for a font.|
| [drawing_text_global.h](capi-drawing-text-global-h.md) | Provides APIs for setting text rendering attributes, for example, setting the high-contrast mode.|
| [drawing_text_line.h](capi-drawing-text-line-h.md) | Declares the capabilities for obtaining the character position in a text line, obtaining the run information, and truncating text by line.|
| [drawing_text_lineTypography.h](capi-drawing-text-linetypography-h.md) | Declares the functions related to line typography, including functions to determine the number of characters that can be formatted from a given position within the text.|
| [drawing_text_run.h](capi-drawing-text-run-h.md) | Declares the capabilities of runs, such as obtaining the typographic boundary and drawing.|
| [drawing_text_typography.h](capi-drawing-text-typography-h.md) | Declares the functions related to typography in the drawing module.|
| [drawing_typeface.h](capi-drawing-typeface-h.md) | Declares the functions related to the typeface in the drawing module.<br>Different platforms have their own default typefaces. You can also parse the .ttf file to obtain the typefaces specified by the third party, such as SimSun and SimHei.|
| [drawing_types.h](capi-drawing-types-h.md) | Declares the data types of the canvas, brush, pen, bitmap, and path used to draw 2D graphics.|
