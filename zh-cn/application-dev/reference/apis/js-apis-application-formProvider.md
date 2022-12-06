# FormProvider

FormProvider模块提供了卡片提供方相关接口的能力，开发者在开发卡片时，可通过该模块提供接口实现更新卡片，设置卡片更新时间，获取卡片信息，请求发布卡片等。

> **说明：**
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 从API version 9 开始不再维护，建议使用[FormProvider](js-apis-app-form-formprovider.md)替代。

## 导入模块

```ts
import formProvider from '@ohos.application.formProvider';
```

## setFormNextRefreshTime

setFormNextRefreshTime(formId: string, minute: number, callback: AsyncCallback&lt;void&gt;): void

设置指定卡片的下一次更新时间，使用callback异步回调。

**系统能力：** SystemCapability.Ability.Form

**参数：**

  | 参数名 | 类型    | 必填 | 说明                                   |
  | ------ | ------ | ---- | ------------------------------------- |
  | formId | string | 是   | 卡片标识。                               |
  | minute | number | 是   | 指定多久之后更新，单位分钟，大于等于5。     |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。 |

**示例：**

  ```ts
  var formId = "12400633174999288";
  formProvider.setFormNextRefreshTime(formId, 5, (error, data) => {
      if (error.code) {
          console.log('formProvider setFormNextRefreshTime, error:' + JSON.stringify(error));
      }
  });
  ```

## setFormNextRefreshTime

setFormNextRefreshTime(formId: string, minute: number): Promise&lt;void&gt;

设置指定卡片的下一次更新时间，使用Promise异步回调。

**系统能力：** SystemCapability.Ability.Form

**参数：**

  | 参数名 | 类型    | 必填 | 说明                                   |
  | ------ | ------ | ---- | ------------------------------------- |
  | formId | string | 是   | 卡片标识。                               |
  | minute | number | 是   | 指定多久之后更新，单位分钟，大于等于5。     |

**返回值：**

  | 类型          | 说明                              |
  | ------------- | ---------------------------------- |
  | Promise\<void> | 无返回结果的Promise对象。      |

**示例：**

  ```ts
  var formId = "12400633174999288";
  formProvider.setFormNextRefreshTime(formId, 5).then(() => {
      console.log('formProvider setFormNextRefreshTime success');
  }).catch((error) => {
      console.log('formProvider setFormNextRefreshTime, error:' + JSON.stringify(error));
  });
  ```

## updateForm

updateForm(formId: string, formBindingData: formBindingData.FormBindingData,callback: AsyncCallback&lt;void&gt;): void

更新指定的卡片，使用callback异步回调。

**系统能力：** SystemCapability.Ability.Form

