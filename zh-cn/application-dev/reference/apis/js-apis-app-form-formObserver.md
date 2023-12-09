# @ohos.app.form.formObserver (formObserver)

formObserver模块提供了卡片监听方相关接口的能力，包括对同一用户下安装的卡片新增、删除、可见性变化事件的订阅和取消订阅，获取正在运行的卡片信息等。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口均为系统接口。

## 导入模块

```ts
import formObserver from '@ohos.app.form.formObserver';
```

## on('formAdd')

 on(type: 'formAdd', observerCallback: Callback&lt;formInfo.RunningFormInfo&gt;): void

订阅卡片新增事件。使用callback异步回调，返回当前新增卡片的[RunningFormInfo](js-apis-app-form-formInfo.md)。

**需要权限**：ohos.permission.OBSERVE_FORM_RUNNING

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| type | string | 是   | 填写'formAdd'，表示卡片新增事件。 |
| observerCallback | Callback&lt;formInfo.RunningFormInfo&gt; | 是 | 回调函数。返回新增卡片的RunningFormInfo。 |

**示例：**

```ts
import formObserver from '@ohos.app.form.formObserver';
import formInfo from '@ohos.app.form.formInfo';

formObserver.on('formAdd', (data: formInfo.RunningFormInfo) => {
  console.log(`a new form added, data: ${JSON.stringify(data)}`);
});
```

## on('formAdd')

 on(type: 'formAdd', hostBundleName: string, observerCallback: Callback&lt;formInfo.RunningFormInfo&gt;): void

订阅卡片新增事件。使用callback异步回调，返回指定卡片使用方应用新增卡片的[RunningFormInfo](js-apis-app-form-formInfo.md)。

**需要权限**：ohos.permission.OBSERVE_FORM_RUNNING

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| type | string | 是   | 填写'formAdd'，表示卡片新增事件。 |
| hostBundleName | string | 是 | 指定订阅卡片使用方包的bundleName。缺省则订阅所有卡片使用方的卡片新增事件。 |
| observerCallback | Callback&lt;formInfo.RunningFormInfo&gt; | 是 | 回调函数。返回新增卡片的RunningFormInfo。 |


**示例：**

```ts
import formObserver from '@ohos.app.form.formObserver';
import formInfo from '@ohos.app.form.formInfo';

let bundleName: string = 'ohos.samples.FormApplication';

formObserver.on('formAdd', bundleName, (data: formInfo.RunningFormInfo) => {
  console.log(`a new form added, data: ${JSON.stringify(data)}`);
});
```

## off('formAdd')

 off(type: "formAdd", hostBundleName?: string, observerCallback?: Callback&lt;formInfo.RunningFormInfo&gt;): void

取消订阅卡片新增事件。使用callback异步回调，返回当前新增卡片的[RunningFormInfo](js-apis-app-form-formInfo.md)。

**需要权限**：ohos.permission.OBSERVE_FORM_RUNNING

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| type | string | 是   | 填写'formAdd'，表示卡片新增事件。 |
| hostBundleName | string | 否 | 指定订阅卡片使用方包的bundleName。<br> 填写该参数时，与注册时填写bundleName的on接口对应。<br> 缺省则订阅所有卡片使用方的卡片删除事件，与注册时未填写bundleName的on接口相对应。 |
| observerCallback | Callback&lt;formInfo.RunningFormInfo&gt; | 否 | 回调函数。返回卡片RunningFormInfo。缺省时，表示注销对应已注册事件回调。<br> 需与对应on('formAdd')的callback一致。|


**示例：**

```ts
import formObserver from '@ohos.app.form.formObserver';
import formInfo from '@ohos.app.form.formInfo';

let bundleName: string = 'ohos.samples.FormApplication';
formObserver.off('formAdd', bundleName, (data: formInfo.RunningFormInfo) => {
  console.log(`a new form added, data: ${JSON.stringify(data)}`);
});

```
> **说明：**
> on('formAdd', callback)与off('formAdd', callback)相对应；
> on('formAdd', bundleName, callback)与off('formAdd', bundleName, callback)相对应；
> 订阅（on）只能由自己对应的取消订阅接口（off）取消。

## on('formRemove')

 on(type: 'formRemove', observerCallback: Callback&lt;formInfo.RunningFormInfo&gt;): void

订阅卡片删除事件。使用callback异步回调，返回当前删除卡片的[RunningFormInfo](js-apis-app-form-formInfo.md)。

**需要权限**：ohos.permission.OBSERVE_FORM_RUNNING

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| type | string | 是   | 填写'formRemove'，表示卡片删除事件。 |
| observerCallback | Callback&lt;formInfo.RunningFormInfo&gt; | 是 | 回调函数。返回删除卡片的RunningFormInfo。 |

**示例：**

```ts
import formObserver from '@ohos.app.form.formObserver';
import formInfo from '@ohos.app.form.formInfo';

formObserver.on('formRemove', (data: formInfo.RunningFormInfo) => {
  console.log(`form deleted, data: ${JSON.stringify(data)}`);
});
```

## on('formRemove')

 on(type: 'formRemove', hostBundleName: string, observerCallback: Callback&lt;formInfo.RunningFormInfo&gt;): void

订阅卡片删除事件。使用callback异步回调，返回指定卡片使用方应用被删除卡片的[RunningFormInfo](js-apis-app-form-formInfo.md)。

