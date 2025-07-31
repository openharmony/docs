# 批量数据写数据库场景
<!--Kit: ArkTS-->
<!--Subsystem: commonlibrary-->
<!--Owner: @lijiamin2025-->
<!--SE: @weng-changcheng-->
<!--TSE: @kirl75; @zsw_zhushiwei-->

## 使用TaskPool进行频繁数据库操作

对于需要频繁数据库操作的场景，由于读写数据库存在耗时，因此推荐在子线程中操作，避免阻塞UI线程。

通过ArkTS提供的TaskPool能力，可以将数据库操作任务移到子线程中，实现如下。

1. 创建多个子任务，支持数据库的创建、插入、查询和清除等操作。

2. UI主线程发起数据库操作请求，在子线程中完成数据库的增删改查等操作。

```ts
// Index.ets
import { relationalStore, ValuesBucket } from '@kit.ArkData';
import { taskpool } from '@kit.ArkTS';

@Concurrent
async function create(context: Context) {
  const CONFIG: relationalStore.StoreConfig = {
    name: "Store.db",
    securityLevel: relationalStore.SecurityLevel.S1,
  };

  // 默认数据库文件路径为 context.databaseDir + rdb + StoreConfig.name
  let store: relationalStore.RdbStore = await relationalStore.getRdbStore(context, CONFIG);
  console.info(`Create Store.db successfully!`);

  // 创建表
  const CREATE_TABLE_SQL = "CREATE TABLE IF NOT EXISTS test (" +
    "id INTEGER PRIMARY KEY AUTOINCREMENT, " +
    "name TEXT NOT NULL, " +
    "age INTEGER, " +
    "salary REAL, " +
    "blobType BLOB)";
  await store.executeSql(CREATE_TABLE_SQL);
  console.info(`Create table test successfully!`);
}

@Concurrent
async function insert(context: Context, valueBucketArray: Array<relationalStore.ValuesBucket>) {
  const CONFIG: relationalStore.StoreConfig = {
    name: "Store.db",
    securityLevel: relationalStore.SecurityLevel.S1,
  };

  // 默认数据库文件路径为 context.databaseDir + rdb + StoreConfig.name
  let store: relationalStore.RdbStore = await relationalStore.getRdbStore(context, CONFIG);
  console.info(`Create Store.db successfully!`);

  // 数据插入
  await store.batchInsert("test", valueBucketArray as Object as Array<relationalStore.ValuesBucket>);
}

@Concurrent
async function query(context: Context): Promise<Array<relationalStore.ValuesBucket>> {
  const CONFIG: relationalStore.StoreConfig = {
    name: "Store.db",
    securityLevel: relationalStore.SecurityLevel.S1,
  };

  // 默认数据库文件路径为 context.databaseDir + rdb + StoreConfig.name
  let store: relationalStore.RdbStore = await relationalStore.getRdbStore(context, CONFIG);
  console.info(`Create Store.db successfully!`);

  // 获取结果集
  let predicates: relationalStore.RdbPredicates = new relationalStore.RdbPredicates("test");
  // 查询所有数据
  let resultSet = await store.query(predicates);
  console.info(`Query data successfully! row count:${resultSet.rowCount}`);
  let index = 0;
  let result = new Array<relationalStore.ValuesBucket>(resultSet.rowCount)
  resultSet.goToFirstRow()
  do {
    result[index++] = resultSet.getRow()
  } while (resultSet.goToNextRow());
  resultSet.close();
  return result
}

@Concurrent
async function clear(context: Context) {
  const CONFIG: relationalStore.StoreConfig = {
    name: "Store.db",
    securityLevel: relationalStore.SecurityLevel.S1,
  };

  // 默认数据库文件路径为 context.databaseDir + rdb + StoreConfig.name
  await relationalStore.deleteRdbStore(context, CONFIG);
  console.info(`Delete Store.db successfully!`);
}

@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  build() {
    RelativeContainer() {
      Text(this.message)
        .id('HelloWorld')
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
        .alignRules({
          center: { anchor: '__container__', align: VerticalAlign.Center },
          middle: { anchor: '__container__', align: HorizontalAlign.Center }
        })
        .onClick(async () => {
          let context : Context = this.getUIContext().getHostContext() as Context;

          // 数据准备
          const count = 5
          let valueBucketArray = new Array<relationalStore.ValuesBucket>(count);
          for (let i = 0; i < count; i++) {
            let v : relationalStore.ValuesBucket = {
              id: i,
              name: "zhangsan" + i,
              age: 20,
              salary: 5000 + 50 * i
            };
            valueBucketArray[i] = v;
          }
          await taskpool.execute(create, context)
          await taskpool.execute(insert, context, valueBucketArray)
          let index = 0
          let ret = await taskpool.execute(query, context) as Array<relationalStore.ValuesBucket>
          for (let v of ret) {
            console.info(`Row[${index}].id = ${v.id}`)
            console.info(`Row[${index}].name = ${v.name}`)
            console.info(`Row[${index}].age = ${v.age}`)
            console.info(`Row[${index}].salary = ${v.salary}`)
            index++
          }
          await taskpool.execute(clear, context)
        })
    }
    .height('100%')
    .width('100%')
  }
}
```
<!-- @[taskpool_frequently_operate_database](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ApplicationMultithreadingDevelopment/PracticalCases/entry/src/main/ets/managers/UsingSendable.ets) -->

