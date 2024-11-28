# @ohos.net.ethernet (以太网连接管理)

以太网连接管理主要提供有线网络能力，提供获取有线网络的IP地址等信息。

> **说明：**
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { ethernet } from '@kit.NetworkKit';
```

## HttpProxy

type HttpProxy = connection.HttpProxy;

网络代理配置信息。

**系统能力**：SystemCapability.Communication.NetManager.Ethernet

| 类型 | 说明                                       |
| ------- | ----------------------------------------|
| connection.HttpProxy     | 网络代理配置信息。      |