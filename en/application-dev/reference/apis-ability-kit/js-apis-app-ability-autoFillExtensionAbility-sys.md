# @ohos.app.ability.AutoFillExtensionAbility (AutoFillExtensionAbility) (System API)

The AutoFillExtensionAbility module, inherited from [ExtensionAbility](js-apis-app-ability-extensionAbility.md), provides APIs for automatically filling in and saving accounts and passwords.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
>
> The APIs of this module can be used only in the stage model.
>
> The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { AutoFillExtensionAbility } from '@kit.AbilityKit';
```

## Properties

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| context | [AutoFillExtensionContext](js-apis-inner-application-autoFillExtensionContext-sys.md)  | Yes| No| Context of the AutoFillExtensionAbility. This context is inherited from **ExtensionContext**.|


## AutoFillExtensionAbility.onCreate

onCreate(): void

Called when an AutoFillExtensionAbility is created.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Example**

```ts
import { AutoFillExtensionAbility } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

class MyAutoFillExtensionAbility extends AutoFillExtensionAbility {
  onCreate() {
    hilog.info(0x0000, 'testTag', '%{public}s', 'onCreate');
  }
}
```

## AutoFillExtensionAbility.onFillRequest

onFillRequest(session: UIExtensionContentSession, request: FillRequest, callback: FillRequestCallback): void

Called when an auto-fill request is initiated or a password is generated.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| session | [UIExtensionContentSession](js-apis-app-ability-uiExtensionContentSession.md)  | Yes| UI content information related to the AutoFillExtensionAbility.|
| request | [FillRequest](js-apis-inner-application-autoFillRequest-sys.md#fillrequest)  | Yes| Data to be automatically filled in.|
| callback | [FillRequestCallback](js-apis-inner-application-autoFillRequest-sys.md#fillrequestcallback)  | Yes| Callback used for the auto-fill request.|

**Example**

```ts
import { AutoFillExtensionAbility, UIExtensionContentSession, autoFillManager, common } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

class MyAutoFillExtensionAbility extends AutoFillExtensionAbility {
  onFillRequest(session: UIExtensionContentSession,
                request: autoFillManager.FillRequest,
                callback: autoFillManager.FillRequestCallback) {
    hilog.info(0x0000, 'testTag', '%{public}s', 'autofill onFillRequest');
    hilog.info(0x0000, 'testTag', 'fill requestCallback: %{public}s', JSON.stringify(callback));
    hilog.info(0x0000, 'testTag', 'get request viewData: ', JSON.stringify(request.viewData));
    try {
      let localStorageData: Record<string, UIExtensionContentSession | string | autoFillManager.FillRequestCallback |
      autoFillManager.ViewData | common.AutoFillExtensionContext> = {
        'session': session,
        'message': 'AutoFill Page',
        'fillCallback': callback,
        'viewData': request.viewData,
        'context': this.context,
      };
      let storage_fill = new LocalStorage(localStorageData);
      if (session) {
        session.loadContent('pages/SelectorList', storage_fill);
      } else {
        hilog.error(0x0000, 'testTag', '%{public}s', 'session is null');
      }
    } catch (err) {
      hilog.error(0x0000, 'testTag', '%{public}s', 'failed to load content');
    }
  }
}
```

## AutoFillExtensionAbility.onSaveRequest

onSaveRequest(session: UIExtensionContentSession, request: SaveRequest, callback: SaveRequestCallback): void

Called when automatic or manual saving is initiated.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| session | [UIExtensionContentSession](js-apis-app-ability-uiExtensionContentSession.md)  | Yes| UI content information related to the AutoFillExtensionAbility.|
| request | [SaveRequest](js-apis-inner-application-autoFillRequest-sys.md#saverequest)  | Yes| Data to be saved.|
| callback | [SaveRequestCallback](js-apis-inner-application-autoFillRequest-sys.md#saverequestcallback)  | Yes| Callback used for the saving request.|

**Example**

```ts
import { AutoFillExtensionAbility, UIExtensionContentSession, autoFillManager, common } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

