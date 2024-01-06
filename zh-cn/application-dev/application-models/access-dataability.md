# 访问DataAbility


访问DataAbility需导入基础依赖包，以及获取与DataAbility子模块通信的URI字符串。


其中，基础依赖包包括：


- @ohos.ability.featureAbility

- @ohos.data.dataAbility

- @ohos.data.relationalStore


访问DataAbility的示例代码如下：


1. 创建工具接口类对象。
   
   ```ts
   import featureAbility from '@ohos.ability.featureAbility'
   import ohos_data_ability from '@ohos.data.dataAbility'
   import relationalStore from '@ohos.data.relationalStore'
   ```
   ```ts
   // 作为参数传递的URI,与config中定义的URI的区别是多了一个"/",有三个"/"
   private uri = 'dataability:///com.samples.famodelabilitydevelop.DataAbility';
   private DAHelper = featureAbility.acquireDataAbilityHelper(this.uri);
   ```

2. 构建数据库相关的RDB数据。
   
   ```ts
   import ohos_data_ability from '@ohos.data.dataAbility'
   import rdb from '@ohos.data.rdb'
   ```
   ```ts
   private valuesBucket_insert: rdb.ValuesBucket = { name: 'Rose', introduction: 'insert' };
   private valuesBucket_update: rdb.ValuesBucket = { name: 'Rose', introduction: 'update' };
   private crowd = new Array({ name: 'Rose', introduction: 'batchInsert_one' } as rdb.ValuesBucket,
     { name: 'Rose', introduction: 'batchInsert_two' } as rdb.ValuesBucket);
   private columnArray = new Array('id', 'name', 'introduction');
   private predicates = new ohos_data_ability.DataAbilityPredicates();
   ```

   注：关于DataAbilityPredicates的详细内容，请参考[DataAbility谓词](../reference/apis/js-apis-data-ability.md)。
   
3. 调用insert方法向指定的DataAbility子模块插入数据。
   
   ```ts
   import { BusinessError } from '@ohos.base';
   import promptAction from '@ohos.promptAction';
   
   // callback方式调用:
   this.DAHelper.insert(this.uri, this.valuesBucket_insert, (error: BusinessError, data: number) => {
     if (error && error.code !== 0) {
       promptAction.showToast({
         message: $r('app.string.insert_failed_toast')
       });
     } else {
       promptAction.showToast({
      message: $r('app.string.insert_success_toast')
       });
     }
     Logger.info(TAG, 'DAHelper insert result: ' + data + ', error: ' + JSON.stringify(error));
   }
   );
   ```
   
   
   ```ts
   import featureAbility from '@ohos.ability.featureAbility'
   import { BusinessError } from '@ohos.base';
   import promptAction from '@ohos.promptAction';
   
   // promise方式调用(await需要在async方法中使用):
   this.DAHelper.insert(this.uri, this.valuesBucket_insert).then((datainsert) => {
     promptAction.showToast({
       message: $r('app.string.insert_success_toast')
     });
     Logger.info(TAG, 'DAHelper insert result: ' + datainsert);
   }).catch((error: BusinessError) => {
     promptAction.showToast({
       message: $r('app.string.insert_failed_toast')
     });
     Logger.error(TAG, `DAHelper insert failed. Cause: ${error.message}`);
   });
   ```
   
4. 调用delete方法删除DataAbility子模块中指定的数据。
   
   ```ts
   import featureAbility from '@ohos.ability.featureAbility'
   import promptAction from '@ohos.promptAction';
   
   // callback方式调用:
   this.DAHelper.delete(this.uri, this.predicates, (error, data) => {
     if (error && error.code !== 0) {
       promptAction.showToast({
         message: $r('app.string.delete_failed_toast')
       });
     } else {
       promptAction.showToast({
         message: $r('app.string.delete_success_toast')
       });
    }
     Logger.info(TAG, 'DAHelper delete result: ' + data + ', error: ' + JSON.stringify(error));
   }
   );
   ```

   
   ```ts
   import featureAbility from '@ohos.ability.featureAbility'
   import promptAction from '@ohos.promptAction';
   
   // promise方式调用(await需要在async方法中使用):
   this.DAHelper.delete(this.uri, this.predicates).then((datadelete) => {
    promptAction.showToast({
       message: $r('app.string.delete_success_toast')
     });
     Logger.info(TAG, 'DAHelper delete result: ' + datadelete);
   }).catch((error: BusinessError) => {
     promptAction.showToast({
       message: $r('app.string.delete_failed_toast')
     });
     Logger.error(TAG, `DAHelper delete failed. Cause: ${error.message}`);
   });
   ```

