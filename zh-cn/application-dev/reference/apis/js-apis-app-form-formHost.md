# @ohos.app.form.formHost (formHost)

formHost模块提供了卡片使用方相关接口的能力，包括对使用方同一用户下安装的卡片进行删除、释放、请求更新、获取卡片信息、状态等操作。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口均为系统接口。

## 导入模块

```ts
import formHost from '@ohos.app.form.formHost';
```

## deleteForm

deleteForm(formId: string, callback: AsyncCallback&lt;void&gt;): void

删除指定的卡片。调用此方法后，应用程序将无法使用该卡片，卡片管理器服务不再保留有关该卡片的信息。使用callback异步回调。

**需要权限**：ohos.permission.REQUIRE_FORM

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| formId | string | 是   | 卡片标识。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当删除指定的卡片成功，error为undefined，否则为错误对象 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form can not be operated by the current application. |

以上错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

**示例：**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  let formId = '12400633174999288';
  formHost.deleteForm(formId, (error) => {
  if (error) {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  } else {
    console.log('formHost deleteForm success');
  }
  });
} catch (error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## deleteForm

deleteForm(formId: string): Promise&lt;void&gt;

删除指定的卡片。调用此方法后，应用程序将无法使用该卡片，卡片管理器服务不再保留有关该卡片的信息。使用Promise异步回调。

**需要权限**：ohos.permission.REQUIRE_FORM

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| formId | string | 是   | 卡片标识。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |


**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form can not be operated by the current application. |

以上错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

**参数：**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  let formId = '12400633174999288';
  formHost.deleteForm(formId).then(() => {
    console.log('formHost deleteForm success');
  }).catch((error) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## releaseForm

releaseForm(formId: string, callback: AsyncCallback&lt;void&gt;): void

释放指定的卡片。调用此方法后，应用程序将无法使用该卡片，但卡片管理器服务仍然保留有关该卡片的缓存信息和存储信息。使用callback异步回调。

**需要权限**：ohos.permission.REQUIRE_FORM

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| formId | string | 是   | 卡片标识。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当释放指定的卡片成功，error为undefined；否则为错误对象。|

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form can not be operated by the current application. |

以上错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

**示例：**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  let formId = '12400633174999288';
  formHost.releaseForm(formId, (error) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    }
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## releaseForm

releaseForm(formId: string, isReleaseCache: boolean, callback: AsyncCallback&lt;void&gt;): void

释放指定的卡片。调用此方法后，应用程序将无法使用该卡片，卡片管理器服务保留有关该卡片的存储信息，可以选择是否保留缓存信息。使用callback异步回调。

**需要权限**：ohos.permission.REQUIRE_FORM

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名         | 类型     | 必填 | 说明        |
| -------------- | ------  | ---- | ----------- |
| formId         | string  | 是   | 卡片标识。     |
| isReleaseCache | boolean | 是   | 是否释放缓存。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当释放指定的卡片成功，error为undefined；否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form can not be operated by the current application. |

以上错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

**示例：**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  let formId = '12400633174999288';
  formHost.releaseForm(formId, true, (error) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    }
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## releaseForm

releaseForm(formId: string, isReleaseCache?: boolean): Promise&lt;void&gt;

释放指定的卡片。调用此方法后，应用程序将无法使用该卡片，卡片管理器服务保留有关该卡片的存储信息，可以选择是否保留缓存信息。使用Promise异步回调。

**需要权限**：ohos.permission.REQUIRE_FORM

**系统能力**：SystemCapability.Ability.Form

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

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form can not be operated by the current application. |

以上错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

**示例：**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  let formId = '12400633174999288';
  formHost.releaseForm(formId, true).then(() => {
    console.log('formHost releaseForm success');
  }).catch((error) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## requestForm

requestForm(formId: string, callback: AsyncCallback&lt;void&gt;): void

请求卡片更新。使用callback异步回调。

**需要权限**：ohos.permission.REQUIRE_FORM

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| formId | string | 是   | 卡片标识。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当请求卡片更新成功，error为undefined；否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form can not be operated by the current application. |

以上错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

**示例：**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  let formId = '12400633174999288';
  formHost.requestForm(formId, (error) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    }
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## requestForm

requestForm(formId: string): Promise&lt;void&gt;

请求卡片更新。使用Promise异步回调。

**需要权限**：ohos.permission.REQUIRE_FORM

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| formId | string | 是   | 卡片标识。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form can not be operated by the current application. |

以上错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

**示例：**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  let formId = '12400633174999288';
  formHost.requestForm(formId).then(() => {
    console.log('formHost requestForm success');
  }).catch((error) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}

```

## castToNormalForm

castToNormalForm(formId: string, callback: AsyncCallback&lt;void&gt;): void

将指定的临时卡片转换为普通卡片。使用callback异步回调。

**需要权限**：ohos.permission.REQUIRE_FORM

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| formId | string | 是   | 卡片标识。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当将指定的临时卡片转换为普通卡片成功，error为undefined，否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501002 | The number of forms exceeds upper bound. |
| 16501003 | The form can not be operated by the current application. |

以上错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

**示例：**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  let formId = '12400633174999288';
  formHost.castToNormalForm(formId, (error) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    }
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## castToNormalForm

castToNormalForm(formId: string): Promise&lt;void&gt;

将指定的临时卡片转换为普通卡片。使用Promise异步回调。

**需要权限**：ohos.permission.REQUIRE_FORM

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| formId | string | 是   | 卡片标识。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。|

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501002 | The number of forms exceeds upper bound. |
| 16501003 | The form can not be operated by the current application. |

以上错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

**示例：**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  let formId = '12400633174999288';
  formHost.castToNormalForm(formId).then(() => {
    console.log('formHost castTempForm success');
  }).catch((error) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## notifyVisibleForms

notifyVisibleForms(formIds: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void

向卡片框架发送通知以使指定的卡片可见。该方法调用成功后，会调用onVisibilityChange通知卡片提供方。使用callback异步回调。

**需要权限**：ohos.permission.REQUIRE_FORM

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| formIds  | Array&lt;string&gt;       | 是   | 卡片标识列表。         |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当向卡片框架发送通知以使指定的卡片可见成功，error为undefined，否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16501000 | An internal functional error occurred. |

以上错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

**示例：**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  let formId = ['12400633174999288'];
  formHost.notifyVisibleForms(formId, (error) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    }
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## notifyVisibleForms

notifyVisibleForms(formIds: Array&lt;string&gt;): Promise&lt;void&gt;

向卡片框架发送通知以使指定的卡片可见。该方法调用成功后，会调用onVisibilityChange通知卡片提供方。使用Promise异步回调。

**需要权限**：ohos.permission.REQUIRE_FORM

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| formIds | Array&lt;string&gt; | 是   | 卡片标识列表。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16501000 | An internal functional error occurred. |

以上错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

**示例：**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  let formId = ['12400633174999288'];
  formHost.notifyVisibleForms(formId).then(() => {
    console.log('formHost notifyVisibleForms success');
  }).catch((error) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## notifyInvisibleForms

notifyInvisibleForms(formIds: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void

向卡片框架发送通知以使指定的卡片不可见。该方法调用成功后，会调用onVisibilityChange通知卡片提供方。使用callback异步回调。

**需要权限**：ohos.permission.REQUIRE_FORM

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| formIds  | Array&lt;string&gt;       | 是   | 卡片标识列表。|
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当向卡片框架发送通知以使指定的卡片不可见成功，error为undefined，否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16501000 | An internal functional error occurred. |

以上错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

**示例：**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  let formId = ['12400633174999288'];
  formHost.notifyInvisibleForms(formId, (error) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    }
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## notifyInvisibleForms

notifyInvisibleForms(formIds: Array&lt;string&gt;): Promise&lt;void&gt;

向卡片框架发送通知以使指定的卡片不可见。该方法调用成功后，会调用onVisibilityChange通知卡片提供方。使用Promise异步回调。

**需要权限**：ohos.permission.REQUIRE_FORM

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| formIds | Array&lt;string&gt; | 是   | 卡片标识列表。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。|

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16501000 | An internal functional error occurred. |

以上错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

**示例：**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  let formId = ['12400633174999288'];
  formHost.notifyInvisibleForms(formId).then(() => {
    console.log('formHost notifyInvisibleForms success');
  }).catch((error) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## enableFormsUpdate

enableFormsUpdate(formIds: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void

向卡片框架发送通知以使指定的卡片可以更新。该方法调用成功后，卡片刷新状态设置为使能，卡片可以接收来自卡片提供方的更新。使用callback异步回调。

**需要权限**：ohos.permission.REQUIRE_FORM

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| formIds  | Array&lt;string&gt;       | 是   | 卡片标识列表。         |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当向卡片框架发送通知以使指定的卡片可以更新成功，error为undefined，否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16501000 | An internal functional error occurred. |
| 16501003 | The form can not be operated by the current application. |

以上错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

**示例：**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  let formId = ['12400633174999288'];
  formHost.enableFormsUpdate(formId, (error) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    }
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## enableFormsUpdate

enableFormsUpdate(formIds: Array&lt;string&gt;): Promise&lt;void&gt;

向卡片框架发送通知以使指定的卡片可以更新。该方法调用成功后，卡片刷新状态设置为使能，卡片可以接收来自卡片提供方的更新。使用Promise异步回调。

**需要权限**：ohos.permission.REQUIRE_FORM

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| formIds | Array&lt;string&gt; | 是   | 卡片标识列表。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16501000 | An internal functional error occurred. |
| 16501003 | The form can not be operated by the current application. |

以上错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

**示例：**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  let formId = ['12400633174999288'];
  formHost.enableFormsUpdate(formId).then(() => {
    console.log('formHost enableFormsUpdate success');
  }).catch((error) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## disableFormsUpdate

disableFormsUpdate(formIds: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void

向卡片框架发送通知以使指定的卡片不可以更新。该方法调用成功后，卡片刷新状态设置为去使能，卡片不可以接收来自卡片提供方的更新。使用callback异步回调。

**需要权限**：ohos.permission.REQUIRE_FORM

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| formIds  | Array&lt;string&gt;       | 是   | 卡片标识列表。         |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当向卡片框架发送通知以使指定的卡片不可以更新成功，error为undefined，否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form can not be operated by the current application. |

以上错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

**示例：**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  let formId = ['12400633174999288'];
  formHost.disableFormsUpdate(formId, (error) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    }
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## disableFormsUpdate

disableFormsUpdate(formIds: Array&lt;string&gt;): Promise&lt;void&gt;

向卡片框架发送通知以使指定的卡片不可以更新。该方法调用成功后，卡片刷新状态设置为去使能，卡片不可以接收来自卡片提供方的更新。使用Promise异步回调。

**需要权限**：ohos.permission.REQUIRE_FORM

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| formIds | Array&lt;string&gt; | 是   | 卡片标识列表。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form can not be operated by the current application. |

以上错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

**示例：**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  let formId = ['12400633174999288'];
  formHost.disableFormsUpdate(formId).then(() => {
    console.log('formHost disableFormsUpdate success');
  }).catch((error) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## isSystemReady

isSystemReady(callback: AsyncCallback&lt;void&gt;): void

检查系统是否准备好。使用callback异步回调。

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当检查系统是否准备好成功，error为undefined，否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 202 | The application is not a system application.   |
| 401 | If the input parameter is not valid parameter. |

以上错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

**示例：**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  formHost.isSystemReady((error, data) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    }
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## isSystemReady

isSystemReady(): Promise&lt;void&gt;

检查系统是否准备好。使用Promise异步回调。

**系统能力**：SystemCapability.Ability.Form

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 202 | The application is not a system application.   |

以上错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

**示例：**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  formHost.isSystemReady().then(() => {
    console.log('formHost isSystemReady success');
  }).catch((error) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## getAllFormsInfo

getAllFormsInfo(callback: AsyncCallback&lt;Array&lt;formInfo.FormInfo&gt;&gt;): void

获取设备上所有应用提供的卡片信息。使用callback异步回调。

**需要权限**：ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力**：SystemCapability.Ability.Form

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16501000 | An internal functional error occurred. |

以上错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| callback | AsyncCallback&lt;Array&lt;[formInfo.FormInfo](js-apis-app-form-formInfo.md)&gt;&gt; | 是 | 回调函数。当获取设备上所有应用提供的卡片信息成功，error为undefined，data为查询到的卡片信息；否则为错误对象。 |

**示例：**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  formHost.getAllFormsInfo((error, data) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    } else {
      console.log('formHost getAllFormsInfo, data: ${JSON.stringify(data)}');
    }
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## getAllFormsInfo

getAllFormsInfo(): Promise&lt;Array&lt;formInfo.FormInfo&gt;&gt;

获取设备上所有应用提供的卡片信息。使用Promise异步回调。

**需要权限**：ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力**：SystemCapability.Ability.Form

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16501000 | An internal functional error occurred. |

以上错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

**返回值：**

| 类型                                                         | 说明                                |
| :----------------------------------------------------------- | :---------------------------------- |
| Promise&lt;Array&lt;[formInfo.FormInfo](js-apis-app-form-formInfo.md)&gt;&gt; | Promise对象，返回查询到的卡片信息。 |

**示例：**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  formHost.getAllFormsInfo().then((data) => {
    console.log('formHost getAllFormsInfo data: ${JSON.stringify(data)}');
  }).catch((error) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## getFormsInfo

getFormsInfo(bundleName: string, callback: AsyncCallback&lt;Array&lt;formInfo.FormInfo&gt;&gt;): void

获取设备上指定应用程序提供的卡片信息。使用callback异步回调。

**需要权限**：ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| bundleName | string | 是 | 要查询的应用Bundle名称。 |
| callback | AsyncCallback&lt;Array&lt;[formInfo.FormInfo](js-apis-app-form-formInfo.md)&gt;&gt; | 是 | 回调函数。当获取设备上指定应用程序提供的卡片信息成功，error为undefined，data为查询到的卡片信息；否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

以上错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

**示例：**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  formHost.getFormsInfo('com.example.ohos.formjsdemo', (error, data) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    } else {
      console.log('formHost getFormsInfo, data: ${JSON.stringify(data)}');
    }
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## getFormsInfo

getFormsInfo(bundleName: string, moduleName: string, callback: AsyncCallback&lt;Array&lt;formInfo.FormInfo&gt;&gt;): void

获取设备上指定应用程序提供的卡片信息。使用callback异步回调。

**需要权限**：ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| bundleName | string | 是 | 要查询的应用Bundle名称。 |
| moduleName | string | 是 |  要查询的模块名称。 |
| callback | AsyncCallback&lt;Array&lt;[formInfo.FormInfo](js-apis-app-form-formInfo.md)&gt;&gt; | 是 | 回调函数。当获取设备上指定应用程序提供的卡片信息成功，error为undefined，data为查询到的卡片信息；否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

以上错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

**示例：**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  formHost.getFormsInfo('com.example.ohos.formjsdemo', 'entry', (error, data) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    } else {
      console.log('formHost getFormsInfo, data: ${JSON.stringify(data)}');
    }
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## getFormsInfo

getFormsInfo(bundleName: string, moduleName?: string): Promise&lt;Array&lt;formInfo.FormInfo&gt;&gt;

获取设备上指定应用程序提供的卡片信息。使用Promise异步回调。

**需要权限**：ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| bundleName | string | 是 | 要查询的应用Bundle名称。 |
| moduleName | string | 否 |  要查询的模块名称，缺省默认为空。 |

**返回值：**

| 类型                                                         | 说明                                |
| :----------------------------------------------------------- | :---------------------------------- |
| Promise&lt;Array&lt;[formInfo.FormInfo](js-apis-app-form-formInfo.md)&gt;&gt; | Promise对象，返回查询到的卡片信息。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

以上错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

**示例：**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  formHost.getFormsInfo('com.example.ohos.formjsdemo', 'entry').then((data) => {
    console.log('formHost getFormsInfo, data: ${JSON.stringify(data)}');
  }).catch((error) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## getRunningFormInfos<sup>10+</sup>

getRunningFormInfos(callback: AsyncCallback&lt;Array&lt;formInfo.RunningFormInfo&gt;&gt;, hostBundleName?: string): void

获取设备上正在运行的所有非临时卡片信息。使用callback异步回调。

**需要权限**：ohos.permission.REQUIRE_FORM

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
import formHost from '@ohos.app.form.formHost';

try {
  formHost.getRunningFormInfos((error, data) => {
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

## getRunningFormInfos<sup>10+</sup>

getRunningFormInfos(hostBundleName?: string):  Promise&lt;Array&lt;formInfo.RunningFormInfo&gt;&gt;

获取设备上正在运行的所有非临时卡片信息。使用Promise异步回调。

**需要权限**：ohos.permission.REQUIRE_FORM

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
import formHost from '@ohos.app.form.formHost';

try {
  formHost.getRunningFormInfos('com.example.ohos.formjsdemo').then((data) => {
    console.log('formHost getRunningFormInfos, data: ${JSON.stringify(data)}');
  }).catch((error) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## deleteInvalidForms

deleteInvalidForms(formIds: Array&lt;string&gt;, callback: AsyncCallback&lt;number&gt;): void

根据列表删除应用程序的无效卡片。使用callback异步回调。

**需要权限**：ohos.permission.REQUIRE_FORM

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| formIds | Array&lt;string&gt; | 是   | 有效卡片标识列表。 |
| callback | AsyncCallback&lt;number&gt; | 是 | 回调函数。当根据列表删除应用程序的无效卡片成功，error为undefined，data为删除的卡片个数；否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16501000 | An internal functional error occurred. |

以上错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

**示例：**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  let formIds = new Array('12400633174999288', '12400633174999289');
  formHost.deleteInvalidForms(formIds, (error, data) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    } else {
      console.log('formHost deleteInvalidForms, data: ${JSON.stringify(data)}');
    }
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## deleteInvalidForms

deleteInvalidForms(formIds: Array&lt;string&gt;): Promise&lt;number&gt;

根据列表删除应用程序的无效卡片。使用Promise异步回调。

**需要权限**：ohos.permission.REQUIRE_FORM

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| formIds | Array&lt;string&gt; | 是   | 有效卡片标识列表。 |

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise&lt;number&gt; | Promise对象，返回删除的卡片个数。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16501000 | An internal functional error occurred. |

以上错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

**示例：**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  let formIds = new Array('12400633174999288', '12400633174999289');
  formHost.deleteInvalidForms(formIds).then((data) => {
    console.log('formHost deleteInvalidForms, data: ${JSON.stringify(data)}');
  }).catch((error) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## acquireFormState

acquireFormState(want: Want, callback: AsyncCallback&lt;formInfo.FormStateInfo&gt;): void

获取卡片状态。使用callback异步回调。

**需要权限**：ohos.permission.REQUIRE_FORM 和 ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| want | [Want](js-apis-application-want.md) | 是   | 查询卡片状态时携带的want信息。需要包含bundle名、ability名、module名、卡片名、卡片规格等。 |
| callback | AsyncCallback&lt;[formInfo.FormStateInfo](js-apis-app-form-formInfo.md#formstateinfo)&gt; | 是 | 回调函数。当获取卡片状态成功，error为undefined，data为获取到的卡片状态；否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

以上错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

**示例：**

```ts
import formHost from '@ohos.app.form.formHost';

let want = {
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
  formHost.acquireFormState(want, (error, data) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    } else {
      console.log('formHost acquireFormState, data: ${JSON.stringify(data)}');
    }
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## acquireFormState

acquireFormState(want: Want): Promise&lt;formInfo.FormStateInfo&gt;

获取卡片状态。使用Promise异步回调。

**需要权限**：ohos.permission.REQUIRE_FORM 和 ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| want   | [Want](js-apis-application-want.md) | 是   | 查询卡片状态时携带的want信息。需要包含bundle名、ability名、module名、卡片名、卡片规格等。 |

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise&lt;[formInfo.FormStateInfo](js-apis-app-form-formInfo.md#formstateinfo)&gt; | Promise对象，返回卡片状态。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

以上错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

**示例：**

```ts
import formHost from '@ohos.app.form.formHost';

let want = {
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
  formHost.acquireFormState(want).then((data) => {
    console.log('formHost acquireFormState, data: ${JSON.stringify(data)}');
  }).catch((error) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## on('formUninstall')

on(type: 'formUninstall', callback: Callback&lt;string&gt;): void

订阅卡片卸载事件。使用callback异步回调。

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| type | string | 是   | 填写'formUninstall'，表示卡片卸载事件。 |
| callback | Callback&lt;string&gt; | 是 | 回调函数。返回卡片标识。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |

以上错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

**示例：**

```ts
import formHost from '@ohos.app.form.formHost';

let callback = function(formId) {
  console.log('formHost on formUninstall, formId: ${formId}');
}
formHost.on('formUninstall', callback);
```

## off('formUninstall')

off(type: 'formUninstall', callback?: Callback&lt;string&gt;): void

取消订阅卡片卸载事件。使用callback异步回调。

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| type | string | 是   | 填写'formUninstall'，表示卡片卸载事件。 |
| callback | Callback&lt;string&gt; | 否 | 回调函数。返回卡片标识。缺省时，表示注销所有已注册事件回调。<br> 需与对应on('formUninstall')的callback一致。|

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |

以上错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

**示例：**

```ts
import formHost from '@ohos.app.form.formHost';

let callback = function(formId) {
  console.log('formHost on formUninstall, formId: ${formId}');
}
formHost.off('formUninstall', callback);
```

## on('formAdd')<sup>10+</sup>

 on(type: 'formAdd', observerCallback: Callback&lt;formInfo.RunningFormInfo&gt;, bundleName?: string): void

订阅卡片新增事件。使用callback异步回调，返回当前新增卡片的[RunningFormInfo](js-apis-app-form-formInfo.md)。

**需要权限**：ohos.permission.REQUIRE_FORM

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| type | string | 是   | 填写'formAdd'，表示卡片新增事件。 |
| callback | Callback&lt;formInfo.RunningFormInfo&gt; | 是 | 回调函数。返回新增卡片的RunningFormInfo。 |
| bundleName | string | 否 | 指定订阅卡片使用方包的bundleName。缺省则订阅所有卡片使用方的卡片新增事件。 |

**示例：**

```ts
import formHost from '@ohos.app.form.formHost';
let bundleName = 'ohos.samples.FormApplication';
let callback = function(data) {
  console.log('a new form added, data: ${JSON.stringify(data)');
}

formHost.on('formAdd', callback);
formHost.on('formAdd', callback, bundleName);
```

## off('formAdd')<sup>10+</sup>

 off(type: "formAdd", observerCallback?: Callback&lt;formInfo.RunningFormInfo&gt;, bundleName?: string): void

取消订阅卡片新增事件。使用callback异步回调，返回当前新增卡片的[RunningFormInfo](js-apis-app-form-formInfo.md)。

**需要权限**：ohos.permission.REQUIRE_FORM

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| type | string | 是   | 填写'formAdd'，表示卡片新增事件。 |
| callback | Callback&lt;formInfo.RunningFormInfo&gt; | 否 | 回调函数。返回卡片RunningFormInfo。缺省时，表示注销对应已注册事件回调。<br> 需与对应on('formAdd')的callback一致。|
| bundleName | string | 否 | 指定订阅卡片使用方包的bundleName。<br> 填写该参数时，与注册时填写bundleName的on接口对应。<br> 缺省则订阅所有卡片使用方的卡片删除事件，与注册时未填写bundleName的on接口相对应。 |

**示例：**

```ts
import formHost from '@ohos.app.form.formHost';
let bundleName = 'ohos.samples.FormApplication';
let callback = function(data) {
  console.log('a new form added, data: ${JSON.stringify(data)');
}

formHost.off('formAdd', callback);
formHost.off('formAdd', callback, bundleName);
```
> **说明：**
> on('formAdd', callback)与off('formAdd', callback)相对应；
> on('formAdd', callback, bundleName)与off('formAdd', callback, bundleName)相对应；
> 订阅（on）只能由自己对应的取消订阅接口（off）取消。

## on('formRemove')<sup>10+</sup>

 on(type: 'formRemove', observerCallback: Callback&lt;formInfo.RunningFormInfo&gt;, bundleName?: string): void

订阅卡片删除事件。使用callback异步回调，返回当前删除卡片的[RunningFormInfo](js-apis-app-form-formInfo.md)。

**需要权限**：ohos.permission.REQUIRE_FORM

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| type | string | 是   | 填写'formRemove'，表示卡片删除事件。 |
| callback | Callback&lt;formInfo.RunningFormInfo&gt; | 是 | 回调函数。返回删除卡片的RunningFormInfo。 |
| bundleName | string | 否 | 指定订阅卡片使用方包的bundleName。缺省则订阅所有卡片使用方的卡片删除事件。 |

**示例：**

```ts
import formHost from '@ohos.app.form.formHost';
let bundleName = 'ohos.samples.FormApplication';
let callback = function(data) {
  console.log('a new form added, data: ${JSON.stringify(data)');
}

formHost.on('formRemove', callback);
formHost.on('formRemove', callback, bundleName);
```

## off('formRemove')<sup>10+</sup>

off(type: "formRemove", observerCallback?: Callback&lt;formInfo.RunningFormInfo&gt;, bundleName?: string): void

取消订阅卡片删除事件。使用callback异步回调，返回当前删除卡片的[RunningFormInfo](js-apis-app-form-formInfo.md)。

**需要权限**：ohos.permission.REQUIRE_FORM

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| type | string | 是   | 填写'formRemove'，表示卡片删除事件。 |
| callback | Callback&lt;formInfo.RunningFormInfo&gt; | 否 | 回调函数。返回卡片RunningFormInfo。缺省时，表示注销对应已注册事件回调。<br> 需与对应on('formRemove')的callback一致。|
| bundleName | string | 否 | 指定订阅卡片使用方包的bundleName。<br> 填写该参数时，与注册时填写bundleName的on接口对应。<br> 缺省则订阅所有卡片使用方的卡片删除事件，与注册时未填写bundleName的on接口相对应。 |

**示例：**

```ts
import formHost from '@ohos.app.form.formHost';
let bundleName = 'ohos.samples.FormApplication';
let callback = function(data) {
  console.log('a new form added, data: ${JSON.stringify(data)');
}

formHost.off('formRemove', callback);
formHost.off('formRemove', callback, bundleName);
```
> **说明：**
> on('formRemove', callback)与off('formRemove', callback)相对应；
> on('formRemove', callback, bundleName)与off('formRemove', callback, bundleName)相对应；
> 订阅（on）只能由自己对应的取消订阅接口（off）取消。

## notifyFormsVisible

notifyFormsVisible(formIds: Array&lt;string&gt;, isVisible: boolean, callback: AsyncCallback&lt;void&gt;): void

通知卡片是否可见。使用callback异步回调。

**需要权限**：ohos.permission.REQUIRE_FORM

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| formIds | Array&lt;string&gt; | 是   | 卡片标识列表。 |
| isVisible | boolean | 是   | 是否可见。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当通知卡片是否可见成功，error为undefined，否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16501000 | An internal functional error occurred. |
| 16501003 | The form can not be operated by the current application. |

以上错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

**示例：**

```ts
import formHost from '@ohos.app.form.formHost';

let formIds = new Array('12400633174999288', '12400633174999289');
try {
  formHost.notifyFormsVisible(formIds, true, (error) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    }
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## notifyFormsVisible

notifyFormsVisible(formIds: Array&lt;string&gt;, isVisible: boolean): Promise&lt;void&gt;

通知卡片是否可见。使用Promise异步回调。

**需要权限**：ohos.permission.REQUIRE_FORM

**系统能力**：SystemCapability.Ability.Form

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

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16501000 | An internal functional error occurred. |
| 16501003 | The form can not be operated by the current application. |

以上错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

**示例：**

```ts
import formHost from '@ohos.app.form.formHost';

let formIds = new Array('12400633174999288', '12400633174999289');
try {
  formHost.notifyFormsVisible(formIds, true).then(() => {
    console.log('formHost notifyFormsVisible success');
  }).catch((error) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## notifyFormsEnableUpdate

notifyFormsEnableUpdate(formIds: Array&lt;string&gt;, isEnableUpdate: boolean, callback: AsyncCallback&lt;void&gt;): void

通知卡片是否启用更新状态。使用callback异步回调。

**需要权限**：ohos.permission.REQUIRE_FORM

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| formIds | Array&lt;string&gt; | 是   | 卡片标识列表。 |
| isEnableUpdate | boolean | 是   | 是否使能更新。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当通知卡片是否启用更新状态成功，error为undefined，否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16501000 | An internal functional error occurred. |
| 16501003 | The form can not be operated by the current application. |

以上错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

**示例：**

```ts
import formHost from '@ohos.app.form.formHost';

let formIds = new Array('12400633174999288', '12400633174999289');
try {
  formHost.notifyFormsEnableUpdate(formIds, true, (error) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    }
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## notifyFormsEnableUpdate

notifyFormsEnableUpdate(formIds: Array&lt;string&gt;, isEnableUpdate: boolean): Promise&lt;void&gt;

通知卡片是否启用更新状态。使用Promise异步回调。

**需要权限**：ohos.permission.REQUIRE_FORM

**系统能力**：SystemCapability.Ability.Form

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

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16501000 | An internal functional error occurred. |
| 16501003 | The form can not be operated by the current application. |

以上错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

**示例：**

```ts
import formHost from '@ohos.app.form.formHost';

let formIds = new Array('12400633174999288', '12400633174999289');
try {
  formHost.notifyFormsEnableUpdate(formIds, true).then(() => {
    console.log('formHost notifyFormsEnableUpdate success');
  }).catch((error) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```
## shareForm

shareForm(formId: string, deviceId: string, callback: AsyncCallback&lt;void&gt;): void

指定formId和远程设备Id进行卡片分享。使用callback异步回调。

**需要权限**：ohos.permission.REQUIRE_FORM 和 ohos.permission.DISTRIBUTED_DATASYNC

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| formId | string | 是   | 卡片标识。 |
| deviceId | string | 是   | 远程设备标识。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当指定formId和远程设备Id进行卡片分享成功，error为undefined，否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form can not be operated by the current application. |

以上错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

**示例：**

```ts
import formHost from '@ohos.app.form.formHost';

let formId = '12400633174999288';
let deviceId = 'EFC11C0C53628D8CC2F8CB5052477E130D075917034613B9884C55CD22B3DEF2';
try {
  formHost.shareForm(formId, deviceId, (error) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    }
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## shareForm

shareForm(formId: string, deviceId: string): Promise&lt;void&gt;

指定formId和远程设备Id进行卡片分享。使用Promise异步回调。

**需要权限**：ohos.permission.REQUIRE_FORM 和 ohos.permission.DISTRIBUTED_DATASYNC

**系统能力**：SystemCapability.Ability.Form

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

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form can not be operated by the current application. |

以上错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

**示例：**

```ts
import formHost from '@ohos.app.form.formHost';

let formId = '12400633174999288';
let deviceId = 'EFC11C0C53628D8CC2F8CB5052477E130D075917034613B9884C55CD22B3DEF2';
try {
  formHost.shareForm(formId, deviceId).then(() => {
    console.log('formHost shareForm success');
  }).catch((error) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## notifyFormsPrivacyProtected

notifyFormsPrivacyProtected(formIds: Array\<string>, isProtected: boolean, callback: AsyncCallback\<void>): void

通知指定卡片隐私保护状态改变。使用callback异步回调。

**需要权限**：ohos.permission.REQUIRE_FORM

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| formIds | Array\<string\> | 是   | 需要修改隐私保护的卡片标识列表。 |
| isProtected | boolean | 是   | 是否进行隐私保护。 |
| callback | AsyncCallback\<void> | 是 | 回调函数。当指定卡片设置隐私保护属性成功，error为undefined，否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16501000 | An internal functional error occurred. |

以上错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

**示例：**

```ts
import formHost from '@ohos.app.form.formHost';

let formIds = new Array('12400633174999288', '12400633174999289');
try {
  formHost.notifyFormsPrivacyProtected(formIds, true, (error) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    }
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## notifyFormsPrivacyProtected

notifyFormsPrivacyProtected(formIds: Array\<string\>, isProtected: boolean): Promise\<void\>;

通知指定卡片隐私保护状态改变。使用Promise异步回调。

**需要权限**：ohos.permission.REQUIRE_FORM

**系统能力**：SystemCapability.Ability.Form

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

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16501000 | An internal functional error occurred. |

以上错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

```ts
import formHost from '@ohos.app.form.formHost';

let formIds = new Array('12400633174999288', '12400633174999289');
try {
  formHost.notifyFormsPrivacyProtected(formIds, true).then(() => {
    console.log('formHost notifyFormsPrivacyProtected success');
  }).catch((error) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## acquireFormData<sup>10+</sup>

acquireFormData(formId: string, callback: AsyncCallback<{[key: string]: Object}>): void;

请求卡片提供方数据。使用callback异步回调。

**需要权限**：ohos.permission.REQUIRE_FORM

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| formId | string | 是   | 卡片标识。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

以上错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

**示例：**

```ts
import formHost from '@ohos.app.form.formHost';

let formId = '12400633174999288';
try {
  formHost.acquireFormData(formId, (error, data) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    } else {
      console.log('formHost acquireFormData, data: ${JSON.stringify(data)}');
    }
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## acquireFormData<sup>10+</sup>

acquireFormData(formId: string): Promise<{[key: string]: Object}>;

请求卡片提供方数据。使用Promise异步回调。

**需要权限**：ohos.permission.REQUIRE_FORM

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名      | 类型            | 必填 | 说明                             |
| ----------- | --------------- | ---- | -------------------------------- |
| formId | string | 是   | 卡片标识。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise<{[key: string]: Object}>| 以Promise方式返回接口运行结果及分享数据。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permissions denied. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

以上错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

```ts
import formHost from '@ohos.app.form.formHost';

let formId = '12400633174999288';
try {
  formHost.acquireFormData(formId).then((data) => {
    console.log('formHost acquireFormData success' + data);
  }).catch((error) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## getRunningFormInfosByFilter<sup>10+</sup>

getRunningFormInfosByFilter(formProviderFilter: formInfo.FormProviderFilter): Promise&lt;Array&lt;formInfo.RunningFormInfo&gt;&gt;

根据提供方信息查询卡片已有的使用方列表信息。使用Promise异步回调。

**需要权限**：ohos.permission.REQUIRE_FORM

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
import formHost from '@ohos.app.form.formHost';

let formInstanceFilter = {
  bundleName: "com.example.formprovide",
  abilityName: "EntryFormAbility",
  formName: "widget",
  moduleName: "entry"
}
try {
  formHost.getRunningFormInfosByFilter(formInstanceFilter).then(data1 => {
    console.info('formHost getRunningFormInfosByFilter return err :');
  }).catch((error) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## getRunningFormInfosByFilter<sup>10+</sup>

getRunningFormInfosByFilter(formProviderFilter: formInfo.FormProviderFilter, callback: AsyncCallback&lt;Array&lt;formInfo.RunningFormInfo&gt;&gt;): void

根据提供方信息查询卡片已有的使用方列表信息。使用callback异步回调。

**需要权限**：ohos.permission.REQUIRE_FORM

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


```ts
import formHost from '@ohos.app.form.formHost';

let formInstanceFilter = {
  bundleName: "com.example.formprovide",
  abilityName: "EntryFormAbility",
  formName: "widget",
  moduleName: "entry"
}
try {
  formHost.getRunningFormInfosByFilter(formInstanceFilter,(error, data) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    } else {
      console.log('formHost getRunningFormInfosByFilter, data: ${JSON.stringify(data)}');
    }
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## getRunningFormInfoById<sup>10+</sup>

getRunningFormInfoById(formId: string): Promise&lt;formInfo.RunningFormInfo&gt;


根据formId查询卡片已有的使用方列表信息。使用Promise异步回调。

**需要权限**：ohos.permission.REQUIRE_FORM

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


```ts
import formHost from '@ohos.app.form.formHost';
let formId = '12400633174999288';
try {
  formHost.getRunningFormInfoById(formId).then(data1 => {
    console.info('formHost getRunningFormInfoById return err :');
  }).catch((error) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## getRunningFormInfoById<sup>10+</sup>

getRunningFormInfoById(formId: string, callback: AsyncCallback&lt;formInfo.RunningFormInfo&gt;): void

根据提供方信息查询卡片已有的使用方列表信息。使用callback异步回调。

**需要权限**：ohos.permission.REQUIRE_FORM

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

```ts
import formHost from '@ohos.app.form.formHost';

let formId = '12400633174999288';
try {
  formHost.getRunningFormInfoById(formId,(error, data) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    } else {
      console.log('formHost getRunningFormInfoById, data: ${JSON.stringify(data)}');
    }
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## on('notifyVisible')<sup>10+</sup>

 on(type: 'notifyVisible', observerCallback: Callback&lt;Array&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo.md)&gt;&gt;, bundleName?: string): void

订阅通知卡片可见的事件。

​触发通知卡片可见场景为：调用notifyVisibleForms接口通知对应卡片可见性变更为可见状态

**需要权限**：ohos.permission.REQUIRE_FORM

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                                                         |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type       | string                                                       | 是   | 仅允许填写'notifyVisible'，表示订阅通知卡片可见的事件。      |
| callback   | Callback &lt;Array&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo.md)&gt;&gt; | 是   | 回调函数。返回订阅通知卡片可见的RunningFormInfo。            |
| bundleName | string                                                       | 否   | 指定卡片使用方的bundleName，用于订阅卡片在该使用方的可见状态变更事件。 |

**示例：**

```ts
import formHost from '@ohos.app.form.formHost';
let bundleName = 'ohos.samples.FormApplication';
let callback = function(data) {
  console.log('form change visibility, data: ${JSON.stringify(data)');
}

formHost.on('notifyVisible', callback);
formHost.on('notifyVisible', callback, bundleName);
```

## off('notifyVisible')<sup>10+</sup>

 off(type: "notifyVisible", observerCallback?: Callback&lt;Array&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo.md)&gt;&gt;, bundleName?: string): void

取消订阅通知卡片可见的事件。

**需要权限**：ohos.permission.REQUIRE_FORM

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                                                         |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type       | string                                                       | 是   | 仅允许填写'notifyVisible'，表示取消订阅通知卡片为可见的事件。 |
| callback   | Callback &lt;Array&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo.md)&gt;&gt; | 否   | 入参，注册时注册进去的callback。缺省时，表示注销对应已注册订阅的回调。<br> 需与对应on('notifyVisible')的callback一致。 |
| bundleName | string                                                       | 否   | 指定卡片使用方的bundleName，用于订阅卡片在该使用方的可见状态变更事件。<br> 填写该参数时，与注册时填写bundleName的on接口对应。 |

**示例：**

```ts
import formHost from '@ohos.app.form.formHost';
let bundleName = 'ohos.samples.FormApplication';
let callback = function(data) {
  console.log('form change visibility, data: ${JSON.stringify(data)');
}

formHost.off('notifyVisible', callback);
formHost.off('notifyVisible', callback, bundleName);
```

> **说明：**
> on('notifyVisible', callback)与off('notifyVisible', callback)相对应；
> on('notifyVisible', callback, bundleName)与off('notifyVisible', callback, bundleName)相对应；
> 订阅（on）只能由自己对应的取消订阅接口（off）取消。



## on('notifyInvisible')<sup>10+</sup>

 on(type: 'notifyInvisible', observerCallback: Callback&lt;Array&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo.md)&gt;>, bundleName?: string): void

订阅通知卡片不可见的事件。

​触发通知卡片不可见场景为：调用notifyInvisibleForms接口通知对应卡片可见性变更为不可见状态

**需要权限**：ohos.permission.REQUIRE_FORM

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                                                         |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type       | string                                                       | 是   | 仅允许填写'notifyInvisible'，表示订阅卡片不可见的事件。      |
| callback   | Callback &lt;Array&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo.md)&gt;&gt; | 是   | 回调函数。返回订阅通知卡片不可见的RunningFormInfo。          |
| bundleName | string                                                       | 否   | 指定卡片使用方的bundleName，用于订阅卡片在该使用方的可见状态变更事件。 |

**示例：**

```ts
import formHost from '@ohos.app.form.formHost';
let bundleName = 'ohos.samples.FormApplication';
let callback = function(data) {
  console.log('form change invisibility, data: ${JSON.stringify(data)');
}

formHost.on('notifyInvisible', callback);
formHost.on('notifyInvisible', callback, bundleName);
```

## off('notifyInvisible')<sup>10+</sup>

 off(type: "notifyInvisible", observerCallback?: Callback&lt;Array&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo.md)>&gt;, bundleName?: string): void

取消订阅通知卡片不可见事件。

**需要权限**：ohos.permission.REQUIRE_FORM

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                                                         |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type       | string                                                       | 是   | 仅允许填写'notifyInvisible'，表示卡片可见性变更为不可见。    |
| callback   | Callback &lt;Array&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo.md)&gt;&gt; | 否   | 入参，注册时注册进去的callback。缺省时，表示注销对应已注册事件回调。<br/> 需与对应on('notifyInvisible')的callback一致。 |
| bundleName | string                                                       | 否   | 指定卡片使用方的bundleName，用于订阅卡片在该使用方的可见状态变更事件。<br> 填写该参数时，与注册时填写bundleName的on接口对应。<br>  |

**示例：**

```ts
import formHost from '@ohos.app.form.formHost';
let bundleName = 'ohos.samples.FormApplication';
let callback = function(data) {
  console.log('form change invisibility, data: ${JSON.stringify(data)');
}

formHost.off('notifyInvisible', callback);
formHost.off('notifyInvisible', callback, bundleName);
```

> **说明：**
> on('notifyInvisible', callback)与off('notifyInvisible', callback)相对应；
> on('notifyInvisible', callback, bundleName)与off('notifyInvisible', callback, bundleName)相对应；
> 订阅（on）只能由自己对应的取消订阅接口（off）取消。