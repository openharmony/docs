# 分布式数据对象变更说明

## c1.data_object.1 setSessionId行为变更

**访问级别**

公开接口

**变更原因**

解决无效数据同步问题。

**变更影响**

该变更为不兼容变更。在跨端迁移开发场景中，发起端分布式数据对象调用setSessionId接口后，数据不会自动同步到接收端。

**起始 API Level**

9

**变更发生版本**

从OpenHarmony SDK 5.0.0.21开始。

**变更的接口/组件**

setSessionId/分布式数据对象（data_object）

**适配指导**

在跨端迁移开发场景中，发起端分布式数据对象调用setSessionId接口后，再调用save接口保存数据到接收端。

```ts
let dataObject = distributedDataObject.create(context, source);
dataObject.setSessionId(sessionId);
dataObject.save(wantParam.targetDevice as string); // 调用save接口保存数据到接收端
```

详见[在跨端迁移中使用分布式数据对象迁移数据](../../../application-dev/database/data-sync-of-distributed-data-object.md#在跨端迁移中使用分布式数据对象迁移数据)。
