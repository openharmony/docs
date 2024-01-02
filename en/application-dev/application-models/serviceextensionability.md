# ServiceExtensionAbility

## Overview

[ServiceExtensionAbility](../reference/apis/js-apis-app-ability-serviceExtensionAbility.md) is an ExtensionAbility component of the service type that provides capabilities related to background services. It holds an internal [ServiceExtensionContext](../reference/apis/js-apis-inner-application-serviceExtensionContext.md), which provides a variety of APIs for external systems.

In this document, the started ServiceExtensionAbility is called the server, and the component that starts the ServiceExtensionAbility is called the client.

A ServiceExtensionAbility can be started or connected by other components to process transactions in the background based on the request of the caller. System applications can call the [startServiceExtensionAbility()](../reference/apis/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartserviceextensionability) method to start a ServiceExtensionAbility or call the [connectServiceExtensionAbility()](../reference/apis/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextconnectserviceextensionability) method to connect to a ServiceExtensionAbility. Third-party applications can call only [connectServiceExtensionAbility()](../reference/apis/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextconnectserviceextensionability) to connect to a ServiceExtensionAbility. The differences between starting and connecting to a ServiceExtensionAbility are as follows:

- **Starting**: In the case that AbilityA starts ServiceB, they are weakly associated. After AbilityA exits, ServiceB remains running.

- **Connecting**: In the case that AbilityA connects to ServiceB, they are strongly associated. After AbilityA exits, ServiceB also exits.

Note the following:

- If a ServiceExtensionAbility is started only by means of connecting, its lifecycle is controlled by the client. A new connection is set up each time the client calls the [connectServiceExtensionAbility()](../reference/apis/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextconnectserviceextensionability) method. When the client exits or calls the [disconnectServiceExtensionAbility()](../reference/apis/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextdisconnectserviceextensionability) method, the connection is interrupted. After all connections are interrupted, the ServiceExtensionAbility automatically exits.

- Once a ServiceExtensionAbility is started by means of starting, it will not exit automatically. System applications can call the [stopServiceExtensionAbility()](../reference/apis/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstopserviceextensionability) method to stop it.

- The connection or disconnection operation can be performed only in the main thread, but not in the **Worker** and **TaskPool** threads.

> **NOTE**
>
> Currently, third-party applications cannot implement a ServiceExtensionAbility. To implement transaction processing in the background, they can use [background tasks](../task-management/background-task-overview.md).
>
> A UIAbility of a third-party application can connect to a ServiceExtensionAbility provided by a system application through the context.
>
> Third-party applications can connect to a ServiceExtensionAbility provided by a system application only when they gain focus in the foreground.

## Lifecycle

The [ServiceExtensionAbility](../reference/apis/js-apis-app-ability-serviceExtensionAbility.md) class provides the lifecycle callbacks **onCreate()**, **onRequest()**, **onConnect()**, **onDisconnect()**, and **onDestroy()**. Override them as required. The following figure shows the ServiceExtensionAbility lifecycle.

**Figure 1** ServiceExtensionAbility lifecycle

![ServiceExtensionAbility-lifecycle](figures/ServiceExtensionAbility-lifecycle.png)

- **onCreate**

  This callback is triggered when a ServiceExtensionAbility is created for the first time. You can perform initialization operations, for example, registering a common event listener.

  > **NOTE**
  >
  > If a ServiceExtensionAbility has been created, starting it again does not trigger the **onCreate()** callback.

- **onRequest**

  This callback is triggered when another component calls the [startServiceExtensionAbility()](../reference/apis/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartserviceextensionability) method to start a ServiceExtensionAbility. After being started, the ServiceExtensionAbility runs in the background. This callback is triggered each time the [startServiceExtensionAbility()](../reference/apis/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartserviceextensionability) method is called.

- **onConnect**

  This callback is triggered when another component calls the [connectServiceExtensionAbility()](../reference/apis/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextconnectserviceextensionability) method to connect to a ServiceExtensionAbility. In this method, a remote proxy object, namely, IRemoteObject, is returned, through which the client communicates with the server by means of RPC. At the same time, the system stores the IRemoteObject. If another component calls the [connectServiceExtensionAbility()](../reference/apis/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextconnectserviceextensionability) method to connect to this ServiceExtensionAbility, the system returns the saved IRemoteObject, without triggering the callback.

