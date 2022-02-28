# Lightweight Storage<a name="EN-US_TOPIC_0000001154532408"></a>

Lightweight storage provides applications with data processing capability and allows applications to perform lightweight data storage and query. Data is stored in key-value pairs. Keys are of the string type, and values can be of the numeric, string, or Boolean type.

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import<a name="s56d19203690d4782bfc74069abb6bd71"></a>

```
import dataStorage from '@ohos.data.storage'
```

## System Capabilities
SystemCapability.DistributedDataManager.Preference.Core

## Required Permissions<a name="section11257113618419"></a>

None

## Attributes<a name="section7299123218370"></a>

<a name="table1540155452420"></a>
<table><thead align="left"><tr id="row1947713549244"><th class="cellrowborder" valign="top" width="22.720000000000002%" id="mcps1.1.6.1.1"><p id="p74771754102410"><a name="p74771754102410"></a><a name="p74771754102410"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="12.839999999999998%" id="mcps1.1.6.1.2"><p id="p1047755412411"><a name="p1047755412411"></a><a name="p1047755412411"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="10.97%" id="mcps1.1.6.1.3"><p id="p34782054192412"><a name="p34782054192412"></a><a name="p34782054192412"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="8.95%" id="mcps1.1.6.1.4"><p id="p1847865452413"><a name="p1847865452413"></a><a name="p1847865452413"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="44.519999999999996%" id="mcps1.1.6.1.5"><p id="p12478954132419"><a name="p12478954132419"></a><a name="p12478954132419"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1247811541240"><td class="cellrowborder" valign="top" width="22.720000000000002%" headers="mcps1.1.6.1.1 "><p id="p51525360147"><a name="p51525360147"></a><a name="p51525360147"></a>MAX_KEY_LENGTH</p>
</td>
<td class="cellrowborder" valign="top" width="12.839999999999998%" headers="mcps1.1.6.1.2 "><p id="p9478135414243"><a name="p9478135414243"></a><a name="p9478135414243"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.97%" headers="mcps1.1.6.1.3 "><p id="p1247885492411"><a name="p1247885492411"></a><a name="p1247885492411"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="8.95%" headers="mcps1.1.6.1.4 "><p id="p3478054192416"><a name="p3478054192416"></a><a name="p3478054192416"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="44.519999999999996%" headers="mcps1.1.6.1.5 "><p id="p12478654172415"><a name="p12478654172415"></a><a name="p12478654172415"></a>Maximum length of a key. It is 80 bytes.</p>
</td>
</tr>
<tr id="row184789546249"><td class="cellrowborder" valign="top" width="22.720000000000002%" headers="mcps1.1.6.1.1 "><p id="p1971014525154"><a name="p1971014525154"></a><a name="p1971014525154"></a>MAX_VALUE_LENGTH</p>
</td>
<td class="cellrowborder" valign="top" width="12.839999999999998%" headers="mcps1.1.6.1.2 "><p id="p1392172791820"><a name="p1392172791820"></a><a name="p1392172791820"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.97%" headers="mcps1.1.6.1.3 "><p id="p1870905231512"><a name="p1870905231512"></a><a name="p1870905231512"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="8.95%" headers="mcps1.1.6.1.4 "><p id="p137081152141516"><a name="p137081152141516"></a><a name="p137081152141516"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="44.519999999999996%" headers="mcps1.1.6.1.5 "><p id="p1470645211154"><a name="p1470645211154"></a><a name="p1470645211154"></a>Maximum length of a value of the string type. It is 8192 bytes.</p>
</td>
</tr>
</tbody>
</table>

## dataStorage.getStorageSync<a name="section172447329132"></a>

getStorageSync\(path: string\): Storage

Reads a specified file and loads the data to the  **Storage**  instance for data operations in synchronous mode.

-   Parameters

    <a name="table2720134112170"></a>
    <table><thead align="left"><tr id="row18721041131710"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p19721184111716"><a name="p19721184111716"></a><a name="p19721184111716"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p672184171715"><a name="p672184171715"></a><a name="p672184171715"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p972174116173"><a name="p972174116173"></a><a name="p972174116173"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1372134161712"><a name="p1372134161712"></a><a name="p1372134161712"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row11721541121717"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1472154117175"><a name="p1472154117175"></a><a name="p1472154117175"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p372134110175"><a name="p372134110175"></a><a name="p372134110175"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p19721134101713"><a name="p19721134101713"></a><a name="p19721134101713"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1068312615010"><a name="p1068312615010"></a><a name="p1068312615010"></a>Storage path of the application internal data</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table372204131719"></a>
    <table><thead align="left"><tr id="row8722124116175"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p4722041171712"><a name="p4722041171712"></a><a name="p4722041171712"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p072234114173"><a name="p072234114173"></a><a name="p072234114173"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row4722144111715"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p16723164161713"><a name="p16723164161713"></a><a name="p16723164161713"></a><a href="#section12882825611">Storage</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p12723741161713"><a name="p12723741161713"></a><a name="p12723741161713"></a><strong id="b1665811064019"><a name="b1665811064019"></a><a name="b1665811064019"></a>Storage</strong> instance used for data storage operations</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example:

    ```
    import dataStorage from '@ohos.data.storage'
    import featureAbility from '@ohos.ability.featureAbility'
    
    (async () => {
      var context = featureAbility.getContext()
      var path = await context.getFilesDir()
      let storage = dataStorage.getStorageSync(path + '/mystore')
      storage.putSync('startup', 'auto')
      storage.flushSync()
  })()
    ```


## dataStorage.getStorage<a name="section192192415554"></a>

getStorage\(path: string, callback: AsyncCallback<Storage\>\): void

Reads a specified file and loads the data to the  **Storage**  instance for data operations. This method uses a callback to return the execution result.

-   Parameters

    <a name="table69661135912"></a>
    <table><thead align="left"><tr id="row149668318915"><th class="cellrowborder" valign="top" width="14.451487079473427%" id="mcps1.1.5.1.1"><p id="p7966738914"><a name="p7966738914"></a><a name="p7966738914"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="25.42174549000487%" id="mcps1.1.5.1.2"><p id="p296713699"><a name="p296713699"></a><a name="p296713699"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.511945392491468%" id="mcps1.1.5.1.3"><p id="p196718315911"><a name="p196718315911"></a><a name="p196718315911"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="49.614822038030226%" id="mcps1.1.5.1.4"><p id="p9967231197"><a name="p9967231197"></a><a name="p9967231197"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row99671533914"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p79671633910"><a name="p79671633910"></a><a name="p79671633910"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.42174549000487%" headers="mcps1.1.5.1.2 "><p id="p11967433914"><a name="p11967433914"></a><a name="p11967433914"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.511945392491468%" headers="mcps1.1.5.1.3 "><p id="p19671336916"><a name="p19671336916"></a><a name="p19671336916"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.614822038030226%" headers="mcps1.1.5.1.4 "><p id="p77021147102715"><a name="p77021147102715"></a><a name="p77021147102715"></a>Storage path of the application internal data</p>
    </td>
    </tr>
    <tr id="row128961021101812"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p6897172121814"><a name="p6897172121814"></a><a name="p6897172121814"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.42174549000487%" headers="mcps1.1.5.1.2 "><p id="p9897102181813"><a name="p9897102181813"></a><a name="p9897102181813"></a>AsyncCallback&lt;<a href="#section12882825611">Storage</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.511945392491468%" headers="mcps1.1.5.1.3 "><p id="p188982219189"><a name="p188982219189"></a><a name="p188982219189"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.614822038030226%" headers="mcps1.1.5.1.4 "><p id="p989815213187"><a name="p989815213187"></a><a name="p989815213187"></a>Callback used to return the result.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example:

    ```
    import dataStorage from '@ohos.data.storage'
    import featureAbility from '@ohos.ability.featureAbility'
    
    (async () => {
      var context = featureAbility.getContext()
      var path = await context.getFilesDir()
      dataStorage.getStorage(path + '/mystore', function (err, storage) {
        if (err) {
            console.info("Get the storage failed, path: " + path + '/mystore')
            return;
        }
        storage.putSync('startup', 'auto')
        storage.flushSync()
    })
  })()
    ```


