# picker-view<a name="ZH-CN_TOPIC_0000001127125108"></a>

嵌入页面的滑动选择器。

## 子组件<a name="section54292411343"></a>

不支持。

## 属性<a name="section121957126347"></a>

除支持[通用属性](js-components-common-attributes.md)外，还支持如下属性：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.48%" id="mcps1.1.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="35.76%" id="mcps1.1.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>type</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>text</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>设置滑动选择器的类型，该属性不支持动态修改，可选项有：</p>
<ul><li>text：文本选择器。</li><li>time：时间选择器。</li><li>date：日期选择器。</li><li>datetime：日期时间选择器。</li><li>multi-text：多列文本选择器。</li></ul>
</td>
</tr>
</tbody>
</table>

文本选择器：type=text

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="24.007599240075994%" id="mcps1.1.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="10.808919108089192%" id="mcps1.1.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.62913708629137%" id="mcps1.1.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.14928507149285%" id="mcps1.1.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="49.4050594940506%" id="mcps1.1.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="24.007599240075994%" headers="mcps1.1.6.1.1 "><p>range</p>
</td>
<td class="cellrowborder" valign="top" width="10.808919108089192%" headers="mcps1.1.6.1.2 "><p>Array</p>
</td>
<td class="cellrowborder" valign="top" width="8.62913708629137%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.14928507149285%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.4050594940506%" headers="mcps1.1.6.1.5 "><p>设置文本选择器的取值范围。</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>使用时需要使用数据绑定的方式，如range = {{data}}，js中声明相应变量：data：["15", "20", "25"]。</p>
</div></div>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="24.007599240075994%" headers="mcps1.1.6.1.1 "><p>selected</p>
</td>
<td class="cellrowborder" valign="top" width="10.808919108089192%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.62913708629137%" headers="mcps1.1.6.1.3 "><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.14928507149285%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.4050594940506%" headers="mcps1.1.6.1.5 "><p>设置文本选择器的默认选择值，该值需要为range的索引。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="24.007599240075994%" headers="mcps1.1.6.1.1 "><p><span>indicator</span>prefix</p>
</td>
<td class="cellrowborder" valign="top" width="10.808919108089192%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.62913708629137%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.14928507149285%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.4050594940506%" headers="mcps1.1.6.1.5 "><p>文本选择器选定值增加的前缀字段。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="24.007599240075994%" headers="mcps1.1.6.1.1 "><p>indicatorsuffix</p>
</td>
<td class="cellrowborder" valign="top" width="10.808919108089192%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.62913708629137%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.14928507149285%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.4050594940506%" headers="mcps1.1.6.1.5 "><p>文本选择器选定值增加的后缀字段。</p>
</td>
</tr>
</tbody>
</table>

时间选择器：type=time

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="24%" id="mcps1.1.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="10.83%" id="mcps1.1.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.61%" id="mcps1.1.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.1499999999999995%" id="mcps1.1.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="49.41%" id="mcps1.1.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="24%" headers="mcps1.1.6.1.1 "><p>containsecond</p>
</td>
<td class="cellrowborder" valign="top" width="10.83%" headers="mcps1.1.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.61%" headers="mcps1.1.6.1.3 "><p>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.1499999999999995%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.41%" headers="mcps1.1.6.1.5 "><p>时间选择器是否包含秒。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="24%" headers="mcps1.1.6.1.1 "><p>selected</p>
</td>
<td class="cellrowborder" valign="top" width="10.83%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.61%" headers="mcps1.1.6.1.3 "><p><span>当前时间</span></p>
</td>
<td class="cellrowborder" valign="top" width="7.1499999999999995%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.41%" headers="mcps1.1.6.1.5 "><p>设置时间选择器的默认取值，格式为 HH:mm；</p>
<p>当包含秒时，格式为HH:mm:ss。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="24%" headers="mcps1.1.6.1.1 "><p>hours</p>
</td>
<td class="cellrowborder" valign="top" width="10.83%" headers="mcps1.1.6.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.61%" headers="mcps1.1.6.1.3 "><p>24<sup>1-4</sup></p>
<p>-<sup><span>5+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="7.1499999999999995%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.41%" headers="mcps1.1.6.1.5 "><p>设置时间选择器采用的时间格式，可选值：</p>
<ul><li>12：按照12小时制显示，用上午和下午进行区分；</li><li>24：按照24小时制显示。<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>默认值会依据系统当前所选地区和语言选择当地习惯的小时制(12小时制或24小时制)。<sup><span>5+</span></sup></p>
</div></div>
</li></ul>
</td>
</tr>
</tbody>
</table>

