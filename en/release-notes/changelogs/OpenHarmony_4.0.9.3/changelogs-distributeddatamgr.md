# Distributed Data Subsystem Changelog

## Change of the cl.data.cloudData Enum Name from Action to clearAction

**Change Impact**

From OpenHarmony4.0.9.3, use **clearAction()** to specify the action taken to clear the cloud data locally.

**Key API/Component Changes**

Before change:

 ```ts
 enum Action {
    CLEAR_CLOUD_INFO,
    CLEAR_CLOUD_DATA_AND_INFO
  }
 ```

After change:

 ```ts
 enum ClearAction {
    CLEAR_CLOUD_INFO,
    CLEAR_CLOUD_DATA_AND_INFO
  }
 ```

## Change of the cl.data.cloudData API Name from clean to clear

**Change Impact**

From OpenHarmony4.0.9.3, use **clear()** to clear the cloud data locally.

**Key API/Component Changes**

Before change:

 ```ts
    static clean(
      accountId: string,
      appActions: { [bundleName: string]: Action },
      callback: AsyncCallback<void>
    ): void;
    static clean(accountId: string, appActions: { [bundleName: string]: Action }): Promise<void>;
 ```

After change:

 ```ts
     static clear(
      accountId: string,
      appActions: { [bundleName: string]: ClearAction },
      callback: AsyncCallback<void>
    ): void;
    static clear(accountId: string, appActions: { [bundleName: string]: ClearAction }): Promise<void>;
 ```

## Change of the Statistic Value from success to successful in cl.data.relationalStore

**Change Impact**

From OpenHarmony4.0.9.3, use **Statistic.successful** to indicate the number of rows that are successfully synchronized between the device and cloud.

**Key API/Component Changes**

The enumerated value **success** of **Statistic** is changed to **successful**.

Before change:

 ```ts
  interface Statistic {
    total: number;
    success: number;
    failed: number;
    remained: number;
  }
 ```

After change:

 ```ts
  interface Statistic {
    total: number;
    successful: number;
    failed: number;
    remained: number;
  }
 ```

## Change of the Type of the setDistributedTables() Input Parameter type from number to DistributedType in cl.data.relationalStore

**Change Impact**

From OpenHarmony4.0.9.3, the type of the input parameter **type** of **setDistributedTables()** is changed from **number** to **DistributedType**.

**Key API/Component Changes**

Before change:

 ```ts
setDistributedTables(tables: Array<string>, type: number, config: DistributedConfig, callback: AsyncCallback<void>): void;
setDistributedTables(tables: Array<string>, type?: number, config?: DistributedConfig): Promise<void>;
 ```

After change:

 ```ts
setDistributedTables(tables: Array<string>, type: DistributedType, config: DistributedConfig, callback: AsyncCallback<void>): void;
setDistributedTables(tables: Array<string>, type?: DistributedType, config?: DistributedConfig): Promise<void>;
 ```
