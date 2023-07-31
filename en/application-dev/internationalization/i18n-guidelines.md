# i18n Development

The **i18n** module provides system-related or enhanced i18n capabilities, such as locale management, phone number formatting, and calendar, through supplementary i18n APIs that are not defined in ECMA 402. For more details about APIs and their usage, see [i18n](../reference/apis/js-apis-i18n.md).

The [intl](intl-guidelines.md) module provides basic i18n capabilities through the standard i18n interfaces defined in ECMA 402. It works with the **i18n** module to provide a complete suite of i18n capabilities.

## Obtaining and Setting i18n Information

The following table lists the APIs used to configure information such as the system language, preferred language, country or region, 24-hour clock, and use of local digits.

### Available APIs

| Class       | API                                    | Description                   |
| --------- | ---------------------------------------- | --------------------- |
| System | getDisplayCountry(country:string,locale:string,sentenceCase?:boolean):string<sup>9+</sup> | Obtains the localized representation of a country.          |
| System | getDisplayLanguage(language:string,locale:string,sentenceCase?:boolean):string<sup>9+</sup> | Obtains the localized representation of a language.          |
| System | getSystemLanguages():Array<string><sup>9+</sup>               | Obtains the system language list.              |
| System | getSystemCountries(language: string):Array<string><sup>9+</sup>               | Obtains the list of countries and regions supported for the specified language.              |
| System | isSuggested(language: string, region?: string): boolean<sup>9+</sup>               | Checks whether the system language matches the specified region.              |
| System | getSystemLanguage():string<sup>9+</sup>               | Obtains the system language.              |
| System | setSystemLanguage(language: string)<sup>9+</sup>               | Sets the system language.              |
| System | getSystemRegion():string<sup>9+</sup>                 | Obtains the system region.              |
| System | setSystemRegion(region: string)<sup>9+</sup>                 | Sets the system region.              |
| System | getSystemLocale():string<sup>9+</sup>                 | Obtains the system locale.          |
| System | setSystemLocale(locale: string)<sup>9+</sup>                 | Sets the system locale.          |
| System | is24HourClock():boolean<sup>9+</sup>     | Checks whether the 24-hour clock is used.   |
| System | set24HourClock():boolean<sup>9+</sup>     | Sets the 24-hour clock.   |
| System | addPreferredLanguage(language: string, index?: number)<sup>9+</sup>     | Adds a preferred language to the specified position on the preferred language list.   |
| System | removePreferredLanguage(index: number)<sup>9+</sup>     | Deletes a preferred language from the specified position on the preferred language list.   |
| System | getPreferredLanguageList()<sup>9+</sup>     | Obtains the preferred language list.   |
| System | getFirstPreferredLanguage()<sup>9+</sup>     | Obtains the first language in the preferred language list.   |
| System | getAppPreferredLanguage()<sup>9+</sup>     | Obtains the preferred language of an application.   |
| System | setUsingLocalDigit(flag: boolean)<sup>9+</sup>     | Specifies whether to enable use of local digits.   |
| System | getUsingLocalDigit()<sup>9+</sup>     | Checks whether use of local digits is enabled.   |
|  | isRTL(locale:string):boolean<sup>9+</sup> | Checks whether the locale uses a right-to-left (RTL) language.|

### How to Develop
1. Import the **i18n** module.

   ```js
   import I18n from '@ohos.i18n';
   ```

2. Obtain and set the system language.
   
   Call **setSystemLanguage** to set the system language. (This is a system API and can be called only by system applications with the **UPDATE_CONFIGURATION** permission.)
   Call the **getSystemLanguage** API to obtain the system language.
   
   ```js
   try {
      I18n.System.setSystemLanguage("en"); // Set the system language to en.
      let language = I18n.System.getSystemLanguage(); // language = "en"
   } catch(error) {
      console.error(`call i18n.System interface failed, error code: ${error.code}, message: ${error.message}`);
   }
   ```

3. Obtain and set the system locale.
   
   Call **setSystemRegion** to set the system country or region. (This is a system API and can be called only by system applications with the **UPDATE_CONFIGURATION** permission.)
   Call **getSystemRegion** to obtain the system country or region.

   ```js
   try {
      I18n.System.setSystemRegion("CN"); // Set the system country to CN.
      let region = I18n.System.getSystemRegion(); // region = "CN"
   } catch(error) {
      console.error(`call i18n.System interface failed, error code: ${error.code}, message: ${error.message}`);
   }
   ```

