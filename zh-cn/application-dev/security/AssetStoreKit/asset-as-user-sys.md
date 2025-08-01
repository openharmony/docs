# 指定用户空间进行关键资产操作(仅对系统应用开放)

<!--Kit: Asset Store Kit-->
<!--Subsystem: Security-->
<!--Owner: @JeremyXu-->
<!--SE: @skye_you-->
<!--TSE: @nacyli-->

对于提供了系统级管理功能的单实例应用，一般场景下，所有用户共用一个实例，该实例负责实现不同用户的数据隔离。

1. 当同时有多个用户处于活跃状态时，单实例应用需要准确告知待操作关键资产所属的用户空间，才能够在该用户空间下存储、访问、销毁关键资产。
2. 单实例应用存储“首次解锁后可访问”和“解锁状态时可访问”的关键资产时，必须指定其所属的用户空间。

为了支持上述场景中单实例应用的关键资产数据隔离和访问控制，ASSET提供了一套可以指定用户空间进行关键资产操作的接口（仅面向系统应用）。

## 约束与限制

使用接口需要申请权限：ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS。

申请流程请参考：[申请应用权限](../AccessToken/determine-application-mode.md#system_basic等级应用申请权限的方式)。

## 接口介绍

可通过API文档查看相关接口：

| 接口名称 | 说明 | 基础功能接口（不指定用户空间）<br>开发示例 |
| -------- | -------- | ----------|
| [addAsUser](../../reference/apis-asset-store-kit/js-apis-asset-sys.md#assetaddasuser)              |   在指定用户空间中新增一条关键资产，使用Promise方式异步返回结果。           |  [add](asset-js-add.md)             |
| [removeAsUser](../../reference/apis-asset-store-kit/js-apis-asset-sys.md#assetremoveasuser)              |   从指定用户空间中删除符合条件的一条或多条关键资产，使用Promise方式异步返回结果。           |  [remove](asset-js-remove.md)             |
| [updateAsUser](../../reference/apis-asset-store-kit/js-apis-asset-sys.md#assetupdateasuser)              |   在指定用户空间中更新符合条件的一条关键资产，使用Promise方式异步返回结果。           |  [update](asset-js-update.md)             |
| [preQueryAsUser](../../reference/apis-asset-store-kit/js-apis-asset-sys.md#assetprequeryasuser)              |   在指定用户空间中查询的预处理，用于需要用户认证的关键资产。在用户认证成功后，应当随后调用[queryAsUser](../../reference/apis-asset-store-kit/js-apis-asset-sys.md#assetqueryasuser)、[postQueryAsUser](../../reference/apis-asset-store-kit/js-apis-asset-sys.md#assetpostqueryasuser)。使用Promise方式异步返回结果。           |  [preQuery](asset-js-query-auth.md)             |
| [queryAsUser](../../reference/apis-asset-store-kit/js-apis-asset-sys.md#assetqueryasuser)              |   在指定用户空间中查询一条或多条符合条件的关键资产。若查询需要用户认证的关键资产，则需要在本函数前调用[preQueryAsUser](../../reference/apis-asset-store-kit/js-apis-asset-sys.md#assetprequeryasuser)，在本函数后调用[postQueryAsUser](../../reference/apis-asset-store-kit/js-apis-asset-sys.md#assetpostqueryasuser)。使用Promise回调异步返回结果。           |  若查询需要用户认证的关键资产：[query](asset-js-query-auth.md)<br>若查询不需要用户认证的关键资产：[query](asset-js-query.md)            |
| [postQueryAsUser](../../reference/apis-asset-store-kit/js-apis-asset-sys.md#assetpostqueryasuser)              |   在指定用户空间中查询的后置处理，用于需要用户认证的关键资产。需与[preQueryAsUser](../../reference/apis-asset-store-kit/js-apis-asset-sys.md#assetprequeryasuser)函数成对出现。使用Promise方式异步返回结果。           |  [postQuery](asset-js-query-auth.md)            |