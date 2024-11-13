# 分布式数据管理系统键值型数据管理ChangeLog

OpenHarmony 5.0.0.22 版本相较于OpenHarmony 之前的版本，键值型数据管理的API变更如下。

## cl.kv_store.1 FieldNode类default字段的接口行为变更

FieldNode类的default字段定义为string类型，只能传入string类型。

**访问级别**

公开接口

**变更原因**

[FieldNode](../../../application-dev/reference/apis-arkdata/js-apis-distributedKVStore.md#fieldnode)类中的default字段定义为string类型，API12之前为空实现可传入任意类型不报错，API12修复Bug，传入非string类型数据会校验失败。

**变更影响**

该变更为不兼容变更。

变更前：FieldNode类中的default字段的定义为string类型，但底层是空实现，传入任意类型不报错。

变更后：Bug修复后，传入非法类型（非string类型），在创建数据库时会抛出异常。

**起始API Level**

9

**变更发生版本**

从OpenHarmony SDK 5.0.0.22开始。

**变更的接口/组件**

FieldNode类default字段/键值型数据管理（kv_store）

**适配指导**

在使用FieldNode类中的default字段时，传入string类型的值。