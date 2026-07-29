# @ohos.app.form.formProvider (formProvider)
<!--Kit: Form Kit-->
<!--Subsystem: Ability-->
<!--Owner: @Qian-Win-->
<!--Designer: @cx983299475-->
<!--Tester: @mahailong123456-->
<!--Adviser: @HelloShuo-->

formProvider模块提供了获取卡片信息、更新卡片、设置卡片刷新时间等能力。该模块作为卡片提供方与卡片管理服务的桥梁，通过IPC机制与FormExtension进行通信，实现卡片的更新、信息获取等操作。适用于卡片提供方需要主动更新卡片内容、管理卡片生命周期、获取卡片运行状态等场景，帮助开发者实现卡片的动态更新和状态管理。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { formProvider } from '@kit.FormKit';
```

## formProvider.setFormNextRefreshTime

setFormNextRefreshTime(formId: string, minute: number, callback: AsyncCallback&lt;void&gt;): void

设置指定卡片的下一次刷新时间，使用callback异步回调。适用于需要精确控制卡片刷新时机的场景，例如定时任务等。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明                                   |
| ------ | ------ | ---- | ------------------------------------- |
| formId | string | 是   | 卡片标识。                               |
| minute | number | 是   | 指定卡片多久之后刷新，取值范围：大于等于5，单位：min。  |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。设置结果的回调，成功时error为undefined。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501002 | The number of forms exceeds the maximum allowed. |
| 16501003 | The form cannot be operated by the current application. |

**示例：**

```ts
import { formProvider } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

