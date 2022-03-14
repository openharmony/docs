# 卡片数据绑定类

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```
import formBindingData from '@ohos.application.formBindingData';
```

## 权限

无

## formBindingData.createFormBindingData

createFormBindingData(obj?: Object | string): FormBindingData

创建一个FormBindingData对象。

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型           | 必填 | 说明                                                         |
| ------ | -------------- | ---- | ------------------------------------------------------------ |
| obj    | Object或string | 否   | js卡片要展示的数据。可以是包含若干键值对的Object或者 json 格式的字符串。 |


**返回值：**

| 类型                                | 说明                                    |
| ----------------------------------- | --------------------------------------- |
| [FormBindingData](#formbindingdata) | 根据传入数据创建的FormBindingData对象。 |


**示例：**

  ```js
  let obj = {"temperature": "21°"};
  let formBindingDataObj = formBindingData.createFormBindingData(obj);
  ```

## formBindingData.FormBindingData

FormBindingData相关描述。

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 名称 | 类型           | 说明                                                         |
| ---- | -------------- | ------------------------------------------------------------ |
| obj  | Object或string | js卡片要展示的数据。可以是包含若干键值对的Object或者 json 格式的字符串。 |