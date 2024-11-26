# Batch Data Writing to the Database

## Using TaskPool for Frequent Database Operations

In scenarios where frequent database operations are required, it is time-consuming to read and write the database. Therefore, you are advised to perform operations in sub-threads to avoid blocking the UI thread.

The TaskPool capability provided by ArkTS can be used to move database operation tasks to subthreads. The implementation is as follows:

1. Create multiple subtasks and supports operations such as database creation, insertion, query, and clearing.

2. The UI main thread calls subtasks to perform database operations such as adding, deleting, modifying, and querying data.

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

  // The default database file path is context.databaseDir + rdb + StoreConfig.name.
  let store: relationalStore.RdbStore = await relationalStore.getRdbStore(context, CONFIG);
  console.info(`Create Store.db successfully!`);

  // Create a table.
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

  // The default database file path is context.databaseDir + rdb + StoreConfig.name.
  let store: relationalStore.RdbStore = await relationalStore.getRdbStore(context, CONFIG);
  console.info(`Create Store.db successfully!`);

  // Insert data.
  await store.batchInsert("test", valueBucketArray as Object as Array<relationalStore.ValuesBucket>);
}

@Concurrent
async function query(context: Context): Promise<Array<relationalStore.ValuesBucket>> {
  const CONFIG: relationalStore.StoreConfig = {
    name: "Store.db",
    securityLevel: relationalStore.SecurityLevel.S1,
  };

  // The default database file path is context.databaseDir + rdb + StoreConfig.name.
  let store: relationalStore.RdbStore = await relationalStore.getRdbStore(context, CONFIG);
  console.info(`Create Store.db successfully!`);

  // Obtain the result set.
  let predicates: relationalStore.RdbPredicates = new relationalStore.RdbPredicates("test");
  let resultSet = await store.query (predicates); // Query all data.
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

  // The default database file path is context.databaseDir + rdb + StoreConfig.name.
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
          let context = getContext(this);

          // Prepare data.
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

## Using Sendable for Large-Capacity Database Operations

It takes a long time to transfer database data across threads. When the data volume is large, the UI main thread is still occupied. You are advised to use Sendable to encapsulate database data to reduce the cross-thread overhead.

1. Define the data format in the database. Sendable can be used to reduce the cross-thread time consumption.

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

2. Initiated by the UI main thread to add, delete, modify, and query data in subthreads.

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
   
     // The default database file path is context.databaseDir + rdb + StoreConfig.name.
     let store: relationalStore.RdbStore = await relationalStore.getRdbStore(context, CONFIG);
     console.info(`Create Store.db successfully!`);
   
     // Create a table.
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
   
     // The default database file path is context.databaseDir + rdb + StoreConfig.name.
     let store: relationalStore.RdbStore = await relationalStore.getRdbStore(context, CONFIG);
     console.info(`Create Store.db successfully!`);
   
     // Insert data.
     await store.batchInsert("test", valueBucketArray as Object as Array<ValuesBucket>);
   }
   
   @Concurrent
   async function query(context: Context): Promise<collections.Array<SharedValuesBucket | undefined>> {
     const CONFIG: relationalStore.StoreConfig = {
       name: "Store.db",
       securityLevel: relationalStore.SecurityLevel.S1,
     };
   
     // The default database file path is context.databaseDir + rdb + StoreConfig.name.
     let store: relationalStore.RdbStore = await relationalStore.getRdbStore(context, CONFIG);
     console.info(`Create Store.db successfully!`);
   
     // Obtain the result set.
     let predicates: relationalStore.RdbPredicates = new relationalStore.RdbPredicates("test");
     let resultSet = await store.query (predicates); // Query all data.
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
   
     // The default database file path is context.databaseDir + rdb + StoreConfig.name.
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
             let context = getContext(this);
   
             // Prepare data.
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
