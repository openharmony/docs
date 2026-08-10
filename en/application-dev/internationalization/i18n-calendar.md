# Calendar Setting

<!--Kit: Localization Kit-->
<!--Subsystem: Global-->
<!--Owner: @yliupy-->
<!--Designer: @sunyaozu-->
<!--Tester: @lpw_work-->
<!--Adviser: @ningningW-->
<!-- md-trans-meta sourceCommit=b4bc1de04741b2b7eb55943f0035c70ca9a9b7d9 translatedAt=2026-08-04T12:24:22.787Z pushedAt=2026-08-04T12:38:03.688Z -->

## Function Description

Users in different regions use different calendars. Most regions use the Gregorian calendar, while some regions use other calendars, such as the lunar calendar, Islamic calendar, or Hebrew calendar. The time and date on a calendar are calculated based on the calendar system and are adjusted according to time zone and daylight saving time (DST) changes. Therefore, users need to set a calendar that conforms to local conventions. The i18n module provides the [Calendar](../reference/apis-localization-kit/js-apis-i18n.md#calendar) class, which allows you to set the calendar, date, time zone, first day of the week, and the minimal days in the first week of the year. In addition, you can determine whether a specific day is a weekend on the calendar and calculate the difference in days. During app development, you can choose to use different features based on your service requirements.

## How to Develop

The following example shows how to use the [Calendar](../reference/apis-localization-kit/js-apis-i18n.md#calendar) class to obtain the lunar calendar date corresponding to a Gregorian calendar date.

1. Import the required module.

   <!-- @[import_module](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/International/Internationalization/entry/src/main/ets/i18napplication/CalendarSetting.ets) -->

   ``` TypeScript
   import { i18n } from '@kit.LocalizationKit';
   ```

2. Usage scenarios.

- Gregorian calendar usage.

   <!-- @[check_and_set_date](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/International/Internationalization/entry/src/main/ets/i18napplication/CalendarSetting.ets) -->

   ``` TypeScript
   let calendar: i18n.Calendar = i18n.getCalendar('zh-Hans', 'gregory');
   // Set the date and time of the Calendar object to 2022.06.13 08:00:00.
   calendar.setTime(new Date(2022, 5, 13, 8, 0, 0));
   calendar.setTime(1655078400000);

   // Set the date and time of the Calendar object to 2022.06.13 08:00:00.
   calendar.set(2022, 5, 13, 8, 0, 0);

   // Set the time zone for the Calendar object.
   calendar.setTimeZone('Asia/Shanghai');

   // Obtain the time zone for the Calendar object.
   let timezone = calendar.getTimeZone(); // timezone = 'Asia/Shanghai'

   // Obtain the start day of a week for the Calendar object.
   let firstDayOfWeek = calendar.getFirstDayOfWeek(); // firstDayOfWeek = 1

   // Set the start day of a week for the Calendar object.
   calendar.setFirstDayOfWeek(1);

   // Obtain the minimum number of days in the first week of a year for the Calendar object.
   let minimalDaysInFirstWeek = calendar.getMinimalDaysInFirstWeek(); // minimalDaysInFirstWeek = 1

   // Set the minimum number of days in the first week of a year for the Calendar object.
   calendar.setMinimalDaysInFirstWeek(3);

   // Obtain the value of the specified field in the Calendar object.
   let year = calendar.get('year'); // year = 2022

   // Obtain the localized name of the Calendar object.
   let calendarName = calendar.getDisplayName('zh-Hans'); // calendarName = 'Gregorian calendar'

   // Check whether a given date is a weekend for the Calendar object.
   let isWeekend = calendar.isWeekend(new Date(2023, 9, 15)); // isWeekend = true

   // Perform addition and subtraction operations on the specified field of the Calendar object.
   calendar.set(2023, 10, 15);
   calendar.add('date', 2);
   let day = calendar.get('date'); // day = 17

   // Check the number of days between the Calendar object and the specified date.
   let daysDifference = calendar.compareDays(new Date(2023, 10, 15)); // daysDifference = -3
   ```

- Obtain the lunar calendar date corresponding to a Gregorian calendar date.

   <!-- @[get_lunar_date](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/International/Internationalization/entry/src/main/ets/i18napplication/CalendarSetting.ets) -->

   ``` TypeScript
   let calendarChinese: i18n.Calendar = i18n.getCalendar('zh-Hans', 'chinese');
   // Set the Gregorian calendar date to the calendar object. The date and time is 2023.07.25 08:00:00.
   calendarChinese.setTime(new Date(2023, 6, 25, 8, 0, 0));

   // Obtain the year, month, and day of the lunar calendar.
   let yearChinese = calendarChinese.get('year'); // year = 40, indicating the 40th year in the sexagenary cycle, ranging from 1 to 60.
   let monthChinese = calendarChinese.get('month'); // month = 5, indicating June.
   let dayChinese = calendarChinese.get('date'); // day = 8, indicating the 8th day.
   ```

**Table 1** List of supported calendars

| Type| Name| 
| -------- | -------- |
| buddhist | Buddhist calendar| 
| chinese | Lunar calendar| 
| coptic | Coptic calendar| 
| ethiopic | Ethiopian calendar| 
| hebrew | Hebrew calendar| 
| gregory | Gregorian calendar| 
| indian | Indian calendar| 
| islamic_civil | Islamic calendar (civil epoch)| 
| islamic_tbla | Islamic calendar (tabular)| 
| islamic_umalqura | Islamic calendar (Umm al-Qura)| 
| japanese | Japanese calendar| 
| persian | Persian calendar| 

<!--RP1--><!--RP1End-->