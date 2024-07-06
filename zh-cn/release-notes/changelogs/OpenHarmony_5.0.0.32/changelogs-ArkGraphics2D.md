# 方舟2D图形服务变更说明

## c1.ArkGraphics2D.1 OH_NativeImage_GetTransformMatrix接口废弃

**访问级别**

公开接口。

**废弃原因**

接口输出matrix未完全实现，需废弃，使用新接口替代。

**废弃影响**

该变更为不兼容性变更。

接口不建议使用，建议通过OH_NativeImage_GetTransformMatrixV2替代。

**起始API Level**

9

**废弃发生版本**

OpenHarmony SDK 5.0.0.31

**废弃的接口/组件**

OH_NativeImage_GetTransformMatrix接口废弃，建议通过OH_NativeImage_GetTransformMatrixV2替代。

**适配指导**

将OH_NativeImage_GetTransformMatrix接口替换为OH_NativeImage_GetTransformMatrixV2。

## c1.ArkGraphics2D.2 OH_NativeWindow_CreateNativeWindow接口废弃

**访问级别**

公开接口。

**废弃原因**

用户无法获取入参类型，用户无法使用，需废弃。

**废弃影响**

该变更为不兼容性变更。

无影响，用户本身就无法使用该接口。

**起始API Level**

8

**废弃发生版本**

OpenHarmony SDK 5.0.0.31

**废弃的接口/组件**

OH_NativeWindow_CreateNativeWindow接口废弃，无替代接口。

**适配指导**

无影响，用户本身就无法使用该接口。

## c1.ArkGraphics2D.3 OH_NativeWindow_CreateNativeWindowBufferFromSurfaceBuffer接口废弃

**访问级别**

公开接口。

**废弃原因**

用户无法获取入参类型，用户无法使用，需废弃。

**废弃影响**

该变更为不兼容性变更。

无影响，用户本身就无法使用该接口。

**起始API Level**

8

**废弃发生版本**

OpenHarmony SDK 5.0.0.31

**废弃的接口/组件**

OH_NativeWindow_CreateNativeWindowBufferFromSurfaceBuffer接口废弃，建议通过OH_NativeWindow_CreateNativeWindowBufferFromNativeBuffer替代。

**适配指导**

无影响，用户本身就无法使用该接口。

## c1.ArkGraphics2D.4 OH_NativeWindow_GetLastFlushedBuffer接口废弃

**访问级别**

公开接口。

**废弃原因**

接口输出matrix未完全实现，需废弃，使用新接口替代。

**废弃影响**

该变更为不兼容性变更。

接口不建议使用，建议通过OH_NativeWindow_GetLastFlushedBufferV2替代。

**起始API Level**

11

**废弃发生版本**

OpenHarmony SDK 5.0.0.31

**废弃的接口/组件**

OH_NativeWindow_GetLastFlushedBuffer接口废弃，建议通过OH_NativeWindow_GetLastFlushedBufferV2替代。

**适配指导**

将OH_NativeWindow_GetLastFlushedBuffer接口替换为OH_NativeWindow_GetLastFlushedBufferV2。

