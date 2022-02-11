# Lightweight Data Store Development<a name="EN-US_TOPIC_0000001230830543"></a>

## When to Use<a name="section13841104521714"></a>

The lightweight data store is ideal for storing lightweight and frequently used data, but not for storing a large amount of data or data with frequent changes. The application data is persistently stored on a device in the form of files. Note that the instance accessed by an application contains all data of the file. The data is always loaded to the memory of the device until the application removes it from the memory. The application can perform data operations using the  **Storage**  APIs.

## Available APIs<a name="section15173156141712"></a>

The lightweight data store provides applications with data processing capability and allows applications to perform lightweight data storage and query. Data is stored in key-value pairs. Keys are of the string type, and values can be of the number, string, or Boolean type.

**Creating a Storage Instance**

Create a  **Storage**  instance for data operations. A  **Storage**  instance is created after data is read from a specified file and loaded to the instance.

**Table  1**  API for creating a  **Storage**  instance

<a name="table17310132152415"></a>
<table><thead align="left"><tr id="row93118212413"><th class="cellrowborder" valign="top" width="17.69%" id="mcps1.2.4.1.1"><p id="p031118214242"><a name="p031118214242"></a><a name="p031118214242"></a>Package Name</p>
</th>
<th class="cellrowborder" valign="top" width="28.249999999999996%" id="mcps1.2.4.1.2"><p id="p19311326245"><a name="p19311326245"></a><a name="p19311326245"></a>Method</p>
</th>
<th class="cellrowborder" valign="top" width="54.059999999999995%" id="mcps1.2.4.1.3"><p id="p1131118252418"><a name="p1131118252418"></a><a name="p1131118252418"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row38631245202910"><td class="cellrowborder" valign="top" width="17.69%" headers="mcps1.2.4.1.1 "><p id="p8365103153013"><a name="p8365103153013"></a><a name="p8365103153013"></a>ohos.data.storage</p>
</td>
<td class="cellrowborder" valign="top" width="28.249999999999996%" headers="mcps1.2.4.1.2 "><p id="p1937481213019"><a name="p1937481213019"></a><a name="p1937481213019"></a>getStorage(path: string): Promise&lt;Storage&gt;;</p>
</td>
<td class="cellrowborder" valign="top" width="54.059999999999995%" headers="mcps1.2.4.1.3 "><p id="p4311132162417"><a name="p4311132162417"></a><a name="p4311132162417"></a>Obtains the <strong id="b193911821194211"><a name="b193911821194211"></a><a name="b193911821194211"></a>Storage</strong> singleton corresponding to a file for data operations.</p>
</td>
</tr>
</tbody>
</table>

**Writing Data**

Call the  **put\(\)**  method to add or modify data in a  **Storage**  instance.

**Table  2**  API for writing data

<a name="table52021841142013"></a>
<table><thead align="left"><tr id="row2202741122013"><th class="cellrowborder" valign="top" width="19.79%" id="mcps1.2.4.1.1"><p id="p12161443377"><a name="p12161443377"></a><a name="p12161443377"></a>Class</p>
</th>
<th class="cellrowborder" valign="top" width="37%" id="mcps1.2.4.1.2"><p id="p172028414205"><a name="p172028414205"></a><a name="p172028414205"></a>Method</p>
</th>
<th class="cellrowborder" valign="top" width="43.21%" id="mcps1.2.4.1.3"><p id="p162020415205"><a name="p162020415205"></a><a name="p162020415205"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row8203194115202"><td class="cellrowborder" valign="top" width="19.79%" headers="mcps1.2.4.1.1 "><p id="p31644311712"><a name="p31644311712"></a><a name="p31644311712"></a>Storage</p>
</td>
<td class="cellrowborder" valign="top" width="37%" headers="mcps1.2.4.1.2 "><p id="p105961650131617"><a name="p105961650131617"></a><a name="p105961650131617"></a>put(key: string, value: ValueType): Promise&lt;void&gt;;</p>
</td>
<td class="cellrowborder" valign="top" width="43.21%" headers="mcps1.2.4.1.3 "><p id="p127261044489"><a name="p127261044489"></a><a name="p127261044489"></a>Writes data of the number, string, and Boolean types.</p>
</td>
</tr>
</tbody>
</table>

