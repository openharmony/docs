# @ohos.data.graphStore (图数据库)(系统接口)

图数据库（Graph Database，GDB）是以顶点（[Vertex](#vertex)）、边（[Edge](#edge)）为基础存储单元，以高效存储、查询图数据为设计原理的数据管理系统。图数据库提供了一套完整的对本地数据库进行管理的机制，对外提供了一系列的读（查询）、写（增删改）、事务管理等接口，可以直接运行用户输入的GQL（Graph Query Language，图查询语言）语句来满足存储、查询、分析高度互联数据的场景需要。

- [Vertex](#vertex)：顶点，代表实体或实例，例如人员、企业、账户或要跟踪的任何其他项目。它们大致相当于关系数据库中的记录、关系或行，或者文档存储数据库中的文档。
- [Edge](#edge)：边，也称作关系，将节点连接到其他节点的线；代表节点之间的关系。边是图数据库中的关键概念，图数据库独有的数据抽象概念，而关系型数据库和文件型数据库并没有“边”这一概念，它们的关系查询必须在运行时进行具体化。
- [Path](#path)：路径，由顶点和边按照一定顺序组成的序列。
- [PathSegment](#pathsegment)：路径段，路径中的某一条边及其起点、终点。

该模块提供以下图数据库相关的常用功能：

- [GraphStore](#graphstore)：提供管理图数据库(GDB)方法的接口。
- [Result](#result)：提供用户调用图数据库读、写接口之后返回的结果。
- [Transaction](#transaction)：提供管理事务对象的接口。

> **说明：**
> 
> - 本模块首批接口从API version 18开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 当前页面仅包含本模块的系统接口。

## 导入模块

```ts
import { graphStore } from '@kit.ArkData';
```

## graphStore.getStore

getStore(context: Context, config: StoreConfig): Promise&lt;GraphStore&gt;

获得GraphStore实例以操作图数据库，根据需求配置GraphStore实例的参数，通过该实例调用接口执行相关的数据操作，使用promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

**参数：**

| 参数名  | 类型                             | 必填 | 说明                                                         |
| ------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| context | Context                          | 是   | 应用的上下文，推荐使用Stage模型。 <br>FA模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-app-context.md)。<br>Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md)。 |
| config  | [StoreConfig](#storeconfig) | 是   | 与此GDB存储相关的数据库配置。                                |

**返回值**：

| 类型                                      | 说明                              |
| ----------------------------------------- | --------------------------------- |
| Promise&lt;[GraphStore](#graphstore)&gt; | Promise对象。返回GraphStore对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[图数据库错误码](errorcode-data-gdb.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 202  | Permission verification failed, application which is not a system application uses system API. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 31300000  | Inner error. |
| 31300001  | Database corrupted. |
| 31300014  | Failed to open or delete database with an invalid database path. |
| 31300015  | StoreConfig, for example, securityLevel or encrypt, is changed. |

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

let store: graphStore.GraphStore | null = null;

class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    const STORE_CONFIG: graphStore.StoreConfig = {
      name: "testGraphDb",
      securityLevel: graphStore.SecurityLevel.S2
    };

    graphStore.getStore(this.context, STORE_CONFIG).then(async (gdb: graphStore.GraphStore) => {
      store = gdb;
      console.info('Get GraphStore successfully.');
    }).catch((err: BusinessError) => {
      console.error(`Get GraphStore failed, code is ${err.code}, message is ${err.message}`);
    })
  }
}
```

## graphStore.deleteStore

deleteStore(context: Context, config: StoreConfig): Promise&lt;void&gt;

使用指定的数据库文件配置删除数据库，使用promise异步回调。

删除前，请确保数据库已关闭，建议使用[close](#close)接口关闭数据库后再进行删除。删除成功后，请将数据库对象置为null，不再使用。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

**参数**

| 参数名  | 类型    | 必填 | 说明                                                         |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| context | Context                          | 是   | 应用的上下文，推荐使用Stage模型。 <br>FA模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-app-context.md)。<br>Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md)。 |
| config  | [StoreConfig](#storeconfig) | 是   | 与此GDB存储相关的数据库配置。<br/>**使用约束：** <br/>删除数据库时仅以config.name为标识，不关注其他配置项。 |

**返回值**：

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[图数据库错误码](errorcode-data-gdb.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 202  | Permission verification failed, application which is not a system application uses system API. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 31300000  | Inner error. |
| 31300014  | Failed to open or delete database with an invalid database path. |

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

let store: graphStore.GraphStore | null = null;

const STORE_CONFIG: graphStore.StoreConfig = {
  name: "testGraphDb",
  securityLevel: graphStore.SecurityLevel.S2
};

class EntryAbility extends UIAbility {
  onWindowStageDestroy() {
    graphStore.deleteStore(this.context, STORE_CONFIG).then(() => {
      store = null;
      console.info('Delete GraphStore successfully.');
    }).catch((err: BusinessError) => {
      console.error(`Delete GraphStore failed, code is ${err.code},message is ${err.message}`);
    })
  }
}
```

## StoreConfig

用于管理图数据库的配置。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

| 名称        | 类型          | 必填 | 说明                                                      |
| ------------- | ------------- | ---- | --------------------------------------------------------- |
| name          | string        | 是   | 数据库文件名，也是数据库唯一标识符。<br/>**使用约束：** <br/>1. 文件名长度上限为128字节。<br/>2. 文件名不包含.db后缀。 |
| securityLevel | [SecurityLevel](#securitylevel) | 是   | 设置数据库安全级别。<br/>**使用约束：** <br/>1. 安全级别不支持从高到低变更。<br/>2. 同一个数据库如果需要变更安全等级，需要使用[close](#close)接口关闭已经打开的数据库，再将修改安全等级后的StoreConfig作为参数重新调用[getStore](#graphstoregetstore)。 |
| encrypt | boolean       | 否   | 指定数据库是否加密，默认不加密。<br/> true:加密。<br/> false:非加密。<br/>**使用约束：** <br/>1. 不支持从加密数据库到非加密数据库的变更。<br/>2. 同一个数据库如果需要从非加密数据库变更为加密数据库，需要使用[close](#close)接口关闭已经打开的数据库，再将修改加密标志后的StoreConfig作为参数重新调用[getStore](#graphstoregetstore)。 |

## SecurityLevel

用于表示数据库的安全级别枚举。请使用枚举名称而非枚举值。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

| 名称 | 值   | 说明                                                         |
| ---- | ---- | ------------------------------------------------------------ |
| S1   | 1    | 表示数据库的安全级别为低级别，当数据泄露时会产生较低影响。例如，包含壁纸等系统数据的数据库。 |
| S2   | 2    | 表示数据库的安全级别为中级别，当数据泄露时会产生较大影响。例如，包含录音、视频等用户生成数据或通话记录等信息的数据库。 |
| S3   | 3    | 表示数据库的安全级别为高级别，当数据泄露时会产生重大影响。例如，包含用户运动、健康、位置等信息的数据库。 |
| S4   | 4    | 表示数据库的安全级别为关键级别，当数据泄露时会产生严重影响。例如，包含认证凭据、财务数据等信息的数据库。 |

## ValueType

type ValueType = null | number | string

用于表示允许的数据字段类型，接口参数的具体类型根据其功能而定。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

| 类型    | 说明                 |
| ------- | -------------------- |
| null    | 表示值类型为空。 |
| number  | 表示值类型为数字，可取任意值。 |
| string  | 表示值类型为字符，可取任意值。 |

## Vertex

用于记录顶点的相关信息。Vertex仅作为返回值（[Result](#result)）中的类型出现，不支持自定义填写，可通过使用[read](#read)接口查询获得。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

| 名称          | 类型                          | 必填  | 说明           |
| ----------- | --------------------------- | --- | ------------ |
| vid        | string | 是   | 顶点的标识符。不支持自定义填写，使用[GraphStore.write](#write-1)或[Transaction.write](#write)接口插入顶点后由底层分配的全局唯一标识符。 |
| labels     | Array&lt;string&gt; | 是   | 顶点的标签。在使用[GraphStore.write](#write-1)或[Transaction.write](#write)接口创建图使用的GQL语句中指定，每个元素长度上限为128字节，不区分大小写，以大写形式存储。 |
| properties | Record&lt;string, [ValueType](#valuetype)&gt; | 是   | 顶点的属性。key长度上限为128字节，数量上限为1024条，在使用[GraphStore.write](#write-1)或[Transaction.write](#write)接口创建图使用的GQL语句中指定，value类型为string时长度上限为64 * 1024字节。 |

## Edge

记录边的相关信息。Edge仅作为返回值（[Result](#result)）中的类型出现，不支持自定义填写，可通过使用[read](#read)接口查询获得。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

| 名称          | 类型                          | 必填  | 说明           |
| ----------- | --------------------------- | --- | ------------ |
| eid        | string | 是   | 边的标识符。不支持自定义填写，使用[GraphStore.write](#write-1)或[Transaction.write](#write)接口插入边后由底层分配的全局唯一标识符。 |
| type       | string | 是   | 边的类型。在使用[GraphStore.write](#write-1)或[Transaction.write](#write)接口创建图使用的GQL语句中指定，长度上限为128字节，不区分大小写，以大写形式存储。 |
| startVid   | string | 是   | 起始顶点的标识符。不支持自定义填写，使用[GraphStore.write](#write-1)或[Transaction.write](#write)接口插入顶点后由底层分配的全局唯一标识符。 |
| endVid     | string | 是   | 终点的标识符。不支持自定义填写，使用[GraphStore.write](#write-1)或[Transaction.write](#write)接口插入顶点后由底层分配的全局唯一标识符。 |
| properties | Record&lt;string, [ValueType](#valuetype)&gt; | 是   | 边的属性。key长度上限为128字节，数量上限为1024条，在使用[GraphStore.write](#write-1)或[Transaction.write](#write)接口创建图使用的GQL语句中指定，value类型为string时长度上限为64 * 1024字节。 |

## PathSegment

记录路径段（路径中的每条边及其起点、终点）的相关信息。PathSegment仅作为返回值（[Path.segments](#path)）的类型出现，不支持自定义填写，可通过使用[read](#read)接口查询获得。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

| 名称          | 类型                          | 必填  | 说明           |
| ----------- | --------------------------- | --- | ------------ |
| start | [Vertex](#vertex) | 是   | 路径段的起始顶点。 |
| end   | [Vertex](#vertex) | 是   | 路径段的终点。 |
| edge  | [Edge](#edge)     | 是   | 路径段的边。 |

## Path

记录路径的相关信息。Path仅作为返回值（[Result](#result)）中的类型出现，不支持自定义填写，可通过使用[read](#read)接口查询获得。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

| 名称          | 类型                          | 必填  | 说明           |
| ----------- | --------------------------- | --- | ------------ |
| start    | [Vertex](#vertex) | 是   | 路径的起始顶点。 |
| end      | [Vertex](#vertex) | 是   | 路径的终点。 |
| length   | number            | 是   | 路径的长度，即路径中路径段的数量（segments.length），上限为1024条。 |
| segments | Array&lt;[PathSegment](#pathsegment)&gt; | 是   | 路径中所有路径段。 |

## Result

GQL语句的执行结果。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

| 名称          | 类型                          | 必填  | 说明           |
| ----------- | --------------------------- | --- | ------------ |
| records | Array&lt;Record&lt;string, Object&gt;&gt; | 否   | GQL语句执行结果的数据记录。默认值为空。<br/>如果有执行结果，Object具体类型根据查询GQL语句不同，可能是[Vertex](#vertex)，[Edge](#edge)，[Path](#path)或[ValueType](#valuetype)。 |


## Transaction

提供用于管理图数据库的事务处理方法的接口。

不同事务对象之间的操作是隔离的，当前图数据库使用库级锁。所以如果存在一个事务使用[write](#write)接口写入后未使用[commit](#commit)接口提交或使用[rollback](#rollback)接口回滚，此时其他Transaction实例使用[read](#read)/[write](#write)或GraphStore实例使用[GraphStore.read](#read-1)/[GraphStore.write](#write-1)进行读写操作时会返回31300003错误码。另外如果存在一个事务使用[read](#read)接口查询后未使用[commit](#commit)接口提交或使用[rollback](#rollback)接口回滚，此时其他Transaction实例使用[write](#write)或GraphStore实例使用[GraphStore.write](#write-1)进行写操作时也会返回31300003错误码。

下列API示例中都需先使用[createTransaction](#createtransaction)接口获取到Transaction实例，再通过此实例调用对应方法。

### read

read(gql: string): Promise&lt;Result&gt;

执行数据查询语句。查询范围包括使用[GraphStore.write](#write-1)接口写入的数据、其他事务中使用[write](#write)接口写入并使用[commit](#commit)接口提交的数据以及当前事务中使用[write](#write)接口写入的数据。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

**参数：**

| 参数名 | 类型                          | 必填 | 说明                       |
| ------ | ----------------------------- | ---- | -------------------------- |
| gql  | string  | 是   | 要执行的GQL语句。长度上限为1024 * 1024字节。 |

**返回值**：

| 类型                  | 说明                                              |
| --------------------- | ------------------------------------------------- |
| Promise&lt;[Result](#result)&gt; | Promise对象。如果操作成功，返回GQL语句的执行结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[图数据库错误码](errorcode-data-gdb.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 202  | Permission verification failed, application which is not a system application uses system API. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 31300000  | Inner error. |
| 31300001  | Database corrupted. |
| 31300002  | Already closed. |
| 31300003  | The database is busy. |
| 31300004  | The database is out of memory. |
| 31300005  | The database is full. |
| 31300006  | A duplicate graph name, vertex or edge type, or vertex or edge property name exists. |
| 31300007  | The graph name, vertex or edge type, or vertex or edge property is not defined. |
| 31300008  | The graph name, vertex or edge type, or vertex or edge property name does not conform to constraints. |
| 31300009  | The GQL statement syntax error. |
| 31300010  | The GQL statement semantic error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const QUERY_PATH_GQL = "MATCH path=(a:Person {name : \'name_1\'})-[]->{2, 2}(b:Person {name : \'name_3\'}) RETURN path;";
if(transaction != undefined) {
  (transaction as graphStore.Transaction).read(QUERY_PATH_GQL).then((result: graphStore.Result) => {
    console.info('Read successfully');
    result.records?.forEach((data) => {
      for (let item of Object.entries(data)) {
        const key = item[0];
        const value = item[1];
        const path = value as graphStore.Path;
        console.info(`key : ${key}, path.length : ${path.length}`);
      }
    });
  }).catch((err: BusinessError) => {
    console.error(`Read failed, code is ${err.code}, message is ${err.message}`);
  })
}
```

### write

write(gql: string): Promise&lt;Result&gt;

执行数据写入语句。用于添加、删除和更新数据等。暂不支持修改表结构（[Vertex](#vertex)和[Edge](#edge)的类型或属性）、创建/删除图以及创建/删除索引。不支持使用本接口执行事务操作语句，包括开启事务（START TRANSACTION）、提交事务（COMMIT）以及回滚事务（ROLLBACK）。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

**参数：**

| 参数名 | 类型                          | 必填 | 说明                       |
| ------ | ----------------------------- | ---- | -------------------------- |
| gql  | string  | 是   | 要执行的GQL语句。长度上限为1024 * 1024字节。 |

**返回值**：

| 类型                  | 说明                                              |
| --------------------- | ------------------------------------------------- |
| Promise&lt;[Result](#result)&gt; | Promise对象。如果操作成功，返回GQL语句的执行结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[图数据库错误码](errorcode-data-gdb.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 202  | Permission verification failed, application which is not a system application uses system API. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 31300000  | Inner error. |
| 31300001  | Database corrupted. |
| 31300002  | Already closed. |
| 31300003  | The database is busy. |
| 31300004  | The database is out of memory. |
| 31300005  | The database is full. |
| 31300006  | A duplicate graph name, vertex or edge type, or vertex or edge property name exists. |
| 31300007  | The graph name, vertex or edge type, or vertex or edge property is not defined. |
| 31300008  | The graph name, vertex or edge type, or vertex or edge property name does not conform to constraints. |
| 31300009  | The GQL statement syntax error. |
| 31300010  | The GQL statement semantic error. |
| 31300012  | The number of graph names, vertex or edge types, or vertex or edge properties exceeds the limit. |
| 31300013  | A conflicting constraint already exists. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const INSERT_GQL = "INSERT (:Person {name: 'name_1', age: 11});";
if(transaction != undefined) {
  (transaction as graphStore.Transaction).write(INSERT_GQL).then(() => {
    console.info('Write successfully');
  }).catch((err: BusinessError) => {
    console.error(`Write failed, code is ${err.code}, message is ${err.message}`);
  })
}
```

### commit

commit(): Promise&lt;void&gt;

提交当前事务中已执行的GQL语句，事务提交后，当前事务失效。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

**返回值**：

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[图数据库错误码](errorcode-data-gdb.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 202  | Permission verification failed, application which is not a system application uses system API. |
| 31300000  | Inner error. |
| 31300001  | Database corrupted. |
| 31300002  | Already closed. |
| 31300003  | The database is busy. |
| 31300004  | The database is out of memory. |
| 31300005  | The database is full. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if(transaction != undefined) {
  (transaction as graphStore.Transaction).commit().then(() => {
    console.info(`Commit successfully`);
  }).catch ((err: BusinessError) => {
    console.error(`Commit failed, code is ${err.code}, message is ${err.message}`);
  })
}
```

### rollback

rollback(): Promise&lt;void&gt;

回滚当前事务中已执行的GQL语句，事务回滚后，当前事务失效。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

**返回值**：

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[图数据库错误码](errorcode-data-gdb.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 202  | Permission verification failed, application which is not a system application uses system API. |
| 31300000  | Inner error. |
| 31300001  | Database corrupted. |
| 31300002  | Already closed. |
| 31300003  | The database is busy. |
| 31300004  | The database is out of memory. |
| 31300005  | The database is full. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if(transaction != undefined) {
  (transaction as graphStore.Transaction).rollback().then(() => {
    console.info(`Rollback successfully`);
  }).catch ((err: BusinessError) => {
    console.error(`Rollback failed, code is ${err.code}, message is ${err.message}`);
  })
}
```


## GraphStore

提供管理图数据库(GDB)方法的接口。

下列API示例中都需先使用[getStore](#graphstoregetstore)接口获取到GraphStore实例，再通过此实例调用对应方法。

### read

read(gql: string): Promise&lt;Result&gt;

执行数据查询语句。查询范围包括使用[write](#write-1)接口写入的数据以及所有事务中使用[Transaction.write](#write)接口写入并使用[Transaction.commit](#commit)接口提交的数据。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

**参数：**

| 参数名 | 类型                          | 必填 | 说明                       |
| ------ | ----------------------------- | ---- | -------------------------- |
| gql  | string  | 是   | 要执行的GQL语句。长度上限为1024 * 1024字节。 |

**返回值**：

| 类型                  | 说明                                              |
| --------------------- | ------------------------------------------------- |
| Promise&lt;[Result](#result)&gt; | Promise对象。如果操作成功，返回GQL语句执行结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[图数据库错误码](errorcode-data-gdb.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 202  | Permission verification failed, application which is not a system application uses system API. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 31300000  | Inner error. |
| 31300001  | Database corrupted. |
| 31300002  | Already closed. |
| 31300003  | The database is busy. |
| 31300004  | The database is out of memory. |
| 31300005  | The database is full. |
| 31300006  | A duplicate graph name, vertex or edge type, or vertex or edge property name exists. |
| 31300007  | The graph name, vertex or edge type, or vertex or edge property is not defined. |
| 31300008  | The graph name, vertex or edge type, or vertex or edge property name does not conform to constraints. |
| 31300009  | The GQL statement syntax error. |
| 31300010  | The GQL statement semantic error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const QUERY_PATH_GQL = "MATCH path=(a:Person {name : \'name_1\'})-[]->{2, 2}(b:Person {name : \'name_3\'}) RETURN path;";
if(store != null) {
  (store as graphStore.GraphStore).read(QUERY_PATH_GQL).then((result: graphStore.Result) => {
    console.info('Read successfully');
    result.records?.forEach((data) => {
      for (let item of Object.entries(data)) {
        const key = item[0];
        const value = item[1];
        const path = value as graphStore.Path;
        console.info(`key : ${key}, path.length : ${path.length}`);
      }
    });
  }).catch((err: BusinessError) => {
    console.error(`Read failed, code is ${err.code}, message is ${err.message}`);
  })
}
```

### write

write(gql: string): Promise&lt;Result&gt;

执行数据写入语句。用于创建图、删除图、增删改数据等。暂不支持修改表结构（[Vertex](#vertex)和[Edge](#edge)的类型或属性）。不支持使用本接口执行事务操作语句，包括开启事务（START TRANSACTION）、提交事务（COMMIT）以及回滚事务（ROLLBACK）。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

**参数：**

| 参数名 | 类型                          | 必填 | 说明                       |
| ------ | ----------------------------- | ---- | -------------------------- |
| gql  | string  | 是   | 要执行的GQL语句。长度上限为1024 * 1024字节。 |

**返回值**：

| 类型                  | 说明                                              |
| --------------------- | ------------------------------------------------- |
| Promise&lt;[Result](#result)&gt; | Promise对象。如果操作成功，返回GQL语句执行结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[图数据库错误码](errorcode-data-gdb.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 202  | Permission verification failed, application which is not a system application uses system API. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 31300000  | Inner error. |
| 31300001  | Database corrupted. |
| 31300002  | Already closed. |
| 31300003  | The database is busy. |
| 31300004  | The database is out of memory. |
| 31300005  | The database is full. |
| 31300006  | A duplicate graph name, vertex or edge type, or vertex or edge property name exists. |
| 31300007  | The graph name, vertex or edge type, or vertex or edge property is not defined. |
| 31300008  | The graph name, vertex or edge type, or vertex or edge property name does not conform to constraints. |
| 31300009  | The GQL statement syntax error. |
| 31300010  | The GQL statement semantic error. |
| 31300012  | The number of graph names, vertex or edge types, or vertex or edge properties exceeds the limit. |
| 31300013  | A conflicting constraint already exists. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const CREATE_GRAPH_GQL = "CREATE GRAPH test { (person:Person {name STRING, age INT}),(person)-[:Friend {year INT}]->(person) };"
if(store != null) {
  (store as graphStore.GraphStore).write(CREATE_GRAPH_GQL).then(() => {
    console.info('Write successfully');
  }).catch((err: BusinessError) => {
    console.error(`Write failed, code is ${err.code}, message is ${err.message}`);
  })
}
```

### createTransaction

createTransaction(): Promise&lt;Transaction&gt;

创建事务实例。当前图数据库同一时刻最多只能创建4个事务实例。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

**返回值**：

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;[Transaction](#transaction)&gt; | Promise对象。如果操作成功，返回创建的事务实例。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[图数据库错误码](errorcode-data-gdb.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 202  | Permission verification failed, application which is not a system application uses system API. |
| 31300000  | Inner error. |
| 31300001  | Database corrupted. |
| 31300002  | Already closed. |
| 31300003  | The database is busy. |
| 31300004  | The database is out of memory. |
| 31300005  | The database is full. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let transaction: graphStore.Transaction | undefined = undefined;

if(store != null) {
  (store as graphStore.GraphStore).createTransaction().then((trans: graphStore.Transaction) => {
    transaction = trans;
    console.info('createTransaction successfully');
  }).catch((err: BusinessError) => {
    console.error(`createTransaction failed, code is ${err.code}, message is ${err.message}`);
  })
}
```

### close

close(): Promise&lt;void&gt;

关闭图数据库（GDB），未提交的事务将被回滚。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

**返回值**：

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[图数据库错误码](errorcode-data-gdb.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 202  | Permission verification failed, application which is not a system application uses system API. |
| 31300000  | Inner error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if(store != null) {
  (store as graphStore.GraphStore).close().then(() => {
    console.info(`Close successfully`);
  }).catch ((err: BusinessError) => {
    console.error(`Close failed, code is ${err.code}, message is ${err.message}`);
  })
}
```