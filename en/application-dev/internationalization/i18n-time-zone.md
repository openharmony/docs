# Time Zone Setting

<!--Kit: Localization Kit-->
<!--Subsystem: Global-->
<!--Owner: @yliupy-->
<!--Designer: @zw_feifei-->
<!--Tester: @lpw_work-->
<!--Adviser: @ningningW-->
<!-- md-trans-meta sourceCommit=1a7fdda7cb0bdacc6b1c367c8fd0def17530cd88 translatedAt=2026-08-15T01:53:49.781Z pushedAt=2026-08-15T08:42:29.007Z -->

## Use Cases

The local time of different countries and regions varies according to their longitude. Therefore, different time zones are planned. For example, the UK uses time zone 0 and China uses time zone GMT+8. The time in China is eight hours ahead of that in the UK. For example, 12:00 in Beijing is 4 a.m. in London. The time zone module allows your application to obtain the time zone list to implement its own service logic, for example, a dual-clock application.<br>Since API version 20, the time zone module also supports obtaining the time zone transition time and offset. For details about the time zone transition logic, see [DST Transition](./i18n-dst-transition.md).

## Available APIs

The following table describes the key APIs of the time zone module. For details about the APIs, see [@ohos.i18n (Internationalization)](../reference/apis-localization-kit/js-apis-i18n.md).

| Name| Description|
| -------- | -------- |
| getTimeZone(zoneID?: string): TimeZone | Obtains the **TimeZone** object corresponding to the specified time zone ID.|
| getID(): string | Obtains the ID of the **TimeZone** object.|
| getDisplayName(locale?: string, isDST?: boolean): string | Obtains time zone display name in the specified language.|
| getRawOffset(): number | Obtains the fixed offset of the **TimeZone** object.|
| getOffset(date?: number): number | Obtains the offset of the specified time zone at the specified time.|
| getAvailableIDs(): Array&lt;string&gt; | Obtains the list of time zone IDs supported by the system.|
| getAvailableZoneCityIDs(): Array&lt;string&gt; | Obtains the list of time zone city IDs supported by the system. |
| getCityDisplayName(cityID: string, locale: string): string | Obtains time zone city display name in the specified language.|
| getTimezoneFromCity(cityID: string): TimeZone | Creates a **TimeZone** object based on the specified city ID.|
| getTimezonesByLocation(longitude: number, latitude: number): Array&lt;TimeZone&gt; | Obtains the array of **TimeZone** objects based on the specified geographic coordinates.|
| getZoneRules(): ZoneRules | Obtains the time zone transition rule.|
| nextTransition(date?: number): ZoneOffsetTransition | Obtains the **nextTransition** object for the specified time.|
| getMilliseconds(): number | Obtains the timestamp of the time zone transition.|
| getOffsetAfter(): number | Obtains the offset after the time zone transition.|
| getOffsetBefore(): number | Obtains the offset before the time zone transition.|

## How to Develop

### Using Basic Functions

1. Import the required module.

   <!-- @[import_module](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/International/Internationalization/entry/src/main/ets/i18napplication/TimezoneDstSetting.ets) -->

   ``` TypeScript
   import { i18n } from '@kit.LocalizationKit';
   ```

2. Usage scenarios.

