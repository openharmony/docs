# Internationalization Development (i18n)

This development guide describes how to use i18n APIs that are not defined in ECMA 402.

## Obtaining System Language and Region Information

APIs are provided to access the system language and region information.


### Available APIs

| Module | API | Description | 
| -------- | -------- | -------- |
| ohos.i18n | getSystemLanguage(): string | Obtains the system language. | 
| ohos.i18n | getSystemRegion(): string | Obtains the system region. | 
| ohos.i18n | getSystemLocale(): string | Obtains the system locale. | 
| ohos.i18n | isRTL(locale: string): boolean<sup>7+</sup> | Checks whether the locale uses a right-to-left (RTL) language. | 
| ohos.i18n | is24HourClock(): boolean<sup>7+</sup> | Checks whether the system uses a 24-hour clock. | 
| ohos.i18n | getDisplayLanguage(language: string, locale: string, sentenceCase?: boolean): string | Obtains the localized display of a language. | 
| ohos.i18n | getDisplayCountry(country: string, locale: string, sentenceCase?: boolean): string | Obtains the localized display of a country name. | 


### How to Develop

1. Obtain the system language.<br>
    Call the **getSystemLanguage** method to obtain the system language (**i18n** is the name of the imported module).

   
   ```
   var language = i18n.getSystemLanguage();
   ```

2. Obtain the system region.<br>
    Call the **getSystemRegion** method to obtain the system region.
     
   ```
   var region = i18n.getSystemRegion();
   ```

3. Obtain the system locale.<br>
    Call the **getSystemLocale** method to obtain the system locale.
     
   ```
   var locale = i18n.getSystemLocale();
   ```

4. Check whether the locale's language is RTL.<br>
    Call the **isRTL** method to check whether the locale's language is RTL.

   
   ```
   var rtl = i18n.isRTL("zh-CN");
   ```

5. Check whether the system uses a 24-hour clock.<br>
    Call the **is24HourClock** method to check whether the system uses a 24-hour clock.
     
   ```
   var hourClock = i18n.is24HourClock();
   ```

6. Obtain the localized display of a language.<br>
    Call the **getDisplayLanguage** method to obtain the localized display of a language. **language** indicates the language to be localized, **locale** indicates the locale, and **sentenceCase** indicates whether the first letter of the result must be capitalized.
     
   ```
   var language = "en";
   var locale = "zh-CN";
   var sentenceCase = false;
   var localizedLanguage = i18n.getDisplayLanguage(language, locale, sentenceCase);
   ```

7. Obtain the localized display of a country.<br>
    Call the **getDisplayCountry** method to obtain the localized display of a country name. **country** indicates the country code (a two-letter code in compliance with ISO-3166, for example, CN), **locale** indicates the locale, and **sentenceCase** indicates whether the first letter of the result must be capitalized.
     
   ```
   var country = "US";
   var locale = "zh-CN";
   var sentenceCase = false;
   var localizedCountry = i18n.getDisplayCountry(country, locale, sentenceCase);
   ```


## Obtaining Calendar Information

[Calendar](../reference/apis/js-apis-intl.md) APIs are used to obtain calendar information, for example, the localized display of the calendar, the first day of a week, and the minimum count of days in the first week of a year.


### Available APIs

