# formfwk Subsystem Changelog

## cl.formfwk.1 Some APIs Moved from @ohos.app.form.formHost.d.ts and Their Permission Changed

1. APIs used for listening for and obtaining dynamic widget information are moved from **@ohos.app.form.formHost.d.ts** to **@ohos.app.form.formObserver.d.ts**.
2. The permission for these APIs is changed from **ohos.permission.REQUIRE_FORM** to **ohos.permission.OBSERVE_FORM_RUNNING**.

**Change Impact**

Applications that use the involved ArkTS APIs may have compatibility issues.

**Key API/Component Changes**

|     API     | Home .d.ts File Before Modification| Home .d.ts File After Modification| Permission Required Before Modification| Permission Required After Modification|
|   --------    |   --------    |   --------    | --------      | --------  |
| on('formAdd') | @ohos.app.form.formHost.d.ts | @ohos.app.form.formObserver.d.ts | ohos.permission.REQUIRE_FORM | ohos.permission.OBSERVE_FORM_RUNNING | @ohos.app.form.formHost.d.ts | @ohos.app.form.formObserver.d.ts | ohos.permission.REQUIRE_FORM|ohos.permission.OBSERVE_FORM_RUNNING|
| off('formAdd')| @ohos.app.form.formHost.d.ts | @ohos.app.form.formObserver.d.ts | ohos.permission.REQUIRE_FORM|ohos.permission.OBSERVE_FORM_RUNNING | @ohos.app.form.formHost.d.ts | @ohos.app.form.formObserver.d.ts | ohos.permission.REQUIRE_FORM | ohos.permission.OBSERVE_FORM_RUNNING |
| on('formRemove') | @ohos.app.form.formHost.d.ts | @ohos.app.form.formObserver.d.ts | ohos.permission.REQUIRE_FORM | ohos.permission.OBSERVE_FORM_RUNNING | @ohos.app.form.formHost.d.ts | @ohos.app.form.formObserver.d.ts | ohos.permission.REQUIRE_FORM | ohos.permission.OBSERVE_FORM_RUNNING |
| off('formRemove') | @ohos.app.form.formHost.d.ts | @ohos.app.form.formObserver.d.ts | ohos.permission.REQUIRE_FORM | ohos.permission.OBSERVE_FORM_RUNNING | @ohos.app.form.formHost.d.ts | @ohos.app.form.formObserver.d.ts | ohos.permission.REQUIRE_FORM | ohos.permission.OBSERVE_FORM_RUNNING |
| on('notifyVisible') | @ohos.app.form.formHost.d.ts | @ohos.app.form.formObserver.d.ts | ohos.permission.REQUIRE_FORM | ohos.permission.OBSERVE_FORM_RUNNING | @ohos.app.form.formHost.d.ts | @ohos.app.form.formObserver.d.ts | ohos.permission.REQUIRE_FORM | ohos.permission.OBSERVE_FORM_RUNNING |
| off('notifyVisible') | @ohos.app.form.formHost.d.ts | @ohos.app.form.formObserver.d.ts | ohos.permission.REQUIRE_FORM | ohos.permission.OBSERVE_FORM_RUNNING | @ohos.app.form.formHost.d.ts | @ohos.app.form.formObserver.d.ts | ohos.permission.REQUIRE_FORM | ohos.permission.OBSERVE_FORM_RUNNING |
| on('notifyInvisible') | @ohos.app.form.formHost.d.ts | @ohos.app.form.formObserver.d.ts | ohos.permission.REQUIRE_FORM | ohos.permission.OBSERVE_FORM_RUNNING | @ohos.app.form.formHost.d.ts | @ohos.app.form.formObserver.d.ts | ohos.permission.REQUIRE_FORM | ohos.permission.OBSERVE_FORM_RUNNING |
| off('notifyInvisible') | @ohos.app.form.formHost.d.ts | @ohos.app.form.formObserver.d.ts | ohos.permission.REQUIRE_FORM | ohos.permission.OBSERVE_FORM_RUNNING | @ohos.app.form.formHost.d.ts | @ohos.app.form.formObserver.d.ts | ohos.permission.REQUIRE_FORM | ohos.permission.OBSERVE_FORM_RUNNING |
| getRunningFormInfos | @ohos.app.form.formHost.d.ts | @ohos.app.form.formObserver.d.ts | ohos.permission.REQUIRE_FORM | ohos.permission.OBSERVE_FORM_RUNNING | @ohos.app.form.formHost.d.ts | @ohos.app.form.formObserver.d.ts | ohos.permission.REQUIRE_FORM | ohos.permission.OBSERVE_FORM_RUNNING |
| getRunningFormInfosByFilter | @ohos.app.form.formHost.d.ts | @ohos.app.form.formObserver.d.ts | ohos.permission.REQUIRE_FORM | ohos.permission.OBSERVE_FORM_RUNNING | @ohos.app.form.formHost.d.ts | @ohos.app.form.formObserver.d.ts | ohos.permission.REQUIRE_FORM | ohos.permission.OBSERVE_FORM_RUNNING |
| getRunningFormInfoById | @ohos.app.form.formHost.d.ts | @ohos.app.form.formObserver.d.ts | ohos.permission.REQUIRE_FORM | ohos.permission.OBSERVE_FORM_RUNNING | @ohos.app.form.formHost.d.ts | @ohos.app.form.formObserver.d.ts | ohos.permission.REQUIRE_FORM | ohos.permission.OBSERVE_FORM_RUNNING |


