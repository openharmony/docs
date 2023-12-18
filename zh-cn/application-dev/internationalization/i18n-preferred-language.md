# 设置应用偏好语言

## 功能介绍

对于多语言用户，很多情况下会将系统语言设置为一种语言（如中文），将特定APP应用的语言设置为另一种语言（如英语）。当界面加载应用资源时，依据应用设置的语言进行显示。开发过程中，开发者需将应用国际化特性区域设置为应用偏好语言，使应用界面的国际化特性与界面加载的资源保持一致。当前，应用仅支持设置一种语言。

## 开发步骤

接口具体使用方法和说明请参考[getAppPreferredLanguage](../reference/apis/js-apis-i18n.md#getapppreferredlanguage9)的API接口文档。

以时间日期格式化为例说明。

1. 导入模块。
   ```ts
   import Intl from '@ohos.intl';
   import I18n from '@ohos.i18n';
   import { BusinessError } from '@ohos.base';
   ```

2. 需要获取应用的偏好语言。
   ```ts
   try {  
     let appPreferredLanguage: string = I18n.System.getAppPreferredLanguage(); // 获取应用偏好语言
   } catch(error) {
     let err: BusinessError = error as BusinessError;
     console.error(`call System.getAppPreferredLanguage failed, error code: ${err.code}, message: ${err.message}.`);
   }
   ```
   
3. 基于应用偏好语言，创建时间日期格式化对象，将时间日期格式化为与一致的格式。
   ```ts
   let date: Date = new Date(2023, 9, 25);
   let dateTimeFmt: Intl.DateTimeFormat = new Intl.DateTimeFormat(appPreferredLanguage);
   let result = dateTimeFmt.format(date); // result = "2023/10/23"(具体显示效果与系统环境相关)
   ```