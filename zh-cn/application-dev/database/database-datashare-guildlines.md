# DataShare开发指导
## 场景介绍
DataShare，用于应用管理其自身数据，并支持同个设备上不同应用间的数据共享。

DataShare可分为数据的提供方和访问方两部分，提供方可以选择性实现数据的增、删、改、查，以及文件打开等功能，并对外提供这些接口。访问方利用工具类，便可以访问提供方提供的各种功能。

## 接口说明

**表1** DataShare提供方需要实现的API

|接口名|描述|
|:------|:------|
|onCreate?(want: Want, callback: AsyncCallback&lt;void&gt;): void|DataShareExtensionAbility生命周期回调，在数据提供方应用创建时回调，执行初始化业务逻辑操作，如创建数据库。|
|insert?(uri: string, valueBucket: ValuesBucket, callback: AsyncCallback&lt;number&gt;): void|业务函数，在访问方向数据库中插入数据时回调。|
|update?(uri: string, predicates: DataSharePredicates, valueBucket: ValuesBucket, callback: AsyncCallback&lt;number&gt;): void|业务函数，在访问方更新数据时回调。|
|query?(uri: string, predicates: DataSharePredicates, columns: Array&lt;string&gt;, callback: AsyncCallback&lt;Object&gt;): void|业务函数，在访问方查询数据时回调。|
|delete?(uri: string, predicates: DataSharePredicates, callback: AsyncCallback&lt;number&gt;): void|业务函数，在访问方删除数据时回调。|
|batchInsert?(uri: string, valueBuckets: Array&lt;ValuesBucket&gt;, callback: AsyncCallback&lt;number&gt;): void|业务函数，在访问方调用批量插入数据接口时回调。|
|getType?(uri: string, callback: AsyncCallback&lt;string&gt;): void|业务函数，返回URI所指定数据的MIME类型。|
|getFileTypes?(uri: string, mimeTypeFilter: string, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void|业务函数，返回支持的文件的MIME类型。|
|normalizeUri?(uri: string, callback: AsyncCallback&lt;string&gt;): void|业务函数，实现对URI进行规范化。一个规范化的URI可以支持跨设备使用、持久化、备份和还原等，当上下文改变时仍然可以引用到相同的数据项。|
|denormalizeUri?(uri: string, callback: AsyncCallback&lt;string&gt;): void|业务函数，实现将规范化URI转换成非规范化的URI。|
|openFile?(uri: string, mode: string, callback: AsyncCallback&lt;number&gt;): void|业务函数，在访问方调用打开文件时回调。提供方需要实现按mode所指定的方式打开uri所指定的文件，并返回其文件描述符。|


## 开发步骤
### 数据提供方应用的开发（仅限系统应用）

1. 数据提供方（也称服务端）应用的开发者可继承于DataShareExtensionAbility，并根据自己的需求或目标选择性实现Insert、Query、Update、Delete等接口的业务内容，例如数据提供方只提供查询服务，则可只重写查询接口。业务的实现可由开发者自定义，例如数据存储实现可以选择OpenHarmony支持的数据库，也可以直接使用文件进行读写，甚至可以访问网络数据。由此可见，DataShare并不产生或存储数据，它只是“数据的搬运工”。

   创建数据提供方的代码示例如下：

   ```ets
   import Extension from '@ohos.application.DataShareExtensionAbility'
   import rdb from '@ohos.data.rdb';
   import fileIo from '@ohos.fileio'
   import dataSharePredicates from '@ohos.data.dataSharePredicates'
   
   
   let DB_NAME = "DB00.db";
   let TBL_NAME = "TBL00";
   let DDL_TBL_CREATE = "CREATE TABLE IF NOT EXISTS "
   + TBL_NAME
   + " (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, age INTEGER, isStudent BOOLEAN, Binary BINARY)";
   
   let rdbStore;
   let result;
   
   export default class DataShareExtAbility extends Extension {
       private rdbStore_;
   
       onCreate(want, callback) {
           result = this.context.cacheDir + '/datashare.txt'
           rdb.getRdbStore(this.context, {
               name: DB_NAME
           }, 1, function (err, data) {
               rdbStore = data;
               rdbStore.executeSql(DDL_TBL_CREATE, [], function (err) {
                   console.log('DataShareExtAbility onCreate, executeSql done err:' + JSON.stringify(err));
               });
               callback();
           });
       }
   
       insert(uri, value, callback) {
           if (value == null) {
               console.info('invalid valueBuckets');
               return;
           }
           rdbStore.insert(TBL_NAME, value, function (err, ret) {
               console.info('callback ret:' + ret);
               if (callback != undefined) {
                   callback(err, ret);
               }
           });
       }
   
       update(uri, predicates, value, callback) {
           if (predicates == null || predicates == undefined) {
               console.info('invalid predicates');
               return;
           }
           try {
               rdbStore.update(TBL_NAME,value, predicates, function (err, ret) {
                   console.info('callback ret:' + ret);
                   console.info('callback err:' + err);
                   if (callback != undefined) {
                       callback(err, ret);
                   }
               });
           } catch (err) {
               console.error('error' + err);
           }
       }
   
       delete(uri, predicates, callback) {
           if (predicates == null || predicates == undefined) {
               console.info('invalid predicates');
               return;
           }
           try {
               rdbStore.delete(TBL_NAME,predicates, function (err, ret) {
                   console.info('ret:' + ret);
                   if (callback != undefined) {
                       callback(err, ret);
                   }
               });
           } catch (err) {
               console.error('error' + err);
           }
       }
   
       query(uri, predicates, columns,  callback) {
           if (predicates == null || predicates == undefined) {
               console.info('invalid predicates');
           }
           try {
               rdbStore.query(TBL_NAME, predicates, columns, function (err, resultSet) {
                   if (resultSet != undefined) {
                       console.info('resultSet.rowCount: ' + resultSet.rowCount);
                   }
                   if (callback != undefined) {
                       callback(err, resultSet);
                   }
               });
           } catch (err) {
               console.error('error' + err);
           }
       }
   
       batchInsert(uri: string, valueBuckets, callback) {
           if (valueBuckets == null || valueBuckets.length == undefined) {
               console.info('invalid valueBuckets');
               return;
           }
           let resultNum = valueBuckets.length
           valueBuckets.forEach(vb => {
               console.info('valueBuckets:' + JSON.stringify(vb));
               rdbStore.insert(TBL_NAME, vb, function (err, ret) {
                   console.info('callback ret:' + ret);
                   if (callback != undefined) {
                       callback(err, resultNum);
                   }
               });
           });
       }
   
       getType(uri: string,callback) {
           let ret = "image";
           console.info('ret:' + ret);
           let err = {"code":0};
           callback(err,ret);
           return ret;
       }
   
       getFileTypes(uri: string, mimeTypeFilter: string, callback) {
           let ret = new Array("type01", "type02", "type03");
           console.info('ret:' + ret);
           let err = {"code":2};
           callback(err,ret);
           return ret;
       }
   
       openFile(uri: string, mode: string, callback) {
           fileIo.open(result, 0o2 | 0o100, 0o666, function(err, fd) {
               if(err) {
                   console.info('OpenFile err = ' + err);
               }
               let num = fileIo.writeSync(fd, "this is a interesting test of DataShare");
               callback(err,fd);
           })
       }
   
       normalizeUri(uri: string,callback) {
           let ret = "normalize+" + uri;
           console.info('ret:' + ret);
           let err = {"code":2};
           callback(err,ret);
       }
   
       denormalizeUri(uri: string,callback) {
           let ret = "denormalize+" + uri;
           console.info('ret:' + ret);
           let err = {"code":2};
           callback(err,ret);
           return ret;
       }
   };
   ```

2. 子模块配置

   | Json重要字段 | 备注说明                                                     |
   | ------------ | ------------------------------------------------------------ |
   | "name"       | Ability名称，对应Ability派生的Data类名。                     |
   | "type"       | Ability类型，Data对应的Ability类型为”data“。                 |
   | "uri"        | 通信使用的URI。                                              |
   | "visible"    | 对其他应用是否可见，设置为true时，Data才能与其他应用进行通信传输数据。 |

   **module.json5配置样例**

   ```ets
   "extensionAbilities": [
     {
       "srcEntrance": "./ets/DataShareExtAbility/DataShareExtAbility.ts",
       "name": "DataShareExtAbility",
       "icon": "$media:icon",
       "description": "$string:description_datashareextability",
       "type": "dataShare",
       "uri": "datashare://com.samples.datasharetest.DataShare",
       "visible": true
     }
   ]
   ```

### 数据访问方应用的开发
#### 数据访问方应用开发指导


1. 导入基础依赖包，以及获取与数据提供方通信的URI字符串。

   其中，基础依赖包包括：

   - @ohos.application.Ability
   - @ohos.data.dataShare
   - @ohos.data.dataSharePredicates

   ```ets
   // 作为参数传递的URI，与module.json5中定义的URI的区别是多了一个"/"，是因为作为参数传递的URI中，在第二个与第三个"/"中间，存在一个DeviceID的参数
   import Ability from '@ohos.application.Ability'
   import dataShare from '@ohos.data.dataShare'
   import dataSharePredicates from '@ohos.data.dataSharePredicates'
   
   let dsHelper;
   let abilityContext;
   let dseUri = ("datashare:///com.samples.datasharetest.DataShare");
   ```

2. 创建工具接口类对象。

   工具接口类对象DataShareHelper相关接口可参考[DataShareHelper](../reference/apis/js-apis-dataShareHelper.md)文档。
   ```ets
   export default class MainAbility extends Ability {
   	onWindowStageCreate(windowStage) {
   		abilityContext = this.context;
   		dataShare.createDataShareHelper(abilityContext, dseUri, (err,data)=>{
   			dsHelper = data;
   		});
   	}
   }
   ```

3. 获取到接口类对象后，便可利用其提供的接口访问提供方提供的服务，如进行数据的增删改查等。

   ```ets
   // 构建一条数据
   var valuesBucket = {"name": "ZhangSan", "age": 21, "isStudent": false, "Binary": new Uint8Array([1,2,3])};
   var updateBucket = {"name": "LiSi", "age": 18, "isStudent": true, "Binary": new Uint8Array([1,2,3])};
   let da =  new dataSharePredicates.DataSharePredicates();
   var valArray =new Array("*");
   let people = new Array(
   	{"name": "LiSi", "age": 41, "Binary": ar},
   	{"name": "WangWu", "age": 21, "Binary": arr},
   	{"name": "ZhaoLiu", "age": 61, "Binary": arr});
   ```

   ```ets
   // 插入一条数据，callback方式调用:
   dsHelper.insert(dseUri, valuesBucket, (err,data) => {
       console.log("dsHelper insert result: " + data);
   });
   ```

   ```ets
   // 插入一条数据，promise方式调用:
   let ret = await dsHelper.insert(dseUri, valuesBucket);
   ```

   ```ets
   // 删除指定的数据，callback方式调用:
   dsHelper.delete(dseUri, da, (err,data) => {
       console.log("dsHelper delete result: " + data);
   });
   ```

   ```ets
   // 删除指定的数据，promise方式调用:
   let ret = await dsHelper.delete(dseUri, da);
   ```

   ```ets
   // 更新数据，callback方式调用:
   dsHelper.update(dseUri, da, updateBucket, (err,data) => {
       console.log("dsHelper update result: " + data);
   });
   ```

   ```ets
   // 更新数据，promise方式调用:
   let ret = await dsHelper.update(dseUri, da, updateBucket);
   ```

   ```ets
   // 查询数据，callback方式调用:
   dsHelper.query(dseUri, da, valArray, (err,data) => {
       console.log("dsHelper query result: " + data);
   });
   ```

   ```ets
   // 查询数据，promise方式调用:
   let result = await dsHelper.query(dseUri, da, valArray);
   ```

## 相关实例

针对DataShare开发，有以下相关实例可供参考：

待补充。

- [`DataShare`：DataShare的创建与访问（eTS）（API9）](https://gitee.com/openharmony/app_samples/tree/master/ability/DataAbility)
