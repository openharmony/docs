# 屏幕亮度

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

该模块提供屏幕亮度的设置接口。


## 导入模块

```js
import brightness from '@ohos.brightness';
```

## brightness.setValue

setValue(value: number): void

设置系统的屏幕亮度。

此接口为系统接口，三方应用不支持调用。

**系统能力：** SystemCapability.PowerManager.DisplayPowerManager

**参数：**

| 参数名   | 类型     | 必填   | 说明          |
| ----- | ------ | ---- | ----------- |
| value | number | 是    | 亮度的值（0~255） |

**示例：**

```js
brightness.setValue(128);
```
