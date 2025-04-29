# Language and Locale Name Localization


## Use Cases

Language and locale name localization means to localize language and locale names on the UI based on local language habits. For example, Simplified Chinese and English are used in an English environment while 简体中文 and 英文 are used in a Chinese environment.


## How to Develop

For details about the APIs, see [getDisplayCountry](../reference/apis-localization-kit/js-apis-i18n.md#getdisplaycountry9) and [getDisplayLanguage](../reference/apis-localization-kit/js-apis-i18n.md#getdisplaylanguage9).

1. Import the **i18n** module.
   ```ts
   import { i18n } from '@kit.LocalizationKit';
   ```

2. Localize language names.
   In scenarios where language names are provided for users, for example, switching of the system language, the system displays the localized language names to users. The following provides an example of displaying German in a way similar to Chinese.
   ```ts
   let displayLanguage: string = i18n.System.getDisplayLanguage('de', 'zh-Hans-CN'); // displayLanguage = 'German'
   // language: two-letter language code, for example, zh, de, or fr.
   // locale: localization identifier, for example, en-GB, en-US, or zh-Hans-CN.
   // sentenceCase: whether the first letter of the language name needs to be capitalized. The default value is true.
   ```

3. Localize country/region names.
   In scenarios where country/region names are provided for users, for example, switching of the system locale, the system displays the localized country/region names to users. The following uses Saudi Arabia as an example.
   ```ts
   let displayCountry: string = i18n.System.getDisplayCountry('SA', 'en-GB'); // displayCountry = 'Saudi Arabia'
   // country: two-letter country/region code, for example, CN, DE, or SA.
   // locale: localization identifier, for example, en-GB, en-US, or zh-Hans-CN.
   // sentenceCase: whether the first letter of the country/region name needs to be capitalized. The default value is true.
   ```
<!--no_check-->