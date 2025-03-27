# @ohos.bluetooth.constant (蓝牙constant模块)(系统接口)

constant模块提供了蓝牙中常量的定义。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.bluetooth.constant (蓝牙constant模块)](js-apis-bluetooth-constant.md)。

## 导入模块

```js
import { constant } from '@kit.ConnectivityKit';
```

## AccessAuthorization<sup>11+</sup>

枚举，访问权限。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称                 | 值  | 说明     |
| ------------------ | ---- | ------ |
| UNKNOWN<sup>11+</sup> | 0    | 未知。<br/>此接口为系统接口。  |
| ALLOWED<sup>11+</sup> | 1    | 允许。<br/>此接口为系统接口。  |
| REJECTED<sup>11+</sup> | 2    | 拒绝。<br/>此接口为系统接口。 |