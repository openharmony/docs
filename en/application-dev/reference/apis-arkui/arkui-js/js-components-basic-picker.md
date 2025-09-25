# picker

>  **NOTE**
>
>  This component is supported since API version 4. Updates will be marked with a superscript to indicate their earliest API version.

The **\<picker>** component supports common, date, time, date and time, and multi-column text selectors.


## Required Permissions

None


## Child Components

Not supported


## Attributes

In addition to the [universal attributes](js-components-common-attributes.md), the following attributes are supported.

| Name  | Type    | Default Value | Mandatory  | Description                                      |
| ---- | ------ | ---- | ---- | ---------------------------------------- |
| type | string | -    | No   | Picker type. Dynamic modification is not supported. The options are as follows:<br>- **text**: text selector.<br>- **date**: date selector.<br>- **time**: time selector.<br>- **datetime**: date and time selector.<br>- **multi-text**: multi-column text selector.|


### Common Selector

When **type** is set to **text**, a common selector is used.

| Name      | Type    | Default Value | Mandatory  | Description                                      |
| -------- | ------ | ---- | ---- | ---------------------------------------- |
| range    | Array  | -    | No   | Value range of the common selector, for example, **["15", "20", "25"]**.<br>Use the data binding mode, for example, `range = {{data}}`. Declare the corresponding variable `data: ["15", "20", "25"]` in JavaScript.|
| selected | string | 0    | No   | Default value of the common selector. The value should be the index of **range**.|
| value    | string | -    | No   | Value of the common selector.                              |


### Date Selector

When **type** is set to **date**, a date selector is used.

| Name                | Type          | Default Value       | Mandatory  | Description                                      |
| ------------------ | ------------ | ---------- | ---- | ---------------------------------------- |
| start              | &lt;time&gt; | 1970-1-1   | No   | Start date of the date selector, in the format of YYYY-MM-DD.       |
| end                | &lt;time&gt; | 2100-12-31 | No   | End date of the date selector, in the format of YYYY-MM-DD.       |
| selected           | string       | Current date      | No   | Default value of the date selector, in format of YYYY-MM-DD.|
| value              | string       | -          | Yes   | Value of the date selector.                              |
| lunar<sup>5+</sup> | boolean      | false      | No   | Whether the pop-up window displays the lunar calendar.                     |
| lunarswitch        | boolean      | false      | No   | Whether the date selector displays the lunar calendar switch, which is used to switch between the Gregorian calendar and lunar calendar. The value **true** means to display the lunar calendar switch for users to switch between the Gregorian calendar and lunar calendar. The value **false** means not to display the lunar calendar switch.<br>When both **lunarswitch** and **lunar** are set to **true**, the switch is selected.|


### Time Selector

When **type** is set to **time**, a time selector is used.

| Name           | Type     | Default Value                                | Mandatory  | Description                                      |
| ------------- | ------- | ----------------------------------- | ---- | ---------------------------------------- |
| containsecond | boolean | false                               | No   | Whether seconds are contained.                           |
| selected      | string  | Current time                               | No   | Default value of the time selector, in format of HH:mm. If seconds are contained, the format is HH:mm:ss.<br> |
| value         | string  | -                                   | No   | Value of the time selector.                              |
| hours         | number  | 24<sup>1-4</sup><br>-<sup>5+</sup> | No   | Time format used by the time selector. Available values are as follows:<br>- **12**: displayed in 12-hour format and distinguished by a.m. and p.m.<br>- **24**: displayed in 24-hour format.<br>Since API version 5, the default value is the most commonly-used hour format in the current locale.|


### Date and Time Selector

When **type** is set to **datetime**, a date and time selector is used.

| Name                | Type     | Default Value                                | Mandatory  | Description                                      |
| ------------------ | ------- | ----------------------------------- | ---- | ---------------------------------------- |
| selected           | string  | Current date and time                             | No   | Default value of the date and time selector. The value can be in either of the following formats:<br>- MM-DD-HH-mm<br>- YYYY-MM-DD-HH-mm<br>If the year is not set, the current year is used by default. The value you set is the date selected by default in the pop-up window.|
| value              | string  | -                                   | Yes   | Value of the date and time selector.                            |
| hours              | number  | 24<sup>1-4</sup><br>-<sup>5+</sup> | No   | Time format used by the date and time selector. Available values are as follows:<br>- **12**: displayed in 12-hour format and distinguished by a.m. and p.m.<br>- **24**: displayed in 24-hour format.<br>Since API version 5, the default value is the most commonly-used hour format in the current locale.|
| lunar<sup>5+</sup> | boolean | false                               | No   | Whether the pop-up window displays the lunar calendar.                   |
| lunarswitch        | boolean | false                               | No   | Whether the date selector displays the lunar calendar switch, which is used to switch between the Gregorian calendar and lunar calendar. The value **true** means to display the lunar calendar switch for users to switch between the Gregorian calendar and lunar calendar. The value **false** means not to display the lunar calendar switch.<br>When both **lunarswitch** and **lunar** are set to **true**, the switch is selected.|


### Multi-Column Text Selector

When **type** is set to **multi-text**, a multi-column text selector is used.

