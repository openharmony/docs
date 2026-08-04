# 绑定手势事件
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @yihao-lin-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @Brilliantry_Rui-->

为组件绑定不同类型的手势事件，并设置事件的响应方法；支持普通手势绑定、父组件优先识别手势和父子组件同时触发手势，适用于组件交互响应、父子组件手势优先级控制以及多组件手势协同触发等场景。

>  **说明：**
>
> - 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 可以通过gesture、priorityGesture和parallelGesture给组件绑定手势识别，手势识别成功后可以通过事件回调通知组件。可以通过[触摸热区](ts-universal-attributes-touch-target.md)指定可识别手势的区域。gesture、priorityGesture和parallelGesture当前不支持使用三目运算符（`条件 ? 表达式1 : 表达式2`）切换手势绑定。

## gesture

gesture(gesture: GestureType, mask?: GestureMask): T

绑定手势。

> **说明：**
>
> 该接口不支持在[attributeModifier](ts-universal-attributes-attribute-modifier.md#attributemodifier)中调用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                       | 必填 | 说明                         |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| gesture  |  [GestureType](./ts-gesture-common.md#gesturetype) | 是   | 绑定的手势类型。 |
| mask  |  [GestureMask](./ts-gesture-common.md#gesturemask枚举说明) | 否   | 事件响应设置。当需要设置父组件优先识别手势时是否屏蔽子组件手势时传入该参数：GestureMask.Normal表示不屏蔽子组件手势，适用于父组件优先识别后仍允许子组件手势按默认规则参与识别的场景；GestureMask.IgnoreInternal表示屏蔽子组件手势，适用于希望父组件priorityGesture绑定的手势优先响应并忽略子组件手势的场景。不传入时默认值为GestureMask.Normal。 |

**返回值：**

| 类型     | 说明        |
| ------ | --------- |
| T | 返回当前组件，可用于链式调用。 |

## priorityGesture

priorityGesture(gesture: GestureType, mask?: GestureMask): T

绑定优先识别手势。

1. 默认情况下，子组件优先识别通过gesture绑定的手势，当父组件配置priorityGesture时，父组件优先识别priorityGesture绑定的手势。

2. 绑定长按手势时，设置的触发长按最短时间小于其他参与手势识别组件的组件会优先响应，并忽略priorityGesture设置。

> **说明：**
>
> 该接口不支持在[attributeModifier](ts-universal-attributes-attribute-modifier.md#attributemodifier)中调用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                       | 必填 | 说明                         |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| gesture | [GestureType](./ts-gesture-common.md#gesturetype) | 是 | 绑定的手势对象。绑定长按手势时，设置触发长按的最短时间较小的组件会优先响应，并忽略priorityGesture设置。 |
| mask  |  [GestureMask](./ts-gesture-common.md#gesturemask枚举说明) | 否   | 事件响应设置。<br/>默认值：GestureMask.Normal |

**返回值：**

| 类型     | 说明        |
| ------ | --------- |
| T | 返回当前组件，可用于链式调用。 |

## parallelGesture

parallelGesture(gesture: GestureType, mask?: GestureMask): T

绑定可与子组件手势同时触发的手势。手势事件为非冒泡事件。父组件设置parallelGesture时，父子组件相同的手势事件都可以触发，实现类似冒泡效果。

> **说明：**
>
> 该接口不支持在[attributeModifier](ts-universal-attributes-attribute-modifier.md#attributemodifier)中调用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                       | 必填 | 说明                         |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| gesture  |  [GestureType](./ts-gesture-common.md#gesturetype) | 是   | 绑定的手势对象。 |
| mask | [GestureMask](./ts-gesture-common.md#gesturemask枚举说明) | 否 | 事件响应设置。当需要配置父子组件手势同时触发时，可传入该参数控制是否屏蔽子组件手势：GestureMask.Normal表示不屏蔽子组件手势，适用于父子组件手势都需要响应的场景；GestureMask.IgnoreInternal表示屏蔽子组件手势，适用于只希望父组件parallelGesture绑定的手势响应的场景。不传入时默认值为GestureMask.Normal。 |

**返回值：**

| 类型     | 说明        |
| ------ | --------- |
| T | 返回当前组件，可用于链式调用。 |

## SourceType枚举说明<sup>8+</sup>

定义输入源对应的设备类型。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 值 | 说明 |
| ---- | --- | -------- |
| Unknown | 0 | 未知输入源。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| Mouse | 1 | 鼠标。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| TouchScreen | 2 | 触摸屏。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| KEY<sup>22+</sup> | 4 | 按键。<br>**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。<br>**模型约束：** 此接口仅可在Stage模型下使用。 |
| JOYSTICK<sup>22+</sup> | 5 | 手柄。<br>**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。<br>**模型约束：** 此接口仅可在Stage模型下使用。 |

## SourceTool枚举说明<sup>9+</sup>

定义输入源对应的工具类型。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 值 | 说明 |
| -------- | - | --------- |
| Unknown | 0 | 未知输入源。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| Finger | 1 | 手指输入。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| Pen | 2 | 手写笔输入。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| MOUSE<sup>12+</sup> | 7 | 鼠标输入。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br>**模型约束：** 此接口仅可在Stage模型下使用。 |
| TOUCHPAD<sup>12+</sup> | 9 | 触控板输入。触控板单指输入被视为鼠标输入操作。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br>**模型约束：** 此接口仅可在Stage模型下使用。 |
| JOYSTICK<sup>12+</sup> | 10 | 手柄输入。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br>**模型约束：** 此接口仅可在Stage模型下使用。 |

## 示例

### 示例1（父组件优先识别手势和父子组件同时触发手势）

该示例通过配置priorityGesture和parallelGesture分别实现了父组件优先识别手势和父子组件同时触发手势。

```ts
// xxx.ets
@Entry
@Component
struct GestureSettingsExample {
  @State priorityTestValue: string = ''
  @State parallelTestValue: string = ''

  build() {
    Column() {
      Column() {
        Text('TapGesture:' + this.priorityTestValue).fontSize(28)
          .gesture(
            TapGesture()
              .onAction(() => {
                this.priorityTestValue += '\nText';
              }))
      }
      .height(200)
      .width(250)
      .padding(20)
      .margin(20)
      .border({ width: 3 })
      // 设置为priorityGesture时，点击文本会忽略Text组件的TapGesture手势事件，优先识别父组件Column的TapGesture手势事件
      .priorityGesture(
        TapGesture()
          .onAction((event: GestureEvent) => {
            this.priorityTestValue += '\nColumn';
          }), GestureMask.IgnoreInternal)

      Column() {
        Text('TapGesture:' + this.parallelTestValue).fontSize(28)
          .gesture(
            TapGesture()
              .onAction((event: GestureEvent) => {
                this.parallelTestValue += '\nText';
              }))
      }
      .height(200)
      .width(250)
      .padding(20)
      .margin(20)
      .border({ width: 3 })
      // 设置为parallelGesture时，点击文本会同时触发子组件Text与父组件Column的TapGesture手势事件
      .parallelGesture(
        TapGesture()
          .onAction((event: GestureEvent) => {
            this.parallelTestValue += '\nColumn';
          }), GestureMask.Normal)
    }
  }
}
```

![parallelGesture](figures/parallelGesture.gif)

### 示例2（实时监测参与滑动手势的有效触点数量）

该示例通过读取fingerInfos实时监测参与滑动手势的有效触点数量。

```ts
// xxx.ets
@Entry
@Component
struct PanGestureWithFingerCount {
  @State offsetX: number = 0
  @State offsetY: number = 0
  @State positionX: number = 0
  @State positionY: number = 0
  @State fingerCount: number = 0 // 用于记录参与手势的触点数量
  private panOption: PanGestureOptions = new PanGestureOptions({
    direction: PanDirection.All,
    fingers: 1
  })

  build() {
    Column() {
      // 显示当前有效触点数量
      Text(`触点数量：${this.fingerCount}`)
        .fontSize(20)
        .margin(10)

      Column() {
        Text('PanGesture offset:\nX: ' + this.offsetX + '\n' + 'Y: ' + this.offsetY)
      }
      .height(200)
      .width(300)
      .padding(20)
      .border({ width: 3 })
      .margin(50)
      .translate({ x: this.offsetX, y: this.offsetY, z: 0 })
      .gesture(
        PanGesture(this.panOption)
          .onActionStart((event: GestureEvent) => {
            console.info('Pan start');
            this.fingerCount = event.fingerInfos?.length || 0; // 记录触点数量
          })
          .onActionUpdate((event: GestureEvent) => {
            if (event) {
              console.info(`fingerInfos ${JSON.stringify(event.fingerInfos)}`);
              this.offsetX = this.positionX + event.offsetX;
              this.offsetY = this.positionY + event.offsetY;
              this.fingerCount = event.fingerInfos?.length || 0; // 更新触点数量，记录下参与当前手势的有效触点的数量
            }
          })
          .onActionEnd(() => {
            this.positionX = this.offsetX;
            this.positionY = this.offsetY;
            this.fingerCount = 0; // 触点离开触摸区域后归零
            console.info('Pan end');
          })
          .onActionCancel(() => {
            this.fingerCount = 0; // 手势取消后归零
          })
      )

      Button('切换为双指滑动')
        .onClick(() => {
          this.panOption.setFingers(2);
        })
    }
  }
}
```

![parallelGesture2](figures/zh-cn_image_0000001210195017.gif)