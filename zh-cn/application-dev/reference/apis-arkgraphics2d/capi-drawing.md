# Drawing

## 概述

Drawing模块提供包括2D图形渲染、文字绘制和图片显示等功能函数。<br>本模块采用屏幕物理像素单位px。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8
## 文件汇总

| 名称 | 描述 |
| -- | -- |
| [drawing_bitmap.h](capi-drawing-bitmap-h.md) | 文件中定义了与位图相关的功能函数。 |
| [drawing_brush.h](capi-drawing-brush-h.md) | 文件中定义了与画刷相关的功能函数。 |
| [drawing_canvas.h](capi-drawing-canvas-h.md) | 文件中定义了与画布相关的功能函数。<br>画布自带一个黑色，开启抗锯齿，不具备其他任何样式的默认画刷，当且仅当画布中主动设置的画刷和画笔都不存在时生效。 |
| [drawing_color.h](capi-drawing-color-h.md) | 文件中定义了与颜色相关的功能函数。 |
| [drawing_color_filter.h](capi-drawing-color-filter-h.md) | 声明与绘图模块中的颜色滤波器对象相关的函数。 |
| [drawing_color_space.h](capi-drawing-color-space-h.md) | 文件中定义了与颜色空间相关的功能函数。 |
| [drawing_error_code.h](capi-drawing-error-code-h.md) | 声明与绘图模块中的错误码相关的函数。include native_drawing/drawing_error_code.h |
| [drawing_filter.h](capi-drawing-filter-h.md) | 声明与绘图模块中的滤波器对象相关的函数。 |
| [drawing_font.h](capi-drawing-font-h.md) | 文件中定义了与字体相关的功能函数。 |
| [drawing_font_collection.h](capi-drawing-font-collection-h.md) | 定义绘制模块中与字体集合相关的函数。 |
| [drawing_font_mgr.h](capi-drawing-font-mgr-h.md) | 文件中定义了与字体管理相关的功能函数，用于加载和匹配系统中可用的字体。 |
| [drawing_gpu_context.h](capi-drawing-gpu-context-h.md) | 声明与绘图模块中的图形处理器上下文对象相关的函数。 |
| [drawing_image.h](capi-drawing-image-h.md) | 文件中定义了与图片相关的功能函数。 |
| [drawing_image_filter.h](capi-drawing-image-filter-h.md) | 声明与绘图模块中的图像滤波器对象相关的函数。 |
| [drawing_mask_filter.h](capi-drawing-mask-filter-h.md) | 声明与绘图模块中的对象相关的函数。 |
| [drawing_matrix.h](capi-drawing-matrix-h.md) | 文件中定义了与矩阵相关的功能函数。 |
| [drawing_memory_stream.h](capi-drawing-memory-stream-h.md) | 文件中定义了与内存流相关的功能函数。 |
| [drawing_path.h](capi-drawing-path-h.md) | 文件中定义了与自定义路径相关的功能函数。 |
| [drawing_path_effect.h](capi-drawing-path-effect-h.md) | 文件中定义了与路径效果相关的功能函数。 |
| [drawing_pen.h](capi-drawing-pen-h.md) | 文件中定义了与画笔相关的功能函数。 |
| [drawing_pixel_map.h](capi-drawing-pixel-map-h.md) | 声明与绘图模块中的像素图对象相关的函数。 |
| [drawing_point.h](capi-drawing-point-h.md) | 文件中定义了与坐标点相关的功能函数。 |
| [drawing_record_cmd.h](capi-drawing-record-cmd-h.md) | 文件中定义了与录制指令对象相关的功能函数。 |
| [drawing_rect.h](capi-drawing-rect-h.md) | 文件中定义了与矩形相关的功能函数。 |
| [drawing_region.h](capi-drawing-region-h.md) | 定义了与区域相关的功能函数，包括区域的创建，边界设置和销毁等。 |
| [drawing_register_font.h](capi-drawing-register-font-h.md) | 定义绘制模块中字体管理器相关的函数。 |
| [drawing_round_rect.h](capi-drawing-round-rect-h.md) | 文件中定义了与圆角矩形相关的功能函数。 |
| [drawing_sampling_options.h](capi-drawing-sampling-options-h.md) | 文件中定义了与采样相关的功能函数。用于图片或者纹理等图像的采样。 |
| [drawing_shader_effect.h](capi-drawing-shader-effect-h.md) | 声明与绘图模块中的着色器对象相关的函数。 |
| [drawing_shadow_layer.h](capi-drawing-shadow-layer-h.md) | 声明与绘图模块中的阴影层对象相关的函数。 |
| [drawing_surface.h](capi-drawing-surface-h.md) | 文件中定义与surface相关的功能函数，包括surface的创建、销毁和使用等。 |
| [drawing_text_blob.h](capi-drawing-text-blob-h.md) | 文件中定义了与文字相关的功能函数。 |
| [drawing_text_declaration.h](capi-drawing-text-declaration-h.md) | 提供2d 绘制文本相关的数据结构声明 |
| [drawing_text_font_descriptor.h](capi-drawing-text-font-descriptor-h.md) | 定义了字体信息的相关接口，比如获取字体信息，查找指定字体等。 |
| [drawing_text_global.h](capi-drawing-text-global-h.md) | 提供文本全局信息的相关接口，比如设置文本渲染高对比度模式等。 |
| [drawing_text_line.h](capi-drawing-text-line-h.md) | 提供获取文本行内的字符位置、获取渲染单元信息和按行截断等功能。 |
| [drawing_text_lineTypography.h](capi-drawing-text-linetypography-h.md) | 提供排版行相关的接口，比如获取指定位置处开始可以排版的字符个数等函数。 |
| [drawing_text_run.h](capi-drawing-text-run-h.md) | 提供字体渲染单元的相关接口，比如绘制功能、获取排版边界功能等。 |
| [drawing_text_typography.h](capi-drawing-text-typography-h.md) | 定义绘制模块中排版相关的函数。 |
| [drawing_typeface.h](capi-drawing-typeface-h.md) | 文件中定义了与字形相关的功能函数。<br>不同的平台有自己的默认字形，也可以从ttf文件解析出三方指定字形，如宋体、黑体字形等。 |
| [drawing_types.h](capi-drawing-types-h.md) | 文件中定义了用于绘制2d图形的数据类型，包括画布、画笔、画刷、位图和路径。 |
