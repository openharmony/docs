# Cross-Device Synchronization of KV Stores


## When to Use

KV Stores are suitable for storing service data with simple relationships. It provides higher read and write performance than the SQL database. KV stores are widely used because the simplicity of the KV data model poses fewer database version compatibility issues in distributed scenarios and simplifies conflict handling in data synchronization.


## Basic Concepts

Before implementing cross-device synchronization of KV stores, understand the following concepts:


### Single KV Store

In a single KV store, data is saved in the unit of a single entry. When data is modified locally, the data entry is updated no matter whether it has been synchronized. Only one copy of data is retained globally for multiple devices. The data of the latest time is kept for the same entry (with the same primary code) of multiple devices. The data in single KV stores is not differentiated by device. If the data modified on multiple devices has the same key, the value will be overwritten. For the data written or modified locally, the data with the latest time is synchronized to other devices. Single KV stores are used to store information, such as the Contacts and weather application data.

![singleKVStore](figures/singleKVStore.jpg)


### Device KV Store

In a device KV store, the local device ID is added before the key of the KV pair stored by an application. In this way, the data of different devices is isolated. Data is managed by device and can be queried by device.

The underlying devices manage the data by device. The device KV stores support distributed data query by device, but do not support modification of the data synchronized from peer devices. Device KV stores are used to store the data that needs to be accessed by device, such as the Gallery thumbnails.

![deviceKVStore](figures/deviceKVStore.jpg)


## Synchronization Types

The **DatamgrService** provides the following synchronization types:


- Manual synchronization: The application calls **sync()** to trigger a synchronization. The list of devices to be synchronized and the synchronization mode must be specified. The synchronization mode can be **PULL_ONLY** (pulling remote data to the local end), **PUSH_ONLY** (pushing local data to the remote end), or **PUSH_PULL** (pushing local data to the remote end and pulling remote data to the local end). You can use the [**sync()** with the **query** parameter](../reference/apis/js-apis-distributedKVStore.md#sync-1) to synchronize the data that meets the specified conditions.

- Automatic synchronization: The distributed database automatically pushes local data to the remote end and pulls remote data to the local end. An automatic synchronization is triggered when a device goes online or an application updates data.


## Working Principles

After completing device discovery and authentication, the underlying communication component notifies the application that the device goes online. The **DatamgrService** then establishes an encrypted transmission channel to synchronize data between the two devices.


### Cross-Device Data Synchronization Mechanism

![kvStore](figures/kvStore.jpg)

When **put()** or **delete()** is called successfully, an automatic synchronization is triggered. The distributed data is sent to the peer device through the communication adaptation layer for synchronization.

If **sync()** is called successfully, a manual synchronization is triggered to send distributed data to the peer device through the communication adaptation layer.


### Data Change Notification Mechanism

When data is added, deleted, or modified, a notification is sent to the subscriber. The notifications can be classified into the following types:

- Local data change notification: subscription of the application data changes on the local device. When the data in the local KV store is added, deleted, or modified in the database, a notification is received.

- Distributed data change notification: subscription of the application data changes of other devices in the network. When the data in the local KV store changes after being synchronized with data from another device in the same network, a notification is received.


## Constraints

- For each record in a device KV store, the key cannot exceed 896 bytes and the value cannot exceed 4 MB.

- For each record in a single KV store, the key cannot exceed 1 KB and the value cannot exceed 4 MB.

- The KV stores do not support custom conflict resolution policies for applications.

- A maximum of 16 KV stores can be opened simultaneously for an application.

- Each KV store supports a maximum of eight callbacks for subscription of data change notifications.


## Available APIs

The following table lists the APIs for cross-device data synchronization of the single KV store. Most of the APIs are executed asynchronously, using a callback or promise to return the result. The following table uses the callback-based APIs as an example. For more information about the APIs, see [Distributed KV Store](../reference/apis/js-apis-distributedKVStore.md).

| API| Description|
| -------- | -------- |
| createKVManager(config: KVManagerConfig): KVManager | Creates a **KvManager** instance to manage database objects.|
| getKVStore&lt;T&gt;(storeId: string, options: Options, callback: AsyncCallback&lt;T&gt;): void | Creates and obtains a KV store of the specified type.|
| put(key: string, value: Uint8Array\|string\|number\|boolean, callback: AsyncCallback&lt;void&gt;): void | Inserts and updates data.|
| on(event: 'dataChange', type: SubscribeType, listener: Callback&lt;ChangeNotification&gt;): void | Subscribes to data changes in the KV store.|
| get(key: string, callback: AsyncCallback&lt;boolean \| string \| number \| Uint8Array&gt;): void | Queries the value of the specified key.|
| sync(deviceIds: string[], mode: SyncMode, delayMs?: number): void | Triggers a manual synchronization of the KV store.|


## How to Develop

The following uses a single KV store as an example to describe how to implement cross-device data synchronization. The development process is as follows.

![kvStore_development_process](figures/kvStore_development_process.png)

> **NOTE**
>
> The data on a device can be synchronized only to the devices whose data security labels are not higher than the security level of the device. For details, see [Access Control Mechanism in Cross-Device Synchronization](sync-app-data-across-devices-overview.md#access-control-mechanism-in-cross-device-synchronization).

1. Import the module.

   ```ts
   import distributedKVStore from '@ohos.data.distributedKVStore';
   ```

2. Apply for required permissions.

   a) Apply for the **ohos.permission.DISTRIBUTED_DATASYNC** permission. For details, see [Declaring Permissions in the Configuration File](../security/accesstoken-guidelines.md#declaring-permissions-in-the-configuration-file).

   b) Display a dialog box to ask authorization from the user when the application is started for the first time. For details, see [Requesting User Authorization](../security/accesstoken-guidelines.md#requesting-user-authorization).

3. Create a **KvManager** instance based on the specified **KvManagerConfig** object.

   a) Create a **kvManagerConfig** object based on the application context.

   b) Create a **KvManager** instance.


   ```ts
   // Obtain the context of the stage model.
   import window from '@ohos.window';
   import UIAbility from '@ohos.app.ability.UIAbility';
   import { BusinessError } from '@ohos.base';
   
   let kvManager: distributedKVStore.KVManager | undefined = undefined;
   
   class EntryAbility extends UIAbility {
     onWindowStageCreate(windowStage:window.WindowStage) {
       let context = this.context;
     }
   }
    
    // Obtain the context of the FA model.
   import featureAbility from '@ohos.ability.featureAbility';
   import { BusinessError } from '@ohos.base';
    
   let context = featureAbility.getContext();
   
   // Construct a kvManager instance.
   try {
     const kvManagerConfig: distributedKVStore.KVManagerConfig = {
       bundleName: 'com.example.datamanagertest',
       context: context
     }
     kvManager = distributedKVStore.createKVManager(kvManagerConfig);
     console.info('Succeeded in creating KVManager.');
     // Create and obtain the KV store.
   } catch (e) {
     let error = e as BusinessError;
     console.error(`Failed to create KVManager. Code:${error.code},message:${error.message}`);
   }
   
   if (kvManager !== undefined) {
     kvManager = kvManager as distributedKVStore.KVManager;
     // Perform subsequent operations such as creating a KV store.
     // ...
   }
   ```

4. Obtain the KV store of the specified type.

   a) Declare the ID of the distributed KV store to create.

   b) Disable the auto synchronization function (**autoSync:false**) to facilitate subsequent verification of the synchronization function. If synchronization is required, call the **sync()** interface.


   ```ts
   let kvStore: distributedKVStore.SingleKVStore | undefined = undefined;
   try {
     const options: distributedKVStore.Options = {
       createIfMissing: true,
       encrypt: false,
       backup: false,
       autoSync: false,
       // If kvStoreType is left empty, a device KV store is created by default.
       kvStoreType: distributedKVStore.KVStoreType.SINGLE_VERSION,
       // Device KV store: kvStoreType: distributedKVStore.KVStoreType.DEVICE_COLLABORATION,
       securityLevel: distributedKVStore.SecurityLevel.S1
     };
     kvManager.getKVStore<distributedKVStore.SingleKVStore>('storeId', options, (err, store: distributedKVStore.SingleKVStore) => {
       if (err) {
         console.error(`Failed to get KVStore: Code:${err.code},message:${err.message}`);
         return;
       }
       console.info('Succeeded in getting KVStore.');
       kvStore = store;
       // Before performing related data operations, obtain a KV store instance.
     });
   } catch (e) {
     let error = e as BusinessError;
     console.error(`An unexpected error occurred. Code:${error.code},message:${error.message}`);
   }
   if (kvStore !== undefined) {
     kvStore = kvStore as distributedKVStore.SingleKVStore;
       // Perform subsequent data operations, such as adding, deleting, modifying, and querying data, and subscribing to data changes.
       // ...
   }
   ```

