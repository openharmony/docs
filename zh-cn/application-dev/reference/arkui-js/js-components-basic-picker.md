# picker<a name="ZH-CN_TOPIC_0000001173324637"></a>

滑动选择器组件，类型支持普通选择器、日期选择器、时间选择器、时间日期选择器和多列文本选择器。

## 权限列表<a name="section11257113618419"></a>

无

## 子组件<a name="section9288143101012"></a>

不支持。

## 属性<a name="section2907183951110"></a>

除支持[通用属性](js-components-common-attributes.md)外，还支持如下属性：↵

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.48%" id="mcps1.1.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.46%" id="mcps1.1.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="35.82%" id="mcps1.1.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>type</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.46%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.82%" headers="mcps1.1.6.1.5 "><p>该属性值不支持动态修改。可选择项有：</p>
<ul><li>text：文本选择器。</li><li>date：日期选择器。</li><li>time：时间选择器。</li><li>datetime：日期时间选择器。</li><li>multi-text：多列文本选择器。</li></ul>
</td>
</tr>
</tbody>
</table>

### 普通选择器<a name="section28061337142416"></a>

滑动选择器类型设置为text时表示普通选择器。

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="24.000000000000004%" id="mcps1.1.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="10.810000000000002%" id="mcps1.1.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.63%" id="mcps1.1.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.850000000000001%" id="mcps1.1.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="48.71%" id="mcps1.1.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p>range</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p>Array</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.850000000000001%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="48.71%" headers="mcps1.1.6.1.5 "><p>设置普通选择器的取值范围，如["15", "20", "25"]。</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>使用时需要使用数据绑定的方式，如range = {{data}}，js中声明相应变量：data：["15", "20", "25"]。</p>
</div></div>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p>selected</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.850000000000001%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="48.71%" headers="mcps1.1.6.1.5 "><p>设置普通选择器弹窗的默认取值，取值需要是 range 的索引值，该取值表示选择器弹窗界面的默认选择值。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p>value</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.850000000000001%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="48.71%" headers="mcps1.1.6.1.5 "><p>设置普通选择器的值。</p>
</td>
</tr>
</tbody>
</table>

### 日期选择器<a name="section194021642517"></a>

滑动选择器类型设置为date时表示日期选择器。

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="24.000000000000004%" id="mcps1.1.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="10.810000000000002%" id="mcps1.1.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.63%" id="mcps1.1.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.15%" id="mcps1.1.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="49.410000000000004%" id="mcps1.1.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p>start</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p>&lt;time&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p>1970-1-1</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p>设置日期选择器的起始时间，格式为 YYYY-MM-DD。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p>end</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p>&lt;time&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p>2100-12-31</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p>设置日期选择器的结束时间，格式为 YYYY-MM-DD。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p>selected</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p>当前日期</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p>设置日期选择器弹窗的默认取值，格式为 YYYY-MM-DD，该取值表示选择器弹窗界面的默认选择值。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p>value</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p>是</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p>设置日期选择器的值。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p>lunar<sup>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p>设置日期选择器弹窗界面是否为农历展示。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p>lunarswitch</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p>设置日期选择器是否显示农历开关。当值为true时，显示农历开关，点击农历开关可切换公历和农历。当值为false时，不显示农历开关。</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>仅手机和平板设备支持。 当lunarswitch=true且lunar=true时，开关按钮处于被选中状态。</p>
</div></div>
</td>
</tr>
</tbody>
</table>

### 时间选择器<a name="section14386134222510"></a>

滑动选择器类型设置为time时表示时间选择器。

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="24.000000000000004%" id="mcps1.1.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="10.810000000000002%" id="mcps1.1.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.63%" id="mcps1.1.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.15%" id="mcps1.1.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="49.410000000000004%" id="mcps1.1.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p>containsecond</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p>设置时间选择器是否包含秒。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p>selected</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p>当前时间</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p>设置时间选择器弹窗的默认取值，格式为 HH:mm；当包含秒时，格式为HH:mm:ss，</p>
<p>该取值表示选择器弹窗界面的默认选择值。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p>value</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p>设置时间选择器的值。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p>hours</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p>24<sup>1-4</sup></p>
<p>-<sup><span>5+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p>设置时间选择器采用的时间格式，可选值：</p>
<ul><li>12：按照12小时制显示，用上午和下午进行区分；</li><li>24：按照24小时制显示。<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>默认值会依据系统当前所选地区和语言选择当地习惯的小时制(12小时制或24小时制)。<sup><span>5+</span></sup></p>
</div></div>
</li></ul>
</td>
</tr>
</tbody>
</table>

