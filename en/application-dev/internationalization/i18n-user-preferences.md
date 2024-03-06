# User Preference Setting

## Use Cases

In addition to system locales and application preferred languages, the system supports setting of user preferences. Currently, the system supports two user preferences: whether to use local digits and whether to use the 12/24-hour format. User preference settings are saved to system locales and application preferred languages as part of the internationalization feature.

## How to Develop

User preference setting is implemented by using [setUsingLocalDigit](../reference/apis/js-apis-i18n.md#setusinglocaldigit9) and [set24HourClock](../reference/apis/js-apis-i18n.md#set24hourclock9). The development procedure is as follows:


1. Import the **intl** module.
   ```ts
   import Intl from '@ohos.intl';
   import I18n from '@ohos.i18n';
   import { BusinessError } from '@ohos.base';
   ```

2. Obtain the preferred language of an application.
   ```ts
   try {
     // Obtain the preferred language of the application. Assume that the current preferred language is ar.
     let appPreferredLanguage: string = I18n.System.getAppPreferredLanguage();
   } catch(error) {
     let err: BusinessError = error as BusinessError;
     console.error(`call System.getAppPreferredLanguage failed, error code: ${err.code}, message: ${err.message}.`);
   }
   ```

3. Enable display of local digits on the application page.
   ```ts
   try {  
     I18n.System.setUsingLocalDigit(true); // Enable the local digit switch.
   } catch(error) {
     let err: BusinessError = error as BusinessError;
     console.error(`call System.setUsingLocalDigit failed, error code: ${err.code}, message: ${err.message}.`);
   }
   let date = new Date(2023, 9, 25);
   let dateTimeFmt = new Intl.DateTimeFormat(appPreferredLanguage);
   let result = dateTimeFmt.format(date); // result = "٢٠٢٣/١٠/٢٥" (local Arabic digits)
   ```

4. Set the 24-hour clock format.
   ```ts
   try {  
     I18n.System.set24HourClock(true); // true means to enable the 24-hour clock, and false means to enable the 12-hour clock.
   } catch(error) {
     let err: BusinessError = error as BusinessError;
     console.error(`call System.set24HourClock failed, error code: ${err.code}, message: ${err.message}.`);
   }
   let date = new Date(2023, 9, 25, 16, 48, 0);
   let dateTimeFmt = new Intl.DateTimeFormat(appPreferredLanguage, { timeStyle: "medium" });
   let result = dateTimeFmt.format(date); // result = "16:48:00"
   ```
