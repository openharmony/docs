# 悬浮事件
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiangtao92-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @HelloCrease-->

光标滑动或手写笔在屏幕上悬浮移动扫过组件时触发。

>  **说明：**
>
>  - 从API version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>  - 目前支持通过外接鼠标、手写笔以及触控板触发。

## onHover

onHover(event: (isHover: boolean, event: HoverEvent) => void): T

鼠标或手写笔进入或退出组件时触发hover事件。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名              | 类型                                | 必填 | 说明                                                         |
| ------------------- | ----------------------------------- | ---- | ------------------------------------------------------------ |
| event  | (isHover: boolean, event: [HoverEvent](#hoverevent10对象说明)) => void  | 是   | 鼠标的状态信息。<br />event表示设置阻塞事件冒泡属性，并获取鼠标或手写笔悬浮的位置坐标，从API version 11开始支持。<br />isHover表示鼠标或手写笔是否悬浮在组件上，进入时为true，&nbsp;离开时为false。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回当前组件。 |

## onHoverMove<sup>15+</sup>

onHoverMove(event: Callback&lt;HoverEvent&gt;): T

手写笔悬浮于组件上方时触发悬浮移动事件。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名              | 类型                                | 必填 | 说明                                                         |
| ------------------- | ----------------------------------- | ---- | ------------------------------------------------------------ |
| event | Callback<[HoverEvent](#hoverevent10对象说明)> | 是   |设置阻塞事件冒泡属性，并获取手写笔悬浮的位置坐标。         |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回当前组件。 |

## HoverEvent<sup>10+</sup>对象说明

继承于[BaseEvent](ts-gesture-customize-judge.md#baseevent对象说明8)。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 只读 | 可选 | 说明 |
| --------------- | ---------- | ----- | ----- | -------------------- |
| x<sup>15+</sup> |number|否|是|鼠标光标或手写笔位置相对于当前组件左上角的x轴坐标。<br>单位：vp<br> **原子化服务API：**  从API version 15开始，该接口支持在原子化服务中使用。|
| y<sup>15+</sup> |number|否|是|鼠标光标或手写笔位置相对于当前组件左上角的y轴坐标。<br>单位：vp<br> **原子化服务API：**  从API version 15开始，该接口支持在原子化服务中使用。|
| windowX<sup>15+</sup> |number|否|是|鼠标光标或手写笔位置相对于应用窗口左上角的x轴坐标。<br>单位：vp<br> **原子化服务API：**  从API version 15开始，该接口支持在原子化服务中使用。|
| windowY<sup>15+</sup> |number|否|是|鼠标光标或手写笔位置相对于应用窗口左上角的y轴坐标。<br>单位：vp<br> **原子化服务API：**  从API version 15开始，该接口支持在原子化服务中使用。|
| displayX<sup>15+</sup> |number|否|是|鼠标光标或手写笔位置相对于应用屏幕左上角的x轴坐标。<br>单位：vp<br> **原子化服务API：**  从API version 15开始，该接口支持在原子化服务中使用。|
| displayY<sup>15+</sup> |number|否|是|鼠标光标或手写笔位置相对于应用屏幕左上角的y轴坐标。<br>单位：vp<br> **原子化服务API：**  从API version 15开始，该接口支持在原子化服务中使用。|
| stopPropagation | () => void |否|否| 阻塞事件冒泡。 <br> **原子化服务API：**  从API version 11开始，该接口支持在原子化服务中使用。|
| globalDisplayX<sup>20+</sup> | number |否|是| 鼠标光标或手写笔位置相对于全局屏幕的左上角的X坐标。<br/>单位：vp<br/>取值范围：[0, +∞)<br/>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。 |
| globalDisplayY<sup>20+</sup> | number |否|是| 鼠标光标或手写笔位置相对于全局屏幕的左上角的Y坐标。<br/>单位：vp<br/>取值范围：[0, +∞)<br/>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。 |

## 示例

### 示例1（使用onHover）

该示例通过按钮设置了悬浮事件 `onHover()`，鼠标悬浮可触发onHover事件修改按钮颜色。

```ts
// xxx.ets
@Entry
@Component
struct HoverEventExample {
  @State hoverText: string = 'no hover';
  @State color: Color = Color.Blue;

  build() {
    Column({ space: 20 }) {
      Button(this.hoverText)
        .width(180).height(80)
        .backgroundColor(this.color)
        .onHover((isHover: boolean, event: HoverEvent) => {
          // 通过onHover事件动态修改按钮在是否有鼠标或手写笔悬浮时的文本内容与背景颜色
          // 通过event.sourceTool区分设备是鼠标还是手写笔
          if (isHover) {
            if (event.sourceTool == SourceTool.Pen) {
              this.hoverText = 'pen hover';
              this.color = Color.Pink;
            } else if (event.sourceTool == SourceTool.MOUSE) {
              this.hoverText = 'mouse hover';
              this.color = Color.Red;
            }
          } else {
            this.hoverText = 'no hover';
            this.color = Color.Blue;
          }
        })
    }.padding({ top: 30 }).width('100%')
  }
}
```

示意图：

未悬浮时的文本内容与背景颜色：

 ![nohover](figures/no-hover.png) 

手写笔悬浮时改变文本内容与背景颜色：

 ![penhover](figures/pen-hover.png) 

### 示例2（使用onHoverMove）

该示例设置了按钮的 `onHoverMove()` 事件。当手写笔悬浮在按钮时，UI界面会显示当前手写笔悬浮状的位置。

```ts
// xxx.ets
@Entry
@Component
struct OnHoverMoveEventExample {
  @State hoverMoveText: string = '';

  build() {
    Column({ space: 20 }) {
      Button('onHoverMove')
        .width(180).height(80)
        .onHoverMove((event: HoverEvent) => {
          this.hoverMoveText = 'onHoverMove:\nXY = (' + event.x + ', ' + event.y + ')' + 
                               '\nwindowXY = (' + event.windowX + ', ' + event.windowY + ')' +
                               '\ndisplayXY = (' + event.displayX + ', ' + event.displayY + ')';
        })

      Text(this.hoverMoveText)
    }.padding({ top: 30 }).width('100%')
  }
}
```

示意图：

手写悬浮在Button组件上时，UI不断刷新笔尖的位置信息：

![onHoverMove](figures/onHoverMove.png)