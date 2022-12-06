# FormProvider

FormProvider模块提供了卡片提供方相关接口的能力，包括更新卡片，设置卡片更新时间，获取卡片信息，请求发布卡片等。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```
import formProvider from '@ohos.app.ability.formProvider';
```

## 权限

无

## setFormNextRefreshTime

setFormNextRefreshTime(formId: string, minute: number, callback: AsyncCallback&lt;void&gt;): void;

设置指定卡片的下一次更新时间。

**系统能力：**

SystemCapability.Ability.Form

**参数：**

  | 参数名 | 类型    | 必填 | 说明                                   |
  | ------ | ------ | ---- | ------------------------------------- |
  | formId | string | 是   | 卡片标识                               |
  | minute | number | 是   | 指定多久之后更新，单位分钟，大于等于5     |
  | callback | AsyncCallback&lt;void&gt; | 是 | callback形式返回启动结果 |

**示例：**

  ```js
  var formId = "12400633174999288";
  try {
    formProvider.setFormNextRefreshTime(formId, 5, (error, data) => {
        if (error.code) {
          console.log('formProvider setFormNextRefreshTime, error:' + JSON.stringify(error));
        }
    });
  } catch (paramError) {
    console.log("error: " + paramError.code + ", " + paramError.message);
  }
  ```

## setFormNextRefreshTime

setFormNextRefreshTime(formId: string, minute: number): Promise&lt;void&gt;;

设置指定卡片的下一次更新时间，以promise方式返回。

**系统能力：**

SystemCapability.Ability.Form

**参数：**

  | 参数名 | 类型    | 必填 | 说明                                   |
  | ------ | ------ | ---- | ------------------------------------- |
  | formId | string | 是   | 卡片标识                               |
  | minute | number | 是   | 指定多久之后更新，单位分钟，大于等于5     |

**返回值：**

  | 类型          | 说明                              |
  | ------------- | ---------------------------------- |
  | Promise\<void> |Promise实例，用于获取异步返回结果。      |

**示例：**

  ```js
  var formId = "12400633174999288";
  try {
    formProvider.setFormNextRefreshTime(formId, 5).then(() => {
      console.log('formProvider setFormNextRefreshTime success');
    }).catch((error) => {
      console.log('formProvider setFormNextRefreshTime, error:' + JSON.stringify(error));
    });
  } catch (paramError) {
    console.log("error: " + paramError.code + ", " + paramError.message);
  }
  ```

## updateForm

updateForm(formId: string, formBindingData: formBindingData.FormBindingData,callback: AsyncCallback&lt;void&gt;): void;

更新指定的卡片。

**系统能力：**

SystemCapability.Ability.Form

