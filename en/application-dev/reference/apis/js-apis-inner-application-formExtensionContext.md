# FormExtensionContext

The FormExtensionContext module, inherited from [ExtensionContext](js-apis-inner-application-extensionContext.md), provides the context environment for the [FormExtensionAbility](js-apis-app-form-formExtensionAbility.md).

You can use the APIs of this module to start a FormExtensionAbility.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import common from '@ohos.app.ability.common';
```

## FormExtensionContext.startAbility

startAbility(want: Want, callback: AsyncCallback&lt;void&gt;): void

Starts an ability. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.Form

**Error codes**

| ID| Error Message|
| -------- | -------- |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500100 | Failed to obtain the configuration information. |
| 16500101 | The application is not a system application. |
| 16501000 | An internal functional error occurred. |

For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Parameters**

| Name|                Type              | Mandatory|              Description              |
| ------| --------------------------------- | ---- | -------------------------------------- |
| want| [Want](js-apis-app-ability-want.md) | Yes | Information about the ability to start, such as the bundle name, ability name, and custom parameters.|
| callback| AsyncCallback&lt;void&gt;       | Yes | Callback used to return the result. If the ability is started, **err** is undefined; otherwise, **err** is an error object.|

**Example**

```ts
import FormExtensionAbility from '@ohos.app.form.FormExtensionAbility';
import Want from '@ohos.app.ability.Want';
import Base from '@ohos.base';

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
    this.context.startAbility(want, (error: Base.BusinessError) => {
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
| want| [Want](js-apis-app-ability-want.md) | Yes | Information about the ability to start, such as the bundle name, ability name, and custom parameters.|

**Return value**

| Type         | Description                               |
| ------------ | ---------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

| ID| Error Message|
| -------- | -------- |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500100 | Failed to obtain the configuration information. |
| 16500101 | The application is not a system application. |
| 16501000 | An internal functional error occurred. |

For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
import FormExtensionAbility from '@ohos.app.form.FormExtensionAbility';
import Want from '@ohos.app.ability.Want';
import Base from '@ohos.base';

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
    }).catch((error: Base.BusinessError) => {
      console.error('StartAbility failed, error.code: ${error.code}, error.message: ${error.message}');
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
| want | [Want](js-apis-app-ability-want.md)  | Yes| Want information about the target ability, such as the ability name and bundle name.|
| options | [ConnectOptions](js-apis-inner-ability-connectOptions.md) | Yes| Callback used to return the information indicating that the connection is successful, interrupted, or failed.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Returns a connect ID, which will be used for the disconnection.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16000011 | The context does not exist.        |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import FormExtensionAbility from '@ohos.app.form.FormExtensionAbility';
import Want from '@ohos.app.ability.Want';
import rpc from '@ohos.rpc';
import Base from '@ohos.base';

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
      onDisconnect(elementName) { console.log('----------- onDisconnect -----------') },
      onFailed(code) { console.error('----------- onFailed -----------') }
    };

    let connection: number | null = null;
    try {
      connection = this.context.connectServiceExtensionAbility(want, options);
    } catch (paramError) {
      // Process input parameter errors.
      console.error(`error.code: ${(paramError as Base.BusinessError).code}, error.message: ${(paramError as Base.BusinessError).message}`);
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
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000011 | The context does not exist.        |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import FormExtensionAbility from '@ohos.app.form.FormExtensionAbility';
import rpc from '@ohos.rpc';
import Base from '@ohos.base';

// commRemote is the remote object returned in the onConnect() callback. The value null is meaningless and is only an example.
let commRemote: rpc.IRemoteObject | null = null;
export default class MyFormExtensionAbility extends FormExtensionAbility {
  onFormEvent(formId: string, message: string) {
    // In actual use, connection is the return value of connectServiceExtensionAbility(). The value 1 is meaningless and is only an example.
    let connection: number = 1;

    try {
      this.context.disconnectServiceExtensionAbility(connection, (error: Base.BusinessError) => {
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
      console.error(`error.code: ${(paramError as Base.BusinessError).code}, error.message: ${(paramError as Base.BusinessError).message}`);
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
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000011 | The context does not exist.        |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import FormExtensionAbility from '@ohos.app.form.FormExtensionAbility';
import rpc from '@ohos.rpc';
import Base from '@ohos.base';

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
        .catch((error: Base.BusinessError) => {
          commRemote = null;
          // Process service logic errors.
          console.error(`disconnectServiceExtensionAbility failed, error.code: ${error.code}, error.message: ${error.message}`);
        });
    } catch (paramError) {
      commRemote = null;
      // Process input parameter errors.
      console.error(`error.code: ${(paramError as Base.BusinessError).code}, error.message: ${(paramError as Base.BusinessError).message}`);
    }
  }
};
```