| Name      | Type     | Default Value      | Mandatory  | Description                                      |
| -------- | ------- | --------- | ---- | ---------------------------------------- |
| columns  | number  | -         | Yes   | Number of columns in the multi-column text selector.                           |
| range    | Two-dimensional array| -         | No   | Items of the multi-column text selector. **range** is a two-dimensional array that indicates the number of columns. Each item in the array indicates the data of each column, for example, **[["a", "b"], ["c", "d"]]**.<br>Use the data binding mode, for example, `range = {{data}}`. Declare the corresponding variable `data: ["15", "20", "25"]` in JavaScript.|
| selected | Array   | [0,0,0, ...]| No   | Default value of the multi-column text selector, which is an array consisting of the indexes of the selected items in each column.|
| value    | Array   | -         | No   | Value of the multi-column text selector, which is an array consisting of the values of the selected items in each column.           |


## Styles

In addition to the [universal styles](js-components-common-styles.md), the following styles are supported.

| Name                        | Type                        | Default Value       | Mandatory  | Description                                      |
| -------------------------- | -------------------------- | ---------- | ---- | ---------------------------------------- |
| text-color                 | &lt;color&gt;              | -          | No   | Text color of the selector.                               |
| font-size                  | &lt;length&gt;             | -          | No   | Font size of the selector.                               |
| allow-scale                | boolean                    | true       | No   | Whether the font size changes with the system's font size settings.<br>If the **config-changes** tag of **fontSize** is configured for abilities in the **config.json** file, the setting takes effect without application restart.|
| letter-spacing             | &lt;length&gt;             | 0          | No   | Letter spacing of the selector. For details, see **letter-spacing** in the **[\<text>](js-components-basic-text.md#styles)** component.|
| text-decoration            | string                     | -          | No   | Text decoration of the selector. For details, see **text-decoration** in the **[\<text>](js-components-basic-text.md#styles)** component.|
| font-style                 | string                     | normal     | No   | Font style of the selector. For details, see **font-style** in the **[\<text>](js-components-basic-text.md#styles)** component.|
| font-weight                | number \| string | normal     | No   | Font weight of the selector. For details, see **font-weight** in the **[\<text>](js-components-basic-text.md#styles)** component.|
| font-family                | string                     | sans-serif | No   | Font family, in which fonts are separated by commas (,). Each font is set using a font name or font family name. The first font in the family or the specified [custom font](js-components-common-customizing-font.md) is used for the text.|
| line-height                | &lt;length&gt;             | 0px        | No   | Text line height of the selector.                               |
| column-height<sup>5+</sup> | &lt;length&gt;             | -          | No   | Height of the selector option list.                            |


## Events

In addition to the [universal events](js-components-common-events.md), the following events are supported.


### Common Selector

| Name    | Parameter                                      | Description                                      |
| ------ | ---------------------------------------- | ---------------------------------------- |
| change | { newValue: newValue, newSelected: newSelected } | Triggered when an item is selected and the OK button is clicked in the displayed pop-up window. **newSelected** is the index.|
| cancel | -                                        | Triggered when the cancel button is clicked.                     |


### Date Selector

| Name    | Parameter                                      | Description                                      |
| ------ | ---------------------------------------- | ---------------------------------------- |
| change | { year: year, month: month, day: day } | Triggered when an item is selected and the OK button is clicked in the displayed pop-up window.<br>The value of **month** ranges from **0** (January) to **11** (December) since API version 5.|
| cancel | -                                        | Triggered when the cancel button is clicked.                     |


### Date and Time Selector

| Name    | Parameter                                      | Description                          |
| ------ | ---------------------------------------- | ---------------------------- |
| change | { year: year, month: month, day: day,  hour: hour, minute: minute} | Triggered when an item is selected and the OK button is clicked in the displayed pop-up window.|
| cancel | -                                        | Triggered when the cancel button is clicked.         |


### Time Selector

| Name    | Parameter                                      | Description                                      |
| ------ | ---------------------------------------- | ---------------------------------------- |
| change | { hour: hour, minute: minute, [second: second] } | Triggered when an item is selected and the OK button is clicked in the displayed pop-up window. If **containsecond** is set to true, value contains seconds.|
| cancel | -                                        | Triggered when the cancel button is clicked.                     |


### Multi-Column Text Selector

| Name          | Parameter                                      | Description                                      |
| ------------ | ---------------------------------------- | ---------------------------------------- |
| change       | { newValue: [newValue1, newValue2, newValue3, …], newSelected:[newSelected1, newSelected2, newSelected3, …] } | Triggered when an item is selected and the OK button is clicked in the displayed pop-up window.<br>- **newValue** is an array consisting of the values of the selected items.<br>- **newSelected** is an array consisting of the indexes of the selected items. The lengths of **newValue** and **newSelected** are the same as the length of **range**.|
| columnchange | { column: column, newValue: newValue, newSelected: newSelected } | Triggered when the value of a column in the multi-column selector changes.<br>- **column**: column whose value has changed.<br>- **newValue**: selected value.<br>- **newSelected**: index of the selected value.|
| cancel       | -                                        | Triggered when the cancel button is clicked.                     |


## Methods

In addition to the [universal methods](js-components-common-methods.md), the following methods are supported.

| Name  | Parameter  | Description             |
| ---- | ---- | --------------- |
| show | -    | Shows the picker.|


## Example

```html
<!-- xxx.hml -->
<div class="container">
    <select @change="selectChange">
        <option value="{{ item }}" for="item in selectList">
            {{ item }}
        </option>
    </select>
    <picker id="picker0" type="text" value="{{ textvalue }}" selected="{{ textselect }}" range="{{ rangetext }}"
            onchange="textonchange"
            oncancel="textoncancel" class="pickertext" show="false"></picker>

    <picker id="picker1" type="date" value="{{ datevalue }}" start="2002-2-5" end="2030-6-5" selected="{{ dateselect }}"
            lunarswitch="true"
            onchange="dateonchange" oncancel="dateoncancel" class="pickerdate" show="false"></picker>

    <picker id="picker2" type="time" value="{{ timevalue }}" containsecond="{{ containsecond }}"
            selected="{{ timeselect }}" hours="12"
            onchange="timeonchange" oncancel="timeoncancel" class="pickertime" show="false"></picker>

    <picker id="picker3" type="datetime" value="{{ datetimevalue }}" selected="{{ datetimeselect }}" hours="24"
            lunarswitch="true"
            onchange="datetimeonchange" oncancel="datetimeoncancel" class="pickerdatetime" show="false"></picker>

    <picker id="picker4" type="multi-text" value="{{ multitextvalue }}" columns="3" range="{{ multitext }}"
            selected="{{ multitextselect }}"
            onchange="multitextonchange" oncancel="multitextoncancel" class="pickermuitl" show="false"></picker>
</div>
```

```css
/* xxx.css */
.container {
    flex-direction: column;
    justify-content: center;
    align-items: center;
}

picker {
    width: 60%;
    height: 80px;
    border-radius: 20px;
    text-color: white;
    font-size: 15px;
    background-color: #4747e3;
    margin-left: 20%;
}

select {
    background-color: #efecec;
    height: 50px;
    width: 60%;
    margin-left: 20%;
    margin-top: 300px;
    margin-bottom: 50px;
    font-size: 22px;
}
```

```js
// xxx.js
import promptAction from '@ohos.promptAction';

export default {
    data: {
        selectList: ["text", "data", "time", "datetime", "multitext"],
        rangetext: ['15', "20", "25"],
        multitext: [["a", "b", "c"], ["e", "f", "g"], ["h", "i"], ["k", "l", "m"]],
        textvalue: 'default textvalue',
        datevalue: 'default datevalue',
        timevalue: 'default timevalue',
        datetimevalue: 'default datetimevalue',
        multitextvalue: 'default multitextvalue',
        containsecond: true,
        multitextselect: [1, 2, 0],
        datetimeselect: '2012-5-6-11-25',
        timeselect: '11:22:30',
        dateselect: '2021-3-2',
        textselect: '2'
    },
    selectChange(e) {
        for (let i = 0;i < this.selectList.length; i++) {
            if (e.newValue == this.selectList[i]) {
                this.$element("picker" + i).show();
            }
        }
    },
    textonchange(e) {
        this.textvalue = e.newValue;
        promptAction.showToast({
            message: "text:" + e.newValue + ",newSelected:" + e.newSelected
        })
    },
    textoncancel(e) {
        promptAction.showToast({
            message: "text: textoncancel"
        })
    },
    dateonchange(e) {
        this.datevalue = e.year + "-" + e.month + "-" + e.day;
        promptAction.showToast({
            message: "date:" + e.year + "-" + (e.month + 1) + "-" + e.day
        })
    },
    dateoncancel() {
        promptAction.showToast({
            message: "date: dateoncancel"
        })
    },
    timeonchange(e) {
        if (this.containsecond) {
            this.timevalue = e.hour + ":" + e.minute + ":" + e.second;
            promptAction.showToast({
                message: "Time:" + e.hour + ":" + e.minute + ":" + e.second
            })
        } else {
            this.timevalue = e.hour + ":" + e.minute;
            promptAction.showToast({
                message: "Time:" + e.hour + ":" + e.minute
            })
        }
    },
    timeoncancel() {
        promptAction.showToast({
            message: "timeoncancel"
        })
    },
    datetimeonchange(e) {
        this.datetimevalue = e.year + "-" + e.month + "-" + e.day + " " + e.hour + ":" + e.minute;
        promptAction.showToast({
            message: "Time:" + (e.month + 1) + "-" + e.day + " " + e.hour + ":" + e.minute
        })
    },
    datetimeoncancel() {
        promptAction.showToast({
            message: "datetimeoncancel"
        })
    },
    multitextonchange(e) {
        this.multitextvalue = e.newValue;
        promptAction.showToast({
            message: "Multi-column text change" + e.newValue
        })
    },
    multitextoncancel() {
        promptAction.showToast({
            message: "multitextoncancel"
        })
    },
    popup_picker() {
        this.$element("picker_text").show();
    },
}
```

![mmmm](figures/mmmm.gif)
