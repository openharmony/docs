# input<a name="ZH-CN_TOPIC_0000001173324647"></a>

交互式组件，包括单选框，多选框，按钮和单行文本输入框。

## 权限列表<a name="section11257113618419"></a>

无

## 子组件<a name="section9288143101012"></a>

不支持。

## 属性<a name="section2907183951110"></a>

除支持[通用属性](js-components-common-attributes.md)外，还支持如下属性：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="20.26%" id="mcps1.1.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="9.42%" id="mcps1.1.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="14.549999999999999%" id="mcps1.1.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="8.01%" id="mcps1.1.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="47.760000000000005%" id="mcps1.1.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="20.26%" headers="mcps1.1.6.1.1 "><p>type</p>
</td>
<td class="cellrowborder" valign="top" width="9.42%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="14.549999999999999%" headers="mcps1.1.6.1.3 "><p>text</p>
</td>
<td class="cellrowborder" valign="top" width="8.01%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.760000000000005%" headers="mcps1.1.6.1.5 "><p>input组件类型，可选值为<span>text，email，date，time，number，password，</span>button，checkbox，radio。</p>
<p>其中text，email，date，time，number，password这六种类型之间支持动态切换修改。</p>
<p>button，checkbox，radio不支持动态修改。可选值定义如下：</p>
<ul><li>button：定义可点击的按钮；</li><li>checkbox：定义多选框；</li><li>radio：定义单选按钮，允许在多个拥有相同name值的选项中选中其中一个；</li><li>text：定义一个单行的文本字段</li><li>email：定义用于e-mail地址的字段；</li><li>date：定义 date 控件（包括年、月、日，不包括时间）；</li><li>time：定义用于输入时间的控件（不带时区）；</li><li>number：定义用于输入数字的字段；</li><li>password：定义密码字段（字段中的字符会被遮蔽）。<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>智能穿戴仅支持button、radio、checkbox类型。</p>
</div></div>
</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="20.26%" headers="mcps1.1.6.1.1 "><p>checked</p>
</td>
<td class="cellrowborder" valign="top" width="9.42%" headers="mcps1.1.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="14.549999999999999%" headers="mcps1.1.6.1.3 "><p>false</p>
</td>
<td class="cellrowborder" valign="top" width="8.01%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.760000000000005%" headers="mcps1.1.6.1.5 "><p>当前组件是否选中，仅type为checkbox和radio生效。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="20.26%" headers="mcps1.1.6.1.1 "><p>name</p>
</td>
<td class="cellrowborder" valign="top" width="9.42%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="14.549999999999999%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.01%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.760000000000005%" headers="mcps1.1.6.1.5 "><p>input组件的名称。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="20.26%" headers="mcps1.1.6.1.1 "><p>value</p>
</td>
<td class="cellrowborder" valign="top" width="9.42%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="14.549999999999999%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.01%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.760000000000005%" headers="mcps1.1.6.1.5 "><p>input组件的value值，当类型为radio时必填且相同name值的选项该值唯一。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="20.26%" headers="mcps1.1.6.1.1 "><p>placeholder</p>
</td>
<td class="cellrowborder" valign="top" width="9.42%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="14.549999999999999%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.01%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.760000000000005%" headers="mcps1.1.6.1.5 "><p>设置提示文本的内容，仅在type为text|email|date|time|number|password时生效。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="20.26%" headers="mcps1.1.6.1.1 "><p>maxlength</p>
</td>
<td class="cellrowborder" valign="top" width="9.42%" headers="mcps1.1.6.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="14.549999999999999%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.01%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.760000000000005%" headers="mcps1.1.6.1.5 "><p>输入框可输入的最多字符数量，不填表示不限制输入框中字符数量。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="20.26%" headers="mcps1.1.6.1.1 "><p>enterkeytype</p>
</td>
<td class="cellrowborder" valign="top" width="9.42%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="14.549999999999999%" headers="mcps1.1.6.1.3 "><p>default</p>
</td>
<td class="cellrowborder" valign="top" width="8.01%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.760000000000005%" headers="mcps1.1.6.1.5 "><p>不支持动态修改。</p>
<p>设置软键盘Enter按钮的类型，可选值为：</p>
<ul><li>default：默认</li><li>next：下一项</li><li>go：前往</li><li>done：完成</li><li>send：发送</li><li>search：搜索</li></ul>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>除“next”外，点击后会自动收起软键盘。</p>
</div></div>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="20.26%" headers="mcps1.1.6.1.1 "><p>headericon</p>
</td>
<td class="cellrowborder" valign="top" width="9.42%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="14.549999999999999%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.01%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.760000000000005%" headers="mcps1.1.6.1.5 "><p>在文本输入前的图标资源路径，该图标不支持点击事件（button，checkbox和radio不生效），图标格式为jpg，png和svg。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="20.26%" headers="mcps1.1.6.1.1 "><p>showcounter<sup>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="9.42%" headers="mcps1.1.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="14.549999999999999%" headers="mcps1.1.6.1.3 "><p>false</p>
</td>
<td class="cellrowborder" valign="top" width="8.01%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.760000000000005%" headers="mcps1.1.6.1.5 "><p>文本输入框是否显示计数下标，需要配合maxlength一起使用。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="20.26%" headers="mcps1.1.6.1.1 "><p>menuoptions<sup>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="9.42%" headers="mcps1.1.6.1.2 "><p>Array&lt;<a href="#table83621954963">MenuOption</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="14.549999999999999%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.01%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.760000000000005%" headers="mcps1.1.6.1.5 "><p>设置文本选择弹框点击更多按钮之后显示的菜单项。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="20.26%" headers="mcps1.1.6.1.1 "><p>autofocus<sup><span>6+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="9.42%" headers="mcps1.1.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="14.549999999999999%" headers="mcps1.1.6.1.3 "><p>false</p>
</td>
<td class="cellrowborder" valign="top" width="8.01%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.760000000000005%" headers="mcps1.1.6.1.5 "><p>是否自动获焦。</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>应用首页中设置不生效，可在onActive中延迟（100-500ms左右）调用focus方法实现输入框在首页中自动获焦。</p>
</div></div>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="20.26%" headers="mcps1.1.6.1.1 "><p>selectedstart<sup><span>6+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="9.42%" headers="mcps1.1.6.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="14.549999999999999%" headers="mcps1.1.6.1.3 "><p>-1</p>
</td>
<td class="cellrowborder" valign="top" width="8.01%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.760000000000005%" headers="mcps1.1.6.1.5 "><p>开始选择文本时初始选择位置。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="20.26%" headers="mcps1.1.6.1.1 "><p>selectedend<sup><span>6+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="9.42%" headers="mcps1.1.6.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="14.549999999999999%" headers="mcps1.1.6.1.3 "><p>-1</p>
</td>
<td class="cellrowborder" valign="top" width="8.01%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.760000000000005%" headers="mcps1.1.6.1.5 "><p>开始选择文本时结尾选择位置。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="20.26%" headers="mcps1.1.6.1.1 "><p>softkeyboardenabled<sup><span>6+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="9.42%" headers="mcps1.1.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="14.549999999999999%" headers="mcps1.1.6.1.3 "><p>true</p>
</td>
<td class="cellrowborder" valign="top" width="8.01%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.760000000000005%" headers="mcps1.1.6.1.5 "><p>编辑时是否弹出系统软键盘。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="20.26%" headers="mcps1.1.6.1.1 "><p>showpasswordicon<sup><span>6+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="9.42%" headers="mcps1.1.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="14.549999999999999%" headers="mcps1.1.6.1.3 "><p>true</p>
</td>
<td class="cellrowborder" valign="top" width="8.01%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.760000000000005%" headers="mcps1.1.6.1.5 "><p>是否显示密码框末尾的图标（仅type为password时生效）。</p>
</td>
</tr>
</tbody>
</table>

