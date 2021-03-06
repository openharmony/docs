# Internationalization Development (intl)

This development guide describes how to use i18n APIs that are defined in ECMA 402.

> **NOTE**<br>
> In the code snippets in this document, **intl** refers to the name of the imported module.

## Setting Locale Information

Use [Locale](../reference/apis/js-apis-intl.md) APIs to maximize or minimize locale information.


### Available APIs

| Module | API | Description | 
| -------- | -------- | -------- |
| ohos.intl | constructor()<sup>8+</sup> | Instantiates a **Locale** object. | 
| ohos.intl | constructor(locale?: string, options?: options) | Instantiates a **Locale** object based on the locale parameter and options. | 
| ohos.intl | toString(): string | Converts locale information into a string. | 
| ohos.intl | maximize(): Locale | Maximizes locale information. | 
| ohos.intl | minimize(): Locale | Minimizes locale information. | 


### How to Develop

1. Instantiate a **Locale** object.<br>
   Create a **Locale** object by using the **Locale** constructor. This method receives a string representing the locale and an optional [Attributes](../reference/apis/js-apis-intl.md) list. 

   A **Locale** object consists of four parts: language, script, region, and extension, which are separated by using a hyphen (-).
   -  Language: mandatory. It is represented by a two-letter or three-letter code as defined in ISO-639. For example, **en** indicates English and **zh** indicates Chinese.
   -  Script: optional. It is represented by a four-letter code as defined in ISO-15924. The first letter is in uppercase, and the remaining three letters are in lowercase. For example, **Hant** represents the traditional Chinese, and **Hans** represents the simplified Chinese.
   -  Country or region: optional. It is represented by two-letter code as defined in ISO-3166. Both letters are in uppercase. For example, **CN** represents China, and **US** represents the United States.
   -  Extensions: optional. Each extension consists of two parts, key and value. Currently, the extensions listed in the following table are supported (see BCP 47 Extensions). Extensions can be in any sequence and are written in the format of **-key-value**. They are appended to the language, script, and region by using **-u**. For example, **zh-u-nu-latn-ca-chinese** indicates that the Latin numbering system and Chinese calendar system are used. Extensions can also be passed via the second parameter.
      | Extended Parameter ID| Description|
      | -------- | -------- |
      | ca | Calendar algorithm.|
      | co | Collation type.|
      | hc | Hour cycle.|
      | nu | Numbering system.|
      | kn | Whether numeric collation is used when sorting or comparing strings.|
      | kf | Whether upper case or lower case is considered when sorting or comparing strings.|

   
   ```
   var locale = "zh-CN";
   var options = {caseFirst: false, calendar: "chinese", collation: pinyin};
   var localeObj = new intl.Locale(locale, options);
   ```

2. Obtain the string representing a **Locale** object.<br>
   Call the **toString** method to obtain the string representing a **Locale** object, which includes the language, region, and other options.
     
   ```
   var localeStr = localeObj.toString();
   ```

3. Maximize locale information.<br>
   Call the **maximize** method to maximize locale information; that is, supplement the missing script and region information.
     
   ```
   var maximizedLocale = localeObj.maximize();
   ```

4. Minimize locale information.<br>
   Call the **minimize** method to minimize locale information; that is, delete the unnecessary script and region information.
     
   ```
   var minimizedLocale = localeObj.minimize();
   ```


## Formatting the Date and Time

Use [DateTimeFormat](../reference/apis/js-apis-intl.md) APIs to format the date and time for a specific locale.


### Available APIs

| Module | API | Description | 
| -------- | -------- | -------- |
| ohos.intl | constructor()<sup>8+</sup> | Creates a **DateTimeFormat** object. | 
| ohos.intl | constructor(locale: string \| Array&lt;string&gt;, options?: DateTimeOptions) | Creates a **DateTimeFormat** object and sets the locale and other formatting-related attributes. | 
| ohos.intl | format(date: Date): string | Calculates the date and time based on the locale and other formatting-related attributes of the **DateTimeFormat** object. | 
| ohos.intl | formatRange(startDate: Date, endDate: Date): string | Calculates the period based on the locale and other formatting-related attributes of the **DateTimeFormat** object. | 
| ohos.intl | resolvedOptions(): DateTimeOptions | Obtains the related attributes of the **DateTimeFormat** object. | 


### How to Develop

1. Instantiate a **DateTimeFormat** object.<br>
   Use the default constructor of **DateTimeFormat** to obtain the system default locale by accessing the system language and region settings, and set it as the locale in the **DateTimeFormat** object.

   
   ```
   var dateTimeFormat = new intl.DateTimeFormat();
   ```

   Alternatively, use your own locale and formatting parameters to create a **DateTimeFormat** object. Formatting parameters are optional. For a full list of formatting parameters, see [DateTimeOptions](../reference/apis/js-apis-intl.md).
   
   ```
   var options = {dateStyle: "full", timeStyle: "full"};
   var dateTimeFormat = new intl.DateTimeFormat("zh-CN", options);
   ```