## dataStorage.getStorage<a name="section761705115251"></a>

getStorage\(path: string\): Promise<Storage\>

Reads a specified file and loads the data to the  **Storage**  instance for data operations. This method uses a promise to return the execution result.

-   Parameters

    <a name="table206180511253"></a>
    <table><thead align="left"><tr id="row126181951152513"><th class="cellrowborder" valign="top" width="14.451487079473427%" id="mcps1.1.5.1.1"><p id="p20618155112513"><a name="p20618155112513"></a><a name="p20618155112513"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.700633837152608%" id="mcps1.1.5.1.2"><p id="p561885114256"><a name="p561885114256"></a><a name="p561885114256"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.628961482203803%" id="mcps1.1.5.1.3"><p id="p561814519259"><a name="p561814519259"></a><a name="p561814519259"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.21891760117016%" id="mcps1.1.5.1.4"><p id="p1861845120252"><a name="p1861845120252"></a><a name="p1861845120252"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row6619751162515"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p196192514253"><a name="p196192514253"></a><a name="p196192514253"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.700633837152608%" headers="mcps1.1.5.1.2 "><p id="p36191951162515"><a name="p36191951162515"></a><a name="p36191951162515"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.628961482203803%" headers="mcps1.1.5.1.3 "><p id="p16191051162511"><a name="p16191051162511"></a><a name="p16191051162511"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.21891760117016%" headers="mcps1.1.5.1.4 "><p id="p7722105418272"><a name="p7722105418272"></a><a name="p7722105418272"></a>Storage path of the application internal data</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table2619551122516"></a>
    <table><thead align="left"><tr id="row46201751152513"><th class="cellrowborder" valign="top" width="30.44%" id="mcps1.1.3.1.1"><p id="p1162075110255"><a name="p1162075110255"></a><a name="p1162075110255"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.56%" id="mcps1.1.3.1.2"><p id="p46202512251"><a name="p46202512251"></a><a name="p46202512251"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row562015514258"><td class="cellrowborder" valign="top" width="30.44%" headers="mcps1.1.3.1.1 "><p id="p146201551122516"><a name="p146201551122516"></a><a name="p146201551122516"></a>Promise&lt;<a href="#section12882825611">Storage</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="69.56%" headers="mcps1.1.3.1.2 "><p id="p1062005172514"><a name="p1062005172514"></a><a name="p1062005172514"></a>Promise used to return the result.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example:

    ```
    import dataStorage from '@ohos.data.storage'
    import featureAbility from '@ohos.ability.featureAbility'
    
    (async () => {
      var context = featureAbility.getContext()
      var path = await context.getFilesDir()
      let promise = dataStorage.getStorage(path + '/mystore')
      promise.then((storage) => {
        storage.putSync('startup', 'auto')
        storage.flushSync()
    }).catch((err) => {
        console.info("Get the storage failed, path: " + path + '/mystore')
    })
  }()
    ```


## dataStorage.deleteStorageSync<a name="section1396463815379"></a>

deleteStorageSync\(path: string\): void

Removes the singleton  **Storage**  instance of the specified file from the memory, and deletes the specified file, its backup file, and damaged files. After the specified file is deleted, the  **Storage**  instance cannot be used to perform any data operation. Otherwise, data inconsistency will occur. This method uses a synchronous mode.

-   Parameters

    <a name="table99651538193711"></a>
    <table><thead align="left"><tr id="row1296553843712"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p19965183833714"><a name="p19965183833714"></a><a name="p19965183833714"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p9965153863713"><a name="p9965153863713"></a><a name="p9965153863713"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p15965133819375"><a name="p15965133819375"></a><a name="p15965133819375"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p496518383377"><a name="p496518383377"></a><a name="p496518383377"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row6965238143718"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p18965163816378"><a name="p18965163816378"></a><a name="p18965163816378"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p10965193816372"><a name="p10965193816372"></a><a name="p10965193816372"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p896623833719"><a name="p896623833719"></a><a name="p896623833719"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p157012058162714"><a name="p157012058162714"></a><a name="p157012058162714"></a>Storage path of the application internal data</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example:

    ```
    dataStorage.deleteStorageSync(path + '/mystore')
    ```


## dataStorage.deleteStorage<a name="section17967123883712"></a>

deleteStorage\(path: string, callback: AsyncCallback<void\>\)

Removes the singleton  **Storage**  instance of the specified file from the memory, and deletes the specified file, its backup file, and damaged files. After the specified file is deleted, the  **Storage**  instance cannot be used to perform any data operation. Otherwise, data inconsistency will occur. This method uses an asynchronous callback to return the execution result.

-   Parameters

    <a name="table1296893843713"></a>
    <table><thead align="left"><tr id="row5968193863710"><th class="cellrowborder" valign="top" width="11.59434422233057%" id="mcps1.1.5.1.1"><p id="p99681338103714"><a name="p99681338103714"></a><a name="p99681338103714"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="25.67528035104826%" id="mcps1.1.5.1.2"><p id="p1968838123715"><a name="p1968838123715"></a><a name="p1968838123715"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.3373963920039%" id="mcps1.1.5.1.3"><p id="p14968123803720"><a name="p14968123803720"></a><a name="p14968123803720"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="54.39297903461725%" id="mcps1.1.5.1.4"><p id="p7968238143715"><a name="p7968238143715"></a><a name="p7968238143715"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row129691538133719"><td class="cellrowborder" valign="top" width="11.59434422233057%" headers="mcps1.1.5.1.1 "><p id="p14969438143718"><a name="p14969438143718"></a><a name="p14969438143718"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.67528035104826%" headers="mcps1.1.5.1.2 "><p id="p9969123873716"><a name="p9969123873716"></a><a name="p9969123873716"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.3373963920039%" headers="mcps1.1.5.1.3 "><p id="p159691438173711"><a name="p159691438173711"></a><a name="p159691438173711"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="54.39297903461725%" headers="mcps1.1.5.1.4 "><p id="p06171654601"><a name="p06171654601"></a><a name="p06171654601"></a>Storage path of the application internal data</p>
    </td>
    </tr>
    <tr id="row9969173819374"><td class="cellrowborder" valign="top" width="11.59434422233057%" headers="mcps1.1.5.1.1 "><p id="p69691238153715"><a name="p69691238153715"></a><a name="p69691238153715"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.67528035104826%" headers="mcps1.1.5.1.2 "><p id="p149691380378"><a name="p149691380378"></a><a name="p149691380378"></a>AsyncCallback&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.3373963920039%" headers="mcps1.1.5.1.3 "><p id="p2969103843715"><a name="p2969103843715"></a><a name="p2969103843715"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="54.39297903461725%" headers="mcps1.1.5.1.4 "><p id="p396915388374"><a name="p396915388374"></a><a name="p396915388374"></a>Callback used to return the result.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example:

    ```
    dataStorage.deleteStorage(path + '/mystore', function (err) {
        if (err) {
            console.info("Deleted failed with err: " + err)
            return
        }
        console.info("Deleted successfully.")
    })
    ```


## dataStorage.deleteStorage<a name="section1497163823719"></a>

deleteStorage\(path: string\): Promise<void\>

Removes the singleton  **Storage**  instance of the specified file from the memory, and deletes the specified file, its backup file, and damaged files. After the specified file is deleted, the  **Storage**  instance cannot be used to perform any data operation. Otherwise, data inconsistency will occur. This method uses a promise to return the execution result.

