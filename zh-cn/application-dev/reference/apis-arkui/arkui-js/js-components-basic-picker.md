# picker

>  **说明：**
>  从API version 4开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

滑动选择器组件，类型支持普通选择器、日期选择器、时间选择器、时间日期选择器和多列文本选择器。


## 权限列表

无


## 子组件

不支持。


## 属性

除支持[通用属性](js-components-common-attributes.md)外，还支持如下属性：

| 名称   | 类型     | 默认值  | 必填   | 描述                                       |
| ---- | ------ | ---- | ---- | ---------------------------------------- |
| type | string | -    | 否    | 该属性值不支持动态修改。可选择项有：<br/>-&nbsp;text：文本选择器。<br/>-&nbsp;date：日期选择器。<br/>-&nbsp;time：时间选择器。<br/>-&nbsp;datetime：日期时间选择器。<br/>-&nbsp;multi-text：多列文本选择器。 |


### 普通选择器

滑动选择器类型设置为text时表示普通选择器。

| 名称       | 类型     | 默认值  | 必填   | 描述                                       |
| -------- | ------ | ---- | ---- | ---------------------------------------- |
| range    | Array  | -    | 否    | 设置普通选择器的取值范围，如["15",&nbsp;"20",&nbsp;"25"]。<br/>使用时需要使用数据绑定的方式`range ={{data}}`，js中声明相应变量`data：["15","20","25"]`。 |
| selected | string | 0    | 否    | 设置普通选择器弹窗的默认取值，取值需要是&nbsp;range&nbsp;的索引值，该取值表示选择器弹窗界面的默认选择值。 |
| value    | string | -    | 否    | 设置普通选择器的值。                               |


### 日期选择器

滑动选择器类型设置为date时表示日期选择器。

| 名称                 | 类型           | 默认值        | 必填   | 描述                                       |
| ------------------ | ------------ | ---------- | ---- | ---------------------------------------- |
| start              | &lt;time&gt; | 1970-1-1   | 否    | 设置日期选择器的起始时间，格式为&nbsp;YYYY-MM-DD。        |
| end                | &lt;time&gt; | 2100-12-31 | 否    | 设置日期选择器的结束时间，格式为&nbsp;YYYY-MM-DD。        |
| selected           | string       | 当前日期       | 否    | 设置日期选择器弹窗的默认取值，格式为&nbsp;YYYY-MM-DD，该取值表示选择器弹窗界面的默认选择值。 |
| value              | string       | -          | 是    | 设置日期选择器的值。                               |
| lunar<sup>5+</sup> | boolean      | false      | 否    | 设置日期选择器是否为农历展示。<br/>默认值：false，表示设置日期选择器是公历展示。                      |
| lunarswitch        | boolean      | false      | 否    | 设置日期选择器是否显示农历开关。当值为true时，显示农历开关，点击农历开关可切换公历和农历。当值为false时，不显示农历开关。<br/>当lunarswitch=true且lunar=true时，开关按钮处于被选中状态。 |


### 时间选择器

滑动选择器类型设置为time时表示时间选择器。

| 名称            | 类型      | 默认值                                 | 必填   | 描述                                       |
| ------------- | ------- | ----------------------------------- | ---- | ---------------------------------------- |
| containsecond | boolean | false                               | 否    | 设置时间选择器是否包含秒。 <br/>默认值：false，表示设置时间选择器不包含秒。                           |
| selected      | string  | 当前时间                                | 否    | 设置时间选择器弹窗的默认取值，格式为&nbsp;HH:mm；当包含秒时，格式为HH:mm:ss，<br/>该取值表示选择器弹窗界面的默认选择值。 |
| value         | string  | -                                   | 否    | 设置时间选择器的值。                               |
| hours         | number  | 24<sup>1-4</sup><br/>-<sup>5+</sup> | 否    | 设置时间选择器采用的时间格式，可选值：<br/>-&nbsp;12：按照12小时制显示，用上午和下午进行区分；<br/>-&nbsp;24：按照24小时制显示。<br/>从API Version 5开始，默认值会依据系统当前所选地区和语言选择当地习惯的小时制(12小时制或24小时制)。 |


### 日期时间选择器

