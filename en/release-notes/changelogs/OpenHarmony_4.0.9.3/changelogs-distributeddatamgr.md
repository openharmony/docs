# Distributed Data Subsystem Changelog

## cl.distributeddatamgr.1 Change of the API Name from Action to clearAction in the cloudData Module

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

**Adaptation Guide**

From OpenHarmony4.0.9.3, use **clearAction()** to specify the action taken to clear the cloud data locally.

## cl.distributeddatamgr.2 Change of the API Name from clean to clear in the cloudData Module

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

**Adaptation Guide**

From OpenHarmony4.0.9.3, use **clear()** to clear the cloud data locally.

## cl.distributeddatamgr.3 Change of "success" to "successful" in Statistic of the relationalStore Module

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

**Adaptation Guide**

From OpenHarmony4.0.9.3, use **Statistic.successful** to indicate the number of rows that are successfully synchronized between the device and cloud.

## cl.distributeddatamgr.4 Change of the Parameter type in setDistributedTables() from the number Type to DistributedType in the relationalStore Module

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
**Adaptation Guide**

From OpenHarmony4.0.9.3, the type of the input parameter **type** of **setDistributedTables()** is changed from **number** to **DistributedType**.