-   Parameters

    <a name="table597293815378"></a>
    <table><thead align="left"><tr id="row29721938203716"><th class="cellrowborder" valign="top" width="14.451487079473427%" id="mcps1.1.5.1.1"><p id="p19972173883714"><a name="p19972173883714"></a><a name="p19972173883714"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="18.95660653339834%" id="mcps1.1.5.1.2"><p id="p49721938103718"><a name="p49721938103718"></a><a name="p49721938103718"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.825938566552901%" id="mcps1.1.5.1.3"><p id="p17972113863711"><a name="p17972113863711"></a><a name="p17972113863711"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.76596782057533%" id="mcps1.1.5.1.4"><p id="p15972838123714"><a name="p15972838123714"></a><a name="p15972838123714"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1972163818374"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p597373833717"><a name="p597373833717"></a><a name="p597373833717"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="p11973173814378"><a name="p11973173814378"></a><a name="p11973173814378"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="p209732388379"><a name="p209732388379"></a><a name="p209732388379"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="p7812982288"><a name="p7812982288"></a><a name="p7812982288"></a>Storage path of the application internal data</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table5973738153710"></a>
    <table><thead align="left"><tr id="row17973238123713"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p17973538183719"><a name="p17973538183719"></a><a name="p17973538183719"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p109731385374"><a name="p109731385374"></a><a name="p109731385374"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row89731838173711"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p34467362719"><a name="p34467362719"></a><a name="p34467362719"></a>Promise&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p15446536474"><a name="p15446536474"></a><a name="p15446536474"></a>Promise used to return the result.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example:

    ```
    let promise = dataStorage.deleteStorage(path + '/mystore')
    promise.then(() => {
        console.info("Deleted successfully.")
    }).catch((err) => {
        console.info("Deleted failed with err: " + err)
    })
    ```


## dataStorage.removeStorageFromCacheSync<a name="section1212418572425"></a>

removeStorageFromCacheSync\(path: string\): void

Removes the singleton  **Storage**  instance of the specified file from the memory. The removed instance cannot be used for data operations. Otherwise, data inconsistency will occur.

This method uses a synchronous mode.

-   Parameters

    <a name="table121245571424"></a>
    <table><thead align="left"><tr id="row61241257164218"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p13125165744216"><a name="p13125165744216"></a><a name="p13125165744216"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p141259575429"><a name="p141259575429"></a><a name="p141259575429"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p1312515724213"><a name="p1312515724213"></a><a name="p1312515724213"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p6125157124212"><a name="p6125157124212"></a><a name="p6125157124212"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1112595715421"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1712610572429"><a name="p1712610572429"></a><a name="p1712610572429"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p5126457164217"><a name="p5126457164217"></a><a name="p5126457164217"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p19126457134212"><a name="p19126457134212"></a><a name="p19126457134212"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1724911392818"><a name="p1724911392818"></a><a name="p1724911392818"></a>Storage path of the application internal data</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example:

    ```
    dataStorage.removeStorageFromCacheSync(path + '/mystore')
    ```


## dataStorage.removeStorageFromCache<a name="section141288570429"></a>

removeStorageFromCache\(path: string, callback: AsyncCallback<Storage\>\): void

Removes the singleton  **Storage**  instance of the specified file from the memory. The removed instance cannot be used for data operations. Otherwise, data inconsistency will occur.

This method uses an asynchronous mode.

-   Parameters

    <a name="table12128115713423"></a>
    <table><thead align="left"><tr id="row131291857124212"><th class="cellrowborder" valign="top" width="14.451487079473427%" id="mcps1.1.5.1.1"><p id="p181291157174220"><a name="p181291157174220"></a><a name="p181291157174220"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="25.29497805948318%" id="mcps1.1.5.1.2"><p id="p20129205715426"><a name="p20129205715426"></a><a name="p20129205715426"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.664553876157972%" id="mcps1.1.5.1.3"><p id="p21294574428"><a name="p21294574428"></a><a name="p21294574428"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="52.58898098488542%" id="mcps1.1.5.1.4"><p id="p512965716425"><a name="p512965716425"></a><a name="p512965716425"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row21299574423"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p17129105714421"><a name="p17129105714421"></a><a name="p17129105714421"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.29497805948318%" headers="mcps1.1.5.1.2 "><p id="p7129185794217"><a name="p7129185794217"></a><a name="p7129185794217"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.664553876157972%" headers="mcps1.1.5.1.3 "><p id="p813075717426"><a name="p813075717426"></a><a name="p813075717426"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="52.58898098488542%" headers="mcps1.1.5.1.4 "><p id="p3442141014113"><a name="p3442141014113"></a><a name="p3442141014113"></a>Storage path of the application internal data</p>
    </td>
    </tr>
    <tr id="row1813015717423"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p813085711421"><a name="p813085711421"></a><a name="p813085711421"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.29497805948318%" headers="mcps1.1.5.1.2 "><p id="p013085719427"><a name="p013085719427"></a><a name="p013085719427"></a>AsyncCallback&lt;<a href="#section12882825611">Storage</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.664553876157972%" headers="mcps1.1.5.1.3 "><p id="p181301457184219"><a name="p181301457184219"></a><a name="p181301457184219"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="52.58898098488542%" headers="mcps1.1.5.1.4 "><p id="p191301575425"><a name="p191301575425"></a><a name="p191301575425"></a>Callback used to return the result.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example:

    ```
    dataStorage.removeStorageFromCache(path + '/mystore', function (err) {
        if (err) {
            console.info("Removed storage from cache failed with err: " + err)
            return
        }
        console.info("Removed storage from cache successfully.")
    })
    ```


## dataStorage.removeStorageFromCache<a name="section1813245718422"></a>

removeStorageFromCache\(path: string\): Promise<void\>

Removes the singleton  **Storage**  instance of the specified file from the memory. The removed instance cannot be used for data operations. Otherwise, data inconsistency will occur.

This method uses an asynchronous mode.

-   Parameters

    <a name="table2133125713429"></a>
    <table><thead align="left"><tr id="row9133857194218"><th class="cellrowborder" valign="top" width="14.451487079473427%" id="mcps1.1.5.1.1"><p id="p813355716423"><a name="p813355716423"></a><a name="p813355716423"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="18.95660653339834%" id="mcps1.1.5.1.2"><p id="p213495712420"><a name="p213495712420"></a><a name="p213495712420"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.825938566552901%" id="mcps1.1.5.1.3"><p id="p713465724210"><a name="p713465724210"></a><a name="p713465724210"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.76596782057533%" id="mcps1.1.5.1.4"><p id="p413425734218"><a name="p413425734218"></a><a name="p413425734218"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row0134105716421"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p14134135744212"><a name="p14134135744212"></a><a name="p14134135744212"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="p613417578427"><a name="p613417578427"></a><a name="p613417578427"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="p313555724217"><a name="p313555724217"></a><a name="p313555724217"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="p88981021172812"><a name="p88981021172812"></a><a name="p88981021172812"></a>Storage path of the application internal data</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table513585718424"></a>
    <table><thead align="left"><tr id="row191352576429"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p51351257104220"><a name="p51351257104220"></a><a name="p51351257104220"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p113611571421"><a name="p113611571421"></a><a name="p113611571421"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row0136165744213"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p159416454718"><a name="p159416454718"></a><a name="p159416454718"></a>Promise&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p13941645472"><a name="p13941645472"></a><a name="p13941645472"></a>Promise used to return the result.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example:

    ```
    let promise = dataStorage.removeStorageFromCache(path + '/mystore')
    promise.then(() => {
        console.info("Removed storage from cache successfully.")
    }).catch((err) => {
        console.info("Removed storage from cache failed with err: " + err)
    })
    ```


## Storage<a name="section12882825611"></a>

Provides APIs for obtaining and modifying storage data.

### getSync<a name="section1984422131910"></a>

getSync\(key: string, defValue: ValueType\): ValueType

Obtains the value corresponding to a key. If the value is null or not in the default value format, the default value is returned.

This method uses a synchronous mode.

