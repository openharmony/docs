# @ohos.data.relationalStore (关系型数据库)

关系型数据库（Relational Database，RDB）是一种基于关系模型来管理数据的数据库。关系型数据库基于SQLite组件提供了一套完整的对本地数据库进行管理的机制，对外提供了一系列的增、删、改、查等接口，也可以直接运行用户输入的SQL语句来满足复杂的场景需要。支持通过[ResultSet.getSendableRow](#getsendablerow12)方法获取Sendable数据，进行跨线程传递。

为保证插入并读取数据成功，建议一条数据不要超过2M。超出该大小，插入成功，读取失败。

大数据量场景下查询数据可能会导致耗时长甚至应用卡死，如有相关操作可参考文档[批量数据写数据库场景](../../arkts-utils/batch-database-operations-guide.md)，且有建议如下：
- 单次查询数据量不超过5000条。
- 在[TaskPool](../apis-arkts/js-apis-taskpool.md)中查询。
- 拼接SQL语句尽量简洁。
- 合理地分批次查询。

该模块提供以下关系型数据库相关的常用功能：

- [RdbPredicates](#rdbpredicates)：数据库中用来代表数据实体的性质、特征或者数据实体之间关系的词项，主要用来定义数据库的操作条件。
- [RdbStore](#rdbstore)：提供管理关系数据库（RDB）方法的接口。
- [ResultSet](#resultset)：提供用户调用关系型数据库查询接口之后返回的结果集合。
- [Transaction](#transaction14)：提供管理事务对象的接口。

> **说明：**
> 
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { relationalStore } from '@kit.ArkData';
```

## relationalStore.getRdbStore

getRdbStore(context: Context, config: StoreConfig, callback: AsyncCallback&lt;RdbStore&gt;): void

获得一个相关的RdbStore，操作关系型数据库，用户可以根据自己的需求配置RdbStore的参数，然后通过RdbStore调用相关接口可以执行相关的数据操作，使用callback异步回调。

加密参数[encrypt](#storeconfig)只在首次创建数据库时生效，因此在创建数据库时，选择正确的加密参数非常重要，并且在之后无法更改加密参数。

| 当前开库的加密类型  | 首次创建数据库的加密类型           | 结果 |
| ------- | -------------------------------- | ---- |
| 非加密 | 加密                          | 将数据库以加密方式打开。   |
| 加密 | 非加密                          | 将数据库以非加密方式打开。   |

getRdbStore目前不支持多线程并发操作。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型                                           | 必填 | 说明                                                         |
| -------- | ---------------------------------------------- | ---- | ------------------------------------------------------------ |
| context  | Context                                        | 是   | 应用的上下文。<br>FA模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-app-context.md)。<br>Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md)。 |
| config   | [StoreConfig](#storeconfig)               | 是   | 与此RDB存储相关的数据库配置。                                |
| callback | AsyncCallback&lt;[RdbStore](#rdbstore)&gt; | 是   | 指定callback回调函数，返回RdbStore对象。                   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**   |
|-----------|---------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error.     |
| 14800010  | Invalid database path.   |
| 14800011  | Database corrupted.    |
| 14801001  | The operation is supported in the stage model only.    |
| 14801002  | Invalid data group ID.   |
| 14800017  | Config changed.   |
| 14800020  | The secret key is corrupted or lost.   |
| 14800021  | SQLite: Generic error.    |
| 14800022  | SQLite: Callback routine requested an abort.   |
| 14800023  | SQLite: Access permission denied.    |
| 14800027  | SQLite: Attempt to write a readonly database.   |
| 14800028  | SQLite: Some kind of disk I/O error occurred.     |
| 14800029  | SQLite: The database is full.  |
| 14800030  | SQLite: Unable to open the database file.   |

**示例：**

FA模型示例：

<!--code_no_check_fa-->
```js
import { featureAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let store: relationalStore.RdbStore | undefined = undefined;
let context = featureAbility.getContext();

const STORE_CONFIG: relationalStore.StoreConfig = {
  name: "RdbTest.db",
  securityLevel: relationalStore.SecurityLevel.S3
};

relationalStore.getRdbStore(context, STORE_CONFIG, async (err: BusinessError, rdbStore: relationalStore.RdbStore) => {
  if (err) {
    console.error(`Get RdbStore failed, code is ${err.code},message is ${err.message}`);
    return;
  }
  console.info('Get RdbStore successfully.');
  store = rdbStore;
  // 成功获取到 rdbStore 后执行后续操作
});
```

Stage模型示例：

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

let store: relationalStore.RdbStore | undefined = undefined;

class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    const STORE_CONFIG: relationalStore.StoreConfig = {
      name: "RdbTest.db",
      securityLevel: relationalStore.SecurityLevel.S3
    };

    relationalStore.getRdbStore(this.context, STORE_CONFIG, async (err: BusinessError, rdbStore: relationalStore.RdbStore) => {
      if (err) {
        console.error(`Get RdbStore failed, code is ${err.code},message is ${err.message}`);
        return;
      }
      console.info('Get RdbStore successfully.');
      store = rdbStore;
      // 成功获取到 rdbStore 后执行后续操作
    });
  }
}
```

## relationalStore.getRdbStore

getRdbStore(context: Context, config: StoreConfig): Promise&lt;RdbStore&gt;

获得一个相关的RdbStore，操作关系型数据库，用户可以根据自己的需求配置RdbStore的参数，然后通过RdbStore调用相关接口可以执行相关的数据操作，使用Promise异步回调。

加密参数[encrypt](#storeconfig)只在首次创建数据库时生效，因此在创建数据库时，选择正确的加密参数非常重要，并且在之后无法更改加密参数。

| 当前开库的加密类型  | 首次创建数据库的加密类型           | 结果 |
| ------- | -------------------------------- | ---- |
| 非加密 | 加密                          | 将数据库以加密方式打开。   |
| 加密 | 非加密                          | 将数据库以非加密方式打开。   |

getRdbStore目前不支持多线程并发操作。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名  | 类型                             | 必填 | 说明                                                         |
| ------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| context | Context                          | 是   | 应用的上下文。<br>FA模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-app-context.md)。<br>Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md)。 |
| config  | [StoreConfig](#storeconfig) | 是   | 与此RDB存储相关的数据库配置。                                |

**返回值**：

| 类型                                      | 说明                              |
| ----------------------------------------- | --------------------------------- |
| Promise&lt;[RdbStore](#rdbstore)&gt; | Promise对象。返回RdbStore对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800010  | Invalid database path. |
| 14800011  | Database corrupted.  |
| 14801001  | The operation is supported in the stage model only.                               |
| 14801002  | Invalid data group ID.                             |
| 14800017  | Config changed. |
| 14800020  | The secret key is corrupted or lost.   |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort.   |
| 14800023  | SQLite: Access permission denied.    |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |

**示例：**

FA模型示例：

<!--code_no_check_fa-->
```js
import { featureAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let store: relationalStore.RdbStore | undefined = undefined;
let context = featureAbility.getContext();

const STORE_CONFIG: relationalStore.StoreConfig = {
  name: "RdbTest.db",
  securityLevel: relationalStore.SecurityLevel.S3
};

relationalStore.getRdbStore(context, STORE_CONFIG).then(async (rdbStore: relationalStore.RdbStore) => {
  store = rdbStore;
  console.info('Get RdbStore successfully.');
}).catch((err: BusinessError) => {
  console.error(`Get RdbStore failed, code is ${err.code},message is ${err.message}`);
});
```

Stage模型示例：

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

let store: relationalStore.RdbStore | undefined = undefined;

class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    const STORE_CONFIG: relationalStore.StoreConfig = {
      name: "RdbTest.db",
      securityLevel: relationalStore.SecurityLevel.S3
    };

    relationalStore.getRdbStore(this.context, STORE_CONFIG).then(async (rdbStore: relationalStore.RdbStore) => {
      store = rdbStore;
      console.info('Get RdbStore successfully.');
    }).catch((err: BusinessError) => {
      console.error(`Get RdbStore failed, code is ${err.code},message is ${err.message}`);
    });
  }
}
```

## relationalStore.deleteRdbStore

deleteRdbStore(context: Context, name: string, callback: AsyncCallback&lt;void&gt;): void

删除数据库文件，使用callback异步回调。

删除成功后，建议将数据库对象置为null。建立数据库时，若在[StoreConfig](#storeconfig)中配置了自定义路径，则调用此接口进行删库无效，必须使用 [deleteRdbStore](#relationalstoredeleterdbstore10) 接口进行删库。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                                         |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| context  | Context                   | 是   | 应用的上下文。<br>FA模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-app-context.md)。<br>Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md)。 |
| name     | string                    | 是   | 数据库名称。                                                 |
| callback | AsyncCallback&lt;void&gt; | 是   | 指定callback回调函数。                                       |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                        |
|-----------|---------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error.     |
| 14800010  | Failed to open or delete database by invalid database path. |

**示例：**

FA模型示例：

<!--code_no_check_fa-->
```js
import { featureAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let store: relationalStore.RdbStore | undefined = undefined;
let context = featureAbility.getContext();

relationalStore.deleteRdbStore(context, "RdbTest.db", (err: BusinessError) => {
  if (err) {
    console.error(`Delete RdbStore failed, code is ${err.code},message is ${err.message}`);
    return;
  }
  store = undefined;
  console.info('Delete RdbStore successfully.');
});
```

Stage模型示例：

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

let store: relationalStore.RdbStore | undefined = undefined;

class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    relationalStore.deleteRdbStore(this.context, "RdbTest.db", (err: BusinessError) => {
      if (err) {
        console.error(`Delete RdbStore failed, code is ${err.code},message is ${err.message}`);
        return;
      }
      store = undefined;
      console.info('Delete RdbStore successfully.');
    });
  }
}
```

## relationalStore.deleteRdbStore

deleteRdbStore(context: Context, name: string): Promise&lt;void&gt;

使用指定的数据库文件配置删除数据库，使用Promise异步回调。

删除成功后，建议将数据库对象置为null。建立数据库时，若在[StoreConfig](#storeconfig)中配置了自定义路径，则调用此接口进行删库无效，必须使用 [deleteRdbStore](#relationalstoredeleterdbstore10-1) 接口进行删库。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数**

| 参数名  | 类型    | 必填 | 说明                                                         |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| context | Context | 是   | 应用的上下文。<br>FA模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-app-context.md)。<br>Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md)。 |
| name    | string  | 是   | 数据库名称。                                                 |

**返回值**：

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                                                         |
|-----------|----------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error.                                                                     |
| 14800010  | Invalid database path.                      |

**示例：**

FA模型示例：

<!--code_no_check_fa-->
```js
import { featureAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let store: relationalStore.RdbStore | undefined = undefined;
let context = featureAbility.getContext();

relationalStore.deleteRdbStore(context, "RdbTest.db").then(() => {
  store = undefined;
  console.info('Delete RdbStore successfully.');
}).catch((err: BusinessError) => {
  console.error(`Delete RdbStore failed, code is ${err.code},message is ${err.message}`);
});
```

Stage模型示例：

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

let store: relationalStore.RdbStore | undefined = undefined;

class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    relationalStore.deleteRdbStore(this.context, "RdbTest.db").then(() => {
      store = undefined;
      console.info('Delete RdbStore successfully.');
    }).catch((err: BusinessError) => {
      console.error(`Delete RdbStore failed, code is ${err.code},message is ${err.message}`);
    });
  }
}
```

## relationalStore.deleteRdbStore<sup>10+</sup>

deleteRdbStore(context: Context, config: StoreConfig, callback: AsyncCallback\<void>): void

使用指定的数据库文件配置删除数据库，使用callback异步回调。

删除成功后，建议将数据库对象置为null。若数据库文件处于公共沙箱目录下，则删除数据库时必须使用该接口，当存在多个进程操作同一个数据库的情况，建议向其他进程发送数据库删除通知使其感知并处理。建立数据库时，若在[StoreConfig](#storeconfig)中配置了自定义路径，则必须调用此接口进行删库。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                                         |
| -------- | --------------------------- | ---- | ------------------------------------------------------------ |
| context  | Context                     | 是   | 应用的上下文。<br>FA模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-app-context.md)。<br>Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md)。 |
| config   | [StoreConfig](#storeconfig) | 是   | 与此RDB存储相关的数据库配置。                                |
| callback | AsyncCallback&lt;void&gt;   | 是   | 指定callback回调函数。                                       |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**          |
|-----------|----------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error.        |
| 14800010  | Failed to open or delete database by invalid database path.        |
| 14801001  | The operation is supported in the stage model only.         |
| 14801002  | Invalid data group ID.        |

**示例：**

FA模型示例：

<!--code_no_check_fa-->
```js
import { featureAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let store: relationalStore.RdbStore | undefined = undefined;
let context = featureAbility.getContext();

const STORE_CONFIG: relationalStore.StoreConfig = {
  name: "RdbTest.db",
  securityLevel: relationalStore.SecurityLevel.S3
};

relationalStore.deleteRdbStore(context, STORE_CONFIG, (err: BusinessError) => {
  if (err) {
    console.error(`Delete RdbStore failed, code is ${err.code},message is ${err.message}`);
    return;
  }
  store = undefined;
  console.info('Delete RdbStore successfully.');
});
```

Stage模型示例：

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

let store: relationalStore.RdbStore | undefined = undefined;

class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    const STORE_CONFIG: relationalStore.StoreConfig = {
      name: "RdbTest.db",
      securityLevel: relationalStore.SecurityLevel.S3
    };
    relationalStore.deleteRdbStore(this.context, STORE_CONFIG, (err: BusinessError) => {
      if (err) {
        console.error(`Delete RdbStore failed, code is ${err.code},message is ${err.message}`);
        return;
      }
      store = undefined;
      console.info('Delete RdbStore successfully.');
    });
  }
}
```

## relationalStore.deleteRdbStore<sup>10+</sup>

deleteRdbStore(context: Context, config: StoreConfig): Promise\<void>

使用指定的数据库文件配置删除数据库，使用Promise异步回调。

删除成功后，建议将数据库对象置为null。若数据库文件处于公共沙箱目录下，则删除数据库时必须使用该接口，当存在多个进程操作同一个数据库的情况，建议向其他进程发送数据库删除通知使其感知并处理。建立数据库时，若在[StoreConfig](#storeconfig)中配置了自定义路径，则必须调用此接口进行删库。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数**

| 参数名  | 类型                        | 必填 | 说明                                                         |
| ------- | --------------------------- | ---- | ------------------------------------------------------------ |
| context | Context                     | 是   | 应用的上下文。<br>FA模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-app-context.md)。<br>Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md)。 |
| config  | [StoreConfig](#storeconfig) | 是   | 与此RDB存储相关的数据库配置。                                |

**返回值**：

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**             |
|-----------|---------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported.      |
| 14800000  | Inner error.      |
| 14800010  | Invalid database path.   |
| 14801001  | The operation is supported in the stage model only.   |
| 14801002  | Invalid data group ID.   |

**示例：**

FA模型示例：

<!--code_no_check_fa-->
```js
import { featureAbility } from "@kit.AbilityKit";
import { BusinessError } from '@kit.BasicServicesKit';

let store: relationalStore.RdbStore | undefined = undefined;
let context = featureAbility.getContext();

const STORE_CONFIG: relationalStore.StoreConfig = {
  name: "RdbTest.db",
  securityLevel: relationalStore.SecurityLevel.S3
};

relationalStore.deleteRdbStore(context, STORE_CONFIG).then(() => {
  store = undefined;
  console.info('Delete RdbStore successfully.');
}).catch((err: BusinessError) => {
  console.error(`Delete RdbStore failed, code is ${err.code},message is ${err.message}`);
});
```

Stage模型示例：

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

let store: relationalStore.RdbStore | undefined = undefined;

class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    const STORE_CONFIG: relationalStore.StoreConfig = {
      name: "RdbTest.db",
      securityLevel: relationalStore.SecurityLevel.S3
    };
    relationalStore.deleteRdbStore(this.context, STORE_CONFIG).then(() => {
      store = undefined;
      console.info('Delete RdbStore successfully.');
    }).catch((err: BusinessError) => {
      console.error(`Delete RdbStore failed, code is ${err.code},message is ${err.message}`);
    });
  }
}
```
## relationalStore.isVectorSupported<sup>18+</sup>

isVectorSupported(): boolean

判断系统是否提供向量数据库能力。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**返回值**：

| 类型    | 说明                                              |
| ------- | ------------------------------------------------- |
| boolean | 系统具备向量数据库能力时返回true，否则返回false。 |

**示例：**

```
let result = relationalStore.isVectorSupported();
```

## relationalStore.isTokenizerSupported<sup>18+</sup>

isTokenizerSupported(tokenizer: Tokenizer): boolean

判断当前平台是否支持传入的分词器，此为同步接口。

如果当前平台支持传入的分词器时，此接口返回值为true；反之，返回值为false。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名  | 类型                  | 必填 | 说明                                                         |
| ------- | --------------------- | ---- | ------------------------------------------------------------ |
| tokenizer | [Tokenizer](#tokenizer18)               | 是   | 需要被判断是否支持的分词器。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| boolean | true表示当前平台支持当前传入的分词器，false表示当前平台不支持当前传入的分词器。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**             |
|-----------|---------------------|
| 401       | Parameter error. Possible causes: Incorrect parameter types. |


**示例：**

```ts
import { relationalStore } from '@kit.ArkData'; // 导入模块

let customType = relationalStore.Tokenizer.CUSTOM_TOKENIZER;
let customTypeSupported = relationalStore.isTokenizerSupported(customType);
console.info("custom tokenizer supported on current platform: " + customTypeSupported);
```

## StoreConfig

管理关系数据库配置。

| 名称        | 类型          | 必填 | 说明                                                      |
| ------------- | ------------- | ---- | --------------------------------------------------------- |
| name          | string        | 是   | 数据库文件名，也是数据库唯一标识符。<br/>**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core   |
| securityLevel | [SecurityLevel](#securitylevel) | 是   | 设置数据库安全级别。<br/>**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core|
| encrypt       | boolean       | 否   | 指定数据库是否加密，默认不加密。<br/> true：加密。<br/> false：非加密。<br/>**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core |
| dataGroupId<sup>10+</sup> | string | 否 | 应用组ID，<!--RP1-->暂不支持指定dataGroupId在对应的沙箱路径下创建RdbStore实例。<!--RP1End--><br/>**模型约束：** 此属性仅在Stage模型下可用。<br/>从API version 10开始，支持此可选参数。dataGroupId共沙箱的方式不支持多进程访问加密数据库，当此参数不填时，默认在本应用沙箱目录下创建RdbStore实例。<br/>**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core |
| customDir<sup>11+</sup> | string | 否 | 数据库自定义路径。<br/>**使用约束：** 数据库路径大小限制为128字节，如果超过该大小会开库失败，返回错误。<br/>从API version 11开始，支持此可选参数。数据库将在如下的目录结构中被创建：context.databaseDir + "/rdb/" + customDir，其中context.databaseDir是应用沙箱对应的路径，"/rdb/"表示创建的是关系型数据库，customDir表示自定义的路径。当此参数不填时，默认在本应用沙箱目录下创建RdbStore实例。从API version 18开始，如果同时配置了rootDir参数，将打开或删除如下路径数据库：rootDir + "/" + customDir + "/" + name。<br/>**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core |
| rootDir<sup>18+</sup> | string | 否 | 指定数据库根路径。<br/>从API version 18开始，支持此可选参数。将从如下目录打开或删除数据库：rootDir + "/" + customDir。通过设置此参数打开的数据库为只读模式，不允许对数据库进行写操作，否则返回错误码801。配置此参数打开或删除数据库时，应确保对应路径下数据库文件存在，并且有读取权限，否则返回错误码14800010。<br/>**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core |
| autoCleanDirtyData<sup>11+</sup> | boolean | 否 | 指定是否自动清理云端删除后同步到本地的数据，true表示自动清理，false表示手动清理，默认自动清理。<br/>对于端云协同的数据库，当云端删除的数据同步到设备端时，可通过该参数设置设备端是否自动清理。手动清理可以通过[cleanDirtyData<sup>11+</sup>](#cleandirtydata11)接口清理。<br/>从API version 11开始，支持此可选参数。<br/>**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client |
| allowRebuild<sup>12+</sup> | boolean | 否 | 指定数据库是否支持异常时自动删除，并重建一个空库空表，默认不删除。<br/>true：自动删除。<br/>false：不自动删除。<br/>从API version 12开始，支持此可选参数。<br/>**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core |
| isReadOnly<sup>12+</sup> | boolean | 否 | 指定数据库是否只读，默认为数据库可读写。<br/>true：只允许从数据库读取数据，不允许对数据库进行写操作，否则会返回错误码801。<br/>false：允许对数据库进行读写操作。<br/>从API version 12开始，支持此可选参数。<br/>**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core |
| pluginLibs<sup>12+</sup> | Array\<string> | 否 | 表示包含有fts（Full-Text Search，即全文搜索引擎）等能力的动态库名的数组。<br/>**使用约束：** <br/>1. 动态库名的数量限制最多为16个，如果超过该数量会开库失败，返回错误。<br/>2. 动态库名需为本应用沙箱路径下或系统路径下的动态库，如果动态库无法加载会开库失败，返回错误。<br/>3. 动态库名需为完整路径，用于被sqlite加载。<br/>样例：[context.bundleCodeDir+ "/libs/arm64/" + libtokenizer.so]，其中context.bundleCodeDir是应用沙箱对应的路径，"/libs/arm64/"表示子目录，libtokenizer.so表示动态库的文件名。当此参数不填时，默认不加载动态库。<br/>4. 动态库需要包含其全部依赖，避免依赖项丢失导致无法运行。<br/>例如：在ndk工程中，使用默认编译参数构建libtokenizer.so，此动态库依赖c++标准库。在加载此动态库时，由于namespace与编译时不一致，链接到了错误的libc++_shared.so，导致`__emutls_get_address`符号找不到。要解决此问题，需在编译时静态链接c++标准库，具体请参见[NDK工程构建概述](../../napi/build-with-ndk-overview.md)。<br/>**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core |
| cryptoParam<sup>14+</sup> | [CryptoParam](#cryptoparam14) | 否 | 指定用户自定义的加密参数。<br/>当此参数不填时，使用默认的加密参数，见[CryptoParam](#cryptoparam14)各参数默认值。<br/>此配置只有在encrypt选项设置为真时才有效。<br/>从API version 14开始，支持此可选参数。<br/>**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core |
| vector<sup>18+</sup> | boolean | 否 | 指定数据库是否是向量数据库，true表示向量数据库，false表示关系型数据库，默认为false。<br/>向量数据库适用于存储和处理高维向量数据，关系型数据库适用于存储和处理结构化数据。<br/>向量数据库目前支持[execute](#execute12-1)，[querySql](#querysql-1)，[beginTrans](#begintrans12)，[commit](#commit12)，[rollback](#rollback12)，[backup](#backup)，[restore](#restore)以及[ResultSet](#resultset)类型操作接口。当使用向量数据库时，在调用deleteRdbStore接口前，应当确保向量数据库已经被正确关闭。<br/>**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core |
| tokenizer<sup>18+</sup> | [Tokenizer](#tokenizer18) | 否 | 指定用户在fts场景下使用哪种分词器。<br/>当此参数不填时，则在fts下不支持中文以及多国语言分词，但仍可支持英文分词。<br/>**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core |
| persist<sup>18+</sup> | boolean | 否 | 指定数据库是否需要持久化。true表示持久化，false表示不持久化，即内存数据库。默认为true。<br/>内存数据库不支持加密、backup、restore、跨进程访问及分布式能力，securityLevel属性会被忽略。<br/>**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core |

## SecurityLevel

数据库的安全级别枚举。请使用枚举名称而非枚举值。数据库的安全等级仅支持由低向高设置，不支持由高向低设置。

> **说明：**
>
> 若需要进行同步操作，数据库安全等级应不高于对端设备安全等级，具体可见[跨设备同步访问控制机制](../../database/sync-app-data-across-devices-overview.md#跨设备同步访问控制机制)。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 名称 | 值   | 说明                                                         |
| ---- | ---- | ------------------------------------------------------------ |
| S1   | 1    | 表示数据库的安全级别为低级别，当数据泄露时会产生较低影响。例如，包含壁纸等系统数据的数据库。 |
| S2   | 2    | 表示数据库的安全级别为中级别，当数据泄露时会产生较大影响。例如，包含录音、视频等用户生成数据或通话记录等信息的数据库。 |
| S3   | 3    | 表示数据库的安全级别为高级别，当数据泄露时会产生重大影响。例如，包含用户运动、健康、位置等信息的数据库。 |
| S4   | 4    | 表示数据库的安全级别为关键级别，当数据泄露时会产生严重影响。例如，包含认证凭据、财务数据等信息的数据库。 |

## CryptoParam<sup>14+</sup>

数据库加密参数配置。此配置只有在StoreConfig的encrypt选项设置为真时才有效。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 名称          | 类型   | 必填 | 说明                                                         |
| ------------- | ------ | ---- | ------------------------------------------------------------ |
| encryptionKey | Uint8Array | 是   | 指定数据库加/解密使用的密钥。<br/>如传入密钥为空，则由数据库负责生成并保存密钥，并使用生成的密钥打开数据库文件。<br/>使用完后用户需要将密钥内容全部置为零。 |
| iterationCount | number | 否 | 整数类型，指定数据库PBKDF2算法的迭代次数，默认值为10000。<br/>迭代次数应当为大于零的整数，若非整数则向下取整。<br/>不指定此参数或指定为零时，使用默认值10000，并使用默认加密算法AES_256_GCM。 |
| encryptionAlgo | [EncryptionAlgo](#encryptionalgo14) | 否 | 指定数据库加解密使用的加密算法。如不指定，默认值为 AES_256_GCM。 |
| hmacAlgo | [HmacAlgo](#hmacalgo14) | 否 | 指定数据库加解密使用的HMAC算法。如不指定，默认值为SHA256。 |
| kdfAlgo | [KdfAlgo](#kdfalgo14) | 否 | 指定数据库加解密使用的PBKDF2算法。如不指定，默认使用和HMAC算法相等的算法。 |
| cryptoPageSize | number | 否 | 整数类型，指定数据库加解密使用的页大小。如不指定，默认值为1024字节。<br/>用户指定的页大小应为1024到65536范围内的整数，并且为2<sup>n</sup>。若指定值非整数，则向下取整。 |

## EncryptionAlgo<sup>14+</sup>

数据库的加密算法枚举。请使用枚举名称而非枚举值。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 名称 | 值   | 说明 |
| ---- | ---- | ---- |
| AES_256_GCM |  0    | AES_256_GCM加密算法。     |
| AES_256_CBC |  1    | AES_256_CBC加密算法。     |

## HmacAlgo<sup>14+</sup>

数据库的HMAC算法枚举。请使用枚举名称而非枚举值。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 名称 | 值   | 说明 |
| ---- | ---- | ---- |
| SHA1 |  0    | HMAC_SHA1算法。     |
| SHA256 |  1    | HMAC_SHA256算法。     |
| SHA512 |  2    | HMAC_SHA512算法。    |

## KdfAlgo<sup>14+</sup>

数据库的PBKDF2算法枚举。请使用枚举名称而非枚举值。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 名称 | 值   | 说明 |
| ---- | ---- | ---- |
| KDF_SHA1 |  0    | PBKDF2_HMAC_SHA1算法。     |
| KDF_SHA256 |  1    | PBKDF2_HMAC_SHA256算法。     |
| KDF_SHA512 |  2    | PBKDF2_HMAC_SHA512算法。     |

## Tokenizer<sup>18+</sup>

描述fts（全文搜索）场景下使用的分词器枚举。请使用枚举名称而非枚举值。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 名称                              | 值   | 说明             |
| ------------------------------- | --- | -------------- |
| NONE_TOKENIZER     | 0  | 不使用分词器。      |
| ICU_TOKENIZER | 1 | 表示使用icu分词器，支持中文以及多国语言。指定icu分词器时，可指定使用哪种语言，例如zh_CN表示中文，tr_TR表示土耳其语等。详细支持的语言种类，请查阅[ICU分词器](https://gitee.com/openharmony/third_party_icu/blob/master/icu4c/source/data/lang/zh.txt)。详细的语言缩写，请查阅该目录（[ICU支持的语言缩写](https://gitee.com/openharmony/third_party_icu/tree/master/icu4c/source/data/locales)）下的文件名。|
| CUSTOM_TOKENIZER | 2 | 表示使用自研分词器，可支持中文（简体、繁体）、英文、阿拉伯数字。CUSTOM_TOKENIZER相比ICU_TOKENIZER在分词准确率、常驻内存占用上更有优势。 |

在使用不同的分词器时，使用的创表语句会有所区别。

**示例：**

使用ICU_TOKENIZER分词器时，创建表的示例：

```ts
import { relationalStore } from '@kit.ArkData'; // 导入模块
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

// 此处示例在Stage模式、Ability中实现，使用者也可以在其他合理场景中使用
class EntryAbility extends UIAbility {
  async onWindowStageCreate(windowStage: window.WindowStage) {
    let store: relationalStore.RdbStore | undefined = undefined;
    const STORE_CONFIG: relationalStore.StoreConfig = {
      name: "MyStore.db",
      securityLevel: relationalStore.SecurityLevel.S3,
      tokenizer: relationalStore.Tokenizer.ICU_TOKENIZER
    };
    store = await relationalStore.getRdbStore(this.context, STORE_CONFIG);

    const SQL_CREATE_TABLE = "CREATE VIRTUAL TABLE example USING fts4(name, content, tokenize=icu zh_CN)";
    if (store != undefined) {
      (store as relationalStore.RdbStore).executeSql(SQL_CREATE_TABLE, (err) => {
        if (err) {
          console.error(`ExecuteSql failed, code is ${err.code},message is ${err.message}`);
          return;
        }
        console.info('create virtual table done.');
      });
    }
  }
}
```

使用CUSTOM_TOKENIZER分词器时，创建表的示例：

```ts
import { relationalStore } from '@kit.ArkData'; // 导入模块
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

// 此处示例在Stage模式、Ability中实现，使用者也可以在其他合理场景中使用
class EntryAbility extends UIAbility {
  async onWindowStageCreate(windowStage: window.WindowStage) {
    let store: relationalStore.RdbStore | undefined = undefined;
    const STORE_CONFIG: relationalStore.StoreConfig = {
      name: "MyStore.db",
      securityLevel: relationalStore.SecurityLevel.S3,
      tokenizer: relationalStore.Tokenizer.CUSTOM_TOKENIZER
    };
    store = await relationalStore.getRdbStore(this.context, STORE_CONFIG);

    const SQL_CREATE_TABLE = "CREATE VIRTUAL TABLE example USING fts5(name, content, tokenize='customtokenizer')";
    if (store != undefined) {
      (store as relationalStore.RdbStore).executeSql(SQL_CREATE_TABLE, (err) => {
        if (err) {
          console.error(`ExecuteSql failed, code is ${err.code},message is ${err.message}`);
          return;
        }
        console.info('create virtual table done.');
      });
    }
  }
}
```

## AssetStatus<sup>10+</sup>

描述资产附件的状态枚举。请使用枚举名称而非枚举值。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 名称                              | 值   | 说明             |
| ------------------------------- | --- | -------------- |
| ASSET_NORMAL     | 1  | 表示资产状态正常。      |
| ASSET_INSERT | 2 | 表示资产需要插入到云端。 |
| ASSET_UPDATE | 3 | 表示资产需要更新到云端。 |
| ASSET_DELETE | 4 | 表示资产需要在云端删除。 |
| ASSET_ABNORMAL    | 5   | 表示资产状态异常。      |
| ASSET_DOWNLOADING | 6   | 表示资产正在下载到本地设备。 |

## Asset<sup>10+</sup>

记录资产附件（文件、图片、视频等类型文件）的相关信息。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 名称          | 类型                          | 必填  | 说明           |
| ----------- | --------------------------- | --- | ------------ |
| name        | string                      | 是   | 资产的名称。       |
| uri         | string                      | 是   | 资产的uri，在系统里的绝对路径。       |
| path        | string                      | 是   | 资产在应用沙箱里的路径。       |
| createTime  | string                      | 是   | 资产被创建出来的时间。   |
| modifyTime  | string                      | 是   | 资产最后一次被修改的时间。 |
| size        | string                      | 是   | 资产占用空间的大小。    |
| status      | [AssetStatus](#assetstatus10) | 否   | 资产的状态，默认值为ASSET_NORMAL。        |

## Assets<sup>10+</sup>

type Assets = Asset[]

表示[Asset](#asset10)类型的数组。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 类型    | 说明                 |
| ------- | -------------------- |
| [Asset](#asset10)[] | 表示Asset类型的数组。   |

## ValueType

type ValueType = null | number | string | boolean | Uint8Array | Asset | Assets | Float32Array | bigint

用于表示允许的数据字段类型，接口参数具体类型根据其功能而定。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 类型    | 说明                 |
| ------- | -------------------- |
| null<sup>10+</sup>    | 表示值类型为空。   |
| number  | 表示值类型为数字。   |
| string  | 表示值类型为字符串。  |
| boolean | 表示值类型为布尔值。 |
| Uint8Array<sup>10+</sup>           | 表示值类型为Uint8类型的数组。            |
| Asset<sup>10+</sup>  | 表示值类型为附件[Asset](#asset10)。<br/>当字段类型是Asset时，在创建表的sql语句中，类型应当为：ASSET。 |
| Assets<sup>10+</sup> | 表示值类型为附件数组[Assets](#assets10)。<br/>当字段类型是Assets时，在创建表的sql语句中，类型应当为：ASSETS。 |
| Float32Array<sup>12+</sup> | 表示值类型为浮点数组。<br/>当字段类型是Float32Array时，在创建表的sql语句中，类型应当为：floatvector(128)。 |
| bigint<sup>12+</sup> | 表示值类型为任意长度的整数。<br/>当字段类型是bigint时，在创建表的sql语句中，类型应当为：UNLIMITED INT，详见[通过关系型数据库实现数据持久化](../../database/data-persistence-by-rdb-store.md)。<br/>**说明：** bigint类型当前不支持比较大小，不支持如下谓词：between、notBetween、greaterThanlessThan、greaterThanOrEqualTo、lessThanOrEqualTo、orderByAsc、orderByDesc。<br/>bigint类型字段的数据写入时，需通过BigInt()方法或在数据尾部添加'n'的方式明确为bigint类型，如'let data = BigInt(1234)'或'let data = 1234n'。<br/>bigint字段如果写入number类型的数据，则查询该数据的返回类型为number，而非bigint。 |

## ValuesBucket

type ValuesBucket = Record<string, ValueType>

用于存储键值对的类型。不支持Sendable跨线程传递。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 类型              | 说明                           |
| ---------------- | ---------------------------- |
| Record<string, [ValueType](#valuetype)> | 表示键值对类型。键的类型为string，值的类型为[ValueType](#valuetype)。 |

## PRIKeyType<sup>10+</sup> 

type PRIKeyType = number | string

用于表示数据库表某一行主键的数据类型。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 类型             | 说明                               |
| ---------------- | ---------------------------------- |
| number | 主键的类型可以是number。 |
| string | 主键的类型可以是string。 |

## UTCTime<sup>10+</sup>

type UTCTime = Date

用于表示UTC类型时间的数据类型。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 类型 | 说明            |
| ---- | --------------- |
| Date | UTC类型的时间。 |

## ModifyTime<sup>10+</sup> 

type ModifyTime = Map<PRIKeyType, UTCTime>

用于存储数据库表的主键和修改时间的数据类型。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 类型                                                    | 说明                                                         |
| ------------------------------------------------------- | ------------------------------------------------------------ |
| Map<[PRIKeyType](#prikeytype10), [UTCTime](#utctime10)> | 键表示是数据库表某一行的主键，值表示该行的最后修改时间，用UTC格式表示。 |

## SyncMode

指数据库同步模式。请使用枚举名称而非枚举值。

| 名称           | 值   | 说明                               |
| -------------- | ---- | ---------------------------------- |
| SYNC_MODE_PUSH                       | 0   | 表示数据从本地设备推送到远程设备。<br>**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core |
| SYNC_MODE_PULL                       | 1   | 表示数据从远程设备拉至本地设备。<br>**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core |
| SYNC_MODE_TIME_FIRST<sup>10+</sup>   | 4   | 表示数据从修改时间较近的一端同步到修改时间较远的一端。<br>**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client |
| SYNC_MODE_NATIVE_FIRST<sup>10+</sup> | 5   | 表示数据从本地设备同步到云端。<br>**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client |
| SYNC_MODE_CLOUD_FIRST<sup>10+</sup>  | 6   | 表示数据从云端同步到本地设备。<br>**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client |

## Origin<sup>11+</sup>

表示数据来源。请使用枚举名称而非枚举值。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client

| 名称           | 值   | 说明                               |
| -------------- | ---- | ---------------------------------- |
| LOCAL       | 0   | 表示本地数据。      |
| CLOUD       | 1   | 表示云端同步的数据。     |
| REMOTE      | 2   | 表示端端同步的数据。 |

## Field<sup>11+</sup>

用于谓词查询条件的特殊字段。请使用枚举名称而非枚举值。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client

| 名称           | 值   | 说明                               |
| -------------- | ---- | ---------------------------------- |
| CURSOR_FIELD        | '#_cursor'     | 用于cursor查找的字段名。|
| ORIGIN_FIELD        | '#_origin'     | 用于cursor查找时指定数据来源的字段名。    |
| DELETED_FLAG_FIELD  | '#_deleted_flag' | 用于cursor查找的结果集返回时填充的字段，表示云端删除的数据同步到本地后数据是否清理。<br>返回的结果集中，该字段对应的value为false表示数据未清理，true表示数据已清理。|
| DATA_STATUS_FIELD<sup>12+</sup>   | '#_data_status' | 用于cursor查找的结果集返回时填充的字段，返回的结果集中，该字段对应的0表示正常数据，1表示退出账号保留数据，2表示云侧同步删除，3表示退出账户删除数据。|
| OWNER_FIELD  | '#_cloud_owner' | 用于共享表中查找owner时，返回的结果集中填充的字段，表示当前共享记录的共享发起者。|
| PRIVILEGE_FIELD  | '#_cloud_privilege' | 用于共享表中查找共享数据权限时，返回的结果集中填充的字段，表示当前共享记录的允许的操作权限。|
| SHARING_RESOURCE_FIELD   | '#_sharing_resource_field' | 用于数据共享查找共享数据的共享资源时，返回的结果集中填充的字段，表示共享数据的共享资源标识。|

## SubscribeType

描述订阅类型。请使用枚举名称而非枚举值。

| 名称                  | 值   | 说明               |
| --------------------- | ---- | ------------------ |
| SUBSCRIBE_TYPE_REMOTE | 0    | 订阅远程数据更改。<br>**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core |
| SUBSCRIBE_TYPE_CLOUD<sup>10+</sup> | 1  | 订阅云端数据更改。<br>**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client |
| SUBSCRIBE_TYPE_CLOUD_DETAILS<sup>10+</sup> | 2  | 订阅云端数据更改详情。<br>**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client |
| SUBSCRIBE_TYPE_LOCAL_DETAILS<sup>12+</sup> | 3  | 订阅本地数据更改详情。<br>**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core |

## RebuildType<sup>12+</sup>

描述数据库重建类型的枚举。请使用枚举名称而非枚举值。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 名称    | 值   | 说明                                                                                                             |
| ------- | ---- |----------------------------------------------------------------------------------------------------------------|
| NONE    | 0    | 表示数据库未进行重建。                                                                                                    |
| REBUILT | 1    | 表示数据库进行了重建并且生成了空数据库，需要应用重新建表和恢复数据。                                                                             |
| REPAIRED | 2    | 表示数据库进行了修复，恢复了未损坏的数据，当前只有[向量数据库](#storeconfig)具备该能力。 |

## ChangeType<sup>10+</sup>

描述数据变更类型的枚举。请使用枚举名称而非枚举值。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 名称                         | 值   | 说明                         |
| -------------------------- | --- | -------------------------- |
| DATA_CHANGE  | 0   | 表示是数据发生变更。   |
| ASSET_CHANGE | 1   | 表示是资产附件发生了变更。 |

## ChangeInfo<sup>10+</sup>

记录端云同步过程详情。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 名称     | 类型                               | 必填 | 说明                                                         |
| -------- | ---------------------------------- | ---- | ------------------------------------------------------------ |
| table    | string                             | 是   | 表示发生变化的表的名称。                                     |
| type     | [ChangeType](#changetype10)        | 是   | 表示发生变化的数据的类型，数据或者资产附件发生变化。         |
| inserted | Array\<string\> \| Array\<number\> | 是   | 记录插入数据的位置，如果该表的主键是string类型，该值是主键的值，否则该值表示插入数据的行号。 |
| updated  | Array\<string\> \| Array\<number\> | 是   | 记录更新数据的位置，如果该表的主键是string类型，该值是主键的值，否则该值表示更新数据的行号。 |
| deleted  | Array\<string\> \| Array\<number\> | 是   | 记录删除数据的位置，如果该表的主键是string类型，该值是主键的值，否则该值表示删除数据的行号。 |

## DistributedType<sup>10+</sup>

描述表的分布式类型的枚举。请使用枚举名称而非枚举值。

| 名称                | 值   | 说明                                                                                                 |
| ------------------ | --- | -------------------------------------------------------------------------------------------------- |
| DISTRIBUTED_DEVICE | 0  | 表示在不同设备之间分布式的数据库表。<br>**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core               |
| DISTRIBUTED_CLOUD  | 1   | 表示在设备和云端之间分布式的数据库表。<br>**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client |

## DistributedConfig<sup>10+</sup>

记录表的分布式配置信息。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 名称     | 类型    | 必填 | 说明                                                         |
| -------- | ------- | ---- | ------------------------------------------------------------ |
| autoSync   | boolean | 是   | 该值为true时，表示该表支持自动同步和手动同步；该值为false时，表示该表只支持手动同步，不支持自动同步。 |
| asyncDownloadAsset<sup>18+</sup> | boolean | 否 | 表示当前数据库在端云同步时，同步或异步下载资产。true表示优先下载完所有数据后，使用异步任务下载资产；false表示同步下载资产；默认值为false。 |
| enableCloud<sup>18+</sup> | boolean | 否 | 表示当前数据库是否允许端云同步。true表示允许端云同步；false表示不允许端云同步。默认值为true。 |

## ConflictResolution<sup>10+</sup>

插入和修改接口的冲突解决模式。请使用枚举名称而非枚举值。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 名称                 | 值   | 说明                                                         |
| -------------------- | ---- | ------------------------------------------------------------ |
| ON_CONFLICT_NONE | 0 | 表示当冲突发生时，不做任何处理。 |
| ON_CONFLICT_ROLLBACK | 1    | 表示当冲突发生时，中止SQL语句并回滚当前事务。                |
| ON_CONFLICT_ABORT    | 2    | 表示当冲突发生时，中止当前SQL语句，并撤销当前 SQL 语句所做的任何更改，但是由同一事务中先前的 SQL 语句引起的更改被保留并且事务保持活动状态。 |
| ON_CONFLICT_FAIL     | 3    | 表示当冲突发生时，中止当前 SQL 语句。但它不会撤销失败的 SQL 语句的先前更改，也不会结束事务。 |
| ON_CONFLICT_IGNORE   | 4    | 表示当冲突发生时，跳过包含违反约束的行并继续处理 SQL 语句的后续行。 |
| ON_CONFLICT_REPLACE  | 5    | 表示当冲突发生时，在插入或更新当前行之前删除导致约束违例的预先存在的行，并且命令会继续正常执行。 |

## Progress<sup>10+</sup>

描述端云同步过程的枚举。请使用枚举名称而非枚举值。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 名称             | 值   | 说明                     |
| ---------------- | ---- | ------------------------ |
| SYNC_BEGIN       | 0    | 表示端云同步过程开始。   |
| SYNC_IN_PROGRESS | 1    | 表示正在端云同步过程中。 |
| SYNC_FINISH      | 2    | 表示端云同步过程已完成。 |

## Statistic<sup>10+</sup>

描述数据库表的端云同步过程的统计信息。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 名称       | 类型   | 必填 | 说明                                     |
| ---------- | ------ | ---- | ---------------------------------------- |
| total      | number | 是   | 表示数据库表中需要端云同步的总行数。     |
| successful | number | 是   | 表示数据库表中端云同步成功的行数。       |
| failed     | number | 是   | 表示数据库表中端云同步失败的行数。       |
| remained   | number | 是   | 表示数据库表中端云同步剩余未执行的行数。 |

## TableDetails<sup>10+</sup>

描述数据库表执行端云同步任务上传和下载的统计信息。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 名称     | 类型                      | 必填 | 说明                                       |
| -------- | ------------------------- | ---- | ------------------------------------------ |
| upload   | [Statistic](#statistic10) | 是   | 表示数据库表中端云同步上传过程的统计信息。 |
| download | [Statistic](#statistic10) | 是   | 表示数据库表中端云同步下载过程的统计信息。 |

## ProgressCode<sup>10+</sup>

表示端云同步过程的状态。请使用枚举名称而非枚举值。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 名称                  | 值   | 说明                                                         |
| --------------------- | ---- | ------------------------------------------------------------ |
| SUCCESS               | 0    | 表示端云同步过程成功。                                       |
| UNKNOWN_ERROR         | 1    | 表示端云同步过程遇到未知错误。                               |
| NETWORK_ERROR         | 2    | 表示端云同步过程遇到网络错误。                               |
| CLOUD_DISABLED        | 3    | 表示云端不可用。                                             |
| LOCKED_BY_OTHERS      | 4    | 表示有其他设备正在端云同步，本设备无法进行端云同步。<br>请确保无其他设备占用云端资源后，再使用本设备进行端云同步任务。 |
| RECORD_LIMIT_EXCEEDED | 5    | 表示本次端云同步需要同步的条目或大小超出最大值。由云端配置最大值。 |
| NO_SPACE_FOR_ASSET    | 6    | 表示云空间剩余空间小于待同步的资产大小。                     |
| BLOCKED_BY_NETWORK_STRATEGY<sup>12+</sup>    | 7    | 表示端云同步被网络策略限制。                     |

## ProgressDetails<sup>10+</sup>

描述数据库整体执行端云同步任务上传和下载的统计信息。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 名称     | 类型                                              | 必填 | 说明                                                         |
| -------- | ------------------------------------------------- | ---- | ------------------------------------------------------------ |
| schedule | [Progress](#progress10)                           | 是   | 表示端云同步过程。                                           |
| code     | [ProgressCode](#progresscode10)                   | 是   | 表示端云同步过程的状态。                                     |
| details  | Record<string, [TableDetails](#tabledetails10)> | 是   | 表示端云同步各表的统计信息。<br>键表示表名，值表示该表的端云同步过程统计信息。 |

## SqlExecutionInfo<sup>12+</sup>

描述数据库执行的SQL语句的统计信息。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 名称     | 类型                                               | 只读 | 可选  |说明                                                         |
| -------- | ------------------------------------------------- | ---- | ---- | -------------------------------------------------------- |
| sql<sup>12+</sup>           | Array&lt;string&gt;            | 是   |   否   | 表示执行的SQL语句的数组。当[batchInsert](#batchinsert)的参数太大时，可能有多个SQL。      |
| totalTime<sup>12+</sup>      | number                        | 是   |   否   | 表示执行SQL语句的总时间，单位为μs。                                    |
| waitTime<sup>12+</sup>       | number                        | 是   |   否   | 表示获取句柄的时间，单位为μs。                                         |
| prepareTime<sup>12+</sup>    | number                        | 是   |   否   | 表示准备SQL和绑定参数的时间，单位为μs。                                 |
| executeTime<sup>12+</sup>    | number                        | 是   |   否   | 表示执行SQL语句的时间，单位为μs。 |

## TransactionType<sup>14+</sup>

描述创建事务对象的枚举。请使用枚举名称而非枚举值。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 名称             | 值   | 说明                     |
| ---------------- | ---- | ------------------------ |
| DEFERRED       | 0    | 表示创建一个DEFERRED类型的事务对象，该类型的事务对象在创建时只会关闭自动提交而不会真正开始事务，只有在首次读或写操作时会真正开始一个读或写事务。   |
| IMMEDIATE | 1    | 表示创建一个IMMEDIATE类型的事务对象，该类型的事务对象在创建时会真正开始一个写事务；如果有别的写事务未提交，则会创建失败，返回错误码14800024。 |
| EXCLUSIVE      | 2    | 表示创建一个EXCLUSIVE类型的事务对象，该类型的事务在WAL模式下和IMMEDIATE相同，但在其它日志模式下能够防止事务期间有其它连接读取数据库。 |

## TransactionOptions<sup>14+</sup>

事务对象的配置信息。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 名称        | 类型          | 必填 | 说明                                                      |
| ------------- | ------------- | ---- | --------------------------------------------------------- |
| transactionType          | [TransactionType](#transactiontype14)        | 否   | 事务类型。默认为DEFERRED。  |

## ColumnType<sup>18+</sup>

描述数据库列存储类型的枚举。请使用枚举名称而非枚举值。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 名称          | 值   | 说明                                                         |
| ------------- | ---- | ------------------------------------------------------------ |
| NULL          | 0    | 表示列数据类型为NULL。                                       |
| INTEGER       | 1    | 表示列数据类型为64位整数。可用于保存8位（包括布尔值）、16位、32位、64位整数。如果64位整数大于2^53或小于-2^53，需使用[getString](#getstring)将64位整数转换为字符串。 |
| REAL          | 2    | 表示列类型为浮点数。                                         |
| TEXT          | 3    | 表示列类型为字符串。                                         |
| BLOB          | 4    | 表示列类型为Uint8Array。                                     |
| ASSET         | 5    | 表示列类型为[Asset](#asset10)。                              |
| ASSETS        | 6    | 表示列类型为[Assets](#assets10)。                            |
| FLOAT_VECTOR  | 7    | 表示列类型为Float32Array。                                   |
| UNLIMITED_INT | 8    | 表示列类型为bigint。                                         |

## RdbPredicates

表示关系型数据库（RDB）的谓词。该类确定RDB中条件表达式的值是true还是false。谓词间支持多语句拼接，拼接时默认使用and()连接。不支持Sendable跨线程传递。

### constructor

constructor(name: string)

构造函数。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明         |
| ------ | ------ | ---- | ------------ |
| name   | string | 是   | 数据库表名。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                                                                                       |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

**示例：**

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
```

### inDevices

inDevices(devices: Array&lt;string&gt;): RdbPredicates

同步分布式数据库时连接到组网内指定的远程设备。

> **说明：**
>
> 其中devices通过调用[deviceManager.getAvailableDeviceListSync](../apis-distributedservice-kit/js-apis-distributedDeviceManager.md#getavailabledevicelistsync)方法得到。
数据库同步时调用Sync接口，需要在入参谓词中调用inDevices接口选择设备。如果不调用inDevices接口即默认连接组网内所有的设备。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名  | 类型                | 必填 | 说明                       |
| ------- | ------------------- | ---- | -------------------------- |
| devices | Array&lt;string&gt; | 是   | 指定的组网内的远程设备ID。 |

**返回值**：

| 类型                                 | 说明                       |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](#rdbpredicates) | 返回与指定字段匹配的谓词。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                                                                                       |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

**示例：**

```ts
import { distributedDeviceManager } from '@kit.DistributedServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

let dmInstance: distributedDeviceManager.DeviceManager;
let deviceIds: Array<string> = [];

try {
  dmInstance = distributedDeviceManager.createDeviceManager("com.example.appdatamgrverify");
  let devices: Array<distributedDeviceManager.DeviceBasicInfo> = dmInstance.getAvailableDeviceListSync();
  for (let i = 0; i < devices.length; i++) {
    deviceIds[i] = devices[i].networkId!;
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error("createDeviceManager errCode:" + code + ",errMessage:" + message);
}

let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.inDevices(deviceIds);
```

### inAllDevices

inAllDevices(): RdbPredicates

同步分布式数据库时连接到组网内所有的远程设备。


**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**返回值**：

| 类型                                 | 说明                       |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](#rdbpredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.inAllDevices();
```

### equalTo

equalTo(field: string, value: ValueType): RdbPredicates

配置谓词以匹配数据表的field列中值为value的字段。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型                    | 必填 | 说明                   |
| ------ | ----------------------- | ---- | ---------------------- |
| field  | string                  | 是   | 数据库表中的列名。     |
| value  | [ValueType](#valuetype) | 是   | 指示要与谓词匹配的值。 |

**返回值**：

| 类型                                 | 说明                       |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](#rdbpredicates) | 返回与指定字段匹配的谓词。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                                                                                       |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

**示例：**

```ts
// 匹配数据表的"NAME"列中值为"Lisa"的字段
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Lisa");
```


### notEqualTo

notEqualTo(field: string, value: ValueType): RdbPredicates

配置谓词以匹配数据表的field列中值不为value的字段。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型                    | 必填 | 说明                   |
| ------ | ----------------------- | ---- | ---------------------- |
| field  | string                  | 是   | 数据库表中的列名。     |
| value  | [ValueType](#valuetype) | 是   | 指示要与谓词匹配的值。 |

**返回值**：

| 类型                                 | 说明                       |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](#rdbpredicates) | 返回与指定字段匹配的谓词。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                                                                                       |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

**示例：**

```ts
// 匹配数据表的"NAME"列中值不为"Lisa"的字段
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.notEqualTo("NAME", "Lisa");
```


### beginWrap

beginWrap(): RdbPredicates

向谓词添加左括号。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**返回值**：

| 类型                                 | 说明                      |
| ------------------------------------ | ------------------------- |
| [RdbPredicates](#rdbpredicates) | 返回带有左括号的Rdb谓词。 |

**示例：**

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Lisa")
  .beginWrap()
  .equalTo("AGE", 18)
  .or()
  .equalTo("SALARY", 200.5)
  .endWrap();
```

### endWrap

endWrap(): RdbPredicates

向谓词添加右括号。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**返回值**：

| 类型                                 | 说明                      |
| ------------------------------------ | ------------------------- |
| [RdbPredicates](#rdbpredicates) | 返回带有右括号的Rdb谓词。 |

**示例：**

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Lisa")
  .beginWrap()
  .equalTo("AGE", 18)
  .or()
  .equalTo("SALARY", 200.5)
  .endWrap();
```

### or

or(): RdbPredicates

将或条件添加到谓词中。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**返回值**：

| 类型                                 | 说明                      |
| ------------------------------------ | ------------------------- |
| [RdbPredicates](#rdbpredicates) | 返回带有或条件的Rdb谓词。 |

**示例：**

```ts
// 匹配数据表的"NAME"列中值为"Lisa"或"Rose"的字段
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Lisa")
  .or()
  .equalTo("NAME", "Rose");
```

### and

and(): RdbPredicates

向谓词添加和条件。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**返回值**：

| 类型                                 | 说明                      |
| ------------------------------------ | ------------------------- |
| [RdbPredicates](#rdbpredicates) | 返回带有和条件的Rdb谓词。 |

**示例：**

```ts
// 匹配数据表的"NAME"列中值为"Lisa"且"SALARY"列中值为"200.5"的字段
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Lisa")
  .and()
  .equalTo("SALARY", 200.5);
```

### contains

contains(field: string, value: string): RdbPredicates

配置谓词以匹配数据表的field列中包含value的字段。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | ---------------------- |
| field  | string | 是   | 数据库表中的列名。     |
| value  | string | 是   | 指示要与谓词匹配的值。 |

**返回值**：

| 类型                                 | 说明                       |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](#rdbpredicates) | 返回与指定字段匹配的谓词。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                                                                                       |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

**示例：**

```ts
// 匹配数据表的"NAME"列中包含"os"的字段，如"Rose"
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.contains("NAME", "os");
```

### beginsWith

beginsWith(field: string, value: string): RdbPredicates

配置谓词以匹配数据表的field列中以value开头的字段。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | ---------------------- |
| field  | string | 是   | 数据库表中的列名。     |
| value  | string | 是   | 指示要与谓词匹配的值。 |

**返回值**：

| 类型                                 | 说明                       |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](#rdbpredicates) | 返回与指定字段匹配的谓词。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                                                                                       |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

**示例：**

```ts
// 匹配数据表的"NAME"列中以"Li"开头的字段，如"Lisa"
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.beginsWith("NAME", "Li");
```

### endsWith

endsWith(field: string, value: string): RdbPredicates

配置谓词以匹配数据表的field列中以value结尾的字段。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | ---------------------- |
| field  | string | 是   | 数据库表中的列名。     |
| value  | string | 是   | 指示要与谓词匹配的值。 |

**返回值**：

| 类型                                 | 说明                       |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](#rdbpredicates) | 返回与指定字段匹配的谓词。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                                                                                       |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

**示例：**

```ts
// 匹配数据表的"NAME"列中以"se"结尾的字段，如"Rose"
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.endsWith("NAME", "se");
```

### isNull

isNull(field: string): RdbPredicates

配置谓词以匹配数据表的field列中值为null的字段。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| field  | string | 是   | 数据库表中的列名。 |

**返回值**：

| 类型                                 | 说明                       |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](#rdbpredicates) | 返回与指定字段匹配的谓词。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                                                                                       |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

**示例**：

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.isNull("NAME");
```

### isNotNull

isNotNull(field: string): RdbPredicates

配置谓词以匹配数据表的field列中值不为null的字段。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| field  | string | 是   | 数据库表中的列名。 |

**返回值**：

| 类型                                 | 说明                       |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](#rdbpredicates) | 返回与指定字段匹配的谓词。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                                                                                       |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

**示例：**

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.isNotNull("NAME");
```

### like

like(field: string, value: string): RdbPredicates

配置谓词以匹配数据表的field列中值类似于value的字段。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | ---------------------- |
| field  | string | 是   | 数据库表中的列名。     |
| value  | string | 是   | 指示要与谓词匹配的值。 |

**返回值**：

| 类型                                 | 说明                       |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](#rdbpredicates) | 返回与指定字段匹配的谓词。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                                                                                       |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

**示例：**

```ts
// 匹配数据表的"NAME"列中值类似于"os"的字段，如"Rose"
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.like("NAME", "%os%");
```

### glob

glob(field: string, value: string): RdbPredicates

配置谓词匹配数据字段为string的指定字段。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| field  | string | 是   | 数据库表中的列名。                                           |
| value  | string | 是   | 指示要与谓词匹配的值。<br>支持通配符，*表示0个、1个或多个数字或字符，?表示1个数字或字符。 |

**返回值**：

| 类型                                 | 说明                       |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](#rdbpredicates) | 返回与指定字段匹配的谓词。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                                                                                       |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

**示例：**

```ts
// 匹配数据表的"NAME"列中类型为string且值为"?h*g"的字段
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.glob("NAME", "?h*g");
```

### between

between(field: string, low: ValueType, high: ValueType): RdbPredicates

配置谓词以匹配数据表的field列中值在给定范围内的字段（包含范围边界）。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型                    | 必填 | 说明                       |
| ------ | ----------------------- | ---- | -------------------------- |
| field  | string                  | 是   | 数据库表中的列名。         |
| low    | [ValueType](#valuetype) | 是   | 指示与谓词匹配的最小值。   |
| high   | [ValueType](#valuetype) | 是   | 指示与谓词匹配的最大值。 |

**返回值**：

| 类型                                 | 说明                       |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](#rdbpredicates) | 返回与指定字段匹配的谓词。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                                                                                       |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

**示例：**

```ts
// 匹配数据表的"AGE"列中大于等于10且小于等于50的值
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.between("AGE", 10, 50);
```

### notBetween

notBetween(field: string, low: ValueType, high: ValueType): RdbPredicates

配置谓词以匹配数据表的field列中值超出给定范围的字段（不包含范围边界）。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型                    | 必填 | 说明                       |
| ------ | ----------------------- | ---- | -------------------------- |
| field  | string                  | 是   | 数据库表中的列名。         |
| low    | [ValueType](#valuetype) | 是   | 指示与谓词匹配的最小值。   |
| high   | [ValueType](#valuetype) | 是   | 指示要与谓词匹配的最大值。 |

**返回值**：

| 类型                                 | 说明                       |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](#rdbpredicates) | 返回与指定字段匹配的谓词。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                                                                                       |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

**示例：**

```ts
// 匹配数据表的"AGE"列中小于10或大于50的值
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.notBetween("AGE", 10, 50);
```

### greaterThan

greaterThan(field: string, value: ValueType): RdbPredicates

配置谓词以匹配数据表的field列中值大于value的字段。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型                    | 必填 | 说明                   |
| ------ | ----------------------- | ---- | ---------------------- |
| field  | string                  | 是   | 数据库表中的列名。     |
| value  | [ValueType](#valuetype) | 是   | 指示要与谓词匹配的值。 |

**返回值**：

| 类型                                 | 说明                       |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](#rdbpredicates) | 返回与指定字段匹配的谓词。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                                                                                       |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

**示例：**

```ts
// 匹配数据表的"AGE"列中大于18的值
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.greaterThan("AGE", 18);
```

### lessThan

lessThan(field: string, value: ValueType): RdbPredicates

配置谓词以匹配数据表的field列中值小于value的字段。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型                    | 必填 | 说明                   |
| ------ | ----------------------- | ---- | ---------------------- |
| field  | string                  | 是   | 数据库表中的列名。     |
| value  | [ValueType](#valuetype) | 是   | 指示要与谓词匹配的值。 |

**返回值**：

| 类型                                 | 说明                       |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](#rdbpredicates) | 返回与指定字段匹配的谓词。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                                                                                       |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

**示例：**

```ts
// 匹配数据表的"AGE"列中小于20的值
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.lessThan("AGE", 20);
```

### greaterThanOrEqualTo

greaterThanOrEqualTo(field: string, value: ValueType): RdbPredicates

配置谓词以匹配数据表的field列中值大于或者等于value的字段。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型                    | 必填 | 说明                   |
| ------ | ----------------------- | ---- | ---------------------- |
| field  | string                  | 是   | 数据库表中的列名。     |
| value  | [ValueType](#valuetype) | 是   | 指示要与谓词匹配的值。 |

**返回值**：

| 类型                                 | 说明                       |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](#rdbpredicates) | 返回与指定字段匹配的谓词。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                                                                                       |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

**示例：**

```ts
// 匹配数据表的"AGE"列中大于等于18的值
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.greaterThanOrEqualTo("AGE", 18);
```

### lessThanOrEqualTo

lessThanOrEqualTo(field: string, value: ValueType): RdbPredicates

配置谓词以匹配数据表的field列中值小于或者等于value的字段。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型                    | 必填 | 说明                   |
| ------ | ----------------------- | ---- | ---------------------- |
| field  | string                  | 是   | 数据库表中的列名。     |
| value  | [ValueType](#valuetype) | 是   | 指示要与谓词匹配的值。 |

**返回值**：

| 类型                                 | 说明                       |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](#rdbpredicates) | 返回与指定字段匹配的谓词。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                                                                                       |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

**示例：**

```ts
// 匹配数据表的"AGE"列中小于等于20的值
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.lessThanOrEqualTo("AGE", 20);
```

### orderByAsc

orderByAsc(field: string): RdbPredicates

配置谓词以匹配数据表的field列中值按升序排序的列。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| field  | string | 是   | 数据库表中的列名。 |

**返回值**：

| 类型                                 | 说明                       |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](#rdbpredicates) | 返回与指定字段匹配的谓词。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                                                                                       |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

**示例：**

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.orderByAsc("NAME");
```

### orderByDesc

orderByDesc(field: string): RdbPredicates

配置谓词以匹配数据表的field列中值按降序排序的列。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| field  | string | 是   | 数据库表中的列名。 |

**返回值**：

| 类型                                 | 说明                       |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](#rdbpredicates) | 返回与指定字段匹配的谓词。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                                                                                       |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

**示例：**

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.orderByDesc("AGE");
```

### distinct

distinct(): RdbPredicates

配置谓词以过滤重复记录并仅保留其中一个。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**返回值**：

| 类型                                 | 说明                           |
| ------------------------------------ | ------------------------------ |
| [RdbPredicates](#rdbpredicates) | 返回可用于过滤重复记录的谓词。 |

**示例：**

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Rose").distinct();
```

### limitAs

limitAs(value: number): RdbPredicates

设置谓词的最大数据记录数量。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明             |
| ------ | ------ | ---- | ---------------- |
| value  | number | 是   | 最大数据记录数，取值应为正整数，传入值小于等于0时，不会限制记录数量。 |

**返回值**：

| 类型                                 | 说明                                 |
| ------------------------------------ | ------------------------------------ |
| [RdbPredicates](#rdbpredicates) | 返回可用于设置最大数据记录数的谓词。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**               |
| --------- |--------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

**示例：**

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Rose").limitAs(3);
```

### offsetAs

offsetAs(rowOffset: number): RdbPredicates

设置谓词查询结果返回的起始位置。需要同步调用limitAs接口指定查询数量，否则将无查询结果。如需查询指定偏移位置后的所有行，limitAs接口调用需传参数-1。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名    | 类型   | 必填 | 说明                               |
| --------- | ------ | ---- | ---------------------------------- |
| rowOffset | number | 是   | 返回结果的起始位置，取值应为正整数。结果集指针起始位置为0，传入值小于等于0时，查询结果将从0下标位置返回。 |

**返回值**：

| 类型                                 | 说明                                 |
| ------------------------------------ | ------------------------------------ |
| [RdbPredicates](#rdbpredicates) | 返回具有指定返回结果起始位置的谓词。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                                                                                       |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

**示例：**

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Rose").limitAs(-1).offsetAs(3);
```

### groupBy

groupBy(fields: Array&lt;string&gt;): RdbPredicates

配置谓词按指定列分组查询结果。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型                | 必填 | 说明                 |
| ------ | ------------------- | ---- | -------------------- |
| fields | Array&lt;string&gt; | 是   | 指定分组依赖的列名。 |

**返回值**：

| 类型                                 | 说明                   |
| ------------------------------------ | ---------------------- |
| [RdbPredicates](#rdbpredicates) | 返回分组查询列的谓词。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                                                                                       |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

**示例：**

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.groupBy(["AGE", "NAME"]);
```

### indexedBy

indexedBy(field: string): RdbPredicates

配置谓词以指定索引列。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明           |
| ------ | ------ | ---- | -------------- |
| field  | string | 是   | 索引列的名称。 |

**返回值**：


| 类型                                 | 说明                                  |
| ------------------------------------ | ------------------------------------- |
| [RdbPredicates](#rdbpredicates) | 返回具有指定索引列的RdbPredicates。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                                                                                       |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

**示例：**

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.indexedBy("SALARY");
```

### in

in(field: string, value: Array&lt;ValueType&gt;): RdbPredicates

配置谓词以匹配数据表的field列中值在给定范围内的字段。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型                                 | 必填 | 说明                                    |
| ------ | ------------------------------------ | ---- | --------------------------------------- |
| field  | string                               | 是   | 数据库表中的列名。                      |
| value  | Array&lt;[ValueType](#valuetype)&gt; | 是   | 以ValueType型数组形式指定的要匹配的值。 |

**返回值**：

| 类型                                 | 说明                       |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](#rdbpredicates) | 返回与指定字段匹配的谓词。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                                                                                       |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

**示例：**

```ts
// 匹配数据表的"AGE"列中在[18，20]中的值
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.in("AGE", [18, 20]);
```

### notIn

notIn(field: string, value: Array&lt;ValueType&gt;): RdbPredicates

将谓词配置为匹配数据字段为ValueType且值超出给定范围的指定字段。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型                                 | 必填 | 说明                                  |
| ------ | ------------------------------------ | ---- | ------------------------------------- |
| field  | string                               | 是   | 数据库表中的列名。                    |
| value  | Array&lt;[ValueType](#valuetype)&gt; | 是   | 以ValueType数组形式指定的要匹配的值。 |

**返回值**：

| 类型                                 | 说明                       |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](#rdbpredicates) | 返回与指定字段匹配的谓词。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                                                                                       |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

**示例：**

```ts
// 匹配数据表的"NAME"列中不在["Lisa", "Rose"]中的值
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.notIn("NAME", ["Lisa", "Rose"]);
```

### notContains<sup>12+</sup>

notContains(field: string, value: string): RdbPredicates

配置谓词以匹配数据表的field列中不包含value的字段。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | ---------------------- |
| field  | string | 是   | 数据库表中的列名。     |
| value  | string | 是   | 指示要与谓词匹配的值。 |

**返回值**：

| 类型                            | 说明                       |
| ------------------------------- | -------------------------- |
| [RdbPredicates](#rdbpredicates) | 返回与指定字段匹配的谓词。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                                                                                       |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

**示例：**

```ts
// 匹配数据表的"NAME"列中不包含"os"的字段，如列表中的"Lisa"
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.notContains("NAME", "os");
```

### notLike<sup>12+</sup>

notLike(field: string, value: string): RdbPredicates

配置谓词以匹配数据表的field列中值不存在类似于value的字段。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | ---------------------- |
| field  | string | 是   | 数据库表中的列名。     |
| value  | string | 是   | 指示要与谓词匹配的值。 |

**返回值**：

| 类型                            | 说明                       |
| ------------------------------- | -------------------------- |
| [RdbPredicates](#rdbpredicates) | 返回与指定字段匹配的谓词。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                                                                                       |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

**示例：**

```ts
// 匹配数据表的"NAME"列中不等于"os"的字段，如列表中的"Rose"
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.notLike("NAME", "os");
```



## RdbStore

提供管理关系数据库（RDB）方法的接口。

在使用以下相关接口前，请使用[executeSql](#executesql)接口初始化数据库表结构和相关数据。

### 属性

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 名称         | 类型            | 只读       | 可选 | 说明                             |
| ------------ | ----------- | ---- | -------------------------------- | -------------------------------- |
| version<sup>10+</sup>  | number | 否 | 否   | 设置和获取数据库版本，值为大于0的正整数。       |
| rebuilt<sup>12+</sup> | [RebuildType](#rebuildtype12) | 是 | 否 | 用于获取数据库是否进行过重建或修复。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported. |
| 14800000  | Inner error. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |

**示例：**

```ts
// 设置数据库版本
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

let store: relationalStore.RdbStore | undefined = undefined;

class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    const STORE_CONFIG: relationalStore.StoreConfig = {
      name: "RdbTest.db",
      securityLevel: relationalStore.SecurityLevel.S3,
    };
    const SQL_CREATE_TABLE = 'CREATE TABLE IF NOT EXISTS EMPLOYEE (ID INTEGER PRIMARY KEY AUTOINCREMENT, NAME TEXT NOT NULL, AGE INTEGER, SALARY REAL, CODES BLOB, IDENTITY UNLIMITED INT, ASSETDATA ASSET, ASSETSDATA ASSETS, FLOATARRAY floatvector(128))';
    relationalStore.getRdbStore(this.context, STORE_CONFIG).then(async (rdbStore: relationalStore.RdbStore) => {
      store = rdbStore;
      await (store as relationalStore.RdbStore).executeSql(SQL_CREATE_TABLE);
      console.info('Get RdbStore successfully.');
    }).catch((err: BusinessError) => {
      console.error(`Get RdbStore failed, code is ${err.code},message is ${err.message}`);
    });

    // 设置数据库版本
    if (store != undefined) {
      (store as relationalStore.RdbStore).version = 3;
      // 获取数据库版本
      console.info(`RdbStore version is ${store.version}`);
      // 获取数据库是否重建
      console.info(`RdbStore rebuilt is ${store.rebuilt}`);
    }
  }
}
```

### insert

insert(table: string, values: ValuesBucket, callback: AsyncCallback&lt;number&gt;):void

向目标表中插入一行数据，使用callback异步回调。由于共享内存大小限制为2Mb，因此单条数据的大小需小于2Mb，否则会查询失败。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型                          | 必填 | 说明                                                       |
| -------- | ----------------------------- | ---- | ---------------------------------------------------------- |
| table    | string                        | 是   | 指定的目标表名。                                           |
| values   | [ValuesBucket](#valuesbucket) | 是   | 表示要插入到表中的数据行。                                 |
| callback | AsyncCallback&lt;number&gt;   | 是   | 指定callback回调函数。如果操作成功，返回行ID；否则返回-1。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |
| 14800047  | The WAL file size exceeds the default limit. |

**示例：**

```ts
let value1 = "Lisa";
let value2 = 18;
let value3 = 100.5;
let value4 = new Uint8Array([1, 2, 3, 4, 5]);

// 以下三种方式可用
const valueBucket1: relationalStore.ValuesBucket = {
  'NAME': value1,
  'AGE': value2,
  'SALARY': value3,
  'CODES': value4,
};
const valueBucket2: relationalStore.ValuesBucket = {
  NAME: value1,
  AGE: value2,
  SALARY: value3,
  CODES: value4,
};
const valueBucket3: relationalStore.ValuesBucket = {
  "NAME": value1,
  "AGE": value2,
  "SALARY": value3,
  "CODES": value4,
};

if (store != undefined) {
  (store as relationalStore.RdbStore).insert("EMPLOYEE", valueBucket1, (err: BusinessError, rowId: number) => {
    if (err) {
      console.error(`Insert is failed, code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info(`Insert is successful, rowId = ${rowId}`);
  });
}
```

### insert<sup>10+</sup>

insert(table: string, values: ValuesBucket,  conflict: ConflictResolution, callback: AsyncCallback&lt;number&gt;):void

向目标表中插入一行数据，使用callback异步回调。由于共享内存大小限制为2Mb，因此单条数据的大小需小于2Mb，否则会查询失败。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型                                        | 必填 | 说明                                                       |
| -------- | ------------------------------------------- | ---- | ---------------------------------------------------------- |
| table    | string                                      | 是   | 指定的目标表名。                                           |
| values   | [ValuesBucket](#valuesbucket)               | 是   | 表示要插入到表中的数据行。                                 |
| conflict | [ConflictResolution](#conflictresolution10) | 是   | 指定冲突解决模式。                                         |
| callback | AsyncCallback&lt;number&gt;                 | 是   | 指定callback回调函数。如果操作成功，返回行ID；否则返回-1。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ---------------------------------------------------- |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |
| 14800047  | The WAL file size exceeds the default limit. |

**示例：**

```ts
let value1 = "Lisa";
let value2 = 18;
let value3 = 100.5;
let value4 = new Uint8Array([1, 2, 3, 4, 5]);

// 以下三种方式可用
const valueBucket1: relationalStore.ValuesBucket = {
  'NAME': value1,
  'AGE': value2,
  'SALARY': value3,
  'CODES': value4,
};
const valueBucket2: relationalStore.ValuesBucket = {
  NAME: value1,
  AGE: value2,
  SALARY: value3,
  CODES: value4,
};
const valueBucket3: relationalStore.ValuesBucket = {
  "NAME": value1,
  "AGE": value2,
  "SALARY": value3,
  "CODES": value4,
};

if (store != undefined) {
  (store as relationalStore.RdbStore).insert("EMPLOYEE", valueBucket1, relationalStore.ConflictResolution.ON_CONFLICT_REPLACE,
    (err: BusinessError, rowId: number) => {
      if (err) {
        console.error(`Insert is failed, code is ${err.code},message is ${err.message}`);
        return;
      }
      console.info(`Insert is successful, rowId = ${rowId}`);
    });
}
```

### insert

insert(table: string, values: ValuesBucket):Promise&lt;number&gt;

向目标表中插入一行数据，使用Promise异步回调。由于共享内存大小限制为2Mb，因此单条数据的大小需小于2Mb，否则会查询失败。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型                          | 必填 | 说明                       |
| ------ | ----------------------------- | ---- | -------------------------- |
| table  | string                        | 是   | 指定的目标表名。           |
| values | [ValuesBucket](#valuesbucket) | 是   | 表示要插入到表中的数据行。 |

**返回值**：

| 类型                  | 说明                                              |
| --------------------- | ------------------------------------------------- |
| Promise&lt;number&gt; | Promise对象。如果操作成功，返回行ID；否则返回-1。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |
| 14800047  | The WAL file size exceeds the default limit. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let value1 = "Lisa";
let value2 = 18;
let value3 = 100.5;
let value4 = new Uint8Array([1, 2, 3, 4, 5]);

// 以下三种方式可用
const valueBucket1: relationalStore.ValuesBucket = {
  'NAME': value1,
  'AGE': value2,
  'SALARY': value3,
  'CODES': value4,
};
const valueBucket2: relationalStore.ValuesBucket = {
  NAME: value1,
  AGE: value2,
  SALARY: value3,
  CODES: value4,
};
const valueBucket3: relationalStore.ValuesBucket = {
  "NAME": value1,
  "AGE": value2,
  "SALARY": value3,
  "CODES": value4,
};

if (store != undefined) {
  (store as relationalStore.RdbStore).insert("EMPLOYEE", valueBucket1).then((rowId: number) => {
    console.info(`Insert is successful, rowId = ${rowId}`);
  }).catch((err: BusinessError) => {
    console.error(`Insert is failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### insert<sup>10+</sup>

insert(table: string, values: ValuesBucket,  conflict: ConflictResolution):Promise&lt;number&gt;

向目标表中插入一行数据，使用Promise异步回调。由于共享内存大小限制为2Mb，因此单条数据的大小需小于2Mb，否则会查询失败。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型                                        | 必填 | 说明                       |
| -------- | ------------------------------------------- | ---- | -------------------------- |
| table    | string                                      | 是   | 指定的目标表名。           |
| values   | [ValuesBucket](#valuesbucket)               | 是   | 表示要插入到表中的数据行。 |
| conflict | [ConflictResolution](#conflictresolution10) | 是   | 指定冲突解决模式。         |

**返回值**：

| 类型                  | 说明                                              |
| --------------------- | ------------------------------------------------- |
| Promise&lt;number&gt; | Promise对象。如果操作成功，返回行ID；否则返回-1。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |
| 14800047  | The WAL file size exceeds the default limit. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let value1 = "Lisa";
let value2 = 18;
let value3 = 100.5;
let value4 = new Uint8Array([1, 2, 3, 4, 5]);

// 以下三种方式可用
const valueBucket1: relationalStore.ValuesBucket = {
  'NAME': value1,
  'AGE': value2,
  'SALARY': value3,
  'CODES': value4,
};
const valueBucket2: relationalStore.ValuesBucket = {
  NAME: value1,
  AGE: value2,
  SALARY: value3,
  CODES: value4,
};
const valueBucket3: relationalStore.ValuesBucket = {
  "NAME": value1,
  "AGE": value2,
  "SALARY": value3,
  "CODES": value4,
};

if (store != undefined) {
  (store as relationalStore.RdbStore).insert("EMPLOYEE", valueBucket1, relationalStore.ConflictResolution.ON_CONFLICT_REPLACE).then((rowId: number) => {
    console.info(`Insert is successful, rowId = ${rowId}`);
  }).catch((err: BusinessError) => {
    console.error(`Insert is failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### insertSync<sup>12+</sup>

insertSync(table: string, values: ValuesBucket,  conflict?: ConflictResolution):number

向目标表中插入一行数据。由于共享内存大小限制为2Mb，因此单条数据的大小需小于2Mb，否则会查询失败。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型                                        | 必填 | 说明                                                         |
| -------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| table    | string                                      | 是   | 指定的目标表名。                                             |
| values   | [ValuesBucket](#valuesbucket)               | 是   | 表示要插入到表中的数据行。                                   |
| conflict | [ConflictResolution](#conflictresolution10) | 否   | 指定冲突解决模式。默认值是relationalStore.ConflictResolution.ON_CONFLICT_NONE。 |

**返回值**：

| 类型   | 说明                                 |
| ------ | ------------------------------------ |
| number | 如果操作成功，返回行ID；否则返回-1。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000     | Inner error.                                                 |
| 14800011     | Database corrupted.                                          |
| 14800014     | Already closed.                                              |
| 14800015     | The database does not respond.                                        |
| 14800021     | SQLite: Generic error.                                       |
| 14800022     | SQLite: Callback routine requested an abort.                 |
| 14800023     | SQLite: Access permission denied.                            |
| 14800024     | SQLite: The database file is locked.                         |
| 14800025     | SQLite: A table in the database is locked.                   |
| 14800026     | SQLite: The database is out of memory.                       |
| 14800027     | SQLite: Attempt to write a readonly database.                |
| 14800028     | SQLite: Some kind of disk I/O error occurred.                |
| 14800029     | SQLite: The database is full.                                |
| 14800030     | SQLite: Unable to open the database file.                    |
| 14800031     | SQLite: TEXT or BLOB exceeds size limit.                     |
| 14800032     | SQLite: Abort due to constraint violation.                   |
| 14800033     | SQLite: Data type mismatch.                                  |
| 14800034     | SQLite: Library used incorrectly.                            |
| 14800047     | The WAL file size exceeds the default limit.                 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let value1 = "Lisa";
let value2 = 18;
let value3 = 100.5;
let value4 = new Uint8Array([1, 2, 3, 4, 5]);

// 以下三种方式可用
const valueBucket1: relationalStore.ValuesBucket = {
  'NAME': value1,
  'AGE': value2,
  'SALARY': value3,
  'CODES': value4,
};
const valueBucket2: relationalStore.ValuesBucket = {
  NAME: value1,
  AGE: value2,
  SALARY: value3,
  CODES: value4,
};
const valueBucket3: relationalStore.ValuesBucket = {
  "NAME": value1,
  "AGE": value2,
  "SALARY": value3,
  "CODES": value4,
};

if (store != undefined) {
  try {
    let rowId: number = (store as relationalStore.RdbStore).insertSync("EMPLOYEE", valueBucket1, relationalStore.ConflictResolution.ON_CONFLICT_REPLACE);
    console.info(`Insert is successful, rowId = ${rowId}`);
  } catch (error) {
    console.error(`Insert is failed, code is ${error.code},message is ${error.message}`);
  }
}
```

### insertSync<sup>12+</sup>

insertSync(table: string, values: sendableRelationalStore.ValuesBucket, conflict?: ConflictResolution):number

传入Sendable数据，向目标表中插入一行数据。由于共享内存大小限制为2Mb，因此单条数据的大小需小于2Mb，否则会查询失败。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型                                                                                           | 必填 | 说明                                                                            |
| -------- | ---------------------------------------------------------------------------------------------- | ---- | ------------------------------------------------------------------------------- |
| table    | string                                                                                         | 是   | 指定的目标表名。                                                                |
| values   | [sendableRelationalStore.ValuesBucket](./js-apis-data-sendableRelationalStore.md#valuesbucket) | 是   | 表示要插入到表中的可跨线程传递数据。                                            |
| conflict | [ConflictResolution](#conflictresolution10)                                                    | 否   | 指定冲突解决模式。默认值是relationalStore.ConflictResolution.ON_CONFLICT_NONE。 |

**返回值**：

| 类型   | 说明                                 |
| ------ | ------------------------------------ |
| number | 如果操作成功，返回行ID；否则返回-1。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000     | Inner error.                                                 |
| 14800011     | Database corrupted.                                          |
| 14800014     | Already closed.                                              |
| 14800015     | The database does not respond.                                        |
| 14800021     | SQLite: Generic error.                                       |
| 14800022     | SQLite: Callback routine requested an abort.                 |
| 14800023     | SQLite: Access permission denied.                            |
| 14800024     | SQLite: The database file is locked.                         |
| 14800025     | SQLite: A table in the database is locked.                   |
| 14800026     | SQLite: The database is out of memory.                       |
| 14800027     | SQLite: Attempt to write a readonly database.                |
| 14800028     | SQLite: Some kind of disk I/O error occurred.                |
| 14800029     | SQLite: The database is full.                                |
| 14800030     | SQLite: Unable to open the database file.                    |
| 14800031     | SQLite: TEXT or BLOB exceeds size limit.                     |
| 14800032     | SQLite: Abort due to constraint violation.                   |
| 14800033     | SQLite: Data type mismatch.                                  |
| 14800034     | SQLite: Library used incorrectly.                            |
| 14800047     | The WAL file size exceeds the default limit.                 |

**示例：**

```ts
import { sendableRelationalStore } from '@kit.ArkData';

const valuesBucket: relationalStore.ValuesBucket = {
  "NAME": 'hangman',
  "AGE": 18,
  "SALARY": 100.5,
  "CODES": new Uint8Array([1, 2, 3]),
};
const sendableValuesBucket = sendableRelationalStore.toSendableValuesBucket(valuesBucket);

if (store != undefined) {
  try {
    let rowId: number = (store as relationalStore.RdbStore).insertSync("EMPLOYEE", sendableValuesBucket, relationalStore.ConflictResolution.ON_CONFLICT_REPLACE);
    console.info(`Insert is successful, rowId = ${rowId}`);
  } catch (error) {
    console.error(`Insert is failed, code is ${error.code},message is ${error.message}`);
  }
}
```

### batchInsert

batchInsert(table: string, values: Array&lt;ValuesBucket&gt;, callback: AsyncCallback&lt;number&gt;):void

向目标表中插入一组数据，使用callback异步回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型                                       | 必填 | 说明                                                         |
| -------- | ------------------------------------------ | ---- | ------------------------------------------------------------ |
| table    | string                                     | 是   | 指定的目标表名。                                             |
| values   | Array&lt;[ValuesBucket](#valuesbucket)&gt; | 是   | 表示要插入到表中的一组数据。             |
| callback | AsyncCallback&lt;number&gt;                | 是   | 指定callback回调函数。如果操作成功，返回插入的数据个数，否则返回-1。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |
| 14800047  | The WAL file size exceeds the default limit. |

**示例：**

```ts
let value1 = "Lisa";
let value2 = 18;
let value3 = 100.5;
let value4 = new Uint8Array([1, 2, 3, 4, 5]);
let value5 = "Jack";
let value6 = 19;
let value7 = 101.5;
let value8 = new Uint8Array([6, 7, 8, 9, 10]);
let value9 = "Tom";
let value10 = 20;
let value11 = 102.5;
let value12 = new Uint8Array([11, 12, 13, 14, 15]);

const valueBucket1: relationalStore.ValuesBucket = {
  'NAME': value1,
  'AGE': value2,
  'SALARY': value3,
  'CODES': value4,
};
const valueBucket2: relationalStore.ValuesBucket = {
  'NAME': value5,
  'AGE': value6,
  'SALARY': value7,
  'CODES': value8,
};
const valueBucket3: relationalStore.ValuesBucket = {
  'NAME': value9,
  'AGE': value10,
  'SALARY': value11,
  'CODES': value12,
};

let valueBuckets = new Array(valueBucket1, valueBucket2, valueBucket3);
if (store != undefined) {
  (store as relationalStore.RdbStore).batchInsert("EMPLOYEE", valueBuckets, (err, insertNum) => {
    if (err) {
      console.error(`batchInsert is failed, code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info(`batchInsert is successful, the number of values that were inserted = ${insertNum}`);
  })
}
```

### batchInsert

batchInsert(table: string, values: Array&lt;ValuesBucket&gt;):Promise&lt;number&gt;

向目标表中插入一组数据，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型                                       | 必填 | 说明                         |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| table  | string                                     | 是   | 指定的目标表名。             |
| values | Array&lt;[ValuesBucket](#valuesbucket)&gt; | 是   | 表示要插入到表中的一组数据。|

**返回值**：

| 类型                  | 说明                                                        |
| --------------------- | ----------------------------------------------------------- |
| Promise&lt;number&gt; | Promise对象。如果操作成功，返回插入的数据个数，否则返回-1。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |
| 14800047  | The WAL file size exceeds the default limit. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let value1 = "Lisa";
let value2 = 18;
let value3 = 100.5;
let value4 = new Uint8Array([1, 2, 3, 4, 5]);
let value5 = "Jack";
let value6 = 19;
let value7 = 101.5;
let value8 = new Uint8Array([6, 7, 8, 9, 10]);
let value9 = "Tom";
let value10 = 20;
let value11 = 102.5;
let value12 = new Uint8Array([11, 12, 13, 14, 15]);

const valueBucket1: relationalStore.ValuesBucket = {
  'NAME': value1,
  'AGE': value2,
  'SALARY': value3,
  'CODES': value4,
};
const valueBucket2: relationalStore.ValuesBucket = {
  'NAME': value5,
  'AGE': value6,
  'SALARY': value7,
  'CODES': value8,
};
const valueBucket3: relationalStore.ValuesBucket = {
  'NAME': value9,
  'AGE': value10,
  'SALARY': value11,
  'CODES': value12,
};

let valueBuckets = new Array(valueBucket1, valueBucket2, valueBucket3);
if (store != undefined) {
  (store as relationalStore.RdbStore).batchInsert("EMPLOYEE", valueBuckets).then((insertNum: number) => {
    console.info(`batchInsert is successful, the number of values that were inserted = ${insertNum}`);
  }).catch((err: BusinessError) => {
    console.error(`batchInsert is failed, code is ${err.code},message is ${err.message}`);
  })
}
```

### batchInsertSync<sup>12+</sup>

batchInsertSync(table: string, values: Array&lt;ValuesBucket&gt;):number

向目标表中插入一组数据。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型                                       | 必填 | 说明                         |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| table  | string                                     | 是   | 指定的目标表名。             |
| values | Array&lt;[ValuesBucket](#valuesbucket)&gt; | 是   | 表示要插入到表中的一组数据。 |

**返回值**：

| 类型   | 说明                                           |
| ------ | ---------------------------------------------- |
| number | 如果操作成功，返回插入的数据个数，否则返回-1。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000     | Inner error.                                                 |
| 14800011     | Database corrupted.                                          |
| 14800014     | Already closed.                                              |
| 14800015     | The database does not respond.                                        |
| 14800021     | SQLite: Generic error.                                       |
| 14800022     | SQLite: Callback routine requested an abort.                 |
| 14800023     | SQLite: Access permission denied.                            |
| 14800024     | SQLite: The database file is locked.                         |
| 14800025     | SQLite: A table in the database is locked.                   |
| 14800026     | SQLite: The database is out of memory.                       |
| 14800027     | SQLite: Attempt to write a readonly database.                |
| 14800028     | SQLite: Some kind of disk I/O error occurred.                |
| 14800029     | SQLite: The database is full.                                |
| 14800030     | SQLite: Unable to open the database file.                    |
| 14800031     | SQLite: TEXT or BLOB exceeds size limit.                     |
| 14800032     | SQLite: Abort due to constraint violation.                   |
| 14800033     | SQLite: Data type mismatch.                                  |
| 14800034     | SQLite: Library used incorrectly.                            |
| 14800047     | The WAL file size exceeds the default limit.                 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let value1 = "Lisa";
let value2 = 18;
let value3 = 100.5;
let value4 = new Uint8Array([1, 2, 3, 4, 5]);
let value5 = "Jack";
let value6 = 19;
let value7 = 101.5;
let value8 = new Uint8Array([6, 7, 8, 9, 10]);
let value9 = "Tom";
let value10 = 20;
let value11 = 102.5;
let value12 = new Uint8Array([11, 12, 13, 14, 15]);

const valueBucket1: relationalStore.ValuesBucket = {
  'NAME': value1,
  'AGE': value2,
  'SALARY': value3,
  'CODES': value4,
};
const valueBucket2: relationalStore.ValuesBucket = {
  'NAME': value5,
  'AGE': value6,
  'SALARY': value7,
  'CODES': value8,
};
const valueBucket3: relationalStore.ValuesBucket = {
  'NAME': value9,
  'AGE': value10,
  'SALARY': value11,
  'CODES': value12,
};

let valueBuckets = new Array(valueBucket1, valueBucket2, valueBucket3);
if (store != undefined) {
  try {
    let insertNum: number = (store as relationalStore.RdbStore).batchInsertSync("EMPLOYEE", valueBuckets);
    console.info(`batchInsert is successful, the number of values that were inserted = ${insertNum}`);
  } catch (err) {
    console.error(`batchInsert is failed, code is ${err.code},message is ${err.message}`);
  }
}
```

### batchInsertWithConflictResolution<sup>18+</sup>

batchInsertWithConflictResolution(table: string, values: Array&lt;ValuesBucket&gt;, conflict: ConflictResolution): Promise&lt;number&gt;

向目标表中插入一组数据，可以通过conflict参数指定冲突解决模式。使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型                                       | 必填 | 说明                         |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| table  | string                                     | 是   | 指定的目标表名。             |
| values | Array&lt;[ValuesBucket](#valuesbucket)&gt; | 是   | 表示要插入到表中的一组数据。 |
| conflict   | [ConflictResolution](#conflictresolution10) | 是   | 指定冲突解决模式。       |

**返回值**：

| 类型   | 说明                                           |
| ------ | ---------------------------------------------- |
| Promise&lt;number&gt; | Promise对象。如果操作成功，返回插入的数据个数，否则返回-1。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000     | Inner error.                                                 |
| 14800011     | Database corrupted.                                          |
| 14800014     | Already closed.                                              |
| 14800015     | The database does not respond.                                        |
| 14800021     | SQLite: Generic error.                                       |
| 14800022     | SQLite: Callback routine requested an abort.                 |
| 14800023     | SQLite: Access permission denied.                            |
| 14800024     | SQLite: The database file is locked.                         |
| 14800025     | SQLite: A table in the database is locked.                   |
| 14800026     | SQLite: The database is out of memory.                       |
| 14800027     | SQLite: Attempt to write a readonly database.                |
| 14800028     | SQLite: Some kind of disk I/O error occurred.                |
| 14800029     | SQLite: The database is full.                                |
| 14800030     | SQLite: Unable to open the database file.                    |
| 14800031     | SQLite: TEXT or BLOB exceeds size limit.                     |
| 14800032     | SQLite: Abort due to constraint violation.                   |
| 14800033     | SQLite: Data type mismatch.                                  |
| 14800034     | SQLite: Library used incorrectly.                            |
| 14800047     | The WAL file size exceeds the default limit.                 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let value1 = "Lisa";
let value2 = 18;
let value3 = 100.5;
let value4 = new Uint8Array([1, 2, 3, 4, 5]);
let value5 = "Jack";
let value6 = 19;
let value7 = 101.5;
let value8 = new Uint8Array([6, 7, 8, 9, 10]);
let value9 = "Tom";
let value10 = 20;
let value11 = 102.5;
let value12 = new Uint8Array([11, 12, 13, 14, 15]);

const valueBucket1: relationalStore.ValuesBucket = {
  'NAME': value1,
  'AGE': value2,
  'SALARY': value3,
  'CODES': value4,
};
const valueBucket2: relationalStore.ValuesBucket = {
  'NAME': value5,
  'AGE': value6,
  'SALARY': value7,
  'CODES': value8,
};
const valueBucket3: relationalStore.ValuesBucket = {
  'NAME': value9,
  'AGE': value10,
  'SALARY': value11,
  'CODES': value12,
};

let valueBuckets = new Array(valueBucket1, valueBucket2, valueBucket3);
if (store != undefined) {
  (store as relationalStore.RdbStore).batchInsertWithConflictResolution("EMPLOYEE", valueBuckets, relationalStore.ConflictResolution.ON_CONFLICT_REPLACE).then((insertNum: number) => {
    console.info(`batchInsert is successful, insertNum = ${insertNum}`);
  }).catch((err: BusinessError) => {
    console.error(`batchInsert is failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### batchInsertWithConflictResolutionSync<sup>18+</sup>

batchInsertWithConflictResolutionSync(table: string, values: Array&lt;ValuesBucket&gt;, conflict: ConflictResolution): number

向目标表中插入一组数据。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型                                       | 必填 | 说明                         |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| table  | string                                     | 是   | 指定的目标表名。             |
| values | Array&lt;[ValuesBucket](#valuesbucket)&gt; | 是   | 表示要插入到表中的一组数据。 |
| conflict   | [ConflictResolution](#conflictresolution10) | 是   | 指定冲突解决模式。       |

**返回值**：

| 类型   | 说明                                           |
| ------ | ---------------------------------------------- |
| number | 如果操作成功，返回插入的数据个数，否则返回-1。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000     | Inner error.                                                 |
| 14800011     | Database corrupted.                                          |
| 14800014     | Already closed.                                              |
| 14800015     | The database does not respond.                                        |
| 14800021     | SQLite: Generic error.                                       |
| 14800022     | SQLite: Callback routine requested an abort.                 |
| 14800023     | SQLite: Access permission denied.                            |
| 14800024     | SQLite: The database file is locked.                         |
| 14800025     | SQLite: A table in the database is locked.                   |
| 14800026     | SQLite: The database is out of memory.                       |
| 14800027     | SQLite: Attempt to write a readonly database.                |
| 14800028     | SQLite: Some kind of disk I/O error occurred.                |
| 14800029     | SQLite: The database is full.                                |
| 14800030     | SQLite: Unable to open the database file.                    |
| 14800031     | SQLite: TEXT or BLOB exceeds size limit.                     |
| 14800032     | SQLite: Abort due to constraint violation.                   |
| 14800033     | SQLite: Data type mismatch.                                  |
| 14800034     | SQLite: Library used incorrectly.                            |
| 14800047     | The WAL file size exceeds the default limit.                 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let value1 = "Lisa";
let value2 = 18;
let value3 = 100.5;
let value4 = new Uint8Array([1, 2, 3, 4, 5]);
let value5 = "Jack";
let value6 = 19;
let value7 = 101.5;
let value8 = new Uint8Array([6, 7, 8, 9, 10]);
let value9 = "Tom";
let value10 = 20;
let value11 = 102.5;
let value12 = new Uint8Array([11, 12, 13, 14, 15]);

const valueBucket1: relationalStore.ValuesBucket = {
  'NAME': value1,
  'AGE': value2,
  'SALARY': value3,
  'CODES': value4,
};
const valueBucket2: relationalStore.ValuesBucket = {
  'NAME': value5,
  'AGE': value6,
  'SALARY': value7,
  'CODES': value8,
};
const valueBucket3: relationalStore.ValuesBucket = {
  'NAME': value9,
  'AGE': value10,
  'SALARY': value11,
  'CODES': value12,
};

let valueBuckets = new Array(valueBucket1, valueBucket2, valueBucket3);
if (store != undefined) {
  try {
    let insertNum: number = (store as relationalStore.RdbStore).batchInsertWithConflictResolutionSync("EMPLOYEE", valueBuckets, relationalStore.ConflictResolution.ON_CONFLICT_REPLACE);
    console.info(`batchInsert is successful, the number of values that were inserted = ${insertNum}`);
  } catch (err) {
    console.error(`batchInsert is failed, code is ${err.code},message is ${err.message}`);
  }
}
```

### update

update(values: ValuesBucket, predicates: RdbPredicates, callback: AsyncCallback&lt;number&gt;):void

根据RdbPredicates的指定实例对象更新数据库中的数据，使用callback异步回调。由于共享内存大小限制为2Mb，因此单条数据的大小需小于2Mb，否则会查询失败。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名     | 类型                                 | 必填 | 说明                                                         |
| ---------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| values     | [ValuesBucket](#valuesbucket)        | 是   | values指示数据库中要更新的数据行。键值对与数据库表的列名相关联。 |
| predicates | [RdbPredicates](#rdbpredicates) | 是   | RdbPredicates的实例对象指定的更新条件。                    |
| callback   | AsyncCallback&lt;number&gt;          | 是   | 指定的callback回调方法。返回受影响的行数。                   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |
| 14800047  | The WAL file size exceeds the default limit. |

**示例：**

```ts
let value1 = "Rose";
let value2 = 22;
let value3 = 200.5;
let value4 = new Uint8Array([1, 2, 3, 4, 5]);

// 以下三种方式可用
const valueBucket1: relationalStore.ValuesBucket = {
  'NAME': value1,
  'AGE': value2,
  'SALARY': value3,
  'CODES': value4,
};
const valueBucket2: relationalStore.ValuesBucket = {
  NAME: value1,
  AGE: value2,
  SALARY: value3,
  CODES: value4,
};
const valueBucket3: relationalStore.ValuesBucket = {
  "NAME": value1,
  "AGE": value2,
  "SALARY": value3,
  "CODES": value4,
};

let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Lisa");
if (store != undefined) {
  (store as relationalStore.RdbStore).update(valueBucket1, predicates, (err, rows) => {
    if (err) {
      console.error(`Updated failed, code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info(`Updated row count: ${rows}`);
  });
}
```

### update<sup>10+</sup>

update(values: ValuesBucket, predicates: RdbPredicates, conflict: ConflictResolution, callback: AsyncCallback&lt;number&gt;):void

根据RdbPredicates的指定实例对象更新数据库中的数据，使用callback异步回调。由于共享内存大小限制为2Mb，因此单条数据的大小需小于2Mb，否则会查询失败。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名     | 类型                                        | 必填 | 说明                                                         |
| ---------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| values     | [ValuesBucket](#valuesbucket)               | 是   | values指示数据库中要更新的数据行。键值对与数据库表的列名相关联。 |
| predicates | [RdbPredicates](#rdbpredicates)            | 是   | RdbPredicates的实例对象指定的更新条件。                      |
| conflict   | [ConflictResolution](#conflictresolution10) | 是   | 指定冲突解决模式。                                           |
| callback   | AsyncCallback&lt;number&gt;                 | 是   | 指定的callback回调方法。返回受影响的行数。                   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |
| 14800047  | The WAL file size exceeds the default limit. |

**示例：**

```ts
let value1 = "Rose";
let value2 = 22;
let value3 = 200.5;
let value4 = new Uint8Array([1, 2, 3, 4, 5]);

// 以下三种方式可用
const valueBucket1: relationalStore.ValuesBucket = {
  'NAME': value1,
  'AGE': value2,
  'SALARY': value3,
  'CODES': value4,
};
const valueBucket2: relationalStore.ValuesBucket = {
  NAME: value1,
  AGE: value2,
  SALARY: value3,
  CODES: value4,
};
const valueBucket3: relationalStore.ValuesBucket = {
  "NAME": value1,
  "AGE": value2,
  "SALARY": value3,
  "CODES": value4,
};

let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Lisa");
if (store != undefined) {
  (store as relationalStore.RdbStore).update(valueBucket1, predicates, relationalStore.ConflictResolution.ON_CONFLICT_REPLACE, (err, rows) => {
    if (err) {
      console.error(`Updated failed, code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info(`Updated row count: ${rows}`);
  });
}
```

### update

update(values: ValuesBucket, predicates: RdbPredicates):Promise&lt;number&gt;

根据RdbPredicates的指定实例对象更新数据库中的数据，使用Promise异步回调。由于共享内存大小限制为2Mb，因此单条数据的大小需小于2Mb，否则会查询失败。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名       | 类型                                 | 必填 | 说明                                                         |
| ------------ | ------------------------------------ | ---- | ------------------------------------------------------------ |
| values       | [ValuesBucket](#valuesbucket)        | 是   | values指示数据库中要更新的数据行。键值对与数据库表的列名相关联。 |
| predicates | [RdbPredicates](#rdbpredicates) | 是   | RdbPredicates的实例对象指定的更新条件。                    |

**返回值**：

| 类型                  | 说明                                      |
| --------------------- | ----------------------------------------- |
| Promise&lt;number&gt; | 指定的Promise回调方法。返回受影响的行数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |
| 14800047  | The WAL file size exceeds the default limit. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let value1 = "Rose";
let value2 = 22;
let value3 = 200.5;
let value4 = new Uint8Array([1, 2, 3, 4, 5]);

// 以下三种方式可用
const valueBucket1: relationalStore.ValuesBucket = {
  'NAME': value1,
  'AGE': value2,
  'SALARY': value3,
  'CODES': value4,
};
const valueBucket2: relationalStore.ValuesBucket = {
  NAME: value1,
  AGE: value2,
  SALARY: value3,
  CODES: value4,
};
const valueBucket3: relationalStore.ValuesBucket = {
  "NAME": value1,
  "AGE": value2,
  "SALARY": value3,
  "CODES": value4,
};

let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Lisa");
if (store != undefined) {
  (store as relationalStore.RdbStore).update(valueBucket1, predicates).then(async (rows: Number) => {
    console.info(`Updated row count: ${rows}`);
  }).catch((err: BusinessError) => {
    console.error(`Updated failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### update<sup>10+</sup>

update(values: ValuesBucket, predicates: RdbPredicates, conflict: ConflictResolution):Promise&lt;number&gt;

根据RdbPredicates的指定实例对象更新数据库中的数据，使用Promise异步回调。由于共享内存大小限制为2Mb，因此单条数据的大小需小于2Mb，否则会查询失败。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名     | 类型                                        | 必填 | 说明                                                         |
| ---------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| values     | [ValuesBucket](#valuesbucket)               | 是   | values指示数据库中要更新的数据行。键值对与数据库表的列名相关联。 |
| predicates | [RdbPredicates](#rdbpredicates)            | 是   | RdbPredicates的实例对象指定的更新条件。                      |
| conflict   | [ConflictResolution](#conflictresolution10) | 是   | 指定冲突解决模式。                                           |

**返回值**：

| 类型                  | 说明                                      |
| --------------------- | ----------------------------------------- |
| Promise&lt;number&gt; | 指定的Promise回调方法。返回受影响的行数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |
| 14800047  | The WAL file size exceeds the default limit. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let value1 = "Rose";
let value2 = 22;
let value3 = 200.5;
let value4 = new Uint8Array([1, 2, 3, 4, 5]);

// 以下三种方式可用
const valueBucket1: relationalStore.ValuesBucket = {
  'NAME': value1,
  'AGE': value2,
  'SALARY': value3,
  'CODES': value4,
};
const valueBucket2: relationalStore.ValuesBucket = {
  NAME: value1,
  AGE: value2,
  SALARY: value3,
  CODES: value4,
};
const valueBucket3: relationalStore.ValuesBucket = {
  "NAME": value1,
  "AGE": value2,
  "SALARY": value3,
  "CODES": value4,
};

let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Lisa");
if (store != undefined) {
  (store as relationalStore.RdbStore).update(valueBucket1, predicates, relationalStore.ConflictResolution.ON_CONFLICT_REPLACE).then(async (rows: Number) => {
    console.info(`Updated row count: ${rows}`);
  }).catch((err: BusinessError) => {
    console.error(`Updated failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### updateSync<sup>12+</sup>

updateSync(values: ValuesBucket, predicates: RdbPredicates, conflict?: ConflictResolution):number

根据RdbPredicates的指定实例对象更新数据库中的数据。由于共享内存大小限制为2Mb，因此单条数据的大小需小于2Mb，否则会查询失败。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名     | 类型                                        | 必填 | 说明                                                         |
| ---------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| values     | [ValuesBucket](#valuesbucket)               | 是   | values指示数据库中要更新的数据行。键值对与数据库表的列名相关联。 |
| predicates | [RdbPredicates](#rdbpredicates)             | 是   | RdbPredicates的实例对象指定的更新条件。                      |
| conflict   | [ConflictResolution](#conflictresolution10) | 否   | 指定冲突解决模式。默认值是relationalStore.ConflictResolution.ON_CONFLICT_NONE。 |

**返回值**：

| 类型   | 说明               |
| ------ | ------------------ |
| number | 返回受影响的行数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000     | Inner error.                                                 |
| 14800011     | Database corrupted.                                          |
| 14800014     | Already closed.                                              |
| 14800015     | The database does not respond.                                        |
| 14800021     | SQLite: Generic error.                                       |
| 14800022     | SQLite: Callback routine requested an abort.                 |
| 14800023     | SQLite: Access permission denied.                            |
| 14800024     | SQLite: The database file is locked.                         |
| 14800025     | SQLite: A table in the database is locked.                   |
| 14800026     | SQLite: The database is out of memory.                       |
| 14800027     | SQLite: Attempt to write a readonly database.                |
| 14800028     | SQLite: Some kind of disk I/O error occurred.                |
| 14800029     | SQLite: The database is full.                                |
| 14800030     | SQLite: Unable to open the database file.                    |
| 14800031     | SQLite: TEXT or BLOB exceeds size limit.                     |
| 14800032     | SQLite: Abort due to constraint violation.                   |
| 14800033     | SQLite: Data type mismatch.                                  |
| 14800034     | SQLite: Library used incorrectly.                            |
| 14800047     | The WAL file size exceeds the default limit.                 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let value1 = "Rose";
let value2 = 22;
let value3 = 200.5;
let value4 = new Uint8Array([1, 2, 3, 4, 5]);

// 以下三种方式可用
const valueBucket1: relationalStore.ValuesBucket = {
  'NAME': value1,
  'AGE': value2,
  'SALARY': value3,
  'CODES': value4,
};
const valueBucket2: relationalStore.ValuesBucket = {
  NAME: value1,
  AGE: value2,
  SALARY: value3,
  CODES: value4,
};
const valueBucket3: relationalStore.ValuesBucket = {
  "NAME": value1,
  "AGE": value2,
  "SALARY": value3,
  "CODES": value4,
};

let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Lisa");
if (store != undefined) {
  try {
    let rows: Number = (store as relationalStore.RdbStore).updateSync(valueBucket1, predicates, relationalStore.ConflictResolution.ON_CONFLICT_REPLACE);
    console.info(`Updated row count: ${rows}`);
  } catch (error) {
    console.error(`Updated failed, code is ${error.code},message is ${error.message}`);
  }
}
```

### delete

delete(predicates: RdbPredicates, callback: AsyncCallback&lt;number&gt;):void

根据RdbPredicates的指定实例对象从数据库中删除数据，使用callback异步回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名     | 类型                                 | 必填 | 说明                                      |
| ---------- | ------------------------------------ | ---- | ----------------------------------------- |
| predicates | [RdbPredicates](#rdbpredicates) | 是   | RdbPredicates的实例对象指定的删除条件。 |
| callback   | AsyncCallback&lt;number&gt;          | 是   | 指定callback回调函数。返回受影响的行数量。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |
| 14800047  | The WAL file size exceeds the default limit. |

**示例：**

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Lisa");
if (store != undefined) {
  (store as relationalStore.RdbStore).delete(predicates, (err, rows) => {
    if (err) {
      console.error(`Delete failed, code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info(`Delete rows: ${rows}`);
  });
}
```

### delete

delete(predicates: RdbPredicates):Promise&lt;number&gt;

根据RdbPredicates的指定实例对象从数据库中删除数据，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名     | 类型                                 | 必填 | 说明                                      |
| ---------- | ------------------------------------ | ---- | ----------------------------------------- |
| predicates | [RdbPredicates](#rdbpredicates) | 是   | RdbPredicates的实例对象指定的删除条件。 |

**返回值**：

| 类型                  | 说明                            |
| --------------------- | ------------------------------- |
| Promise&lt;number&gt; | Promise对象。返回受影响的行数量。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |
| 14800047  | The WAL file size exceeds the default limit. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Lisa");
if (store != undefined) {
  (store as relationalStore.RdbStore).delete(predicates).then((rows: Number) => {
    console.info(`Delete rows: ${rows}`);
  }).catch((err: BusinessError) => {
    console.error(`Delete failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### deleteSync<sup>12+</sup>

deleteSync(predicates: RdbPredicates):number

根据RdbPredicates的指定实例对象从数据库中删除数据。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名     | 类型                            | 必填 | 说明                                    |
| ---------- | ------------------------------- | ---- | --------------------------------------- |
| predicates | [RdbPredicates](#rdbpredicates) | 是   | RdbPredicates的实例对象指定的删除条件。 |

**返回值**：

| 类型   | 说明               |
| ------ | ------------------ |
| number | 返回受影响的行数量。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000     | Inner error.                                                 |
| 14800011     | Database corrupted.                                          |
| 14800014     | Already closed.                                              |
| 14800015     | The database does not respond.                                        |
| 14800021     | SQLite: Generic error.                                       |
| 14800022     | SQLite: Callback routine requested an abort.                 |
| 14800023     | SQLite: Access permission denied.                            |
| 14800024     | SQLite: The database file is locked.                         |
| 14800025     | SQLite: A table in the database is locked.                   |
| 14800026     | SQLite: The database is out of memory.                       |
| 14800027     | SQLite: Attempt to write a readonly database.                |
| 14800028     | SQLite: Some kind of disk I/O error occurred.                |
| 14800029     | SQLite: The database is full.                                |
| 14800030     | SQLite: Unable to open the database file.                    |
| 14800031     | SQLite: TEXT or BLOB exceeds size limit.                     |
| 14800032     | SQLite: Abort due to constraint violation.                   |
| 14800033     | SQLite: Data type mismatch.                                  |
| 14800034     | SQLite: Library used incorrectly.                            |
| 14800047     | The WAL file size exceeds the default limit.                 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Lisa");
if (store != undefined) {
  try {
    let rows: Number = (store as relationalStore.RdbStore).deleteSync(predicates);
    console.info(`Delete rows: ${rows}`);
  } catch (err) {
    console.error(`Delete failed, code is ${err.code},message is ${err.message}`);
  }
}
```

### query<sup>10+</sup>

query(predicates: RdbPredicates, callback: AsyncCallback&lt;ResultSet&gt;):void

根据指定条件查询数据库中的数据，使用callback异步回调。由于共享内存大小限制为2Mb，因此单条数据的大小需小于2Mb，否则会查询失败。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                                                        |
| ---------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------------- |
| predicates | [RdbPredicates](#rdbpredicates)                         | 是   | RdbPredicates的实例对象指定的查询条件。                   |
| callback   | AsyncCallback&lt;[ResultSet](#resultset)&gt; | 是   | 指定callback回调函数。如果操作成功，则返回ResultSet对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |

**示例：**

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Rose");
if (store != undefined) {
  (store as relationalStore.RdbStore).query(predicates, (err, resultSet) => {
    if (err) {
      console.error(`Query failed, code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info(`ResultSet column names: ${resultSet.columnNames}, column count: ${resultSet.columnCount}`);
    // resultSet是一个数据集合的游标，默认指向第-1个记录，有效的数据从0开始。
    while (resultSet.goToNextRow()) {
      const id = resultSet.getLong(resultSet.getColumnIndex("ID"));
      const name = resultSet.getString(resultSet.getColumnIndex("NAME"));
      const age = resultSet.getLong(resultSet.getColumnIndex("AGE"));
      const salary = resultSet.getDouble(resultSet.getColumnIndex("SALARY"));
      console.info(`id=${id}, name=${name}, age=${age}, salary=${salary}`);
    }
    // 释放数据集的内存，若不释放可能会引起fd泄露与内存泄露
    resultSet.close();
  });
}
```

### query

query(predicates: RdbPredicates, columns: Array&lt;string&gt;, callback: AsyncCallback&lt;ResultSet&gt;):void

根据指定条件查询数据库中的数据，使用callback异步回调。由于共享内存大小限制为2Mb，因此单条数据的大小需小于2Mb，否则会查询失败。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                                                        |
| ---------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------------- |
| predicates | [RdbPredicates](#rdbpredicates)                         | 是   | RdbPredicates的实例对象指定的查询条件。                   |
| columns    | Array&lt;string&gt;                                          | 是   | 表示要查询的列。如果值为空，则查询应用于所有列。            |
| callback   | AsyncCallback&lt;[ResultSet](#resultset)&gt; | 是   | 指定callback回调函数。如果操作成功，则返回ResultSet对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |

**示例：**

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Rose");
if (store != undefined) {
  (store as relationalStore.RdbStore).query(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"], (err, resultSet) => {
    if (err) {
      console.error(`Query failed, code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info(`ResultSet column names: ${resultSet.columnNames}, column count: ${resultSet.columnCount}`);
    // resultSet是一个数据集合的游标，默认指向第-1个记录，有效的数据从0开始。
    while (resultSet.goToNextRow()) {
      const id = resultSet.getLong(resultSet.getColumnIndex("ID"));
      const name = resultSet.getString(resultSet.getColumnIndex("NAME"));
      const age = resultSet.getLong(resultSet.getColumnIndex("AGE"));
      const salary = resultSet.getDouble(resultSet.getColumnIndex("SALARY"));
      console.info(`id=${id}, name=${name}, age=${age}, salary=${salary}`);
    }
    // 释放数据集的内存，若不释放可能会引起fd泄露与内存泄露
    resultSet.close();
  });
}
```

### query

query(predicates: RdbPredicates, columns?: Array&lt;string&gt;):Promise&lt;ResultSet&gt;

根据指定条件查询数据库中的数据，使用Promise异步回调。由于共享内存大小限制为2Mb，因此单条数据的大小需小于2Mb，否则会查询失败。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名     | 类型                                 | 必填 | 说明                                             |
| ---------- | ------------------------------------ | ---- | ------------------------------------------------ |
| predicates | [RdbPredicates](#rdbpredicates) | 是   | RdbPredicates的实例对象指定的查询条件。        |
| columns    | Array&lt;string&gt;                  | 否   | 表示要查询的列。如果值为空，则查询应用于所有列。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |

**返回值**：

| 类型                                                    | 说明                                               |
| ------------------------------------------------------- | -------------------------------------------------- |
| Promise&lt;[ResultSet](#resultset)&gt; | Promise对象。如果操作成功，则返回ResultSet对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Rose");
if (store != undefined) {
  (store as relationalStore.RdbStore).query(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"]).then((resultSet: relationalStore.ResultSet) => {
    console.info(`ResultSet column names: ${resultSet.columnNames}, column count: ${resultSet.columnCount}`);
    // resultSet是一个数据集合的游标，默认指向第-1个记录，有效的数据从0开始。
    while (resultSet.goToNextRow()) {
      const id = resultSet.getLong(resultSet.getColumnIndex("ID"));
      const name = resultSet.getString(resultSet.getColumnIndex("NAME"));
      const age = resultSet.getLong(resultSet.getColumnIndex("AGE"));
      const salary = resultSet.getDouble(resultSet.getColumnIndex("SALARY"));
      console.info(`id=${id}, name=${name}, age=${age}, salary=${salary}`);
    }
    // 释放数据集的内存，若不释放可能会引起fd泄露与内存泄露
    resultSet.close();
  }).catch((err: BusinessError) => {
    console.error(`Query failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### querySync<sup>12+</sup>

querySync(predicates: RdbPredicates, columns?: Array&lt;string&gt;):ResultSet

根据指定条件查询数据库中的数据。对query同步接口获得的resultSet进行操作时，若逻辑复杂且循环次数过多，可能造成freeze问题，建议将此步骤放到[taskpool](../apis-arkts/js-apis-taskpool.md)线程中执行。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名     | 类型                            | 必填 | 说明                                                         |
| ---------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| predicates | [RdbPredicates](#rdbpredicates) | 是   | RdbPredicates的实例对象指定的查询条件。                      |
| columns    | Array&lt;string&gt;             | 否   | 表示要查询的列。如果值为空，则查询应用于所有列。默认值为空。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000     | Inner error.                                                 |
| 14800014     | Already closed.                                              |
| 14800015     | The database does not respond.                                        |

**返回值**：

| 类型                    | 说明                                |
| ----------------------- | ----------------------------------- |
| [ResultSet](#resultset) | 如果操作成功，则返回ResultSet对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Rose");
if (store != undefined) {
  try {
    let resultSet: relationalStore.ResultSet = (store as relationalStore.RdbStore).querySync(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"]);
    console.info(`ResultSet column names: ${resultSet.columnNames}, column count: ${resultSet.columnCount}`);
    // resultSet是一个数据集合的游标，默认指向第-1个记录，有效的数据从0开始。
    while (resultSet.goToNextRow()) {
      const id = resultSet.getLong(resultSet.getColumnIndex("ID"));
      const name = resultSet.getString(resultSet.getColumnIndex("NAME"));
      const age = resultSet.getLong(resultSet.getColumnIndex("AGE"));
      const salary = resultSet.getDouble(resultSet.getColumnIndex("SALARY"));
      console.info(`id=${id}, name=${name}, age=${age}, salary=${salary}`);
    }
    // 释放数据集的内存，若不释放可能会引起fd泄露与内存泄露
    resultSet.close();
  } catch (err) {
    console.error(`Query failed, code is ${err.code},message is ${err.message}`);
  }
}
```

### remoteQuery

remoteQuery(device: string, table: string, predicates: RdbPredicates, columns: Array&lt;string&gt; , callback: AsyncCallback&lt;ResultSet&gt;): void

根据指定条件查询远程设备数据库中的数据。使用callback异步回调。

> **说明：**
>
> 其中device通过调用[deviceManager.getAvailableDeviceListSync](../apis-distributedservice-kit/js-apis-distributedDeviceManager.md#getavailabledevicelistsync)方法得到。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名     | 类型                                         | 必填 | 说明                                                      |
| ---------- | -------------------------------------------- | ---- | --------------------------------------------------------- |
| device     | string                                       | 是   | 指定的远程设备ID。                                        |
| table      | string                                       | 是   | 指定的目标表名。                                          |
| predicates | [RdbPredicates](#rdbpredicates)              | 是   | RdbPredicates的实例对象，指定查询的条件。                 |
| columns    | Array&lt;string&gt;                          | 是   | 表示要查询的列。如果值为空，则查询应用于所有列。          |
| callback   | AsyncCallback&lt;[ResultSet](#resultset)&gt; | 是   | 指定callback回调函数。如果操作成功，则返回ResultSet对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported. |
| 14800000  | Inner error. |
| 14800014  | Already closed. |

**示例：**

```ts
import { distributedDeviceManager } from '@kit.DistributedServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

let dmInstance: distributedDeviceManager.DeviceManager;
let deviceId: string | undefined = undefined;

try {
  dmInstance = distributedDeviceManager.createDeviceManager("com.example.appdatamgrverify");
  let devices = dmInstance.getAvailableDeviceListSync();
  if (deviceId != undefined) {
    deviceId = devices[0].networkId;
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error("createDeviceManager errCode:" + code + ",errMessage:" + message);
}

let predicates = new relationalStore.RdbPredicates('EMPLOYEE');
predicates.greaterThan("id", 0);
if (store != undefined && deviceId != undefined) {
  (store as relationalStore.RdbStore).remoteQuery(deviceId, "EMPLOYEE", predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"]).then((resultSet: relationalStore.ResultSet) => {
    console.info(`ResultSet column names: ${resultSet.columnNames}, column count: ${resultSet.columnCount}`);
    // resultSet是一个数据集合的游标，默认指向第-1个记录，有效的数据从0开始。
    while (resultSet.goToNextRow()) {
      const id = resultSet.getLong(resultSet.getColumnIndex("ID"));
      const name = resultSet.getString(resultSet.getColumnIndex("NAME"));
      const age = resultSet.getLong(resultSet.getColumnIndex("AGE"));
      const salary = resultSet.getDouble(resultSet.getColumnIndex("SALARY"));
      console.info(`id=${id}, name=${name}, age=${age}, salary=${salary}`);
    }
    // 释放数据集的内存，若不释放可能会引起fd泄露与内存泄露
    resultSet.close();
  }).catch((err: BusinessError) => {
    console.error(`Failed to remoteQuery, code is ${err.code},message is ${err.message}`);
  });
}
```

### remoteQuery

remoteQuery(device: string, table: string, predicates: RdbPredicates, columns: Array&lt;string&gt;): Promise&lt;ResultSet&gt;

根据指定条件查询远程设备数据库中的数据。使用Promise异步回调。

> **说明：**
>
> 其中device通过调用[deviceManager.getAvailableDeviceListSync](../apis-distributedservice-kit/js-apis-distributedDeviceManager.md#getavailabledevicelistsync)方法得到。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名     | 类型                                 | 必填 | 说明                                             |
| ---------- | ------------------------------------ | ---- | ------------------------------------------------ |
| device     | string                               | 是   | 指定的远程设备ID。                   |
| table      | string                               | 是   | 指定的目标表名。                                 |
| predicates | [RdbPredicates](#rdbpredicates) | 是   | RdbPredicates的实例对象，指定查询的条件。      |
| columns    | Array&lt;string&gt;                  | 是   | 表示要查询的列。如果值为空，则查询应用于所有列。 |

**返回值**：

| 类型                                                         | 说明                                               |
| ------------------------------------------------------------ | -------------------------------------------------- |
| Promise&lt;[ResultSet](#resultset)&gt; | Promise对象。如果操作成功，则返回ResultSet对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported. |
| 14800000  | Inner error. |
| 14800014  | Already closed. |

**示例：**

```ts
import { distributedDeviceManager } from '@kit.DistributedServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

let dmInstance: distributedDeviceManager.DeviceManager;
let deviceId: string | undefined = undefined;

try {
  dmInstance = distributedDeviceManager.createDeviceManager("com.example.appdatamgrverify");
  let devices: Array<distributedDeviceManager.DeviceBasicInfo> = dmInstance.getAvailableDeviceListSync();
  if (devices != undefined) {
    deviceId = devices[0].networkId;
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error("createDeviceManager errCode:" + code + ",errMessage:" + message);
}

let predicates = new relationalStore.RdbPredicates('EMPLOYEE');
predicates.greaterThan("id", 0);
if (store != undefined && deviceId != undefined) {
  (store as relationalStore.RdbStore).remoteQuery(deviceId, "EMPLOYEE", predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"]).then((resultSet: relationalStore.ResultSet) => {
    console.info(`ResultSet column names: ${resultSet.columnNames}, column count: ${resultSet.columnCount}`);
    // resultSet是一个数据集合的游标，默认指向第-1个记录，有效的数据从0开始。
    while (resultSet.goToNextRow()) {
      const id = resultSet.getLong(resultSet.getColumnIndex("ID"));
      const name = resultSet.getString(resultSet.getColumnIndex("NAME"));
      const age = resultSet.getLong(resultSet.getColumnIndex("AGE"));
      const salary = resultSet.getDouble(resultSet.getColumnIndex("SALARY"));
      console.info(`id=${id}, name=${name}, age=${age}, salary=${salary}`);
    }
    // 释放数据集的内存，若不释放可能会引起fd泄露与内存泄露
    resultSet.close();
  }).catch((err: BusinessError) => {
    console.error(`Failed to remoteQuery, code is ${err.code},message is ${err.message}`);
  });
}
```

### querySql<sup>10+</sup>

querySql(sql: string, callback: AsyncCallback&lt;ResultSet&gt;):void

根据指定SQL语句查询数据库中的数据，语句中的各种表达式和操作符之间的关系操作符号不超过1000个，使用callback异步回调。

[向量数据库](#storeconfig)当前支持的标准语法有where、limit、offset、order by、group by以及having；扩展语法有<->（计算相似度）和<=>（计算余弦距离），支持在聚合函数（max、min）中使用，不支持在聚合函数（sum、avg、count）和基础函数（random、abs、upper、lower、length）中使用。

聚合函数不支持嵌套使用。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型                                         | 必填 | 说明                                    |
| -------- | -------------------------------------------- | ---- |---------------------------------------|
| sql      | string                                       | 是   | 指定要执行的SQL语句。                          |
| callback | AsyncCallback&lt;[ResultSet](#resultset)&gt; | 是   | 指定callback回调函数。如果操作成功，则返回ResultSet对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |

**示例：**

关系型数据库：

```ts
if (store != undefined) {
  (store as relationalStore.RdbStore).querySql("SELECT * FROM EMPLOYEE CROSS JOIN BOOK WHERE BOOK.NAME = 'sanguo'", (err, resultSet) => {
    if (err) {
      console.error(`Query failed, code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info(`ResultSet column names: ${resultSet.columnNames}, column count: ${resultSet.columnCount}`);
    // resultSet是一个数据集合的游标，默认指向第-1个记录，有效的数据从0开始。
    while (resultSet.goToNextRow()) {
      const id = resultSet.getLong(resultSet.getColumnIndex("ID"));
      const name = resultSet.getString(resultSet.getColumnIndex("NAME"));
      const age = resultSet.getLong(resultSet.getColumnIndex("AGE"));
      const salary = resultSet.getDouble(resultSet.getColumnIndex("SALARY"));
      console.info(`id=${id}, name=${name}, age=${age}, salary=${salary}`);
    }
    // 释放数据集的内存，若不释放可能会引起fd泄露与内存泄露
    resultSet.close();
  });
}
```

向量数据库：

```ts
// 相似度的计算符号是<->，余弦距离的计算符号是<=>
const querySql = "select id, repr <-> '[1.5,5.6]' as distance from test ORDER BY repr <-> '[1.5,5.6]' limit 10 offset 1;";
let resultSet = await store.querySql(querySql);

// 聚合查询，其中group by支持多列
const querySql1 = "select id, repr from test group by id, repr having max(repr<=>[1.5,5.6]);";
let resultSet1 = await store.querySql(querySql1);

// 子查询，最大支持嵌套32层
const querySql2 = "select * from test where id in (select id from test1)";
let resultSet2 = await store.querySql(querySql2);
```

### querySql

querySql(sql: string, bindArgs: Array&lt;ValueType&gt;, callback: AsyncCallback&lt;ResultSet&gt;):void

根据指定SQL语句查询数据库中的数据，语句中的各种表达式和操作符之间的关系操作符号不超过1000个，使用callback异步回调。

[向量数据库](#storeconfig)当前支持的标准语法有where、limit、offset、order by、group by以及having；扩展语法有<->（计算相似度）和<=>（计算余弦距离），支持在聚合函数（max、min）中使用，不支持在聚合函数（sum、avg、count）和基础函数（random、abs、upper、lower、length）中使用。

聚合函数不支持嵌套使用。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型                                         | 必填 | 说明                                                         |
| -------- | -------------------------------------------- | ---- | ------------------------------------------------------------ |
| sql      | string                                       | 是   | 指定要执行的SQL语句。                                        |
| bindArgs | Array&lt;[ValueType](#valuetype)&gt;         | 是   | SQL语句中参数的值。该值与sql参数语句中的占位符相对应。当sql参数语句完整时，该参数需为空数组。 |
| callback | AsyncCallback&lt;[ResultSet](#resultset)&gt; | 是   | 指定callback回调函数。如果操作成功，则返回ResultSet对象。    |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |

**示例：**

```ts
if (store != undefined) {
  (store as relationalStore.RdbStore).querySql("SELECT * FROM EMPLOYEE CROSS JOIN BOOK WHERE BOOK.NAME = ?", ['sanguo'], (err, resultSet) => {
    if (err) {
      console.error(`Query failed, code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info(`ResultSet column names: ${resultSet.columnNames}, column count: ${resultSet.columnCount}`);
    // resultSet是一个数据集合的游标，默认指向第-1个记录，有效的数据从0开始。
    while (resultSet.goToNextRow()) {
      const id = resultSet.getLong(resultSet.getColumnIndex("ID"));
      const name = resultSet.getString(resultSet.getColumnIndex("NAME"));
      const age = resultSet.getLong(resultSet.getColumnIndex("AGE"));
      const salary = resultSet.getDouble(resultSet.getColumnIndex("SALARY"));
      console.info(`id=${id}, name=${name}, age=${age}, salary=${salary}`);
    }
    // 释放数据集的内存，若不释放可能会引起fd泄露与内存泄露
    resultSet.close();
  });
}
```

### querySql

querySql(sql: string, bindArgs?: Array&lt;ValueType&gt;):Promise&lt;ResultSet&gt;

根据指定SQL语句查询数据库中的数据，语句中的各种表达式和操作符之间的关系操作符号不超过1000个，使用Promise异步回调。

[向量数据库](#storeconfig)当前支持的标准语法有where、limit、offset、order by、group by以及having；扩展语法有<->（计算相似度）和<=>（计算余弦距离），支持在聚合函数（max、min）中使用，不支持在聚合函数（sum、avg、count）和基础函数（random、abs、upper、lower、length）中使用。

聚合函数不支持嵌套使用。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型                                 | 必填 | 说明                                                         |
| -------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| sql      | string                               | 是   | 指定要执行的SQL语句。                                        |
| bindArgs | Array&lt;[ValueType](#valuetype)&gt; | 否   | SQL语句中参数的值。该值与sql参数语句中的占位符相对应。当sql参数语句完整时，该参数不填。 |

**返回值**：

| 类型                                                    | 说明                                               |
| ------------------------------------------------------- | -------------------------------------------------- |
| Promise&lt;[ResultSet](#resultset)&gt; | Promise对象。如果操作成功，则返回ResultSet对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |

**示例：**

关系型数据库：

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if (store != undefined) {
  (store as relationalStore.RdbStore).querySql("SELECT * FROM EMPLOYEE CROSS JOIN BOOK WHERE BOOK.NAME = 'sanguo'").then((resultSet: relationalStore.ResultSet) => {
    console.info(`ResultSet column names: ${resultSet.columnNames}, column count: ${resultSet.columnCount}`);
    // resultSet是一个数据集合的游标，默认指向第-1个记录，有效的数据从0开始。
    while (resultSet.goToNextRow()) {
      const id = resultSet.getLong(resultSet.getColumnIndex("ID"));
      const name = resultSet.getString(resultSet.getColumnIndex("NAME"));
      const age = resultSet.getLong(resultSet.getColumnIndex("AGE"));
      const salary = resultSet.getDouble(resultSet.getColumnIndex("SALARY"));
      console.info(`id=${id}, name=${name}, age=${age}, salary=${salary}`);
    }
    // 释放数据集的内存，若不释放可能会引起fd泄露与内存泄露
    resultSet.close();
  }).catch((err: BusinessError) => {
    console.error(`Query failed, code is ${err.code},message is ${err.message}`);
  });
}
```

向量数据库：

```ts
// 查询id为1，与[1.5, 2.5]相似度小于0.5，且以相似度进行升序排序的前10条数据
const querySql = "select id, repr <-> ? as distance from test where id = ? and repr <-> ? < 0.5 ORDER BY repr <-> ? limit 10;";
const vectorValue: Float32Array = new Float32Array([1.5, 2.5]);
let resultSet = await store.querySql(querySql, [vectorValue, 1, vectorValue, vectorValue]); 
```

### querySqlSync<sup>12+</sup>

querySqlSync(sql: string, bindArgs?: Array&lt;ValueType&gt;):ResultSet

根据指定SQL语句查询数据库中的数据，语句中的各种表达式和操作符之间的关系操作符号不超过1000个。对query同步接口获得的resultSet进行操作时，若逻辑复杂且循环次数过多，可能造成freeze问题，建议将此步骤放到[taskpool](../apis-arkts/js-apis-taskpool.md)线程中执行。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型                                 | 必填 | 说明                                                         |
| -------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| sql      | string                               | 是   | 指定要执行的SQL语句。                                        |
| bindArgs | Array&lt;[ValueType](#valuetype)&gt; | 否   | SQL语句中参数的值。该值与sql参数语句中的占位符相对应。当sql参数语句完整时，该参数不填。默认值为空。 |

**返回值**：

| 类型                    | 说明                                |
| ----------------------- | ----------------------------------- |
| [ResultSet](#resultset) | 如果操作成功，则返回ResultSet对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000     | Inner error.                                                 |
| 14800014     | Already closed.                                              |
| 14800015     | The database does not respond.                                        |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if (store != undefined) {
  try {
    let resultSet: relationalStore.ResultSet = (store as relationalStore.RdbStore).querySqlSync("SELECT * FROM EMPLOYEE CROSS JOIN BOOK WHERE BOOK.NAME = 'sanguo'");
    console.info(`ResultSet column names: ${resultSet.columnNames}, column count: ${resultSet.columnCount}`);
    // resultSet是一个数据集合的游标，默认指向第-1个记录，有效的数据从0开始。
    while (resultSet.goToNextRow()) {
      const id = resultSet.getLong(resultSet.getColumnIndex("ID"));
      const name = resultSet.getString(resultSet.getColumnIndex("NAME"));
      const age = resultSet.getLong(resultSet.getColumnIndex("AGE"));
      const salary = resultSet.getDouble(resultSet.getColumnIndex("SALARY"));
      console.info(`id=${id}, name=${name}, age=${age}, salary=${salary}`);
    }
    // 释放数据集的内存，若不释放可能会引起fd泄露与内存泄露
    resultSet.close();
  } catch (err) {
    console.error(`Query failed, code is ${err.code},message is ${err.message}`);
  }
}
```

### executeSql<sup>10+</sup>

executeSql(sql: string, callback: AsyncCallback&lt;void&gt;):void

执行包含指定参数但不返回值的SQL语句，语句中的各种表达式和操作符之间的关系操作符号不超过1000个，使用callback异步回调。

此接口不支持执行查询、附加数据库和事务操作，可以使用[querySql](#querysql10)、[query](#query10)、[attach](#attach12)、[beginTransaction](#begintransaction)、[commit](#commit)等接口代替。

不支持分号分隔的多条语句。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型                                 | 必填 | 说明                                                         |
| -------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| sql      | string                               | 是   | 指定要执行的SQL语句。                                        |
| callback | AsyncCallback&lt;void&gt;            | 是   | 指定callback回调函数。                                       |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported the sql(attach,begin,commit,rollback etc.). |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |
| 14800047  | The WAL file size exceeds the default limit. |

**示例：**

```ts
const SQL_DELETE_TABLE = "DELETE FROM test WHERE name = 'zhangsan'";
if (store != undefined) {
  (store as relationalStore.RdbStore).executeSql(SQL_DELETE_TABLE, (err) => {
    if (err) {
      console.error(`ExecuteSql failed, code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info('Delete table done.');
  });
}
```

### executeSql

executeSql(sql: string, bindArgs: Array&lt;ValueType&gt;, callback: AsyncCallback&lt;void&gt;):void

执行包含指定参数但不返回值的SQL语句，语句中的各种表达式和操作符之间的关系操作符号不超过1000个，使用callback异步回调。

此接口不支持执行查询、附加数据库和事务操作，可以使用[querySql](#querysql10)、[query](#query10)、[attach](#attach12)、[beginTransaction](#begintransaction)、[commit](#commit)等接口代替。

不支持分号分隔的多条语句。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型                                 | 必填 | 说明                                                         |
| -------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| sql      | string                               | 是   | 指定要执行的SQL语句。                                        |
| bindArgs | Array&lt;[ValueType](#valuetype)&gt; | 是   | SQL语句中参数的值。该值与sql参数语句中的占位符相对应。当sql参数语句完整时，该参数需为空数组。 |
| callback | AsyncCallback&lt;void&gt;            | 是   | 指定callback回调函数。                                       |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported the sql(attach,begin,commit,rollback etc.). |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |
| 14800047  | The WAL file size exceeds the default limit. |

**示例：**

```ts
const SQL_DELETE_TABLE = "DELETE FROM test WHERE name = ?";
if (store != undefined) {
  (store as relationalStore.RdbStore).executeSql(SQL_DELETE_TABLE, ['zhangsan'], (err) => {
    if (err) {
      console.error(`ExecuteSql failed, code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info('Delete table done.');
  });
}
```

### executeSql

executeSql(sql: string, bindArgs?: Array&lt;ValueType&gt;):Promise&lt;void&gt;

执行包含指定参数但不返回值的SQL语句，语句中的各种表达式和操作符之间的关系操作符号不超过1000个，使用Promise异步回调。

此接口不支持执行查询、附加数据库和事务操作，可以使用[querySql](#querysql10)、[query](#query10)、[attach](#attach12)、[beginTransaction](#begintransaction)、[commit](#commit)等接口代替。

不支持分号分隔的多条语句。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型                                 | 必填 | 说明                                                         |
| -------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| sql      | string                               | 是   | 指定要执行的SQL语句。                                        |
| bindArgs | Array&lt;[ValueType](#valuetype)&gt; | 否   | SQL语句中参数的值。该值与sql参数语句中的占位符相对应。当sql参数语句完整时，该参数不填。 |

**返回值**：

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported the sql(attach,begin,commit,rollback etc.). |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |
| 14800047  | The WAL file size exceeds the default limit. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const SQL_DELETE_TABLE = "DELETE FROM test WHERE name = 'zhangsan'";
if (store != undefined) {
  (store as relationalStore.RdbStore).executeSql(SQL_DELETE_TABLE).then(() => {
    console.info('Delete table done.');
  }).catch((err: BusinessError) => {
    console.error(`ExecuteSql failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### execute<sup>12+</sup>

execute(sql: string, args?: Array&lt;ValueType&gt;):Promise&lt;ValueType&gt;

执行包含指定参数的SQL语句，语句中的各种表达式和操作符之间的关系操作符号不超过1000个，返回值类型为ValueType，使用Promise异步回调。

该接口支持执行增删改操作，支持执行PRAGMA语法的sql，支持对表的操作（建表、删表、修改表），返回结果类型由执行具体sql的结果决定。

此接口不支持执行查询、附加数据库和事务操作，可以使用[querySql](#querysql10)、[query](#query10)、[attach](#attach12)、[beginTransaction](#begintransaction)、[commit](#commit)等接口代替。

向量数据库使用该接口执行插入操作，数据来源于子查询时，支持全字段插入，暂不支持部分字段插入。

不支持分号分隔的多条语句。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型                                 | 必填 | 说明                                                         |
| -------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| sql      | string                               | 是   | 指定要执行的SQL语句。                                        |
| args | Array&lt;[ValueType](#valuetype)&gt; | 否   | SQL语句中参数的值。该值与sql参数语句中的占位符相对应。当sql参数语句完整时，该参数不填。 |

**返回值**：

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;[ValueType](#valuetype)&gt; | Promise对象，返回sql执行后的结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported the sql(attach,begin,commit,rollback etc.). |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |
| 14800047  | The WAL file size exceeds the default limit. |

**示例：**

关系型数据库：

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 校验数据库完整性
if (store != undefined) {
  const SQL_CHECK_INTEGRITY = 'PRAGMA integrity_check';
  (store as relationalStore.RdbStore).execute(SQL_CHECK_INTEGRITY).then((data) => {
    console.info(`check result: ${data}`);
  }).catch((err: BusinessError) => {
    console.error(`check failed, code is ${err.code}, message is ${err.message}`);
  });
}

// 删除表中所有数据
if (store != undefined) {
  const SQL_DELETE_TABLE = 'DELETE FROM test';
  (store as relationalStore.RdbStore).execute(SQL_DELETE_TABLE).then((data) => {
    console.info(`delete result: ${data}`);
  }).catch((err: BusinessError) => {
    console.error(`delete failed, code is ${err.code}, message is ${err.message}`);
  });
}

// 删表
if (store != undefined) {
  const SQL_DROP_TABLE = 'DROP TABLE test';
  (store as relationalStore.RdbStore).execute(SQL_DROP_TABLE).then((data) => {
    console.info(`drop result: ${data}`);
  }).catch((err: BusinessError) => {
    console.error(`drop failed, code is ${err.code}, message is ${err.message}`);
  });
}
```

向量数据库：

```ts
// FLOATVECTOR(2)是维度为2的向量属性，后续操作repr需依照该维度进行。
let createSql = "CREATE TABLE test (ID text PRIMARY KEY,REPR FLOATVECTOR(2));";
// 建表
await store!.execute(createSql);
// 使用参数绑定插入数据
let insertSql = "insert into test VALUES(?, ?);";
const vectorValue: Float32Array = Float32Array.from([1.5, 6.6]);
await store!.execute(insertSql, [0, vectorValue]);
// 不使用绑定参数直接执行
await store!.execute("insert into test values(1, '[3.5, 1.8]');");
```

### execute<sup>12+</sup>

execute(sql: string, txId: number, args?: Array&lt;ValueType&gt;): Promise&lt;ValueType&gt;

执行包含指定参数的SQL语句，语句中的各种表达式和操作符之间的关系操作符号不超过1000个，使用Promise异步回调。

该接口仅支持[向量数据库](#storeconfig)使用。使用该接口执行插入操作，数据来源于子查询时，支持全字段插入，暂不支持部分字段插入。

此接口不支持执行查询，可以使用[querySql](#querysql10)接口代替。

不支持分号分隔的多条语句。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型                                 | 必填 | 说明                                                         |
| -------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| sql      | string                               | 是   | 指定要执行的SQL语句。                                        |
| txId      | number                               | 是   | 通过[beginTrans](#begintrans12)获取的事务ID，如果传0，该语句默认在单独事务内。                                      |
| args | Array&lt;[ValueType](#valuetype)&gt; | 否   | SQL语句中参数的值。该值与sql参数语句中的占位符相对应。该参数不填，填null或者填undefined，都认为是sql参数语句完整。 |

**返回值**：

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;[ValueType](#valuetype)&gt; | Promise对象，返回null。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported the sql(attach,begin,commit,rollback etc.). |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |
| 14800047  | The WAL file size exceeds the default limit. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
if (store != null) {
  let txId: number;
  (store as relationalStore.RdbStore).beginTrans().then((txId: number) => {
    (store as relationalStore.RdbStore).execute("DELETE FROM TEST WHERE age = ? OR age = ?", txId, ["18", "20"])
      .then(() => {
        (store as relationalStore.RdbStore).commit(txId);
      })
      .catch((err: BusinessError) => {
        (store as relationalStore.RdbStore).rollback(txId);
        console.error(`execute sql failed, code is ${err.code},message is ${err.message}`);
      });
  });
}
```

### executeSync<sup>12+</sup>

executeSync(sql: string, args?: Array&lt;ValueType&gt;): ValueType

执行包含指定参数的SQL语句，语句中的各种表达式和操作符之间的关系操作符号不超过1000个，返回值类型为ValueType。

该接口支持执行增删改操作，支持执行PRAGMA语法的sql，支持对表的操作（建表、删表、修改表），返回结果类型由执行具体sql的结果决定。

此接口不支持执行查询、附加数据库和事务操作，可以使用[querySql](#querysql10)、[query](#query10)、[attach](#attach12)、[beginTransaction](#begintransaction)、[commit](#commit)等接口代替。

不支持分号分隔的多条语句。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型                                 | 必填 | 说明                                                         |
| ------ | ------------------------------------ | ---- | ------------------------------------------------------------ |
| sql    | string                               | 是   | 指定要执行的SQL语句。                                        |
| args   | Array&lt;[ValueType](#valuetype)&gt; | 否   | SQL语句中参数的值。该值与sql参数语句中的占位符相对应。该参数不填，或者填null或undefined，都认为是sql参数语句完整。默认值为空。 |

**返回值**：

| 类型                    | 说明                |
| ----------------------- | ------------------- |
| [ValueType](#valuetype) | 返回sql执行后的结果 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000     | Inner error.                                                 |
| 14800011     | Database corrupted.                                          |
| 14800014     | Already closed.                                              |
| 14800015     | The database does not respond.                               |
| 14800021     | SQLite: Generic error.                                       |
| 14800022     | SQLite: Callback routine requested an abort.                 |
| 14800023     | SQLite: Access permission denied.                            |
| 14800024     | SQLite: The database file is locked.                         |
| 14800025     | SQLite: A table in the database is locked.                   |
| 14800026     | SQLite: The database is out of memory.                       |
| 14800027     | SQLite: Attempt to write a readonly database.                |
| 14800028     | SQLite: Some kind of disk I/O error occurred.                |
| 14800029     | SQLite: The database is full.                                |
| 14800030     | SQLite: Unable to open the database file.                    |
| 14800031     | SQLite: TEXT or BLOB exceeds size limit.                     |
| 14800032     | SQLite: Abort due to constraint violation.                   |
| 14800033     | SQLite: Data type mismatch.                                  |
| 14800034     | SQLite: Library used incorrectly.                            |
| 14800047     | The WAL file size exceeds the default limit.                 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 校验数据库完整性
if (store != undefined) {
  const SQL_CHECK_INTEGRITY = 'PRAGMA integrity_check';
  try {
    let data = (store as relationalStore.RdbStore).executeSync(SQL_CHECK_INTEGRITY);
    console.info(`check result: ${data}`);
  } catch (err) {
    console.error(`check failed, code is ${err.code}, message is ${err.message}`);
  }
}

// 删除表中所有数据
if (store != undefined) {
  const SQL_DELETE_TABLE = 'DELETE FROM test';
  try {
    let data = (store as relationalStore.RdbStore).executeSync(SQL_DELETE_TABLE);
    console.info(`delete result: ${data}`);
  } catch (err) {
    console.error(`delete failed, code is ${err.code}, message is ${err.message}`);
  }
}

// 删表
if (store != undefined) {
  const SQL_DROP_TABLE = 'DROP TABLE test';
  try {
    let data = (store as relationalStore.RdbStore).executeSync(SQL_DROP_TABLE);
    console.info(`drop result: ${data}`);
  } catch (err) {
    console.error(`drop failed, code is ${err.code}, message is ${err.message}`);
  }
}
```

### getModifyTime<sup>10+</sup>

getModifyTime(table: string, columnName: string, primaryKeys: PRIKeyType[], callback: AsyncCallback&lt;ModifyTime&gt;): void

获取数据库表中数据的最后修改时间，使用callback异步回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名      | 类型                                             | 必填 | 说明                                                         |
| ----------- | ------------------------------------------------ | ---- | ------------------------------------------------------------ |
| table       | string                                           | 是   | 指定要查询的数据库表的表名。                                 |
| columnName  | string                                           | 是   | 指定要查询的数据库表的列名。                                 |
| primaryKeys | [PRIKeyType](#prikeytype10)[]                    | 是   | 指定要查询的行的主键。<br>如果数据库表无主键，参数columnName需传入"rowid"，此时primaryKeys为要查询的数据库表的行号。<br>如果数据库表无主键，参数columnName传入不为"rowid"，返回对应的错误码。 |
| callback    | AsyncCallback&lt;[ModifyTime](#modifytime10)&gt; | 是   | 指定callback回调函数。如果操作成功，则返回ModifyTime对象，表示数据的最后修改时间。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Need 3 - 4  parameter(s)! 2. The RdbStore must be not nullptr.3. The tablesNames must be not empty string. 4. The columnName must be not empty string. 5. The PRIKey must be number or string. |
| 801       | Capability not supported. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |

**示例：**

```ts
let PRIKey = [1, 4, 2, 3];
if (store != undefined) {
  (store as relationalStore.RdbStore).getModifyTime("EMPLOYEE", "NAME", PRIKey, (err, modifyTime: relationalStore.ModifyTime) => {
    if (err) {
      console.error(`getModifyTime failed, code is ${err.code},message is ${err.message}`);
      return;
    }
    let size = modifyTime.size;
  });
}
```

### getModifyTime<sup>10+</sup>

getModifyTime(table: string, columnName: string, primaryKeys: PRIKeyType[]): Promise&lt;ModifyTime&gt;

获取数据库表中数据的最后修改时间，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名      | 类型                          | 必填 | 说明                                                         |
| ----------- | ----------------------------- | ---- | ------------------------------------------------------------ |
| table       | string                        | 是   | 指定要查询的数据库表的表名。                                 |
| columnName  | string                        | 是   | 指定要查询的数据库表的列名。                                 |
| primaryKeys | [PRIKeyType](#prikeytype10)[] | 是   | 指定要查询的行的主键。<br>如果数据库表无主键，参数columnName需传入"rowid"，此时primaryKeys为要查询的数据库表的行号。<br>如果数据库表无主键，参数columnName传入不为"rowid"，返回对应的错误码。 |

**返回值**：

| 类型                                       | 说明                                                      |
| ------------------------------------------ | --------------------------------------------------------- |
| Promise&lt;[ModifyTime](#modifytime10)&gt; | 返回ModifyTime类型的Promise对象，表示数据最后的修改时间。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Need 3 - 4  parameter(s)! 2. The RdbStore must be not nullptr.3. The tablesNames must be not empty string. 4. The columnName must be not empty string. 5. The PRIKey must be number or string. |
| 801       | Capability not supported. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let PRIKey = [1, 2, 3];
if (store != undefined) {
  (store as relationalStore.RdbStore).getModifyTime("EMPLOYEE", "NAME", PRIKey)
    .then((modifyTime: relationalStore.ModifyTime) => {
      let size = modifyTime.size;
    })
    .catch((err: BusinessError) => {
      console.error(`getModifyTime failed, code is ${err.code},message is ${err.message}`);
    });
}
```

### beginTransaction

beginTransaction():void

在开始执行SQL语句之前，开始事务。
此接口不允许嵌套事务，且不支持在多进程或多线程中使用。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. The store must not be nullptr. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |
| 14800047  | The WAL file size exceeds the default limit. |

**示例：**

```ts
let value1 = "Lisa";
let value2 = 18;
let value3 = 100.5;
let value4 = new Uint8Array([1, 2, 3]);

if (store != undefined) {
  (store as relationalStore.RdbStore).beginTransaction();
  const valueBucket: relationalStore.ValuesBucket = {
    'NAME': value1,
    'AGE': value2,
    'SALARY': value3,
    'CODES': value4,
  };
  (store as relationalStore.RdbStore).insert("test", valueBucket);
  (store as relationalStore.RdbStore).commit();
}
```

### beginTrans<sup>12+</sup>

beginTrans(): Promise&lt;number&gt;

在开始执行SQL语句之前，开始事务，使用Promise异步回调。

与[beginTransaction](#begintransaction)的区别在于：该接口会返回事务ID，[execute](#execute12-1)可以指定不同事务ID达到事务隔离目的。

该接口仅支持[向量数据库](#storeconfig)使用。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**返回值**：

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;number&gt; | Promise对象，返回事务ID。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. The store must not be nullptr. |
| 801       | Capability not supported the sql(attach,begin,commit,rollback etc.). |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |
| 14800047  | The WAL file size exceeds the default limit. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
if (store != null) {
  let txId: number;
  (store as relationalStore.RdbStore).beginTrans().then((txId: number) => {
    (store as relationalStore.RdbStore).execute("DELETE FROM TEST WHERE age = ? OR age = ?", txId, ["18", "20"])
      .then(() => {
        (store as relationalStore.RdbStore).commit(txId);
      })
      .catch((err: BusinessError) => {
        (store as relationalStore.RdbStore).rollback(txId);
        console.error(`execute sql failed, code is ${err.code},message is ${err.message}`);
      });
  });
}
```

### createTransaction<sup>14+</sup>

createTransaction(options?: TransactionOptions): Promise&lt;Transaction&gt;

创建一个事务对象并开始事务，使用Promise异步回调。

与[beginTransaction](#begintransaction)的区别在于：createTransaction接口会返回一个事务对象，不同事务对象之间是隔离的。使用事务对象进行插入、删除或更新数据等操作，无法被注册数据变更通知[on('dataChange')](#ondatachange)监听到。

一个store最多支持同时存在四个事务对象，超过后会返回14800015错误码，此时需要检查是否持有事务对象时间过长或并发事务过多，若确认无法通过上述优化解决问题，建议等待现有事务释放后，再尝试新建事务对象。

优先使用createTransaction，不再推荐使用beginTransaction。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名      | 类型                          | 必填 | 说明                                                         |
| ----------- | ----------------------------- | ---- | ------------------------------------------------------------ |
| options       | [TransactionOptions](#transactionoptions14)           | 否   | 表示事务对象的配置信息。                                 |

**返回值**：

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;[Transaction](#transaction14)&gt; | Promise对象，返回事务对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database is busy.              |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if (store != undefined) {
  (store as relationalStore.RdbStore).createTransaction().then((transaction: relationalStore.Transaction) => {
    transaction.execute("DELETE FROM test WHERE age = ? OR age = ?", [21, 20]).then(() => {
      transaction.commit();
    }).catch((e: BusinessError) => {
      transaction.rollback();
      console.error(`execute sql failed, code is ${e.code},message is ${e.message}`);
    });
  }).catch((err: BusinessError) => {
    console.error(`createTransaction faided, code is ${err.code},message is ${err.message}`);
  });
}
```

### commit

commit():void

提交已执行的SQL语句，跟[beginTransaction](#begintransaction)配合使用。
此接口不允许嵌套事务，且不支持在多进程或多线程中使用。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. The store must not be nullptr. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |

**示例：**

```ts
let value1 = "Lisa";
let value2 = 18;
let value3 = 100.5;
let value4 = new Uint8Array([1, 2, 3]);

if (store != undefined) {
  (store as relationalStore.RdbStore).beginTransaction();
  const valueBucket: relationalStore.ValuesBucket = {
    'NAME': value1,
    'AGE': value2,
    'SALARY': value3,
    'CODES': value4,
  };
  (store as relationalStore.RdbStore).insert("test", valueBucket);
  (store as relationalStore.RdbStore).commit();
}
```

### commit<sup>12+</sup>

commit(txId : number):Promise&lt;void&gt;

提交已执行的SQL语句，跟[beginTrans](#begintrans12)配合使用。

该接口仅支持[向量数据库](#storeconfig)使用。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型                                 | 必填 | 说明                                                         |
| -------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| txId      | number                               | 是   | 通过[beginTrans](#begintrans12)获取的事务ID。                                        |

**返回值**：

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
if (store != null) {
  let txId: number;
  (store as relationalStore.RdbStore).beginTrans().then((txId: number) => {
    (store as relationalStore.RdbStore).execute("DELETE FROM TEST WHERE age = ? OR age = ?", txId, ["18", "20"])
      .then(() => {
        (store as relationalStore.RdbStore).commit(txId);
      })
      .catch((err: BusinessError) => {
        (store as relationalStore.RdbStore).rollback(txId);
        console.error(`execute sql failed, code is ${err.code},message is ${err.message}`);
      });
  });
}
```

### rollBack

rollBack():void

回滚已经执行的SQL语句。
此接口不允许嵌套事务，且不支持在多进程或多线程中使用。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. The store must not be nullptr. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let value1 = "Lisa";
let value2 = 18;
let value3 = 100.5;
let value4 = new Uint8Array([1, 2, 3]);

if (store != undefined) {
  try {
    (store as relationalStore.RdbStore).beginTransaction();
    const valueBucket: relationalStore.ValuesBucket = {
      'NAME': value1,
      'AGE': value2,
      'SALARY': value3,
      'CODES': value4,
    };
    (store as relationalStore.RdbStore).insert("test", valueBucket);
    (store as relationalStore.RdbStore).commit();
  } catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error(`Transaction failed, code is ${code},message is ${message}`);
    (store as relationalStore.RdbStore).rollBack();
  }
}
```

### rollback<sup>12+</sup>

rollback(txId : number):Promise&lt;void&gt;

回滚已经执行的SQL语句，跟[beginTrans](#begintrans12)配合使用。

该接口仅支持[向量数据库](#storeconfig)使用。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型                                 | 必填 | 说明                                                         |
| -------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| txId      | number                               | 是   | 通过[beginTrans](#begintrans12)获取的事务ID。                                        |

**返回值**：

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. The store must not be nullptr. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
if (store != null) {
  let txId: number;
  (store as relationalStore.RdbStore).beginTrans().then((txId: number) => {
    (store as relationalStore.RdbStore).execute("DELETE FROM TEST WHERE age = ? OR age = ?", txId, ["18", "20"])
      .then(() => {
        (store as relationalStore.RdbStore).commit(txId);
      })
      .catch((err: BusinessError) => {
        (store as relationalStore.RdbStore).rollback(txId);
        console.error(`execute sql failed, code is ${err.code},message is ${err.message}`);
      });
  });
}
```

### backup

backup(destName:string, callback: AsyncCallback&lt;void&gt;):void

以指定名称备份数据库，使用callback异步回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                     |
| -------- | ------------------------- | ---- | ------------------------ |
| destName | string                    | 是   | 指定数据库的备份文件名。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 指定callback回调函数。   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. The store must not be nullptr. |
| 14800000  | Inner error. |
| 14800010  | Invalid database path. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |

**示例：**

```ts
if (store != undefined) {
  (store as relationalStore.RdbStore).backup("dbBackup.db", (err) => {
    if (err) {
      console.error(`Backup failed, code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info('Backup success.');
  });
}
```

### backup

backup(destName:string): Promise&lt;void&gt;

以指定名称备份数据库，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型   | 必填 | 说明                     |
| -------- | ------ | ---- | ------------------------ |
| destName | string | 是   | 指定数据库的备份文件名。 |

**返回值**：

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if (store != undefined) {
  let promiseBackup = (store as relationalStore.RdbStore).backup("dbBackup.db");
  promiseBackup.then(() => {
    console.info('Backup success.');
  }).catch((err: BusinessError) => {
    console.error(`Backup failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### restore

restore(srcName:string, callback: AsyncCallback&lt;void&gt;):void

从指定的数据库备份文件恢复数据库，使用callback异步回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                     |
| -------- | ------------------------- | ---- | ------------------------ |
| srcName  | string                    | 是   | 指定数据库的备份文件名。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 指定callback回调函数。   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |

**示例：**

```ts
if (store != undefined) {
  (store as relationalStore.RdbStore).restore("dbBackup.db", (err) => {
    if (err) {
      console.error(`Restore failed, code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info('Restore success.');
  });
}
```

### restore

restore(srcName:string): Promise&lt;void&gt;

从指定的数据库备份文件恢复数据库，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名  | 类型   | 必填 | 说明                     |
| ------- | ------ | ---- | ------------------------ |
| srcName | string | 是   | 指定数据库的备份文件名。 |

**返回值**：

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if (store != undefined) {
  let promiseRestore = (store as relationalStore.RdbStore).restore("dbBackup.db");
  promiseRestore.then(() => {
    console.info('Restore success.');
  }).catch((err: BusinessError) => {
    console.error(`Restore failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### setDistributedTables

setDistributedTables(tables: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void

设置分布式数据库表，使用callback异步回调。

**需要权限：** ohos.permission.DISTRIBUTED_DATASYNC

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                   |
| -------- | ------------------------- | ---- | ---------------------- |
| tables   | Array&lt;string&gt;       | 是   | 要设置的分布式数据库表表名。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 指定callback回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported. |
| 14800000  | Inner error. |
| 14800014  | Already closed. |

**示例：**

```ts
if (store != undefined) {
  (store as relationalStore.RdbStore).setDistributedTables(["EMPLOYEE"], (err) => {
    if (err) {
      console.error(`SetDistributedTables failed, code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info('SetDistributedTables successfully.');
  });
}
```

### setDistributedTables

 setDistributedTables(tables: Array&lt;string&gt;): Promise&lt;void&gt;

设置分布式数据库表，使用Promise异步回调。

**需要权限：** ohos.permission.DISTRIBUTED_DATASYNC

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型                     | 必填 | 说明                     |
| ------ | ------------------------ | ---- | ------------------------ |
| tables | ArrayArray&lt;string&gt; | 是   | 要设置的分布式数据库表表名。 |

**返回值**：

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported. |
| 14800000  | Inner error. |
| 14800014  | Already closed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if (store != undefined) {
  (store as relationalStore.RdbStore).setDistributedTables(["EMPLOYEE"]).then(() => {
    console.info('SetDistributedTables successfully.');
  }).catch((err: BusinessError) => {
    console.error(`SetDistributedTables failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### setDistributedTables<sup>10+</sup>

setDistributedTables(tables: Array&lt;string&gt;, type: DistributedType, callback: AsyncCallback&lt;void&gt;): void

设置分布式数据库表，使用callback异步回调。

**需要权限：** ohos.permission.DISTRIBUTED_DATASYNC

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                         |
| -------- | ------------------------------------- | ---- | ---------------------------- |
| tables   | Array&lt;string&gt;                   | 是   | 要设置的分布式数据库表表名。 |
| type     | [DistributedType](#distributedtype10) | 是   | 表的分布式类型。             |
| callback | AsyncCallback&lt;void&gt;             | 是   | 指定callback回调函数。       |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported. |
| 14800000  | Inner error. |
| 14800014  | Already closed. |
| 14800051  | The type of the distributed table does not match. |

**示例：**

```ts
if (store != undefined) {
  (store as relationalStore.RdbStore).setDistributedTables(["EMPLOYEE"], relationalStore.DistributedType.DISTRIBUTED_CLOUD, (err) => {
    if (err) {
      console.error(`SetDistributedTables failed, code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info('SetDistributedTables successfully.');
  });
}
```

### setDistributedTables<sup>10+</sup>

setDistributedTables(tables: Array&lt;string&gt;, type: DistributedType, config: DistributedConfig, callback: AsyncCallback&lt;void&gt;): void

设置分布式数据库表，使用callback异步回调。

**需要权限：** ohos.permission.DISTRIBUTED_DATASYNC

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名      | 类型                                  | 必填  | 说明              |
| -------- | ----------------------------------- | --- | --------------- |
| tables   | Array&lt;string&gt;                 | 是   | 要设置的分布式数据库表表名。     |
| type     | [DistributedType](#distributedtype10) | 是   | 表的分布式类型。 |
| config | [DistributedConfig](#distributedconfig10) | 是 | 表的分布式配置信息。 |
| callback | AsyncCallback&lt;void&gt;           | 是   | 指定callback回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported. |
| 14800000  | Inner error. |
| 14800014  | Already closed. |
| 14800051  | The type of the distributed table does not match. |

**示例：**

```ts
if (store != undefined) {
  (store as relationalStore.RdbStore).setDistributedTables(["EMPLOYEE"], relationalStore.DistributedType.DISTRIBUTED_CLOUD, {
    autoSync: true
  }, (err) => {
    if (err) {
      console.error(`SetDistributedTables failed, code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info('SetDistributedTables successfully.');
  });
}
```

### setDistributedTables<sup>10+</sup>

 setDistributedTables(tables: Array&lt;string>, type?: DistributedType, config?: DistributedConfig): Promise&lt;void>

设置分布式数据库表，使用Promise异步回调。

**需要权限：** ohos.permission.DISTRIBUTED_DATASYNC

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型                                      | 必填 | 说明                                                         |
| ------ | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| tables | Array&lt;string&gt;                       | 是   | 要设置的分布式数据库表表名。                                 |
| type   | [DistributedType](#distributedtype10)     | 否   | 表的分布式类型。默认值是relationalStore.DistributedType.DISTRIBUTED_DEVICE。 |
| config | [DistributedConfig](#distributedconfig10) | 否   | 表的分布式配置信息。不传入时默认autoSync为false，即只支持手动同步。 |

**返回值**：

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported. |
| 14800000  | Inner error. |
| 14800014  | Already closed. |
| 14800051  | The type of the distributed table does not match. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if (store != undefined) {
  (store as relationalStore.RdbStore).setDistributedTables(["EMPLOYEE"], relationalStore.DistributedType.DISTRIBUTED_CLOUD, {
    autoSync: true
  }).then(() => {
    console.info('SetDistributedTables successfully.');
  }).catch((err: BusinessError) => {
    console.error(`SetDistributedTables failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### obtainDistributedTableName

obtainDistributedTableName(device: string, table: string, callback: AsyncCallback&lt;string&gt;): void

根据远程设备的本地表名获取指定远程设备的分布式表名。在查询远程设备数据库时，需要使用分布式表名，使用callback异步回调。

> **说明：**
>
> 其中device通过调用[deviceManager.getAvailableDeviceListSync](../apis-distributedservice-kit/js-apis-distributedDeviceManager.md#getavailabledevicelistsync)方法得到。

**需要权限：** ohos.permission.DISTRIBUTED_DATASYNC

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                                         |
| -------- | --------------------------- | ---- | ------------------------------------------------------------ |
| device   | string                      | 是   | 远程设备ID 。                                                |
| table    | string                      | 是   | 远程设备的本地表名。                                         |
| callback | AsyncCallback&lt;string&gt; | 是   | 指定的callback回调函数。如果操作成功，返回远程设备的分布式表名。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported. |
| 14800000  | Inner error. |
| 14800014  | Already closed. |

**示例：**

```ts
import { distributedDeviceManager } from '@kit.DistributedServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

let dmInstance: distributedDeviceManager.DeviceManager;
let deviceId: string | undefined = undefined;

try {
  dmInstance = distributedDeviceManager.createDeviceManager("com.example.appdatamgrverify");
  let devices = dmInstance.getAvailableDeviceListSync();
  deviceId = devices[0].networkId;
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error("createDeviceManager errCode:" + code + ",errMessage:" + message);
}

if (store != undefined && deviceId != undefined) {
  (store as relationalStore.RdbStore).obtainDistributedTableName(deviceId, "EMPLOYEE", (err, tableName) => {
    if (err) {
      console.error(`ObtainDistributedTableName failed, code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info(`ObtainDistributedTableName successfully, tableName= ${tableName}`);
  });
}
```

### obtainDistributedTableName

 obtainDistributedTableName(device: string, table: string): Promise&lt;string&gt;

根据远程设备的本地表名获取指定远程设备的分布式表名。在查询远程设备数据库时，需要使用分布式表名，使用Promise异步回调。

> **说明：**
>
> 其中device通过调用[deviceManager.getAvailableDeviceListSync](../apis-distributedservice-kit/js-apis-distributedDeviceManager.md#getavailabledevicelistsync)方法得到。

**需要权限：** ohos.permission.DISTRIBUTED_DATASYNC

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| device | string | 是   | 远程设备ID。         |
| table  | string | 是   | 远程设备的本地表名。 |

**返回值**：

| 类型                  | 说明                                                  |
| --------------------- | ----------------------------------------------------- |
| Promise&lt;string&gt; | Promise对象。如果操作成功，返回远程设备的分布式表名。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported. |
| 14800000  | Inner error. |
| 14800014  | Already closed. |

**示例：**

```ts
import { distributedDeviceManager } from '@kit.DistributedServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

let dmInstance: distributedDeviceManager.DeviceManager;
let deviceId: string | undefined = undefined;

try {
  dmInstance = distributedDeviceManager.createDeviceManager("com.example.appdatamgrverify");
  let devices = dmInstance.getAvailableDeviceListSync();
  deviceId = devices[0].networkId;
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error("createDeviceManager errCode:" + code + ",errMessage:" + message);
}

if (store != undefined && deviceId != undefined) {
  (store as relationalStore.RdbStore).obtainDistributedTableName(deviceId, "EMPLOYEE").then((tableName: string) => {
    console.info(`ObtainDistributedTableName successfully, tableName= ${tableName}`);
  }).catch((err: BusinessError) => {
    console.error(`ObtainDistributedTableName failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### sync

sync(mode: SyncMode, predicates: RdbPredicates, callback: AsyncCallback&lt;Array&lt;[string, number]&gt;&gt;): void

在设备之间同步数据，使用callback异步回调。

**需要权限：** ohos.permission.DISTRIBUTED_DATASYNC

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名     | 类型                                               | 必填 | 说明                                                         |
| ---------- | -------------------------------------------------- | ---- | ------------------------------------------------------------ |
| mode       | [SyncMode](#syncmode)                             | 是   | 指同步模式。该值可以是relationalStore.SyncMode.SYNC_MODE_PUSH、relationalStore.SyncMode.SYNC_MODE_PULL。                               |
| predicates | [RdbPredicates](#rdbpredicates)               | 是   | 约束同步数据和设备。                                         |
| callback   | AsyncCallback&lt;Array&lt;[string, number]&gt;&gt; | 是   | 指定的callback回调函数，用于向调用者发送同步结果。string：设备ID；number：每个设备同步状态，0表示成功，其他值表示失败。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported. |
| 14800000  | Inner error. |
| 14800014  | Already closed. |

**示例：**

```ts
import { distributedDeviceManager } from '@kit.DistributedServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

let dmInstance: distributedDeviceManager.DeviceManager;
let deviceIds: Array<string> = [];

try {
  dmInstance = distributedDeviceManager.createDeviceManager("com.example.appdatamgrverify");
  let devices: Array<distributedDeviceManager.DeviceBasicInfo> = dmInstance.getAvailableDeviceListSync();
  for (let i = 0; i < devices.length; i++) {
    deviceIds[i] = devices[i].networkId!;
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error("createDeviceManager errCode:" + code + ",errMessage:" + message);
}

let predicates = new relationalStore.RdbPredicates('EMPLOYEE');
predicates.inDevices(deviceIds);
if (store != undefined) {
  (store as relationalStore.RdbStore).sync(relationalStore.SyncMode.SYNC_MODE_PUSH, predicates, (err, result) => {
    if (err) {
      console.error(`Sync failed, code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info('Sync done.');
    for (let i = 0; i < result.length; i++) {
      console.info(`device= ${result[i][0]}, status= ${result[i][1]}`);
    }
  });
}
```

### sync

 sync(mode: SyncMode, predicates: RdbPredicates): Promise&lt;Array&lt;[string, number]&gt;&gt;

在设备之间同步数据，使用Promise异步回调。

**需要权限：** ohos.permission.DISTRIBUTED_DATASYNC

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名     | 类型                                 | 必填 | 说明                           |
| ---------- | ------------------------------------ | ---- | ------------------------------ |
| mode       | [SyncMode](#syncmode)               | 是   | 指同步模式。该值可以是relationalStore.SyncMode.SYNC_MODE_PUSH、relationalStore.SyncMode.SYNC_MODE_PULL。 |
| predicates | [RdbPredicates](#rdbpredicates) | 是   | 约束同步数据和设备。           |

**返回值**：

| 类型                                         | 说明                                                         |
| -------------------------------------------- | ------------------------------------------------------------ |
| Promise&lt;Array&lt;[string, number]&gt;&gt; | Promise对象，用于向调用者发送同步结果。string：设备ID；number：每个设备同步状态，0表示成功，其他值表示失败。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported. |
| 14800000  | Inner error. |
| 14800014  | Already closed. |

**示例：**

```ts
import { distributedDeviceManager } from '@kit.DistributedServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

let dmInstance: distributedDeviceManager.DeviceManager;
let deviceIds: Array<string> = [];

try {
  dmInstance = distributedDeviceManager.createDeviceManager("com.example.appdatamgrverify");
  let devices: Array<distributedDeviceManager.DeviceBasicInfo> = dmInstance.getAvailableDeviceListSync();
  for (let i = 0; i < devices.length; i++) {
    deviceIds[i] = devices[i].networkId!;
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error("createDeviceManager errCode:" + code + ",errMessage:" + message);
}

let predicates = new relationalStore.RdbPredicates('EMPLOYEE');
predicates.inDevices(deviceIds);
if (store != undefined) {
  (store as relationalStore.RdbStore).sync(relationalStore.SyncMode.SYNC_MODE_PUSH, predicates).then((result: Object[][]) => {
    console.info('Sync done.');
    for (let i = 0; i < result.length; i++) {
      console.info(`device= ${result[i][0]}, status= ${result[i][1]}`);
    }
  }).catch((err: BusinessError) => {
    console.error(`Sync failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### cloudSync<sup>10+</sup>

cloudSync(mode: SyncMode, progress: Callback&lt;ProgressDetails&gt;, callback: AsyncCallback&lt;void&gt;): void

手动执行对所有分布式表的端云同步，使用callback异步回调。使用该接口需要实现云服务功能。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                                               |
| -------- | ----------------------------------------------------- | ---- | -------------------------------------------------- |
| mode     | [SyncMode](#syncmode)                                 | 是   | 表示数据库的同步模式。                             |
| progress | Callback&lt;[ProgressDetails](#progressdetails10)&gt; | 是   | 用来处理数据库同步详细信息的回调函数。             |
| callback | AsyncCallback&lt;void&gt;                             | 是   | 指定的callback回调函数，用于向调用者发送同步结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**        |
|-----------|-------|
| 401       | Parameter error. Possible causes: 1. Need 2 - 4  parameter(s). 2. The RdbStore must be not nullptr. 3. The mode must be a SyncMode of cloud. 4. The progress must be a callback type. 5. The callback must be a function. |
| 801       | Capability not supported.       |
| 14800014  | Already closed.        |

**示例：**

```ts
if (store != undefined) {
  (store as relationalStore.RdbStore).cloudSync(relationalStore.SyncMode.SYNC_MODE_CLOUD_FIRST, (progressDetails) => {
    console.info(`Progess: ${progressDetails}`);
  }, (err) => {
    if (err) {
      console.error(`Cloud sync failed, code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info('Cloud sync succeeded');
  });
}
```

### cloudSync<sup>10+</sup>

cloudSync(mode: SyncMode, progress: Callback&lt;ProgressDetails&gt;): Promise&lt;void&gt;

手动执行对所有分布式表的端云同步，使用Promise异步回调。使用该接口需要实现云服务功能。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                                   |
| -------- | ----------------------------------------------------- | ---- | -------------------------------------- |
| mode     | [SyncMode](#syncmode)                                 | 是   | 表示数据库的同步模式。                 |
| progress | Callback&lt;[ProgressDetails](#progressdetails10)&gt; | 是   | 用来处理数据库同步详细信息的回调函数。 |

**返回值**：

| 类型                | 说明                                    |
| ------------------- | --------------------------------------- |
| Promise&lt;void&gt; | Promise对象，用于向调用者发送同步结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**    |
|-----------|------------------|
| 401       | Parameter error. Possible causes: 1. Need 2 - 4  parameter(s). 2. The RdbStore must be not nullptr. 3. The mode must be a SyncMode of cloud. 4. The progress must be a callback type. |
| 801       | Capability not supported.   |
| 14800014  | Already closed.           |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if (store != undefined) {
  (store as relationalStore.RdbStore).cloudSync(relationalStore.SyncMode.SYNC_MODE_CLOUD_FIRST, (progressDetail: relationalStore.ProgressDetails) => {
    console.info(`progress: ${progressDetail}`);
  }).then(() => {
    console.info('Cloud sync succeeded');
  }).catch((err: BusinessError) => {
    console.error(`cloudSync failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### cloudSync<sup>10+</sup>

cloudSync(mode: SyncMode, tables: string[], progress: Callback&lt;ProgressDetails&gt;, callback: AsyncCallback&lt;void&gt;): void

手动执行对指定表的端云同步，使用callback异步回调。使用该接口需要实现云服务功能。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                                               |
| -------- | ----------------------------------------------------- | ---- | -------------------------------------------------- |
| mode     | [SyncMode](#syncmode)                                 | 是   | 表示数据库的同步模式。                             |
| tables   | string[]                                              | 是   | 指定同步的表名。                                   |
| progress | Callback&lt;[ProgressDetails](#progressdetails10)&gt; | 是   | 用来处理数据库同步详细信息的回调函数。             |
| callback | AsyncCallback&lt;void&gt;                             | 是   | 指定的callback回调函数，用于向调用者发送同步结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                                                                                                                                                                                                  |
|-----------|-------|
| 401       | Parameter error. Possible causes: 1. Need 2 - 4  parameter(s). 2. The RdbStore must be not nullptr. 3. The mode must be a SyncMode of cloud. 4. The tablesNames must be not empty. 5. The progress must be a callback type. 6.The callback must be a function.|
| 801       | Capability not supported.   |
| 14800014  | Already closed.   |

**示例：**

```ts
const tables = ["table1", "table2"];

if (store != undefined) {
  (store as relationalStore.RdbStore).cloudSync(relationalStore.SyncMode.SYNC_MODE_CLOUD_FIRST, tables, (progressDetail: relationalStore.ProgressDetails) => {
    console.info(`Progess: ${progressDetail}`);
  }, (err) => {
    if (err) {
      console.error(`Cloud sync failed, code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info('Cloud sync succeeded');
  });
};
```

### cloudSync<sup>10+</sup>

cloudSync(mode: SyncMode, tables: string[], progress: Callback&lt;ProgressDetails&gt;): Promise&lt;void&gt;

手动执行对指定表的端云同步，使用Promise异步回调。使用该接口需要实现云服务功能。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                                   |
| -------- | ----------------------------------------------------- | ---- | -------------------------------------- |
| mode     | [SyncMode](#syncmode)                                 | 是   | 表示数据库的同步模式。                 |
| tables   | string[]                                              | 是   | 指定同步的表名。                       |
| progress | Callback&lt;[ProgressDetails](#progressdetails10)&gt; | 是   | 用来处理数据库同步详细信息的回调函数。 |

**返回值**：

| 类型                | 说明                                    |
| ------------------- | --------------------------------------- |
| Promise&lt;void&gt; | Promise对象，用于向调用者发送同步结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**     |
|-----------|---------------|
| 401       | Parameter error. Possible causes: 1. Need 2 - 4  parameter(s). 2. The RdbStore must be not nullptr. 3. The mode must be a SyncMode of cloud. 4. The tablesNames must be not empty. 5. The progress must be a callback type |
| 801       | Capability not supported.    |
| 14800014  | Already closed.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const tables = ["table1", "table2"];

if (store != undefined) {
  (store as relationalStore.RdbStore).cloudSync(relationalStore.SyncMode.SYNC_MODE_CLOUD_FIRST, tables, (progressDetail: relationalStore.ProgressDetails) => {
    console.info(`progress: ${progressDetail}`);
  }).then(() => {
    console.info('Cloud sync succeeded');
  }).catch((err: BusinessError) => {
    console.error(`cloudSync failed, code is ${err.code},message is ${err.message}`);
  });
};
```

### on('dataChange')

on(event: 'dataChange', type: SubscribeType, observer: Callback&lt;Array&lt;string&gt;&gt;): void

注册数据库的数据变更的事件监听。当分布式数据库中的数据发生更改时，将调用回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| event    | string                                                       | 是   | 取值为'dataChange'，表示数据更改。                           |
| type     | [SubscribeType](#subscribetype)                              | 是   | 订阅类型。                                                   |
| observer | Callback&lt;Array&lt;string&gt;&gt;                          | 是   | 指分布式数据库中数据更改事件的观察者。Array&lt;string&gt;为数据库中的数据发生改变的对端设备ID。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**        |
|-----------|-------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported. |
| 14800014  | Already closed.    |

**示例：**

```ts
import { distributedDeviceManager } from '@kit.DistributedServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

let storeObserver = (devices: Array<string>) => {
  if (devices != undefined) {
    for (let i = 0; i < devices.length; i++) {
      console.info(`device= ${devices[i]} data changed`);
    }
  }
};

try {
  if (store != undefined) {
    (store as relationalStore.RdbStore).on('dataChange', relationalStore.SubscribeType.SUBSCRIBE_TYPE_REMOTE, storeObserver);
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`Register observer failed, code is ${code},message is ${message}`);
}
```

### on('dataChange')<sup>10+</sup>

on(event: 'dataChange', type: SubscribeType, observer: Callback&lt;Array&lt;string&gt;&gt;\| Callback&lt;Array&lt;ChangeInfo&gt;&gt;): void

注册数据库的数据变更的事件监听。当分布式数据库或本地数据库中的数据发生更改时，将调用回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型                                | 必填 | 说明                                        |
| -------- | ----------------------------------- | ---- | ------------------------------------------- |
| event    | string                              | 是   | 取值为'dataChange'，表示数据更改。          |
| type     | [SubscribeType](#subscribetype)    | 是   | 订阅类型。 |
| observer | Callback&lt;Array&lt;string&gt;&gt; \| Callback&lt;Array&lt;[ChangeInfo](#changeinfo10)&gt;&gt; | 是   | 回调函数。<br>当type为SUBSCRIBE_TYPE_REMOTE，observer类型需为Callback&lt;Array&lt;string&gt;&gt;，其中Array&lt;string&gt;为数据库中的数据发生改变的对端设备ID。<br> 当type为SUBSCRIBE_TYPE_CLOUD，observer类型需为Callback&lt;Array&lt;string&gt;&gt;，其中Array&lt;string&gt;为数据库中的数据发生改变的云端账号。<br> 当type为SUBSCRIBE_TYPE_CLOUD_DETAILS，observer类型需为Callback&lt;Array&lt;ChangeInfo&gt;&gt;，其中Array&lt;ChangeInfo&gt;为数据库端云同步过程的详情。<br>当type为SUBSCRIBE_TYPE_LOCAL_DETAILS，observer类型需为Callback&lt;Array&lt;ChangeInfo&gt;&gt;，其中Array&lt;ChangeInfo&gt;为本地数据库中的数据更改的详情。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**        |
|-----------|-------------|
| 202       | Permission verification failed, application which is not a system application uses system API. |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported. |
| 14800014  | Already closed.    |

**示例1：type为SUBSCRIBE_TYPE_REMOTE**

```ts
import { distributedDeviceManager } from '@kit.DistributedServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

let storeObserver = (devices: Array<string>) => {
  if (devices != undefined) {
    for (let i = 0; i < devices.length; i++) {
      console.info(`device= ${devices[i]} data changed`);
    }
  }
};

try {
  if (store != undefined) {
    (store as relationalStore.RdbStore).on('dataChange', relationalStore.SubscribeType.SUBSCRIBE_TYPE_REMOTE, storeObserver);
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`Register observer failed, code is ${code},message is ${message}`);
}
```

**示例2：type为SUBSCRIBE_TYPE_LOCAL_DETAILS**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let changeInfos = (changeInfos: Array<relationalStore.ChangeInfo>) => {
  for (let i = 0; i < changeInfos.length; i++) {
    console.info(`changeInfos = ${changeInfos[i]}`);
  }
};

try {
  if (store != undefined) {
    (store as relationalStore.RdbStore).on('dataChange', relationalStore.SubscribeType.SUBSCRIBE_TYPE_LOCAL_DETAILS, changeInfos);
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`on dataChange fail, code is ${code},message is ${message}`);
}

let value1 = "Lisa";
let value2 = 18;
let value3 = 100.5;
let value4 = new Uint8Array([1, 2, 3]);

try {
  const valueBucket: relationalStore.ValuesBucket = {
    'name': value1,
    'age': value2,
    'salary': value3,
    'blobType': value4,
  };

  if (store != undefined) {
    (store as relationalStore.RdbStore).insert('test', valueBucket);
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`insert fail, code is ${code},message is ${message}`);
}
```

### on<sup>10+</sup>

on(event: string, interProcess: boolean, observer: Callback\<void>): void

注册数据库的进程内或者进程间事件监听。当调用[emit](#emit10)接口时，将调用回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名       | 类型            | 必填 | 说明                                                         |
| ------------ | --------------- | ---- | ------------------------------------------------------------ |
| event        | string          | 是   | 订阅事件名称，与emit接口触发事件时的名称一致。               |
| interProcess | boolean         | 是   | 指定是进程间还是本进程订阅。<br/> true：进程间。<br/> false：本进程。 |
| observer     | Callback\<void> | 是   | 回调函数。                                                   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**        |
|-----------|-------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported. |
| 14800000  | Inner error.    |
| 14800014  | Already closed.    |
| 14800050  | Failed to obtain the subscription service.    |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let storeObserver = () => {
  console.info(`storeObserver`);
};

try {
  if (store != undefined) {
    (store as relationalStore.RdbStore).on('storeObserver', false, storeObserver);
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`Register observer failed, code is ${code},message is ${message}`);
}
```

### on('autoSyncProgress')<sup>11+</sup>

on(event: 'autoSyncProgress', progress: Callback&lt;ProgressDetails&gt;): void

在已打开端云同步，并且网络状态正常的条件下，注册自动同步进度通知，自动同步进行时调用回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名       | 类型                              | 必填 | 说明                                |
| ------------ |---------------------------------| ---- |-----------------------------------|
| event        | string                          | 是   | 取值为'autoSyncProgress'，表示自动同步进度通知。 |
| progress     | Callback&lt;[ProgressDetails](#progressdetails10)&gt; | 是   | 回调函数。                             |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**    |
|-----------|--------|
| 401       | Parameter error. Possible causes: 1. Need 2 - 3  parameter(s)! 2. The RdbStore must be valid. 3. The event must be a not empty string. 4. The progress must be function. |
| 801       | Capability not supported.  |
| 14800014  | Already closed.     |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let progressDetail = (progressDetail: relationalStore.ProgressDetails) => {
  console.info(`progress: ${progressDetail}`);
};

try {
  if (store != undefined) {
    (store as relationalStore.RdbStore).on('autoSyncProgress', progressDetail);
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`Register observer failed, code is ${code},message is ${message}`);
}
```

### on('statistics')<sup>12+</sup>

on(event: 'statistics', observer: Callback&lt;SqlExecutionInfo&gt;): void

订阅SQL统计信息。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名       | 类型                              | 必填 | 说明                                |
| ------------ |---------------------------------| ---- |-----------------------------------|
| event        | string                          | 是   | 订阅事件名称，取值为'statistics'，表示sql执行时间的统计。 |
| observer     | Callback&lt;[SqlExecutionInfo](#sqlexecutioninfo12)&gt; | 是   | 回调函数。用于返回数据库中SQL执行时间的统计信息。  |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**    |
|-----------|--------|
| 401       | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 801       | Capability not supported.  |
| 14800000  | Inner error.  |
| 14800014  | Already closed.     |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let sqlExecutionInfo = (sqlExecutionInfo: relationalStore.SqlExecutionInfo) => {
  console.info(`sql: ${sqlExecutionInfo.sql[0]}`);
  console.info(`totalTime: ${sqlExecutionInfo.totalTime}`);
  console.info(`waitTime: ${sqlExecutionInfo.waitTime}`);
  console.info(`prepareTime: ${sqlExecutionInfo.prepareTime}`);
  console.info(`executeTime: ${sqlExecutionInfo.executeTime}`);
};

try {
  if (store != undefined) {
    (store as relationalStore.RdbStore).on('statistics', sqlExecutionInfo);
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`Register observer failed, code is ${code},message is ${message}`);
}

try {
  let value1 = "Lisa";
  let value2 = 18;
  let value3 = 100.5;
  let value4 = new Uint8Array([1, 2, 3, 4, 5]);

  const valueBucket: relationalStore.ValuesBucket = {
    'NAME': value1,
    'AGE': value2,
    'SALARY': value3,
    'CODES': value4,
  };
  if (store != undefined) {
    (store as relationalStore.RdbStore).insert('test', valueBucket);
  }
} catch (err) {
  console.error(`insert fail, code:${err.code}, message: ${err.message}`);
}
```

### off('dataChange')

off(event:'dataChange', type: SubscribeType, observer: Callback&lt;Array&lt;string&gt;&gt;): void

取消数据变更的事件监听。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| event    | string                                                       | 是   | 取值为'dataChange'，表示数据更改。                           |
| type     | [SubscribeType](#subscribetype) | 是   | 订阅类型。                                                   |
| observer | Callback&lt;Array&lt;string&gt;&gt;                          | 是   | 指已注册的数据更改观察者。Array&lt;string&gt;为数据库中的数据发生改变的对端设备ID。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**        |
|-----------|-------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported. |
| 14800014  | Already closed.    |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let storeObserver = (devices: Array<string>) => {
  if (devices != undefined) {
    for (let i = 0; i < devices.length; i++) {
      console.info(`device= ${devices[i]} data changed`);
    }
  }
};

try {
  if (store != undefined) {
    // 此处不能使用Lambda表达式
    (store as relationalStore.RdbStore).on('dataChange', relationalStore.SubscribeType.SUBSCRIBE_TYPE_REMOTE, storeObserver);
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`Register observer failed, code is ${code},message is ${message}`);
}

try {
  if (store != undefined) {
    (store as relationalStore.RdbStore).off('dataChange', relationalStore.SubscribeType.SUBSCRIBE_TYPE_REMOTE, storeObserver);
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`Unregister observer failed, code is ${code},message is ${message}`);
}
```

### off('dataChange')<sup>10+</sup>

off(event:'dataChange', type: SubscribeType, observer?: Callback&lt;Array&lt;string&gt;&gt;\| Callback&lt;Array&lt;ChangeInfo&gt;&gt;): void

取消数据变更的事件监听。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型                                | 必填 | 说明                                        |
| -------- | ---------------------------------- | ---- | ------------------------------------------ |
| event    | string                              | 是   | 取值为'dataChange'，表示数据更改。          |
| type     | [SubscribeType](#subscribetype)     | 是   | 订阅类型。                                 |
| observer | Callback&lt;Array&lt;string&gt;&gt;\| Callback&lt;Array&lt;[ChangeInfo](#changeinfo10)&gt;&gt; | 否 | 回调函数。<br/>当type为SUBSCRIBE_TYPE_REMOTE，observer类型需为Callback&lt;Array&lt;string&gt;&gt;，其中Array&lt;string&gt;为数据库中的数据发生改变的对端设备ID。<br/> 当type为SUBSCRIBE_TYPE_CLOUD，observer类型需为Callback&lt;Array&lt;string&gt;&gt;，其中Array&lt;string&gt;为数据库中的数据发生改变的云端账号。<br/> 当type为SUBSCRIBE_TYPE_CLOUD_DETAILS，observer类型需为Callback&lt;Array&lt;ChangeInfo&gt;&gt;，其中Array&lt;ChangeInfo&gt;为数据库端云同步过程的详情。<br>当type为SUBSCRIBE_TYPE_LOCAL_DETAILS，observer类型需为Callback&lt;Array&lt;ChangeInfo&gt;&gt;，其中Array&lt;ChangeInfo&gt;为本地数据库中的数据更改的详情。<br> 当observer没有传入时，表示取消当前type类型下所有数据变更的事件监听。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**        |
|-----------|-------------|
| 202       | Permission verification failed, application which is not a system application uses system API. |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported. |
| 14800014  | Already closed.    |

**示例：**

```ts
import { distributedDeviceManager } from '@kit.DistributedServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

let storeObserver = (devices: Array<string>) => {
  if (devices != undefined) {
    for (let i = 0; i < devices.length; i++) {
      console.info(`device= ${devices[i]} data changed`);
    }
  }
};

try {
  if (store != undefined) {
    (store as relationalStore.RdbStore).on('dataChange', relationalStore.SubscribeType.SUBSCRIBE_TYPE_REMOTE, storeObserver);
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`Register observer failed, code is ${code},message is ${message}`);
}

try {
  if (store != undefined) {
    (store as relationalStore.RdbStore).off('dataChange', relationalStore.SubscribeType.SUBSCRIBE_TYPE_REMOTE, storeObserver);
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`Unregister observer failed, code is ${code},message is ${message}`);
}
```

### off<sup>10+</sup>

off(event: string, interProcess: boolean, observer?: Callback\<void>): void

取消数据变更的事件监听。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名       | 类型            | 必填 | 说明                                                         |
| ------------ | --------------- | ---- | ------------------------------------------------------------ |
| event        | string          | 是   | 取消订阅事件名称。事件名称与on接口调用时订阅事件的名称一致。 |
| interProcess | boolean         | 是   | 指定是进程间还是本进程取消订阅。<br/> true：进程间。<br/> false：本进程。 |
| observer     | Callback\<void> | 否   | 该参数存在，则取消指定Callback监听回调，否则取消该event事件的所有监听回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                           |
| ------------ | -------------------------------------- |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported. |
| 14800000     | Inner error.                           |
| 14800014  | Already closed.    |
| 14800050     | Failed to obtain the subscription service. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let storeObserver = () => {
  console.info(`storeObserver`);
};

try {
  if (store != undefined) {
    (store as relationalStore.RdbStore).on('storeObserver', false, storeObserver);
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`Register observer failed, code is ${code},message is ${message}`);
}

try {
  if (store != undefined) {
    (store as relationalStore.RdbStore).off('storeObserver', false, storeObserver);
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`Unregister observer failed, code is ${code},message is ${message}`);
}
```

### off('autoSyncProgress')<sup>11+</sup>

off(event: 'autoSyncProgress', progress?: Callback&lt;ProgressDetails&gt;): void

取消订阅自动同步进度的通知。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名       | 类型                              | 必填 | 说明                                                               |
| ------------ |---------------------------------| ---- |------------------------------------------------------------------|
| event        | string                          | 是   | 取值为'autoSyncProgress'，表示自动同步进度通知。                                |
| progress     | Callback&lt;[ProgressDetails](#progressdetails10)&gt; | 否   | 指已注册的自动同步进度观察者。该参数存在，则取消订阅指定回调，该参数为null或undefined或不存在，则取消订阅所有回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**         |
| ------------ |--------------------|
| 401       | Parameter error. Possible causes: 1. Need 1 - 3  parameter(s)! 2. The RdbStore must be valid. 3. The event must be a not empty string. 4. The progress must be function. |
| 801       | Capability not supported.  |
| 14800014  | Already closed.       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let progressDetail = (progressDetail: relationalStore.ProgressDetails) => {
  console.info(`progress: ${progressDetail}`);
};

try {
  if (store != undefined) {
    (store as relationalStore.RdbStore).on('autoSyncProgress', progressDetail);
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`Register observer failed, code is ${code},message is ${message}`);
}

try {
  if (store != undefined) {
    (store as relationalStore.RdbStore).off('autoSyncProgress', progressDetail);
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`Unregister failed, code is ${code},message is ${message}`);
}
```

### off('statistics')<sup>12+</sup>

off(event: 'statistics', observer?: Callback&lt;SqlExecutionInfo&gt;): void

取消订阅SQL统计信息。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名       | 类型                              | 必填 | 说明                                |
| ------------ |---------------------------------| ---- |-----------------------------------|
| event        | string                          | 是   | 取消订阅事件名称。取值为'statistics'，表示sql执行时间的统计。 |
| observer     | Callback&lt;[SqlExecutionInfo](#sqlexecutioninfo12)&gt; | 否   | 回调函数。该参数存在，则取消指定Callback监听回调，否则取消该event事件的所有监听回调。  |


**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**    |
|-----------|--------|
| 401       | Parameter error.  |
| 801       | Capability not supported.  |
| 14800000  | Inner error.  |
| 14800014  | Already closed.     |

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  if (store != undefined) {
    (store as relationalStore.RdbStore).off('statistics');
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`Unregister observer failed, code is ${code},message is ${message}`);
}
```

### emit<sup>10+</sup>

emit(event: string): void

通知通过[on](#on10)注册的进程间或者进程内监听事件。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| event  | string | 是   | 通知订阅事件的名称，可自定义事件名称，不能与系统已有事件[dataChange](#ondatachange)，[autoSyncProgress](#onautosyncprogress11)，[statistics](#onstatistics12)名称重复。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                                                                                      |
| --------- |---------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported.     |
| 14800000  | Inner error.   |
| 14800014  | Already closed.     |
| 14800050  | Failed to obtain the subscription service.    |


**示例：**

```ts
if (store != undefined) {
  (store as relationalStore.RdbStore).emit('storeObserver');
}
```

### cleanDirtyData<sup>11+</sup>

cleanDirtyData(table: string, cursor: number, callback: AsyncCallback&lt;void&gt;): void

清理云端删除的数据同步到本地后，未自动清理的，且数据的游标（cursor）小于指定游标的数据。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                                               |
| -------- | ----------------------------------------------------- | ---- | -------------------------------------------------- |
| table     | string                        | 是   | 表示当前数据库的表的名称。                             |
| cursor    | number                        | 是   | 整数类型，表示数据游标，小于此游标的脏数据将被清理。     |
| callback  | AsyncCallback&lt;void&gt;     | 是   | 指定的callback回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**     |
|-----------|---------------|
| 401       | Parameter error. Possible causes: 1. Need 1 - 3  parameter(s)! 2. The RdbStore must be not nullptr. 3. The tablesNames must be not empty string. 4. The cursor must be valid cursor. |
| 801       | Capability not supported. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |

**示例：**

```ts
if (store != undefined) {
  (store as relationalStore.RdbStore).cleanDirtyData('test_table', 100, (err) => {
    if (err) {
      console.error(`clean dirty data failed, code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info('clean dirty data succeeded');
  });
}
```

### cleanDirtyData<sup>11+</sup>

cleanDirtyData(table: string, callback: AsyncCallback&lt;void&gt;): void

清理云端删除的数据同步到本地后，未自动清理的所有数据。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                                               |
| -------- | ----------------------------------------------------- | ---- | -------------------------------------------------- |
| table     | string                        | 是   | 表示当前数据库的表的名称。 |
| callback  | AsyncCallback&lt;void&gt;     | 是   | 指定的callback回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**       |
|-----------|---------|
| 401       | Parameter error. Possible causes: 1. Need 1 - 3  parameter(s). 2. The RdbStore must be not nullptr. 3. The tablesNames must be not empty string. |
| 801       | Capability not supported.    |
| 14800000  | Inner error.        |
| 14800011  | Database corrupted.   |
| 14800014  | Already closed.       |
| 14800015  | The database does not respond.      |
| 14800021  | SQLite: Generic error.     |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied.           |
| 14800024  | SQLite: The database file is locked.        |
| 14800025  | SQLite: A table in the database is locked.  |
| 14800026  | SQLite: The database is out of memory.      |
| 14800027  | SQLite: Attempt to write a readonly database.   |
| 14800028  | SQLite: Some kind of disk I/O error occurred.  |
| 14800029  | SQLite: The database is full.                |
| 14800030  | SQLite: Unable to open the database file.            |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit.             |
| 14800032  | SQLite: Abort due to constraint violation.   |
| 14800033  | SQLite: Data type mismatch.                  |
| 14800034  | SQLite: Library used incorrectly.          |

**示例：**

```ts
if (store != undefined) {
  (store as relationalStore.RdbStore).cleanDirtyData('test_table', (err) => {
    if (err) {
      console.error(`clean dirty data failed, code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info('clean dirty data succeeded');
  });
}
```

### cleanDirtyData<sup>11+</sup>

cleanDirtyData(table: string, cursor?: number): Promise&lt;void&gt;

清理云端删除的数据同步到本地后，未自动清理的，且数据的游标（cursor）小于指定游标的数据。若无cursor参数，将全部清理。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                                               |
| -------- | ----------------------------------------------------- | ---- | -------------------------------------------------- |
| table     | string           | 是   | 表示当前数据库的表的名称。           |
| cursor    | number           | 否   | 整数类型，表示数据游标，小于此游标的脏数据将被清理。当此参数不填时，清理当前表的所有脏数据。 |

**返回值：**
| 参数名    | 说明                                               |
| -------- | ------------------------------------------------- |
| Promise\<void> | 无返回结果的Promise对象。        |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                                                                                                                                      |
|-----------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Need 1 - 3  parameter(s)! 2. The RdbStore must be not nullptr. 3. The tablesNames must be not empty string. 4. The cursor must be valid cursor. |
| 801       | Capability not supported. |
| 14800000  | Inner error.            |
| 14800011  | Database corrupted.   |
| 14800014  | Already closed. |
| 14800015  | The database does not respond.   |
| 14800021  | SQLite: Generic error.   |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied.          |
| 14800024  | SQLite: The database file is locked.      |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory.   |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full.   |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if (store != undefined) {
  (store as relationalStore.RdbStore).cleanDirtyData('test_table', 100).then(() => {
    console.info('clean dirty data  succeeded');
  }).catch((err: BusinessError) => {
    console.error(`clean dirty data failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### attach<sup>12+</sup>

attach(fullPath: string, attachName: string, waitTime?: number) : Promise&lt;number&gt;

将一个数据库文件附加到当前数据库中，以便在SQL语句中可以直接访问附加数据库中的数据。

数据库文件来自文件，且此API不支持附加加密数据库。调用attach接口后，数据库切换为非WAL模式，性能会存在一定的劣化。

attach的时候，数据库会切换为非WAL模式，切换模式需要确保所有的ResultSet都已经Close，所有的写操作已经结束，否则会报错14800015。

attach不能并发调用，可能出现未响应情况，报错14800015，需要重试。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名        | 类型     | 必填  | 说明           |
| ----------- | ------ | --- | ------------ |
| fullPath | string | 是   | 表示要附加的数据库的路径。 |
| attachName | string | 是   | 表示附加后的数据库的别名。 |
| waitTime | number | 否   | 表示附加数据库文件的等待时长。默认值2s，最小值1s，最大值300s。 |

**返回值：**

| 类型              | 说明                           |
| ---------------- | ---------------------------- |
|  Promise&lt;number&gt; | Promise对象。返回附加数据库的数量。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported. |
| 14800000  | Inner error. |
| 14800010  | Invalid database path.               |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond.                 |
| 14800016  | The database alias already exists.                |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |

**示例：**

```ts
// 非加密数据库附加非加密数据库。
import { BusinessError } from '@kit.BasicServicesKit';

if (store != undefined) {
  (store as relationalStore.RdbStore).attach("/path/rdbstore1.db", "attachDB").then((number: number) => {
    console.info('attach succeeded');
  }).catch((err: BusinessError) => {
    console.error(`attach failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### attach<sup>12+</sup>

attach(context: Context, config: StoreConfig, attachName: string, waitTime?: number) : Promise&lt;number&gt;

将一个当前应用的数据库附加到当前数据库中，以便在SQL语句中可以直接访问附加数据库中的数据。

此API不支持加密数据库附加非加密数据库的场景。调用attach接口后，数据库切换为非WAL模式，性能会存在一定的劣化。

attach的时候，数据库会切换为非WAL模式，切换模式需要确保所有的ResultSet都已经Close，所有的写操作已经结束，否则会报错14800015。

attach不能并发调用，可能出现未响应情况，报错14800015，需要重试。除此之外，attach附加加密数据库时，可能受到并发的影响，出现解密失败的情况，报错14800011，需要显式指定加密参数并重试。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名        | 类型     | 必填  | 说明           |
| ----------- | ------ | --- | ------------ |
| context | Context                          | 是   | 应用的上下文。<br>FA模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-app-context.md)。<br>Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md)。 |
| config  | [StoreConfig](#storeconfig) | 是   | 与此RDB存储相关的数据库配置。                                |
| attachName | string | 是   | 表示附加后的数据库的别名。 |
| waitTime | number | 否   | 表示附加数据库文件的等待时长。默认值2s，最小值1s，最大值300s。 |

**返回值：**

| 类型              | 说明                           |
| ---------------- | ---------------------------- |
|  Promise&lt;number&gt; | Promise对象。返回附加数据库的数量。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported. |
| 14800000  | Inner error. |
| 14800010  | Invalid database path.               |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond.                 |
| 14800016  | The database alias already exists.                |
| 14801001  | The operation is supported in the stage model only.                 |
| 14801002  | Invalid data group ID.                |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |

**示例1：非加密数据库附加非加密数据库**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let attachStore: relationalStore.RdbStore | undefined = undefined;

const STORE_CONFIG1: relationalStore.StoreConfig = {
  name: "rdbstore1.db",
  securityLevel: relationalStore.SecurityLevel.S3,
};

relationalStore.getRdbStore(this.context, STORE_CONFIG1).then(async (rdbStore: relationalStore.RdbStore) => {
  attachStore = rdbStore;
  console.info('Get RdbStore successfully.');
}).catch((err: BusinessError) => {
  console.error(`Get RdbStore failed, code is ${err.code},message is ${err.message}`);
});

if (store != undefined) {
  (store as relationalStore.RdbStore).attach(this.context, STORE_CONFIG1, "attachDB").then((number: number) => {
    console.info(`attach succeeded, number is ${number}`);
  }).catch((err: BusinessError) => {
    console.error(`attach failed, code is ${err.code},message is ${err.message}`);
  });
}
```

**示例2：非加密数据库附加加密数据库**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let attachStore: relationalStore.RdbStore | undefined = undefined;

const STORE_CONFIG2: relationalStore.StoreConfig = {
  name: "rdbstore2.db",
  encrypt: true,
  securityLevel: relationalStore.SecurityLevel.S3,
};

relationalStore.getRdbStore(this.context, STORE_CONFIG2).then(async (rdbStore: relationalStore.RdbStore) => {
  attachStore = rdbStore;
  console.info('Get RdbStore successfully.');
}).catch((err: BusinessError) => {
  console.error(`Get RdbStore failed, code is ${err.code},message is ${err.message}`);
});

if (store != undefined) {
  (store as relationalStore.RdbStore).attach(this.context, STORE_CONFIG2, "attachDB2", 10).then((number: number) => {
    console.info(`attach succeeded, number is ${number}`);
  }).catch((err: BusinessError) => {
    console.error(`attach failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### detach<sup>12+</sup>

detach(attachName: string, waitTime?: number) : Promise&lt;number&gt;

将附加的数据库从当前数据库中分离。

当所有的附加的数据库被分离后，数据库会重新切换为WAL模式。

在detach之前，所有的数据库操作要确保已经结束，所有的ResultSet已经Close。并且不能并发调用，可能出现未响应情况，需要重试。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名        | 类型     | 必填  | 说明           |
| ----------- | ------ | --- | ------------ |
| attachName | string | 是   | 表示附加后的数据库的别名。 |
| waitTime | number | 否   | 表示分离数据库的等待时长。默认值2s，最小值1s，最大值300s。 |

**返回值：**

| 类型              | 说明                           |
| ---------------- | ---------------------------- |
|  Promise&lt;number&gt; | Promise对象。返回分离后剩余附加的数据库的数量。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**       |
|-----------|------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error.            |
| 14800011  | Database corrupted.         |
| 14800014  | Already closed.        |
| 14800015  | The database does not respond.         |
| 14800021  | SQLite: Generic error.            |
| 14800022  | SQLite: Callback routine requested an abort.       |
| 14800023  | SQLite: Access permission denied.           |
| 14800024  | SQLite: The database file is locked.        |
| 14800025  | SQLite: A table in the database is locked.       |
| 14800026  | SQLite: The database is out of memory.     |
| 14800027  | SQLite: Attempt to write a readonly database.        |
| 14800028  | SQLite: Some kind of disk I/O error occurred.    |
| 14800029  | SQLite: The database is full.      |
| 14800030  | SQLite: Unable to open the database file.       |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit.      |
| 14800032  | SQLite: Abort due to constraint violation.    |
| 14800033  | SQLite: Data type mismatch.       |
| 14800034  | SQLite: Library used incorrectly.       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if (store != undefined) {
  (store as relationalStore.RdbStore).detach("attachDB").then((number: number) => {
    console.info(`detach succeeded, number is ${number}`);
  }).catch((err: BusinessError) => {
    console.error(`detach failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### lockRow<sup>12+</sup>

lockRow(predicates: RdbPredicates):Promise&lt;void&gt;

根据RdbPredicates的指定实例对象从数据库中锁定数据，锁定数据不执行端云同步，使用Promise异步回调。

该接口只支持主键为基本类型的表、不支持共享表、无主键表和复合类型主键表。
该接口不支持依赖关系表之间的锁传递，如果表存在依赖关系，需要根据依赖关系手动调用该接口。
该接口不支持对已删除数据的操作。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名     | 类型                                 | 必填 | 说明                                      |
| ---------- | ------------------------------------ | ---- | ----------------------------------------- |
| predicates | [RdbPredicates](#rdbpredicates) | 是   | RdbPredicates的实例对象指定的锁定条件。 |

**返回值**：

| 类型                  | 说明                            |
| --------------------- | ------------------------------- |
| Promise&lt;void&gt;   | 无返回结果的Promise对象。        |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                                                     |
|-----------|----------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error.                                                                                 |
| 14800011  | Database corrupted.                                                                          |
| 14800014  | Already closed.                                                                              |
| 14800015  | The database does not respond.                                                                        |
| 14800018  | No data meets the condition.                                                                 |
| 14800021  | SQLite: Generic error.                                                                       |
| 14800022  | SQLite: Callback routine requested an abort.                                                 |
| 14800023  | SQLite: Access permission denied.                                                            |
| 14800024  | SQLite: The database file is locked.                                                         |
| 14800025  | SQLite: A table in the database is locked.                                                   |
| 14800026  | SQLite: The database is out of memory.                                                       |
| 14800027  | SQLite: Attempt to write a readonly database.                                                |
| 14800028  | SQLite: Some kind of disk I/O error occurred.                                                |
| 14800029  | SQLite: The database is full.                                                                |
| 14800030  | SQLite: Unable to open the database file.                                                    |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit.                                                     |
| 14800032  | SQLite: Abort due to constraint violation.                                                   |
| 14800033  | SQLite: Data type mismatch.                                                                  |
| 14800034  | SQLite: Library used incorrectly.                                                            |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Lisa");
if (store != undefined) {
  (store as relationalStore.RdbStore).lockRow(predicates).then(() => {
    console.info(`Lock success`);
  }).catch((err: BusinessError) => {
    console.error(`Lock failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### unlockRow<sup>12+</sup>

unlockRow(predicates: RdbPredicates):Promise&lt;void&gt;

根据RdbPredicates的指定实例对象从数据库中解锁数据，使用Promise异步回调。

该接口只支持主键为基本类型的表、不支持共享表、无主键表和复合类型主键表。
该接口不支持依赖关系表之间的锁传递，如果表存在依赖关系，需要根据依赖关系手动调用该接口。
该接口不支持对已删除数据的操作。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名     | 类型                                 | 必填 | 说明                                      |
| ---------- | ------------------------------------ | ---- | ----------------------------------------- |
| predicates | [RdbPredicates](#rdbpredicates) | 是   | RdbPredicates的实例对象指定的锁定条件。 |

**返回值**：

| 类型                  | 说明                            |
| --------------------- | ------------------------------- |
| Promise&lt;void&gt;   | 无返回结果的Promise对象。        |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond.                 |
| 14800018  | No data meets the condition.                |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Lisa");
if (store != undefined) {
  (store as relationalStore.RdbStore).unlockRow(predicates).then(() => {
    console.info(`Unlock success`);
  }).catch((err: BusinessError) => {
    console.error(`Unlock failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### queryLockedRow<sup>12+</sup>

queryLockedRow(predicates: RdbPredicates, columns?: Array&lt;string&gt;):Promise&lt;ResultSet&gt;

根据指定条件查询数据库中锁定的数据，使用Promise异步回调。
由于共享内存大小限制为2Mb，因此单条数据的大小需小于2Mb，否则会查询失败。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名     | 类型                                 | 必填 | 说明                                             |
| ---------- | ------------------------------------ | ---- | ------------------------------------------------ |
| predicates | [RdbPredicates](#rdbpredicates) | 是   | RdbPredicates的实例对象指定的查询条件。        |
| columns    | Array&lt;string&gt;                  | 否   | 表示要查询的列。如果值为空，则查询应用于所有列。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond.                 |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |

**返回值**：

| 类型                                                    | 说明                                               |
| ------------------------------------------------------- | -------------------------------------------------- |
| Promise&lt;[ResultSet](#resultset)&gt; | Promise对象。如果操作成功，则返回ResultSet对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Rose");
if (store != undefined) {
  (store as relationalStore.RdbStore).queryLockedRow(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"]).then((resultSet: relationalStore.ResultSet) => {
    console.info(`ResultSet column names: ${resultSet.columnNames}, column count: ${resultSet.columnCount}`);
    // resultSet是一个数据集合的游标，默认指向第-1个记录，有效的数据从0开始。
    while (resultSet.goToNextRow()) {
      const id = resultSet.getLong(resultSet.getColumnIndex("ID"));
      const name = resultSet.getString(resultSet.getColumnIndex("NAME"));
      const age = resultSet.getLong(resultSet.getColumnIndex("AGE"));
      const salary = resultSet.getDouble(resultSet.getColumnIndex("SALARY"));
      console.info(`id=${id}, name=${name}, age=${age}, salary=${salary}`);
    }
    // 释放数据集的内存，若不释放可能会引起fd泄露与内存泄露
    resultSet.close();
  }).catch((err: BusinessError) => {
    console.error(`Query failed, code is ${err.code},message is ${err.message}`);
  });
}
```
### close<sup>12+</sup>

close(): Promise&lt;void&gt;

关闭数据库，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**返回值：**

| 类型                | 说明          |
| ------------------- | ------------- |
| Promise&lt;void&gt; | Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                    |
| ------------ | ----------------------------------------------- |
| 401          | Parameter error. The store must not be nullptr. |
| 14800000     | Inner error.                                    |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if (store != undefined) {
  (store as relationalStore.RdbStore).close().then(() => {
    console.info(`close succeeded`);
  }).catch((err: BusinessError) => {
    console.error(`close failed, code is ${err.code},message is ${err.message}`);
  });
}
```

## ResultSet

提供通过查询数据库生成的数据库结果集的访问方法。结果集是指用户调用关系型数据库查询接口之后返回的结果集合，提供了多种灵活的数据访问方式，以便用户获取各项数据。

### 使用说明

首先需要获取resultSet对象。

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

let store: relationalStore.RdbStore | undefined = undefined;

class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    const STORE_CONFIG: relationalStore.StoreConfig = {
      name: "RdbTest.db",
      securityLevel: relationalStore.SecurityLevel.S3,
    };

    relationalStore.getRdbStore(this.context, STORE_CONFIG).then(async (rdbStore: relationalStore.RdbStore) => {
      store = rdbStore;
      const asset: relationalStore.Asset = {
        name: "name",
        uri: "uri",
        createTime: "createTime",
        modifyTime: "modifyTime",
        size: "size",
        path: "path",
      };
      const assets: relationalStore.Assets = [asset];
      const valueBucket: relationalStore.ValuesBucket = {
        "NAME": "hello world",
        "AGE": 3,
        "SALARY": 0.5,
        "CODES": new Uint8Array([1, 2, 3]),
        "IDENTITY": 100n,
        "ASSETDATA": asset,
        "ASSETSDATA": assets,
        "FLOATARRAY": new Float32Array([1.5, 2.5]),
      };
      (store as relationalStore.RdbStore).insertSync("EMPLOYEE", valueBucket);
      let resultSet: relationalStore.ResultSet | undefined = undefined;
      let predicates: relationalStore.RdbPredicates = new relationalStore.RdbPredicates("EMPLOYEE");
      let columns: Array<string> = ["ID", "NAME", "AGE", "SALARY", "CODES", "IDENTITY", "ASSETDATA", "ASSETSDATA", "FLOATARRAY"];
      await (store as relationalStore.RdbStore).query(predicates, columns).then(async (result: relationalStore.ResultSet) => {
        resultSet = result;
        console.info(`resultSet columnNames: ${resultSet.columnNames}`);
        console.info(`resultSet columnCount: ${resultSet.columnCount}`);
      });
      console.info('Get RdbStore successfully.');
    }).catch((err: BusinessError) => {
      console.error(`Get RdbStore failed, code is ${err.code},message is ${err.message}`);
    });
  }
}
```

### 属性

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 名称         | 类型            | 必填 | 说明                             |
| ------------ | ------------------- | ---- | -------------------------------- |
| columnNames  | Array&lt;string&gt; | 是   | 获取结果集中所有列的名称。       |
| columnCount  | number              | 是   | 获取结果集中列的数量。             |
| rowCount     | number              | 是   | 获取结果集中行的数量。             |
| rowIndex     | number              | 是   | 获取结果集当前行的索引位置，默认值为-1。索引位置下标从0开始。 |
| isAtFirstRow | boolean             | 是   | 检查结果集指针是否位于第一行（行索引为0），true表示位于第一行，false表示不位于第一行。 |
| isAtLastRow  | boolean             | 是   | 检查结果集指针是否位于最后一行，true表示位于最后一行，false表示不位于最后一行。 |
| isEnded      | boolean             | 是   | 检查结果集指针是否位于最后一行之后，true表示位于最后一行之后，false表示不位于最后一行之后。 |
| isStarted    | boolean             | 是   | 检查指针是否移动过，true表示指针已移动过，false表示指针未移动过。             |
| isClosed     | boolean             | 是   | 检查当前结果集是否关闭，true表示结果集已关闭，false表示结果集未关闭。         |

### getColumnIndex

getColumnIndex(columnName: string): number

根据指定的列名获取列索引。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明                       |
| ---------- | ------ | ---- | -------------------------- |
| columnName | string | 是   | 表示结果集中指定列的名称。 |

**返回值：**

| 类型   | 说明               |
| ------ | ------------------ |
| number | 返回指定列的索引。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800013  | Column out of bounds. |
| 14800014  | Already closed. |
| 14800019  | The SQL must be a query statement. |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |

**示例：**

```ts
if (resultSet != undefined) {
  const id = (resultSet as relationalStore.ResultSet).getLong((resultSet as relationalStore.ResultSet).getColumnIndex("ID"));
  const name = (resultSet as relationalStore.ResultSet).getString((resultSet as relationalStore.ResultSet).getColumnIndex("NAME"));
  const age = (resultSet as relationalStore.ResultSet).getLong((resultSet as relationalStore.ResultSet).getColumnIndex("AGE"));
  const salary = (resultSet as relationalStore.ResultSet).getDouble((resultSet as relationalStore.ResultSet).getColumnIndex("SALARY"));
}
```

### getColumnName

getColumnName(columnIndex: number): string

根据指定的列索引获取列名。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名      | 类型   | 必填 | 说明                       |
| ----------- | ------ | ---- | -------------------------- |
| columnIndex | number | 是   | 表示结果集中指定列的索引。 |

**返回值：**

| 类型   | 说明               |
| ------ | ------------------ |
| string | 返回指定列的名称。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800013  | Column out of bounds. |
| 14800014  | Already closed. |
| 14800019  | The SQL must be a query statement. |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |

**示例：**

```ts
if (resultSet != undefined) {
  const id = (resultSet as relationalStore.ResultSet).getColumnName(0);
  const name = (resultSet as relationalStore.ResultSet).getColumnName(1);
  const age = (resultSet as relationalStore.ResultSet).getColumnName(2);
}
```

### getColumnType<sup>18+</sup>

getColumnType(columnIdentifier: number | string): Promise\<ColumnType>

根据指定的列索引或列名称获取列数据类型，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名           | 类型             | 必填 | 说明                                                         |
| ---------------- | ---------------- | ---- | ------------------------------------------------------------ |
| columnIdentifier | number \| string | 是   | 表示结果集中指定列的索引或名称。索引必须是非负整数，最大不能超过属性columnNames的长度。列名必须是属性columnNames内的名称。 |

**返回值：**

| 类型                                 | 说明                                |
| ------------------------------------ | ----------------------------------- |
| Promise<[ColumnType](#columntype18)> | Promise对象。返回指定列的数据类型。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000     | Inner error.                                                 |
| 14800011     | Database corrupted.                                          |
| 14800012     | Row out of bounds.                                           |
| 14800013     | Column out of bounds.                                        |
| 14800014     | Already closed.                                              |
| 14800019     | The SQL must be a query statement.                           |
| 14800021     | SQLite: Generic error.                                       |
| 14800022     | SQLite: Callback routine requested an abort.                 |
| 14800023     | SQLite: Access permission denied.                            |
| 14800024     | SQLite: The database file is locked.                         |
| 14800025     | SQLite: A table in the database is locked.                   |
| 14800026     | SQLite: The database is out of memory.                       |
| 14800027     | SQLite: Attempt to write a readonly database.                |
| 14800028     | SQLite: Some kind of disk I/O error occurred.                |
| 14800029     | SQLite: The database is full.                                |
| 14800030     | SQLite: Unable to open the database file.                    |
| 14800031     | SQLite: TEXT or BLOB exceeds size limit.                     |
| 14800032     | SQLite: Abort due to constraint violation.                   |
| 14800033     | SQLite: Data type mismatch.                                  |
| 14800034     | SQLite: Library used incorrectly.                            |

**示例：**

```ts
if (resultSet != undefined) {
  let idType = await (resultSet as relationalStore.ResultSet).getColumnType("ID") as relationalStore.ColumnType;
  let nameType = await (resultSet as relationalStore.ResultSet).getColumnType("NAME") as relationalStore.ColumnType;
  let ageType = await (resultSet as relationalStore.ResultSet).getColumnType("AGE") as relationalStore.ColumnType;
  let salaryType = await (resultSet as relationalStore.ResultSet).getColumnType("SALARY") as relationalStore.ColumnType;
  let codesType = await (resultSet as relationalStore.ResultSet).getColumnType("CODES") as relationalStore.ColumnType;
  let identityType = await (resultSet as relationalStore.ResultSet).getColumnType(5) as relationalStore.ColumnType;
  let assetDataType = await (resultSet as relationalStore.ResultSet).getColumnType(6) as relationalStore.ColumnType;
  let assetsDataType = await (resultSet as relationalStore.ResultSet).getColumnType(7) as relationalStore.ColumnType;
  let floatArrayType = await (resultSet as relationalStore.ResultSet).getColumnType(8) as relationalStore.ColumnType;
}
```

### getColumnTypeSync<sup>18+</sup>

getColumnTypeSync(columnIdentifier: number | string): ColumnType

根据指定的列索引或列名称获取列数据类型。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core 

**参数：**

| 参数名           | 类型             | 必填 | 说明                                                         |
| ---------------- | ---------------- | ---- | ------------------------------------------------------------ |
| columnIdentifier | number \| string | 是   | 表示结果集中指定列的索引或名称。索引必须是非负整数，最大不能超过属性columnNames的长度。列名必须是属性columnNames内的名称。 |

**返回值：**

| 类型                        | 说明                   |
| --------------------------- | ---------------------- |
| [ColumnType](#columntype18) | 返回指定列的数据类型。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000     | Inner error.                                                 |
| 14800011     | Database corrupted.                                          |
| 14800012     | Row out of bounds.                                           |
| 14800013     | Column out of bounds.                                        |
| 14800014     | Already closed.                                              |
| 14800019     | The SQL must be a query statement.                           |
| 14800021     | SQLite: Generic error.                                       |
| 14800022     | SQLite: Callback routine requested an abort.                 |
| 14800023     | SQLite: Access permission denied.                            |
| 14800024     | SQLite: The database file is locked.                         |
| 14800025     | SQLite: A table in the database is locked.                   |
| 14800026     | SQLite: The database is out of memory.                       |
| 14800027     | SQLite: Attempt to write a readonly database.                |
| 14800028     | SQLite: Some kind of disk I/O error occurred.                |
| 14800029     | SQLite: The database is full.                                |
| 14800030     | SQLite: Unable to open the database file.                    |
| 14800031     | SQLite: TEXT or BLOB exceeds size limit.                     |
| 14800032     | SQLite: Abort due to constraint violation.                   |
| 14800033     | SQLite: Data type mismatch.                                  |
| 14800034     | SQLite: Library used incorrectly.                            |

**示例：**

```ts
if (resultSet != undefined) {
  let idType = (resultSet as relationalStore.ResultSet).getColumnTypeSync("ID") as relationalStore.ColumnType;
  let nameType = (resultSet as relationalStore.ResultSet).getColumnTypeSync("NAME") as relationalStore.ColumnType;
  let ageType = (resultSet as relationalStore.ResultSet).getColumnTypeSync("AGE") as relationalStore.ColumnType;
  let salaryType = (resultSet as relationalStore.ResultSet).getColumnTypeSync("SALARY") as relationalStore.ColumnType;
  let codesType = (resultSet as relationalStore.ResultSet).getColumnTypeSync("CODES") as relationalStore.ColumnType;
  let identityType = (resultSet as relationalStore.ResultSet).getColumnTypeSync(5) as relationalStore.ColumnType;
  let assetDataType = (resultSet as relationalStore.ResultSet).getColumnTypeSync(6) as relationalStore.ColumnType;
  let assetsDataType = (resultSet as relationalStore.ResultSet).getColumnTypeSync(7) as relationalStore.ColumnType;
  let floatArrayType = (resultSet as relationalStore.ResultSet).getColumnTypeSync(8) as relationalStore.ColumnType;
}
```

### goTo

goTo(offset:number): boolean

指定相对当前结果集指针位置的偏移量，以移动结果集的指针位置。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                         |
| ------ | ------ | ---- | ---------------------------- |
| offset | number | 是   | 表示相对当前结果集指针位置的偏移量，正值表示向后移动，负值表示向前移动。 |

**返回值：**

| 类型    | 说明                                          |
| ------- | --------------------------------------------- |
| boolean | 如果成功移动结果集，则为true；否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800012  | Row out of bounds. |
| 14800014  | Already closed. |
| 14800019  | The SQL must be a query statement. |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |

**示例：**

```ts
if (resultSet != undefined) {
  (resultSet as relationalStore.ResultSet).goTo(1);
}
```

### goToRow

goToRow(position: number): boolean

转到结果集的指定行。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型   | 必填 | 说明                     |
| -------- | ------ | ---- | ------------------------ |
| position | number | 是   | 表示要移动到的指定位置。 |

**返回值：**

| 类型    | 说明                                          |
| ------- | --------------------------------------------- |
| boolean | 如果成功移动结果集，则为true；否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800012  | Row out of bounds. |
| 14800014  | Already closed. |
| 14800019  | The SQL must be a query statement. |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |

**示例：**

```ts
if (resultSet != undefined) {
  (resultSet as relationalStore.ResultSet).goToRow(5);
}
```

### goToFirstRow

goToFirstRow(): boolean


转到结果集的第一行。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**返回值：**

| 类型    | 说明                                          |
| ------- | --------------------------------------------- |
| boolean | 如果成功移动结果集，则为true；否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800012  | Row out of bounds. |
| 14800014  | Already closed. |
| 14800019  | The SQL must be a query statement. |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |

**示例：**

```ts
if (resultSet != undefined) {
  (resultSet as relationalStore.ResultSet).goToFirstRow();
}
```

### goToLastRow

goToLastRow(): boolean

转到结果集的最后一行。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**返回值：**

| 类型    | 说明                                          |
| ------- | --------------------------------------------- |
| boolean | 如果成功移动结果集，则为true；否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800012  | Row out of bounds. |
| 14800014  | Already closed. |
| 14800019  | The SQL must be a query statement. |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |

**示例：**

```ts
if (resultSet != undefined) {
  (resultSet as relationalStore.ResultSet).goToLastRow();
}
```

### goToNextRow

goToNextRow(): boolean

转到结果集的下一行。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**返回值：**

| 类型    | 说明                                          |
| ------- | --------------------------------------------- |
| boolean | 如果成功移动结果集，则为true；否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800012  | Row out of bounds. |
| 14800014  | Already closed. |
| 14800019  | The SQL must be a query statement. |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |

**示例：**

```ts
if (resultSet != undefined) {
  (resultSet as relationalStore.ResultSet).goToNextRow();
}
```

### goToPreviousRow

goToPreviousRow(): boolean

转到结果集的上一行。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**返回值：**

| 类型    | 说明                                          |
| ------- | --------------------------------------------- |
| boolean | 如果成功移动结果集，则为true；否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800012  | Row out of bounds. |
| 14800014  | Already closed. |
| 14800019  | The SQL must be a query statement. |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |

**示例：**

```ts
if (resultSet != undefined) {
  (resultSet as relationalStore.ResultSet).goToPreviousRow();
}
```

### getValue<sup>12+</sup>

getValue(columnIndex: number): ValueType

获取当前行中指定列的值，值类型如果是ValueType指定的任意类型，则会以对应类型返回指定类的值，否则返回14800000。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名      | 类型   | 必填 | 说明                    |
| ----------- | ------ | ---- | ----------------------- |
| columnIndex | number | 是   | 指定的列索引，从0开始。 |

**返回值：**

| 类型       | 说明                             |
| ---------- | -------------------------------- |
| [ValueType](#valuetype) | 表示允许的数据字段类型。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**     |
|-----------|---------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error.      |
| 14800011  | Database corrupted.        |
| 14800012  | Row out of bounds.       |
| 14800013  | Column out of bounds.   |
| 14800014  | Already closed.       |
| 14800021  | SQLite: Generic error.    |
| 14800022  | SQLite: Callback routine requested an abort.     |
| 14800023  | SQLite: Access permission denied.    |
| 14800024  | SQLite: The database file is locked.    |
| 14800025  | SQLite: A table in the database is locked.  |
| 14800026  | SQLite: The database is out of memory.    |
| 14800027  | SQLite: Attempt to write a readonly database.    |
| 14800028  | SQLite: Some kind of disk I/O error occurred.    |
| 14800029  | SQLite: The database is full.   |
| 14800030  | SQLite: Unable to open the database file.    |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit.    |
| 14800032  | SQLite: Abort due to constraint violation.   |
| 14800033  | SQLite: Data type mismatch.      |
| 14800034  | SQLite: Library used incorrectly.    |

**示例：**

```ts
if (resultSet != undefined) {
  const codes = (resultSet as relationalStore.ResultSet).getValue((resultSet as relationalStore.ResultSet).getColumnIndex("BIGINT_COLUMN"));
}
```

### getBlob

getBlob(columnIndex: number): Uint8Array


以字节数组的形式获取当前行中指定列的值，如果当前列的数据类型为INTEGER、DOUBLE、TEXT、BLOB类型，会转成字节数组类型返回指定值，如果该列内容为空时，会返回空字节数组，其他类型则返回14800000。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名      | 类型   | 必填 | 说明                    |
| ----------- | ------ | ---- | ----------------------- |
| columnIndex | number | 是   | 指定的列索引，从0开始。 |

**返回值：**

| 类型       | 说明                             |
| ---------- | -------------------------------- |
| Uint8Array | 以字节数组的形式返回指定列的值。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800012  | Row out of bounds. |
| 14800013  | Column out of bounds. |
| 14800014  | Already closed. |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |

**示例：**

```ts
if (resultSet != undefined) {
  const codes = (resultSet as relationalStore.ResultSet).getBlob((resultSet as relationalStore.ResultSet).getColumnIndex("CODES"));
}
```

### getString

getString(columnIndex: number): string

以字符串形式获取当前行中指定列的值，如果当前列中的值为INTEGER、DOUBLE、TEXT、BLOB类型，会以字符串形式返回指定值，如果是当前列中的值为INTEGER，并且为空，则会返回空字符串""，其他类型则返回14800000。如果当前列中的值为DOUBLE类型，可能存在精度的丢失，建议使用[getDouble](#getdouble)接口获取。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名      | 类型   | 必填 | 说明                    |
| ----------- | ------ | ---- | ----------------------- |
| columnIndex | number | 是   | 指定的列索引，从0开始。 |

**返回值：**

| 类型   | 说明                         |
| ------ | ---------------------------- |
| string | 以字符串形式返回指定列的值。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800012  | Row out of bounds. |
| 14800013  | Column out of bounds. |
| 14800014  | Already closed. |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |

**示例：**

```ts
if (resultSet != undefined) {
  const name = (resultSet as relationalStore.ResultSet).getString((resultSet as relationalStore.ResultSet).getColumnIndex("NAME"));
}
```

### getLong

getLong(columnIndex: number): number

以Long形式获取当前行中指定列的值，如果当前列的数据类型为INTEGER、DOUBLE、TEXT、BLOB类型，会转成Long类型返回指定值，如果该列内容为空时，会返回0，其他类型则返回14800000。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名      | 类型   | 必填 | 说明                    |
| ----------- | ------ | ---- | ----------------------- |
| columnIndex | number | 是   | 指定的列索引，从0开始。 |

**返回值：**

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| number | 以Long形式返回指定列的值。<br>该接口支持的数据范围是：Number.MIN_SAFE_INTEGER ~ Number.MAX_SAFE_INTEGER，若超出该范围，建议使用[getDouble](#getdouble)。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800012  | Row out of bounds. |
| 14800013  | Column out of bounds. |
| 14800014  | Already closed. |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |

**示例：**

```ts
if (resultSet != undefined) {
  const age = (resultSet as relationalStore.ResultSet).getLong((resultSet as relationalStore.ResultSet).getColumnIndex("AGE"));
}
```

### getDouble

getDouble(columnIndex: number): number

以double形式获取当前行中指定列的值，如果当前列的数据类型为INTEGER、DOUBLE、TEXT、BLOB类型，会转成double类型返回指定值，如果该列内容为空时，会返回0.0，其他类型则返回14800000。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名      | 类型   | 必填 | 说明                    |
| ----------- | ------ | ---- | ----------------------- |
| columnIndex | number | 是   | 指定的列索引，从0开始。 |

**返回值：**

| 类型   | 说明                         |
| ------ | ---------------------------- |
| number | 以double形式返回指定列的值。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800012  | Row out of bounds. |
| 14800013  | Column out of bounds. |
| 14800014  | Already closed. |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |

**示例：**

```ts
if (resultSet != undefined) {
  const salary = (resultSet as relationalStore.ResultSet).getDouble((resultSet as relationalStore.ResultSet).getColumnIndex("SALARY"));
}
```

### getAsset<sup>10+</sup>

getAsset(columnIndex: number): Asset

以[Asset](#asset10)形式获取当前行中指定列的值，如果当前列的数据类型为Asset类型，会以Asset类型返回指定值，如果当前列中的值为null时，会返回null，其他类型则返回14800000。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名         | 类型     | 必填  | 说明           |
| ----------- | ------ | --- | ------------ |
| columnIndex | number | 是   | 指定的列索引，从0开始。 |

**返回值：**

| 类型              | 说明                         |
| --------------- | -------------------------- |
| [Asset](#asset10) | 以Asset形式返回指定列的值。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800012  | Row out of bounds. |
| 14800013  | Column out of bounds. |
| 14800014  | Already closed. |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |

**示例：**

```ts
if (resultSet != undefined) {
  const doc = (resultSet as relationalStore.ResultSet).getAsset((resultSet as relationalStore.ResultSet).getColumnIndex("DOC"));
}
```

### getAssets<sup>10+</sup>

getAssets(columnIndex: number): Assets

以[Assets](#assets10)形式获取当前行中指定列的值，如果当前列的数据类型为Assets类型，会以Assets类型返回指定值，如果当前列中的值为null时，会返回null，其他类型则返回14800000。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名         | 类型     | 必填  | 说明           |
| ----------- | ------ | --- | ------------ |
| columnIndex | number | 是   | 指定的列索引，从0开始。 |

**返回值：**

| 类型              | 说明                           |
| ---------------- | ---------------------------- |
| [Assets](#assets10)| 以Assets形式返回指定列的值。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800012  | Row out of bounds. |
| 14800013  | Column out of bounds. |
| 14800014  | Already closed. |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |

**示例：**

```ts
if (resultSet != undefined) {
  const docs = (resultSet as relationalStore.ResultSet).getAssets((resultSet as relationalStore.ResultSet).getColumnIndex("DOCS"));
}
```

### getRow<sup>11+</sup>

getRow(): ValuesBucket

获取当前行。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**返回值：**

| 类型              | 说明                           |
| ---------------- | ---------------------------- |
| [ValuesBucket](#valuesbucket) | 返回指定行的值。 |

**错误码：**

以下错误码的详细介绍请参见[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800012  | Row out of bounds. |
| 14800013  | Column out of bounds. |
| 14800014  | Already closed. |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |

**示例：**

```ts
if (resultSet != undefined) {
  const row = (resultSet as relationalStore.ResultSet).getRow();
}
```

### getRows<sup>18+</sup>

getRows(maxCount: number, position?: number): Promise<Array\<ValuesBucket>>

从结果集中获取指定数量的数据，使用Promise异步回调。禁止与[ResultSet](#resultset)的其它接口并发调用，否则获取的数据可能非预期。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名      | 类型   | 必填 | 说明                    |
| ----------- | ------ | ---- | ----------------------- |
| maxCount | number | 是   | 正整数，指定要从结果集中获取数据的条数。不为正整数则参数非法，抛出错误码401。 |
| position | number | 否   | 非负整数，指定从结果集中获取数据的起始位置，不填则从结果集的当前行（默认首次获取数据时为当前结果集的第一行）开始获取数据。不为非负整数则参数非法，抛出错误码401。 |


**返回值：**

| 类型              | 说明                           |
| ---------------- | ---------------------------- |
| Promise<Array<[ValuesBucket](#valuesbucket)>> | 返回maxCount条数据，剩余数据不足maxCount条则返回剩余数据，返回空数组时代表已经遍历到结果集的末尾。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800012  | Row out of bounds. |
| 14800013  | Column out of bounds. |
| 14800014  | Already closed. |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |

**示例：**

```ts
// 以查到100条数据为例
async function proccessRows(resultSet: relationalStore.ResultSet) {
  // 示例1：仅指定maxCount
  if (resultSet != undefined) {
    let rows: Array<relationalStore.ValuesBucket>;
    let maxCount: number = 50;
    // 从结果集的当前行（默认首次获取数据时为当前结果集的第一行，后续为上次获取数据结束位置的下一行）开始获取数据
    // getRows会自动移动结果集当前行到上次getRows获取结束位置的下一行，无需使用goToFirstRow、goToNextRow等接口移动
    while ((rows = await (resultSet as relationalStore.ResultSet).getRows(maxCount)).length != 0) {
      console.info(JSON.stringify(rows[0]));
    }
  }

  // 示例2：指定maxCount和起始的position
  if (resultSet != undefined) {
    let rows: Array<relationalStore.ValuesBucket>;
    let maxCount: number = 50;
    let position: number = 50;
    while ((rows = await (resultSet as relationalStore.ResultSet).getRows(maxCount, position)).length != 0) {
      console.info(JSON.stringify(rows[0]));
      position += rows.length;
    }
  }
}
```

### getSendableRow<sup>12+</sup>

getSendableRow(): sendableRelationalStore.ValuesBucket

获取当前行数据的sendable形式，用于跨线程传递使用。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**返回值：**

| 类型                                                                                           | 说明                                           |
| ---------------------------------------------------------------------------------------------- | ---------------------------------------------- |
| [sendableRelationalStore.ValuesBucket](./js-apis-data-sendableRelationalStore.md#valuesbucket) | 当前行数据的sendable形式，用于跨线程传递使用。 |

**错误码：**

以下错误码的详细介绍请参见[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                  |
| ------------ | --------------------------------------------- |
| 14800000     | Inner error.                                  |
| 14800011     | Database corrupted.                           |
| 14800012     | Row out of bounds.                            |
| 14800013     | Column out of bounds.                         |
| 14800014     | Already closed.                               |
| 14800021     | SQLite: Generic error.                        |
| 14800022     | SQLite: Callback routine requested an abort.  |
| 14800023     | SQLite: Access permission denied.             |
| 14800024     | SQLite: The database file is locked.          |
| 14800025     | SQLite: A table in the database is locked.    |
| 14800026     | SQLite: The database is out of memory.        |
| 14800027     | SQLite: Attempt to write a readonly database. |
| 14800028     | SQLite: Some kind of disk I/O error occurred. |
| 14800029     | SQLite: The database is full.                 |
| 14800030     | SQLite: Unable to open the database file.     |
| 14800031     | SQLite: TEXT or BLOB exceeds size limit.      |
| 14800032     | SQLite: Abort due to constraint violation.    |
| 14800033     | SQLite: Data type mismatch.                   |
| 14800034     | SQLite: Library used incorrectly.             |

**示例：**

```ts
import { taskpool } from '@kit.ArkTS';
import type ctx from '@ohos.app.ability.common';
import { sendableRelationalStore } from '@kit.ArkData';

@Concurrent
async function getDataByName(name: string, context: ctx.UIAbilityContext) {
  const STORE_CONFIG: relationalStore.StoreConfig = {
    name: "RdbTest.db",
    securityLevel: relationalStore.SecurityLevel.S3
  };
  const store = await relationalStore.getRdbStore(context, STORE_CONFIG);
  const predicates = new relationalStore.RdbPredicates("EMPLOYEE");
  predicates.equalTo("NAME", name);
  const resultSet = store.querySync(predicates);

  if (resultSet.rowCount > 0) {
    resultSet.goToFirstRow();
    const sendableValuesBucket = resultSet.getSendableRow();
    return sendableValuesBucket;
  } else {
    return null;
  }
}

class EntryAbility extends UIAbility {
  async onWindowStageCreate(windowStage: window.WindowStage) {
    const task = new taskpool.Task(getDataByName, 'Lisa', getContext());
    const sendableValuesBucket = await taskpool.execute(task) as sendableRelationalStore.ValuesBucket;

    if (sendableValuesBucket) {
      const columnCount = sendableValuesBucket.size;
      const age = sendableValuesBucket.get('age');
      const name = sendableValuesBucket.get('name');
      console.info(`Query data in taskpool succeeded, name is "${name}", age is "${age}"`);
    }
  }
}
```

### isColumnNull

isColumnNull(columnIndex: number): boolean

检查当前行中指定列的值是否为null。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名      | 类型   | 必填 | 说明                    |
| ----------- | ------ | ---- | ----------------------- |
| columnIndex | number | 是   | 指定的列索引，从0开始。 |

**返回值：**

| 类型    | 说明                                                      |
| ------- | --------------------------------------------------------- |
| boolean | 如果当前行中指定列的值为null，则返回true，否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------- |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800012  | Row out of bounds. |
| 14800013  | Column out of bounds. |
| 14800014  | Already closed. |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |

**示例：**

```ts
if (resultSet != undefined) {
  const isColumnNull = (resultSet as relationalStore.ResultSet).isColumnNull((resultSet as relationalStore.ResultSet).getColumnIndex("CODES"));
}
```

### close

close(): void

关闭结果集，若不关闭可能会引起fd泄露和内存泄露。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**示例：**

```ts
if (resultSet != undefined) {
  (resultSet as relationalStore.ResultSet).close();
}
```

**错误码：**

以下错误码的详细介绍请参见[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 14800000  | Inner error. |
| 14800012  | Row out of bounds. |

## Transaction<sup>14+</sup>

提供以事务方式管理数据库的方法。事务对象是通过[createTransaction](#createtransaction14)接口创建的，不同事务对象之间的操作是隔离的，不同类型事务的区别见[TransactionType](#transactiontype14) 。

当前关系型数据库同一时刻只支持一个写事务，所以如果当前[RdbStore](#rdbstore)存在写事务未释放，创建IMMEDIATE或EXCLUSIVE事务会返回14800024错误码。如果是创建的DEFERRED事务，则可能在首次使用DEFERRED事务调用写操作时返回14800024错误码。通过IMMEDIATE或EXCLUSIVE创建写事务或者DEFERRED事务升级到写事务之后，[RdbStore](#rdbstore)的写操作也会返回14800024错误码。

当事务并发量较高且写事务持续时间较长时，返回14800024错误码的次数可能会变多，开发者可以通过减少事务占用时长减少14800024出现的次数，也可以通过重试的方式处理14800024错误码。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

let store: relationalStore.RdbStore | undefined = undefined;

class EntryAbility extends UIAbility {
  async onWindowStageCreate(windowStage: window.WindowStage) {
    const STORE_CONFIG: relationalStore.StoreConfig = {
      name: "RdbTest.db",
      securityLevel: relationalStore.SecurityLevel.S3,
    };

    await relationalStore.getRdbStore(this.context, STORE_CONFIG).then(async (rdbStore: relationalStore.RdbStore) => {
      store = rdbStore;
      console.info('Get RdbStore successfully.');
    }).catch((err: BusinessError) => {
      console.error(`Get RdbStore failed, code is ${err.code},message is ${err.message}`);
    });

    if (store != undefined) {
      (store as relationalStore.RdbStore).createTransaction().then((transaction: relationalStore.Transaction) => {
        console.info(`createTransaction success`);
        // 成功获取到事务对象后执行后续操作
      }).catch((err: BusinessError) => {
        console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
      });
    }
  }
}
```

### commit<sup>14+</sup>

commit(): Promise&lt;void&gt;

提交已执行的SQL语句。如果是使用异步接口执行sql语句，请确保异步接口执行完成之后再调用commit接口，否则可能会丢失SQL操作。调用commit接口之后，该Transaction对象及创建的ResultSet对象都会被关闭。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**返回值**：

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |

**示例：**

```ts
let value1 = "Lisa";
let value2 = 18;
let value3 = 100.5;
let value4 = new Uint8Array([1, 2, 3]);

if (store != undefined) {
  const valueBucket: relationalStore.ValuesBucket = {
    'NAME': value1,
    'AGE': value2,
    'SALARY': value3,
    'CODES': value4,
  };
  (store as relationalStore.RdbStore).createTransaction().then((transaction: relationalStore.Transaction) => {
    transaction.execute("DELETE FROM TEST WHERE age = ? OR age = ?", ["18", "20"]).then(() => {
      transaction.commit();
    }).catch((e: BusinessError) => {
      transaction.rollback();
      console.error(`execute sql failed, code is ${e.code},message is ${e.message}`);
    });
  }).catch((err: BusinessError) => {
    console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### rollback<sup>14+</sup>

rollback(): Promise&lt;void&gt;

回滚已经执行的SQL语句。调用rollback接口之后，该Transaction对象及创建的ResultSet对象都会被关闭。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**返回值**：

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |

**示例：**

```ts
if (store != undefined) {
  (store as relationalStore.RdbStore).createTransaction().then((transaction: relationalStore.Transaction) => {
    transaction.execute("DELETE FROM TEST WHERE age = ? OR age = ?", ["18", "20"]).then(() => {
      transaction.commit();
    }).catch((e: BusinessError) => {
      transaction.rollback();
      console.error(`execute sql failed, code is ${e.code},message is ${e.message}`);
    });
  }).catch((err: BusinessError) => {
    console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### insert<sup>14+</sup>

insert(table: string, values: ValuesBucket, conflict?: ConflictResolution): Promise&lt;number&gt;

向目标表中插入一行数据，使用Promise异步回调。由于共享内存大小限制为2Mb，因此单条数据的大小需小于2Mb，否则会查询失败。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型                                        | 必填 | 说明                       |
| -------- | ------------------------------------------- | ---- | -------------------------- |
| table    | string                                      | 是   | 指定的目标表名。           |
| values   | [ValuesBucket](#valuesbucket)               | 是   | 表示要插入到表中的数据行。 |
| conflict | [ConflictResolution](#conflictresolution10) | 否   | 指定冲突解决模式。默认值是relationalStore.ConflictResolution.ON_CONFLICT_NONE。         |

**返回值**：

| 类型                  | 说明                                              |
| --------------------- | ------------------------------------------------- |
| Promise&lt;number&gt; | Promise对象。如果操作成功，返回行ID；否则返回-1。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800021  | SQLite: Generic error. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800033  | SQLite: Data type mismatch. |
| 14800047  | The WAL file size exceeds the default limit. |

**示例：**

```ts
let value1 = "Lisa";
let value2 = 18;
let value3 = 100.5;
let value4 = new Uint8Array([1, 2, 3, 4, 5]);

// 以下三种方式可用
const valueBucket1: relationalStore.ValuesBucket = {
  'NAME': value1,
  'AGE': value2,
  'SALARY': value3,
  'CODES': value4,
};
const valueBucket2: relationalStore.ValuesBucket = {
  NAME: value1,
  AGE: value2,
  SALARY: value3,
  CODES: value4,
};
const valueBucket3: relationalStore.ValuesBucket = {
  "NAME": value1,
  "AGE": value2,
  "SALARY": value3,
  "CODES": value4,
};

if (store != undefined) {
  (store as relationalStore.RdbStore).createTransaction().then((transaction: relationalStore.Transaction) => {
    transaction.insert("EMPLOYEE", valueBucket1, relationalStore.ConflictResolution.ON_CONFLICT_REPLACE).then((rowId: number) => {
      transaction.commit();
      console.info(`Insert is successful, rowId = ${rowId}`);
    }).catch((e: BusinessError) => {
      transaction.rollback();
      console.error(`Insert is failed, code is ${e.code},message is ${e.message}`);
    });
  }).catch((err: BusinessError) => {
    console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### insertSync<sup>14+</sup>

insertSync(table: string, values: ValuesBucket | sendableRelationalStore.ValuesBucket, conflict?: ConflictResolution): number

向目标表中插入一行数据。由于共享内存大小限制为2Mb，因此单条数据的大小需小于2Mb，否则会查询失败。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型                                        | 必填 | 说明                                                         |
| -------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| table    | string                                      | 是   | 指定的目标表名。                                             |
| values   | [ValuesBucket](#valuesbucket) \| [sendableRelationalStore.ValuesBucket](./js-apis-data-sendableRelationalStore.md#valuesbucket)   | 是   | 表示要插入到表中的数据行。                                   |
| conflict | [ConflictResolution](#conflictresolution10) | 否   | 指定冲突解决模式。默认值是relationalStore.ConflictResolution.ON_CONFLICT_NONE。 |

**返回值**：

| 类型   | 说明                                 |
| ------ | ------------------------------------ |
| number | 如果操作成功，返回行ID；否则返回-1。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000     | Inner error.                                                 |
| 14800011     | Database corrupted.                                          |
| 14800014     | Already closed.                                              |
| 14800021     | SQLite: Generic error.                                       |
| 14800023     | SQLite: Access permission denied.                            |
| 14800024     | SQLite: The database file is locked.                         |
| 14800025     | SQLite: A table in the database is locked.                   |
| 14800026     | SQLite: The database is out of memory.                       |
| 14800027     | SQLite: Attempt to write a readonly database.                |
| 14800028     | SQLite: Some kind of disk I/O error occurred.                |
| 14800029     | SQLite: The database is full.                                |
| 14800031     | SQLite: TEXT or BLOB exceeds size limit.                     |
| 14800033     | SQLite: Data type mismatch.                                  |
| 14800047     | The WAL file size exceeds the default limit.                 |

**示例：**

```ts
let value1 = "Lisa";
let value2 = 18;
let value3 = 100.5;
let value4 = new Uint8Array([1, 2, 3, 4, 5]);

// 以下三种方式可用
const valueBucket1: relationalStore.ValuesBucket = {
  'NAME': value1,
  'AGE': value2,
  'SALARY': value3,
  'CODES': value4,
};
const valueBucket2: relationalStore.ValuesBucket = {
  NAME: value1,
  AGE: value2,
  SALARY: value3,
  CODES: value4,
};
const valueBucket3: relationalStore.ValuesBucket = {
  "NAME": value1,
  "AGE": value2,
  "SALARY": value3,
  "CODES": value4,
};

if (store != undefined) {
  (store as relationalStore.RdbStore).createTransaction().then((transaction: relationalStore.Transaction) => {
    try {
      let rowId: number = (transaction as relationalStore.Transaction).insertSync("EMPLOYEE", valueBucket1, relationalStore.ConflictResolution.ON_CONFLICT_REPLACE);
      transaction.commit();
      console.info(`Insert is successful, rowId = ${rowId}`);
    } catch (e) {
      transaction.rollback();
      console.error(`Insert is failed, code is ${e.code},message is ${e.message}`);
    };
  }).catch((err: BusinessError) => {
    console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### batchInsert<sup>14+</sup>

batchInsert(table: string, values: Array&lt;ValuesBucket&gt;): Promise&lt;number&gt;

向目标表中插入一组数据，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型                                       | 必填 | 说明                         |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| table  | string                                     | 是   | 指定的目标表名。             |
| values | Array&lt;[ValuesBucket](#valuesbucket)&gt; | 是   | 表示要插入到表中的一组数据。|

**返回值**：

| 类型                  | 说明                                                        |
| --------------------- | ----------------------------------------------------------- |
| Promise&lt;number&gt; | Promise对象。如果操作成功，返回插入的数据个数，否则返回-1。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800021  | SQLite: Generic error. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800033  | SQLite: Data type mismatch. |
| 14800047  | The WAL file size exceeds the default limit. |

**示例：**

```ts
let value1 = "Lisa";
let value2 = 18;
let value3 = 100.5;
let value4 = new Uint8Array([1, 2, 3, 4, 5]);
let value5 = "Jack";
let value6 = 19;
let value7 = 101.5;
let value8 = new Uint8Array([6, 7, 8, 9, 10]);
let value9 = "Tom";
let value10 = 20;
let value11 = 102.5;
let value12 = new Uint8Array([11, 12, 13, 14, 15]);

const valueBucket1: relationalStore.ValuesBucket = {
  'NAME': value1,
  'AGE': value2,
  'SALARY': value3,
  'CODES': value4,
};
const valueBucket2: relationalStore.ValuesBucket = {
  'NAME': value5,
  'AGE': value6,
  'SALARY': value7,
  'CODES': value8,
};
const valueBucket3: relationalStore.ValuesBucket = {
  'NAME': value9,
  'AGE': value10,
  'SALARY': value11,
  'CODES': value12,
};

let valueBuckets = new Array(valueBucket1, valueBucket2, valueBucket3);
if (store != undefined) {
  (store as relationalStore.RdbStore).createTransaction().then((transaction: relationalStore.Transaction) => {
    transaction.batchInsert("EMPLOYEE", valueBuckets).then((insertNum: number) => {
      transaction.commit();
      console.info(`batchInsert is successful, the number of values that were inserted = ${insertNum}`);
    }).catch((e: BusinessError) => {
      transaction.rollback();
      console.error(`batchInsert is failed, code is ${e.code},message is ${e.message}`);
    });
  }).catch((err: BusinessError) => {
    console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### batchInsertSync<sup>14+</sup>

batchInsertSync(table: string, values: Array&lt;ValuesBucket&gt;): number

向目标表中插入一组数据。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型                                       | 必填 | 说明                         |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| table  | string                                     | 是   | 指定的目标表名。             |
| values | Array&lt;[ValuesBucket](#valuesbucket)&gt; | 是   | 表示要插入到表中的一组数据。 |

**返回值**：

| 类型   | 说明                                           |
| ------ | ---------------------------------------------- |
| number | 如果操作成功，返回插入的数据个数，否则返回-1。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000     | Inner error.                                                 |
| 14800011     | Database corrupted.                                          |
| 14800014     | Already closed.                                              |
| 14800021     | SQLite: Generic error.                                       |
| 14800023     | SQLite: Access permission denied.                            |
| 14800024     | SQLite: The database file is locked.                         |
| 14800025     | SQLite: A table in the database is locked.                   |
| 14800026     | SQLite: The database is out of memory.                       |
| 14800027     | SQLite: Attempt to write a readonly database.                |
| 14800028     | SQLite: Some kind of disk I/O error occurred.                |
| 14800029     | SQLite: The database is full.                                |
| 14800031     | SQLite: TEXT or BLOB exceeds size limit.                     |
| 14800033     | SQLite: Data type mismatch.                                  |
| 14800047     | The WAL file size exceeds the default limit.                 |

**示例：**

```ts
let value1 = "Lisa";
let value2 = 18;
let value3 = 100.5;
let value4 = new Uint8Array([1, 2, 3, 4, 5]);
let value5 = "Jack";
let value6 = 19;
let value7 = 101.5;
let value8 = new Uint8Array([6, 7, 8, 9, 10]);
let value9 = "Tom";
let value10 = 20;
let value11 = 102.5;
let value12 = new Uint8Array([11, 12, 13, 14, 15]);

const valueBucket1: relationalStore.ValuesBucket = {
  'NAME': value1,
  'AGE': value2,
  'SALARY': value3,
  'CODES': value4,
};
const valueBucket2: relationalStore.ValuesBucket = {
  'NAME': value5,
  'AGE': value6,
  'SALARY': value7,
  'CODES': value8,
};
const valueBucket3: relationalStore.ValuesBucket = {
  'NAME': value9,
  'AGE': value10,
  'SALARY': value11,
  'CODES': value12,
};

let valueBuckets = new Array(valueBucket1, valueBucket2, valueBucket3);
if (store != undefined) {
  (store as relationalStore.RdbStore).createTransaction().then((transaction: relationalStore.Transaction) => {
    try {
      let insertNum: number = (transaction as relationalStore.Transaction).batchInsertSync("EMPLOYEE", valueBuckets);
      transaction.commit();
      console.info(`batchInsert is successful, the number of values that were inserted = ${insertNum}`);
    } catch (e) {
      transaction.rollback();
      console.error(`batchInsert is failed, code is ${e.code},message is ${e.message}`);
    };
  }).catch((err: BusinessError) => {
    console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### batchInsertWithConflictResolution<sup>18+</sup>

batchInsertWithConflictResolution(table: string, values: Array&lt;ValuesBucket&gt;, conflict: ConflictResolution): Promise&lt;number&gt;

向目标表中插入一组数据，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型                                       | 必填 | 说明                         |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| table  | string                                     | 是   | 指定的目标表名。             |
| values | Array&lt;[ValuesBucket](#valuesbucket)&gt; | 是   | 表示要插入到表中的一组数据。|
| conflict | [ConflictResolution](#conflictresolution10) | 是   | 指定冲突解决模式。如果是ON_CONFLICT_ROLLBACK模式，当发生冲突时会回滚整个事务。 |

**返回值**：

| 类型                  | 说明                                                        |
| --------------------- | ----------------------------------------------------------- |
| Promise&lt;number&gt; | Promise对象。如果操作成功，返回插入的数据个数，否则返回-1。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |
| 14800047  | The WAL file size exceeds the default limit. |

**示例：**

```ts
let value1 = "Lisa";
let value2 = 18;
let value3 = 100.5;
let value4 = new Uint8Array([1, 2, 3, 4, 5]);
let value5 = "Jack";
let value6 = 19;
let value7 = 101.5;
let value8 = new Uint8Array([6, 7, 8, 9, 10]);
let value9 = "Tom";
let value10 = 20;
let value11 = 102.5;
let value12 = new Uint8Array([11, 12, 13, 14, 15]);

const valueBucket1: relationalStore.ValuesBucket = {
  'NAME': value1,
  'AGE': value2,
  'SALARY': value3,
  'CODES': value4,
};
const valueBucket2: relationalStore.ValuesBucket = {
  'NAME': value5,
  'AGE': value6,
  'SALARY': value7,
  'CODES': value8,
};
const valueBucket3: relationalStore.ValuesBucket = {
  'NAME': value9,
  'AGE': value10,
  'SALARY': value11,
  'CODES': value12,
};

let valueBuckets = new Array(valueBucket1, valueBucket2, valueBucket3);
if (store != undefined) {
  (store as relationalStore.RdbStore).createTransaction().then((transaction: relationalStore.Transaction) => {
    transaction.batchInsertWithConflictResolution("EMPLOYEE", valueBuckets, relationalStore.ConflictResolution.ON_CONFLICT_REPLACE).then((insertNum: number) => {
      transaction.commit();
      console.info(`batchInsert is successful, the number of values that were inserted = ${insertNum}`);
    }).catch((e: BusinessError) => {
      transaction.rollback();
      console.error(`batchInsert is failed, code is ${e.code},message is ${e.message}`);
    });
  }).catch((err: BusinessError) => {
    console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### batchInsertWithConflictResolutionSync<sup>18+</sup>

batchInsertWithConflictResolutionSync(table: string, values: Array&lt;ValuesBucket&gt;, conflict: ConflictResolution): number

向目标表中插入一组数据。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型                                       | 必填 | 说明                         |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| table  | string                                     | 是   | 指定的目标表名。             |
| values | Array&lt;[ValuesBucket](#valuesbucket)&gt; | 是   | 表示要插入到表中的一组数据。 |
| conflict | [ConflictResolution](#conflictresolution10) | 是   | 指定冲突解决模式。如果是ON_CONFLICT_ROLLBACK模式，当发生冲突时会回滚整个事务。 |

**返回值**：

| 类型   | 说明                                           |
| ------ | ---------------------------------------------- |
| number | 如果操作成功，返回插入的数据个数，否则返回-1。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |
| 14800047  | The WAL file size exceeds the default limit. |

**示例：**

```ts
let value1 = "Lisa";
let value2 = 18;
let value3 = 100.5;
let value4 = new Uint8Array([1, 2, 3, 4, 5]);
let value5 = "Jack";
let value6 = 19;
let value7 = 101.5;
let value8 = new Uint8Array([6, 7, 8, 9, 10]);
let value9 = "Tom";
let value10 = 20;
let value11 = 102.5;
let value12 = new Uint8Array([11, 12, 13, 14, 15]);

const valueBucket1: relationalStore.ValuesBucket = {
  'NAME': value1,
  'AGE': value2,
  'SALARY': value3,
  'CODES': value4,
};
const valueBucket2: relationalStore.ValuesBucket = {
  'NAME': value5,
  'AGE': value6,
  'SALARY': value7,
  'CODES': value8,
};
const valueBucket3: relationalStore.ValuesBucket = {
  'NAME': value9,
  'AGE': value10,
  'SALARY': value11,
  'CODES': value12,
};

let valueBuckets = new Array(valueBucket1, valueBucket2, valueBucket3);
if (store != undefined) {
  (store as relationalStore.RdbStore).createTransaction().then((transaction: relationalStore.Transaction) => {
    try {
      let insertNum: number = (transaction as relationalStore.Transaction).batchInsertWithConflictResolutionSync("EMPLOYEE", valueBuckets, relationalStore.ConflictResolution.ON_CONFLICT_REPLACE);
      transaction.commit();
      console.info(`batchInsert is successful, the number of values that were inserted = ${insertNum}`);
    } catch (e) {
      transaction.rollback();
      console.error(`batchInsert is failed, code is ${e.code},message is ${e.message}`);
    };
  }).catch((err: BusinessError) => {
    console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### update<sup>14+</sup>

update(values: ValuesBucket, predicates: RdbPredicates, conflict?: ConflictResolution): Promise&lt;number&gt;

根据RdbPredicates的指定实例对象更新数据库中的数据，使用Promise异步回调。由于共享内存大小限制为2Mb，因此单条数据的大小需小于2Mb，否则会查询失败。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名     | 类型                                        | 必填 | 说明                                                         |
| ---------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| values     | [ValuesBucket](#valuesbucket)               | 是   | values指示数据库中要更新的数据行。键值对与数据库表的列名相关联。 |
| predicates | [RdbPredicates](#rdbpredicates)            | 是   | RdbPredicates的实例对象指定的更新条件。                      |
| conflict   | [ConflictResolution](#conflictresolution10) | 否   | 指定冲突解决模式。默认值是relationalStore.ConflictResolution.ON_CONFLICT_NONE。                                          |

**返回值**：

| 类型                  | 说明                                      |
| --------------------- | ----------------------------------------- |
| Promise&lt;number&gt; | 指定的Promise回调方法。返回受影响的行数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800021  | SQLite: Generic error. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800033  | SQLite: Data type mismatch. |
| 14800047  | The WAL file size exceeds the default limit. |

**示例：**

```ts
let value1 = "Rose";
let value2 = 22;
let value3 = 200.5;
let value4 = new Uint8Array([1, 2, 3, 4, 5]);

// 以下三种方式可用
const valueBucket1: relationalStore.ValuesBucket = {
  'NAME': value1,
  'AGE': value2,
  'SALARY': value3,
  'CODES': value4,
};
const valueBucket2: relationalStore.ValuesBucket = {
  NAME: value1,
  AGE: value2,
  SALARY: value3,
  CODES: value4,
};
const valueBucket3: relationalStore.ValuesBucket = {
  "NAME": value1,
  "AGE": value2,
  "SALARY": value3,
  "CODES": value4,
};

let predicates = new relationalStore.RdbPredicates('EMPLOYEE');
predicates.equalTo("NAME", "Lisa");

if (store != undefined) {
  (store as relationalStore.RdbStore).createTransaction().then((transaction: relationalStore.Transaction) => {
    transaction.update(valueBucket1, predicates, relationalStore.ConflictResolution.ON_CONFLICT_REPLACE).then(async (rows: Number) => {
      transaction.commit();
      console.info(`Updated row count: ${rows}`);
    }).catch((e: BusinessError) => {
      transaction.rollback();
      console.error(`Updated failed, code is ${e.code},message is ${e.message}`);
    });
  }).catch((err: BusinessError) => {
    console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### updateSync<sup>14+</sup>

updateSync(values: ValuesBucket, predicates: RdbPredicates, conflict?: ConflictResolution): number

根据RdbPredicates的指定实例对象更新数据库中的数据。由于共享内存大小限制为2Mb，因此单条数据的大小需小于2Mb，否则会查询失败。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名     | 类型                                        | 必填 | 说明                                                         |
| ---------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| values     | [ValuesBucket](#valuesbucket)               | 是   | values指示数据库中要更新的数据行。键值对与数据库表的列名相关联。 |
| predicates | [RdbPredicates](#rdbpredicates)             | 是   | RdbPredicates的实例对象指定的更新条件。                      |
| conflict   | [ConflictResolution](#conflictresolution10) | 否   | 指定冲突解决模式。默认值是relationalStore.ConflictResolution.ON_CONFLICT_NONE。 |

**返回值**：

| 类型   | 说明               |
| ------ | ------------------ |
| number | 返回受影响的行数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000     | Inner error.                                                 |
| 14800011     | Database corrupted.                                          |
| 14800014     | Already closed.                                              |
| 14800021     | SQLite: Generic error.                                       |
| 14800023     | SQLite: Access permission denied.                            |
| 14800024     | SQLite: The database file is locked.                         |
| 14800025     | SQLite: A table in the database is locked.                   |
| 14800026     | SQLite: The database is out of memory.                       |
| 14800027     | SQLite: Attempt to write a readonly database.                |
| 14800028     | SQLite: Some kind of disk I/O error occurred.                |
| 14800029     | SQLite: The database is full.                                |
| 14800031     | SQLite: TEXT or BLOB exceeds size limit.                     |
| 14800033     | SQLite: Data type mismatch.                                  |
| 14800047     | The WAL file size exceeds the default limit.                 |

**示例：**

```ts
let value1 = "Rose";
let value2 = 22;
let value3 = 200.5;
let value4 = new Uint8Array([1, 2, 3, 4, 5]);

// 以下三种方式可用
const valueBucket1: relationalStore.ValuesBucket = {
  'NAME': value1,
  'AGE': value2,
  'SALARY': value3,
  'CODES': value4,
};
const valueBucket2: relationalStore.ValuesBucket = {
  NAME: value1,
  AGE: value2,
  SALARY: value3,
  CODES: value4,
};
const valueBucket3: relationalStore.ValuesBucket = {
  "NAME": value1,
  "AGE": value2,
  "SALARY": value3,
  "CODES": value4,
};

let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Lisa");

if (store != undefined) {
  (store as relationalStore.RdbStore).createTransaction().then((transaction: relationalStore.Transaction) => {
    try {
      let rows: Number = (transaction as relationalStore.Transaction).updateSync(valueBucket1, predicates, relationalStore.ConflictResolution.ON_CONFLICT_REPLACE);
      transaction.commit();
      console.info(`Updated row count: ${rows}`);
    } catch (e) {
      transaction.rollback();
      console.error(`Updated failed, code is ${e.code},message is ${e.message}`);
    };
  }).catch((err: BusinessError) => {
    console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### delete<sup>14+</sup>

delete(predicates: RdbPredicates):Promise&lt;number&gt;

根据RdbPredicates的指定实例对象从数据库中删除数据，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名     | 类型                                 | 必填 | 说明                                      |
| ---------- | ------------------------------------ | ---- | ----------------------------------------- |
| predicates | [RdbPredicates](#rdbpredicates) | 是   | RdbPredicates的实例对象指定的删除条件。 |

**返回值**：

| 类型                  | 说明                            |
| --------------------- | ------------------------------- |
| Promise&lt;number&gt; | Promise对象。返回受影响的行数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800021  | SQLite: Generic error. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800033  | SQLite: Data type mismatch. |
| 14800047  | The WAL file size exceeds the default limit. |

**示例：**

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Lisa");

if (store != undefined) {
  (store as relationalStore.RdbStore).createTransaction().then((transaction: relationalStore.Transaction) => {
    transaction.delete(predicates).then((rows: Number) => {
      transaction.commit();
      console.info(`Delete rows: ${rows}`);
    }).catch((e: BusinessError) => {
      transaction.rollback();
      console.error(`Delete failed, code is ${e.code},message is ${e.message}`);
    });
  }).catch((err: BusinessError) => {
    console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### deleteSync<sup>14+</sup>

deleteSync(predicates: RdbPredicates): number

根据RdbPredicates的指定实例对象从数据库中删除数据。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名     | 类型                            | 必填 | 说明                                    |
| ---------- | ------------------------------- | ---- | --------------------------------------- |
| predicates | [RdbPredicates](#rdbpredicates) | 是   | RdbPredicates的实例对象指定的删除条件。 |

**返回值**：

| 类型   | 说明               |
| ------ | ------------------ |
| number | 返回受影响的行数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800021  | SQLite: Generic error. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800033  | SQLite: Data type mismatch. |
| 14800047  | The WAL file size exceeds the default limit. |

**示例：**

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Lisa");

if (store != undefined) {
  (store as relationalStore.RdbStore).createTransaction().then((transaction: relationalStore.Transaction) => {
    try {
      let rows: Number = (transaction as relationalStore.Transaction).deleteSync(predicates);
      transaction.commit();
      console.info(`Delete rows: ${rows}`);
    } catch (e) {
      transaction.rollback();
      console.error(`Delete failed, code is ${e.code},message is ${e.message}`);
    };
  }).catch((err: BusinessError) => {
    console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### query<sup>14+</sup>

query(predicates: RdbPredicates, columns?: Array&lt;string&gt;): Promise&lt;ResultSet&gt;

根据指定条件查询数据库中的数据，使用Promise异步回调。由于共享内存大小限制为2Mb，因此单条数据的大小需小于2Mb，否则会查询失败。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名     | 类型                                 | 必填 | 说明                                             |
| ---------- | ------------------------------------ | ---- | ------------------------------------------------ |
| predicates | [RdbPredicates](#rdbpredicates) | 是   | RdbPredicates的实例对象指定的查询条件。        |
| columns    | Array&lt;string&gt;                  | 否   | 表示要查询的列。如果值为空，则查询应用于所有列。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800021  | SQLite: Generic error. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800047  | The WAL file size exceeds the default limit. |

**返回值**：

| 类型                                                    | 说明                                               |
| ------------------------------------------------------- | -------------------------------------------------- |
| Promise&lt;[ResultSet](#resultset)&gt; | Promise对象。如果操作成功，则返回ResultSet对象。 |

**示例：**

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Rose");

if (store != undefined) {
  (store as relationalStore.RdbStore).createTransaction().then((transaction: relationalStore.Transaction) => {
    transaction.query(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"]).then((resultSet: relationalStore.ResultSet) => {
      console.info(`ResultSet column names: ${resultSet.columnNames}, column count: ${resultSet.columnCount}`);
      // resultSet是一个数据集合的游标，默认指向第-1个记录，有效的数据从0开始。
      while (resultSet.goToNextRow()) {
        const id = resultSet.getLong(resultSet.getColumnIndex("ID"));
        const name = resultSet.getString(resultSet.getColumnIndex("NAME"));
        const age = resultSet.getLong(resultSet.getColumnIndex("AGE"));
        const salary = resultSet.getDouble(resultSet.getColumnIndex("SALARY"));
        console.info(`id=${id}, name=${name}, age=${age}, salary=${salary}`);
      }
      // 释放数据集的内存，若不释放可能会引起fd泄露与内存泄露
      resultSet.close();
      transaction.commit();
    }).catch((e: BusinessError) => {
      transaction.rollback();
      console.error(`Query failed, code is ${e.code},message is ${e.message}`);
    });
  }).catch((err: BusinessError) => {
    console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### querySync<sup>14+</sup>

querySync(predicates: RdbPredicates, columns?: Array&lt;string&gt;): ResultSet

根据指定条件查询数据库中的数据。对query同步接口获得的resultSet进行操作时，若逻辑复杂且循环次数过多，可能造成freeze问题，建议将此步骤放到[taskpool](../apis-arkts/js-apis-taskpool.md)线程中执行。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名     | 类型                            | 必填 | 说明                                                         |
| ---------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| predicates | [RdbPredicates](#rdbpredicates) | 是   | RdbPredicates的实例对象指定的查询条件。                      |
| columns    | Array&lt;string&gt;             | 否   | 表示要查询的列。如果值为空，则查询应用于所有列。默认值为空。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800021  | SQLite: Generic error. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800047  | The WAL file size exceeds the default limit. |

**返回值**：

| 类型                    | 说明                                |
| ----------------------- | ----------------------------------- |
| [ResultSet](#resultset) | 如果操作成功，则返回ResultSet对象。 |

**示例：**

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Rose");

if (store != undefined) {
  (store as relationalStore.RdbStore).createTransaction().then((transaction: relationalStore.Transaction) => {
    try {
      let resultSet: relationalStore.ResultSet = (transaction as relationalStore.Transaction).querySync(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"]);
      console.info(`ResultSet column names: ${resultSet.columnNames}, column count: ${resultSet.columnCount}`);
      // resultSet是一个数据集合的游标，默认指向第-1个记录，有效的数据从0开始。
      while (resultSet.goToNextRow()) {
        const id = resultSet.getLong(resultSet.getColumnIndex("ID"));
        const name = resultSet.getString(resultSet.getColumnIndex("NAME"));
        const age = resultSet.getLong(resultSet.getColumnIndex("AGE"));
        const salary = resultSet.getDouble(resultSet.getColumnIndex("SALARY"));
        console.info(`id=${id}, name=${name}, age=${age}, salary=${salary}`);
      }
      // 释放数据集的内存，若不释放可能会引起fd泄露与内存泄露
      resultSet.close();
      transaction.commit();
    } catch (e) {
      transaction.rollback();
      console.error(`Query failed, code is ${e.code},message is ${e.message}`);
    };
  }).catch((err: BusinessError) => {
    console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### querySql<sup>14+</sup>

querySql(sql: string, args?: Array&lt;ValueType&gt;): Promise&lt;ResultSet&gt;

根据指定SQL语句查询数据库中的数据，语句中的各种表达式和操作符之间的关系操作符号不超过1000个，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型                                 | 必填 | 说明                                                         |
| -------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| sql      | string                               | 是   | 指定要执行的SQL语句。                                        |
| args | Array&lt;[ValueType](#valuetype)&gt; | 否   | SQL语句中参数的值。该值与sql参数语句中的占位符相对应。当sql参数语句完整时，该参数不填。 |

**返回值**：

| 类型                                                    | 说明                                               |
| ------------------------------------------------------- | -------------------------------------------------- |
| Promise&lt;[ResultSet](#resultset)&gt; | Promise对象。如果操作成功，则返回ResultSet对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800021  | SQLite: Generic error. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800047  | The WAL file size exceeds the default limit. |

**示例：**

```ts
if (store != undefined) {
  (store as relationalStore.RdbStore).createTransaction().then((transaction: relationalStore.Transaction) => {
    transaction.querySql("SELECT * FROM EMPLOYEE CROSS JOIN BOOK WHERE BOOK.NAME = 'sanguo'").then((resultSet: relationalStore.ResultSet) => {
      console.info(`ResultSet column names: ${resultSet.columnNames}, column count: ${resultSet.columnCount}`);
      // resultSet是一个数据集合的游标，默认指向第-1个记录，有效的数据从0开始。
      while (resultSet.goToNextRow()) {
        const id = resultSet.getLong(resultSet.getColumnIndex("ID"));
        const name = resultSet.getString(resultSet.getColumnIndex("NAME"));
        const age = resultSet.getLong(resultSet.getColumnIndex("AGE"));
        const salary = resultSet.getDouble(resultSet.getColumnIndex("SALARY"));
        console.info(`id=${id}, name=${name}, age=${age}, salary=${salary}`);
      }
      // 释放数据集的内存，若不释放可能会引起fd泄露与内存泄露
      resultSet.close();
      transaction.commit();
    }).catch((e: BusinessError) => {
      transaction.rollback();
      console.error(`Query failed, code is ${e.code},message is ${e.message}`);
    });
  }).catch((err: BusinessError) => {
    console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### querySqlSync<sup>14+</sup>

querySqlSync(sql: string, args?: Array&lt;ValueType&gt;): ResultSet

根据指定SQL语句查询数据库中的数据，语句中的各种表达式和操作符之间的关系操作符号不超过1000个。对query同步接口获得的resultSet进行操作时，若逻辑复杂且循环次数过多，可能造成freeze问题，建议将此步骤放到[taskpool](../apis-arkts/js-apis-taskpool.md)线程中执行。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型                                 | 必填 | 说明                                                         |
| -------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| sql      | string                               | 是   | 指定要执行的SQL语句。                                        |
| args | Array&lt;[ValueType](#valuetype)&gt; | 否   | SQL语句中参数的值。该值与sql参数语句中的占位符相对应。当sql参数语句完整时，该参数不填。默认值为空。 |

**返回值**：

| 类型                    | 说明                                |
| ----------------------- | ----------------------------------- |
| [ResultSet](#resultset) | 如果操作成功，则返回ResultSet对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800021  | SQLite: Generic error. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800047  | The WAL file size exceeds the default limit. |

**示例：**

```ts
if (store != undefined) {
  (store as relationalStore.RdbStore).createTransaction().then((transaction: relationalStore.Transaction) => {
    try {
      let resultSet: relationalStore.ResultSet = (transaction as relationalStore.Transaction).querySqlSync("SELECT * FROM EMPLOYEE CROSS JOIN BOOK WHERE BOOK.NAME = 'sanguo'");
      console.info(`ResultSet column names: ${resultSet.columnNames}, column count: ${resultSet.columnCount}`);
      // resultSet是一个数据集合的游标，默认指向第-1个记录，有效的数据从0开始。
      while (resultSet.goToNextRow()) {
        const id = resultSet.getLong(resultSet.getColumnIndex("ID"));
        const name = resultSet.getString(resultSet.getColumnIndex("NAME"));
        const age = resultSet.getLong(resultSet.getColumnIndex("AGE"));
        const salary = resultSet.getDouble(resultSet.getColumnIndex("SALARY"));
        console.info(`id=${id}, name=${name}, age=${age}, salary=${salary}`);
      }
      // 释放数据集的内存，若不释放可能会引起fd泄露与内存泄露
      resultSet.close();
      transaction.commit();
    } catch (e) {
      transaction.rollback();
      console.error(`Query failed, code is ${e.code},message is ${e.message}`);
    };
  }).catch((err: BusinessError) => {
    console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### execute<sup>14+</sup>

execute(sql: string, args?: Array&lt;ValueType&gt;): Promise&lt;ValueType&gt;

执行包含指定参数的SQL语句，语句中的各种表达式和操作符之间的关系操作符号不超过1000个，返回值类型为ValueType，使用Promise异步回调。

该接口支持执行增删改操作，支持执行PRAGMA语法的sql，支持对表的操作（建表、删表、修改表），返回结果类型由执行具体sql的结果决定。

此接口不支持执行查询、附加数据库和事务操作，查询可以使用[querySql](#querysql14)、[query](#query14)接口代替、附加数据库可以使用[attach](#attach12)接口代替。

不支持分号分隔的多条语句。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型                                 | 必填 | 说明                                                         |
| -------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| sql      | string                               | 是   | 指定要执行的SQL语句。                                        |
| args | Array&lt;[ValueType](#valuetype)&gt; | 否   | SQL语句中参数的值。该值与sql参数语句中的占位符相对应。当sql参数语句完整时，该参数不填。 |

**返回值**：

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;[ValueType](#valuetype)&gt; | Promise对象，返回sql执行后的结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported the sql(attach,begin,commit,rollback etc.). |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800021  | SQLite: Generic error. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800033  | SQLite: Data type mismatch. |
| 14800047  | The WAL file size exceeds the default limit. |

**示例：**

```ts
// 删除表中所有数据
if (store != undefined) {
  const SQL_DELETE_TABLE = 'DELETE FROM test';
  (store as relationalStore.RdbStore).createTransaction().then((transaction: relationalStore.Transaction) => {
    transaction.execute(SQL_DELETE_TABLE).then((data) => {
      transaction.commit();
      console.info(`delete result: ${data}`);
    }).catch((e: BusinessError) => {
      transaction.rollback();
      console.error(`delete failed, code is ${e.code}, message is ${e.message}`);
    });
  }).catch((err: BusinessError) => {
    console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### executeSync<sup>14+</sup>

executeSync(sql: string, args?: Array&lt;ValueType&gt;): ValueType

执行包含指定参数的SQL语句，语句中的各种表达式和操作符之间的关系操作符号不超过1000个，返回值类型为ValueType。

该接口支持执行增删改操作，支持执行PRAGMA语法的sql，支持对表的操作（建表、删表、修改表），返回结果类型由执行具体sql的结果决定。

此接口不支持执行查询、附加数据库和事务操作，查询可以使用[querySql](#querysql14)、[query](#query14)接口代替、附加数据库可以使用[attach](#attach12)接口代替。

不支持分号分隔的多条语句。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型                                 | 必填 | 说明                                                         |
| ------ | ------------------------------------ | ---- | ------------------------------------------------------------ |
| sql    | string                               | 是   | 指定要执行的SQL语句。                                        |
| args   | Array&lt;[ValueType](#valuetype)&gt; | 否   | SQL语句中参数的值。该值与sql参数语句中的占位符相对应。该参数不填，或者填null或undefined，都认为是sql参数语句完整。默认值为空。 |

**返回值**：

| 类型                    | 说明                |
| ----------------------- | ------------------- |
| [ValueType](#valuetype) | 返回sql执行后的结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported the sql(attach,begin,commit,rollback etc.). |
| 14800000     | Inner error.                                                 |
| 14800011     | Database corrupted.                                          |
| 14800014     | Already closed.                                              |
| 14800021     | SQLite: Generic error.                                       |
| 14800023     | SQLite: Access permission denied.                            |
| 14800024     | SQLite: The database file is locked.                         |
| 14800025     | SQLite: A table in the database is locked.                   |
| 14800026     | SQLite: The database is out of memory.                       |
| 14800027     | SQLite: Attempt to write a readonly database.                |
| 14800028     | SQLite: Some kind of disk I/O error occurred.                |
| 14800029     | SQLite: The database is full.                                |
| 14800031     | SQLite: TEXT or BLOB exceeds size limit.                     |
| 14800033     | SQLite: Data type mismatch.                                  |
| 14800047     | The WAL file size exceeds the default limit.                 |

**示例：**

```ts
// 删除表中所有数据
if (store != undefined) {
  (store as relationalStore.RdbStore).createTransaction().then((transaction: relationalStore.Transaction) => {
    const SQL_DELETE_TABLE = 'DELETE FROM test';
    try {
      let data = (transaction as relationalStore.Transaction).executeSync(SQL_DELETE_TABLE);
      transaction.commit();
      console.info(`delete result: ${data}`);
    } catch (e) {
      transaction.rollback();
      console.error(`delete failed, code is ${e.code}, message is ${e.message}`);
    };
  }).catch((err: BusinessError) => {
    console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
  });
}
```