5. 调用update方法更新指定DataAbility子模块中的数据。
   
   ```ts
   import featureAbility from '@ohos.ability.featureAbility'
   import promptAction from '@ohos.promptAction';
   
   // callback方式调用:
   this.predicates.equalTo('name', 'Rose');
   this.DAHelper.update(this.uri, this.valuesBucket_update, this.predicates, (error, data) => {
     if (error && error.code !== 0) {
       promptAction.showToast({
         message: $r('app.string.update_failed_toast')
       });
     } else {
       promptAction.showToast({
         message: $r('app.string.update_success_toast')
       });
    }
     Logger.info(TAG, 'DAHelper update result: ' + data + ', error: ' + JSON.stringify(error));
   }
   );
   ```

   
   ```ts
   import featureAbility from '@ohos.ability.featureAbility'
   import promptAction from '@ohos.promptAction';
   
   // promise方式调用(await需要在async方法中使用):
   this.predicates.equalTo('name', 'Rose');
   this.DAHelper.update(this.uri, this.valuesBucket_update, this.predicates).then((dataupdate) => {
    promptAction.showToast({
       message: $r('app.string.update_success_toast')
     });
     Logger.info(TAG, 'DAHelper update result: ' + dataupdate);
   }).catch((error: BusinessError) => {
     promptAction.showToast({
       message: $r('app.string.update_failed_toast')
     });
     Logger.error(TAG, `DAHelper update failed. Cause: ${error.message}`);
   });
   ```

6. 调用query方法在指定的DataAbility子模块中查找数据。
   
   ```ts
   import featureAbility from '@ohos.ability.featureAbility'
   import promptAction from '@ohos.promptAction';
   
   // callback方式调用:
   this.predicates.equalTo('name', 'Rose');
   this.DAHelper.query(this.uri, this.columnArray, this.predicates, (error, data) => {
     if (error && error.code !== 0) {
       promptAction.showToast({
         message: $r('app.string.query_failed_toast')
       });
       Logger.error(TAG, `DAHelper query failed. Cause: ${error.message}`);
     } else {
       promptAction.showToast({
         message: $r('app.string.query_success_toast')
    });
     }
     // ResultSet是一个数据集合的游标，默认指向第-1个记录，有效的数据从0开始。
     while (data.goToNextRow()) {
    const id = data.getLong(data.getColumnIndex('id'));
       const name = data.getString(data.getColumnIndex('name'));
       const introduction = data.getString(data.getColumnIndex('introduction'));
       Logger.info(TAG, `DAHelper query result:id = [${id}], name = [${name}], introduction = [${introduction}]`);
     }
     // 释放数据集的内存
     data.close();
   }
   );
   ```

   
   ```ts
   import featureAbility from '@ohos.ability.featureAbility'
   import promptAction from '@ohos.promptAction';
   
   // promise方式调用(await需要在async方法中使用):
   this.predicates.equalTo('name', 'Rose');
   this.DAHelper.query(this.uri, this.columnArray, this.predicates).then((dataquery) => {
     promptAction.showToast({
       message: $r('app.string.query_success_toast')
     });
     // ResultSet是一个数据集合的游标，默认指向第-1个记录，有效的数据从0开始。
     while (dataquery.goToNextRow()) {
       const id = dataquery.getLong(dataquery.getColumnIndex('id'));
       const name = dataquery.getString(dataquery.getColumnIndex('name'));
       const introduction = dataquery.getString(dataquery.getColumnIndex('introduction'));
       Logger.info(TAG, `DAHelper query result:id = [${id}], name = [${name}], introduction = [${introduction}]`);
     }
     // 释放数据集的内存
     dataquery.close();
   }).catch((error: BusinessError) => {
     promptAction.showToast({
       message: $r('app.string.query_failed_toast')
     });
     Logger.error(TAG, `DAHelper query failed. Cause: ${error.message}`);
   });
   ```
   