**表 1**  MenuOption<sup>5+</sup>

<a name="table83621954963"></a>
<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p>icon</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p>菜单选项中的图标路径。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p>content</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p>菜单选项中的文本内容。</p>
</td>
</tr>
</tbody>
</table>

## 样式<a name="section066012492913"></a>

除支持[通用样式](js-components-common-styles.md)外，还支持如下样式：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="23.11768823117688%" id="mcps1.1.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="20.537946205379463%" id="mcps1.1.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="22.757724227577242%" id="mcps1.1.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.58924107589241%" id="mcps1.1.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="25.997400259974%" id="mcps1.1.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>color</p>
</td>
<td class="cellrowborder" valign="top" width="20.537946205379463%" headers="mcps1.1.6.1.2 "><p>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="22.757724227577242%" headers="mcps1.1.6.1.3 "><p>#e6000000</p>
</td>
<td class="cellrowborder" valign="top" width="7.58924107589241%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="25.997400259974%" headers="mcps1.1.6.1.5 "><p>单行输入框或者按钮的文本颜色。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>font-size</p>
</td>
<td class="cellrowborder" valign="top" width="20.537946205379463%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="22.757724227577242%" headers="mcps1.1.6.1.3 "><p>16px</p>
</td>
<td class="cellrowborder" valign="top" width="7.58924107589241%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="25.997400259974%" headers="mcps1.1.6.1.5 "><p>单行输入框或者按钮的文本尺寸。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>allow-scale</p>
</td>
<td class="cellrowborder" valign="top" width="20.537946205379463%" headers="mcps1.1.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="22.757724227577242%" headers="mcps1.1.6.1.3 "><p>true</p>
</td>
<td class="cellrowborder" valign="top" width="7.58924107589241%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="25.997400259974%" headers="mcps1.1.6.1.5 "><p>单行输入框或者按钮的文本尺寸是否跟随系统设置字体缩放尺寸进行放大缩小。</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>如果在config描述文件中针对ability配置了fontSize的config-changes标签，则应用不会重启而直接生效。</p>
</div></div>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>placeholder-color</p>
</td>
<td class="cellrowborder" valign="top" width="20.537946205379463%" headers="mcps1.1.6.1.2 "><p>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="22.757724227577242%" headers="mcps1.1.6.1.3 "><p>#99000000</p>
</td>
<td class="cellrowborder" valign="top" width="7.58924107589241%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="25.997400259974%" headers="mcps1.1.6.1.5 "><p>单行输入框的提示文本的颜色，type为text|email|date|time|number|password时生效。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>font-weight</p>
</td>
<td class="cellrowborder" valign="top" width="20.537946205379463%" headers="mcps1.1.6.1.2 "><p>number | string</p>
</td>
<td class="cellrowborder" valign="top" width="22.757724227577242%" headers="mcps1.1.6.1.3 "><p>normal</p>
</td>
<td class="cellrowborder" valign="top" width="7.58924107589241%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="25.997400259974%" headers="mcps1.1.6.1.5 "><p>单行输入框或者按钮的字体粗细，见<a href="js-components-basic-text.md#section5775351116">text组件font-weight的样式属性</a>。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>caret-color<sup>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.537946205379463%" headers="mcps1.1.6.1.2 "><p>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="22.757724227577242%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.58924107589241%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="25.997400259974%" headers="mcps1.1.6.1.5 "><p>设置输入光标的颜色。</p>
</td>
</tr>
</tbody>
</table>

