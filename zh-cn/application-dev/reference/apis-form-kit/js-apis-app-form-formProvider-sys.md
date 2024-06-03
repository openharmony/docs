# @ohos.app.form.formProvider (formProvider)(系统接口)

FormProvider模块提供了卡片提供方相关接口的能力，开发者在开发卡片时，可通过该模块提供接口实现更新卡片、设置卡片更新时间、获取卡片信息、请求发布卡片等。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 当前页面仅包含本模块的系统接口，其他公共接口参见[@ohos.app.form.formProvider (formProvider)](./js-apis-app-form-formProvider.md)。

## 导入模块

```ts
import { formProvider } from '@kit.FormKit';
```


## requestPublishForm

requestPublishForm(want: Want, formBindingData: formBindingData.FormBindingData, callback: AsyncCallback\<string>): void

请求发布一张卡片到使用方。使用方通常为桌面，使用callback异步回调。

**系统能力：** SystemCapability.Ability.Form

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名 | 类型                                                                    | 必填 | 说明             |
| ------ | ---------------------------------------------------------------------- | ---- | ---------------- |
| want | [Want](../apis-ability-kit/js-apis-app-ability-want.md)                           | 是   | 发布请求，需包含以下字段。<br>abilityName: 目标卡片ability<br>parameters:<br>'ohos.extra.param.key.form_dimension'<br>'ohos.extra.param.key.form_name'<br>'ohos.extra.param.key.module_name' |
| formBindingData | [formBindingData.FormBindingData](js-apis-app-form-formBindingData.md#formbindingdata) | 是   | 创建卡片的数据。 |
| callback | AsyncCallback&lt;string&gt; | 是 | 回调函数，返回卡片标识。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

以上错误码的详细介绍请参见[卡片错误码](errorcode-form.md)。

**示例：**

```ts
import { formBindingData, formProvider } from '@kit.FormKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let want: Want = {
  abilityName: 'FormAbility',
  parameters: {
    'ohos.extra.param.key.form_dimension': 2,
    'ohos.extra.param.key.form_name': 'widget',
    'ohos.extra.param.key.module_name': 'entry'
  }
};
try {
  let param: Record<string, string> = {
    'temperature': '22c',
    'time': '22:00'
  }
  let obj: formBindingData.FormBindingData = formBindingData.createFormBindingData(param);
  formProvider.requestPublishForm(want, obj, (error: BusinessError, data: string) => {
    if (error) {
      console.error(`callback error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message})`);
      return;
    }
    console.log(`formProvider requestPublishForm, form ID is: ${JSON.stringify(data)}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message})`);
}
```

## requestPublishForm

requestPublishForm(want: Want, callback: AsyncCallback&lt;string&gt;): void

请求发布一张卡片到使用方。使用方通常为桌面，使用callback异步回调。

**系统能力：** SystemCapability.Ability.Form

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名   | 类型                                | 必填 | 说明                                                         |
| -------- | ----------------------------------- | ---- | ------------------------------------------------------------ |
| want     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 发布请求，需包含以下字段。<br>abilityName: 目标卡片ability<br>parameters:<br>'ohos.extra.param.key.form_dimension'<br>'ohos.extra.param.key.form_name'<br>'ohos.extra.param.key.module_name' |
| callback | AsyncCallback&lt;string&gt;         | 是   |  回调函数，返回卡片标识。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

以上错误码的详细介绍请参见[卡片错误码](errorcode-form.md)。

**示例：**

```ts
import { formProvider } from '@kit.FormKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let want: Want = {
  abilityName: 'FormAbility',
  parameters: {
    'ohos.extra.param.key.form_dimension': 2,
    'ohos.extra.param.key.form_name': 'widget',
    'ohos.extra.param.key.module_name': 'entry'
  }
};
try {
  formProvider.requestPublishForm(want, (error: BusinessError, data: string) => {
    if (error) {
      console.error(`callback error, code: ${error.code}, message: ${error.message})`);
      return;
    }
    console.log(`formProvider requestPublishForm, form ID is: ${JSON.stringify(data)}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message})`);
}
```

## requestPublishForm

requestPublishForm(want: Want, formBindingData?: formBindingData.FormBindingData): Promise&lt;string&gt;