- **onDisconnect**

  This callback is triggered when the last connection is interrupted. A connection is interrupted when the client exits or the [disconnectServiceExtensionAbility()](../reference/apis/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextdisconnectserviceextensionability) method is called.

- **onDestroy**

  This callback is triggered when a ServiceExtensionAbility is no longer used and the instance is ready for destruction. You can clear resources in this callback, for example, deregistering the listener.

## Implementing a Background Service (for System Applications Only)

### Preparations

Only system applications can implement a ServiceExtensionAbility. You must make the following preparations before development:

- **Switching to the full SDK**: All the APIs provided by the **ServiceExtensionAbility** class are marked as system APIs and hidden by default. Therefore, you must manually obtain the full SDK from the mirror and switch to it in DevEco Studio. For details, see [Guide to Switching to Full SDK](../faqs/full-sdk-switch-guide.md).

- **Requesting the AllowAppUsePrivilegeExtension privilege**: Only applications with the **AllowAppUsePrivilegeExtension** privilege can implement a ServiceExtensionAbility. For details about how to request the privilege, see [Application Privilege Configuration Guide](../../device-dev/subsystems/subsys-app-privilege-config-guide.md).

### Defining IDL APIs

As a background service, a ServiceExtensionAbility needs to provide APIs that can be called by external systems. You can define the APIs in IDL files and use the [IDL tool](../IDL/idl-guidelines.md) to generate proxy and stub files. The following demonstrates how to define a file named **IIdlServiceExt.idl**:

```cpp
interface OHOS.IIdlServiceExt {
  int ProcessData([in] int data);
  void InsertDataToMap([in] String key, [in] int val);
}
```

Create the **IdlServiceExt** directory in the **ets** directory of a module in a DevEco Studio project, and copy the files generated by the [IDL tool](../IDL/idl-guidelines.md) to this directory. Then create a file named **idl_service_ext_impl.ts** to implement the IDL APIs.

```
├── ets
│ ├── IdlServiceExt
│ │   ├── i_idl_service_ext.ts      # File generated by the IDL tool.
│ │   ├── idl_service_ext_proxy.ts  # File generated by the IDL tool.
│ │   ├── idl_service_ext_stub.ts   # File generated by the IDL tool.
│ │   ├── idl_service_ext_impl.ts   # Customize this file to implement IDL APIs.
│ └
└
```

An example of **idl_service_ext_impl.ts** is as follows:

```ts
import {processDataCallback} from './i_idl_service_ext';
import {insertDataToMapCallback} from './i_idl_service_ext';
import IdlServiceExtStub from './idl_service_ext_stub';

const ERR_OK = 0;
const TAG: string = "[IdlServiceExtImpl]";

// You need to implement APIs in this type.
export default class ServiceExtImpl extends IdlServiceExtStub {
  processData(data: number, callback: processDataCallback): void {
    // Implement service logic.
    console.info(TAG, `processData: ${data}`);
    callback(ERR_OK, data + 1);
  }

  insertDataToMap(key: string, val: number, callback: insertDataToMapCallback): void {
    // Implement service logic.
    console.info(TAG, `insertDataToMap, key: ${key}  val: ${val}`);
    callback(ERR_OK);
  }
}
```

### Creating a ServiceExtensionAbility

To manually create a ServiceExtensionAbility in the DevEco Studio project, perform the following steps:

1. In the **ets** directory of a module in the project, right-click and choose **New > Directory** to create a directory named **ServiceExtAbility**.

2. In the **ServiceExtAbility** directory, right-click and choose **New > TypeScript File** to create a file named **ServiceExtAbility.ets**.

    ```
    ├── ets
    │ ├── IdlServiceExt
    │ │   ├── i_idl_service_ext.ets      # File generated by the IDL tool.
    │ │   ├── idl_service_ext_proxy.ets  # File generated by the IDL tool.
    │ │   ├── idl_service_ext_stub.ets   # File generated by the IDL tool.
    │ │   ├── idl_service_ext_impl.ets   # Customize this file to implement IDL APIs.
    │ ├── ServiceExtAbility
    │ │   ├── ServiceExtAbility.ets
    └
    ```