日期选择器：type=date

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
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p>设置日期选择器的默认选择值，格式为 YYYY-MM-DD。</p>
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
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p>设置日期选择器是否显示农历开关，显示农历开关时，可以在弹窗界面展现农历的开关由于公历和农历切换。在设置显示农历时，开关状态为开，当设置不显示农历时，开关状态为关。手机生效。</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>仅手机和平板设备支持。</p>
</div></div>
</td>
</tr>
</tbody>
</table>

日期时间选择器：type=datetime，日期的选择范围为本年的日月。

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
<tbody><tr><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p>selected</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p>当前日期时间</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p>设置日期时间选择器的默认取值，格式有两种，为月日时分MM-DD-HH-mm或者年月日时分YYYY-MM-DD-HH-mm，不设置年时，默认使用当前年，该取值表示选择器弹窗时弹窗界面的默认选择值。</p>
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
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p>设置日期时间选择器采用的时间格式，可选值：</p>
<ul><li>12：按照12小时制显示，用上午和下午进行区分；</li><li>24：按照24小时制显示。<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>默认值会依据系统当前所选地区和语言选择当地习惯的小时制(12小时制或24小时制)。<sup><span>5+</span></sup></p>
</div></div>
</li></ul>
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
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p>设置日期时间选择器弹窗界面是否为农历展示。</p>
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
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p>设置日期时间选择器是否显示农历开关，显示农历开关时，可以在弹窗界面展现农历的开关由于公历和农历切换。在设置显示农历时，开关状态为开，当设置不显示农历时，开关状态为关。手机生效。</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>仅手机和平板设备支持。</p>
</div></div>
</td>
</tr>
</tbody>
</table>

多列文本选择器：type=multi-text

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
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p>设置多列文本选择器的选择值，该值为二维数组。长度表示多少列，数组的每项表示每列的数据，如  [["a","b"], ["c","d"]]。</p>
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
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p>设置多列文本选择器的默认值，每一列被选中项对应的索引构成的数组，该取值表示选择器弹窗时弹窗界面的默认选择值。</p>
</td>
</tr>
</tbody>
</table>

## 样式<a name="section198061172344"></a>

除支持[通用样式](js-components-common-styles.md)外，还支持如下样式：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="23.11768823117688%" id="mcps1.1.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="20.477952204779523%" id="mcps1.1.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.47895210478952%" id="mcps1.1.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="5.909409059094091%" id="mcps1.1.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="40.01599840015999%" id="mcps1.1.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>color</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.47895210478952%" headers="mcps1.1.6.1.3 "><p>#ffffff</p>
</td>
<td class="cellrowborder" valign="top" width="5.909409059094091%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>候选项字体颜色。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>font-size</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.47895210478952%" headers="mcps1.1.6.1.3 "><p>16px</p>
</td>
<td class="cellrowborder" valign="top" width="5.909409059094091%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>候选项字体尺寸，类型length，单位px。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>selected-color</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.47895210478952%" headers="mcps1.1.6.1.3 "><p>#ff0a69f7</p>
</td>
<td class="cellrowborder" valign="top" width="5.909409059094091%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>选中项字体颜色。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>selected-font-size</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.47895210478952%" headers="mcps1.1.6.1.3 "><p>20px</p>
</td>
<td class="cellrowborder" valign="top" width="5.909409059094091%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>选中项字体尺寸，类型length，单位px。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>disappear-color<sup>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.47895210478952%" headers="mcps1.1.6.1.3 "><p>#ffffff</p>
</td>
<td class="cellrowborder" valign="top" width="5.909409059094091%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>渐变消失项的字体颜色。消失项是在一列中有五个选项场景下最上和最下的两个选项。</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>仅手机和平板设备支持。</p>
</div></div>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>disappear-font-size<sup>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.47895210478952%" headers="mcps1.1.6.1.3 "><p>14px</p>
</td>
<td class="cellrowborder" valign="top" width="5.909409059094091%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>渐变消失项的字体尺寸。消失项是在一列中有五个选项场景下最上和最下的两个选项。</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>仅手机和平板设备支持。</p>
</div></div>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>font-family</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.47895210478952%" headers="mcps1.1.6.1.3 "><p>sans-serif</p>
</td>
<td class="cellrowborder" valign="top" width="5.909409059094091%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>选项字体类型。字体列表，用逗号分隔，每个字体用字体名或者字体族名设置。列表中第一个系统中存在的或者通过<a href="js-components-common-customizing-font.md">自定义字体</a>指定的字体，会被选中作为文本的字体。</p>
</td>
</tr>
</tbody>
</table>

## 事件<a name="section103398253399"></a>

仅支持如下事件：

