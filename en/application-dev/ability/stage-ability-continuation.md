# Ability Continuation Development

## When to Use

Ability continuation is to continue the current mission of an application, including the UI component state variables and distributed objects, on another device. The UI component state variables are used to synchronize UI data, and the distributed objects are used to synchronize memory data.

## Available APIs

The following table lists the APIs used for ability continuation. For details about the APIs, see [Ability](../reference/apis/js-apis-application-ability.md).

**Table 1** Ability continuation APIs

|API| Description|
|:------ | :------|
| onContinue(wantParam : {[key: string]: any}): OnContinueResult | Called by the initiator to store the data required for continuation and request continuation. The value **AGREE** means that the continuation is accepted, and **REJECT** means the continuation is rejected, and **MISMATCH** means a version mismatch.|
| onCreate(want: Want, param: LaunchParam): void | Called by the target to restore the data and UI page.|
| **enum** OnContinueResult | Enumerates the return values of **onContinue**. The options are as follows: **AGREE** (request accepted), **REJECT** (request denied), and **MISMATCH** (version mismatch).|



**Figure 1** Ability continuation development

![continuation_dev](figures/continuation-info.png)

## How to Develop

### Application Continuation

1. Configuration

   - Configure the application to support ability continuation.

     Set the **continuable** field in the **module.json5** file to **true**. The default value is **false**. If this parameter is set to **false**, the application cannot be continued on another device.

   ```javascript
   "continuable": true
   ```



   - Configure the application startup type.

     Set **launchType** in the **module.json5** file to **standard** to add multi-instance support to the application.

   ```javascript
   "launchType": "standard"
   ```



   - Apply for the distributed permissions.

     Declare the **DISTRIBUTED_DATASYNC** permission in the **module.json5** file for the application.

   ```javascript
   "requestPermissions": [
       {
           "name": "ohos.permission.DISTRIBUTED_DATASYNC"
       },
   ```

   This permission must be granted by the user in a dialog box when the application is started for the first time. To enable the application to display a dialog box to ask for the permission, add the following code to **onWindowStageCreate** of the **Ability** class:

   ```javascript
   requestPermissions = async () => {
       let permissions: Array<string> = [
           "ohos.permission.DISTRIBUTED_DATASYNC"
       ];
       let needGrantPermission = false
       let accessManger = accessControl.createAtManager()
       Logger.info("app permission get bundle info")
       let bundleInfo = await bundle.getApplicationInfo(BUNDLE_NAME, 0, 100)
       Logger.info(`app permission query permission ${bundleInfo.accessTokenId.toString()}`)
       for (const permission of permissions) {
           Logger.info(`app permission query grant status ${permission}`)
           try {
               let grantStatus = await accessManger.verifyAccessToken(bundleInfo.accessTokenId, permission)
               if (grantStatus === PERMISSION_REJECT) {
                   needGrantPermission = true
                   break;
               }
           } catch (err) {
               Logger.error(`app permission query grant status error ${permission} ${JSON.stringify(err)}`)
               needGrantPermission = true
               break;
           }
       }
       if (needGrantPermission) {
           Logger.info("app permission needGrantPermission")
           try {
               await this.context.requestPermissionsFromUser(permissions)
           } catch (err) {
               Logger.error(`app permission ${JSON.stringify(err)}`)
           }
       } else {
           Logger.info("app permission already granted")
       }
   }
   ```



2. Implement the **onContinue()** API.

   The **onContinue()** API is called by the initiator to save the UI component state variables and memory data and prepare for continuation. After the application completes the continuation preparation, the system must return **OnContinueResult.AGREE(0)** to accept the continuation request. If an error code is returned, the request is rejected. If this API is not implemented, the system rejects the continuation request by default.

   Modules to import:

   ```javascript
   import Ability from '@ohos.application.Ability';
   import AbilityConstant from '@ohos.application.AbilityConstant';
   ```

   To implement ability continuation, you must implement this API and have the value **AGREE** returned.


   Example

   ```javascript
    onContinue(wantParam : {[key: string]: any}) {
        Logger.info("onContinue using distributedObject")
        // Set the user input data into the want parameter.
        wantParam["input"] = AppStorage.Get<string>('ContinueInput');
        Logger.info(`onContinue input = ${wantParam["input"]}`);
        return AbilityConstant.OnContinueResult.AGREE
    }
   ```



