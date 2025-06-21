# DST Transition


## Use Cases

DST is a local time system that sees manual adjustment to the time with the aim of saving energy in certain countries/regions. When DST is enabled, the time is usually advanced by a certain period compared to the standard time.


## How It Works

When the system time reaches the DST transition point, DST transition is automatically implemented based on the DST transition rules configured in the system. If an application uses a standard TS API, for example, `Date()`, to obtain and display the time, it also displays the DST time when the DST transition time is reached.

The DST transition rules are as follows:

1. Calculate the number of hours in a day.
   The number of hours in a day changes on the day of DST transition. In most countries, there are 23 hours on the day when DST starts and there are 25 hours on the day when the DST ends.

   Calculate the number of hours between the same clock time before and after the DST transition. The sample code is as follows:
   ```ts
   import { i18n } from '@kit.LocalizationKit';

   let calendar: i18n.Calendar = i18n.getCalendar('zh-Hans');
   calendar.setTimeZone('Europe/London');
   calendar.set (2021, 2, 27, 16, 0, 0); // Time before the DST starts
   let startTime: number = calendar.getTimeInMillis();
   calendar.set (2021, 2, 28, 16, 0, 0); // Time in the DST period
   let finishTime: number = calendar.getTimeInMillis();
   let hours: number = (finishTime - startTime) / (3600 * 1000); // hours = 23
   ```

2. Store and display time data.
   Store and display time data according to the local DST timing rules. The time gap and repetition caused by DST transition need to be processed.

   The transition into DST will cause a period of time gap, for example, transition from 1:59:59 to 3:00:00. The transition out of DST will cause a period of time overlap, for example, rollback from 3:59:59 to 3:00:00.

   It is recommended that the DST flag be added to the local time when DST is active.

   ![DST flag](figures/dst-flag.png)

3. Store and transmit time data.
   You are advised to use the standard time (UTC or GMT) of time zone 0 for time data storage and transmission. This helps prevent data loss or errors caused by DST transition.
