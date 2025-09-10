# Persisting RDB Store Data (ArkTS)
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @baijidong-->
<!--Designer: @widecode; @htt1997-->
<!--Tester: @yippo; @logic42-->
<!--Adviser: @ge-yafang-->


## When to Use

A relational database (RDB) store is used to store data in complex relational models, such as the student information including names, student IDs, and scores of each subject, or employee information including names, employee IDs, and positions, based on SQLite. The data is more complex than key-value (KV) pairs due to strict mappings. You can use **RelationalStore** to implement persistence of this type of data.

Querying data from a large amount of data may take time or even cause application suspension. In this case, you can perform batch operations. For details, see [Batch Database Operations](../arkts-utils/batch-database-operations-guide.md). Moreover, observe the following:
- The maximum number of data records to query at a time is 5000.
- Use [TaskPool](../reference/apis-arkts/js-apis-taskpool.md) if there is a large amount of data needs to be queried.
- Keep concatenated SQL statements as concise as possible.
- Query data in batches.

## Basic Concepts

- **Predicates**: a representation of the property or feature of a data entity, or the relationship between data entities. It is used to define operation conditions.

- **ResultSet**: a set of query results, which allows access to the required data in flexible modes.


## Working Principles

**RelationalStore** provides APIs for applications to perform data operations. With SQLite as the underlying persistent storage engine, **RelationalStore** provides SQLite database features, including transactions, indexes, views, triggers, foreign keys, parameterized queries, prepared SQL statements, and more.

**Figure 1** Working mechanism

![relationStore_local](figures/relationStore_local.jpg)


## Constraints