3. In the **ServiceExtAbility.ets** file, import the ServiceExtensionAbility module. Customize a class that inherits from **ServiceExtensionAbility** and implement the lifecycle callbacks. Return the previously defined **ServiceExtImpl** object in the **onConnect** lifecycle callback.

   ```ts
   import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';
   import ServiceExtImpl from '../IdlServiceExt/idl_service_ext_impl';
   import Want from '@ohos.app.ability.Want';
   import rpc from '@ohos.rpc';
   
   const TAG: string = "[ServiceExtAbility]";
   
   export default class ServiceExtAbility extends ServiceExtensionAbility {
     serviceExtImpl: ServiceExtImpl = new ServiceExtImpl("ExtImpl");

     onCreate(want: Want) {
       console.info(TAG, `onCreate, want: ${want.abilityName}`);
     }
   
     onRequest(want: Want, startId: number) {
       console.info(TAG, `onRequest, want: ${want.abilityName}`);
     }
   
     onConnect(want: Want) {
       console.info(TAG, `onConnect, want: ${want.abilityName}`);
       // Return the ServiceExtImpl object, through which the client can communicate with the ServiceExtensionAbility.
       return this.serviceExtImpl as rpc.RemoteObject;
     }
   
     onDisconnect(want: Want) {
       console.info(TAG, `onDisconnect, want: ${want.abilityName}`);
     }
   
     onDestroy() {
       console.info(TAG, `onDestroy`);
     }
   }
   ```

4. Register the ServiceExtensionAbility in the [module.json5 file](../quick-start/module-configuration-file.md) of the module in the project. Set **type** to **"service"** and **srcEntry** to the code path of the ServiceExtensionAbility component.

   ```json
   {
     "module": {
       ...
       "extensionAbilities": [
         {
           "name": "ServiceExtAbility",
           "icon": "$media:icon",
           "description": "service",
           "type": "service",
           "exported": true,
           "srcEntry": "./ets/ServiceExtAbility/ServiceExtAbility.ts"
         }
       ]
     }
   }
   ```

## Starting a Background Service (for System Applications Only)

