# System Language and Region Setting


## How It Works

You can add multiple languages in the **Language & region** area in **Settings**. The list formed by multiple languages is called a language list, and the first language in the list is called the system language. Locales are divided based on the locale ID.

When you set or switch the system language, the system checks whether the [extended parameter](i18n-locale-culture.md) matches the system language. If they do not match, the system deletes the extended parameter. For example, if the current system language is **ar** and the local numeral system is **arab**, the local numeral system will be changed to **mymr** once you switch the system language to **my**. If you switch the language to Chinese, the Arabic numeral system is used because local numerals are not supported. Meanwhile, the extended parameter associated with the numeral system is removed.


## How to Develop

For details about how to use related APIs, see [System](../reference/apis-localization-kit/js-apis-i18n.md#system9).

1. Import the **i18n** module.
   ```ts
   import { i18n } from '@kit.LocalizationKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

2. Obtain the system language, region, and locale.
   ```ts
   // Obtain the system language.
   let systemLanguage: string = i18n.System.getSystemLanguage();  // systemLanguage indicates the current system language.
 
   // Obtain the system region.
   let systemRegion: string = i18n.System.getSystemRegion();  // systemRegion indicates the current system region.
   
   // Obtain the system locale.
   let systemLocale: string = i18n.System.getSystemLocale();  // systemLocale is the current system locale.
   ```
<!--Del-->
3. Set the system language, region, and locale.
   ```ts
   // Set the current system language to zh-Hans.
   try {
     i18n.System.setSystemLanguage('zh-Hans');
   } catch (error) {
     let err: BusinessError = error as BusinessError;
     console.error(`call System.setSystemLanguage failed, error code: ${err.code}, message: ${err.message}.`);
   }

   // Set the current system region to CN.
   try {
     i18n.System.setSystemRegion('CN');
   } catch (error) {
     let err: BusinessError = error as BusinessError;
     console.error(`call System.setSystemRegion failed, error code: ${err.code}, message: ${err.message}.`);
   }

   // Set the current system locale to zh-Hans-CN.
   try {
     i18n.System.setSystemLocale('zh-Hans-CN');
   } catch (error) {
     let err: BusinessError = error as BusinessError;
     console.error(`call System.setSystemLocale failed, error code: ${err.code}, message: ${err.message}.`);
   }
   ```
<!--DelEnd-->
