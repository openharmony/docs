# Accessing a DataAbility


To access a DataAbility, import the basic dependency packages and obtain the URI string for communicating with the DataAbility.


The basic dependency packages include:


- @ohos.ability.featureAbility

- @ohos.data.dataAbility

- @ohos.data.relationalStore


The sample code for accessing a DataAbility is as follows:


1. Create a **DataAbilityHelper** instance.
   
   ```ts
   import featureAbility from '@ohos.ability.featureAbility'
   import ohos_data_ability from '@ohos.data.dataAbility'
   import relationalStore from '@ohos.data.relationalStore'
   ```
   ```ts
   // Different from the URI defined in the config.json file, the URI passed in the parameter has an extra slash (/), three slashes in total.
   private uri = 'dataability:///com.samples.famodelabilitydevelop.DataAbility';
   private DAHelper = featureAbility.acquireDataAbilityHelper(this.uri);
   ```

2. Construct RDB data.
   
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

   For details about DataAbilityPredicates, see [DataAbility Predicates](../reference/apis/js-apis-data-ability.md).
   
3. Use **insert** to insert data to the DataAbility.
   
   ```ts
   import { BusinessError } from '@ohos.base';
   import promptAction from '@ohos.promptAction';
   import Logger from '../../utils/Logger';
   
   const TAG: string = 'PageDataAbility';
   
   // Callback mode:
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
   import Logger from '../../utils/Logger';
   
   const TAG: string = 'PageDataAbility';
   
   // Promise mode (await needs to be used in the asynchronous method):
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
   
4. Use **delete** to delete data from the DataAbility.
   
   ```ts
   import featureAbility from '@ohos.ability.featureAbility'
   import promptAction from '@ohos.promptAction';
   import Logger from '../../utils/Logger';
   
   const TAG: string = 'PageDataAbility';
   
   // Callback mode:
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
   import Logger from '../../utils/Logger';
   
   const TAG: string = 'PageDataAbility';
   
   // Promise mode (await needs to be used in the asynchronous method):
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

5. Use **update** to update data in the DataAbility.
   
   ```ts
   import featureAbility from '@ohos.ability.featureAbility'
   import promptAction from '@ohos.promptAction';
   import Logger from '../../utils/Logger';
   
   const TAG: string = 'PageDataAbility';
   
   // Callback mode:
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
   import Logger from '../../utils/Logger';
   
   const TAG: string = 'PageDataAbility';
   
   // Promise mode (await needs to be used in the asynchronous method):
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

6. Use **query** to query data in the DataAbility.
   
   ```ts
   import featureAbility from '@ohos.ability.featureAbility'
   import promptAction from '@ohos.promptAction';
   import Logger from '../../utils/Logger';
   
   const TAG: string = 'PageDataAbility';
   
   // Callback mode:
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
     // ResultSet is a cursor of a data set. By default, the cursor points to the -1st record. Valid data starts from 0.
     while (data.goToNextRow()) {
    const id = data.getLong(data.getColumnIndex('id'));
       const name = data.getString(data.getColumnIndex('name'));
       const introduction = data.getString(data.getColumnIndex('introduction'));
       Logger.info(TAG, `DAHelper query result:id = [${id}], name = [${name}], introduction = [${introduction}]`);
     }
     // Release the data set memory.
     data.close();
   }
   );
   ```

   
   ```ts
   import featureAbility from '@ohos.ability.featureAbility'
   import promptAction from '@ohos.promptAction';
   import Logger from '../../utils/Logger';
   
   const TAG: string = 'PageDataAbility';
   
   // Promise mode (await needs to be used in the asynchronous method):
   this.predicates.equalTo('name', 'Rose');
   this.DAHelper.query(this.uri, this.columnArray, this.predicates).then((dataquery) => {
     promptAction.showToast({
       message: $r('app.string.query_success_toast')
     });
     // ResultSet is a cursor of a data set. By default, the cursor points to the -1st record. Valid data starts from 0.
     while (dataquery.goToNextRow()) {
       const id = dataquery.getLong(dataquery.getColumnIndex('id'));
       const name = dataquery.getString(dataquery.getColumnIndex('name'));
       const introduction = dataquery.getString(dataquery.getColumnIndex('introduction'));
       Logger.info(TAG, `DAHelper query result:id = [${id}], name = [${name}], introduction = [${introduction}]`);
     }
     // Release the data set memory.
     dataquery.close();
   }).catch((error: BusinessError) => {
     promptAction.showToast({
       message: $r('app.string.query_failed_toast')
     });
     Logger.error(TAG, `DAHelper query failed. Cause: ${error.message}`);
   });
   ```
   
7. Use **batchInsert** to insert data in batches to the DataAbility.
   
   ```ts
   import featureAbility from '@ohos.ability.featureAbility'
   import promptAction from '@ohos.promptAction';
   import Logger from '../../utils/Logger';
   
   const TAG: string = 'PageDataAbility';
   
   // Callback mode:
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
   import Logger from '../../utils/Logger';
   
   const TAG: string = 'PageDataAbility';
   
   // Promise mode (await needs to be used in the asynchronous method):
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

8. Use **executeBatch** to process data in batches in the DataAbility.
   
   ```ts
   import featureAbility from '@ohos.ability.featureAbility'
   import promptAction from '@ohos.promptAction';
   import Logger from '../../utils/Logger';
   
   const TAG: string = 'PageDataAbility';
   
   // Callback mode:
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
   import Logger from '../../utils/Logger';
   
   const TAG: string = 'PageDataAbility';
   
   // Promise mode (await needs to be used in the asynchronous method):
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


The APIs for operating a DataAbility are provided by **DataAbilityHelper**. For details about the APIs, see [DataAbilityHelper](../reference/apis/js-apis-inner-ability-dataAbilityHelper.md).