### 日期时间选择器<a name="section10180192513261"></a>

滑动选择器类型设置为datetime时表示日期时间选择器，日期的选择范围为本年的日月。

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="23.98%" id="mcps1.1.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="10.83%" id="mcps1.1.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.63%" id="mcps1.1.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.1499999999999995%" id="mcps1.1.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="49.41%" id="mcps1.1.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="23.98%" headers="mcps1.1.6.1.1 "><p>selected</p>
</td>
<td class="cellrowborder" valign="top" width="10.83%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p>当前日期时间</p>
</td>
<td class="cellrowborder" valign="top" width="7.1499999999999995%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.41%" headers="mcps1.1.6.1.5 "><p>设置日期时间选择器弹窗的默认取值，有两种可选格式。</p>
<ul><li>月日时分：MM-DD-HH-mm</li><li>年月日时分：YYYY-MM-DD-HH-mm</li></ul>
<p>不设置年时，默认使用当前年，该取值表示选择器弹窗界面的默认选择值。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.98%" headers="mcps1.1.6.1.1 "><p>value</p>
</td>
<td class="cellrowborder" valign="top" width="10.83%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.1499999999999995%" headers="mcps1.1.6.1.4 "><p>是</p>
</td>
<td class="cellrowborder" valign="top" width="49.41%" headers="mcps1.1.6.1.5 "><p>设置日期时间选择器的值。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.98%" headers="mcps1.1.6.1.1 "><p>hours</p>
</td>
<td class="cellrowborder" valign="top" width="10.83%" headers="mcps1.1.6.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p>24<sup>1-4</sup></p>
<p>-<sup><span>5+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="7.1499999999999995%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.41%" headers="mcps1.1.6.1.5 "><p>设置日期时间选择器采用的时间格式，可选值：</p>
<ul><li>12：按照12小时制显示，用上午和下午进行区分；</li><li>24：按照24小时制显示。<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>默认值会依据系统当前所选地区和语言选择当地习惯的小时制(12小时制或24小时制)。<sup><span>5+</span></sup></p>
</div></div>
</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.98%" headers="mcps1.1.6.1.1 "><p>lunar<sup>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="10.83%" headers="mcps1.1.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.1499999999999995%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.41%" headers="mcps1.1.6.1.5 "><p>设置日期时间选择器弹窗界面是否为农历展示。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.98%" headers="mcps1.1.6.1.1 "><p>lunarswitch</p>
</td>
<td class="cellrowborder" valign="top" width="10.83%" headers="mcps1.1.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.1499999999999995%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.41%" headers="mcps1.1.6.1.5 "><p>设置日期选择器是否显示农历开关。当值为true时，显示农历开关，点击农历开关可切换公历和农历。当值为false时，不显示农历开关。</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>仅手机和平板设备支持。 当lunarswitch=true且lunar=true时，开关按钮处于被选中状态。</p>
</div></div>
</td>
</tr>
</tbody>
</table>

### 多列文本选择器<a name="section18757165414262"></a>

滑动选择器类型设置为multi-text时表示多列文本选择器。

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="24.000000000000004%" id="mcps1.1.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="10.810000000000002%" id="mcps1.1.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.63%" id="mcps1.1.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.15%" id="mcps1.1.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="49.410000000000004%" id="mcps1.1.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p>columns</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p>是</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p>设置多列文本选择器的列数。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p>range</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p>二维Array</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p>设置多列文本选择器的选择项，其中range 为二维数组。长度表示多少列，数组的每项表示每列的数据，如  [["a","b"], ["c","d"]]。</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>使用时需要使用数据绑定的方式，如range = {{data}}，js中声明相应变量：data：[["a","b"], ["c","d"]]。</p>
</div></div>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p>selected</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p>Array</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p>[0,0,0,…]</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p>设置多列文本选择器弹窗的默认值，每一列被选中项对应的索引构成的数组，该取值表示选择器弹窗界面的默认选择值。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p>value</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p>Array</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p>设置多列文本选择器的值，每一列被选中项对应的值构成的数组。</p>
</td>
</tr>
</tbody>
</table>

