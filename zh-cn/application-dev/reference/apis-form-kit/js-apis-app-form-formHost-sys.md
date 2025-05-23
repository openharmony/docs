# @ohos.app.form.formHost (formHost)(系统接口)

formHost模块提供了卡片使用方相关接口的能力，包括对使用方同一用户下安装的卡片进行删除、释放、请求更新、获取卡片信息、状态等操作。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口均为系统接口。

## 导入模块

```ts
import { formHost } from '@kit.FormKit';
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

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form cannot be operated by the current application. |

**示例：**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formId: string = '12400633174999288';
  formHost.deleteForm(formId, (error: BusinessError) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    } else {
      console.log('formHost deleteForm success');
    }
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
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


**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form cannot be operated by the current application. |

**示例：**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formId: string = '12400633174999288';
  formHost.deleteForm(formId).then(() => {
    console.log('formHost deleteForm success');
  }).catch((error: BusinessError) => {
    console.error(`formHost deleteForm, error: ${JSON.stringify(error)}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
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

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form cannot be operated by the current application. |

**示例：**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formId: string = '12400633174999288';
  formHost.releaseForm(formId, (error: BusinessError) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    }
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
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

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form cannot be operated by the current application. |

**示例：**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formId: string = '12400633174999288';
  formHost.releaseForm(formId, true, (error: BusinessError) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    }
  });
} catch(error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
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
| isReleaseCache | boolean | 否   | 是否释放缓存，默认为false。  |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form cannot be operated by the current application. |

**示例：**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formId: string = '12400633174999288';
  formHost.releaseForm(formId, true).then(() => {
    console.log('formHost releaseForm success');
  }).catch((error: BusinessError) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
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

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form cannot be operated by the current application. |

**示例：**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formId: string = '12400633174999288';
  formHost.requestForm(formId, (error: BusinessError) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    }
  });
} catch(error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
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

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form cannot be operated by the current application. |

**示例：**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formId: string = '12400633174999288';
  formHost.requestForm(formId).then(() => {
    console.log('formHost requestForm success');
  }).catch((error: BusinessError) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## requestFormWithParams<sup>12+</sup>

requestFormWithParams(formId: string, wantParams?: Record<string, Object>): Promise&lt;void&gt;

携带参数请求卡片更新。使用Promise异步回调。

**需要权限：** ohos.permission.REQUIRE_FORM

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| formId | string | 是   | 卡片标识。 |
| wantParams | Record<string, Object> | 否   | 更新参数。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form cannot be operated by the current application. |

**示例：**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formId: string = '12400633174999288';
  let params: Record<string, Object> = {
    'ohos.extra.param.key.host_bg_inverse_color': '#ff000000' as Object
  };
  formHost.requestFormWithParams(formId, params).then(() => {
    console.log('formHost requestFormWithParams success');
  }).catch((error: BusinessError) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## castToNormalForm

castToNormalForm(formId: string, callback: AsyncCallback&lt;void&gt;): void

将指定的临时卡片转换为普通卡片。使用callback异步回调。

**需要权限：** ohos.permission.REQUIRE_FORM

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| formId | string | 是   | 卡片标识。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当将指定的临时卡片转换为普通卡片成功，error为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501002 | The number of forms exceeds the maximum allowed. |
| 16501003 | The form cannot be operated by the current application. |

**示例：**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formId: string = '12400633174999288';
  formHost.castToNormalForm(formId, (error: BusinessError) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    }
  });
} catch(error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## castToNormalForm

castToNormalForm(formId: string): Promise&lt;void&gt;

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

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501002 | The number of forms exceeds the maximum allowed. |
| 16501003 | The form cannot be operated by the current application. |

**示例：**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formId: string = '12400633174999288';
  formHost.castToNormalForm(formId).then(() => {
    console.log('formHost castTempForm success');
  }).catch((error: BusinessError) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
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

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred. |

**示例：**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formId: string[] = ['12400633174999288'];
  formHost.notifyVisibleForms(formId, (error: BusinessError) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    }
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
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

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred. |

**示例：**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formId: string[] = ['12400633174999288'];
  formHost.notifyVisibleForms(formId).then(() => {
    console.log('formHost notifyVisibleForms success');
  }).catch((error: BusinessError) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
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

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred. |

**示例：**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formId: string[] = ['12400633174999288'];
  formHost.notifyInvisibleForms(formId, (error: BusinessError) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    }
  });
} catch(error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
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

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred. |

**示例：**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formId: string[] = ['12400633174999288'];
  formHost.notifyInvisibleForms(formId).then(() => {
    console.log('formHost notifyInvisibleForms success');
  }).catch((error: BusinessError) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
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

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred. |
| 16501003 | The form cannot be operated by the current application. |

**示例：**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formId: string[] = ['12400633174999288'];
  formHost.enableFormsUpdate(formId, (error: BusinessError) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    }
  });
} catch(error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
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

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred. |
| 16501003 | The form cannot be operated by the current application. |

**示例：**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formId: string[] = ['12400633174999288'];
  formHost.enableFormsUpdate(formId).then(() => {
    console.log('formHost enableFormsUpdate success');
  }).catch((error: BusinessError) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
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

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form cannot be operated by the current application. |

**示例：**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formId: string[] = ['12400633174999288'];
  formHost.disableFormsUpdate(formId, (error: BusinessError) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    }
  });
} catch(error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
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

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form cannot be operated by the current application. |

**示例：**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formId: string[] = ['12400633174999288'];
  formHost.disableFormsUpdate(formId).then(() => {
    console.log('formHost disableFormsUpdate success');
  }).catch((error: BusinessError) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## isSystemReady

isSystemReady(callback: AsyncCallback&lt;void&gt;): void

检查系统是否准备好。使用callback异步回调。

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当检查系统是否准备好成功，error为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 202 | The application is not a system application.   |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |

**示例：**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  formHost.isSystemReady((error: BusinessError) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    }
  });
} catch(error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## isSystemReady

isSystemReady(): Promise&lt;void&gt;

检查系统是否准备好。使用Promise异步回调。

**系统能力：** SystemCapability.Ability.Form

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 202 | The application is not a system application.   |

**示例：**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  formHost.isSystemReady().then(() => {
    console.log('formHost isSystemReady success');
  }).catch((error: BusinessError) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## getAllFormsInfo

getAllFormsInfo(callback: AsyncCallback&lt;Array&lt;formInfo.FormInfo&gt;&gt;): void

获取设备上所有应用提供的卡片信息。使用callback异步回调。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型                                                                                           | 必填 | 说明    |
| ------ |----------------------------------------------------------------------------------------------| ---- | ------- |
| callback | AsyncCallback&lt;Array&lt;[formInfo.FormInfo](js-apis-app-form-formInfo.md#forminfo)&gt;&gt; | 是 | 回调函数。当获取设备上所有应用提供的卡片信息成功，error为undefined，data为查询到的卡片信息；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred. |

**示例：**

```ts
import { formHost, formInfo } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  formHost.getAllFormsInfo((error: BusinessError, data: formInfo.FormInfo[]) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    } else {
      console.log(`formHost getAllFormsInfo, data: ${JSON.stringify(data)}`);
    }
  });
} catch(error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## getAllFormsInfo

getAllFormsInfo(): Promise&lt;Array&lt;formInfo.FormInfo&gt;&gt;

获取设备上所有应用提供的卡片信息。使用Promise异步回调。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.Ability.Form

**返回值：**

| 类型                                                                                     | 说明                    |
|:---------------------------------------------------------------------------------------|:----------------------|
| Promise&lt;Array&lt;[formInfo.FormInfo](js-apis-app-form-formInfo.md#forminfo)&gt;&gt; | Promise对象。返回查询到的卡片信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred. |

**示例：**

```ts
import { formHost, formInfo } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  formHost.getAllFormsInfo().then((data: formInfo.FormInfo[]) => {
    console.log(`formHost getAllFormsInfo data: ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## getFormsInfo

getFormsInfo(bundleName: string, callback: AsyncCallback&lt;Array&lt;formInfo.FormInfo&gt;&gt;): void

获取设备上指定应用程序提供的卡片信息。使用callback异步回调。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型                                                                                           | 必填 | 说明    |
| ------ |----------------------------------------------------------------------------------------------| ---- | ------- |
| bundleName | string                                                                                       | 是 | 要查询的应用Bundle名称。 |
| callback | AsyncCallback&lt;Array&lt;[formInfo.FormInfo](js-apis-app-form-formInfo.md#forminfo)&gt;&gt; | 是 | 回调函数。当获取设备上指定应用程序提供的卡片信息成功，error为undefined，data为查询到的卡片信息；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

**示例：**

```ts
import { formHost, formInfo } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  formHost.getFormsInfo('com.example.ohos.formjsdemo', (error: BusinessError, data: formInfo.FormInfo[]) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    } else {
      console.log(`formHost getFormsInfo, data: ${JSON.stringify(data)}`);
    }
  });
} catch(error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## getFormsInfo

getFormsInfo(bundleName: string, moduleName: string, callback: AsyncCallback&lt;Array&lt;formInfo.FormInfo&gt;&gt;): void

获取设备上指定应用程序提供的卡片信息。使用callback异步回调。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型                                                                                           | 必填 | 说明    |
| ------ |----------------------------------------------------------------------------------------------| ---- | ------- |
| bundleName | string                                                                                       | 是 | 要查询的应用Bundle名称。 |
| moduleName | string                                                                                       | 是 |  要查询的模块名称。 |
| callback | AsyncCallback&lt;Array&lt;[formInfo.FormInfo](js-apis-app-form-formInfo.md#forminfo)&gt;&gt; | 是 | 回调函数。当获取设备上指定应用程序提供的卡片信息成功，error为undefined，data为查询到的卡片信息；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

**示例：**

```ts
import { formHost, formInfo } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  formHost.getFormsInfo('com.example.ohos.formjsdemo', 'entry', (error: BusinessError, data: formInfo.FormInfo[]) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    } else {
      console.log(`formHost getFormsInfo, data: ${JSON.stringify(data)}`);
    }
  });
} catch(error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## getFormsInfo

getFormsInfo(bundleName: string, moduleName?: string): Promise&lt;Array&lt;formInfo.FormInfo&gt;&gt;

获取设备上指定应用程序提供的卡片信息。使用Promise异步回调。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| bundleName | string | 是 | 要查询的应用Bundle名称。 |
| moduleName | string | 否 |  要查询的模块名称，缺省默认为空。 |

**返回值：**

| 类型                                                                                     | 说明                                |
|:---------------------------------------------------------------------------------------| :---------------------------------- |
| Promise&lt;Array&lt;[formInfo.FormInfo](js-apis-app-form-formInfo.md#forminfo)&gt;&gt; | Promise对象。返回查询到的卡片信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

**示例：**

```ts
import { formHost, formInfo } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  formHost.getFormsInfo('com.example.ohos.formjsdemo', 'entry').then((data: formInfo.FormInfo[]) => {
    console.log(`formHost getFormsInfo, data: ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## getFormsInfo<sup>12+</sup>

getFormsInfo(filter: formInfo.FormInfoFilter): Promise&lt;Array&lt;formInfo.FormInfo&gt;&gt;

获取设备上指定应用程序提供的卡片信息。使用Promise异步回调。

**需要权限**：ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| filter | [formInfo.FormInfoFilter](js-apis-app-form-formInfo.md#forminfofilter) | 是 | 卡片信息过滤器。 |

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise&lt;Array&lt;[formInfo.FormInfo](js-apis-app-form-formInfo.md)&gt;&gt; | Promise对象。返回查询到符合条件的卡片信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application.  |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error.  |
| 16500060 | Service connection error.  |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

**示例：**

```ts
import { formHost, formInfo } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

const filter: formInfo.FormInfoFilter = {
  bundleName: 'ohos.samples.FormApplication',
  moduleName: 'entry',
  supportedDimensions: [FormDimension.Dimension_1_2, FormDimension.Dimension_2_2, FormDimension.Dimension_2_4]
};
try {
  formHost.getFormsInfo(filter).then((data: formInfo.FormInfo[]) => {
    console.log(`formHost getFormsInfo, data: ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
    console.error(`promise error, code: ${error.code}, message: ${error.message})`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message})`);
}
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

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred. |

**示例：**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formIds: string[] = new Array('12400633174999288', '12400633174999289');
  formHost.deleteInvalidForms(formIds, (error: BusinessError, data: number) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    } else {
      console.log(`formHost deleteInvalidForms, data: ${JSON.stringify(data)}`);
    }
  });
} catch(error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
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

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred. |

**示例：**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formIds: string[] = new Array('12400633174999288', '12400633174999289');
  formHost.deleteInvalidForms(formIds).then((data: number) => {
    console.log(`formHost deleteInvalidForms, data: ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## acquireFormState

acquireFormState(want: Want, callback: AsyncCallback&lt;formInfo.FormStateInfo&gt;): void

获取卡片状态。使用callback异步回调。

**需要权限：** ohos.permission.REQUIRE_FORM 和 ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| want | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 查询卡片状态时携带的want信息。需要包含bundle名、ability名、module名、卡片名、卡片规格等。 |
| callback | AsyncCallback&lt;[formInfo.FormStateInfo](js-apis-app-form-formInfo.md#formstateinfo)&gt; | 是 | 回调函数。当获取卡片状态成功，error为undefined，data为获取到的卡片状态；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

**示例：**

```ts
import { formHost, formInfo } from '@kit.FormKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
try {
  formHost.acquireFormState(want, (error: BusinessError, data: formInfo.FormStateInfo) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    } else {
      console.log(`formHost acquireFormState, data: ${JSON.stringify(data)}`);
    }
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## acquireFormState

acquireFormState(want: Want): Promise&lt;formInfo.FormStateInfo&gt;

获取卡片状态。使用Promise异步回调。

**需要权限：** ohos.permission.REQUIRE_FORM 和 ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| want   | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 查询卡片状态时携带的want信息。需要包含bundle名、ability名、module名、卡片名、卡片规格等。 |

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise&lt;[formInfo.FormStateInfo](js-apis-app-form-formInfo.md#formstateinfo)&gt; | Promise对象。返回卡片状态。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

**示例：**

```ts
import { formHost, formInfo } from '@kit.FormKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
try {
  formHost.acquireFormState(want).then((data: formInfo.FormStateInfo) => {
    console.log(`formHost acquireFormState, data: ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
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

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |

**示例：**

```ts
import { formHost } from '@kit.FormKit';

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

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |

**示例：**

```ts
import { formHost } from '@kit.FormKit';

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

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred. |
| 16501003 | The form cannot be operated by the current application. |

**示例：**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

let formIds: string[] = new Array('12400633174999288', '12400633174999289');
try {
  formHost.notifyFormsVisible(formIds, true, (error: BusinessError) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    }
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
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

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred. |
| 16501003 | The form cannot be operated by the current application. |

**示例：**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

let formIds: string[] = new Array('12400633174999288', '12400633174999289');
try {
  formHost.notifyFormsVisible(formIds, true).then(() => {
    console.log('formHost notifyFormsVisible success');
  }).catch((error: BusinessError) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
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

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred. |
| 16501003 | The form cannot be operated by the current application. |

**示例：**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

let formIds: string[] = new Array('12400633174999288', '12400633174999289');
try {
  formHost.notifyFormsEnableUpdate(formIds, true, (error: BusinessError) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    }
  });
} catch(error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
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

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred. |
| 16501003 | The form cannot be operated by the current application. |

**示例：**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

let formIds: string[] = new Array('12400633174999288', '12400633174999289');
try {
  formHost.notifyFormsEnableUpdate(formIds, true).then(() => {
    console.log('formHost notifyFormsEnableUpdate success');
  }).catch((error: BusinessError) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```
## shareForm

shareForm(formId: string, deviceId: string, callback: AsyncCallback&lt;void&gt;): void

指定formId和远程设备Id进行卡片分享。使用callback异步回调。

**需要权限：** ohos.permission.REQUIRE_FORM 和 ohos.permission.DISTRIBUTED_DATASYNC

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| formId | string | 是   | 卡片标识。 |
| deviceId | string | 是   | 远程设备标识。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当指定formId和远程设备Id进行卡片分享成功，error为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form cannot be operated by the current application. |

**示例：**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

let formId: string = '12400633174999288';
let deviceId: string = 'EFC11C0C53628D8CC2F8CB5052477E130D075917034613B9884C55CD22B3DEF2';
try {
  formHost.shareForm(formId, deviceId, (error: BusinessError) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    }
  });
} catch(error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## shareForm

shareForm(formId: string, deviceId: string): Promise&lt;void&gt;

指定formId和远程设备Id进行卡片分享。使用Promise异步回调。

**需要权限：** ohos.permission.REQUIRE_FORM 和 ohos.permission.DISTRIBUTED_DATASYNC

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| formId | string | 是   | 卡片标识。 |
| deviceId | string | 是   | 远程设备标识。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form cannot be operated by the current application. |

**示例：**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

let formId: string = '12400633174999288';
let deviceId: string = 'EFC11C0C53628D8CC2F8CB5052477E130D075917034613B9884C55CD22B3DEF2';
try {
  formHost.shareForm(formId, deviceId).then(() => {
    console.log('formHost shareForm success');
  }).catch((error: BusinessError) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## notifyFormsPrivacyProtected

notifyFormsPrivacyProtected(formIds: Array\<string>, isProtected: boolean, callback: AsyncCallback\<void>): void

通知指定卡片隐私保护状态改变。使用callback异步回调。

**需要权限：** ohos.permission.REQUIRE_FORM

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| formIds | Array\<string\> | 是   | 需要修改隐私保护的卡片标识列表。 |
| isProtected | boolean | 是   | 是否进行隐私保护。 |
| callback | AsyncCallback\<void> | 是 | 回调函数。当指定卡片设置隐私保护属性成功，error为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred. |

**示例：**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

let formIds: string[] = new Array('12400633174999288', '12400633174999289');
try {
  formHost.notifyFormsPrivacyProtected(formIds, true, (error: BusinessError) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    }
  });
} catch(error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## notifyFormsPrivacyProtected

notifyFormsPrivacyProtected(formIds: Array\<string\>, isProtected: boolean): Promise\<void\>

通知指定卡片隐私保护状态改变。使用Promise异步回调。

**需要权限：** ohos.permission.REQUIRE_FORM

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名      | 类型            | 必填 | 说明                             |
| ----------- | --------------- | ---- | -------------------------------- |
| formIds     | Array\<string\> | 是   | 需要修改隐私保护的卡片标识列表。 |
| isProtected | boolean         | 是   | 是否进行隐私保护。               |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred. |

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

let formIds: string[] = new Array('12400633174999288', '12400633174999289');
try {
  formHost.notifyFormsPrivacyProtected(formIds, true).then(() => {
    console.log('formHost notifyFormsPrivacyProtected success');
  }).catch((error: BusinessError) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## acquireFormData<sup>10+</sup>

acquireFormData(formId: string, callback: AsyncCallback\<Record\<string, Object>>): void

请求卡片提供方数据。使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限：** ohos.permission.REQUIRE_FORM

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| formId | string | 是   | 卡片标识。 |
| callback | AsyncCallback\<Record\<string, Object> | 是   | 以callback方式返回接口运行结果及分享数据。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

**示例：**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

let formId: string = '12400633174999288';
try {
  formHost.acquireFormData(formId, (error, data) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    } else {
      console.log(`formHost acquireFormData, data: ${JSON.stringify(data)}`);
    }
  });
} catch(error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## acquireFormData<sup>10+</sup>

acquireFormData(formId: string): Promise\<Record\<string, Object>>

请求卡片提供方数据。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限：** ohos.permission.REQUIRE_FORM

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名      | 类型            | 必填 | 说明                             |
| ----------- | --------------- | ---- | -------------------------------- |
| formId | string | 是   | 卡片标识。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise\<Record\<string, Object>>| 以Promise方式返回接口运行结果及分享数据。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

**示例：**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

let formId: string = '12400633174999288';
try {
  formHost.acquireFormData(formId).then((data) => {
    console.log('formHost acquireFormData success' + data);
  }).catch((error: BusinessError) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## setRouterProxy<sup>11+</sup>

setRouterProxy(formIds: Array&lt;string&gt;, proxy: Callback&lt;Want&gt;, callback: AsyncCallback&lt;void&gt;): void

设置卡片跳转代理。使用callback异步回调，返回卡片跳转所需要Want信息。



> **说明：**
>
>- 一般情况下，对于桌面添加的卡片，当卡片触发router跳转时，卡片框架会检测其跳转目的地是否合理，是否有跳转权限，然后进行应用跳转。如果卡片使用方添加了卡片，并设置了卡片跳转代理，那么卡片触发router跳转时，卡片框架不会再为其进行跳转操作，会把包含跳转目的地的want参数返回给卡片使用方。因此如果卡片使用方希望使用该want信息进行应用跳转，需要确保自身拥有应用跳转的权限，参考
[UIAbilityContext.startAbility()](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability)接口。
>
>- 一个formId最多只能设置一个跳转代理，多次设置后，最后设置的proxy生效。

**需要权限：** ohos.permission.REQUIRE_FORM

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                                         |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| formIds  | Array&lt;string&gt;       | 是   | 卡片标识数组。                                               |
| proxy    | Callback&lt;Want&gt;      | 是   | 回调函数。返回跳转所需要的Want信息。                         |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数，当指定卡片设置router跳转代理成功时，error为undefined；否则抛出异常。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permissions denied.                                          |
| 202      | The application is not a system application.                 |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error.                            |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred.                       |
| 16501003 | The form cannot be operated by the current application.     |

**示例：**

```ts
import { common, Want } from '@kit.AbilityKit';
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct CardExample {
  private context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  @State formId: number = 0;
  @State fwidth: number = 420;
  @State fheight: number = 280;

  build() {
    Column() {
      FormComponent({
        id: this.formId,
        name: "widget",
        bundle: "com.example.cardprovider",
        ability: "EntryFormAbility",
        module: "entry",
        dimension: FormDimension.Dimension_2_2,
        temporary: false,
      })
        .allowUpdate(true)
        .size({ width: this.fwidth, height: this.fheight })
        .visibility(Visibility.Visible)
        .onAcquired((form) => {
          console.log(`testTag form info : ${JSON.stringify(form)}`);
          this.formId = form.id;
          try {
            let formIds: string[] = [this.formId.toString()];
            formHost.setRouterProxy(formIds, (want: Want) => {
              console.info(`formHost recv router event, want: ${JSON.stringify(want)}`);
              // 卡片使用方自己处理跳转
              this.context.startAbility(want, (err: BusinessError) => {
                console.info(`formHost startAbility error, code: ${err.code}, message: ${err.message}`);
              });
            }, (err: BusinessError) => {
              console.error(`set router proxy error, code: ${err.code}, message: ${err.message}`);
            })
          } catch (e) {
            console.log('formHost setRouterProxy catch exception: ' + JSON.stringify(e));
          }
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

## setRouterProxy<sup>11+</sup>

setRouterProxy(formIds: Array&lt;string&gt;, proxy: Callback&lt;Want&gt;): Promise&lt;void&gt;

设置卡片跳转代理。使用Promise异步回调，返回卡片跳转所需要Want信息。

> **说明：**
>
>- 一般情况下，对于桌面添加的卡片，当卡片触发router跳转时，卡片框架会检测其跳转目的地是否合理，是否有跳转权限，然后进行应用跳转。如果卡片使用方添加了卡片，并设置了卡片跳转代理，那么卡片触发router跳转时，卡片框架不会再为其进行跳转操作，会把包含跳转目的地的want参数返回给卡片使用方。因此如果卡片使用方希望使用该want信息进行应用跳转，需要确保自身拥有应用跳转的权限，参考[UIAbilityContext.startAbility()](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability)接口。
>
>- 一个formId最多只能设置一个跳转代理，多次设置后，最后设置的proxy生效。



**需要权限：** ohos.permission.REQUIRE_FORM

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名  | 类型                 | 必填 | 说明                                 |
| ------- | -------------------- | ---- | ------------------------------------ |
| formIds | Array&lt;string&gt;  | 是   | 卡片标识数组。                       |
| proxy   | Callback&lt;Want&gt; | 是   | 回调函数。返回跳转所需要的Want信息。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permissions denied.                                          |
| 202      | The application is not a system application.                 |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error.                            |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred.                       |
| 16501003 | The form cannot be operated by the current application.     |

**示例：**

```ts
import { formHost } from '@kit.FormKit';
import { common, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct CardExample {
  private context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  @State formId: number = 0;
  @State fwidth: number = 420;
  @State fheight: number = 280;

  build() {
    Column() {
      FormComponent({
        id: this.formId,
        name: "widget",
        bundle: "com.example.cardprovider",
        ability: "EntryFormAbility",
        module: "entry",
        dimension: FormDimension.Dimension_2_2,
        temporary: false,
      })
        .allowUpdate(true)
        .size({ width: this.fwidth, height: this.fheight })
        .visibility(Visibility.Visible)
        .onAcquired((form) => {
          console.log(`testTag form info : ${JSON.stringify(form)}`);
          this.formId = form.id;
          try {
            let formIds: string[] = [this.formId.toString()];
            formHost.setRouterProxy(formIds, (want: Want) => {
              console.info(`formHost recv router event, want: ${JSON.stringify(want)}`);
              // 卡片使用方自己处理跳转
              this.context.startAbility(want, (err: BusinessError) => {
                console.info(`formHost startAbility error, code: ${err.code}, message: ${err.message}`);
              });
            }).then(() => {
              console.info('formHost set router proxy success');
            }).catch((err: BusinessError) => {
              console.error(`set router proxy error, code: ${err.code}, message: ${err.message}`);
            })
          } catch (e) {
            console.log('formHost setRouterProxy catch exception: ' + JSON.stringify(e));
          }
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

## clearRouterProxy<sup>11+</sup>

clearRouterProxy(formIds:Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void

清除卡片跳转代理。使用callback异步回调。

**需要权限：** ohos.permission.REQUIRE_FORM

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                                         |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| formIds  | Array&lt;string&gt;;      | 是   | 卡片标识数组。                                               |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数，当指定卡片取消router跳转代理成功时，error为undefined；否则抛出异常。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permissions denied.                                          |
| 202      | The application is not a system application.                 |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error.                            |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred.                       |
| 16501003 | The form cannot be operated by the current application.     |

**示例：**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formIds: string[] = ['12400633174999288'];
  formHost.clearRouterProxy(formIds, (err: BusinessError) => {
    if (err) {
      console.error(`formHost clear router proxy error, code: ${err.code}, message: ${err.message}`);
    }
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## clearRouterProxy<sup>11+</sup>

clearRouterProxy(formIds:Array&lt;string&gt;): Promise&lt;void&gt;

清除卡片跳转代理。使用Promise异步回调。

**需要权限：** ohos.permission.REQUIRE_FORM

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名  | 类型                | 必填 | 说明           |
| ------- | ------------------- | ---- | -------------- |
| formIds | Array&lt;string&gt; | 是   | 卡片标识数组。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permissions denied.                                          |
| 202      | The application is not a system application.                 |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error.                            |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred.                       |
| 16501003 | The form cannot be operated by the current application.     |

**示例：**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formIds: string[] = ['12400633174999288'];
  formHost.clearRouterProxy(formIds).then(() => {
    console.log('formHost clear rourter proxy success');
  }).catch((err: BusinessError) => {
    console.error(`formHost clear router proxy error, code: ${err.code}, message: ${err.message}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```
## setFormsRecyclable<sup>11+</sup>

setFormsRecyclable(formIds:Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void

设置卡片可回收。使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限：** ohos.permission.REQUIRE_FORM

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                                         |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| formIds  | Array&lt;string&gt;;      | 是   | 卡片标识数组。                                               |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数，当设置卡片可回收成功时，error为undefined；否则抛出异常。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permissions denied.                                          |
| 202      | The application is not a system application.                 |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error.                            |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred.                       |

**示例：**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formIds: string[] = ['12400633174999288'];
  formHost.setFormsRecyclable(formIds, (err: BusinessError) => {
    if (err) {
      console.error(`setFormsRecyclable error, code: ${err.code}, message: ${err.message}`);
    }
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## setFormsRecyclable<sup>11+</sup>

setFormsRecyclable(formIds:Array&lt;string&gt;): Promise&lt;void&gt;

设置卡片可回收。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限：** ohos.permission.REQUIRE_FORM

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名  | 类型                | 必填 | 说明           |
| ------- | ------------------- | ---- | -------------- |
| formIds | Array&lt;string&gt; | 是   | 卡片标识数组。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permissions denied.                                          |
| 202      | The application is not a system application.                 |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error.                            |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred.                       |

**示例：**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formIds: string[] = ['12400633174999288'];
  formHost.setFormsRecyclable(formIds).then(() => {
    console.log('setFormsRecyclable success');
  }).catch((err: BusinessError) => {
    console.error(`setFormsRecyclable error, code: ${err.code}, message: ${err.message}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```
## recoverForms<sup>11+</sup>

recoverForms(formIds:Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void

恢复卡片。使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限：** ohos.permission.REQUIRE_FORM

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                                         |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| formIds  | Array&lt;string&gt;;      | 是   | 卡片标识数组。                                               |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数，当恢复卡片成功时，error为undefined；否则抛出异常。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permissions denied.                                          |
| 202      | The application is not a system application.                 |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error.                            |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred.                       |

**示例：**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formIds: string[] = ['12400633174999288'];
  formHost.recoverForms(formIds, (err: BusinessError) => {
    if (err) {
      console.error(`recoverForms error, code: ${err.code}, message: ${err.message}`);
    }
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```
## recoverForms<sup>11+</sup>

recoverForms(formIds: Array&lt;string&gt;): Promise&lt;void&gt;

恢复被回收的卡片，并将它的状态更新为不可回收，如果卡片未被回收则只更新状态为不可回收。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限：** ohos.permission.REQUIRE_FORM

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名  | 类型                | 必填 | 说明           |
| ------- | ------------------- | ---- | -------------- |
| formIds | Array&lt;string&gt; | 是   | 卡片标识数组。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |


**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permissions denied.                                          |
| 202      | The application is not a system application.                 |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error.                            |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred.                       |

**示例：**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formIds: string[] = ['12400633174999288'];
  formHost.recoverForms(formIds).then(() => {
    console.info('recover forms success');
  }).catch((err: BusinessError) => {
    console.error(`formHost recover forms error, code: ${err.code}, message: ${err.message}`);
  });
} catch (e) {
  console.info(`catch error, code: ${e.code}, message: ${e.message}`);
}
```
## recycleForms<sup>12+</sup>

recycleForms(formIds: Array&lt;string&gt;): Promise&lt;void&gt;

立即回收卡片内存。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限：** ohos.permission.REQUIRE_FORM

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名  | 类型                | 必填 | 说明           |
| ------- | ------------------- | ---- | -------------- |
| formIds | Array&lt;string&gt; | 是   | 卡片标识数组。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |


**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permissions denied.                                          |
| 202      | The application is not a system application.                 |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error.                            |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred.                       |

**示例：**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formIds: string[] = ['12400633174999288'];
  formHost.recycleForms(formIds).then(() => {
    console.info('recycle forms success');
  }).catch((err: BusinessError) => {
    console.error(`formHost recycle forms error, code: ${err.code}, message: ${err.message}`);
  });
} catch (e) {
  console.error(`catch error, code: ${e.code}, message: ${e.message}`);
}
```

## updateFormLocation<sup>12+</sup>
updateFormLocation(formId: string, location: formInfo.FormLocation): void;

更新卡片位置。

**模型约束**: 此接口仅可在Stage模型下使用。

**需要权限**：ohos.permission.REQUIRE_FORM

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| formId | string | 是   | 卡片标识。 |
| location |[formInfo.FormLocation](js-apis-app-form-formInfo-sys.md#formlocation) | 是 | 卡片位置。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permissions denied.                                          |
| 202      | The application is not a system application.                                    |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error.                            |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred.                       |
| 16501001 | The ID of the form to be operated does not exist.            |
| 16501003 | The form cannot be operated by the current application.     |

**示例：**

```ts
import { formHost, formInfo } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formId: string = '12400633174999288';
  formHost.updateFormLocation(formId, formInfo.FormLocation.SCREEN_LOCK);
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## setPublishFormResult<sup>12+</sup>

setPublishFormResult(formId: string, result: formInfo.PublishFormResult): void;

设置卡片加桌结果。

**模型约束**: 此接口仅可在Stage模型下使用。

**需要权限**：ohos.permission.REQUIRE_FORM

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明               |
| ------ | ------------------------------------------------------------ | ---- | ------------------ |
| formId | string                                                       | 是   | 卡片标识。         |
| result | [PublishFormResult](js-apis-app-form-formInfo-sys.md#publishformresult) | 是   | 发布卡片加桌结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permissions denied.                                          |
| 202      | The application is not a system application.                                    |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error.                            |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred.                       |
| 16501001 | The ID of the form to be operated does not exist.            |

**示例：**

```ts
import { formHost, formInfo } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formId: string = '12400633174999288';
  let res: formInfo.PublishFormResult = {code: formInfo.PublishFormErrorCode.SUCCESS, message: ''};
  formHost.setPublishFormResult(formId, res);
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## updateFormLockedState<sup>18+</sup>

updateFormLockedState(formId: string, isLocked: boolean): Promise&lt;void&gt;

通知卡片管控状态更新。

卡片管控状态是指，应用使能了应用锁管控，对应应用的卡片也会跟随使能应用锁管控，此时卡片页面会使用加锁的蒙板样式遮罩卡片。在管控状态下，操作和使用卡片需要输入加锁时设置的密码。

**模型约束**: 此接口仅可在Stage模型下使用。

**需要权限**：ohos.permission.REQUIRE_FORM

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|-------|------|------|-----|
| formId | string | 是 | 卡片标识。 |
| isLocked | boolean | 是 | 标识卡片是否为管控状态，true表示管控状态，false表示非管控状态。 |

**返回值：**
| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permissions denied.                                          |
| 202      | caller is not a system app.                 |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error.                            |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred.                       |
| 16501001 | The ID of the form to be operated does not exist.                       |
| 16501003 | The form cannot be operated by the current application.     |

**示例：**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

let formId: string = '12400633174999288';
let isLocked: boolean = true;

try {
  formHost.updateFormLockedState(this.formId, this.isLocked).then(() => {
    console.log(`formHost updateFormLockedState success`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}

```