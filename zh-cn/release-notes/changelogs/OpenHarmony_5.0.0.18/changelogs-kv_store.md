# 分布式数据管理系统键值型数据管理ChangeLog

OpenHarmony 5.0.0.18 版本相较于OpenHarmony 之前的版本，键值型数据管理的API变更如下。

## cl.kv_store.1 BusinessError类code字段的接口行为变更

BusinessError类中的code字段返回number类型。

**访问级别**

公开接口

**变更原因**

BusinessError类中的code字段定义为number类型，API12之前错误返回string类型，API12修复Bug，修正为number类型。

**变更影响**

该变更为不兼容变更。

变更前：BusinessError类中的code字段定义为number类型，实际返回string类型，应用判断的是字符串类型。

变更后：Bug修复后，code字段返回number类型。

**起始API Level**

9

**变更发生版本**

从OpenHarmony SDK 5.0.0.18开始。

**变更的接口/组件**

BusinessError类code字段/键值型数据管理（kv_store）

**适配指导**

BusinessError类code字段将会返回number类型的值，应用需要使用number类型进行判断。