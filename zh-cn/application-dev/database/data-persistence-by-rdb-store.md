# 通过关系型数据库实现数据持久化


## 场景介绍

关系型数据库基于SQLite组件，适用于存储包含复杂关系数据的场景，比如一个班级的学生信息，需要包括姓名、学号、各科成绩等，又或者公司的雇员信息，需要包括姓名、工号、职位等，由于数据之间有较强的对应关系，复杂程度比键值型数据更高，此时需要使用关系型数据库来持久化保存数据。


## 基本概念

- **谓词**：数据库中用来代表数据实体的性质、特征或者数据实体之间关系的词项，主要用来定义数据库的操作条件。

- **结果集**：指用户查询之后的结果集合，可以对数据进行访问。结果集提供了灵活的数据访问方式，可以更方便地拿到用户想要的数据。


## 运作机制

关系型数据库对应用提供通用的操作接口，底层使用SQLite作为持久化存储引擎，支持SQLite具有的数据库特性，包括但不限于事务、索引、视图、触发器、外键、参数化查询和预编译SQL语句。

**图1** 关系型数据库运作机制
 
![relationStore_local](figures/relationStore_local.jpg)


## 约束限制

- 系统默认日志方式是WAL（Write Ahead Log）模式，系统默认落盘方式是FULL模式。

- 数据库中有4个读连接和1个写连接，线程获取到空闲读连接时，即可进行读取操作。当没有空闲读连接且有空闲写连接时，会将写连接当做读连接来使用。

- 为保证数据的准确性，数据库同一时间只能支持一个写操作。

- 当应用被卸载完成后，设备上的相关数据库文件及临时文件会被自动清除。

- ArkTS侧支持的基本数据类型：number、string、二进制类型数据、boolean。

- 为保证插入并读取数据成功，建议一条数据不要超过2M。超出该大小，插入成功，读取失败。

## 接口说明

以下是关系型数据库持久化功能的相关接口，大部分为异步接口。异步接口均有callback和Promise两种返回形式，下表均以callback形式为例，更多接口及使用方式请见[关系型数据库](../reference/apis-arkdata/js-apis-data-relationalStore.md)。

| 接口名称 | 描述 | 
| -------- | -------- |
| getRdbStore(context: Context, config: StoreConfig, callback: AsyncCallback&lt;RdbStore&gt;): void | 获得一个RdbStore，操作关系型数据库，用户可以根据自己的需求配置RdbStore的参数，然后通过RdbStore调用相关接口可以执行相关的数据操作。 | 
| executeSql(sql: string, bindArgs: Array&lt;ValueType&gt;, callback: AsyncCallback&lt;void&gt;):void | 执行包含指定参数但不返回值的SQL语句。 | 
| insert(table: string, values: ValuesBucket, callback: AsyncCallback&lt;number&gt;):void | 向目标表中插入一行数据。 | 
| update(values: ValuesBucket, predicates: RdbPredicates, callback: AsyncCallback&lt;number&gt;):void | 根据predicates的指定实例对象更新数据库中的数据。 | 
| delete(predicates: RdbPredicates, callback: AsyncCallback&lt;number&gt;):void | 根据predicates的指定实例对象从数据库中删除数据。 | 
| query(predicates: RdbPredicates, columns: Array&lt;string&gt;, callback: AsyncCallback&lt;ResultSet&gt;):void | 根据指定条件查询数据库中的数据。 | 
| deleteRdbStore(context: Context, name: string, callback: AsyncCallback&lt;void&gt;): void | 删除数据库。 | 