## 样式<a name="section1299175511712"></a>

除支持[通用样式](js-components-common-styles.md)外，还支持如下样式：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="14.318568143185681%" id="mcps1.1.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="11.528847115288471%" id="mcps1.1.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="13.268673132686734%" id="mcps1.1.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="8.60913908609139%" id="mcps1.1.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="52.274772522747725%" id="mcps1.1.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="14.318568143185681%" headers="mcps1.1.6.1.1 "><p>text-color</p>
</td>
<td class="cellrowborder" valign="top" width="11.528847115288471%" headers="mcps1.1.6.1.2 "><p>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.268673132686734%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.60913908609139%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.274772522747725%" headers="mcps1.1.6.1.5 "><p>选择器的文本颜色。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="14.318568143185681%" headers="mcps1.1.6.1.1 "><p>font-size</p>
</td>
<td class="cellrowborder" valign="top" width="11.528847115288471%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.268673132686734%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.60913908609139%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.274772522747725%" headers="mcps1.1.6.1.5 "><p>选择器的文本尺寸。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="14.318568143185681%" headers="mcps1.1.6.1.1 "><p>allow-scale</p>
</td>
<td class="cellrowborder" valign="top" width="11.528847115288471%" headers="mcps1.1.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="13.268673132686734%" headers="mcps1.1.6.1.3 "><p>true</p>
</td>
<td class="cellrowborder" valign="top" width="8.60913908609139%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.274772522747725%" headers="mcps1.1.6.1.5 "><p>选择器的文本尺寸是否跟随系统设置字体缩放尺寸进行放大缩小。</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>如果在config描述文件中针对ability配置了fontSize的config-changes标签，则应用不会重启而直接生效。</p>
</div></div>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="14.318568143185681%" headers="mcps1.1.6.1.1 "><p>letter-spacing</p>
</td>
<td class="cellrowborder" valign="top" width="11.528847115288471%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.268673132686734%" headers="mcps1.1.6.1.3 "><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="8.60913908609139%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.274772522747725%" headers="mcps1.1.6.1.5 "><p>选择器的字符间距。见<a href="js-components-basic-text.md#section5775351116">text组件的letter-spacing样式属性</a>。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="14.318568143185681%" headers="mcps1.1.6.1.1 "><p>text-decoration</p>
</td>
<td class="cellrowborder" valign="top" width="11.528847115288471%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.268673132686734%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.60913908609139%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.274772522747725%" headers="mcps1.1.6.1.5 "><p>选择器的文本修饰。见<a href="js-components-basic-text.md#section5775351116">text组件的text-decoration样式属性</a>。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="14.318568143185681%" headers="mcps1.1.6.1.1 "><p>font-style</p>
</td>
<td class="cellrowborder" valign="top" width="11.528847115288471%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.268673132686734%" headers="mcps1.1.6.1.3 "><p>normal</p>
</td>
<td class="cellrowborder" valign="top" width="8.60913908609139%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.274772522747725%" headers="mcps1.1.6.1.5 "><p>选择器的字体样式。见<a href="js-components-basic-text.md#section5775351116">text组件的font-style样式属性</a>。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="14.318568143185681%" headers="mcps1.1.6.1.1 "><p>font-weight</p>
</td>
<td class="cellrowborder" valign="top" width="11.528847115288471%" headers="mcps1.1.6.1.2 "><p>number | string</p>
</td>
<td class="cellrowborder" valign="top" width="13.268673132686734%" headers="mcps1.1.6.1.3 "><p>normal</p>
</td>
<td class="cellrowborder" valign="top" width="8.60913908609139%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.274772522747725%" headers="mcps1.1.6.1.5 "><p>选择器的字体粗细。见<a href="js-components-basic-text.md#section5775351116">text组件的font-weight样式属性</a>。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="14.318568143185681%" headers="mcps1.1.6.1.1 "><p>font-family</p>
</td>
<td class="cellrowborder" valign="top" width="11.528847115288471%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.268673132686734%" headers="mcps1.1.6.1.3 "><p>sans-serif</p>
</td>
<td class="cellrowborder" valign="top" width="8.60913908609139%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.274772522747725%" headers="mcps1.1.6.1.5 "><p>选择器的字体列表，用逗号分隔，每个字体用字体名或者字体族名设置。列表中第一个系统中存在的或者通过<a href="js-components-common-customizing-font.md">自定义字体</a>指定的字体，会被选中作为文本的字体。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="14.318568143185681%" headers="mcps1.1.6.1.1 "><p>line-height</p>
</td>
<td class="cellrowborder" valign="top" width="11.528847115288471%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.268673132686734%" headers="mcps1.1.6.1.3 "><p>0px</p>
</td>
<td class="cellrowborder" valign="top" width="8.60913908609139%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.274772522747725%" headers="mcps1.1.6.1.5 "><p>选择器的文本行高。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="14.318568143185681%" headers="mcps1.1.6.1.1 "><p>column-height<sup>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="11.528847115288471%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.268673132686734%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.60913908609139%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.274772522747725%" headers="mcps1.1.6.1.5 "><p>选择器的选择项列表高度。</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>仅手机和平板设备支持。</p>
</div></div>
</td>
</tr>
</tbody>
</table>

