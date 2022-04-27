# Distributed Data Service Development<a name="EN-US_TOPIC_0000001183227606"></a>

## When to Use<a name="section29812823611"></a>

The DDS implements synchronization of application data across user devices. When data is added, deleted, or modified for an application on a device, the same application on another device can obtain the data changes. The DDS applies to the distributed gallery, messages, contacts, and file manager.

## Available APIs<a name="section10795222103613"></a>

The following table describes the APIs provided by the OpenHarmony DDS module.

**Table  1**  APIs provided by the DDS

<a name="table1479715411814"></a>
<table><thead align="left"><tr id="row117981654681"><th class="cellrowborder" valign="top" width="13.171317131713172%" id="mcps1.2.4.1.1"><p id="p207989543820"><a name="p207989543820"></a><a name="p207989543820"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="53.525352535253525%" id="mcps1.2.4.1.2"><p id="p1379845420813"><a name="p1379845420813"></a><a name="p1379845420813"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="33.3033303330333%" id="mcps1.2.4.1.3"><p id="p10798145412810"><a name="p10798145412810"></a><a name="p10798145412810"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row14541456191517"><td class="cellrowborder" rowspan="2" valign="top" width="13.171317131713172%" headers="mcps1.2.4.1.1 "><p id="p65410566158"><a name="p65410566158"></a><a name="p65410566158"></a>Creating a distributed database</p>
</td>
<td class="cellrowborder" valign="top" width="53.525352535253525%" headers="mcps1.2.4.1.2 "><p id="p1941744894319"><a name="p1941744894319"></a><a name="p1941744894319"></a>createKVManager(config: KVManagerConfig, callback: AsyncCallback&lt;KVManager&gt;): void</p>
<p id="p1096444965211"><a name="p1096444965211"></a><a name="p1096444965211"></a>createKVManager(config: KVManagerConfig): Promise&lt;KVManager&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="33.3033303330333%" headers="mcps1.2.4.1.3 "><p id="p101014641817"><a name="p101014641817"></a><a name="p101014641817"></a>Creates a <strong id="b1522993164717"><a name="b1522993164717"></a><a name="b1522993164717"></a>KVManager</strong> object for database management.</p>
</td>
</tr>
<tr id="row154114568151"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p696417105816"><a name="p696417105816"></a><a name="p696417105816"></a>getKVStore&lt;T extends KVStore&gt;(storeId: string, options: Options, callback: AsyncCallback&lt;T&gt;): void</p>
<p id="p249610364411"><a name="p249610364411"></a><a name="p249610364411"></a>getKVStore&lt;T extends KVStore&gt;(storeId: string, options: Options): Promise&lt;T&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1939220263198"><a name="p1939220263198"></a><a name="p1939220263198"></a>Obtains the KV store with specified <strong id="b1047044512494"><a name="b1047044512494"></a><a name="b1047044512494"></a>Options</strong> and <strong id="b76466490494"><a name="b76466490494"></a><a name="b76466490494"></a>storeId</strong>.</p>
</td>
</tr>
<tr id="row157982545817"><td class="cellrowborder" rowspan="3" valign="top" width="13.171317131713172%" headers="mcps1.2.4.1.1 "><p id="p37985541683"><a name="p37985541683"></a><a name="p37985541683"></a>Managing data in a distributed database</p>
</td>
<td class="cellrowborder" valign="top" width="53.525352535253525%" headers="mcps1.2.4.1.2 "><p id="p131294221332"><a name="p131294221332"></a><a name="p131294221332"></a>put(key: string, value: Uint8Array | string | number | boolean, callback: AsyncCallback&lt;void&gt;): void</p>
<p id="p5426816843"><a name="p5426816843"></a><a name="p5426816843"></a>put(key: string, value: Uint8Array | string | number | boolean): Promise&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="33.3033303330333%" headers="mcps1.2.4.1.3 "><p id="p176461135185113"><a name="p176461135185113"></a><a name="p176461135185113"></a>Inserts and updates data.</p>
</td>
</tr>
<tr id="row97981541589"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1081643813515"><a name="p1081643813515"></a><a name="p1081643813515"></a>delete(key: string, callback: AsyncCallback&lt;void&gt;): void</p>
<p id="p18154322061"><a name="p18154322061"></a><a name="p18154322061"></a>delete(key: string): Promise&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p199836513815"><a name="p199836513815"></a><a name="p199836513815"></a>Deletes data.</p>
</td>
</tr>
<tr id="row67981354182"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p570352011813"><a name="p570352011813"></a><a name="p570352011813"></a>get(key: string, callback: AsyncCallback&lt;Uint8Array | string | boolean | number&gt;): void</p>
<p id="p68241257189"><a name="p68241257189"></a><a name="p68241257189"></a>get(key: string): Promise&lt;Uint8Array | string | boolean | number&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p66421735105117"><a name="p66421735105117"></a><a name="p66421735105117"></a>Queries data.</p>
</td>
</tr>
<tr id="row79301383912"><td class="cellrowborder" valign="top" width="13.171317131713172%" headers="mcps1.2.4.1.1 "><p id="p9931153113918"><a name="p9931153113918"></a><a name="p9931153113918"></a>Subscribing to changes in the distributed data</p>
</td>
<td class="cellrowborder" valign="top" width="53.525352535253525%" headers="mcps1.2.4.1.2 "><p id="p1650011101175"><a name="p1650011101175"></a><a name="p1650011101175"></a>on(event: 'dataChange', type: SubscribeType, observer: Callback&lt;ChangeNotification&gt;): void</p>
<p id="p76436491878"><a name="p76436491878"></a><a name="p76436491878"></a>on(event: 'syncComplete', syncCallback: Callback&lt;Array&lt;[string, number]&gt;&gt;): void</p>
</td>
<td class="cellrowborder" valign="top" width="33.3033303330333%" headers="mcps1.2.4.1.3 "><p id="p1793120318397"><a name="p1793120318397"></a><a name="p1793120318397"></a>Subscribes to data changes in the database.</p>
</td>
</tr>
<tr id="row6194318125312"><td class="cellrowborder" valign="top" width="13.171317131713172%" headers="mcps1.2.4.1.1 "><p id="p61941518135320"><a name="p61941518135320"></a><a name="p61941518135320"></a>Synchronizing distributed data</p>
</td>
<td class="cellrowborder" valign="top" width="53.525352535253525%" headers="mcps1.2.4.1.2 "><p id="p149121836097"><a name="p149121836097"></a><a name="p149121836097"></a>sync(deviceIdList: string[], mode: SyncMode, allowedDelayMs?: number): void</p>
</td>
<td class="cellrowborder" valign="top" width="33.3033303330333%" headers="mcps1.2.4.1.3 "><p id="p1319561811538"><a name="p1319561811538"></a><a name="p1319561811538"></a>Triggers database synchronization in manual mode.</p>
</td>
</tr>
</tbody>
</table>

