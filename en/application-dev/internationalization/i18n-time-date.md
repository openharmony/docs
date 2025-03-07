# Date and Time Formatting

## Use Cases

The date and time formats vary according to countries and cultures. The difference lies in such aspects as the sequence of year, month, and day in a date and the separator of hour, minute, and second in the time. If your application needs to display the date and time, ensure that the information is displayed in line with local user habits for easy understanding.

Time and date formatting includes date and time formatting, relative time formatting, and time segment formatting. Date and time formatting means to convert the date and time into a string in the specified format. Relative time formatting means to convert the time difference between a time point and another time point to the specified format, for example, 30 seconds ago or 1 day later. Time segment formatting means to convert a time segment to the specified format, for example, Wednesday or 8:00-11:30.

## Constraints

1. The date format and time format must be set at the same time. If the date format, but not the time format, is set, only the date format is displayed. If the time format, but not the date format, is set, only the time format is displayed.

2. If the date or time format is specified, setting of the year, month, day, hour, minute, second, and weekday formats is not supported. If the date or time format is not set, the year, month, day, hour, minute, second, and weekday formats can be set independently.

## How to Develop

### Date and Time Formatting

Date and time formatting is implemented by the [format](../reference/apis-localization-kit/js-apis-intl.md#format) API of [DateTimeFormat](../reference/apis-localization-kit/js-apis-intl.md#datetimeformat). The development procedure is as follows:

1. Import the **intl** module.
   ```ts
   import { intl } from '@kit.LocalizationKit';
   ```

2. Create a **DateTimeFormat** object.
   Pass in a locale or locale list. If a locale list is passed, the first valid locale is used. If you do not pass in any locale, the current system locale will be used.
   You can use **DateTimeOptions** to set different date and time formats. For details, see Table 1 to Table 6.

   ```ts
   let dateFormat: intl.DateTimeFormat = new intl.DateTimeFormat(locale: string | Array<string>, options?: DateTimeOptions);
   let dateFormat: intl.DateTimeFormat = new intl.DateTimeFormat(); // Do not pass in the locale.
   ```

3. Format the date and time.
   ```ts
   // Format the date and time.
   let formattedDate: string = dateFormat.format(date: Date);
   
   // Format the time segment.
   let formattedDateRange: string = dateFormat.formatRange(startDate: Date, endDate: Date);
   ```

4. Obtain **DateTimeOptions** and view the configuration of formatting options.
   ```ts
   let options: intl.DateTimeOptions = dateFormat.resolvedOptions();
   ```

**Date and Time Formatting Options**

The following uses the time **2021-09-17 13:04:00** and locale **zh-CN** as an example to show the values of [DateTimeOptions](../reference/apis-localization-kit/js-apis-intl.md#datetimeoptions) and corresponding display effects.

**Table 1** Date display format (dateStyle)

| Value| Display Effect| 
| -------- | -------- |
| full | Friday, September 17, 2021| 
| long | September 17, 2021| 
| short | 2021/9/17 | 
| medium | September 17, 2021| 

**Table 2** Time display format (timeStyle)

| Value| Display Effect| 
| -------- | -------- |
| full | 13:04:00 China Standard Time| 
| long | GMT+8 13:4:00 | 
| short | 13:04 | 
| medium | 13:04:00 | 

**Table 3** Year display format (year)

| Value| Display Effect| 
| -------- | -------- |
| numeric | 2021 | 
| 2-digit | 21 | 

**Table 4** Weekday display format (weekday)

| Value| Display Effect| 
| -------- | -------- |
| long | Friday| 
| short | Fri.| 
| narrow | 5| 


**Table 5** Hour cycle (hourCycle)

| Value| Display Effect| 
| -------- | -------- |
| h11 | 13:04| 
| h12 | 1:04| 
| h23 | 1:04 | 
| h24 | 13:04 | 

**Development Example**
```ts
// Import the intl module.
import { intl } from '@kit.LocalizationKit';

let date = new Date(2021, 8, 17, 13, 4, 0); // The date and time is 2021.09.17 13:04:00.
let startDate = new Date(2021, 8, 17, 13, 4, 0);
let endDate = new Date(2021, 8, 18, 13, 4, 0);

// Display complete time information.
let dateFormat1 = new intl.DateTimeFormat('zh-CN', {dateStyle: 'full', timeStyle: 'full'});
let formattedDate1 = dateFormat1.format(date); // formattedDate1: Friday, September 17, 2021 at 13:04:00 China Standard Time

// Display short time information in limited space.
let dateFormat2 = new intl.DateTimeFormat('zh-CN', {dateStyle: 'short', timeStyle: 'short'});
let formattedDate2 = dateFormat2.format(date); // formattedDate2: 2021/9/17 13:04 

// Customize the display effect of year, month, day, hour, minute, and second.
let dateFormat3 = new intl.DateTimeFormat('zh-CN', {year: 'numeric', month: '2-digit', day: '2-digit', hour: '2-digit', minute: '2-digit', second: '2-digit'});
let formattedDate3 = dateFormat3.format(date); // formattedDate3: 2021/09/17 13:04:00

// Display only part of the time.
let dateFormat4 = new intl.DateTimeFormat('zh-CN', {month: 'long', day: 'numeric', weekday: 'long' });
let formattedDate4 = dateFormat4.format(date); // formattedDate4: Friday, September 17

// Customize the date and time format.
let dateFormat5 = new intl.DateTimeFormat('zh-CN', {dateStyle: 'short', timeStyle: 'short', hourCycle: 'h11'});
let formattedDate5 = dateFormat5.format(date); // formattedDate5: 2021/9/17 1:04 PM

// Customize the date and time format for users accustomed to other numeral systems.
let dateFormat6 = new intl.DateTimeFormat('zh-CN', {dateStyle: 'short', timeStyle: 'short', numberingSystem: 'arab'});
let formattedDate6 = dateFormat6.format(date); // formattedDate6: ٢٠٢١/٩/١٧ ١٣:٠٤

// Format a time segment.
let dataFormat7 = new intl.DateTimeFormat('en-GB');
let formattedDateRange = dataFormat7.formatRange(startDate, endDate); // formattedDateRange: 17/09/2021 - 18/09/2021

// Obtain formatting options.
let dataFormat8 = new intl.DateTimeFormat('en-GB', {dateStyle: 'full'});
let options = dataFormat8.resolvedOptions();
let dateStyle = options.dateStyle; // dateStyle: full
```

### Relative Time Formatting

Relative time formatting is implemented by the [format](../reference/apis-localization-kit/js-apis-intl.md#format8) API of [RelativeTimeFormat](../reference/apis-localization-kit/js-apis-intl.md#relativetimeformat8). The development procedure is as follows:

1. Import the **intl** module.
   ```ts
   import { intl } from '@kit.LocalizationKit';
   ```

2. Create a **RelativeTimeFormat** object.
   You can use **RelativeTimeFormatInputOptions** to set different output message formats and message lengths. For details, see Table 7 and Table 8.
   ```ts
   let relativeTimeFormat: intl.RelativeTimeFormat = new intl.RelativeTimeFormat(locale: string | Array<string>, options?: RelativeTimeFormatInputOptions);
   ```

3. Format the relative time. **value** indicates the formatted value, and **unit** indicates the formatted unit.
   ```ts
   let formattedRelativeTime: string = relativeTimeFormat.format(value: number, unit: string);
   ```

4. Format the custom relative time.
   ```ts
   let parts: Array<object> = relativeTimeFormat.formatToParts(value: number, unit: string);
   ```

5. Obtain **RelativeTimeFormatInputOptions** and view the configuration of formatting options.
   ```ts
   let options: intl.RelativeTimeFormatInputOptions = relativeTimeFormat.resolvedOptions();
   ```

**Relative Time Formatting Options**

The following uses the relative time **one day ago** and locales **fr-FR** and **en-GB** as an example to show different values of [RelativeTimeFormatInputOptions](../reference/apis-localization-kit/js-apis-intl.md#relativetimeformatinputoptions8) and corresponding display effects.

**Table 6** Output message format (numeric)

| Value| Display Effect (fr-FR)| Display Effect (en-GB)| 
| -------- | -------- | -------- |
| always | il y a 1 jour | 1 day ago | 
| auto | hier | yesterday | 

Table 7 Internationalization message length (style)

| Value| Display Effect (fr-FR)| Display Effect (en-GB)| 
| -------- | -------- | -------- |
| long | il y a 1 jour | 1 day ago | 
| short | il y a 1 j | 1 day ago | 
| narrow | -1 j | 1 day ago | 


**Development Example**
```ts
// Import the intl module.
import { intl } from '@kit.LocalizationKit';

// Display the relative time.
let relativeTimeFormat1 = new intl.RelativeTimeFormat('en-GB');
let formattedRelativeTime1 = relativeTimeFormat1.format(-1, 'day'); // formattedRelativeTime1: 1 day ago

// Display the relative time in a conversational style.
let relativeTimeFormat2 = new intl.RelativeTimeFormat('en-GB', {numeric: "auto"});
let formattedRelativeTime2 = relativeTimeFormat2.format(-1, 'day'); // formattedRelativeTime2: yesterday

// Use the narrow style for certain languages.
let relativeTimeFormat3 = new intl.RelativeTimeFormat('fr-FR'); // The default style is long.
let formattedRelativeTime3 = relativeTimeFormat3.format(-1, 'day'); // formattedRelativeTime3: il y a 1 jour
let relativeTimeFormat4 = new intl.RelativeTimeFormat('fr-FR', {style: 'narrow'});
let formattedRelativeTime4 = relativeTimeFormat4.format(-1, 'day'); // formattedRelativeTime4: -1 j

// Display the custom relative time for the specified locale.
let relativeTimeFormat5 = new intl.RelativeTimeFormat('en-GB', {style: 'long'});
// parts: [{type: 'literal', value: 'in'}, {type: 'integer', value: 1, unit: 'day'}, {type: 'literal', value: 'day'}]
let parts = relativeTimeFormat5.formatToParts(1, 'day');

// Obtain the formatting options of RelativeTimeFormat.
let relativeTimeFormat6 = new intl.RelativeTimeFormat('en-GB', {numeric: 'auto'});
let options = relativeTimeFormat6.resolvedOptions();
let numeric = options.numeric; // numeric: auto
```