**需要权限**：ohos.permission.OBSERVE_FORM_RUNNING

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| type | string | 是   | 填写'formRemove'，表示卡片删除事件。 |
| hostBundleName | string | 是 | 指定订阅卡片使用方包的bundleName。缺省则订阅所有卡片使用方的卡片删除事件。 |
| observerCallback | Callback&lt;formInfo.RunningFormInfo&gt; | 是 | 回调函数。返回删除卡片的RunningFormInfo。 |

**示例：**

```ts
import formObserver from '@ohos.app.form.formObserver';
import formInfo from '@ohos.app.form.formInfo';

let bundleName: string = 'ohos.samples.FormApplication';
formObserver.on('formRemove', bundleName, (data: formInfo.RunningFormInfo) => {
  console.log(`form deleted, data: ${JSON.stringify(data)}`);
});
```

## off('formRemove')

off(type: "formRemove", hostBundleName?: string, observerCallback?: Callback&lt;formInfo.RunningFormInfo&gt;): void

取消订阅卡片删除事件。使用callback异步回调，返回当前删除卡片的[RunningFormInfo](js-apis-app-form-formInfo.md)。

**需要权限**：ohos.permission.OBSERVE_FORM_RUNNING

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| type | string | 是   | 填写'formRemove'，表示卡片删除事件。 |
| hostBundleName | string | 否 | 指定订阅卡片使用方包的bundleName。<br> 填写该参数时，与注册时填写bundleName的on接口对应。<br> 缺省则订阅所有卡片使用方的卡片删除事件，与注册时未填写bundleName的on接口相对应。 |
| observerCallback | Callback&lt;formInfo.RunningFormInfo&gt; | 否 | 回调函数。返回卡片RunningFormInfo。缺省时，表示注销对应已注册事件回调。<br> 需与对应on('formRemove')的callback一致。|

**示例：**

```ts
import formObserver from '@ohos.app.form.formObserver';
import formInfo from '@ohos.app.form.formInfo';

let bundleName: string = 'ohos.samples.FormApplication';
formObserver.off('formRemove', bundleName, (data: formInfo.RunningFormInfo) => {
  console.log(`a new form added, data: ${JSON.stringify(data)}`);
});
```
> **说明：**
> on('formRemove', callback)与off('formRemove', callback)相对应；
> on('formRemove', bundleName, callback)与off('formRemove', bundleName, callback)相对应；
> 订阅（on）只能由自己对应的取消订阅接口（off）取消。

## on('notifyVisible')

 on(type: 'notifyVisible', observerCallback: Callback&lt;Array&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo.md)&gt;&gt;): void

订阅通知卡片可见的事件。

​触发通知卡片可见场景为：调用notifyVisibleForms接口通知对应卡片可见性变更为可见状态

**需要权限**：ohos.permission.OBSERVE_FORM_RUNNING

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                                                         |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type       | string                                                       | 是   | 仅允许填写'notifyVisible'，表示订阅通知卡片可见的事件。      |
| observerCallback   | Callback &lt;Array&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo.md)&gt;&gt; | 是   | 回调函数。返回订阅通知卡片可见的RunningFormInfo。            |

**示例：**

```ts
import formObserver from '@ohos.app.form.formObserver';
import formInfo from '@ohos.app.form.formInfo';

formObserver.on('notifyVisible', (data: formInfo.RunningFormInfo[]) => {
  console.log(`form change visibility, data: ${JSON.stringify(data)}`);
});

```

## on('notifyVisible')

 on(type: 'notifyVisible', hostBundleName: string, observerCallback: Callback&lt;Array&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo.md)&gt;&gt;): void

订阅通知卡片可见的事件。

​触发通知卡片可见场景为：调用notifyVisibleForms接口通知对应卡片可见性变更为可见状态

**需要权限**：ohos.permission.OBSERVE_FORM_RUNNING

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                                                         |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type       | string                                                       | 是   | 仅允许填写'notifyVisible'，表示订阅通知卡片可见的事件。      |
| hostBundleName | string                                                       | 是   | 指定卡片使用方的bundleName，用于订阅卡片在该使用方的可见状态变更事件。 |
| observerCallback   | Callback &lt;Array&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo.md)&gt;&gt; | 是   | 回调函数。返回订阅通知卡片可见的RunningFormInfo。            |


**示例：**

```ts
import formObserver from '@ohos.app.form.formObserver';
import formInfo from '@ohos.app.form.formInfo';

let bundleName: string = 'ohos.samples.FormApplication';
formObserver.on('notifyVisible', bundleName, (data: formInfo.RunningFormInfo[]) => {
  console.log(`form change visibility, data: ${JSON.stringify(data)}`);
});
```

## off('notifyVisible')

 off(type: "notifyVisible", hostBundleName?: string, observerCallback?: Callback&lt;Array&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo.md)&gt;&gt;): void

取消订阅通知卡片可见的事件。

**需要权限**：ohos.permission.OBSERVE_FORM_RUNNING

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                                                         |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type       | string                                                       | 是   | 仅允许填写'notifyVisible'，表示取消订阅通知卡片为可见的事件。 |
| hostBundleName | string                                                       | 否   | 指定卡片使用方的bundleName，用于订阅卡片在该使用方的可见状态变更事件。<br> 填写该参数时，与注册时填写bundleName的on接口对应。 |
| observerCallback   | Callback &lt;Array&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo.md)&gt;&gt; | 否   | 入参，注册时注册进去的callback。缺省时，表示注销对应已注册订阅的回调。<br> 需与对应on('notifyVisible')的callback一致。 |