5. Subscribe to changes of distributed data. To unsubscribe from the data changes, call [off('dataChange')](../reference/apis/js-apis-distributedKVStore.md#offdatachange).
   
   ```ts
   try {
     kvStore.on('dataChange', distributedKVStore.SubscribeType.SUBSCRIBE_TYPE_ALL, (data) => {
       console.info(`dataChange callback call data: ${data}`);
     });
   } catch (e) {
     let error = e as BusinessError;
     console.error(`An unexpected error occurred. code:${error.code},message:${error.message}`);
   }
   ```

6. Write data to the single KV store.

   a) Construct the key and value to be written to the single KV store.

   b) Write KV pairs to the single KV store.


   ```ts
   const KEY_TEST_STRING_ELEMENT = 'key_test_string';
   const VALUE_TEST_STRING_ELEMENT = 'value_test_string';
   try {
     kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, (err) => {
       if (err !== undefined) {
         console.error(`Failed to put data. Code:${err.code},message:${err.message}`);
         return;
       }
       console.info('Succeeded in putting data.');
     });
   } catch (e) {
     let error = e as BusinessError;
     console.error(`An unexpected error occurred. Code:${error.code},message:${error.message}`);
   }
   ```

7. Query data in the single KV store.

   a) Construct the key to be queried from the single KV store.

   b) Query data from the single KV store.


   ```ts
   const KEY_TEST_STRING_ELEMENT = 'key_test_string';
   const VALUE_TEST_STRING_ELEMENT = 'value_test_string';
   try {
     kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, (err) => {
       if (err !== undefined) {
         console.error(`Failed to put data. Code:${err.code},message:${err.message}`);
         return;
       }
       console.info('Succeeded in putting data.');
       kvStore = kvStore as distributedKVStore.SingleKVStore;
       kvStore.get(KEY_TEST_STRING_ELEMENT, (err, data) => {
         if (err != undefined) {
           console.error(`Failed to get data. Code:${err.code},message:${err.message}`);
           return;
         }
         console.info(`Succeeded in getting data. Data:${data}`);
       });
     });
   } catch (e) {
     let error = e as BusinessError;
     console.error(`Failed to get data. Code:${error.code},message:${error.message}`);
   }
   ```

8. Synchronize data to other devices.

   Select the devices to be synchronized with data and the synchronization mode. The user needs to confirm the synchronization mode when the application is started for the first time.

   > **NOTE**
   >
   > In manual synchronization mode, **deviceIds** can be obtained by [devManager.getAvailableDeviceListSync](../reference/apis/js-apis-distributedDeviceManager.md#getavailabledevicelistsync).

   ```ts
   import deviceManager from '@ohos.distributedDeviceManager';
    
   let devManager: deviceManager.DeviceManager;
   try {
     // create deviceManager
     devManager = deviceManager.createDeviceManager(context.applicationInfo.name);
     // deviceIds is obtained by devManager.getAvailableDeviceListSync.
     let deviceIds: string[] = [];
     if (devManager != null) {
       let devices = devManager.getAvailableDeviceListSync();
       for (let i = 0; i < devices.length; i++) {
         deviceIds[i] = devices[i].networkId as string;
       }
     }
     try {
       // 1000 indicates the maximum delay, in ms.
       kvStore.sync(deviceIds, distributedKVStore.SyncMode.PUSH_ONLY, 1000);
     } catch (e) {
       let error = e as BusinessError;
       console.error(`An unexpected error occurred. Code:${error.code},message:${error.message}`);
     }

   } catch (err) {
     let error = err as BusinessError;
     console.error("createDeviceManager errCode:" + error.code + ",errMessage:" + error.message);
   }
   ```
