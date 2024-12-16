# @ohos.net.sharing (网络共享管理)

网络共享管理分享设备已有网络给其他连接设备。

> **说明：**
>
> 本模块首批接口从 API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```js
import { sharing } from '@kit.NetworkKit';
```

## NetHandle

type NetHandle = connection.NetHandle

数据网络的句柄。在调用NetHandle的方法之前，需要先获取NetHandle对象。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| [connection.NetHandle](./js-apis-net-connection.md#nethandle) | 网络链路信息 |