**示例：**

```ts
import formObserver from '@ohos.app.form.formObserver';
import formInfo from '@ohos.app.form.formInfo';

let bundleName: string = 'ohos.samples.FormApplication';
formObserver.off('notifyVisible', bundleName, (data: formInfo.RunningFormInfo[]) => {
  console.log(`form change visibility, data: ${JSON.stringify(data)}`);
});
```

> **说明：**
> on('notifyVisible', callback)与off('notifyVisible', callback)相对应；
> on('notifyVisible', bundleName, callback)与off('notifyVisible', bundleName, callback)相对应；
> 订阅（on）只能由自己对应的取消订阅接口（off）取消。

## on('notifyInvisible')

 on(type: 'notifyInvisible', observerCallback: Callback&lt;Array&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo.md)&gt;>): void

订阅通知卡片不可见的事件。

​触发通知卡片不可见场景为：调用notifyInvisibleForms接口通知对应卡片可见性变更为不可见状态

**需要权限**：ohos.permission.OBSERVE_FORM_RUNNING

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                                                         |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type       | string                                                       | 是   | 仅允许填写'notifyInvisible'，表示订阅卡片不可见的事件。      |
| observerCallback   | Callback &lt;Array&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo.md)&gt;&gt; | 是   | 回调函数。返回订阅通知卡片不可见的RunningFormInfo。          |

**示例：**

```ts
import formObserver from '@ohos.app.form.formObserver';
import formInfo from '@ohos.app.form.formInfo';

formObserver.on('notifyInvisible', (data: formInfo.RunningFormInfo[]) => {
  console.log(`form change invisibility, data: ${JSON.stringify(data)}`);
});
```


## on('notifyInvisible')

 on(type: 'notifyInvisible', hostBundleName: string, observerCallback: Callback&lt;Array&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo.md)&gt;>): void

订阅通知卡片不可见的事件。

​触发通知卡片不可见场景为：调用notifyInvisibleForms接口通知对应卡片可见性变更为不可见状态

**需要权限**：ohos.permission.OBSERVE_FORM_RUNNING

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                                                         |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type       | string                                                       | 是   | 仅允许填写'notifyInvisible'，表示订阅卡片不可见的事件。      |
| hostBundleName | string                                                       | 是   | 指定卡片使用方的bundleName，用于订阅卡片在该使用方的可见状态变更事件。 |
| observerCallback   | Callback &lt;Array&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo.md)&gt;&gt; | 是   | 回调函数。返回订阅通知卡片不可见的RunningFormInfo。          |

**示例：**

```ts
import formObserver from '@ohos.app.form.formObserver';
import formInfo from '@ohos.app.form.formInfo';

let bundleName: string = 'ohos.samples.FormApplication';
formObserver.on('notifyInvisible', bundleName, (data: formInfo.RunningFormInfo[]) => {
  console.log(`form change invisibility, data: ${JSON.stringify(data)}`);
});
```

## off('notifyInvisible')

 off(type: "notifyInvisible", hostBundleName?: string, observerCallback?: Callback&lt;Array&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo.md)>&gt;): void

取消订阅通知卡片不可见事件。

**需要权限**：ohos.permission.OBSERVE_FORM_RUNNING

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                                                         |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type       | string                                                       | 是   | 仅允许填写'notifyInvisible'，表示卡片可见性变更为不可见。    |
| hostBundleName | string                                                       | 否   | 指定卡片使用方的bundleName，用于订阅卡片在该使用方的可见状态变更事件。<br> 填写该参数时，与注册时填写bundleName的on接口对应。<br>  |
| observerCallback   | Callback &lt;Array&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo.md)&gt;&gt; | 否   | 入参，注册时注册进去的callback。缺省时，表示注销对应已注册事件回调。<br/> 需与对应on('notifyInvisible')的callback一致。 |

**示例：**

```ts
import formObserver from '@ohos.app.form.formObserver';
import formInfo from '@ohos.app.form.formInfo';

let bundleName: string = 'ohos.samples.FormApplication';
formObserver.off('notifyInvisible', bundleName, (data: formInfo.RunningFormInfo[]) => {
  console.log(`form change invisibility, data: ${JSON.stringify(data)}`);
});
```

> **说明：**
> on('notifyInvisible', callback)与off('notifyInvisible', callback)相对应；
> on('notifyInvisible', bundleName, callback)与off('notifyInvisible', bundleName, callback)相对应；
> 订阅（on）只能由自己对应的取消订阅接口（off）取消。


## getRunningFormInfos

getRunningFormInfos(callback: AsyncCallback&lt;Array&lt;formInfo.RunningFormInfo&gt;&gt;, hostBundleName?: string): void

获取设备上正在运行的所有非临时卡片信息。使用callback异步回调。

**需要权限**：ohos.permission.OBSERVE_FORM_RUNNING

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| callback | AsyncCallback&lt;Array&lt;formInfo.RunningFormInfo&gt;&gt; | 是 | 回调函数。获取设备上指定应用为卡片使用方的当前卡片信息成功，error为undefined，data为查询到的卡片信息。|
| hostBundleName | string | 否 |  指定要查询的卡片使用方名称，指定后会仅返回该卡片使用方下正在运行的非临时卡片信息。 <br> 缺省时，返回设备上所有正在运行的非临时卡片信息。 |

