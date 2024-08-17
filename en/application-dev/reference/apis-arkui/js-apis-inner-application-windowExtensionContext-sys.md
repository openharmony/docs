# WindowExtensionContext (System API)

The **WindowExtensionContext** module, inherited from [ExtensionContext](../apis-ability-kit/js-apis-inner-application-extensionContext.md), is the context environment of the WindowExtensionAbility.

The **WindowExtensionContext** module provides the capabilities of the [WindowExtensionAbility](js-apis-application-windowExtensionAbility-sys.md), including starting the ability.

> **NOTE**
>
>  - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
>  - The APIs provided by this module are system APIs.
>
>  - The APIs of this module can be used only in the stage model.

## Usage

Before using the **WindowExtensionContext** module, you must define a child class that inherits from **WindowExtensionAbility**.

```ts
import { WindowExtensionAbility, WindowExtensionContext } from '@kit.ArkUI';

let context: WindowExtensionContext | null = null;

class WindowExtAbility extends WindowExtensionAbility {
  onConnect() {
    context = this.context; // Obtain a WindowExtensionContext instance.
  }
}
```

## WindowExtensionContext.startAbility

startAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;): void

Starts an ability. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| want | [Want](../apis-ability-kit/js-apis-app-ability-want.md)  | Yes | Want information about the target ability. |
| options | [StartOptions](../apis-ability-kit/js-apis-app-ability-startOptions.md) | Yes | Parameters used for starting the ability. |
| callback | AsyncCallback&lt;void&gt; | Yes | Callback used to return the result. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message |
| ------- | --------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { WindowExtensionAbility } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';
import { Want, StartOptions } from '@kit.AbilityKit';

class WindowExtAbility extends WindowExtensionAbility {
  
  onConnect() {
    let want: Want = {
      bundleName: 'com.example.myapplication',
      abilityName: 'MainAbility'
    };
    let options: StartOptions = {
      windowMode: 102
    };

    try {
      this.context.startAbility(want, options, (error: BusinessError) => {
        let message = (error as BusinessError).message;
        let errCode = (error as BusinessError).code;
        if (errCode) {
          // Process service logic errors.
          console.error(`startAbility failed, error.code: ${errCode}, error.message: ${message}`);
          return;
        }
        // Carry out normal service processing.
        console.log('startAbility succeed');
      });
    } catch (paramError) {
      // Process input parameter errors.
      let message = (paramError as BusinessError).message;
      let errCode = (paramError as BusinessError).code;
      console.error(`error.code: ${errCode}, error.message: ${message}`);
    }
  }
}
```

## WindowExtensionContext.startAbility

startAbility(want: Want, options?: StartOptions): Promise\<void>

Starts an ability. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| want | [Want](../apis-ability-kit/js-apis-app-ability-want.md)  | Yes | Want information about the target ability, such as the ability name and bundle name. |
| options | [StartOptions](../apis-ability-kit/js-apis-app-ability-startOptions.md) | No | Parameters used for starting the ability. |

**Return value**

| Type | Description |
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message |
| ------- | --------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { WindowExtensionAbility } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';
import { Want, StartOptions } from '@kit.AbilityKit';

class WindowExtAbility extends WindowExtensionAbility {

  onConnect() {
    let want: Want = {
      bundleName: 'com.example.myapp',
      abilityName: 'MainAbility'
    };
    let options: StartOptions = {
      windowMode: 102,
    };

    try {
      this.context.startAbility(want, options)
        .then(() => {
          // Carry out normal service processing.
          console.log('startAbility succeed');
        })
        .catch((error: BusinessError) => {
          // Process service logic errors.
          let message = (error as BusinessError).message;
          let errCode = (error as BusinessError).code;
          console.error(`startAbility failed, error.code: ${errCode}, error.message: ${message}`);
        });
    } catch (paramError) {
      // Process input parameter errors.
      let message = (paramError as BusinessError).message;
      let errCode = (paramError as BusinessError).code;
      console.error(`error.code: ${errCode}, error.message: ${message}`);
    }
  }
}
```
