# ArkData子系统Changelog

## cl.arkdata.1 关系型数据管理@ohos.data.relationalStore.d.ts中getRdbStore加密方式变更返回错误码变更
**访问级别**

公开接口

**变更原因**

当前接口getRdbStore的config参数中加密参数（encrypt）如果和实际加密方式不一致会抛数据库损坏错误码（14800011），行为不正确。

**变更影响**

该变更为兼容性变更。

变更前：
关系型数据管理[@ohos.data.relationalStore.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.data.relationalStore.d.ts)中getRdbStore接口如果发生加密方式变更（从加密变非加密或者相反），会返回14800011。

变更后：
关系型数据管理[@ohos.data.relationalStore.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.data.relationalStore.d.ts)中getRdbStore接口如果发生加密方式变更（从加密变非加密或者相反），会按实际加密方式打开。


**起始API Level**

API 9

**变更发生版本**

从OpenHarmony 5.0.1.1 版本开始。

**变更的接口/组件**

[@ohos.data.relationalStore.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.data.relationalStore.d.ts)中如下接口：

1. function getRdbStore(context: Context, config: StoreConfig, callback: AsyncCallback\<RdbStore\>): void;

2. function getRdbStore(context: Context, config: StoreConfig): Promise\<RdbStore\>;

**适配指导**

无需适配