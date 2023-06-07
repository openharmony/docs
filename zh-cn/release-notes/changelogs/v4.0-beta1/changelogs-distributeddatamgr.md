# 分布式数据管理子系统JS API变更Changelog

## cl.distributeddatamgr.1 接口变更
distributeddatamgr子系统relationalStore组件接口存在变更：

变更前：
应用调用getRdbStore接口后，通过返回对象rdbStore的openStatus属性（openStatus == ON_CREATE）判断数据库是否为新创建。
变更后：
应用调用getRdbStore接口后，通过返回对象rdbStore的version属性（version == 0）判断数据库是否为新创建。

开发者需要根据以下说明对应用进行适配。

 **变更影响**

影响API10版本的JS接口，应用需要进行适配才可以在新版本SDK环境正常实现功能。

**关键的接口/组件变更**

| 模块名                             | 类名             | 方法/属性/枚举/常量 | 变更类型 |
| ------------------------------    | --------------- | ---------------- | ------- |
| @ohos.data.relationalStore        | RdbStore        | openStatus: number; 改为 version: number; |  变更   |


**适配指导**

应用中设置和获取数据库版本可参考下列代码：

```ts
const STORE_CONFIG = {
    name: "rdbstore.db",
    securityLevel: data_rdb.SecurityLevel.S1
}
data_rdb.getRdbStore(this.context, STORE_CONFIG, function (err, rdbStore) {
    // 变更前：
    // if (rdbStore.openStatus == ON_CREATE) {
    //     rdbStore.executeSql("CREATE TABLE IF NOT EXISTS student (id INTEGER PRIMARY KEY AUTOINCREMENT, score REAL);", null) // create table xxx
    // }
    
    // 变更后：
    if (rdbStore.version == 0) {
        rdbStore.executeSql("CREATE TABLE IF NOT EXISTS student (id INTEGER PRIMARY KEY AUTOINCREMENT, score REAL);", null) // create table xxx
        // 设置数据库版本，值为大于0的正整数
        rdbStore.version == 3
    }
    // 获取数据库版本
    console.info("Get RdbStore version is " + rdbStore.version)
})
```