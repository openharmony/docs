# @ohos.annotation (注解)
<!--Kit: Basic Services Kit-->
<!--Subsystem: Base-->
<!--Owner: @majiajun518-->
<!--Designer: @majiajun518-->
<!--Tester: @jiyong_sd-->
<!--Adviser: @fang-jinxu-->

本模块定义了OpenHarmony ArkTS API的注解类型，如生命周期最小可用版本、API告警屏蔽等，用于帮助开发者标识和管理API的兼容性、告警抑制等特性。该模块解决了开发者在跨版本开发、第三方SDK集成等场景中遇到的版本兼容性告警、权限告警、多设备适配告警等问题，通过注解方式抑制不必要的告警干扰，提高代码的可维护性和开发效率。

> **说明：**
>
> - 本模块首批接口从 API version 22 开始支持。后续版本的新增接口，采用上角标单独标记起始版本。

## 导入模块

```typescript
import { Available, SuppressWarnings, SuppressWarningsType } from '@kit.BasicServicesKit';
```

## Available

@interface Available { minApiVersion: string = '' }

提供API注解能力，用于标记API支持的最低可用版本。此注解可以标注在类、接口、函数、变量、类型、模块、枚举上。在源码定义处添加注解后，编译工具会在使用处检查潜在的兼容性问题。当minApiVersion大于build-profile.json5中指定的compatibleSdkVersion字段，会生成兼容性警告。

**卡片能力：** 从API version 22开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Base

<!--RP1-->
| 名称 | 类型 | 只读 | 可选 | 说明                       |
| ---- | ---- | ---- | --- | -------------------------- |
| minApiVersion | string | 否 | 否 | minApiVersion用于标识最低可用版本，由两部分组成：系统类型+版本号。仅当系统类型为OpenHarmony时可省略系统类型。例如：'OpenHarmony 20'，'20'。当minApiVersion大于build-profile.json5中指定的compatibleSDKVersion字段时，会生成兼容性警告。 |

**示例：**

  ```typescript
  import { Available, deviceInfo } from '@kit.BasicServicesKit';

  @Available({minApiVersion: 'OpenHarmony 22'}) // 标记函数最低可用版本
  function myFunc() {}

  @Available({minApiVersion: '22'}) // 标记类最低可用版本，系统类型默认值为 OpenHarmony
  class MyClass {}

  // 不建议写法：如果工程根目录下build-profile.json5文件设置的compatibleSdkVersion值小于 22，直接调用myFunc方法且没有做版本判断处理，编译器会在myFunc方法调用处抛出告警，提示该方法可能在低版本设备上运行失败
  myFunc();

  // 建议写法1：使用deviceInfo.sdkApiVersion获取系统软件API版本进行判断，可以避免低版本设备运行异常，消除编译告警
  if (deviceInfo.sdkApiVersion >= 22) {
    myFunc();
  } else {
    // 根据业务逻辑选择低版本可用方法
  }

  // 建议写法2：在myFunc调用处的父级函数（或类）上，标记@Available起始版本信息，当新标记的版本号不低于 myFunc的最低可用版本, 消除编译告警
  @Available({minApiVersion: 'OpenHarmony 22'})
  function myNewFunc() {
    myFunc();
  }
  ```
<!--RP1End-->

## SuppressWarnings<sup>23+</sup>

@interface SuppressWarnings {

  rules: Array\<SuppressWarningsType>;

}  

系统提供的API告警屏蔽功能，允许开发者通过注解的方式抑制API调用时产生的告警。该功能可应用于类、函数、变量、类型、接口等API元素上。在源码中添加相应标注后，编译器会根据预设规则自动屏蔽对应的告警信息。适用于需要在特定场景下暂时忽略某些告警、避免编译器产生干扰性警告的情况，帮助开发者专注于关键问题，提高开发效率。

**卡片能力：** 从API version 23开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 23开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Base

