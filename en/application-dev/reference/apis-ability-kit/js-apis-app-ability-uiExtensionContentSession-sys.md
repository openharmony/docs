# @ohos.app.ability.UIExtensionContentSession (UI Operation Class for ExtensionAbilities with UI) (System API)

UIExtensionContentSession is an instance created when the [UIExtensionAbility](js-apis-app-ability-uiExtensionAbility.md) loads UI content. When the UIExtensionComponent starts a UIExtensionAbility, the UIExtensionAbility creates a UIExtensionContentSession instance and returns it through the [onSessionCreate](js-apis-app-ability-uiExtensionAbility.md#onsessioncreate) callback. One UIExtensionComponent corresponds to one UIExtensionContentSession instance, which provides methods such as UI loading and result notification. The UIExtensionContentSession instances of multiple UIExtensionAbilities are operated separately.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
>
> This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.app.ability.UIExtensionContentSession (UI Operation Class for ExtensionAbilities with UI)](js-apis-app-ability-uiExtensionContentSession.md).

## Modules to Import

```ts
import { UIExtensionContentSession } from '@kit.AbilityKit';
```

## UIExtensionContentSession

### sendData

sendData(data: Record\<string, Object>): void

Sends data to the UIExtensionComponent.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| data | Record\<string,&nbsp;Object> | Yes| Data to send.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 202      | Not System App. Interface caller is not a system app. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16000050 | Internal error. |

**Example**

```ts
import { UIExtensionContentSession } from '@kit.AbilityKit';

@Entry()
@Component
struct Index {
  private storage: LocalStorage | undefined = this.getUIContext().getSharedLocalStorage();
  private session: UIExtensionContentSession | undefined =
    this.storage?.get<UIExtensionContentSession>('session');

  build() {
    RelativeContainer() {
      Button('SendData')
        .onClick(() => {
          let data: Record<string, Object> = {
            'number': 123456,
            'message': 'test'
          };

          try {
            this.session?.sendData(data);
          } catch (err) {
            console.log('sendData err:' + JSON.stringify(err));
          }
        })
    }
    .height('100%')
    .width('100%')
  }
}
```

### setReceiveDataCallback

setReceiveDataCallback(callback: (data: Record\<string, Object>) => void): void

Sets a callback to receive data from the UIExtensionComponent. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | (data: Record\<string, Object>) => void | Yes| Callback used to return the received data.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 202      | Not System App. Interface caller is not a system app. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16000050 | Internal error. |

**Example**

```ts
import { UIExtensionContentSession } from '@kit.AbilityKit';

@Entry()
@Component
struct Index {
  storage: LocalStorage | undefined = this.getUIContext().getSharedLocalStorage();
  private session: UIExtensionContentSession | undefined =
    this.storage?.get<UIExtensionContentSession>('session');

  build() {
    RelativeContainer() {
      Button('SendData')
        .onClick(() => {
          this.session?.setReceiveDataCallback((data: Record<string, Object>) => {
            console.info(`Succeeded in setReceiveDataCallback, data: ${JSON.stringify(data)}`);
          });
        })
    }
    .height('100%')
    .width('100%')
  }
}
```

### setReceiveDataForResultCallback<sup>11+</sup>

setReceiveDataForResultCallback(callback: (data: Record<string, Object>) => Record<string, Object>): void

Sets a callback with a return value to receive data from the UIExtensionComponent. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core


**Parameters**

| Name| Type| Mandatory| Description            |
| -------- | -------- | -------- |----------------|
| callback | (data: Record\<string, Object>) => Record\<string, Object> | Yes| Callback used to return the received data with a return value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 202      | Not System App. Interface caller is not a system app. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16000050 | Internal error. |

**Example**

```ts
import { UIExtensionContentSession } from '@kit.AbilityKit';

@Entry()
@Component
struct Index {
  storage: LocalStorage | undefined = this.getUIContext().getSharedLocalStorage();
  private session: UIExtensionContentSession | undefined =
    this.storage?.get<UIExtensionContentSession>('session');

  build() {
    RelativeContainer() {
      Button('SetReceiveDataForResultCallback')
        .onClick(() => {
          this.session?.setReceiveDataForResultCallback((data: Record<string, Object>) => {
            console.info(`Succeeded in setReceiveDataCallback, data: ${JSON.stringify(data)}`);
            return data;
          });
        })
    }
    .height('100%')
    .width('100%')
  }
}
```

