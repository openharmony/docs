# 分布式数据管理子系统ChangeLog

## cl.datashare.1 js-apis-data-dataShare API version 10开始托管数据对外接口从Ashmem改为ArrayBuffer。

**变更影响**

托管数据对外接口从Ashmem改为ArrayBuffer

## PublishedItem<sup>10+</sup>

指定发布的数据类型。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Consumer

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | string | 是 | 指定发布数据的键。 |
| data | string \| ArrayBuffer | 是 | 指定发布的数据。如果数据很大，请使用ArrayBuffer。 |
| subscriberId | string | 是 | 指定订阅者id。 |

**适配指导**
示例代码如下：

变更前代码示例：

**示例**

```ts
import rpc from '@ohos.rpc';

function onPublishCallback(err, node:dataShare.PublishedDataChangeNode) {
    console.info("onPublishCallback node bundleName " + JSON.stringify(node.bundleName));
    console.info("onPublishCallback node data size" + node.data.length);
    for (let i = 0; i < node.data.length; i++) {
        console.info("onPublishCallback node " + typeof node.data[i].data);
        if (typeof node.data[i].data != 'string') {
            let ash:rpc.Ashmem = node.data[i].data;
            ash.mapReadonlyAshmem();
            console.info("onPublishCallback " + JSON.stringify(ash.readAshmem(ash.getAshmemSize()/4, 0)));
            ash.closeAshmem();
        }
        console.info("onPublishCallback data " + i + " " + JSON.stringify(node.data[i]));
    }
}
let uris:Array<string> = ['city', 'datashareproxy://com.acts.ohos.data.datasharetest/appInfo', 'key2'];
let subscriberId = '11';
let result: Array<dataShare.OperationResult> = dataShareHelper.on('publishedDataChange', uris, subscriberId, onPublishCallback);
```

**示例**

```ts
import rpc from '@ohos.rpc';

let ashmem = null;
let subscriberId = '11';
let version = 1;
let data : Array<dataShare.PublishedItem> = [
    {key:"city", subscriberId:"11", data:"xian"},
    {key:"datashareproxy://com.acts.ohos.data.datasharetest/appInfo", subscriberId:"11", data:"appinfo is just a test app"},
    {key:"empty", subscriberId:"11", data:"nobody sub"}];
let nums:number[] = [1,2,3];
function publishCallback(err, result: Array<dataShare.OperationResult>) {
    console.info("publishCallback " + JSON.stringify(result));
    ashmem.closeAshmem();
}
try {
    ashmem = rpc.Ashmem.create("ashmem", (nums.length) * 4);
    ashmem.mapReadWriteAshmem();
    ashmem.writeAshmem(nums, nums.length, 0);
    data.push({
        "key" : "key2",
        "data" : ashmem,
        "subscriberId" : "11",
    });
    console.info("data length is:", data.length);
    dataShareHelper.publish(data, "com.acts.ohos.data.datasharetest", version, publishCallback);
} catch (e) {
    console.error("publish error " + JSON.stringify(e));
}
```

变更后代码示例：

**示例：**

```ts
import rpc from '@ohos.rpc';

function onPublishCallback(err, node:dataShare.PublishedDataChangeNode) {
    console.info("onPublishCallback node bundleName " + JSON.stringify(node.bundleName));
    console.info("onPublishCallback node data size" + node.data.length);
    for (let i = 0; i < node.data.length; i++) {
        console.info("onPublishCallback node " + typeof node.data[i].data);
        if (typeof node.data[i].data != 'string') {
            let array:ArrayBuffer = node.data[i].data;
            let data:Uint8Array = new Uint8Array(array);
            console.info("onPublishCallback " + i + " " + JSON.stringify(data));
        }
        console.info("onPublishCallback data " + i + " " + JSON.stringify(node.data[i]));
    }
}
let uris:Array<string> = ['city', 'datashareproxy://com.acts.ohos.data.datasharetest/appInfo', 'key2'];
let subscriberId = '11';
let result: Array<dataShare.OperationResult> = dataShareHelper.on('publishedDataChange', uris, subscriberId, onPublishCallback);
```

**示例：**

```ts
let arrayBuffer = null;
let subscriberId = '11';
let version = 1;
let data : Array<dataShare.PublishedItem> = [
    {key:"city", subscriberId:"11", data:"xian"},
    {key:"datashareproxy://com.acts.ohos.data.datasharetest/appInfo", subscriberId:"11", data:"appinfo is just a test app"},
    {key:"empty", subscriberId:"11", data:"nobody sub"}];
let nums:number[] = [1,2,3];
function publishCallback(err, result: Array<dataShare.OperationResult>) {
    console.info("publishCallback " + JSON.stringify(result));
}
try {
    arrayBuffer = new ArrayBuffer(nums.length);
    let array:Uint8Array = new Uint8Array(arrayBuffer);
    data.push({
        "key" : "key2",
        "data" : array,
        "subscriberId" : "11",
    });
    console.info("data length is:", data.length);
    dataShareHelper.publish(data, "com.acts.ohos.data.datasharetest", version, publishCallback);
} catch (e) {
    console.error("publish error " + JSON.stringify(e));
}
```