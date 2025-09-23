# @ohos.window.floatingBall (Floating Ball Window)
<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @betafringe007-->
<!--Designer: @zhoulin_-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->

This module provides essential functionalities for floating balls. It lets you check whether the device supports floating balls and create a controller to start, update, or stop them. It is ideal for tasks like comparing prices, searching for answers, or grabbing orders. The floating ball appears as a floating widget above other application, quickly showing important information.

> **NOTE**
>
> The initial APIs of this module are supported since API version 20. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { floatingBall } from '@kit.ArkUI';
```

## floatingBall.isFloatingBallEnabled

isFloatingBallEnabled(): boolean

Checks whether the device supports floating balls.

**System capability**: SystemCapability.Window.SessionManager

**Return value**

| Type| Description|
|------------|------------|
| boolean  | Check result for the support of floating balls. **true** if supported, **false** otherwise.|

**Example**

```ts
let enable: boolean = floatingBall.isFloatingBallEnabled();
console.info('Floating ball enabled is: ' + enable);
```

## floatingBall.create

create(config: FloatingBallConfiguration): Promise&lt;FloatingBallController&gt;

Creates a floating ball controller. This API uses a promise to return the result.

**System capability**: SystemCapability.Window.SessionManager

**Device behavior differences**: This API can be properly called on phones and tablets. If it is called on other device types, error code 801 is returned.

**Parameters**

| Name| Type| Mandatory| Description|
|------------|------------|------------|------------|
| config | [FloatingBallConfiguration](#floatingballconfiguration) | Yes| Parameters for creating the floating ball controller. This parameter cannot be empty, and **context** that is used to construct this parameter cannot be empty.|

**Return value**

| Type| Description|
|------------|------------|
| Promise&lt;[FloatingBallController](#floatingballcontroller)&gt; | Promise used to return the floating ball controller.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
|------------|------------|
| 801 | Capability not supported.Failed to call the API due to limited device capabilities. |
| 1300019 | Wrong parameters for operating the floating ball. |
| 1300023 | Floating ball internal error. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';

let floatingBallController: floatingBall.FloatingBallController | undefined = undefined;
// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let ctx = this.getUIContext().getHostContext() as common.UIAbilityContext; 
let config: floatingBall.FloatingBallConfiguration = {
  context: ctx,
};
try {
  floatingBall.create(config).then((data: floatingBall.FloatingBallController) => {
    floatingBallController = data;
    console.info(`Succeeded in creating floating ball controller. Data: ${data}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to create floating ball controller. Cause:${err.code}, message:${err.message}`);
  });
} catch(e) {
  console.error(`Failed to create floating ball controller. Cause:${e.code}, message:${e.message}`);
}
```

## FloatingBallConfiguration

Describes the parameters for creating a floating ball controller.

**System capability**: SystemCapability.Window.SessionManager

| Name| Type| Read-Only| Optional| Description|
|------------|------------|------------|------------|------------|
| context | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md) | No| No| Context environment.|

## FloatingBallController

Implements a floating ball controller instance, which is used to start, update, and stop floating balls, and register callbacks.

