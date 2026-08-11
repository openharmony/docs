# 扩展认证错误码


<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码](../errorcode-universal.md)说明文档。

## 33200001 无效的netId值

**错误信息**

Invalid netId.

**错误描述**

不合法的net Id值。

**可能原因**

net Id值不存在。

**处理步骤**

输入一个合法的net ID值。

## 33200002 退出指定netId网卡扩展认证失败

**错误信息**

log off fail.

**错误描述**

退出指定的net Id的扩展认证失败。

**可能原因**

net Id值不存在。

**处理步骤**

输入一个合法的net ID值。

## 33200003 无效的eth eap配置

**错误信息**

Invalid profile.

**错误描述**

不合法的eth eap配置。

**可能原因**

profile值配置错误。

**处理步骤**

配置正确的profile值。

## 33200004 无效的eap结果值

**错误信息**

Invalid result.

**错误描述**

不合法的eap result值。

**可能原因**

传入的result值不属于CustomResult范围。

**处理步骤**

属于类型CustomResult的值。

## 33200005 无效的eap数据长度

**错误信息**

Invalid size of eap data.

**错误描述**

不合法的EAP数据长度值。

**可能原因**

传入的EAP数据长度与EapData中的bufferLen不相等。

**处理步骤**

确保bufferLen参数与EAP数据长度一致。

## 33200006 无效的网络类型

**错误信息**

Invalid net type.

**错误描述**

网络类型不合法。

**可能原因**

传入的网络类型不支持。

**处理步骤**

传入支持的合法网络类型：WLAN：1；ETH：2。


## 33200007 无效的eapCode值

**错误信息**

Invalid eap code.

**错误描述**

eap code不合法。

**可能原因**

传入的参数不在合理取值范围。

**处理步骤**

eap code的合法取值为1、2、3、4。

## 33200008 无效的eapType值

**错误信息**

Invalid eap type.

**错误描述**

eap type不合法。

**可能原因**

传入的参数不在合理取值范围。

**处理步骤**

传入合法的eap type，取值范围为[1, 255]。

## 33200009 netmanager进程不存在

**错误信息**

netmanager stop.

**错误描述**

netmanager进程不存在。

**可能原因**

系统netmanager进程问题。

**处理步骤**

重启机器。

## 33200010 无效的eap状态

**错误信息**

Invalid eth state.

**错误描述**

无效的eth状态。

**可能原因**

以太网卡工作状态异常。

**处理步骤**

可尝试插拔有线网重试。

## 33200099 程序内部错误

**错误信息**

internal error.

**错误描述**

程序内部出现错误。

**可能原因**

1.EAP报文处理异常，如报文解析失败、数据格式错误，通过日志关键词过滤wpa_supplicant:EAP进行定位分析。

2.认证流程异常，如状态机错误、认证超时未响应，通过日志关键词过滤entering state进行定位分析。

3.证书处理失败，如证书加载失败、证书解析错误、密钥操作失败，通过日志关键词过滤wpa_supplicant:SSL进行定位分析。

4.回调函数异常，如回调未正确实现或抛出未捕获异常，通过日志关键词过滤replyCustomEapData进行定位分析。

5.通信失败，如socket通信异常、连接断开。此原因常见于[startEthEap](js-apis-net-eap.md#eapstartetheap)和[logOffEthEap](js-apis-net-eap.md#eaplogoffetheap)接口，通过日志关键词过滤startEap或stopEap检查命令是否正常下发。

**处理步骤**

1.查看系统日志定位具体异常原因，通过日志关键词过滤supplicant定位EAP报文处理异常，通过日志关键词过滤replyCustomEapData定位回调函数异常；对于[startEthEap](js-apis-net-eap.md#eapstartetheap)和[logOffEthEap](js-apis-net-eap.md#eaplogoffetheap)接口触发的通信异常，可通过日志关键词过滤startEap或stopEap进行定位。

2.确认EAP认证流程调用顺序正确，避免在未完成上一步操作时进行下一步操作。

3.检查证书和密钥配置是否正确，确保证书格式符合要求。

4.确认回调函数在注销前未被重复注销，且在注册后正常使用。

5.若问题持续存在，请重启设备后重试。

