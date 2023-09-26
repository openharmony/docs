# 分布式数据管理子系统ChangeLog

## cl.datashare.1 js-apis-data-dataShare API version 10开始托管数据PublishedItem中data的数据类型从Ashmem变更为ArrayBuffer

**变更影响**

PublishedItem中data的数据类型从Ashmem变更为ArrayBuffer

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

**示例：**

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