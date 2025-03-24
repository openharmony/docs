# @ohos.multimodalInput.inputConsumer (组合按键)

组合按键订阅模块，用于处理组合按键的订阅。

> **说明：**
>
> - 本模块首批接口从API version 14开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块


```js
import { inputConsumer } from '@kit.InputKit';
```

## HotkeyOptions<sup>14+</sup>

快捷键选项。

**系统能力：** SystemCapability.MultimodalInput.Input.InputConsumer

| 名称        | 类型   | 可读   | 可写   | 说明      |
| --------- | ------ | ------- | ------- | ------- |
| preKeys   | Array&lt;number&gt; | 是      | 否      | 修饰键（包括 Ctrl、Shift 和 Alt）集合，数量范围[1, 2]，修饰按键无顺序要求。<br>例如，Ctrl+Shift+Esc中，Ctrl+Shift称为修饰键。 |
| finalKey  | number  | 是      | 否      | 被修饰键，为除修饰键和 Meta 以外的其它按键。<br>如Ctrl+Shift+Esc中，Esc称为被修饰键。 |
| isRepeat  | boolean  | 是      | 否      | 是否上报重复的按键事件。true表示上报，false表示不上报，若不填默认为true。 |

## KeyPressedConfig<sup>16+</sup>

按键事件消费设置。

**系统能力：** SystemCapability.MultimodalInput.Input.InputConsumer

