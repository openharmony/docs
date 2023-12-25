# @ohos.app.ability.AutoFillExtensionAbility (AutoFillExtensionAbility)

The AutoFillExtensionAbility module, inherited from [ExtensionAbility](js-apis-app-ability-extensionAbility.md), provides APIs for automatically filling in and saving accounts and passwords.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import AutoFillExtensionAbility from '@ohos.app.ability.AutoFillExtensionAbility';
```

## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| context | [AutoFillExtensionContext](js-apis-inner-application-autoFillExtensionContext.md)  | Yes| No| Context of the AutoFillExtensionAbility. This context is inherited from **ExtensionContext**.|


## AutoFillExtensionAbility.onCreate

onCreate(): void

Called when an AutoFillExtensionAbility is created.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Example**

  ```ts
  import AutoFillExtensionAbility from '@ohos.app.ability.AutoFillExtensionAbility';
  import hilog from '@ohos.hilog';

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

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| session | [UIExtensionContentSession](js-apis-app-ability-uiExtensionContentSession.md)  | Yes| No| UI content information related to the AutoFillExtensionAbility.|
| request | [FillRequest](js-apis-inner-application-autoFillRequest.md#fillrequest)  | Yes| No| Data to be automatically filled in.|
| callback | [FillRequestCallback](js-apis-inner-application-autoFillRequest.md#fillrequestcallback)  | Yes| No| Callback used for the auto-fill request.|

**Example**

  ```ts
  import AutoFillExtensionAbility from '@ohos.app.ability.AutoFillExtensionAbility';
  import UIExtensionContentSession from '@ohos.app.ability.UIExtensionContentSession';
  import autoFillManager from '@ohos.app.ability.autoFillManager';
  import hilog from '@ohos.hilog';

  class MyAutoFillExtensionAbility extends AutoFillExtensionAbility {
    onFillRequest(session: UIExtensionContentSession,
                  request: autoFillManager.FillRequest,
                  callback: autoFillManager.FillRequestCallback) {
      hilog.info(0x0000, 'testTag', '%{public}s', 'autofill onFillRequest');
      hilog.info(0x0000, 'testTag', 'fill requestCallback: %{public}s', JSON.stringify(callback));
      hilog.info(0x0000, 'testTag', "get request viewData: ", JSON.stringify(request.viewData));
      try {
        let storage_fill = new LocalStorage(
          {
            'session': session,
            'message': "AutoFill Page",
            'fillCallback': callback,
            'viewData': request.viewData,
            'context': this.context,
          });
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

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| session | [UIExtensionContentSession](js-apis-app-ability-uiExtensionContentSession.md)  | Yes| No| UI content information related to the AutoFillExtensionAbility.|
| request | [SaveRequest](js-apis-inner-application-autoFillRequest.md#saverequest)  | Yes| No| Data to be saved.|
| callback | [SaveRequestCallback](js-apis-inner-application-autoFillRequest.md#saverequestcallback)  | Yes| No| Callback used for the saving request.|

**Example**

  ```ts
  import AutoFillExtensionAbility from '@ohos.app.ability.AutoFillExtensionAbility';
  import UIExtensionContentSession from '@ohos.app.ability.UIExtensionContentSession';
  import autoFillManager from '@ohos.app.ability.autoFillManager';
  import hilog from '@ohos.hilog';

  class MyAutoFillExtensionAbility extends AutoFillExtensionAbility {
    onSaveRequest(session : UIExtensionContentSession,
                  request : autoFillManager.SaveRequest,
                  callback : autoFillManager.SaveRequestCallback) {
      hilog.info(0x0000, 'testTag', '%{public}s', 'onSaveRequest');
      try {
        let storage_save = new LocalStorage(
          {
            'session': session,
            'message': "AutoFill Page",
            'callback': callback,
            'viewData': request.viewData
          });
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
  import AutoFillExtensionAbility from '@ohos.app.ability.AutoFillExtensionAbility';
  import UIExtensionContentSession from '@ohos.app.ability.UIExtensionContentSession';
  import hilog from '@ohos.hilog';

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
  import AutoFillExtensionAbility from '@ohos.app.ability.AutoFillExtensionAbility';
  import hilog from '@ohos.hilog';

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
  import AutoFillExtensionAbility from '@ohos.app.ability.AutoFillExtensionAbility';
  import hilog from '@ohos.hilog';

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
  import AutoFillExtensionAbility from '@ohos.app.ability.AutoFillExtensionAbility';
  import hilog from '@ohos.hilog';

  class MyAutoFillExtensionAbility extends AutoFillExtensionAbility {
    onDestroy() {
      hilog.info(0x0000, 'testTag', '%{public}s', 'onDestroy');
    }
  }
  ```
