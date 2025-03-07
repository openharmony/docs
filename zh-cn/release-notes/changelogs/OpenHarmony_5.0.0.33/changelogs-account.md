# 账号子系统Changelog

## cl.account_os_account.1. queryDistributedVirtualDeviceld错误码实现变更

**访问级别**

公开接口

**变更原因**

按照JS错误码规范要求，当权限不足时，接口返回201错误码（与设计保持一致）。当前权限不足也是返回12300001系统异常，开发者无法区分权限不足和系统异常。

**变更影响**

该变更为不兼容变更。

变更前：在未申请权限时调用queryDistributedVirtualDeviceld接口，返回错误码：12300001

变更后：在未申请权限时调用queryDistributedVirtualDeviceld接口，返回错误码：201

**起始API Level**

API 9

**变更发生版本**

从OpenHarmony SDK 5.0.0.33开始。

**变更的接口/组件**

变更的接口：queryDistributedVirtualDeviceld

**适配指导**

该变更为权限失败场景，开发时遇到该问题即可感知，在开发过程中无需特殊适配。
