# Locale and Cultural Habit Division


## Use Cases

In a broad sense, a locale uniquely identifies a specific geographical region by using digits, letters, symbols, or their combinations.

Regarding internationalization, a locale is an abstraction of a user group, including the user language, script (for example, simplified Chinese or traditional Chinese), country/region, and other cultural habits (for example, calendar and numeral system). Locales are the basis for an application to implement internationalization capabilities.


## How It Works

A locale consists of four parts: language, script, country/region, and extended parameters. The language is mandatory. For details, see Table 1. For supported extended parameters, see Table 2. For numeral systems corresponding to different languages, see Table 3. The Arabic numeral system is used for languages that are not listed in the table by default. 

**Table 1** Description of the locale

| Part| Description| 
| -------- | -------- |
| Language| Language used by the user. The value consists of two or three lowercase letters. For example, **zh** indicates Chinese.<br>For more language codes, see the ISO-639 standard.| 
| Script| Character set used by the user. The value consists of four letters with the first letter being capitalized. For example, **Hans** indicates simplified Chinese.<br>For more script codes, see the ISO-15924 standard.| 
| Country/region| Country/region where the user is located. The value consists of two uppercase letters. For example, **CN** indicates China.<br>For more country/region codes, see the ISO-3166 standard.| 
| Extensions| Extended parameters that indicate other features of the user, including the calendar, string collation, numeral system, and hour cycle. The value starts with a lowercase letter **u**. Each extended parameter consists of a key and a value, which are separated using a hyphen (-). For example, **u-ca-chinese-co-pinyin** means collation by lunar calendar and pinyin.<br>For supported extended parameters, see Table 2. For more extended parameters, see BCP 47 Extensions.| 

**Table 2** Supported extended parameters

| Parameter| Description| 
| -------- | -------- |
| ca | Calendar system used by the user. For example, **chinese** indicates the lunar calendar.| 
| co | String collation rule used by the user. For example, **pinyin** means collation by Pinyin.| 
| hc | Hour cycle used by the user. For example, **h11** indicates the hour cycle from 0 to 11.| 
| nu | Numeral system used by the user. For example, **arab** indicates the Arabic numeral system. For details, see Table 3.| 
| kn | Processing specific to digits during collation.<br>- **true**: Digits are treated as a whole.<br>- **false**: Digits are treated as common characters.| 
| kf | Processing specific to case capitalization during collation.<br>- **upper**: Uppercase letters are placed in the front.<br>- **lower**: Lowercase letters are placed in the front.<br>- **false**: The default value of the current locale is used.| 

**Table 3** Languages and numeral systems

| Language| Numeral System| 
| -------- | -------- |
| ar | arab | 
| as | beng | 
| bn | beng | 
| fa | arabext | 
| mr | deva | 
| my | mymr | 
| ne | deva | 
| ur | latn | 
| Others| arab | 


## How to Develop

The following uses date and time formatting as an example. For details about APIs, see [getPluralStringValueSync](../reference/apis-localization-kit/js-apis-resource-manager.md#getpluralstringvaluesync10).

1. Import the **intl** module.
   ```ts
   import { intl } from '@kit.LocalizationKit';
   ```

2. Create a **Locale** object. Three methods are provided:
   - According to the format provided in [How It Works](#how-it-works), pass in the locale string to the **Locale** constructor to create a **Locale** object.
   - Configure locale features in **LocaleOptions**, and then use the locale string and **LocaleOptions** to create a **Locale** object. The attributes configured in **LocaleOptions** automatically overwrite the corresponding attributes in the locale string.
   - Use the default **Locale** constructor to create a **Locale** object. This object will be used to represent the current system locale.

   ```ts
   let date = new Date(2023, 9, 15);
   
   // Method 1: Create a Locale object using the locale string.
   let zhLocale = new intl.Locale("zh-Hans-CN-u-nu-latn");
   
   // Method 2: Create a Locale object using the locale string and LocaleOptions.
   let enLocale = new intl.Locale("en", {numberingSystem: "latn"});
   
   // Method 3: Create a Locale object using the default Locale constructor.
   let systemLocale = new intl.Locale();
   ```

3. Format the date and time.
   Pass the **Locale** object to the **DateTimeFormat** constructor to create a **DateTimeFormat** class to implement date and time formatting for the locale. Similarly, three methods are provided.

   ```ts
   // Method 1
   let zhDateTimeFmt = new intl.DateTimeFormat(zhLocale.toString());
   let result = zhDateTimeFmt.format(date); // result = "2023/10/15"
   
   // Method 2
   let enDateTimeFmt = new intl.DateTimeFormat(enLocale.toString());
   result = enDateTimeFmt.format(date); // result = "10/15/23"
   
   // Method 3
   let systemDateTimeFmt = new intl.DateTimeFormat(systemLocale.toString());
   result = systemDateTimeFmt.format(date); // result = "2023/10/15" (The display effect depends on the current system environment.)
   ```
