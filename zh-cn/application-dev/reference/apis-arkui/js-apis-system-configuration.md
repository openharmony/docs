# @system.configuration (应用配置)

> **说明：**
> - 从API Version 7 开始，该接口不再维护，推荐使用新接口[`@ohos.i18n`](../apis-localization-kit/js-apis-i18n.md)和[`@ohos.intl`](../apis-localization-kit/js-apis-intl.md)。
>
> 
> - 本模块首批接口从API version 3开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块


```ts
import Configuration from '@system.configuration';
```


## configuration.getLocale

static getLocale(): LocaleResponse

获取应用当前的语言和地区。默认与系统的语言和地区同步。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Lite

**返回值：**
| 类型            | 说明            |
| -------------- | ------------- |
| LocaleResponse | 应用当前Locale相关信息。 |

**示例：**
  ```
  export default {    
    getLocale() {        
      const localeInfo = configuration.getLocale();        
      console.info(localeInfo.language);    
    }
  }
  ```


## LocaleResponse

表示应用当前Locale的属性。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：以下各项对应的系统能力均为SystemCapability.ArkUI.ArkUI.Lite

| 名称   | 类型   | 可读   | 可写   | 说明                                       |
| ---- | ------ | ---- | ---- | ---------------------------------------- |
| language | string | 是    | 否    | 语言。例如：zh。 |
| countryOrRegion | string | 是    | 否    | 国家或地区。例如：CN。 |
| dir | string | 是    | 否    | 文字布局方向。取值范围：<br/>-&nbsp;ltr：从左到右；<br/>-&nbsp;rtl：从右到左。 |