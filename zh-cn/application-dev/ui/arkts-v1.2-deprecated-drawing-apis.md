# 绘制组件

以下接口在ArkTS1.1中已标记为废弃，并在ArkTS1.2中不再支持。

## setXComponentSurfaceSize

ArkTS1.1接口声明：[setXComponentSurfaceSize(value: {surfaceWidth: number, surfaceHeight: number}): void](../reference/apis-arkui/arkui-ts/ts-basic-components-xcomponent.md#setXComponentSurfaceSizedeprecated)

替代的ArkTS1.2接口声明：[setXComponentSurfaceRect(rect: SurfaceRect): void](../reference/apis-arkui/arkui-ts/ts-basic-components-xcomponent.md#setxcomponentsurfacerect12)

适配方法如下：

ArkTS1.1

```
controller.setXComponentSurfaceSize({surfaceWidth: 100, surfaceHeight: 100})
```

ArkTS1.2

```
controller.setXComponentSurfaceRect({surfaceWidth: 100, surfaceHeight: 100} as SurfaceRect)
```