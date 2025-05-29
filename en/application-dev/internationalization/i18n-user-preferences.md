# Setting User Preferences (For System Applications Only)

## Use Cases

In addition to system locales and application preferred languages, the system supports setting of user preferences. Currently, the system supports two user preferences: whether to use local digits and whether to use the 12/24-hour format. User preference settings are saved to system locales and application preferred languages as part of the internationalization feature.

## How to Develop

For details about how to use the APIs, see [setUsingLocalDigit](../reference/apis-localization-kit/js-apis-i18n-sys.md#setusinglocaldigit9) and [set24HourClock](../reference/apis-localization-kit/js-apis-i18n-sys.md#set24hourclock9).


1. Import the **intl** module.
   ```ts
   import { i18n, intl } from '@kit.LocalizationKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

2. Obtain the preferred language of an application.
   ```ts
   // Obtain the preferred language of an application.
   let appPreferredLanguage: string = i18n.System.getAppPreferredLanguage();
   ```

3. Enable display of local digits on the application page.
   ```ts
   try {
     i18n.System.setUsingLocalDigit(true); // Enable use of local digits.
   } catch (error) {
     let err: BusinessError = error as BusinessError;
     console.error(`call System.setUsingLocalDigit failed, error code: ${err.code}, message: ${err.message}.`);
   }
   let date: Date = new Date(2023, 9, 25); // The date is 2023-10-25.
   let appPreferredLanguage: string = 'ar';
   let dateTimeFmt: intl.DateTimeFormat = new intl.DateTimeFormat(appPreferredLanguage);
   let formattedTime: string = dateTimeFmt.format(date); // formattedTime = '٢٠٢٣/١٠/٢٥' (represented by localized numbers in Arabic)
   ```

4. Set the 24-hour clock format.
   ```ts
   try {
     i18n.System.set24HourClock (true); // Set the system time to the 24-hour clock.
   } catch (error) {
     let err: BusinessError = error as BusinessError;
     console.error(`call System.set24HourClock failed, error code: ${err.code}, message: ${err.message}.`);
   }
   let date: Date = new Date(2023, 9, 25, 16, 48, 0); // The date and time is 2023-10-25 16:48:00.
   let appPreferredLanguage: string = 'zh';
   let dateTimeFmt: intl.DateTimeFormat = new intl.DateTimeFormat(appPreferredLanguage, { timeStyle: 'medium' });
   let formattedTime: string = dateTimeFmt.format(date); // formattedTime = '16:48:00'
   ```