Before calling any of the following APIs, you must use [floatingBall.create()](#floatingballcreate) to create a floating ball controller instance.

**System capability**: SystemCapability.Window.SessionManager

### startFloatingBall

startFloatingBall(params: FloatingBallParams): Promise&lt;void&gt;

Starts the floating ball. This API uses a promise to return the result.

**Required permissions**: ohos.permission.USE_FLOAT_BALL

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name| Type| Mandatory| Description|
|------------|------------|------------|------------|
| params | [FloatingBallParams](#floatingballparams) | Yes| Parameters for starting the floating ball.|

**Return value**

| Type| Description|
|------------|------------|
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
|------------|------------|
| 201 | Permission verification failed, usually returned by VerifyAccessToken. |
| 1300019 | Wrong parameters for operating the floating ball. |
| 1300020 | Failed to create the floating ball window. |
| 1300021 | Failed to start multiple floating ball windows. |
| 1300022 | Repeated floating ball operation. |
| 1300023 | Floating ball internal error. |
| 1300024 | The floating ball window state is abnormal. |
| 1300025 | The floating ball state does not support this operation. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let startParams: floatingBall.FloatingBallParams = {
  template: floatingBall.FloatingBallTemplate.EMPHATIC,
  title: 'title',
  content: 'content'
};
try {
  floatingBallController.startFloatingBall(startParams).then(() => {
    console.info('Succeeded in starting floating ball.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to start floating ball. Cause:${err.code}, message:${err.message}`);
  });
} catch(e) {
  console.error(`Failed to start floating ball. Cause:${e.code}, message:${e.message}`);
}
```

### updateFloatingBall

updateFloatingBall(params: FloatingBallParams): Promise&lt;void&gt;

Updates the floating ball. This API uses a promise to return the result.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name| Type| Mandatory| Description|
|------------|------------|------------|------------|
| params | [FloatingBallParams](#floatingballparams) | Yes| Parameters for updating the floating ball.|

**Return value**

| Type| Description|
|------------|------------|
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID| Error Message|
|------------|------------|
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. |
| 1300019 | Wrong parameters for operating the floating ball. |
| 1300023 | Floating ball internal error. |
| 1300024 | The floating ball window state is abnormal. |
| 1300025 | The floating ball state does not support this operation. |
| 1300027 | When updating the floating ball, the template type cannot be changed. |
| 1300028 | Updating static template-based floating balls is not supported. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let updateParams: floatingBall.FloatingBallParams = {
  template: floatingBall.FloatingBallTemplate.EMPHATIC,
  title: 'title2',
  content: 'content2'
};
try {
  floatingBallController.updateFloatingBall(updateParams).then(() => {
    console.info('Succeeded in updating floating ball.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to update floating ball. Cause:${err.code}, message:${err.message}`);
  });
} catch(e) {
  console.error(`Failed to update floating ball. Cause:${e.code}, message:${e.message}`);
}
```

### stopFloatingBall

stopFloatingBall(): Promise&lt;void&gt;

Stops the floating ball. This API uses a promise to return the result.

**System capability**: SystemCapability.Window.SessionManager

**Return value**

| Type| Description|
|------------|------------|
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID| Error Message|
|------------|------------|
| 1300022 | Repeated floating ball operation. |
| 1300023 | Floating ball internal error. |
| 1300024 | The floating ball window state is abnormal. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

floatingBallController.stopFloatingBall().then(() => {
  console.info('Succeeded in stopping floating ball.');
}).catch((err: BusinessError) => {
  console.error(`Failed to stop floating ball. Cause:${err.code}, message:${err.message}`);
});
```

### on('stateChange')

on(type: 'stateChange', callback: Callback&lt;FloatingBallState&gt;): void