4. Obtain and set the system locale.

   Call **setSystemLocale** to set the system locale. (This is a system API and can be called only by system applications with the **UPDATE_CONFIGURATION** permission.) For details about how to set a locale, see [Setting Locale Information](../internationalization/intl-guidelines.md#setting-locale-information).
   Call **getSystemLocale** to obtain the system locale.

   ```js
   try {
      I18n.System.setSystemLocale("zh-Hans-CN"); // Set the system locale to zh-Hans-CN.
      let locale = I18n.System.getSystemLocale(); // locale = "zh-Hans-CN"
   } catch(error) {
      console.error(`call i18n.System interface failed, error code: ${error.code}, message: ${error.message}`);
   }
   ```

5. Check whether the locale uses a right-to-left (RTL) language.

   Call **isRTL** to check whether the locale uses an RTL language.

   ```js
   try {
      let rtl = I18n.isRTL("zh-CN"); // rtl = false
      rtl = I18n.isRTL("ar"); // rtl = true
   } catch(error) {
      console.error(`call i18n.System interface failed, error code: ${error.code}, message: ${error.message}`);
   }
   ```

6. Obtain and set the 24-hour clock.

   Call **set24HourClock** to enable the 24-hour clock.
   Call **is24HourClock** to check whether the 24-hour clock is enabled.

   ```js
   try {
      I18n.System.set24HourClock(true);
      let hourClock = I18n.System.is24HourClock(); // hourClock = true
   } catch(error) {
      console.error(`call i18n.System interface failed, error code: ${error.code}, message: ${error.message}`);
   }
   ```

7. Obtain the localized representation of a language.

   Call **getDisplayLanguage** to obtain the localized representation of a language. **language** indicates the language to be localized, **locale** indicates the locale, and **sentenceCase** indicates whether the first letter of the result must be capitalized.

   ```js
   try {
      let language = "en";
      let locale = "zh-CN";
      let sentenceCase = false;
      let localizedLanguage = I18n.System.getDisplayLanguage(language, locale, sentenceCase); // localizedLanguage = "English"
   } catch(error) {
      console.error(`call i18n.System interface failed, error code: ${error.code}, message: ${error.message}`);
   }
   ```

8. Obtain the localized representation of a country.

   Call **getDisplayCountry** to obtain the localized representation of a country. **country** indicates the country to be localized, **locale** indicates the locale, and **sentenceCase** indicates whether the first letter of the result must be capitalized.

   ```js
   try {
      let country = "US";
      let locale = "zh-CN";
      let sentenceCase = false;
      let localizedCountry = I18n.System.getDisplayCountry(country, locale, sentenceCase); // localizedCountry = "U.S."
   } catch(error) {
      console.error(`call i18n.System interface failed, error code: ${error.code}, message: ${error.message}`);
   }
   ```

9. Obtain the list of system languages and the list of countries supported by a system language.

   Call **getSystemLanguages** to obtain the list of system languages.
   Call **getSystemCountries** to obtain the list of countries and regions supported by a system language.
   ```js
   
   try {
      let languageList = I18n.System.getSystemLanguages();  // languageList = ["en-Latn-US", "zh-Hans"]
      let countryList = I18n.System.getSystemCountries("zh"); // countryList = ["ZW", "YT", ..., "CN", "DE"], 240 countries and regions in total
   } catch(error) {
      console.error(`call i18n.System interface failed, error code: ${error.code}, message: ${error.message}`);
   }
   ```

10. Check whether the language matches a country or region.

   Call **isSuggested** to check whether the language matches a country or region.
   
   ```js
   try {
      let isSuggest = I18n.System.isSuggested("zh", "CN"); // isSuggest = true
   } catch(error) {
      console.error(`call i18n.System interface failed, error code: ${error.code}, message: ${error.message}`);
   }
   ```

11. Obtain and set the preferred language.

   Call **addPreferredLanguage** to add a preferred language to the preferred language list.
   Call **removePreferredLanguage** to remove a preferred language from the preferred language list. (**addPreferredLanguage** and **removePreferredLanguage** are system APIs and can be called only by system applications with the **UPDATE_CONFIGURATION** permission.)
   Call **getPreferredLanguageList** to obtain the preferred language list.
   Call **getFirstPreferredLanguage** to obtain the first preferred language in the preferred language list.
   Call **getAppPreferredLanguageList** to obtain the preferred language of the application. It is the first language that matches the application resource in the preferred language list.
   
   ```js
   try {
      I18n.System.addPreferredLanguage("en-GB", 0); // Set the first language in the preferred language list to en-GB.
      let list = I18n.System.getPreferredLanguageList(); // Obtain the preferred language list. Example: list = ["en-GB", ...]
      I18n.System.removePreferredLanguage(list.length - 1); // Remove the last preferred language from the preferred language list.
      let firstPreferredLanguage = I18n.System.getFirstPreferredLanguage(); // firstPreferredLanguage = "en-GB"
      let appPreferredLanguage = I18n.System.getAppPreferredLanguage(); // Set the preferred language of the application to en-GB if the application contains en-GB resources.
   } catch(error) {
      console.error(`call i18n.System interface failed, error code: ${error.code}, message: ${error.message}`);
   }
   ```

12. Obtain and set the local digit switch.

   Call **setUsingLocalDigit** to enable the local digit switch. (This is a system API and can be called only by system applications with the UPDATE_CONFIGURATION permission.)
   Call **getUsingLocalDigit** to check whether the local digit switch is enabled.
   Currently, use of local digits is supported only for the following languages: **ar**, **as**, **bn**, **fa**, **mr**, **my**, **ne**, **ur**.

```js
try {
   I18n.System.setUsingLocalDigit(true); // Enable the local digit switch.
   let status = I18n.System.getUsingLocalDigit(); // status = true
} catch(error) {
   console.error(`call i18n.System interface failed, error code: ${error.code}, message: ${error.message}`);
}
```

## Obtain the calendar information.

[Calendar](../reference/apis/js-apis-i18n.md#calendar8) provides APIs to obtain calendar information, for example, localized representation of the calendar, the start day of a week, and the minimum number of days in the first week of a year.

### Available APIs

| Class       | API                                    | Description                   |
| --------- | ---------------------------------------- | --------------------- |
|  | getCalendar(locale:string,type?:string):Calendar<sup>8+</sup> | Obtains the **Calendar** object for a specific locale and type.|
| Calendar | setTime(date:Date): void<sup>8+</sup>    | Sets the date for this **Calendar** object.       |
| Calendar | setTime(time:number): void<sup>8+</sup>  | Sets the date for this **Calendar** object.       |
| Calendar | set(year:number,month:number,date:number,hour?:number,minute?:number,second?:number): void<sup>8+</sup> | Sets the year, month, day, hour, minute, and second for this **Calendar** object.  |
| Calendar | setTimeZone(timezone:string): void<sup>8+</sup> | Sets the time zone of this **Calendar** object.           |
| Calendar | getTimeZone():string<sup>8+</sup>        | Obtains the time zone of this **Calendar** object.           |
| Calendar | getFirstDayOfWeek():number<sup>8+</sup>  | Obtains the start day of a week for this **Calendar** object.        |
| Calendar | setFirstDayOfWeek(value:number): void<sup>8+</sup> | Sets the first day of a week for the **Calendar** object.        |
| Calendar | getMinimalDaysInFirstWeek():number<sup>8+</sup> | Obtains the minimum number of days in the first week of a year.       |
| Calendar | setMinimalDaysInFirstWeek(value:number): void<sup>8+</sup> | Sets the minimum number of days in the first week of a year.       |
| Calendar | getDisplayName(locale:string):string<sup>8+</sup> | Obtains the localized display of the **Calendar** object.        |
| Calendar | isWeekend(date?:Date):boolean<sup>8+</sup> | Checks whether a given date is a weekend in the calendar.    |

### How to Develop

1. Import the **i18n** module.

   ```js
   import I18n from '@ohos.i18n';
   ```

2. Instantiate a **Calendar** object.

   Call **getCalendar** to obtain the time zone object of a specific locale and type (**i18n** is the name of the imported module). **type** indicates the valid calendar type, for example, **buddhist**, **chinese**, **coptic**, **ethiopic**, **hebrew**, **gregory**, **indian**, **islamic_civil**, **islamic_tbla**, **islamic_umalqura**, **japanese**, and **persian**. If **type** is left unspecified, the default calendar type of the locale is used.

   ```js
   let calendar = I18n.getCalendar("zh-CN", "chinese"); // Create the Calendar object for the Chinese lunar calendar.
   ```

3. Set the time for the **Calendar** object.

     Call **setTime** to set the time of the **Calendar** object. Two types of parameters are supported. One is a **Date** object, and the other is a value indicating the number of milliseconds elapsed since January 1, 1970, 00:00:00 GMT.

   ```js
   let date1 = new Date();
   calendar.setTime(date1);
   let date2 = 1000;
   calendar.setTime(date2);
   ```

4. Set the year, month, day, hour, minute, and second for this **Calendar** object.

     Call **set** to set the year, month, day, hour, minute, and second for the **Calendar** object.

   ```js
   calendar.set(2021, 12, 21, 6, 0, 0);
   ```

5. Set and obtain the time zone for the **Calendar** object.

   Call **setTimeZone** and **getTimeZone** to set and obtain the time zone of the **Calendar** object. Note that **setTimeZone** requires an input string to indicate the time zone to be set.

   ```js
   calendar.setTimeZone("Asia/Shanghai");
   let timezone = calendar.getTimeZone();  // timezone = "China Standard Time"
   ```

6. Set and obtain the first day of a week for the **Calendar** object.

   Call **setFirstDayOfWeek** and **getFirstDayOfWeek** to set and obtain the start day of a week for the **Calendar** object. **setFirstDayOfWeek** must be set to a value indicating the first day of a week. The value **1** indicates Sunday, and the value **7** indicates Saturday.

   ```js
   calendar.setFirstDayOfWeek(1);
   let firstDayOfWeek = calendar.getFirstDayOfWeek(); // firstDayOfWeek = 1
   ```

7. Set and obtain the minimum count of days in the first week for the **Calendar** object.
     Call **setMinimalDaysInFirstWeek** and **getMinimalDaysInFirstWeek** to set and obtain the minimum number of days in the first week for the **Calendar** object.

   ```js
   calendar.setMinimalDaysInFirstWeek(3);
   let minimalDaysInFirstWeek = calendar.getMinimalDaysInFirstWeek(); // minimalDaysInFirstWeek = 3
   ```

8. Obtain the localized representation of the **Calendar** object.
   Call **getDisplayName** to obtain the localized representation of the **Calendar** object.

   ```js
   let localizedName = calendar.getDisplayName("zh-CN"); // localizedName = " Lunar Calendar"
   ```

9. Check whether a date is a weekend.

   Call **isWeekend** to determine whether the input date is a weekend.

   ```js
   let date = new Date(2022, 12, 12, 12, 12, 12);
   let weekend = calendar.isWeekend(date); // weekend = false
   ```

## Formatting a Phone Number

[PhoneNumberFormat](../reference/apis/js-apis-i18n.md#phonenumberformat8) provides APIs to format phone numbers of different countries or regions and check whether the phone number format is correct.

### Available APIs

| Class       | API                                    | Description                     |
| --------- | ---------------------------------------- | ----------------------- |
| PhoneNumberFormat | constructor(country:string,options?:PhoneNumberFormatOptions)<sup>8+</sup> | Instantiates a **PhoneNumberFormat** object.|
| PhoneNumberFormat | isValidNumber(number:string):boolean<sup>8+</sup> | Checks whether the value of **number** is a phone number in the correct format.|
| PhoneNumberFormat | format(number:string):string<sup>8+</sup> | Formats the value of **number** based on the specified country and style. |
| PhoneNumberFormat | getLocationName(number: string, locale: string): string<sup>9+</sup> | Obtains the home location of a phone number. |

### How to Develop

1. Import the **i18n** module.

   ```js
   import I18n from '@ohos.i18n';
   ```

2. Instantiate a **PhoneNumberFormat** object.

   Call the **PhoneNumberFormat** constructor to instantiate a **PhoneNumberFormat** object. The country code and formatting options of the phone number need to be passed into this constructor. The formatting options are optional, including a style option. Values of this option include: **E164**, **INTERNATIONAL**, **NATIONAL**, and **RFC3966**.

   ```js
   let phoneNumberFormat = new I18n.PhoneNumberFormat("CN", {type: "E164"});
   ```

3. Check whether the phone number format is correct.

     Call **isValidNumber** to check whether the format of the input phone number is correct.

   ```js
   let validNumber = phoneNumberFormat.isValidNumber("15812341234"); // validNumber = true
   ```

4. Format a phone number.

     Call **format** to format the input phone number.

   ```js
   let formattedNumber = phoneNumberFormat.format("15812341234"); // formattedNumber = "+8615812341234"
   ```

## Measurement Conversion

The **I18NUtil** class provides an API to implement measurement conversion.

### Available APIs

| Class       | API                                    | Description                                     |
| --------- | ---------------------------------------- | --------------------------------------- |
| I18NUtil | unitConvert(fromUnit:UnitInfo,toUnit:UnitInfo,value:number,locale:string,style?:string):string<sup>9+</sup> | Converts one measurement unit into another and formats the unit based on the specified locale and style.|

### How to Develop

1. Import the **i18n** module.

   ```js
   import I18n from '@ohos.i18n';
   ```

2. Convert a measurement unit.

   Call [unitConvert](../reference/apis/js-apis-i18n.md#unitconvert9) to convert a measurement unit and format the display result.

   ```js
   let fromUnit = {unit: "cup", measureSystem: "US"};
   let toUnit = {unit: "liter", measureSystem: "SI"};
   let number = 1000;
   let locale = "en-US";
   let style = "long";
   let converttedUnit = I18n.I18NUtil.unitConvert(fromUnit, toUnit, number, locale, style); // converttedUnit = "236.588 liters"
   ```

## Alphabet Indexing

[IndexUtil](../reference/apis/js-apis-i18n.md#indexutil8) provides APIs to obtain the alphabet indexes of different locales and calculate the index to which a string belongs.

### Available APIs

| Class       | API                                    | Description                     |
| --------- | ---------------------------------------- | ----------------------- |
|  | getInstance(locale?:string):IndexUtil<sup>8+</sup> | Instantiates an **IndexUtil** object.            |
| IndexUtil | getIndexList():Array&lt;string&gt;<sup>8+</sup> | Obtains the index list of the current locale.       |
| IndexUtil | addLocale(locale:string): void<sup>8+</sup> | Adds the index of a new locale to the index list.|
| IndexUtil | getIndex(text:string):string<sup>8+</sup> | Obtains the index of a text object.           |

### How to Develop

1. Import the **i18n** module.

   ```js
   import I18n from '@ohos.i18n';
   ```

2. Instantiates an **IndexUtil** object.

   Call **getInstance** to instantiate an **IndexUtil** object for a specific locale. When the **locale** parameter is empty, instantiate an **IndexUtil** object of the default locale.


   ```js
   let indexUtil = I18n.getInstance("zh-CN");
   ```

3. Obtain the index list.

     Call **getIndexList** to obtain the alphabet index list of the current locale.

   ```js
   let indexList = indexUtil.getIndexList(); // indexList = ["...", "A", "B", "C", ..., "X", "Y", "Z", "..."]
   ```

4. Add an index.

     Call **addLocale** to add the alphabet index of a new locale to the current index list.

   ```js
   indexUtil.addLocale("ar");
   ```

5. Obtain the index of a string.

     Call **getIndex** to obtain the alphabet index of a string.

   ```js
   let text = "access index";
   let index = indexUtil.getIndex(text); // index = "A"
   ```

## Obtaining Line Breaks of Text

When a text is displayed in more than one line, use [BreakIterator8](../reference/apis/js-apis-i18n.md#breakiterator8) APIs to obtain the line break positions of the text.

### Available APIs

| Class       | API                                    | Description                            |
| --------- | ---------------------------------------- | ------------------------------ |
|  | getLineInstance(locale:string):BreakIterator<sup>8+</sup> | Instantiates a **BreakIterator** object.                      |
| BreakIterator | setLineBreakText(text:string): void<sup>8+</sup> | Sets the text to be processed.                     |
| BreakIterator | getLineBreakText():string<sup>8+</sup>   | Obtains the text to be processed.                     |
| BreakIterator | current():number<sup>8+</sup>            | Obtains the current position of a **BreakIterator** object in the text being processed.             |
| BreakIterator | first():number<sup>8+</sup>              | Sets a **BreakIterator** object to the first breakable point.           |
| BreakIterator | last():number<sup>8+</sup>               | Sets a **BreakIterator** object to the last breakable point.          |
| BreakIterator | next(index?:number):number<sup>8+</sup>  | Moves a **BreakIterator** object to the break point according to **index**.          |
| BreakIterator | previous():number<sup>8+</sup>           | Moves a **BreakIterator** object to the previous break point.            |
| BreakIterator | following(offset:number):number<sup>8+</sup> | Moves a **BreakIterator** object to the break point following the position specified by **offset**.|
| BreakIterator | isBoundary(offset:number):boolean<sup>8+</sup> | Determines whether a position is a break point.                 |

### How to Develop

1. Import the **i18n** module.

   ```js
   import I18n from '@ohos.i18n';
   ```

2. Instantiate a **BreakIterator** object.

   Call **getLineInstance** to instantiate a **BreakIterator** object.

   ```js
   let locale = "en-US";
   let breakIterator = I18n.getLineInstance(locale);
   ```

3. Set and access the text that requires line breaking.

   Call **setLineBreakText** and **getLineBreakText** to set and access the text that requires line breaking.

   ```js
   let text = "Apple is my favorite fruit";
   breakIterator.setLineBreakText(text);
   let breakText = breakIterator.getLineBreakText();  // breakText = "Apple is my favorite fruit"
   ```

4. Obtain the current position of the **BreakIterator** object.

   Call **current** to obtain the current position of the **BreakIterator** object in the text being processed.

   ```js
   let pos = breakIterator.current(); // pos = 0
   ```

5. Set the position of a **BreakIterator** object.

   The following APIs are provided to adjust the **first**, **last**, **next**, **previous**, or **following** position of the **BreakIterator** object in the text to be processed.

   ```js
   let firstPos = breakIterator.first(); // Set a BreakIterator object to the first break point, that is, the start position of the text (firstPos = 0).
   let lastPos = breakIterator.last(); // Sets a BreakIterator object to the last break point, that is, the position after the text end (lastPos = 26).
   // Move a BreakIterator object forward or backward by a certain number of break points.
   // If a positive number is input, move backward. If a negative number is input, move forward. If no value is input, move one position backward.
   // If the object is moved out of the text length range, **-1** is returned.
   let nextPos = breakIterator.next(-2); // nextPos = 12
   let previousPos = breakIterator.previous(); // Move a BreakIterator object to the previous break point. When the text length is out of the range, **-1** is returned. Example: previousPos = 9
   // Move a BreakIterator object to the break point following the position specified by **offset**. If the object is moved out of the text length range, **-1** is returned.
   let followingPos = breakIterator.following(10); // Example: followingPos = 12
   ```

6. Determine whether a position is a break point.

   Call **isBoundary** to determine whether a position is a break point. If yes, **true** is returned and the **BreakIterator** object is moved to this position. If no, **false** is returned and the **BreakIterator** object is moved to a break point after this position.

   ```js
   let isboundary = breakIterator.isBoundary(5); // isboundary = false
   ```

## Obtaining the Time Zone

[TimeZone](../reference/apis/js-apis-i18n.md#timezone) provides APIs to obtain time zone information, such as the time zone ID, localized representation, and time zone offset.

### Available APIs

| Class       | API                                    | Description                            |
| --------- | ---------------------------------------- | ------------------------------ |
|  | getTimeZone(zoneID?: string): TimeZone<sup>7+</sup> | Obtains a **TimeZone** object.                      |
| TimeZone | getID(): string<sup>7+</sup> | Obtains the time zone ID.                     |
| TimeZone | getDisplayName(locale?: string, isDST?: boolean): string<sup>7+</sup>   | Obtains the localized representation of the time zone.                     |
| TimeZone | getRawOffset(): number<sup>7+</sup>            | Obtains the offset between the time zone represented by a **TimeZone** object and the UTC time zone.             |
| TimeZone | getOffset(date?: number): number<sup>7+</sup>              | Obtains the offset between the time zone represented by a **TimeZone** object and the UTC time zone at a certain time point.           |
| TimeZone | getAvailableIDs(): Array<string><sup>9+</sup>               | Obtains the list of time zone IDs supported by the system.          |
| TimeZone | getAvailableZoneCityIDs(): Array<string><sup>9+</sup>  | Obtains the list of time zone city IDs supported by the system.          |
| TimeZone | getCityDisplayName(cityID: string, locale: string): string<sup>9+</sup>           | Obtains the localized representation of a time zone city in the specified locale.            |
| TimeZone | getTimezoneFromCity(cityID: string): TimeZone<sup>9+</sup> | Obtains the **TimeZone** object corresponding to the specified time zone ID.|

### How to Develop

1. Import the **i18n** module.

   ```js
   import I18n from '@ohos.i18n';
   ```

2. Instantiate the **TimeZone** object, and obtain the time zone information.

   Call **getTimeZone** to obtain the **TimeZone** object.

   ```js
   let timezone = I18n.getTimeZone(); // If you use the default settings, you'll obtain the TimeZone object corresponding to the system time zone.
   ```

   Obtain the time zone ID, localized representation, time zone offset, and time zone offset at a certain time point.
   
   ```js
   let timezoneID = timezone.getID(); // timezoneID = "Asia/Shanghai"
   let timezoneDisplayName = timezone.getDisplayName(); // timezoneDisplayName = "China Standard Time"
   let rawOffset = timezone.getRawOffset(); // rawOffset = 28800000
   let offset = timezone.getOffset(new Date().getTime()); // offset = 28800000
   ```

3. Obtain the list of time zone IDs supported by the system.

   Call **getAvailableIDs** to obtain the list of time zone IDs supported by the system.
   You can use the time zone ID in the time zone ID list as an input parameter of the **getTimeZone** API to create a **TimeZone** object.

   ```js
   let timezoneIDs = I18n.TimeZone.getAvailableIDs(); // timezoneIDs = ["America/Adak", ...], which contains 24 time zone IDs in total
   let timezone = I18n.getTimeZone(timezoneIDs[0]);
   let timezoneDisplayName = timezone.getDisplayName(); // timezoneDisplayName = "Hawaii-Aleutian Standard Time"
   ```

4. Obtain the list of time zone city IDs supported by the system.

   Call **getAvailableZoneCityIDs** to obtain the list of time zone city IDs supported by the system.
   Call **getCityDisplayName** to obtain the localized representation of the time zone city ID.
   Call **getTimezoneFromCity** to create a **TimeZone** object based on the time zone city ID.

   ```js
   let zoneCityIDs = I18n.TimeZone.getAvailableZoneCityIDs(); // ["Auckland", "Magadan", ...]
   let cityDisplayName = I18n.TimeZone.getCityDisplayName(zoneCityIDs[0], "zh-Hans"); // cityDisplayName = "Auckland (New Zealand)"
   let timezone = I18n.TimeZone.getTimezoneFromCity(zoneCityIDs[0]);
   let timezoneDisplayName = timezone.getDisplayName(); // timezoneDisplayName = "New Zealand Standard Time"
   ```

## Obtain the **Transliterator** object.

Call [Transliterator](../reference/apis/js-apis-i18n.md#transliterator9) APIs to create a **Transliterator** object and obtain the transliterated string.

### Available APIs

| Class       | API                                    | Description                            |
| --------- | ---------------------------------------- | ------------------------------ |
| Transliterator | getAvailableIDs():Array<string><sup>9+</sup> | Obtains the transliterator ID list.                      |
| Transliterator | getInstance(): Transliterator<sup>9+</sup> | Creates a **Transliterator** object.                     |
| Transliterator | transform(text: string): string<sup>9+</sup>   | Obtains a transliterated string.                     |

### How to Develop

1. Import the **i18n** module.

   ```js
   import I18n from '@ohos.i18n';
   ```

2. Obtains the transliterator ID list.

   Call **getAvailableIDs** to obtain the transliterator ID list.
   An ID is in the **source-destination** format. For example, **ASCII-Latin** means to convert the transliterator ID from ASCII to Latin.

   ```js
   let ids = I18n.Transliterator.getAvailableIDs(); // ids = ["ASCII-Latin", "Accents-Any", ... ], 671 languages in total
   ```

3. Create a **Transliterator** object, and obtain the transliterated string.

   You can use the ID in the transliterator ID list as an input parameter of the **getInstance** API to create a **Transliterator** object.
   Call **transform** to obtain the transliterated string.

   ```js
   let transliterator = I18n.Transliterator.getInstance("Any-Latin"); // Any-Latin means to convert any text to Latin text.
   let transformText = transliterator.transform ("你好");   // transformText = "nǐ hǎo"
   let transliterator2 = I18n.Transliterator.getInstance("Latin-ASCII");   // Latin-ASCII means to convert Latin text to ASCII text.
   let transformText = transliterator2.transform(transformText);   // transformText = "ni hao"
   ```

## Obtaining the Character Type

[Unicode](../reference/apis/js-apis-i18n.md#unicode9) provides APIs to obtain character information, for example, whether a character is a digit or a space.

### Available APIs

| Class       | API                                    | Description                            |
| --------- | ---------------------------------------- | ------------------------------ |
| Unicode | isDigit(char: string): boolean<sup>9+</sup> | Checks whether the input character is a digit.                      |
| Unicode | isSpaceChar(char: string): boolean<sup>9+</sup> | Checks whether the input character is a space.                     |
| Unicode | isWhitespace(char: string): boolean<sup>9+</sup>   | Checks whether the input character is a white space.                     |
| Unicode | isRTL(char: string): boolean<sup>9+</sup>            | Checks whether the input character is of the RTL language.             |
| Unicode | isIdeograph(char: string): boolean<sup>9+</sup>              | Checks whether the input character is an ideographic character.           |
| Unicode | isLetter(char: string): boolean<string><sup>9+</sup>               | Checks whether the input character is a letter.          |
| Unicode | isLowerCase(char: string): boolean<string><sup>9+</sup>  | Checks whether the input character is a lowercase letter.          |
| Unicode | isUpperCase(char: string): boolean<sup>9+</sup>           | Checks whether the input character is an uppercase letter.            |
| Unicode | getType(char: string): string<sup>9+</sup> | Obtains the type of a character.|

### How to Develop

1. Import the **i18n** module.

   ```js
   import I18n from '@ohos.i18n';
   ```

2. Check the input character has a certain attribute.

   Check whether the input character is a digit.

   ```js
   let isDigit = I18n.Unicode.isDigit("1"); // isDigit = true
   isDigit = I18n.Unicode.isDigit("a"); // isDigit = false
   ```

   Check whether the input character is a space.

   ```js
   let isSpaceChar = I18n.Unicode.isSpaceChar(" "); // isSpaceChar = true
   isSpaceChar = I18n.Unicode.isSpaceChar("\n"); // isSpaceChar = false
   ```

   Check whether the input character is a white space.

   ```js
   let isWhitespace = I18n.Unicode.isWhitespace(" "); // isWhitespace = true
   isWhitespace = I18n.Unicode.isWhitespace("\n"); // isWhitespace = true
   ```

   Check whether the input character is of the RTL language.

   ```js
   let isRTL = I18n.Unicode.isRTL(""); // isRTL = true (Arabic characters are written from left to right.)
   isRTL = I18n.Unicode.isRTL("a"); // isRTL = false
   ```

   Check whether the input character is an ideographic character.

   ```js
   let isIdeograph = I18n.Unicode.isIdeograph("Hello"); // isIdeograph = true
   isIdeograph = I18n.Unicode.isIdeograph("a"); // isIdeograph = false
   ```

   Check whether the input character is a letter.

   ```js
   let isLetter = I18n.Unicode.isLetter("a"); // isLetter = true
   isLetter = I18n.Unicode.isLetter("."); // isLetter = false
   ```

   Check whether the input character is a lowercase letter.

   ```js
   let isLowerCase = I18n.Unicode.isLowerCase("a"); // isLetter = true
   isLowerCase = I18n.Unicode.isLowerCase("A"); // isLetter = false
   ```

   Check whether the input character is an uppercase letter.

   ```js
   let isUpperCase = I18n.Unicode.isUpperCase("a"); // isUpperCase = false
   isUpperCase = I18n.Unicode.isUpperCase("A"); // isUpperCase = true
   ```

3. Obtain the character type.

   Call **getType** to obtain the character type.

   ```js
   let type = I18n.Unicode.getType("a"); // type = U_LOWER_CASE_LETTER
   ```

## Obtaining the Sequence of Year, Month, and Day in a Date

### Available APIs

| Class       | API                                    | Description                            |
| --------- | ---------------------------------------- | ------------------------------ |
| I18NUtil | getDateOrder(locale: string): string<sup>9+</sup> | Checks the sequence of year, month, and day in a date.                      |

### How to Develop

1. Import the **i18n** module.

   ```js
   import I18n from '@ohos.i18n';
   ```

2. Check the sequence of year, month, and day in a date.

   Call **getDateOrder** to obtain the sequence of year, month, and day in the date of the specified locale.
   The API returns a string consisting of three parts, **y**, **L**, and **d**, which indicate the year, month, and day, respectively. The three parts are separated by using a hyphen (-), for example, **y-L-d**.

   ```js
   let order = I18n.I18NUtil.getDateOrder("zh-CN"); // order = "y-L-d" indicates that the sequence of year, month, and day in Chinese is year-month-day.
   ```
<!--no_check-->