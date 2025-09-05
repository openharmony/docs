# @ohos.application.DataShareExtensionAbility (数据共享扩展能力)(系统接口)
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @woodenarow-->
<!--Designer: @woodenarow; @xuelei3-->
<!--Tester: @chenwan188; @logic42-->
<!--Adviser: @ge-yafang-->

**DataShareExtensionAbility**基于ExtensionAbility框架，提供支持数据共享业务的能力。

>**说明：** 
>
> - 本模块首批接口从API version 9开始支持，后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块接口为系统接口。
>
> - 本模块接口仅可在Stage模型下使用。


## 导入模块

```ts
import { DataShareExtensionAbility } from '@kit.ArkData';
```

## 属性

**系统能力**：SystemCapability.DistributedDataManager.DataShare.Provider

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| context<sup>10+</sup> | [ExtensionContext](../apis-ability-kit/js-apis-inner-application-extensionContext.md)  | 是 | 否 |表示数据共享扩展能力上下文。 |

## onCreate

onCreate?(want: Want, callback: AsyncCallback&lt;void&gt;): void

DataShare客户端连接DataShareExtensionAbility服务端时，服务端回调此接口，执行初始化业务逻辑操作。该方法可以选择性重写。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Provider

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ------ | ------ | ------ |
| want | [Want](../apis-ability-kit/js-apis-app-ability-want.md#want) | 是  | Want类型信息，包括Ability名称、Bundle名称等。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。无返回值。 |

**示例：**

```ts
import { DataShareExtensionAbility, relationalStore } from '@kit.ArkData';
import { Want } from '@kit.AbilityKit';

let DB_NAME = 'DB00.db';
let TBL_NAME = 'TBL00';
let DDL_TBL_CREATE = 'CREATE TABLE IF NOT EXISTS '
  + TBL_NAME
  + ' (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, age INTEGER, phoneNumber DOUBLE, isStudent BOOLEAN, Binary BINARY)';
let rdbStore: relationalStore.RdbStore;

export default class DataShareExtAbility extends DataShareExtensionAbility {
  onCreate(want: Want, callback: Function) {
    relationalStore.getRdbStore(this.context, {
      name: DB_NAME,
      securityLevel: relationalStore.SecurityLevel.S3
    }, (err, data) => {
      console.info(`getRdbStore done, data : ${data}`);
      rdbStore = data;
      rdbStore.executeSql(DDL_TBL_CREATE, [], (err) => {
        console.error(`executeSql done, error message : ${err}`);
      });
      if (callback) {
        callback();
      }
    });
  }
};
```

## UpdateOperation<sup>12+</sup>

批量更新操作的参数结构。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Provider

| 名称            | 类型                                                         | 必填 | 说明           |
| --------------- | ------------------------------------------------------------ | ---- | -------------- |
| UpdateOperation | [dataShare.UpdateOperation](js-apis-data-dataShare-sys.md#updateoperation12) | 是   | 要更新的数据。 |

## insert

insert?(uri: string, valueBucket: ValuesBucket, callback: AsyncCallback&lt;number&gt;): void

在数据库插入时回调此接口，该方法可以选择性重写。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Provider

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ------ | ------ | ------ |
| uri |string | 是  | 指示要插入的数据的路径。 |
| valueBucket |[ValuesBucket](js-apis-data-valuesBucket.md#valuesbucket) | 是 | 指示要插入的数据。 |
| callback |AsyncCallback&lt;number&gt; | 是 | 回调函数。返回插入数据记录的索引。 |

**示例：**

```ts
import { DataShareExtensionAbility, relationalStore, ValuesBucket } from '@kit.ArkData';

let TBL_NAME = 'TBL00';
let rdbStore: relationalStore.RdbStore;

export default class DataShareExtAbility extends DataShareExtensionAbility {
  insert(uri: string, valueBucket: ValuesBucket, callback: Function) {
    if (valueBucket === null) {
      console.error('invalid valueBuckets');
      return;
    }
    rdbStore.insert(TBL_NAME, valueBucket, (err, ret) => {
      console.info(`callback ret: ${ret}`);
      if (callback !== undefined) {
        callback(err, ret);
      }
    });
  }
};
```

## update

update?(uri: string, predicates: dataSharePredicates.DataSharePredicates, valueBucket: ValuesBucket, callback: AsyncCallback&lt;number&gt;): void

在数据库更新时服务端回调此接口，该方法可以选择性重写。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Provider

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ------ | ------ | ------ |
| uri | string | 是  | 指示要更新的数据的路径。 |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | 是  | 指示筛选条件。 |
| valueBucket | [ValuesBucket](js-apis-data-valuesBucket.md#valuesbucket) | 是 | 指示要更新的数据。 |
| callback | AsyncCallback&lt;number&gt; | 是 | 回调函数。返回更新的数据记录数。 |

**示例：**

```ts
import { DataShareExtensionAbility, relationalStore, dataSharePredicates, ValuesBucket } from '@kit.ArkData';

let TBL_NAME = 'TBL00';
let rdbStore: relationalStore.RdbStore;

export default class DataShareExtAbility extends DataShareExtensionAbility {
  update(uri: string, predicates: dataSharePredicates.DataSharePredicates, valueBucket: ValuesBucket, callback: Function) {
    if (predicates === null || predicates === undefined) {
      return;
    }
    rdbStore.update(TBL_NAME, valueBucket, predicates, (err, ret) => {
      if (callback !== undefined) {
        callback(err, ret);
      }
    });
  }
};
```

## batchUpdate<sup>12+</sup>

batchUpdate?( operations: Record&lt;string, Array&lt;UpdateOperation&gt;&gt; , callback:  AsyncCallback&lt;Record&lt;string, Array&lt;number&gt;&gt;&gt;): void

在数据库批量更新时服务端回调此接口，该方法可以选择性重写。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Provider

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                                                   |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------ |
| operations | Record&lt;string, Array&lt;[UpdateOperation](#updateoperation12)&gt;&gt; | 是   | 要更新数据的路径、筛选条件和数据集合。                 |
| callback   | AsyncCallback&lt;Record&lt;string, Array&lt;number&gt;&gt;&gt;  | 是   | 回调函数。返回更新的数据记录数集合，更新失败的UpdateOperation的数据记录数为-1。 |

**示例：**

```ts
import { DataShareExtensionAbility, relationalStore, dataShare } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit'

let TBL_NAME = 'TBL00';
let rdbStore: relationalStore.RdbStore;

export default class DataShareExtAbility extends DataShareExtensionAbility {
  batchUpdate(operations:Record<string, Array<dataShare.UpdateOperation>>, callback:Function) {
    let recordOps : Record<string, Array<dataShare.UpdateOperation>> = operations;
    let results : Record<string, Array<number>> = {};
    let a = Object.entries(recordOps);
    for (let i = 0; i < a.length; i++) {
      let key = a[i][0];
      let values = a[i][1];
      let result : number[] = [];
      for (const value of values) {
        rdbStore.update(TBL_NAME, value.values, value.predicates).then(async (rows) => {
          console.info('Update row count is ' + rows);
          result.push(rows);
        }).catch((err:BusinessError) => {
          console.info('Update failed, err is ' + JSON.stringify(err));
          result.push(-1)
        })
      }
      results[key] = result;
    }
    callback(null, results);
  }
};
```

## delete

delete?(uri: string, predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback&lt;number&gt;): void

在删除数据库记录时服务端回调此接口，该方法可以选择性重写。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Provider

**参数：**

| 参数名       | 类型                                                     | 必填 | 说明                               |
| ---------- | ------------------------------------------------------------ | ---- | ---------------------------------- |
| uri        | string                                                       | 是   | 指示要删除的数据的路径。           |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | 是   | 指示筛选条件。                     |
| callback   | AsyncCallback&lt;number&gt;                                  | 是   | 回调函数。返回已删除的数据记录数。 |

**示例：**

```ts
import { DataShareExtensionAbility, relationalStore, dataSharePredicates } from '@kit.ArkData';

let TBL_NAME = 'TBL00';
let rdbStore: relationalStore.RdbStore;

export default class DataShareExtAbility extends DataShareExtensionAbility {
  delete(uri: string, predicates: dataSharePredicates.DataSharePredicates, callback: Function) {
    if (predicates === null || predicates === undefined) {
      return;
    }
    rdbStore.delete(TBL_NAME, predicates, (err, ret) => {
      if (callback !== undefined) {
        callback(err, ret);
      }
    });
  }
};
```

## query

query?(uri: string, predicates: dataSharePredicates.DataSharePredicates, columns: Array&lt;string&gt;, callback: AsyncCallback&lt;Object&gt;): void

在查询数据库时服务端回调此接口，该方法可以选择性重写。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Provider

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ------ | ------ | ------ |
| uri | string | 是  | 指示要查询的数据的路径。 |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | 是  | 指示筛选条件。 |
| columns | Array&lt;string&gt; | 是 | 指示要查询的列。如果此参数为空，则查询所有列。 |
| callback | AsyncCallback&lt;Object&gt; | 是 | 回调函数。返回查询到的结果集。 |

**示例：**

```ts
import { DataShareExtensionAbility, relationalStore, dataSharePredicates } from '@kit.ArkData';

let TBL_NAME = 'TBL00';
let rdbStore: relationalStore.RdbStore;

export default class DataShareExtAbility extends DataShareExtensionAbility {
  query(uri: string, predicates: dataSharePredicates.DataSharePredicates, columns: Array<string>, callback: Function) {
    if (predicates === null || predicates === undefined) {
      return;
    }
    rdbStore.query(TBL_NAME, predicates, columns, (err, resultSet) => {
      if (resultSet !== undefined) {
        console.info(`resultSet.rowCount: ${resultSet.rowCount}`);
      }
      if (callback !== undefined) {
        callback(err, resultSet);
      }
    });
  }
};
```

## batchInsert

batchInsert?(uri: string, valueBuckets: Array&lt;ValuesBucket&gt;, callback: AsyncCallback&lt;number&gt;): void

在数据库批量插入时服务端回调此接口，该方法可以选择性重写。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Provider

**参数：**

| 参数名        | 类型                                                     | 必填 | 说明                             |
| ------------ | ------------------------------------------------------------ | ---- | -------------------------------- |
| uri          | string                                                       | 是   | 指示要批量插入的数据的路径。     |
| valueBuckets | Array&lt;[ValuesBucket](js-apis-data-valuesBucket.md#valuesbucket)&gt; | 是   | 指示要批量插入的数据。           |
| callback     | AsyncCallback&lt;number&gt;                                  | 是   | 回调函数。返回插入的数据记录数。 |

**示例：**

```ts
import { DataShareExtensionAbility, relationalStore, ValuesBucket } from '@kit.ArkData';

let TBL_NAME = 'TBL00';
let rdbStore: relationalStore.RdbStore;

export default class DataShareExtAbility extends DataShareExtensionAbility {
  batchInsert(uri: string, valueBuckets: Array<ValuesBucket>, callback: Function) {
    if (valueBuckets === null || valueBuckets.length <= 0) {
      console.error('invalid valueBuckets');
      return;
    }
    rdbStore.batchInsert(TBL_NAME, valueBuckets, (err, ret) => {
      if (callback !== undefined) {
        callback(err, ret);
      }
    });
  };
};
```

## normalizeUri

normalizeUri?(uri: string, callback: AsyncCallback&lt;string&gt;): void

用户给定的URI转换为服务端使用的URI时回调此接口，该方法可以选择性重写。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Provider

**参数：**

| 参数名     | 类型                  | 必填 | 说明                    |
| -------- | --------------------- | ---- | ----------------------- |
| uri      | string                | 是   | 指示用户传入的[URI](../apis-arkts/js-apis-uri.md#uri)。 |
| callback | AsyncCallback&lt;string&gt; | 是   | 回调函数。如果支持URI规范化，则返回规范化URI，否则返回空。 |

**示例：**

```ts
import { DataShareExtensionAbility } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit'

export default class DataShareExtAbility extends DataShareExtensionAbility {
  normalizeUri(uri: string, callback: Function) {
    let key = 'code';
    let value = 0;
    let err: BusinessError = {
      code: value,
      name: key,
      message: key
    };
    let ret: string = `normalize: ${uri}`;
    callback(err, ret);
  }
};
```

## denormalizeUri

denormalizeUri?(uri: string, callback: AsyncCallback&lt;string&gt;): void

服务端使用的URI转换为用户传入的初始URI时服务端回调此接口，该方法可以选择性重写。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Provider

**参数：**

| 参数名     | 类型                  | 必填 | 说明                    |
| -------- | --------------------- | ---- | ----------------------- |
| uri      | string                | 是   | 指示服务端使用的[URI](../apis-arkts/js-apis-uri.md#uri)。 |
| callback | AsyncCallback&lt;string&gt; | 是   | 回调函数。如果反规范化成功，则返回反规范化的URI；如果无需进行反规范化，则返回原始URI；若不支持则返回空。 |

**示例：**

```ts
import { DataShareExtensionAbility } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit'

export default class DataShareExtAbility extends DataShareExtensionAbility {
  denormalizeUri(uri: string, callback: Function) {
    let key = 'code';
    let value = 0;
    let err: BusinessError = {
      code: value,
      name: key,
      message: key
    };
      let ret = `denormalize ${uri}`;
      callback(err, ret);
  }
};
```
