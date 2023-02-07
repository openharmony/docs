# Accessing a DataAbility


To access a DataAbility, import the basic dependency packages and obtain the URI string for communicating with the DataAbility.


The basic dependency packages include:


- @ohos.ability.featureAbility

- @ohos.data.dataAbility

- @ohos.data.rdb


The sample code for accessing a DataAbility is as follows:


1. Create a **DataAbilityHelper** instance.
   
   ```ts
   // Different from the URI defined in the config.json file, the URI passed in the parameter has an extra slash (/), three slashes in total.
   import featureAbility from '@ohos.ability.featureAbility'
   import ohos_data_ability from '@ohos.data.dataAbility'
   import ohos_data_rdb from '@ohos.data.rdb'
   
   let urivar = "dataability:///com.ix.DataAbility"
   let DAHelper = featureAbility.acquireDataAbilityHelper(urivar);
   ```

2. Construct RDB data.
   
   ```ts
   let valuesBucket = {"name": "gaolu"}
   let da = new ohos_data_ability.DataAbilityPredicates()
   let valArray =new Array("value1");
   let cars = new Array({"batchInsert1" : "value1",});
   ```

   For details about DataAbilityPredicates, see [DataAbility Predicates](../reference/apis/js-apis-data-ability.md).

3. Use **insert** to insert data to the DataAbility.
   
   ```ts
   // Callback mode:
   DAHelper.insert(
     urivar,
     valuesBucket,
     (error, data) => {
       console.info("DAHelper insert result: " + data)
     }
   );
   ```

   
   ```ts
   // Promise mode (await needs to be used in the asynchronous method):
   let datainsert = await DAHelper.insert(urivar, valuesBucket).then((data) => {
     console.info("insert success.");
   }).catch((error) => {
     console.error("insert failed.");
   });
   ```

4. Use **delete** to delete data from the DataAbility.
   
   ```ts
   // Callback mode:
   DAHelper.delete(
     urivar,
     da,
     (error, data) => {
       console.info("DAHelper delete result: " + data)
     }
   );
   ```

   
   ```ts
   // Promise mode (await needs to be used in the asynchronous method):
   let datadelete = await DAHelper.delete(
     urivar,
     da,
   );
   ```

5. Use **update** to update data in the DataAbility.
   
   ```ts
   // Callback mode:
   DAHelper.update(
     urivar,
     valuesBucket,
     da,
     (error, data) => {
       console.info("DAHelper update result: " + data)
     }
   );
   ```

   
   ```ts
   // Promise mode (await needs to be used in the asynchronous method):
   let dataupdate = await DAHelper.update(
     urivar,
     valuesBucket,
     da,
   );
   ```

6. Use **query** to query data in the DataAbility.
   
   ```ts
   // Callback mode:
   DAHelper.query(
     urivar,
     valArray,
     da,
     (error, data) => {
       console.info("DAHelper query result: " + data)
     }
   );
   ```

   
   ```ts
   // Promise mode (await needs to be used in the asynchronous method):
   let dataquery = await DAHelper.query(
     urivar,
     valArray,
     da
   );
   ```

7. Use **batchInsert** to insert data in batches to the DataAbility.
   
   ```ts
   // Callback mode:
   DAHelper.batchInsert(
     urivar,
     cars,
     (error, data) => {
       console.info("DAHelper batchInsert result: " + data)
     }
   );
   ```

   
   ```ts
   // Promise mode (await needs to be used in the asynchronous method):
   let databatchInsert = await DAHelper.batchInsert(
     urivar,
     cars
   );
   ```

8. Use **executeBatch** to process data in batches in the DataAbility.
   
   ```ts
   // Callback mode:
   DAHelper.executeBatch(
     urivar,
     [
       {
         uri: urivar,
         type: featureAbility.DataAbilityOperationType.TYPE_INSERT,
         valuesBucket: {"executeBatch" : "value1",},
         predicates: da,
         expectedCount:0,
         predicatesBackReferences: null,
         interrupted:true,
       }
     ],
     (error, data) => {
       console.info("DAHelper executeBatch result: " + data)
     }
   );
   ```

   
   ```ts
   // Promise mode (await needs to be used in the asynchronous method):
   let dataexecuteBatch = await DAHelper.executeBatch(
     urivar,
     [
       {
         uri: urivar,
         type: featureAbility.DataAbilityOperationType.TYPE_INSERT,
         valuesBucket:
         {
           "executeBatch" : "value1",
         },
         predicates: da,
         expectedCount:0,
         predicatesBackReferences: null,
         interrupted:true,
       }
     ]
   );
   ```


The APIs for operating a DataAbility are provided by **DataAbilityHelper**. For details about the APIs, see [DataAbilityHelper](../reference/apis/js-apis-inner-ability-dataAbilityHelper.md).
