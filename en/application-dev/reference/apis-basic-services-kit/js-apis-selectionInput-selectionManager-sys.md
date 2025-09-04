# @ohos.selectionInput.selectionManager (Word Selection Management) (System API)

This module provides word selection management capabilities, including creating, displaying, moving, hiding, and destroying windows, listening for word selection events, and retrieving the selected text.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 20. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - APIs of this module can be called only by applications that integrate the ExtensionAbility for word selection.
> - The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { selectionManager } from '@kit.BasicServicesKit';
```


## on('selectionCompleted')

on(type: 'selectionCompleted', callback: Callback\<SelectionInfo>): void

Registers a callback to listen for the word selection completion event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.SelectionInput.Selection

**Parameters**

| Name  | Type                                       | Mandatory| Description                                          |
| -------- | ------------------------------------------- | ---- | ---------------------------------------------- |
| type     | string                                      | Yes  | Event type, which is **'selectionCompleted'**.|
| callback | Callback\<[SelectionInfo](#selectioninfo)> | Yes  | Callback used to return the word selection information.      |

**Error codes**

For details about the error codes, see [Word Selection Service Error Codes](errorcode-selection.md).

| ID  | Error Message                      |
| ---------- | ----------------------------- |
| 33600003   | Invalid operation. The selection app is not valid. |

**Example**

```ts
import { selectionManager } from '@kit.BasicServicesKit';

try {
  selectionManager.on('selectionCompleted', (info: selectionManager.SelectionInfo) => {
    console.info(`SelectionInfo text: ${info.text}`);
  });
} catch (err) {
  console.error(`Failed to register selectionCompleted callback: ${JSON.stringify(err)}`);
}
```

## off('selectionCompleted')

off(type: 'selectionCompleted', callback?: Callback\<SelectionInfo>): void

Unregisters the callback used to listen for the word selection completion event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.SelectionInput.Selection

**Parameters**

| Name  | Type                                       | Mandatory| Description                                                        |
| -------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                      | Yes  | Event type, which is **'selectionCompleted'**.              |
| callback | Callback\<[SelectionInfo](#selectioninfo)> | No  | Callback to unregister. If this parameter is not specified, this API unregisters all callbacks for the specified type.|

**Example**

```ts
import { selectionManager } from '@kit.BasicServicesKit';

let selectionChangeCallback = (info: selectionManager.SelectionInfo) => {
  console.info(`SelectionInfo text: ${info.text}`);
};

selectionManager.on('selectionCompleted', selectionChangeCallback);
try {
  selectionManager.off('selectionCompleted', selectionChangeCallback);
} catch (err) {
  console.error(`Failed to unregister selectionCompleted: ${JSON.stringify(err)}`);
}
```

## createPanel

createPanel(ctx: Context, info: PanelInfo): Promise\<Panel>

Creates a word selection panel. This API uses a promise to return the result.

Only one [main panel](./js-apis-selectionInput-selectionPanel-sys.md) and one [menu panel](./js-apis-selectionInput-selectionPanel-sys.md) can be created for a single word selection application.

**System capability**: SystemCapability.SelectionInput.Selection

**Parameters**

| Name  | Type       | Mandatory| Description                    |
| ------- | ----------- | ---- | ------------------------ |
| ctx     | [Context](../apis-ability-kit/js-apis-inner-application-context.md) | Yes  | Context that the current word selection panel depends on.|
| info    | [PanelInfo](./js-apis-selectionInput-selectionPanel-sys.md)   | Yes  | Information about the word selection panel.|

**Return value**
| Type  | Description                                                                |
| ------- | ------------------------------------------------------------------ |
| Promise\<[Panel](#panel)> | Promise used to return the word selection panel created. |

**Error codes**

For details about the error codes, see [Word Selection Service Error Codes](errorcode-selection.md).

| ID  | Error Message                      |
| ---------- | ----------------------------- |
| 33600001   | Selection service exception. |
| 33600003   | Invalid operation. The selection app is not valid. |

**Example**

```ts
import { selectionManager, SelectionExtensionAbility, PanelInfo, PanelType, BusinessError } from '@kit.BasicServicesKit';
import { rpc } from '@kit.IPCKit';
import { Want } from '@kit.AbilityKit';

