# Globalization Subsystem ChangeLog

## cl.global.1 Runtime Authentication Added for System APIs

The internationalization component of the globalization subsystem adds runtime authentication for system APIs in certain scenarios. The following changes are made in API version 9 and later:
 - Setting the system language, country or region, and area
 - Setting the 24-hour format of the system
 - Adding and removing the preferred language
 - Setting localized numbers

You need to adapt your application based on the following information.

**Change Impacts**

APIs involved in the preceding scenarios can be properly called only by system applications that have the **UPDATE_CONFIGURATION** permission.

**Key API/Component Changes**

 - Involved APIs:
   - setSystemLanguage(language: string): void;
   - setSystemRegion(region: string): void;
   - setSystemLocale(locale: string): void;
   - set24HourClock(option: boolean): void;
   - addPreferredLanguage(language: string, index?: number): void;
   - removePreferredLanguage(index: number): void;
   - setUsingLocalDigit(flag: boolean): void;

**Adaptation Guide**

Make sure the application trying to call any of the above APIs is a system application. Non-system applications are not allowed to call the APIs.
An exception will be thrown upon lack of a necessary permission or a call request from a non-system application. The exception can be captured via **try-catch**.

```js
import I18n from '@ohos.i18n'

try {
  I18n.System.setSystemLanguage('zh');
} catch(error) {
  console.error(`call System.setSystemLanguage failed, error code: ${error.code}, message: ${error.message}.`)
}
```