**参数：**

  | 参数名 | 类型                                                                    | 必填 | 说明             |
  | ------ | ---------------------------------------------------------------------- | ---- | ---------------- |
  | formId | string                                                                 | 是   | 请求更新的卡片标识。 |
  | formBindingData | [FormBindingData](js-apis-application-formBindingData.md#formbindingdata) | 是   | 用于更新的数据。    |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。 |

**示例：**

  ```ts
  import formBindingData from '@ohos.application.formBindingData';
  var formId = "12400633174999288";
  let obj = formBindingData.createFormBindingData({temperature:"22c", time:"22:00"});
  formProvider.updateForm(formId, obj, (error, data) => {
      if (error.code) {
          console.log('formProvider updateForm, error:' + JSON.stringify(error));
      }
  });
  ```

## updateForm

updateForm(formId: string, formBindingData: formBindingData.FormBindingData): Promise&lt;void&gt;

更新指定的卡片，使用Promise异步回调。

**系统能力：** SystemCapability.Ability.Form

**参数：**

  | 参数名 | 类型                                                                    | 必填 | 说明             |
  | ------ | ---------------------------------------------------------------------- | ---- | ---------------- |
  | formId | string                                                                 | 是   | 请求更新的卡片标识。 |
  | formBindingData | [FormBindingData](js-apis-application-formBindingData.md#formbindingdata) | 是   | 用于更新的数据。    |

**返回值：**

| 类型           | 说明                                |
| -------------- | ----------------------------------- |
| Promise\<void> | 无返回结果的Promise对象。 |

**示例：**

  ```ts
  import formBindingData from '@ohos.application.formBindingData';
  var formId = "12400633174999288";
  let obj = formBindingData.createFormBindingData({temperature:"22c", time:"22:00"});
  formProvider.updateForm(formId, obj).then(() => {
      console.log('formProvider updateForm success');
  }).catch((error) => {
      console.log('formProvider updateForm, error:' + JSON.stringify(error));
  });
  ```

## getFormsInfo<sup>9+</sup>

getFormsInfo(callback: AsyncCallback&lt;Array&lt;formInfo.FormInfo&gt;&gt;): void

获取设备上当前应用程序的卡片信息，使用callback异步回调。

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| callback | AsyncCallback&lt;Array&lt;[FormInfo](./js-apis-application-formInfo.md#forminfo-1)&gt;&gt; | 是 | 回调函数。返回查询到的卡片信息。 |

**示例：**

```ts
formProvider.getFormsInfo((error, data) => {
    if (error.code) {
        console.log('formProvider getFormsInfo, error:' + JSON.stringify(error));
    } else {
        console.log('formProvider getFormsInfo, data:' + JSON.stringify(data));
    }
});
```
## getFormsInfo<sup>9+</sup>

getFormsInfo(filter: formInfo.FormInfoFilter, callback: AsyncCallback&lt;Array&lt;formInfo.FormInfo&gt;&gt;): void

获取设备上当前应用程序的卡片信息，并筛选符合条件的信息，使用callback异步回调。

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| filter | [formInfo.FormInfoFilter](./js-apis-application-formInfo.md#forminfofilter) | 是 | 卡片信息过滤器。 |
| callback | AsyncCallback&lt;Array&lt;[FormInfo](./js-apis-application-formInfo.md#forminfo-1)&gt;&gt; | 是 | 回调函数。返回查询到符合条件的卡片信息。 |

**示例：**

```ts
import formInfo from '@ohos.application.formInfo';
const filter : formInfo.FormInfoFilter = {
    // get info of forms belong to module entry.
    moduleName : "entry"
};
formProvider.getFormsInfo(filter, (error, data) => {
    if (error.code) {
        console.log('formProvider getFormsInfo, error:' + JSON.stringify(error));
    } else {
        console.log('formProvider getFormsInfo, data:' + JSON.stringify(data));
    }
});
```

## getFormsInfo<sup>9+</sup>

getFormsInfo(filter?: formInfo.FormInfoFilter): Promise&lt;Array&lt;formInfo.FormInfo&gt;&gt;

获取设备上当前应用程序的卡片信息，使用Promise异步回调。

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| filter | [formInfo.FormInfoFilter](./js-apis-application-formInfo.md) | 否 | 卡片信息过滤器。 |

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise&lt;Array&lt;[FormInfo](./js-apis-application-formInfo.md#forminfo-1)&gt;&gt; | Promise对象。返回查询到符合条件的卡片信息。 |

**示例：**

```ts
import formInfo from '@ohos.application.formInfo';
const filter : formInfo.FormInfoFilter = {
    // get info of forms belong to module entry.
    moduleName : "entry"
};
formProvider.getFormsInfo(filter).then((data) => {
    console.log('formProvider getFormsInfo, data:' + JSON.stringify(data));
}).catch((error) => {
    console.log('formProvider getFormsInfo, error:' + JSON.stringify(error));
});
```

## requestPublishForm<sup>9+</sup>

requestPublishForm(want: Want, formBindingData: formBindingData.FormBindingData, callback: AsyncCallback\<string>): void

请求发布一张卡片到使用方。使用方通常为桌面。

**系统能力：** SystemCapability.Ability.Form

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名 | 类型                                                                    | 必填 | 说明             |
| ------ | ---------------------------------------------------------------------- | ---- | ---------------- |
| want | [Want](js-apis-application-want.md)                           | 是   | 发布请求。需包含以下字段。<br>abilityName: 目标卡片ability<br>parameters:<br>"ohos.extra.param.key.form_dimension"<br>"ohos.extra.param.key.form_name"<br>"ohos.extra.param.key.module_name" |
| formBindingData | [FormBindingData](js-apis-application-formBindingData.md#formbindingdata) | 是   | 创建卡片的数据。 |
| callback | AsyncCallback&lt;string&gt; | 是 | 回调函数。返回卡片标识。 |

**示例：**

  ```ts
  import formBindingData from '@ohos.application.formBindingData';
  var want = {
      abilityName: "FormAbility",
      parameters: {
          "ohos.extra.param.key.form_dimension": 2,
          "ohos.extra.param.key.form_name": "widget",
          "ohos.extra.param.key.module_name": "entry"
      }
  };
  let obj = formBindingData.createFormBindingData({temperature:"22c", time:"22:00"});
  formProvider.requestPublishForm(want, obj, (error, data) => {
      if (error.code) {
          console.log('formProvider requestPublishForm, error: ' + JSON.stringify(error));
      } else {
          console.log('formProvider requestPublishForm, form ID is: ' + JSON.stringify(data));
      }
  });
  ```

## requestPublishForm<sup>9+</sup>

requestPublishForm(want: Want, callback: AsyncCallback&lt;string&gt;): void

请求发布一张卡片到使用方。使用方通常为桌面。

**系统能力：** SystemCapability.Ability.Form

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                | 必填 | 说明                                                         |
| -------- | ----------------------------------- | ---- | ------------------------------------------------------------ |
| want     | [Want](js-apis-application-want.md) | 是   | 发布请求。需包含以下字段。<br>abilityName: 目标卡片ability<br>parameters:<br>"ohos.extra.param.key.form_dimension"<br>"ohos.extra.param.key.form_name"<br>"ohos.extra.param.key.module_name" |
| callback | AsyncCallback&lt;string&gt;         | 是   |  回调函数。返回卡片标识。 |

**示例：**

  ```ts
  var want = {
      abilityName: "FormAbility",
      parameters: {
          "ohos.extra.param.key.form_dimension": 2,
          "ohos.extra.param.key.form_name": "widget",
          "ohos.extra.param.key.module_name": "entry"
      }
  };
  formProvider.requestPublishForm(want, (error, data) => {
      if (error.code) {
          console.log('formProvider requestPublishForm, error: ' + JSON.stringify(error));
      } else {
          console.log('formProvider requestPublishForm, form ID is: ' + JSON.stringify(data));
      }
  });
  ```

## requestPublishForm<sup>9+</sup>

requestPublishForm(want: Want, formBindingData?: formBindingData.FormBindingData): Promise&lt;string&gt;

请求发布一张卡片到使用方。使用方通常为桌面。

**系统能力：** SystemCapability.Ability.Form

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名          | 类型                                                         | 必填 | 说明                                                         |
| --------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| want            | [Want](js-apis-application-want.md)                          | 是   | 发布请求。需包含以下字段。<br>abilityName: 目标卡片ability<br>parameters:<br>"ohos.extra.param.key.form_dimension"<br>"ohos.extra.param.key.form_name"<br>"ohos.extra.param.key.module_name" |
| formBindingData | [FormBindingData](js-apis-application-formBindingData.md#formbindingdata) | 否   | 创建卡片的数据。                                           |

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise&lt;string&gt; | Promise对象。返回卡片标识。 |

**示例：**

  ```ts
  var want = {
      abilityName: "FormAbility",
      parameters: {
          "ohos.extra.param.key.form_dimension": 2,
          "ohos.extra.param.key.form_name": "widget",
          "ohos.extra.param.key.module_name": "entry"
      }
  };
  formProvider.requestPublishForm(want).then((data) => {
      console.log('formProvider requestPublishForm success, form ID is :' + JSON.stringify(data));
  }).catch((error) => {
      console.log('formProvider requestPublishForm, error: ' + JSON.stringify(error));
  });
  ```

## isRequestPublishFormSupported<sup>9+<sup>

isRequestPublishFormSupported(callback: AsyncCallback&lt;boolean&gt;): void

查询是否支持发布一张卡片到使用方。

**系统接口**: 此接口为系统接口。

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。返回是否支持发布一张卡片到使用方。|

**示例：**

```ts
formProvider.isRequestPublishFormSupported((error, isSupported) => {
  if (error.code) {
    console.log('formProvider isRequestPublishFormSupported, error:' + JSON.stringify(error));
  } else {
    if (isSupported) {
      var want = {
      abilityName: "FormAbility",
      parameters: {
        "ohos.extra.param.key.form_dimension": 2,
        "ohos.extra.param.key.form_name": "widget",
        "ohos.extra.param.key.module_name": "entry"
      }
      };
      formProvider.requestPublishForm(want, (error, data) => {
        if (error.code) {
          console.log('formProvider requestPublishForm, error: ' + JSON.stringify(error));
        } else {
          console.log('formProvider requestPublishForm, form ID is: ' + JSON.stringify(data));
        }
      });
    }
  }
});
```

## isRequestPublishFormSupported<sup>9+</sup>

isRequestPublishFormSupported(): Promise&lt;boolean&gt;

查询是否支持发布一张卡片到使用方。

**系统接口**: 此接口为系统接口。

**系统能力：** SystemCapability.Ability.Form

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise&lt;boolean&gt; | Promise对象。返回是否支持发布一张卡片到使用方。 |

**示例：**

```ts
formProvider.isRequestPublishFormSupported().then((isSupported) => {
  if (isSupported) {
    var want = {
    abilityName: "FormAbility",
    parameters: {
        "ohos.extra.param.key.form_dimension": 2,
        "ohos.extra.param.key.form_name": "widget",
        "ohos.extra.param.key.module_name": "entry"
    }
    };
    formProvider.requestPublishForm(want).then((data) => {
      console.log('formProvider requestPublishForm success, form ID is :' + JSON.stringify(data));
    }).catch((error) => {
      console.log('formProvider requestPublishForm, error: ' + JSON.stringify(error));
    });
  }
}).catch((error) => {
  console.log('formProvider isRequestPublishFormSupported, error:' + JSON.stringify(error));
});
```