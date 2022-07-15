# Internationalization Development (intl)

This development guide describes how to use i18n APIs that are defined in ECMA 402.

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
   Create a **Locale** object by using the **Locale** constructor. This method receives a string representing the locale and an optional [Attributes](../reference/apis/js-apis-intl.md) list. In the code below, **intl** is the name of the imported module.

   
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
   Use the default constructor of **DateTimeFormat** to obtain the system default locale by accessing the system language and region settings, and set it as the locale in the **DateTimeFormat** object. In the code below, **intl** is the name of the imported module.

   
   ```
   var dateTimeFormat = new intl.DateTimeFormat();
   ```

   Alternatively, use your own locale and formatting parameters to create a **DateTimeFormat** object. Formatting parameters are optional. For a full list of formatting parameters, see [DateTimeOptions](../reference/apis/js-apis-intl.md).
   
   ```
   var options = {dateStyle: "full", timeStyle: "full"};
   var dateTimeFormat = new intl.DateTimeFormat("zh-CN", options);
   ```

2. Format the date and time.<br>
   Use the **format** method of **DateTimeFormat** to format a **Date** object. This method returns a string representing the formatting result.
   
   ```
   Date date = new Date();
   var formatResult = dateTimeFormat.format(date);
   ```

3. Format a period.<br>
   Use the **formatRange** method of **DateTimeFormat** to format a period. This method requires input of two **Date** objects, which respectively indicate the start date and end date of a period. This method returns a string representing the formatting result.
   
   ```
   Date startDate = new Date();
   Date endDate = new Date();
   var formatResult = dateTimeFormat.formatRange(startDate, endDate);
   ```

4. Obtain attributes of the **DateTimeFormat** object.<br>
   The **resolvedOptions** method of **DateTimeFormat** returns an object that contains all related attributes and values of the **DateTimeFormat** object.
   
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
| ohos.intl | resolvedOptions(): NumberOptions | Obtains the attributes of the **NumberFormat** object. | 


### How to Develop

1. Instantiate a **NumberFormat** object.<br>
   Use the default constructor of **NumberFormat** to obtain the system default locale by accessing the system language and region settings, and set it as the locale in the **NumberFormat** object. In the code below, **intl** is the name of the imported module.

   
   ```
   var numberFormat = new intl.NumberFormat();
   ```

   Alternatively, use your own locale and formatting parameters to create a **NumberFormat** object. Formatting parameters are optional. For a full list of formatting parameters, see [NumberOptions](../reference/apis/js-apis-intl.md).
   
   ```
   var options = {compactDisplay: "short", notation: "compact"};
   var numberFormat = new intl.NumberFormat("zh-CN", options);
   ```

2. Format a number.<br>
   Use the **format** method of **NumberFormat** to format a number. A string is returned as the formatting result.
   
   ```
   var number = 1234.5678
   var formatResult = numberFormat.format(number);
   ```

3. Obtain attributes of the **NumberFormat** object.<br>
   The **resolvedOptions** method of NumberFormat returns an object that contains all related attributes and values of the **NumberFormat** object.
   
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
| ohos.intl | resolvedOptions(): CollatorOptions<sup>8+</sup> | Obtains the attributes of the **Collator** object. | 


### How to Develop

1. Instantiate a **Collator** object.<br>
   Use the default constructor of **Collator** to obtain the system default locale by accessing the system language and region settings, and set it as the locale in the **Collator** object. In the code below, **intl** is the name of the imported module.

   
   ```
   var collator = new intl.Collator();
   ```

   Alternatively, use your own locale and formatting parameters to create a **Collator** object. For a full list of parameters, see [CollatorOptions](../reference/apis/js-apis-intl.md).
   
   ```
   var collator= new intl.Collator("zh-CN", {localeMatcher: "best fit", usage: "sort"};
   ```

2. Compare two strings.<br>
   Use the **compare** method of **Collator** to compare two input strings. This method returns a value as the comparison result. The return value **-1** indicates that the first string is shorter than the second string, the return value **1** indicates that the first string is longer than the second string, and the return value **0** indicates that the two strings are of equal lengths.
   
   ```
   var str1 = "first string";
   var str2 = "second string";
   var compareResult = collator.compare(str1, str2);
   ```

3. Obtain attributes of the **Collator** object.<br>
   The **resolvedOptions** method of **Collator** returns an object that contains all related attributes and values of the **Collator** object.
   
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
   Use the default constructor of **PluralRules** to obtain the system default locale by accessing the system language and region settings, and set it as the locale in the **PluralRules** object. In the code below, **intl** is the name of the imported module.

   
   ```
   var pluralRules = new intl.PluralRules();
   ```

   Alternatively, use your own locale and formatting parameters to create a **PluralRules** object. For a full list of parameters, see [PluralRulesOptions](../reference/apis/js-apis-intl.md).
   
   ```
   var plurals = new intl.PluralRules("zh-CN", {localeMatcher: "best fit", type: "cardinal"};
   ```

2. Determine the singular or plural category.<br>
   Use the **select** method of **PluralRules** to determine the singular-plural type for an input number. This method returns a string as the category of the input number, which can be any of the following: **zero**, **one**, **two**, **few**, **many**, and **other**.
   
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
| ohos.intl | resolvedOptions(): RelativeTimeFormatResolvedOptions<sup>8+</sup> | Obtains the attributes of the **RelativeTimeFormat** object. | 


### How to Develop

1. Instantiate a **RelativeTimeFormat** object.<br>
   Use the default constructor of **RelativeTimeFormat** to obtain the system default locale by accessing the system language and region settings, and set it as the locale in the **RelativeTimeFormat** object. In the code below, **intl** is the name of the imported module.

   
   ```
   var relativeTimeFormat = new intl.RelativeTimeFormat();
   ```

   Alternatively, use your own locale and formatting parameters to create a **RelativeTimeFormat** object. Formatting parameters are optional. For a full list of formatting parameters, see [ RelativeTimeFormatInputOptions](../reference/apis/js-apis-intl.md).
   
   ```
   var relativeTimeFormat = new intl.RelativeTimeFormat("zh-CN", {numeric: "always", style: "long"};
   ```

2. Format the relative time.<br>
   Use the **format** method of **RelativeTimeFormat** to format the relative time. This method receives a numeric value representing the time length and a string-form unit, like **year**, **quarter**, **month**, **week**, **day**, **hour**, **minute**, and **second**. This method returns a string representing the formatting result.
   
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
   The **resolvedOptions** method of **RelativeTimeFormat** returns an object that contains all related attributes and values of the **RelativeTimeFormat** object. For a full list of attributes, see [ RelativeTimeFormatResolvedOptions](../reference/apis/js-apis-intl.md).
   
   ```
   var options = numberFormat.resolvedOptions();
   ```
