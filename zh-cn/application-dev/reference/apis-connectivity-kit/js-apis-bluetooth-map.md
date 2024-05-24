# @ohos.bluetooth.map (蓝牙map模块)

map模块提供了访问信息相关功能的方法。

> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。



## 导入模块

```js
import { map } from '@kit.ConnectivityKit';
```


## map.createMapMseProfile

createMapMseProfile(): MapMseProfile

创建mapMse profile实例。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**返回值：**

| 类型                            | 说明         |
| ----------------------------- | ---------- |
| MapMseProfile | 返回该profile的实例。 |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    let mapMseProfile = map.createMapMseProfile();
    console.info('MapMse success');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## mapMseProfile

使用mapMseProfile方法之前需要创建该类的实例进行操作，通过createMapMseProfile()方法构造此实例。
