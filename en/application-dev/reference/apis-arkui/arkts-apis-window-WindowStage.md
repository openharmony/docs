# Interface (WindowStage)
<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @waterwin-->
<!--Designer: @nyankomiya-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->

> **NOTE**
>
> - The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The initial APIs of this interface are supported since API version 9.

Implements a window manager, which manages each basic window unit, that is, [Window](arkts-apis-window-Window.md) instance.

Before calling any of the following APIs, you must use [onWindowStageCreate()](../apis-ability-kit/js-apis-app-ability-uiAbility.md#onwindowstagecreate) to create a WindowStage instance.

## Modules to Import

```ts
import { window } from '@kit.ArkUI';
```

## getMainWindow<sup>9+</sup>

getMainWindow(callback: AsyncCallback&lt;Window&gt;): void

Obtains the main window of this WindowStage. This API uses an asynchronous callback to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name  | Type                                  | Mandatory| Description                                         |
| -------- | -------------------------------------- | ---- | --------------------------------------------- |
| callback | AsyncCallback&lt;[Window](arkts-apis-window-Window.md)&gt; | Yes  | Callback used to return the main window.|

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |
| 1300005 | This window stage is abnormal. |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    windowStage.getMainWindow((err: BusinessError, data) => {
      const errCode: number = err.code;
      if (errCode) {
        console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      windowClass = data;
      console.info('Succeeded in obtaining the main window. Data: ' + JSON.stringify(data));
    });
  }
};
```

## getMainWindow<sup>9+</sup>

getMainWindow(): Promise&lt;Window&gt;

Obtains the main window of this WindowStage. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Return value**

| Type                            | Description                                            |
| -------------------------------- | ------------------------------------------------ |
| Promise&lt;[Window](arkts-apis-window-Window.md)&gt; | Promise used to return the main window.|

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |
| 1300005 | This window stage is abnormal. |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    let promise = windowStage.getMainWindow();
    promise.then((data) => {
      windowClass = data;
      console.info('Succeeded in obtaining the main window. Data: ' + JSON.stringify(data));
    }).catch((err: BusinessError) => {
      console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
    });
  }
};
```

## getMainWindowSync<sup>9+</sup>

getMainWindowSync(): Window

Obtains the main window of this WindowStage.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Return value**

| Type| Description|
| ----------------- | --------------------------------- |
| [Window](arkts-apis-window-Window.md) | Main window.|

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |
| 1300005 | This window stage is abnormal. |