请求发布一张卡片到使用方。使用方通常为桌面，使用Promise异步回调。

**系统能力：** SystemCapability.Ability.Form

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名          | 类型                                                         | 必填 | 说明                                                         |
| --------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| want            | [Want](../apis-ability-kit/js-apis-app-ability-want.md)                          | 是   | 发布请求，需包含以下字段。<br>abilityName: 目标卡片ability<br>parameters:<br>'ohos.extra.param.key.form_dimension'<br>'ohos.extra.param.key.form_name'<br>'ohos.extra.param.key.module_name' |
| formBindingData | [formBindingData.FormBindingData](js-apis-app-form-formBindingData.md#formbindingdata) | 否   | 创建卡片的数据，默认为空，不提供创建卡片数据。                                      |

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise&lt;string&gt; | Promise对象。返回卡片标识。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

以上错误码的详细介绍请参见[卡片错误码](errorcode-form.md)。

**示例：**

```ts
import { formProvider } from '@kit.FormKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let want: Want = {
  abilityName: 'FormAbility',
  parameters: {
    'ohos.extra.param.key.form_dimension': 2,
    'ohos.extra.param.key.form_name': 'widget',
    'ohos.extra.param.key.module_name': 'entry'
  }
};
try {
  formProvider.requestPublishForm(want).then((data: string) => {
    console.log(`formProvider requestPublishForm success, form ID is : ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
    console.error(`promise error, code: ${error.code}, message: ${error.message})`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message})`);
}
```

## isRequestPublishFormSupported

isRequestPublishFormSupported(callback: AsyncCallback&lt;boolean&gt;): void

查询是否支持发布一张卡片到使用方，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。返回是否支持发布一张卡片到使用方。|

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16501000 | An internal functional error occurred. |

以上错误码的详细介绍请参见[卡片错误码](errorcode-form.md)。

**示例：**

```ts
import { formProvider } from '@kit.FormKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  formProvider.isRequestPublishFormSupported((error: BusinessError, isSupported: boolean) => {
    if (error) {
      console.error(`callback error, code: ${error.code}, message: ${error.message})`);
    } else {
      if (isSupported) {
        let want: Want = {
          abilityName: 'FormAbility',
          parameters: {
            'ohos.extra.param.key.form_dimension': 2,
            'ohos.extra.param.key.form_name': 'widget',
            'ohos.extra.param.key.module_name': 'entry'
          }
        };
        try {
          formProvider.requestPublishForm(want, (error: BusinessError, data: string) => {
            if (error) {
              console.error(`callback error, code: ${error.code}, message: ${error.message})`);
              return;
            }
            console.log(`formProvider requestPublishForm, form ID is: ${JSON.stringify(data)}`);
          });
        } catch (error) {
          console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message})`);
        }
      }
    }
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message})`);
}
```

## isRequestPublishFormSupported

isRequestPublishFormSupported(): Promise&lt;boolean&gt;

查询是否支持发布一张卡片到使用方，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Ability.Form

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise&lt;boolean&gt; | Promise对象。返回是否支持发布一张卡片到使用方。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 202 | The application is not a system application. |
| 16500050 | IPC connection error. |
| 16501000 | An internal functional error occurred. |

以上错误码的详细介绍请参见[卡片错误码](errorcode-form.md)。

**示例：**

```ts
import { formProvider } from '@kit.FormKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  formProvider.isRequestPublishFormSupported().then((isSupported: boolean) => {
    if (isSupported) {
      let want: Want = {
        abilityName: 'FormAbility',
        parameters: {
          'ohos.extra.param.key.form_dimension': 2,
          'ohos.extra.param.key.form_name': 'widget',
          'ohos.extra.param.key.module_name': 'entry'
        }
      };
      try {
        formProvider.requestPublishForm(want).then((data: string) => {
          console.log(`formProvider requestPublishForm success, form ID is : ${JSON.stringify(data)}`);
        }).catch((error: BusinessError) => {
          console.error(`promise error, code: ${error.code}, message: ${error.message})`);
        });
      } catch (error) {
        console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message})`);
      }
    }
  }).catch((error: BusinessError) => {
    console.error(`promise error, code: ${error.code}, message: ${error.message})`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message})`);
}
```