# @ohos.bluetooth.hid (蓝牙hid模块)

hid模块提供了访问蓝牙hid相关功能的方法。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。



## 导入模块

```js
import hid from '@ohos.bluetooth.hid';
```


## hid.createHidHostProfile

createHidHostProfile(): HidHostProfile

创建hid profile实例。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**返回值：**

| 类型                            | 说明         |
| ----------------------------- | ---------- |
| HidHostProfile | 返回该profile的实例。 |

**示例：**

```js
import { BusinessError } from '@ohos.base';
try {
    let hidHostProfile = hid.createHidHostProfile();
    console.info('hidHost success');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