**错误码：**
以下错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. ||

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
      console.log(`formObserver getRunningFormInfos, data: ${JSON.stringify(data)}`);
    }
  }, 'com.example.ohos.formjsdemo');
} catch(error) {
  console.error(`catch error, code: ${(error as Base.BusinessError).code}, message: ${(error as Base.BusinessError).message}`);
}
```

## getRunningFormInfos<sup>11+</sup>

getRunningFormInfos(callback: AsyncCallback&lt;Array&lt;formInfo.RunningFormInfo&gt;&gt;, isUnusedIncluded: boolean, hostBundleName?: string): void

获取所有卡片信息。使用callback异步回调。

**需要权限**：ohos.permission.OBSERVE_FORM_RUNNING

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| callback | AsyncCallback&lt;Array&lt;formInfo.RunningFormInfo&gt;&gt; | 是 | 以callback形式返回获取到的所有卡片信息，当获取成功时，回调中的error为undefined，data为查询到的卡片信息。|
| isUnusedIncluded | boolean | 是 |  是否包含未使用的卡片。 |
| hostBundleName | string | 否 |  指定要查询的卡片使用方名称，指定后会仅返回该卡片使用方下正在运行的非临时卡片信息。 <br> 缺省时，返回设备上所有正在运行的非临时卡片信息。 |

**错误码：**
以下错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. ||

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
      console.log(`formObserver getRunningFormInfos, data: ${JSON.stringify(data)}`);
    }
  }, true, 'com.example.ohos.formjsdemo');
} catch(error) {
  console.error(`catch error, code: ${(error as Base.BusinessError).code}, message: ${(error as Base.BusinessError).message}`);
}
```

## getRunningFormInfos

getRunningFormInfos(hostBundleName?: string):  Promise&lt;Array&lt;formInfo.RunningFormInfo&gt;&gt;

获取设备上正在运行的所有非临时卡片信息。使用Promise异步回调。

**需要权限**：ohos.permission.OBSERVE_FORM_RUNNING

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| hostBundleName | string | 否 |  指定要查询的卡片使用方名称，指定后会仅返回该卡片使用方下正在运行的非临时卡片信息。 <br> 缺省时，返回设备上所有正在运行的非临时卡片信息。 |

**返回值：**

| 类型                                                         | 说明                                |
| :----------------------------------------------------------- | :---------------------------------- |
| Promise&lt;Array&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo.md)&gt;&gt; | Promise对象，返回查询到的卡片信息。 |

**错误码：**
以下错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. ||

**示例：**

```ts
import formObserver from '@ohos.app.form.formObserver';
import formInfo from '@ohos.app.form.formInfo';
import Base from '@ohos.base';

try {
  formObserver.getRunningFormInfos('com.example.ohos.formjsdemo').then((data: formInfo.RunningFormInfo[]) => {
    console.log(`formObserver getRunningFormInfos, data: ${JSON.stringify(data)}`);
  }).catch((error: Base.BusinessError) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${(error as Base.BusinessError).code}, message: ${(error as Base.BusinessError).message}`);
}
```

## getRunningFormInfos<sup>11+</sup>

getRunningFormInfos(isUnusedIncluded: boolean, hostBundleName?: string):  Promise&lt;Array&lt;formInfo.RunningFormInfo&gt;&gt;

获取设备上正在运行的所有非临时卡片信息。使用Promise异步回调。

**需要权限**：ohos.permission.OBSERVE_FORM_RUNNING

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| isUnusedIncluded | boolean | 是 |  是否包含未使用的卡片。 |
| hostBundleName | string | 否 |  指定要查询的卡片使用方名称，指定后会仅返回该卡片使用方下正在运行的非临时卡片信息。 <br> 缺省时，返回设备上所有正在运行的非临时卡片信息。 |

**返回值：**

| 类型                                                         | 说明                                |
| :----------------------------------------------------------- | :---------------------------------- |
| Promise&lt;Array&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo.md)&gt;&gt; | Promise对象，返回查询到的卡片信息。 |

**错误码：**
以下错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. ||

**示例：**

```ts
import formObserver from '@ohos.app.form.formObserver';
import formInfo from '@ohos.app.form.formInfo';
import Base from '@ohos.base';