## 开发步骤
因Stage模型、FA模型的差异，个别示例代码提供了在两种模型下的对应示例；示例代码未区分模型或没有对应注释说明时默认在两种模型下均适用。
1. 使用关系型数据库实现数据持久化，需要获取一个RdbStore，其中包括建库、建表、升降级等操作。示例代码如下所示：

   Stage模型示例：
     
   ```ts
   import { relationalStore } from '@kit.ArkData'; // 导入模块
   import { UIAbility } from '@kit.AbilityKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { window } from '@kit.ArkUI';

   // 此处示例在Ability中实现，使用者也可以在其他合理场景中使用
   class EntryAbility extends UIAbility {
     onWindowStageCreate(windowStage: window.WindowStage) {
       const STORE_CONFIG :relationalStore.StoreConfig= {
         name: 'RdbTest.db', // 数据库文件名
         securityLevel: relationalStore.SecurityLevel.S3, // 数据库安全级别
         encrypt: false, // 可选参数，指定数据库是否加密，默认不加密
         customDir: 'customDir/subCustomDir', // 可选参数，数据库自定义路径。数据库将在如下的目录结构中被创建：context.databaseDir + '/rdb/' + customDir，其中context.databaseDir是应用沙箱对应的路径，'/rdb/'表示创建的是关系型数据库，customDir表示自定义的路径。当此参数不填时，默认在本应用沙箱目录下创建RdbStore实例。
         isReadOnly: false // 可选参数，指定数据库是否以只读方式打开。该参数默认为false，表示数据库可读可写。该参数为true时，只允许从数据库读取数据，不允许对数据库进行写操作，否则会返回错误码801。
       };

       // 判断数据库版本，如果不匹配则需进行升降级操作
       // 假设当前数据库版本为3，表结构：EMPLOYEE (NAME, AGE, SALARY, CODES, IDENTITY)
       const SQL_CREATE_TABLE = 'CREATE TABLE IF NOT EXISTS EMPLOYEE (ID INTEGER PRIMARY KEY AUTOINCREMENT, NAME TEXT NOT NULL, AGE INTEGER, SALARY REAL, CODES BLOB, IDENTITY UNLIMITED INT)'; // 建表Sql语句, IDENTITY为bigint类型，sql中指定类型为UNLIMITED INT

       relationalStore.getRdbStore(this.context, STORE_CONFIG, (err, store) => {
         if (err) {
           console.error(`Failed to get RdbStore. Code:${err.code}, message:${err.message}`);
           return;
         }
         console.info('Succeeded in getting RdbStore.');

         // 当数据库创建时，数据库默认版本为0
         if (store.version === 0) {
           store.executeSql(SQL_CREATE_TABLE); // 创建数据表
           // 设置数据库的版本，入参为大于0的整数
           store.version = 3;
         }

         // 如果数据库版本不为0且和当前数据库版本不匹配，需要进行升降级操作
         // 当数据库存在并假定版本为1时，例应用从某一版本升级到当前版本，数据库需要从1版本升级到2版本
         if (store.version === 1) {
           // version = 1：表结构：EMPLOYEE (NAME, SALARY, CODES, ADDRESS) => version = 2：表结构：EMPLOYEE (NAME, AGE, SALARY, CODES, ADDRESS)
           if (store !== undefined) {
             (store as relationalStore.RdbStore).executeSql('ALTER TABLE EMPLOYEE ADD COLUMN AGE INTEGER');
             store.version = 2;
           }
         }

         // 当数据库存在并假定版本为2时，例应用从某一版本升级到当前版本，数据库需要从2版本升级到3版本
         if (store.version === 2) {
           // version = 2：表结构：EMPLOYEE (NAME, AGE, SALARY, CODES, ADDRESS) => version = 3：表结构：EMPLOYEE (NAME, AGE, SALARY, CODES)
           if (store !== undefined) {
             (store as relationalStore.RdbStore).executeSql('ALTER TABLE EMPLOYEE DROP COLUMN ADDRESS TEXT');
             store.version = 3;
           }
         }
       });

       // 请确保获取到RdbStore实例后，再进行数据库的增、删、改、查等操作
     }
   }
   ```

   FA模型示例：

   ```ts
   import { relationalStore } from '@kit.ArkData'; // 导入模块
   import { featureAbility } from '@kit.AbilityKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   
   let context = featureAbility.getContext();

   const STORE_CONFIG :relationalStore.StoreConfig = {
     name: 'RdbTest.db', // 数据库文件名
     securityLevel: relationalStore.SecurityLevel.S3 // 数据库安全级别
   };

   // 假设当前数据库版本为3，表结构：EMPLOYEE (NAME, AGE, SALARY, CODES, IDENTITY)
   const SQL_CREATE_TABLE = 'CREATE TABLE IF NOT EXISTS EMPLOYEE (ID INTEGER PRIMARY KEY AUTOINCREMENT, NAME TEXT NOT NULL, AGE INTEGER, SALARY REAL, CODES BLOB, IDENTITY UNLIMITED INT)'; // 建表Sql语句，IDENTITY为bigint类型，sql中指定类型为UNLIMITED INT

   relationalStore.getRdbStore(context, STORE_CONFIG, (err, store) => {
     if (err) {
       console.error(`Failed to get RdbStore. Code:${err.code}, message:${err.message}`);
       return;
     }
     console.info('Succeeded in getting RdbStore.');

     // 当数据库创建时，数据库默认版本为0
     if (store.version === 0) {
       store.executeSql(SQL_CREATE_TABLE); // 创建数据表
       // 设置数据库的版本，入参为大于0的整数
       store.version = 3;
     }

     // 如果数据库版本不为0且和当前数据库版本不匹配，需要进行升降级操作
     // 当数据库存在并假定版本为1时，例应用从某一版本升级到当前版本，数据库需要从1版本升级到2版本
     if (store.version === 1) {
       // version = 1：表结构：EMPLOYEE (NAME, SALARY, CODES, ADDRESS) => version = 2：表结构：EMPLOYEE (NAME, AGE, SALARY, CODES, ADDRESS)
       store.executeSql('ALTER TABLE EMPLOYEE ADD COLUMN AGE INTEGER');
       store.version = 2;
     }

     // 当数据库存在并假定版本为2时，例应用从某一版本升级到当前版本，数据库需要从2版本升级到3版本
     if (store.version === 2) {
       // version = 2：表结构：EMPLOYEE (NAME, AGE, SALARY, CODES, ADDRESS) => version = 3：表结构：EMPLOYEE (NAME, AGE, SALARY, CODES)
       store.executeSql('ALTER TABLE EMPLOYEE DROP COLUMN ADDRESS TEXT');
       store.version = 3;
     }
   });

   // 请确保获取到RdbStore实例后，再进行数据库的增、删、改、查等操作
   ```

   > **说明：**
   >
   > - 应用创建的数据库与其上下文（Context）有关，即使使用同样的数据库名称，但不同的应用上下文，会产生多个数据库，例如每个UIAbility都有各自的上下文。
   > 
   > - 当应用首次获取数据库（调用getRdbStore）后，在应用沙箱内会产生对应的数据库文件。使用数据库的过程中，在与数据库文件相同的目录下可能会产生以-wal和-shm结尾的临时文件。此时若开发者希望移动数据库文件到其它地方使用查看，则需要同时移动这些临时文件，当应用被卸载完成后，其在设备上产生的数据库文件及临时文件也会被移除。
   > 
   > - 错误码的详细介绍请参见[通用错误码](../reference/errorcode-universal.md)和[关系型数据库错误码](../reference/apis-arkdata/errorcode-data-rdb.md)。