| 名称        | 类型   | 可读   | 可写   | 说明      |
| --------- | ------ | ------- | ------- | ------- |
| key       | number  | 是      | 否      | 按键键值。<br>当前仅支持[KEYCODE_VOLUME_UP](js-apis-keycode.md#keycode)键和[KEYCODE_VOLUME_DOWN](js-apis-keycode.md#keycode)键。 |  
| action    | number  | 是      | 否      | 按键事件类型。取值如下，当前仅支持取值为1。<br>- 1：按键按下。<br>- 2：按键抬起。 |  
| isRepeat  | boolean  | 是      | 否      | 是否上报重复的按键事件。 |

## inputConsumer.getAllSystemHotkeys<sup>14+</sup>

getAllSystemHotkeys(): Promise&lt;Array&lt;HotkeyOptions&gt;&gt;

获取系统所有快捷键，使用Promise异步回调。

**系统能力：** SystemCapability.MultimodalInput.Input.InputConsumer

**返回值：**

| 参数         |  说明                                       |
| ---------- |  ---------------------------------------- |
| Promise&lt;Array&lt;HotkeyOptions&gt;&gt;                    | Promise对象，返回所有系统快捷键的列表。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                  |
| -------- | ------------------------- |
| 801      | Capability not supported. |

**示例：**

```js
inputConsumer.getAllSystemHotkeys().then((data: Array<inputConsumer.HotkeyOptions>) => {
  console.log(`List of system hotkeys : ${JSON.stringify(data)}`);
});
```

## inputConsumer.on('hotkeyOptions')<sup>14+</sup>

on(type: 'hotkeyChange', hotkeyOptions: HotkeyOptions, callback: Callback&lt;HotkeyOptions&gt;): void

订阅全局组合按键，当满足条件的组合按键输入事件发生时，使用Callback异步方式上报组合按键数据。

**系统能力：** SystemCapability.MultimodalInput.Input.InputConsumer

**参数：** 

| 参数名         | 类型                         | 必填   | 说明                                       |
| ---------- | -------------------------- | ---- | ---------- |
| type       | string                     | 是    | 事件类型，固定取值为'hotkeyChange'。                   |
| hotkeyOptions | [HotkeyOptions](#hotkeyoptions14) | 是    | 快捷键选项。                 |
| callback   | Callback&lt;HotkeyOptions&gt; | 是    | 回调函数，当满足条件的全局组合按键输入事件发生时，异步上报组合按键数据。 |

**错误码**：

以下错误码的详细介绍请参见[inputconsumer错误码](errorcode-inputconsumer.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |
| 801 | Capability not supported. |
| 4200002  | The hotkey has been used by the system. |
| 4200003  | The hotkey has been subscribed to by another. |

**示例：**

```js
let leftCtrlKey = 2072;
let zKey = 2042;
let hotkeyOptions: inputConsumer.HotkeyOptions = {
  preKeys: [ leftCtrlKey ],
  finalKey: zKey,
  isRepeat: true
};
let hotkeyCallback = (hotkeyOptions: inputConsumer.HotkeyOptions) => {
  console.log(`hotkeyOptions: ${JSON.stringify(hotkeyOptions)}`);
}
try {
  inputConsumer.on("hotkeyChange", hotkeyOptions, hotkeyCallback);
} catch (error) {
  console.log(`Subscribe failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputConsumer.off('hotkeyOptions')<sup>14+</sup>

off(type: 'hotkeyChange', hotkeyOptions: HotkeyOptions, callback?: Callback&lt;HotkeyOptions&gt;): void

取消订阅全局组合按键。

**系统能力：** SystemCapability.MultimodalInput.Input.InputConsumer

**参数：** 

| 参数名         | 类型                         | 必填   | 说明                              |
| ---------- | -------------------------- | ---- | ---------- |
| type       | string                     | 是    | 事件类型，固定取值为'hotkeyChange'。        |
| hotkeyOptions | [HotkeyOptions](#hotkeyoptions14) | 是    | 快捷键选项。             |
| callback   | Callback&lt;HotkeyOptions&gt; | 否    | 需要取消订阅的回调函数。若不填，则取消当前应用全局快捷键选项已订阅的所有回调函数。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |
| 801 | Capability not supported. |

**示例：**

```js
let leftCtrlKey = 2072;
let zKey = 2042;
// 取消订阅单个全局快捷键回调函数
let hotkeyCallback = (hotkeyOptions: inputConsumer.HotkeyOptions) => {
  console.log(`hotkeyOptions: ${JSON.stringify(hotkeyOptions)}`);
}
let hotkeyOption: inputConsumer.HotkeyOptions = {preKeys: [leftCtrlKey], finalKey: zKey, isRepeat: true};
try {
  inputConsumer.on("hotkeyChange", hotkeyOption, hotkeyCallback);
  inputConsumer.off("hotkeyChange", hotkeyOption, hotkeyCallback);
  console.log(`Unsubscribe success`);
} catch (error) {
  console.log(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

```js
let leftCtrlKey = 2072;
let zKey = 2042;
// 取消订阅所有全局快捷键回调函数
let hotkeyCallback = (hotkeyOptions: inputConsumer.HotkeyOptions) => {
  console.log(`hotkeyOptions: ${JSON.stringify(hotkeyOptions)}`);
}
let hotkeyOption: inputConsumer.HotkeyOptions = {preKeys: [leftCtrlKey], finalKey: zKey, isRepeat: true};
try {
  inputConsumer.on("hotkeyChange", hotkeyOption, hotkeyCallback);
  inputConsumer.off("hotkeyChange", hotkeyOption);
  console.log(`Unsubscribe success`);
} catch (error) {
  console.log(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputConsumer.on('keyPressed')<sup>16+</sup>

on(type: 'keyPressed', options: KeyPressedConfig, callback: Callback&lt;KeyEvent&gt;): void

订阅按键按下事件。若当前应用处于前台焦点窗口，用户按下指定按键，会触发回调。

**系统能力：** SystemCapability.MultimodalInput.Input.InputConsumer

**参数：**

| 参数名         | 类型                                | 必填  | 说明                              |
| ---------- | --------------------------             | ----  | ---------- |
| type       | string                                 | 是     | 事件类型，固定取值为'keyPressed'。        |
| options    | [KeyPressedConfig](#keypressedconfig16)| 是     | 按键事件消费设置。           |
| callback   | Callback&lt;[KeyEvent](./js-apis-keyevent.md#keyevent)&gt; | 是    | 用于返回按键事件的回调函数。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |
| 801 | Capability not supported. |

**示例：**

```js
try {
  let options: inputConsumer.KeyPressedConfig = {
    key: 16,
    action: 1,
    isRepeat: false,
  }
  inputConsumer.on('keyPressed', options, (event: KeyEvent) => {
    console.log(`Subscribe success ${JSON.stringify(event)}`);
  });
} catch (error) {
  console.log(`Subscribe execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputConsumer.off('keyPressed')<sup>16+</sup>

off(type: 'keyPressed', callback?: Callback&lt;KeyEvent&gt;): void

取消按键按下事件订阅。

**系统能力：** SystemCapability.MultimodalInput.Input.InputConsumer

**参数：**

| 参数名         | 类型                         | 必填   | 说明                              |
| ---------- | -------------------------- | ---- | ---------- |
| type       | string                     | 是    | 事件类型，固定取值为'keyPressed'。        |
| callback   | Callback&lt;[KeyEvent](./js-apis-keyevent.md#keyevent)&gt; | 否    | 需要取消订阅的回调函数。若不填，则取消当前已订阅的所有回调函数。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |
| 801 | Capability not supported. |

**示例：**

```js
try {
  // 取消指定回调函数
  inputConsumer.off('keyPressed', (event: KeyEvent) => {
    console.log(`Unsubscribe success ${JSON.stringify(event)}`);
  });
  // 取消当前已订阅的所有回调函数
  inputConsumer.off("keyPressed");
} catch (error) {
  console.log(`Unsubscribe execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```
