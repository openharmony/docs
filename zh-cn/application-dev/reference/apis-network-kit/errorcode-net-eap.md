# EAP错误码

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 33200001 无效的netId值

**错误信息**

invalid netId.

**错误描述**

不合法的net Id值

## 33200002 退出指定netId网卡扩展认证失败

**错误信息**

log off fail.

## 33200003 无效的eth eap配置

**错误信息**

invalid profile.

**错误描述**

不合法的eth eap配置

**可能原因**

profile配置存在错误

## 33200004 无效的eap结果值

**错误信息**

invalid custom result.

**错误描述**

不合法的eap result值

**可能原因**

传入的result值不属于CustomResult范围

## 33200005 无效的eap数据长度

**错误信息**

invalid size of eap data.

**错误描述**

不合法的eap 数据长度值

**可能原因**

传入的eap数据长度与EapData中的bufferLen不相等。

## 33200006 无效的网络类型

**错误信息**

invalid netType.

**错误描述**

网络类型不合法

**可能原因**

传入的网络类型不支持

**处理步骤**

传入支持的合法网络类型 WLAN: 1 ETH: 2。


## 33200007 无效的eapCode值

**错误信息**

invalid eapCode.

**错误描述**

eap code不合法。

**处理步骤**

eap code 合法范围是1，2，3，4


## 33200008 无效的eapType值

**错误信息**

Invalid eapType.

**错误描述**

eap type不合法。

**处理步骤**

传入合法的eap type范围 1~255

## 33200009 netmanager进程不存在

**错误描述**

netmanager进程停止.

**处理步骤**

重启机器

## 33200099 程序内部错误

**错误描述**

程序内部出现错误