try {
  formObserver.getRunningFormInfos(true, 'com.example.ohos.formjsdemo').then((data: formInfo.RunningFormInfo[]) => {
    console.log(`formObserver getRunningFormInfos, data: ${JSON.stringify(data)}`);
  }).catch((error: Base.BusinessError) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${(error as Base.BusinessError).code}, message: ${(error as Base.BusinessError).message}`);
}
```

## getRunningFormInfosByFilter

getRunningFormInfosByFilter(formProviderFilter: formInfo.FormProviderFilter): Promise&lt;Array&lt;formInfo.RunningFormInfo&gt;&gt;

根据提供方信息查询卡片已有的使用方列表信息。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限**：ohos.permission.OBSERVE_FORM_RUNNING

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名      | 类型            | 必填 | 说明                             |
| ----------- | --------------- | ---- | -------------------------------- |
| formProviderFilter     | [formInfo.FormProviderFilter](js-apis-app-form-formInfo.md#formProviderFilter) | 是   | 卡片提供方应用信息。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;Array&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo.md#RunningFormInfo)&gt;&gt; | Promise对象，返回查询到的使用方列表信息。 |

**错误码：**

以下错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000  | An internal functional error occurred. |


```ts
import formObserver from '@ohos.app.form.formObserver';
import formInfo from '@ohos.app.form.formInfo';
import Base from '@ohos.base';

let formInstanceFilter: formInfo.FormProviderFilter = {
  bundleName: "com.example.formprovide",
  abilityName: "EntryFormAbility",
  formName: "widget",
  moduleName: "entry"
}
try {
  formObserver.getRunningFormInfosByFilter(formInstanceFilter).then((data: formInfo.RunningFormInfo[]) => {
    console.info('formObserver getRunningFormInfosByFilter success, data:' + JSON.stringify(data));
  }).catch((error: Base.BusinessError) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${(error as Base.BusinessError).code}, message: ${(error as Base.BusinessError).message}`);
}
```

## getRunningFormInfosByFilter

getRunningFormInfosByFilter(formProviderFilter: formInfo.FormProviderFilter, callback: AsyncCallback&lt;Array&lt;formInfo.RunningFormInfo&gt;&gt;): void

根据提供方信息查询卡片已有的使用方列表信息。使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限**：ohos.permission.OBSERVE_FORM_RUNNING

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名      | 类型            | 必填 | 说明                             |
| ----------- | --------------- | ---- | -------------------------------- |
| formProviderFilter     | [formInfo.FormProviderFilter](js-apis-app-form-formInfo.md#formProviderFilter) | 是   | 卡片提供方应用信息。 |
| callback | AsyncCallback&lt;Array&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo.md)&gt;&gt; | 是 | 回调函数。返回查询到的使用方列表信息，error为undefined，data为查询到的使用方列表信息；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000  | An internal functional error occurred. |

**示例：**

```ts
import formObserver from '@ohos.app.form.formObserver';
import formInfo from '@ohos.app.form.formInfo';
import Base from '@ohos.base';

let formInstanceFilter: formInfo.FormProviderFilter = {
  bundleName: "com.example.formprovide",
  abilityName: "EntryFormAbility",
  formName: "widget",
  moduleName: "entry"
}
try {
  formObserver.getRunningFormInfosByFilter(formInstanceFilter,(error: Base.BusinessError, data: formInfo.RunningFormInfo[]) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    } else {
      console.log(`formObserver getRunningFormInfosByFilter, data: ${JSON.stringify(data)}`);
    }
  });
} catch(error) {
  console.error(`catch error, code: ${(error as Base.BusinessError).code}, message: ${(error as Base.BusinessError).message}`);
}
```

## getRunningFormInfoById

getRunningFormInfoById(formId: string): Promise&lt;formInfo.RunningFormInfo&gt;


根据formId查询卡片已有的使用方列表信息。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限**：ohos.permission.OBSERVE_FORM_RUNNING

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名      | 类型            | 必填 | 说明                             |
| ----------- | --------------- | ---- | -------------------------------- |
| formId     | string | 是   | 卡片标识。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo.md)&gt; | Promise对象，返回查询到的使用方列表信息。 |

**错误码：**

以下错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000  | An internal functional error occurred. |

**示例：**

```ts
import formObserver from '@ohos.app.form.formObserver';
import formInfo from '@ohos.app.form.formInfo';
import Base from '@ohos.base';

let formId: string = '12400633174999288';
try {
  formObserver.getRunningFormInfoById(formId).then((data: formInfo.RunningFormInfo) => {
    console.info('formObserver getRunningFormInfoById success, data:' + JSON.stringify(data));
  }).catch((error: Base.BusinessError) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${(error as Base.BusinessError).code}, message: ${(error as Base.BusinessError).message}`);
}
```

## getRunningFormInfoById<sup>11+</sup>

getRunningFormInfoById(formId: string, isUnusedIncluded: boolean): Promise&lt;formInfo.RunningFormInfo&gt;


根据formId查询卡片已有的使用方列表信息。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限**：ohos.permission.OBSERVE_FORM_RUNNING

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名      | 类型            | 必填 | 说明                             |
| ----------- | --------------- | ---- | -------------------------------- |
| formId     | string | 是   | 卡片标识。 |
| isUnusedIncluded     | boolean | 是   | 是否包含未使用的卡片。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo.md)&gt; | Promise对象，返回查询到的使用方列表信息。 |

**错误码：**

以下错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 16500050 | An IPC connection error happened. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000  | An internal functional error occurred. |

**示例：**

```ts
import formObserver from '@ohos.app.form.formObserver';
import formInfo from '@ohos.app.form.formInfo';
import Base from '@ohos.base';

let formId: string = '12400633174999288';
try {
  formObserver.getRunningFormInfoById(formId, true).then((data: formInfo.RunningFormInfo) => {
    console.info('formObserver getRunningFormInfoById success, data:' + JSON.stringify(data));
  }).catch((error: Base.BusinessError) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${(error as Base.BusinessError).code}, message: ${(error as Base.BusinessError).message}`);
}
```

## getRunningFormInfoById

getRunningFormInfoById(formId: string, callback: AsyncCallback&lt;formInfo.RunningFormInfo&gt;): void

根据提供方信息查询卡片已有的使用方列表信息。使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限**：ohos.permission.OBSERVE_FORM_RUNNING

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名      | 类型            | 必填 | 说明                             |
| ----------- | --------------- | ---- | -------------------------------- |
| formId     | string | 是   | 卡片标识。 |
| callback | AsyncCallback&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo.md)&gt; | 是 | 回调函数。返回查询到的使用方列表信息，error为undefined，data为查询到的使用方列表信息；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000  | An internal functional error occurred. |

**示例：**

```ts
import formObserver from '@ohos.app.form.formObserver';
import formInfo from '@ohos.app.form.formInfo';
import Base from '@ohos.base';