class SelectionAbilityStub extends rpc.RemoteObject {
  constructor(des: string) {
    super(des);
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
    let panelInfo: PanelInfo = {
      panelType: PanelType.MENU_PANEL,
      x: 0,
      y: 0,
      width: 500,
      height: 200
    }
    selectionManager.createPanel(this.context, panelInfo)
      .then((panel: selectionManager.Panel) => {
        console.info('Succeed in creating panel.');
      }).catch((err: BusinessError) => {
      console.error(`Failed to create panel: ${JSON.stringify(err)}`);
    });
    return new SelectionAbilityStub('remote');
  }
}
export default ServiceExtAbility;
```

## destroyPanel

destroyPanel(panel: Panel): Promise\<void>

Destroys the word selection panel. This API uses a promise to return the result.

**System capability**: SystemCapability.SelectionInput.Selection

**Parameters**

| Name  | Type       | Mandatory| Description                    |
| ---------| ----------- | ---- | ------------------------ |
| panel    | [Panel](#panel)       | Yes  | Word selection panel to destroy.     |

**Return value**
| Type   | Description                                                                |
| ------- | -------------------------------------------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Word Selection Service Error Codes](errorcode-selection.md).

| ID  | Error Message                      |
| ---------- | ----------------------------- |
| 33600001   | Selection service exception. |

**Example**

```ts
import { selectionManager, SelectionExtensionAbility, PanelInfo, PanelType, BusinessError } from '@kit.BasicServicesKit';
import { rpc } from '@kit.IPCKit';
import { Want } from '@kit.AbilityKit';

class SelectionAbilityStub extends rpc.RemoteObject {
  constructor(des: string) {
    super(des);
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
    let panelInfo: PanelInfo = {
      panelType: PanelType.MENU_PANEL,
      x: 0,
      y: 0,
      width: 500,
      height: 200
    }
    let selectionPanel: selectionManager.Panel | undefined = undefined;

    selectionManager.createPanel(this.context, panelInfo)
      .then((panel: selectionManager.Panel) => {
        console.info('Succeed in creating panel.');
        selectionPanel = panel;
        try {
          if (selectionPanel) {
            selectionManager.destroyPanel(selectionPanel).then(() => {
              console.info('Succeed in destroying panel.');
            }).catch((err: BusinessError) => {
              console.error(`Failed to destroy panel: ${JSON.stringify(err)}`);
            });
          }
        } catch (err) {
          console.error(`Failed to destroy panel: ${JSON.stringify(err)}`);
        }
      }).catch((err: BusinessError) => {
      console.error(`Failed to create panel: ${JSON.stringify(err)}`);
    });
    return new SelectionAbilityStub('remote');
  }
}
export default ServiceExtAbility;
```

## SelectionInfo

Defines the information of a word selection event.

**System capability**: SystemCapability.SelectionInput.Selection

| Name     | Type| Read-Only| Optional| Description        |
| --------- | -------- | ---- | ---- | ------------ |
| text   	| string   | No  | No  | Selected text.|
| selectionType	    | [SelectionType](#selectiontype)   | No  | No  | Operation for selecting words.|
| startDisplayX   	| number   | No  | No  | X-coordinate of the screen where the word selection starts, in px.|
| startDisplayY   	| number   | No  | No  | Y-coordinate of the screen where the word selection starts, in px.|
| endDisplayX   	| number   | No  | No  | X-coordinate of the screen where the word selection ends, in px.|
| endDisplayY   	| number   | No  | No  | Y-coordinate of the screen where the word selection ends, in px.|
| startWindowX   	| number   | No  | No  | X-coordinate of the window where the word selection starts, in px.|
| startWindowY   	| number   | No  | No  | Y-coordinate of the window where the word selection starts, in px.|
| endWindowX   	| number   | No  | No  | X-coordinate of the window where the word selection ends, in px.|
| endWindowY   	| number   | No  | No  | Y-coordinate of the window where the word selection ends, in px.|
| displayID   	| number   | No  | No  | ID of the screen where the window with selected words is located.|
| windowID   	| number   | No  | No  | ID of the window where words are selected.|
| bundleName   	| string   | No  | No  | Bundle name of the application where words are selected.|

## Panel

In the following API examples, you must first use [createPanel](#createpanel) to obtain a **Panel** instance, and then call the APIs using the obtained instance.

### setUiContent

setUiContent(path: string): Promise\<void>

Sets the page content for the word selection panel. This API uses a promise to return the result.

**System capability**: SystemCapability.SelectionInput.Selection

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| path | string | Yes  |  Path of the page content to be set. This path is configured in the **resources/base/profile/main_pages.json** file of the project in the stage model. The FA model is not supported.|

**Return value**

| Type  | Description                            |
| ------- | ------------------------------ |
| Promise\<void> | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Word Selection Service Error Codes](errorcode-selection.md).

| ID  | Error Message                      |
| ---------- | ----------------------------- |
| 33600001   | Selection service exception. |
| 33600002   | This selection window has been destroyed. |

**Example**

```ts
import { selectionManager, BusinessError } from '@kit.BasicServicesKit';

