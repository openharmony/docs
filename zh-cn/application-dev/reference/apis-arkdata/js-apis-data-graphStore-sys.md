# @ohos.data.graphStore (图数据库)(系统接口)

图数据库（Graph Database，GDB）是一种基于图论为数据基础的数据管理系统。图数据库提供了一套完整的对本地数据库进行管理的机制，对外提供了一系列的读、写等接口，可以直接运行用户输入的GQL（Graph Query Language，图查询语言）语句来满足复杂的场景需要。

该模块提供以下图数据库相关的常用功能：

- [GraphStore](#graphstore)：提供管理图数据库(GDB)方法的接口。
- [Result](#result)：提供用户调用图数据库读、写接口之后返回的结果。

> **说明：**
> 
> - 本模块首批接口从API version 16开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 当前页面仅包含本模块的系统接口。

## 导入模块

```ts
import { graphStore } from '@kit.ArkData';
```

## graphStore.getStore

getStore(context: Context, config: StoreConfig): Promise&lt;GraphStore&gt;

获得一个相关的GraphStore实例，操作图数据库，用户可以根据自己的需求配置GraphStore实例的参数，然后通过GraphStore实例调用相关接口可以执行相关的数据操作，使用promise异步回调。

getStore目前不支持多线程并发操作。

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
| 31300014  | Invalid database path. |
| 31300015  | Config changed. |

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
      console.info('Get GraphStore successfully.')
    }).catch((err: BusinessError) => {
      console.error(`Get GraphStore failed, code is ${err.code}, message is ${err.message}`);
    })
  }
}
```

## graphStore.deleteStore

deleteStore(context: Context, config: StoreConfig): Promise&lt;void&gt;

使用指定的数据库文件配置删除数据库，使用Promise异步回调。

删除成功后，建议将数据库对象置为null。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

**参数**

| 参数名  | 类型    | 必填 | 说明                                                         |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| context | Context                          | 是   | 应用的上下文，推荐使用Stage模型。 <br>FA模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-app-context.md)。<br>Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md)。 |
| config  | [StoreConfig](#storeconfig) | 是   | 与此GDB存储相关的数据库配置。                                |

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
| 31300014  | Invalid database path. |

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
  onWindowStageCreate(windowStage: window.WindowStage){
    graphStore.deleteStore(this.context, STORE_CONFIG).then(()=>{
      store = null;
      console.info('Delete GraphStore successfully.');
    }).catch((err: BusinessError) => {
      console.error(`Delete GraphStore failed, code is ${err.code},message is ${err.message}`);
    })
  }
}
```

## StoreConfig

管理图数据库配置。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

