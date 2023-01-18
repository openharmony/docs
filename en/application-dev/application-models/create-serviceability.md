# Creating a ServiceAbility


1. Create a ServiceAbility.

     Override the ServiceAbility lifecycle callbacks to implement your own logic for processing interaction requests.

   ```ts
     import rpc from "@ohos.rpc"
     
     class FirstServiceAbilityStub extends rpc.RemoteObject {
       constructor(des: any) {
         if (typeof des === 'string') {
           super(des)
         } else {
           return
         }
       }
     }
     
     export default {
       onStart() {
         console.info('ServiceAbility onStart')
       },
       onStop() {
         console.info('ServiceAbility onStop')
       },
       onCommand(want, startId) {
         console.info('ServiceAbility onCommand')
       },
       onConnect(want) {
         console.info('ServiceAbility onConnect' + want)
         return new FirstServiceAbilityStub('test')
       },
       onDisconnect(want) {
         console.info('ServiceAbility onDisconnect' + want)
       }
     }
   ```

2. Register the ServiceAbility.
   
    Declare the ServiceAbility in the **config.json** file by setting its **type** attribute to **service**. The **visible** attribute specifies whether the ServiceAbility can be called by other applications. The value **true** means that the ServiceAbility can be called by other applications, and **false** means that the ServiceAbility can be called only within the application. To enable the ServiceAbility to be called by other applications, set **visible** to **true** when registering the ServiceAbility and enable associated startup. For details about the startup rules, see [Component Startup Rules](component-startup-rules.md).
    
    ```json
         {
           "module": {
             "abilities": [
               {
                 "name": ".ServiceAbility",
                 "srcLanguage": "ets",
                 "srcPath": "ServiceAbility",
                 "icon": "$media:icon",
                 "description": "hap sample empty service",
                 "type": "service",
                 "visible": true
               }
             ]
           }
         }
    ```
