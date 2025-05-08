# Date and Time Formatting

## Use Cases

The date and time formats vary according to countries and cultures. The difference lies in such aspects as the sequence of year, month, and day in a date and the separator of hour, minute, and second in the time. If your application needs to display the date and time, ensure that the information is displayed in line with local user habits for easy understanding.

Time and date formatting includes date and time formatting, relative time formatting, and time segment formatting. Date and time formatting means to convert the date and time into a string in the specified format. Relative time formatting means to convert the time difference between a time point and another time point to the specified format, for example, 30 seconds ago or 1 day later. Time segment formatting means to convert a time segment to the specified format, for example, Wednesday or 8:00-11:30.

## Constraints

1. The date format and time format must be set at the same time. If the time format, but not the date format, is set, only the time is displayed; if the date format, but not the time format, is set, only the date is displayed.

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
   You can use **DateTimeOptions** to set different date and time formats. For details, see Table 1 to Table 10.

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

The following uses 13:04:00 and 00:25:00 on September 17, 2021 and locales **zh-CN** and **en** as examples to illustrate the values and display results of [DateTimeOptions](../reference/apis-localization-kit/js-apis-intl.md#datetimeoptions).

**Table 1** Date display format (dateStyle)

| Value  | Description                                   | 2021-09-17 13:04:00 for Locale zh-CN| 2021-09-17 13:04:00 for Locale en|
| ------ | --------------------------------------- | ------------------------------------------  | ---------------------------------------- |
| full   | Complete date display, including the year, month, day, and week.| 2021年9月17日星期五                         | Friday, September 17, 2021               |
| long   | Long date display, including the year, month, and day.    | 2021年9月17日                               | September 17, 2021                       |
| short  | Short date display, including the year, month, and day.    | 2021/9/17                                   | 9/17/21                                  |
| medium | Medium date display, including the year, month, and day.  | 2021年9月17日                               | Sep 17, 2021                             |

**Table 2** Time display format (timeStyle)

| Value  | Description| 2021-09-17 13:04:00 for Locale zh-CN| 2021-09-17 13:04:00 for Locale en|
| ------ | ------------- | -------- | -------- |
| full   | Complete time display, including the time zone and time accurate to seconds.| 中国标准时间 13:04:00 | 13:04:00 China Standard Time |
| long   | Long time display, including the time zone expressed in the format of GMT + time zone offset and time accurate to seconds.| GMT+8 13:04:00 | 13:04:00 GMT+8 |
| short  | Short time display, including hour and minute.| 13:04 | 13:04 |
| medium | Medium time display, including hour, minute, and second.| 13:04:00 | 13:04:00 |

**Table 3** Year display format (year)

| Value| Description| 2021-09-17 13:04:00 for Locale zh-CN| 2021-09-17 13:04:00 for Locale en|
| -------- | --------- | -------- | -------- |
| numeric | Complete year| 2021年| 2021 |
| 2-digit | 2-digit year display| 21年| 21 |

**Table 4** Weekday display format (weekday)

| Value| Description| 2021-09-17 13:04:00 for Locale zh-CN| 2021-09-17 13:04:00 for Locale en|
| -------- | ------- | -------- | -------- |
| long | Long weekday display| 星期五| Friday |
| short | Short weekday display.| 周五| Fri |
| narrow | Narrow weekday display.| 五| F |

**Table 5** Hour cycle format (hourCycle)

| Value| Description           | 2021-09-17 13:04:00 for Locale zh-CN| 2021-09-17 00:25:00 for Locale zh-CN|
| --- | --------------- | -------------------------------------------- | ------------------------------------------- |
| h11 | Use of 0-11 to indicate the hour| 下午1:04                                    |  上午0:25                                   |
| h12 | Use of 1-12 to indicate the hour| 下午1:04                                    |  上午12:25                                  |
| h23 | Use of 0-23 to indicate the hour| 13:04                                        | 00:25                                       |
| h24 | Use of 1-24 to indicate the hour| 13:04                                        | 24:25                                       |

> **NOTE**
>
> The preceding table shows the display effect for different values of **hourCycle** when **dateStyle** or **timeStyle** is not set.


**Table 6** Hour cycle format (hourCycle)

| Value| Description           | 2021-09-17 13:04:00 for Locale zh-CN| 2021-09-17 00:25:00 for Locale zh-CN|
| --- | --------------- | -------------------------------------------- | ------------------------------------------- |
| h11 | Use of 1-24 to indicate the hour| 下午13:04                                   |  上午24:25                                  |
| h12 | Use of 1-12 to indicate the hour| 下午1:04                                    |  上午12:25                                  |
| h23 | Use of 0-11 to indicate the hour| 1:04                                         |  0:25                                       |
| h24 | Use of 0-23 to indicate the hour| 13:04                                        |  0:25                                       |

> **NOTE**
>
> The preceding table shows the display effect for different values of **hourCycle** when **dateStyle** or **timeStyle** is set.

**Table 7** Month format (month)

| Value| Description| 2021-09-17 13:04:00 for Locale zh-CN| 2021-09-17 13:04:00 for Locale en|
| -------- | --------- | -------- | -------- |
| numeric | Display of the month as a number| 9月| 9 |
| 2-digit | Display of the month in two digits| 09月| 09 |
| long | Long month display| 九月| September |
| short | Short month display| 9| Sep |
| narrow | Narrow month display| 9 | S |

**Table 8** Localized representation of time zone names (timeZoneName)

| Value | Description               | 2021-09-17 13:04:00 for Locale zh-CN| 2021-09-17 13:04:00 for Locale en|
| ----- | ------------------ | -------------------------------------------- | ---------------------------------------- |
| long  | Long time zone name| 中国标准时间                                 | China Standard Time                      |
| short | Short time zone name| GMT+8                                        | GMT+8                                    |

**Table 9** Era display format (era)

| Value| Description| 2021-09-17 13:04:00 for Locale zh-CN| 2021-09-17 13:04:00 for Locale en|
| -------- | ------ | -------- | -------- |
| long | Long epoch display| 公元| Anno Domini |
| short | Short epoch display| 公元| AD |
| narrow | Narrow epoch display| 公元| A |

**Table 10** Time period format (dayPeriod)

| Value| Description| 2021-09-17 13:04:00 for Locale zh-CN| 2021-09-17 13:04:00 for Locale en|
| -------- | ------ | -------- | -------- |
| long | Long time period display| 下午| in the afternoon |
| short | Short time period display| 下午| in the afternoon |
| narrow | Narrow time period display| 下午| in the afternoon |

**Development Example**
```ts
// Import the intl module.
import { intl } from '@kit.LocalizationKit';

let date: Date = new Date(2021, 8, 17, 13, 4, 0); // The date and time is 2021.09.17 13:04:00.
let startDate: Date = new Date(2021, 8, 17, 13, 4, 0);
let endDate: Date = new Date(2021, 8, 18, 13, 4, 0);

// Display complete time information.
let fullFormat: intl.DateTimeFormat = new intl.DateTimeFormat('zh-CN', { dateStyle: 'full', timeStyle: 'full' });
let formattedDate: string = fullFormat.format(date); // formattedDate = 'Friday, September 17, 2021 China Standard Time 13:04:00'

// Display short time information in limited space.
let shortFormat: intl.DateTimeFormat = new intl.DateTimeFormat('zh-CN', { dateStyle: 'short', timeStyle: 'short' });
formattedDate = shortFormat.format(date); // formattedDate = '2021/9/17 13:04'

// Customize the display effect of year, month, day, hour, minute, and second.
let customFormat: intl.DateTimeFormat = new intl.DateTimeFormat('zh-CN',
  {
    year: 'numeric',
    month: '2-digit',
    day: '2-digit',
    hour: '2-digit',
    minute: '2-digit',
    second: '2-digit'
  });
formattedDate = customFormat.format(date); // formattedDate = '2021/09/17 13:04:00'

// Display only part of the time.
let partialFormat: intl.DateTimeFormat = new intl.DateTimeFormat('zh-CN',
  {
    month: 'long',
    day: 'numeric',
    weekday: 'long'
  });
formattedDate = partialFormat.format(date); // formattedDate = 'Friday, September 17'

// Customize the date and time format.
let hourCycleFormat: intl.DateTimeFormat = new intl.DateTimeFormat('zh-CN',
  {
    dateStyle: 'short',
    timeStyle: 'short',
    hourCycle: 'h11'
  });
formattedDate = hourCycleFormat.format(date); // formattedDate = '2021/9/17 1:04 PM'

// Customize the date and time format for users accustomed to other numeral systems.
let numberingSystemFormat: intl.DateTimeFormat = new intl.DateTimeFormat('zh-CN',
  {
    dateStyle: 'short',
    timeStyle: 'short',
    numberingSystem: 'arab'
  });
formattedDate = numberingSystemFormat.format(date); // formattedDate = '٢٠٢١/٩/١٧ ١٣:٠٤'

// Format a time segment.
let dateRangeFormat: intl.DateTimeFormat = new intl.DateTimeFormat('en-GB');
let formattedDateRange: string =
  dateRangeFormat.formatRange(startDate, endDate); // formattedDateRange = '17/09/2021 - 18/09/2021'

// Obtain formatting options.
let dateFormat: intl.DateTimeFormat = new intl.DateTimeFormat('en-GB', { dateStyle: 'full' });
let options: intl.DateTimeOptions = dateFormat.resolvedOptions();
let dateStyle: string | undefined = options.dateStyle; // dateStyle = 'full'
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

**Table 11** Numeric representation (numeric)

| Value  | Description                                         | Display Effect (fr-FR)| Display Effect (en-GB)|
| ------ | -------------------------------------------- | -------------- | --------------- |
| always | Use of a number to indicate the relative time                        | il y a 1 jour  | 1 day ago       |
| auto   | Use of a phrase or value based on the locale to indicate the relative time| hier           | yesterday       |

**Table 12** Relative time style (style)

| Value  | Description                 | Display Effect (fr-FR)| Display Effect (en-GB)|
| ------ | -------------------- | -------------- | --------------  |
| long   | Long relative time display  | il y a 1 jour  | 1 day ago       |
| short  | Short relative time display  | il y a 1 j     | 1 day ago       |
| narrow | Narrow relative time display| -1 j           | 1 day ago       |


**Development Example**
```ts
// Import the intl module.
import { intl } from '@kit.LocalizationKit';

// Display the relative time.
let relativeTimeFormat: intl.RelativeTimeFormat = new intl.RelativeTimeFormat('en-GB');
let formattedRelativeTime: string = relativeTimeFormat.format(-1, 'day'); // formattedRelativeTime = '1 day ago'

// Display the relative time in a conversational style.
let numericAutoFormat: intl.RelativeTimeFormat = new intl.RelativeTimeFormat('en-GB', { numeric: 'auto' });
formattedRelativeTime = numericAutoFormat.format(-1, 'day'); // formattedRelativeTime = 'yesterday'

// Use the narrow style for certain languages.
let longFormat: intl.RelativeTimeFormat = new intl.RelativeTimeFormat('fr-FR'); // The default style is long.
formattedRelativeTime = longFormat.format(-1, 'day'); // formattedRelativeTime = 'il y a 1 jour'
let narrowFormat: intl.RelativeTimeFormat = new intl.RelativeTimeFormat('fr-FR', { style: 'narrow' });
formattedRelativeTime = narrowFormat.format(-1, 'day'); // formattedRelativeTime = '-1 j'

// Display the custom relative time for the specified locale.
let partFormat: intl.RelativeTimeFormat = new intl.RelativeTimeFormat('en-GB', { style: 'long' });
// parts = [{type: 'literal', value: 'in'}, {type: 'integer', value: 1, unit: 'day'}, {type: 'literal', value: 'day'}]
let parts: object[] = partFormat.formatToParts(1, 'day');

// Obtain the formatting options of RelativeTimeFormat.
let resolvedFormat: intl.RelativeTimeFormat = new intl.RelativeTimeFormat('en-GB', { numeric: 'auto' });
let options: intl.RelativeTimeFormatResolvedOptions = resolvedFormat.resolvedOptions();
let numeric: string = options.numeric; // numeric = 'auto'
```
<!--no_check-->