| Module | API | Description |
| -------- | -------- | -------- |
| ohos.i18n | getCalendar(locale: string, type?: string): Calendar<sup>8+</sup> | Obtains the **Calendar** object for a specific locale and type. |
| ohos.i18n | setTime(date: Date): void<sup>8+</sup> | Sets the date for the **Calendar** object. |
| ohos.i18n | setTime(time: number): void<sup>8+</sup> | Sets the time for the **Calendar** object. |
| ohos.i18n | set(year: number, month: number, date: number, hour?: number, minute?: number, second?: number): void<sup>8+</sup> | Sets the year, month, day, hour, minute, and second for the **Calendar** object. |
| ohos.i18n | setTimeZone(timezone: string): void<sup>8+</sup> | Sets the time zone for the **Calendar** object. |
| ohos.i18n | getTimeZone(): string<sup>8+</sup> | Obtains the time zone for the **Calendar** object. |
| ohos.i18n | getFirstDayOfWeek(): number<sup>8+</sup> | Obtains the first day of a week for the **Calendar** object. |
| ohos.i18n | setFirstDayOfWeek(value: number): void<sup>8+</sup> | Sets the first day of a week for the **Calendar** object. |
| ohos.i18n | getMinimalDaysInFirstWeek(): number<sup>8+</sup> | Obtains the minimum count of days in the first week of a year. |
| ohos.i18n | setMinimalDaysInFirstWeek(value: number): void<sup>8+</sup> | Sets the minimum count of days in the first week of a year. |
| ohos.i18n | getDisplayName(locale: string): string<sup>8+</sup> | Obtains the localized display of the **Calendar** object. |
| ohos.i18n | isWeekend(date?: Date): boolean<sup>8+</sup> | Checks whether a given date is a weekend. |


### How to Develop

1. Instantiate a **Calendar** object.<br>
    Call the **getCalendar** method to obtain the time zone object of a specific locale and type (**i18n** is the name of the imported module). **type** indicates the valid calendar type, for example, **buddhist**, **chinese**, **coptic**, **ethiopic**, **hebrew**, **gregory**, **indian**, **islamic_civil**, **islamic_tbla**, **islamic_umalqura**, **japanese**, and **persian**. If **type** is left unspecified, the default calendar type of the locale is used.

   
   ```
   var calendar = i18n.getCalendar("zh-CN", "gregory);
   ```

2. Set the time for the **Calendar** object.<br>
    Call the **setTime** method to set the time of the **Calendar** object. This method receives two types of parameters. One is a **Date** object, and the other is a value indicating the number of milliseconds elapsed since January 1, 1970, 00:00:00 GMT.
     
   ```
   var date1 = new Date();
   calendar.setTime(date1);
   var date2 = 1000;
   calendar.setTime(date2);
   ```

3. Set the year, month, day, hour, minute, and second for the **Calendar** object.<br>
    Call the **set** method to set the year, month, day, hour, minute, and second for the **Calendar** object.
     
   ```
   calendar.set(2021, 12, 21, 6, 0, 0)
   ```

4. Set and obtain the time zone for the **Calendar** object.<br>
    Call the **setTimeZone** and **getTimeZone** methods to set and obtain the time zone for the **Calendar** object. The **setTimeZone** method requires an input string to indicate the time zone to be set.

   
   ```
   calendar.setTimeZone("Asia/Shanghai");
   var timezone = calendar.getTimeZone();
   ```

5. Set and obtain the first day of a week for the **Calendar** object.<br>
    Call the **setFirstDayOfWeek** and **getFirstDayOfWeek** methods to set and obtain the first day of a week for the **Calendar** object. **setFirstDayOfWeek** must be set to a value indicating the first day of a week. The value **1** indicates Sunday, and the value **7** indicates Saturday.

   
   ```
   calendar.setFirstDayOfWeek(1);
   var firstDayOfWeek = calendar.getFirstDayOfWeek();
   ```

6. Set and obtain the minimum count of days in the first week for the **Calendar** object.<br>
    Call the **setMinimalDaysInFirstWeek** and **getMinimalDaysInFirstWeek** methods to set and obtain the minimum count of days in the first week for the **Calendar** object.
     
   ```
   calendar.setMinimalDaysInFirstWeek(3);
   var minimalDaysInFirstWeek = calendar.getMinimalDaysInFirstWeek();
   ```

7. Obtain the localized display of the **Calendar** object.<br>
    Call the **getDisplayName** method to obtain the localized display of the **Calendar** object.

   
   ```
   var localizedName = calendar.getDisplayName("zh-CN");
   ```

8. Check whether a date is a weekend.<br>
    Call the **isWeekend** method to determine whether the input date is a weekend.

   
   ```
   var date = new Date();
   var weekend = calendar.isWeekend(date);
   ```


