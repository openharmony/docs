# Cross-Device Synchronization of RDB Stores


## When to Use

You can synchronize the application data in a local RDB store on a device to other divices that form a Super Device.


## Basic Concepts

OpenHamony supports synchronization of the relational data of an application across multiple devices.

- Distributed table list<br>After a table is created for an application in an RDB store, you can set it as a distributed table. When querying the RDB store of a remote device, you can obtain the distributed table name of the remote device based on the local table name.

- Synchronization mode<br>Data can be synchronized between devices in either of the following ways: <br>- Pushing data from a local device to a remote device. <br>- Pulling data from a remote device to a local device.


## Working Principles

After completing device discovery and authentication, the underlying communication component notifies the application that the device goes online. The **DatamgrService** then establishes an encrypted transmission channel to synchronize data between the two devices.


### Cross-Device Data Synchronization Mechanism

![relationalStore_sync](figures/relationalStore_sync.jpg)

After writing data to an RDB store, the service sends a synchronization request to the **DatamgrService**.

The **DatamgrService** reads the data to be synchronized from the application sandbox and sends the data to the **DatamgrService** of the target device based on the **deviceId** of the peer device. Then, the **DatamgrService** writes the data to the RDB of the same application.


### Data Change Notification Mechanism

When data is added, deleted, or modified, a notification is sent to the subscriber. The notifications can be classified into the following types:

- Local data change notification: subscription of the application data changes on the local device. When the data in the local KV store is added, deleted, or modified in the database, a notification is received.

- Distributed data change notification: subscription of the application data changes of other devices in the network. When the data in the local RDB store changes after being synchronized with data from another device in the same network, a notification is received.


## Constraints

- A maximum of 16 RDB stores can be opened simultaneously for an application.

- Each RDB store supports a maximum of eight callbacks for subscription of data change notifications.


## Available APIs

Most of the APIs for cross-device data synchronization of RDB stores are executed asynchronously in callback or promise mode. The following table uses the callback-based APIs as an example. For more information about the APIs, see [RDB Store](../reference/apis/js-apis-data-relationalStore.md).