A system application uses the [startServiceExtensionAbility()](../reference/apis/js-apis-inner-application-uiAbilityContext.md#abilitycontextstartserviceextensionability) method to start a background service. The [onRequest()](../reference/apis/js-apis-app-ability-serviceExtensionAbility.md#serviceextensionabilityonrequest) callback is invoked, through which the background service receives the **Want** object passed by the caller. After the background service is started, its lifecycle is independent of that of the client. In other words, even if the client is destroyed, the background service remains alive. Therefore, the background service must be stopped by calling [terminateSelf()](../reference/apis/js-apis-inner-application-serviceExtensionContext.md#serviceextensioncontextterminateself) when its work is complete. Alternatively, another component can call [stopServiceExtensionAbility()](../reference/apis/js-apis-inner-application-uiAbilityContext.md#abilitycontextstopserviceextensionability) to stop the background service.

> **NOTE**
>
> [startServiceExtensionAbility()](../reference/apis/js-apis-inner-application-uiAbilityContext.md#abilitycontextstartserviceextensionability), [stopServiceExtensionAbility()](../reference/apis/js-apis-inner-application-uiAbilityContext.md#abilitycontextstopserviceextensionability), and [terminateSelf()](../reference/apis/js-apis-inner-application-serviceExtensionContext.md#serviceextensioncontextterminateself) provided by the **ServiceExtensionContext** class are system APIs and cannot be called by third-party applications.

1. Start a new ServiceExtensionAbility in a system application. For details about how to obtain the context, see [Obtaining the Context of UIAbility](uiability-usage.md#obtaining-the-context-of-uiability).

   ```ts
   import common from '@ohos.app.ability.common';
   import Want from '@ohos.app.ability.Want';
   import { BusinessError } from '@ohos.base';

   let context: common.UIAbilityContext = ...; // UIAbilityContext
   let want: Want = {
     deviceId: "",
     bundleName: "com.example.myapplication",
     abilityName: "ServiceExtAbility"
   };
   context.startServiceExtensionAbility(want).then(() => {
     console.info('Succeeded in starting ServiceExtensionAbility.');
   }).catch((err: BusinessError) => {
     console.error(`Failed to start ServiceExtensionAbility. Code is ${err.code}, message is ${err.message}`);
   })
   ```

2. Stop the ServiceExtensionAbility in the system application.

   ```ts
   import common from '@ohos.app.ability.common';
   import Want from '@ohos.app.ability.Want';
   import { BusinessError } from '@ohos.base';

   let context: common.UIAbilityContext = ...; // UIAbilityContext
   let want: Want = {
     deviceId: "",
     bundleName: "com.example.myapplication",
     abilityName: "ServiceExtAbility"
   };
   context.stopServiceExtensionAbility(want).then(() => {
     console.info('Succeeded in stopping ServiceExtensionAbility.');
   }).catch((err: BusinessError) => {
     console.error(`Failed to stop ServiceExtensionAbility. Code is ${err.code}, message is ${err.message}`);
   })
   ```

3. Enable the ServiceExtensionAbility to stop itself.

   ```ts
   import common from '@ohos.app.ability.common';
   import { BusinessError } from '@ohos.base';

   let context: common.ServiceExtensionContext = ...; // ServiceExtensionContext
   context.terminateSelf().then(() => {
     console.info('Succeeded in terminating self.');
   }).catch((err: BusinessError) => {
     console.error(`Failed to terminate self. Code is ${err.code}, message is ${err.message}`);
   })
   ```

> **NOTE**
>
> Background services remain alive in the background for a long time. To minimize resource usage, destroy a background service in time in either of the following ways when it finishes the requested task:
>
> - The background service calls the [terminateSelf()](../reference/apis/js-apis-inner-application-serviceExtensionContext.md#serviceextensioncontextterminateself) method to automatically stop itself.
> - Another component calls the [stopServiceExtensionAbility()](../reference/apis/js-apis-inner-application-uiAbilityContext.md#abilitycontextstopserviceextensionability) method to stop the background service.

## Connecting to a Background Service

Either a system application or a third-party application can connect to a background service (specified in the **Want** object) through [connectServiceExtensionAbility()](../reference/apis/js-apis-inner-application-uiAbilityContext.md#abilitycontextconnectserviceextensionability). The [onConnect()](../reference/apis/js-apis-app-ability-serviceExtensionAbility.md#serviceextensionabilityonconnect) callback is invoked, through which the background service receives the **Want** object passed by the caller. In this way, a persistent connection is established.

The ServiceExtensionAbility returns an IRemoteObject in the **onConnect()** callback. Through this IRemoteObject, you can define communication interfaces for RPC interaction between the client and server. Multiple clients can simultaneously connect to the same background service. After a client finishes the interaction, it must call [disconnectServiceExtensionAbility()](../reference/apis/js-apis-inner-application-uiAbilityContext.md#abilitycontextdisconnectserviceextensionability) to disconnect from the service. If all clients connected to a background service are disconnected, the system destroys the service.

- Call **connectServiceExtensionAbility()** to establish a connection to a background service. For details about how to obtain the context, see [Obtaining the Context of UIAbility](uiability-usage.md#obtaining-the-context-of-uiability).
  
  ```ts
  import common from '@ohos.app.ability.common';
  import Want from '@ohos.app.ability.Want';

  let want: Want = {
    deviceId: "",
    bundleName: "com.example.myapplication",
    abilityName: "ServiceExtAbility"
  };
  let options: common.ConnectOptions = {
    onConnect(elementName, remote) {
      /* remote is the object returned by the ServiceExtensionAbility in the onConnect lifecycle callback.
       * This object is used for communication with the ServiceExtensionAbility. For details, see the section below.
       */
      console.info('onConnect callback');
      if (remote === null) {
        console.info(`onConnect remote is null`);
        return;
      }
    },
    onDisconnect(elementName) {
      console.info('onDisconnect callback')
    },
    onFailed(code) {
      console.info('onFailed callback')
    }
  }
  // The ID returned after the connection is set up must be saved. The ID will be used for disconnection.
  let connectionId: number = this.context.connectServiceExtensionAbility(want, options);
  ```

- Use **disconnectServiceExtensionAbility()** to disconnect from the background service.
  
  ```ts
  import { BusinessError } from '@ohos.base';
  // connectionId is returned when connectServiceExtensionAbility is called and needs to be manually maintained.
  this.context.disconnectServiceExtensionAbility(connectionId).then(() => {
    console.info('disconnectServiceExtensionAbility success');
  }).catch((error: BusinessError) => {
    console.error('disconnectServiceExtensionAbility failed');
  })
  ```

## Communication Between the Client and Server

After obtaining the [rpc.RemoteObject](../reference/apis/js-apis-rpc.md#iremoteobject) from the **onConnect()** lifecycle callback, the client can communicate with the ServiceExtensionAbility in either of the following ways:

- Using the IDL APIs provided by the server for communication (recommended)

  ```ts
  // The client needs to import idl_service_ext_proxy.ts provided by the server to the local project.
  import IdlServiceExtProxy from '../IdlServiceExt/idl_service_ext_proxy';
  import common from '@ohos.app.ability.common';

  let options: common.ConnectOptions = {
    onConnect(elementName, remote) {
      console.info('onConnect callback');
      if (remote === null) {
        console.info(`onConnect remote is null`);
        return;
      }
      let serviceExtProxy: IdlServiceExtProxy = new IdlServiceExtProxy(remote);
      // Communication is carried out by API calling, without exposing RPC details.
      serviceExtProxy.processData(1, (errorCode: number, retVal: number) => {
        console.info(`processData, errorCode: ${errorCode}, retVal: ${retVal}`);
      });
      serviceExtProxy.insertDataToMap('theKey', 1, (errorCode: number) => {
        console.info(`insertDataToMap, errorCode: ${errorCode}`);
      })
    },
    onDisconnect(elementName) {
      console.info('onDisconnect callback')
    },
    onFailed(code) {
      console.info('onFailed callback')
    }
  }
  ```

- Calling [sendMessageRequest](../reference/apis/js-apis-rpc.md#sendmessagerequest9) to send messages to the server (not recommended)

  ```ts
  import rpc from '@ohos.rpc';
  import common from '@ohos.app.ability.common';
  import { BusinessError } from '@ohos.base';

  const REQUEST_CODE = 1;
  let options: common.ConnectOptions = {
    onConnect(elementName, remote) {
      console.info('onConnect callback');
      if (remote === null) {
        console.info(`onConnect remote is null`);
        return;
      }
      /* Directly call the RPC interface to send messages to the server.
       * The client needs to serialize the input parameters and deserialize the return values. The process is complex.
       */ 
      let option = new rpc.MessageOption();
      let data = new rpc.MessageSequence();
      let reply = new rpc.MessageSequence();
      data.writeInt(100);
  
      // @param code Indicates the service request code sent by the client.
      // @param data Indicates the {@link MessageSequence} object sent by the client.
      // @param reply Indicates the response message object sent by the remote service.
      // @param options Specifies whether the operation is synchronous or asynchronous.
      // 
      // @return Returns {@code true} if the operation is successful; returns {@code false} otherwise.
      remote.sendMessageRequest(REQUEST_CODE, data, reply, option).then((ret) => {
        let msg = reply.readInt();
        console.info(`sendMessageRequest ret:${ret} msg:${msg}`);
      }).catch((error: BusinessError) => {
        console.info('sendMessageRequest failed');
      });
    },
    onDisconnect(elementName) {
      console.info('onDisconnect callback')
    },
    onFailed(code) {
      console.info('onFailed callback')
    }
  }
  ```

## Client Identity Verification by the Server

When a ServiceExtensionAbility is used to provide sensitive services, the client identity must be verified. You can implement the verification on the IDL stub. For details about the IDL API implementation, see [Defining IDL APIs](#defining-idl-apis). Two verification modes are recommended:

- **Verifying the client identity based on callerUid**

  Call the [getCallingUid()](../reference/apis/js-apis-rpc.md#getcallinguid) method to obtain the UID of the client, and then call the [getBundleNameByUid()](../reference/apis/js-apis-bundleManager.md#bundlemanagergetbundlenamebyuid) method to obtain the corresponding bundle name. In this way, the client identity is verified. Note that [getBundleNameByUid()](../reference/apis/js-apis-bundleManager.md#bundlemanagergetbundlenamebyuid) is asynchronous, and therefore the server cannot return the verification result to the client. This verification mode applies when the client sends an asynchronous task request to the server. The sample code is as follows:

  ```ts
  import rpc from '@ohos.rpc';
  import { BusinessError } from '@ohos.base';
  import bundleManager from '@ohos.bundle.bundleManager';
  import { processDataCallback } from './i_idl_service_ext';
  import { insertDataToMapCallback } from './i_idl_service_ext';
  import IdlServiceExtStub from './idl_service_ext_stub';

  const ERR_OK = 0;
  const ERR_DENY = -1;
  const TAG: string = "[IdlServiceExtImpl]";

  export default class ServiceExtImpl extends IdlServiceExtStub {
    processData(data: number, callback: processDataCallback): void {
      console.info(TAG, `processData: ${data}`);

      let callerUid = rpc.IPCSkeleton.getCallingUid();
      bundleManager.getBundleNameByUid(callerUid).then((callerBundleName) => {
        console.info(TAG, 'getBundleNameByUid: ' + callerBundleName);
        // Identify the bundle name of the client.
        if (callerBundleName != 'com.example.connectextapp') { // The verification fails.
          console.info(TAG, 'The caller bundle is not in trustlist, reject');
          return;
        }
        // The verification is successful, and service logic is executed normally.
      }).catch((err: BusinessError) => {
        console.info(TAG, 'getBundleNameByUid failed: ' + err.message);
      });
    }

    insertDataToMap(key: string, val: number, callback: insertDataToMapCallback): void {
      // Implement service logic.
      console.info(TAG, `insertDataToMap, key: ${key}  val: ${val}`);
      callback(ERR_OK);
    }
  }
  ```

- **Verifying the client identity based on callerTokenId**

  Call the [getCallingTokenId()](../reference/apis/js-apis-rpc.md#getcallingtokenid) method to obtain the token ID of the client, and then call the [verifyAccessTokenSync()](../reference/apis/js-apis-abilityAccessCtrl.md#verifyaccesstokensync) method to check whether the client has the required permission. Currently, the system does not support permission customization. Therefore, only [system-defined permissions](../security/permission-list.md) can be verified. The sample code is as follows:

  ```ts
  import rpc from '@ohos.rpc';
  import abilityAccessCtrl from '@ohos.abilityAccessCtrl';
  import {processDataCallback} from './i_idl_service_ext';
  import {insertDataToMapCallback} from './i_idl_service_ext';
  import IdlServiceExtStub from './idl_service_ext_stub';
  
  const ERR_OK = 0;
  const ERR_DENY = -1;
  const TAG: string = "[IdlServiceExtImpl]";
  
  export default class ServiceExtImpl extends IdlServiceExtStub {
    processData(data: number, callback: processDataCallback): void {
      console.info(TAG, `processData: ${data}`);
  
      let callerTokenId = rpc.IPCSkeleton.getCallingTokenId();
      let accessManger = abilityAccessCtrl.createAtManager();
      /* The permission to be verified varies depending on the service requirements.
       * ohos.permission.SET_WALLPAPER is only an example.
       */
      let grantStatus =
          accessManger.verifyAccessTokenSync(callerTokenId, "ohos.permission.SET_WALLPAPER");
      if (grantStatus === abilityAccessCtrl.GrantStatus.PERMISSION_DENIED) {
          console.info(TAG, `PERMISSION_DENIED`);
          callback(ERR_DENY, data);   // The verification fails and an error is returned.
          return;
      }
      callback(ERR_OK, data + 1);     // The verification is successful, and service logic is executed normally.
    }
  
    insertDataToMap(key: string, val: number, callback: insertDataToMapCallback): void {
      // Implement service logic.
      console.info(TAG, `insertDataToMap, key: ${key}  val: ${val}`);
      callback(ERR_OK);
    }
  }
  ```
