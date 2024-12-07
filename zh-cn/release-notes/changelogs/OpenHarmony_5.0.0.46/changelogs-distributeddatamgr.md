# 分布式数据管理子系统Changelog

## cl.relationalStore.1 getRow、getValue 接口行为变更

**访问级别**

公开接口

**变更原因**

当插入列类型是blob且数据为长度为0的Uint8Array时，数据库对应错误写入null值，导致使用getRow和getValue接口读取时，读取数值结果错误与插入数据不匹配。为修复bug，引入此行为变更。

**变更影响**

该变更为不兼容性变更。
变更前：在blob类型的列里插入长度为0的Uint8Array，调用getRow/getValue接口，获取到的值是null。
变更后：在blob类型的列里插入长度为0的Uint8Array，调用getRow/getValue接口，获取到的值是长度为0的Uint8Array。

**起始 API Level**

| 接口名称  | 起始 API Level |
|----------|--------------|
| getRow   | API 11       |
| getValue | API 12       |

**变更发生版本**

从OpenHarmony SDK 5.0.0.46版本开始。

**变更的接口/组件**

@ohos.data.relationalStore.d.ts中getRow接口。
@ohos.data.relationalStore.d.ts中getValue接口。

**适配指导**

变更后，接口的调用方式没有发生变化。开发者需要关注，在blob类型的列里插入长度为0的Uint8Array后，调用getRow或getValue获取到的值发生了变化。
