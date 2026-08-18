# Preferred Language

<!--Kit: Localization Kit-->
<!--Subsystem: Global-->
<!--Owner: @yliupy-->
<!--Designer: @zw_feifei-->
<!--Tester: @lpw_work-->
<!--Adviser: @ningningW-->
<!-- md-trans-meta sourceCommit=1a7fdda7cb0bdacc6b1c367c8fd0def17530cd88 translatedAt=2026-08-15T01:53:31.793Z pushedAt=2026-08-15T08:42:14.077Z -->

## Use Cases

Multi-language users usually set the system language to one language (for example, Chinese) and the language of a specific application to another language (for example, English). When application resources are loaded on the UI, it is expected that the resources be displayed in the language set for the application. To address this issue, you can set a preferred language in locale settings so that resources are loaded in the preferred language when the application is launched. Currently, only one preferred language can be set for an application.

## How to Develop

For details about the API usage and description, see the API documentation of [getAppPreferredLanguage](../reference/apis-localization-kit/js-apis-i18n.md#getapppreferredlanguage9). The sample code is as follows:

1. Import the required module.

   <!-- @[import_module](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/International/Internationalization/entry/src/main/ets/i18napplication/LanguagePreferenceSetting.ets) -->

   ``` TypeScript
   import { i18n } from '@kit.LocalizationKit';
   import { BusinessError, commonEventManager } from '@kit.BasicServicesKit';
   ```

2. Usage scenarios.

- Obtain the preferred language of the app.

   <!-- @[get_preferred_language](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/International/Internationalization/entry/src/main/ets/i18napplication/LanguagePreferenceSetting.ets) -->

   ``` TypeScript
   let appPreferredLanguage = i18n.System.getAppPreferredLanguage(); // Obtain the app preferred language.
   ```

- Set the preferred language of the app. After the preferred language of the app is set to the target language, the app UI switches to the target language. This affects only the app itself, not the system language settings.

   <!-- @[set_preferred_language](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/International/Internationalization/entry/src/main/ets/i18napplication/LanguagePreferenceSetting.ets) -->

   ``` TypeScript
   try {
     i18n.System.setAppPreferredLanguage('zh-Hans'); // Set the preferred language of the application to zh-Hans.
   } catch (error) {
     let err: BusinessError = error as BusinessError;
     console.error(`call System.setAppPreferredLanguage failed, error code: ${err.code}, message: ${err.message}.`);
   }
   ```

- Clear the preferred language of the app. After the preferred language of the app is set to **default**, the app UI follows the system language. This feature takes effect after the app is restarted.

   <!-- @[clear_preferred_language](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/International/Internationalization/entry/src/main/ets/i18napplication/LanguagePreferenceSetting.ets) -->

   ``` TypeScript
   try {  
     i18n.System.setAppPreferredLanguage ('default'); // Clear the preferred language of the application.
   } catch (error) {
     let err: BusinessError = error as BusinessError;
     console.error(`call System.setAppPreferredLanguage failed, error code: ${err.code}, message: ${err.message}.`);
   }
   ```