let formId: string = '12400633174999288';
try {
  formObserver.getRunningFormInfoById(formId,(error: Base.BusinessError, data: formInfo.RunningFormInfo) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    } else {
      console.log(`formObserver getRunningFormInfoById, data: ${JSON.stringify(data)}`);
    }
  });
} catch(error) {
  console.error(`catch error, code: ${(error as Base.BusinessError).code}, message: ${(error as Base.BusinessError).message}`);
}
```

## getRunningFormInfoById<sup>11+</sup>

getRunningFormInfoById(formId: string, isUnusedIncluded: boolean, callback: AsyncCallback&lt;formInfo.RunningFormInfo&gt;): void

根据卡片标识formId，查询卡片已有的使用方列表信息。使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限**：ohos.permission.OBSERVE_FORM_RUNNING

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名      | 类型            | 必填 | 说明                             |
| ----------- | --------------- | ---- | -------------------------------- |
| formId     | string | 是   | 卡片标识。 |
| isUnusedIncluded     | boolean | 是   | 是否包含未使用的卡片。 |
| callback | AsyncCallback&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo.md)&gt; | 是 | 回调函数。返回查询到的使用方列表信息，error为undefined，data为查询到的使用方列表信息；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 16500050 | An IPC connection error happened. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000  | An internal functional error occurred. |

**示例：**

```ts
import formObserver from '@ohos.app.form.formObserver';
import formInfo from '@ohos.app.form.formInfo';
import Base from '@ohos.base';

let formId: string = '12400633174999288';
try {
  formObserver.getRunningFormInfoById(formId, true, (error: Base.BusinessError, data: formInfo.RunningFormInfo) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    } else {
      console.log(`formObserver getRunningFormInfoById, data: ${JSON.stringify(data)}`);
    }
  });
} catch(error) {
  console.error(`catch error, code: ${(error as Base.BusinessError).code}, message: ${(error as Base.BusinessError).message}`);
}
```

## on('router')<sup>11+</sup>

 on(type: 'router', observerCallback: Callback&lt;formInfo.RunningFormInfo&gt;): void

订阅卡片router事件。使用callback异步回调，返回触发router事件的卡片的[RunningFormInfo](js-apis-app-form-formInfo.md#runningforminfo10)。

**需要权限**：ohos.permission.OBSERVE_FORM_RUNNING

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名           | 类型                                     | 必填 | 说明                                      |
| ---------------- | ---------------------------------------- | ---- | ----------------------------------------- |
| type             | string                                   | 是   | 填写'router'，表示订阅卡片的router事件。          |
| observerCallback | Callback&lt;formInfo.RunningFormInfo&gt; | 是   | 回调函数。返回触发router事件的卡片的RunningFormInfo。 |

**错误码：**
以下错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

| 错误码ID | 错误信息                                       |
| -------- | ---------------------------------------------- |
| 202      | The application is not a system application.   |
| 401      | If the input parameter is not valid parameter. |

**示例：**

```ts
import formObserver from '@ohos.app.form.formObserver';
import formInfo from '@ohos.app.form.formInfo';

let callback = (data: formInfo.RunningFormInfo) => {
  console.log('Router event listening in registered form.' + JSON.stringify(data));
};
formObserver.on('router', callback);
```

## on('router')<sup>11+</sup>

 on(type: 'router', hostBundleName: string, observerCallback: Callback&lt;formInfo.RunningFormInfo&gt;): void

订阅指定卡片使用方的卡片的router事件。使用callback异步回调，返回触发router事件的卡片的[RunningFormInfo](js-apis-app-form-formInfo.md#runningforminfo10)。

**需要权限**：ohos.permission.OBSERVE_FORM_RUNNING

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名           | 类型                                     | 必填 | 说明                                                         |
| ---------------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| type             | string                                   | 是   | 填写'router'，表示订阅卡片的router事件。                             |
| hostBundleName   | string                                   | 是   | 指定卡片使用方的bundleName。缺省则订阅所有卡片使用方的卡片的router事件。 |
| observerCallback | Callback&lt;formInfo.RunningFormInfo&gt; | 是   | 回调函数。返回触发router事件的卡片的RunningFormInfo。                    |

**错误码：**
以下错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

| 错误码ID | 错误信息                                       |
| -------- | ---------------------------------------------- |
| 202      | The application is not a system application.   |
| 401      | If the input parameter is not valid parameter. |

**示例：**

```ts
import formObserver from '@ohos.app.form.formObserver';
import formInfo from '@ohos.app.form.formInfo';

