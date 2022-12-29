# 访问DataAbility


访问DataAbility需导入基础依赖包，以及获取与DataAbility子模块通信的URI字符串。


其中，基础依赖包包括：


- @ohos.ability.featureAbility

- @ohos.data.dataAbility

- @ohos.data.rdb


访问DataAbility的示例代码如下：


1. 创建工具接口类对象。
   
   ```ts
   // 作为参数传递的URI,与config中定义的URI的区别是多了一个"/",有三个"/"
   import featureAbility from '@ohos.ability.featureAbility'
   import ohos_data_ability from '@ohos.data.dataAbility'
   import ohos_data_rdb from '@ohos.data.rdb'
   
   let urivar = "dataability:///com.ix.DataAbility"
   let DAHelper = featureAbility.acquireDataAbilityHelper(urivar);
   ```

2. 构建数据库相关的RDB数据。
   
   ```ts
   let valuesBucket = {"name": "gaolu"}
   let da = new ohos_data_ability.DataAbilityPredicates()
   let valArray =new Array("value1");
   let cars = new Array({"batchInsert1" : "value1",});
   ```

   注：关于DataAbilityPredicates的详细内容，请参考[DataAbility谓词](../reference/apis/js-apis-data-ability.md)。

3. 调用insert方法向指定的DataAbility子模块插入数据。
   
   ```ts
   // callback方式调用:
   DAHelper.insert(
     urivar,
     valuesBucket,
     (error, data) => {
       console.info("DAHelper insert result: " + data)
     }
   );
   ```

   
   ```ts
   // promise方式调用(await需要在async方法中使用):
   let datainsert = await DAHelper.insert(urivar, valuesBucket).then((data) => {
     console.info("insert success.");
   }).catch((error) => {
     console.error("insert failed.");
   });
   ```

4. 调用delete方法删除DataAbility子模块中指定的数据。
   
   ```ts
   // callback方式调用:
   DAHelper.delete(
     urivar,
     da,
     (error, data) => {
       console.info("DAHelper delete result: " + data)
     }
   );
   ```

   
   ```ts
   // promise方式调用(await需要在async方法中使用):
   let datadelete = await DAHelper.delete(
     urivar,
     da,
   );
   ```

5. 调用update方法更新指定DataAbility子模块中的数据。
   
   ```ts
   // callback方式调用:
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
   // promise方式调用(await需要在async方法中使用):
   let dataupdate = await DAHelper.update(
     urivar,
     valuesBucket,
     da,
   );
   ```

6. 调用query方法在指定的DataAbility子模块中查找数据。
   
   ```ts
   // callback方式调用:
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
   // promise方式调用(await需要在async方法中使用):
   let dataquery = await DAHelper.query(
     urivar,
     valArray,
     da
   );
   ```

7. 调用batchInsert方法向指定的DataAbility子模块批量插入数据。
   
   ```ts
   // callback方式调用:
   DAHelper.batchInsert(
     urivar,
     cars,
     (error, data) => {
       console.info("DAHelper batchInsert result: " + data)
     }
   );
   ```

   
   ```ts
   // promise方式调用(await需要在async方法中使用):
   let databatchInsert = await DAHelper.batchInsert(
     urivar,
     cars
   );
   ```

8. 调用executeBatch方法向指定的DataAbility子模块进行数据的批量处理。
   
   ```ts
   // callback方式调用:
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
   // promise方式调用(await需要在async方法中使用):
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


DataAbility的客户端的接口是由工具接口类对象DataAbilityHelper向外提供，相关接口可参考[DataAbilityHelper模块](../reference/apis/js-apis-inner-ability-dataAbilityHelper.md)。
