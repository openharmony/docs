# 分布式数据子系统ChangeLog

## cl.data.cloudData修改Action接口改名为clearAction

**变更影响**

基于OpenHarmony4.0.9.3及之后的SDK版本开发的应用，可以使用clearAction接口指定清除本地下载的云端数据的行为枚举。

**关键接口/组件变更**

修改前的接口原型：

 ```ts
 /**
   * Describes the clear action type.
   *
   * @enum { number }
   * @syscap SystemCapability.DistributedDataManager.CloudSync.Config
   * @systemapi
   * @since 10
   */
  enum Action {
    /**
     * Indicates clearing cloud-related data only, which includes cloud meta data and cloud-related local data.
     *
     * @syscap SystemCapability.DistributedDataManager.CloudSync.Config
     * @systemapi
     * @since 10
     */
    CLEAR_CLOUD_INFO,

    /**
     * Indicates clearing all cloud-related file data,which synchronized with the cloud.
     *
     * @syscap SystemCapability.DistributedDataManager.CloudSync.Config
     * @systemapi
     * @since 10
     */
    CLEAR_CLOUD_DATA_AND_INFO
  }
 ```

修改后的接口原型：

 ```ts
/**
   * Describes the clear action type.
   *
   * @enum { number }
   * @syscap SystemCapability.DistributedDataManager.CloudSync.Config
   * @systemapi
   * @since 10
   */
  enum ClearAction {
    /**
     * Indicates clearing cloud-related data only, which includes cloud meta data and cloud-related local data.
     *
     * @syscap SystemCapability.DistributedDataManager.CloudSync.Config
     * @systemapi
     * @since 10
     */
    CLEAR_CLOUD_INFO,

    /**
     * Indicates clearing all cloud-related file data,which synchronized with the cloud.
     *
     * @syscap SystemCapability.DistributedDataManager.CloudSync.Config
     * @systemapi
     * @since 10
     */
    CLEAR_CLOUD_DATA_AND_INFO
  }
 ```

## 

## cl.data.cloudData修改clean接口改名为clear

**变更影响**

基于OpenHarmony4.0.9.3及之后的SDK版本开发的应用，可以使用clear接口清除本地下载的云端数据。

**关键接口/组件变更**

修改前的接口原型：

 ```ts
 /**
     * deletes cloud information from local data.
     *
     * @permission ohos.permission.CLOUDDATA_CONFIG
     * @param { string } accountId - Indicates the account ID. The account ID is required by hashing the information of specific opened cloud.
     * @param { {[bundleName: string]: Action} } appActions - Indicates information about the application data need to clear in which way.
     * @param { AsyncCallback<void> } callback - the callback of clean.
     * @throws { BusinessError } 201 - Permission verification failed, usually the result returned by VerifyAccessToken.
     * @throws { BusinessError } 202 - Permission verification failed, application which is not a system application uses system API.
     * @throws { BusinessError } 401 - Parameter error.
     * @throws { BusinessError } 801 - Capability not supported.
     * @syscap SystemCapability.DistributedDataManager.CloudSync.Config
     * @systemapi
     * @since 10
     */
    static clean(
      accountId: string,
      appActions: { [bundleName: string]: Action },
      callback: AsyncCallback<void>
    ): void;

    /**
     * deletes cloud information from local data.
     *
     * @permission ohos.permission.CLOUDDATA_CONFIG
     * @param { string } accountId - Indicates the account ID. The account ID is required by hashing the information of specific opened cloud.
     * @param { {[bundleName: string]: Action} } appActions - Indicates information about the application data need to clear in which way.
     * @returns { Promise<void> } the promise returned by the function.
     * @throws { BusinessError } 201 - Permission verification failed, usually the result returned by VerifyAccessToken.
     * @throws { BusinessError } 202 - Permission verification failed, application which is not a system application uses system API.
     * @throws { BusinessError } 401 - Parameter error.
     * @throws { BusinessError } 801 - Capability not supported.
     * @syscap SystemCapability.DistributedDataManager.CloudSync.Config
     * @systemapi
     * @since 10
     */
    static clean(accountId: string, appActions: { [bundleName: string]: Action }): Promise<void>;
 ```