## 事件<a name="section1721512551218"></a>

除支持[通用事件](js-components-common-events.md)外，还支持如下事件：

-   当input类型为text、email、date、time、number、password时，支持如下事件：

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="24.852485248524854%" id="mcps1.1.4.1.1"><p>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="29.552955295529554%" id="mcps1.1.4.1.2"><p>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="45.5945594559456%" id="mcps1.1.4.1.3"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p>change</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p>{ value:inputValue }</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p>输入框输入内容发生变化时触发该事件，返回用户当前输入值。</p>
    <div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>改变value属性值不会触发该回调。</p>
    </div></div>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p>enterkeyclick</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p>{ value:enterKey }</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p>软键盘enter键点击后触发该事件，返回enter按钮的类型，enterKey类型为number，可选值为：</p>
    <ul><li>2：设置enterkeytype属性为go时生效。</li><li>3：设置enterkeytype属性为search时生效。</li><li>4：设置enterkeytype属性为send时生效。</li><li>5：设置enterkeytype属性为next时生效。</li><li>6：不设置enterkeytype或者设置enterkeytype属性为default、done时生效。</li></ul>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p>translate<sup>5+</sup></p>
    </td>
    <td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p>{ value: selectedText }</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p>设置此事件后，进行文本选择操作后文本选择弹窗会出现翻译按钮，点击翻译按钮之后，触发该回调，返回选中的文本内容。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p>share<sup>5+</sup></p>
    </td>
    <td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p>{ value: selectedText }</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p>设置此事件后，进行文本选择操作后文本选择弹窗会出现分享按钮，点击分享按钮之后，触发该回调，返回选中的文本内容。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p>search<sup>5+</sup></p>
    </td>
    <td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p>{ value: selectedText }</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p>设置此事件后，进行文本选择操作后文本选择弹窗会出现搜索按钮，点击搜索按钮之后，触发该回调，返回选中的文本内容。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p>optionselect<sup><span>5+</span></sup></p>
    </td>
    <td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p>{ index:optionIndex, value: selectedText }</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p>文本选择弹窗中设置menuoptions属性后，用户在文本选择操作后，点击菜单项后触发该回调，返回点击的菜单项序号和选中的文本内容。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p>selectchange<sup>6+</sup></p>
    </td>
    <td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p>{ start: number，end: number }</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p>文本选择变化时触发事件。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   当input类型为checkbox、radio时，支持如下事件：

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="24.852485248524854%" id="mcps1.1.4.1.1"><p>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="29.552955295529554%" id="mcps1.1.4.1.2"><p>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="45.5945594559456%" id="mcps1.1.4.1.3"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p>change</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p>{ checked:true | false }</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p>checkbox多选框或radio单选框的checked状态发生变化时触发该事件。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 方法<a name="section47669296127"></a>

