# 分布式数据管理子系统ChangeLog

## cl.distributeddatamgr.1 RelationalStore execute，executeSync接口执行不合法SQL语句错误码变更

**访问级别**

公开接口

**变更原因**

提升该场景接口错误码准确性，提升开发者问题定位效率。

**变更影响**

该变更为不兼容变更。

变更前：执行不合法的SQL语句，报错的error对象code值为14800000。

变更后：执行不合法的SQL语句，报错的error对象code值为14800021。

**起始 API Level**

12

**变更发生版本**

从OpenHarmony SDK 5.0.0.38开始。

**变更的接口/组件**

|               场景               |      变更前      |      变更后      |
| :------------------------------: | :--------------: | :--------------: |
|   execute接口执行不合法SQL语句   | 错误码为14800000 | 错误码为14800021 |
| executeSync接口执行不合法SQL语句 | 错误码为14800000 | 错误码为14800021 |

**适配指导**

在调用execute，executeSync接口执行SQL语句场景，如使用14800000错误码作为判定条件，需要将对应判定条件错误码修改为14800021。

修改前execute接口执行SQL语句报错错误码：

```ts
try {
    await rdbStore.execute("COMMIT");
} catch (err) {
    if (err.code === 14800000) {
        console.log(`execute failed, code: ${err.code}`);
    }
}
```

修改后execute接口执行SQL语句报错错误码：

```ts
try {
    await rdbStore.execute("COMMIT");
} catch (err) {
    if (err.code === 14800021) {
        console.log(`execute failed, code: ${err.code}`);
    }
}
```

修改前executeSync接口执行SQL语句报错错误码：

```ts
try {
    await rdbStore.executeSync("COMMIT");
} catch (err) {
    if (err.code === 14800000) {
        console.log(`execute failed, code: ${err.code}`);
    }
}
```

修改后executeSync接口执行SQL语句报错错误码：

```ts
try {
    await rdbStore.executeSync("COMMIT");
} catch (err) {
    if (err.code === 14800021) {
        console.log(`execute failed, code: ${err.code}`);
    }
}
```
