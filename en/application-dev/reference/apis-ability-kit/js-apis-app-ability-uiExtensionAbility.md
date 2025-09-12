# @ohos.app.ability.UIExtensionAbility (ExtensionAbility with UI)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @zhangyafei-echo; @xuzhihao666-->
<!--Designer: @zhangyafei-echo-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->


UIExtensionAbility is an ExtensionAbility component with a User Interface (UI). It inherits from [ExtensionAbility](js-apis-app-ability-extensionAbility.md) and provides basic lifecycle capabilities such as component creation, destruction, and foreground/background switching. Unlike the UIAbility, the UIExtensionAbility does not appear as a separate mission in the mission view. The foreground/background state and visibility of the UIExtensionAbility follow those of its host window.

You cannot directly inherit from the UIExtensionAbility. However, you can choose other components that inherit from UIExtensionAbility based on specific service scenarios. For example, when handling data shared from other applications, you can use the [ShareExtensionAbility](./js-apis-app-ability-shareExtensionAbility.md); when providing widget editing functionality, you can use the [FormEditExtensionAbility](../apis-form-kit/js-apis-app-form-formEditExtensionAbility.md).

For details about the inheritance relationship of each ability, see [Inheritance Relationship](./js-apis-app-ability-ability.md#ability-inheritance-relationship).

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import { UIExtensionAbility } from '@kit.AbilityKit';
```

## UIExtensionAbility

Represents an ExtensionAbility with a UI, and provides lifecycle callbacks for component creation, destruction, and foreground/background switching.

### Properties

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

| Name| Type| Read-only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| context | [UIExtensionContext](js-apis-inner-application-uiExtensionContext.md) | No| No| Context of the UIExtensionAbility.|

### onCreate

onCreate(launchParam: AbilityConstant.LaunchParam): void

Called when a UIExtensionAbility instance is created. You can execute initialization logic (such as defining variables and loading resources) within this callback.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| launchParam<sup>12+</sup> | [AbilityConstant.LaunchParam](js-apis-app-ability-abilityConstant.md#launchparam) | Yes| Parameters for application launch, including the reason for application launch and the reason for the last application exit.|

**Example**

```ts
// The UIExtensionAbility class does not allow direct inheritance by third-party applications. The child class ShareExtensionAbility is used here as an example.
import { ShareExtensionAbility, AbilityConstant } from '@kit.AbilityKit';

const TAG: string = '[testTag] ShareExtAbility';

export default class ShareExtAbility extends ShareExtensionAbility {
  onCreate(launchParam: AbilityConstant.LaunchParam) {
    console.info(TAG, `onCreate, launchParam: ${JSON.stringify(launchParam)}`);
  }
}
```

### onSessionCreate

onSessionCreate(want: Want, session: UIExtensionContentSession): void

Called when a [UIExtensionContentSession](js-apis-app-ability-uiExtensionContentSession.md) instance is created. You can load a page through the UIExtensionContentSession instance within this callback.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Data passed by the caller when launching the UIExtensionAbility.|
| session | [UIExtensionContentSession](js-apis-app-ability-uiExtensionContentSession.md) | Yes| UIExtensionContentSession instance.|

**Example**

```ts
// The UIExtensionAbility class does not allow direct inheritance by third-party applications. The child class ShareExtensionAbility is used here as an example.
import { ShareExtensionAbility, UIExtensionContentSession, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

const TAG: string = '[testTag] ShareExtAbility';

export default class ShareExtAbility extends ShareExtensionAbility {
  onSessionCreate(want: Want, session: UIExtensionContentSession) {
    console.info(TAG, `onSessionCreate, want: ${JSON.stringify(want)}`);
    try {
      session.loadContent('pages/Index');
    } catch (error) {
      let code = (error as BusinessError).code;
      let message = (error as BusinessError).message;
      console.error(`Failed to load content, code: ${code}, msg: ${message}`);
    }
  }
}
```

### onSessionDestroy

onSessionDestroy(session: UIExtensionContentSession): void

Called when a UIExtensionContentSession is destroyed. It informs applications that the UIExtensionContentSession instance is no longer available for use.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| session | [UIExtensionContentSession](js-apis-app-ability-uiExtensionContentSession.md) | Yes| UIExtensionContentSession instance.|

**Example**

```ts
// The UIExtensionAbility class does not allow direct inheritance by third-party applications. The child class ShareExtensionAbility is used here as an example.
import { ShareExtensionAbility, UIExtensionContentSession } from '@kit.AbilityKit';

const TAG: string = '[testTag] ShareExtAbility';

export default class ShareExtAbility extends ShareExtensionAbility {
  onSessionDestroy(session: UIExtensionContentSession) {
    console.info(TAG, `onSessionDestroy`);
  }
}
```

### onForeground

onForeground(): void

Called when a UIExtensionAbility is initially launched into the foreground or transitions from the background to the foreground. You can apply for resources when the UI becomes visible within this callback.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Example**

```ts
// The UIExtensionAbility class does not allow direct inheritance by third-party applications. The child class ShareExtensionAbility is used here as an example.
import { ShareExtensionAbility } from '@kit.AbilityKit';

const TAG: string = '[testTag] ShareExtAbility';

export default class ShareExtAbility extends ShareExtensionAbility {
  onForeground() {
    console.info(TAG, `onForeground`);
  }
}
```

### onBackground

onBackground(): void

Called when a UIExtensionAbility transitions from the foreground to the background. You can release resources when the UI is no longer invisible within this callback.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Example**

```ts
// The UIExtensionAbility class does not allow direct inheritance by third-party applications. The child class ShareExtensionAbility is used here as an example.
import { ShareExtensionAbility } from '@kit.AbilityKit';

const TAG: string = '[testTag] ShareExtAbility';

export default class ShareExtAbility extends ShareExtensionAbility {
  onBackground() {
    console.info(TAG, `onBackground`);
  }
}
```

### onDestroy

onDestroy(): void | Promise&lt;void&gt;

Called when a UIExtensionAbility is destroyed. You can clear resources and save data during this lifecycle. This API returns the result synchronously or uses a promise to return the result.

After the **onDestroy()** lifecycle callback is executed, the application may exit. Consequently, the asynchronous function (for example, asynchronously writing data to the database) in **onDestroy()** may fail to be executed. Using a Promise for asynchronous callback is recommended to prevent such issues.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Returns**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| void \| Promise\<void> | No return value or a Promise object that returns no value.                    |

**Example**

- A synchronous callback example is as follows:
  ```ts
  // The UIExtensionAbility class does not allow direct inheritance by third-party applications. The child class ShareExtensionAbility is used here as an example.
  import { ShareExtensionAbility } from '@kit.AbilityKit';

  const TAG: string = '[testTag] ShareExtAbility';

  export default class ShareExtAbility extends ShareExtensionAbility {
    onDestroy() {
      console.info(TAG, `onDestroy`);
    }
  }
  ```

- An asynchronous callback example is as follows:
  ```ts
  // The UIExtensionAbility class does not allow direct inheritance by third-party applications. The child class ShareExtensionAbility is used here as an example.
  import { ShareExtensionAbility } from '@kit.AbilityKit';

  const TAG: string = '[testTag] ShareExtAbility';

  export default class ShareExtAbility extends ShareExtensionAbility {
    // Use the async/await syntax to implement an asynchronous callback. The async keyword declares that onDestroy is an asynchronous function.
    async onDestroy(): Promise<void> {
      console.info(TAG, `onDestroy begin`);
      try {
        const result: string = await new Promise((resolve: Function) => {
          setTimeout(() => {
            resolve('Hello, world!');
          }, 3000);
        });
        console.info(TAG, result); // result is 'Hello, world!'
      } catch (e) {
        console.error(TAG, `Get exception: ${e}`);
      }
      console.info(TAG, `onDestroy end`);
    }
  }
  ```
