# @ohos.application.formHost (formHost)(系统接口)

formHost模块提供了卡片使用方相关接口的能力，包括对使用方同一用户下安装的卡片进行删除、释放、请求更新，获取信息、状态等操作。

> **说明：**
>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 从API version 9 开始不再维护，建议使用[formHost](js-apis-app-form-formHost-sys.md)替代。
> 本模块接口均为系统接口。

## 导入模块

```ts
import formHost from '@ohos.application.formHost';
```

## deleteForm

deleteForm(formId: string, callback: AsyncCallback&lt;void&gt;): void

删除指定的卡片。调用此方法后，应用程序将无法使用该卡片，卡片管理器服务不再保留有关该卡片的信息。使用callback异步回调。

**需要权限：** ohos.permission.REQUIRE_FORM

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| formId | string | 是   | 卡片标识。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当删除指定的卡片成功，error为undefined，否则为错误对象。 |

**示例：**

```ts
import Base from '@ohos.base';

let formId: string = '12400633174999288';
formHost.deleteForm(formId, (error: Base.BusinessError) => {
  if (error.code) {
    console.error(`formHost deleteForm, error: ${JSON.stringify(error)}`);
  }
});
```

## deleteForm

deleteForm(formId: string): Promise&lt;void&gt;

删除指定的卡片。调用此方法后，应用程序将无法使用该卡片，卡片管理器服务不再保留有关该卡片的信息。使用Promise异步回调。

**需要权限：** ohos.permission.REQUIRE_FORM

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| formId | string | 是   | 卡片标识。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```ts
import Base from '@ohos.base';

let formId: string = '12400633174999288';
formHost.deleteForm(formId).then(() => {
  console.log('formHost deleteForm success');
}).catch((error: Base.BusinessError) => {
  console.error(`formHost deleteForm, error: ${JSON.stringify(error)}`);
});
```

## releaseForm

releaseForm(formId: string, callback: AsyncCallback&lt;void&gt;): void

释放指定的卡片。调用此方法后，应用程序将无法使用该卡片，但卡片管理器服务仍然保留有关该卡片的缓存信息和存储信息。使用callback异步回调。

**需要权限：** ohos.permission.REQUIRE_FORM

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| formId | string | 是   | 卡片标识。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当释放指定的卡片成功，error为undefined；否则为错误对象。|

**示例：**

```ts
import Base from '@ohos.base';

let formId: string = '12400633174999288';
formHost.releaseForm(formId, (error: Base.BusinessError) => {
  if (error.code) {
    console.error(`formHost releaseForm, error: ${JSON.stringify(error)}`);
  } else {
    console.log('formHost releaseForm success');
  }
});
```

## releaseForm

releaseForm(formId: string, isReleaseCache: boolean, callback: AsyncCallback&lt;void&gt;): void

释放指定的卡片。调用此方法后，应用程序将无法使用该卡片，卡片管理器服务保留有关该卡片的存储信息，可以选择是否保留缓存信息。使用callback异步回调。

**需要权限：** ohos.permission.REQUIRE_FORM

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名         | 类型     | 必填 | 说明        |
| -------------- | ------  | ---- | ----------- |
| formId         | string  | 是   | 卡片标识。     |
| isReleaseCache | boolean | 是   | 是否释放缓存。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当释放指定的卡片成功，error为undefined；否则为错误对象。 |

**示例：**

```ts
import Base from '@ohos.base';

let formId: string = '12400633174999288';
formHost.releaseForm(formId, true, (error: Base.BusinessError) => {
  if (error.code) {
    console.error(`formHost releaseForm, error: ${JSON.stringify(error)}`);
  } else {
    console.log('formHost releaseForm success');
  }
});
```

## releaseForm

releaseForm(formId: string, isReleaseCache?: boolean): Promise&lt;void&gt;

释放指定的卡片。调用此方法后，应用程序将无法使用该卡片，卡片管理器服务保留有关该卡片的存储信息，可以选择是否保留缓存信息。使用Promise异步回调。