2. Format the date and time.<br>
   Call the **format** method to format a **Date** object. This method returns a string representing the formatting result.
     
   ```
   Date date = new Date();
   var formatResult = dateTimeFormat.format(date);
   ```

3. Format a period.<br>
   Call the **formatRange** method to format a period. This method requires input of two **Date** objects, which respectively indicate the start date and end date of a period. This method returns a string representing the formatting result.
     
   ```
   Date startDate = new Date();
   Date endDate = new Date();
   var formatResult = dateTimeFormat.formatRange(startDate, endDate);
   ```

4. Obtain attributes of the **DateTimeFormat** object.<br>
   Call the **resolvedOptions** method to obtain attributes of the **DateTimeFormat** object. This method will return an array that contains all attributes and values of the object.
     
   ```
   var options = dateTimeFormat.resolvedOptions();
   ```


## Number Formatting

Use [NumberFormat](../reference/apis/js-apis-intl.md) APIs to format a number for a specific locale.


### Available APIs

| Module | API | Description | 
| -------- | -------- | -------- |
| ohos.intl | constructor()<sup>8+</sup> | Creates a **NumberFormat** object. | 
| ohos.intl | constructor(locale: string \| Array&lt;string&gt;, options?: NumberOptions) | Creates a **NumberFormat** object and sets the locale and other formatting-related attributes. | 
| ohos.intl | format(number: number): string | Calculates the number based on the locale and other formatting-related attributes of the **NumberFormat** object. | 
| ohos.intl | resolvedOptions(): NumberOptions | Obtains attributes of the **NumberFormat** object. | 


### How to Develop

1. Instantiate a **NumberFormat** object.<br>
   Use the default constructor of **NumberFormat** to obtain the system default locale by accessing the system language and region settings, and set it as the locale in the **NumberFormat** object.

   
   ```
   var numberFormat = new intl.NumberFormat();
   ```

   Alternatively, use your own locale and formatting parameters to create a **NumberFormat** object. Formatting parameters are optional. For a full list of formatting parameters, see [NumberOptions](../reference/apis/js-apis-intl.md).
   
   ```
   var options = {compactDisplay: "short", notation: "compact"};
   var numberFormat = new intl.NumberFormat("zh-CN", options);
   ```

2. Format a number.<br>
   Call the **format** method to format a number. A string is returned as the formatting result.
     
   ```
   var number = 1234.5678
   var formatResult = numberFormat.format(number);
   ```

3. Obtain attributes of the **NumberFormat** object.<br>
   Call the **resolvedOptions** method to obtain attributes of the **NumberFormat** object. This method will return an array that contains all attributes and values of the object.
     
   ```
   var options = numberFormat.resolvedOptions();
   ```


## String Sorting

Use [Collator](../reference/apis/js-apis-intl.md) APIs to sort strings based on a specific locale. Users in different regions have different preferences for string sorting.


### Available APIs

| Module | API | Description | 
| -------- | -------- | -------- |
| ohos.intl | constructor()<sup>8+</sup> | Creates a **Collator** object. | 
| ohos.intl | constructor(locale: string \| Array&lt;string&gt;, options?: CollatorOptions)<sup>8+</sup> | Creates a **Collator** object and sets the locale and other related attributes. | 
| ohos.intl | compare(first: string, second: string): number<sup>8+</sup> | Calculates the comparison result of two strings based on the locale and other attributes of the **Collator** object. | 
| ohos.intl | resolvedOptions(): CollatorOptions<sup>8+</sup> | Obtains attributes of the **Collator** object. | 


### How to Develop

1. Instantiate a **Collator** object.<br>
   Use the default constructor of **Collator** to obtain the system default locale by accessing the system language and region settings, and set it as the locale in the **Collator** object.

   
   ```
   var collator = new intl.Collator();
   ```

   Alternatively, use your own locale and formatting parameters to create a **Collator** object. For a full list of parameters, see [CollatorOptions](../reference/apis/js-apis-intl.md).
   
   ```
   var collator= new intl.Collator("zh-CN", {localeMatcher: "best fit", usage: "sort"};
   ```

2. Compare two strings.<br>
   Call the **compare** method to compare two input strings. This method returns a value as the comparison result. The return value **-1** indicates that the first string is shorter than the second string, the return value **1** indicates that the first string is longer than the second string, and the return value **0** indicates that the two strings are of equal lengths.
     
   ```
   var str1 = "first string";
   var str2 = "second string";
   var compareResult = collator.compare(str1, str2);
   ```

3. Obtain attributes of the **Collator** object.<br>
   Call the **resolvedOptions** method to obtain attributes of the **Collator** object. This method will return an array that contains all attributes and values of the object.
     
   ```
   var options = collator.resolvedOptions();
   ```