-   Parameters

    <a name="table134047259197"></a>
    <table><thead align="left"><tr id="row134041225191915"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p7404172513199"><a name="p7404172513199"></a><a name="p7404172513199"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p1740422518197"><a name="p1740422518197"></a><a name="p1740422518197"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p18404122513192"><a name="p18404122513192"></a><a name="p18404122513192"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p2404025121912"><a name="p2404025121912"></a><a name="p2404025121912"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row20404172517195"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p3404625101912"><a name="p3404625101912"></a><a name="p3404625101912"></a>key</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p114047255192"><a name="p114047255192"></a><a name="p114047255192"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p10404162571912"><a name="p10404162571912"></a><a name="p10404162571912"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p10404192513199"><a name="p10404192513199"></a><a name="p10404192513199"></a>Key of the data. It cannot be empty.</p>
    </td>
    </tr>
    <tr id="row1740492512196"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1540432551910"><a name="p1540432551910"></a><a name="p1540432551910"></a>defValue</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p8404102516199"><a name="p8404102516199"></a><a name="p8404102516199"></a>ValueType</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p6405202516196"><a name="p6405202516196"></a><a name="p6405202516196"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1140502514190"><a name="p1140502514190"></a><a name="p1140502514190"></a>Default value to be returned if the value of the specified key does not exist. The value can be a number, string, or Boolean value.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table432284131914"></a>
    <table><thead align="left"><tr id="row14322941161913"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p83221416199"><a name="p83221416199"></a><a name="p83221416199"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p732219418192"><a name="p732219418192"></a><a name="p732219418192"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row63221941101918"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p932204131910"><a name="p932204131910"></a><a name="p932204131910"></a>ValueType</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p1832294181917"><a name="p1832294181917"></a><a name="p1832294181917"></a>Value corresponding to the specified key. If the value is null or not in the default value format, the default value is returned.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example:

    ```
    let value = storage.getSync('startup', 'default')
    console.info("The value of startup is " + value)
    ```


### get<a name="section12293161972016"></a>

get\(key: string, defValue: ValueType, callback: AsyncCallback<ValueType\>\): void

Obtains the value corresponding to a key. If the value is null or not in the default value format, the default value is returned.

This method uses an asynchronous mode.

-   Parameters

    <a name="table4937172922016"></a>
    <table><thead align="left"><tr id="row3937162917202"><th class="cellrowborder" valign="top" width="14.451487079473427%" id="mcps1.1.5.1.1"><p id="p39377296202"><a name="p39377296202"></a><a name="p39377296202"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="18.95660653339834%" id="mcps1.1.5.1.2"><p id="p1093712917202"><a name="p1093712917202"></a><a name="p1093712917202"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.825938566552901%" id="mcps1.1.5.1.3"><p id="p5937142915201"><a name="p5937142915201"></a><a name="p5937142915201"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.76596782057533%" id="mcps1.1.5.1.4"><p id="p693722972018"><a name="p693722972018"></a><a name="p693722972018"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row0937829202013"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p1993718293203"><a name="p1993718293203"></a><a name="p1993718293203"></a>key</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="p1937122922018"><a name="p1937122922018"></a><a name="p1937122922018"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="p10937152962019"><a name="p10937152962019"></a><a name="p10937152962019"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="p793710294206"><a name="p793710294206"></a><a name="p793710294206"></a>Key of the data. It cannot be empty.</p>
    </td>
    </tr>
    <tr id="row1293752912012"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p1893714292206"><a name="p1893714292206"></a><a name="p1893714292206"></a>defValue</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="p119371729132012"><a name="p119371729132012"></a><a name="p119371729132012"></a>ValueType</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="p12937429102016"><a name="p12937429102016"></a><a name="p12937429102016"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="p129372299204"><a name="p129372299204"></a><a name="p129372299204"></a>Default value to be returned. The value can be a number, string, or Boolean value.</p>
    </td>
    </tr>
    <tr id="row109381229142014"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p1693815299207"><a name="p1693815299207"></a><a name="p1693815299207"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="p15938329142010"><a name="p15938329142010"></a><a name="p15938329142010"></a>AsyncCallback&lt;ValueType&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="p10938929162017"><a name="p10938929162017"></a><a name="p10938929162017"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="p893812912201"><a name="p893812912201"></a><a name="p893812912201"></a>Callback used to return the result.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example:

    ```
    storage.get('startup', 'default', function(err, value) {
        if (err) {
            console.info("Get the value of startup failed with err: " + err)
            return
        }
        console.info("The value of startup is " + value)
    })
    ```


### get<a name="section18984643152118"></a>

get\(key: string, defValue: ValueType\): Promise<ValueType\>

Obtains the value corresponding to a key. If the value is null or not in the default value format, the default value is returned.

This method uses an asynchronous mode.

-   Parameters

    <a name="table18177853162110"></a>
    <table><thead align="left"><tr id="row181781453102111"><th class="cellrowborder" valign="top" width="14.451487079473427%" id="mcps1.1.5.1.1"><p id="p13178953122112"><a name="p13178953122112"></a><a name="p13178953122112"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="18.95660653339834%" id="mcps1.1.5.1.2"><p id="p111781153172115"><a name="p111781153172115"></a><a name="p111781153172115"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.825938566552901%" id="mcps1.1.5.1.3"><p id="p5178125342118"><a name="p5178125342118"></a><a name="p5178125342118"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.76596782057533%" id="mcps1.1.5.1.4"><p id="p17178105320210"><a name="p17178105320210"></a><a name="p17178105320210"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row81781153162116"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p91786538215"><a name="p91786538215"></a><a name="p91786538215"></a>key</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="p11178105316219"><a name="p11178105316219"></a><a name="p11178105316219"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="p71781653142115"><a name="p71781653142115"></a><a name="p71781653142115"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="p717812534216"><a name="p717812534216"></a><a name="p717812534216"></a>Key of the data. It cannot be empty.</p>
    </td>
    </tr>
    <tr id="row191781653182116"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p7178185315217"><a name="p7178185315217"></a><a name="p7178185315217"></a>defValue</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="p6178105319217"><a name="p6178105319217"></a><a name="p6178105319217"></a>ValueType</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="p17178653132119"><a name="p17178653132119"></a><a name="p17178653132119"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="p817813533210"><a name="p817813533210"></a><a name="p817813533210"></a>Default value to be returned. The value can be a number, string, or Boolean value.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table17633151592210"></a>
    <table><thead align="left"><tr id="row12633615192219"><th class="cellrowborder" valign="top" width="29.59%" id="mcps1.1.3.1.1"><p id="p15633161517226"><a name="p15633161517226"></a><a name="p15633161517226"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="70.41%" id="mcps1.1.3.1.2"><p id="p106331915142212"><a name="p106331915142212"></a><a name="p106331915142212"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row14633115142215"><td class="cellrowborder" valign="top" width="29.59%" headers="mcps1.1.3.1.1 "><p id="p56331015142214"><a name="p56331015142214"></a><a name="p56331015142214"></a>Promise&lt;ValueType&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="70.41%" headers="mcps1.1.3.1.2 "><p id="p15633101522214"><a name="p15633101522214"></a><a name="p15633101522214"></a>Promise used to return the result.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example:

    ```
    let promise = storage.get('startup', 'default')
    promise.then((value) => {
        console.info("The value of startup is " + value)
    }).catch((err) => {
        console.info("Get the value of startup failed with err: " + err)
    })
    ```


### putSync<a name="section2042914810266"></a>

putSync\(key: string, value: ValueType\): void

Obtains the  **Storage**  instance corresponding to the specified file, writes data to the  **Storage**  instance using a  **Storage**  API, and saves the modification using  **flush\(\)**  or  **flushSync\(\)**.

This method uses a synchronous mode.

