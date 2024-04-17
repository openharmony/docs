# 指定用户身份操作(仅对系统应用开放)

多用户并发进行关键资产的安全存储及管理操作时，为了实现用户关键资产的隔离和访问控制，ASSET提供了额外的可以指定用户空间进行用户关键资产的安全存储及管理的接口。

## 约束与限制

- 使用方的user ID必须在0到99之间，包含0和99。
- 这部分接口是原有能力的增强，仅面向系统应用开放。

# 接口说明

这部分增强接口，在现有的功能接口的基础上，增加支持参数`userId`用于指定用户空间。

| 指定用户的接口 | 说明 | 不指定用户的接口示例参考 |
| -------- | -------- | ----------| 
| [addAsUser](../../reference/apis-asset-store-kit/js-apis-asset-sys.md#assetaddasuser)              |   在指定用户空间中新增一条关键资产，使用Promise方式异步返回结果。           |  [add](asset-js-add.md)             |
| [removeAsUser](../../reference/apis-asset-store-kit/js-apis-asset-sys.md#assetremoveasuser)              |   从指定用户空间中删除符合条件的一条或多条关键资产，使用Promise方式异步返回结果。           |  [remove](asset-js-remove.md)             |
| [updateAsUser](../../reference/apis-asset-store-kit/js-apis-asset-sys.md#assetupdateasuser)              |   在指定用户空间中更新符合条件的一条关键资产，使用Promise方式异步返回结果。           |  [update](asset-js-update.md)             |
| [preQueryAsUser](../../reference/apis-asset-store-kit/js-apis-asset-sys.md#assetprequeryasuser)              |   在指定用户空间中查询的预处理，用于需要用户认证的关键资产。在用户认证成功后，应当随后调用[queryAsUser](../../reference/apis-asset-store-kit/js-apis-asset-sys.md#assetqueryasuser)、[postQueryAsUser](../../reference/apis-asset-store-kit/js-apis-asset-sys.md#assetpostqueryasuser)。使用Promise方式异步返回结果。           |  [preQuery](asset-js-query-auth.md)             |
| [queryAsUser](../../reference/apis-asset-store-kit/js-apis-asset-sys.md#assetqueryasuser)              |   在指定用户空间中查询一条或多条符合条件的关键资产。若查询需要用户认证的关键资产，则需要在本函数前调用[preQueryAsUser](../../reference/apis-asset-store-kit/js-apis-asset-sys.md#assetprequeryasuser)，在本函数后调用[postQueryAsUser](../../reference/apis-asset-store-kit/js-apis-asset-sys.md#assetpostqueryasuser)。使用Promise回调异步返回结果。           |  若查询需要用户认证的关键资产: [query](asset-js-query-auth.md)<br>若查询不需要用户认证的关键资产: [query](asset-js-query.md)            |
| [postQueryAsUser](../../reference/apis-asset-store-kit/js-apis-asset-sys.md#assetpostqueryasuser)              |   在指定用户空间中查询的后置处理，用于需要用户认证的关键资产。需与[preQueryAsUser](../../reference/apis-asset-store-kit/js-apis-asset-sys.md#assetprequeryasuser)函数成对出现。使用Promise方式异步返回结果。           |  [postQuery](asset-js-query-auth.md)            |