**需要权限：** ohos.permission.REQUIRE_FORM

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名         | 类型     | 必填 | 说明        |
| -------------- | ------  | ---- | ----------- |
| formId         | string  | 是   | 卡片标识。     |
| isReleaseCache | boolean | 否   | 是否释放缓存，默认为false。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```ts
import Base from '@ohos.base';

let formId: string = '12400633174999288';
formHost.releaseForm(formId, true).then(() => {
  console.log('formHost releaseForm success');
}).catch((error: Base.BusinessError) => {
  console.error(`formHost releaseForm, error: ${JSON.stringify(error)}`);
});
```

## requestForm

requestForm(formId: string, callback: AsyncCallback&lt;void&gt;): void

请求卡片更新。使用callback异步回调。

**需要权限：** ohos.permission.REQUIRE_FORM

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| formId | string | 是   | 卡片标识。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当请求卡片更新成功，error为undefined；否则为错误对象。 |

**示例：**

```ts
import Base from '@ohos.base';

let formId: string = '12400633174999288';
formHost.requestForm(formId, (error: Base.BusinessError) => {
  if (error.code) {
    console.error(`formHost requestForm, error: ${JSON.stringify(error)}`);
  }
});
```

## requestForm

requestForm(formId: string): Promise&lt;void&gt;

请求卡片更新。使用Promise异步回调。

**需要权限：** ohos.permission.REQUIRE_FORM

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| formId | string | 是   | 卡片标识。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```ts
import Base from '@ohos.base';

let formId: string = '12400633174999288';
formHost.requestForm(formId).then(() => {
  console.log('formHost requestForm success');
}).catch((error: Base.BusinessError) => {
  console.error(`formHost requestForm, error: ${JSON.stringify(error)}`);
});
```

## castTempForm

castTempForm(formId: string, callback: AsyncCallback&lt;void&gt;): void

将指定的临时卡片转换为普通卡片。使用callback异步回调。

**需要权限：** ohos.permission.REQUIRE_FORM

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| formId | string | 是   | 卡片标识。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当将指定的临时卡片转换为普通卡片成功，error为undefined，否则为错误对象。 |

**示例：**

```ts
import Base from '@ohos.base';

let formId: string = '12400633174999288';
formHost.castTempForm(formId, (error: Base.BusinessError) => {
  if (error.code) {
    console.error(`formHost castTempForm, error: ${JSON.stringify(error)}`);
  }
});
```

## castTempForm

castTempForm(formId: string): Promise&lt;void&gt;

将指定的临时卡片转换为普通卡片。使用Promise异步回调。

**需要权限：** ohos.permission.REQUIRE_FORM

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| formId | string | 是   | 卡片标识。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。|

**示例：**

```ts
import Base from '@ohos.base';

let formId: string = '12400633174999288';
formHost.castTempForm(formId).then(() => {
  console.log('formHost castTempForm success');
}).catch((error: Base.BusinessError) => {
  console.error(`formHost castTempForm, error: ${JSON.stringify(error)}`);
});
```

## notifyVisibleForms

