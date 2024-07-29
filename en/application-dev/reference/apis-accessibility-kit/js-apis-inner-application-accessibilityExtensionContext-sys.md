# AccessibilityExtensionContext (System API)

The **AccessibilityExtensionContext** module, inherited from **ExtensionContext**, provides context for **AccessibilityExtensionAbility**.

You can use the APIs of this module to configure the concerned information, obtain root information, and inject gestures.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The current page contains only the system APIs of the current module. For details about other public APIs, see [AccessibilityExtensionContext](js-apis-inner-application-accessibilityExtensionContext.md).

## Instructions

Before using the **AccessibilityExtensionContext** module, you must define a child class that inherits from **AccessibilityExtensionAbility**.

```ts
import { AccessibilityExtensionAbility } from '@kit.AccessibilityKit';

class EntryAbility extends AccessibilityExtensionAbility {
  onConnect(): void {
    let axContext = this.context; 
  } 
}
```

### enableScreenCurtain<sup>12+</sup>

enableScreenCurtain(isEnable: boolean): void;

Enables or disables the screen curtain.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name        | Type                                    | Mandatory  | Description            |
| ----------- | ---------------------------------------- | ---- | -------------- |
| isEnable | boolean | Yes   | **true** indicates enabled; **false** indicates disabled.|

**Error codes**

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| ID  | Error Message                                    |
| ------- | ---------------------------------------- |
| 401  | Input parameter error. Incorrect parameter types. |
| 9300003 | Do not have accessibility right for this operation. |

**Example**

```ts
import { AccessibilityElement } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let rootElement: AccessibilityElement;

axContext.getWindowRootElement().then((data: AccessibilityElement) => {
  rootElement = data;
  console.log(`Succeeded in get root element of the window, ${JSON.stringify(data)}`);
  await rootElement.enableScreenCurtain(true);
  console.log(`Succeeded in enableScreenCurtain}`);
}).catch((err: BusinessError) => {
  console.error(`failed to enableScreenCurtain, Code is ${err.code}, message is ${err.message}`);
});
```
