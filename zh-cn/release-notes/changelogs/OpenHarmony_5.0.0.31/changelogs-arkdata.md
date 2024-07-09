# ArkData方舟数据管理变更说明

## cl.ArkData.1 Asset属性类型变更

**访问级别**

公开接口

**变更原因**

Asset的属性在OpenHarmony 5.0 Beta1阶段增加了undefined类型，破坏了Asset的通用性。

**变更影响**

该变更为不兼容变更。Asset的属性去掉了undefined对类型的支持。

如果已经按照OpenHarmony 5.0 Beta1的方法使用了undefined类型，则会由于类型不匹配，导致代码编译失败。

**起始 API Level**

11

**变更发生版本**

从OpenHarmony SDK 5.0.0.31开始。

**变更的接口/组件**

Asset/数据通用类型（commonType）

**适配指导**

对于已按照OpenHarmony 5.0 Beta1版本的方法在Asset属性使用undefined类型的应用工程，必须改为空字符串来解决数据覆盖问题。

对于其他使用Asset属性的应用工程，建议设置空字符串来解决数据覆盖问题。

## cl.ArkData.2 setSessionId接口行为变更

**访问级别**

公开接口

**变更原因**

分布式数据对象的同步数据时，会尝试同步与同账号网络中的所有设备建立链接，并进行数据同步。但实际上组网中的其他设备未必创建了分布式数据对象，它们不需要同步数据。所以可能产生无效的数据同步，浪费系统资源。

**变更影响**

该变更为不兼容变更。现在分布式数据对象只会和处于[跨端迁移](../../../application-dev/application-models/hop-cross-device-migration.md)或[多端协同](../../../application-dev/application-models/hop-multi-device-collaboration.md)的对端设备进行数据同步。未适配跨端迁移或多端协同的应用，使用分布式数据对象，数据不会自动同步。

**起始 API Level**

9

**变更发生版本**

从OpenHarmony SDK 5.0.0.31开始。

**变更的接口/组件**

setSessionId/分布式数据对象（data_object）

**适配指导**

详见分布式数据对象开发指南中的[在跨端迁移中使用分布式数据对象迁移数据](../../../application-dev/database/data-sync-of-distributed-data-object.md#在跨端迁移中使用分布式数据对象迁移数据)和[在多端协同中使用分布式数据对象](../../../application-dev/database/data-sync-of-distributed-data-object.md#在多端协同中使用分布式数据对象)示例代码。
