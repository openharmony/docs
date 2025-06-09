# Account Subsystem Changelog

## cl.account.1 Change in the osAccount.distributedAccount.DistributedAccountAbility.getOsAccountDistributedInfo Return Value Generation Rules

**Access Level**

Public API

**Reason for the Change**

The return value generation rules of the API do not comply with the design specification.

**Change Impact**

This change does not require application adaptation.

Before change: The generation rules of **name**, **id**, **nickname**, **avatar**, and **scalableData** do not comply with the design specification.

After change: The generation rules of these attributes are corrected. The queries for the same distributed account data return different results than before.

**Start API Level**

API 9

**Change Since**

OpenHarmony SDK 5.1.0.56

**Key API/Component Changes**

The following APIs in [@ohos.account.distributedAccount.d.ts](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-basic-services-kit/js-apis-distributed-account.md):

- getOsAccountDistributedInfo(callback: AsyncCallback&lt;DistributedInfo&gt;): &lt;void&gt;
- getOsAccountDistributedInfo(): Promise&lt;DistributedInfo&gt;

**Adaptation Guide**

No adaptation is required.