-   Parameters

    <a name="table18627821182614"></a>
    <table><thead align="left"><tr id="row162782182615"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p36278211263"><a name="p36278211263"></a><a name="p36278211263"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p1662732192616"><a name="p1662732192616"></a><a name="p1662732192616"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p1362762182616"><a name="p1362762182616"></a><a name="p1362762182616"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p186282218261"><a name="p186282218261"></a><a name="p186282218261"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1262810215268"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p196284210266"><a name="p196284210266"></a><a name="p196284210266"></a>key</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1462802113268"><a name="p1462802113268"></a><a name="p1462802113268"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p1628192192612"><a name="p1628192192612"></a><a name="p1628192192612"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p6628521122615"><a name="p6628521122615"></a><a name="p6628521122615"></a>Key of the data to be modified. It cannot be empty.</p>
    </td>
    </tr>
    <tr id="row5628202152619"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p8628102192617"><a name="p8628102192617"></a><a name="p8628102192617"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p66281421192620"><a name="p66281421192620"></a><a name="p66281421192620"></a>ValueType</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p96281217267"><a name="p96281217267"></a><a name="p96281217267"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p15628721142612"><a name="p15628721142612"></a><a name="p15628721142612"></a>New value. The value can be a number, string, or Boolean value.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example:

    ```
    storage.putSync('startup', 'auto')
    ```


### put<a name="section141693514276"></a>

put\(key: string, value: ValueType, callback: AsyncCallback<void\>\): void

Obtains the  **Storage**  instance corresponding to the specified file, writes data to the  **Storage**  instance using a  **Storage**  API, and saves the modification using  **flush\(\)**  or  **flushSync\(\)**.

This method uses an asynchronous mode.

-   Parameters

    <a name="table875524602811"></a>
    <table><thead align="left"><tr id="row2075518465285"><th class="cellrowborder" valign="top" width="14.451487079473427%" id="mcps1.1.5.1.1"><p id="p1075574672815"><a name="p1075574672815"></a><a name="p1075574672815"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="23.539736713798145%" id="mcps1.1.5.1.2"><p id="p6755114618283"><a name="p6755114618283"></a><a name="p6755114618283"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.4534373476353%" id="mcps1.1.5.1.3"><p id="p137551446142814"><a name="p137551446142814"></a><a name="p137551446142814"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="51.55533885909311%" id="mcps1.1.5.1.4"><p id="p1275544652813"><a name="p1275544652813"></a><a name="p1275544652813"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row7755124692813"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p17755346102818"><a name="p17755346102818"></a><a name="p17755346102818"></a>key</p>
    </td>
    <td class="cellrowborder" valign="top" width="23.539736713798145%" headers="mcps1.1.5.1.2 "><p id="p177551846172817"><a name="p177551846172817"></a><a name="p177551846172817"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.4534373476353%" headers="mcps1.1.5.1.3 "><p id="p16756946182810"><a name="p16756946182810"></a><a name="p16756946182810"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.55533885909311%" headers="mcps1.1.5.1.4 "><p id="p775614662815"><a name="p775614662815"></a><a name="p775614662815"></a>Key of the data to be modified. It cannot be empty.</p>
    </td>
    </tr>
    <tr id="row1875674613284"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p1175634652819"><a name="p1175634652819"></a><a name="p1175634652819"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="23.539736713798145%" headers="mcps1.1.5.1.2 "><p id="p37561846152814"><a name="p37561846152814"></a><a name="p37561846152814"></a>ValueType</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.4534373476353%" headers="mcps1.1.5.1.3 "><p id="p075684619281"><a name="p075684619281"></a><a name="p075684619281"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.55533885909311%" headers="mcps1.1.5.1.4 "><p id="p117561246192811"><a name="p117561246192811"></a><a name="p117561246192811"></a>New value. The value can be a number, string, or Boolean value.</p>
    </td>
    </tr>
    <tr id="row375674614288"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p14756134672812"><a name="p14756134672812"></a><a name="p14756134672812"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="23.539736713798145%" headers="mcps1.1.5.1.2 "><p id="p1075614612285"><a name="p1075614612285"></a><a name="p1075614612285"></a>AsyncCallback&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.4534373476353%" headers="mcps1.1.5.1.3 "><p id="p2756746202817"><a name="p2756746202817"></a><a name="p2756746202817"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.55533885909311%" headers="mcps1.1.5.1.4 "><p id="p375610463287"><a name="p375610463287"></a><a name="p375610463287"></a>Callback used to return the result.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example:

    ```
    storage.put('startup', 'auto', function (err) {
        if (err) {
            console.info("Put the value of startup failed with err: " + err)
            return
        }
        console.info("Put the value of startup successfully.")
    })
    ```


### put<a name="section594485413298"></a>

put\(key: string, value: ValueType\): Promise<void\>

Obtains the  **Storage**  instance corresponding to the specified file, writes data to the  **Storage**  instance using a  **Storage**  API, and saves the modification using  **flush\(\)**  or  **flushSync\(\)**.

This method uses an asynchronous mode.

-   Parameters

    <a name="table144341091305"></a>
    <table><thead align="left"><tr id="row7434691304"><th class="cellrowborder" valign="top" width="14.451487079473427%" id="mcps1.1.5.1.1"><p id="p1343429163015"><a name="p1343429163015"></a><a name="p1343429163015"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="18.95660653339834%" id="mcps1.1.5.1.2"><p id="p04349953017"><a name="p04349953017"></a><a name="p04349953017"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.825938566552901%" id="mcps1.1.5.1.3"><p id="p3434395307"><a name="p3434395307"></a><a name="p3434395307"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.76596782057533%" id="mcps1.1.5.1.4"><p id="p154349963020"><a name="p154349963020"></a><a name="p154349963020"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row16434196302"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p14345943014"><a name="p14345943014"></a><a name="p14345943014"></a>key</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="p8434159163014"><a name="p8434159163014"></a><a name="p8434159163014"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="p124341963010"><a name="p124341963010"></a><a name="p124341963010"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="p144354963019"><a name="p144354963019"></a><a name="p144354963019"></a>Key of the data to be modified. It cannot be empty.</p>
    </td>
    </tr>
    <tr id="row18435109123019"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p194354913309"><a name="p194354913309"></a><a name="p194354913309"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="p24358918307"><a name="p24358918307"></a><a name="p24358918307"></a>ValueType</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="p5435994306"><a name="p5435994306"></a><a name="p5435994306"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="p17435149123016"><a name="p17435149123016"></a><a name="p17435149123016"></a>New value. The value can be a number, string, or Boolean value.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table3877202333010"></a>
    <table><thead align="left"><tr id="row1687722319306"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p187722311304"><a name="p187722311304"></a><a name="p187722311304"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p18772239307"><a name="p18772239307"></a><a name="p18772239307"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1287820238301"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p987892315302"><a name="p987892315302"></a><a name="p987892315302"></a>Promise&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p208781523143017"><a name="p208781523143017"></a><a name="p208781523143017"></a>Promise used to return the result.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example:

    ```
    let promise = storage.put('startup', 'auto')
    promise.then(() => {
        console.info("Put the value of startup successfully.")
    }).catch((err) => {
        console.info("Put the value of startup failed with err: " + err)
    })
    ```


### hasSync<a name="section7273343143018"></a>

hasSync\(key: string\): boolean

Checks whether the storage object contains data with the specified key.

This method uses a synchronous mode.

-   Parameters

    <a name="table206971230310"></a>
    <table><thead align="left"><tr id="row13697434313"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p1169763133112"><a name="p1169763133112"></a><a name="p1169763133112"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p669716343112"><a name="p669716343112"></a><a name="p669716343112"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p1869717312318"><a name="p1869717312318"></a><a name="p1869717312318"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p146971031315"><a name="p146971031315"></a><a name="p146971031315"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row169719323119"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1269713323114"><a name="p1269713323114"></a><a name="p1269713323114"></a>key</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1697193193119"><a name="p1697193193119"></a><a name="p1697193193119"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p1669716313310"><a name="p1669716313310"></a><a name="p1669716313310"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p8697139312"><a name="p8697139312"></a><a name="p8697139312"></a>Key of the data. It cannot be empty.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table269819353119"></a>
    <table><thead align="left"><tr id="row10698153173115"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p46983317313"><a name="p46983317313"></a><a name="p46983317313"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p769815310315"><a name="p769815310315"></a><a name="p769815310315"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1769815310313"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p869833203110"><a name="p869833203110"></a><a name="p869833203110"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p166981339312"><a name="p166981339312"></a><a name="p166981339312"></a>Returns <strong id="b35918155715"><a name="b35918155715"></a><a name="b35918155715"></a>true</strong> if the storage object contains data with the specified key; returns <strong id="b105911713577"><a name="b105911713577"></a><a name="b105911713577"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example:

    ```
    let isExist = storage.hasSync('startup')
    if (isExist) {
        console.info("The key of startup is contained.")
    }
    ```


