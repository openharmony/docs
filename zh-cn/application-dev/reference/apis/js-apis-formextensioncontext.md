# FormExtensionContext

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

FormExtension的上下文环境，提供FormExtension具有的能力和接口，继承自ExtensionContext。

## 导入模块

```js
import FormExtension from "@ohos.application.FormExtension";
```

## FormExtensionContext.updateForm

updateForm(formId: string, formBindingData: formBindingData.FormBindingData, callback: AsyncCallback\<void>): void

主动更新卡片。

**系统能力**：SystemCapability.Ability.Form

**参数：**

  | 参数名          | 类型                                                         | 必填 | 说明                                   |
  | --------------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
  | formId          | string                                                       | 是   | 请求更新的卡片ID。                     |
  | formBindingData | [formBindingData.FormBindingData](js-apis-formbindingdata.md#formbindingdata) | 是   | 卡片新的数据。                         |
  | callback        | AsyncCallback\<void>                                         | 是   | 回调函数，返回接口调用是否成功的结果。 |

**示例：**

  ```js
  let obj2 = formBindingData.createFormBindingData({temperature:"22c", time:"22:00"});
  this.context.updateForm(formId, obj2, (data)=>{
      console.log('FormExtension context updateForm, data:' + data);
  });
  ```

## FormExtensionContext.updateForm

updateForm(formId: string, formBindingData: formBindingData.FormBindingData): Promise\<void>

更新卡片。

**系统能力**：SystemCapability.Ability.Form

**参数：**

  | 参数名          | 类型                                                         | 必填 | 说明               |
  | --------------- | ------------------------------------------------------------ | ---- | ------------------ |
  | formId          | string                                                       | 是   | 请求更新的卡片ID。 |
  | formBindingData | [formBindingData.FormBindingData](js-apis-formbindingdata.md#formbindingdata) | 是   | 卡片新的数据。     |

**返回值：**

  | 类型           | 说明                              |
  | -------------- | --------------------------------- |
  | Promise\<void> | 返回一个Promise，包含接口的结果。 |

**示例：**

  ```
  let obj2 = formBindingData.createFormBindingData({temperature:"22c", time:"22:00"});
  this.context.updateForm(formId, obj2)
      .then((data)=>{
          console.log('FormExtension context updateForm, data:' + data);
      }).catch((error) => {
      console.error('Operation updateForm failed. Cause: ' + error);});
  ```