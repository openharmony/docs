# 表单类组件

## Slider（滑动条组件）

以下接口在ArkTS1.1中已标记为废弃，并在ArkTS1.2中不再支持。

### minLabel

ArkTS1.1接口声明：[minLabel(value: string)](../reference/apis-arkui/arkui-ts/ts-basic-components-slider.md#minlabeldeprecated)

替代的ArkTS1.2接口声明：[min?: number](../reference/apis-arkui/arkui-ts/ts-basic-components-slider.md#slideroptions对象说明)

### maxLabel

ArkTS1.1接口声明：[maxLabel(value: string)](../reference/apis-arkui/arkui-ts/ts-basic-components-slider.md#maxlabeldeprecated)

替代的ArkTS1.2接口声明：[max?: number](../reference/apis-arkui/arkui-ts/ts-basic-components-slider.md#slideroptions对象说明)

适配方法如下：

ArkTS1.1

```
Slider({value: 50}).minLabel('0').maxLabel('100')
```

ArkTS1.2

```
Slider({value: 50, min: 0, max: 100})
```