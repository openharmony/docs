# formfwk子系统ChangeLog

## cl.formfwk.1 @ohos.app.form.formHost.d.ts部分接口移出，接口权限变动

1. @ohos.app.form.formHost.d.ts中涉及监听和获取卡片动态信息的接口移至@ohos.app.form.formObserver.d.ts;
2. 涉及接口需申请权限由ohos.permission.REQUIRE_FORM修改为ohos.permission.OBSERVE_FORM_RUNNING。

**变更影响**

对于已发布的ArkTS接口，可能影响三方应用的兼容性。

**关键的接口/组件变更**

|     接口      | 修改前所属d.ts | 修改后所属d.ts | 修改前所需权限 | 修改后所需权限 |
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


**适配指导**

已使用相关接口开发的应用工程，需要对接口进行适配。从OpenHarmony 4.0.9.5版本起，相关接口使用应导入@ohos.app.form.formObserver.d.ts，并申请ohos.permission.OBSERVE_FORM_RUNNING权限。

**示例：**
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

## cl.formfwk.2 事件订阅，取消订阅相关接口（on/off）参数顺序调整

事件订阅，取消订阅相关接口（on/off）中的callback调整为接口最后一个参数。

**变更影响**

对于已发布的ArkTS接口，可能影响三方应用的兼容性。

**关键的接口/组件变更**

修改前的接口原型：

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

修改后的接口原型：

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


**适配指导**

已使用相关接口开发的应用工程，需要对接口进行适配。从OpenHarmony 4.0.9.5版本起，相关接口使用应注意入参顺序的调整，将callback作为最后一个参数进行接口调用。

**示例：**
```ts
import formObserver from '@ohos.app.form.formObserver';

let bundleName = 'ohos.samples.FormApplication';
let callback = function(data) {
  console.log('a new form added, data: ${JSON.stringify(data)');
}

formHost.on('formAdd', callback);
formHost.on('formAdd', bundleName, callback);
```