## 事件<a name="section1724215114357"></a>

除支持[通用事件](js-components-common-events.md)外，还支持如下事件：

### 普通选择器<a name="section167201221192710"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="15.370000000000001%" id="mcps1.1.4.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="34.22%" id="mcps1.1.4.1.2"><p>参数</p>
</th>
<th class="cellrowborder" valign="top" width="50.41%" id="mcps1.1.4.1.3"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="15.370000000000001%" headers="mcps1.1.4.1.1 "><p>change</p>
</td>
<td class="cellrowborder" valign="top" width="34.22%" headers="mcps1.1.4.1.2 "><p>{ newValue: newValue, newSelected: newSelected }</p>
</td>
<td class="cellrowborder" valign="top" width="50.41%" headers="mcps1.1.4.1.3 "><p>普通选择器选择值后点击弹窗中的确定按钮时触发该事件（newSelected为索引）。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="15.370000000000001%" headers="mcps1.1.4.1.1 "><p>cancel</p>
</td>
<td class="cellrowborder" valign="top" width="34.22%" headers="mcps1.1.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="50.41%" headers="mcps1.1.4.1.3 "><p>用户点击弹窗中的取消按钮时触发该事件。</p>
</td>
</tr>
</tbody>
</table>

### 日期选择器<a name="section161113322714"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="15.370000000000001%" id="mcps1.1.4.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="34.18%" id="mcps1.1.4.1.2"><p>参数</p>
</th>
<th class="cellrowborder" valign="top" width="50.449999999999996%" id="mcps1.1.4.1.3"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="15.370000000000001%" headers="mcps1.1.4.1.1 "><p>change</p>
</td>
<td class="cellrowborder" valign="top" width="34.18%" headers="mcps1.1.4.1.2 "><p>{ year: year, month: month, day: day }</p>
</td>
<td class="cellrowborder" valign="top" width="50.449999999999996%" headers="mcps1.1.4.1.3 "><p>日期选择器选择值后点击弹窗中的确认按钮时触发该事件。</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>month值范围为： 0（1月）~11（12月）。<sup><span>5+</span></sup></p>
</div></div>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="15.370000000000001%" headers="mcps1.1.4.1.1 "><p>cancel</p>
</td>
<td class="cellrowborder" valign="top" width="34.18%" headers="mcps1.1.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="50.449999999999996%" headers="mcps1.1.4.1.3 "><p>用户点击弹窗中的取消按钮时触发该事件。</p>
</td>
</tr>
</tbody>
</table>

### 日期时间选择器<a name="section15386114572710"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="15.370000000000001%" id="mcps1.1.4.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="39.82%" id="mcps1.1.4.1.2"><p>参数</p>
</th>
<th class="cellrowborder" valign="top" width="44.81%" id="mcps1.1.4.1.3"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="15.370000000000001%" headers="mcps1.1.4.1.1 "><p>change</p>
</td>
<td class="cellrowborder" valign="top" width="39.82%" headers="mcps1.1.4.1.2 "><p>{ year: year, month: month, day: day,  hour: hour, minute: minute}</p>
</td>
<td class="cellrowborder" valign="top" width="44.81%" headers="mcps1.1.4.1.3 "><p>日期时间选择器选择值后点击弹窗中的确认按钮时触发该事件。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="15.370000000000001%" headers="mcps1.1.4.1.1 "><p>cancel</p>
</td>
<td class="cellrowborder" valign="top" width="39.82%" headers="mcps1.1.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="44.81%" headers="mcps1.1.4.1.3 "><p>用户点击弹窗中的取消按钮时触发该事件。</p>
</td>
</tr>
</tbody>
</table>

