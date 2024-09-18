# ArkGraphics2D Changelog

## c1.ArkGraphics2D.1 OH_NativeImage_GetTransformMatrix Deprecated

**Access Level**

Public API

**Reason for Change**

This API does not fully implement the output of a matrix. Therefore, it needs to be deprecated and replaced with a new one.

**Change Impact**

This change is a non-compatible change.

You are advised to use **OH_NativeImage_GetTransformMatrixV2** instead of **OH_NativeImage_GetTransformMatrix**.

**Start API Level**

9

**Change Since**

OpenHarmony SDK 5.0.0.31

**Deprecated APIs/Components**

The **OH_NativeImage_GetTransformMatrix** API is deprecated. Use **OH_NativeImage_GetTransformMatrixV2** instead.

**Adaptation Guide**

Replace **OH_NativeImage_GetTransformMatrix** with **OH_NativeImage_GetTransformMatrixV2**.

## c1.ArkGraphics2D.2 OH_NativeWindow_CreateNativeWindow Deprecated

**Access Level**

Public API

**Reason for Change**

Users cannot obtain the input parameter type and therefore cannot actually use this API.

**Change Impact**

This change is a non-compatible change.

There is no impact. Users cannot use the API.

**Start API Level**

8

**Change Since**

OpenHarmony SDK 5.0.0.31

**Deprecated APIs/Components**

The **OH_NativeWindow_CreateNativeWindow** API is deprecated and no substitute is provided.

**Adaptation Guide**

There is no impact. Users cannot use the API.

## c1.ArkGraphics2D.3 OH_NativeWindow_CreateNativeWindowBufferFromSurfaceBuffer Deprecated

**Access Level**

Public API

**Reason for Change**

Users cannot obtain the input parameter type and therefore cannot actually use this API.

**Change Impact**

This change is a non-compatible change.

There is no impact. Users cannot use the API.

**Start API Level**

8

**Change Since**

OpenHarmony SDK 5.0.0.31

**Deprecated APIs/Components**

The **OH_NativeWindow_CreateNativeWindowBufferFromSurfaceBuffer** API is deprecated. You are advised to use **OH_NativeWindow_CreateNativeWindowBufferFromNativeBuffer** instead.

**Adaptation Guide**

There is no impact. Users cannot use the API.

## c1.ArkGraphics2D.4 OH_NativeWindow_GetLastFlushedBuffer Deprecated

**Access Level**

Public API

**Reason for Change**

This API does not fully implement the output of a matrix. Therefore, it needs to be deprecated and replaced with a new one.

**Change Impact**

This change is a non-compatible change.

You are advised to use **OH_NativeWindow_GetLastFlushedBufferV2** instead of **OH_NativeWindow_GetLastFlushedBuffer**.

**Start API Level**

11

**Change Since**

OpenHarmony SDK 5.0.0.31

**Deprecated APIs/Components**

The **OH_NativeWindow_GetLastFlushedBuffer** API is deprecated. Use **OH_NativeWindow_GetLastFlushedBufferV2** instead.

**Adaptation Guide**

Replace **OH_NativeWindow_GetLastFlushedBuffer** with **OH_NativeWindow_GetLastFlushedBufferV2**.

## cl.ArkGraphics2D.5 Error Code Is Added to OH_Drawing_RegisterFont() and OH_Drawing_RegisterFontBuffer()

**Access Level**

Public API

**Reason for Change**

The **OH_Drawing_RegisterFont()** and **OH_Drawing_RegisterFontBuffer()** APIs do not verify the file content.

**Change Impact**

This change is a non-compatible change.
1. Before change: The file content is not verified. If the file is damaged, the default font is used and a success message is returned.
2. After change: The file content is verified. If the font fails to be created, error code 9 is reported, indicating that the file is damaged.

**Start API Level**

11

**Change Since**

OpenHarmony SDK 5.0.0.32

**Key API/Component Changes**

Error code 9 indicating file damage is added to **OH_Drawing_RegisterFont()** and **OH_Drawing_RegisterFontBuffer()**.

**Adaptation Guide**

Search for **OH_Drawing_RegisterFont** and **OH_Drawing_RegisterFontBuffer** globally to adapt to the new error code.
