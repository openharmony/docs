# @ohos.app.form.formAgent (FormAgent)

FormAgent模块提供了卡片代理相关接口的能力，目前仅包括请求发布卡片。

> **说明：**
> - 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本模块接口为系统接口。

## 导入模块

```ts
import formAgent from '@ohos.app.form.formAgent';
```

## requestPublishForm

requestPublishForm(want: Want, callback: AsyncCallback&lt;string&gt;): void

请求发布一张卡片到使用方，使用callbck异步回调。使用方通常为桌面。

**需要权限**：ohos.permission.AGENT_REQUIRE_FORM

**系统能力：** SystemCapability.Ability.Form

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                | 必填 | 说明                                                         |
| -------- | ----------------------------------- | ---- | ------------------------------------------------------------ |
| want     | [Want](js-apis-app-ability-want.md) | 是   | 发布请求。需包含以下字段。<br>bundleName: 目标卡片bundleName<br>abilityName: 目标卡片ability<br>parameters:<br>- ohos.extra.param.key.form_dimension: 目标卡片规格<br>- ohos.extra.param.key.form_name: 目标卡片名<br>- ohos.extra.param.key.module_name: 目标卡片moduleName|
| callback | AsyncCallback&lt;string&gt;         | 是   |  回调函数。返回卡片标识。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 16500050 | An IPC connection error happened. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

以上错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

**示例：**

```ts
import Want from '@ohos.app.ability.Want';
import Base from '@ohos.base';

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
  formAgent.requestPublishForm(want, (error: Base.BusinessError, data: string) => {
    if (error) {
      console.error(`callback error, code: ${error.code}, message: ${error.message})`);
      return;
    }
    console.log(`formAgent requestPublishForm, form ID is: ${JSON.stringify(data)}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as Base.BusinessError).code}, message: ${(error as Base.BusinessError).message})`);
}
```

## requestPublishForm

requestPublishForm(want: Want): Promise&lt;string&gt;

请求发布一张卡片到使用方，使用Promise异步回调。使用方通常为桌面。

**需要权限**：ohos.permission.AGENT_REQUIRE_FORM

**系统能力：** SystemCapability.Ability.Form

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名          | 类型                                                         | 必填 | 说明                                                         |
| --------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| want     | [Want](js-apis-app-ability-want.md) | 是   | 发布请求。需包含以下字段。<br>bundleName: 目标卡片bundleName<br>abilityName: 目标卡片ability<br>parameters:<br>- ohos.extra.param.key.form_dimension: 目标卡片规格<br>- ohos.extra.param.key.form_name: 目标卡片名<br>- ohos.extra.param.key.module_name: 目标卡片moduleName |

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise&lt;string&gt; | Promise对象。返回卡片标识。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 16500050 | An IPC connection error happened. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

以上错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。

**示例：**

```ts
import Want from '@ohos.app.ability.Want';
import Base from '@ohos.base';

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
    console.log(`formAgent requestPublishForm success, form ID is : ${JSON.stringify(data)}`);
  }).catch((error: Base.BusinessError) => {
    console.error(`promise error, code: ${error.code}, message: ${error.message})`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as Base.BusinessError).code}, message: ${(error as Base.BusinessError).message})`);
}
```