| 名称        | 类型          | 必填 | 说明                                                      |
| ------------- | ------------- | ---- | --------------------------------------------------------- |
| name          | string        | 是   | 数据库文件名，也是数据库唯一标识符。<br/>**使用约束：** <br/>1. 文件名长度上限为255字节。<br/>2. 文件名不包含.db后缀。 |
| securityLevel | [SecurityLevel](#securitylevel) | 是   | 设置数据库安全级别。<br/>**使用约束：** <br/>1. 安全级别不支持从高到低变更。<br/>2. 同一个数据库如果需要变更安全等级，需要使用[GraphStore.close](#close)接口关闭数据库，再将修改安全等级后的StoreConfig作为参数重新调用[graphStore.getStore](#graphstoregetstore)。 |

## SecurityLevel

数据库的安全级别枚举。请使用枚举名称而非枚举值。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

| 名称 | 值   | 说明                                                         |
| ---- | ---- | ------------------------------------------------------------ |
| S1   | 1    | 表示数据库的安全级别为低级别，当数据泄露时会产生较低影响。 |
| S2   | 2    | 表示数据库的安全级别为中级别，当数据泄露时会产生较大影响。 |
| S3   | 3    | 表示数据库的安全级别为高级别，当数据泄露时会产生重大影响。 |
| S4   | 4    | 表示数据库的安全级别为关键级别，当数据泄露时会产生严重影响。 |

## ValueType

type ValueType = null | number | string

用于表示允许的数据字段类型，接口参数具体类型根据其功能而定。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

| 类型    | 说明                 |
| ------- | -------------------- |
| null    | 表示值类型为空。 |
| number  | 表示值类型为数字，可取任意值。 |
| string  | 表示值类型为字符，可取任意值。 |

## Vertex

记录顶点的相关信息。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

| 名称          | 类型                          | 必填  | 说明           |
| ----------- | --------------------------- | --- | ------------ |
| vid        | string | 是   | 顶点的标识符。不支持自定义填写，使用[write](#write)接口插入顶点后由底层分配的全局唯一标识符。 |
| labels     | Array&lt;string&gt; | 是   | 顶点的标签。在创建图的GQL语句中指定，每个元素长度上限为128字节。 |
| properties | Record&lt;string, [ValueType](#valuetype)&gt; | 是   | 顶点的属性。在创建图的GQL语句中指定，key长度上限为128字节，数量上限为1024条，value类型为string时长度上限为64 * 1024字节。 |

## Edge

记录边的相关信息。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

| 名称          | 类型                          | 必填  | 说明           |
| ----------- | --------------------------- | --- | ------------ |
| eid        | string | 是   | 边的标识符。不支持自定义填写，使用[write](#write)接口插入边后由底层分配的全局唯一标识符。 |
| type       | string | 是   | 边的类型。在创建图的GQL语句中指定，长度上限为128字节。 |
| startVid   | string | 是   | 起始顶点的标识符。不支持自定义填写，使用[write](#write)接口插入顶点后由底层分配的全局唯一标识符。 |
| endVid     | string | 是   | 终点的标识符。不支持自定义填写，使用[write](#write)接口插入顶点后由底层分配的全局唯一标识符。 |
| properties | Record&lt;string, [ValueType](#valuetype)&gt; | 是   | 边的属性。在创建图的GQL语句中指定，key长度上限为128字节，数量上限为1024条，value类型为string时长度上限为64 * 1024字节。 |

## PathSegment

记录路径段（路径中的每条边及其起点、终点）的相关信息。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

| 名称          | 类型                          | 必填  | 说明           |
| ----------- | --------------------------- | --- | ------------ |
| start | [Vertex](#vertex) | 是   | 路径段的起始顶点。 |
| end   | [Vertex](#vertex) | 是   | 路径段的终点。 |
| edge  | [Edge](#edge)     | 是   | 路径段的边。 |

## Path

记录路径的相关信息。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

| 名称          | 类型                          | 必填  | 说明           |
| ----------- | --------------------------- | --- | ------------ |
| start    | [Vertex](#vertex) | 是   | 路径的起始顶点。 |
| end      | [Vertex](#vertex) | 是   | 路径的终点。 |
| length   | number            | 是   | 路径的长度，即路径中路径段的数量（segments.length），上限为1024条。 |
| segments | Array&lt;[PathSegment](#pathsegment)&gt; | 是   | 路径中所有路径段。 |

## Result

GQL语句执行结果。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

| 名称          | 类型                          | 必填  | 说明           |
| ----------- | --------------------------- | --- | ------------ |
| records | Array&lt;Record&lt;string, Object&gt;&gt; | 否   | GQL语句执行结果的数据记录。默认值为空。<br/>如果有执行结果，Object具体类型根据查询GQL语句不同，可能是[Vertex](#vertex)，[Edge](#edge)，[Path](#path)或[ValueType](#valuetype) |


## GraphStore

提供管理图数据库(GDB)方法的接口。

### read

read(gql: string): Promise&lt;Result&gt;

执行查询过程。

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
| 31300006  | Duplicate type or properties name of vertex and edge. |
| 31300007  | The type or properties of vertex and edge is not defined. |
| 31300008  | The type or properties name of vertex and edge does not conform to constraint. |
| 31300009  | The GQL statement syntax error. |
| 31300010  | The GQL statement semantic error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const QUERY_PATH_GQL = "MATCH path=(a:Person {name : \'name_1\'})-[]->{2, 2}(b:Person {name : \'name_3\'}) RETURN path;"
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

执行数据修改或表结构修改过程。

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
| 31300006  | Duplicate type or properties name of vertex and edge. |
| 31300007  | The type or properties of vertex and edge is not defined. |
| 31300008  | The type or properties name of vertex and edge does not conform to constraint. |
| 31300009  | The GQL statement syntax error. |
| 31300010  | The GQL statement semantic error. |
| 31300012  | The number of types or properties of vertex and edge exceeds the upper limit. |
| 31300013  | A conflicting constraint already exists. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const CREATE_GRAPH_GQL = "CREATE GRAPH test { (person:Person {name STRING, age INT}),(person)-[:Friend]->(person) };"
if(store != null) {
  (store as graphStore.GraphStore).write(CREATE_GRAPH_GQL).then(() => {
    console.info('Write successfully');
  }).catch((err: BusinessError) => {
    console.error(`Write failed, code is ${err.code}, message is ${err.message}`);
  })
}
```

### close

close(): Promise&lt;void&gt;

关闭图数据库（GDB）。

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