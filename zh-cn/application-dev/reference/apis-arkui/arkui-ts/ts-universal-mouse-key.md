# 鼠标事件
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiangtao92-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @HelloCrease-->

在鼠标的单个动作触发多个事件时，事件的顺序是固定的，鼠标事件默认透传。

>  **说明：**
>
>  - 从API version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>  - 目前仅支持通过外接鼠标触发。

## onMouse

onMouse(event: (event: MouseEvent) => void): T

当前组件被鼠标按键点击时或者鼠标在组件上悬浮移动时，触发该回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                              | 必填 | 说明                                                         |
| ------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| event | (event: [MouseEvent](#mouseevent对象说明)) => void | 是   | 返回触发事件时的时间戳、鼠标按键、动作、鼠标位置在整个屏幕上的坐标和相对于当前组件的坐标。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回当前组件。 |

## MouseEvent对象说明

继承于[BaseEvent](ts-gesture-customize-judge.md#baseevent8)。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称                    | 类型                    | 只读    |  可选   |     说明                          |
| ---------------------- | -------------------------------------- |-------------- |------------- |  --------------------------- |
| x                      | number                                  | 否           |  否     |鼠标位置相对于当前组件左上角的x轴坐标。<br/>单位：vp<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。         |
| y                      | number                                    |  否         |  否     |鼠标位置相对于当前组件左上角的y轴坐标。<br/>单位：vp<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。         |
| button                 | [MouseButton](ts-appendix-enums.md#mousebutton8)      |  否     |  否     |鼠标按键。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                        |
| action                 | [MouseAction](ts-appendix-enums.md#mouseaction8)       |  否   |  否     |鼠标动作。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                        |
| stopPropagation        | () => void                            |  否          |  否     |阻塞[事件冒泡](../../../ui/arkts-interaction-basic-principles.md#事件冒泡)。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                      |
| windowX<sup>10+</sup> | number                           |  否          |  否     |鼠标位置相对于应用窗口左上角的x轴坐标。<br/>单位：vp<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| windowY<sup>10+</sup> | number                           |  否         |  否     |鼠标位置相对于应用窗口左上角的y轴坐标。<br/>单位：vp<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| displayX<sup>10+</sup> | number                          |  否         |  否     |鼠标位置相对于应用屏幕左上角的x轴坐标。<br/>单位：vp<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| displayY<sup>10+</sup> | number                         |  否          |  否     |鼠标位置相对于应用屏幕左上角的y轴坐标。<br/>单位：vp<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| screenX<sup>(deprecated)</sup> | number                 |  否         |  否     |鼠标位置相对于应用窗口左上角的x轴坐标。<br>单位：vp<br/>从API version 10开始不再维护，建议使用windowX代替。 |
| screenY<sup>(deprecated)</sup> | number                 |  否          |  否     |鼠标位置相对于应用窗口左上角的y轴坐标。<br>单位：vp<br/>从API version 10开始不再维护，建议使用windowY代替。 |
| rawDeltaX<sup>15+</sup> | number      |  否   |  是     |相对于先前上报的鼠标指针位置的X轴偏移量。当鼠标指针处于屏幕边缘时，该值可能小于两次上报的X坐标之差。<br/>单位：vp<br/>**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。 |
| rawDeltaY<sup>15+</sup> | number      |  否     |  是    |相对于先前上报的鼠标指针位置的Y轴偏移量。<br/>单位：vp<br/>**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。 |
| pressedButtons<sup>15+</sup> | MouseButton[]      |  否      | 是     |所有鼠标上按着的按钮集合。<br/>**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。 |
| globalDisplayX<sup>20+</sup> | number       |  否    |  是    |鼠标位置相对于全局屏幕的左上角的X坐标。<br/>单位：vp<br/>取值范围：[0, +∞)<br/>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。 |
| globalDisplayY<sup>20+</sup> | number      | 否      |  是    |鼠标位置相对于全局屏幕的左上角的Y坐标。<br/>单位：vp<br/>取值范围：[0, +∞)<br/>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。 |

## 示例

该示例通过按钮设置了鼠标事件，通过鼠标点击按钮可以触发onMouse事件，获取鼠标事件相关参数。
鼠标滚轮的处理请参考[轴事件示例](ts-universal-events-axis.md#示例)。

```ts
// xxx.ets
@Entry
@Component
struct MouseEventExample {
  @State hoverText: string = 'no hover';
  @State mouseText: string = '';
  @State action: string = '';
  @State mouseBtn: string = '';
  @State color: Color = Color.Blue;

  build() {
    Column({ space: 20 }) {
      Button(this.hoverText)
        .width(180).height(80)
        .backgroundColor(this.color)
        .onHover((isHover: boolean, event: HoverEvent) => {
          // 通过onHover事件动态修改按钮在是否有鼠标悬浮时的文本内容与背景颜色
          if (isHover) {
            this.hoverText = 'hover';
            this.color = Color.Pink;
          } else {
            this.hoverText = 'no hover';
            this.color = Color.Blue;
          }
        })
      Button('onMouse')
        .width(180).height(80)
        .onMouse((event: MouseEvent): void => {
          if (event) {
            switch (event.button) {
              case MouseButton.None:
                this.mouseBtn = 'None';
                break;
              case MouseButton.Left:
                this.mouseBtn = 'Left';
                break;
              case MouseButton.Right:
                this.mouseBtn = 'Right';
                break;
              case MouseButton.Back:
                this.mouseBtn = 'Back';
                break;
              case MouseButton.Forward:
                this.mouseBtn = 'Forward';
                break;
              case MouseButton.Middle:
                this.mouseBtn = 'Middle';
                break;
            }
            switch (event.action) {
              case MouseAction.Hover:
                this.action = 'Hover';
                break;
              case MouseAction.Press:
                this.action = 'Press';
                break;
              case MouseAction.Move:
                this.action = 'Move';
                break;
              case MouseAction.Release:
                this.action = 'Release';
                break;
            }
            this.mouseText = 'onMouse:\nButton = ' + this.mouseBtn +
              '\nAction = ' + this.action + '\nXY=(' + event.x + ',' + event.y + ')' +
              '\nwindowXY=(' + event.windowX + ',' + event.windowY + ')' +
              '\ntargetDisplayId = ' + event.targetDisplayId +
              '\nrawDeltaX = ' + event.rawDeltaX +
              '\nrawDeltaY = ' + event.rawDeltaY +
              '\nlength = ' + event.pressedButtons?.length;
          }
        })
      Text(this.mouseText)
    }.padding({ top: 30 }).width('100%')
  }
}
```

示意图： 

鼠标点击时：

![mouse](figures/mouse.gif)