| 名称 | 类型 | 只读 | 可选 | 说明                       |
| ---- | ---- | ---- | --- | -------------------------- |
| rules | Array<[SuppressWarningsType](#suppresswarningstype23)> | 否 | 否 | 支持告警消除的规则集合，用于指定需要抑制的告警类型。可通过数组传入多个规则同时抑制多种告警。可选取值参见[SuppressWarningsType](#suppresswarningstype23)。|

**注解使用示例：**

<!--RP2-->
兼容性告警消除预置条件：OpenHarmony工程根目录下，build-profile.json5文件设置的compatibleSdkVersion值为20。
<!--RP2End-->

权限告警消除预置条件：module.json5配置文件的requestPermissions标签中没有申请权限。

> **说明：**
>
> 用于容器节点时，会屏蔽节点下子节点产生的告警。
>
> 重复规则屏蔽时，仅生效代码位置上距离最近且符合规则的屏蔽类型。当多个不同类型的抑制实例同时存在时，各类型独立生效。

  ```typescript
  import { SuppressWarnings, SuppressWarningsType, systemDateTime } from '@kit.BasicServicesKit';
  import { photoAccessHelper } from '@kit.MediaLibraryKit';
  import { common } from '@kit.AbilityKit';
  // 兼容性告警消除部分
  systemDateTime.getAutoTimeStatus();  // 该接口起始版本为21，直接调用会生成兼容性告警。
  // The 'getAutoTimeStatus' API is supported since SDK version 21. However, the current compatible SDK version is 20.

  @SuppressWarnings({rules: [SuppressWarningsType.COMPATIBILITY]})
  function myFunc() {
    systemDateTime.getAutoTimeStatus(); // 使用@SuppressWarnings注解后，兼容性告警被抑制。用于myFunc()容器节点时，子节点的兼容性告警也被抑制。
  }

  @SuppressWarnings({rules: [SuppressWarningsType.COMPATIBILITY]})
  class MyClass {
    status = systemDateTime.getAutoTimeStatus(); // 使用@SuppressWarnings注解后，兼容性告警被抑制。
  }


  // 权限告警消除部分
  async function savePhotoToGallery(context: common.UIAbilityContext) {
    let helper = photoAccessHelper.getPhotoAccessHelper(context);
    let uri = await helper.createAsset(photoAccessHelper.PhotoType.IMAGE, 'jpg');
    // To use this API, you need to apply for the permissions: ohos.permission.WRITE_IMAGEVIDEO
  }

  @SuppressWarnings({rules: [SuppressWarningsType.PERMISSION]})
  async function savePhotoToGallerySuppressCompatibility(context: common.UIAbilityContext) {
    let helper = photoAccessHelper.getPhotoAccessHelper(context);
    @SuppressWarnings({rules: [SuppressWarningsType.COMPATIBILITY]}) // 如果同时存在两种屏蔽内容，仅生效最近的抑制类型。（兼容性告警被抑制，权限告警仍然存在）
    let uri = await helper.createAsset(photoAccessHelper.PhotoType.IMAGE, 'jpg'); // 使用@SuppressWarnings注解后，兼容性告警被抑制，权限告警仍然存在。
  }

  @SuppressWarnings({rules: [SuppressWarningsType.PERMISSION]})
  async function savePhotoToGallerySuppress(context: common.UIAbilityContext) {
    let helper = photoAccessHelper.getPhotoAccessHelper(context);
    let uri = await helper.createAsset(photoAccessHelper.PhotoType.IMAGE, 'jpg'); // 使用@SuppressWarnings注解后，权限告警被抑制。
  }
  ```

// @SuppressWarnings \<SuppressWarningsType>

本功能支持以单行注释形式快速抑制告警。在触发告警的代码行上方添加注释后，编译器将根据规则自动屏蔽对应的告警信息。注释中的标识符与SuppressWarningsType枚举值对应（如compatibility对应COMPATIBILITY），仅对紧随其后的代码行生效。

> **说明：**
>
> 仅支持单行注释(//)格式，示例：// @SuppressWarnings compatibility
>
> 不支持多行注释(/\*\*/)格式，示例：/\* @SuppressWarnings compatibility */
>
> 不支持屏蔽容器节点下的子节点

**注释使用示例：**

<!--RP3-->
兼容性告警消除预置条件：OpenHarmony工程根目录下，build-profile.json5文件设置的compatibleSdkVersion值为20。
<!--RP3End-->

权限告警消除预置条件：module.json5配置文件的requestPermissions标签中没有申请权限。

  ```typescript
  import { systemDateTime } from '@kit.BasicServicesKit';
  import { photoAccessHelper } from '@kit.MediaLibraryKit';
  import { common } from '@kit.AbilityKit';
  // 兼容性告警消除部分
  systemDateTime.getAutoTimeStatus();  // 该接口起始版本为21，直接调用会生成兼容性告警。
  // The 'getAutoTimeStatus' API is supported since SDK version 21. However, the current compatible SDK version is 20.

  // @SuppressWarnings compatibility
  systemDateTime.getAutoTimeStatus();  // 使用@SuppressWarnings注释后，兼容性告警被抑制。


  // 权限告警消除部分
  async function savePhotoToGallery(context: common.UIAbilityContext) {
    let helper = photoAccessHelper.getPhotoAccessHelper(context);
    let uri = await helper.createAsset(photoAccessHelper.PhotoType.IMAGE, 'jpg');
    // To use this API, you need to apply for the permissions: ohos.permission.WRITE_IMAGEVIDEO
  }
  // @SuppressWarnings permission
  async function savePhotoToGallerySuppressNoUse(context: common.UIAbilityContext) {
    let helper = photoAccessHelper.getPhotoAccessHelper(context);
    let uri = await helper.createAsset(photoAccessHelper.PhotoType.IMAGE, 'jpg'); // 使用注释后，容器内子节点的告警不支持消除，仍会产生告警
    // To use this API, you need to apply for the permissions: ohos.permission.WRITE_IMAGEVIDEO
  }

  async function savePhotoToGallerySuppress(context: common.UIAbilityContext) {
    let helper = photoAccessHelper.getPhotoAccessHelper(context);
    // @SuppressWarnings permission
    let uri = await helper.createAsset(photoAccessHelper.PhotoType.IMAGE, 'jpg'); // 使用@SuppressWarnings注释后，权限告警被抑制。
  }
  ```

## SuppressWarningsType<sup>23+</sup>

支持消除告警的规则。帮助开发者根据实际需求选择性地屏蔽兼容性告警、多设备告警、权限告警等，在确保代码质量的同时减少不必要的告警干扰，提升开发体验。

**卡片能力：** 从API version 23开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 23开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**起始版本：** 23

**系统能力：** SystemCapability.Base

| 名称                   | 值   | 说明                           |
| ---------------------- | ---- | ------------------------------ |
| COMPATIBILITY     | compatibility    | 支持消除兼容性告警。当调用API的起始版本高于工程设置的兼容SDK版本时产生的告警。建议在已做版本判断或兼容性处理时使用，避免盲目抑制告警导致低版本设备运行异常。 |
| SYSCAP     | syscap    | 支持消除多设备告警。当调用API的系统能力在目标设备上不支持时产生的告警。 |
| PERMISSION     | permission    | 支持消除权限告警。当调用需要权限的API但未在配置文件中声明相应权限时产生的告警。<br>**起始版本：** 26.0.0 |
