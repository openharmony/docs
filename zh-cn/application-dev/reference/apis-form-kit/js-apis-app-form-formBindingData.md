# @ohos.app.form.formBindingData (卡片数据绑定类)
<!--Kit: Form Kit-->
<!--Subsystem: Ability-->
<!--Owner: @Qian-Win-->
<!--Designer: @cx983299475-->
<!--Tester: @mahailong123456-->
<!--Adviser: @HelloShuo-->
卡片数据绑定模块提供卡片数据绑定的能力，支持创建FormBindingData对象并设置卡片展示数据。适用于卡片数据更新、图片数据传递等场景，能够帮助开发者便捷地管理卡片展示内容，提升卡片数据管理的效率。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { formBindingData } from '@kit.FormKit';
```


## ProxyData<sup>10+</sup>

卡片代理刷新订阅数据信息。

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.Form

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| key | string | 否 | 否 | 卡片代理刷新的订阅标识，与数据发布者保持一致。|
| subscriberId | string | 否 | 是 | 卡片代理刷新的订阅条件，用于指定订阅的消息过滤条件。设置后会根据subscriberId匹配相应的代理刷新消息，默认值为当前卡片的formId。当需要指定特定的订阅条件时传入此参数，不传入时默认值为当前卡片的formId。|

## FormBindingData

FormBindingData对象的属性定义。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.Form

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- |-------- | -------- |
| data | Object | 否 | 否 | 卡片要展示的数据。可以是包含若干键值对的Object或者JSON格式的字符串。|
| proxies<sup>10+</sup> | Array<[ProxyData](#proxydata10)> | 否 | 是 | 卡片代理刷新的订阅信息，配置后会订阅代理刷新消息。默认为空数组，表示不订阅代理刷新消息。当需要使用卡片代理刷新功能时传入此参数，不传入时默认为空数组（不使用代理刷新）。<br>**模型约束：** 此接口仅可在Stage模型下使用。|

## formBindingData.createFormBindingData

createFormBindingData(obj?: Object | string): FormBindingData

创建一个FormBindingData对象。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型           | 必填 | 说明                                                         |
| ------ | -------------- | ---- | ------------------------------------------------------------ |
| obj    | Object \| string | 否   | 卡片要展示的数据，用于绑定卡片UI显示的内容。当需要向卡片传递数据时传入此参数，可以是包含若干键值对的Object或者JSON格式的字符串。不传入时创建一个空的FormBindingData对象，卡片将显示默认内容。其中图片数据以'formImages'作为标识，内容为图片标识与图片文件描述符的键值对`{'formImages': {'key1': fd1, 'key2': fd2}}`。<br>**说明：** 在[卡片刷新](../../form/arkts-ui-widget-interaction-overview.md)过程中，卡片UI通过[@LocalStorageProp](../../ui/state-management/arkts-localstorage.md#localstorageprop)接收卡片数据时，FormBindingData对象会序列化，即卡片数据会转换成string类型。从API version 20开始，如果卡片刷新的数据通过共享内存更新，刷新数据总大小不超过10MB，刷新图片数量不超过20张，API version 19及之前的版本，图片文件数量上限为5张，每张限制内存2MB，超出限制的图片会显示异常。 |


**返回值：**

| 类型                                | 说明                                    |
| ----------------------------------- | --------------------------------------- |
| [FormBindingData](#formbindingdata) | 根据传入数据创建的FormBindingData对象，用于卡片数据绑定，向卡片提供要展示的数据。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |


**示例：**

```ts
import { formBindingData } from '@kit.FormKit';
import { fileIo } from '@kit.CoreFileKit';
import { common } from '@kit.AbilityKit';

@Entry
@Component
struct Index {
  content = this.getUIContext().getHostContext() as common.UIAbilityContext;
  pathDir: string = this.content.filesDir;

  createFormBindingData() {
    let filePath = this.pathDir + "/form.png";
    let fd: number = -1;
    try {
      fd = fileIo.openSync(filePath, fileIo.OpenMode.READ_ONLY).fd;
      let formImagesParam: Record<string, number> = {
        'image': fd
      };
      let createFormBindingDataParam: Record<string, string | Record<string, number>> = {
        'name': '21°',
        'imgSrc': 'image',
        'formImages': formImagesParam
      };
      let formBindingDataObj = formBindingData.createFormBindingData(createFormBindingDataParam);
    } catch (error) {
      console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
    } finally {
      if (fd !== -1) {
        fileIo.closeSync(fd);
      }
    }
  }

  build() {
    Button('createFormBindingData')
      .onClick((event: ClickEvent) => {
        this.createFormBindingData();
      })
  }
}
```