### has<a name="section185676222325"></a>

has\(key: string, callback: AsyncCallback<boolean\>\): boolean

Checks whether the storage object contains data with the specified key.

This method uses an asynchronous mode.

-   Parameters

    <a name="table1769918466400"></a>
    <table><thead align="left"><tr id="row19699194616406"><th class="cellrowborder" valign="top" width="14.451487079473427%" id="mcps1.1.5.1.1"><p id="p76991946164012"><a name="p76991946164012"></a><a name="p76991946164012"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="26.738176499268647%" id="mcps1.1.5.1.2"><p id="p669954618400"><a name="p669954618400"></a><a name="p669954618400"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.68746952705997%" id="mcps1.1.5.1.3"><p id="p136994463402"><a name="p136994463402"></a><a name="p136994463402"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="48.12286689419795%" id="mcps1.1.5.1.4"><p id="p1069984634014"><a name="p1069984634014"></a><a name="p1069984634014"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row17699646184013"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p1769917466409"><a name="p1769917466409"></a><a name="p1769917466409"></a>key</p>
    </td>
    <td class="cellrowborder" valign="top" width="26.738176499268647%" headers="mcps1.1.5.1.2 "><p id="p3699124614409"><a name="p3699124614409"></a><a name="p3699124614409"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.68746952705997%" headers="mcps1.1.5.1.3 "><p id="p176992461406"><a name="p176992461406"></a><a name="p176992461406"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="48.12286689419795%" headers="mcps1.1.5.1.4 "><p id="p14699746114020"><a name="p14699746114020"></a><a name="p14699746114020"></a>Key of the data. It cannot be empty.</p>
    </td>
    </tr>
    <tr id="row10699164684011"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p166994467401"><a name="p166994467401"></a><a name="p166994467401"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="26.738176499268647%" headers="mcps1.1.5.1.2 "><p id="p3699746194019"><a name="p3699746194019"></a><a name="p3699746194019"></a>AsyncCallback&lt;boolean&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.68746952705997%" headers="mcps1.1.5.1.3 "><p id="p8700746114012"><a name="p8700746114012"></a><a name="p8700746114012"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="48.12286689419795%" headers="mcps1.1.5.1.4 "><p id="p147004466406"><a name="p147004466406"></a><a name="p147004466406"></a>Callback used to return the result.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table1150162734110"></a>
    <table><thead align="left"><tr id="row1950110276414"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p75011227194112"><a name="p75011227194112"></a><a name="p75011227194112"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p1550192794116"><a name="p1550192794116"></a><a name="p1550192794116"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row9501627134110"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p11501112734115"><a name="p11501112734115"></a><a name="p11501112734115"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p1350212774110"><a name="p1350212774110"></a><a name="p1350212774110"></a>Returns <strong id="b1242063601510"><a name="b1242063601510"></a><a name="b1242063601510"></a>true</strong> if the storage object contains data with the specified key; returns <strong id="b1142033612155"><a name="b1142033612155"></a><a name="b1142033612155"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example:

    ```
    storage.has('startup', function (err, isExist) {
        if (err) {
            console.info("Check the key of startup failed with err: " + err)
            return
        }
        if (isExist) {
            console.info("The key of startup is contained.")
        }
    })
    ```


### has<a name="section415084610412"></a>

has\(key: string\): Promise<boolean\>

Checks whether the storage object contains data with the specified key.

This method uses an asynchronous mode.

-   Parameters

    <a name="table10418320457"></a>
    <table><thead align="left"><tr id="row15414329454"><th class="cellrowborder" valign="top" width="14.451487079473427%" id="mcps1.1.5.1.1"><p id="p6423294518"><a name="p6423294518"></a><a name="p6423294518"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="18.95660653339834%" id="mcps1.1.5.1.2"><p id="p11443274517"><a name="p11443274517"></a><a name="p11443274517"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.825938566552901%" id="mcps1.1.5.1.3"><p id="p104132164511"><a name="p104132164511"></a><a name="p104132164511"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.76596782057533%" id="mcps1.1.5.1.4"><p id="p5423224514"><a name="p5423224514"></a><a name="p5423224514"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row34732194515"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p641232154519"><a name="p641232154519"></a><a name="p641232154519"></a>key</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="p2047321454"><a name="p2047321454"></a><a name="p2047321454"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="p64203213458"><a name="p64203213458"></a><a name="p64203213458"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="p1433213456"><a name="p1433213456"></a><a name="p1433213456"></a>Key of the data. It cannot be empty.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table1120619131462"></a>
    <table><thead align="left"><tr id="row12063139466"><th class="cellrowborder" valign="top" width="30.56%" id="mcps1.1.3.1.1"><p id="p15206213154614"><a name="p15206213154614"></a><a name="p15206213154614"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.44%" id="mcps1.1.3.1.2"><p id="p1920651317466"><a name="p1920651317466"></a><a name="p1920651317466"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1620731334615"><td class="cellrowborder" valign="top" width="30.56%" headers="mcps1.1.3.1.1 "><p id="p9207161324612"><a name="p9207161324612"></a><a name="p9207161324612"></a>Promise&lt;boolean&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="69.44%" headers="mcps1.1.3.1.2 "><p id="p202076136463"><a name="p202076136463"></a><a name="p202076136463"></a>Promise used to return the result.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example:

    ```
    let promise = storage.has('startup')
    promise.then((isExist) => {
        if (isExist) {
            console.info("The key of startup is contained.")
        }
    }).catch((err) => {
        console.info("Check the key of startup failed with err: " + err)
    })
    ```


### deleteSync<a name="section31481447174613"></a>

deleteSync\(key: string\): void

Deletes the data with the specified key from this storage object.

This method uses a synchronous mode.

-   Parameters

    <a name="table733743144711"></a>
    <table><thead align="left"><tr id="row233733114710"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p18337137471"><a name="p18337137471"></a><a name="p18337137471"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p23378324711"><a name="p23378324711"></a><a name="p23378324711"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p53377324710"><a name="p53377324710"></a><a name="p53377324710"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p73371133477"><a name="p73371133477"></a><a name="p73371133477"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row733793124714"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p123378374715"><a name="p123378374715"></a><a name="p123378374715"></a>key</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p16338836476"><a name="p16338836476"></a><a name="p16338836476"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p12338193194714"><a name="p12338193194714"></a><a name="p12338193194714"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p9338731476"><a name="p9338731476"></a><a name="p9338731476"></a>Key of the data. It cannot be empty.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example:

    ```
    storage.deleteSync('startup')
    ```


### delete<a name="section31755184812"></a>

delete\(key: string, callback: AsyncCallback<void\>\): void

Deletes the data with the specified key from this storage object.

This method uses an asynchronous mode.