## How to Develop<a name="section1252143014159"></a>

The following uses a single KV store as an example to describe the development procedure.

1.  Import the distributed database module.

    ```js
    import distributedData from '@ohos.data.distributedData';
    ```

2.  Create a  **KvManager**  instance based on the specified  **KvManagerConfig**  object.

    1.  Create a  **KvManagerConfig**  object based on the application context.
    2.  Create a  **KvManager**  instance.

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

3.  Create and obtain a single KV store.

    1.  Declare the ID of the single KV store to create.
    2.  Create a single KV store. You are advised to disable automatic synchronization \(**autoSync:false**\) and call  **sync**  if a synchronization is required.

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
            securityLevel : distributedData.SecurityLevel.S2,
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

    >![](../public_sys-resources/icon-note.gif) **NOTE:** 
    >For data synchronization between networked devices, you are advised to open the distributed database during application startup to obtain the database handle. With this database handle \(**kvStore**  in this example\), you can perform operations, such as inserting data into the database, without creating the database repeatedly during the lifecycle of the handle.

4.  Subscribe to changes in the distributed data.

    The following is the sample code for subscribing to the data changes of a single KV store:

    ```js
    kvStore.on('dataChange', distributedData.SubscribeType.SUBSCRIBE_TYPE_ALL, function (data) {
        console.log("dataChange callback call data: " + JSON.stringify(data));
    });
    ```

5.  Write data to the single KV store.

    1.  Construct the key and value to be written into the single KV store.
    2.  Write key-value pairs into the single KV store.

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

6.  Query data in the single KV store.

    1.  Construct the key to be queried from the single KV store.
    2.  Query data from the single KV store.

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

7.  Synchronize data to other devices.

    Select the devices in the same network and the synchronization mode to synchronize data.

    The following is the sample code for data synchronization in a single KV store.  **deviceIds**  can be obtained by deviceManager by calling  **getTrustedDeviceListSync\(\)**, and  **1000**  indicates that the maximum delay time is 1000 ms.

    ```js
    import deviceManager from '@ohos.distributedHardware.deviceManager';
    
    let devManager;
    // create deviceManager
    deviceManager.createDeviceManager("bundleName", (err, value) => {
        if (!err) {
            devManager = value;
        }
    });
    
    // get deviceIds
    let deviceIds = [];
    if (devManager != null) {
        var deviceList = devManager.getTrustedDeviceListSync();
        for (var i = 0; i < deviceList.length; i++) {
            deviceIds[i] = deviceList[i].deviceId;
        }
    }
    kvStore.sync(deviceIds, distributedData.SyncMode.PUSH_ONLY, 1000);
    ```


