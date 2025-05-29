# ArkData Changelog

## cl.arkdata.1 Change in the Return Value When the Encryption Mode Is Changed in getRdbStore in @ohos.data.relationalStore.d.ts
**Access Level**

Public API

**Reason for the Change**

If the value of **encrypt** contained in the **config** parameter of **getRdbStore()** does not match the actual encryption mode, error 14800011 will be returned, which does not indicate the actual error.

**Change Impact**

This change is a compatible change.

Before the change: 
If the encryption mode in **getRdbStore()** in [@ohos.data.relationalStore.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.data.relationalStore.d.ts) is changed, error 14800011 is returned.

After the change:
If the encryption mode in **getRdbStore()** in [@ohos.data.relationalStore.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.data.relationalStore.d.ts) is changed, the RDB store will be opened in the specified encryption mode.


**Start API Level**

API 9

**Change Since**

OpenHarmony 5.0.1.1

**Key API/Component Changes**

The following APIs in [@ohos.data.relationalStore.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.data.relationalStore.d.ts):

1. function getRdbStore(context: Context, config: StoreConfig, callback: AsyncCallback\<RdbStore\>): void;

2. function getRdbStore(context: Context, config: StoreConfig): Promise\<RdbStore\>;

**Adaptation Guide**

No adaptation is required.
