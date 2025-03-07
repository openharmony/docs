# Preferred Language Setting

## Use Cases

In most cases, multi-language users may set the system language to one language (for example, Chinese) and the language of a specific application to another language (for example, English). When application resources are loaded on the UI, it is expected that the resources be displayed in the language set for the application. To address this issue, you can set a preferred language in locale settings so that resources are loaded in the preferred language when the application is launched. Currently, only one preferred language can be set for an application.

## How to Develop

For details about how to use related APIs, see [getAppPreferredLanguage](../reference/apis-localization-kit/js-apis-i18n.md#getapppreferredlanguage9).

The following uses date and time formatting as an example to illustrate how the preferred language works.

1. Import the **i18n** and **intl** modules.
   ```ts
   import { i18n } from '@kit.LocalizationKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

2. Obtain the preferred language of the application.
   ```ts
     let appPreferredLanguage: string = i18n.System.getAppPreferredLanguage(); // Obtain the preferred language of the application.
   ```
   
3. Set the preferred language of the application. After the preferred language of the application is set to the target language, the application UI is switched to the target language. The setting affects only the application, but not the system language settings.
   ```ts
    try {  
      i18n.System.setAppPreferredLanguage("zh-Hans"); // Set the preferred language of the application to zh-Hans.
    } catch(error) {
      let err: BusinessError = error as BusinessError;
      console.error(`call System.setAppPreferredLanguage failed, error code: ${err.code}, message: ${err.message}.`);
    }
   ```

4. Clear the preferred language of the application. If the preferred language is set to **default**, the application's language will be the same as the system language, and the setting will take effect upon application restarting.
   ```ts
    try {  
      i18n.System.setAppPreferredLanguage ("default"); // Clear the preferred language of the application.
    } catch(error) {
      let err: BusinessError = error as BusinessError;
      console.error(`call System.setAppPreferredLanguage failed, error code: ${err.code}, message: ${err.message}.`);
    }
   ```