**Adaptation Guide**

Adapt your application code accordingly. To use these APIs in OpenHarmony 4.0.9.5 and later versions, import **@ohos.app.form.formObserver.d.ts** and request the **ohos.permission.OBSERVE_FORM_RUNNING** permission.

**Example**
```ts
import formObserver from '@ohos.app.form.formObserver';
import formInfo from '@ohos.app.form.formInfo';
import Base from '@ohos.base';

try {
  formObserver.getRunningFormInfos((error: Base.BusinessError, data: formInfo.RunningFormInfo[]) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    } else {
      console.log('formHost getRunningFormInfos, data: ${JSON.stringify(data)}');
    }
  }, 'com.example.ohos.formjsdemo');
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## cl.formfwk.2 Adjusted the Parameter Sequence of Event Subscription and Unsubscription APIs (on/off)

The **callback** parameter is moved as the last parameter in the event subscription and unsubscription APIs (**on**/**off**).

**Change Impact**

Applications that use the involved ArkTS APIs may have compatibility issues.

**Key API/Component Changes**

Before change:

```ts
function on(type: 'formAdd', observerCallback: Callback<formInfo.RunningFormInfo>, bundleName?: string): void;
function off(type: 'formAdd', observerCallback?: Callback<formInfo.RunningFormInfo>, bundleName?: string): void;

function on(type: 'formRemove', observerCallback: Callback<formInfo.RunningFormInfo>, bundleName?: string): void;
function off(type: 'formRemove', observerCallback?: Callback<formInfo.RunningFormInfo>, bundleName?: string): void;

function on(
    type: 'notifyVisible',
    observerCallback: Callback<Array<formInfo.RunningFormInfo>>,
    hostBundleName?: string
  ): void;
function off(
    type: 'notifyVisible',
    observerCallback?: Callback<Array<formInfo.RunningFormInfo>>,
    hostBundleName?: string
  ): void;

function on(
    type: 'notifyInvisible',
    observerCallback: Callback<Array<formInfo.RunningFormInfo>>,
    hostBundleName?: string
  ): void;
function off(
    type: 'notifyInvisible',
    observerCallback?: Callback<Array<formInfo.RunningFormInfo>>,
    hostBundleName?: string
  ): void;
```

After change:

```ts
function on(type: 'formAdd', observerCallback: Callback<formInfo.RunningFormInfo>): void;
function on(type: 'formAdd', hostBundleName: string, observerCallback: Callback<formInfo.RunningFormInfo>): void;
function off(type: 'formAdd', hostBundleName?: string, observerCallback?: Callback<formInfo.RunningFormInfo>): void;

function on(type: 'formRemove', observerCallback: Callback<formInfo.RunningFormInfo>): void;
function on(type: 'formRemove', hostBundleName: string, observerCallback: Callback<formInfo.RunningFormInfo>): void;
function off(type: 'formRemove', hostBundleName?: string, observerCallback?: Callback<formInfo.RunningFormInfo>): void;

function on(type: 'notifyVisible', observerCallback: Callback<Array<formInfo.RunningFormInfo>>): void;
function on(
    type: 'notifyVisible',
    hostBundleName: string,
    observerCallback: Callback<Array<formInfo.RunningFormInfo>>
  ): void;
function off(
    type: 'notifyVisible',
    hostBundleName?: string,
    observerCallback?: Callback<Array<formInfo.RunningFormInfo>>
  ): void;

function on(type: 'notifyInvisible', observerCallback: Callback<Array<formInfo.RunningFormInfo>>): void;
function on(
    type: 'notifyInvisible',
    hostBundleName: string,
    observerCallback: Callback<Array<formInfo.RunningFormInfo>>,
  ): void;
function off(
    type: 'notifyInvisible',
    hostBundleName?: string,
    observerCallback?: Callback<Array<formInfo.RunningFormInfo>>
  ): void;
```


**Adaptation Guide**

Adapt your application code accordingly. In OpenHarmony 4.0.9.5 and later versions, pass in **callback** as the last parameter when calling these APIs.

**Example**
```ts
import formObserver from '@ohos.app.form.formObserver';

let bundleName = 'ohos.samples.FormApplication';
let callback = function(data) {
  console.log('a new form added, data: ${JSON.stringify(data)');
}

formHost.on('formAdd', callback);
formHost.on('formAdd', bundleName, callback);
```