| API| Description|
| -------- | -------- |
| setDistributedTables(tables: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void | Sets the distributed tables to be synchronized.|
| sync(mode: SyncMode, predicates: RdbPredicates, callback: AsyncCallback&lt;Array&lt;[string, number]&gt;&gt;): void | Synchronizes data across devices.|
| on(event: 'dataChange', type: SubscribeType, observer: Callback&lt;Array&lt;string&gt;&gt;): void | Subscribes to changes in the distributed data.|
| off(event:'dataChange', type: SubscribeType, observer: Callback&lt;Array&lt;string&gt;&gt;): void | Unsubscribe from changes in the distributed data.|
| obtainDistributedTableName(device: string, table: string, callback: AsyncCallback&lt;string&gt;): void; | Obtains the table name on the specified device based on the local table name.|
| remoteQuery(device: string, table: string, predicates: RdbPredicates, columns: Array&lt;string&gt; , callback: AsyncCallback&lt;ResultSet&gt;): void | Queries data from the RDB store of a remote device based on specified conditions.|


## How to Develop

> **NOTE**
>
> The data on a device can be synchronized only to the devices whose data security labels are not higher than the security level of the device. For details, see [Access Control Mechanism in Cross-Device Synchronization](sync-app-data-across-devices-overview.md#access-control-mechanism-in-cross-device-synchronization).

1. Import the module.

   ```ts
   import relationalStore from '@ohos.data.relationalStore';
   ```

2. Apply for required permissions.

   1. Apply for the **ohos.permission.DISTRIBUTED_DATASYNC** permission. For details, see [Declaring Permissions in the Configuration File](../security/accesstoken-guidelines.md#declaring-permissions-in-the-configuration-file).
   2. Display a dialog box to ask authorization from the user when the application is started for the first time. For details, see [Requesting User Authorization](../security/accesstoken-guidelines.md#requesting-user-authorization).

3. Create an RDB store and set a table for distributed synchronization.

   ```ts
   import UIAbility from '@ohos.app.ability.UIAbility';
   import window from '@ohos.window';
   import { BusinessError } from "@ohos.base";

   class EntryAbility extends UIAbility {
     onWindowStageCreate(windowStage: window.WindowStage) {
       const STORE_CONFIG: relationalStore.StoreConfig = {
         name: "RdbTest.db",
         securityLevel: relationalStore.SecurityLevel.S1
       };

       relationalStore.getRdbStore(this.context, STORE_CONFIG, (err: BusinessError, store: relationalStore.RdbStore) => {
         store.executeSql('CREATE TABLE IF NOT EXISTS EMPLOYEE (ID INTEGER PRIMARY KEY AUTOINCREMENT, NAME TEXT NOT NULL, AGE INTEGER, SALARY REAL, CODES BLOB)', (err) => {
           // Set the table for distributed synchronization.
           store.setDistributedTables(['EMPLOYEE']);
           // Perform related operations.
         })
       })
     }
   }
   ```

4. Synchronize data across devices. After **sync()** is called to trigger a synchronization, data is synchronized from the local device to all other devices on the network.

   ```ts
   // Construct the predicate object for synchronizing the distributed table.
   let predicates = new relationalStore.RdbPredicates('EMPLOYEE');
   // Call sync() to synchronize data.
   if(store != undefined)
   {
     (store as relationalStore.RdbStore).sync(relationalStore.SyncMode.SYNC_MODE_PUSH, predicates, (err, result) => {
       // Check whether data synchronization is successful.
       if (err) {
         console.error(`Failed to sync data. Code:${err.code},message:${err.message}`);
         return;
       }
       console.info('Succeeded in syncing data.');
       for (let i = 0; i < result.length; i++) {
         console.info(`device:${result[i][0]},status:${result[i][1]}`);
       }
     })
   }
   ```

5. Subscribe to changes in the distributed data. The data synchronization triggers the **observer** callback registered in **on()**. The input parameter of the callback is the ID of the device whose data changes.

   ```ts
   let devices: string | undefined = undefined;
   try {
     // Register an observer to listen for the changes of the distributed data.
     // When data in the RDB store changes, the registered callback will be invoked to return the data changes.
     if(store != undefined) {
       (store as relationalStore.RdbStore).on('dataChange', relationalStore.SubscribeType.SUBSCRIBE_TYPE_REMOTE, (storeObserver)=>{
         if(devices != undefined){
           for (let i = 0; i < devices.length; i++) {
             console.info(`The data of device:${devices[i]} has been changed.`);
           }
         }
       });
     }
   } catch (err) {
     console.error('Failed to register observer. Code:${err.code},message:${err.message}');
   }
   // You can unsubscribe from the data changes if required.
   try {
     if(store != undefined) {
       (store as relationalStore.RdbStore).off('dataChange', relationalStore.SubscribeType.SUBSCRIBE_TYPE_REMOTE, (storeObserver)=>{
       }
     }
   } catch (err) {
     console.error('Failed to register observer. Code:${err.code},message:${err.message}');
   }
   ```

6. Query data across devices. If data synchronization is not complete or triggered, an application can call **remoteQuery()** to query data from a remote device.

   > **NOTE**
   >
   > The value of **deviceIds** can be obtained by [deviceManager.getAvailableDeviceListSync](../reference/apis/js-apis-distributedDeviceManager.md#getavailabledevicelistsync).


   ```ts
   // Obtain device IDs.
   import deviceManager from '@ohos.distributedDeviceManager';
   import { BusinessError } from '@ohos.base'

   let dmInstance: deviceManager.DeviceManager;
   let deviceId: string | undefined = undefined ;

   try {
     dmInstance = deviceManager.createDeviceManager("com.example.appdatamgrverify");
     let devices = dmInstance.getAvailableDeviceListSync();

     deviceId = devices[0].networkId;

     // Construct a predicate object for querying the distributed table.
     let predicates = new relationalStore.RdbPredicates('EMPLOYEE');
     // Query data from the specified remote device and return the query result.
     if(store != undefined && deviceId != undefined) {
       (store as relationalStore.RdbStore).remoteQuery(deviceId, 'EMPLOYEE', predicates, ['ID', 'NAME', 'AGE', 'SALARY', 'CODES'],
         (err: BusinessError, resultSet: relationalStore.ResultSet) => {
           if (err) {
             console.error(`Failed to remoteQuery data. Code:${err.code},message:${err.message}`);
             return;
           }
           console.info(`ResultSet column names: ${resultSet.columnNames}, column count: ${resultSet.columnCount}`);
         }
       )
     }
   } catch (err) {
     let code = (err as BusinessError).code;
     let message = (err as BusinessError).message;
     console.error("createDeviceManager errCode:" + code + ",errMessage:" + message);
   }
   ```