let hostBundleName: string = 'ohos.samples.FormApplication';
let callback = (data: formInfo.RunningFormInfo) => {
  console.log('Router event listening in registered form.' + JSON.stringify(data));
};
formObserver.on('router', hostBundleName, callback);
```

## off('router')<sup>11+</sup>

 off(type: "router", hostBundleName?: string, observerCallback?: Callback&lt;formInfo.RunningFormInfo&gt;): void

取消订阅卡片call事件的callback异步回调。

**需要权限**：ohos.permission.OBSERVE_FORM_RUNNING

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名           | 类型                                     | 必填 | 说明                                                         |
| ---------------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| type             | string                                   | 是   | 填写'router'，表示取消订阅卡片的router事件。                             |
| hostBundleName   | string                                   | 否   | 指定订阅卡片使用方包的bundleName。<br>填写该参数时，与注册时填写bundleName的on接口对应。<br>缺省则订阅所有卡片使用方点击router类型卡片的事件，与注册时未填写bundleName的on接口相对应。 |
| observerCallback | Callback&lt;formInfo.RunningFormInfo&gt; | 否   | 回调函数。返回卡片RunningFormInfo。缺省时，表示注销对应bundleName下已注册事件回调。<br>需与对应on('router')的callback一致。 |

**错误码：**
以下错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

| 错误码ID | 错误信息                                       |
| -------- | ---------------------------------------------- |
| 202      | The application is not a system application.   |
| 401      | If the input parameter is not valid parameter. |

**示例：**

```ts
import formObserver from '@ohos.app.form.formObserver';
import formInfo from '@ohos.app.form.formInfo';

let hostBundleName: string = 'ohos.samples.FormApplication';
let callback = (data: formInfo.RunningFormInfo) => {
  console.log('Unregister form router event Listening.' + JSON.stringify(data));
};
formObserver.off('router', hostBundleName, callback);
```

## on('message')<sup>11+</sup>

 on(type: 'message', observerCallback: Callback&lt;formInfo.RunningFormInfo&gt;): void

订阅卡片message事件。使用callback异步回调，返回触发message事件的卡片的[RunningFormInfo](js-apis-app-form-formInfo.md#runningforminfo10)。

**需要权限**：ohos.permission.OBSERVE_FORM_RUNNING

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名           | 类型                                     | 必填 | 说明                                      |
| ---------------- | ---------------------------------------- | ---- | ----------------------------------------- |
| type             | string                                   | 是   | 填写'message'，表示订阅卡片的message事件。         |
| observerCallback | Callback&lt;formInfo.RunningFormInfo&gt; | 是   | 回调函数。返回触发message事件的卡片的RunningFormInfo。 |

**错误码：**
以下错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

| 错误码ID | 错误信息                                       |
| -------- | ---------------------------------------------- |
| 202      | The application is not a system application.   |
| 401      | If the input parameter is not valid parameter. |

**示例：**

```ts
import formObserver from '@ohos.app.form.formObserver';
import formInfo from '@ohos.app.form.formInfo';

let callback = (data: formInfo.RunningFormInfo) => {
  console.log('Message event listening in registered form.' + JSON.stringify(data));
};
formObserver.on('message', callback);
```

## on('message')<sup>11+</sup>

 on(type: 'message', hostBundleName: string, observerCallback: Callback&lt;formInfo.RunningFormInfo&gt;): void

订阅指定卡片使用方的卡片的message事件。使用callback异步回调，返回触发message事件的卡片的[RunningFormInfo](js-apis-app-form-formInfo.md#runningforminfo10)。

**需要权限**：ohos.permission.OBSERVE_FORM_RUNNING

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名           | 类型                                     | 必填 | 说明                                                         |
| ---------------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| type             | string                                   | 是   | 填写'message'，表示订阅卡片的message事件。                            |
| hostBundleName   | string                                   | 是   | 指定卡片使用方的bundleName。缺省则订阅所有卡片使用方的卡片的message事件。 |
| observerCallback | Callback&lt;formInfo.RunningFormInfo&gt; | 是   | 回调函数。返回触发message事件的卡片的RunningFormInfo。                    |

**错误码：**
以下错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

| 错误码ID | 错误信息                                       |
| -------- | ---------------------------------------------- |
| 202      | The application is not a system application.   |
| 401      | If the input parameter is not valid parameter. |

**示例：**

```ts
import formObserver from '@ohos.app.form.formObserver';
import formInfo from '@ohos.app.form.formInfo';

let hostBundleName: string = 'ohos.samples.FormApplication';
let callback = (data: formInfo.RunningFormInfo) => {
  console.log('Message event listening in registered form.' + JSON.stringify(data));
};
formObserver.on('message', hostBundleName, callback);
```

## off('message')<sup>11+</sup>

 off(type: "message", hostBundleName?: string, observerCallback?: Callback&lt;formInfo.RunningFormInfo&gt;): void

取消订阅卡片call事件的callback异步回调。

**需要权限**：ohos.permission.OBSERVE_FORM_RUNNING

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名           | 类型                                     | 必填 | 说明                                                         |
| ---------------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| type             | string                                   | 是   | 填写'message'，表示取消订阅卡片的message事件。                         |
| hostBundleName   | string                                   | 否   | 指定订阅卡片使用方包的bundleName。<br>填写该参数时，与注册时填写bundleName的on接口对应。<br>缺省则取消订阅所有卡片使用方的点击事件，与注册时未填写bundleName的on接口相对应。 |
| observerCallback | Callback&lt;formInfo.RunningFormInfo&gt; | 否   | 回调函数。返回卡片RunningFormInfo。缺省时，表示注销对应已注册事件回调。<br>需与对应on('message')的callback一致。 |

**错误码：**
以下错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

| 错误码ID | 错误信息                                       |
| -------- | ---------------------------------------------- |
| 202      | The application is not a system application.   |
| 401      | If the input parameter is not valid parameter. |

**示例：**

```ts
import formObserver from '@ohos.app.form.formObserver';
import formInfo from '@ohos.app.form.formInfo';

