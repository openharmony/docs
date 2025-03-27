# 本地化语言与地区名称


## 使用场景

本地化语言与地区名称是指界面的语言列表和地区列表按照本地的语言习惯显示，确保用户可识别，主要在展示语言与地区名称的场景下使用。例如，在简体中文环境下，简体中文用“简体中文”表示，英文用“英文”表示；在英文环境下，简体中文用“Simplified Chinese”表示，英文用“English”表示。


## 开发步骤

接口具体说明请参考[getDisplayCountry](../reference/apis-localization-kit/js-apis-i18n.md#getdisplaycountry9)和[getDisplayLanguage](../reference/apis-localization-kit/js-apis-i18n.md#getdisplaylanguage9)的API文档。

1. 导入模块。
   ```ts
   import { i18n } from '@kit.LocalizationKit';
   ```

2. 本地化语言名称。
   在给用户提供语言名称的场景中，例如切换系统语言时，系统展示用户可读的本地化语言名称，以中文形式显示德语为例。
   ```ts
   let displayLanguage: string = i18n.System.getDisplayLanguage('de', 'zh-Hans-CN'); // displayLanguage = '德文'
   // language: 语言两字母代码，如'zh'，'de'，'fr'等
   // locale: 本地化标识符，如'en-GB'、'en-US'、'zh-Hans-CN'等
   // sentenceCase: 返回的语言名称是否需要首字母大写，默认值：true
   ```

3. 本地化国家/地区名称。
   在给用户提供国家/地区名称时，getDisplayCountry()返回本地化的国家/地区名称。
   ```ts
   let displayCountry: string = i18n.System.getDisplayCountry('SA', 'en-GB'); // displayCountry = 'Saudi Arabia'
   // country: 国家/地区两字母代码，如'CN'、'DE'、'SA'等
   // locale: 本地化标识符，如'en-GB'、'en-US'、'zh-Hans-CN'等
   // sentenceCase: 返回的国家/地区名称是否需要首字母大写，默认值：true
   ```
