# Creating a ServiceAbility


1. Create a ServiceAbility.

   Override the ServiceAbility lifecycle callbacks to implement your own logic for processing interaction requests.

   ```ts
   import type Want from '@ohos.app.ability.Want';
   import rpc from '@ohos.rpc';
   import hilog from '@ohos.hilog';
   
   const TAG: string = '[Sample_FAModelAbilityDevelop]';
   const domain: number = 0xFF00;
   
   class FirstServiceAbilityStub extends rpc.RemoteObject {
     constructor(des: Object) {
       if (typeof des === 'string') {
         super(des);
       } else {
         return;
       }
     }
   
     onRemoteRequest(code: number, data: rpc.MessageParcel, reply: rpc.MessageParcel, option: rpc.MessageOption): boolean {
       hilog.info(domain, TAG, 'ServiceAbility onRemoteRequest called');
       if (code === 1) {
         let string = data.readString();
         hilog.info(domain, TAG, `ServiceAbility string=${string}`);
         let result = Array.from(string).sort().join('');
         hilog.info(domain, TAG, `ServiceAbility result=${result}`);
         reply.writeString(result);
       } else {
         hilog.info(domain, TAG, 'ServiceAbility unknown request code');
       }
       return true;
     }
   }
   
   class ServiceAbility {
     onStart(): void {
       hilog.info(domain, TAG, 'ServiceAbility onStart');
     }
   
     onStop(): void {
       hilog.info(domain, TAG, 'ServiceAbility onStop');
     }
   
     onCommand(want: Want, startId: number): void {
       hilog.info(domain, TAG, 'ServiceAbility onCommand');
     }
   
     onConnect(want: Want): rpc.RemoteObject {
       hilog.info(domain, TAG, 'ServiceAbility onDisconnect' + want);
       return new FirstServiceAbilityStub('test');
     }
   
     onDisconnect(want: Want): void {
       hilog.info(domain, TAG, 'ServiceAbility onDisconnect' + want);
     }
   }
   
   export default new ServiceAbility();
   ```

2. Register the ServiceAbility.
   
    Declare the ServiceAbility in the **config.json** file by setting its **type** attribute to **service**. The **visible** attribute specifies whether the ServiceAbility can be called by other applications. The value **true** means that the ServiceAbility can be called by other applications, and **false** means that the ServiceAbility can be called only within the application. To enable the ServiceAbility to be called by other applications, set **visible** to **true** when registering the ServiceAbility and enable associated startup. For details about the startup rules, see [Component Startup Rules](component-startup-rules.md).
    
    ```json
    {
      ...
      "module": {
        ...
        "abilities": [
          ...
          {
            "name": ".ServiceAbility",
            "srcLanguage": "ets",
            "srcPath": "ServiceAbility",
            "icon": "$media:icon",
            "description": "$string:ServiceAbility_desc",
            "type": "service",
            "visible": true
          },
          ...
        ]
        ...
      }
    }
    ```