### 时间选择器<a name="section17835159152813"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="15.370000000000001%" id="mcps1.1.4.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="34.22%" id="mcps1.1.4.1.2"><p>参数</p>
</th>
<th class="cellrowborder" valign="top" width="50.41%" id="mcps1.1.4.1.3"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="15.370000000000001%" headers="mcps1.1.4.1.1 "><p>change</p>
</td>
<td class="cellrowborder" valign="top" width="34.22%" headers="mcps1.1.4.1.2 "><p>{ hour: hour, minute: minute, [second: second] }</p>
</td>
<td class="cellrowborder" valign="top" width="50.41%" headers="mcps1.1.4.1.3 "><p>时间选择器选择值后点击弹窗中的确认按钮时触发该事件，当使用时分秒时，还包含秒数据。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="15.370000000000001%" headers="mcps1.1.4.1.1 "><p>cancel</p>
</td>
<td class="cellrowborder" valign="top" width="34.22%" headers="mcps1.1.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="50.41%" headers="mcps1.1.4.1.3 "><p>用户点击弹窗中的取消按钮时触发该事件。</p>
</td>
</tr>
</tbody>
</table>

### 多列文本选择器<a name="section126981922162818"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="13.969999999999999%" id="mcps1.1.4.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="36.9%" id="mcps1.1.4.1.2"><p>参数</p>
</th>
<th class="cellrowborder" valign="top" width="49.13%" id="mcps1.1.4.1.3"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="13.969999999999999%" headers="mcps1.1.4.1.1 "><p>change</p>
</td>
<td class="cellrowborder" valign="top" width="36.9%" headers="mcps1.1.4.1.2 "><p>{ newValue: [newValue1, newValue2, newValue3, …], newSelected:[newSelected1, newSelected2, newSelected3, …] }</p>
</td>
<td class="cellrowborder" valign="top" width="49.13%" headers="mcps1.1.4.1.3 "><p>多列文本选择器选择值后点击弹窗中的确认按钮时触发该事件，其中：</p>
<ul><li>newValue：被选中项对应的值构成的数组。</li><li>newSelected：被选中项对应的索引构成的数组，两者的长度和range的长度一致。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="13.969999999999999%" headers="mcps1.1.4.1.1 "><p>columnchange</p>
</td>
<td class="cellrowborder" valign="top" width="36.9%" headers="mcps1.1.4.1.2 "><p>{ column: column, newValue: newValue, newSelected: newSelected }</p>
</td>
<td class="cellrowborder" valign="top" width="49.13%" headers="mcps1.1.4.1.3 "><p>多列文本选择器中某一列的值改变时触发该事件，其中：</p>
<ul><li>column：第几列修改。</li><li>newValue：选中的值。</li><li>newSelected：选中值对应的索引。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="13.969999999999999%" headers="mcps1.1.4.1.1 "><p>cancel</p>
</td>
<td class="cellrowborder" valign="top" width="36.9%" headers="mcps1.1.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="49.13%" headers="mcps1.1.4.1.3 "><p>用户点击弹窗中的取消按钮时触发该事件。</p>
</td>
</tr>
</tbody>
</table>

## 方法<a name="section47669296127"></a>

除支持[通用方法](js-components-common-methods.md)外，支持如下方法：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="23%" id="mcps1.1.4.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="32%" id="mcps1.1.4.1.2"><p>参数</p>
</th>
<th class="cellrowborder" valign="top" width="45%" id="mcps1.1.4.1.3"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="23%" headers="mcps1.1.4.1.1 "><p>show</p>
</td>
<td class="cellrowborder" valign="top" width="32%" headers="mcps1.1.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="45%" headers="mcps1.1.4.1.3 "><p>显示 picker。</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section11956342165513"></a>

