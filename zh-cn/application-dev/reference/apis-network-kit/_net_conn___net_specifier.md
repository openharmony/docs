# NetConn_NetSpecifier

## 概述

网络的特征集，包含网络的能力集与网络的标识符。

**起始版本：** 12

**相关模块：**[NetConnection](_net_connection.md)


## 汇总


### 成员变量

| 名称 | 描述 |
| -------- | -------- |
| [caps](#caps) | 网络能力集。 |
| [bearerPrivateIdentifier](#bearerprivateidentifier) | 网络标识符。 |


## 结构体成员变量说明


### caps

```
NetConn_NetCapabilities NetConn_NetSpecifier::caps
```

**描述**

网络能力集。


### bearerPrivateIdentifier

```
char* NetConn_NetSpecifier::bearerPrivateIdentifier
```

**描述**

网络标识符。
