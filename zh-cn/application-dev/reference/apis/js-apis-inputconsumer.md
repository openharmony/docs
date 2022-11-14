# 组合按键

组合按键订阅模块，用于处理组合按键的订阅。

> **说明：**
>
> - 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块接口为系统接口。


## 导入模块


```js
import inputConsumer from '@ohos.multimodalInput.inputConsumer';
```


## inputConsumer.on

on(type: "key", keyOptions: KeyOptions, callback: Callback&lt;KeyOptions&gt;): void

订阅组合按键，当满足条件的组合按键输入事件发生时，使用Callback异步方式上报组合按键数据。

**系统能力：** SystemCapability.MultimodalInput.Input.InputConsumer

**参数：** 

| 参数         | 类型                         | 必填   | 说明                                       |
| ---------- | -------------------------- | ---- | ---------------------------------------- |
| type       | string                     | 是    | 事件类型，目前只支持”key“。                       |
| keyOptions | [keyOptions](#keyoptions)  | 是    | 组合键选项。                 |
| callback   | Callback&lt;KeyOptions&gt; | 是    | 回调函数，当满足条件的组合按键输入事件发生时，异步上报组合按键数据。 |

**示例：** 

```js
let leftAltKey = 2045;
let tabKey = 2049;
try {
  inputConsumer.on("key", {preKeys: [leftAltKey], finalKey: tabKey, isFinalKeyDown: true, finalKeyDownDuration: 0}, keyOptions => {
    console.log(`keyOptions: ${JSON.stringify(keyOptions)}`);
  });
} catch (error) {
  console.log(`Subscribe failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```


## inputConsumer.off

off(type: "key", keyOptions: KeyOptions, callback?: Callback&lt;KeyOptions&gt;): void

取消订阅组合按键。

**系统能力：** SystemCapability.MultimodalInput.Input.InputConsumer

**参数：** 

| 参数         | 类型                         | 必填   | 说明                              |
| ---------- | -------------------------- | ---- | ------------------------------- |
| type       | string                     | 是    | 事件类型，当前只支持”key“。              |
| keyOptions | [keyOptions](#keyoptions)  | 是    | 组合键选项。             |
| callback   | Callback&lt;KeyOptions&gt; | 否    | 需要取消订阅的回调函数，若无此参数，则取消当前应用的组合键选项已订阅的所有回调函数。 |

**示例：** 

```js
let leftAltKey = 2045;
let tabKey = 2049;
// 取消订阅单个回调函数
let callback = function (keyOptions) {
  console.log(`keyOptions: ${JSON.stringify(keyOptions)}`);
}
let keyOption = {preKeys: [leftAltKey], finalKey: tabKey, isFinalKeyDown: true, finalKeyDownDuration: 0};
try {
  inputConsumer.on("key", keyOption, callback);
  inputConsumer.off("key", keyOption, callback);
  console.log(`Unsubscribe success`);
} catch (error) {
  console.log(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```
```js
let leftAltKey = 2045;
let tabKey = 2049;
// 取消订阅所有回调函数
let callback = function (keyOptions) {
  console.log(`keyOptions: ${JSON.stringify(keyOptions)}`);
}
let keyOption = {preKeys: [leftAltKey], finalKey: tabKey, isFinalKeyDown: true, finalKeyDownDuration: 0};
try {
  inputConsumer.on("key", keyOption, callback);
  inputConsumer.off("key", keyOption);
  console.log(`Unsubscribe success`);
} catch (error) {
  console.log(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```


## KeyOptions

组合键选项。

**系统能力：** SystemCapability.MultimodalInput.Input.InputConsumer

| 参数                   | 类型      | 必填   | 说明                       |
| -------------------- | ------- | ---- | ------------------------ |
| preKeys              | Array   | 是    | 前置按键集合，数量范围[0, 4]，前置按键无顺序要求。 |
| finalKey             | Number  | 是    | 最终按键，此项必填，最终按键触发上报回调函数。 |
| isFinalKeyDown       | boolean | 是    | 最终按键状态。 |
| finalKeyDownDuration | Number  | 是    | 最终按键保持按下持续时间，为0时立即触发回调函数，大于0时，当isFinalKeyDown为true，则最终按键按下超过此时长后触发回调函数，当isFinalKeyDown为false，则最终按键按下到抬起时间小于此时长时触发回调函数。   |