type=text：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="16.16161616161616%" id="mcps1.1.4.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="41.41414141414141%" id="mcps1.1.4.1.2"><p>参数</p>
</th>
<th class="cellrowborder" valign="top" width="42.42424242424242%" id="mcps1.1.4.1.3"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="16.16161616161616%" headers="mcps1.1.4.1.1 "><p>change</p>
</td>
<td class="cellrowborder" valign="top" width="41.41414141414141%" headers="mcps1.1.4.1.2 "><p>{ newValue: newValue, newSelected: newSelected }</p>
</td>
<td class="cellrowborder" valign="top" width="42.42424242424242%" headers="mcps1.1.4.1.3 "><p>文本选择器选定值后触发该事件。</p>
</td>
</tr>
</tbody>
</table>

type=time：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="16.16161616161616%" id="mcps1.1.4.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="41.41414141414141%" id="mcps1.1.4.1.2"><p>参数</p>
</th>
<th class="cellrowborder" valign="top" width="42.42424242424242%" id="mcps1.1.4.1.3"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="16.16161616161616%" headers="mcps1.1.4.1.1 "><p>change</p>
</td>
<td class="cellrowborder" valign="top" width="41.41414141414141%" headers="mcps1.1.4.1.2 "><p>{ hour: hour, minute: minute<span>, [second:second] </span>}</p>
</td>
<td class="cellrowborder" valign="top" width="42.42424242424242%" headers="mcps1.1.4.1.3 "><p>时间选择器选定值后触发该事件。</p>
<p>包含秒时，返回时分秒。</p>
</td>
</tr>
</tbody>
</table>

type=date：

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
<td class="cellrowborder" valign="top" width="34.22%" headers="mcps1.1.4.1.2 "><p>{ year:year, month:month, day:day }</p>
</td>
<td class="cellrowborder" valign="top" width="50.41%" headers="mcps1.1.4.1.3 "><p>日期选择器选择值后触发该事件。</p>
</td>
</tr>
</tbody>
</table>

type=datetime：

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
<td class="cellrowborder" valign="top" width="34.22%" headers="mcps1.1.4.1.2 "><p>{ year:year, month:month, day:day,  hour:hour, minute:minute }</p>
</td>
<td class="cellrowborder" valign="top" width="50.41%" headers="mcps1.1.4.1.3 "><p>日期时间选择器选择值后触发该事件。</p>
</td>
</tr>
</tbody>
</table>

type=multi-text：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="13.969999999999999%" id="mcps1.1.4.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="36.9%" id="mcps1.1.4.1.2"><p>参数</p>
</th>
<th class="cellrowborder" valign="top" width="49.13%" id="mcps1.1.4.1.3"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="13.969999999999999%" headers="mcps1.1.4.1.1 "><p>columnchange</p>
</td>
<td class="cellrowborder" valign="top" width="36.9%" headers="mcps1.1.4.1.2 "><p>{ column:column, newValue:newValue, newSelected:newSelected }</p>
</td>
<td class="cellrowborder" valign="top" width="49.13%" headers="mcps1.1.4.1.3 "><p>多列文本选择器某一列的值改变时触发该事件，column：第几列修改，newValue：选中的值，newSelected：选中值对应的索引。</p>
</td>
</tr>
</tbody>
</table>

## 方法<a name="section718304515396"></a>

不支持。

## 示例<a name="section738534695417"></a>

```
<!-- xxx.hml -->
<div class="container" @swipe="handleSwipe">
  <text class="title">
    Selected：{{time}}
  </text>
  <picker-view class="time-picker" type="time" selected="{{defaultTime}}" @change="handleChange"></picker-view>
</div>
```

```
/* xxx.css */
.container {
  flex-direction: column;
  justify-content: center;
  align-items: center;
  left: 0px;
  top: 0px;
  width: 454px;
  height: 454px;
}
.title {
  font-size: 30px;
  text-align: center;
}
.time-picker {
  width: 500px;
  height: 400px;
  margin-top: 20px;
}
```

```
/* xxx.js */
export default {
  data: {
    defaultTime: "",
    time: "",
  },
  onInit() {
    this.defaultTime = this.now();
  },
  handleChange(data) {
    this.time = this.concat(data.hour, data.minute);
  },
  now() {
    const date = new Date();
    const hours = date.getHours();
    const minutes = date.getMinutes();
    return this.concat(hours, minutes);
  },

  fill(value) {
    return (value > 9 ? "" : "0") + value;
  },

  concat(hours, minutes) {
    return `${this.fill(hours)}:${this.fill(minutes)}`;
  },
}
```

![](figures/sssssss.png)

