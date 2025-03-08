# UIServiceHostProxy (System API)

UIServiceHostProxy functions as a proxy to send data from the [UIServiceExtensionAbility](js-apis-app-ability-uiServiceExtensionAbility-sys.md) server to the client.


> **NOTE**
>
>  - The initial APIs of this module are supported since API version 13. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>  - The APIs of this module can be used only in the stage model.
>  - The APIs of this module must be used in the main thread, but not in sub-threads such as Worker and TaskPool.
>  - The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { common } from '@kit.AbilityKit';
```


## UIServiceHostProxy.sendData

sendData(data: Record\<string, Object>): void

Sends data from the [UIServiceExtensionAbility](js-apis-app-ability-uiServiceExtensionAbility-sys.md) server to the client.


**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| data | Record\<string, Object> | Yes| No| Data to be sent to the [UIServiceExtensionAbility](js-apis-app-ability-uiServiceExtensionAbility-sys.md) client.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 202 | Not System App. Interface caller is not a system app .                                                       |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**Example**

```ts
import { common, UIServiceExtensionAbility } from '@kit.AbilityKit';

const TAG: string = '[UiServiceExtensionAbility] ';

export default class MyUiServiceExtensionAbility extends UIServiceExtensionAbility {

  // Process data sending.
  onData(proxy: common.UIServiceHostProxy, data: Record<string, Object>) {
    console.log(TAG + `onData ${JSON.stringify(data)}`);
    // Define the data to be sent.
    let formData: Record<string, string> = {
      'proxyData': 'proxyData'
    };
    try {
      // Send data to the UIServiceExtensionAbility server.
      proxy.sendData(formData);
    } catch (err) {
      console.log(TAG + `sendData failed ${JSON.stringify(err.message)}`);
    }
  }
}
```
