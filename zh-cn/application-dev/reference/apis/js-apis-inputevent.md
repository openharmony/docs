# 输入事件

设备上报的基本事件。

>  **说明：**
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import InputEvent from '@ohos.multimodalInput.inputEvent';
```

## InputEvent 

**系统能力**：SystemCapability.MultimodalInput.Input.Core

| 名称         | 参数类型   | 可读   | 可写   | 描述             |
| ---------- | ------ | ---- | ---- | -------------- |
| id         | number | 是    | 否    | 事件id |
| deviceId   | number | 是    | 否    | 上报输入事件的设备id    |
| actionTime | number | 是    | 否    | 输入事件的上报时间      |
| screenId   | number | 是    | 否    | 目标屏幕id         |
| windowId   | number | 是    | 否    | 目标窗口id         |