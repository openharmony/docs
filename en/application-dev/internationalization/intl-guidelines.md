# intl Development

The **intl** module provides basic i18n capabilities, such as time and date formatting, number formatting, and string sorting, through the standard i18n APIs defined in ECMA 402. For more details about APIs and their usage, see [intl](../reference/apis/js-apis-intl.md).

The [i18n](../reference/apis/js-apis-i18n.md) module provides enhanced I18N capabilities through supplementary interfaces that are not defined in ECMA 402. It works with the Intl module to provide a complete suite of I18N capabilities.

## Setting Locale Information

[Locale](../reference/apis/js-apis-intl.md#locale) provides APIs to maximize or minimize the locale information.

### Available APIs

| Class| API| Description|
| -------- | -------- | -------- |
| Locale | constructor()<sup>8+</sup> | Instantiates a **Locale** object.|
| Locale | constructor(locale:string,options?:LocaleOptions) | Instantiates a **Locale** object based on the locale parameter and options.|
| Locale | toString():string | Converts locale information into a string.|
| Locale | maximize():Locale | Maximizes locale information.|
| Locale | minimize():Locale | Minimizes locale information.|

### How to Develop

1. Import the **intl** module.

   Importing an incorrect bundle can lead to unexpected API behavior.
   
   ```js
   import Intl from '@ohos.intl';
   ```

2. Instantiates a **Locale** object.

   Create a **Locale** object using the **Locale** constructor. This API receives a string representing the locale and an optional [attribute](../reference/apis/js-apis-intl.md#localeoptions) list. (Note that **intl** is the name of the imported module.)

   A **Locale** object consists of four parts: language, script, region, and extension, which are separated by using a hyphen (-).
   -  Language: mandatory. It is represented by a two-letter or three-letter code as defined in ISO-639. For example, **en** indicates English and **zh** indicates Chinese.
   -  Script: optional. It is represented by a four-letter code as defined in ISO-15924. The first letter is in uppercase, and the remaining three letters are in lowercase. For example, **Hant** represents the traditional Chinese, and **Hans** represents the simplified Chinese.
   -  Country or region: optional. It is represented by two-letter code as defined in ISO-3166. Both letters are in uppercase. For example, **CN** represents China, and **US** represents the United States.
   -  Extensions: optional. Each extension consists of two parts, key and value. Currently, the extensions listed in the following table are supported (see BCP 47 Extensions). Extensions can be in any sequence and are written in the format of **-key-value**. They are appended to the language, script, and region by using **-u**. For example, **zh-u-nu-latn-ca-chinese** indicates that the latn digital system and chinese calendar system are used. Extensions can also be passed via the second parameter.
      | Extended Parameter ID| Description|
      | -------- | -------- |
      | ca | Calendar algorithm.|
      | co | Collation type.|
      | hc | Hour cycle.|
      | nu | Numbering system.|
      | kn | Whether numeric collation is used when sorting or comparing strings.|
      | kf | Whether capitalization is considered when sorting or comparing strings.|

   
   ```js
   let locale = "zh-CN";
   let options = {caseFirst: "false", calendar: "chinese", collation: "pinyin"};
   let localeObj = new Intl.Locale(locale, options);
   ```

3. Obtain the string representing a **Locale** object.

     Call **toString** to obtain the string representing a **Locale** object, including the language, region, and other options.
     
   ```js
   let localeStr = localeObj.toString(); // localeStr = "zh-CN-u-ca-chinese-co-pinyin-kf-false
   ```

4. Maximize locale information.

     Call **maximize** to maximize locale information; that is, supplement the missing script and region information.
     
   ```js
   let maximizedLocale = localeObj.maximize();
   let maximizedLocaleStr = maximizedLocale.toString(); // localeStr = "zh-Hans-CN-u-ca-chinese-co-pinyin-kf-false
   ```

5. Minimize locale information.

     Call **minimize** to minimize locale information; that is, delete the unnecessary script and region information.
     
   ```js
   let minimizedLocale = localeObj.minimize();
   let minimizedLocaleStr = minimizedLocale.toString(); // zh-u-ca-chinese-co-pinyin-kf-false
   ```

## Formatting the Date and Time

[DateTimeFormat](../reference/apis/js-apis-intl.md#datetimeformat) provides APIs to format the date and time for the specified locale.

### Available APIs

| Class| API| Description|
| -------- | -------- | -------- |
| DateTimeFormat | constructor()<sup>8+</sup> | Creates a **DateTimeFormat** object.|
| DateTimeFormat | constructor(locale:string\|Array&lt;string&gt;,options?:DateTimeOptions) | Creates a **DateTimeFormat** object and sets the locale and other formatting-related attributes.|
| DateTimeFormat | format(date:Date):string | Calculates the date and time based on the locale and other formatting-related attributes of the **DateTimeFormat** object.|
| DateTimeFormat | formatRange(startDate:Date,endDate:Date):string | Calculates the period based on the locale and other formatting-related attributes of the **DateTimeFormat** object.|
| DateTimeFormat | resolvedOptions():DateTimeOptions | Obtains the related attributes of the **DateTimeFormat** object.|

### How to Develop

1. Import the **intl** module.

   Importing an incorrect bundle can lead to unexpected API behavior.
   
   ```js
   import Intl from '@ohos.intl';
   ```

2. Instantiate a **DateTimeFormat** object.

   Use the default constructor of **DateTimeFormat** to obtain the system default locale by accessing the system language and region settings, and set it as the locale in the **DateTimeFormat** object.

   ```js
   let dateTimeFormat = new Intl.DateTimeFormat();
   ```

     Alternatively, use your own locale and formatting parameters to create a **DateTimeFormat** object. Formatting parameters are optional. For a full list of formatting parameters, see [DateTimeOptions](../reference/apis/js-apis-intl.md#datetimeoptions9).
   
   ```js
   let options = {dateStyle: "full", timeStyle: "full"};
   let dateTimeFormat = new Intl.DateTimeFormat("zh-CN", options);
   ```

3. Format the date and time.

     Call **format** to format a **Date** object. A string is returned as the formatting result.
     
   ```js
   let options = {dateStyle: "full", timeStyle: "full"};
   let dateTimeFormat = new Intl.DateTimeFormat("zh-CN", options);
   let date = new Date(2022, 12, 12, 12, 12, 12);
   let formatResult = dateTimeFormat.format(date); // formatResult = "January 12, 2023, Thursday, 12:12:12 pm, China Standard Time"
   ```

4. Format a period.

     Call **formatRange** to format a period. This API requires the input of two **Date** objects, which respectively indicate the start date and end date of a period. A string is returned as the formatting result.
     
   ```js
   let startDate = new Date(2021, 11, 17, 3, 24, 0);
   let endDate = new Date(2021, 11, 18, 3, 24, 0);
   let datefmt = new Intl.DateTimeFormat("en-GB");
   let formatRangeResult = datefmt.formatRange(startDate, endDate); // formatRangeResult = "17/12/2021-18/12/2021"
   ```

5. Access the attributes of the **DateTimeFormat** object.

     Call **resolvedOptions** to obtain an object that contains all related attributes and values of the **DateTimeFormat** object.
     
   ```js
   let options = {dateStyle: "full", timeStyle: "full"};
   let dateTimeFormat = new Intl.DateTimeFormat("zh-CN", options);
   let resolvedOptions = dateTimeFormat.resolvedOptions(); // resolvedOptions = {"locale": "zh-CN", "calendar": "gregorian", "dateStyle":"full", "timeStyle":"full", "timeZone": "CST"}
   ```

## Formatting Numbers

[NumberFormat](../reference/apis/js-apis-intl.md#numberformat) provides APIs to implement the number formatting specific to a locale.

### Available APIs

| Class| API| Description|
| -------- | -------- | -------- |
| NumberFormat | constructor()<SUP>8+</SUP> | Creates a **NumberFormat** object for the specified locale.|
| NumberFormat | constructor(locale:string\|Array&lt;string&gt;,options?:NumberOptions) | Creates a **NumberFormat** object and sets the locale and other formatting-related attributes.|
| NumberFormat | format(number:number):string | Calculates the number based on the locale and other formatting-related attributes of the **NumberFormat** object.|
| NumberFormat | resolvedOptions():NumberOptions | Obtains the attributes of the **NumberFormat** object.|

### How to Develop

1. Import the **intl** module.

   Importing an incorrect bundle can lead to unexpected API behavior.
   
   ```js
   import Intl from '@ohos.intl';
   ```

2. Instantiate a **NumberFormat** object.

   Use the default constructor of **NumberFormat** to obtain the system default locale by accessing the system language and region settings and set it as the locale in the **NumberFormat** object (**intl** is the name of the imported module).

   ```js
   let numberFormat = new Intl.NumberFormat();
   ```

     Alternatively, use your own locale and formatting parameters to create a **NumberFormat** object. Formatting parameters are optional. For a full list of formatting parameters, see [NumberOptions](../reference/apis/js-apis-intl.md#numberoptions9).
   
   ```js
   let options = {compactDisplay: "short", notation: "compact"};
   let numberFormat = new Intl.NumberFormat("zh-CN", options);
   ```

3. Format a number.

     Call **format** to format a number. A string is returned as the formatting result.
     
   ```js
   let options = {compactDisplay: "short", notation: "compact"};
   let numberFormat = new Intl.NumberFormat("zh-CN", options);
   let number = 1234.5678;
   let formatResult = numberFormat.format(number); // formatResult = "1235"
   ```

4. Access the attributes of the **NumberFormat** object.

     Call **resolvedOptions** to obtain an object that contains all related attributes and values of the **NumberFormat** object.
     
   ```js
   let options = {compactDisplay: "short", notation: "compact"};
   let numberFormat = new Intl.NumberFormat("zh-CN", options);
   let resolvedOptions = numberFormat.resolvedOptions();  // resolvedOptions = {"locale": "zh-CN", "compactDisplay": "short", "notation": "compact", "numberingSystem": "Latn"}
   ```

## Sorting Strings

Users in different regions have different requirements for string sorting. [Collator](../reference/apis/js-apis-intl.md#collator8) provides APIs to sort character strings specific to a locale.

### Available APIs

| Class| API| Description|
| -------- | -------- | -------- |
| Collator | constructor()<sup>8+</sup> | Creates a **Collator** object.|
| Collator | constructor(locale:string\|Array&lt;string&gt;,options?:CollatorOptions)<sup>8+</sup> | Creates a **Collator** object and sets the locale and other related attributes.|
| Collator | compare(first:string,second:string):number<sup>8+</sup> | Calculates the comparison result of two strings based on the locale and other attributes of the **Collator** object.|
| Collator | resolvedOptions():CollatorOptions<sup>8+</sup> | Obtains the attributes of the **Collator** object.|

### How to Develop

1. Import the **intl** module.

   Importing an incorrect bundle can lead to unexpected API behavior.
   
   ```js
   import Intl from '@ohos.intl';
   ```

2. Instantiate a **Collator** object.

   Use the default constructor of **Collator** to obtain the system default locale by accessing the system language and region settings and set it as the locale in the **Collator** object (**intl** is the name of the imported module).

   ```js
   let collator = new Intl.Collator();
   ```

     Alternatively, use your own locale and formatting parameters to create a **Collator** object. For a full list of parameters, see [CollatorOptions](../reference/apis/js-apis-intl.md#collatoroptions9).
     The **sensitivity** parameter is used to specify the levels of differences that will be used for string comparison. The value **base** indicates that only characters are compared, but not the accent and capitalization. For example, 'a' != 'b', 'a' == '', 'a'=='A'. The value **accent** indicates that the accent is considered, but not the capitalization. For example, 'a' != 'b', 'a' == '', 'a'=='A'. The value **case** indicates that the capitalization is considered, but the accent. For example, 'a' != 'b', 'a' == '', 'a'=='A'. The value **variant** indicates that the accent and capitalization are considered. For example, 'a' != 'b', 'a' == '', 'a'=='A'.
   
   ```js
   let collator= new Intl.Collator("zh-CN", {localeMatcher: "best fit", usage: "sort", sensitivity: "case"});
   ```

3. Compare two strings.

     Call **compare** to compare two input strings. This API returns a value as the comparison result. The return value **-1** indicates that the first string is shorter than the second string, the return value **1** indicates that the first string is longer than the second string, and the return value **0** indicates that the two strings are of equal lengths. This allows you to sort character strings based on the comparison result.
     
   ```js
   let collator= new Intl.Collator("zh-CN", {localeMatcher: "best fit", usage: "sort", sensitivity: "case"});
   let str1 = "first string";
   let str2 = "second string";
   let compareResult = collator.compare(str1, str2); // compareResult = -1
   str1 = "first";
   str2 = "First";
   compareResult = collator.compare(str1, str2); // compareResult = -1
   ```

4. Access the attributes of the **Collator** object.

     Call **resolvedOptions** to obtain an object that contains all related attributes and values of the **Collator** object.
     
   ```js
   let collator= new Intl.Collator("zh-CN", {localeMatcher: "best fit", usage: "sort"});
   let options = collator.resolvedOptions(); // options = {"localeMatcher": "best fit", "locale": "zh-CN", "usage": "sort", "sensitivity": "variant", "ignorePunctuation": "false", "numeric": false, "caseFirst": "false", "collation": "default"}
   ```

## Determining the Singular-Plural Type

According to grammars in certain languages, the singular or plural form of a noun depends on the number prior to the noun. [PluralRules](../reference/apis/js-apis-intl.md#pluralrules8) provides APIs to determine the singular-plural type for a specific locale.

### Available APIs

| Class| API| Description|
| -------- | -------- | -------- |
| PluralRules | constructor()<sup>8+</sup> | Creates a **PluralRules** object.|
| PluralRules | constructor(locale:string\|Array&lt;string&gt;,options?:PluralRulesOptions)<sup>8+</sup> | Creates a **PluralRules** object and sets the locale and other related attributes.|
| PluralRules | select(n:number):string<sup>8+</sup> | Determines the singular-plural type based on the locale and other formatting-related attributes of the **PluralRules** object.|


### How to Develop

1. Import the **intl** module.

   Importing an incorrect bundle can lead to unexpected API behavior.
   
   ```js
   import Intl from '@ohos.intl';
   ```

2. Instantiate a **PluralRules** object.

   Use the default constructor of **PluralRules** to obtain the system default locale by accessing the system language and region settings and set it as the locale in the **PluralRules** object (**intl** is the name of the imported module).

   ```js
   let pluralRules = new Intl.PluralRules();
   ```

     Alternatively, use your own locale and formatting parameters to create a **PluralRules** object. For a full list of parameters, see [PluralRulesOptions](../reference/apis/js-apis-intl.md#pluralrulesoptions9).
   
   ```js
   let pluralRules = new Intl.PluralRules("zh-CN", {localeMatcher: "best fit", type: "cardinal"});
   ```

3. Determine the singular-plural type.

     Call **select** to determine the singular-plural type for an input number. This API returns a string as the category of the input number, which can be any of the following: **zero**, **one**, **two**, **few**, **many**, and **other**.
     
   ```js
   let pluralRules = new Intl.PluralRules("zh-CN", {localeMatcher: "best fit", type: "cardinal"});
   let number = 1234.5678;
   let categoryResult = pluralRules.select(number); // categoryResult = "other"
   ```

## Formatting the Relative Time

[RelativeTimeFormat](../reference/apis/js-apis-intl.md#relativetimeformat8) provides APIs to format the relative time for a specific locale.

### Available APIs

| Class| API| Description|
| -------- | -------- | -------- |
| RelativeTimeFormat | constructor()<sup>8+</sup> | Creates a **RelativeTimeFormat** object.|
| RelativeTimeFormat | constructor(locale:string\|Array&lt;string&gt;,options?:RelativeTimeFormatInputOptions)<sup>8+</sup> | Creates a **RelativeTimeFormat** object and sets the locale and other formatting-related attributes.|
| RelativeTimeFormat | format(value:number,unit:string):string<sup>8+</sup> | Calculates the relative time format based on the locale and other formatting-related attributes of the **RelativeTimeFormat** object.|
| RelativeTimeFormat | formatToParts(value:number,unit:string):Array&lt;object&gt;<sup>8+</sup> | Obtains each part of the relative time format based on the locale and other formatting-related attributes of the **RelativeTimeFormat** object.|
| RelativeTimeFormat | resolvedOptions():RelativeTimeFormatResolvedOptions<sup>8+</sup> | Obtains the attributes of the **RelativeTimeFormat** object.|

### How to Develop

1. Import the **intl** module.

   Importing an incorrect bundle can lead to unexpected API behavior.
   
   ```js
   import Intl from '@ohos.intl';
   ```

2. Instantiate a **RelativeTimeFormat** object.

   Use the default constructor of **RelativeTimeFormat** to obtain the system default locale by accessing the system language and region settings and set it as the locale in the **RelativeTimeFormat** object (**intl** is the name of the imported module).
   
   ```js
   let relativeTimeFormat = new Intl.RelativeTimeFormat();
   ```

     Alternatively, use your own locale and formatting parameters to create a **RelativeTimeFormat** object. Formatting parameters are optional. For a full list of formatting parameters, see [ RelativeTimeFormatInputOptions](../reference/apis/js-apis-intl.md#relativetimeformatinputoptions9).
   
   ```js
   let relativeTimeFormat = new Intl.RelativeTimeFormat("zh-CN", {numeric: "always", style: "long"});
   ```

3. Format the relative time.

     Call **format** to format the relative time. This API receives a numeric value representing the time length and a string-form unit, like **year**, **quarter**, **month**, **week**, **day**, **hour**, **minute**, and **second**. A string is returned as the formatting result.
     
   ```js
   let relativeTimeFormat = new Intl.RelativeTimeFormat("zh-CN", {numeric: "always", style: "long"});
   let number = 2;
   let unit = "year";
   let formatResult = relativeTimeFormat.format(number, unit); // 2 years later
   ```

4. Obtain each part of the relative time format.

     On obtaining each part of the relative time format, customize the relative time formatting result.
     
   ```js
   let relativeTimeFormat = new Intl.RelativeTimeFormat("zh-CN", {numeric: "always", style: "long"});
   let number = 2;
   let unit = "year";
   let formatPartsResult = relativeTimeFormat.formatToParts(number, unit); // formatPartsResult = [{"type": "integer", "value": "2", "unit": "year"}, {"type":"literal", "value": "years later"}]
   ```

5. Access the attributes of the **RelativeTimeFormat** object.

     Call **resolvedOptions** to obtain an object that contains all related attributes and values of the **RelativeTimeFormat** object. For a full list of attributes, see [RelativeTimeFormatResolvedOptions](../reference/apis/js-apis-intl.md#relativetimeformatresolvedoptions8).
     
   ```js
   let relativeTimeFormat = new Intl.RelativeTimeFormat("zh-CN", {numeric: "always", style: "long"});
   let options = relativeTimeFormat.resolvedOptions(); // options = {"locale": "zh-CN", "style": "long", "numeric": "always", "numberingSystem": "latn"}
   ```

## Samples

The following sample is provided to help you better understand how to develop internationalization capabilities:

- [`International`: Internationalization (ArkTS) (API9) (Full SDK)] (https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-3.2-Release/code/SystemFeature/Internationalnation/International)
