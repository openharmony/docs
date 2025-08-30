# 组合手势
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiangtao92-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @HelloCrease-->

手势识别组合，即多种手势组合为复合手势，支持连续识别、并行识别和互斥识别。

>  **说明：**
>
>  从API version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 接口

GestureGroup(mode: GestureMode, ...gesture: GestureType[])

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                                                     | 必填 | 说明                                                     |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| mode    | [GestureMode](#gesturemode枚举说明)                          | 是   | 设置组合手势识别模式。<br/>默认值：GestureMode.Sequence      |
| gesture | [GestureType](ts-gesture-settings.md#gesturetype)[] | 是   | 设置1个或者多个基础手势类型时，这些手势会被识别为组合手势。若此参数不填则组合手势识别功能不生效。<br/>**说明：**  <br/>当需要为一个组件同时添加单击和双击手势时，可在组合手势中添加两个TapGesture，需要双击手势在前，单击手势在后，否则不生效。 |

## GestureMode枚举说明

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称    | 值    | 说明                                       |
| --------- | -------| ------------------------------------- |
| Sequence | - | 顺序识别，按照手势的注册顺序识别手势，直到所有手势识别成功。若有一个手势识别失败，后续手势识别均失败。<br>顺序识别手势组仅有最后一个手势可以响应onActionEnd。 |
| Parallel | - | 并发识别，注册的手势同时识别，直到所有手势识别结束，手势识别互相不影响。     |
| Exclusive| - | 互斥识别，注册的手势同时识别，若有一个手势识别成功，则结束手势识别。       |


## 事件

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### onCancel

onCancel(event: () => void)

手势识别成功，接收到触摸取消事件触发回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                       | 必填 | 说明                         |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| event  |  () => void | 是   | 手势事件回调函数。 |

## 示例

该示例通过配置GestureGroup实现了长按和拖动的组合手势顺序识别。

```ts
// xxx.ets
@Entry
@Component
struct GestureGroupExample {
  @State count: number = 0;
  @State offsetX: number = 0;
  @State offsetY: number = 0;
  @State positionX: number = 0;
  @State positionY: number = 0;
  @State borderStyles: BorderStyle = BorderStyle.Solid;

  build() {
    Column() {
      Text('sequence gesture\n' + 'LongPress onAction:' + this.count + '\nPanGesture offset:\nX: ' + this.offsetX + '\n' + 'Y: ' + this.offsetY)
        .fontSize(15)
    }
    .translate({ x: this.offsetX, y: this.offsetY, z: 0 })
    .height(150)
    .width(200)
    .padding(20)
    .margin(20)
    .border({ width: 3, style: this.borderStyles })
    .gesture(
      // 以下组合手势为顺序识别，当长按手势事件未正常触发时则不会触发拖动手势事件
      GestureGroup(GestureMode.Sequence,
        LongPressGesture({ repeat: true })
          .onAction((event?: GestureEvent) => {
            if (event && event.repeat) {
              this.count++
            }
            console.info('LongPress onAction')
          }),
        PanGesture()
          .onActionStart(() => {
            this.borderStyles = BorderStyle.Dashed
            console.info('pan start')
          })
          .onActionUpdate((event?: GestureEvent) => {
            if (event) {
              this.offsetX = this.positionX + event.offsetX
              this.offsetY = this.positionY + event.offsetY
            }
            console.info('pan update')
          })
          .onActionEnd(() => {
            this.positionX = this.offsetX
            this.positionY = this.offsetY
            this.borderStyles = BorderStyle.Solid
            console.info('pan end')
          })
      )
        .onCancel(() => {
          console.info('sequence gesture canceled')
        })
    )
  }
}
```

示意图：

按顺序首先触发长按事件：

![zh-cn_image_0000001174104384](figures/zh-cn_image_0000001174104384.png)

按顺序首先触发长按事件，长按事件识别结束之后，其次触发拖动事件，向右下方拖动：

 ![zh-cn_image1_0000001174104384](figures/zh-cn_image1_0000001174104384.png) 