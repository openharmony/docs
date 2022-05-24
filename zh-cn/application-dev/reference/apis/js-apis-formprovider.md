# FormProvider

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

卡片提供方相关接口。

## 导入模块

```
import formProvider from '@ohos.application.formProvider';
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
  formProvider.setFormNextRefreshTime(formId, 5, (error, data) => {
      if (error.code) {
          console.log('formProvider setFormNextRefreshTime, error:' + JSON.stringify(error));
      }
  });
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
  formProvider.setFormNextRefreshTime(formId, 5).then(() => {
      console.log('formProvider setFormNextRefreshTime success');
  }).catch((error) => {
      console.log('formProvider setFormNextRefreshTime, error:' + JSON.stringify(error));
  });
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
  formProvider.updateForm(formId, obj, (error, data) => {
      if (error.code) {
          console.log('formProvider updateForm, error:' + JSON.stringify(error));
      }
  });
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
  formProvider.updateForm(formId, obj).then(() => {
      console.log('formProvider updateForm success');
  }).catch((error) => {
      console.log('formProvider updateForm, error:' + JSON.stringify(error));
  });
  ```