-   Parameters

    <a name="table1463510520490"></a>
    <table><thead align="left"><tr id="row116351594920"><th class="cellrowborder" valign="top" width="14.451487079473427%" id="mcps1.1.5.1.1"><p id="p1963515554910"><a name="p1963515554910"></a><a name="p1963515554910"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="24.48561677230619%" id="mcps1.1.5.1.2"><p id="p1263535104918"><a name="p1263535104918"></a><a name="p1263535104918"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.985372988785958%" id="mcps1.1.5.1.3"><p id="p063513511492"><a name="p063513511492"></a><a name="p063513511492"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="51.07752315943442%" id="mcps1.1.5.1.4"><p id="p463555174910"><a name="p463555174910"></a><a name="p463555174910"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row13636175124918"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p1663635174919"><a name="p1663635174919"></a><a name="p1663635174919"></a>key</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.48561677230619%" headers="mcps1.1.5.1.2 "><p id="p12636145184919"><a name="p12636145184919"></a><a name="p12636145184919"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.985372988785958%" headers="mcps1.1.5.1.3 "><p id="p76361652495"><a name="p76361652495"></a><a name="p76361652495"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.07752315943442%" headers="mcps1.1.5.1.4 "><p id="p76361658497"><a name="p76361658497"></a><a name="p76361658497"></a>Key of the data. It cannot be empty.</p>
    </td>
    </tr>
    <tr id="row96363574913"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p763616510498"><a name="p763616510498"></a><a name="p763616510498"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.48561677230619%" headers="mcps1.1.5.1.2 "><p id="p1636125174918"><a name="p1636125174918"></a><a name="p1636125174918"></a>AsyncCallback&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.985372988785958%" headers="mcps1.1.5.1.3 "><p id="p463615517491"><a name="p463615517491"></a><a name="p463615517491"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.07752315943442%" headers="mcps1.1.5.1.4 "><p id="p156361259495"><a name="p156361259495"></a><a name="p156361259495"></a>Callback used to return the result.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example:

    ```
    storage.delete('startup', function (err) {
        if (err) {
            console.info("Delete startup key failed with err: " + err)
            return
        }
        console.info("Deleted startup key successfully.")
    })
    ```


### delete<a name="section11711858125016"></a>

delete\(key: string\): Promise<void\>

Deletes the data with the specified key from this storage object.

This method uses an asynchronous mode.

-   Parameters

    <a name="table193166815517"></a>
    <table><thead align="left"><tr id="row16316784518"><th class="cellrowborder" valign="top" width="14.451487079473427%" id="mcps1.1.5.1.1"><p id="p1331615865119"><a name="p1331615865119"></a><a name="p1331615865119"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="18.95660653339834%" id="mcps1.1.5.1.2"><p id="p9316178135110"><a name="p9316178135110"></a><a name="p9316178135110"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.825938566552901%" id="mcps1.1.5.1.3"><p id="p11316158115115"><a name="p11316158115115"></a><a name="p11316158115115"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.76596782057533%" id="mcps1.1.5.1.4"><p id="p1631613812519"><a name="p1631613812519"></a><a name="p1631613812519"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1231618811515"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p1831613813513"><a name="p1831613813513"></a><a name="p1831613813513"></a>key</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.95660653339834%" headers="mcps1.1.5.1.2 "><p id="p83162805112"><a name="p83162805112"></a><a name="p83162805112"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.825938566552901%" headers="mcps1.1.5.1.3 "><p id="p43161845116"><a name="p43161845116"></a><a name="p43161845116"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.76596782057533%" headers="mcps1.1.5.1.4 "><p id="p183171819512"><a name="p183171819512"></a><a name="p183171819512"></a>Key of the data.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table6698194765112"></a>
    <table><thead align="left"><tr id="row36984478516"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p15698124745118"><a name="p15698124745118"></a><a name="p15698124745118"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p1269816474513"><a name="p1269816474513"></a><a name="p1269816474513"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row16698247205114"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p18698447105115"><a name="p18698447105115"></a><a name="p18698447105115"></a>Promise&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p36981947155117"><a name="p36981947155117"></a><a name="p36981947155117"></a>Promise used to return the result.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example:

    ```
    let promise = storage.delete('startup')
    promise.then(() => {
        console.info("Deleted startup key successfully.")
    }).catch((err) => {
        console.info("Delete startup key failed with err: " + err)
    })
    ```


### flushSync<a name="section1952191618523"></a>

flushSync\(\): void

Saves the modification of the current object to the current  **Storage**  instance and synchronizes the modification to the file.

This method uses a synchronous mode.

-   Example:

    ```
    storage.flushSync()
    ```


### flush<a name="section65806875414"></a>

flush\(callback: AsyncCallback<void\>\): void

Saves the modification of the current object to the current  **Storage**  instance and stores the modification to the file in an asynchronous mode.

This method uses an asynchronous mode.

-   Parameters

    <a name="table158501215125418"></a>
    <table><thead align="left"><tr id="row9850415125415"><th class="cellrowborder" valign="top" width="14.451487079473427%" id="mcps1.1.5.1.1"><p id="p17850115155417"><a name="p17850115155417"></a><a name="p17850115155417"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="25.041443198439783%" id="mcps1.1.5.1.2"><p id="p1585081595414"><a name="p1585081595414"></a><a name="p1585081595414"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.372013651877133%" id="mcps1.1.5.1.3"><p id="p18509157544"><a name="p18509157544"></a><a name="p18509157544"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="53.13505607020965%" id="mcps1.1.5.1.4"><p id="p785020151545"><a name="p785020151545"></a><a name="p785020151545"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row198503159545"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p785118152548"><a name="p785118152548"></a><a name="p785118152548"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.041443198439783%" headers="mcps1.1.5.1.2 "><p id="p48511715105417"><a name="p48511715105417"></a><a name="p48511715105417"></a>AsyncCallback&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.372013651877133%" headers="mcps1.1.5.1.3 "><p id="p20851201513548"><a name="p20851201513548"></a><a name="p20851201513548"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="53.13505607020965%" headers="mcps1.1.5.1.4 "><p id="p19851715105412"><a name="p19851715105412"></a><a name="p19851715105412"></a>Callback used to return the result.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example:

    ```
    storage.flush(function (err) {
        if (err) {
            console.info("Flush to file failed with err: " + err)
            return
        }
        console.info("Flushed to file successfully.")
    })
    ```


### flush<a name="section524213130551"></a>

flush\(\): Promise<void\>

Saves the modification of the current object to the current  **Storage**  instance and stores the modification to the file in an asynchronous mode.

This method uses an asynchronous mode.

-   Return values

    <a name="table197324403552"></a>
    <table><thead align="left"><tr id="row197328403555"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p1173344085511"><a name="p1173344085511"></a><a name="p1173344085511"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p87336404552"><a name="p87336404552"></a><a name="p87336404552"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row573324045513"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p773318409553"><a name="p773318409553"></a><a name="p773318409553"></a>Promise&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p1273364018550"><a name="p1273364018550"></a><a name="p1273364018550"></a>Promise used to return the result.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example:

    ```
    let promise = storage.flush()
    promise.then(() => {
        console.info("Flushed to file successfully.")
    }).catch((err) => {
        console.info("Flush to file failed with err: " + err)
    })
    ```


### clearSync<a name="section119861517115914"></a>

clearSync\(\): void

Clears all data in a storage object.

This method uses a synchronous mode.

-   Example:

    ```
    storage.clearSync()
    ```


### clear<a name="section15671520306"></a>

clear\(callback: AsyncCallback<void\>\): void

Clears all data in a storage object.

This method uses an asynchronous mode.

-   Parameters

    <a name="table84588321621"></a>
    <table><thead align="left"><tr id="row154589321724"><th class="cellrowborder" valign="top" width="14.451487079473427%" id="mcps1.1.5.1.1"><p id="p17458732925"><a name="p17458732925"></a><a name="p17458732925"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="22.837640175524133%" id="mcps1.1.5.1.2"><p id="p1945893212211"><a name="p1945893212211"></a><a name="p1945893212211"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.389566065333982%" id="mcps1.1.5.1.3"><p id="p24590321822"><a name="p24590321822"></a><a name="p24590321822"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="51.32130667966845%" id="mcps1.1.5.1.4"><p id="p194593321528"><a name="p194593321528"></a><a name="p194593321528"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row2459163212210"><td class="cellrowborder" valign="top" width="14.451487079473427%" headers="mcps1.1.5.1.1 "><p id="p11459832229"><a name="p11459832229"></a><a name="p11459832229"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.837640175524133%" headers="mcps1.1.5.1.2 "><p id="p1145913211215"><a name="p1145913211215"></a><a name="p1145913211215"></a>AsyncCallback&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.389566065333982%" headers="mcps1.1.5.1.3 "><p id="p13459183218216"><a name="p13459183218216"></a><a name="p13459183218216"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.32130667966845%" headers="mcps1.1.5.1.4 "><p id="p84590321224"><a name="p84590321224"></a><a name="p84590321224"></a>Callback used to return the result.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example:

    ```
    storage.clear(function (err) {
        if (err) {
            console.info("Clear to file failed with err: " + err)
            return
        }
        console.info("Cleared to file successfully.")
    })
    ```


