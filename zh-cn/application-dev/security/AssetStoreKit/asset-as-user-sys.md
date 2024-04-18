# 指定用户空间进行关键资产操作(仅对系统应用开放)

对于提供了系统级管理功能的单实例应用，一般场景下，所有用户共用一个实例，该实例负责实现不同用户的数据隔离。

1. 当同时有多个用户处于活跃状态时，单实例应用如果需要为不同用户存储、访问、销毁关键资产，则需要准确告知所操作的关键资产所属的用户空间。
2. 单实例应用需要存储“首次解锁后可访问”、“解锁状态时可访问”类型的关键资产时，需要指定关键资产所属的用户空间。

为了支持上述场景中单实例应用的关键资产数据隔离和访问控制，ASSET提供了一套可以指定用户空间进行关键资产操作的接口（仅面向系统应用）。

## 约束与限制

- 使用接口需要申请权限：ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS。申请流程请参考：[申请应用权限]（https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/security/AccessToken/determine-application-mode.md#system_basic%E7%AD%89%E7%BA%A7%E7%9A%84%E5%BA%94%E7%94%A8%E7%94%B3%E8%AF%B7%E6%9D%83%E9%99%90）

# 接口介绍

可通过API文档查看相关接口：

| 接口名称 | 说明 | 基础功能接口（不指定用户空间）开发示例 |
| -------- | -------- | ----------| 
| [addAsUser](../../reference/apis-asset-store-kit/js-apis-asset-sys.md#assetaddasuser)              |   在指定用户空间中新增一条关键资产，使用Promise方式异步返回结果。           |  [add](asset-js-add.md)             |
| [removeAsUser](../../reference/apis-asset-store-kit/js-apis-asset-sys.md#assetremoveasuser)              |   从指定用户空间中删除符合条件的一条或多条关键资产，使用Promise方式异步返回结果。           |  [remove](asset-js-remove.md)             |
| [updateAsUser](../../reference/apis-asset-store-kit/js-apis-asset-sys.md#assetupdateasuser)              |   在指定用户空间中更新符合条件的一条关键资产，使用Promise方式异步返回结果。           |  [update](asset-js-update.md)             |
| [preQueryAsUser](../../reference/apis-asset-store-kit/js-apis-asset-sys.md#assetprequeryasuser)              |   在指定用户空间中查询的预处理，用于需要用户认证的关键资产。在用户认证成功后，应当随后调用[queryAsUser](../../reference/apis-asset-store-kit/js-apis-asset-sys.md#assetqueryasuser)、[postQueryAsUser](../../reference/apis-asset-store-kit/js-apis-asset-sys.md#assetpostqueryasuser)。使用Promise方式异步返回结果。           |  [preQuery](asset-js-query-auth.md)             |
| [queryAsUser](../../reference/apis-asset-store-kit/js-apis-asset-sys.md#assetqueryasuser)              |   在指定用户空间中查询一条或多条符合条件的关键资产。若查询需要用户认证的关键资产，则需要在本函数前调用[preQueryAsUser](../../reference/apis-asset-store-kit/js-apis-asset-sys.md#assetprequeryasuser)，在本函数后调用[postQueryAsUser](../../reference/apis-asset-store-kit/js-apis-asset-sys.md#assetpostqueryasuser)。使用Promise回调异步返回结果。           |  若查询需要用户认证的关键资产: [query](asset-js-query-auth.md)<br>若查询不需要用户认证的关键资产: [query](asset-js-query.md)            |
| [postQueryAsUser](../../reference/apis-asset-store-kit/js-apis-asset-sys.md#assetpostqueryasuser)              |   在指定用户空间中查询的后置处理，用于需要用户认证的关键资产。需与[preQueryAsUser](../../reference/apis-asset-store-kit/js-apis-asset-sys.md#assetprequeryasuser)函数成对出现。使用Promise方式异步返回结果。           |  [postQuery](asset-js-query-auth.md)            |