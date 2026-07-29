# @ohos.app.form.formAgent (FormAgent)(系统接口)
<!--Kit: Form Kit-->
<!--Subsystem: Ability-->
<!--Owner: @Qian-Win-->
<!--Designer: @cx983299475-->
<!--Tester: @mahailong123456-->
<!--Adviser: @HelloShuo-->

FormAgent模块提供了卡片代理相关接口的能力，目前仅包括请求发布卡片。适用于系统应用需要将卡片发布到使用方（如桌面）的场景，能够帮助系统应用便捷地请求发布卡片，简化卡片发布流程。

> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口为系统接口。

## 导入模块

```ts
import { formAgent } from '@kit.FormKit';
```

## requestPublishForm

requestPublishForm(want: Want, callback: AsyncCallback&lt;string&gt;): void

请求发布一张卡片到使用方，使用callback异步回调。使用方通常为桌面。适用于系统应用需要主动将卡片添加到桌面的场景。

**需要权限：** ohos.permission.AGENT_REQUIRE_FORM

**系统能力：** SystemCapability.Ability.Form

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名   | 类型                                | 必填 | 说明                                                         |
| -------- | ----------------------------------- | ---- | ------------------------------------------------------------ |
| want     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 发布请求，需包含以下字段。<br>bundleName: 目标卡片所属应用的bundleName<br>abilityName: 目标卡片所属应用的Ability<br>parameters:<br>- ohos.extra.param.key.form_dimension: 目标卡片规格，取值原则：1-2x2、2-2x4、3-4x4等，具体规格见卡片配置<br>- ohos.extra.param.key.form_name: 目标卡片名<br>- ohos.extra.param.key.module_name: 目标卡片moduleName|
| callback | AsyncCallback&lt;string&gt | 是 | 回调函数，用于异步返回卡片标识。回调参数：error为错误对象（成功时为null），data为卡片标识（string类型）。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |
| 16501008 | Waiting for the form addition to the desktop timed out. <br/>适用版本：12+ |

**示例：**

```ts
import { formAgent } from '@kit.FormKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let want: Want = {
  bundleName: 'com.ohos.exampledemo',
  abilityName: 'FormAbility',
  parameters: {
    'ohos.extra.param.key.form_dimension': 2,
    'ohos.extra.param.key.form_name': 'widget',
    'ohos.extra.param.key.module_name': 'entry'
  }
};
try {
  formAgent.requestPublishForm(want, (error: BusinessError, data: string) => {
    if (error) {
      console.error(`callback error, code: ${error.code}, message: ${error.message}`);
      return;
    }
    console.info(`formAgent requestPublishForm, form ID is: ${data}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## requestPublishForm

requestPublishForm(want: Want): Promise&lt;string&gt;

请求发布一张卡片到使用方，使用Promise异步回调。使用方通常为桌面。适用于系统应用需要主动将卡片添加到桌面的场景。

**需要权限：** ohos.permission.AGENT_REQUIRE_FORM

**系统能力：** SystemCapability.Ability.Form

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名          | 类型                                                         | 必填 | 说明                                                         |
| --------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| want     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 发布请求，需包含以下字段。<br>bundleName: 目标卡片所属应用的bundleName<br>abilityName: 目标卡片所属应用的Ability<br>parameters:<br>- ohos.extra.param.key.form_dimension: 目标卡片规格<br>- ohos.extra.param.key.form_name: 目标卡片名<br>- ohos.extra.param.key.module_name: 目标卡片moduleName |

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise&lt;string&gt; | Promise对象。返回卡片标识。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |
| 16501008 | Waiting for the form addition to the desktop timed out. <br/>适用版本：12+ |

**示例：**

```ts
import { formAgent } from '@kit.FormKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let want: Want = {
  bundleName: 'com.ohos.exampledemo',
  abilityName: 'FormAbility',
  parameters: {
    'ohos.extra.param.key.form_dimension': 2,
    'ohos.extra.param.key.form_name': 'widget',
    'ohos.extra.param.key.module_name': 'entry'
  }
};
try {
  formAgent.requestPublishForm(want).then((data: string) => {
    console.info(`formAgent requestPublishForm success, form ID is : ${data}`);
  }).catch((error: BusinessError) => {
    console.error(`promise error, code: ${error.code}, message: ${error.message}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## updateFormCrossBundle

updateFormCrossBundle(formId: string, formBindingData: formBindingData.FormBindingData): Promise&lt;void&gt;

跨应用更新卡片，使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限**：ohos.permission.UPDATE_FORM_CROSS_BUNDLE

**系统能力：** SystemCapability.Ability.Form

**系统接口：** 此接口为系统接口。

**起始版本：** 26.0.0

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ------ | ---- | -------|
| formId | string | 是 | 待更新的卡片标识。|
| formBindingData | [formBindingData.FormBindingData](js-apis-app-form-formBindingData.md#formbindingdata) | 是 | 用于更新的卡片数据。|

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
| 16500050 | Possible cause IPC connection error. Such as the remote object does not exist. |
| 16500060 | Possible cause Service State error. Such as the form is recovering. |
| 16501000 | Possible cause internal functional error. Such as virtualization failed. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form to be operated has been deleted already. |
| 16501007 | The form to be operated is not trusted. |

**示例：**

```ts
import { formBindingData, formAgent } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

let formId: string = '123456789'; // 卡片的formId，请替换为实际的formId。
try {
  let param: Record<string, string> = {
    'temperature': '22c',
    'time': '22:00'
  };
  let obj: formBindingData.FormBindingData = formBindingData.createFormBindingData(param);
  formAgent.updateFormCrossBundle(formId, obj).then(() => {
    console.info('formAgent updateFormCrossBundle success');
  }).catch((error: BusinessError) => {
    console.error(`promise error, code: ${error?.code}, message: ${error?.message}`);
  });
} catch (error) {
  console.error(`catch error, code: ${error?.code}, message: ${error?.message}`);
}
```