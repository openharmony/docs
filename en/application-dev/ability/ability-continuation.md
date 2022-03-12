# Ability Continuation Development

## When to Use

With ability continuation APIs, you can migrate the current application task, including some page data and stack information, to a remote device. If the migration is successful, the local task will be cleared. If the migration fails, the local task can be migrated again.

  

## Available APIs

The following table lists the API used for ability continuation. For details about the API, see the interface document.

**Table 1** Ability continuation API

|API| Description|
|:------ | :------|
| onContinue(wantParams : {[key: string]: any}) | A callback used to store the data required for migration and indicate whether the migration is accepted. The value **true** means that the migration is accepted, and **false** means the opposite.|



## How to Develop

### Migrating an Ability



1. Configure data.

   - Configure the ability to support migration.

   ​    Set the **continuable** field in the **config.json** file to **true**, which indicates that migration is supported. The default value is **false**.

   ```
   "continuable": true
   ```

       Abilities with the **continuable** field set to **false** cannot be migrated.

   * Configure the ability startup type.

   ​    Currently, only multi-instance abilities can be migrated. Therefore, you must set the **launchType** field in the **config.json** file to **standard**.

   ```
   "launchType": "standard"
   ```

   

2. Implement the **onContinue** API.

   Modules to Import

   ```
   import Ability from '@ohos.application.Ability';
   ```

   - To implement migration, you must implement this API and have the value **true** returned.


   - Example

   ```javascript
       onContinue(wantParams : {[key: string]: any}) {
           console.log("MainAbility onContinue")
           return true;
       }
   ```

   

3. Implement the migration logic in the **onCreate** API.

   - On the remote device, determine whether the startup is **LaunchReason.CONTINUATION** (3) based on **launchReason** in **onCreate**.

   
   - After data restore is complete, call **restoreWindowStage** to trigger page restoration.
   

   * Example
   
   ```javascript
       onCreate(want , launchParam) {
           // The ability is being created. Initialize resources for this ability.
           console.log("MainAbility onCreate", launchParam.launchReason);
           if (launchParam.launchReason == LaunchReason.CONTINUATION) {
               this.contentStorage = new ContenStorage();
               this.context.restoreWindowStage(this.contentStorage);
           }
       }
   
   ```
   
   

### Migrating Data

1. Use custom data.

   - You can fill custom data in the key-value format in the **wantParams** parameter, through which the data will be transferred to the remote device. The **key** type is string, and therefore it is used to carry simple and lightweight data.


   ```javascript
       onContinue(wantParams : {[key: string]: any}) {
           console.log("Continue My Data")
           wantParams["myData"] = "my1234567";
           return true;
       }
   ```

   - If the remote device detects a migration, it obtains the custom data saved at the initiator from **want.parameters**.

   ```javascript
       onCreate(want , launchParam) {
           if (launchParam.launchReason == LaunchReason.CONTINUATION) {
               console.log("onCreate LaunchReason = CONTINUATION",want.parameters["myData"]); // my1234567
               ...
               this.context.restoreWindowStage(this.contentStorage);
           }
       }
   
   ```

   

2. Use distributed objects.

   You can use distributed objects to transfer more data to a remote device. For details, see the distributed object interface document.

   - In **onContinue**, the initiator saves the data to be migrated to the distributed object, sets the session ID, and sends the session ID to the remote device through **wantParams**.


   - The remote device obtains the session ID from **onCreate**, creates a distributed object, and associates the distributed object with the session ID. In this way, the distributed object can be synchronized. Before calling **restoreWindowStage**, ensure that all distributed objects required for migration have been associated for correct data retrieval.


   * Example

   ```javascript
   import Ability from '@ohos.application.Ability';
   import distributedObject from '@ohos.data.distributedDataObject';
   
   var g_object = distributedObject.createDistributedObject({name:undefined});
   
   export default class MainAbility extends Ability {
       contentStorage : ContenStorage
       sessionId : string;
       onCreate(want , launchParam) {
           if (launchParam.launchReason == 3) {
               this.sessionId = want.parameters["session"] // Obtain the session ID.
   
               function statusCallback(sessionId, networkid, status) {
                   console.info("object status change sessionId: " + sessionId + " status: " + status +
                   "g_object.name: " + g_object.name); // The synchronized distributed object content "name = Amy" can be obtained from the callback.
               }
               g_object.on("status", statusCallback); // Register a callback to listen for the distributed object synchronization result.
   
               g_object.setSessionId(this.sessionId); // Associate the local distributed object with the session ID of the initiator.
   
               this.contentStorage = new ContenStorage();
               this.context.restoreWindowStage(this.contentStorage);
           }
       }
   
       onContinue(wantParams : {[key: string]: any}) {
           console.log("using distributedObject")
           this.sessionId = "654321";
           g_object.setSessionId(this.sessionId); // Set the session ID of the distributed object.
           g_object.name = "Amy"; // Fill data.
           wantParams["session"] = this.sessionId; // Send the session ID to the remote device through the want object.
           return true;
       }
   ```

   
