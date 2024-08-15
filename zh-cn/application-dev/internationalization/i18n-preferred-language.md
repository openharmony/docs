# 设置应用偏好语言

## 功能介绍

对于多语言用户，很多情况下会将系统语言设置为一种语言（如中文），将特定APP应用的语言设置为另一种语言（如英语）。当界面加载应用资源时，依据应用设置的语言进行显示。开发过程中，开发者需将应用国际化特性区域设置为应用偏好语言，使应用界面的国际化特性与界面加载的资源保持一致。当前，应用仅支持设置一种语言。

## 开发步骤

接口具体使用方法和说明请参考[getAppPreferredLanguage](../reference/apis-localization-kit/js-apis-i18n.md#getapppreferredlanguage9)的API接口文档。

以时间日期格式化为例说明。

1. 导入模块。
   ```ts
   import { i18n } from '@kit.LocalizationKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

2. 需要获取应用的偏好语言。
   ```ts
     let appPreferredLanguage: string = i18n.System.getAppPreferredLanguage(); // 获取应用偏好语言
   ```
   
3. 设置应用的偏好语言。将应用偏好语言设置为目标语言后，该应用的界面会切换为目标语言。设置应用的偏好语言仅影响应用本身，不会影响系统语言设置。
   ```ts
    try {  
      i18n.System.setAppPreferredLanguage("zh-Hans"); // 设置应用偏好语言为zh-Hans
    } catch(error) {
      let err: BusinessError = error as BusinessError;
      console.error(`call System.setAppPreferredLanguage failed, error code: ${err.code}, message: ${err.message}.`);
    }
   ```