### startAbility

startAbility(want: Want, callback: AsyncCallback&lt;void&gt;): void

Starts an ability. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).
> The application where the UIExtensionComponent is located must be running in the foreground and gain focus.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information about the target ability.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the ability is started, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201      | The application does not have permission to call the interface. |
| 202      | Not System App. Interface caller is not a system app. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Cannot start an invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation and prepare continuation flag is forbidden.        |
| 16000011 | The context does not exist.        |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

**Example**

```ts
import { UIExtensionContentSession, UIExtensionAbility, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class UIExtAbility extends UIExtensionAbility {
  // ...

  onSessionCreate(want: Want, session: UIExtensionContentSession): void {
    session.startAbility(want, (err: BusinessError) => {
      if (err) {
        console.error(`Failed to startAbility, code: ${err.code}, msg: ${err.message}`);
        return;
      }
      console.info(`Succeeded in startAbility`);
    })
  }

  // ...
}
```

### startAbility

startAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;): void

Starts an ability with **options** specified. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).
> The application where the UIExtensionComponent is located must be running in the foreground and gain focus.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md)  | Yes| Want information about the target ability.|
| options | [StartOptions](js-apis-app-ability-startOptions.md) | Yes| Parameters used for starting the ability.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the ability is started, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201      | The application does not have permission to call the interface. |
| 202      | Not System App. Interface caller is not a system app. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16000001 | The specified ability does not exist. |
| 16000004 | Cannot start an invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000011 | The context does not exist.        |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

**Example**

```ts
import { UIExtensionContentSession, UIExtensionAbility, Want, StartOptions } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class UIExtAbility extends UIExtensionAbility {
  // ...

  onSessionCreate(want: Want, session: UIExtensionContentSession): void {
    let starOptions: StartOptions = {
      displayId: 0
    };

    session.startAbility(want, starOptions, (err: BusinessError) => {
      if (err) {
        console.error(`Failed to startAbility, code: ${err.code}, msg: ${err.message}`);
        return;
      }
      console.info(`Succeeded in startAbility`);
    })
  }

  // ...
}
```

### startAbility

startAbility(want: Want, options?: StartOptions): Promise&lt;void&gt;

Starts an ability. This API uses a promise to return the result.

> **NOTE**
>
> For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).
> The application where the UIExtensionComponent is located must be running in the foreground and gain focus.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information about the target ability.|
| options | [StartOptions](js-apis-app-ability-startOptions.md) | No| Parameters used for starting the ability.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201      | The application does not have permission to call the interface. |
| 202      | Not System App. Interface caller is not a system app. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Cannot start an invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation and prepare continuation flag is forbidden.        |
| 16000011 | The context does not exist.        |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

**Example**

```ts
import { UIExtensionContentSession, UIExtensionAbility, Want, StartOptions } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class UIExtAbility extends UIExtensionAbility {
  // ...

  onSessionCreate(want: Want, session: UIExtensionContentSession): void {
    let starOptions: StartOptions = {
      displayId: 0
    };

    session.startAbility(want, starOptions)
      .then(() => {
        console.info(`Succeeded in startAbility`);
      })
      .catch((err: BusinessError) => {
        console.error(`Failed to startAbility, code: ${err.code}, msg: ${err.message}`);
      });
  }

  // ...
}
```

### startAbilityForResult

startAbilityForResult(want: Want, callback: AsyncCallback&lt;AbilityResult&gt;): void

Starts an ability and returns the result to the caller after the ability is terminated. This API uses an asynchronous callback to return the result.