### clear<a name="section21300181536"></a>

clear\(\): Promise<void\>

Clears all data in a storage object.

This method uses an asynchronous mode.

-   Return values

    <a name="table123728475316"></a>
    <table><thead align="left"><tr id="row11372947131"><th class="cellrowborder" valign="top" width="20.380000000000003%" id="mcps1.1.3.1.1"><p id="p13372104710314"><a name="p13372104710314"></a><a name="p13372104710314"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.62%" id="mcps1.1.3.1.2"><p id="p1737316471834"><a name="p1737316471834"></a><a name="p1737316471834"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row337374719310"><td class="cellrowborder" valign="top" width="20.380000000000003%" headers="mcps1.1.3.1.1 "><p id="p1937313478315"><a name="p1937313478315"></a><a name="p1937313478315"></a>Promise&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.62%" headers="mcps1.1.3.1.2 "><p id="p1337317471631"><a name="p1337317471631"></a><a name="p1337317471631"></a>Promise used to return the result.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example:

    ```
    let promise = storage.clear()
    promise.then(() => {
        console.info("Cleared to file successfully.")
    }).catch((err) => {
        console.info("Clear to file failed with err: " + err)
    })
    ```


### on \('change'\)<a name="section189332511954"></a>

on\(type: 'change', callback: Callback<StorageObserver\>\): void

Subscribes to data changes. The  **StorageObserver**  needs to be implemented. When the value of the key subscribed to is changed, a callback will be invoked after  **flush\(\)**  or  **flushSync\(\)**  is executed.

-   Parameters

    <a name="table61212334717"></a>
    <table><thead align="left"><tr id="row6122133313720"><th class="cellrowborder" valign="top" width="17.119999999999997%" id="mcps1.1.4.1.1"><p id="p112215335718"><a name="p112215335718"></a><a name="p112215335718"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="32.190000000000005%" id="mcps1.1.4.1.2"><p id="p1912223317713"><a name="p1912223317713"></a><a name="p1912223317713"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="50.690000000000005%" id="mcps1.1.4.1.3"><p id="p912219331374"><a name="p912219331374"></a><a name="p912219331374"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1412293319714"><td class="cellrowborder" valign="top" width="17.119999999999997%" headers="mcps1.1.4.1.1 "><p id="p11122203314718"><a name="p11122203314718"></a><a name="p11122203314718"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.190000000000005%" headers="mcps1.1.4.1.2 "><p id="p15941366336"><a name="p15941366336"></a><a name="p15941366336"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="50.690000000000005%" headers="mcps1.1.4.1.3 "><p id="p11227331716"><a name="p11227331716"></a><a name="p11227331716"></a>Event type. The value <strong id="b46279714239"><a name="b46279714239"></a><a name="b46279714239"></a>change</strong> indicates a data change event.</p>
    </td>
    </tr>
    <tr id="row41225333715"><td class="cellrowborder" valign="top" width="17.119999999999997%" headers="mcps1.1.4.1.1 "><p id="p11122183312719"><a name="p11122183312719"></a><a name="p11122183312719"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.190000000000005%" headers="mcps1.1.4.1.2 "><p id="p1012218331376"><a name="p1012218331376"></a><a name="p1012218331376"></a>Callback&lt;<a href="#section256244135613">StorageObserver</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="50.690000000000005%" headers="mcps1.1.4.1.3 "><p id="p181227334710"><a name="p181227334710"></a><a name="p181227334710"></a>Callback object.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example:

    ```
    var observer = function (key) {
        console.info("The key of " + key + " changed.")
    }
    storage.on('change', observer)
    storage.putSync('startup', 'auto')
    storage.flushSync()  // observer will be called.
    ```


### off \('change'\)<a name="section6421153815"></a>

off\(type: 'change', callback: Callback<StorageObserver\>\): void

Unsubscribes from data changes.

-   Parameters

    <a name="table84837251480"></a>
    <table><thead align="left"><tr id="row1648312251283"><th class="cellrowborder" valign="top" width="17.05%" id="mcps1.1.4.1.1"><p id="p1448317251186"><a name="p1448317251186"></a><a name="p1448317251186"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="32.26%" id="mcps1.1.4.1.2"><p id="p1748352512812"><a name="p1748352512812"></a><a name="p1748352512812"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="50.690000000000005%" id="mcps1.1.4.1.3"><p id="p1448382520818"><a name="p1448382520818"></a><a name="p1448382520818"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row94831251086"><td class="cellrowborder" valign="top" width="17.05%" headers="mcps1.1.4.1.1 "><p id="p348332516813"><a name="p348332516813"></a><a name="p348332516813"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.26%" headers="mcps1.1.4.1.2 "><p id="p88671011183314"><a name="p88671011183314"></a><a name="p88671011183314"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="50.690000000000005%" headers="mcps1.1.4.1.3 "><p id="p1486721113334"><a name="p1486721113334"></a><a name="p1486721113334"></a>Event type. The value <strong id="b10312165319239"><a name="b10312165319239"></a><a name="b10312165319239"></a>change</strong> indicates a data change event.</p>
    </td>
    </tr>
    <tr id="row148410251888"><td class="cellrowborder" valign="top" width="17.05%" headers="mcps1.1.4.1.1 "><p id="p9484142519818"><a name="p9484142519818"></a><a name="p9484142519818"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.26%" headers="mcps1.1.4.1.2 "><p id="p1448412251388"><a name="p1448412251388"></a><a name="p1448412251388"></a>Callback&lt;<a href="#section256244135613">StorageObserver</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="50.690000000000005%" headers="mcps1.1.4.1.3 "><p id="p34843252811"><a name="p34843252811"></a><a name="p34843252811"></a>Callback object to be canceled.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example:

    ```
    var observer = function (key) {
        console.info("The key of " + key + " changed.")
    }
    storage.off('change', observer)
    ```


## StorageObserver<a name="section256244135613"></a>

<a name="table0103172561814"></a>
<table><thead align="left"><tr id="row12103152513185"><th class="cellrowborder" valign="top" width="17.911791179117913%" id="mcps1.1.5.1.1"><p id="p1610322561817"><a name="p1610322561817"></a><a name="p1610322561817"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="12.291229122912291%" id="mcps1.1.5.1.2"><p id="p20103132551816"><a name="p20103132551816"></a><a name="p20103132551816"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="10.551055105510551%" id="mcps1.1.5.1.3"><p id="p1103172518188"><a name="p1103172518188"></a><a name="p1103172518188"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="59.245924592459254%" id="mcps1.1.5.1.4"><p id="p19103125141812"><a name="p19103125141812"></a><a name="p19103125141812"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row201031125101812"><td class="cellrowborder" valign="top" width="17.911791179117913%" headers="mcps1.1.5.1.1 "><p id="p5549181319415"><a name="p5549181319415"></a><a name="p5549181319415"></a>key</p>
</td>
<td class="cellrowborder" valign="top" width="12.291229122912291%" headers="mcps1.1.5.1.2 "><p id="p39351925253"><a name="p39351925253"></a><a name="p39351925253"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.551055105510551%" headers="mcps1.1.5.1.3 "><p id="p8935162182512"><a name="p8935162182512"></a><a name="p8935162182512"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="59.245924592459254%" headers="mcps1.1.5.1.4 "><p id="p1179214508910"><a name="p1179214508910"></a><a name="p1179214508910"></a>Data changed</p>
</td>
</tr>
</tbody>
</table>