**参数：**

  | 参数名 | 类型                                                                    | 必填 | 说明             |
  | ------ | ---------------------------------------------------------------------- | ---- | ---------------- |
  | formId | string                                                                 | 是   | 请求更新的卡片标识 |
  | formBindingData | [FormBindingData](js-apis-formbindingdata.md#formbindingdata) | 是   | 用于更新的数据    |
  | callback | AsyncCallback&lt;void&gt; | 是 | callback形式返回启动结果 |

**示例：**

  ```js
  import formBindingData from '@ohos.application.formBindingData';
  var formId = "12400633174999288";
  let obj = formBindingData.createFormBindingData({temperature:"22c", time:"22:00"});
  try {
    formProvider.updateForm(formId, obj, (error, data) => {
      if (error.code) {
          console.log('formProvider updateForm, error:' + JSON.stringify(error));
      }
    });
  } catch (paramError) {
    console.log("error: " + paramError.code + ", " + paramError.message);
  }
  ```

## updateForm

updateForm(formId: string, formBindingData: formBindingData.FormBindingData): Promise&lt;void&gt;;

更新指定的卡片，以promise方式返回。

**系统能力：**

SystemCapability.Ability.Form

**参数：**

  | 参数名 | 类型                                                                    | 必填 | 说明             |
  | ------ | ---------------------------------------------------------------------- | ---- | ---------------- |
  | formId | string                                                                 | 是   | 请求更新的卡片标识 |
  | formBindingData | [FormBindingData](js-apis-formbindingdata.md#formbindingdata) | 是   | 用于更新的数据    |

**返回值：**

| 类型           | 说明                                |
| -------------- | ----------------------------------- |
| Promise\<void> | Promise实例，用于获取异步返回结果。 |

**示例：**

  ```js
  import formBindingData from '@ohos.application.formBindingData';
  var formId = "12400633174999288";
  let obj = formBindingData.createFormBindingData({temperature:"22c", time:"22:00"});
  try {
    formProvider.updateForm(formId, obj).then(() => {
      console.log('formProvider updateForm success');
    }).catch((error) => {
      console.log('formProvider updateForm, error:' + JSON.stringify(error));
    });
  } catch (paramError) {
    console.log("error: " + paramError.code + ", " + paramError.message);
  }
  ```

## getFormsInfo

getFormsInfo(callback: AsyncCallback&lt;Array&lt;formInfo.FormInfo&gt;&gt;): void;

获取设备上当前应用程序的卡片信息。

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| callback | AsyncCallback&lt;Array&lt;[FormInfo](./js-apis-formInfo.md#forminfo-1)&gt;&gt; | 是 | callback形式返回查询到的卡片信息。 |

**示例：**

```js
formProvider.getFormsInfo((error, data) => {
    if (error.code) {
        console.log('formProvider getFormsInfo, error:' + JSON.stringify(error));
    } else {
        console.log('formProvider getFormsInfo, data:' + JSON.stringify(data));
    }
});
```
## getFormsInfo

getFormsInfo(filter: formInfo.FormInfoFilter, callback: AsyncCallback&lt;Array&lt;formInfo.FormInfo&gt;&gt;): void;

获取设备上当前应用程序的卡片信息。

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| filter | [formInfo.FormInfoFilter](./js-apis-formInfo.md#forminfofilter) | 是 | 过滤卡片信息 |
| callback | AsyncCallback&lt;Array&lt;[FormInfo](./js-apis-formInfo.md#forminfo-1)&gt;&gt; | 是 | callback形式返回查询到的卡片信息。 |

**示例：**

```js
import formInfo from '@ohos.application.formInfo';
const filter : formInfo.FormInfoFilter = {
    moduleName : "entry"
};
try {
  formProvider.getFormsInfo(filter, (error, data) => {
    if (error.code) {
        console.log('formProvider getFormsInfo, error:' + JSON.stringify(error));
    } else {
        console.log('formProvider getFormsInfo, data:' + JSON.stringify(data));
    }
  });
} catch (paramError) {
  console.log("error: " + paramError.code + ", " + paramError.message);
}
```

## getFormsInfo

getFormsInfo(filter?: formInfo.FormInfoFilter): Promise&lt;Array&lt;formInfo.FormInfo&gt;&gt;;

获取设备上当前应用程序的卡片信息。

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| filter | [formInfo.FormInfoFilter](./js-apis-app-ability-formInfo.md) | 否 | 过滤卡片信息 |

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise&lt;Array&lt;[FormInfo](./js-apis-app-ability-formInfo.md#forminfo-1)&gt;&gt; | Promise实例，用于获取异步返回查询到的卡片信息。 |

**示例：**

```js
import formInfo from '@ohos.app.ability.formInfo';
const filter : formInfo.FormInfoFilter = {
    moduleName : "entry"
};
try {
  formProvider.getFormsInfo(filter).then((data) => {
    console.log('formProvider getFormsInfo, data:' + JSON.stringify(data));
  }).catch((error) => {
    console.log('formProvider getFormsInfo, error:' + JSON.stringify(error));
  });
} catch (paramError) {
  console.log("error: " + paramError.code + ", " + paramError.message);
}
```

## requestPublishForm

requestPublishForm(want: Want, formBindingData: formBindingData.FormBindingData, callback: AsyncCallback\<string>): void;

请求发布一张卡片到使用方。

**系统能力：** SystemCapability.Ability.Form

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型                                                                    | 必填 | 说明             |
| ------ | ---------------------------------------------------------------------- | ---- | ---------------- |
| want | [Want](js-apis-app-ability-Want.md)                           | 是   | abilityName: 目标卡片ability<br>parameters:<br>"ohos.extra.param.key.form_dimension"<br>"ohos.extra.param.key.form_name"<br>"ohos.extra.param.key.module_name" |
| formBindingData | [FormBindingData](js-apis-app-ability-formbindingdata.md#formbindingdata) | 是   | 用于创建卡片的数据 |
| callback | AsyncCallback&lt;string&gt; | 是 | callback形式返回卡片标识 |

**示例：**

  ```js
  import formBindingData from '@ohos.app.ability.formBindingData';
  var want = {
      abilityName: "FormAbility",
      parameters: {
          "ohos.extra.param.key.form_dimension": 2,
          "ohos.extra.param.key.form_name": "widget",
          "ohos.extra.param.key.module_name": "entry"
      }
  };
  try {
    let obj = formBindingData.createFormBindingData({temperature:"22c", time:"22:00"});
    formProvider.requestPublishForm(want, obj, (error, data) => {
      if (error.code) {
          console.log('formProvider requestPublishForm, error: ' + JSON.stringify(error));
      } else {
          console.log('formProvider requestPublishForm, form ID is: ' + JSON.stringify(data));
      }
    });
  } catch (paramError) {
    console.log("error: " + paramError.code + ", " + paramError.message);
  }
  ```

## requestPublishForm

requestPublishForm(want: Want, callback: AsyncCallback&lt;string&gt;): void;

请求发布一张卡片到使用方。

**系统能力：** SystemCapability.Ability.Form

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型                                | 必填 | 说明                                                         |
| -------- | ----------------------------------- | ---- | ------------------------------------------------------------ |
| want     | [Want](js-apis-app-ability-Want.md) | 是   | abilityName: 目标卡片ability<br>parameters:<br>"ohos.extra.param.key.form_dimension"<br>"ohos.extra.param.key.form_name"<br>"ohos.extra.param.key.module_name" |
| callback | AsyncCallback&lt;string&gt;         | 是   | callback形式返回卡片标识                                     |

**示例：**

  ```js
  var want = {
      abilityName: "FormAbility",
      parameters: {
          "ohos.extra.param.key.form_dimension": 2,
          "ohos.extra.param.key.form_name": "widget",
          "ohos.extra.param.key.module_name": "entry"
      }
  };
  try {
    formProvider.requestPublishForm(want, (error, data) => {
      if (error.code) {
          console.log('formProvider requestPublishForm, error: ' + JSON.stringify(error));
      } else {
          console.log('formProvider requestPublishForm, form ID is: ' + JSON.stringify(data));
      }
    });
  } catch (paramError) {
    console.log("error: " + paramError.code + ", " + paramError.message);
  }
  ```

## requestPublishForm

requestPublishForm(want: Want, formBindingData?: formBindingData.FormBindingData): Promise&lt;string&gt;;

请求发布一张卡片到使用方。

**系统能力：** SystemCapability.Ability.Form

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名          | 类型                                                         | 必填 | 说明                                                         |
| --------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| want            | [Want](js-apis-app-ability-Want.md)                          | 是   | abilityName: 目标卡片ability<br/>parameters:<br/>"ohos.extra.param.key.form_dimension"<br/>"ohos.extra.param.key.form_name"<br/>"ohos.extra.param.key.module_name" |
| formBindingData | [FormBindingData](js-apis-app-ability-formbindingdata.md#formbindingdata) | 否   | 用于创建卡片的数据                                           |

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise&lt;string&gt; | Promise实例，用于返回卡片标识。 |

**示例：**

  ```js
  var want = {
      abilityName: "FormAbility",
      parameters: {
          "ohos.extra.param.key.form_dimension": 2,
          "ohos.extra.param.key.form_name": "widget",
          "ohos.extra.param.key.module_name": "entry"
      }
  };
  try {
    formProvider.requestPublishForm(want).then((data) => {
      console.log('formProvider requestPublishForm success, form ID is :' + JSON.stringify(data));
    }).catch((error) => {
      console.log('formProvider requestPublishForm, error: ' + JSON.stringify(error));
    });
  } catch (paramError) {
    console.log("error: " + paramError.code + ", " + paramError.message);
  }
  ```

## isRequestPublishFormSupported

isRequestPublishFormSupported(callback: AsyncCallback&lt;boolean&gt;): void;

查询是否支持发布一张卡片到使用方。

**系统能力：** SystemCapability.Ability.Form

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型    | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| callback | AsyncCallback&lt;boolean&gt; | 是 | callback形式返回是否支持发布一张卡片到使用方 |

**示例：**

```js
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

## isRequestPublishFormSupported

isRequestPublishFormSupported(): Promise&lt;boolean&gt;;

查询是否支持发布一张卡片到使用方。

**系统能力：** SystemCapability.Ability.Form

**系统API**: 此接口为系统接口，三方应用不支持调用。

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise&lt;boolean&gt; | Promise实例，用于获取异步返回是否支持发布一张卡片到使用方 |

**示例：**

```js
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