## 使用Sendable进行大容量数据库操作

由于数据库数据跨线程传递存在耗时，数据量较大时会占用UI主线程。推荐使用Sendable封装数据库数据，以降低跨线程开销。

1. 定义数据库中的数据格式，可以使用Sendable，以减少跨线程操作的耗时。

   ```ts
   // SharedValuesBucket.ets
   export interface IValueBucket {
     id: number
     name: string
     age: number
     salary: number
   }
   
   @Sendable
   export class SharedValuesBucket implements IValueBucket {
     id: number = 0
     name: string = ""
     age: number = 0
     salary: number = 0
   
     constructor(v: IValueBucket) {
       this.id = v.id;
       this.name = v.name;
       this.age = v.age;
       this.salary = v.salary
     }
   }
   ```
   <!-- @[define_data_format](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ApplicationMultithreadingDevelopment/PracticalCases/entry/src/main/ets/managers/SharedValuesBucket.ets) -->

2. UI主线程发起数据库操作请求，在子线程完成数据的增删改查等操作。

   ```ts
   // Index.ets
   import { relationalStore, ValuesBucket } from '@kit.ArkData';
   import { collections, taskpool } from '@kit.ArkTS';
   import { IValueBucket, SharedValuesBucket } from './SharedValuesBucket';
   
   @Concurrent
   async function create(context: Context) {
     const CONFIG: relationalStore.StoreConfig = {
       name: "Store.db",
       securityLevel: relationalStore.SecurityLevel.S1,
     };
   
     // 默认数据库文件路径为 context.databaseDir + rdb + StoreConfig.name
     let store: relationalStore.RdbStore = await relationalStore.getRdbStore(context, CONFIG);
     console.info(`Create Store.db successfully!`);
   
     // 创建表
     const CREATE_TABLE_SQL = "CREATE TABLE IF NOT EXISTS test (" +
       "id INTEGER PRIMARY KEY AUTOINCREMENT, " +
       "name TEXT NOT NULL, " +
       "age INTEGER, " +
       "salary REAL, " +
       "blobType BLOB)";
     await store.executeSql(CREATE_TABLE_SQL);
     console.info(`Create table test successfully!`);
   }
   
   @Concurrent
   async function insert(context: Context, valueBucketArray: collections.Array<SharedValuesBucket | undefined>) {
     const CONFIG: relationalStore.StoreConfig = {
       name: "Store.db",
       securityLevel: relationalStore.SecurityLevel.S1,
     };
   
     // 默认数据库文件路径为 context.databaseDir + rdb + StoreConfig.name
     let store: relationalStore.RdbStore = await relationalStore.getRdbStore(context, CONFIG);
     console.info(`Create Store.db successfully!`);
   
     // 数据插入
     await store.batchInsert("test", valueBucketArray as Object as Array<ValuesBucket>);
   }
   
   @Concurrent
   async function query(context: Context): Promise<collections.Array<SharedValuesBucket | undefined>> {
     const CONFIG: relationalStore.StoreConfig = {
       name: "Store.db",
       securityLevel: relationalStore.SecurityLevel.S1,
     };
   
     // 默认数据库文件路径为 context.databaseDir + rdb + StoreConfig.name
     let store: relationalStore.RdbStore = await relationalStore.getRdbStore(context, CONFIG);
     console.info(`Create Store.db successfully!`);
   
     // 获取结果集
     let predicates: relationalStore.RdbPredicates = new relationalStore.RdbPredicates("test");
     // 查询所有数据
     let resultSet = await store.query(predicates);
     console.info(`Query data successfully! row count:${resultSet.rowCount}`);
     let index = 0;
     let result = collections.Array.create<SharedValuesBucket | undefined>(resultSet.rowCount, undefined)
     resultSet.goToFirstRow()
     do {
       let v: IValueBucket = {
         id: resultSet.getLong(resultSet.getColumnIndex("id")),
         name: resultSet.getString(resultSet.getColumnIndex("name")),
         age: resultSet.getLong(resultSet.getColumnIndex("age")),
         salary: resultSet.getLong(resultSet.getColumnIndex("salary"))
       };
       result[index++] = new SharedValuesBucket(v)
     } while (resultSet.goToNextRow());
     resultSet.close();
     return result
   }
   
   @Concurrent
   async function clear(context: Context) {
     const CONFIG: relationalStore.StoreConfig = {
       name: "Store.db",
       securityLevel: relationalStore.SecurityLevel.S1,
     };
   
     // 默认数据库文件路径为 context.databaseDir + rdb + StoreConfig.name
     await relationalStore.deleteRdbStore(context, CONFIG);
     console.info(`Delete Store.db successfully!`);
   }
   
   @Entry
   @Component
   struct Index {
     @State message: string = 'Hello World';
   
     build() {
       RelativeContainer() {
         Text(this.message)
           .id('HelloWorld')
           .fontSize(50)
           .fontWeight(FontWeight.Bold)
           .alignRules({
             center: { anchor: '__container__', align: VerticalAlign.Center },
             middle: { anchor: '__container__', align: HorizontalAlign.Center }
           })
           .onClick(async () => {
             let context : Context = this.getUIContext().getHostContext() as Context;
   
             // 数据准备
             const count = 5
             let valueBucketArray = collections.Array.create<SharedValuesBucket | undefined>(count, undefined);
             for (let i = 0; i < count; i++) {
               let v: IValueBucket = {
                 id: i,
                 name: "zhangsan" + i,
                 age: 20,
                 salary: 5000 + 50 * i
               };
               valueBucketArray[i] = new SharedValuesBucket(v);
             }
             await taskpool.execute(create, context)
             await taskpool.execute(insert, context, valueBucketArray)
             let index = 0
             let ret: collections.Array<SharedValuesBucket> =
               await taskpool.execute(query, context) as collections.Array<SharedValuesBucket>
             for (let v of ret.values()) {
               console.info(`Row[${index}].id = ${v.id}`)
               console.info(`Row[${index}].name = ${v.name}`)
               console.info(`Row[${index}].age = ${v.age}`)
               console.info(`Row[${index}].salary = ${v.salary}`)
               index++
             }
             await taskpool.execute(clear, context)
           })
       }
       .height('100%')
       .width('100%')
     }
   }
   ```
   <!-- @[operate_child_thread_data](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ApplicationMultithreadingDevelopment/PracticalCases/entry/src/main/ets/managers/UsingTaskPool.ets) -->