- Basic functions of the time zone interface: obtaining a specific time zone, calculating fixed and actual time zone offsets, and traversing the time zone list.

   <!-- @[get_current_timezone](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/International/Internationalization/entry/src/main/ets/i18napplication/TimezoneDstSetting.ets) -->

   ``` TypeScript
   // Obtain the time zone of Brazil.
   let timezone: i18n.TimeZone = i18n.getTimeZone('America/Sao_Paulo'); // Pass in a specific time zone to create a TimeZone object.
   let timezoneId = timezone.getID(); // timezoneId = 'America/Sao_Paulo'

   // Obtain the TimeZone object corresponding to the city ID.
   let aucklandTimezone: i18n.TimeZone = i18n.TimeZone.getTimezoneFromCity('Auckland');
   timezoneId = aucklandTimezone.getID(); // timezoneId = 'Pacific/Auckland'

   // Obtain the localized name of the TimeZone object.
   let timeZoneName = timezone.getDisplayName('zh-Hans', true); // timeZoneName = 'Brasilia Standard Time'

   // Localized city name
   let cityDisplayName = i18n.TimeZone.getCityDisplayName('Auckland', 'zh-Hans'); // cityDisplayName = 'Auckland (New Zealand)'

   // Fixed offset of the time zone
   let rawOffset = timezone.getRawOffset(); // rawOffset = -10800000

   // Actual offset of the time zone (fixed offset + DST)
   let offset = timezone.getOffset(1234567890); // offset = -10800000

   // List of time zone IDs supported by the system.
   let availableIDs = i18n.TimeZone.getAvailableIDs(); // availableIDs = ['America/Adak', 'Asia/Hovd', ...]

   // List of time zone city IDs supported by the system.
   let cityIDs = i18n.TimeZone.getAvailableZoneCityIDs(); // cityIDs = ['Auckland', 'Magadan', ...]

   // Traverse the list of time zone city IDs.
   let timezoneList: object[] = []; // Time zone list displayed to the user.

   class Item {
     public cityDisplayName = '';
     public timezoneId = '';
     public offset = '';
     public cityId = '';
   };

   for (let i = 0; i < cityIDs.length; i++) {
     let cityId = cityIDs[i];
     let timezone: i18n.TimeZone = i18n.TimeZone.getTimezoneFromCity(cityId); // TimeZone object corresponding to the city ID
     let cityDisplayName = i18n.TimeZone.getCityDisplayName(cityId, 'zh-CN'); // Localized city name.
     let timestamp = (new Date()).getTime();
     let item: Item = {
       cityDisplayName: cityDisplayName,
       timezoneId: timezone.getID(),
       offset: 'GMT' + (timezone.getOffset(timestamp) / 3600 * 1000),
       cityId: cityId
     };
     timezoneList.push(item);
   }

   // TimeZone object array corresponding to the specified geographical coordinates
   let timezoneArray: i18n.TimeZone[] = i18n.TimeZone.getTimezonesByLocation(-43.1, -22.5);

   // Obtain the nextTransition object for the specified time.
   let tijuanaTzId = 'America/Tijuana';
   let tijuanaTimeZone: i18n.TimeZone = i18n.getTimeZone(tijuanaTzId); // Obtain the time zone of Tijuana.
   let zoneRules: i18n.ZoneRules = tijuanaTimeZone.getZoneRules(); // Obtain the time zone transition rule of the Tijuana time zone.
   let someTime = new Date(2025, 4, 13);
   let zoneOffsetTrans: i18n.ZoneOffsetTransition = zoneRules.nextTransition(someTime.getTime());
   zoneOffsetTrans.getMilliseconds(); // Timestamp of the time zone transition: 1762074000000
   zoneOffsetTrans.getOffsetAfter(); // Offset after the time zone transition: -28800000
   zoneOffsetTrans.getOffsetBefore(); // Offset before the time zone transition: -25200000
   // Format the timestamp of the time zone transition.
   let dateTimeFormat: Intl.DateTimeFormat = new Intl.DateTimeFormat('en-US', {
     timeZone: tijuanaTzId,
     dateStyle: 'long',
     timeStyle: 'long',
     hour12: false
   });
   let dateFormat =
     dateTimeFormat.format(new Date(zoneOffsetTrans.getMilliseconds())); // November 2, 2025, 1:00:00 PST
   ```

- Dual-clock app: first select a time zone from the time zone list and add it to the app preferred time zone list. Then traverse the app preferred time zone list to obtain the time of each time zone.

   <!-- @[display_dual_timezones](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/International/Internationalization/entry/src/main/ets/i18napplication/TimezoneDstSetting.ets) -->

   ``` TypeScript
   let pauloTimezone: i18n.TimeZone = i18n.getTimeZone('America/Sao_Paulo');
   let defaultTimezone: i18n.TimeZone = i18n.getTimeZone();
   let appPreferredTimeZoneList: i18n.TimeZone[] = []; // App preferred time zone list.
   appPreferredTimeZoneList.push(pauloTimezone);
   appPreferredTimeZoneList.push(defaultTimezone);
   
   let locale: Intl.Locale = i18n.System.getSystemLocaleInstance();
   for (let i = 0; i < appPreferredTimeZoneList.length; i++) {
     let timezone = appPreferredTimeZoneList[i].getID();
     let calendar: i18n.Calendar = i18n.getCalendar(locale.toString());
     calendar.setTimeZone(timezone); // Set the time zone of the calendar object.
     // Obtain the year, month, day, hour, minute, and second.
     let year = calendar.get('year');
     let month = calendar.get('month');
     let day = calendar.get('date');
     let hour = calendar.get('hour');
     let minute = calendar.get('minute');
     let second = calendar.get('second');
   }
   ```