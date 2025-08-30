# 轴事件
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiangtao92-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @HelloCrease-->

轴事件指组件被鼠标滚轮滚动或触控板双指沿特定方向（轴）滑动时触发的事件。“轴”指二维坐标系中的方向，分为水平（X轴）和垂直（Y轴）。

>  **说明：**
>
>  从API Version 17开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## onAxisEvent

onAxisEvent(event: Callback\<AxisEvent>): T

鼠标滚轮滚动或触控板双指滑动时触发该回调。

**原子化服务API：** 从API version 17开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                              | 必填 | 说明                 |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | Callback\<[AxisEvent](#axisevent)> | 是   | 获得[AxisEvent](#axisevent)对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回当前组件。 |

## AxisEvent

轴事件的对象说明，继承于[BaseEvent](ts-gesture-customize-judge.md#baseevent8)。

**原子化服务API：** 从API version 17开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### 属性

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称            | 类型  | 只读|可选                              | 说明                                                    |
| ------------------- | -----------------------|------|----- | -------------------------------------------------------- |
| action              | [AxisAction](ts-appendix-enums.md#axisaction17)           | 是   | 否   | 轴事件的动作类型。<br/>**原子化服务API：** 从API version 17开始，该接口支持在原子化服务中使用。                   |
| x                   | number                 | 是   | 否   | 鼠标光标相对于被点击元素左边缘的X坐标。<br/>单位：vp<br/>**原子化服务API：** 从API version 17开始，该接口支持在原子化服务中使用。  |
| y                   | number                 | 是   | 否   | 鼠标光标相对于被点击元素上边缘的Y坐标。<br/>单位：vp<br/>**原子化服务API：** 从API version 17开始，该接口支持在原子化服务中使用。  |
| windowX             | number                 | 是   | 否   | 鼠标光标相对于当前窗口左上角的X坐标。<br/>单位：vp<br/>**原子化服务API：** 从API version 17开始，该接口支持在原子化服务中使用。 |
| windowY             | number                 | 是   | 否   | 鼠标光标相对于当前窗口左上角的Y坐标。<br/>单位：vp<br/>**原子化服务API：** 从API version 17开始，该接口支持在原子化服务中使用。 |
| displayX            | number                 | 是   | 否   | 鼠标光标相对于当前屏幕左上角的X坐标。<br/>单位：vp<br/>**原子化服务API：** 从API version 17开始，该接口支持在原子化服务中使用。 |
| displayY            | number                 | 是   | 否   | 鼠标光标相对于当前屏幕左上角的Y坐标。<br/>单位：vp<br/>**原子化服务API：** 从API version 17开始，该接口支持在原子化服务中使用。 |
| scrollStep          | number                 | 是   | 否   | 鼠标轴滚动步长配置。<br/> **说明：** 仅支持鼠标滚轮，取值范围：[0~65535]<br/>**原子化服务API：** 从API version 17开始，该接口支持在原子化服务中使用。|
| propagation         | Callback\<void>        | 是   | 否   | 激活[事件冒泡](../../../ui/arkts-interaction-basic-principles.md#事件冒泡)。<br/>**原子化服务API：** 从API version 17开始，该接口支持在原子化服务中使用。   |
| globalDisplayX<sup>20+</sup> | number | 否 | 是 | 鼠标光标相对于全局屏幕的左上角的X坐标。<br/>单位：vp<br/>取值范围：[0, +∞)<br/>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。 |
| globalDisplayY<sup>20+</sup> | number | 否 | 是 | 鼠标光标相对于全局屏幕的左上角的Y坐标。<br/>单位：vp<br/>取值范围：[0, +∞)<br/>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。 |

### getHorizontalAxisValue

getHorizontalAxisValue(): number

获取此次轴事件的水平轴值。

**原子化服务API：** 从API version 17开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型              |说明       |
| ------- | --------------------------------- | 
| number | 水平轴值。<br>单位：vp |

### getVerticalAxisValue

getVerticalAxisValue(): number

获取此次轴事件的垂直轴值。

**原子化服务API：** 从API version 17开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型              |说明       |
| ------- | --------------------------------- | 
| number | 垂直轴值。<br>单位：vp |

## 示例

该示例中，对按钮设置轴事件，通过滚动鼠标滚轮可获取轴事件的相关参数。

```ts
// xxx.ets
@Entry
@Component
struct AxisEventExample {
  @State text: string = ''

  build() {
    Column() {
      Row({ space: 20 }) {
        Button('AxisEvent').width(100).height(40)
          .onAxisEvent((event?: AxisEvent) => {
            if (event) {
              this.text =
                'AxisEvent:' + '\n  action:' + event.action + '\n  displayX:' + event.displayX + '\n  displayY:' +
                event.displayY + '\n  windowX:' + event.windowX + '\n  windowY:' + event.windowY + '\n  x:' + event.x +
                  '\n  y:' + event.y + '\n VerticalAxisValue:' + event.getVerticalAxisValue() +
                  '\n HorizontalAxisValue:' + event.getHorizontalAxisValue()
            }
          })
      }.margin(20)

      Text(this.text).margin(15)
    }.width('100%')
  }
}
```

鼠标滚轮滚动时：

![onAxisEvent](figures/onAxisEvent.png)
