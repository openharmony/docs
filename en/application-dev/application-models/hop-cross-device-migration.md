# Cross-Device Migration


## When to Use

The main task of cross-device migration is to migrate the current mission (including the page component status) of an application to the target device so that the mission can continue on that device. Cross-device migration supports the following features:

- Storage and restoration of custom data

- Storage and restoration of page routing information and page component status data

- Application compatibility detection

- Setting the mission continuation state (**ACTIVE** by default) dynamically

  For example, for an editing application, only the text editing page needs to be migrated to the target service. In this case, you can call [setMissionContinueState](../reference/apis/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextsetmissioncontinuestate10) for precise control.

- Determining whether to restore the page stack (page stack restored by default)

  If an application wants to customize the page to be displayed after being migrated to the target device, the application can use [SUPPORT_CONTINUE_PAGE_STACK_KEY](../reference/apis/js-apis-app-ability-wantConstant.md#wantconstantparams) for precise control.

- Determining whether to exit the application on the initiator after a successful migration (application exit by default)

  You can use [SUPPORT_CONTINUE_SOURCE_EXIT_KEY](../reference/apis/js-apis-app-ability-wantConstant.md#wantconstantparams) for precise control.


## Cross-Device Migration Process

The following figure shows the cross-device migration process.

**Figure 1** Cross-device migration process

![hop-cross-device-migration](figures/hop-cross-device-migration.png)


## Constraints

- Since cross-device migration mission management is not available, you can only develop applications that support cross-device migration. Your application cannot initiate migration.

- Cross-device migration must be performed between the same UIAbility component. In other words, the components must have the same **bundleName**, **abilityName**, and **signature**.


## Best Practices

For better user experience, you are advised to use the **wantParam** parameter to transmit data smaller than 100 KB.


## Available APIs

The table below describes the main APIs used for cross-device migration. For details, see [API Reference](../reference/apis/js-apis-app-ability-uiAbility.md).

**Table 1** Cross-device migration APIs

| **API**| Description|
| -------- | -------- |
| onContinue(wantParam : {[key: string]: Object}): OnContinueResult | Called by the initiator to store the data required for migration and indicate whether the migration is accepted.<br>- **AGREE**: The migration is accepted.<br>- **REJECT**: The migration is rejected, for example, when an application is abnormal in **onContinue()**.<br>- **MISMATCH**: The version does not match. The application on the initiator can obtain the version number of the target application from **onContinue()**. If the migration cannot be performed due to version mismatch, this error code is returned.|
| onCreate(want: Want, param: AbilityConstant.LaunchParam): void; | Called by the target to restore the data and UI page when the target uses cold start or the target is a multiton application and uses hot start. For details, see [UIAbility Component Launch Type](uiability-launch-type.md).|
| onNewWant(want: Want, launchParams: AbilityConstant.LaunchParam): void; | Called by the target to restore the data and UI page when the target is a singleton application and uses hot start. For details, see [UIAbility Component Launch Type](uiability-launch-type.md).|



## How to Develop

1. Request the **ohos.permission.DISTRIBUTED_DATASYNC** permission. For details, see [Declaring Permissions in the Configuration File](../security/accesstoken-guidelines.md#declaring-permissions-in-the-configuration-file).

2. Display a dialog box to ask for authorization from the user when the application is started for the first time. For details, see [Requesting User Authorization](../security/accesstoken-guidelines.md#requesting-user-authorization).

3. Configure the fields related to cross-device migration in the configuration file.

   Configure the application to support migration.

   Set the **continuable** field in the **module.json5** file to **true**. The default value is **false**. If this parameter is set to **false**, the application cannot be continued on the target device.


   ```json
   {
     "module": {
       ...
       "abilities": [
         {
           ...
           "continuable": true,
         }
       ]
     }
   }
   ```

   Configure the application launch type. For details, see [UIAbility Component Launch Type](uiability-launch-type.md).

4. Implement [onContinue()](../reference/apis/js-apis-app-ability-uiAbility.md#abilityoncontinue) in the UIAbility of the initiator.

   [onContinue()](../reference/apis/js-apis-app-ability-uiAbility.md#abilityoncontinue) is called on the initiator. You can save the data in this method to implement application compatibility check and migration decision.
   - Saving migrated data: You can save the data to be migrated in key-value pairs in **wantParam**.

   - Checking application compatibility: You can obtain the version number of the target application from **wantParam** and that of the current application from **wantParam.version** of the **onContinue()** callback. Then you can check the compatibility between the two.

   - Making a migration decision: You can determine whether to support the migration based on the return value of **onContinue()**. For details about the return values, see [Available APIs](#available-apis).

   The sample code is as follows:
   
   ```ts
   import UIAbility from '@ohos.app.ability.UIAbility';
   import AbilityConstant from '@ohos.app.ability.AbilityConstant';
   
   onContinue(wantParam : {[key: string]: any}) {         
       console.info(`onContinue version = ${wantParam.version}, targetDevice: ${wantParam.targetDevice}`)         
       let workInput = AppStorage.Get<string>('ContinueWork');         
       // Set the user input data into wantParam.        
       wantParam["work"] = workInput // set user input data into want params         
       console.info(`onContinue input = ${wantParam["input"]}`);         
       return AbilityConstant.OnContinueResult.AGREE     
   }
   ```

5. Implement **onCreate()** and **onNewWant()** in the UIAbility of the target application to implement data restoration.
   - Implementation example of **onCreate**
      - The target device determines whether the startup is **LaunchReason.CONTINUATION** based on **launchReason** in **onCreate()**.
      - You can obtain the saved migration data from the **want** parameter.
      - After data restoration is complete, call **restoreWindowStage** to trigger page restoration, including page stack information.
        
         ```ts
         import UIAbility from '@ohos.app.ability.UIAbility'; 
         import AbilityConstant from '@ohos.app.ability.AbilityConstant';
         import distributedObject from '@ohos.data.distributedDataObject';  
         
         export default class EntryAbility extends UIAbility {     
             storage : LocalStorage;     
             onCreate(want, launchParam) {         
                 console.info(`EntryAbility onCreate ${AbilityConstant.LaunchReason.CONTINUATION}`)         
                 if (launchParam.launchReason == AbilityConstant.LaunchReason.CONTINUATION) {             
                     // Obtain the user data from the want parameter.            
                     let workInput = want.parameters.work             
                     console.info(`work input ${workInput}`)             
                     AppStorage.SetOrCreate<string>('ContinueWork', workInput)             
                     this.storage = new LocalStorage();             
                     this.context.restoreWindowStage(this.storage);         
                 }     
             } 
         }
         ```
   - For a singleton application, you must also implement **onNewWant()**, in the same way as **onCreate()**.
      - Determine the migration scenario in **onNewWant()**, restore data, and trigger page restoration.

         ```ts  
         export default class EntryAbility extends UIAbility {     
             storage : LocalStorage;     
             onNewWant(want, launchParam) {         
                 console.info(`EntryAbility onNewWant ${AbilityConstant.LaunchReason.CONTINUATION}`)         
                 if (launchParam.launchReason == AbilityConstant.LaunchReason.CONTINUATION) {             
                     // Obtain the user data from the want parameter.            
                     let workInput = want.parameters.work             
                     console.info(`work input ${workInput}`)             
                     AppStorage.SetOrCreate<string>('ContinueWork', workInput)             
                     this.storage = new LocalStorage();             
                     this.context.restoreWindowStage(this.storage);         
                 }     
             } 
         }
      ```
   
6. (Optional) Call [setMissionContinueState](../reference/apis/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextsetmissioncontinuestate10) to set the mission continuation state.

   For an application that supports migration, mission migration is enabled by default, and the system notifies peripheral trusted devices that a mission can be migrated or canceled based on the gain/loss focus state of the mission. If you want the system to send a notification to peripheral devices only when your application is in a specific scenario, set the migration continuation state to **INACTIVE** when the application is started and change it to **ACTIVE** when the application enters that specific scenario.

    - Example: An application does not require migration during startup.

        ```ts
        import UIAbility from '@ohos.app.ability.UIAbility';
        import AbilityConstant from '@ohos.app.ability.AbilityConstant';

        onCreate(want, launchParam) {
          this.context.setMissionContinueState(AbilityConstant.ContinueState.INACTIVE, (result) => {
            console.info(`setMissionContinueState: ${JSON.stringify(result)}`);
          });
        }
        ```
    - Example: The application requires migration in a specific service process.

        ```ts
        import UIAbility from '@ohos.app.ability.UIAbility';
        import AbilityConstant from '@ohos.app.ability.AbilityConstant';

        this.context.setMissionContinueState(AbilityConstant.ContinueState.ACTIVE, (result) => {
          console.info(`setMissionContinueState: ${JSON.stringify(result)}`);
        });
        ```

7. (Optional) Configure whether to restore the page stack.

   By default, the page stack is restored. If an application does not want to use the page stack restored by the system, you can set the page to be displayed in **onWindowStageRestore()**. For details about the configuration, see [SUPPORT_CONTINUE_PAGE_STACK_KEY](../reference/apis/js-apis-app-ability-wantConstant.md#wantconstantparams).

    - Example: An application does not want automatically restored page stack information.

        ```ts
        import UIAbility from '@ohos.app.ability.UIAbility';
        import wantConstant from '@ohos.app.ability.wantConstant.d.ts';

        onContinue(wantParam : {[key: string]: any}) {         
            console.info(`onContinue version = ${wantParam.version}, targetDevice: ${wantParam.targetDevice}`)         
            wantParam[wantConstant.Params.SUPPORT_CONTINUE_PAGE_STACK_KEY] = false;
            return AbilityConstant.OnContinueResult.AGREE;
        }

        onWindowStageRestore(windowStage) {
            // Set the page to be displayed after the migration.
            windowStage.setUIContent(this.contex, "pages/index", null);
        }
        ```

8. (Optional) Configure whether to exit the application on the initiator after a successful migration.

   By default, the application on the initiator exits. If you do not want the application on the initiator to automatically exit after a successful migration, set the [SUPPORT_CONTINUE_SOURCE_EXIT_KEY](../reference/apis/js-apis-app-ability-wantConstant.md#wantconstantparams) parameter.

    - Example: An application on the initiator does not exit after a successful migration.

        ```ts
        import UIAbility from '@ohos.app.ability.UIAbility';
        import wantConstant from '@ohos.app.ability.wantConstant.d.ts';

        onContinue(wantParam : {[key: string]: any}) {         
            console.info(`onContinue version = ${wantParam.version}, targetDevice: ${wantParam.targetDevice}`)         
            wantParam[wantConstant.Params.SUPPORT_CONTINUE_SOURCE_EXIT_KEY] = false;
            return AbilityConstant.OnContinueResult.AGREE;
        }
        ```
