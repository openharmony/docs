# 应用迁移开发指导

## 场景介绍

迁移的主要工作是实现将应用当前任务，包括页面部分数据、栈信息等，迁移到远端设备。迁移成功后，本端任务将被清除；若失败则不会，可允许再次迁移。

  

## 接口说明

迁移提供的能力如下，具体的API详见接口文档

**表1** 应用迁移API接口功能介绍

|接口名 | 描述|
|:------ | :------|
| onContinue(wantParams : {[key: string]: any}) | 迁移发起端在该回调中保存迁移所需要的数据，同时返回是否同意迁移：true表示同意，false表示拒绝。 |



## 开发步骤

### 迁移应用



1. 配置

   - 配置应用支持迁移

   ​    在config.json中配置continuable字段：true表示支持迁移，false表示不支持，默认为false.

   ```
   "continuable": true
   ```

   ​    配置为false的应用将无法在任务中心进行迁移。

   * 配置应用启动类型

   ​    迁移当前只支持多实例应用，需要在在config.json中配置launchType字段为standard

   ```
   "launchType": "standard"
   ```

   

2. 实现onContinue接口 

   导入模块

   ```
   import Ability from '@ohos.application.Ability';
   ```

   - 要实现迁移，此接口必须实现并返回true，否则默认为拒绝迁移。


   - 示例

   ```javascript
       onContinue(wantParams : {[key: string]: any}) {
           console.log("MainAbility onContinue")
           return true;
       }
   ```

   

3. 在onCreate接口中实现迁移逻辑

   - 远端设备上，在onCreate中根据launchReason判断该次启动是否为迁移LaunchReason.CONTINUATION（3）

   
   - 完成数据恢复后，开发者需要调用**restoreWindowStage**来触发页面恢复。
   

   * 示例
   
   ```javascript
       onCreate(want , launchParam) {
           // Ability is creating, initialize resources for this ability
           console.log("MainAbility onCreate", launchParam.launchReason);
           if (launchParam.launchReason == LaunchReason.CONTINUATION) {
               this.contentStorage = new ContenStorage();
               this.context.restoreWindowStage(this.contentStorage);
           }
       }
   
   ```
   
   

### 迁移数据

1. 使用自定义数据

   - wantParams中可以填写key-value形式自定义数据，key类型string，填充的数据将随want被传输到远端，用于携带一些简单、轻量的数据。


   ```javascript
       onContinue(wantParams : {[key: string]: any}) {
           console.log("Continue My Data")
           wantParams["myData"] = "my1234567";
           return true;
       }
   ```

   - 同时在远端判断如果是迁移，可以从want.parameters中取出在发起端保存的自定义数据。

   ```javascript
       onCreate(want , launchParam) {
           if (launchParam.launchReason == LaunchReason.CONTINUATION) {
               console.log("onCreate LaunchReason = CONTINUATION",want.parameters["myData"]); // my1234567
               ...
               this.context.restoreWindowStage(this.contentStorage);
           }
       }
   
   ```

   

2. 使用分布式对象

   使用分布式对象可以传输更多的数据到远端设备，更多用法详见分布式对象接口文档。

   - 发起端在onContinue中，将待迁移的数据存入分布式对象中，然后设置好session id，并通过wantParams将session id传到远端设备。


   - 远端设备在onCreate中，取出发起端传过来的session id，建立分布式对象并关联该session id，这样就能实现分布式对象的同步。需要注意的是，在调用restoreWindowStage之前，迁移需要的分布式对象必须全部关联完，保证能够获取到正确的数据。


   * 示例

   ```javascript
   import Ability from '@ohos.application.Ability';
   import distributedObject from '@ohos.data.distributedDataObject';
   
   var g_object = distributedObject.createDistributedObject({name:undefined});
   
   export default class MainAbility extends Ability {
       contentStorage : ContenStorage
       sessionId : string;
       onCreate(want , launchParam) {
           if (launchParam.launchReason == 3) {
               this.sessionId = want.parameters["session"] // 取出session id
   
               function statusCallback(sessionId, networkid, status) {
                   console.info("object status change sessionId: " + sessionId + " status: " + status +
                   "g_object.name: " + g_object.name); // 回调中可以取到同步过来的分布式对象内容 name = Amy
               }
               g_object.on("status", statusCallback); // 注册分布式对象同步结果的监听
   
               g_object.setSessionId(this.sessionId); // 将本地分布式对象也关联发起端的session id
   
               this.contentStorage = new ContenStorage();
               this.context.restoreWindowStage(this.contentStorage);
           }
       }
   
       onContinue(wantParams : {[key: string]: any}) {
           console.log("using distributedObject")
           this.sessionId = "654321";
           g_object.setSessionId(this.sessionId); //1 设置分布式对象的session id
           g_object.name = "Amy"; // 填入数据
           wantParams["session"] = this.sessionId; // 将session id 通过want传到远端
           return true;
       }
   ```

   