class MyAutoFillExtensionAbility extends AutoFillExtensionAbility {
  onSaveRequest(session : UIExtensionContentSession,
                request : autoFillManager.SaveRequest,
                callback : autoFillManager.SaveRequestCallback) {
    hilog.info(0x0000, 'testTag', '%{public}s', 'onSaveRequest');
    try {
      let localStorageData: Record<string, UIExtensionContentSession | string | autoFillManager.SaveRequestCallback |
      autoFillManager.ViewData | common.AutoFillExtensionContext> = {
        'session': session,
        'message': 'AutoFill Page',
        'fillCallback': callback,
        'viewData': request.viewData,
        'context': this.context,
      };
      let storage_save = new LocalStorage(localStorageData);
      if (session) {
        session.loadContent('pages/SavePage', storage_save);
      } else {
        hilog.error(0x0000, 'testTag', '%{public}s', 'session is null');
      }
    } catch (err) {
      hilog.error(0x0000, 'testTag', '%{public}s', 'failed to load content');
    }
  }
}
```

## AutoFillExtensionAbility.onUpdateRequest<sup>12+</sup>

onUpdateRequest(request: UpdateRequest): void

Called when an update request is received.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| request | [UpdateRequest](js-apis-inner-application-autoFillRequest-sys.md#updaterequest12)  | Yes| Update request.|

**Example**

```ts
import { AutoFillExtensionAbility, autoFillManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

class MyAutoFillExtensionAbility extends AutoFillExtensionAbility {
  onUpdateRequest(request: autoFillManager.UpdateRequest) {
    hilog.info(0x0000, 'testTag', '%{public}s', 'on update request, view data is: %{public}s',
      JSON.stringify(request.viewData));
  }
}
```

## AutoFillExtensionAbility.onSessionDestroy

onSessionDestroy(session: UIExtensionContentSession): void

Called when a **UIExtensionContentSession** instance is destroyed for this AutoFillExtensionAbility.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| session | [UIExtensionContentSession](js-apis-app-ability-uiExtensionContentSession.md) | Yes| UI content information related to the AutoFillExtensionAbility.|

**Example**

```ts
import { AutoFillExtensionAbility, UIExtensionContentSession } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

class MyAutoFillExtensionAbility extends AutoFillExtensionAbility {
  onSessionDestroy(session : UIExtensionContentSession) {
    hilog.info(0x0000, 'testTag', '%{public}s', 'onSessionDestroy');
  }
}
```

## AutoFillExtensionAbility.onForeground

onForeground(): void

Called when this AutoFillExtensionAbility is switched from the background to the foreground.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Example**

```ts
import { AutoFillExtensionAbility } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

class MyAutoFillExtensionAbility extends AutoFillExtensionAbility {
  onForeground() {
    hilog.info(0x0000, 'testTag', '%{public}s', 'onForeground');
  }
}
```

## AutoFillExtensionAbility.onBackground

onBackground(): void

Called when this AutoFillExtensionAbility is switched from the foreground to the background.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Example**

```ts
import { AutoFillExtensionAbility } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

class MyAutoFillExtensionAbility extends AutoFillExtensionAbility {
  onBackground() {
    hilog.info(0x0000, 'testTag', '%{public}s', 'onBackground');
  }
}
```

## AutoFillExtensionAbility.onDestroy

onDestroy(): void | Promise&lt;void&gt;

Called to clear resources when this AutoFillExtensionAbility is destroyed. This API either returns the result directly or uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Return value**

| Type                                 | Description                           |
| ------------------------------------- | ------------------------------- |
| void&nbsp;\|&nbsp;Promise&lt;void&gt; | Returns no value or returns a Promise.|

**Example**

```ts
import { AutoFillExtensionAbility } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

class MyAutoFillExtensionAbility extends AutoFillExtensionAbility {
  onDestroy() {
    hilog.info(0x0000, 'testTag', '%{public}s', 'onDestroy');
  }
}
```
