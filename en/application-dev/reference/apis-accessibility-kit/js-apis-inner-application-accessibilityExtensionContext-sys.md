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
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 9300003 | No accessibility permission to perform the operation. |

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

### findElement('elementId')<sup>12+</sup>

findElement(type: 'elementId', condition: number): Promise\<AccessibilityElement>;

Queries the node elements in the current active window based on the **elementId**. This API uses a promise to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name      | Type                               | Mandatory  | Description                                      |
| --------- | --------------------------------- | ---- | ---------------------------------------- |
| type      | string                            | Yes   | Type of element finding. The value is fixed at **'elementId'**.|
| condition | number | Yes   | **elementId** of the node element.                          |

**Return value**

| Type                                 | Description                              |
| ----------------------------------- | -------------------------------- |
| Promise&lt;[AccessibilityElement](js-apis-inner-application-accessibilityExtensionContext.md#accessibilityelement9)&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| ID  | Error Message                         |
| ------- | ----------------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// elementId is 10.
let condition = 10;

// rootElement is an instance of AccessibilityElement.
rootElement.findElement('elementId', condition).then((data: AccessibilityElement) => {
  console.log(`Succeeded in find element, ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`failed to find element, Code is ${err.code}, message is ${err.message}`);
});
```

### findElement('textType')<sup>12+</sup>

findElement(type: 'textType', condition: string): Promise\<Array\<AccessibilityElement>>;

Queries all node elements based on the **accessibilityTextHint** text type configured for a node. This API uses a promise to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name      | Type    | Mandatory  | Description                           |
| --------- | ------ | ---- | ----------------------------- |
| type      | string | Yes   | Type of element finding. The value is fixed at **'textType'**.|
| condition | string | Yes   | Search criteria.                     |

**Return value**

| Type                                      | Description                           |
| ---------------------------------------- | ----------------------------- |
| Promise&lt;Array&lt;[AccessibilityElement](js-apis-inner-application-accessibilityExtensionContext.md#accessibilityelement9)&gt;&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| ID  | Error Message                         |
| ------- | ----------------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// The content of condition must be the same as the type value in the accessibilityTextHint attribute of the target component.
let condition = 'location'; 

// rootElement is an instance of AccessibilityElement.
rootElement.findElement('textType', condition).then((data: AccessibilityElement[]) => {
  console.log(`Succeeded in find element, ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`failed to find element, Code is ${err.code}, message is ${err.message}`);
});
```

### getCursorPosition<sup>12+</sup>

getCursorPosition(): Promise\<number>;

Obtains the cursor position in the **Text** component. This API uses a promise to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Return value**

| Type                 | Description              |
| ------------------- | ---------------- |
| Promise&lt;number&gt; | Promise used to return the result.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// rootElement is an instance of AccessibilityElement.
rootElement.getCursorPosition().then((data: number) => {
  console.info(`Succeeded in getCursorPosition, ${data}`);
}).catch((err: BusinessError) => {
  console.error(`failed to getCursorPosition, Code is ${err.code}, message is ${err.message}`);
});
```

### getCursorPosition<sup>12+</sup>

getCursorPosition(callback: AsyncCallback\<number>): void;

Obtains the cursor position in the **Text** component. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name        | Type                                    | Mandatory  | Description            |
| ----------- | ---------------------------------------- | ---- | -------------- |
| callback | AsyncCallback&lt;number&gt; | Yes   | Callback function used to return the result.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// rootElement is an instance of AccessibilityElement.
rootElement.getCursorPosition((err: BusinessError, data: number) => {
  if (err && err.code) {
    console.error(`failed to getCursorPosition, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in getCursorPosition, ${data}`);
});
```

### startAbility<sup>12+</sup>

startAbility(want: Want): void;

Starts the foreground page.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](../../reference/apis-ability-kit/js-apis-app-ability-want.md) | Yes| Want information about the target ability, such as the ability name and bundle name.|

**Error codes**

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| ID  | Error Message                                    |
| ------- | ---------------------------------------- |
| 201 | Permission denied. Interface caller does not have permission. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let want: Want = {
  bundleName: 'com.huawei.hmos.photos'
  abilityName: 'com.huawei.hmos.photos.MainAbility'
}

axContext.startAbility(want).then(() => {
  console.info(`startAbility Succeeded enable ability`);
}).catch((err: BusinessError) => {
  console.error(`startAbility failed to enable ability, Code is ${err.code}, message is ${err.message}`);
});
```
