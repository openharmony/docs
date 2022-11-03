# 按键输入事件

KeyEvent模块提供了设备可以上报的按键事件。

>  **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import {Action, Key, KeyEvent} from '@ohos.multimodalInput.keyEvent';
```

## Action

**系统能力**：SystemCapability.MultimodalInput.Input.Core

| 名称   | 参数类型 | 可读 | 可写 | 描述     |
| ------ | -------- | ---- | ---- | -------- |
| CANCEL | number   | 是   | 否   | 取消按钮 |
| DOWN   | number   | 是   | 否   | 按下按钮 |
| UP     | number   | 是   | 否   | 抬起按钮 |

## Key

**系统能力**：SystemCapability.MultimodalInput.Input.Core

| 名称        | 参数类型 | 可读 | 可写 | 描述           |
| ----------- | -------- | ---- | ---- | -------------- |
| code        | KeyCode  | 是   | 否   | 按键码         |
| pressedTime | number   | 是   | 否   | 按下持续的时间 |
| deviceId    | number   | 是   | 否   | 按键所属设备   |

## KeyEvent

**系统能力**：SystemCapability.MultimodalInput.Input.Core

| 名称        | 参数类型 | 可读 | 可写 | 描述                           |
| ----------- | -------- | ---- | ---- | ------------------------------ |
| action      | Action   | 是   | 否   | 按键动作                       |
| key         | Key      | 是   | 否   | 当前发生变化的按键             |
| unicodeChar | number   | 是   | 否   | 按键对应的uniCode字符          |
| keys        | Key[]    | 是   | 否   | 当前处于按下状态的按键列表     |
| ctrlKey     | boolean  | 是   | 否   | 当前ctrlKey是否处于按下状态    |
| altKey      | boolean  | 是   | 否   | 当前altKey是否处于按下状态     |
| shiftKey    | boolean  | 是   | 否   | 当前shiftKey是否处于按下状态   |
| logoKey     | boolean  | 是   | 否   | 当前logoKey是否处于按下状态    |
| fnKey       | boolean  | 是   | 否   | 当前fnKey是否处于按下状态      |
| capsLock    | boolean  | 是   | 否   | 当前capsLock是否处于激活状态   |
| numLock     | boolean  | 是   | 否   | 当前numLock是否处于激活状态    |
| scrollLock  | boolean  | 是   | 否   | 当前scrollLock是否处于激活状态 |
