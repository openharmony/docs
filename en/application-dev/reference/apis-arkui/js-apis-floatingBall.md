# @ohos.window.floatingBall (Floating Ball Window)
<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @betafringe007-->
<!--Designer: @taoweihua-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->

This module provides essential functionalities for floating balls. It lets you check whether the device supports floating balls and create a controller to start, update, or stop them. This module is ideal for cross-application scenarios such as question search, bill records, product price comparison, order grabbing, and translation, as well as real-time market monitoring in financial apps. It displays content in a small window. The floating ball appears as a floating widget above other application, quickly showing important information.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 20. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - In versions earlier than OpenHarmony 7.0.0, the floating ball feature is supported only on tablets in non-[desktop mode](../../windowmanager/freeform-window-overview.md#desktop-mode) and on phones. Since OpenHarmony 7.0.0, the floating ball feature is supported only on phones, PCs/2-in-1 devices, and tablets.
>
> - For the system capability SystemCapability.Window.SessionManager, use [canIUse()](../common/js-apis-syscap.md#caniuse) to check whether the device supports this system capability and the corresponding APIs.

**Comparison between the floating ball and float view**:

- Similarities: Both the floating ball and [float view](js-apis-floatView.md) are special types of application auxiliary windows that can remain displayed on the foreground even after the application's main window and corresponding UIAbility transition to the background. They can be used to continue displaying the UI after the application transitions to the background.
- Differences:
  - They have different display forms: A floating ball is displayed as a small ball and is suitable for displaying key information. A float view is displayed as a small window with a relatively large display area, which can continuously display application content or provide shortcut operations.
  - The floating ball can only be displayed on the edge, while the float view does not have this restriction.
  - The floating ball template is fixed, and the UI cannot be customized for applications. The float view also has a template, and the float view is managed by the system and its UI is drawn in a unified manner. However, it provides a drawing area for applications to load specified page content.

**Linkage with the float view**:

This module can be used together with [@ohos.window.floatView](js-apis-floatView.md). After the float view controller is bound to the floating ball controller using the [floatView.bind](js-apis-floatView.md#floatviewbind) API, users can click the floating ball to expand it as a float view, and click the minimize button in the upper left corner of the float view to collapse it back as a floating ball. This allows for seamless switching between the two window forms.

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
// Check whether the current device supports the floating ball feature.
let enable: boolean = floatingBall.isFloatingBallEnabled();
console.info('Floating ball enabled is: ' + enable);
```

## floatingBall.create

create(config: FloatingBallConfiguration): Promise&lt;FloatingBallController&gt;

Creates a floating ball controller. This API uses a promise to return the result.

**System capability**: SystemCapability.Window.SessionManager

**Device behavior differences**: In versions earlier than OpenHarmony 7.0.0, this API can be called properly on tablets in non-[desktop mode](../../windowmanager/freeform-window-overview.md#desktop-mode) and phones. If it is called on other devices and tablets in desktop mode, error code 801 is returned. Since OpenHarmony 7.0.0, this API can be properly called on phones, PCs/2-in-1 devices, and tablets. If it is called on other device types, error code 801 is returned.

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

// Declare the floating ball controller instance.
let floatingBallController: floatingBall.FloatingBallController | undefined = undefined;
// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let ctx = this.getUIContext().getHostContext() as common.UIAbilityContext; 
// Configure the floating ball controller.
let config: floatingBall.FloatingBallConfiguration = {
  context: ctx,
};
try {
  // Create a floating ball controller.
  floatingBall.create(config).then((data: floatingBall.FloatingBallController) => {
    // Save the controller instance.
    floatingBallController = data;
    console.info(`Succeeded in creating floating ball controller. Data: ${data}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to create floating ball controller. Cause:${err.code}, message:${err.message}`);
  });
} catch (e) {
  console.error(`Failed to create floating ball controller. Cause:${e.code}, message:${e.message}`);
}
```

## FloatingBallConfiguration

Describes the parameters for creating a floating ball controller.

**System capability**: SystemCapability.Window.SessionManager

| Name| Type| Read-Only| Optional| Description|
|------------|------------|------------|------------|------------|
| context | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md) | No| No| Context, which is used to associate the main window of the application when creating a floating ball controller. This parameter cannot be left empty. Generally, the **UIAbilityContext** object is passed.|

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
| params | [FloatingBallParams](#floatingballparams) | Yes| Parameters for starting the floating ball, which are used to set the title, content, or background color of the floating ball.|

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
| 1300034 | This operation conflicts with other floating windows. Possible cause: App has already started float view.<br>Applicable versions: 26.0.0+|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Set the parameters for starting the floating ball.
let startParams: floatingBall.FloatingBallParams = {
  template: floatingBall.FloatingBallTemplate.EMPHATIC,
  title: 'title',
  content: 'content'
};
try {
  // Start the floating ball.
  floatingBallController.startFloatingBall(startParams).then(() => {
    console.info('Succeeded in starting floating ball.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to start floating ball. Cause:${err.code}, message:${err.message}`);
  });
} catch (e) {
  console.error(`Failed to start floating ball. Cause:${e.code}, message:${e.message}`);
}
```

### updateFloatingBall

updateFloatingBall(params: FloatingBallParams): Promise&lt;void&gt;

Updates the floating ball. This API uses a promise to return the result. This API can be called to update the floating ball only after [startFloatingBall()](#startfloatingball) is called to start the floating ball.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name| Type| Mandatory| Description|
|------------|------------|------------|------------|
| params | [FloatingBallParams](#floatingballparams) | Yes| Parameters for updating the floating ball, which are used to update the title, content, or background color of the floating ball. When this API is called to update the floating ball, the **template** field (template type) cannot be modified.|

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

// Set the parameters for updating the floating ball.
let updateParams: floatingBall.FloatingBallParams = {
  template: floatingBall.FloatingBallTemplate.EMPHATIC,
  title: 'title2',
  content: 'content2'
};
try {
  // Update the floating ball.
  floatingBallController.updateFloatingBall(updateParams).then(() => {
    console.info('Succeeded in updating floating ball.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to update floating ball. Cause:${err.code}, message:${err.message}`);
  });
} catch (e) {
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

// Stop the floating ball.
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
// Define the callback function for status changes.
let onStateChange = (state: floatingBall.FloatingBallState) => {
  console.info('Floating ball stateChange: ' + state);
};
try {
  // Register the callback for listening to floating ball state changes.
  floatingBallController.on('stateChange', onStateChange);
} catch (e) {
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
// Define the callback function for status changes (the callback function must be the same as that registered).
let onStateChange = (state: floatingBall.FloatingBallState) => {
  console.info('Floating ball stateChange: ' + state);
};
try {
  // Unregister the callback for listening to floating ball state changes.
  floatingBallController.off('stateChange', onStateChange);
} catch (e) {
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
// Define the click event callback function.
let onClick = () => {
  console.info('Floating ball onClick');
};
try {
  // Register the callback for listening to click events of the floating ball.
  floatingBallController.on('click', onClick);
} catch (e) {
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
// Define the callback function for the click event (the callback function must be the same as that registered).
let onClick = () => {
  console.info('Floating ball onClick');
};
try {
  // Unregister the callback for listening to click events of the floating ball.
  floatingBallController.off('click', onClick);
} catch (e) {
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

// Obtain the window information of the floating ball.
floatingBallController.getFloatingBallWindowInfo().then((data: floatingBall.FloatingBallWindowInfo) => {
  console.info('Succeeded in getting floating ball window info. Info: ' + JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.error(`Failed to get floating ball window info. Cause code: ${err.code}, message: ${err.message}`);
});
```

### restoreMainWindow

restoreMainWindow(want: Want): Promise&lt;void&gt;

Restores the main window of the application and loads the specified page. This API uses a promise to return the result. This API can be called only after the floating ball is tapped. If the application has the **ohos.permission.AUTO_RESTORE_MAIN_WINDOW** permission, this API can be called directly without tapping the floating ball.

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
| 1300026 | Failed to restore the main window. Possible causes: <br>1. Invalid parameter. The provided bundleName does not match the caller's application bundleName.<br>2. The application lacks the ohos.permission.AUTO_RESTORE_MAIN_WINDOW permission, and no user interaction (click) on the floating ball has occurred. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { Want } from '@kit.AbilityKit';

// Set the Want parameter of the main window to be restored.
let want: Want = {
  bundleName: 'xxx.xxx.xxx',
  abilityName: 'EntryAbility'
};
try {
  // Restore the main window of the application and load the specified page.
  floatingBallController.restoreMainWindow(want).then(() => {
    console.info('Succeeded in restoring floating ball main window.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to restore floating ball main window. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (e) {
  console.error(`Failed to restore floating ball main window. Cause:${e.code}, message:${e.message}`);
}
```

### setFloatingBallVisibilityInApp<sup>24+</sup>

setFloatingBallVisibilityInApp(isVisible: boolean): Promise&lt;void&gt;

Sets whether the floating ball is visible in the application. This API uses a promise to return the result.
- When the application is in the multitasking screen (the [lifecycle state](../../windowmanager/window-lifecycle.md#lifecycle-states-of-an-apps-main-window) is **PAUSED**), the floating ball is invisible.
- By default (when this API is not called) or when this API is called with the value **true** passed in, the floating ball is visible except on the recent tasks screen.
- When this API is called with the value **false** passed in, the floating ball is invisible when the application is in the foreground (the [lifecycle state](../../windowmanager/window-lifecycle.md#lifecycle-states-of-an-apps-main-window) is **SHOWN** or **RESUMED**) and is visible when the application is in the background (the [lifecycle state](../../windowmanager/window-lifecycle.md#lifecycle-states-of-an-apps-main-window) is **HIDDEN**).

**System capability**: SystemCapability.Window.SessionManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name| Type| Mandatory| Description|
|------------|------------|------------|------------|
| isVisible | boolean | Yes| **true** indicates that the floating ball is visible in the application, and **false** indicates the opposite.|

**Return value**

| Type| Description|
|------------|------------|
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID| Error Message|
|------------|------------|
| 1300003 | This window manager service works abnormally. Possible cause: Internal IPC error. |
| 1300023 | Floating ball internal error. Possible cause: The floating ball controller is null. |
| 1300024 | The floating ball window state is abnormal. Possible causes: The floating ball window has not been created or has been destroyed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Set the floating ball to be invisible in the application.
floatingBallController?.setFloatingBallVisibilityInApp(false).then(() => {
  console.info('Succeeded in setting floating ball visibility.');
}).catch((err: BusinessError) => {
  console.error(`Failed to set floating ball visibility. Cause code: ${err.code}, message: ${err.message}`);
});
```

### onDestroy

onDestroy(callback: Callback&lt;string&gt;): void

Registers a callback to listen for floating ball destruction events. When a floating ball is destroyed, the callback function receives the string indicating the destruction reason. To prevent memory leaks, call [offDestroy](#offdestroy) to unregister the callback when it is no longer needed.

**System capability**: SystemCapability.Window.SessionManager

**Model restriction**: This API can be used only in the stage model.

**Since**: 26.0.0

**Parameters**

| Name| Type| Mandatory| Description|
|------------|------------|------------|------------|
| callback | Callback&lt;string&gt; | Yes| Callback used to the reason why the floating ball is stopped. The stop reasons include:<br>- **"APP_STOP"**: The application proactively stops the floating ball.<br>- **"DUMPSTER_STOP"**: The floating ball is dragged to the trash can.<br>- **"LONG_PRESS_SINGLE_STOP"**: A single floating ball is long-pressed.<br>- **"LONG_PRESS_ALL_STOP"**: All floating balls are long-pressed.<br>- **"MAIN_WINDOW_DESTROY_STOP"**: The main window associated with the context is destroyed.<br>- **"SQUEEZE"**: The number of floating balls on the device exceeds the upper limit, and the floating ball is stopped by other floating balls.<br>- **"FLOAT_VIEW_STOP"**: After being bound to a float view, the floating ball stops with the float view.<br>- **"STOP_IN_SIDEBAR"**: The floating ball is stopped on the sidebar.|

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID| Error Message|
|------------|------------|
| 1300019 | Wrong parameters for operating the floating ball. Possible cause: Callback is null or not callable. |
| 1300022 | Repeated floating ball operation. |
| 1300023 | Floating ball internal error. Possible cause: System error, such as a null pointer, insufficient memory. |
| 1300024 | The floating ball window state is abnormal. Possible cause: The floating ball controller has been destroyed. |

**Example**

```ts
// Define the callback function for the destruction event.
let onDestroy = (reason: string) => {
  console.info('Floating ball has destroyed, reason: ' + reason);
};
try {
  // Register the callback for listening to floating ball destruction events.
  floatingBallController?.onDestroy(onDestroy);
} catch (e) {
  console.error(`Failed to onDestroy floating ball. Cause:${e.code}, message:${e.message}`);
}
```

### offDestroy

offDestroy(callback?: Callback&lt;string&gt;): void

Unregisters the callback to listen for floating ball destruction events.

**System capability**: SystemCapability.Window.SessionManager

**Model restriction**: This API can be used only in the stage model.

**Since**: 26.0.0

**Parameters**

| Name| Type| Mandatory| Description|
|------------|------------|------------|------------|
| callback | Callback&lt;string&gt; | No| Callback to unregister. If a value is passed in, the corresponding callback is unregistered. If no value is passed in, all callbacks associated with the floating ball destruction events are unregistered.|

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID| Error Message|
|------------|------------|
| 1300019 | Wrong parameters for operating the floating ball. Possible cause: Callback is null or not callable. |
| 1300023 | Floating ball internal error. Possible cause: System error, such as a null pointer, insufficient memory. |
| 1300024 | The floating ball window state is abnormal. Possible cause: The floating ball controller has been destroyed. |

**Example**

```ts
// Define the callback function for the destruction event (the callback function must be the same as that registered).
let onDestroy = (reason: string) => {
  console.info('Floating ball has destroyed, reason: ' + reason);
};
try {
  // Unregister the callback for listening to floating ball destruction events.
  floatingBallController?.offDestroy(onDestroy);
} catch (e) {
  console.error(`Failed to offDestroy floating ball. Cause:${e.code}, message:${e.message}`);
}
// Unregister all callbacks.
try {
  floatingBallController?.offDestroy();
} catch (e) {
  console.error(`Failed to offDestroy all listeners. Cause:${e.code}, message:${e.message}`);
}
```

## FloatingBallParams

Describes the parameters for starting and updating the floating ball.

**System capability**: SystemCapability.Window.SessionManager

| Name| Type| Read-Only| Optional| Description|
|------------|------------|------------|------------|------------|
| template | [FloatingBallTemplate](#floatingballtemplate) | No| No| Floating ball template. Different templates have different requirements on other parameters. For details, see the enumeration description of **FloatingBallTemplate**.|
| title | string | No| No| Title of the floating ball. It cannot be an empty string and cannot exceed 64 bytes. If an empty string or a string longer than 64 bytes is passed, error code [1300019](errorcode-window.md#1300019-floating-ball-parameter-verification-error) is returned.|
| content | string | No| Yes| Content of the floating ball. It cannot exceed 64 bytes. The default value is an empty string, and no content is displayed on the floating ball. If the value exceeds 64 bytes, error code [1300019](errorcode-window.md#1300019-floating-ball-parameter-verification-error) is returned.|
| backgroundColor | string | No| Yes| Background color of the floating ball, in hexadecimal format without transparency (for example, **'#008EF5'** or **'#FF008EF5'**). If the format is incorrect, error code [1300019](errorcode-window.md#1300019-floating-ball-parameter-verification-error) is returned. If this parameter is not specified, the default background color of the system (light or dark mode) is used.|
| titleColor | string | No| Yes| Title text color of the floating ball, in hexadecimal format without the alpha channel (for example, **'#008EF5'** or **'#FF008EF5'**). If this parameter is not specified, the color is automatically filled based on the background color. If the background color is light, the text color is filled with black (**'#E5000000'**). If the background color is dark, the text color is filled with white (**'#E5FFFFFF'**). When setting this attribute, you must also set **backgroundColor**. Otherwise, error code [1300019](errorcode-window.md#1300019-floating-ball-parameter-verification-error) will be returned.<br>**Since**: 26.0.0<br>**Model restriction**: This API can be used only in the stage model.|
| contentColor | string | No| Yes| Content text color of the floating ball, in hexadecimal format without the alpha channel (for example, **'#008EF5'** or **'#FF008EF5'**). If this parameter is not specified, the color is automatically filled based on the background color. If the background color is light, the text color is filled with black (**'#99000000'**). If the background color is dark, the text color is filled with white (**'#99FFFFFF'**). When setting this attribute, you must also set **backgroundColor**. Otherwise, error code [1300019](errorcode-window.md#1300019-floating-ball-parameter-verification-error) will be returned.<br>**Since**: 26.0.0<br>**Model restriction**: This API can be used only in the stage model.|
| icon | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) | No| Yes| Icon of the floating ball. The total number of icon pixel bytes cannot exceed 192 KB (which is obtained through [getPixelBytesNumber](../apis-image-kit/arkts-apis-image-PixelMap.md#getpixelbytesnumber7)). If the total number exceeds 192 KB, error code [1300019](errorcode-window.md#1300019-floating-ball-parameter-verification-error) is returned. The recommended size is 128 px * 128 px. Actual display may vary based on the device capability and floating ball UI style.|
| textUpdateAnimationType | [FloatingBallTextUpdateAnimationType](#floatingballtextupdateanimationtype) | No| Yes| Animation type used when the floating ball text is updated. The default value is **FloatingBallTextUpdateAnimationType.ANIMATION_NONE**.<br>**Since**: 26.0.0<br>**Model restriction**: This API can be used only in the stage model.|

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

## FloatingBallTextUpdateAnimationType

Enumerates the animation types used when the floating ball text is updated.

**System capability**: SystemCapability.Window.SessionManager

**Model restriction**: This API can be used only in the stage model.

**Since**: 26.0.0

| Name| Value| Description|
|------------|------------|------------|
| ANIMATION_NONE | 0 | No animation.|
| ANIMATION_OPACITY | 1 | Fade-in and fade-out animation.|