## 复杂类实例对象使用Sendable进行大容量数据库操作

普通类实例对象的属性可持有Sendable类实例对象。

对于复杂的普通类实例对象，可以先将相应数据库数据字段封装为Sendable类实例对象，再由普通类实例对象持有，从而降低跨线程开销。

1. 定义数据库中的数据格式，采用Sendable，减少跨线程耗时。

   ```ts
   // SharedValuesBucket.ets
   export interface IValueBucket {
     id: number;
     name: string;
     age: number;
     salary: number;
   }
   
   @Sendable
   export class SharedValuesBucket implements IValueBucket {
     id: number = 0;
     name: string = "";
     age: number = 0;
     salary: number = 0;
   
     constructor(v: IValueBucket) {
       this.id = v.id;
       this.name = v.name;
       this.age = v.age;
       this.salary = v.salary;
     }
   }
   ```

2. 定义普通类实例对象，持有Sendable类实例对象。

   ```ts
   // Material.ets
   import { SharedValuesBucket } from './SharedValuesBucket';
   import { collections } from '@kit.ArkTS';

   export class Material {
     seq: number = 0;
     materialName: string = "";
     // ... 省略其他属性
     buckets: collections.Array<SharedValuesBucket | undefined>;

     constructor(seq: number, materialName: string, buckets: collections.Array<SharedValuesBucket | undefined>) {
       this.seq = seq;
       this.materialName = materialName;
       this.buckets = buckets;
     }

     getBuckets() : collections.Array<SharedValuesBucket | undefined>{
       return this.buckets;
     }

     setBuckets(buckets: collections.Array<SharedValuesBucket | undefined>) {
       this.buckets = buckets;
     }
   }
   ```