An ability can be terminated in the following ways:
 - Normally, you can call [terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#terminateselfwithresult) to terminate the ability. The result is returned to the caller.
 - If an exception occurs, for example, the ability is killed, an error message, in which **resultCode** is **-1**, is returned to the caller.
 - If different applications call this API to start an ability that uses the singleton mode and then call [terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#terminateselfwithresult) to terminate the ability, the normal result is returned to the last caller, and an exception message, in which **resultCode** is **-1**, is returned to others.

> **NOTE**
>
> For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).
> The application where the UIExtensionComponent is located must be running in the foreground and gain focus.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want |[Want](js-apis-app-ability-want.md) | Yes| Want information about the target ability.|
| callback | AsyncCallback&lt;[AbilityResult](js-apis-inner-ability-abilityResult.md)&gt; | Yes| Callback used to return the result. If the ability is started and terminated, **err** is **undefined** and **data** is the obtained result code and data; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201      | The application does not have permission to call the interface. |
| 202      | Not System App. Interface caller is not a system app. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Cannot start an invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation and prepare continuation flag is forbidden. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

**Example**

```ts
import { UIExtensionContentSession, UIExtensionAbility, Want, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class UIExtAbility extends UIExtensionAbility {
  // ...

  onSessionCreate(want: Want, session: UIExtensionContentSession): void {
    session.startAbilityForResult(want, (err: BusinessError, data: common.AbilityResult) => {
      if (err) {
        console.error(`Failed to startAbilityForResult, code: ${err.code}, msg: ${err.message}`);
        return;
      }
      console.info(`Succeeded in startAbilityForResult, data: ${JSON.stringify(data)}`);
    })
  }

  // ...
}
```

### startAbilityForResult

startAbilityForResult(want: Want, options: StartOptions, callback: AsyncCallback&lt;AbilityResult&gt;): void

Starts an ability with **options** specified and returns the result to the caller after the ability is terminated. This API uses an asynchronous callback to return the result.

An ability can be terminated in the following ways:
 - Normally, you can call [terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#terminateselfwithresult) to terminate the ability. The result is returned to the caller.
 - If an exception occurs, for example, the ability is killed, an error message, in which **resultCode** is **-1**, is returned to the caller.
 - If different applications call this API to start an ability that uses the singleton mode and then call [terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#terminateselfwithresult) to terminate the ability, the normal result is returned to the last caller, and an exception message, in which **resultCode** is **-1**, is returned to others.

> **NOTE**
>
> For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).
> The application where the UIExtensionComponent is located must be running in the foreground and gain focus.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want |[Want](js-apis-app-ability-want.md) | Yes| Want information about the target ability.|
| options | [StartOptions](js-apis-app-ability-startOptions.md) | Yes| Parameters used for starting the ability.|
| callback | AsyncCallback&lt;[AbilityResult](js-apis-inner-ability-abilityResult.md)&gt; | Yes| Callback used to return the result. If the ability is started and terminated, **err** is **undefined** and **data** is the obtained result code and data; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201      | The application does not have permission to call the interface. |
| 202      | Not System App. Interface caller is not a system app. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16000001 | The specified ability does not exist. |
| 16000004 | Cannot start an invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

**Example**

```ts
import { UIExtensionContentSession, UIExtensionAbility, Want, StartOptions, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class UIExtAbility extends UIExtensionAbility {
  // ...

  onSessionCreate(want: Want, session: UIExtensionContentSession): void {
    let starOptions: StartOptions = {
      displayId: 0
    };

    session.startAbilityForResult(want, starOptions, (err: BusinessError, data: common.AbilityResult) => {
      if (err) {
        console.error(`Failed to startAbilityForResult, code: ${err.code}, msg: ${err.message}`);
        return;
      }
      console.info(`Succeeded in startAbilityForResult, data: ${JSON.stringify(data)}`);
    })
  }

  // ...
}
```

### startAbilityForResult

startAbilityForResult(want: Want, options?: StartOptions): Promise&lt;AbilityResult&gt;

Starts an ability and returns the result to the caller after the ability is terminated. This API uses a promise to return the result.

An ability can be terminated in the following ways:
 - Normally, you can call [terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#terminateselfwithresult) to terminate the ability. The result is returned to the caller.
 - If an exception occurs, for example, the ability is killed, an error message, in which **resultCode** is **-1**, is returned to the caller.
 - If different applications call this API to start an ability that uses the singleton mode and then call [terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#terminateselfwithresult) to terminate the ability, the normal result is returned to the last caller, and an exception message, in which **resultCode** is **-1**, is returned to others.

> **NOTE**
>
> For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).
> The application where the UIExtensionComponent is located must be running in the foreground and gain focus.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information about the target ability.|
| options | [StartOptions](js-apis-app-ability-startOptions.md) | No| Parameters used for starting the ability.|


**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[AbilityResult](js-apis-inner-ability-abilityResult.md)&gt; | Promise used to return the result code and data.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201      | The application does not have permission to call the interface. |
| 202      | Not System App. Interface caller is not a system app. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Cannot start an invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation and prepare continuation flag is forbidden. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

**Example**

```ts
import { UIExtensionContentSession, UIExtensionAbility, Want, StartOptions, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class UIExtAbility extends UIExtensionAbility {
  // ...

  onSessionCreate(want: Want, session: UIExtensionContentSession): void {
    let starOptions: StartOptions = {
      displayId: 0
    };

    session.startAbilityForResult(want, starOptions)
      .then((data: common.AbilityResult) => {
        console.info(`Succeeded in startAbilityForResult, data: ${JSON.stringify(data)}`);
      })
      .catch((err: BusinessError) => {
        console.error(`Failed to startAbilityForResult, code: ${err.code}, msg: ${err.message}`);
      });
  }

  // ...
}
```

### setWindowBackgroundColor

setWindowBackgroundColor(color: string): void

Sets the background color for the loading page of the UIExtensionAbility. This API can be used only after [loadContent()](js-apis-app-ability-uiExtensionContentSession.md#loadcontent) is called and takes effect.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| color | string | Yes| Background color to set. The value is a hexadecimal RGB or ARGB color code and is case insensitive, for example, **#00FF00** or **#FF00FF00**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 202      | Not System App. Interface caller is not a system app. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16000050 | Internal error. |

**Example**

```ts
import { UIExtensionContentSession, UIExtensionAbility, Want } from '@kit.AbilityKit';

export default class UIExtAbility extends UIExtensionAbility {
  // ...

  onSessionCreate(want: Want, session: UIExtensionContentSession): void {
    let storage: LocalStorage = new LocalStorage();
    storage.setOrCreate('session', session);

    try {
      session.loadContent('pages/Extension', storage);
    } catch (err) {
      console.log('loadContent err:' + JSON.stringify(err));
    }

    try {
      session.setWindowBackgroundColor('#00FF00');
    } catch (err) {
      console.log('setWindowBackgroundColor err:' + JSON.stringify(err));
    }
  }

  // ...
}
```

### startAbilityAsCaller<sup>11+</sup>

startAbilityAsCaller(want: Want, callback: AsyncCallback\<void>): void

Starts an ability as the caller. The initial ability places its caller information (such as the bundle name and ability name) in the **want** parameter and transfers the information to an **ExtensionAbility** at the middle layer. When the ExtensionAbility starts another ability by calling this API, the started ability can obtain the caller information of the initial ability from the **onCreate** lifecycle. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information about the target ability.|
| callback | AsyncCallback\<void> | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201      | The application does not have permission to call the interface. |
| 202      | Not System App. Interface caller is not a system app. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Cannot start an invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation and prepare continuation flag is forbidden. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled. |
| 16000013 | The application is controlled by EDM. |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

**Example**

```ts
import { UIExtensionContentSession, UIExtensionAbility, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class UIExtAbility extends UIExtensionAbility {
  // ...

  onSessionCreate(want: Want, session: UIExtensionContentSession): void {
    let localWant: Want = want;
    localWant.bundleName = 'com.example.demo';
    localWant.moduleName = 'entry';
    localWant.abilityName = 'TestAbility';

    session.startAbilityAsCaller(localWant, (err: BusinessError) => {
      if (err) {
        console.error(`Failed to startAbilityAsCaller, code: ${err.code}, msg: ${err.message}`);
        return;
      }
      console.info(`Succeeded in startAbilityAsCaller`);
    })
  }

  // ...
}
```

### startAbilityAsCaller<sup>11+</sup>

startAbilityAsCaller(want: Want, options: StartOptions, callback: AsyncCallback\<void>): void

Starts an ability as the caller, with **options** specified. The initial ability places its caller information (such as the bundle name and ability name) in the **want** parameter and transfers the information to an **ExtensionAbility** at the middle layer. When the ExtensionAbility starts another ability by calling this API, the started ability can obtain the caller information of the initial ability from the **onCreate** lifecycle. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information about the target ability.|
| options | [StartOptions](js-apis-app-ability-startOptions.md) | Yes| Parameters used for starting the ability.|
| callback | AsyncCallback\<void> | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201      | The application does not have permission to call the interface. |
| 202      | Not System App. Interface caller is not a system app. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16000001 | The specified ability does not exist. |
| 16000004 | Cannot start an invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled. |
| 16000013 | The application is controlled by EDM. |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

**Example**

```ts
import { UIExtensionContentSession, UIExtensionAbility, Want, StartOptions } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class UIExtAbility extends UIExtensionAbility {
  // ...

  onSessionCreate(want: Want, session: UIExtensionContentSession): void {
    let localWant: Want = want;
    localWant.bundleName = 'com.example.demo';
    localWant.moduleName = 'entry';
    localWant.abilityName = 'TestAbility';

    let startOptions: StartOptions = {
      displayId: 0
    };

    session.startAbilityAsCaller(localWant, startOptions, (err: BusinessError) => {
      if (err) {
        console.error(`Failed to startAbilityAsCaller, code: ${err.code}, msg: ${err.message}`);
        return;
      }
      console.info(`Succeeded in startAbilityAsCaller`);
    })
  }

  // ...
}
```

### startAbilityAsCaller<sup>11+</sup>

startAbilityAsCaller(want: Want, options?: StartOptions): Promise\<void>

Starts an ability as the caller. The initial ability places its caller information (such as the bundle name and ability name) in the **want** parameter and transfers the information to an **ExtensionAbility** at the middle layer. When the ExtensionAbility starts another ability by calling this API, the started ability can obtain the caller information of the initial ability from the **onCreate** lifecycle. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information about the target ability.|
| options | [StartOptions](js-apis-app-ability-startOptions.md) | No| Parameters used for starting the ability.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201      | The application does not have permission to call the interface. |
| 202      | Not System App. Interface caller is not a system app. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Cannot start an invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation and prepare continuation flag is forbidden. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled. |
| 16000013 | The application is controlled by EDM. |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

**Example**

```ts
import { UIExtensionContentSession, UIExtensionAbility, Want, StartOptions } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class UIExtAbility extends UIExtensionAbility {
  // ...

  onSessionCreate(want: Want, session: UIExtensionContentSession): void {
    let localWant: Want = want;
    localWant.bundleName = 'com.example.demo';
    localWant.moduleName = 'entry';
    localWant.abilityName = 'TestAbility';

    let startOptions: StartOptions = {
      displayId: 0
    };

    session.startAbilityAsCaller(localWant, startOptions)
      .then(() => {
        console.info(`Succeeded in startAbilityAsCaller`);
      })
      .catch((err: BusinessError) => {
        console.error(`Failed to startAbilityAsCaller, code: ${err.code}, msg: ${err.message}`);
      });
  }

  // ...
}
```

### getUIExtensionHostWindowProxy<sup>11+</sup>

getUIExtensionHostWindowProxy(): uiExtensionHost.UIExtensionHostWindowProxy

Obtains the window object corresponding to the current UIExtension to notify the width, height, position, and avoided area.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type| Description|
| -------- | -------- |
| [uiExtensionHost.UIExtensionHostWindowProxy](../apis-arkui/js-apis-uiExtensionHost-sys.md) | Window information of the host application.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 202      | Not System App. Interface caller is not a system app. |
| 16000050 | Internal error. |

**Example**

```ts
import { UIExtensionAbility, UIExtensionContentSession, Want } from '@kit.AbilityKit';
import { uiExtensionHost } from '@kit.ArkUI';

const TAG: string = '[UIExtAbility]';

export default class UIExtAbility extends UIExtensionAbility {
  onCreate() {
    console.log(TAG, `UIExtAbility onCreate`);
  }

  onForeground() {
    console.log(TAG, `UIExtAbility onForeground`);
  }

  onBackground() {
    console.log(TAG, `UIExtAbility onBackground`);
  }

  onDestroy() {
    console.log(TAG, `UIExtAbility onDestroy`);
  }

  onSessionCreate(want: Want, session: UIExtensionContentSession) {
    let extensionHostWindow = session.getUIExtensionHostWindowProxy();
    let data: Record<string, UIExtensionContentSession | uiExtensionHost.UIExtensionHostWindowProxy> = {
      'session': session,
      'extensionHostWindow': extensionHostWindow
    };
    let storage: LocalStorage = new LocalStorage(data);

    try {
      session.loadContent('pages/Extension', storage);
    } catch (err) {
      console.log('loadContent err:' + JSON.stringify(err));
    }
  }

  onSessionDestroy(session: UIExtensionContentSession) {
    console.log(TAG, `UIExtAbility onSessionDestroy`);
  }
}
```
