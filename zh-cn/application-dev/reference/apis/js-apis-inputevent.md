# InputEvent

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```ts
import InputEvent from '@ohos.multimodalInput.inputEvent';
```

## 属性

**系统能力**：以下各项对应的系统能力均为SystemCapability.MultimodalInput.Input.Core


| 名称 | 参数类型 | 可读 | 可写 | 描述 |
| -------- | -------- | -------- | -------- | -------- |
| id | number | 是 | 否 | 由服务端生成全局唯一事件id |
| deviceId | number | 是 | 否 | 上报输入事件的设备id |
| actionTime | number | 是 | 否 | 事件发生时间 |
| screenId | number | 是 | 否 | 目标屏幕id |
| windowId | number | 是 | 否 | 目标窗口id |