7. 调用batchInsert方法向指定的DataAbility子模块批量插入数据。
   
   ```ts
   import featureAbility from '@ohos.ability.featureAbility'
   import promptAction from '@ohos.promptAction';
   
   // callback方式调用:
   this.DAHelper.batchInsert(this.uri, this.crowd, (error, data) => {
     if (error && error.code !== 0) {
       promptAction.showToast({
         message: $r('app.string.batchInsert_failed_toast')
       });
     } else {
       promptAction.showToast({
         message: $r('app.string.batchInsert_success_toast')
       });
    }
     Logger.info(TAG, 'DAHelper batchInsert result: ' + data + ', error: ' + JSON.stringify(error));
   }
   );
   ```

   
   ```ts
   import featureAbility from '@ohos.ability.featureAbility'
   import promptAction from '@ohos.promptAction';
   
   // promise方式调用(await需要在async方法中使用):
   this.DAHelper.batchInsert(this.uri, this.crowd).then((databatchInsert) => {
    promptAction.showToast({
       message: $r('app.string.batchInsert_success_toast')
     });
     Logger.info(TAG, 'DAHelper batchInsert result: ' + databatchInsert);
   }).catch((error: BusinessError) => {
     promptAction.showToast({
       message: $r('app.string.batchInsert_failed_toast')
     });
     Logger.error(TAG, `DAHelper batchInsert failed. Cause: ${error.message}`);
   });
   ```

8. 调用executeBatch方法向指定的DataAbility子模块进行数据的批量处理。
   
   ```ts
   import featureAbility from '@ohos.ability.featureAbility'
   import promptAction from '@ohos.promptAction';
   
   // callback方式调用:
   let operations: Array<ability.DataAbilityOperation> = [{
     uri: this.uri,
     type: featureAbility.DataAbilityOperationType.TYPE_INSERT,
     valuesBucket: { name: 'Rose', introduction: 'executeBatch' },
     predicates: this.predicates,
     expectedCount: 0,
     predicatesBackReferences: undefined,
     interrupted: true,
   }];
   this.DAHelper.executeBatch(this.uri, operations, (error, data) => {
     if (error && error.code !== 0) {
       promptAction.showToast({
         message: $r('app.string.executeBatch_failed_toast')
       });
     } else {
       promptAction.showToast({
         message: $r('app.string.executeBatch_success_toast')
       });
     }
    Logger.info(TAG, `DAHelper executeBatch, result: ` + JSON.stringify(data) + ', error: ' + JSON.stringify(error));
   }
   );
   ```

   
   ```ts
   import featureAbility from '@ohos.ability.featureAbility'
   import promptAction from '@ohos.promptAction';
   
   // promise方式调用(await需要在async方法中使用):
   let operations: Array<ability.DataAbilityOperation> = [{
     uri: this.uri,
     type: featureAbility.DataAbilityOperationType.TYPE_INSERT,
     valuesBucket: { name: 'Rose', introduction: 'executeBatch' },
     predicates: this.predicates,
     expectedCount: 0,
     predicatesBackReferences: undefined,
     interrupted: true,
   }];
   this.DAHelper.executeBatch(this.uri, operations).then((dataquery) => {
     promptAction.showToast({
       message: $r('app.string.executeBatch_success_toast')
     });
     Logger.info(TAG, 'DAHelper executeBatch result: ' + JSON.stringify(dataquery));
   }).catch((error: BusinessError) => {
     promptAction.showToast({
       message: $r('app.string.executeBatch_failed_toast')
     });
     Logger.error(TAG, `DAHelper executeBatch failed. Cause: ${error.message}`);
   });
   ```


DataAbility的客户端的接口是由工具接口类对象DataAbilityHelper向外提供，相关接口可参考[DataAbilityHelper模块](../reference/apis/js-apis-inner-ability-dataAbilityHelper.md)。