notifyVisibleForms(formIds: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void

向卡片框架发送通知以使指定的卡片可见。该方法调用成功后，会调用onVisibilityChange通知卡片提供方。使用callback异步回调。

**需要权限：** ohos.permission.REQUIRE_FORM

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| formIds  | Array&lt;string&gt;       | 是   | 卡片标识列表。         |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当向卡片框架发送通知以使指定的卡片可见成功，error为undefined，否则为错误对象。 |

**示例：**

```ts
import Base from '@ohos.base';

let formId: string[] = ['12400633174999288'];
formHost.notifyVisibleForms(formId, (error: Base.BusinessError) => {
  if (error.code) {
    console.error(`formHost notifyVisibleForms, error: ${JSON.stringify(error)}`);
  }
});
```

## notifyVisibleForms

notifyVisibleForms(formIds: Array&lt;string&gt;): Promise&lt;void&gt;

向卡片框架发送通知以使指定的卡片可见。该方法调用成功后，会调用onVisibilityChange通知卡片提供方。使用Promise异步回调。

**需要权限：** ohos.permission.REQUIRE_FORM

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| formIds | Array&lt;string&gt; | 是   | 卡片标识列表。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```ts
import Base from '@ohos.base';

let formId: string[] = ['12400633174999288'];
formHost.notifyVisibleForms(formId).then(() => {
  console.log('formHost notifyVisibleForms success');
}).catch((error: Base.BusinessError) => {
  console.error(`formHost notifyVisibleForms, error: ${JSON.stringify(error)}`);
});
```

## notifyInvisibleForms

notifyInvisibleForms(formIds: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void

向卡片框架发送通知以使指定的卡片不可见。该方法调用成功后，会调用onVisibilityChange通知卡片提供方。使用callback异步回调。

**需要权限：** ohos.permission.REQUIRE_FORM

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| formIds  | Array&lt;string&gt;       | 是   | 卡片标识列表。|
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当向卡片框架发送通知以使指定的卡片不可见成功，error为undefined，否则为错误对象。 |

**示例：**

```ts
import Base from '@ohos.base';

let formId: string[] = ['12400633174999288'];
formHost.notifyInvisibleForms(formId, (error: Base.BusinessError) => {
  if (error.code) {
    console.error(`formHost notifyInvisibleForms, error: ${JSON.stringify(error)}`);
  }
});
```

## notifyInvisibleForms

notifyInvisibleForms(formIds: Array&lt;string&gt;): Promise&lt;void&gt;

向卡片框架发送通知以使指定的卡片不可见。该方法调用成功后，会调用onVisibilityChange通知卡片提供方。使用Promise异步回调。

**需要权限：** ohos.permission.REQUIRE_FORM

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| formIds | Array&lt;string&gt; | 是   | 卡片标识列表。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。|

**示例：**

```ts
import Base from '@ohos.base';

let formId: string[] = ['12400633174999288'];
formHost.notifyInvisibleForms(formId).then(() => {
  console.log('formHost notifyInvisibleForms success');
}).catch((error: Base.BusinessError) => {
  console.error(`formHost notifyInvisibleForms, error: ${JSON.stringify(error)}`);
});
```

## enableFormsUpdate

enableFormsUpdate(formIds: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void

向卡片框架发送通知以使指定的卡片可以更新。该方法调用成功后，卡片刷新状态设置为使能，卡片可以接收来自卡片提供方的更新。使用callback异步回调。

**需要权限：** ohos.permission.REQUIRE_FORM

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| formIds  | Array&lt;string&gt;       | 是   | 卡片标识列表。         |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当向卡片框架发送通知以使指定的卡片可以更新成功，error为undefined，否则为错误对象。 |

**示例：**

```ts
import Base from '@ohos.base';

let formId: string[] = ['12400633174999288'];
formHost.enableFormsUpdate(formId, (error: Base.BusinessError) => {
  if (error.code) {
    console.error(`formHost enableFormsUpdate, error: ${JSON.stringify(error)}`);
  }
});
```

## enableFormsUpdate

enableFormsUpdate(formIds: Array&lt;string&gt;): Promise&lt;void&gt;

向卡片框架发送通知以使指定的卡片可以更新。该方法调用成功后，卡片刷新状态设置为使能，卡片可以接收来自卡片提供方的更新。使用Promise异步回调。

**需要权限：** ohos.permission.REQUIRE_FORM

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| formIds | Array&lt;string&gt; | 是   | 卡片标识列表。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```ts
import Base from '@ohos.base';

let formId: string[] = ['12400633174999288'];
formHost.enableFormsUpdate(formId).then(() => {
  console.log('formHost enableFormsUpdate success');
}).catch((error: Base.BusinessError) => {
  console.error(`formHost enableFormsUpdate, error: ${JSON.stringify(error)}`);
});
```

## disableFormsUpdate

disableFormsUpdate(formIds: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void

向卡片框架发送通知以使指定的卡片不可以更新。该方法调用成功后，卡片刷新状态设置为去使能，卡片不可以接收来自卡片提供方的更新。使用callback异步回调。

**需要权限：** ohos.permission.REQUIRE_FORM

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| formIds  | Array&lt;string&gt;       | 是   | 卡片标识列表。         |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当向卡片框架发送通知以使指定的卡片不可以更新成功，error为undefined，否则为错误对象。 |

**示例：**

```ts
import Base from '@ohos.base';

let formId: string[] = ['12400633174999288'];
formHost.disableFormsUpdate(formId, (error: Base.BusinessError) => {
  if (error.code) {
    console.error(`formHost disableFormsUpdate, error: ${JSON.stringify(error)}`);
  }
});
```

## disableFormsUpdate

disableFormsUpdate(formIds: Array&lt;string&gt;): Promise&lt;void&gt;

向卡片框架发送通知以使指定的卡片不可以更新。该方法调用成功后，卡片刷新状态设置为去使能，卡片不可以接收来自卡片提供方的更新。使用Promise异步回调。

**需要权限：** ohos.permission.REQUIRE_FORM

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| formIds | Array&lt;string&gt; | 是   | 卡片标识列表。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```ts
import Base from '@ohos.base';

let formId: string[] = ['12400633174999288'];
formHost.disableFormsUpdate(formId).then(() => {
  console.log('formHost disableFormsUpdate success');
}).catch((error: Base.BusinessError) => {
  console.error(`formHost disableFormsUpdate, error: ${JSON.stringify(error)}`);
});
```

## isSystemReady

isSystemReady(callback: AsyncCallback&lt;void&gt;): void

检查系统是否准备好。使用callback异步回调。

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当检查系统是否准备好成功，error为undefined，否则为错误对象。 |

**示例：**

```ts
import Base from '@ohos.base';

let formId: string = '12400633174999288';
formHost.isSystemReady((error: Base.BusinessError) => {
  if (error.code) {
    console.error(`formHost isSystemReady, error: ${JSON.stringify(error)}`);
  }
});
```

## isSystemReady

isSystemReady(): Promise&lt;void&gt;

检查系统是否准备好。使用Promise异步回调。

**系统能力：** SystemCapability.Ability.Form

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```ts
import Base from '@ohos.base';

let formId: string = '12400633174999288';
formHost.isSystemReady().then(() => {
  console.log('formHost isSystemReady success');
}).catch((error: Base.BusinessError) => {
  console.error(`formHost isSystemReady, error: ${JSON.stringify(error)}`);
});
```

## getAllFormsInfo

getAllFormsInfo(callback: AsyncCallback&lt;Array&lt;formInfo.FormInfo&gt;&gt;): void

获取设备上所有应用提供的卡片信息。使用callback异步回调。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| callback | AsyncCallback&lt;Array&lt;[formInfo.FormInfo](js-apis-app-form-formInfo.md)&gt;&gt; | 是 | 回调函数。当获取设备上所有应用提供的卡片信息成功，error为undefined，data为查询到的卡片信息；否则为错误对象。 |

**示例：**

```ts
import formInfo from '@ohos.app.form.formInfo';
import Base from '@ohos.base';

formHost.getAllFormsInfo((error: Base.BusinessError, data: formInfo.FormInfo[]) => {
  if (error.code) {
    console.error(`formHost getAllFormsInfo, error: ${JSON.stringify(error)}`);
  } else {
    console.log(`formHost getAllFormsInfo, data: ${JSON.stringify(data)}`);
  }
});
```

## getAllFormsInfo

getAllFormsInfo(): Promise&lt;Array&lt;formInfo.FormInfo&gt;&gt;

获取设备上所有应用提供的卡片信息。使用Promise异步回调。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.Ability.Form

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise&lt;Array&lt;[formInfo.FormInfo](js-apis-app-form-formInfo.md)&gt;&gt; | Promise对象。返回查询到的卡片信息。 |

**示例：**

  ```ts
  import formInfo from '@ohos.app.form.formInfo';
  import Base from '@ohos.base';

  formHost.getAllFormsInfo().then((data: formInfo.FormInfo[]) => {
    console.log(`formHost getAllFormsInfo data: ${JSON.stringify(data)}`);
  }).catch((error: Base.BusinessError) => {
    console.error(`formHost getAllFormsInfo, error: ${JSON.stringify(error)}`);
  });
  ```

## getFormsInfo

getFormsInfo(bundleName: string, callback: AsyncCallback&lt;Array&lt;formInfo.FormInfo&gt;&gt;): void

获取设备上指定应用程序提供的卡片信息。使用callback异步回调。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| bundleName | string | 是 | 要查询的应用Bundle名称。 |
| callback | AsyncCallback&lt;Array&lt;[formInfo.FormInfo](js-apis-app-form-formInfo.md)&gt;&gt; | 是 | 回调函数。当获取设备上指定应用程序提供的卡片信息成功，error为undefined，data为查询到的卡片信息；否则为错误对象。 |

**示例：**

```ts
import formInfo from '@ohos.app.form.formInfo';
import Base from '@ohos.base';

formHost.getFormsInfo('com.example.ohos.formjsdemo', (error: Base.BusinessError, data: formInfo.FormInfo[]) => {
  if (error.code) {
    console.error(`formHost getFormsInfo, error: ${JSON.stringify(error)}`);
  } else {
    console.log(`formHost getFormsInfo, data: ${JSON.stringify(data)}`);
  }
});
```

## getFormsInfo

getFormsInfo(bundleName: string, moduleName: string, callback: AsyncCallback&lt;Array&lt;formInfo.FormInfo&gt;&gt;): void

获取设备上指定应用程序提供的卡片信息。使用callback异步回调。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| bundleName | string | 是 | 要查询的应用程序Bundle名称。 |
| moduleName | string | 是 |  要查询的模块名称。 |
| callback | AsyncCallback&lt;Array&lt;[formInfo.FormInfo](js-apis-app-form-formInfo.md)&gt;&gt; | 是 | 回调函数。当获取设备上指定应用程序提供的卡片信息成功，error为undefined，data为查询到的卡片信息；否则为错误对象。 |

**示例：**

```ts
import formInfo from '@ohos.app.form.formInfo';
import Base from '@ohos.base';

formHost.getFormsInfo('com.example.ohos.formjsdemo', 'entry', (error: Base.BusinessError, data: formInfo.FormInfo[]) => {
  if (error.code) {
    console.error(`formHost getFormsInfo, error: ${JSON.stringify(error)}`);
  } else {
    console.log(`formHost getFormsInfo, data: ${JSON.stringify(data)}`);
  }
});
```

## getFormsInfo

getFormsInfo(bundleName: string, moduleName?: string): Promise&lt;Array&lt;formInfo.FormInfo&gt;&gt;

获取设备上指定应用程序提供的卡片信息。使用Promise异步回调。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| bundleName | string | 是 | 要查询的应用程序Bundle名称。 |
| moduleName | string | 否 |  要查询的模块名称。 |

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise&lt;Array&lt;[formInfo.FormInfo](js-apis-app-form-formInfo.md)&gt;&gt; | Promise对象。返回查询到的卡片信息。 |

**示例：**

  ```ts
  import formInfo from '@ohos.app.form.formInfo';
  import Base from '@ohos.base';

  formHost.getFormsInfo('com.example.ohos.formjsdemo', 'entry').then((data: formInfo.FormInfo[]) => {
    console.log(`formHost getFormsInfo, data: ${JSON.stringify(data)}`);
  }).catch((error: Base.BusinessError) => {
    console.error(`formHost getFormsInfo, error: ${JSON.stringify(error)}`);
  });
  ```

## deleteInvalidForms

deleteInvalidForms(formIds: Array&lt;string&gt;, callback: AsyncCallback&lt;number&gt;): void

根据列表删除应用程序的无效卡片。使用callback异步回调。

**需要权限：** ohos.permission.REQUIRE_FORM

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| formIds | Array&lt;string&gt; | 是   | 有效卡片标识列表。 |
| callback | AsyncCallback&lt;number&gt; | 是 | 回调函数。当根据列表删除应用程序的无效卡片成功，error为undefined，data为删除的卡片个数；否则为错误对象。 |

**示例：**

```ts
import Base from '@ohos.base';

let formIds: string[] = new Array('12400633174999288', '12400633174999289');
formHost.deleteInvalidForms(formIds, (error: Base.BusinessError, data: number) => {
  if (error.code) {
    console.error(`formHost deleteInvalidForms, error: ${JSON.stringify(error)}`);
  } else {
    console.log(`formHost deleteInvalidForms, data: ${JSON.stringify(data)}`);
  }
});
```

## deleteInvalidForms

deleteInvalidForms(formIds: Array&lt;string&gt;): Promise&lt;number&gt;

根据列表删除应用程序的无效卡片。使用Promise异步回调。

**需要权限：** ohos.permission.REQUIRE_FORM

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| formIds | Array&lt;string&gt; | 是   | 有效卡片标识列表。 |

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise&lt;number&gt; | Promise对象。返回删除的卡片个数。 |

**示例：**

```ts
import Base from '@ohos.base';

let formIds: string[] = new Array('12400633174999288', '12400633174999289');
formHost.deleteInvalidForms(formIds).then((data: number) => {
  console.log(`formHost deleteInvalidForms, data: ${JSON.stringify(data)}`);
}).catch((error: Base.BusinessError) => {
  console.error(`formHost deleteInvalidForms, error: ${JSON.stringify(error)}`);
});
```

## acquireFormState

acquireFormState(want: Want, callback: AsyncCallback&lt;formInfo.FormStateInfo&gt;): void

获取卡片状态。使用callback异步回调。

**需要权限：** ohos.permission.REQUIRE_FORM 和 ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| want | [Want](../apis-ability-kit/js-apis-application-want.md) | 是   | 查询卡片状态时携带的want信息。需要包含bundle名、ability名、module名、卡片名、卡片规格等。 |
| callback | AsyncCallback&lt;[formInfo.FormStateInfo](js-apis-application-formInfo.md#formstateinfo)&gt; | 是 | 回调函数。当获取卡片状态成功，error为undefined，data为获取到的卡片状态；否则为错误对象。 |

**示例：**

```ts
import Want from '@ohos.app.ability.Want';
import formInfo from '@ohos.app.form.formInfo';
import Base from '@ohos.base';

let want: Want = {
  'deviceId': '',
  'bundleName': 'ohos.samples.FormApplication',
  'abilityName': 'FormAbility',
  'parameters': {
    'ohos.extra.param.key.module_name': 'entry',
    'ohos.extra.param.key.form_name': 'widget',
    'ohos.extra.param.key.form_dimension': 2
  }
};
formHost.acquireFormState(want, (error:Base.BusinessError, data: formInfo.FormStateInfo) => {
  if (error.code) {
    console.error(`formHost acquireFormState, error: ${JSON.stringify(error)}`);
  } else {
    console.log(`formHost acquireFormState, data: ${JSON.stringify(data)}`);
  }
});
```

## acquireFormState

acquireFormState(want: Want): Promise&lt;formInfo.FormStateInfo&gt;

获取卡片状态。使用Promise异步回调。

**需要权限：** ohos.permission.REQUIRE_FORM 和 ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| want   | [Want](../apis-ability-kit/js-apis-application-want.md) | 是   | 查询卡片状态时携带的want信息。 |

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise&lt;[formInfo.FormStateInfo](js-apis-application-formInfo.md#formstateinfo)&gt; | Promise对象。返回卡片状态。 |

**示例：**

```ts
import Want from '@ohos.app.ability.Want';
import formInfo from '@ohos.app.form.formInfo';
import Base from '@ohos.base';

let want: Want = {
  'deviceId': '',
  'bundleName': 'ohos.samples.FormApplication',
  'abilityName': 'FormAbility',
  'parameters': {
    'ohos.extra.param.key.module_name': 'entry',
    'ohos.extra.param.key.form_name': 'widget',
    'ohos.extra.param.key.form_dimension': 2
  }
};
formHost.acquireFormState(want).then((data: formInfo.FormStateInfo) => {
  console.log(`formHost acquireFormState, data: ${JSON.stringify(data)}`);
}).catch((error: Base.BusinessError) => {
  console.error(`formHost acquireFormState, error: ${JSON.stringify(error)}`);
});
```

## on('formUninstall')

on(type: 'formUninstall', callback: Callback&lt;string&gt;): void

订阅卡片卸载事件。使用callback异步回调。

> **说明：**
> 
> 卡片卸载与卡片移除不同。当应用卸载时，对应的卡片会自动卸载。

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| type | string | 是   | 填写'formUninstall'，表示卡片卸载事件。 |
| callback | Callback&lt;string&gt; | 是 | 回调函数，返回卡片标识。 |

**示例：**

```ts
import Base from '@ohos.base';

formHost.on('formUninstall', (formId: string) => {
  console.log(`formHost on formUninstall, formId: ${formId}`);
});
```

## off('formUninstall')

off(type: 'formUninstall', callback?: Callback&lt;string&gt;): void

取消订阅卡片卸载事件。使用callback异步回调。

> **说明：**
> 
> 卡片卸载与卡片移除不同。当应用卸载时，对应的卡片会自动卸载。

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| type | string | 是   | 填写'formUninstall'，表示卡片卸载事件。 |
| callback | Callback&lt;string&gt; | 否 | 回调函数，返回卡片标识。缺省时，表示注销所有已注册事件回调。<br> 需与对应on('formUninstall')的callback一致。|

**示例：**

```ts
import Base from '@ohos.base';

formHost.off('formUninstall', (formId: string) => {
  console.log(`formHost on formUninstall, formId: ${formId}`);
});
```

## notifyFormsVisible

notifyFormsVisible(formIds: Array&lt;string&gt;, isVisible: boolean, callback: AsyncCallback&lt;void&gt;): void

通知卡片是否可见。使用callback异步回调。

**需要权限：** ohos.permission.REQUIRE_FORM

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| formIds | Array&lt;string&gt; | 是   | 卡片标识列表。 |
| isVisible | boolean | 是   | 是否可见。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当通知卡片是否可见成功，error为undefined，否则为错误对象。 |

**示例：**

```ts
import Base from '@ohos.base';

let formIds: string[]= new Array('12400633174999288', '12400633174999289');
formHost.notifyFormsVisible(formIds, true, (error: Base.BusinessError) => {
  if (error.code) {
    console.error(`formHost notifyFormsVisible, error: ${JSON.stringify(error)}`);
  }
});
```

## notifyFormsVisible

notifyFormsVisible(formIds: Array&lt;string&gt;, isVisible: boolean): Promise&lt;void&gt;

通知卡片是否可见。使用Promise异步回调。

**需要权限：** ohos.permission.REQUIRE_FORM

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| formIds | Array&lt;string&gt; | 是   | 卡片标识列表。 |
| isVisible | boolean | 是   | 是否可见。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```ts
import Base from '@ohos.base';

let formIds: string[] = new Array('12400633174999288', '12400633174999289');
formHost.notifyFormsVisible(formIds, true).then(() => {
  console.log('formHost notifyFormsVisible success');
}).catch((error: Base.BusinessError) => {
  console.error(`formHost notifyFormsVisible, error: ${JSON.stringify(error)}`);
});
```

## notifyFormsEnableUpdate

notifyFormsEnableUpdate(formIds: Array&lt;string&gt;, isEnableUpdate: boolean, callback: AsyncCallback&lt;void&gt;): void

通知卡片是否启用更新状态。使用callback异步回调。

**需要权限：** ohos.permission.REQUIRE_FORM

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| formIds | Array&lt;string&gt; | 是   | 卡片标识列表。 |
| isEnableUpdate | boolean | 是   | 是否使能更新。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当通知卡片是否启用更新状态成功，error为undefined，否则为错误对象。 |

**示例：**

```ts
import Base from '@ohos.base';

let formIds: string[] = new Array('12400633174999288', '12400633174999289');
formHost.notifyFormsEnableUpdate(formIds, true, (error: Base.BusinessError) => {
  if (error.code) {
    console.error(`formHost notifyFormsEnableUpdate, error: ${JSON.stringify(error)}`);
  }
});
```

## notifyFormsEnableUpdate

notifyFormsEnableUpdate(formIds: Array&lt;string&gt;, isEnableUpdate: boolean): Promise&lt;void&gt;

通知卡片是否启用更新状态。使用Promise异步回调。

**需要权限：** ohos.permission.REQUIRE_FORM

**系统能力：** SystemCapability.Ability.Form

**参数：**

  | 参数名 | 类型    | 必填 | 说明    |
  | ------ | ------ | ---- | ------- |
  | formIds | Array&lt;string&gt; | 是   | 卡片标识列表。 |
  | isEnableUpdate | boolean | 是   | 是否使能更新。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```ts
import Base from '@ohos.base';

let formIds: string[] = new Array('12400633174999288', '12400633174999289');
formHost.notifyFormsEnableUpdate(formIds, true).then(() => {
  console.log('formHost notifyFormsEnableUpdate success');
}).catch((error: Base.BusinessError) => {
  console.error(`formHost notifyFormsEnableUpdate, error: ${JSON.stringify(error)}`);
});
```
