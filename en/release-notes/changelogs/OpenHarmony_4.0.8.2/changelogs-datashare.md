# Distributed Data Management Subsystem Changelog

## cl.datashare.1 Change of the data Type in PublishedItem from Ashmem to ArrayBuffer

**Change Impact**

Changed the type of **data** in **PublishedItem** from Ashmem to ArrayBuffer.

## PublishedItem<sup>10+</sup>

Defines the data to publish.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | string | Yes| Key of the data to publish.|
| data | string \| ArrayBuffer | Yes| Data to publish. If a large volume of data is to be published, use **data** of the ArrayBuffer type. |
| subscriberId | string | Yes| Subscriber ID.|

**Adaptation Guide**
The sample code is as follows:

**Example**

```ts
let arrayBuffer = new ArrayBuffer(1);
let version = 1;
let data : Array<dataShare.PublishedItem> = [{key:"key2", subscriberId:"11", data:arrayBuffer}];
function publishCallback(err, result: Array<dataShare.OperationResult>) {
    console.info("publishCallback " + JSON.stringify(result));
}
try {
    console.info("data length is:", data.length);
    dataShareHelper.publish(data, "com.acts.ohos.data.datasharetest", version, publishCallback);
} catch (e) {
    console.error("publish error " + JSON.stringify(e));
}
```
