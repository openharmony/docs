#  @ohos.graphics.displaySync(可变帧率能力)
本模块提供OpenHarmony上动画和自绘制内容的帧率设置能力。

> **说明：**
>
> 本模块首批接口和数据定义从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```ts
import displaySync from '@ohos.graphics.displaySync';
```

## displaySync.create
create(): DisplaySync
创建DisplaySync对象，通过此对象设置UI自绘制内容帧率

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                | 说明                     |
| ------------------ | ------------------------ |
| DisplaySync  | 返回当前创建的DisplaySync对象实例。               |

**示例：**
```ts
private backDisplaySyncBigger: displaySync.DisplaySync = displaySync.create();
```

## DisplaySync
 帧率和回调设置示例。用于设置帧率和回调注册，以及启动和停止
下列API示例中都需先使用[displaySync.create()](#displaySync.create)方法获取到DisplaySync实例，再通过此实例调用对应方法。

### IntervalInfo

帧率信息定义

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称                         | 类型     | 说明                    |
| --------------------------- | ------ | ----------------------- |
| timestamp                           | number      | 当前帧到达的时间。|
| targetTimestamp                    | number      | 下一帧预期时间 |

### setExpectedFrameRateRange
setExpectedFrameRateRange(rateRange: ExpectedFrameRateRange) : void

设置期望的帧率范围

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名           | 类型                                       | 必填 | 说明                          |
| --------------- | ------------------------------------------ | ---- | -----------------------------|
| rateRange       | [ExpectedFrameRateRange](../arkui-ts/ts-animatorproperty.md#expectedframeraterange)| 是   | 设置DisplaySync期望的帧率|

**返回值：**

| 类型                | 说明                     |
| ------------------ | ------------------------ |
| [void]  | 无返回值 |

**示例：**
```ts
let  range : ExpectedFrameRateRange = {
  expected: 10,
  min:0,
  max:120
};
this.backDisplaySyncBigger.setExpectedFrameRateRange(range)
```

### on(type: 'frame')

on(type: 'frame', callback: Callback<IntervalInfo>): void

注册每一帧的回调函数

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名           | 类型                                       | 必填 | 说明                          |
| --------------- | ------------------------------------------ | ---- | -----------------------------|
| type | 'frame'| 是   | 设置注册回调的类型（只能是'frame'类型）|
| callback    | [Callback<IntervalInfo>](js-apis-base.md)| 是   | 回调函数|


**返回值：**

| 类型                | 说明                     |
| ------------------ | ------------------------ |
| [void]  | 无返回值 |

**示例：**
```ts
let _this = this
let Bigger = (ii: displaySync.IntervalInfo) => {
_this.drawFirstSize += 1;
    console.info(_this.TAG, 'Bigger:' + ii.timestamp + ' TargetTimeStamp: ' + ii.targetTimestamp);
}

this.backDisplaySyncBigger.setExpectedFrameRateRange(range)
this.backDisplaySyncBigger.on("frame", Bigger)
```

### off(type: 'frame'): void

取消每一帧的回调函数
```ts
off(type: 'frame', callback?: Callback<IntervalInfo>): void
```

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名           | 类型                                       | 必填 | 说明                          |
| --------------- | ------------------------------------------ | ---- | -----------------------------|
| type | 'frame'| 是   | 设置注册回调的类型（只能是'frame'类型）|
| callback    | [Callback<IntervalInfo>](js-apis-base.md)| 是   | 回调函数|

**返回值：**

| 类型                | 说明                     |
| ------------------ | ------------------------ |
| [void]  | 无返回值 |
**示例：**
```ts
this.backDisplaySyncBigger.off("frame", Bigger)
```

### start()
start(): void
开始每帧回调

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                | 说明                     |
| ------------------ | ------------------------ |
| [void]  | 无返回值 |
**示例：**
```ts
Button('StartBigger')
        .fontSize(30)
        .fontColor(Color.Black)
        .onClick(() => {
          this.backDisplaySyncBigger.start()
        })
```

### stop()

stop(): void

停止每帧回调


**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                | 说明                     |
| ------------------ | ------------------------ |
| [void]  | 无返回值 |


**示例：**
```ts
Button('StartBigger')
        .fontSize(30)
        .fontColor(Color.Black)
        .onClick(() => {
          this.backDisplaySyncBigger.start()
        })
```