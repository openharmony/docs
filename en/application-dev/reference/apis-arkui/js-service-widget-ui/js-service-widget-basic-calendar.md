# calendar


The **\<calendar>** component is used to display the calendar page.

> **NOTE**
>
> The APIs of this module are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

## Child Components

Not supported


## Attributes

In addition to the [universal attributes](js-service-widget-common-attributes.md), the following attributes are supported.

| Name            | Type    | Default Value  | Mandatory  | Description                                      |
| -------------- | ------ | ----- | ---- | ---------------------------------------- |
| date           | string | Current date | No   | Date selected on the current page. The default value is the current date in the format of YYYY-MM-DD, for example, 2019-11-22.|
| cardcalendar   | bool   | false | No   | Whether the current calendar is a widget calendar.                          |
| startdayofweek | int    | 6     | No   | Start day of a week on the widget calendar. The default value is Sunday. The value ranges from 0 to 6.            |
| offdays        | string | 5, 6  | No   | Rest days of a week on the widget calendar. The default value is Saturday and Sunday. The value ranges from 0 to 6.        |
| calendardata   | string | -     | Yes   | Data to be displayed on the monthly widget calendar. You can pass data of 5*7 or 6*7 days in the JSON format. For details about the **"data"** attribute, see Table 1.|
| showholiday    | bool   | true  | No   | Whether to display holiday information.                          |

**Table 1** "data" attributes of calendardata

| Name            | Type    | Description                                     |
| -------------- | ------ | --------------------------------------- |
| index          | int    | Index of the data, indicating the sequence number of the date.                         |
| day            | int    | Day.                               |
| month          | int    | Month.                                  |
| year           | int    | Year.                                  |
| isFirstOfLuanr | bool   | Whether the day is the first day of the lunar calendar. The first day is underlined.            |
| hasSchedule    | bool   | Whether there is an event scheduled for the day. If there is, a circle is drawn around the date number.                 |
| markLunarDay   | bool   | Whether the day is a holiday, on which lunar calendar data is marked in blue.                       |
| lunarDay       | string | Lunar date.                                  |
| lunarMonth     | string | Lunar month.                                  |
| dayMark        | string | Day mark.<br>- **work**: workday.<br>- **off**: rest day.|
| dayMarkValue   | string | Text to be displayed for a workday or a rest day.                    |

Example of **calendardata**:

```
{
"year":2021,
"month":1,
"data": [{
    "index": 0,    
    "lunarMonth": "11",
    "lunarDay": "13",    
    "year": 2020,    
    "month ": 12,    
    "day": 27,    
    "dayMark": "work",    
    "dayMarkValue": "On-duty",
    "isFirstOfLunar": true,
    "hasSchedule": true,
    "markLunarDay": true
  },  {
    "index": 1,
    "lunarMonth": "11",
    "lunarDay": "14",   
    "year": 2020,    
    "month ": 12,    
    "day": 28,    
    "dayMark": "work",    
    "dayMarkValue": "On-duty",
    "isFirstOfLunar": true,
    "hasSchedule": true,
    "markLunarDay": true
  },  {
    "index": 2,
    "lunarMonth": "11",
    "lunarDay": "15",   
    "year": 2020,    
    "month ": 12,    
    "day": 29,    
    "dayMark": "work",    
    "dayMarkValue": "On-duty",
    "isFirstOfLunar": true,
    "hasSchedule": true,
    "markLunarDay": true
  },
  ...
  ]
}
```



## Styles

| Name              | Type           | Default Value | Mandatory  | Description     |
| ---------------- | ------------- | ---- | ---- | ------- |
| background-color | &lt;color&gt; | -    | No   | Background color.|


## Events

| Name            | Parameter          | Description             |
| -------------- | ------------ | --------------- |
| selectedchange | changeEvent  | A user clicks a date or switches between months.|
| requestdata    | requestEvent | A date is requested.       |

**Table 2** changeEvent

| Name          | Type    | Description    |
| ------------ | ------ | ------ |
| $event.day   | string | Selected day.|
| $event.month | string | Selected month.|
| $event.year  | string | Selected year.|

**Table 3** requestEvent

| Name                 | Type    | Description      |
| ------------------- | ------ | -------- |
| $event.month        | string | Requested month.  |
| $event.year         | string | Requested year.  |
| $event.currentYear  | string | Current year.|
| $event.currentMonth | string | Current month.|

## Example

The following examples are not intended as copy-paste-ready. Further customization is required.


```html
<!-- xxx.hml -->
<div class="container">
    <calendar class="container_test"
        cardcalendar="true"
        onselectedchange="clickOneDay"
        onrequestdata="messageEventData"
        date="{{currentDate}}"
        offdays="{{offDays}}"
        showholiday="{{showHoliday}}"
        startdayofweek="{{startDayOfWeek}}"
        calendardata="{{calendarData}}">
   </calendar>
</div>
```


```css
/* xxx.css */ 
.container {
    flex-direction:column;
    width: 100%;
    height: 100%;
    align-items:center;
    padding-start: 4px;
    padding-end: 4px;
}
.container_test {
    background-color: white;
}
```


```json
{
    "data": {
        "currentDate": "",
        "offDays": "",
        "startDayOfWeek": 6,
        "showHoliday": true,
        "calendarData": ""
    },
    "actions": {
        "clickOneDay": {
            "action": "router",
            "bundleName": "com.example.calendar",
            "abilityName": "EntryAbility",
            "params": {
                "action": "click_month_view_event",
                "day": "$event.day",
                "month": "$event.month",
                "year": "$event.year"
            }
        },
        "messageEventData": {
            "action": "message",
            "params": {
                "month": "$event.month",
                "year": "$event.year",
                "currentMonth": "$event.currentMonth",
                "currentYear": "$event.currentYear"
            }
        }
    }
}
```