滑动选择器类型设置为datetime时表示日期时间选择器，日期的选择范围为本年的日月。

| 名称                 | 类型      | 默认值                                 | 必填   | 描述                                       |
| ------------------ | ------- | ----------------------------------- | ---- | ---------------------------------------- |
| selected           | string  | 当前日期时间                              | 否    | 设置日期时间选择器弹窗的默认取值，有两种可选格式。<br/>-&nbsp;月日时分：MM-DD-HH-mm<br/>-&nbsp;年月日时分：YYYY-MM-DD-HH-mm<br/>不设置年时，默认使用当前年，该取值表示选择器弹窗界面的默认选择值。 |
| value              | string  | -                                   | 是    | 设置日期时间选择器的值。                             |
| hours              | number  | 24<sup>1-4</sup><br/>-<sup>5+</sup> | 否    | 设置日期时间选择器采用的时间格式，可选值：<br/>-&nbsp;12：按照12小时制显示，用上午和下午进行区分；<br/>-&nbsp;24：按照24小时制显示。<br/>从API Version 5开始，默认值会依据系统当前所选地区和语言选择当地习惯的小时制(12小时制或24小时制)。 |
| lunar<sup>5+</sup> | boolean | false                               | 否    | 设置日期时间选择器是否为农历展示。<br/>默认值：false，表示设置日期选择器为公历展示。                    |
| lunarswitch        | boolean | false                               | 否    | 设置日期选择器是否显示农历开关。当值为true时，显示农历开关，点击农历开关可切换公历和农历。当值为false时，不显示农历开关。<br/>当lunarswitch=true且lunar=true时，开关按钮处于被选中状态。 |


### 多列文本选择器

滑动选择器类型设置为multi-text时表示多列文本选择器。

| 名称       | 类型      | 默认值       | 必填   | 描述                                       |
| -------- | ------- | --------- | ---- | ---------------------------------------- |
| columns  | number  | -         | 是    | 设置多列文本选择器的列数。                            |
| range    | 二维Array | -         | 否    | 设置多列文本选择器的选择项，其中range&nbsp;为二维数组。长度表示多少列，数组的每项表示每列的数据，如&nbsp;&nbsp;[["a","b"],&nbsp;["c","d"]]。<br/>使用时需要使用数据绑定的方式`range ={{data}}`，js中声明相应变量`data：["15","20","25"]`。 |
| selected | Array   | [0,0,0,…] | 否    | 设置多列文本选择器弹窗的默认值，每一列被选中项对应的索引构成的数组，该取值表示选择器弹窗界面的默认选择值。 |
| value    | Array   | -         | 否    | 设置多列文本选择器的值，每一列被选中项对应的值构成的数组。            |


## 样式

除支持[通用样式](js-components-common-styles.md)外，还支持如下样式：