let hostBundleName: string = 'ohos.samples.FormApplication';
let callback = (data: formInfo.RunningFormInfo) => {
  console.log('Unregister form Message event Listening.' + JSON.stringify(data));
};
formObserver.off('message', hostBundleName, callback);
```

## on('call')<sup>11+</sup>

 on(type: 'call', observerCallback: Callback&lt;formInfo.RunningFormInfo&gt;): void

订阅卡片call事件。使用callback异步回调，返回触发call事件的卡片的[RunningFormInfo](js-apis-app-form-formInfo.md#runningforminfo10)。

**需要权限**：ohos.permission.OBSERVE_FORM_RUNNING

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名           | 类型                                     | 必填 | 说明                                      |
| ---------------- | ---------------------------------------- | ---- | ----------------------------------------- |
| type             | string                                   | 是   | 填写'call'，表示订阅卡片的call事件。            |
| observerCallback | Callback&lt;formInfo.RunningFormInfo&gt; | 是   | 回调函数。返回触发call事件的卡片的RunningFormInfo。 |

**错误码：**
以下错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

| 错误码ID | 错误信息                                       |
| -------- | ---------------------------------------------- |
| 202      | The application is not a system application.   |
| 401      | If the input parameter is not valid parameter. |

**示例：**

```ts
import formObserver from '@ohos.app.form.formObserver';
import formInfo from '@ohos.app.form.formInfo';

let callback = (data: formInfo.RunningFormInfo) => {
  console.log('Call event listening in registered form.' + JSON.stringify(data));
};
formObserver.on('call', callback);
```

## on('call')<sup>11+</sup>

 on(type: 'call', hostBundleName: string, observerCallback: Callback&lt;formInfo.RunningFormInfo&gt;): void

订阅指定卡片使用方的卡片的call事件。使用callback异步回调，返回触发call事件的卡片的[RunningFormInfo](js-apis-app-form-formInfo.md#runningforminfo10)。

**需要权限**：ohos.permission.OBSERVE_FORM_RUNNING

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名           | 类型                                     | 必填 | 说明                                                         |
| ---------------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| type             | string                                   | 是   | 填写'call'，表示订阅卡片的call事件。                               |
| hostBundleName   | string                                   | 是   | 指定卡片使用方的bundleName。缺省则订阅所有卡片使用方的卡片的call事件。 |
| observerCallback | Callback&lt;formInfo.RunningFormInfo&gt; | 是   | 回调函数。返回触发call事件的卡片的RunningFormInfo。                    |

**错误码：**
以下错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

| 错误码ID | 错误信息                                       |
| -------- | ---------------------------------------------- |
| 202      | The application is not a system application.   |
| 401      | If the input parameter is not valid parameter. |

**示例：**

```ts
import formObserver from '@ohos.app.form.formObserver';
import formInfo from '@ohos.app.form.formInfo';

let hostBundleName: string = 'ohos.samples.FormApplication';
let callback = (data: formInfo.RunningFormInfo) => {
  console.log('Call event listening in registered form.' + JSON.stringify(data));
};
formObserver.on('call', hostBundleName, callback);
```

## off('call')<sup>11+</sup>

 off(type: "call", hostBundleName?: string, observerCallback?: Callback&lt;formInfo.RunningFormInfo&gt;): void

取消订阅卡片call事件的callback异步回调。

**需要权限**：ohos.permission.OBSERVE_FORM_RUNNING

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名           | 类型                                     | 必填 | 说明                                                         |
| ---------------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| type             | string                                   | 是   | 填写'call'，表示取消订阅卡片的call事件。                           |
| hostBundleName   | string                                   | 否   | 指定订阅卡片使用方包的bundleName。<br>填写该参数时，与注册时填写bundleName的on接口对应。<br>缺省则取消订阅所有卡片使用方的点击事件，与注册时未填写bundleName的on接口相对应。 |
| observerCallback | Callback&lt;formInfo.RunningFormInfo&gt; | 否   | 回调函数。返回卡片RunningFormInfo。缺省时，表示注销对应已注册事件回调。<br>需与对应on('call')的callback一致。 |

**错误码：**
以下错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

| 错误码ID | 错误信息                                       |
| -------- | ---------------------------------------------- |
| 202      | The application is not a system application.   |
| 401      | If the input parameter is not valid parameter. |

**示例：**

```ts
import formObserver from '@ohos.app.form.formObserver';
import formInfo from '@ohos.app.form.formInfo';

let hostBundleName: string = 'ohos.samples.FormApplication';
let callback = (data: formInfo.RunningFormInfo) => {
  console.log('Unregister form Call event Listening.' + JSON.stringify(data));
};
formObserver.off('call', hostBundleName, callback);
```