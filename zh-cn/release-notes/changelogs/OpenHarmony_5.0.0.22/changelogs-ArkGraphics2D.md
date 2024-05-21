# 方舟2D图形服务子系统变更说明

## cl.ArkGraphics2D.1 OH_NativeBuffer_Format枚举名错误修正

**访问级别**

公开接口

**变更原因**

OH_NativeBuffer_Format中的NATIVEBUFFER_PIXEL_FMT_YUV_422_T、NATIVEBUFFER_PIXEL_FMT_YCRCR_422_SP、NATIVEBUFFER_PIXEL_FMT_YCRCR_420_SP、NATIVEBUFFER_PIXEL_FMT_YCRCR_422_P、NATIVEBUFFER_PIXEL_FMT_YCRCR_420_P枚举类型名称单词拼写错误。

**变更影响**

该变更为非兼容性变更。

用户若使用了上述的枚举类型，则需要对其进行枚举名称变更，使用正确的枚举类型。

**API Level**

12

**变更发生版本**

从OpenHarmony SDK 5.0.0.22 版本开始。

**变更的接口/组件**

native_buffer.h中 OH_NativeBuffer_Format枚举类型名称。

**适配指导**

接口使用的示例代码可参考[OH_NativeBuffer接口指导](../../../application-dev/reference/apis-arkgraphics2d/_o_h___native_buffer.md#oh_nativebuffer_format)。