try {
  selectionPanel.setUiContent('pages/Index').then(() => {
    console.info('Succeeded in setting the content.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to setUiContent: ${JSON.stringify(err)}`);
  });
} catch (err) {
  console.error(`Failed to setUiContent: ${JSON.stringify(err)}`);
}
```

### show

show(): Promise\<void>

Shows the word selection panel. This API uses a promise to return the result.

**System capability**: SystemCapability.SelectionInput.Selection

**Return value**

| Type  | Description                            |
| ------- | ------------------------------ |
| Promise\<void> | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Word Selection Service Error Codes](errorcode-selection.md).

| ID  | Error Message                      |
| ---------- | ----------------------------- |
| 33600001   | Selection service exception. |
| 33600002   | This selection window has been destroyed. |

**Example**

```ts
import { selectionManager, BusinessError } from '@kit.BasicServicesKit';

selectionPanel.show().then(() => {
  console.info('Succeeded in showing the panel.');
}).catch((err: BusinessError) => {
  console.error(`Failed to show panel: ${JSON.stringify(err)}`);
});
```

### hide

hide(): Promise\<void>

Hides the word selection panel. This API uses a promise to return the result.

**System capability**: SystemCapability.SelectionInput.Selection

**Return value**

| Type  | Description                            |
| ------- | ------------------------------ |
| Promise\<void> | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Word Selection Service Error Codes](errorcode-selection.md).

| ID  | Error Message                      |
| ---------- | ----------------------------- |
| 33600001   | Selection service exception. |
| 33600002   | This selection window has been destroyed. |

**Example**

```ts
import { selectionManager, BusinessError } from '@kit.BasicServicesKit';

selectionPanel.hide().then(() => {
  console.info('Succeeded in hiding the panel.');
}).catch((err: BusinessError) => {
  console.error(`Failed to hide panel: ${JSON.stringify(err)}`);
});
```

### startMoving

startMoving(): Promise\<void>

Moves the word selection panel by dragging. This API uses a promise to return the result.

**System capability**: SystemCapability.SelectionInput.Selection

**Return value**

| Type  | Description                            |
| ------- | ------------------------------ |
| Promise\<void> | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Word Selection Service Error Codes](errorcode-selection.md).

| ID  | Error Message                      |
| ---------- | ----------------------------- |
| 33600001   | Selection service exception. |
| 33600002   | This selection window has been destroyed. |

**Example**

```ts
import { selectionManager, BusinessError } from '@kit.BasicServicesKit';

RelativeContainer() {
}
.onTouch((event: TouchEvent) => {
  if (event.type === TouchType.Down) {
    if (selectionPanel !== undefined) {
      selectionPanel.startMoving().then(() => {
        console.info('Succeeded in startMoving the panel.');
      }).catch((err: BusinessError) => {
        console.error(`Failed to startMoving panel: ${JSON.stringify(err)}`);
      });
    }
  }
})
```

### moveTo

moveTo(x: number, y: number): Promise\<void>

Moves the word selection panel to the specified coordinates on the screen. This API uses a promise to return the result.

**System capability**: SystemCapability.SelectionInput.Selection

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| x | number | Yes  |Value of the movement along the X axis, in px.|
| y | number | Yes  |Value of the movement along the Y axis, in px.|

**Return value**

| Type  | Description                            |
| ------- | ------------------------------ |
| Promise\<void> | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Word Selection Service Error Codes](errorcode-selection.md).

| ID  | Error Message                      |
| ---------- | ----------------------------- |
| 33600001   | Selection service exception. |
| 33600002   | This selection window has been destroyed. |

**Example**

```ts
import { selectionManager, BusinessError } from '@kit.BasicServicesKit';

try {
  selectionPanel.moveTo(200, 200).then(() => {
    console.info('Succeeded in moving the panel.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to move panel: ${JSON.stringify(err)}`);
  });
} catch (err) {
  console.error(`Failed to move panel: ${JSON.stringify(err)}`);
}
```

### on('destroyed')

on(type: 'destroyed', callback: Callback\<void>): void

Registers a callback to listen for the destroy event of the word selection panel. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.SelectionInput.Selection

**Parameters**

| Name  | Type                                       | Mandatory| Description                                          |
| -------- | ------------------------------------------- | ---- | ---------------------------------------------- |
| type     | string                                      | Yes  | Event type, which is **'destroyed'**.|
| callback | Callback\<void> | Yes  | Callback used to return the result.      |

**Example**

```ts
import { selectionManager, BusinessError } from '@kit.BasicServicesKit';

try {
  selectionPanel.on('destroyed', () => {
    console.info('Panel has destroyed.');
  });
} catch (err) {
  console.error(`Failed to register destroyed callback: ${JSON.stringify(err)}`);
}
```

### off('destroyed')

off(type: 'destroyed', callback?: Callback\<void>): void

Unregisters the callback used to listen for the destroy event of the word selection panel. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.SelectionInput.Selection

**Parameters**

| Name  | Type                                       | Mandatory| Description                                                        |
| -------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                      | Yes  | Event type, which is **'destroyed'**.              |
| callback | Callback\<void> | No  | Callback to unregister. If this parameter is not specified, this API unregisters all callbacks for the specified type.|

**Example**

```ts
import { selectionManager, BusinessError } from '@kit.BasicServicesKit';

try {
  selectionPanel.off('destroyed');
} catch (err) {
  console.error(`Failed to unregister destroyed: ${JSON.stringify(err)}`);
}
```

### on('hidden')

on(type: 'hidden', callback: Callback\<void>): void

Registers a callback to listen for the hide event of the word selection panel. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.SelectionInput.Selection

**Parameters**

| Name  | Type                                       | Mandatory| Description                                          |
| -------- | ------------------------------------------- | ---- | ---------------------------------------------- |
| type     | string                                      | Yes  | Event type, which is **'hidden'**.|
| callback | Callback\<void> | Yes  | Callback used to return the result.      |

**Example**

```ts
import { selectionManager, BusinessError } from '@kit.BasicServicesKit';

try {
  selectionPanel.on('hidden', () => {
    console.info('Panel has hidden.');
  });
} catch (err) {
  console.error(`Failed to register hidden callback: ${JSON.stringify(err)}`);
}
```

### off('hidden')

off(type: 'hidden', callback?: Callback\<void>): void

Unregisters the callback used to listen for the hide event of the word selection panel. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.SelectionInput.Selection

**Parameters**

| Name  | Type                                       | Mandatory| Description                                                        |
| -------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                      | Yes  | Event type, which is **'hidden'**.              |
| callback | Callback\<void> | No  | Callback to unregister. If this parameter is not specified, this API unregisters all callbacks for the specified type.|

**Example**

```ts
import { selectionManager, BusinessError } from '@kit.BasicServicesKit';

try {
  selectionPanel.off('hidden');
} catch (err) {
  console.error(`Failed to unregister hidden: ${JSON.stringify(err)}`);
}
```

## SelectionType

Enumerates the operations for selecting words.

**System capability**: SystemCapability.SelectionInput.Selection

| Name        | Value| Description              |
| ------------ | -- | ------------------ |
| MOUSE_MOVE | 1 | Move the cursor to select words.|
| DOUBLE_CLICK   | 2 | Double-click to select words.|
| TRIPLE_CLICK   | 3 | Triple-click to select words.|