2. 获取到RdbStore后，调用insert()接口插入数据。示例代码如下所示：
     
   ```ts
   let store: relationalStore.RdbStore | undefined = undefined;

   let value1 = 'Lisa';
   let value2 = 18;
   let value3 = 100.5;
   let value4 = new Uint8Array([1, 2, 3, 4, 5]);
   let value5 = BigInt('15822401018187971961171');
   // 以下三种方式可用
   const valueBucket1: relationalStore.ValuesBucket = {
     'NAME': value1,
     'AGE': value2,
     'SALARY': value3,
     'CODES': value4,
     'IDENTITY': value5,
   };
   const valueBucket2: relationalStore.ValuesBucket = {
     NAME: value1,
     AGE: value2,
     SALARY: value3,
     CODES: value4,
     IDENTITY: value5,
   };
   const valueBucket3: relationalStore.ValuesBucket = {
     "NAME": value1,
     "AGE": value2,
     "SALARY": value3,
     "CODES": value4,
     "IDENTITY": value5,
   };

   if (store !== undefined) {
     (store as relationalStore.RdbStore).insert('EMPLOYEE', valueBucket1, (err: BusinessError, rowId: number) => {
       if (err) {
         console.error(`Failed to insert data. Code:${err.code}, message:${err.message}`);
         return;
       }
       console.info(`Succeeded in inserting data. rowId:${rowId}`);
     })
   }
   ```

   > **说明：**
   >
   > 关系型数据库没有显式的flush操作实现持久化，数据插入即保存在持久化文件。

