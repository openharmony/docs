# @ohos.multimodalInput.keyEvent (按键输入事件)

设备上报的按键事件，继承自[InputEvent](js-apis-inputevent.md)。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import { Action, Key, KeyEvent } from '@kit.InputKit';
```

## Action

按键事件类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

| 名称   | 值  | 说明     |
| ------ | ------- | -------- |
| CANCEL | 0    | 按键取消。 |
| DOWN   | 1    | 按键按下。 |
| UP     | 2    | 按键抬起。 |

## Key

按键。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

| 名称        | 类型 | 只读 | 可选 | 说明           |
| ----------- | -------- | ---- | ---- | -------------- |
| code        | [KeyCode](js-apis-keycode.md#keycode)  | 否   | 否   | 按键码。         |
| pressedTime | number   | 否   | 否   | 按键按下时间，单位为微秒（μs）。 |
| deviceId    | number   | 否   | 否   | 按键所属设备id。   |

## KeyEvent

按键事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

| 名称        | 类型 | 只读 | 可选 | 说明                           |
| ----------- | -------- | ---- | ---- | ------------------------------ |
| action      | [Action](#action)   | 否   | 否   | 按键动作。                       |
| key         | [Key](#key)      | 否   | 否   | 当前上报的按键。             |
| unicodeChar | number   | 否   | 否   | 按键对应的uniCode字符。          |
| keys        | [Key](#key) []    | 否   | 否   | 当前处于按下状态的按键列表。     |
| ctrlKey     | boolean  | 否   | 否   | 当前ctrlKey是否处于按下状态。 <br/>true表示处于按下状态，false表示处于抬起状态。 |
| altKey      | boolean  | 否   | 否   | 当前altKey是否处于按下状态。 <br/>true表示处于按下状态，false表示处于抬起状态。     |
| shiftKey    | boolean  | 否   | 否   | 当前shiftKey是否处于按下状态。 <br/>true表示处于按下状态，false表示处于抬起状态。   |
| logoKey     | boolean  | 否   | 否   | 当前logoKey是否处于按下状态。 <br/>true表示处于按下状态，false表示处于抬起状态。    |
| fnKey       | boolean  | 否   | 否   | 当前fnKey是否处于按下状态。 <br/>true表示处于按下状态，false表示处于抬起状态。      |
| capsLock    | boolean  | 否   | 否   | 当前capsLock是否处于激活状态。 <br/>true表示处于激活状态，false表示处于未激活状态。   |
| numLock     | boolean  | 否   | 否   | 当前numLock是否处于激活状态。 <br/>true表示处于激活状态，false表示处于未激活状态。    |
| scrollLock  | boolean  | 否   | 否   | 当前scrollLock是否处于激活状态。 <br/>true表示处于激活状态，false表示处于未激活状态。 |
