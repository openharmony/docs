# ArkGraphics2D Changelog

## c1.ArkGraphics2D.1 OH_Drawing_GpuContextCreateFromGL Deprecated

**Access Level**

Public API

**Reason for Change**

The specialized API **OH_Drawing_GpuContextCreateFromGL**, which is tightly coupled with the GPU backend, has been deprecated. Instead, use the new interface **OH_DrawingGpuContextCreate**, which abstracts away the GPU backend.

**Impact of the Change**

The **OH_Drawing_GpuContextCreateFromGL** API is no longer maintained.

You are advised to use **OH_Drawing_GpuContextCreate** instead.

**Start API Level**

12

**Change Since**

OpenHarmony SDK 5.1.0.59

**Deprecated APIs/Components**

The **OH_Drawing_GpuContextCreateFromGL** API and the **OH_Drawing_GpuContextOptions** struct are deprecated. You are advised to use **OH_Drawing_GpuContextCreate** instead.

**Adaptation Guide**

Replace **OH_Drawing_GpuContextCreateFromGL** with **OH_Drawing_GpuContextCreate** in your code.