**Reading Data**

Call the  **get\(\)**  method to read data from a  **Storage**  instance.

**Table  3**  API for reading data

<a name="table182143189350"></a>
<table><thead align="left"><tr id="row173241118123511"><th class="cellrowborder" valign="top" width="18.04%" id="mcps1.2.4.1.1"><p id="p94819229584"><a name="p94819229584"></a><a name="p94819229584"></a>Class</p>
</th>
<th class="cellrowborder" valign="top" width="37.830000000000005%" id="mcps1.2.4.1.2"><p id="p18324181853514"><a name="p18324181853514"></a><a name="p18324181853514"></a>Method</p>
</th>
<th class="cellrowborder" valign="top" width="44.13%" id="mcps1.2.4.1.3"><p id="p11324131814355"><a name="p11324131814355"></a><a name="p11324131814355"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row18325141813350"><td class="cellrowborder" valign="top" width="18.04%" headers="mcps1.2.4.1.1 "><p id="p1448113223583"><a name="p1448113223583"></a><a name="p1448113223583"></a>Storage</p>
</td>
<td class="cellrowborder" valign="top" width="37.830000000000005%" headers="mcps1.2.4.1.2 "><p id="p1335031410172"><a name="p1335031410172"></a><a name="p1335031410172"></a>get(key: string, defValue: ValueType): Promise&lt;ValueType&gt;;</p>
</td>
<td class="cellrowborder" valign="top" width="44.13%" headers="mcps1.2.4.1.3 "><p id="p11862123993920"><a name="p11862123993920"></a><a name="p11862123993920"></a>Reads data of the number, string, and Boolean types.</p>
</td>
</tr>
</tbody>
</table>

**Storing Data Persistently**

Call the  **flush\(\)**  method to write the cached data back to its text file for persistent storage.

**Table  4**  API for data persistence

<a name="table1290414100219"></a>
<table><thead align="left"><tr id="row690412101627"><th class="cellrowborder" valign="top" width="18.04%" id="mcps1.2.4.1.1"><p id="p1390414101929"><a name="p1390414101929"></a><a name="p1390414101929"></a>Class</p>
</th>
<th class="cellrowborder" valign="top" width="37.830000000000005%" id="mcps1.2.4.1.2"><p id="p59045104215"><a name="p59045104215"></a><a name="p59045104215"></a>Method</p>
</th>
<th class="cellrowborder" valign="top" width="44.13%" id="mcps1.2.4.1.3"><p id="p1190416106210"><a name="p1190416106210"></a><a name="p1190416106210"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row99041710923"><td class="cellrowborder" valign="top" width="18.04%" headers="mcps1.2.4.1.1 "><p id="p7904101018217"><a name="p7904101018217"></a><a name="p7904101018217"></a>Storage</p>
</td>
<td class="cellrowborder" valign="top" width="37.830000000000005%" headers="mcps1.2.4.1.2 "><p id="p1290418101218"><a name="p1290418101218"></a><a name="p1290418101218"></a>flush(): Promise&lt;void&gt;;</p>
</td>
<td class="cellrowborder" valign="top" width="44.13%" headers="mcps1.2.4.1.3 "><p id="p1234935810316"><a name="p1234935810316"></a><a name="p1234935810316"></a>Writes data in the <strong id="b263252724411"><a name="b263252724411"></a><a name="b263252724411"></a>Storage</strong> instance back to its file through an asynchronous thread.</p>
</td>
</tr>
</tbody>
</table>

**Observing Data Changes**

Specify  **StorageObserver**  as the callback to subscribe to data changes. When the value of the subscribed key is changed and the  **flush\(\)**  method is executed,  **StorageObserver**  will be invoked.

**Table  5**  APIs for subscribing to data changes

