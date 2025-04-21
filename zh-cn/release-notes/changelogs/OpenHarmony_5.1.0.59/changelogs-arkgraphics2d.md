# 方舟2D图形服务变更说明

## c1.ArkGraphics2D.1 OH_Drawing_GpuContextCreateFromGL接口废弃

**访问级别**

公开接口。

**废弃原因**

废弃和GPU后端强绑定的特化接口OH_Drawing_GpuContextCreateFromGL，使用屏蔽GPU后端的新接口OH_DrawingGpuContextCreate作为替代。

**废弃影响**

OH_Drawing_GpuContextCreateFromGL接口不再维护。

建议通过OH_Drawing_GpuContextCreate替代。

**起始API Level**

12

**废弃发生版本**

OpenHarmony SDK 5.1.0.59

**废弃的接口/组件**

OH_Drawing_GpuContextCreateFromGL接口和OH_Drawing_GpuContextOptions结构体废弃，建议通过OH_Drawing_GpuContextCreate替代。

**适配指导**

将OH_Drawing_GpuContextCreateFromGL接口替换为OH_Drawing_GpuContextCreate。