**Example**
<!--code_no_check-->
```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    try {
      let windowClass = windowStage.getMainWindowSync();
    } catch (exception) {
      console.error(`Failed to obtain the main window. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
};
```

## createSubWindow<sup>9+</sup>

createSubWindow(name: string, callback: AsyncCallback&lt;Window&gt;): void

Creates a child window for this WindowStage. This API uses an asynchronous callback to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name  | Type                                  | Mandatory| Description                                         |
| -------- | -------------------------------------- | ---- | --------------------------------------------- |
| name     | string                                 | Yes  | Name of the child window.                               |
| callback | AsyncCallback&lt;[Window](arkts-apis-window-Window.md)&gt; | Yes  | Callback used to return the child window.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 401     | Parameter error. Possible cause: Incorrect parameter types. |
| 1300002 | This window state is abnormal. |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    try {
      windowStage.createSubWindow('mySubWindow', (err: BusinessError, data) => {
        const errCode: number = err.code;
        if (errCode) {
          console.error(`Failed to create the subwindow. Cause code: ${err.code}, message: ${err.message}`);
          return;
        }
        windowClass = data;
        console.info('Succeeded in creating the subwindow. Data: ' + JSON.stringify(data));
        if (!windowClass) {
          console.info('Failed to load the content. Cause: windowClass is null');
        }
        else {
          windowClass.resize(500, 1000);
        }
      });
    } catch (exception) {
      console.error(`Failed to create the subwindow. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
};
```

## createSubWindow<sup>9+</sup>

createSubWindow(name: string): Promise&lt;Window&gt;

Creates a child window for this WindowStage. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name| Type  | Mandatory| Description          |
| ------ | ------ | ---- | -------------- |
| name   | string | Yes  | Name of the child window.|

**Return value**

| Type                            | Description                                            |
| -------------------------------- | ------------------------------------------------ |
| Promise&lt;[Window](arkts-apis-window-Window.md)&gt; | Promise used to return the child window.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 401     | Parameter error. Possible cause: Incorrect parameter types. |
| 1300002 | This window state is abnormal. |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    try {
      let promise = windowStage.createSubWindow('mySubWindow');
      promise.then((data) => {
        windowClass = data;
        console.info('Succeeded in creating the subwindow. Data: ' + JSON.stringify(data));
      }).catch((err: BusinessError) => {
        console.error(`Failed to create the subwindow. Cause code: ${err.code}, message: ${err.message}`);
      });
    } catch (exception) {
      console.error(`Failed to create the subwindow. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
};
```

## createSubWindowWithOptions<sup>11+</sup>

createSubWindowWithOptions(name: string, options: SubWindowOptions): Promise&lt;Window&gt;

Creates a child window for this WindowStage. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name| Type  | Mandatory| Description          |
| ------ | ------ | ---- | -------------- |
| name   | string | Yes  | Name of the child window.|
| options  | [SubWindowOptions](arkts-apis-window-i.md#subwindowoptions11) | Yes  | Parameters used for creating the child window. |

**Return value**

| Type                            | Description                                            |
| -------------------------------- | ------------------------------------------------ |
| Promise&lt;[Window](arkts-apis-window-Window.md)&gt; | Promise used to return the child window created.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 401     | Parameter error. Possible cause: Incorrect parameter types. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300005 | This window stage is abnormal. |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    try {
      let options : window.SubWindowOptions = {
        title: 'title',
        decorEnabled: true
      };
      let promise = windowStage.createSubWindowWithOptions('mySubWindow', options);
      promise.then((data) => {
        windowClass = data;
        console.info('Succeeded in creating the subwindow. Data: ' + JSON.stringify(data));
      }).catch((err: BusinessError) => {
        console.error(`Failed to create the subwindow. Cause code: ${err.code}, message: ${err.message}`);
      });
    } catch (exception) {
      console.error(`Failed to create the subwindow. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
};
```

## getSubWindow<sup>9+</sup>

getSubWindow(callback: AsyncCallback&lt;Array&lt;Window&gt;&gt;): void

Obtains all the child windows of this WindowStage. This API uses an asynchronous callback to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name  | Type                                               | Mandatory| Description                                             |
| -------- | --------------------------------------------------- | ---- | ------------------------------------------------- |
| callback | AsyncCallback&lt;Array&lt;[Window](arkts-apis-window-Window.md)&gt;&gt; | Yes  | Callback used to return all the child windows.|

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |

**Example**
<!--code_no_check-->
```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    let windowClass: window.Window[] = [];
    windowStage.getSubWindow((err: BusinessError, data) => {
      const errCode: number = err.code;
      if (errCode) {
        console.error(`Failed to obtain the subwindow. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      windowClass = data;
      console.info('Succeeded in obtaining the subwindow. Data: ' + JSON.stringify(data));
    });
  }
};
```

## getSubWindow<sup>9+</sup>

getSubWindow(): Promise&lt;Array&lt;Window&gt;&gt;

Obtains all the child windows of this WindowStage. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Return value**

| Type                                         | Description                                                |
| --------------------------------------------- | ---------------------------------------------------- |
| Promise&lt;Array&lt;[Window](arkts-apis-window-Window.md)&gt;&gt; | Promise used to return all the child windows.|

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |

**Example**
<!--code_no_check-->
```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    let windowClass: window.Window[] = [];
    let promise = windowStage.getSubWindow();
    promise.then((data) => {
      windowClass = data;
      console.info('Succeeded in obtaining the subwindow. Data: ' + JSON.stringify(data));
    }).catch((err: BusinessError) => {
      console.error(`Failed to obtain the subwindow. Cause code: ${err.code}, message: ${err.message}`);
    });
  }
};
```

## loadContent<sup>9+</sup>

loadContent(path: string, storage: LocalStorage, callback: AsyncCallback&lt;void&gt;): void

Loads the content of a page, with its path in the current project specified, to the main window of this WindowStage, and transfers the state attribute to the page through a local storage. This API uses an asynchronous callback to return the result. You are advised to call this API during UIAbility startup. If called repeatedly, this API will destroy the existing page content (UIContent) before loading the new content. Exercise caution when using it. The execution context of the current UI may be unclear. Therefore, you are advised not to perform UI-related operations within the callback.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name  | Type                                           | Mandatory| Description                                                        |
| -------- | ----------------------------------------------- | ---- | ------------------------------------------------------------ |
| path     | string                                          | Yes  | Path of the page from which the content will be loaded. The path is configured in the **main_pages.json** file of the project. |
| storage  | [LocalStorage](../../ui/state-management/arkts-localstorage.md) | Yes  | Page-level UI state storage unit, which is used to transfer the state attribute for the page.|
| callback | AsyncCallback&lt;void&gt;                       | Yes  | Callback used to return the result.                                                  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Invalid path parameter.|
| 1300002 | This window state is abnormal. |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...

  storage: LocalStorage = new LocalStorage();

  onWindowStageCreate(windowStage: window.WindowStage) {
    this.storage.setOrCreate('storageSimpleProp', 121);
    console.info('onWindowStageCreate');
    try {
      windowStage.loadContent('pages/page2', this.storage, (err: BusinessError) => {
        const errCode: number = err.code;
        if (errCode) {
          console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info('Succeeded in loading the content.');
      });
    } catch (exception) {
      console.error(`Failed to load the content. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
};
```

## loadContent<sup>9+</sup>

loadContent(path: string, storage?: LocalStorage): Promise&lt;void&gt;

Loads the content of a page, with its path in the current project specified, to the main window of this WindowStage, and transfers the state attribute to the page through a local storage. This API uses a promise to return the result. You are advised to call this API during UIAbility startup. If called repeatedly, this API will destroy the existing page content (UIContent) before loading the new content. Exercise caution when using it. The execution context of the current UI may be unclear. Therefore, you are advised not to perform UI-related operations within the callback.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name | Type                                           | Mandatory| Description                                                        |
| ------- | ----------------------------------------------- | ---- | ------------------------------------------------------------ |
| path    | string                                          | Yes  | Path of the page from which the content will be loaded. The path is configured in the **main_pages.json** file of the project.|
| storage | [LocalStorage](../../ui/state-management/arkts-localstorage.md) | No  | Page-level UI state storage unit, which is used to transfer the state attribute for the page.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Invalid path parameter.|
| 1300002 | This window state is abnormal. |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...

  storage: LocalStorage = new LocalStorage();

  onWindowStageCreate(windowStage: window.WindowStage) {
    this.storage.setOrCreate('storageSimpleProp', 121);
    console.info('onWindowStageCreate');
    try {
      let promise = windowStage.loadContent('pages/page2', this.storage);
      promise.then(() => {
        console.info('Succeeded in loading the content.');
      }).catch((err: BusinessError) => {
        console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
      });
    } catch (exception) {
      console.error(`Failed to load the content. Cause code: ${exception.code}, message: ${exception.message}`);
    }
    ;
  }
};
```

## loadContent<sup>9+</sup>

loadContent(path: string, callback: AsyncCallback&lt;void&gt;): void

Loads the content of a page, with its path in the current project specified, to the main window of this WindowStage. This API uses an asynchronous callback to return the result. You are advised to call this API during UIAbility startup. If called repeatedly, this API will destroy the existing page content (UIContent) before loading the new content. Exercise caution when using it. The execution context of the current UI may be unclear. Therefore, you are advised not to perform UI-related operations within the callback.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name  | Type                     | Mandatory| Description                |
| -------- | ------------------------- | ---- | -------------------- |
| path     | string                    | Yes  | Path of the page from which the content will be loaded. The path is configured in the **main_pages.json** file of the project.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.          |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Invalid path parameter.|
| 1300002 | This window state is abnormal. |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    try {
      windowStage.loadContent('pages/page2', (err: BusinessError) => {
        const errCode: number = err.code;
        if (errCode) {
          console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info('Succeeded in loading the content.');
      });
    } catch (exception) {
      console.error(`Failed to load the content. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
};
```

## loadContentByName<sup>11+</sup>

loadContentByName(name: string, storage: LocalStorage, callback: AsyncCallback&lt;void&gt;): void

Loads the content of a [named route](../../ui/arkts-routing.md#named-route) page to this WindowStage, and transfers the state attribute to the page through a local storage. This API uses an asynchronous callback to return the result. You are advised to call this API during UIAbility startup. If called repeatedly, this API will destroy the existing page content (UIContent) before loading the new content. Exercise caution when using it. The execution context of the current UI may be unclear. Therefore, you are advised not to perform UI-related operations within the callback.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| name     | string                                                  | Yes  | Name of the named route page.                                            |
| storage  | [LocalStorage](../../ui/state-management/arkts-localstorage.md) | Yes  | Page-level UI state storage unit, which is used to transfer the state attribute for the page.|
| callback | AsyncCallback&lt;void&gt;                               | Yes  | Callback used to return the result.                                                  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message                                     |
| -------- | --------------------------------------------- |
| 401      | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002  | This window state is abnormal.                |

**Example**

<!--code_no_check-->
```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import * as Index from '../pages/Index'; // Import the named route page.

export default class EntryAbility extends UIAbility {
  // ...

  storage: LocalStorage = new LocalStorage();

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    this.storage.setOrCreate('storageSimpleProp', 121);
    try {
      windowStage.loadContentByName(Index.entryName, this.storage, (err: BusinessError) => {
        const errCode: number = err.code;
        if (errCode) {
          console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info('Succeeded in loading the content.');
      });
    } catch (exception) {
      console.error(`Failed to load the content. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
};
```
<!--code_no_check-->
```ts
// ets/pages/Index.ets
export const entryName : string = 'Index';
@Entry({routeName: entryName, useSharedStorage: true})
@Component
export struct Index {
  @State message: string = 'Hello World'
  @LocalStorageLink('storageSimpleProp') storageSimpleProp: number = 1;
  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

## loadContentByName<sup>11+</sup>

loadContentByName(name: string, callback: AsyncCallback&lt;void&gt;): void

Loads the content of a [named route](../../ui/arkts-routing.md#named-route) page to this WindowStage. This API uses an asynchronous callback to return the result. You are advised to call this API during UIAbility startup. If called repeatedly, this API will destroy the existing page content (UIContent) before loading the new content. Exercise caution when using it. The execution context of the current UI may be unclear. Therefore, you are advised not to perform UI-related operations within the callback.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name  | Type                     | Mandatory| Description            |
| -------- | ------------------------- | ---- | ---------------- |
| name     | string                    | Yes  | Name of the named route page.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.      |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message                                     |
| -------- | --------------------------------------------- |
| 401      | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002  | This window state is abnormal.                |

**Example**

<!--code_no_check-->
```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import * as Index from '../pages/Index'; // Import the named route page.

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    try {
      windowStage.loadContentByName(Index.entryName, (err: BusinessError) => {
        const errCode: number = err.code;
        if (errCode) {
          console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info('Succeeded in loading the content.');
      });
    } catch (exception) {
      console.error(`Failed to load the content. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
};
```
<!--code_no_check-->
```ts
// ets/pages/Index.ets
export const entryName : string = 'Index';
@Entry({routeName: entryName})
@Component
export struct Index {
  @State message: string = 'Hello World'
  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

## loadContentByName<sup>11+</sup>

loadContentByName(name: string, storage?: LocalStorage): Promise&lt;void&gt;

Loads the content of a [named route](../../ui/arkts-routing.md#named-route) page to this WindowStage, and transfers the state attribute to the page through a local storage. This API uses a promise to return the result. You are advised to call this API during UIAbility startup. If called repeatedly, this API will destroy the existing page content (UIContent) before loading the new content. Exercise caution when using it. The execution context of the current UI may be unclear. Therefore, you are advised not to perform UI-related operations within the callback.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name | Type        | Mandatory| Description                                                        |
| ------- | ------------ | ---- | ------------------------------------------------------------ |
| name    | string       | Yes  | Name of the named route page.                                            |
| storage | [LocalStorage](../../ui/state-management/arkts-localstorage.md) | No  | Page-level UI state storage unit, which is used to transfer the state attribute for the page.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message                                     |
| -------- | --------------------------------------------- |
| 401      | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002  | This window state is abnormal.                |

**Example**

<!--code_no_check-->
```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import * as Index from '../pages/Index'; // Import the named route page.

export default class EntryAbility extends UIAbility {
  // ...

  storage: LocalStorage = new LocalStorage();

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    this.storage.setOrCreate('storageSimpleProp', 121);
    try {
      let promise = windowStage.loadContentByName(Index.entryName, this.storage);
      promise.then(() => {
        console.info('Succeeded in loading the content.');
      }).catch((err: BusinessError) => {
        console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
      });
    } catch (exception) {
      console.error(`Failed to load the content. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
};
```
<!--code_no_check-->
```ts
// ets/pages/Index.ets
export const entryName : string = 'Index';
@Entry({routeName: entryName, useSharedStorage: true})
@Component
export struct Index {
  @State message: string = 'Hello World'
  @LocalStorageLink('storageSimpleProp') storageSimpleProp: number = 1;
  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

## on('windowStageEvent')<sup>9+</sup>

on(eventType: 'windowStageEvent', callback: Callback&lt;WindowStageEventType&gt;): void

Subscribes to the WindowStage lifecycle change event.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| eventType  | string                                                       | Yes  | Event type. The value is fixed at **'windowStageEvent'**, indicating the WindowStage lifecycle change event.|
| callback | Callback&lt;[WindowStageEventType](arkts-apis-window-e.md#windowstageeventtype9)&gt; | Yes  | Callback used to return the WindowStage lifecycle state.               |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal. |
| 1300005 | This window stage is abnormal. |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    try {
      windowStage.on('windowStageEvent', (data) => {
        console.info('Succeeded in enabling the listener for window stage event changes. Data: ' +
        JSON.stringify(data));
      });
    } catch (exception) {
      console.error(`Failed to enable the listener for window stage event changes. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
};
```

## off('windowStageEvent')<sup>9+</sup>

off(eventType: 'windowStageEvent', callback?: Callback&lt;WindowStageEventType&gt;): void

Unsubscribes from the WindowStage lifecycle change event.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| eventType  | string                                                       | Yes  | Event type. The value is fixed at **'windowStageEvent'**, indicating the WindowStage lifecycle change event.|
| callback | Callback&lt;[WindowStageEventType](arkts-apis-window-e.md#windowstageeventtype9)&gt; | No  | Callback used to return the WindowStage lifecycle state. If a value is passed in, the corresponding subscription is canceled. If no value is passed in, all subscriptions to the specified event are canceled.               |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 401     | Parameter error. Possible cause: 1. Incorrect parameter types; 2. Parameter verification failed. |
| 1300002 | This window state is abnormal. |
| 1300005 | This window stage is abnormal. |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    const callback = (windowStageEventType: window.WindowStageEventType) => {
      // ...
    }
    try {
      windowStage.on('windowStageEvent', callback);
    } catch (exception) {
      console.error(`Failed to enable the listener for window stage event changes. Cause code: ${exception.code}, message: ${exception.message}`);
    }
    try {
      windowStage.off('windowStageEvent', callback);
      // Unregister all the callbacks that have been registered through on().
      windowStage.off('windowStageEvent');
    } catch (exception) {
      console.error(`Failed to disable the listener for window stage event changes. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
};
```

## on('windowStageLifecycleEvent')<sup>20+</sup>

on(eventType: 'windowStageLifecycleEvent', callback: Callback&lt;WindowStageLifecycleEventType&gt;): void

Subscribes to the WindowStage lifecycle change event.

> **NOTE**
>
>  Comparison with [on('windowStageEvent')](#onwindowstageevent9):
>
> 1. **on('windowStageEvent')** does not ensure the sequence of state transitions. It is not suitable for cases where the order of states matters. In such cases, use this API instead.
>
> 2. This API does not support listening for focus gain/loss states of the WindowStage. For such requirements, use [on('windowEvent')](arkts-apis-window-Window.md#onwindowevent10).
>
> 3. For details about system mechanisms and lifecycle transitions, see [Main Window Lifecycle](../../windowmanager/window-overview.md#main-window-lifecycle).

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| eventType  | string                                                       | Yes  | Event type. The value is fixed at **'windowStageLifecycleEvent'**, indicating the WindowStage lifecycle change event.|
| callback | Callback&lt;[WindowStageLifecycleEventType](arkts-apis-window-e.md#windowstagelifecycleeventtype20)&gt; | Yes  | Callback used to return the WindowStage lifecycle state.               |

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300005 | This window stage is abnormal. |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    const callback = (data: window.WindowStageLifecycleEventType) => {
      console.info('Succeeded in enabling the listener for window stage event changes. Data: ' +
        JSON.stringify(data));
      // Process services based on the event status.
      if (data === window.WindowStageLifecycleEventType.SHOWN) {
        console.info('current window stage event is SHOWN');
        // ...
      } else if (data === window.WindowStageLifecycleEventType.RESUMED) {
        console.info('current window stage event is RESUMED');
        // ...
      } else if (data === window.WindowStageLifecycleEventType.PAUSED) {
        console.info('current window stage event is PAUSED');
        // ...
      } else if (data === window.WindowStageLifecycleEventType.HIDDEN) {
        console.info('current window stage event is HIDDEN');
        // ...
      }
      // ...
    }
    try {
      windowStage.on('windowStageLifecycleEvent', callback);
    } catch (exception) {
      console.error(`Failed to enable the listener for window stage event changes. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
};
```

## off('windowStageLifecycleEvent')<sup>20+</sup>

off(eventType: 'windowStageLifecycleEvent', callback?: Callback&lt;WindowStageLifecycleEventType&gt;): void

Unsubscribes from the WindowStage lifecycle change event.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| eventType  | string                                                       | Yes  | Event type. The value is fixed at **'windowStageLifecycleEvent'**, indicating the WindowStage lifecycle change event.|
| callback | Callback&lt;[WindowStageLifecycleEventType](arkts-apis-window-e.md#windowstagelifecycleeventtype20)&gt; | No  | Callback used to return the WindowStage lifecycle state. If a value is passed in, the corresponding subscription is canceled. If no value is passed in, all subscriptions to the specified event are canceled.               |

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300005 | This window stage is abnormal. |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    const callback = (windowStageLifecycleEvent: window.WindowStageLifecycleEventType) => {
      // ...
    }
    try {
      windowStage.on('windowStageLifecycleEvent', callback);
    } catch (exception) {
      console.error(`Failed to enable the listener for window stage event changes. Cause code: ${exception.code}, message: ${exception.message}`);
    }
    try {
      windowStage.off('windowStageLifecycleEvent', callback);
      // Unregister all the callbacks that have been registered through on().
      windowStage.off('windowStageLifecycleEvent');
    } catch (exception) {
      console.error(`Failed to disable the listener for window stage event changes. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
};
```

## on('windowStageClose')<sup>14+</sup>

on(eventType: 'windowStageClose', callback: Callback&lt;void&gt;): void

Subscribes to the click event on the close button in the three-button navigation bar of the main window. This API works only in [freeform window](../../windowmanager/window-terminology.md#freeform-window) mode. This event is triggered when the close button in the three-button navigation bar of the main window is clicked. The registered lifecycle callback function [UIAbility.onPrepareToTerminate](../apis-ability-kit/js-apis-app-ability-uiAbility.md#onpreparetoterminate10) is not executed.

If the event is subscribed to multiple times, only the most recently subscribed-to event takes effect.

The callback function in this API is executed synchronously. For asynchronous close events of the main window, refer to [on('windowWillClose')](arkts-apis-window-Window.md#onwindowwillclose15).

If there is an existing event subscribed to by calling [on('windowWillClose')](arkts-apis-window-Window.md#onwindowwillclose15), only the [on('windowWillClose')](arkts-apis-window-Window.md#onwindowwillclose15) API will be responded to.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Window.SessionManager

**Atomic service API**: This API can be used in atomic services since API version 14.

**Device behavior differences**: This API can be properly called on 2-in-1 devices and tablets. If it is called on other device types, error code 801 is returned.

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| eventType  | string                                                       | Yes  | Event type. The value is fixed at **'windowStageClose'**, indicating that the close button in the three-button navigation bar of the main window is clicked|
| callback | Callback&lt;void&gt; | Yes  | Callback invoked when the close button in the upper-right corner of the main window is clicked. It does not return any parameter. The internal logic of the callback function requires a return value of the Boolean type. The return value determines whether to continue to close the main window. The value **true** means not to close the main window, and **false** means to continue to close the main window.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801 | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    try {
      windowStage.on('windowStageClose', () => {
        console.info('Succeeded in enabling the listener for window stage close event.');
        return false;
      });
    } catch (exception) {
      console.error(`Failed to enable the listener for window stage close event. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
};
```

## off('windowStageClose')<sup>14+</sup>

off(eventType: 'windowStageClose', callback?: Callback&lt;void&gt;): void

Unsubscribes from the event indicating that the main window is closed. This API works only in [freeform window](../../windowmanager/window-terminology.md#freeform-window) mode.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Window.SessionManager

**Atomic service API**: This API can be used in atomic services since API version 14.

**Device behavior differences**: This API can be properly called on 2-in-1 devices and tablets. If it is called on other device types, error code 801 is returned.

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| eventType  | string                                                       | Yes  | Event type. The value is fixed at **'windowStageClose'**, indicating that the close button in the three-button navigation bar of the main window is clicked.|
| callback | Callback&lt;void&gt; | No  | Callback invoked when the close button in the upper-right corner of the main window is clicked. It does not return any parameter. The internal logic of the callback function requires a return value of the Boolean type. The return value determines whether to continue to close the main window. The value **true** means not to close the main window, and **false** means to continue to close the main window. If a value is passed in, the corresponding subscription is canceled. If no value is passed in, all subscriptions to the specified event are canceled.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801 | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    const callback = () => {
      // ...
      return false;
    }
    try {
      windowStage.on('windowStageClose', callback);
      windowStage.off('windowStageClose', callback);
      windowStage.off('windowStageClose');
    } catch (exception) {
      console.error(`Failed to disable the listener for window stage close changes. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
};
```

## setDefaultDensityEnabled<sup>12+</sup>

setDefaultDensityEnabled(enabled: boolean): void

Sets whether the main window of the application uses the system's default density. Child windows and system windows will follow the main window's setting. Before calling this API, call [WindowStage.loadContent()](#loadcontent9) to initialize the layout to ensure the correct call sequence.

If this API is not called, the default density is not used.

When the default density is not used, if [setCustomDensity()](#setcustomdensity15) has been called, the window will be re-laid out according to the custom display size changes. Otherwise, it will be re-laid out according to the system display size changes.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name          | Type   | Mandatory| Description                        |
| ---------------- | ------- | ---- | ---------------------------- |
| enabled | boolean | Yes  | Whether to enable the system's default density. **true** to enable, **false** otherwise. When the system's default density is enabled, the window layout does not change with the system display size.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300005 | This window stage is abnormal. |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit'

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
      windowStage.loadContent("pages/page2", (err: BusinessError) => {
        let errCode: number = err.code;
        if (errCode) {
          console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info('onWindowStageCreate');
      try {
        windowStage.setDefaultDensityEnabled(true);
        console.info('Succeeded in loading the content.');
      } catch (exception) {
        console.error(`Failed to set default density enabled. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
};
```

## setCustomDensity<sup>15+</sup>

setCustomDensity(density: number): void

Allows the main window of the application to customize its display size scale factor.

Existing child windows and system windows do not immediately re-layout to match the main window's new scale factor. They will re-layout to reflect this change only when their layout information (such as position, size, and system scale size) changes.

If both this API and [setDefaultDensityEnabled(true)](#setdefaultdensityenabled12) are called, the setting from the last called API will be applied.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name          | Type   | Mandatory| Description                        |
| ---------------- | ------- | ---- | ---------------------------- |
| density | number | Yes  | Custom display size scale factor. The value is a floating-point number in the range [0.5, 4.0] or is set to **-1.0**. The value **4.0** indicates the largest permissible display size scale factor for the window, and **-1.0** means that the window uses the system's default display size scale factor.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300005 | This window stage is abnormal. |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    try {
      windowStage.setCustomDensity(-1.0);
    } catch (exception) {
      console.error(`Failed to set custom density. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
};
```

## setCustomDensity<sup>20+</sup>

setCustomDensity(density: number, applyToSubWindow?: boolean): void

Allows the main window of the application to customize its display size scale factor and control when child windows and system windows re-layout to match the main window.

If both this API and [setDefaultDensityEnabled(true)](#setdefaultdensityenabled12) are called, the setting from the last called API will be applied.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name          | Type   | Mandatory| Description                        |
| ---------------- | ------- | ---- | ---------------------------- |
| density | number | Yes  | Custom display size scale factor. The value is a floating-point number in the range [0.5, 4.0] or is set to **-1.0**. The value **4.0** indicates the largest permissible display size scale factor for the window, and **-1.0** means that the window uses the system's default display size scale factor.|
| applyToSubWindow | boolean | No  | Whether existing child windows and system windows should immediately re-layout to match the main window's new scale factor. If this parameter is set to **true**, they will immediately re-layout to match the main window's new scale factor. If this parameter is set to **false**, they will re-layout to reflect this change only when their layout information (such as position, size, and system scale size) changes. The default value is **false**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300005 | This window stage is abnormal. |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    try {
      windowStage.setCustomDensity(2.0);
      windowStage.setCustomDensity(3.0, true);
      windowStage.setCustomDensity(-1.0, false);
    } catch (exception) {
      console.error(`Failed to set custom density. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
};
```

## setWindowModal<sup>14+</sup>

setWindowModal(isModal: boolean): Promise&lt;void&gt;

Enables the modal property of the main window. This API uses a promise to return the result. It works only in [freeform window](../../windowmanager/window-terminology.md#freeform-window) mode.

This API must be called by the main window and the setting takes effect for the main window. After the modal property of the main window is enabled, other main windows in the same application process and their child windows do not respond to user interactions until the main window is closed or the main window's modal property is disabled.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Window.SessionManager

**Device behavior differences**: This API can be properly called on 2-in-1 devices and tablets. If it is called on other device types, error code 801 is returned.

**Parameters**

| Name   | Type   | Mandatory| Description                                         |
| --------- | ------- | ---- | --------------------------------------------- |
| isModal | boolean | Yes  | Whether to enable the modal property of the main window. **true** to enable, **false** otherwise.|


**Return value**

| Type| Description|
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message                      |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002  | This window state is abnormal. |
| 1300003  | This window manager service works abnormally. |
| 1300005 | This window stage is abnormal. |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    try {
      let promise = windowStage.setWindowModal(true);
      promise.then(() => {
        console.info('Succeeded in setting window modal');
      }).catch((err: BusinessError) => {
        console.error(`Failed to set window modal. Cause code: ${err.code}, message: ${err.message}`);
      });
    } catch (exception) {
      console.error(`Failed to set window modal. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

## removeStartingWindow<sup>14+</sup>

removeStartingWindow(): Promise&lt;void&gt;

Allows the application to control the time when the launch page disappears.

This API takes effect only for the application main window when **enable.remove.starting.window** under **metadata** in [abilities](../../quick-start/module-configuration-file.md#abilities) in the **module.json5** file is set to **true**.

If the tag is set to **true**, the system provides timeout protection for the launch page. If this API is not called within 5 seconds, the system automatically removes the launch page.

If the tag is set to **false** or is not configured, this API does not take effect. The launch page will be automatically removed after the first frame of the application is rendered.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Window.SessionManager

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    windowStage.removeStartingWindow().then(() => {
      console.info('Succeeded in removing starting window.');
    }).catch((err: BusinessError) => {
        console.error(`Failed to remove starting window. Cause code: ${err.code}, message: ${err.message}`);
    });
  }
};
```

## setWindowRectAutoSave<sup>14+</sup>

setWindowRectAutoSave(enabled: boolean): Promise&lt;void&gt;

Enables or disables the auto-save feature for the size of the last closed main window. This API uses a promise to return the result.

When the auto-save feature is enabled, within the same UIAbility, the size of the last closed main window is remembered. When this main window is restarted, it will open at the remembered size according to the rules.

The following rules apply in stacking scenarios:

1. If the current instance is a free-form window, the next opened window will adopt the same size when stacked.
2. If the current instance is maximized or in full-screen mode, the next opened window will maintain the maximized state when stacked.

The following table describes the memory rules:

|Last Window State|Memorizing Rule|
|-------------|-------|
|Free-form window|Retains the size/position of the free-form window, rebound if exceeding the workspace.|
|Split-screen window|Retains the size and position of the free-form window before screen splitting.|
|Maximized window|Retains the maximized state.|
|Immersive window|Retains the size and position of the free-form window before immersive mode.|
|Minimized window|Retains the size and position of the free-form window before minimization.|

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Window.SessionManager

**Device behavior differences**: This API can be properly called on 2-in-1 devices. If it is called on other device types, error code 801 is returned.

**Parameters**

| Name   | Type   | Mandatory| Description                                         |
| --------- | ------- | ---- | --------------------------------------------- |
| enabled | boolean | Yes  | Whether to enable the auto-save feature. **true** to enable, **false** otherwise.|


**Return value**

| Type| Description|
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message                      |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002  | This window state is abnormal. |
| 1300003  | This window manager service works abnormally. |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    try {
      let promise = windowStage.setWindowRectAutoSave(true);
      promise.then(() => {
        console.info('Succeeded in setting window rect auto-save');
      }).catch((err: BusinessError) => {
        console.error(`Failed to set window rect auto-save. Cause code: ${err.code}, message: ${err.message}`);
      });
    } catch (exception) {
      console.error(`Failed to set window rect auto-save. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

## setWindowRectAutoSave<sup>17+</sup>

setWindowRectAutoSave(enabled: boolean, isSaveBySpecifiedFlag: boolean): Promise&lt;void&gt;

Enables or disables the auto-save feature for the size of the main window. This API uses a promise to return the result.

Within the same UIAbility, you can remember the size of the last closed main window, or you can remember the size of each main window individually. The individual auto-save feature for each main window size is only available when the UIAbility launch mode is set to **specified** and the **isSaveBySpecifiedFlag** parameter is set to **true**.

When the auto-save feature is enabled, the size of the main window when it is closed is remembered. When the main window is restarted, it will open at the remembered size according to the rules.

The following table describes the memory rules:

|Last Window State|Memorizing Rule|
|-------------|-------|
|Free-form window|Retains the size/position of the free-form window, rebound if exceeding the workspace.|
|Split-screen window|Retains the size and position of the free-form window before screen splitting.|
|Maximized window|Retains the maximized state.|
|Immersive window|Retains the size and position of the free-form window before immersive mode.|
|Minimized window|Retains the size and position of the free-form window before minimization.|

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 17.

**System capability**: SystemCapability.Window.SessionManager

**Device behavior differences**: This API can be properly called on 2-in-1 devices. If it is called on other device types, error code 801 is returned.

**Parameters**

| Name   | Type   | Mandatory| Description                                         |
| --------- | ------- | ---- | --------------------------------------------- |
| enabled | boolean | Yes  | Whether to enable the auto-save feature. **true** to enable, **false** otherwise.|
| isSaveBySpecifiedFlag | boolean | Yes  | Whether to enable the individual auto-save feature when the UIAbility launch mode is set to **specified**. **true** to enable, **false** otherwise.|


**Return value**

| Type| Description|
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message                      |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801      | Capability not supported. Function setWindowRectAutoSave can not work correctly due to limited device capabilities. |
| 1300002  | This window state is abnormal. |
| 1300003  | This window manager service works abnormally. |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    try {
      let promise = windowStage.setWindowRectAutoSave(true, true);
      promise.then(() => {
        console.info('Succeeded in setting window rect auto-save');
      }).catch((err: BusinessError) => {
        console.error(`Failed to set window rect auto-save. Cause code: ${err.code}, message: ${err.message}`);
      });
    } catch (exception) {
      console.error(`Failed to set window rect auto-save. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

## isWindowRectAutoSave<sup>14+</sup>

isWindowRectAutoSave(): Promise&lt;boolean&gt;

Checks whether the auto-save feature is enabled for the main window's size. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Window.SessionManager

**Device behavior differences**: This API can be properly called on 2-in-1 devices. If it is called on other device types, error code 801 is returned.

**Return value**

| Type| Description|
| ---------------------- | ------------------------------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise used to return the result. **true** if enabled, **false** otherwise.|

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    try {
      let promise = windowStage.isWindowRectAutoSave();
      promise.then((data) => {
        console.info(`Succeeded in checking whether the window support the rect auto-save. Data: ${data}`);
      }).catch((err: BusinessError) => {
        console.error(`Failed to check whether the window support the rect auto-save. Cause code: ${err.code}, message: ${err.message}`);
      });
    } catch (exception) {
      console.error(`Failed to check whether the window support the rect auto-save. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

## setSupportedWindowModes<sup>15+</sup>

setSupportedWindowModes(supportedWindowModes: Array<bundleManager.SupportWindowMode>): Promise&lt;void&gt;

Sets the supported window modes of the main window. This API uses a promise to return the result. It works only in [freeform window](../../windowmanager/window-terminology.md#freeform-window) mode.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Window.SessionManager

**Device behavior differences**: This API can be properly called on 2-in-1 devices and tablets. If it is called on other device types, error code 801 is returned.

**Parameters**

| Name   | Type   | Mandatory| Description                                         |
| --------- | ------- | ---- | --------------------------------------------- |
| supportedWindowModes | Array&lt;[bundleManager.SupportWindowMode](../apis-ability-kit/js-apis-bundleManager.md#supportwindowmode)&gt; | Yes  | Supported window modes.<br>- **FULL_SCREEN**: full-screen mode.<br>- **FLOATING**: floating window mode.<br>- **SPLIT**: split-screen mode. **FULL_SCREEN** or **FLOATING** must be used together. Configuring only **SPLIT** is not supported.<br> Note: The values of the **SupportWindowMode** field in the array should not conflict with the values of the **supportWindowMode** field under [abilities](../../quick-start/module-configuration-file.md#abilities) of the [module.json5 file](../../quick-start/module-configuration-file.md) corresponding to this UIAbility, or with the values of the **supportWindowModes** field in [StartOptions](../apis-ability-kit/js-apis-app-ability-startOptions.md#startoptions). In case of a conflict, the window support mode set by this parameter will take precedence.|

**Return value**

| Type| Description|
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message                      |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002  | This window state is abnormal. |
| 1300003  | This window manager service works abnormally. |

**Example**

```ts
// EntryAbility.ets
import { UIAbility, bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    try {
      let promise = windowStage.setSupportedWindowModes([
        bundleManager.SupportWindowMode.FULL_SCREEN,
        bundleManager.SupportWindowMode.SPLIT,
        bundleManager.SupportWindowMode.FLOATING
      ]);
      promise.then(() => {
        console.info('Succeeded in setting window support modes');
      }).catch((err: BusinessError) => {
        console.error(`Failed to set window support modes. Cause code: ${err.code}, message: ${err.message}`);
      });
    } catch (exception) {
      console.error(`Failed to set window support modes. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

## setSupportedWindowModes<sup>20+</sup>

setSupportedWindowModes(supportedWindowModes: Array<bundleManager.SupportWindowMode>, grayOutMaximizeButton: boolean): Promise&lt;void&gt;

Sets the supported window modes for the main window and optionally disables the maximize button. This API uses a promise to return the result. It takes effect only in [freeform window](../../windowmanager/window-terminology.md#freeform-window) mode.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Window.SessionManager

**Device behavior differences**: This API can be properly called on 2-in-1 devices and tablets. If it is called on other device types, error code 801 is returned.

**Parameters**

| Name   | Type   | Mandatory| Description                                         |
| --------- | ------- | ---- | --------------------------------------------- |
| supportedWindowModes | Array&lt;[bundleManager.SupportWindowMode](../apis-ability-kit/js-apis-bundleManager.md#supportwindowmode)&gt; | Yes  | Supported window modes.<br>- **FULL_SCREEN**: full-screen mode.<br>- **FLOATING**: floating window mode.<br>- **SPLIT**: split-screen mode. **FULL_SCREEN** or **FLOATING** must be used together. Configuring only **SPLIT** is not supported.<br> Note: The values of the **SupportWindowMode** field in the array should not conflict with the value of the **supportWindowMode** field under [abilities](../../quick-start/module-configuration-file.md#abilities) or **supportWindowModes** field in [StartOptions](../apis-ability-kit/js-apis-app-ability-startOptions.md#startoptions) of the [module.json5 file](../../quick-start/module-configuration-file.md) corresponding to this UIAbility. In case of a conflict, the window support mode set by this parameter will take precedence.|
| grayOutMaximizeButton | boolean | Yes| Whether to display the main window and disable its maximize button. The value **true** means to display the main window and disable its maximize button, and **false** means the opposite. This parameter takes effect only when **supportedWindowModes** is not set to **FULL_SCREEN**.|

**Return value**

| Type| Description|
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message                      |
| -------- | ------------------------------ |
| 801      | Capability not supported. Function setSupportedWindowModes can not work correctly due to limited device capabilities. |
| 1300002  | This window state is abnormal. |
| 1300003  | This window manager service works abnormally. |
| 1300016  | Parameter error. Possible cause: 1. Invalid parameter range. 2. Invalid parameter length. 3. Incorrect parameter format. |

**Example**

```ts
// EntryAbility.ets
import { UIAbility, bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    try {
      let promise = windowStage.setSupportedWindowModes([
        bundleManager.SupportWindowMode.FULL_SCREEN,
        bundleManager.SupportWindowMode.SPLIT,
        bundleManager.SupportWindowMode.FLOATING
      ], true);
      promise.then(() => {
        console.info('Succeeded in setting window support modes');
      }).catch((err: BusinessError) => {
        console.error(`Failed to set window support modes. Cause code: ${err.code}, message: ${err.message}`);
      });
    } catch (exception) {
      console.error(`Failed to set window support modes. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```
