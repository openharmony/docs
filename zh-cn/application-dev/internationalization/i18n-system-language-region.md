# 设置系统语言与区域

<!--Kit: Localization Kit-->
<!--Subsystem: Global-->
<!--Owner: @yliupy-->
<!--Designer: @sunyaozu-->
<!--Tester: @lpw_work-->
<!--Adviser: @Brilliantry_Rui-->

## 实现原理

在设置的“语言和地区”中可以添加多种语言，多种语言形成的列表称为语言列表，列表中的第一个语言称为系统语言。系统区域是依据区域ID划分的特定地区。

设置/切换系统语言时，系统会检查[扩展参数](i18n-locale-culture.md)与系统语言是否匹配，若不匹配，则删除扩展参数。例如，当前系统语言设置为阿拉伯语“ar”时，使用本地数字为“arab”。当系统语言切换为马来西亚语“my”时，本地数字参数更改为马来西亚的本地数字“mymr”。当切换为中文时，因中文不支持设置本地数字，采用阿拉伯数字，因此本地数字的扩展参数会被移除。


## 开发步骤

接口具体使用方法和说明请参考[System](../reference/apis-localization-kit/js-apis-i18n.md#system9)的API接口文档。

1. 导入模块。
   ```ts
   import { i18n } from '@kit.LocalizationKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

2. 获取系统语言、系统地区、系统区域。
   ```ts
   // 获取系统语言
   let systemLanguage: string = i18n.System.getSystemLanguage();  // systemLanguage为当前系统语言

   // 获取系统地区
   let systemRegion: string = i18n.System.getSystemRegion();  // systemRegion为当前系统地区

   // 获取系统区域
   let systemLocale: Intl.Locale = i18n.System.getSystemLocaleInstance();  // systemLocale为当前系统区域
   ```
<!--Del-->
3. 设置系统语言、系统地区。
   ```ts
   // 设置系统当前语言为'zh-Hans'
   try {
     i18n.System.setSystemLanguage('zh-Hans');
   } catch (error) {
     let err: BusinessError = error as BusinessError;
     console.error(`call System.setSystemLanguage failed, error code: ${err.code}, message: ${err.message}.`);
   }

   // 设置系统当前地区为'CN'
   try {
     i18n.System.setSystemRegion('CN');
   } catch (error) {
     let err: BusinessError = error as BusinessError;
     console.error(`call System.setSystemRegion failed, error code: ${err.code}, message: ${err.message}.`);
   }
   ```
<!--DelEnd-->