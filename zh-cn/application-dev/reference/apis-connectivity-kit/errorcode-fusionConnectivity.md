# 融合短距服务子系统错误码

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @enjoy_sunshine-->
<!--Designer: @tangjia15-->
<!--Tester: @wangfeng517-->
<!--Adviser: @zhang_yixin13-->

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 34900001 设备未注册

**错误信息**

The device is not bound.

**错误描述**

该设备未注册。

**可能原因**

应用未调用[bindDevice](js-apis-fusionConnectivity-partnerAgent.md#partneragentbinddevice)注册设备。

**处理步骤**

应用调用[bindDevice](js-apis-fusionConnectivity-partnerAgent.md#partneragentbinddevice)注册设备。

## 34900003 设备未配对

**错误信息**

The device is not paired.

**错误描述**

设备未配对。

**可能原因**

应用注册的设备未经过蓝牙配对。

**处理步骤**

执行设备蓝牙配对流程。

## 34900004 设备地址已被注册

**错误信息**

The device address has already been bound with PartnerAgentExtensionAbility.

**错误描述**

该设备地址已经注册过[PartnerAgentExtensionAbility](js-apis-fusionConnectivity-partnerAgentExtensionAbility.md)。

**可能原因**

应用重复注册一个地址。

**处理步骤**

应用调用[unbindDevice](js-apis-fusionConnectivity-partnerAgent.md#partneragentunbinddevice)解注册当前设备，再重新注册[bindDevice](js-apis-fusionConnectivity-partnerAgent.md#partneragentbinddevice)新的Ability。

## 34900005 蓝牙关闭

**错误信息**

Bluetooth disabled.

**错误描述**

蓝牙关闭。

**可能原因**

蓝牙处于关闭状态。

**处理步骤**

打开蓝牙。

## 34900050 该设备未发起测距

**错误信息**

The device has not initiated ranging.

**错误描述**

该设备未发起测距。

**可能原因**

该设备未发起测距，例如：在未调用[startRanging](js-apis-fusionConnectivity-ranging.md#rangingstartranging)的情况下直接调用[stopRanging](js-apis-fusionConnectivity-ranging.md#rangingstopranging)。

**处理步骤**

建议先调用[startRanging](js-apis-fusionConnectivity-ranging.md#rangingstartranging)发起测距后再进行后续操作。

## 34900051 该设备已发起测距

**错误信息**

The device has already initiated ranging.

**错误描述**

该设备已发起测距。

**可能原因**

该设备已发起测距，例如：对同一设备重复调用[startRanging](js-apis-fusionConnectivity-ranging.md#rangingstartranging)而未先调用[stopRanging](js-apis-fusionConnectivity-ranging.md#rangingstopranging)停止之前的测距。

**处理步骤**

建议不要在已经发起测距后重复发起，可以先调用[stopRanging](js-apis-fusionConnectivity-ranging.md#rangingstopranging)结束测距后再重新调用[startRanging](js-apis-fusionConnectivity-ranging.md#rangingstartranging)发起测距。

## 34900052 不支持指定类型的测距服务

**错误信息**

The specified type of ranging service is not supported.

**错误描述**

不支持指定类型的测距服务。

**可能原因**

不支持指定类型的测距服务，例如：传入的测距类型枚举值不在规定范围内，或指定的测距类型在本设备上不支持。

**处理步骤**

该类型服务并不支持测距，请参考[RangingTypes](js-apis-fusionConnectivity-ranging.md#rangingtypes)使用有效的测距类型。

## 34900053 测距服务关闭

**错误信息**

The ranging service is disabled.

**错误描述**

测距服务关闭。

**可能原因**

测距服务关闭，例如：测距服务未使能或已被关闭，无法发起测距操作。

**处理步骤**

建议用户打开服务后再发起测距。

## 34900054 参数不符合业务规格

**错误信息**

The parameter value does not meet specifications.

**错误描述**

参数不符合业务规格。

**可能原因**

参数不符合业务规格：比如设备ID不符合xx:xx:xx:xx:xx:xx（十六进制）的格式。

**处理步骤**

检视入参是否符合业务要求。

## 34900099 操作失败

**错误信息**

Operation failed.

**错误描述**

操作失败。

**可能原因**

因系统原因导致当前操作失败。

**处理步骤**

请重试该操作。