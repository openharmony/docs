# @ohos.app.form.formProvider (formProvider) (System API)

The **formProvider** module provides APIs to obtain widget information, update widgets, set the update time, and request a widget release.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.app.form.formProvider (formProvider)](./js-apis-app-form-formProvider.md).

## Modules to Import

```ts
import { formProvider } from '@kit.FormKit';
```


## requestPublishForm

requestPublishForm(want: Want, formBindingData: formBindingData.FormBindingData, callback: AsyncCallback\<string>): void

Requests to publish a widget carrying data to the widget host (usually the home screen). This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.Form

**System API**: This is a system API.

**Parameters**

| Name| Type                                                                   | Mandatory| Description            |
| ------ | ---------------------------------------------------------------------- | ---- | ---------------- |
| want | [Want](../apis-ability-kit/js-apis-app-ability-want.md)                           | Yes  | Publish request, which must contain the following fields:<br>Information about the target widget.<br>**abilityName**: ability of the target widget.<br>**parameters**:<br>'ohos.extra.param.key.form_dimension'<br>'ohos.extra.param.key.form_name'<br>'ohos.extra.param.key.module_name' |
| formBindingData | [formBindingData.FormBindingData](js-apis-app-form-formBindingData.md#formbindingdata) | Yes  | Data used for creating the widget.|
| callback | AsyncCallback&lt;string&gt; | Yes| Callback used to return the widget ID.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Form Error Codes](errorcode-form.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

**Example**

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

Requests to publish a widget to the widget host (usually the home screen). This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.Form

**System API**: This is a system API.

**Parameters**

| Name  | Type                               | Mandatory| Description                                                        |
| -------- | ----------------------------------- | ---- | ------------------------------------------------------------ |
| want     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Publish request, which must contain the following fields:<br>Information about the target widget.<br>**abilityName**: ability of the target widget.<br>**parameters**:<br>'ohos.extra.param.key.form_dimension'<br>'ohos.extra.param.key.form_name'<br>'ohos.extra.param.key.module_name' |
| callback | AsyncCallback&lt;string&gt;         | Yes  |  Callback used to return the widget ID.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Form Error Codes](errorcode-form.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

**Example**

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

Requests to publish a widget to the widget host (usually the home screen). This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.Form

**System API**: This is a system API.

**Parameters**

| Name         | Type                                                        | Mandatory| Description                                                        |
| --------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| want            | [Want](../apis-ability-kit/js-apis-app-ability-want.md)                          | Yes  | Publish request, which must contain the following fields:<br>Information about the target widget.<br>**abilityName**: ability of the target widget.<br>**parameters**:<br>'ohos.extra.param.key.form_dimension'<br>'ohos.extra.param.key.form_name'<br>'ohos.extra.param.key.module_name' |
| formBindingData | [formBindingData.FormBindingData](js-apis-app-form-formBindingData.md#formbindingdata) | No  | Data used for creating the widget. By default, no value is passed, indicating that no data is provided.                                     |

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;string&gt; | Promise used to return the widget ID.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Form Error Codes](errorcode-form.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

**Example**

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

Checks whether a widget can be published to the widget host. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback function that returns the query result.<br>**true**: The widget can be added to the widget host.<br>**false**: The widget cannot be added to the widget host.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Form Error Codes](errorcode-form.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16501000 | An internal functional error occurred. |

**Example**

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

Checks whether a widget can be published to the widget host. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.Form

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;boolean&gt; | Promise that returns whether a widget can be added to the widget host.<br>**true**: The widget can be added to the widget host.<br>**false**: The widget cannot be added to the widget host.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Form Error Codes](errorcode-form.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 202 | The application is not a system application. |
| 16500050 | IPC connection error. |
| 16501000 | An internal functional error occurred. |

**Example**

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

## activateSceneAnimation<sup>20+</sup>

activateSceneAnimation(formId: string): Promise&lt;void&gt;

Requests to activate a widget. This API takes effect only for [scene-based widgets](../../form/arkts-ui-widget-configuration.md#sceneanimationparams-field). This API uses a promise to return the result. An interactive widget can be in the active or inactive state. In the inactive state, the widget is the same as a common widget. In the active state, the widget can start the **LiveFormExtensionAbility** process developed by the widget host to implement animations.

**System capability**: SystemCapability.Ability.Form

**System API**: This is a system API.

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- |-------|
| formId | string | Yes| Widget ID.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Form Error Codes](errorcode-form.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 202 | The application is not a system application. |
| 801 | Capability not supported.function activateSceneAnimation can not work correctly due to limited device capabilities. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form cannot be operated by the current application. |
| 16501011 | The form can not support this operation. |

**Example**

```ts
import { formProvider } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

let formId: string = '12400633174999288';

try {
  formProvider.activateSceneAnimation(formId).then(() => {
    console.info('activateSceneAnimation succeed.');
  }).catch((error: BusinessError) => {
    console.error(`promise error, code: ${error.code}, message: ${error.message})`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message})`);
}
```

## deactivateSceneAnimation<sup>20+</sup>

deactivateSceneAnimation(formId: string): Promise&lt;void&gt;

Requests to deactivate a widget. This API takes effect only for [scene-based widgets](../../form/arkts-ui-widget-configuration.md#sceneanimationparams-field). This API uses a promise to return the result. An interactive widget can be in the active or inactive state. In the inactive state, the widget is the same as a common widget. In the active state, the widget can start the **LiveFormExtensionAbility** process developed by the widget host to implement animations.

**System capability**: SystemCapability.Ability.Form

**System API**: This is a system API.

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- |-------|
| formId | string | Yes| Widget ID.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Form Error Codes](errorcode-form.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 202 | The application is not a system application. |
| 801 | Capability not supported.function deactivateSceneAnimation can not work correctly due to limited device capabilities. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form cannot be operated by the current application. |
| 16501011 | The form can not support this operation. |

**Example**

```ts
import { formProvider } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

let formId: string = '12400633174999288';

try {
  formProvider.deactivateSceneAnimation(formId).then(() => {
    console.info('deactivateSceneAnimation succeed.');
  }).catch((error: BusinessError) => {
    console.error(`promise error, code: ${error.code}, message: ${error.message})`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message})`);
}
```
