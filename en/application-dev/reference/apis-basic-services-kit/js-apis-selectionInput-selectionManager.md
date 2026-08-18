# @ohos.selectionInput.selectionManager (Word Selection Management)

<!--Kit: Basic Services Kit-->
<!--Subsystem: SelectionInput-->
<!--Owner: @no86-->
<!--Designer: @no86-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @fang-jinxu-->
<!-- md-trans-meta sourceCommit=77a500da4d34f4098d37f8dafb7fd80dec5985ed translatedAt=2026-08-04T10:39:15.500Z pushedAt=2026-08-05T11:50:08.570Z -->

This module provides word selection management capabilities, including creating, displaying, moving, hiding, and destroying panels, listening for word selection events using a mouse or touchpad, and retrieving the selected text. The typical usage process is as follows:

1. Call [on('selectionCompleted')](#selectionmanageronselectioncompleted) to subscribe to the selection completion event.

2. In the callback, call [getSelectionContent](#getselectioncontent) to obtain the selected text.

3. Call [createPanel](#createpanel) to create a word selection panel.

4. Call [setUiContent](#setuicontent) to load the page content.

5. Call [moveToGlobalDisplay](#movetoglobaldisplay) to move the panel to the specified position.

6. Call [show](#show) to display the panel.

7. Call [destroyPanel](#destroypanel) to destroy the panel.

8. Call [off('selectionCompleted')](#selectionmanageroffselectioncompleted) to unsubscribe from the selection completion event.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 24. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - This module is supported only on PCs/2-in-1 devices. You can use **canIUse('SystemCapability.SelectionInput.Selection')** to check whether the current device supports this function.
> - APIs of this module can be called only by apps that integrate the extension ability for word selection. For details about how to implement the extension ability for word selection, see [SelectionExtensionAbility](js-apis-selectionInput-selectionExtensionAbility.md).

## Modules to Import

```ts
import { selectionManager } from '@kit.BasicServicesKit';
```

## selectionManager

**System capability:** SystemCapability.SelectionInput.Selection

**Model restriction:** This API can be used only in the stage model.

### selectionManager.on('selectionCompleted')

on(type: 'selectionCompleted', callback: Callback\<SelectionInfo>): void

Subscribes to the word selection completion event. This API is used together with [off('selectionCompleted')](#selectionmanageroffselectioncompleted). [off('selectionCompleted')](#selectionmanageroffselectioncompleted) is used to unsubscribe from the event.

**System capability:** SystemCapability.SelectionInput.Selection

**Model restriction:** This API can be used only in the stage model.

**Parameters**

| Name  | Type                                       | Mandatory| Description                                          |
| -------- | ------------------------------------------- | ---- | ---------------------------------------------- |
| type     | string                                      | Yes  | Event type, which is **'selectionCompleted'**.|
| callback | Callback\<[SelectionInfo](#selectioninfo)> | Yes | Callback used to return [SelectionInfo](#selectioninfo). This callback is triggered only when the user selects text using the mouse or touchpad (by double-clicking, triple-clicking, or sliding the left mouse button) and then presses **Ctrl**. |

**Error codes**

For details about the following error codes, see [Word Selection Error Codes](errorcode-selection.md). For details about other common error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code  | Error Message                      |
| ---------- | ----------------------------- |
| 33600003   | The application calling the API does not match the application selected in the system settings. |

**Example**

```ts
import { selectionManager } from '@kit.BasicServicesKit';

try {
  // Subscribe to the word selection complete event.
  selectionManager.on('selectionCompleted', (info: selectionManager.SelectionInfo) => {
    console.info('Enter the callback function.');
  });
} catch (err) {
  console.error(`Failed to register selectionCompleted callback. Error code: ${err.code}, error message: ${err.message}`);
}
```

### selectionManager.off('selectionCompleted')

off(type: 'selectionCompleted', callback?: Callback\<SelectionInfo>): void

Unsubscribes from the word selection completion event. This API is used together with [on('selectionCompleted')](#selectionmanageronselectioncompleted).

**System capability:** SystemCapability.SelectionInput.Selection

**Model restriction:** This API can be used only in the stage model.

**Parameters**

| Name  | Type                                       | Mandatory| Description                                                        |
| -------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                      | Yes   | Type of the event to unsubscribe from. The value is fixed to **'selectionCompleted'**.               |
| callback | Callback\<[SelectionInfo](#selectioninfo)> | No   | Callback to be unregistered, which the callback instance registered using **on**. If this parameter is not specified, this API unregisters all callbacks for the specified type. |

**Example**

```ts
import { selectionManager } from '@kit.BasicServicesKit';

// Define a callback used to listen for the word selection completion event, which will be registered and unregistered.
let selectionChangeCallback = (info: selectionManager.SelectionInfo) => {
  console.info('Enter the callback function.');
};

// Register a callback used to listen for the word selection completion event, preparing for subsequent unsubscription.
selectionManager.on('selectionCompleted', selectionChangeCallback);
try {
  // Unsubscribe from the word selection completion event.
  selectionManager.off('selectionCompleted', selectionChangeCallback);
} catch (err) {
  console.error(`Failed to unregister selectionCompleted. Error code: ${err.code}, error message: ${err.message}`);
}
```

### getSelectionContent()

getSelectionContent(): Promise\<string>

Obtains the content of the selected text. This API uses a promise to return the result. This API must be called in the [on('selectionCompleted')](#selectionmanageronselectioncompleted) callback and is valid only after the word selection completion event is triggered.

**System capability:** SystemCapability.SelectionInput.Selection

**Model restriction:** This API can be used only in the stage model.

**Return value**

| Type  | Description                                                                |
| ------- | ------------------------------------------------------------------ |
| Promise\<string> | Promise used to return the content of the selected text. |

**Error codes**

For details about the following error codes, see [Word Selection Error Codes](errorcode-selection.md). For details about other common error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code  | Error Message                      |
| ---------- | ----------------------------- |
| 33600001   | Selection service invocation exception. |
| 33600004   | The interface is called too frequently. |
| 33600005   | The interface is called at the wrong time. |
| 33600006   | The current application is prohibited from accessing content. |
| 33600007   | The length of selected content is out of range. |
| 33600008   | Getting the selected content times out. |

**Example**

```ts
import { selectionManager } from '@kit.BasicServicesKit';

// Subscribe to the word selection complete event and obtain the selected text in the callback.
selectionManager.on('selectionCompleted', async (info: selectionManager.SelectionInfo) => {
  try {
    // Obtain the content of the selected text.
    let content = await selectionManager.getSelectionContent();
    console.info(`Succeeded in getting selection content: ${content}`);
  } catch (err) {
    console.error(`Failed to get selection content. Error code: ${err.code}, error message: ${err.message}`);
  }
});
```

### createPanel

createPanel(ctx: Context, info: PanelInfo): Promise\<Panel>

Creates a word selection panel, which is used to display the service-related operation UI or text processing result. After the panel is used, call [destroyPanel](#destroypanel) to destroy the panel and release resources. This API uses a promise to return the result.

Only one [MENU_PANEL](js-apis-selectionInput-selectionPanel.md#paneltype) and one [MAIN_PANEL](js-apis-selectionInput-selectionPanel.md#paneltype) can be created for one word selection application.

**System capability:** SystemCapability.SelectionInput.Selection

**Model restriction:** This API can be used only in the stage model.

**Parameters**

| Name  | Type       | Mandatory| Description                    |
| ------- | ----------- | ---- | ------------------------ |
| ctx     | [Context](../apis-ability-kit/js-apis-inner-application-context.md#context) | Yes   | Context that the current word selection panel depends on, which is provided by **SelectionExtensionAbility**. |
| info    | [PanelInfo](js-apis-selectionInput-selectionPanel.md#panelinfo)   | Yes   | Configuration information of the word selection panel, which is used to specify the panel type, position, width, and height. Only one **MENU_PANEL** and one **MAIN_PANEL** can be created for one word selection app. |

**Return value**

| Type  | Description                                                                |
| ------- | ------------------------------------------------------------------ |
| Promise\<[Panel](#panel)> | Promise used to return the **Panel** object created, which can be used to set, display, hide, and move the panel, and subscribe to events. |

**Error codes**

For details about the following error codes, see [Word Selection Error Codes](errorcode-selection.md). For details about other common error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code  | Error Message                      |
| ---------- | ----------------------------- |
| 33600001   | Selection service exception. |
| 33600003   | The application calling the API does not match the application selected in the system settings. |

**Example**

```ts
import { selectionManager, SelectionExtensionAbility, PanelInfo, PanelType, BusinessError } from '@kit.BasicServicesKit';
import { rpc } from '@kit.IPCKit';
import { Want } from '@kit.AbilityKit';

class SelectionAbilityStub extends rpc.RemoteObject {
  constructor(descriptor: string) {
    super(descriptor);
  }
  onRemoteMessageRequest(
    code: number,
    data: rpc.MessageSequence,
    reply: rpc.MessageSequence,
    options: rpc.MessageOption
  ): boolean | Promise<boolean> {
    return true;
  }
}

class ServiceExtAbility extends SelectionExtensionAbility {
  onConnect(want: Want): rpc.RemoteObject {
    // Configure the word selection panel, including the panel type, position, and size.
    let panelInfo: PanelInfo = {
      panelType: PanelType.MENU_PANEL,
      x: 0,
      y: 0,
      width: 500,
      height: 200
    };
    let selectionPanel: selectionManager.Panel | undefined = undefined;
    // Create a word selection panel. Obtain this.context by inheriting SelectionExtensionAbility.
    selectionManager.createPanel(this.context, panelInfo)
      .then((panel: selectionManager.Panel) => {
        selectionPanel = panel;
        console.info('Succeed in creating panel.');
      }).catch((err: BusinessError) => {
        console.error(`Failed to create panel. Error code: ${err.code}, error message: ${err.message}`);
    });
    return new SelectionAbilityStub('remote');
  }
}
export default ServiceExtAbility;
```

### destroyPanel

destroyPanel(panel: Panel): Promise\<void>

Destroys the word selection panel. This API is used together with [createPanel](#createpanel) to destroy the panel object created by **createPanel()**. This API uses a promise to return the result.

**System capability:** SystemCapability.SelectionInput.Selection

**Model restriction:** This API can be used only in the stage model.

**Parameters**

| Name  | Type       | Mandatory| Description                    |
| ---------| ----------- | ---- | ------------------------ |
| panel    | [Panel](#panel)       | Yes  | Word selection panel to destroy.     |

**Return value**

| Type   | Description                                                                |
| ------- | -------------------------------------------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the following error codes, see [Word Selection Error Codes](errorcode-selection.md). For details about other common error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code  | Error Message                      |
| ---------- | ----------------------------- |
| 33600001   | Selection service exception. |

**Example**

```ts
import { selectionManager, SelectionExtensionAbility, PanelInfo, PanelType, BusinessError } from '@kit.BasicServicesKit';
import { rpc } from '@kit.IPCKit';
import { Want } from '@kit.AbilityKit';

class SelectionAbilityStub extends rpc.RemoteObject {
  constructor(descriptor: string) {
    super(descriptor);
  }
  onRemoteMessageRequest(
    code: number,
    data: rpc.MessageSequence,
    reply: rpc.MessageSequence,
    options: rpc.MessageOption
  ): boolean | Promise<boolean> {
    return true;
  }
}

class ServiceExtAbility extends SelectionExtensionAbility {
  onConnect(want: Want): rpc.RemoteObject {
    // Configure the word selection panel, including the panel type, position, and size.
    let panelInfo: PanelInfo = {
      panelType: PanelType.MENU_PANEL,
      x: 0,
      y: 0,
      width: 500,
      height: 200
    };
    let selectionPanel: selectionManager.Panel | undefined = undefined;
    // Create a word selection panel first. Obtain a Panel instance to be destroyed later. Obtain this.context by inheriting SelectionExtensionAbility.
    selectionManager.createPanel(this.context, panelInfo)
      .then((panel: selectionManager.Panel) => {
        console.info('Succeed in creating panel.');
        selectionPanel = panel;
        try {
          if (selectionPanel) {
            // Destroy the word selection panel.
            selectionManager.destroyPanel(selectionPanel).then(() => {
              console.info('Succeed in destroying panel.');
            }).catch((err: BusinessError) => {
              console.error(`Failed to destroy panel. Error code: ${err.code}, error message: ${err.message}`);
            });
          }
        } catch (err) {
          console.error(`Failed to destroy panel. Error code: ${err.code}, error message: ${err.message}`);
        }
      }).catch((err: BusinessError) => {
        console.error(`Failed to create panel. Error code: ${err.code}, error message: ${err.message}`);
    });
    return new SelectionAbilityStub('remote');
  }
}
export default ServiceExtAbility;
```

## SelectionInfo

Defines the information of a word selection event.

**System capability:** SystemCapability.SelectionInput.Selection

**Model restriction:** This API can be used only in the stage model.

| Name     | Type| Read-Only| Optional| Description        |
| --------- | -------- | ---- | ---- | ------------ |
| selectionType | [SelectionType](#selectiontype) | No | No | Word selection types. |
| startDisplayX |number| No  | No  | X-coordinate of the screen where the word selection starts, in px.|
| startDisplayY |number| No  | No  | Y-coordinate of the screen where the word selection starts, in px.|
| endDisplayX   |number| No  | No  | X-coordinate of the screen where the word selection ends, in px.|
| endDisplayY   |number| No  | No  | Y-coordinate of the screen where the word selection ends, in px.|
| startWindowX  |number| No  | No  | X-coordinate of the window where the word selection starts, in px.|
| startWindowY  |number| No  | No  | Y-coordinate of the window where the word selection starts, in px.|
| endWindowX    |number| No  | No  | X-coordinate of the window where the word selection ends, in px.|
| endWindowY    |number| No  | No  | Y-coordinate of the window where the word selection ends, in px.|
| displayID     |number| No  | No  | ID of the screen where the window with selected words is located.|
| windowID      |number| No  | No  | ID of the window where words are selected.|
| bundleName    |string| No  | No  | Bundle name of the application where words are selected.|

## Panel

Describes a **Panel** object, which is created using [createPanel](#createpanel). This method can be used to set, display, hide, and move the panel, as well as subscribe to events. It is applicable to scenarios where a custom operation UI needs to be displayed to users after word selection is complete.

**System capability:** SystemCapability.SelectionInput.Selection

**Model restriction:** This API can be used only in the stage model.

In the following APIs, you must first use [createPanel](#createpanel) to obtain a **Panel** instance, and then call the APIs using the obtained instance.

### setUiContent

setUiContent(path: string): Promise\<void>

Sets the UI content for the current word selection panel, for example, to display translation results, search suggestions, or custom action buttons. This API can be called only after a **Panel** instance is obtained by calling [createPanel](#createpanel). This API uses a promise to return the result.

**System capability:** SystemCapability.SelectionInput.Selection

**Model restriction:** This API can be used only in the stage model.

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| path | string | Yes  |  Path of the page content to be set. This path is configured in the **resources/base/profile/main_pages.json** file of the project in the stage model. The FA model is not supported.|

**Return value**

| Type  | Description                            |
| ------- | ------------------------------ |
| Promise\<void> | Promise that returns no value. |

**Error codes**

For details about the following error codes, see [Word Selection Error Codes](errorcode-selection.md). For details about other common error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code  | Error Message                      |
| ---------- | ----------------------------- |
| 33600001   | Selection service exception. |
| 33600002   | This selection window has been destroyed. |

**Example**

<!--code_no_check-->

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  // Load page content for the word selection panel. selectionPanel is a Panel instance created by createPanel.
  selectionPanel.setUiContent('pages/Index').then(() => {
    console.info('Succeeded in setting the content.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to setUiContent. Error code: ${err.code}, error message: ${err.message}`);
  });
} catch (err) {
  console.error(`Failed to setUiContent. Error code: ${err.code}, error message: ${err.message}`);
}
```

### show

show(): Promise\<void>

Shows the word selection panel. This API is used together with [hide](#hide). This API can be called only after a Panel instance is obtained by calling [createPanel](#createpanel). This API uses a promise to return the result.

**System capability:** SystemCapability.SelectionInput.Selection

**Model restriction:** This API can be used only in the stage model.

**Return value**

| Type  | Description                            |
| ------- | ------------------------------ |
| Promise\<void> | Promise that returns no value. |

**Error codes**

For details about the following error codes, see [Word Selection Error Codes](errorcode-selection.md). For details about other common error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code  | Error Message                      |
| ---------- | ----------------------------- |
| 33600001   | Selection service exception. |
| 33600002   | This selection window has been destroyed. |

**Example**

<!--code_no_check-->

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Show the word selection panel. selectionPanel is the panel instance created by createPanel.
selectionPanel.show().then(() => {
  console.info('Succeeded in showing the panel.');
}).catch((err: BusinessError) => {
  console.error(`Failed to show panel. Error code: ${err.code}, error message: ${err.message}`);
});
```

### hide

hide(): Promise\<void>

Hides the word selection panel. This API is used together with [show](#show). This API can be called only after a **Panel** instance is obtained by calling [createPanel](#createpanel). This API uses a promise to return the result. If this API is not called proactively, the panel is automatically hidden when it loses focus.

**System capability:** SystemCapability.SelectionInput.Selection

**Model restriction:** This API can be used only in the stage model.

**Return value**

| Type  | Description                            |
| ------- | ------------------------------ |
| Promise\<void> | Promise that returns no value. |

**Error codes**

For details about the following error codes, see [Word Selection Error Codes](errorcode-selection.md). For details about other common error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code  | Error Message                      |
| ---------- | ----------------------------- |
| 33600001   | Selection service exception. |
| 33600002   | This selection window has been destroyed. |

**Example**

<!--code_no_check-->

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Hide the word selection panel. selectionPanel is a Panel instance created by createPanel.
selectionPanel.hide().then(() => {
  console.info('Succeeded in hiding the panel.');
}).catch((err: BusinessError) => {
  console.error(`Failed to hide panel. Error code: ${err.code}, error message: ${err.message}`);
});
```

### startMoving

startMoving(): Promise\<void>

Sets whether the word selection panel can be dragged along with the mouse, touchpad, or touchscreen. The panel automatically stops moving after the pointer is released. This API can be called only after a **Panel** instance is obtained by calling [createPanel](#createpanel). This API uses a promise to return the result. This API must be called in the **onTouch** callback, and the event type must be **TouchType.Down**.

**System capability:** SystemCapability.SelectionInput.Selection

**Model restriction:** This API can be used only in the stage model.

**Return value**

| Type  | Description                            |
| ------- | ------------------------------ |
| Promise\<void> | Promise that returns no value. |

**Error codes**

For details about the following error codes, see [Word Selection Error Codes](errorcode-selection.md). For details about other common error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code  | Error Message                      |
| ---------- | ----------------------------- |
| 33600001   | Selection service exception. |
| 33600002   | This selection window has been destroyed. |

**Example**

<!--code_no_check-->

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// This code must be placed in build() of the ArkUI page component. RelativeContainer is a built-in component of ArkUI. TouchEvent and TouchType are built-in types of ArkUI.
RelativeContainer() {
  /* 
   * Page layout content, which should be defined based on your actual needs.
   */
}
.onTouch((event: TouchEvent) => {
  if (event.type === TouchType.Down) {
    if (selectionPanel !== undefined) {
      // Enable the word selection panel to be dragged and moved with the mouse, touchpad, or touchscreen. selectionPanel is the panel instance created by createPanel.
      selectionPanel.startMoving().then(() => {
        console.info('Succeeded in startMoving the panel.');
      }).catch((err: BusinessError) => {
        console.error(`Failed to startMoving panel. Error code: ${err.code}, error message: ${err.message}`);
      });
    }
  }
})
```

<!--Del-->

### moveTo<sup>(deprecated)</sup>

moveTo(x: number, y: number): Promise\<void>

Moves the word selection panel to the specified coordinates in the global coordinate system of the screen. The panel can be moved to an extended screen. This API can be called only after a **Panel** instance is obtained by calling [createPanel](#createpanel). This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 20 and deprecated since API version 24. You are advised to use [moveToGlobalDisplay](#movetoglobaldisplay) instead.

**System API:** This is a system API.

**System capability:** SystemCapability.SelectionInput.Selection

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| x | number | Yes | X-coordinate of the target position in the global coordinate system of the screen, in px. The upper left corner of the main screen is the origin of the global coordinate system, and the positive direction of the X axis is rightward. The x-coordinate of an extended screen may be negative, depending on the screen layout. |
| y | number | Yes | Y-coordinate of the target position in the global coordinate system of the screen, in px. The upper left corner of the main screen is the origin of the global coordinate system, and the positive direction of the Y axis is downward. The y-coordinate of an extended screen may be negative, depending on the screen layout. |

**Return value**

| Type  | Description                            |
| ------- | ------------------------------ |
| Promise\<void> | Promise that returns no value. |

**Error codes**

For details about the following error codes, see [Word Selection Error Codes](errorcode-selection.md). For details about other common error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code  | Error Message                      |
| ---------- | ----------------------------- |
| 33600001   | Selection service exception. |
| 33600002   | This selection window has been destroyed. |

**Example**

<!--code_no_check-->

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  // Move the word selection panel to the specified coordinates on the screen. selectionPanel is a Panel instance created by createPanel.
  selectionPanel.moveTo(200, 200).then(() => {
    console.info('Succeeded in moving the panel.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to move panel. Error code: ${err.code}, error message: ${err.message}`);
  });
} catch (err) {
  console.error(`Failed to move panel. Error code: ${err.code}, error message: ${err.message}`);
}
```

<!--DelEnd-->

### moveToGlobalDisplay

moveToGlobalDisplay(x: number, y: number): Promise\<void>

Moves the word selection panel to the specified coordinates in the global coordinate system of the screen. The panel can be moved to an extended screen. This API can be called only after a **Panel** instance is obtained by calling [createPanel](#createpanel). This API uses a promise to return the result.

**System capability:** SystemCapability.SelectionInput.Selection

**Model restriction:** This API can be used only in the stage model.

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| x | number | Yes | X-coordinate of the target position in the global coordinate system of the screen, in px. The upper left corner of the main screen is the origin of the global coordinate system, and the positive direction of the X axis is rightward. The x-coordinate of an extended screen may be negative, depending on the screen layout. |
| y | number | Yes | Y-coordinate of the target position in the global coordinate system of the screen, in px. The upper left corner of the main screen is the origin of the global coordinate system, and the positive direction of the Y axis is downward. The y-coordinate of an extended screen may be negative, depending on the screen layout. |

**Return value**

| Type  | Description                            |
| ------- | ------------------------------ |
| Promise\<void> | Promise that returns no value. |

**Error codes**

For details about the following error codes, see [Word Selection Error Codes](errorcode-selection.md). For details about other common error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code  | Error Message                      |
| ---------- | ----------------------------- |
| 33600001   | Selection service exception. |
| 33600002   | This selection window has been destroyed. |

**Example**

<!--code_no_check-->

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  // Move the word selection panel to the specified coordinates on the screen. selectionPanel is a Panel instance created by createPanel.
  selectionPanel.moveToGlobalDisplay(200, 200).then(() => {
    console.info('Succeeded in moving the panel.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to move panel. Error code: ${err.code}, error message: ${err.message}`);
  });
} catch (err) {
  console.error(`Failed to move panel. Error code: ${err.code}, error message: ${err.message}`);
}
```

### on('destroyed')

on(type: 'destroyed', callback: Callback\<void>): void

Subscribes to the word selection panel destruction event. This API is used together with [off('destroyed')](#offdestroyed). This API can be called only after a **Panel** instance is obtained by calling [createPanel](#createpanel).

**System capability:** SystemCapability.SelectionInput.Selection

**Model restriction:** This API can be used only in the stage model.

**Parameters**

| Name  | Type                                       | Mandatory| Description                                          |
| -------- | ------------------------------------------- | ---- | ---------------------------------------------- |
| type     | string                                      | Yes  | Event type, which is **'destroyed'**.|
| callback | Callback\<void> | Yes | Callback used to return the result, which is triggered when [destroyPanel](#destroypanel) is called to destroy the panel. |

**Example**

<!--code_no_check-->

```ts
try {
  // Subscribe to the word selection panel destruction event. selectionPanel is a Panel instance created by createPanel.
  selectionPanel.on('destroyed', () => {
    console.info('Panel has been destroyed.');
  });
} catch (err) {
  console.error(`Failed to register destroyed callback. Error code: ${err.code}, error message: ${err.message}`);
}
```

### off('destroyed')

off(type: 'destroyed', callback?: Callback\<void>): void

Unsubscribes from the word selection panel destruction event. This API is used together with [on('destroyed')](#ondestroyed). This API can be called only after a **Panel** instance is obtained by calling [createPanel](#createpanel).

**System capability:** SystemCapability.SelectionInput.Selection

**Model restriction:** This API can be used only in the stage model.

**Parameters**

| Name  | Type                                       | Mandatory| Description                                                        |
| -------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                      | Yes   | Type of the event to unsubscribe from. The value is fixed to **'destroyed'**.               |
| callback | Callback\<void> | No   | Callback to be unregistered (that is, the callback instance registered using **on**). If this parameter is not specified, this API unregisters all callbacks for the specified type.|

**Example**

<!--code_no_check-->

```ts
try {
  // Unsubscribe from the word selection panel destroy event. selectionPanel is the panel instance created by createPanel.
  selectionPanel.off('destroyed');
} catch (err) {
  console.error(`Failed to unregister destroyed. Error code: ${err.code}, error message: ${err.message}`);
}
```

### on('hidden')

on(type: 'hidden', callback: Callback\<void>): void

Subscribes to the word selection panel hiding event. This API is used together with [off('hidden')](#offhidden). This event is triggered when the panel is hidden by calling [hide](#hide) or automatically hidden when it loses focus. This API can be called only after a **Panel** instance is obtained by calling [createPanel](#createpanel).

**System capability:** SystemCapability.SelectionInput.Selection

**Model restriction:** This API can be used only in the stage model.

**Parameters**

| Name  | Type                                       | Mandatory| Description                                          |
| -------- | ------------------------------------------- | ---- | ---------------------------------------------- |
| type     | string                                      | Yes  | Event type, which is **'hidden'**.|
| callback | Callback\<void> | Yes | Callback used to return the result, which is triggered when the panel is hidden. The panel can be hidden by calling [hide](#hide) or automatically hidden when it loses focus. |

**Example**

<!--code_no_check-->

```ts
try {
  // Subscribe to the word selection panel hide event. selectionPanel is the panel instance created by createPanel.
  selectionPanel.on('hidden', () => {
    console.info('Panel has been hidden.');
  });
} catch (err) {
  console.error(`Failed to register hidden callback. Error code: ${err.code}, error message: ${err.message}`);
}
```

### off('hidden')

off(type: 'hidden', callback?: Callback\<void>): void

Unsubscribes from the word selection panel hiding event. This API is used together with [on('hidden')](#onhidden). This API can be called only after a **Panel** instance is obtained by calling [createPanel](#createpanel).

**System capability:** SystemCapability.SelectionInput.Selection

**Model restriction:** This API can be used only in the stage model.

**Parameters**

| Name  | Type                                       | Mandatory| Description                                                        |
| -------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                      | Yes   | Type of the event to unsubscribe from. The value is fixed to **'hidden'**.               |
| callback | Callback\<void> | No   | Callback to be unregistered (that is, the callback instance registered using **on**). If this parameter is not specified, this API unregisters all callbacks for the specified type. |

**Example**

<!--code_no_check-->

```ts
try {
  // Unsubscribe from the word selection panel destruction event. selectionPanel is a Panel instance created by createPanel.
  selectionPanel.off('hidden');
} catch (err) {
  console.error(`Failed to unregister hidden. Error code: ${err.code}, error message: ${err.message}`);
}
```

## SelectionType

Enumerates the word selection types.

**System capability:** SystemCapability.SelectionInput.Selection

**Model restriction:** This API can be used only in the stage model.

| Name        | Value| Description              |
| ------------ | -- | ------------------ |
| MOUSE_MOVE | 1 | Word selection by sliding the mouse or touchpad. |
| DOUBLE_CLICK   | 2 | Word selection by double-clicking the mouse or touchpad. |
| TRIPLE_CLICK   | 3 | Word selection by triple-clicking the mouse or touchpad. |