let formId: string = '12400633174999288'; // 表示卡片formId，根据实际formId调整
try {
  formProvider.setFormNextRefreshTime(formId, 5, (error: BusinessError) => {
    if (error) {
      console.error(`callback error, code: ${error.code}, message: ${error.message}`);
      return;
    }
    console.info(`formProvider setFormNextRefreshTime success`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## formProvider.setFormNextRefreshTime

setFormNextRefreshTime(formId: string, minute: number): Promise&lt;void&gt;

设置指定卡片的下一次刷新时间，使用Promise异步回调。适用于需要精确控制卡片刷新时机的场景，例如定时任务等。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明                                   |
| ------ | ------ | ---- | ------------------------------------- |
| formId | string | 是   | 卡片标识。                               |
| minute | number | 是   | 指定卡片多久之后更新，取值范围：大于等于5，单位：min。 |

**返回值：**

| 类型          | 说明                              |
| ------------- | ---------------------------------- |
| Promise\<void> | 无返回结果的Promise对象。      |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501002 | The number of forms exceeds the maximum allowed. |
| 16501003 | The form cannot be operated by the current application. |

**示例：**

```ts
import { formProvider } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

let formId: string = '12400633174999288'; // 表示卡片formId，根据实际formId调整
try {
  formProvider.setFormNextRefreshTime(formId, 5).then(() => {
    console.info(`formProvider setFormNextRefreshTime success`);
  }).catch((error: BusinessError) => {
    console.error(`promise error, code: ${error.code}, message: ${error.message}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## formProvider.updateForm

updateForm(formId: string, formBindingData: formBindingData.FormBindingData, callback: AsyncCallback&lt;void&gt;): void

更新指定的卡片，使用callback异步回调。适用于卡片数据变化时主动更新卡片内容的场景，例如天气数据变化、股票价格更新、任务进度更新等。
> **说明：**
>
> 从API version 20开始，如果卡片刷新的数据通过共享内存更新，刷新数据总大小不超过10MB，刷新图片数量不超过20张。API version 19及之前的版本，图片文件数量上限为5张，每张限制内存2MB，超出限制的图片会显示异常。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型                                                                    | 必填 | 说明             |
| ------ | ---------------------------------------------------------------------- | ---- | ---------------- |
| formId | string                                                                 | 是   | 请求更新的卡片标识。 |
| formBindingData | [formBindingData.FormBindingData](js-apis-app-form-formBindingData.md#formbindingdata) | 是   | 用于更新的数据。具体限制请参考上方说明。    |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。更新结果的回调，成功时error为undefined。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form cannot be operated by the current application. |

**示例：**

```ts
import { formBindingData, formProvider } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

let formId: string = '12400633174999288'; // 表示卡片formId，根据实际formId调整
try {
  let param: Record<string, string> = {
    'temperature': '22c',
    'time': '22:00'
  }
  let obj: formBindingData.FormBindingData = formBindingData.createFormBindingData(param);
  formProvider.updateForm(formId, obj, (error: BusinessError) => {
    if (error) {
      console.error(`callback error, code: ${error.code}, message: ${error.message}`);
      return;
    }
    console.info(`formProvider updateForm success`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## formProvider.updateForm

updateForm(formId: string, formBindingData: formBindingData.FormBindingData): Promise&lt;void&gt;

更新指定的卡片，使用Promise异步回调。适用于卡片数据变化时主动更新卡片内容的场景，例如天气数据变化、股票价格更新、任务进度更新等。
> **说明：**
>
> 从API version 20开始，如果卡片刷新的数据通过共享内存更新，刷新数据总大小不超过10MB，刷新图片数量不超过20张。API version 19及之前的版本，图片文件数量上限为5张，每张限制内存2MB，超出限制的图片会显示异常。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型                                                                    | 必填 | 说明             |
| ------ | ---------------------------------------------------------------------- | ---- | ---------------- |
| formId | string                                                                 | 是   | 请求更新的卡片标识。 |
| formBindingData | [formBindingData.FormBindingData](js-apis-app-form-formBindingData.md#formbindingdata) | 是   | 用于更新的数据。具体限制请参考上方说明。    |

**返回值：**

| 类型           | 说明                                |
| -------------- | ----------------------------------- |
| Promise\<void> | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form cannot be operated by the current application. |

**示例：**

```ts
import { formBindingData, formProvider } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

let formId: string = '12400633174999288'; // 表示卡片formId，根据实际formId调整
let param: Record<string, string> = {
  'temperature': '22c',
  'time': '22:00'
}
let obj: formBindingData.FormBindingData = formBindingData.createFormBindingData(param);
try {
  formProvider.updateForm(formId, obj).then(() => {
    console.info(`formProvider updateForm success`);
  }).catch((error: BusinessError) => {
    console.error(`promise error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## formProvider.getFormsInfo

getFormsInfo(callback: AsyncCallback&lt;Array&lt;formInfo.FormInfo&gt;&gt;): void

获取设备上当前应用程序的卡片信息，使用callback异步回调。适用于卡片管理、调试、统计等场景，例如查看应用所有卡片配置信息、统计卡片数量等。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| callback | AsyncCallback&lt;Array&lt;[formInfo.FormInfo](js-apis-app-form-formInfo.md#forminfo)&gt;&gt; | 是 | 回调函数。返回查询到的卡片信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

**示例：**

```ts
import { formProvider } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  formProvider.getFormsInfo((error, data) => {
    if (error) {
      console.error(`callback error, code: ${error.code}, message: ${error.message}`);
      return;
    }
    console.info(`formProvider getFormsInfo, data: ${JSON.stringify(data)}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```
## formProvider.getFormsInfo

getFormsInfo(filter: formInfo.FormInfoFilter, callback: AsyncCallback&lt;Array&lt;formInfo.FormInfo&gt;&gt;): void

获取设备上当前应用程序的卡片信息，并筛选符合条件的信息，使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| filter | [formInfo.FormInfoFilter](js-apis-app-form-formInfo.md#forminfofilter) | 是 | 卡片信息过滤器。 |
| callback | AsyncCallback&lt;Array&lt;[formInfo.FormInfo](js-apis-app-form-formInfo.md)&gt;&gt; | 是 | 回调函数。返回查询到符合条件的卡片信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

**示例：**

```ts
import { formInfo, formProvider } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

const filter: formInfo.FormInfoFilter = {
  // 获取指定module的卡片信息
  moduleName: 'entry'
};
try {
  formProvider.getFormsInfo(filter, (error, data) => {
    if (error) {
      console.error(`callback error, code: ${error.code}, message: ${error.message}`);
      return;
    }
    console.info(`formProvider getFormsInfo, data: ${JSON.stringify(data)}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## formProvider.getFormsInfo

getFormsInfo(filter?: formInfo.FormInfoFilter): Promise&lt;Array&lt;formInfo.FormInfo&gt;&gt;

获取设备上当前应用符合条件的卡片信息，使用Promise异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| filter | [formInfo.FormInfoFilter](js-apis-app-form-formInfo.md#forminfofilter) | 否 | 卡片信息过滤器，用于筛选指定条件的卡片信息。当需要获取特定模块或特定名称的卡片时传入此参数进行过滤，当需要获取所有卡片信息时可以不传此参数。不传入时默认为空，返回所有卡片信息。 |

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise&lt;Array&lt;[formInfo.FormInfo](js-apis-app-form-formInfo.md)&gt;&gt; | Promise对象。返回查询到符合条件的卡片信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

**示例：**

```ts
import { formInfo, formProvider } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

const filter: formInfo.FormInfoFilter = {
  // 获取指定module的卡片信息
  moduleName: 'entry'
};
try {
  formProvider.getFormsInfo(filter).then((data: formInfo.FormInfo[]) => {
    console.info(`formProvider getFormsInfo, data: ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
    console.error(`promise error, code: ${error.code}, message: ${error.message}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## formProvider.openFormEditAbility<sup>18+</sup>

openFormEditAbility(abilityName: string, formId: string, isMainPage?: boolean): void

打开卡片编辑页。适用于需要用户配置卡片参数的场景，例如设置卡片显示内容、选择数据源、配置更新频率等。

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明                                                 |
| ------ | ------ |----|----------------------------------------------------|
| abilityName | string | 是  | 编辑页的ability名称。                                     |
| formId | string | 是  | 卡片标识。                                              |
| isMainPage | boolean | 否  | 是否为主编辑页。<br>-&nbsp;true：表示是主编辑页，适合首次配置卡片基本信息的场景。<br>-&nbsp;false：表示不是主编辑页，适合进行卡片细节调整或高级配置的场景。<br>默认值：true（通常首次编辑卡片时使用默认值即可）。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID    | 错误信息 |
|----------| -------- |
| 801      | Capability not supported.function openFormEditAbility can not work correctly due to limited device capabilities. |
| 16500050 | IPC connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |
| 16501003 | The form cannot be operated by the current application. |
| 16501007 | Form is not trust. |

**示例：**

```ts
import { formProvider } from '@kit.FormKit';

const TAG: string = 'FormEditDemo-Page] -->';

@Entry
@Component
struct Page {
  @State message: string = 'Hello World';

  aboutToAppear(): void {
    console.info(`${TAG} aboutToAppear.....`);
  }

  build() {
    RelativeContainer() {
      Text(this.message)
        .id('PageHelloWorld')
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
        .alignRules({
          center: { anchor: '__container__', align: VerticalAlign.Top },
          middle: { anchor: '__container__', align: HorizontalAlign.Center }
        })
        .onClick(() => {
          console.info(`${TAG} onClick.....`);
          formProvider.openFormEditAbility('ability://EntryFormEditAbility', '1386529921');
        })
    }
    .height('100%')
    .width('100%')
  }
}
```

## formProvider.closeFormEditAbility<sup>23+</sup>

closeFormEditAbility(isMainPage?: boolean): void

关闭卡片编辑页。适用于卡片编辑完成或取消编辑的场景，例如用户完成参数配置后关闭编辑页、取消编辑操作等。

**系统能力：** SystemCapability.Ability.Form

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型    | 必填 | 说明                                                 |
| ------ | ------ |----|----------------------------------------------------|
| isMainPage | boolean | 否  | 是否关闭主编辑页。<br>-&nbsp;true：关闭主编辑页，适合在主编辑页完成配置后关闭的场景。<br>-&nbsp;false：关闭非主编辑页，适合在多级编辑页场景下关闭当前非主编辑页的场景。<br>默认值：true（通常关闭当前编辑页时使用默认值即可）。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID    | 错误信息 |
|----------| -------- |
| 801      | Capability not supported due to limited device capabilities. |
| 16500050 | IPC connection error. |
| 16501015 | Cannot close the widget editing page opened by other apps. |

**示例：**

```ts
import { formProvider } from '@kit.FormKit';

const TAG: string = 'FormEditDemo-Page] -->';

@Entry
@Component
struct Page {
  @State message: string = 'Hello World';

  aboutToAppear(): void {
    console.info(`${TAG} aboutToAppear.....`);
  }

  build() {
    RelativeContainer() {
      Text(this.message)
        .id('PageHelloWorld')
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
        .alignRules({
          center: { anchor: '__container__', align: VerticalAlign.Top },
          middle: { anchor: '__container__', align: HorizontalAlign.Center }
        })
        .onClick(() => {
          console.info(`${TAG} onClick.....`);
          try {
            formProvider.closeFormEditAbility();
            console.info(`${TAG} close FormEditAbility success.`);
          } catch (error) {
            console.error(`${TAG} close FormEditAbility failed, code: ${error.code}, message: ${error.message}`);
          }
        })
    }
    .height('100%')
    .width('100%')
  }
}
```

## formProvider.openFormManager<sup>18+</sup>

openFormManager(want: Want): void

打开当前应用的卡片管理页面。适用于卡片管理场景，例如预览当前应用所有可以加桌的卡片、添加卡片到负一屏或桌面等。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.Form

**设备行为差异：** 该接口在Wearable中调用会返回[16501000](./errorcode-form.md#16501000-内部功能错误)错误码。

**参数：**

| 参数名  | 类型    | 必填 | 说明                                                                                                                                                                                                                                                                                                      |
|------| ------ | ---- |---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| want     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 打开卡片管理页面的请求中的want参数，需包含以下字段。<br>bundleName: 卡片所属应用的包名。<br>abilityName: 卡片所属的ability名称。<br>parameters:<br>- ohos.extra.param.key.form_dimension: [卡片尺寸](js-apis-app-form-formInfo.md#formdimension)。<br>- ohos.extra.param.key.form_name: 卡片名称。<br>- ohos.extra.param.key.module_name: 卡片所属的模块名称。 |
> **说明：**
>
> 如果parameters参数没有填完整或者指定的卡片不存在，就会默认展示[form_config.json](../../form/arkts-ui-widget-configuration.md#卡片配置)中配置的默认卡片。

**错误码：**

以下错误码的详细介绍请参见[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 16500050 | IPC connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

**示例：**

```ts
import { formProvider } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { Want } from '@kit.AbilityKit';

const want: Want = {
  bundleName: 'com.example.formbutton',
  abilityName: 'EntryFormAbility',
  parameters: {
    'ohos.extra.param.key.form_dimension': 2,
    'ohos.extra.param.key.form_name': 'widget',
    'ohos.extra.param.key.module_name': 'entry'
  },
};
try {
  formProvider.openFormManager(want);
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## formProvider.getPublishedFormInfoById<sup>(deprecated)</sup>

getPublishedFormInfoById(formId: string): Promise&lt;formInfo.FormInfo&gt;

获取设备上当前应用程序已添加到桌面的指定卡片信息，使用Promise异步回调。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

> **说明：**
>
> 该接口从API version 18开始支持，从API version 20开始废弃，建议使用[getPublishedRunningFormInfoById](#formprovidergetpublishedrunningforminfobyid20)替代。

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ |----| ------- |
| formId | string | 是 | 卡片标识。 |

**返回值：**

| 类型                                                                | 说明                                |
|-------------------------------------------------------------------| ---------------------------------- |
| Promise&lt;[formInfo.FormInfo](js-apis-app-form-formInfo.md#forminfo)&gt; | Promise对象。返回查询到符合条件的卡片信息。 |

**错误码：**

以下错误码的详细介绍请参见[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 16500050 | IPC connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

**示例：**

```ts
import { formInfo, formProvider } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

const formId: string = '388344236';
try {
  formProvider.getPublishedFormInfoById(formId).then((data: formInfo.FormInfo) => {
    console.info(`formProvider getPublishedFormInfoById, data: ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
    console.error(`promise error, code: ${error.code}, message: ${error.message}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## formProvider.getPublishedFormInfos<sup>(deprecated)</sup>

getPublishedFormInfos(): Promise&lt;Array&lt;formInfo.FormInfo&gt;&gt;

获取设备上当前应用所有已添加到桌面的卡片信息，使用Promise异步回调。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

> **说明：**
>
> 该接口从API version 18开始支持，从API version 20开始废弃，建议使用[getPublishedRunningFormInfos](#formprovidergetpublishedrunningforminfos20)替代。

**系统能力：** SystemCapability.Ability.Form

**返回值：**

| 类型          | 说明                                |
| ------------ | ---------------------------------- |
| Promise&lt;Array&lt;[formInfo.FormInfo](js-apis-app-form-formInfo.md)&gt;&gt; | Promise对象。返回查询到符合条件的卡片信息。 |

**错误码：**

以下错误码的详细介绍请参见[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 16500050 | IPC connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

**示例：**

```ts
import { formInfo, formProvider } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  formProvider.getPublishedFormInfos().then((data: formInfo.FormInfo[]) => {
    console.info(`formProvider getPublishedFormInfos, data: ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
    console.error(`promise error, code: ${error.code}, message: ${error.message}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## formProvider.requestOverflow<sup>20+</sup>

requestOverflow(formId: string, overflowInfo: formInfo.OverflowInfo): Promise&lt;void&gt;

卡片提供方发起互动卡片动效请求，只针对[场景动效类型互动卡片](../../form/arkts-ui-widget-configuration.md#sceneanimationparams标签)生效，使用Promise异步回调。

**相关方法：**
- [cancelOverflow()](#formprovidercanceloverflow20)：取消互动卡片动效请求，用于取消已发起的动效。

> **说明：**
>
> 1. 该接口在省电模式场景下不可使用，会报16501000错误码。
> 2. 当设备热档位进入HOT场景并且没有点击事件的场景下，该接口会报16501000错误码；当热档位进入OVERHEATED时，任何情况下都会报16501000错误码。热档位信息具体可参考[热档位信息](../../reference/apis-basic-services-kit/js-apis-thermal.md#thermallevel)。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**设备行为差异：** 该接口支持Phone中的部分机型，不支持的设备调用会返回[801](../errorcode-universal.md#801-该设备不支持此api)错误码。

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型                                                                 | 必填 | 说明        |
| ------ |--------------------------------------------------------------------| ---- |-----------|
| formId | string                                                             | 是 | 卡片标识。|
| overflowInfo | [formInfo.OverflowInfo](js-apis-app-form-formInfo.md#overflowinfo20) | 是 | 动效请求参数信息。|

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 801 |   Capability not supported.function requestOverflow can not work correctly due to limited device capabilities. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form cannot be operated by the current application. |
| 16501011 | The form can not support this operation. |

**示例：**

```ts
import { formInfo, formProvider } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

let formId: string = '12400633174999288'; // 表示卡片formId，根据实际formId调整
let overflowInfo: formInfo.OverflowInfo = {
  area: {
    left: -10,
    top: -10,
    width: 180,
    height: 180
  },
  duration: 1000,
  useDefaultAnimation: false,
};

try {
  formProvider.requestOverflow(formId, overflowInfo).then(() => {
    console.info('requestOverflow succeed.');
  }).catch((error: BusinessError) => {
    console.error(`promise error, code: ${error.code}, message: ${error.message}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## formProvider.cancelOverflow<sup>20+</sup>

cancelOverflow(formId: string): Promise&lt;void&gt;

卡片提供方发起取消互动卡片动效请求，只针对[场景动效类型互动卡片](../../form/arkts-ui-widget-configuration.md#sceneanimationparams标签)生效，使用Promise异步回调。

> **说明：**
>
> 1. 该接口在省电模式场景下不可使用，会报16501000错误码。
> 2. 当设备热档位进入HOT场景并且没有点击事件的场景下，该接口会报16501000错误码；当热档位进入OVERHEATED时，任何情况下都会报16501000错误码。热档位信息具体可参考[热档位信息](../../reference/apis-basic-services-kit/js-apis-thermal.md#thermallevel)。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**设备行为差异：** 该接口支持Phone中的部分机型，不支持的设备调用会返回[801](../errorcode-universal.md#801-该设备不支持此api)错误码。

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- |-------|
| formId | string | 是 | 卡片标识。|

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 801 | Capability not supported.function cancelOverflow can not work correctly due to limited device capabilities. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form cannot be operated by the current application. |
| 16501011 | The form can not support this operation. |

**示例：**

```ts
import { formProvider } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

let formId: string = '12400633174999288'; // 表示卡片formId，根据实际formId调整

try {
  formProvider.cancelOverflow(formId).then(() => {
    console.info('cancelOverflow succeed.');
  }).catch((error: BusinessError) => {
    console.error(`promise error, code: ${error.code}, message: ${error.message}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## formProvider.getFormRect<sup>20+</sup>

getFormRect(formId: string): Promise&lt;formInfo.Rect&gt;

查询卡片位置、尺寸，使用Promise异步回调。适用于需要获取卡片在屏幕上的位置和尺寸信息的场景，例如卡片动效、位置校准、布局计算等。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型         | 必填 | 说明        |
| ------ |-------------| ---- |-----------|
| formId | string      | 是 | 卡片标识。|

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;[formInfo.Rect](js-apis-app-form-formInfo.md#rect20)&gt; | Promise对象，返回卡片相对屏幕左上角的位置信息和卡片尺寸信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 801 |   Capability not supported.function getFormRect can not work correctly due to limited device capabilities. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form cannot be operated by the current application. |

**示例：**

```ts
import { formInfo, formProvider } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

let formId: string = '12400633174999288'; // 表示卡片formId，根据实际formId调整

try {
  formProvider.getFormRect(formId).then((data: formInfo.Rect) => {
    console.info(`getFormRect succeed, data: ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
    console.error(`promise error, code: ${error.code}, message: ${error.message}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## formProvider.getPublishedRunningFormInfoById<sup>20+</sup>

getPublishedRunningFormInfoById(formId: string): Promise&lt;formInfo.RunningFormInfo&gt;

获取当前应用已加桌的指定卡片信息，使用Promise异步回调。适用于卡片管理、调试等场景，例如查看指定卡片的位置信息和尺寸信息。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ |----| ------- |
| formId | string | 是 | 卡片标识。 |

**返回值：**

| 类型                                                                | 说明                                |
|-------------------------------------------------------------------| ---------------------------------- |
| Promise&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo.md#runningforminfo20)&gt; | Promise对象。返回符合条件的卡片信息，包括卡片名称、尺寸等。 |

**错误码：**

以下错误码的详细介绍请参见[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 16500050 | IPC connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |
| 16501001  | The ID of the form to be operated does not exist. |
| 16501003  | The form cannot be operated by the current application. |

**示例：**

```ts
import { formInfo, formProvider } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

const formId: string = '388344236';

try {
  formProvider.getPublishedRunningFormInfoById(formId).then((data: formInfo.RunningFormInfo) => {
    console.info(`formProvider getPublishedRunningFormInfoById, data: ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
    console.error(`promise error, code: ${error.code}, message: ${error.message}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## formProvider.getPublishedRunningFormInfos<sup>20+</sup>

getPublishedRunningFormInfos(): Promise&lt;Array&lt;formInfo.RunningFormInfo&gt;&gt;

获取所有已加桌的卡片信息，使用Promise异步回调。适用于卡片管理、批量操作、统计等场景，例如查看应用所有已添加到桌面的卡片信息、批量更新卡片状态等。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.Form

**返回值：**

| 类型          | 说明                                |
| ------------ | ---------------------------------- |
| Promise&lt;Array&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo.md#runningforminfo20)&gt;&gt; | Promise对象。返回符合条件的卡片信息。 |

**错误码：**

以下错误码的详细介绍请参见[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 16500050 | IPC connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

**示例：**

```ts
import { formInfo, formProvider } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  formProvider.getPublishedRunningFormInfos().then((data: formInfo.RunningFormInfo[]) => {
    console.info(`formProvider getPublishedRunningFormInfos, data: ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
    console.error(`promise error, code: ${error.code}, message: ${error.message}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## formProvider.reloadForms<sup>22+</sup>

reloadForms(context: UIAbilityContext, moduleName: string, abilityName: string, formName: string): Promise&lt;number&gt;

对于当前应用中moduleName、abilityName、formName相同的卡片，每次加桌会分配不同的卡片ID。卡片提供方可通过本接口批量更新这些卡片。与reloadAllForms相比，本接口可精确指定更新特定配置的卡片，适用于仅需更新特定卡片场景；reloadAllForms更新当前应用所有已加桌卡片，适用于全局刷新场景。本接口在应用主进程中调用，通知FormExtension进程进行批量更新，仅支持在[UIAbility](../apis-ability-kit/js-apis-app-ability-uiAbility.md)中使用，使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------  |
| context | [UIAbilityContext](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md) | 是   | [UIAbility](../apis-ability-kit/js-apis-app-ability-uiAbility.md)的上下文，用于校验应用身份。     |
| moduleName | string | 是   | 指定卡片的moduleName，需与[form_config.json](../../form/arkts-ui-widget-configuration.md#配置文件字段说明)中配置的module名称一致。需与abilityName、formName配合使用，三者必须同时匹配才能定位到对应卡片。   |
| abilityName | string | 是 | 指定卡片的abilityName，需与[form_config.json](../../form/arkts-ui-widget-configuration.md#配置文件字段说明)中配置的ability名称一致。  |
| formName | string | 是 | 指定卡片在[form_config.json](../../form/arkts-ui-widget-configuration.md#配置文件字段说明)中配置的卡片名称。 |

**返回值：**

| 类型          | 说明                                |
| ------------ | ---------------------------------- |
| Promise&lt;number&gt; | Promise对象。返回请求更新卡片的数量。 |

**错误码：**

以下错误码的详细介绍请参见[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 16501000 | An internal functional error occurred. |

**示例：**

```ts
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { formProvider } from '@kit.FormKit';

try {
  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext。
  let context: common.UIAbilityContext = this.getUIContext().getHostContext() as common.UIAbilityContext;
  // 请开发者替换为实际请求更新的卡片信息
  let moduleName: string = 'entry';
  let abilityName: string = 'EntryFormAbility';
  let formName: string = 'formName';
  formProvider.reloadForms(context, moduleName, abilityName, formName).then((reloadNum: number) => {
    console.info(`reloadForms success, reload number: ${reloadNum}`);
  }).catch((error: BusinessError) => {
    console.error(`promise error, code: ${error.code}, message: ${error.message}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## formProvider.reloadAllForms<sup>22+</sup>

reloadAllForms(context: UIAbilityContext): Promise&lt;number&gt;

在应用主进程通过本接口可以通知FormExtension进程批量更新当前应用下已经加桌的所有卡片，仅支持在[UIAbility](../apis-ability-kit/js-apis-app-ability-uiAbility.md)中调用，使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------  |
| context | [UIAbilityContext](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md) | 是   | [UIAbility](../apis-ability-kit/js-apis-app-ability-uiAbility.md)的上下文，用于校验应用身份。     |

**返回值：**

| 类型          | 说明                                |
| ------------ | ---------------------------------- |
| Promise&lt;number&gt; | Promise对象。返回请求更新卡片的数量。 |

**错误码：**

以下错误码的详细介绍请参见[卡片错误码](errorcode-form.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 16501000 | An internal functional error occurred. |

**示例：**

```ts
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { formProvider } from '@kit.FormKit';

try {
  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext。
  let context: common.UIAbilityContext = this.getUIContext().getHostContext() as common.UIAbilityContext;
  formProvider.reloadAllForms(context).then((reloadNum: number) => {
    console.info(`reloadAllForms success, reload number: ${reloadNum}`);
  }).catch((error: BusinessError) => {
    console.error(`promise error, code: ${error.code}, message: ${error.message}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```