Registers a listener for lifecycle state changes of the floating ball. To prevent memory leaks, remember to unregister the listener when it is no longer needed.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name| Type| Mandatory| Description|
|------------|------------|------------|------------|
| type | string | Yes| Event type. The event **'stateChange'** is triggered when the floating ball lifecycle state changes.|
| callback | Callback&lt;[FloatingBallState](#floatingballstate)&gt; | Yes| Callback used to return the floating ball lifecycle state.|

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID| Error Message|
|------------|------------|
| 1300019 | Wrong parameters for operating the floating ball. |
| 1300022 | Repeated floating ball operation. |
| 1300023 | Floating ball internal error. |
| 1300024 | The floating ball window state is abnormal. |

**Example**

```ts
let onStateChange = (state: floatingBall.FloatingBallState) => {
  console.info('Floating ball stateChange: ' + state);
};
try {
  floatingBallController.on('stateChange', onStateChange);
} catch(e) {
  console.error(`Failed to on stateChange floating ball. Cause:${e.code}, message:${e.message}`);
}
```

### off('stateChange')

off(type: 'stateChange', callback?: Callback&lt;FloatingBallState&gt;): void

Unregisters the listener for lifecycle state changes of the floating ball.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name| Type| Mandatory| Description|
|------------|------------|------------|------------|
| type | string | Yes| Event type. The event **'stateChange'** is triggered when the floating ball lifecycle state changes.|
| callback | Callback&lt;[FloatingBallState](#floatingballstate)&gt; | No| Callback used to return the floating ball lifecycle state. If a value is passed in, the corresponding subscription is canceled. If no value is passed in, all subscriptions to the specified event are canceled.|

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID| Error Message|
|------------|------------|
| 1300019 | Wrong parameters for operating the floating ball. |
| 1300023 | Floating ball internal error. |
| 1300024 | The floating ball window state is abnormal. |

**Example**

```ts
let onStateChange = (state: floatingBall.FloatingBallState) => {
  console.info('Floating ball stateChange: ' + state);
};
try {
  floatingBallController.off('stateChange', onStateChange);
} catch(e) {
  console.error(`Failed to off stateChange floating ball. Cause:${e.code}, message:${e.message}`);
}
```

### on('click')

on(type: 'click', callback: Callback&lt;void&gt;): void

Registers a listener for click events of the floating ball. To prevent memory leaks, remember to unregister the listener when it is no longer needed.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name| Type| Mandatory| Description|
|------------|------------|------------|------------|
| type | string | Yes| Event type. The event **'click'** is triggered when the floating ball is tapped.|
| callback | Callback&lt;void&gt; | Yes| Callback invoked when the floating ball is tapped. It does not return any parameter.|

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID| Error Message|
|------------|------------|
| 1300019 | Wrong parameters for operating the floating ball. |
| 1300022 | Repeated floating ball operation. |
| 1300023 | Floating ball internal error. |
| 1300024 | The floating ball window state is abnormal. |

**Example**

```ts
let onClick = () => {
  console.info('Floating ball onClick');
};
try {
  floatingBallController.on('click', onClick);
} catch(e) {
  console.error(`Failed to on click floating ball. Cause:${e.code}, message:${e.message}`);
}
```

### off('click')

off(type: 'click', callback?: Callback&lt;void&gt;): void

Unregisters the listener for click events of the floating ball.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name| Type| Mandatory| Description|
|------------|------------|------------|------------|
| type | string | Yes| Event type. The event **'click'** is triggered when the floating ball is tapped.|
| callback | Callback&lt;void&gt; | No| Callback invoked when the floating ball is tapped. It does not return any parameter. If a value is passed in, the corresponding subscription is canceled. If no value is passed in, all subscriptions to the specified event are canceled.|

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID| Error Message|
|------------|------------|
| 1300019 | Wrong parameters for operating the floating ball. |
| 1300023 | Floating ball internal error. |
| 1300024 | The floating ball window state is abnormal. |

**Example**

```ts
let onClick = () => {
  console.info('Floating ball onClick');
};
try {
  floatingBallController.off('click', onClick);
} catch(e) {
  console.error(`Failed to off click floating ball. Cause:${e.code}, message:${e.message}`);
}
```

### getFloatingBallWindowInfo

getFloatingBallWindowInfo(): Promise&lt;FloatingBallWindowInfo&gt;

Obtains the floating ball window information. This API uses a promise to return the result.

**System capability**: SystemCapability.Window.SessionManager

**Return value**

| Type| Description|
|------------|------------|
| Promise&lt;[FloatingBallWindowInfo](#floatingballwindowinfo)&gt; | Promise used to return the floating ball window information.|

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID| Error Message|
|------------|------------|
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. |
| 1300023 | Floating ball internal error. |
| 1300024 | The floating ball window state is abnormal. |
| 1300025 | The floating ball state does not support this operation. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

floatingBallController.getFloatingBallWindowInfo().then((data: floatingBall.FloatingBallWindowInfo) => {
  console.info('Succeeded in getting floating ball window info. Info: ' + JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.error(`Failed to get floating ball window info. Cause code: ${err.code}, message: ${err.message}`);
});
```

### restoreMainWindow

restoreMainWindow(want: Want): Promise&lt;void&gt;

Restores the main window of the application and loads the specified page. This API can be called only after the floating ball is tapped. This API uses a promise to return the result.

**Required permissions**: ohos.permission.USE_FLOAT_BALL

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name| Type| Mandatory| Description|
|------------|------------|------------|------------|
| want | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes| Want used for loading the specified page.|

**Return value**

| Type| Description|
|------------|------------|
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
|------------|------------|
| 201 | Permission verification failed, usually returned by VerifyAccessToken. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. |
| 1300019 | Wrong parameters for operating the floating ball. |
| 1300023 | Floating ball internal error. |
| 1300024 | The floating ball window state is abnormal. |
| 1300025 | The floating ball state does not support this operation. |
| 1300026 | Failed to restore the main window. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { Want } from '@kit.AbilityKit';

let want: Want = {
  bundleName: 'xxx.xxx.xxx',
  abilityName: 'EntryAbility'
};
try {
  floatingBallController.restoreMainWindow(want).then(() => {
    console.info('Succeeded in restoring floating ball main window.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to restore floating ball main window. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch(e) {
  console.error(`Failed to create floating ball controller. Cause:${e.code}, message:${e.message}`);
}
```

## FloatingBallParams

Describes the parameters for starting and updating the floating ball.

**System capability**: SystemCapability.Window.SessionManager

| Name| Type| Read-Only| Optional| Description|
|------------|------------|------------|------------|------------|
| template | [FloatingBallTemplate](#floatingballtemplate) | No| No| Floating ball template.|
| title | string | No| No| Title of the floating ball. It cannot be an empty string and cannot exceed 64 bytes.|
| content | string | No| Yes| Content of the floating ball. It cannot exceed 64 bytes. The default value is an empty string, and no content is displayed on the floating ball.|
| backgroundColor | string | No| Yes| Background color of the floating ball, in hexadecimal format without opacity (for example, **'#008EF5'** or **'#FF008EF5'**). If this parameter is not specified, the default background color of the system (light or dark mode) is used.|
| icon | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) | No| Yes| Icon of the floating ball. The total number of bytes of the icon pixels cannot exceed 192 KB (which is obtained through [getPixelBytesNumber](../apis-image-kit/arkts-apis-image-PixelMap.md#getpixelbytesnumber7)). The recommended size is 128 px * 128 px. Actual display may vary based on the device capability and floating ball UI style.|

## FloatingBallState

Enumerates the lifecycle states of the floating ball.

**System capability**: SystemCapability.Window.SessionManager

| Name| Value| Description|
|------------|------------|------------|
| STARTED | 1 | The floating ball is started.|
| STOPPED | 2 | The floating ball is stopped.|

## FloatingBallTemplate

Enumerates the types of the floating ball template.

**System capability**: SystemCapability.Window.SessionManager

| Name| Value| Description|
|------------|------------|------------|
| STATIC | 1 | Static layout, which provides a title and an icon. When this template is used, the **title** and **icon** parameters in **FloatingBallParams** must be passed.|
| NORMAL | 2 | Standard text layout, which provides a title and content. When this template is used, the **title** parameter in **FloatingBallParams** must be passed.|
| EMPHATIC | 3 | Emphasized text layout, which provides an icon, a title, and content. When this template is used, the **title** parameter in **FloatingBallParams** must be passed.|
| SIMPLE | 4 | Plain text layout, which provides only a title. When this template is used, the **title** parameter in **FloatingBallParams** must be passed.|

## FloatingBallWindowInfo

Describes the floating ball window information.

**System capability**: SystemCapability.Window.SessionManager

| Name| Type| Read-Only| Optional| Description|
|------------|------------|------------|------------|------------|
| windowId | number | Yes| No| ID of the floating ball window.|
