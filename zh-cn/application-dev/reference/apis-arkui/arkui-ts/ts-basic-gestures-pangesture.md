# PanGesture
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiangtao92-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @HelloCrease-->

滑动手势事件，当滑动的最小距离达到设定的最小值时触发滑动手势事件。

以下场景可以触发滑动手势：

| 触发方式              | 输入源类型           | 输入设备类型            | 备注                              | 
|----------------------|---------------------|------------------------|-----------------------------------|
| 手指按下滑动。          | [SourceTool](ts-gesture-settings.md#sourcetool枚举说明9).Finger   | [SourceType](ts-gesture-settings.md#sourcetype枚举说明8).TouchScreen | axisVertical和axisHorizontal均为0。 |
| 鼠标左键按下滑动。      | [SourceTool](ts-gesture-settings.md#sourcetool枚举说明9).MOUSE    | [SourceType](ts-gesture-settings.md#sourcetype枚举说明8).Mouse        | axisVertical和axisHorizontal均为0。 |
| 鼠标滚轮滚动。          | [SourceTool](ts-gesture-settings.md#sourcetool枚举说明9).MOUSE    | [SourceType](ts-gesture-settings.md#sourcetype枚举说明8).Mouse        | axisVertical或axisHorizontal不为0。 |
| 触摸板按下左键后滑动。  | [SourceTool](ts-gesture-settings.md#sourcetool枚举说明9).MOUSE  | [SourceType](ts-gesture-settings.md#sourcetype枚举说明8).Mouse     | axisVertical和axisHorizontal均为0。 |
| 触摸板双指滑动。       | [SourceTool](ts-gesture-settings.md#sourcetool枚举说明9).TOUCHPAD  | [SourceType](ts-gesture-settings.md#sourcetype枚举说明8).Mouse      | axisVertical或axisHorizontal不为0。 |
| 手写笔滑动。       | [SourceTool](ts-gesture-settings.md#sourcetool枚举说明9).Pen  | [SourceType](ts-gesture-settings.md#sourcetype枚举说明8).TouchScreen      | axisVertical和axisHorizontal均为0。 |

>  **说明：**
>
>  从API version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 接口

### PanGesture

PanGesture(value?: { fingers?: number; direction?: PanDirection; distance?: number } | PanGestureOptions)

设置滑动手势事件。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | { fingers?: number; direction?: PanDirection; distance?: number } \| [PanGestureOptions](#pangestureoptions) | 否 | 设置拖动手势事件参数。<br> - fingers：用于指定触发滑动的最少手指数，最小为1指，最大取值为10指。<br/>默认值：1<br/>取值范围：[1, 10]<br/>**说明：** <br/>当设置的值小于1或不设置时，会被转化为默认值。<br> - direction：用于指定触发滑动的手势方向，此枚举值支持逻辑与(&amp;)和逻辑或（\|）运算。<br/>默认值：PanDirection.All<br> - distance：用于指定触发滑动手势事件的最小滑动距离，单位为vp。<br/>取值范围：[0, +∞)<br/>手写笔默认值：8，其余输入源默认值：5<br/>**说明：**<br/>[Tabs组件](ts-container-tabs.md)滑动与该滑动手势事件同时存在时，可将distance值设为1，使滑动更灵敏，避免造成事件错乱。<br/>当设定的值小于0时，按默认值处理。 |

### PanGesture<sup>15+</sup>

PanGesture(options?: PanGestureHandlerOptions)

设置拖动手势事件。与[PanGesture](#pangesture-1)相比，options参数新增了对isFingerCountLimited和distanceMap参数，分别表示是否检查触摸屏幕的手指数量以及指定不同输入源触发拖动手势事件的最小拖动距离。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| options   | [PanGestureHandlerOptions](./ts-uigestureevent.md#pangesturehandleroptions)   | 否   | 拖动手势处理器配置参数。 |

## PanDirection枚举说明

与SwipeDirection不同，PanDirection没有角度限制。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 值 | 说明 |
| ---- | -- | ----- |
| All | - | 所有方向。 |
| Horizontal | - | 水平方向。 |
| Vertical | - | 竖直方向。 |
| Left | - | 向左滑动。 |
| Right | - | 向右滑动。 |
| Up | - | 向上滑动。 |
| Down | - | 向下滑动。 |
| None | - | 任何方向都不可触发滑动手势事件。 |


## PanGestureOptions

### constructor

PanGestureOptions(value?: { fingers?: number, direction?: PanDirection, distance?: number })

通过PanGestureOptions对象接口可以动态修改平移手势识别器的属性，从而避免通过状态变量修改属性（状态变量修改会导致UI刷新）。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| --------- | ------------------------------------- | ---- | ------------------------------------------------------------ |
| fingers   | number                                | 否   | 用于指定触发滑动的最少手指数，最小为1指，&nbsp;最大取值为10指。<br/>默认值：1 |
| direction | [PanDirection](#pandirection枚举说明) | 否   | 用于指定设置滑动方向，此枚举值支持逻辑与(&amp;)和逻辑或（\|）运算。<br/>默认值：PanDirection.All |
| distance  | number                                | 否   | 用于指定触发滑动手势事件的最小滑动距离，单位为vp。<br/>手写笔默认值：8，其余输入源默认值：5<br/>**说明：**<br/>[Tabs组件](ts-container-tabs.md)滑动与该滑动手势事件同时存在时，可将distance值设为1，使滑动更灵敏，避免造成事件错乱。<br/>当设定的值小于0时，按默认值处理。<br/>建议设置合理的滑动距离，滑动距离设置过大时会导致滑动不跟手（响应时延慢）的问题。 |

### constructor<sup>20+</sup>

constructor(value?: PanGestureHandlerOptions)

通过PanGestureOptions对象接口可以动态修改平移手势识别器的属性，从而避免通过状态变量修改属性（状态变量修改会导致UI刷新）。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| --------- | ---------------------- | ---- | -------------------------------- |
| value   | [PanGestureHandlerOptions](./ts-uigestureevent.md#pangesturehandleroptions)   | 否   | 拖动手势处理器配置参数。 |

### setDirection

setDirection(value: PanDirection)

设置滑动方向。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                       | 必填 | 说明                      |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| value  |  [PanDirection](#pandirection枚举说明) | 是   | 用于指定设置滑动方向，此枚举值支持逻辑与(&amp;)和逻辑或（\|）运算。<br/>默认值：PanDirection.All |

### setDirection<sup>20+</sup>

setDirection(value: PanDirection): void

设置滑动方向。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                       | 必填 | 说明                         |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| value  |  [PanDirection](#pandirection枚举说明) | 是   | 用于指定设置滑动方向，此枚举值支持逻辑与(&amp;)和逻辑或（\|）运算。<br/>默认值：PanDirection.All |

### setDistance

setDistance(value: number)

设置触发滑动手势事件的最小滑动距离，单位为vp。距离值不宜设置过大，避免因滑动脱手，响应时延过大等问题导致性能劣化，最佳实践请参考：[减小拖动识别距离](https://developer.huawei.com/consumer/cn/doc/best-practices-V5/bpta-application-latency-optimization-cases-V5#section1116134115286)。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                       | 必填 | 说明                        |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| value  |  number | 是   | 用于指定触发滑动手势事件的最小滑动距离，单位为vp。<br/>手写笔默认值：8，其余输入源默认值：5<br/>**说明：**<br/>[Tabs组件](ts-container-tabs.md)滑动与该滑动手势事件同时存在时，可将distance值设为1，使滑动更灵敏，避免造成事件错乱。<br/>当设定的值小于0时，按默认值处理。<br/>建议设置合理的滑动距离，滑动距离设置过大时会导致滑动不跟手（响应时延慢）的问题。 |

### setDistance<sup>20+</sup>

setDistance(value: number): void

设置触发滑动手势事件的最小滑动距离，单位为vp。距离值不宜设置过大，避免因滑动脱手，响应时延过大等问题导致性能劣化，最佳实践请参考：[减小拖动识别距离](https://developer.huawei.com/consumer/cn/doc/best-practices-V5/bpta-application-latency-optimization-cases-V5#section1116134115286)。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                       | 必填 | 说明                       |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| value  |  number | 是   | 用于指定触发滑动手势事件的最小滑动距离，单位为vp。<br/>手写笔默认值：8，其余输入源默认值：5<br/>**说明：**<br/>[Tabs组件](ts-container-tabs.md)滑动与该滑动手势事件同时存在时，可将distance值设为1，使滑动更灵敏，避免造成事件错乱。<br/>当设定的值小于0时，按默认值处理。<br/>建议设置合理的滑动距离，滑动距离设置过大时会导致滑动不跟手（响应时延慢）的问题。 |

### setFingers

setFingers(value: number)

设置触发滑动的最少手指数。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                       | 必填 | 说明                         |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| value  |  number | 是   | 用于指定触发滑动的最少手指数，最小为1指，&nbsp;最大取值为10指。<br/>默认值：1 |

### setFingers<sup>20+</sup>

setFingers(value: number): void

设置触发滑动的最少手指数。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                       | 必填 | 说明                         |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| value  |  number | 是   | 用于指定触发滑动的最少手指数，最小为1指，&nbsp;最大取值为10指。<br/>默认值：1 |


### getDirection<sup>12+</sup>

getDirection(): PanDirection

获取滑动方向。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型     | 说明        |
| ------ | --------- |
| [PanDirection](#pandirection枚举说明) | 返回滑动方向。 |

### getDistance<sup>18+</sup>

getDistance(): number

获取触发滑动手势事件的最小滑动距离。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型     | 说明        |
| ------ | --------- |
| number | 返回滑动手势事件的最小滑动距离。 |


## 事件

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

>  **说明：**
>
>  在[GestureEvent](ts-gesture-settings.md#gestureevent对象说明)的fingerList元素中，手指索引编号与位置相对应，即fingerList[index]的id为index。对于先按下但未参与当前手势触发的手指，fingerList中对应的位置为空。建议优先使用fingerInfos。

### onActionStart

onActionStart(event: (event: GestureEvent) => void)

Pan手势识别成功回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                       | 必填 | 说明                         |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| event  |  (event: [GestureEvent](ts-gesture-settings.md#gestureevent对象说明)) => void | 是   | 手势事件回调函数。 |

### onActionUpdate

onActionUpdate(event: (event: GestureEvent) => void)

Pan手势移动过程中回调。fingerList为多根手指时，该回调监听每次只会更新一根手指的位置信息。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                       | 必填 | 说明                         |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| event  |  (event: [GestureEvent](ts-gesture-settings.md#gestureevent对象说明)) => void | 是   | 手势事件回调函数。 |

### onActionEnd

onActionEnd(event: (event: GestureEvent) => void)

Pan手势识别成功，手指抬起后触发回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                       | 必填 | 说明                         |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| event  |  (event: [GestureEvent](ts-gesture-settings.md#gestureevent对象说明)) => void | 是   | 手势事件回调函数。 |

### onActionCancel

onActionCancel(event: () => void)

Pan手势识别成功，接收到触摸取消事件触发回调。不返回手势事件信息。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                       | 必填 | 说明                         |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| event  |  () => void | 是   | 手势事件回调函数。 |

### onActionCancel<sup>18+</sup>

onActionCancel(event: Callback\<GestureEvent\>)

Pan手势识别成功，接收到触摸取消事件触发回调。返回手势事件信息。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                       | 必填 | 说明                         |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| event  |  Callback\<[GestureEvent](ts-gesture-settings.md#gestureevent对象说明)> | 是   | 手势信息回调函数。 |

## 属性

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型    | 只读 | 可选 | 说明                     |
| ----  | ------ | ---- | ---- | ----------------------- |
| tag<sup>11+</sup>   | string  | 否 | 否 | 设置Pan手势标志，用于自定义手势判定时区分绑定的手势。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| allowedTypes<sup>14+</sup> | Array\<[SourceTool](ts-gesture-settings.md#sourcetool枚举说明9)>  | 否 | 否 | 设置Pan手势支持的事件输入源。<br/>**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。 |

## 示例

该示例通过PanGesture实现了单指/双指滑动手势的识别。

```ts
// xxx.ets
@Entry
@Component
struct PanGestureExample {
  @State offsetX: number = 0;
  @State offsetY: number = 0;
  @State positionX: number = 0;
  @State positionY: number = 0;
  private panOption: PanGestureOptions = new PanGestureOptions({ direction: PanDirection.Left | PanDirection.Right });

  build() {
    Column() {
      Column() {
        Text('PanGesture offset:\nX: ' + this.offsetX + '\n' + 'Y: ' + this.offsetY)
      }
      .height(200)
      .width(300)
      .padding(20)
      .border({ width: 3 })
      .margin(50)
      .translate({ x: this.offsetX, y: this.offsetY, z: 0 }) // 以组件左上角为坐标原点进行移动
      // 左右滑动触发该手势事件
      .gesture(
      PanGesture(this.panOption)
        .onActionStart((event: GestureEvent) => {
          console.info('Pan start');
          console.info('Pan start timeStamp is: ' + event.timestamp);
        })
        .onActionUpdate((event: GestureEvent) => {
          if (event) {
            this.offsetX = this.positionX + event.offsetX;
            this.offsetY = this.positionY + event.offsetY;
          }
        })
        .onActionEnd((event: GestureEvent) => {
          this.positionX = this.offsetX;
          this.positionY = this.offsetY;
          console.info('Pan end');
          console.info('Pan end timeStamp is: ' + event.timestamp);
        })
      )

      Button('修改PanGesture触发条件')
        .onClick(() => {
          // 将PanGesture手势事件触发条件改为双指以任意方向滑动
          this.panOption.setDirection(PanDirection.All);
          this.panOption.setFingers(2);
        })
    }
  }
}
```

示意图：

向左滑动：

![zh-cn_image_0000001174264374](figures/zh-cn_image_0000001174264374.png) 

点击按钮修改PanGesture触发条件，双指向左下方滑动：

 ![zh-cn_image1_0000001174264374](figures/zh-cn_image1_0000001174264374.png) 