# Globalization Subsystem ChangeLog

## cl.global.1 Support of Error Codes for the Internalization Module

APIs provided by the internationalization component of the globalization subsystem are changed to support error codes in the following scenarios. The following changes are made in API version 9 and later:
 - Obtaining the local expression of a country or language
 - Obtaining the list of languages supported by the system and the list of areas supported by a language
 - Checking whether a language matches an area
 - Obtaining and setting the system language, country or region, and area
 - Obtaining and setting the 24-hour format of the system
 - Obtaining, adding, and removing the preferred language
 - Obtaining and setting localized numbers

You need to adapt your applications based on the following information:

**Change Impacts**

The preceding APIs are changed to the static methods of the **System** class. When such an API is called, add the class name to the end of the module name.
The return value data type of the setting APIs (for example, **setSystemLanguage**) is changed from boolean to void.
When a call to an API fails, an error code is returned according to the failure cause. For example, when permissions are not correctly configured for an application, **201** is returned.

**Key API/Component Changes**

Involved APIs:
- getDisplayCountry(country: string, locale: string, sentenceCase?: boolean): string;
- getDisplayLanguage(language: string, locale: string, sentenceCase?: boolean): string;
- getSystemLanguages(): Array<string>;
- getSystemCountries(language: string): Array<string>;
- isSuggested(language: string, region?: string): boolean;
- getSystemLanguage(): string;
- setSystemLanguage(language: string): void;
- getSystemRegion(): string;
- setSystemRegion(region: string): void;
- getSystemLocale(): string;
- setSystemLocale(locale: string): void;
- is24HourClock(): boolean;
- set24HourClock(option: boolean): void;
- addPreferredLanguage(language: string, index?: number): void;
- removePreferredLanguage(index: number): void;
- getPreferredLanguageList(): Array<string>;
- getFirstPreferredLanguage(): string;
- getAppPreferredLanguage(): string;
- setUsingLocalDigit(flag: boolean): void;
- getUsingLocalDigit(): boolean;

**Adaptation Guide**

Use the **try-catch** block to capture errors returned by an API.
```
import I18n from '@ohos.i18n'

try {
  I18n.System.setSystemLanguage('zh');
} catch(error) {
  console.error(`call System.setSystemLanguage failed, error code: ${error.code}, message: ${error.message}.`)
}
```
