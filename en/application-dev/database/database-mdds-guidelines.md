# Distributed Data Service Development

## When to Use

The Distributed Data Service (DDS) implements synchronization of application data across user devices. When data is added, deleted, or modified for an application on a device, the same application on another device can obtain the updated data. The DDS applies to the distributed gallery, messages, contacts, and file manager.


## Available APIs

The table below describes the APIs provided by the OpenHarmony DDS module.

**Table 1** APIs provided by the DDS

| Category                  | API                                                    | Description                                           |
| -------------------------- | ------------------------------------------------------------ | ----------------------------------------------- |
| Creating a distributed database        | createKVManager(config:&nbsp;KVManagerConfig,&nbsp;callback:&nbsp;AsyncCallback&lt;KVManager&gt;):&nbsp;void<br>createKVManager(config:&nbsp;KVManagerConfig):&nbsp;Promise&lt;KVManager> | Creates a **KVManager** object for database management.|
| Obtaining a distributed KV store        | getKVStore&lt;T&nbsp;extends&nbsp;KVStore&gt;(storeId:&nbsp;string,&nbsp;options:&nbsp;Options,&nbsp;callback:&nbsp;AsyncCallback&lt;T&gt;):&nbsp;void<br>getKVStore&lt;T&nbsp;extends&nbsp;KVStore&gt;(storeId:&nbsp;string,&nbsp;options:&nbsp;Options):&nbsp;Promise&lt;T&gt; | Obtains the KV store with the specified **Options** and **storeId**.|
| Managing data in a distributed KV store| put(key:&nbsp;string,&nbsp;value:&nbsp;Uint8Array&nbsp;\|&nbsp;string&nbsp;\|&nbsp;number&nbsp;\|&nbsp;boolean,&nbsp;callback:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void<br>put(key:&nbsp;string,&nbsp;value:&nbsp;Uint8Array&nbsp;\|&nbsp;string&nbsp;\|&nbsp;number&nbsp;\|&nbsp;boolean):&nbsp;Promise&lt;void> | Inserts and updates data.                               |
| Managing data in a distributed KV store| delete(key:&nbsp;string,&nbsp;callback:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void<br>delete(key:&nbsp;string):&nbsp;Promise&lt;void> | Deletes data.                                     |
| Managing data in a distributed KV store| get(key:&nbsp;string,&nbsp;callback:&nbsp;AsyncCallback&lt;Uint8Array&nbsp;\|&nbsp;string&nbsp;\|&nbsp;boolean&nbsp;\|&nbsp;number&gt;):&nbsp;void<br>get(key:&nbsp;string):&nbsp;Promise&lt;Uint8Array&nbsp;\|&nbsp;string&nbsp;\|&nbsp;boolean&nbsp;\|&nbsp;number> | Queries data.                                     |
| Subscribing to changes in the distributed data      | on(event:&nbsp;'dataChange',&nbsp;type:&nbsp;SubscribeType,&nbsp;observer:&nbsp;Callback&lt;ChangeNotification&gt;):&nbsp;void<br>on(event:&nbsp;'syncComplete',&nbsp;syncCallback:&nbsp;Callback&lt;Array&lt;[string,&nbsp;number]&gt;&gt;):&nbsp;void | Subscribes to data changes in the KV store.                       |
| Synchronizing data across devices          | sync(deviceIdList:&nbsp;string[],&nbsp;mode:&nbsp;SyncMode,&nbsp;allowedDelayMs?:&nbsp;number):&nbsp;void | Triggers database synchronization in manual mode.                 |




## How to Develop

The following uses a single KV store as an example to describe the development procedure.

1. Import the distributed data module.
   ```js
   import distributedData from '@ohos.data.distributedData';
   ```

2. Create a **KvManager** instance based on the specified **KvManagerConfig** object.
   1. Create a **KvManagerConfig** object based on the application context.
   2. Create a **KvManager** instance.

   The sample code is as follows:
   ```js
   let kvManager;
   try {
       const kvManagerConfig = {
           bundleName : 'com.example.datamanagertest',
           userInfo : {
               userId : '0',
               userType : distributedData.UserType.SAME_USER_ID
           }
       }
       distributedData.createKVManager(kvManagerConfig, function (err, manager) {
           if (err) {
               console.log("createKVManager err: "  + JSON.stringify(err));
               return;
           }
           console.log("createKVManager success");
           kvManager = manager;
       });
   } catch (e) {
       console.log("An unexpected error occurred. Error:" + e);
   }
   ```

3. Create and obtain a single KV store.
   1. Declare the ID of the single KV store to create.
   2. Create a single KV store. You are advised to disable automatic synchronization (**autoSync:false**) and call **sync** when a synchronization is required.

   The sample code is as follows:
   ```js
   let kvStore;
   try {
       const options = {
           createIfMissing : true,
           encrypt : false,
           backup : false,
           autoSync : false,
           kvStoreType : distributedData.KVStoreType.SINGLE_VERSION,
           securityLevel : distributedData.SecurityLevel.S0,
       };
       kvManager.getKVStore('storeId', options, function (err, store) {
           if (err) {
               console.log("getKVStore err: "  + JSON.stringify(err));
               return;
           }
           console.log("getKVStore success");
           kvStore = store;
       });
   } catch (e) {
       console.log("An unexpected error occurred. Error:" + e);
   }
   ```

   > ![icon-note.gif](../public_sys-resources/icon-note.gif) **NOTE**<br/>
   > For data synchronization between networked devices, you are advised to open the distributed KV store during application startup to obtain the database handle. With this database handle (**kvStore** in this example), you can perform operations, such as inserting data into the KV store, without creating the KV store repeatedly during the lifecycle of the handle.

4.  Subscribe to changes in the distributed data.<br/>
   The following is the sample code for subscribing to the data changes of a single KV store:
   ```js
   kvStore.on('dataChange', distributedData.SubscribeType.SUBSCRIBE_TYPE_ALL, function (data) {
       console.log("dataChange callback call data: " + JSON.stringify(data));
   });
   ```

5. Write data to the single KV store.
   1. Construct the key and value to be written into the single KV store.
   2. Write key-value pairs into the single KV store.

   The following is the sample code for writing key-value pairs of the string type into the single KV store:

   ```js
   const KEY_TEST_STRING_ELEMENT = 'key_test_string';
   const VALUE_TEST_STRING_ELEMENT = 'value-test-string';
   try {
       kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, function (err,data) {
           if (err != undefined) {
               console.log("put err: " + JSON.stringify(err));
               return;
           }
           console.log("put success");
       });
   }catch (e) {
       console.log("An unexpected error occurred. Error:" + e);
   }
   ```

6. Query data in the single KV store.
   1. Construct the key to be queried from the single KV store.
   2. Query data from the single KV store.

   The following is the sample code for querying data of the string type from the single KV store:
   ```js
   const KEY_TEST_STRING_ELEMENT = 'key_test_string';
   const VALUE_TEST_STRING_ELEMENT = 'value-test-string';
   try {
       kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, function (err,data) {
           if (err != undefined) {
               console.log("put err: " + JSON.stringify(err));
               return;
           }
           console.log("put success");
           kvStore.get(KEY_TEST_STRING_ELEMENT, function (err,data) {
               console.log("get success data: " + data);
           });
       });
   }catch (e) {
       console.log("An unexpected error occurred. Error:" + e);
   }
   ```

7. Synchronize data to other devices.<br/>
   Select the devices in the same network and the synchronization mode to synchronize data.

   The following is the sample code for data synchronization in a single KV store. **deviceIds** can be obtained by deviceManager by calling **getTrustedDeviceListSync()**, and **1000** indicates that the maximum delay time is 1000 ms.
   ```js
   import deviceManager from '@ohos.distributedHardware.deviceManager';
   
   let devManager;
   // Create deviceManager.
   deviceManager.createDeviceManager("bundleName", (err, value) => {
       if (!err) {
           devManager = value;
           // Obtain deviceIds.
           let deviceIds = [];
           if (devManager != null) {
               var devices = devManager.getTrustedDeviceListSync();
               for (var i = 0; i < devices.length; i++) {
                   deviceIds[i] = devices[i].deviceId;
               }
           }
           try{
               kvStore.sync(deviceIds, distributedData.SyncMode.PUSH_ONLY, 1000);
           }catch (e) {
                console.log("An unexpected error occurred. Error:" + e);
           }
       }
   });
   ```
