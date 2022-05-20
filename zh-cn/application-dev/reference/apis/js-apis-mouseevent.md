# MouseEvent

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import MouseEvent from '@ohos.multimodalInput.mouseEvent'
```

## 属性

**系统能力**：以下各项对应的系统能力均为SystemCapability.MultimodalInput.Input.Core。

| 名称 | 参数类型 | 可读 | 可写 | 描述 |
| -------- | -------- | -------- | -------- | -------- |
| action | Action | 是 | 否 | 设备类型。 |
| screenX | string | 是 | 否 | 设备厂家名称。 |
| screenY | string | 是 | 否 | 设备品牌名称。 |
| windowX | string | 是 | 否 | 外部产品系列。 |
| windowY | string | 是 | 否 | 产品系列。 |
| rawDeltaX | string | 是 | 否 | 认证型号。 |
| rawDeltaY | string | 是 | 否 | 内部软件子型号。 |
| button | string | 是 | 否 | 硬件版本号。 |
| pressedButtons | string | 是 | 否 | 硬件Profile。 |
| axes | string | 是 | 否 | 设备序列号。 |
| pressedKeys | string | 是 | 否 | Bootloader版本号。 |
| ctrlKey | string | 是 | 否 | 应用二进制接口（Abi）列表。 |
| altKey | string | 是 | 否 | 安全补丁级别。 |
| shiftKey | string | 是 | 否 | 产品版本。 |
| logoKey | string | 是 | 否 | 差异版本号。 |
| fnKey | string | 是 | 否 | 系统的发布类型，取值为：<br/>-&nbsp;Canary：面向特定开发者发布的早期预览版本，不承诺API稳定性。<br/>-&nbsp;Beta：面向开发者公开发布的Beta版本，不承诺API稳定性。<br/>-&nbsp;Release：面向开发者公开发布的正式版本，承诺API稳定性。 |
| capsLock | string | 是 | 否 | 系统版本。 |
| numLock | number | 是 | 否 | Major版本号，随主版本更新增加。 |
| scrollLock | number | 是 | 否 | Senior版本号，随局部架构、重大特性增加。 |

# Action

鼠标事件类型。

## 导入模块

```ts
import Action from '@ohos.multimodalInput.mouseEvent'
```

## 属性

**系统能力**：以下各项对应的系统能力均为SystemCapability.MultimodalInput.Input.Core。

| 名称 | 参数类型 | 可读 | 可写 | 描述 |
| -------- | -------- | -------- | -------- | -------- |
| CANCEL | number | 是 | 否 | 取消事件。 |
| MOVE | number | 是 | 否 | 移动事件。 |
| BUTTON_DOWN | number | 是 | 否 | 按下事件。 |
| BUTTON_UP | number | 是 | 否 | 抬起事件。 |
| AXIS_BEGIN | number | 是 | 否 | 鼠标关联轴事件开始。 |
| AXIS_UPDATE | number | 是 | 否 | 鼠标关联轴事件更新。 |
| AXIS_END | number | 是 | 否 | 鼠标关联轴事件结束。 |

# Button

鼠标按键类型。

## 导入模块

```ts
import Button from '@ohos.multimodalInput.mouseEvent'
```

## 属性

**系统能力**：以下各项对应的系统能力均为SystemCapability.MultimodalInput.Input.Core。

| 名称    | 参数类型 | 可读 | 可写 | 描述           |
| ------- | -------- | ---- | ---- | -------------- |
| LEFT    | number   | 是   | 否   | 鼠标左键。     |
| MIDDLE  | number   | 是   | 否   | 鼠标中键。     |
| RIGHT   | number   | 是   | 否   | 鼠标右键。     |
| SIDE    | number   | 是   | 否   | 鼠标side键。   |
| EXTRA   | number   | 是   | 否   | 鼠标extra键。  |
| FORWARD | number   | 是   | 否   | 鼠标前进键。   |
| BACK    | number   | 是   | 否   | 鼠标后退键。   |
| TASK    | number   | 是   | 否   | 鼠标自定义键。 |

# Axis

鼠标轴类型。

## 导入模块

```ts
import Axis from '@ohos.multimodalInput.mouseEvent'
```

## 属性

**系统能力**：以下各项对应的系统能力均为SystemCapability.MultimodalInput.Input.Core。

| 名称              | 参数类型 | 可读 | 可写 | 描述         |
| ----------------- | -------- | ---- | ---- | ------------ |
| SCROLL_VERTICAL   | number   | 是   | 否   | 鼠标垂直轴。 |
| SCROLL_HORIZONTAL | number   | 是   | 否   | 鼠标水平轴   |
| PINCH             | number   | 是   | 否   | 鼠标捏合轴。 |

# AxisValue

鼠标轴数据。

## 导入模块

```ts
import AxisValue from '@ohos.multimodalInput.mouseEvent'
```

## 属性

**系统能力**：以下各项对应的系统能力均为SystemCapability.MultimodalInput.Input.Core。

| 名称  | 参数类型 | 可读 | 可写 | 描述         |
| ----- | -------- | ---- | ---- | ------------ |
| axis  | Axis     | 是   | 是   | 鼠标轴类型   |
| value | number   | 是   | 是   | 鼠标轴的值。 |