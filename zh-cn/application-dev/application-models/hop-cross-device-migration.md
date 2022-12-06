# 跨端迁移（仅对系统应用开放）


## 功能描述

跨端迁移的主要工作是实现将应用当前任务（包括页面控件状态变量等）迁移到目标设备，能在目标设备上接续。主要功能包括：

- 支持用户自定义数据存储及恢复。

- 支持页面路由信息和页面控件状态数据的存储及恢复。

- 支持应用兼容性检测。


## 跨端迁移流程

跨端迁移流程如下图所示。

  **图1** 跨端迁移流程图  
![hop-cross-device-migration](figures/hop-cross-device-migration.png)


## 约束限制

- 由于“跨端迁移任务管理”能力尚未具备，开发者当前只能开发具备跨端迁移能力的应用，但不能发起迁移。

- 跨端迁移要求在同UIAbility之间进行，也就是需要相同的bundleName、abilityName和签名。


## 最佳实践

为了获得最佳体验，使用wantParam传输的数据建议在100KB以下。


## 接口说明

跨端迁移主要接口如下。详细接口介绍请参见[API参考](../reference/apis/js-apis-application-ability.md)。

  **表1** 跨端迁移接口

| **接口名** | **描述** |
| -------- | -------- |
| onContinue(wantParam&nbsp;:&nbsp;{[key:&nbsp;string]:&nbsp;any}):&nbsp;OnContinueResult | 迁移发起端在该回调中保存迁移所需要的数据，同时返回是否同意迁移：<br/>-&nbsp;AGREE：表示同意。<br/>-&nbsp;REJECT：表示拒绝。<br/>-&nbsp;MISMATCH：表示版本不匹配。 |
| onCreate(want:&nbsp;Want,&nbsp;param:&nbsp;AbilityConstant.LaunchParam):&nbsp;void; | 多实例应用迁移接收端在该回调中完成数据恢复，并触发页面恢复。 |
| onNewWant(want:&nbsp;Want,&nbsp;launchParams:&nbsp;AbilityConstant.LaunchParam):&nbsp;void; | 单实例应用迁移接收端在该回调中完成数据恢复，并触发页面恢复。 |


## 开发步骤

1. 在module.json5配置数据同步权限，示例代码如下。
   
   ```json
   {
     "module": {
       "requestPermissions":[  
         {  
           "name" : "ohos.permission.DISTRIBUTED_DATASYNC",
         }
       ]
     }
   }
   ```

2. 在配置文件中配置跨端迁移相关标签字段。
   - 配置应用支持迁移
      在module.json5中配置continuable标签：true表示支持迁移，false表示不支持，默认为false。配置为false的UIAbility将被系统识别为无法迁移。

      
      ```json
      {
        "module": {
          // ...
          "abilities": [
            {
              // ...
              "continuable": true,
            }
          ]
        }
      }
      ```
   - 根据需要配置应用启动模式类型，配置详情请参照[UIAbility组件启动模式](uiability-launch-type.md)。

3. 申请数据同步权限，弹框示例代码。
   
   ```ts
   requestPermission() {   
       let context = this.context
       let permissions: Array<string> = ['ohos.permission.DISTRIBUTED_DATASYNC']   
       context.requestPermissionsFromUser(permissions).then((data) => {   
           console.info("Succeed to request permission from user with data: "+ JSON.stringify(data))
       }).catch((error) => {       
           console.info("Failed to request permission from user with error: "+ JSON.stringify(error))   
       }) 
   }
   ```

4. 在发起端UIAbility中实现[onContinue()](../reference/apis/js-apis-application-ability.md#abilityoncontinue)接口。
     当应用触发迁移时，[onContinue()](../reference/apis/js-apis-application-ability.md#abilityoncontinue)接口在发起端被调用，开发者可以在该接口中保存迁移数据，实现应用兼容性检测，决定是否支持此次迁移。
   - 保存迁移数据：开发者可以将要迁移的数据通过键值对的方式保存在wantParam中。
   
   - 应用兼容性检测：开发者可以通过从wantParam中获取目标应用的版本号与本应用版本号做兼容性校验。
   
   - 迁移决策：开发者可以通过onContinue接口的返回值决定是否支持此次迁移，返回值信息见[接口说明](#接口说明)。

     示例如下：
     
   ```ts
   import UIAbility from '@ohos.app.ability.UIAbility';
   import AbilityConstant from '@ohos.app.ability.AbilityConstant';
   
   onContinue(wantParam : {[key: string]: any}) {         
       console.info(`onContinue version = ${wantParam.version}, targetDevice: ${wantParam.targetDevice}`)         
       let workInput = AppStorage.Get<string>('ContinueWork');         
       // set user input data into want params         
       wantParam["work"] = workInput // set user input data into want params         
       console.info(`onContinue input = ${wantParam["input"]}`);         
       return AbilityConstant.OnContinueResult.AGREE     
   }
   ```

5. 在目标端设备UIAbility中实现onCreate()/onNewWant()接口，恢复迁移数据。
   - 多实例场景onCreate实现示例
      - 目标端设备上，在onCreate中根据launchReason判断该次启动是否为迁移LaunchReason.CONTINUATION。
      - 开发者可以从want中获取保存的迁移数据。
      - 完成数据恢复后，开发者需要调用restoreWindowStage来触发页面恢复。
        
         ```ts
         import UIAbility from '@ohos.app.ability.UIAbility'; 
         import AbilityConstant from '@ohos.app.ability.AbilityConstant';
         import distributedObject from '@ohos.data.distributedDataObject';  
         
         export default class EntryAbility extends UIAbility {     
             storage : LocalStorage;     
             onCreate(want, launchParam) {         
                 console.info(`EntryAbility onCreate ${AbilityConstant.LaunchReason.CONTINUATION}`)         
                 if (launchParam.launchReason == AbilityConstant.LaunchReason.CONTINUATION) {             
                     // get user data from want params             
                     let workInput = want.parameters.work             
                     console.info(`work input ${workInput}`)             
                     AppStorage.SetOrCreate<string>('ContinueWork', workInput)             
                     this.storage = new LocalStorage();             
                     this.context.restoreWindowStage(this.storage);         
                 }     
             } 
         }
         ```
   - 如果是单实例应用，则采用同样的代码实现onNewWant()接口即可。
