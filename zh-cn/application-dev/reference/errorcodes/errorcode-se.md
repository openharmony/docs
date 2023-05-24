# SE错误码

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](errorcode-universal.md)。

## 3100101

**错误信息**

Illegal service state exception.

**错误描述**

SEService服务状态异常

**可能原因**

1. SEService状态已断开

**处理步骤**

1. 重新执行打开或关闭SE服务。

    

## 3300102

**错误信息**

No such element exception.

**错误描述**

没有这样的SE异常

**可能原因**

1. 和SE服务建立通信异常。
2. SE芯片通信异常。

**处理步骤**

1. 重新执行打开或关闭SE。
2. 重启设备尝试。

## 3300103

**错误信息**

Illegal access rule exception.

**错误描述**

无法获取访问控制规则异常。

**可能原因**

1. 无可用的channel。

**处理步骤**

1. 释放已经连接的Channel。
2. 重启设备尝试。

## 3300104

**错误信息**

Secure element IO exception.

**错误描述**

SE芯片IO异常

**可能原因**

1. 和SE芯片通信异常。
2. SE芯片状态异常。

**处理步骤**

1. 重启设备尝试。

2. 重新执行打开或关闭SE。

    
