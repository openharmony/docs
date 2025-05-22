# 账号子系统Changelog

## cl.account.1 osAccount.distributedAccount.DistributedAccountAbility.getOsAccountDistributedInfo接口返回值生成规则变更

**访问级别**

公开接口

**变更原因**

原接口返回值生成规则与设计不符。

**变更影响**

此变更不涉及应用适配。

变更前：接口返回值中name、id、nickname、avatar 和 scalableData 生成规则与设计不符。

变更后：修正相关属性的生成规则，较变更前，同一分布式账号信息查询结果有差异。

**起始API Level**

API 9

**变更发生版本**

从 OpenHarmony SDK 5.1.0.56 开始

**变更的接口/组件**

[@ohos.account.distributedAccount.d.ts](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-basic-services-kit/js-apis-distributed-account.md)中如下接口:

- getOsAccountDistributedInfo(callback: AsyncCallback&lt;DistributedInfo&gt;): &lt;void&gt;
- getOsAccountDistributedInfo(): Promise&lt;DistributedInfo&gt;

**适配指导**

默认行为变更，无需适配。