3. UI主线程发起数据库操作请求，在子线程进行数据的增删改查等操作。

   ```ts
   // Index.ets
   import { relationalStore, ValuesBucket } from '@kit.ArkData';
   import { collections, taskpool } from '@kit.ArkTS';
   import { IValueBucket, SharedValuesBucket } from './SharedValuesBucket';
   import { Material } from './Material';

   @Concurrent
   async function create(context: Context) {
     const CONFIG: relationalStore.StoreConfig = {
       name: "Store.db",
       securityLevel: relationalStore.SecurityLevel.S1,
     };

     // 默认数据库文件路径为 context.databaseDir + rdb + StoreConfig.name
     let store: relationalStore.RdbStore = await relationalStore.getRdbStore(context, CONFIG);
     console.info(`Create Store.db successfully!`);

     // 创建表
     const CREATE_TABLE_SQL = "CREATE TABLE IF NOT EXISTS test (" +
       "id INTEGER PRIMARY KEY AUTOINCREMENT, " +
       "name TEXT NOT NULL, " +
       "age INTEGER, " +
       "salary REAL, " +
       "blobType BLOB)";
     await store.executeSql(CREATE_TABLE_SQL);
     console.info(`Create table test successfully!`);
   }

   @Concurrent
   async function insert(context: Context, valueBucketArray: collections.Array<SharedValuesBucket | undefined>) {
     const CONFIG: relationalStore.StoreConfig = {
       name: "Store.db",
       securityLevel: relationalStore.SecurityLevel.S1,
     };

     // 默认数据库文件路径为 context.databaseDir + rdb + StoreConfig.name
     let store: relationalStore.RdbStore = await relationalStore.getRdbStore(context, CONFIG);
     console.info(`Create Store.db successfully!`);

     // 数据插入
     await store.batchInsert("test", valueBucketArray as Object as Array<ValuesBucket>);
   }

   @Concurrent
   async function query(context: Context): Promise<collections.Array<SharedValuesBucket | undefined>> {
     const CONFIG: relationalStore.StoreConfig = {
       name: "Store.db",
       securityLevel: relationalStore.SecurityLevel.S1,
     };

     // 默认数据库文件路径为 context.databaseDir + rdb + StoreConfig.name
     let store: relationalStore.RdbStore = await relationalStore.getRdbStore(context, CONFIG);
     console.info(`Create Store.db successfully!`);

     // 获取结果集
     let predicates: relationalStore.RdbPredicates = new relationalStore.RdbPredicates("test");
     // 查询所有数据
     let resultSet = await store.query(predicates);
     console.info(`Query data successfully! row count:${resultSet.rowCount}`);
     let index = 0;
     let result = collections.Array.create<SharedValuesBucket | undefined>(resultSet.rowCount, undefined)
     resultSet.goToFirstRow()
     do {
       let v: IValueBucket = {
         id: resultSet.getLong(resultSet.getColumnIndex("id")),
         name: resultSet.getString(resultSet.getColumnIndex("name")),
         age: resultSet.getLong(resultSet.getColumnIndex("age")),
         salary: resultSet.getLong(resultSet.getColumnIndex("salary"))
       };
       result[index++] = new SharedValuesBucket(v)
     } while (resultSet.goToNextRow());
     resultSet.close();
     return result
   }

   @Concurrent
   async function clear(context: Context) {
     const CONFIG: relationalStore.StoreConfig = {
       name: "Store.db",
       securityLevel: relationalStore.SecurityLevel.S1,
     };

     // 默认数据库文件路径为 context.databaseDir + rdb + StoreConfig.name
     await relationalStore.deleteRdbStore(context, CONFIG);
     console.info(`Delete Store.db successfully!`);
   }

   function initMaterial() : Material {
     // 数据准备
     const count = 5
     let valueBucketArray = collections.Array.create<SharedValuesBucket | undefined>(count, undefined);
     for (let i = 0; i < count; i++) {
       let v: IValueBucket = {
         id: i,
         name: "zhangsan" + i,
         age: 20,
         salary: 5000 + 50 * i
       };
       valueBucketArray[i] = new SharedValuesBucket(v);
     }
     let material = new Material(1, "test", valueBucketArray);
     return material;
   }

   @Entry
   @Component
   struct Index {
     @State message: string = 'Hello World';

     build() {
       RelativeContainer() {
         Text(this.message)
           .id('HelloWorld')
           .fontSize(50)
           .fontWeight(FontWeight.Bold)
           .alignRules({
             center: { anchor: '__container__', align: VerticalAlign.Center },
             middle: { anchor: '__container__', align: HorizontalAlign.Center }
           })
           .onClick(async () => {
             let context : Context = this.getUIContext().getHostContext() as Context;
             let material = initMaterial();
             await taskpool.execute(create, context);
             await taskpool.execute(insert, context, material.getBuckets());
             let index = 0;
             let ret: collections.Array<SharedValuesBucket> =
               await taskpool.execute(query, context) as collections.Array<SharedValuesBucket>;
             material.setBuckets(ret);
             for (let v of ret.values()) {
               console.info(`Row[${index}].id = ${v.id}`);
               console.info(`Row[${index}].name = ${v.name}`);
               console.info(`Row[${index}].age = ${v.age}`);
               console.info(`Row[${index}].salary = ${v.salary}`);
               index++;
             }
             await taskpool.execute(clear, context);
           })
       }
       .height('100%')
       .width('100%')
     }
   }
   ```