修改后的接口原型：

 ```ts
 /**
     * deletes cloud information from local data.
     *
     * @permission ohos.permission.CLOUDDATA_CONFIG
     * @param { string } accountId - Indicates the account ID. The account ID is required by hashing cloud account.
     * @param { { [bundleName: string]: ClearAction } } appActions - Indicates the way in which the application data is to be cleared.
     * @param { AsyncCallback<void> } callback - the callback of clear.
     * @throws { BusinessError } 201 - Permission verification failed, usually the result returned by VerifyAccessToken.
     * @throws { BusinessError } 202 - Permission verification failed, application which is not a system application uses system API.
     * @throws { BusinessError } 401 - Parameter error.
     * @throws { BusinessError } 801 - Capability not supported.
     * @syscap SystemCapability.DistributedDataManager.CloudSync.Config
     * @systemapi
     * @since 10
     */
    static clear(
      accountId: string,
      appActions: { [bundleName: string]: ClearAction },
      callback: AsyncCallback<void>
    ): void;

    /**
     * deletes cloud information from local data.
     *
     * @permission ohos.permission.CLOUDDATA_CONFIG
     * @param { string } accountId - Indicates the account ID. The account ID is required by hashing the information of specific opened cloud.
     * @param { { [bundleName: string]: ClearAction } } appActions - Indicates the way in which the application data is to be cleared.
     * @returns { Promise<void> } the promise returned by the function.
     * @throws { BusinessError } 201 - Permission verification failed, usually the result returned by VerifyAccessToken.
     * @throws { BusinessError } 202 - Permission verification failed, application which is not a system application uses system API.
     * @throws { BusinessError } 401 - Parameter error.
     * @throws { BusinessError } 801 - Capability not supported.
     * @syscap SystemCapability.DistributedDataManager.CloudSync.Config
     * @systemapi
     * @since 10
     */
    static clear(accountId: string, appActions: { [bundleName: string]: ClearAction }): Promise<void>;
 ```

## cl.data.relationalStore修改Statistic中的success为successful

**变更影响**

基于OpenHarmony4.0.9.3及之后的SDK版本开发的应用，可以使用Statistic.successful表示数据库表中端云同步成功的行数。

**关键接口/组件变更**

修改前的接口原型：

 ```ts
 /**
   * Describes the statistic of the cloud sync process.
   *
   * @interface Statistic
   * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
   * @since 10
   */
  interface Statistic {
    /**
     * Describes the total number of data to sync.
     *
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 10
     */
    total: number;

    /**
     * Describes the number of successfully synced data.
     *
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 10
     */
    success: number;

    /**
     * Describes the number of data failed to sync.
     *
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 10
     */
    failed: number;

    /**
     * Describes the number of data remained to sync.
     *
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 10
     */
    remained: number;
  }
 ```

修改后的接口原型：

 ```ts
 /**
   * Describes the statistic of the cloud sync process.
   *
   * @interface Statistic
   * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
   * @since 10
   */
  interface Statistic {
    /**
     * Describes the total number of data to sync.
     *
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 10
     */
    total: number;

    /**
     * Describes the number of successfully synced data.
     *
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 10
     */
    successful: number;

    /**
     * Describes the number of data failed to sync.
     *
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 10
     */
    failed: number;

    /**
     * Describes the number of data remained to sync.
     *
     * @syscap SystemCapability.DistributedDataManager.RelationalStore.Core
     * @since 10
     */
    remained: number;
  }
 ```

## cl.data.relationalStore修改setDistributedTables接口入参type类型由number变为DistributedType

**变更影响**

基于OpenHarmony4.0.9.3及之后的SDK版本开发的应用，setDistributedTables接口入参type类型由number变为DistributedType。

**关键接口/组件变更**

1.修改前setDistributedTables接口：

 ```ts
setDistributedTables(tables: Array<string>, type: number, config: DistributedConfig, callback: AsyncCallback<void>): void;
 ```

修改后setDistributedTables接口：

 ```ts
setDistributedTables(tables: Array<string>, type: DistributedType, config: DistributedConfig, callback: AsyncCallback<void>): void;
 ```

2.修改前setDistributedTables接口：

 ```ts
setDistributedTables(tables: Array<string>, type?: number, config?: DistributedConfig): Promise<void>;
 ```

修改后setDistributedTables接口：

 ```ts
setDistributedTables(tables: Array<string>, type?: DistributedType, config?: DistributedConfig): Promise<void>;
 ```

## cl.data.relationalStore接口新增

新增setDistributedTables(tables: Array&lt;string&gt;, type: DistributedType, callback: AsyncCallback&lt;void&gt; ): void接口。

**变更影响**

基于OpenHarmony4.0.9.3及之后的SDK版本开发的应用，可使用setDistributedTables(tables: Array&lt;string&gt;, type: DistributedType, callback: AsyncCallback&lt;void&gt; ): void设置分布式表。

**关键接口/组件变更**

@ohos.data.relationalStore.d.ts中新增setDistributedTables接口。

| 模块名                          | 类名     | 方法/属性/枚举/常量                                          | 变更类型 |
| ------------------------------- | -------- | ------------------------------------------------------------ | -------- |
| @ohos.data.relationalStore.d.ts | RdbStore | setDistributedTables(tables: Array&lt;string&gt;, type: DistributedType, callback: AsyncCallback&lt;void&gt; ): void | 新增     |

**适配指导**<br>

通过调用setDistributedTables接口设置分布式表。

```ts
store.setDistributedTables(["EMPLOYEE"], relationalStore.DistributedType.DISTRIBUTED_CLOUD, function (err) {
  if (err) {
    console.error(`SetDistributedTables failed, code is ${err.code},message is ${err.message}`);
    return;
  }
  console.info(`SetDistributedTables successfully.`);
})
```

