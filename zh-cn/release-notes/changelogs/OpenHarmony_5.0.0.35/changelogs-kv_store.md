# 分布式数据管理系统键值型数据管理ChangeLog

OpenHarmony 5.0.0.35 版本相较于OpenHarmony 之前的版本，键值型数据管理的API变更如下。

## cl.kv_store.1 FieldNode类default字段的接口行为变更。

FieldNode类的default字段定义为string类型，只能传入string类型。

**访问级别**

公开接口

**变更原因**

FieldNode类中的default字段定义为string类型，API12之前为空实现可传入任意类型不报错，2024年4月API12修复Bug,传入非string类型数据会校验失败。

**变更影响**

非兼容性变更，需要使用者进行适配。

变更前：FieldNode类中的default字段的定义为string类型，但底层是空实现，传入任意类型不报错。

变更后：Bug修复后，传入非法类型（非string类型），在创建数据库时会抛出异常。

**起始API Level**

9

**变更发生版本**

从OpenHarmony SDK 5.0.0.35开始。

**变更的接口/组件**

FieldNode类default字段/键值型数据管理（kv_store）

**适配指导**

在使用FieldNode类中的default字段时，传入string类型的值。


## cl.kv_store.2 BusinessError类code字段的接口行为变更。

BusinessError类中的code字段返回number类型。

**访问级别**

公开接口

**变更原因**

BusinessError类中的code字段定义为number类型，API12之前错误返回string类型，2024年2月API12修复Bug,修正为number类型。

**变更影响**

非兼容性变更，需要使用者进行适配。

变更前：BusinessError类中的code字段定义为number类型，实际返回string类型，应用判断的是字符串类型。

变更后：Bug修复后，code字段返回number类型。

**起始API Level**

9

**变更发生版本**

从OpenHarmony SDK 5.0.0.35开始。

**变更的接口/组件**

BusinessError类code字段/键值型数据管理（kv_store）

**适配指导**

BusinessError类code字段将会返回number类型的值，应用在判断时使用number类型做比较。