- The default log mode is Write Ahead Log ([WAL](data-terminology.md#write-ahead-log-wal)), and the default flush mode is [FULL](data-terminology.md#full).

- The RDB store supports four read connections and one write connection. Read connections can be dynamically expanded. If no read connection is available, a read connection is created to execute the read operation. Write connections cannot be dynamically expanded. If no write connection is available, the write operation is executed after the connection is released.

- To ensure data accuracy, only one write operation is allowed at a time.

- Once an application is uninstalled, related database files and temporary files on the device are automatically deleted.

- ArkTS supports the following basic data types: number, string, binary, and boolean.

- The maximum size of a data record is 2 MB. If a data record exceeds 2 MB, it can be inserted successfully but cannot be read.

## Available APIs

The following table lists the APIs used for RDB data persistence. Most of the APIs are executed asynchronously, using a callback or promise to return the result. The following table uses the callback-based APIs as an example. For more information about the APIs, see [RDB Store](../reference/apis-arkdata/arkts-apis-data-relationalStore.md).

| API| Description|
| -------- | -------- |
| getRdbStore(context: Context, config: StoreConfig, callback: AsyncCallback&lt;RdbStore&gt;): void | Obtains an **RdbStore** instance to implement RDB store operations. You can set **RdbStore** parameters based on actual requirements and use **RdbStore** APIs to perform data operations.|
| createTransaction(options?: TransactionOptions): Promise&lt;Transaction&gt; | Creates a transaction object and starts the transaction.|
| execute(sql: string, args?: Array&lt;ValueType&gt;):Promise&lt;ValueType&gt; | Executes an SQL statement that contains specified parameters.|
| querySql(sql: string, bindArgs?: Array&lt;ValueType&gt;):Promise&lt;ResultSet&gt; | Queries data in a store using the specified SQL statements.|
| insert(table: string, values: ValuesBucket, conflict?: ConflictResolution): Promise&lt;number&gt; | Inserts a row of data into a table.|
| update(values: ValuesBucket, predicates: RdbPredicates, callback: AsyncCallback&lt;number&gt;):void | Updates data in the RDB store based on the specified **predicates** instance.|
| delete(predicates: RdbPredicates, callback: AsyncCallback&lt;number&gt;):void | Deletes data from the RDB store based on the specified **predicates** instance.|
| query(predicates: RdbPredicates, columns: Array&lt;string&gt;, callback: AsyncCallback&lt;ResultSet&gt;):void | Queries data in the RDB store based on specified conditions.|
| deleteRdbStore(context: Context, name: string, callback: AsyncCallback&lt;void&gt;): void | Deletes an RDB store.|
| isTokenizerSupported(tokenizer: Tokenizer): boolean | Checks whether the specified tokenizer is supported. (Tokenizer is a tool for breaking down text into smaller units, which can be words, subwords, characters, or other language fragments.)|

## How to Develop
Unless otherwise specified, the sample code without "stage model" or "FA model" applies to both models.

If error 14800011 is thrown, you need to rebuild the database and restore data to ensure normal application development. For details, see [Rebuilding an RDB Store](data-backup-and-restore.md#rebuilding-an-rdb-store).

1. Obtain an **RdbStore** instance, which includes operations of creating an RDB store and tables, and upgrading or downgrading the RDB store. <br>Example:

   Stage model:
   
   ```ts
   import { relationalStore} from '@kit.ArkData'; // Import the relationalStore module.
   import { UIAbility } from '@kit.AbilityKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { window } from '@kit.ArkUI';

   // In this example, Ability is used to obtain an RdbStore instance. You can use other implementations as required.
   export default class EntryAbility extends UIAbility {
     onWindowStageCreate(windowStage: window.WindowStage) {
       // Before using a tokenizer, call isTokenizerSupported to check whether the tokenizer is supported by the current platform.
       let tokenType = relationalStore.Tokenizer.ICU_TOKENIZER;
       let tokenTypeSupported = relationalStore.isTokenizerSupported(tokenType);
       if (!tokenTypeSupported) {
         console.error(`ICU_TOKENIZER is not supported on this platform.`);
       }
       const STORE_CONFIG: relationalStore.StoreConfig = {
         // Set the store name, which is the database file name.
         name: 'RdbTest.db',
         // Security level of the RDB store.
         securityLevel: relationalStore.SecurityLevel.S3,
         // (Optional) Whether to encrypt the database. By default, the database is not encrypted.
         encrypt: false,
         // (Optional) custom path of the database. The RdbStore instance is created in the sandbox directory of the application by default.
         customDir: 'customDir/subCustomDir',
         // (Optional) Specify whether the RDB store is opened in read-only mode. The default value is false, which means the RDB store is readable and writable. If this parameter is true, data can only be read from the RDB store. If write operation is performed, error code 801 is returned.
         isReadOnly: false,
         // (Optional) Type of the tokenizer used in full-text search (FTS) mode. Only English word segmentation is supported in FTS by default.
         tokenizer: tokenType
       };

       // Check the RDB store version. If the version is incorrect, upgrade or downgrade the RDB store.
       // For example, the RDB store version is 3 and the table structure is EMPLOYEE (NAME, AGE, SALARY, CODES, IDENTITY).
       // Execute the SQL statement for table creation. IDENTITY is of the BIGINT type and is set to UNLIMITED INT.
       const SQL_CREATE_TABLE =
         'CREATE TABLE IF NOT EXISTS EMPLOYEE (ID INTEGER PRIMARY KEY AUTOINCREMENT, NAME TEXT NOT NULL, AGE INTEGER, SALARY REAL, CODES BLOB, IDENTITY UNLIMITED INT)';

       relationalStore.getRdbStore(this.context, STORE_CONFIG, async (err, store) => {
         if (err) {
           console.error(`Failed to get RdbStore. Code:${err.code}, message:${err.message}`);
           return;
         }
         console.info('Succeeded in getting RdbStore.');
         let storeVersion = store.version;
         // When the RDB store is created, the default version is 0.
         if (storeVersion === 0) {
           try {
             await store.execute(SQL_CREATE_TABLE); // Create a table.
             storeVersion = 3;
             // Set the RDB store version, which must be an integer greater than 0.
           } catch (e) {
             const err = e as BusinessError;
             console.error(`Failed to execute sql. Code:${err.code}, message:${err.message}`);
           }
         }

         // If the RDB store version is not 0 and does not match the current version, upgrade or downgrade the RDB store.
         // For example, upgrade the RDB store from version 1 to version 2.
         if (storeVersion === 1) {
           // Upgrade the RDB store from version 1 to version 2, and change the table structure from EMPLOYEE (NAME, SALARY, CODES, ADDRESS) to EMPLOYEE (NAME, AGE, SALARY, CODES, ADDRESS).
           try {
             await store.execute('ALTER TABLE EMPLOYEE ADD COLUMN AGE INTEGER');
             console.info("Upgrade store version from 1 to 2 success.")
             storeVersion = 2;
           } catch (e) {
             const err = e as BusinessError;
             console.error(`Failed to execute sql. Code:${err.code}, message:${err.message}`);
           }
         }

         // For example, upgrade the RDB store from version 2 to version 3.
         if (storeVersion === 2) {
           // Upgrade the RDB store from version 2 to version 3, and change the table structure from EMPLOYEE (NAME, AGE, SALARY, CODES, ADDRESS) to EMPLOYEE (NAME, AGE, SALARY, CODES).
           try {
             await store.execute('ALTER TABLE EMPLOYEE DROP COLUMN ADDRESS');
             storeVersion = 3;
             console.info("Upgrade store version from 2 to 3 success.")
           } catch (e) {
             const err = e as BusinessError;
             console.error(`Failed to execute sql. Code:${err.code}, message:${err.message}`);
           }
         }
         store.version = storeVersion;
         // Before adding, deleting, modifying, and querying data in an RDB store, obtain an RdbStore instance and create a table.
       });
     }
   }
   ```

   FA model:

   ```ts
   import { relationalStore} from '@kit.ArkData'; // Import the relationalStore module.
   import { featureAbility } from '@kit.AbilityKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   
   let context = featureAbility.getContext();

   const STORE_CONFIG: relationalStore.StoreConfig = {
     name: 'RdbTest.db', // Database file name.
     securityLevel: relationalStore.SecurityLevel.S3 // Database security level.
   };

   // For example, the RDB store version is 3 and the table structure is EMPLOYEE (NAME, AGE, SALARY, CODES, IDENTITY).
   // Execute the SQL statement for table creation. IDENTITY is of the BIGINT type and is set to UNLIMITED INT.
   const SQL_CREATE_TABLE =
     'CREATE TABLE IF NOT EXISTS EMPLOYEE (ID INTEGER PRIMARY KEY AUTOINCREMENT, NAME TEXT NOT NULL, AGE INTEGER, SALARY REAL, CODES BLOB, IDENTITY UNLIMITED INT)';
   
   relationalStore.getRdbStore(context, STORE_CONFIG, async (err, store) => {
     if (err) {
       console.error(`Failed to get RdbStore. Code:${err.code}, message:${err.message}`);
       return;
     }
     console.info('Succeeded in getting RdbStore.');

     let storeVersion = store.version;
     // When the RDB store is created, the default version is 0.
     if (storeVersion === 0) {
       try {
         await store.execute(SQL_CREATE_TABLE); // Create a table.
         // Set the RDB store version, which must be an integer greater than 0.
         storeVersion = 3;
       } catch (e) {
         const err = e as BusinessError;
         console.error(`Failed to execute sql. Code:${err.code}, message:${err.message}`);
       }
     }

     // If the RDB store version is not 0 and does not match the current version, upgrade or downgrade the RDB store.
     // For example, upgrade the RDB store from version 1 to version 2.
     if (storeVersion === 1) {
       try {
         // Upgrade the RDB store from version 1 to version 2, and change the table structure from EMPLOYEE (NAME, SALARY, CODES, ADDRESS) to EMPLOYEE (NAME, AGE, SALARY, CODES, ADDRESS).
         await store.execute('ALTER TABLE EMPLOYEE ADD COLUMN AGE INTEGER');
         storeVersion = 2;
         console.info("Upgrade store version from 1 to 2 success.")
       } catch (e) {
         const err = e as BusinessError;
         console.error(`Failed to execute sql. Code:${err.code}, message:${err.message}`);
       }
     }

     // For example, upgrade the RDB store from version 2 to version 3.
     if (storeVersion === 2) {
       try {
         // Upgrade the RDB store from version 2 to version 3, and change the table structure from EMPLOYEE (NAME, AGE, SALARY, CODES, ADDRESS) to EMPLOYEE (NAME, AGE, SALARY, CODES).
         await store.execute('ALTER TABLE EMPLOYEE DROP COLUMN ADDRESS');
         storeVersion = 3;
         console.info("Upgrade store version from 2 to 3 success.")
       } catch (e) {
         const err = e as BusinessError;
         console.error(`Failed to execute sql. Code:${err.code}, message:${err.message}`);
       }
     }
     // Before adding, deleting, modifying, and querying data in an RDB store, obtain an RdbStore instance and create a table.
   });
   ```

   > **NOTE**
   >
   > - The RDB store created by an application varies with the context. Multiple RDB stores are created for the same database name with different application contexts. For example, each UIAbility has its own context.
   > 
   > - When an application calls **getRdbStore()** to obtain an RDB store instance for the first time, the corresponding database file is generated in the application sandbox. When the RDB store is used, temporary files ended with **-wal** and **-shm** may be generated in the same directory as the database file. If you want to move the database files to other places, you must also move these temporary files. After the application is uninstalled, the database files and temporary files generated on the device are also removed.
   > 
   > - For details about the error codes, see [Universal Error Codes](../reference/errorcode-universal.md) and [RDB Store Error Codes](../reference/apis-arkdata/errorcode-data-rdb.md).

2. Call **insert()** to insert data. <br>Example:
   
   ```ts
   let value1 = 'Lisa';
   let value2 = 18;
   let value3 = 100.5;
   let value4 = new Uint8Array([1, 2, 3, 4, 5]);
   let value5 = BigInt('15822401018187971961171');
   const valueBucket: relationalStore.ValuesBucket = {
     NAME: value1,
     AGE: value2,
     SALARY: value3,
     CODES: value4,
     IDENTITY: value5,
   };

   if (store !== undefined) {
     try {
       const rowId = await store.insert('EMPLOYEE', valueBucket);
       console.info(`Succeeded in inserting data. rowId:${rowId}`);
     } catch (error) {
       const err = error as BusinessError;
       console.error(`Failed to insert data. Code:${err.code}, message:${err.message}`);
     }
   }
   ```

   > **NOTE**
   >
   > **RelationalStore** does not provide explicit flush operations for data persistence. The **insert()** method stores data persistently.

3. Modify or delete data based on the specified **Predicates** instance.

   Call **update()** to modify data and **delete()** to delete data. <br>Example:

   ```ts
   let value6 = 'Rose';
   let value7 = 22;
   let value8 = 200.5;
   let value9 = new Uint8Array([1, 2, 3, 4, 5]);
   let value10 = BigInt('15822401018187971967863');
   const valueBucket2: relationalStore.ValuesBucket = {
     NAME: value6,
     AGE: value7,
     SALARY: value8,
     CODES: value9,
     IDENTITY: value10,
   };

   // Modify data.
   let predicates1 = new relationalStore.RdbPredicates('EMPLOYEE'); // Create predicates for the table named EMPLOYEE.
   predicates1.equalTo('NAME', 'Lisa'); // Modify the data of Lisa in the EMPLOYEE table to the specified data.
   if (store !== undefined) {
     (store as relationalStore.RdbStore).update(valueBucket2, predicates1, (err: BusinessError, rows: number) => {
       if (err) {
         console.error(`Failed to update data. Code:${err.code}, message:${err.message}`);
        return;
      }
      console.info(`Succeeded in updating data. row count: ${rows}`);
     })
   }

   // Delete data.
   predicates1 = new relationalStore.RdbPredicates('EMPLOYEE');
   predicates1.equalTo('NAME', 'Lisa');
   if (store !== undefined) {
     (store as relationalStore.RdbStore).delete(predicates1, (err: BusinessError, rows: number) => {
       if (err) {
         console.error(`Failed to delete data. Code:${err.code}, message:${err.message}`);
         return;
       }
       console.info(`Delete rows: ${rows}`);
     })
   }
   ```

4. Query data based on the conditions specified by **Predicates**.

   Call **query()** to query data. The data obtained is returned in a **ResultSet** object. <br>Example:

   ```ts
   let predicates2 = new relationalStore.RdbPredicates('EMPLOYEE');
   predicates2.equalTo('NAME', 'Rose');
   if (store !== undefined) {
     (store as relationalStore.RdbStore).query(predicates2, ['ID', 'NAME', 'AGE', 'SALARY', 'IDENTITY'], (err: BusinessError, resultSet) => {
       if (err) {
         console.error(`Failed to query data. Code:${err.code}, message:${err.message}`);
         return;
       }
       console.info(`ResultSet column names: ${resultSet.columnNames}, column count: ${resultSet.columnCount}`);
       // resultSet is a cursor of a data set. By default, the cursor points to the -1st record. Valid data starts from 0.
       while (resultSet.goToNextRow()) {
         const id = resultSet.getLong(resultSet.getColumnIndex('ID'));
         const name = resultSet.getString(resultSet.getColumnIndex('NAME'));
         const age = resultSet.getLong(resultSet.getColumnIndex('AGE'));
         const salary = resultSet.getDouble(resultSet.getColumnIndex('SALARY'));
         const identity = resultSet.getValue(resultSet.getColumnIndex('IDENTITY'));
         console.info(`id=${id}, name=${name}, age=${age}, salary=${salary}, identity=${identity}`);
       }
       // Release the data set memory.
       resultSet.close();
     })
   }
   ```

   > **NOTE**
   >
   > Use **close()** to close the **ResultSet** that is no longer used in a timely manner so that the memory allocated can be released.

   The RDB store also supports full-text search (FTS) in Chinese or English. The ICU tokenizer is supported.

   The following example demonstrates how to perform FTS with Chinese keywords:

   ```ts
   if (store !== undefined) {
     // Create an FTS table.
     const SQL_CREATE_TABLE = 'CREATE VIRTUAL TABLE IF NOT EXISTS example USING fts4(name, content, tokenize=icu zh_CN)';
     try {
       await store.execute(SQL_CREATE_TABLE);
       console.info('Succeeded in creating fts table.');
     } catch (error) {
       const err = error as BusinessError;
       console.error(`Failed to creating fts table. code: ${err.code}, message: ${err.message}.`);
     }
   }
   if (store !== undefined) {
     try {
       const resultSet = await store.querySql('SELECT name FROM example WHERE example MATCH ?', ['Test']);
       while (resultSet.goToNextRow()) {
         const name = resultSet.getValue(resultSet.getColumnIndex('name'));
         console.info(`name=${name}`);
       }
       resultSet.close();
     } catch (error) {
       const err = error as BusinessError;
       console.error(`Query failed. code: ${err.code}, message: ${err.message}.`);
     }
   }
   ```

5. Use the transaction object to insert, delete, and update data.
   
   Call the **createTransaction** method to create a transaction object and execute the corresponding operation.
   The supported transaction types are **DEFERRED** (default), **IMMEDIATE**, and **EXCLUSIVE**.

   For details, see [Interface (RdbStore)](../reference/apis-arkdata/arkts-apis-data-relationalStore-RdbStore.md#createtransaction14).

   ```ts
   if (store !== undefined) {
     // Create a transaction object.
     try {
       const transaction = await store.createTransaction();
       try {
         // Insert data using the transaction object.
         const rowId = await transaction.insert(
           'EMPLOYEE',
           {
             NAME: 'Lisa',
             AGE: 18,
             SALARY: 100.5,
             CODES: new Uint8Array([1, 2, 3, 4, 5])
           },
           relationalStore.ConflictResolution.ON_CONFLICT_REPLACE
         );
         console.info(`Insert is successful, rowId = ${rowId}`);

         const predicates = new relationalStore.RdbPredicates('EMPLOYEE');
         predicates.equalTo('NAME', 'Lisa');
         // Update data using the transaction object.
         const rows = await transaction.update(
           {
             NAME: 'Rose',
             AGE: 22,
             SALARY: 200.5,
             CODES: new Uint8Array([1, 2, 3, 4, 5])
           },
           predicates,
           relationalStore.ConflictResolution.ON_CONFLICT_REPLACE
         );
         console.info(`Updated row count: ${rows}`);

         // Delete data using the transaction object.
         await transaction.execute('DELETE FROM EMPLOYEE WHERE age = ? OR age = ?', [21, 20]);
         console.log(`execute delete success`);

         // Commit a transaction.
         await transaction.commit();
         console.info('Transaction commit success.');
       } catch (error) {
         const err = error as BusinessError;
         // Roll back the transaction if the execution fails.
         await transaction.rollback();
         console.error(`Transaction execute failed, code is ${err.code}, message is ${err.message}`);
       }
     } catch (error) {
       const err = error as BusinessError;
       console.error(`createTransaction failed, code is ${err.code}, message is ${err.message}`);
     }
   }
   ```

6. Back up the database in the same directory. <br>Two backup modes are available: manual backup and automatic backup (available only for system applications). For details, see [Backing Up an RDB Store](data-backup-and-restore.md#backing-up-an-rdb-store).

   Example: Perform manual backup of an RDB store.

   ```ts
   if (store !== undefined) {
     // Backup.db indicates the name of the database backup file. By default, it is in the same directory as the RdbStore file. You can also specify the directory, which is in the customDir + backup.db format.
     (store as relationalStore.RdbStore).backup("Backup.db", (err: BusinessError) => {
       if (err) {
         console.error(`Failed to backup RdbStore. Code:${err.code}, message:${err.message}`);
         return;
       }
       console.info(`Succeeded in backing up RdbStore.`);
     })
   }
   ```

7. Restore data from the database backup. <br>You can restore an RDB store from the manual backup data or automatic backup data (available only for system applications). For details, see [Restoring RDB Store Data](data-backup-and-restore.md#restoring-rdb-store-data).

   Example: Call [restore](../reference/apis-arkdata/arkts-apis-data-relationalStore-RdbStore.md#restore) to restore an RDB store from the data that is manually backed up.

   ```ts
   if (store !== undefined) {
     (store as relationalStore.RdbStore).restore("Backup.db", (err: BusinessError) => {
       if (err) {
         console.error(`Failed to restore RdbStore. Code:${err.code}, message:${err.message}`);
         return;
       }
       console.info(`Succeeded in restoring RdbStore.`);
     })
   }
   ```

8. Delete the RDB store.

   Call **deleteRdbStore()** to delete the RDB store and related database files. <br>Example:

   Stage model:

   ```ts
   relationalStore.deleteRdbStore(this.context, 'RdbTest.db', (err: BusinessError) => {
    if (err) {
       console.error(`Failed to delete RdbStore. Code:${err.code}, message:${err.message}`);
       return;
     }
     console.info('Succeeded in deleting RdbStore.');
   });
   ```

   FA model:

   ```ts
   relationalStore.deleteRdbStore(context, 'RdbTest.db', (err: BusinessError) => {
     if (err) {
       console.error(`Failed to delete RdbStore. Code:${err.code}, message:${err.message}`);
       return;
     }
     console.info('Succeeded in deleting RdbStore.');
   });
   ```