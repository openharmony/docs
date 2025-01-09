# @ohos.data.distributedKVStore (分布式键值数据库)(系统接口)

分布式键值数据库为应用程序提供不同设备间数据库的分布式协同能力。通过调用分布式键值数据库各个接口，应用程序可将数据保存到分布式键值数据库中，并可对分布式键值数据库中的数据进行增加、删除、修改、查询、同步等操作。

该模块提供以下分布式键值数据库相关的常用功能：

- [KVManager](js-apis-distributedKVStore.md#kvmanager)：分布式键值数据库管理实例，用于获取数据库的相关信息。
- [KVStoreResultSet](js-apis-distributedKVStore.md#kvstoreresultset)：提供获取数据库结果集的相关方法，包括查询和移动数据读取位置等。
- [Query](js-apis-distributedKVStore.md#query)：使用谓词表示数据库查询，提供创建Query实例、查询数据库中的数据和添加谓词的方法。
- [SingleKVStore](#singlekvstore)：单版本分布式键值数据库，不对数据所属设备进行区分，提供查询数据和同步数据的方法。
- [DeviceKVStore](#devicekvstore)：设备协同数据库，继承自[SingleKVStore](#singlekvstore)，以设备维度对数据进行区分，提供查询数据和同步数据的方法。

> **说明：** 
>
> - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.data.distributedKVStore (分布式键值数据库)](js-apis-distributedKVStore.md)。

## 导入模块

```ts
import { distributedKVStore } from '@kit.ArkData';
```

## SingleKVStore

SingleKVStore数据库实例，提供增加数据、删除数据和订阅数据变更、订阅数据同步完成的方法。

在调用SingleKVStore的方法前，需要先通过[getKVStore](js-apis-distributedKVStore.md#getkvstore)构建一个SingleKVStore实例。

### putBatch

putBatch(value: Array&lt;ValuesBucket&gt;, callback: AsyncCallback&lt;void&gt;): void

将值写入SingleKVStore数据库，使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名   | 类型                                                     | 必填 | 说明               |
| -------- | ------------------------------------------------------------ | ---- | ------------------ |
| value    | Array&lt;[ValuesBucket](js-apis-data-valuesBucket.md#valuesbucket)&gt; | 是   | 表示要插入的数据。 |
| callback | AsyncCallback&lt;void&gt;                                     | 是   | 回调函数。         |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)。

| **错误码ID** | **错误信息**                             |
| ------------ | ---------------------------------------- |
| 401          | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 202          | Permission verification failed, application which is not a system application uses system API.|
| 15100003     | Database corrupted.                      |
| 15100005     | Database or result set already closed.   |

以下错误码的详细介绍请参见[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                 |
| ------------ | -------------------------------------------- |
| 14800047     | The WAL file size exceeds the default limit. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { ValuesBucket } from '@kit.ArkData';

try {
  let bucket1: ValuesBucket = {key:"name", value: "LiSi"};
  let bucket2: ValuesBucket = {key:"age", value: 20};
  let bucket3: ValuesBucket = {key:"deposits", value: 12.34};
  let people: Array<ValuesBucket> = new Array(bucket1, bucket2, bucket3)
  kvStore.putBatch(people, (err: BusinessError) => {
    if (err != undefined) {
      console.error(`Failed to put batch.code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info('Succeeded in putting batch');
  })
} catch (e) {
  let error = e as BusinessError;
  console.error(`Failed to do putBatch error.code is ${error.code},message is ${error.message}`);
}
```

### putBatch

putBatch(value: Array&lt;ValuesBucket&gt;): Promise&lt;void&gt;

将valuesbucket类型的值写入SingleKVStore数据库，使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.DistributedDataManager.KVStore.Core

**参数：**

| 参数名 | 类型                                                     | 必填 | 说明               |
| ------ | ------------------------------------------------------------ | ---- | ------------------ |
| value  | Array&lt;[ValuesBucket](js-apis-data-valuesBucket.md#valuesbucket)&gt; | 是   | 表示要插入的数据。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)。

| **错误码ID** | **错误信息**                             |
| ------------ | ---------------------------------------- |
| 401          | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 202          | Permission verification failed, application which is not a system application uses system API.|
| 15100003     | Database corrupted.                      |
| 15100005     | Database or result set already closed.   |

以下错误码的详细介绍请参见[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                 |
| ------------ | -------------------------------------------- |
| 14800047     | The WAL file size exceeds the default limit. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { ValuesBucket } from '@kit.ArkData';

try {
  let bucket1: ValuesBucket = {key:"name", value: "LiSi"};
  let bucket2: ValuesBucket = {key:"age", value: 20};
  let bucket3: ValuesBucket = {key:"deposits", value: 12.34};
  let people: Array<ValuesBucket> = new Array(bucket1, bucket2, bucket3)
  kvStore.putBatch(people).then(() => {
    console.info(`Succeeded in putting patch`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to do putBatch error.code is ${err.code},message is ${err.message}`);
  });
} catch (e) {
  let error = e as BusinessError;
  console.error(`Failed to do putBatch error.code is ${error.code},message is ${error.message}`);
}
```

### delete

delete(predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback&lt;void&gt;)

从数据库中删除符合predicates条件的键值对，使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.DistributedDataManager.DataShare.Provider

**参数：**

| 参数名     | 类型                                                     | 必填 | 说明                                            |
| ---------- | ------------------------------------------------------------ | ---- | ----------------------------------------------- |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | 是   | 指示筛选条件，当此参数为null时，应定义处理逻辑。 |
| callback   | AsyncCallback&lt;void&gt;                                    | 是   | 回调函数。                                      |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 202          | Permission verification failed, application which is not a system application uses system API.|
| 15100003     | Database corrupted.                    |
| 15100005    | Database or result set already closed. |

以下错误码的详细介绍请参见[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                 |
| ------------ | -------------------------------------------- |
| 14800047     | The WAL file size exceeds the default limit. |

**示例：**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let predicates = new dataSharePredicates.DataSharePredicates();
  let arr = ["name"];
  predicates.inKeys(arr);
  kvStore.put("name", "bob", (err:BusinessError) => {
    if (err != undefined) {
      console.error(`Failed to put.code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info("Succeeded in putting");
    if (kvStore != null) {
      kvStore.delete(predicates, (err:BusinessError) => {
        if (err == undefined) {
          console.info('Succeeded in deleting');
        } else {
          console.error(`Failed to delete.code is ${err.code},message is ${err.message}`);
        }
      });
    }
  });
} catch (e) {
  let error = e as BusinessError;
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.message}`);
}
```

### delete

delete(predicates: dataSharePredicates.DataSharePredicates): Promise&lt;void&gt;

从数据库中删除符合predicates条件的键值对，使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.DistributedDataManager.DataShare.Provider

**参数：**

| 参数名     | 类型                                                     | 必填 | 说明                                            |
| ---------- | ------------------------------------------------------------ | ---- | ----------------------------------------------- |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | 是   | 指示筛选条件,当此参数为null时，应定义处理逻辑。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)。

| **错误码ID** | **错误信息**                             |
| ------------ | ---------------------------------------- |
| 401          | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 202          | Permission verification failed, application which is not a system application uses system API.|
| 15100003     | Database corrupted.                      |
| 15100005     | Database or result set already closed.   |

以下错误码的详细介绍请参见[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                 |
| ------------ | -------------------------------------------- |
| 14800047     | The WAL file size exceeds the default limit. |

**示例：**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let predicates = new dataSharePredicates.DataSharePredicates();
  let arr = ["name"];
  predicates.inKeys(arr);
  kvStore.put("name", "bob").then(() => {
    console.info(`Succeeded in putting data`);
    if (kvStore != null) {
      kvStore.delete(predicates).then(() => {
        console.info('Succeeded in deleting');
      }).catch((err: BusinessError) => {
        console.error(`Failed to delete.code is ${err.code},message is ${err.message}`);
      });
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to put.code is ${err.code},message is ${err.message}`);
  });
} catch (e) {
  let error = e as BusinessError;
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.message}`);
}
```

### getResultSet

getResultSet(predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback&lt;KVStoreResultSet&gt;): void

获取与指定Predicate对象匹配的KVStoreResultSet对象，使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.DistributedDataManager.DataShare.Provider

**参数：**

| 参数名     | 类型                                                     | 必填 | 说明                                                         |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | 是   | 指示筛选条件,当此参数为null时，应定义处理逻辑。              |
| callback   | AsyncCallback&lt;[KVStoreResultSet](js-apis-distributedKVStore.md#kvstoreresultset)&gt;   | 是   | 回调函数，获取与指定Predicates对象匹配的KVStoreResultSet对象。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 202          | Permission verification failed, application which is not a system application uses system API.|
| 15100001     | Upper limit exceeded.                  |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**示例：**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let resultSet: distributedKVStore.KVStoreResultSet;
  let predicates = new dataSharePredicates.DataSharePredicates();
  predicates.prefixKey("batch_test_string_key");
  kvStore.getResultSet(predicates, async (err: BusinessError, result: distributedKVStore.KVStoreResultSet) => {
    if (err != undefined) {
      console.error(`Failed to get resultset.code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info('Succeeded in getting result set');
    resultSet = result;
    if (kvStore != null) {
      kvStore.closeResultSet(resultSet, (err: BusinessError) => {
        if (err != undefined) {
          console.error(`Failed to close resultset.code is ${err.code},message is ${err.message}`);
          return;
        }
        console.info('Succeeded in closing result set');
      });
    }
  });
} catch (e) {
  let error = e as BusinessError;
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.code}`);
}
```

### getResultSet

getResultSet(predicates: dataSharePredicates.DataSharePredicates): Promise&lt;KVStoreResultSet&gt;

获取与指定Predicate对象匹配的KVStoreResultSet对象，使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.DistributedDataManager.DataShare.Provider

**参数：**

| 参数名     | 类型                                                     | 必填 | 说明                                            |
| ---------- | ------------------------------------------------------------ | ---- | ----------------------------------------------- |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | 是   | 指示筛选条件,当此参数为null时，应定义处理逻辑。 |

**返回值：**

| 类型                                                 | 说明                      |
| ---------------------------------------------------- | ------------------------- |
| Promise&lt;[KVStoreResultSet](js-apis-distributedKVStore.md#kvstoreresultset)&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 202          | Permission verification failed, application which is not a system application uses system API.|
| 15100001     | Upper limit exceeded.                  |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**示例：**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let resultSet: distributedKVStore.KVStoreResultSet;
  let predicates = new dataSharePredicates.DataSharePredicates();
  predicates.prefixKey("batch_test_string_key");
  kvStore.getResultSet(predicates).then((result: distributedKVStore.KVStoreResultSet) => {
    console.info('Succeeded in getting result set');
    resultSet = result;
    if (kvStore != null) {
      kvStore.closeResultSet(resultSet).then(() => {
        console.info('Succeeded in closing result set');
      }).catch((err: BusinessError) => {
        console.error(`Failed to close resultset.code is ${err.code},message is ${err.message}`);
      });
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to get resultset.code is ${err.code},message is ${err.message}`);
  });

} catch (e) {
  let error = e as BusinessError;
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.code}`);
}
```

## DeviceKVStore

设备协同数据库，继承自SingleKVStore，提供查询数据和同步数据的方法。

设备协同数据库，以设备维度对数据进行区分，每台设备仅能写入和修改本设备的数据，其它设备的数据对其是只读的，无法修改其它设备的数据。

比如，可以使用设备协同数据库实现设备间的图片分享，可以查看其他设备的图片，但无法修改和删除其他设备的图片。

在调用DeviceKVStore的方法前，需要先通过[getKVStore](js-apis-distributedKVStore.md#getkvstore)构建一个DeviceKVStore实例。

### getResultSet

getResultSet(predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback&lt;KVStoreResultSet&gt;): void

获取与本设备指定Predicate对象匹配的KVStoreResultSet对象，使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.DistributedDataManager.DataShare.Provider

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                                                         |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | 是   | 指示筛选条件,当此参数为null时，应定义处理逻辑。              |
| callback   | AsyncCallback&lt;[KVStoreResultSet](js-apis-distributedKVStore.md#kvstoreresultset)&gt;   | 是   | 回调函数，获取与指定Predicates对象匹配的KVStoreResultSet对象。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 202          | Permission verification failed, application which is not a system application uses system API.|
| 15100001     | Upper limit exceeded.                  |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**示例：**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let resultSet: distributedKVStore.KVStoreResultSet;
  let predicates = new dataSharePredicates.DataSharePredicates();
  predicates.prefixKey("batch_test_string_key");
  kvStore.getResultSet(predicates, async (err: BusinessError, result: distributedKVStore.KVStoreResultSet) => {
    if (err != undefined) {
      console.error(`Failed to get resultset.code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info('Succeeded in getting result set');
    resultSet = result;
    if (kvStore != null) {
      kvStore.closeResultSet(resultSet, (err: BusinessError) => {
        if (err != undefined) {
          console.error(`Failed to close resultset.code is ${err.code},message is ${err.message}`);
          return;
        }
        console.info('Succeeded in closing result set');
      })
    }
  });
} catch (e) {
  let error = e as BusinessError;
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.code}`);
}
```

### getResultSet

getResultSet(predicates: dataSharePredicates.DataSharePredicates): Promise&lt;KVStoreResultSet&gt;

获取与本设备指定Predicate对象匹配的KVStoreResultSet对象，使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.DistributedDataManager.DataShare.Provider

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                                            |
| ---------- | ------------------------------------------------------------ | ---- | ----------------------------------------------- |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | 是   | 指示筛选条件,当此参数为null时，应定义处理逻辑。 |

**返回值：**

| 类型                                                 | 说明                      |
| ---------------------------------------------------- | ------------------------- |
| Promise&lt;[KVStoreResultSet](js-apis-distributedKVStore.md#kvstoreresultset)&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 202          | Permission verification failed, application which is not a system application uses system API.|
| 15100001     | Upper limit exceeded.                  |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**示例：**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let resultSet: distributedKVStore.KVStoreResultSet;
  let predicates = new dataSharePredicates.DataSharePredicates();
  predicates.prefixKey("batch_test_string_key");
  kvStore.getResultSet(predicates).then((result: distributedKVStore.KVStoreResultSet) => {
    console.info('Succeeded in getting result set');
    resultSet = result;
    if (kvStore != null) {
      kvStore.closeResultSet(resultSet).then(() => {
        console.info('Succeeded in closing result set');
      }).catch((err: BusinessError) => {
        console.error(`Failed to close resultset.code is ${err.code},message is ${err.message}`);
      });
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to get resultset.code is ${err.code},message is ${err.message}`);
  });
} catch (e) {
  let error = e as BusinessError;
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.code}`);
}
```

### getResultSet

getResultSet(deviceId: string, predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback&lt;KVStoreResultSet&gt;): void

获取与指定Predicate对象匹配的KVStoreResultSet对象，使用callback异步回调。
> **说明：** 
>
> 其中deviceId通过调用[deviceManager.getAvailableDeviceListSync](../apis-distributedservice-kit/js-apis-distributedDeviceManager.md#getavailabledevicelistsync)方法得到。
> deviceId具体获取方式请参考[sync接口示例](js-apis-distributedKVStore.md#sync)。

**模型约束：** 此接口仅可在Stage模型下使用

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.DistributedDataManager.DataShare.Provider

**参数：**

| 参数名     | 类型                                                     | 必填 | 说明                                                         |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| deviceId  | string                                                       | 是   | 标识要查询其数据的设备。                                     |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | 是   | 指示筛选条件,当此参数为null时，应定义处理逻辑。              |
| callback   | AsyncCallback&lt;[KVStoreResultSet](js-apis-distributedKVStore.md#kvstoreresultset)&gt;   | 是   | 回调函数，获取与指定Predicates对象匹配的KVStoreResultSet对象。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 202          | Permission verification failed, application which is not a system application uses system API.|
| 15100001     | Upper limit exceeded.                  |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**示例：**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let resultSet: distributedKVStore.KVStoreResultSet;
  let predicates = new dataSharePredicates.DataSharePredicates();
  predicates.prefixKey("batch_test_string_key");
  kvStore.getResultSet('localDeviceId', predicates, async (err: BusinessError, result: distributedKVStore.KVStoreResultSet) => {
    if (err != undefined) {
      console.error(`Failed to get resultset.code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info('Succeeded in getting result set');
    resultSet = result;
    if (kvStore != null) {
      kvStore.closeResultSet(resultSet, (err: BusinessError) => {
        if (err != undefined) {
          console.error(`Failed to close resultset.code is ${err.code},message is ${err.message}`);
          return;
        }
        console.info('Succeeded in closing result set');
      })
    }
  });
} catch (e) {
  let error = e as BusinessError;
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.code}`);
}
```

### getResultSet

getResultSet(deviceId: string, predicates: dataSharePredicates.DataSharePredicates): Promise&lt;KVStoreResultSet&gt;

获取与指定Predicate对象匹配的KVStoreResultSet对象，使用Promise异步回调。
> **说明：** 
>
> 其中deviceId通过调用[deviceManager.getAvailableDeviceListSync](../apis-distributedservice-kit/js-apis-distributedDeviceManager.md#getavailabledevicelistsync)方法得到。
> deviceId具体获取方式请参考[sync接口示例](js-apis-distributedKVStore.md#sync)。

**模型约束：** 此接口仅可在Stage模型下使用

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.DistributedDataManager.DataShare.Provider

**参数：**

| 参数名     | 类型                                                     | 必填 | 说明                                            |
| ---------- | ------------------------------------------------------------ | ---- | ----------------------------------------------- |
| deviceId  | string                                                       | 是   | 标识要查询其数据的设备。                                     |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | 是   | 指示筛选条件,当此参数为null时，应定义处理逻辑。 |

**返回值：**

| 类型                                                 | 说明                      |
| ---------------------------------------------------- | ------------------------- |
| Promise&lt;[KVStoreResultSet](js-apis-distributedKVStore.md#kvstoreresultset)&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[分布式键值数据库错误码](errorcode-distributedKVStore.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401          | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 202          | Permission verification failed, application which is not a system application uses system API.|
| 15100001     | Upper limit exceeded.                  |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**示例：**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let resultSet: distributedKVStore.KVStoreResultSet;
  let predicates = new dataSharePredicates.DataSharePredicates();
  predicates.prefixKey("batch_test_string_key");
  kvStore.getResultSet('localDeviceId', predicates).then((result: distributedKVStore.KVStoreResultSet) => {
    console.info('Succeeded in getting result set');
    resultSet = result;
    if (kvStore != null) {
      kvStore.closeResultSet(resultSet).then(() => {
        console.info('Succeeded in closing result set');
      }).catch((err: BusinessError) => {
        console.error(`Failed to close resultset.code is ${err.code},message is ${err.message}`);
      });
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to get resultset.code is ${err.code},message is ${err.message}`);
  });
} catch (e) {
  let error = e as BusinessError;
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.code}`);
}
```