## Determining the Singular-Plural Type

Use [PluralRules](../reference/apis/js-apis-intl.md) APIs to determine the singular-plural type for a specific locale. According to the grammar of certain languages, the singular or plural form of a noun depends on its preceding number.


### Available APIs

| Module | API | Description | 
| -------- | -------- | -------- |
| ohos.intl | constructor()<sup>8+</sup> | Creates a **PluralRules** object. | 
| ohos.intl | constructor(locale: string \| Array&lt;string&gt;, options?: PluralRulesOptions)<sup>8+</sup> | Creates a **PluralRules** object and sets the locale and other related attributes. | 
| ohos.intl | select(n: number): string<sup>8+</sup> | Determines the singular-plural type based on the locale and other formatting-related attributes of the **PluralRules** object. | 


### How to Develop

1. Instantiate a **PluralRules** object.<br>
   Use the default constructor of **PluralRules** to obtain the system default locale by accessing the system language and region settings, and set it as the locale in the **PluralRules** object.

   
   ```
   var pluralRules = new intl.PluralRules();
   ```

   Alternatively, use your own locale and formatting parameters to create a **PluralRules** object. For a full list of parameters, see [PluralRulesOptions](../reference/apis/js-apis-intl.md).
   
   ```
   var plurals = new intl.PluralRules("zh-CN", {localeMatcher: "best fit", type: "cardinal"};
   ```

2. Determine the singular-plural type.<br>
   Call the **select** method to determine the singular-plural type of an input number. This method will return a string representing the singular-plural type, which can be any of the following: **zero**, **one**, **two**, **few**, **many**, and **other**.
     
   ```
   var number = 1234.5678
   var categoryResult = plurals.select(number);
   ```


## Formatting Relative Time

Use [RelativeTimeFormat](../reference/apis/js-apis-intl.md) APIs to format the relative time for a specific locale.


### Available APIs

| Module | API | Description | 
| -------- | -------- | -------- |
| ohos.intl | constructor()<sup>8+</sup> | Creates a **RelativeTimeFormat** object. | 
| ohos.intl | constructor(locale: string \| Array&lt;string&gt;, options?: RelativeTimeFormatInputOptions)<sup>8+</sup> | Creates a **RelativeTimeFormat** object and sets the locale and other formatting-related attributes. | 
| ohos.intl | format(value: number, unit: string): string<sup>8+</sup> | Calculates the relative time format based on the locale and other formatting-related attributes of the **RelativeTimeFormat** object. | 
| ohos.intl | formatToParts(value: number, unit: string): Array&lt;object&gt;<sup>8+</sup> | Returns each part of the relative time format based on the locale and other formatting-related attributes of the **RelativeTimeFormat** object. | 
| ohos.intl | resolvedOptions(): RelativeTimeFormatResolvedOptions<sup>8+</sup> | Obtains attributes of the **RelativeTimeFormat** object. | 


### How to Develop

1. Instantiate a **RelativeTimeFormat** object.<br>
   Use the default constructor of **RelativeTimeFormat** to obtain the system default locale by accessing the system language and region settings, and set it as the locale in the **RelativeTimeFormat** object.

   
   ```
   var relativeTimeFormat = new intl.RelativeTimeFormat();
   ```

   Alternatively, use your own locale and formatting parameters to create a **RelativeTimeFormat** object. Formatting parameters are optional. For a full list of formatting parameters, see [ RelativeTimeFormatInputOptions](../reference/apis/js-apis-intl.md).
   
   ```
   var relativeTimeFormat = new intl.RelativeTimeFormat("zh-CN", {numeric: "always", style: "long"};
   ```

2. Format the relative time.<br>
   Call the **format** method to format the relative time. This method receives a numeric value representing the time length and a string-form unit, like **year**, **quarter**, **month**, **week**, **day**, **hour**, **minute**, and **second**. This method returns a string representing the formatting result.
     
   ```
   var number = 2;
   var unit = "year"
   var formatResult = relativeTimeFormat.format(number, unit);
   ```

3. Obtain each part of the relative time format.<br>
   Upon obtaining each part of the relative time format, customize the relative time formatting result.
     
   ```
   var number = 2;
   var unit = "year"
   var formatResult = relativeTimeFormat.formatToParts(number, unit);
   ```

4. Obtain attributes of the **RelativeTimeFormat** object.<br>
   Call the **resolvedOptions** method to obtain attributes of the **RelativeTimeFormat** object. This method will return an array that contains all attributes and values of the object. For a full list of attributes, see [ RelativeTimeFormatResolvedOptions](../reference/apis/js-apis-intl.md).
     
   ```
   var options = numberFormat.resolvedOptions();
   ```

## Samples

The following sample is provided to help you better understand how to develop internationalization capabilities:

-[`International`: Internationalization (JS) (API8)](https://gitee.com/openharmony/app_samples/tree/master/UI/International)
