# 设置系统语言与区域


## 实现原理

在设置的“语言和系统”中可以添加多种语言，多种语言形成的列表称为语言列表，列表中的第一个语言称为系统语言。系统区域是依据区域标识划分的特定地区。

当设置/切换系统语言时，系统会检查[扩展参数](i18n-locale-culture.md)与系统语言是否匹配，若不匹配，则删除扩展属性。例如，当前系统语言设置为阿拉伯语“ar”，使用本地数字为“arab”。当系统语言切换为马来西亚语“my”时，本地数字属性更改为马来西亚的本地数字“mymr”。当切换为中文时，因中文不支持设置本地数字，采用阿拉伯数字，因此本地数字的扩展属性会被移除。


## 开发步骤

接口具体使用方法和说明请参考[System](../reference/apis/js-apis-i18n.md#system9)的API接口文档。

1. 导入模块。
   ```ts
   import I18n from '@ohos.i18n';
   import { BusinessError } from '@ohos.base';
   ```

2. 获取系统语言、系统地区、系统区域。
   ```ts
   // 获取系统语言
   try {
     let systemLanguage = I18n.System.getSystemLanguage();  // systemLanguage为当前系统语言
   } catch(error) {
     console.error(`call System.getSystemLanguage failed, error code: ${error.code}, message: ${error.message}.`);
   }
   
   // 获取系统地区
   try {
     let systemRegion = I18n.System.getSystemRegion();  // systemRegion为当前系统地区
   } catch(error) {
     console.error(`call System.getSystemRegion failed, error code: ${error.code}, message: ${error.message}.`);
   }
   
   // 获取系统区域
   try {
     let systemLocale = I18n.System.getSystemLocale();  // systemLocale为当前系统区域
   } catch(error) {
     console.error(`call System.getSystemLocale failed, error code: ${error.code}, message: ${error.message}.`);
   }
   ```

3. 设置系统语言、系统地区、系统区域。
   ```ts
   // 设置系统当前语言为 "zh"
   try {
     I18n.System.setSystemLanguage('zh'); 
   } catch(error) {
     let err: BusinessError = error as BusinessError;
     console.error(`call System.setSystemLanguage failed, error code: ${err.code}, message: ${err.message}.`);
   }
   
   // 设置系统当前地区为 "CN"
   try {
     I18n.System.setSystemRegion('CN'); 
   } catch(error) {
     let err: BusinessError = error as BusinessError;
     console.error(`call System.setSystemRegion failed, error code: ${err.code}, message: ${err.message}.`);
   }
   
   // 设置系统当前区域为 "zh-Hans-CN"
   try {
     I18n.System.setSystemLocale('zh-Hans-CN'); 
   } catch(error) {
     let err: BusinessError = error as BusinessError;
     console.error(`call System.setSystemLocale failed, error code: ${err.code}, message: ${err.message}.`);
   }
   ```