```
<!-- xxx.hml -->
<div class="container">
  <select @change="selectChange">
        <option value="{{ item }}" for="item in selectList">
            {{ item }}
        </option>
  </select>
  <picker id="picker0" type="text" value="{{textvalue}}" selected="{{textselect}}" range="{{rangetext}}" onchange="textonchange"
    oncancel="textoncancel" class="pickertext"  "></picker>

  <picker id="picker1" type="date" value="{{datevalue}}" start="2002-2-5" end="2030-6-5" selected="{{dateselect}}" lunarswitch="true"
    onchange="dateonchange" oncancel="dateoncancel" class="pickerdate" show="false"></picker>

  <picker id="picker2" type="time" value="{{timevalue}}" containsecond="{{containsecond}}" selected="{{timeselect}}" hours="12"
    onchange="timeonchange" oncancel="timeoncancel" class="pickertime" show="false"></picker>

  <picker id="picker3" type="datetime" value="{{datetimevalue}}" selected="{{datetimeselect}}" hours="24" lunarswitch="true"
    onchange="datetimeonchange" oncancel="datetimeoncancel" class="pickerdatetime" show="false"></picker>

  <picker id="picker4" type="multi-text" value="{{multitextvalue}}" columns="3" range="{{multitext}}" selected="{{multitextselect}}"
    onchange="multitextonchange" oncancel="multitextoncancel" class="pickermuitl" show="false"></picker>
</div>
```

```
/* xxx.css */
.container {    
  flex-direction: column;
  justify-content: center;
  align-items: center;
}
 picker{
  width:60%;
  height:80px;
  border-radius:20px;
  text-color:white;
  font-size:15px;
  background-color:#4747e3;
  margin-left:20%;
}
 select{
  background-color: #efecec;
  height: 50px;
  width: 60%;
  margin-left: 20%;
  margin-top: 300px;
  margin-bottom: 50px;
  font-size: 22px;
}
```

```
// xxx.js
import router from '@system.router';
import prompt from '@system.prompt';
export default {
  data: {    
    selectList:["text","data","time","datetime","multitext"],
    rangetext:['15', "20", "25"],    
    multitext:[["a", "b", "c"], ["e", "f", "g"], ["h", "i"], ["k", "l", "m"]],    
    textvalue:'default textvalue',    
    datevalue:'default datevalue',    
    timevalue:'default timevalue',    
    datetimevalue:'default datetimevalue',    
    multitextvalue:'default multitextvalue',    
    containsecond:true,    
    multitextselect:[1,2,0],    
    datetimeselect:'2012-5-6-11-25',    
    timeselect:'11:22:30',    
    dateselect:'2021-3-2',    
    textselect:'2'
  },
  selectChange(e){
        for(let i = 0;i<this.selectList.length;i++){
            if(e.newValue == this.selectList[i]){
                this.$element("picker"+i).show();
            }
        }
    },
  textonchange(e) {    
    this.textvalue = e.newValue;    
    prompt.showToast({ message:"text:"+e.newValue+",newSelected:"+e.newSelected })
  },
  textoncancel(e) {    
    prompt.showToast({ message:"text: textoncancel" })
  },
  dateonchange(e) {    
    this.datevalue = e.year + "-" + e.month + "-" + e.day;    
    prompt.showToast({ message:"date:"+e.year+"-"+(e.month+1)+"-"+e.day })
  },
  dateoncancel() {    
    prompt.showToast({ message:"date: dateoncancel" })
  },
  timeonchange(e) {    
    if(this.containsecond){        
      this.timevalue=e.hour+":"+e.minute+":"+e.second;        
      prompt.showToast({ message:"Time:" + e.hour + ":" + e.minute + ":" + e.second })
    } else {        
      this.timevalue=e.hour+":"+e.minute;        
      prompt.showToast({ message:"Time:" + e.hour + ":" + e.minute })
    }},
  timeoncancel() {    
    prompt.showToast({ message:"timeoncancel" })
  },
  datetimeonchange(e) {    
    this.datetimevalue=e.year+"-"+e.month+"-"+e.day+" "+e.hour+":"+e.minute;    
    prompt.showToast({ message:"Time:"+(e.month+1)+"-"+e.day+" "+e.hour+":"+e.minute })
  },
  datetimeoncancel() {    
    prompt.showToast({ message:"datetimeoncancel" })
  },
  multitextonchange(e) {    
    this.multitextvalue=e.newValue;    
    prompt.showToast({ message:"Multi-column text change" + e.newValue })
  },
  multitextoncancel() {    
    prompt.showToast({ message:"multitextoncancel" })
  },
  popup_picker() {    
    this.$element("picker_text").show();
  },
}
```

![](figures/mmmm.gif)

