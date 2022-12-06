# 卡片数据绑定类

卡片数据绑定模块提供卡片数据绑定的能力。包括FormBindingData对象的创建、相关信息的描述。

> **说明：**
>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 从API version 9 开始不再维护，建议使用[FormBindingData](js-apis-app-form-formbindingdata.md)替代。
## 导入模块

```
import formBindingData from '@ohos.application.formBindingData';
```

## FormBindingData

FormBindingData相关描述。

**系统能力**：SystemCapability.Ability.Form

| 名称 | 可读 | 可写 | 参数类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- | -------- | -------- |
| data | 是 | 否 | Object | 是 | js卡片要展示的数据。可以是包含若干键值对的Object或者 json 格式的字符串。|


## createFormBindingData

createFormBindingData(obj?: Object | string): FormBindingData

创建一个FormBindingData对象。

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型           | 必填 | 说明                                                         |
| ------ | -------------- | ---- | ------------------------------------------------------------ |
| obj    | Object或string | 否   | js卡片要展示的数据。可以是包含若干键值对的Object或者 json 格式的字符串。其中图片数据以"formImages"作为标识，内容为图片标识与图片文件描述符的键值对{"formImages": {"key1": fd1, "key2": fd2}} |


**返回值：**

| 类型                                | 说明                                    |
| ----------------------------------- | --------------------------------------- |
| [FormBindingData](#formbindingdata) | 根据传入数据创建的FormBindingData对象。 |


**示例：**

  ```js
  import featureAbility from '@ohos.ability.featureAbility';
  import fileio from '@ohos.fileio';
  let context=featureAbility.getContext();
  context.getOrCreateLocalDir((err,data)=>{
      let path=data+"/xxx.jpg";
      let fd = fileio.openSync(path);
      let obj = {
          "temperature": "21°",
          "formImages": {"image": fd}
      };
      let formBindingDataObj = formBindingData.createFormBindingData(obj);
  })

  
  ```

## 属性

FormBindingData相关描述。

**系统能力**：SystemCapability.Ability.Form

| 名称 | 可读 | 可写 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- | -------- | -------- |
| data | 是 | 否 | Object | 是 | js卡片要展示的数据。可以是包含若干键值对的Object或者 json 格式的字符串。|