除支持[通用方法](js-components-common-methods.md)外，还支持如下方法：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="16.88%" id="mcps1.1.4.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="29.12%" id="mcps1.1.4.1.2"><p>参数</p>
</th>
<th class="cellrowborder" valign="top" width="54%" id="mcps1.1.4.1.3"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="16.88%" headers="mcps1.1.4.1.1 "><p>focus</p>
</td>
<td class="cellrowborder" valign="top" width="29.12%" headers="mcps1.1.4.1.2 "><p>{ focus: true|false }，focus不传默认为true。</p>
</td>
<td class="cellrowborder" valign="top" width="54%" headers="mcps1.1.4.1.3 "><p>使组件获得或者失去焦点，type为text|email|date|time|number|password时，可弹出或收起输入法。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16.88%" headers="mcps1.1.4.1.1 "><p>showError</p>
</td>
<td class="cellrowborder" valign="top" width="29.12%" headers="mcps1.1.4.1.2 "><p>{ error: string }</p>
</td>
<td class="cellrowborder" valign="top" width="54%" headers="mcps1.1.4.1.3 "><p>展示输入错误提示，type为text|email|date|time|number|password时生效。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="16.88%" headers="mcps1.1.4.1.1 "><p>delete<sup>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="29.12%" headers="mcps1.1.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="54%" headers="mcps1.1.4.1.3 "><p>type为text|email|date|time|number|password时，根据当前光标位置删除文本内容，如果当前输入组件没有光标，默认删除最后一个字符并展示光标。</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section106355275448"></a>

1.  type为text

    ```
    <!-- xxx.hml -->
    <div class="content">
      <input id="input" class="input" type="text" value="" maxlength="20" enterkeytype="send"
        headericon="/common/search.svg" placeholder="Please input text" onchange="change"
        onenterkeyclick="enterkeyClick">
      </input>
      <input class="button" type="button" value="Submit" onclick="buttonClick"></input>
    </div>
    ```

    ```
    /* xxx.css */
    .content {
      width: 60%;
      flex-direction: column;
      align-items: center;
    }
    .input {
      placeholder-color: gray;
    }
    .button {
      background-color: gray;
      margin-top: 20px;
    }
    ```

    ```
    // xxx.js
    import prompt from '@system.prompt'
    export default {
      change(e){
        prompt.showToast({
          message: "value: " + e.value,
          duration: 3000,
        });
      },
      enterkeyClick(e){
        prompt.showToast({
          message: "enterkey clicked",
          duration: 3000,
        });
      },
      buttonClick(e){
        this.$element("input").showError({
          error: 'error text'
        });
      },
    }
    ```

    ![](figures/zh-cn_image_0000001127284984.png)

2.  type为button

    ```
    <!-- xxx.hml -->
    <div class="div-button">
      <input class="button" type="button" value="Input-Button"></input>
    </div>
    ```

    ```
    /* xxx.css */
    .div-button {
      flex-direction: column;
      align-items: center;
      
      
    }
    .button {
      margin-top: 30px;
      width: 280px;
    }
    ```

    ![](figures/zh-cn_image_0000001198898293.png)

3.  type为checkbox

    ```
    <!-- xxx.hml -->
    <div class="content">
      <input onchange="checkboxOnChange" checked="true" type="checkbox"></input>
      
    </div>
    ```

    ```
    /* xxx.css */
    .content{
      width: 100%;
      height: 200px;
      
      
      align-items: center; 
      justify-content: center;   
    }
    ```

    ```
    // xxx.js
    import prompt from '@system.prompt'
    export default {
      checkboxOnChange(e) {
        prompt.showToast({
          message:'checked: ' + e.checked,
          duration: 3000,
        });
      }
    }
    ```

    ![](figures/zh-cn_image_0000001173324749.png)

4.  type为radio

    ```
    <!-- xxx.hml -->
    <div class="content">
      <input type="radio" checked='true' name="radioSample" value="radio1" onchange="onRadioChange('radio1')"></input>
      <input type="radio" checked='false' name="radioSample" value="radio2" onchange="onRadioChange('radio2')"></input>
      <input type="radio" checked='false' name="radioSample" value="radio3" onchange="onRadioChange('radio3')"></input>
    </div>
    ```

    ```
    /* xxx.css */
    .content{
      width: 100%;
      height: 200px;
      justify-content: center;
      align-items: center;
    }
    ```

    ```
    // xxx.js
    import prompt from '@system.prompt'
    export default {
      onRadioChange(inputValue, e) {
        if (inputValue === e.value) {
          prompt.showToast({
            message: 'The chosen radio is ' + e.value,
            duration: 3000,
          });
        }
      }
    }
    ```

    ![](figures/zh-cn_image_0000001173324751.png)