3. Implement the continuation logic in the **onCreate()** API.

   The **onCreate()** API is called by the target. When the ability is started on the target device, this API is called to instruct the application to synchronize the memory data and UI component state, and triggers page restoration after the synchronization is complete. If the continuation logic is not implemented, the ability will be started in common startup mode and the page cannot be restored.

   The target device determines whether the startup is **LaunchReason.CONTINUATION** based on **launchReason** in **onCreate()**.


   After data restore is complete, call **restoreWindowStage** to trigger page restoration.


   Example

   ```javascript
       onCreate(want, launchParam) {
           Logger.info(`MainAbility onCreate ${AbilityConstant.LaunchReason.CONTINUATION}`)
           globalThis.abilityWant = want;
           if (launchParam.launchReason == AbilityConstant.LaunchReason.CONTINUATION) {
               let input = want.parameters.input // Obtain user data from want params.
               AppStorage.SetOrCreate<string>('ContinueInput', input)
               Logger.info(`onCreate for continuation sessionId:  ${this.sessionId}`)

               this.contentStorage = new ContentStorage();
               this.context.restoreWindowStage(this.contentStorage);
           }
       }
   ```



### Data Continuation

Use distributed objects.

Distributed objects allow cross-device data synchronization like local variables. For two devices that form a Super Device, when data in the distributed data object of an application is added, deleted, or modified on a device, the data for the same application is also updated on the other device. Both devices can listen for the data changes and online and offline states of the other. For details, see [Distributed Data Object Development](../database/database-distributedobject-guidelines.md).

In the ability continuation scenario, the distributed data object is used to synchronize the memory data from the local device to the target device.

- In **onContinue()**, the initiator saves the data to be continued to the distributed object, sets the session ID, and sends the session ID to the target device through **wantParam**.

    ```javascript
      import Ability from '@ohos.application.Ability';
      import distributedObject from '@ohos.data.distributedDataObject';

      var g_object = distributedObject.createDistributedObject({name:undefined});

      export default class MainAbility extends Ability {
          contentStorage : ContentStorage
          sessionId : string;

       onContinue(wantParam : {[key: string]: any}) {
           Logger.info("onContinue using distributedObject")
           this.sessionId = distributedObject.genSessionId();
           // Set the session ID for the distributed data object.
           g_object.setSessionId(this.sessionId);
           g_object.name = "Amy";
           // Set the session ID into the want parameter.
           wantParam["session"] = this.sessionId;
           return AbilityConstant.OnContinueResult.AGREE
       }

    ```

- The target device obtains the session ID from **onCreate()**, creates a distributed object, and associates the distributed object with the session ID. In this way, the distributed object can be synchronized. Before calling **restoreWindowStage**, ensure that all distributed objects required for continuation have been associated.

   ```javascript
      import Ability from '@ohos.application.Ability';
      import distributedObject from '@ohos.data.distributedDataObject';

      var g_object = distributedObject.createDistributedObject({name:undefined});

      export default class MainAbility extends Ability {
          contentStorage : ContentStorage
          sessionId : string;

          statusCallback(sessionId, networkid, status) {
              Logger.info(`continuation object status change, sessionId: ${sessionId}, status: ${status}, g_object.name: ${g_object.name}`)
          }

          onCreate(want, launchParam) {
              Logger.info(`MainAbility onCreate ${AbilityConstant.LaunchReason.CONTINUATION}`)
              if (launchParam.launchReason == AbilityConstant.LaunchReason.CONTINUATION) {
                  // Obtain the session ID of the distributed data object from the want parameter.
                  this.sessionId = want.parameters.session
                  Logger.info(`onCreate for continuation sessionId:  ${this.sessionId}`)

                  g_object.on("status", this.statusCallback);
                  // Set the session ID for data synchronization.
                  g_object.setSessionId(this.sessionId);

                  this.contentStorage = new ContentStorage();
                  this.context.restoreWindowStage(this.contentStorage);
              }
          }
      }
   ```



For details about the complete example, see the sample.