3. 根据谓词指定的实例对象，对数据进行修改或删除。

   调用update()方法修改数据，调用delete()方法删除数据。示例代码如下所示：

   ```ts
   let value6 = 'Rose';
   let value7 = 22;
   let value8 = 200.5;
   let value9 = new Uint8Array([1, 2, 3, 4, 5]);
   let value10 = BigInt('15822401018187971967863');
   // 以下三种方式可用
   const valueBucket4: relationalStore.ValuesBucket = {
     'NAME': value6,
     'AGE': value7,
     'SALARY': value8,
     'CODES': value9,
     'IDENTITY': value10,
   };
   const valueBucket5: relationalStore.ValuesBucket = {
     NAME: value6,
     AGE: value7,
     SALARY: value8,
     CODES: value9,
     IDENTITY: value10,
   };
   const valueBucket6: relationalStore.ValuesBucket = {
     "NAME": value6,
     "AGE": value7,
     "SALARY": value8,
     "CODES": value9,
     "IDENTITY": value10,
   };

   // 修改数据
   let predicates1 = new relationalStore.RdbPredicates('EMPLOYEE'); // 创建表'EMPLOYEE'的predicates
   predicates1.equalTo('NAME', 'Lisa'); // 匹配表'EMPLOYEE'中'NAME'为'Lisa'的字段
   if (store !== undefined) {
     (store as relationalStore.RdbStore).update(valueBucket4, predicates1, (err: BusinessError, rows: number) => {
       if (err) {
         console.error(`Failed to update data. Code:${err.code}, message:${err.message}`);
        return;
      }
      console.info(`Succeeded in updating data. row count: ${rows}`);
     })
   }

   // 删除数据
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

4. 根据谓词指定的查询条件查找数据。

   调用query()方法查找数据，返回一个ResultSet结果集。示例代码如下所示：

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
       // resultSet是一个数据集合的游标，默认指向第-1个记录，有效的数据从0开始。
       while (resultSet.goToNextRow()) {
         const id = resultSet.getLong(resultSet.getColumnIndex('ID'));
         const name = resultSet.getString(resultSet.getColumnIndex('NAME'));
         const age = resultSet.getLong(resultSet.getColumnIndex('AGE'));
         const salary = resultSet.getDouble(resultSet.getColumnIndex('SALARY'));
         const identity = resultSet.getValue(resultSet.getColumnIndex('IDENTITY'));
         console.info(`id=${id}, name=${name}, age=${age}, salary=${salary}, identity=${identity}`);
       }
       // 释放数据集的内存
       resultSet.close();
     })
   }
   ```

   > **说明：**
   >
   > 当应用完成查询数据操作，不再使用结果集（ResultSet）时，请及时调用close方法关闭结果集，释放系统为其分配的内存。

5. 在同路径下备份数据库。示例代码如下所示：

   ```ts
   if (store !== undefined) {
     // "Backup.db"为备份数据库文件名，默认在RdbStore同路径下备份。也可指定路径：customDir + "backup.db"
     (store as relationalStore.RdbStore).backup("Backup.db", (err: BusinessError) => {
       if (err) {
         console.error(`Failed to backup RdbStore. Code:${err.code}, message:${err.message}`);
         return;
       }
       console.info(`Succeeded in backing up RdbStore.`);
     })
   }
   ```

6. 从备份数据库中恢复数据。示例代码如下所示：

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

7. 若数据库文件损坏，需要重建数据库。

   进行开库及增删改查等操作时抛出错误码14800011表示数据库文件损坏。重建数据库的示例代码如下所示：

   ```ts
   if (store !== undefined) {
     // 数据库文件损坏后需要关闭所有数据库连接和结果集，使用store.close()方法或把对象置为null
     (store as relationalStore.RdbStore).close();
     store = undefined;
     // 将config.allowRebuild配置为true，重新调用getRdbStore开库
     const STORE_CONFIG: relationalStore.StoreConfig = {
       name: 'RdbTest.db',
       securityLevel: relationalStore.SecurityLevel.S3,
       allowRebuild: true
     };

     relationalStore.getRdbStore(this.context, STORE_CONFIG).then(async (rdbStore: relationalStore.RdbStore) => {
       store = rdbStore;
       console.info('Get RdbStore successfully.')
     }).catch((err: BusinessError) => {
       console.error(`Get RdbStore failed, code is ${err.code},message is ${err.message}`);
     })

     if (store !== undefined) {
       // 查看重建结果
       if ((store as relationalStore.RdbStore).rebuilt === relationalStore.RebuildType.REBUILT) {
         console.info('Succeeded in rebuilding RdbStore.');
         // 将损坏前备份的数据恢复到新数据库中
         (store as relationalStore.RdbStore).restore("Backup.db", (err: BusinessError) => {
           if (err) {
             console.error(`Failed to restore RdbStore. Code:${err.code}, message:${err.message}`);
             return;
           }
           console.info(`Succeeded in restoring RdbStore.`);
         })
       }
     }
   }
   ``` 

8. 删除数据库。

   调用deleteRdbStore()方法，删除数据库及数据库相关文件。示例代码如下：

   Stage模型示例：

   ```ts
   relationalStore.deleteRdbStore(this.context, 'RdbTest.db', (err: BusinessError) => {
    if (err) {
       console.error(`Failed to delete RdbStore. Code:${err.code}, message:${err.message}`);
       return;
     }
     console.info('Succeeded in deleting RdbStore.');
   });
   ```

   FA模型示例：

   ```ts
   relationalStore.deleteRdbStore(context, 'RdbTest.db', (err: BusinessError) => {
     if (err) {
       console.error(`Failed to delete RdbStore. Code:${err.code}, message:${err.message}`);
       return;
     }
     console.info('Succeeded in deleting RdbStore.');
   });
   ```

## 相关实例

针对关系型数据库的开发，有以下相关实例可供参考：

- [`Rdb`：关系型数据库（ArkTS）（API9）](https://gitee.com/openharmony/codelabs/tree/master/Data/Rdb)
