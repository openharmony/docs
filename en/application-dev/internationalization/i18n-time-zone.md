# Time Zone Setting

## Use Cases

The local time of different countries and regions varies according to their longitude. Therefore, different time zones are planned. For example, the UK uses time zone 0 and China uses time zone GMT+8. The time in China is eight hours earlier than that in the UK. For example, 12:00 in Beijing is 4 a.m. in London. The time zone module allows your application to obtain the time zone list to implement its own service logic, for example, a dual-clock application.

## How to Develop

### Time Zone-related Functions

1. Import the **i18n** module.
   ```ts
   import { i18n } from '@kit.LocalizationKit';
   ```

2. Create a **TimeZone** object and implement functions such as calculating the offset between a fixed time zone and the actual time zone and obtaining and traversing the time zone list.
   ```ts
   // Obtain the time zone of Brazil.
   let timezone = i18n.getTimeZone("America/Sao_Paulo"); // Pass in a specific time zone to create a TimeZone object.
   let timezoneId = timezone.getID();// America/Sao_Paulo
   
   // Obtain the TimeZone object corresponding to the city ID.
   let aucklandTimezone = i18n.TimeZone.getTimezoneFromCity("Auckland");
   let aucklandTzId = aucklandTimezone.getID(); // Pacific/Auckland
   
   // Localized time zone name
   let timeZoneName = timezone.getDisplayName("zh-Hans", true); // Brasilia Standard Time
   
   // Localized city name
   let cityDisplayName = i18n.TimeZone.getCityDisplayName("Auckland", "zh-Hans") // Auckland (New Zealand)
   
   // Fixed offset of the time zone
   let rawOffset = timezone.getRawOffset(); // -10800000
   
   // Actual offset of the time zone (fixed offset + DST)
   let offset = timezone.getOffset(1234567890);// -10800000
   
   // List of time zone IDs supported by the system
   let ids = i18n.TimeZone.getAvailableIDs(); // ["America/Adak", "Asia/Hovd", "America/Sao_Paulo", "Asia/Jerusalem", "Europe/London",...]
   
   // List of time zone city IDs supported by the system
   let cityIdArray = i18n.TimeZone.getAvailableZoneCityIDs();  // ["Auckland", "Magadan", "Lord Howe Island",...]
   // Traverse the list of time zone city IDs.
   let timezoneList: Array<object> = []; // Time zone list displayed to the user
   class Item {
       cityDisplayName : string = "";
       timezoneId : string = "";
       offset : string = "";
       cityId : string = ""
   }
   for (let i =0 ; i < cityIdArray.length ; i++) {
       let cityId = cityIdArray[i];
       let timezone = i18n.TimeZone.getTimezoneFromCity(cityId); // TimeZone object corresponding to the city ID
       let cityDisplayName = i18n.TimeZone.getCityDisplayName(cityId, "zh-CN"); // Localized city name
       let timestamp = (new Date()).getTime()
       let item : Item = {
           cityDisplayName : cityDisplayName,
           timezoneId : timezone.getID(),
           offset : 'GMT'+ (timezone.getOffset(timestamp) / 3600*1000),
           cityId : cityId 
       }
       timezoneList.push(item);
    }
   
   // TimeZone object array corresponding to the specified geographical coordinates
   let timezoneArray = i18n.TimeZone.getTimezonesByLocation(-43.1, -22.5)
   for (let i =0;i < timezoneArray.length; i++) {
       let tzId = timezoneArray[i].getID(); // America/Sao_Paulo
   }
   ```

### Dual-Clock Application

1. Import the **i18n** module.
   ```ts
   import { i18n } from '@kit.LocalizationKit';
   ```

2. Add a time zone to the preferred time zone list of the application.
   ```ts
   let timezone1 = i18n.getTimeZone("America/Sao_Paulo");
   let timezone2 = i18n.getTimeZone();
   let appPreferredTimeZoneList: Array<i18n.TimeZone> = [] // Application preferred time zone list
   appPreferredTimeZoneList.push(timezone1);
   appPreferredTimeZoneList.push(timezone2);
   ```

3. Traverse the preferred time zone list of the application to obtain the time of each time zone.
   ```ts
   let locale = i18n.System.getSystemLocale();
   for (let i = 0 ; i < appPreferredTimeZoneList.length ; i++) {
       let timezone = appPreferredTimeZoneList[i].getID();
       let calendar = i18n.getCalendar(locale);
       calendar.setTimeZone(timezone); // Set the time zone of the Calendar object.
       // Obtain the year, month, day, hour, minute, and second.
       let year = calendar.get("year"); 
       let month = calendar.get("month");
       let day = calendar.get("date");
       let hour = calendar.get("hour");
       let minute = calendar.get("minute");
       let second = calendar.get("second");
   }
   ```