## Formatting a Phone Number

[PhoneNumberFormat](../reference/apis/js-apis-intl.md) APIs are used to format phone numbers in different countries and check whether the phone number formats are correct.


### Available APIs

| Module | API | Description | 
| -------- | -------- | -------- |
| ohos.i18n | constructor(country: string, options?: PhoneNumberFormatOptions)<sup>8+</sup> | Instantiates a **PhoneNumberFormat** object. | 
| ohos.i18n | isValidNumber(number: string): boolean<sup>8+</sup> | Checks whether the value of **number** is a phone number in the correct format. | 
| ohos.i18n | format(number: string): string<sup>8+</sup> | Formats the value of **number** based on the specified country and style. | 


### How to Develop

1. Instantiate a **PhoneNumberFormat** object.<br>
    Call the **PhoneNumberFormat** constructor to instantiate a **PhoneNumberFormat** object. The country code and formatting options of the phone number need to be passed into this constructor. The formatting options are optional, including a style option. Values of this option include: **E164**, **INTERNATIONAL**, **NATIONAL**, and **RFC3966**.

   
   ```
   var phoneNumberFormat = new i18n.PhoneNumberFormat("CN", {type: "E164"});
   ```

2. Check whether the phone number format is correct.
    Call the **isValidNumber** method to check whether the format of the input phone number is correct.
     
   ```
   var validNumber = phoneNumberFormat.isValidNumber("15812341234");
   ```

3. Format a phone number.
    Call the **format** method of **PhoneNumberFormat** to format the input phone number.
     
   ```
   var formattedNumber = phoneNumberFormat.format("15812341234");
   ```


## Measurement Conversion

The **unitConvert** API is provided to help you implement measurement conversion.


### Available APIs

| Module | API | Description | 
| -------- | -------- | -------- |
| ohos.i18n | unitConvert(fromUnit: UnitInfo, toUnit: UnitInfo, value: number, locale: string, style?: string): string<sup>8+</sup> | Converts one measurement unit (**fromUnit**) into another (**toUnit**) and formats the unit based on the specified locale and style. | 


### How to Develop

1. Convert a measurement unit.
   Call the [unitConvert](../reference/apis/js-apis-intl.md) method to convert a measurement unit and format the display result.

   
   ```
   var fromUnit = {unit: "cup", measureSystem: "US"};
   var toUnit = {unit: "liter", measureSystem: "SI"};
   var number = 1000;
   var locale = "en-US";
   var style = "long";
   i18n.Util.unitConvert(fromUtil, toUtil, number, locale, style);
   ```


## Alphabet Index

[IndexUtil](../reference/apis/js-apis-intl.md) APIs are used to obtain the alphabet indexes of different locales and calculate the index to which a string belongs.


### Available APIs

| Module | API | Description |
| -------- | -------- | -------- |
| ohos.i18n | getInstance(locale?: string): IndexUtil<sup>8+</sup> | Instantiates an **IndexUtil** object. |
| ohos.i18n | getIndexList(): Array&lt;string&gt;<sup>8+</sup> | Obtains the index list of the current locale. |
| ohos.i18n | addLocale(locale: string): void<sup>8+</sup> | Adds the index of a new locale to the index list. |
| ohos.i18n | getIndex(text: string): string<sup>8+</sup> | Obtains the index of **text**. |


### How to Develop

1. Instantiate an **IndexUtil** object.<br>
    Call the **getInstance** method to instantiate an **IndexUtil** object for a specific locale. When the **locale** parameter is empty, instantiate an **IndexUtil** object of the default locale.

   
   ```
   var indexUtil = getInstance("zh-CN");
   ```

2. Obtain the index list.<br>
    Call the **getIndexList** method to obtain the alphabet index list of the current locale.
     
   ```
   var indexList = indexUtil.getIndexList();
   ```