<a name="table6483954112110"></a>
<table><thead align="left"><tr id="row124847540217"><th class="cellrowborder" valign="top" width="17.849999999999998%" id="mcps1.2.4.1.1"><p id="p1210134212816"><a name="p1210134212816"></a><a name="p1210134212816"></a>Class</p>
</th>
<th class="cellrowborder" valign="top" width="42.34%" id="mcps1.2.4.1.2"><p id="p1848445472111"><a name="p1848445472111"></a><a name="p1848445472111"></a>Method</p>
</th>
<th class="cellrowborder" valign="top" width="39.81%" id="mcps1.2.4.1.3"><p id="p1848475414213"><a name="p1848475414213"></a><a name="p1848475414213"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2048513546212"><td class="cellrowborder" valign="top" width="17.849999999999998%" headers="mcps1.2.4.1.1 "><p id="p17210342586"><a name="p17210342586"></a><a name="p17210342586"></a>Storage</p>
</td>
<td class="cellrowborder" valign="top" width="42.34%" headers="mcps1.2.4.1.2 "><p id="p124859540219"><a name="p124859540219"></a><a name="p124859540219"></a>on(type: 'change', callback: Callback&lt;StorageObserver&gt;): void;</p>
</td>
<td class="cellrowborder" valign="top" width="39.81%" headers="mcps1.2.4.1.3 "><p id="p1148505452114"><a name="p1148505452114"></a><a name="p1148505452114"></a>Subscribes to data changes.</p>
</td>
</tr>
<tr id="row24851554182111"><td class="cellrowborder" valign="top" width="17.849999999999998%" headers="mcps1.2.4.1.1 "><p id="p914241031014"><a name="p914241031014"></a><a name="p914241031014"></a>Storage</p>
</td>
<td class="cellrowborder" valign="top" width="42.34%" headers="mcps1.2.4.1.2 "><p id="p9929202151011"><a name="p9929202151011"></a><a name="p9929202151011"></a>off(type: 'change', callback: Callback&lt;StorageObserver&gt;): void;</p>
</td>
<td class="cellrowborder" valign="top" width="39.81%" headers="mcps1.2.4.1.3 "><p id="p54853548219"><a name="p54853548219"></a><a name="p54853548219"></a>Unsubscribes from data changes.</p>
</td>
</tr>
</tbody>
</table>

**Deleting Data**

Use the following APIs to delete a  **Storage**  instance or data file.

**Table  6**  APIs for deleting data

<a name="table2445155152418"></a>
<table><thead align="left"><tr id="row164451856244"><th class="cellrowborder" valign="top" width="17.72%" id="mcps1.2.4.1.1"><p id="p8182648181513"><a name="p8182648181513"></a><a name="p8182648181513"></a>Package Name</p>
</th>
<th class="cellrowborder" valign="top" width="43.980000000000004%" id="mcps1.2.4.1.2"><p id="p184461952245"><a name="p184461952245"></a><a name="p184461952245"></a>Method</p>
</th>
<th class="cellrowborder" valign="top" width="38.3%" id="mcps1.2.4.1.3"><p id="p11446652246"><a name="p11446652246"></a><a name="p11446652246"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1644616517249"><td class="cellrowborder" valign="top" width="17.72%" headers="mcps1.2.4.1.1 "><p id="p318244815153"><a name="p318244815153"></a><a name="p318244815153"></a>ohos.data.storage</p>
</td>
<td class="cellrowborder" valign="top" width="43.980000000000004%" headers="mcps1.2.4.1.2 "><p id="p194461457246"><a name="p194461457246"></a><a name="p194461457246"></a>deleteStorage(path: string): Promise&lt;void&gt;;</p>
</td>
<td class="cellrowborder" valign="top" width="38.3%" headers="mcps1.2.4.1.3 "><p id="p19291149141220"><a name="p19291149141220"></a><a name="p19291149141220"></a>Deletes a <strong id="b16577722115210"><a name="b16577722115210"></a><a name="b16577722115210"></a>Storage</strong> instance from the cache and deletes its file from the device.</p>
</td>
</tr>
<tr id="row64461551242"><td class="cellrowborder" valign="top" width="17.72%" headers="mcps1.2.4.1.1 "><p id="p1918314488153"><a name="p1918314488153"></a><a name="p1918314488153"></a>ohos.data.storage</p>
</td>
<td class="cellrowborder" valign="top" width="43.980000000000004%" headers="mcps1.2.4.1.2 "><p id="p134467513248"><a name="p134467513248"></a><a name="p134467513248"></a>removeStorageFromCache(path: string): Promise&lt;void&gt;;</p>
</td>
<td class="cellrowborder" valign="top" width="38.3%" headers="mcps1.2.4.1.3 "><p id="p164461159247"><a name="p164461159247"></a><a name="p164461159247"></a>Deletes a <strong id="b12971117115417"><a name="b12971117115417"></a><a name="b12971117115417"></a>Storage</strong> instance from the cache to release memory.</p>
</td>
</tr>
</tbody>
</table>

