# 分布式数据子系统ChangeLog

## cl.distributeddatamgr.1 cloudData模块修改Action接口改名为clearAction

**变更影响**

@ohos.data.cloudData.d.ts基于OpenHarmony4.0.9.3及之后的SDK版本开发的应用，可以使用clearAction接口指定清除本地下载的云端数据的行为枚举。

**关键接口/组件变更**

修改前的接口原型：

 ```ts
 enum Action {
    CLEAR_CLOUD_INFO,
    CLEAR_CLOUD_DATA_AND_INFO
  }
 ```

修改后的接口原型：

 ```ts
 enum ClearAction {
    CLEAR_CLOUD_INFO,
    CLEAR_CLOUD_DATA_AND_INFO
  }
 ```

**适配指导**

基于OpenHarmony4.0.9.3及之后的SDK版本开发的应用，可以使用clearAction接口指定清除本地下载的云端数据的行为枚举。

## cl.distributeddatamgr.2 cloudData模块修改clean接口改名为clear

**变更影响**

@ohos.data.cloudData.d.ts基于OpenHarmony4.0.9.3及之后的SDK版本开发的应用，可以使用clear接口清除本地下载的云端数据。

**关键接口/组件变更**

修改前的接口原型：

 ```ts
    static clean(
      accountId: string,
      appActions: { [bundleName: string]: Action },
      callback: AsyncCallback<void>
    ): void;
    static clean(accountId: string, appActions: { [bundleName: string]: Action }): Promise<void>;
 ```

修改后的接口原型：

 ```ts
     static clear(
      accountId: string,
      appActions: { [bundleName: string]: ClearAction },
      callback: AsyncCallback<void>
    ): void;
    static clear(accountId: string, appActions: { [bundleName: string]: ClearAction }): Promise<void>;
 ```

**适配指导**

基于OpenHarmony4.0.9.3及之后的SDK版本开发的应用，可以使用clear接口清除本地下载的云端数据。

## cl.distributeddatamgr.3 relationalStore模块修改Statistic中的success为successful

**变更影响**

@ohos.data.cloudData.d.ts基于OpenHarmony4.0.9.3及之后的SDK版本开发的应用，可以使用Statistic.successful表示数据库表中端云同步成功的行数。

**关键接口/组件变更**

Statistic中的枚举项success变更为successful，successful表示数据库表中端云同步成功的行数。

修改前的接口原型：

 ```ts
  interface Statistic {
    total: number;
    success: number;
    failed: number;
    remained: number;
  }
 ```

修改后的接口原型：

 ```ts
  interface Statistic {
    total: number;
    successful: number;
    failed: number;
    remained: number;
  }
 ```

**适配指导**

基于OpenHarmony4.0.9.3及之后的SDK版本开发的应用，可以使用Statistic.successful表示数据库表中端云同步成功的行数。

## cl.distributeddatamgr.4 relationalStore模块修改setDistributedTables接口入参type类型由number变为DistributedType

**变更影响**

@ohos.data.relationalStore.d.ts基于OpenHarmony4.0.9.3及之后的SDK版本开发的应用，setDistributedTables接口入参type类型由number变为DistributedType。

**关键接口/组件变更**

修改前setDistributedTables接口：

 ```ts
setDistributedTables(tables: Array<string>, type: number, config: DistributedConfig, callback: AsyncCallback<void>): void;
setDistributedTables(tables: Array<string>, type?: number, config?: DistributedConfig): Promise<void>;
 ```

修改后setDistributedTables接口：

 ```ts
setDistributedTables(tables: Array<string>, type: DistributedType, config: DistributedConfig, callback: AsyncCallback<void>): void;
setDistributedTables(tables: Array<string>, type?: DistributedType, config?: DistributedConfig): Promise<void>;
 ```
**适配指导**

基于OpenHarmony4.0.9.3及之后的SDK版本开发的应用，setDistributedTables接口入参type类型由number变为DistributedType。
