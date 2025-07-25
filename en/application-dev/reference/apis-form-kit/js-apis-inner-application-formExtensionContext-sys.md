# FormExtensionContext (System API)

The **FormExtensionContext** module, inherited from [ExtensionContext](../apis-ability-kit/js-apis-inner-application-extensionContext.md), provides the context environment for the [FormExtensionAbility](js-apis-app-form-formExtensionAbility.md).

You can use the APIs of this module to start a FormExtensionAbility.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs of this module can be used only in the stage model.
> The APIs provided by this module are system APIs.



## Modules to Import

```ts
import { common } from '@kit.AbilityKit';
```

## FormExtensionContext.startAbility

startAbility(want: Want, callback: AsyncCallback&lt;void&gt;): void

Starts an ability. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.Form

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Form Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

**Parameters**

| Name|                Type              | Mandatory|              Description              |
| ------| --------------------------------- | ---- | -------------------------------------- |
| want| [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes | Information about the ability to start, such as the bundle name, ability name, and custom parameters.|
| callback| AsyncCallback&lt;void&gt;       | Yes | Callback used to return the result. If the ability is started, **err** is undefined; otherwise, **err** is an error object.|

**Example**

```ts
import { FormExtensionAbility } from '@kit.FormKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class MyFormExtensionAbility extends FormExtensionAbility {
  onFormEvent(formId: string, message: string) {
    // Call startAbility() when the message event is triggered.
    console.log(`FormExtensionAbility onFormEvent, formId: ${formId}, message:${message}`);
    let want: Want = {
      deviceId: '',
      bundleName: 'com.example.formstartability',
      abilityName: 'EntryAbility',
      parameters: {
        'message': message
      }
    };
    this.context.startAbility(want, (error: BusinessError) => {
      if (error) {
        console.error(`FormExtensionContext startAbility, error:${JSON.stringify(error)}`);
      } else {
        console.log('FormExtensionContext startAbility success');
      }
    });
  }
};
```

## FormExtensionContext.startAbility

startAbility(want: Want): Promise&lt;void&gt;

Starts an ability. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name|                Type              | Mandatory|              Description              |
| ------| --------------------------------- | ---- | -------------------------------------- |
| want| [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes | Information about the ability to start, such as the bundle name, ability name, and custom parameters.|

**Return value**

| Type         | Description                               |
| ------------ | ---------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Form Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

**Example**

```ts
import { FormExtensionAbility } from '@kit.FormKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class MyFormExtensionAbility extends FormExtensionAbility {
  onFormEvent(formId: string, message: string) {
    // Call startAbility() when the message event is triggered.
    console.log(`FormExtensionAbility onFormEvent, formId:${formId}, message:${message}`);
    let want: Want = {
      deviceId: '',
      bundleName: 'com.example.formstartability',
      abilityName: 'EntryAbility',
      parameters: {
        'message': message
      }
    };
    this.context.startAbility(want).then(() => {
      console.info('StartAbility Success');
    }).catch((error: BusinessError) => {
      console.error(`StartAbility failed, error.code: ${error.code}, error.message: ${error.message}`);
    });
  }
};
```

## FormExtensionContext.connectServiceExtensionAbility<sup>10+</sup>

connectServiceExtensionAbility(want: Want, options: ConnectOptions): number

Connects this ability to a ServiceExtensionAbility.

**System capability**: SystemCapability.Ability.Form

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](../apis-ability-kit/js-apis-app-ability-want.md)  | Yes| Want information about the target ability, such as the ability name and bundle name.|
| options | [ConnectOptions](../apis-ability-kit/js-apis-inner-ability-connectOptions.md) | Yes| Callback used to return the information indicating that the connection is successful, interrupted, or failed.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Returns a connect ID, which will be used for the disconnection.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](../apis-ability-kit/errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201      | Permissions denied.             |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Cannot start an invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16000011 | The context does not exist.        |
| 16000050 | Internal error. |

**Example**

```ts
import { rpc } from '@kit.IPCKit';
import { FormExtensionAbility } from '@kit.FormKit';
import { common, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let commRemote: rpc.IRemoteObject | null = null;

export default class MyFormExtensionAbility extends FormExtensionAbility {
  onFormEvent(formId: string, message: string) {
    // Call connectServiceExtensionAbility() when the message event is triggered.
    console.log(`FormExtensionAbility onFormEvent, formId:${formId}, message:${message}`);
    let want: Want = {
      deviceId: '',
      bundleName: 'com.example.formstartability',
      abilityName: 'EntryAbility',
      parameters: {
        'message': message
      }
    };
    let options: common.ConnectOptions = {
      onConnect(elementName, remote) {
        commRemote = remote; // remote is used to communicate with the ServiceExtensionAbility.
        console.log('----------- onConnect -----------');
      },
      onDisconnect(elementName) {
        console.log('----------- onDisconnect -----------')
      },
      onFailed(code) {
        console.error('----------- onFailed -----------')
      }
    };

    let connection: number | null = null;
    try {
      connection = this.context.connectServiceExtensionAbility(want, options);
    } catch (paramError) {
      // Process input parameter errors.
      console.error(`error.code: ${(paramError as BusinessError).code}, error.message: ${(paramError as BusinessError).message}`);
    }
  }
};
```

## FormExtensionContext.disconnectServiceExtensionAbility<sup>10+</sup>

disconnectServiceExtensionAbility(connection: number, callback: AsyncCallback&lt;void&gt;): void

Disconnects this ability from a ServiceExtensionAbility and after the successful disconnection, sets the remote object returned upon the connection to void. This API uses an asynchronous callback to return the result. 

**System capability**: SystemCapability.Ability.Form

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| connection | number | Yes| Number returned after [connectServiceExtensionAbility](#formextensioncontextconnectserviceextensionability10) is called.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the ability is disconnected, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](../apis-ability-kit/errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16000011 | The context does not exist.        |
| 16000050 | Internal error. |

**Example**

```ts
import { FormExtensionAbility } from '@kit.FormKit';
import { rpc } from '@kit.IPCKit';
import { BusinessError } from '@kit.BasicServicesKit';

// commRemote is the remote object returned in the onConnect() callback. The value null is meaningless and is only an example.
let commRemote: rpc.IRemoteObject | null = null;
export default class MyFormExtensionAbility extends FormExtensionAbility {
  onFormEvent(formId: string, message: string) {
    // In actual use, connection is the return value of connectServiceExtensionAbility(). The value 1 is meaningless and is only an example.
    let connection: number = 1;

    try {
      this.context.disconnectServiceExtensionAbility(connection, (error: BusinessError) => {
        commRemote = null;
        if (error.code) {
          // Process service logic errors.
          console.error(`disconnectServiceExtensionAbility failed, error.code: ${error.code}, error.message: ${error.message}`);
          return;
        }
        // Carry out normal service processing.
        console.log('disconnectServiceExtensionAbility succeed');
      });
    } catch (paramError) {
      commRemote = null;
      // Process input parameter errors.
      console.error(`error.code: ${(paramError as BusinessError).code}, error.message: ${(paramError as BusinessError).message}`);
    }
  }
};
```

## FormExtensionContext.disconnectServiceExtensionAbility<sup>10+</sup>

disconnectServiceExtensionAbility(connection: number): Promise&lt;void&gt;

Disconnects this ability from a ServiceExtensionAbility and after the successful disconnection, sets the remote object returned upon the connection to void. This API uses a promise to return the result. 

**System capability**: SystemCapability.Ability.Form

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| connection | number | Yes| Number returned after [connectServiceExtensionAbility](#formextensioncontextconnectserviceextensionability10) is called.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](../apis-ability-kit/errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16000011 | The context does not exist.        |
| 16000050 | Internal error. |

**Example**

```ts
import { FormExtensionAbility } from '@kit.FormKit';
import { rpc } from '@kit.IPCKit';
import { BusinessError } from '@kit.BasicServicesKit';

// commRemote is the remote object returned in the onConnect() callback. The value null is meaningless and is only an example.
let commRemote: rpc.IRemoteObject | null = null;
export default class MyFormExtensionAbility extends FormExtensionAbility {
  onFormEvent(formId: string, message: string) {
    // In actual use, connection is the return value of connectServiceExtensionAbility(). The value 1 is meaningless and is only an example.
    let connection: number = 1;

    try {
      this.context.disconnectServiceExtensionAbility(connection)
        .then(() => {
          commRemote = null;
          // Carry out normal service processing.
          console.log('disconnectServiceExtensionAbility succeed');
        })
        .catch((error: BusinessError) => {
          commRemote = null;
          // Process service logic errors.
          console.error(`disconnectServiceExtensionAbility failed, error.code: ${error.code}, error.message: ${error.message}`);
        });
    } catch (paramError) {
      commRemote = null;
      // Process input parameter errors.
      console.error(`error.code: ${(paramError as BusinessError).code}, error.message: ${(paramError as BusinessError).message}`);
    }
  }
};
```