## How to Develop<a name="section146940394256"></a>

1.  Import  **@ohos.data.storage**  and related modules to the development environment.

    ```
    import dataStorage from '@ohos.data.storage'
    import featureAbility from '@ohos.ability.featureAbility'  // Used to obtain the file storage path.
    ```

2.  Create a  **Storage**  instance.

    Read the specified file and load its data to the  **Storage**  instance for data operations.

    ```
    var context = featureAbility.getContext()
    var path = await context.getFilesDir()
    let promise = dataStorage.getStorage(path + '/mystore')
    ```


1.  Write data.

    Use the  **put\(\)**  method of the  **Storage**  class to write data to the cached  **Storage**  instance.

    ```
    promise.then((storage) => {
        let getPromise = storage.put('startup', 'auto') // Save data to the Storage instance.
        getPromise.then(() => {
            console.info("Put the value of startup successfully.")
        }).catch((err) => {
            console.info("Put the value of startup failed with err: " + err)
        })
    }).catch((err) => {
        console.info("Get the storage failed")
    })
    ```


1.  Read data.

    Use the  **get\(\)**  method of the  **Storage**  class to read data.

    ```
    promise.then((storage) => {
        let getPromise = storage.get('startup', 'default')
        getPromise.then((value) => {
            console.info("The value of startup is " + value)
        }).catch((err) => {
            console.info("Get the value of startup failed with err: " + err)
        })
    }).catch((err) => {
        console.info("Get the storage failed")
    })
    ```


1.  Store data persistently.

    Use the  **flush**  or  **flushSync**  method to flush data in the  **Storage**  instance to its file.

    ```
    storage.flush();
    ```

2.  Observe data changes.

    Specify  **StorageObserver**  as the callback to subscribe to data changes for an application. When the value of the subscribed key is changed and the  **flush\(\)**  method is executed,  **StorageObserver**  will be invoked. Unregister the  **StorageObserver**  when it is no longer required.

    ```
    promise.then((storage) => {
        var observer = function (key) {
            console.info("The key of " + key + " changed.")
        }
        storage.on('change', observer)
        storage.putSync('startup', 'auto') // Modify data in the Storage instance.
        storage.flushSync() // Trigger the StorageObserver callback.
    
        storage.off(...change..., observer) // Unsubscribe from the data changes.
    }).catch((err) => {
        console.info("Get the storage failed")
    })
    ```


1.  Delete the specified file.

    Use the  **deleteStorage**  method to delete the  **Storage**  singleton of the specified file from the memory, and delete the specified file, its backup file, and damaged files. After the specified files are deleted, the application cannot use that instance to perform any data operation. Otherwise, data inconsistency will occur. The deleted data and files cannot be restored.

    ```
    let promise = dataStorage.deleteStorage(path + '/mystore')
    promise.then(() => {
        console.info("Deleted successfully.")
    }).catch((err) => {
        console.info("Deleted failed with err: " + err)
    })
    ```