| 名称                         | 类型                         | 默认值        | 必填   | 描述                                       |
| -------------------------- | -------------------------- | ---------- | ---- | ---------------------------------------- |
| text-color                 | &lt;color&gt;              | -          | 否    | 选择器的文本颜色。                                |
| font-size                  | &lt;length&gt;             | -          | 否    | 选择器的文本尺寸。                                |
| allow-scale                | boolean                    | true       | 否    | 选择器的文本尺寸是否跟随系统设置字体缩放尺寸进行放大缩小。<br/>如果在config描述文件中针对ability配置了fontSize的config-changes标签，则应用不会重启而直接生效。<br/>默认值：true，表示选择器的文本尺寸跟随系统设置字体缩放尺寸进行放大缩小。 |
| letter-spacing             | &lt;length&gt;             | 0          | 否    | 选择器的字符间距。见[text组件的letter-spacing样式属性](js-components-basic-text.md#样式)。 |
| text-decoration            | string                     | -          | 否    | 选择器的文本修饰。见[text组件的text-decoration样式属性](js-components-basic-text.md#样式)。 |
| font-style                 | string                     | normal     | 否    | 选择器的字体样式。见[text组件的font-style样式属性](js-components-basic-text.md#样式)。 |
| font-weight                | number&nbsp;\|&nbsp;string | normal     | 否    | 选择器的字体粗细。见[text组件的font-weight样式属性](js-components-basic-text.md#样式)。 |
| font-family                | string                     | sans-serif | 否    | 选择器的字体列表，用逗号分隔，每个字体用字体名或者字体族名设置。列表中第一个系统中存在的或者通过[自定义字体](js-components-common-customizing-font.md)指定的字体，会被选中作为文本的字体。 |
| line-height                | &lt;length&gt;             | 0px        | 否    | 选择器的文本行高。                                |
| column-height<sup>5+</sup> | &lt;length&gt;             | -          | 否    | 选择器的选择项列表高度。                             |


## 事件

除支持[通用事件](js-components-common-events.md)外，还支持如下事件：


### 普通选择器

| 名称     | 参数                                       | 描述                                       |
| ------ | ---------------------------------------- | ---------------------------------------- |
| change | {&nbsp;newValue:&nbsp;newValue,&nbsp;newSelected:&nbsp;newSelected&nbsp;} | 普通选择器选择值后点击弹窗中的确定按钮时触发该事件（newSelected为索引）。 |
| cancel | -                                        | 用户点击弹窗中的取消按钮时触发该事件。                      |


### 日期选择器

| 名称     | 参数                                       | 描述                                       |
| ------ | ---------------------------------------- | ---------------------------------------- |
| change | {&nbsp;year:&nbsp;year,&nbsp;month:&nbsp;month,&nbsp;day:&nbsp;day&nbsp;} | 日期选择器选择值后点击弹窗中的确认按钮时触发该事件。<br/>从API Version 5开始，month值范围为：&nbsp;0（1月）~11（12月）。 |
| cancel | -                                        | 用户点击弹窗中的取消按钮时触发该事件。                      |


### 日期时间选择器

| 名称     | 参数                                       | 描述                           |
| ------ | ---------------------------------------- | ---------------------------- |
| change | {&nbsp;year:&nbsp;year,&nbsp;month:&nbsp;month,&nbsp;day:&nbsp;day,&nbsp;&nbsp;hour:&nbsp;hour,&nbsp;minute:&nbsp;minute} | 日期时间选择器选择值后点击弹窗中的确认按钮时触发该事件。 |
| cancel | -                                        | 用户点击弹窗中的取消按钮时触发该事件。          |


### 时间选择器

| 名称     | 参数                                       | 描述                                       |
| ------ | ---------------------------------------- | ---------------------------------------- |
| change | {&nbsp;hour:&nbsp;hour,&nbsp;minute:&nbsp;minute,&nbsp;[second:&nbsp;second]&nbsp;} | 时间选择器选择值后点击弹窗中的确认按钮时触发该事件，当使用时分秒时，还包含秒数据。 |
| cancel | -                                        | 用户点击弹窗中的取消按钮时触发该事件。                      |


### 多列文本选择器

| 名称           | 参数                                       | 描述                                       |
| ------------ | ---------------------------------------- | ---------------------------------------- |
| change       | {&nbsp;newValue:&nbsp;[newValue1,&nbsp;newValue2,&nbsp;newValue3,&nbsp;…],&nbsp;newSelected:[newSelected1,&nbsp;newSelected2,&nbsp;newSelected3,&nbsp;…]&nbsp;} | 多列文本选择器选择值后点击弹窗中的确认按钮时触发该事件，其中：<br/>-&nbsp;newValue：被选中项对应的值构成的数组。<br/>-&nbsp;newSelected：被选中项对应的索引构成的数组，两者的长度和range的长度一致。 |
| columnchange | {&nbsp;column:&nbsp;column,&nbsp;newValue:&nbsp;newValue,&nbsp;newSelected:&nbsp;newSelected&nbsp;} | 多列文本选择器中某一列的值改变时触发该事件，其中：<br/>-&nbsp;column：第几列修改。<br/>-&nbsp;newValue：选中的值。<br/>-&nbsp;newSelected：选中值对应的索引。 |
| cancel       | -                                        | 用户点击弹窗中的取消按钮时触发该事件。                      |


## 方法

除支持[通用方法](js-components-common-methods.md)外，支持如下方法：

| 名称   | 参数   | 描述              |
| ---- | ---- | --------------- |
| show | -    | 显示&nbsp;picker。 |


## 示例

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

![zh-cn_image_0000001191939702](figures/zh-cn_image_0000001191939702.gif)