3. Add an index.<br>
    Call the **addLocale** method to add the alphabet index of a new locale to the current index list.
     
   ```
   indexUtil.addLocale("ar")
   ```

4. Obtain the index of a string.<br>
    Call the **getIndex** method to obtain the alphabet index of a string.
     
   ```
   var text = "access index";
   indexUtil.getIndex(text);
   ```


## Obtaining Line Breaks of Text

When a text is displayed in more than one line, [BreakIterator](../reference/apis/js-apis-intl.md) APIs are used to obtain the line break positions of the text.


### Available APIs

| Module | API | Description |
| -------- | -------- | -------- |
| ohos.i18n | getLineInstance(locale: string): BreakIterator<sup>8+</sup> | Instantiates a **BreakIterator** object. |
| ohos.i18n | setLineBreakText(text: string): void<sup>8+</sup> | Sets the text to be processed. |
| ohos.i18n | getLineBreakText(): string<sup>8+</sup> | Obtains the text to be processed. |
| ohos.i18n | current(): number<sup>8+</sup> | Obtains the current position of a **BreakIterator** object in the text being processed. |
| ohos.i18n | first(): number<sup>8+</sup> | Sets a **BreakIterator** object to the first breakable point. |
| ohos.i18n | last(): number<sup>8+</sup> | Sets a **BreakIterator** object to the last breakable point. |
| ohos.i18n | next(index?: number): number<sup>8+</sup> | Moves a **BreakIterator** object to the break point according to **index**. |
| ohos.i18n | previous(): number<sup>8+</sup> | Moves a **BreakIterator** object to the previous break point. |
| ohos.i18n | following(offset: number): number<sup>8+</sup> | Moves a **BreakIterator** object to the break point following the position specified by **offset**. |
| ohos.i18n | isBoundary(offset: number): boolean<sup>8+</sup> | Determines whether a position is a break point. |


### How to Develop

1. Instantiate a **BreakIterator** object.<br>
    Call the **getLineInstance** method to instantiate a **BreakIterator** object.

   
   ```
   var locale = "en-US"
   var breakIterator = i18n.getLineInstance(locale);
   ```

2. Set and access the text that requires line breaking.<br>
    Call the **setLineBreakText** and **getLineBreakText** methods to set and access the text that requires line breaking.

   
   ```
   var text = "Apple is my favorite fruit";
   breakIterator.setLineBreakText(text);
   var breakText = breakIterator.getLineBreakText();
   ```

3. Obtain the current position of the **BreakIterator** object.<br>
    Call the **current** method to obtain the current position of the **BreakIterator** object in the text being processed.

   
   ```
   var pos = breakIterator.current();
   ```

4. Set the position of a **BreakIterator** object.<br>
    The following APIs are provided to adjust the **first**, **last**, **next**, **previous**, or **following** position of the **BreakIterator** object in the text to be processed.

   
   ```
   var firstPos = breakIterator.first(); // Sets a BreakIterator object to the first break point, that is, the start position of the text.
   var lastPos = breakIterator.last(); // Sets a BreakIterator object to the last break point, that is, the position after the text end.
   // Moves a BreakIterator object forward or backward by a certain number of break points.
   // If a positive number is input, move backward. If a negative number is input, move forward. If no value is input, move one position backward.
   // When the object is moved out of the text length range, -1 is returned.
   var nextPos = breakIterator.next(-2);
   var previousPos = breakIterator.previous(); // Moves a BreakIterator object to the previous break point. When the text length is out of the range, -1 is returned.
   // Moves a BreakIterator object to the break point following the position specified by offset. If the object is moved out of the text length range, -1 is returned.
   var followingPos = breakIterator.following(10); 
   ```

5. Determine whether a position is a break point.<br>
    Call the **isBoundary** method to determine whether a position is a break point. If yes, **true** is returned and the **BreakIterator** object is moved to this position. If no, **false** is returned and the **BreakIterator** object is moved to a break point after this position.

   
   ```
   var isboundary = breakIterator.isBoundary(5);
   ```
