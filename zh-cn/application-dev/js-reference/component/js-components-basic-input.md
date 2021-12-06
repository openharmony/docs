# input<a name="ZH-CN_TOPIC_0000001164290712"></a>

交互式组件，包括单选框，多选框，按钮和单行文本输入框。

## 权限列表<a name="zh-cn_topic_0000001173324647_section11257113618419"></a>

无

## 子组件<a name="zh-cn_topic_0000001173324647_section9288143101012"></a>

不支持。

## 属性<a name="zh-cn_topic_0000001173324647_section2907183951110"></a>

除支持[通用属性](js-components-common-attributes.md)外，还支持如下属性：

<a name="zh-cn_topic_0000001173324647_table20633101642315"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173324647_row663331618238"><th class="cellrowborder" valign="top" width="20.26%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001173324647_aa872998ac2d84843a3c5161889afffef"><a name="zh-cn_topic_0000001173324647_aa872998ac2d84843a3c5161889afffef"></a><a name="zh-cn_topic_0000001173324647_aa872998ac2d84843a3c5161889afffef"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="9.42%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001173324647_ab2111648ee0e4f6d881be8954e7acaab"><a name="zh-cn_topic_0000001173324647_ab2111648ee0e4f6d881be8954e7acaab"></a><a name="zh-cn_topic_0000001173324647_ab2111648ee0e4f6d881be8954e7acaab"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="14.549999999999999%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001173324647_ab377d1c90900478ea4ecab51e9a058af"><a name="zh-cn_topic_0000001173324647_ab377d1c90900478ea4ecab51e9a058af"></a><a name="zh-cn_topic_0000001173324647_ab377d1c90900478ea4ecab51e9a058af"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="8.01%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001173324647_p824610360217"><a name="zh-cn_topic_0000001173324647_p824610360217"></a><a name="zh-cn_topic_0000001173324647_p824610360217"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="47.760000000000005%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001173324647_a1d574a0044ed42ec8a2603bc82734232"><a name="zh-cn_topic_0000001173324647_a1d574a0044ed42ec8a2603bc82734232"></a><a name="zh-cn_topic_0000001173324647_a1d574a0044ed42ec8a2603bc82734232"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173324647_row634417439274"><td class="cellrowborder" valign="top" width="20.26%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324647_p72442555275"><a name="zh-cn_topic_0000001173324647_p72442555275"></a><a name="zh-cn_topic_0000001173324647_p72442555275"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="9.42%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324647_p324455511276"><a name="zh-cn_topic_0000001173324647_p324455511276"></a><a name="zh-cn_topic_0000001173324647_p324455511276"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="14.549999999999999%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324647_p16244055182716"><a name="zh-cn_topic_0000001173324647_p16244055182716"></a><a name="zh-cn_topic_0000001173324647_p16244055182716"></a>text</p>
</td>
<td class="cellrowborder" valign="top" width="8.01%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324647_p3244155102714"><a name="zh-cn_topic_0000001173324647_p3244155102714"></a><a name="zh-cn_topic_0000001173324647_p3244155102714"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.760000000000005%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324647_p924475517275"><a name="zh-cn_topic_0000001173324647_p924475517275"></a><a name="zh-cn_topic_0000001173324647_p924475517275"></a>input组件类型，可选值为<span id="zh-cn_topic_0000001173324647_ph42442055152718"><a name="zh-cn_topic_0000001173324647_ph42442055152718"></a><a name="zh-cn_topic_0000001173324647_ph42442055152718"></a>text，email，date，time，number，password，</span>button，checkbox，radio。</p>
<p id="zh-cn_topic_0000001173324647_p1524485513274"><a name="zh-cn_topic_0000001173324647_p1524485513274"></a><a name="zh-cn_topic_0000001173324647_p1524485513274"></a>其中text，email，date，time，number，password这六种类型之间支持动态切换修改。</p>
<p id="zh-cn_topic_0000001173324647_p17244175532712"><a name="zh-cn_topic_0000001173324647_p17244175532712"></a><a name="zh-cn_topic_0000001173324647_p17244175532712"></a>button，checkbox，radio不支持动态修改。可选值定义如下：</p>
<a name="zh-cn_topic_0000001173324647_ul324417555275"></a><a name="zh-cn_topic_0000001173324647_ul324417555275"></a><ul id="zh-cn_topic_0000001173324647_ul324417555275"><li>button：定义可点击的按钮；</li><li>checkbox：定义多选框；</li><li>radio：定义单选按钮，允许在多个拥有相同name值的选项中选中其中一个；</li><li>text：定义一个单行的文本字段</li><li>email：定义用于e-mail地址的字段；</li><li>date：定义 date 控件（包括年、月、日，不包括时间）；</li><li>time：定义用于输入时间的控件（不带时区）；</li><li>number：定义用于输入数字的字段；</li><li>password：定义密码字段（字段中的字符会被遮蔽）。<div class="note" id="zh-cn_topic_0000001173324647_note45664136102"><a name="zh-cn_topic_0000001173324647_note45664136102"></a><a name="zh-cn_topic_0000001173324647_note45664136102"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001173324647_p1551717289101"><a name="zh-cn_topic_0000001173324647_p1551717289101"></a><a name="zh-cn_topic_0000001173324647_p1551717289101"></a>智能穿戴仅支持button、radio、checkbox类型。</p>
</div></div>
</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324647_row43454437272"><td class="cellrowborder" valign="top" width="20.26%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324647_p5245185582713"><a name="zh-cn_topic_0000001173324647_p5245185582713"></a><a name="zh-cn_topic_0000001173324647_p5245185582713"></a>checked</p>
</td>
<td class="cellrowborder" valign="top" width="9.42%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324647_p202456551277"><a name="zh-cn_topic_0000001173324647_p202456551277"></a><a name="zh-cn_topic_0000001173324647_p202456551277"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="14.549999999999999%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324647_p1245165520272"><a name="zh-cn_topic_0000001173324647_p1245165520272"></a><a name="zh-cn_topic_0000001173324647_p1245165520272"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="8.01%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324647_p6245855172718"><a name="zh-cn_topic_0000001173324647_p6245855172718"></a><a name="zh-cn_topic_0000001173324647_p6245855172718"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.760000000000005%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324647_p12245115512279"><a name="zh-cn_topic_0000001173324647_p12245115512279"></a><a name="zh-cn_topic_0000001173324647_p12245115512279"></a>当前组件是否选中，仅type为checkbox和radio生效。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324647_row834544342712"><td class="cellrowborder" valign="top" width="20.26%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324647_p19245855182719"><a name="zh-cn_topic_0000001173324647_p19245855182719"></a><a name="zh-cn_topic_0000001173324647_p19245855182719"></a>name</p>
</td>
<td class="cellrowborder" valign="top" width="9.42%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324647_p2245955192720"><a name="zh-cn_topic_0000001173324647_p2245955192720"></a><a name="zh-cn_topic_0000001173324647_p2245955192720"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="14.549999999999999%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324647_p14245115502719"><a name="zh-cn_topic_0000001173324647_p14245115502719"></a><a name="zh-cn_topic_0000001173324647_p14245115502719"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.01%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324647_p32451755182718"><a name="zh-cn_topic_0000001173324647_p32451755182718"></a><a name="zh-cn_topic_0000001173324647_p32451755182718"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.760000000000005%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324647_p20245135542717"><a name="zh-cn_topic_0000001173324647_p20245135542717"></a><a name="zh-cn_topic_0000001173324647_p20245135542717"></a>input组件的名称。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324647_row18345124342713"><td class="cellrowborder" valign="top" width="20.26%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324647_p0245185592712"><a name="zh-cn_topic_0000001173324647_p0245185592712"></a><a name="zh-cn_topic_0000001173324647_p0245185592712"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="9.42%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324647_p1224525518275"><a name="zh-cn_topic_0000001173324647_p1224525518275"></a><a name="zh-cn_topic_0000001173324647_p1224525518275"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="14.549999999999999%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324647_p5245115582715"><a name="zh-cn_topic_0000001173324647_p5245115582715"></a><a name="zh-cn_topic_0000001173324647_p5245115582715"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.01%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324647_p624515512278"><a name="zh-cn_topic_0000001173324647_p624515512278"></a><a name="zh-cn_topic_0000001173324647_p624515512278"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.760000000000005%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324647_p0245255112710"><a name="zh-cn_topic_0000001173324647_p0245255112710"></a><a name="zh-cn_topic_0000001173324647_p0245255112710"></a>input组件的value值，当类型为radio时必填且相同name值的选项该值唯一。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324647_row1360803719278"><td class="cellrowborder" valign="top" width="20.26%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324647_p52451955152716"><a name="zh-cn_topic_0000001173324647_p52451955152716"></a><a name="zh-cn_topic_0000001173324647_p52451955152716"></a>placeholder</p>
</td>
<td class="cellrowborder" valign="top" width="9.42%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324647_p2246135512274"><a name="zh-cn_topic_0000001173324647_p2246135512274"></a><a name="zh-cn_topic_0000001173324647_p2246135512274"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="14.549999999999999%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324647_p12462557277"><a name="zh-cn_topic_0000001173324647_p12462557277"></a><a name="zh-cn_topic_0000001173324647_p12462557277"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.01%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324647_p6246125562716"><a name="zh-cn_topic_0000001173324647_p6246125562716"></a><a name="zh-cn_topic_0000001173324647_p6246125562716"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.760000000000005%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324647_p4246205572711"><a name="zh-cn_topic_0000001173324647_p4246205572711"></a><a name="zh-cn_topic_0000001173324647_p4246205572711"></a>设置提示文本的内容，仅在type为text|email|date|time|number|password时生效。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324647_row10729734112719"><td class="cellrowborder" valign="top" width="20.26%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324647_p524615562717"><a name="zh-cn_topic_0000001173324647_p524615562717"></a><a name="zh-cn_topic_0000001173324647_p524615562717"></a>maxlength</p>
</td>
<td class="cellrowborder" valign="top" width="9.42%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324647_p4246165562713"><a name="zh-cn_topic_0000001173324647_p4246165562713"></a><a name="zh-cn_topic_0000001173324647_p4246165562713"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="14.549999999999999%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324647_p1246135522711"><a name="zh-cn_topic_0000001173324647_p1246135522711"></a><a name="zh-cn_topic_0000001173324647_p1246135522711"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.01%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324647_p13246185517271"><a name="zh-cn_topic_0000001173324647_p13246185517271"></a><a name="zh-cn_topic_0000001173324647_p13246185517271"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.760000000000005%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324647_p1224635514274"><a name="zh-cn_topic_0000001173324647_p1224635514274"></a><a name="zh-cn_topic_0000001173324647_p1224635514274"></a>输入框可输入的最多字符数量，不填表示不限制输入框中字符数量。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324647_row1125513210279"><td class="cellrowborder" valign="top" width="20.26%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324647_p14246125513277"><a name="zh-cn_topic_0000001173324647_p14246125513277"></a><a name="zh-cn_topic_0000001173324647_p14246125513277"></a>enterkeytype</p>
</td>
<td class="cellrowborder" valign="top" width="9.42%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324647_p7246055112718"><a name="zh-cn_topic_0000001173324647_p7246055112718"></a><a name="zh-cn_topic_0000001173324647_p7246055112718"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="14.549999999999999%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324647_p1324615552276"><a name="zh-cn_topic_0000001173324647_p1324615552276"></a><a name="zh-cn_topic_0000001173324647_p1324615552276"></a>default</p>
</td>
<td class="cellrowborder" valign="top" width="8.01%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324647_p10246115514272"><a name="zh-cn_topic_0000001173324647_p10246115514272"></a><a name="zh-cn_topic_0000001173324647_p10246115514272"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.760000000000005%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324647_p1824635502717"><a name="zh-cn_topic_0000001173324647_p1824635502717"></a><a name="zh-cn_topic_0000001173324647_p1824635502717"></a>不支持动态修改。</p>
<p id="zh-cn_topic_0000001173324647_p12246255112712"><a name="zh-cn_topic_0000001173324647_p12246255112712"></a><a name="zh-cn_topic_0000001173324647_p12246255112712"></a>设置软键盘Enter按钮的类型，可选值为：</p>
<a name="zh-cn_topic_0000001173324647_ul52461055142716"></a><a name="zh-cn_topic_0000001173324647_ul52461055142716"></a><ul id="zh-cn_topic_0000001173324647_ul52461055142716"><li>default：默认</li><li>next：下一项</li><li>go：前往</li><li>done：完成</li><li>send：发送</li><li>search：搜索</li></ul>
<div class="note" id="zh-cn_topic_0000001173324647_note1524765512720"><a name="zh-cn_topic_0000001173324647_note1524765512720"></a><a name="zh-cn_topic_0000001173324647_note1524765512720"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001173324647_p124795592715"><a name="zh-cn_topic_0000001173324647_p124795592715"></a><a name="zh-cn_topic_0000001173324647_p124795592715"></a>除“next”外，点击后会自动收起软键盘。</p>
</div></div>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324647_row2461329122714"><td class="cellrowborder" valign="top" width="20.26%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324647_p8247655162711"><a name="zh-cn_topic_0000001173324647_p8247655162711"></a><a name="zh-cn_topic_0000001173324647_p8247655162711"></a>headericon</p>
</td>
<td class="cellrowborder" valign="top" width="9.42%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324647_p18247145520271"><a name="zh-cn_topic_0000001173324647_p18247145520271"></a><a name="zh-cn_topic_0000001173324647_p18247145520271"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="14.549999999999999%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324647_p824715572713"><a name="zh-cn_topic_0000001173324647_p824715572713"></a><a name="zh-cn_topic_0000001173324647_p824715572713"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.01%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324647_p2247135582717"><a name="zh-cn_topic_0000001173324647_p2247135582717"></a><a name="zh-cn_topic_0000001173324647_p2247135582717"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.760000000000005%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324647_p20247755102711"><a name="zh-cn_topic_0000001173324647_p20247755102711"></a><a name="zh-cn_topic_0000001173324647_p20247755102711"></a>在文本输入前的图标资源路径，该图标不支持点击事件（button，checkbox和radio不生效），图标格式为jpg，png和svg。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324647_row16836876325"><td class="cellrowborder" valign="top" width="20.26%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324647_p983712712329"><a name="zh-cn_topic_0000001173324647_p983712712329"></a><a name="zh-cn_topic_0000001173324647_p983712712329"></a>showcounter<sup id="zh-cn_topic_0000001173324647_sup19271132920334"><a name="zh-cn_topic_0000001173324647_sup19271132920334"></a><a name="zh-cn_topic_0000001173324647_sup19271132920334"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="9.42%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324647_p178371971325"><a name="zh-cn_topic_0000001173324647_p178371971325"></a><a name="zh-cn_topic_0000001173324647_p178371971325"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="14.549999999999999%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324647_p28374743210"><a name="zh-cn_topic_0000001173324647_p28374743210"></a><a name="zh-cn_topic_0000001173324647_p28374743210"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="8.01%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324647_p6837677327"><a name="zh-cn_topic_0000001173324647_p6837677327"></a><a name="zh-cn_topic_0000001173324647_p6837677327"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.760000000000005%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324647_p11837472328"><a name="zh-cn_topic_0000001173324647_p11837472328"></a><a name="zh-cn_topic_0000001173324647_p11837472328"></a>文本输入框是否显示计数下标，需要配合maxlength一起使用。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324647_row07211971743"><td class="cellrowborder" valign="top" width="20.26%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324647_p177221571244"><a name="zh-cn_topic_0000001173324647_p177221571244"></a><a name="zh-cn_topic_0000001173324647_p177221571244"></a>menuoptions<sup id="zh-cn_topic_0000001173324647_sup154944401542"><a name="zh-cn_topic_0000001173324647_sup154944401542"></a><a name="zh-cn_topic_0000001173324647_sup154944401542"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="9.42%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324647_p8722157248"><a name="zh-cn_topic_0000001173324647_p8722157248"></a><a name="zh-cn_topic_0000001173324647_p8722157248"></a>Array&lt;<a href="#zh-cn_topic_0000001173324647_table83621954963">MenuOption</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="14.549999999999999%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324647_p167221878414"><a name="zh-cn_topic_0000001173324647_p167221878414"></a><a name="zh-cn_topic_0000001173324647_p167221878414"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.01%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324647_p197227713411"><a name="zh-cn_topic_0000001173324647_p197227713411"></a><a name="zh-cn_topic_0000001173324647_p197227713411"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.760000000000005%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324647_p207221573417"><a name="zh-cn_topic_0000001173324647_p207221573417"></a><a name="zh-cn_topic_0000001173324647_p207221573417"></a>设置文本选择弹框点击更多按钮之后显示的菜单项。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324647_row45541828184811"><td class="cellrowborder" valign="top" width="20.26%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324647_p95550281483"><a name="zh-cn_topic_0000001173324647_p95550281483"></a><a name="zh-cn_topic_0000001173324647_p95550281483"></a>autofocus<sup id="zh-cn_topic_0000001173324647_sup1775142235010"><a name="zh-cn_topic_0000001173324647_sup1775142235010"></a><a name="zh-cn_topic_0000001173324647_sup1775142235010"></a><span>6+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="9.42%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324647_p1955511286485"><a name="zh-cn_topic_0000001173324647_p1955511286485"></a><a name="zh-cn_topic_0000001173324647_p1955511286485"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="14.549999999999999%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324647_p6555192874812"><a name="zh-cn_topic_0000001173324647_p6555192874812"></a><a name="zh-cn_topic_0000001173324647_p6555192874812"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="8.01%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324647_p3555142844817"><a name="zh-cn_topic_0000001173324647_p3555142844817"></a><a name="zh-cn_topic_0000001173324647_p3555142844817"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.760000000000005%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324647_p135551628184820"><a name="zh-cn_topic_0000001173324647_p135551628184820"></a><a name="zh-cn_topic_0000001173324647_p135551628184820"></a>是否自动获焦。</p>
<div class="note" id="zh-cn_topic_0000001173324647_note9175194313116"><a name="zh-cn_topic_0000001173324647_note9175194313116"></a><a name="zh-cn_topic_0000001173324647_note9175194313116"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001173324647_p554143517446"><a name="zh-cn_topic_0000001173324647_p554143517446"></a><a name="zh-cn_topic_0000001173324647_p554143517446"></a>应用首页中设置不生效，可在onActive中延迟（100-500ms左右）调用focus方法实现输入框在首页中自动获焦。</p>
</div></div>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324647_row1261993119486"><td class="cellrowborder" valign="top" width="20.26%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324647_p16196311485"><a name="zh-cn_topic_0000001173324647_p16196311485"></a><a name="zh-cn_topic_0000001173324647_p16196311485"></a>selectedstart<sup id="zh-cn_topic_0000001173324647_sup151911922125019"><a name="zh-cn_topic_0000001173324647_sup151911922125019"></a><a name="zh-cn_topic_0000001173324647_sup151911922125019"></a><span>6+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="9.42%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324647_p126191631104819"><a name="zh-cn_topic_0000001173324647_p126191631104819"></a><a name="zh-cn_topic_0000001173324647_p126191631104819"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="14.549999999999999%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324647_p7619163110489"><a name="zh-cn_topic_0000001173324647_p7619163110489"></a><a name="zh-cn_topic_0000001173324647_p7619163110489"></a>-1</p>
</td>
<td class="cellrowborder" valign="top" width="8.01%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324647_p1619123120488"><a name="zh-cn_topic_0000001173324647_p1619123120488"></a><a name="zh-cn_topic_0000001173324647_p1619123120488"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.760000000000005%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324647_p9619113118488"><a name="zh-cn_topic_0000001173324647_p9619113118488"></a><a name="zh-cn_topic_0000001173324647_p9619113118488"></a>开始选择文本时初始选择位置。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324647_row1823083417484"><td class="cellrowborder" valign="top" width="20.26%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324647_p42301334184813"><a name="zh-cn_topic_0000001173324647_p42301334184813"></a><a name="zh-cn_topic_0000001173324647_p42301334184813"></a>selectedend<sup id="zh-cn_topic_0000001173324647_sup759182155017"><a name="zh-cn_topic_0000001173324647_sup759182155017"></a><a name="zh-cn_topic_0000001173324647_sup759182155017"></a><span>6+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="9.42%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324647_p1523013444810"><a name="zh-cn_topic_0000001173324647_p1523013444810"></a><a name="zh-cn_topic_0000001173324647_p1523013444810"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="14.549999999999999%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324647_p1823053404815"><a name="zh-cn_topic_0000001173324647_p1823053404815"></a><a name="zh-cn_topic_0000001173324647_p1823053404815"></a>-1</p>
</td>
<td class="cellrowborder" valign="top" width="8.01%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324647_p162301434104819"><a name="zh-cn_topic_0000001173324647_p162301434104819"></a><a name="zh-cn_topic_0000001173324647_p162301434104819"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.760000000000005%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324647_p2023014344489"><a name="zh-cn_topic_0000001173324647_p2023014344489"></a><a name="zh-cn_topic_0000001173324647_p2023014344489"></a>开始选择文本时结尾选择位置。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324647_row6428183714485"><td class="cellrowborder" valign="top" width="20.26%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324647_p11428837134811"><a name="zh-cn_topic_0000001173324647_p11428837134811"></a><a name="zh-cn_topic_0000001173324647_p11428837134811"></a>softkeyboardenabled<sup id="zh-cn_topic_0000001173324647_sup135541120205017"><a name="zh-cn_topic_0000001173324647_sup135541120205017"></a><a name="zh-cn_topic_0000001173324647_sup135541120205017"></a><span>6+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="9.42%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324647_p18428837114816"><a name="zh-cn_topic_0000001173324647_p18428837114816"></a><a name="zh-cn_topic_0000001173324647_p18428837114816"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="14.549999999999999%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324647_p124281037144812"><a name="zh-cn_topic_0000001173324647_p124281037144812"></a><a name="zh-cn_topic_0000001173324647_p124281037144812"></a>true</p>
</td>
<td class="cellrowborder" valign="top" width="8.01%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324647_p842823714486"><a name="zh-cn_topic_0000001173324647_p842823714486"></a><a name="zh-cn_topic_0000001173324647_p842823714486"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.760000000000005%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324647_p1642873734813"><a name="zh-cn_topic_0000001173324647_p1642873734813"></a><a name="zh-cn_topic_0000001173324647_p1642873734813"></a>编辑时是否弹出系统软键盘。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324647_row18278391483"><td class="cellrowborder" valign="top" width="20.26%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324647_p10827143911483"><a name="zh-cn_topic_0000001173324647_p10827143911483"></a><a name="zh-cn_topic_0000001173324647_p10827143911483"></a>showpasswordicon<sup id="zh-cn_topic_0000001173324647_sup65401815115011"><a name="zh-cn_topic_0000001173324647_sup65401815115011"></a><a name="zh-cn_topic_0000001173324647_sup65401815115011"></a><span>6+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="9.42%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324647_p882719398489"><a name="zh-cn_topic_0000001173324647_p882719398489"></a><a name="zh-cn_topic_0000001173324647_p882719398489"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="14.549999999999999%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324647_p1082753994811"><a name="zh-cn_topic_0000001173324647_p1082753994811"></a><a name="zh-cn_topic_0000001173324647_p1082753994811"></a>true</p>
</td>
<td class="cellrowborder" valign="top" width="8.01%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324647_p13827183954817"><a name="zh-cn_topic_0000001173324647_p13827183954817"></a><a name="zh-cn_topic_0000001173324647_p13827183954817"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.760000000000005%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324647_p10828939174817"><a name="zh-cn_topic_0000001173324647_p10828939174817"></a><a name="zh-cn_topic_0000001173324647_p10828939174817"></a>是否显示密码框末尾的图标（仅type为password时生效）。</p>
</td>
</tr>
</tbody>
</table>

**表 1**  MenuOption<sup>5+</sup>

<a name="zh-cn_topic_0000001173324647_table83621954963"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173324647_row536212545619"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="zh-cn_topic_0000001173324647_p143621541967"><a name="zh-cn_topic_0000001173324647_p143621541967"></a><a name="zh-cn_topic_0000001173324647_p143621541967"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="zh-cn_topic_0000001173324647_p936215541620"><a name="zh-cn_topic_0000001173324647_p936215541620"></a><a name="zh-cn_topic_0000001173324647_p936215541620"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="zh-cn_topic_0000001173324647_p23626541665"><a name="zh-cn_topic_0000001173324647_p23626541665"></a><a name="zh-cn_topic_0000001173324647_p23626541665"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173324647_row5362254461"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001173324647_p33631541265"><a name="zh-cn_topic_0000001173324647_p33631541265"></a><a name="zh-cn_topic_0000001173324647_p33631541265"></a>icon</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001173324647_p536311543619"><a name="zh-cn_topic_0000001173324647_p536311543619"></a><a name="zh-cn_topic_0000001173324647_p536311543619"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001173324647_p73631954762"><a name="zh-cn_topic_0000001173324647_p73631954762"></a><a name="zh-cn_topic_0000001173324647_p73631954762"></a>菜单选项中的图标路径。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324647_row136319547613"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001173324647_p12363654367"><a name="zh-cn_topic_0000001173324647_p12363654367"></a><a name="zh-cn_topic_0000001173324647_p12363654367"></a>content</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001173324647_p1936312549617"><a name="zh-cn_topic_0000001173324647_p1936312549617"></a><a name="zh-cn_topic_0000001173324647_p1936312549617"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001173324647_p1036311548616"><a name="zh-cn_topic_0000001173324647_p1036311548616"></a><a name="zh-cn_topic_0000001173324647_p1036311548616"></a>菜单选项中的文本内容。</p>
</td>
</tr>
</tbody>
</table>

## 样式<a name="zh-cn_topic_0000001173324647_section066012492913"></a>

除支持[通用样式](js-components-common-styles.md)外，还支持如下样式：

<a name="zh-cn_topic_0000001173324647_table168129500519"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173324647_row3812115020515"><th class="cellrowborder" valign="top" width="23.11768823117688%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001173324647_p178128502053"><a name="zh-cn_topic_0000001173324647_p178128502053"></a><a name="zh-cn_topic_0000001173324647_p178128502053"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="20.537946205379463%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001173324647_p781295016511"><a name="zh-cn_topic_0000001173324647_p781295016511"></a><a name="zh-cn_topic_0000001173324647_p781295016511"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="22.757724227577242%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001173324647_p178126501150"><a name="zh-cn_topic_0000001173324647_p178126501150"></a><a name="zh-cn_topic_0000001173324647_p178126501150"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.58924107589241%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001173324647_p19812950754"><a name="zh-cn_topic_0000001173324647_p19812950754"></a><a name="zh-cn_topic_0000001173324647_p19812950754"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="25.997400259974%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001173324647_p381218501456"><a name="zh-cn_topic_0000001173324647_p381218501456"></a><a name="zh-cn_topic_0000001173324647_p381218501456"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173324647_row581317501655"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324647_p12813750459"><a name="zh-cn_topic_0000001173324647_p12813750459"></a><a name="zh-cn_topic_0000001173324647_p12813750459"></a>color</p>
</td>
<td class="cellrowborder" valign="top" width="20.537946205379463%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324647_p148132501751"><a name="zh-cn_topic_0000001173324647_p148132501751"></a><a name="zh-cn_topic_0000001173324647_p148132501751"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="22.757724227577242%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324647_p16813350256"><a name="zh-cn_topic_0000001173324647_p16813350256"></a><a name="zh-cn_topic_0000001173324647_p16813350256"></a>#e6000000</p>
</td>
<td class="cellrowborder" valign="top" width="7.58924107589241%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324647_p1481311501514"><a name="zh-cn_topic_0000001173324647_p1481311501514"></a><a name="zh-cn_topic_0000001173324647_p1481311501514"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="25.997400259974%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324647_p138135501758"><a name="zh-cn_topic_0000001173324647_p138135501758"></a><a name="zh-cn_topic_0000001173324647_p138135501758"></a>单行输入框或者按钮的文本颜色。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324647_row13813175013515"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324647_p118131250153"><a name="zh-cn_topic_0000001173324647_p118131250153"></a><a name="zh-cn_topic_0000001173324647_p118131250153"></a>font-size</p>
</td>
<td class="cellrowborder" valign="top" width="20.537946205379463%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324647_p19813155013512"><a name="zh-cn_topic_0000001173324647_p19813155013512"></a><a name="zh-cn_topic_0000001173324647_p19813155013512"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="22.757724227577242%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324647_p88134501155"><a name="zh-cn_topic_0000001173324647_p88134501155"></a><a name="zh-cn_topic_0000001173324647_p88134501155"></a>16px</p>
</td>
<td class="cellrowborder" valign="top" width="7.58924107589241%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324647_p381305019519"><a name="zh-cn_topic_0000001173324647_p381305019519"></a><a name="zh-cn_topic_0000001173324647_p381305019519"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="25.997400259974%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324647_p148131050253"><a name="zh-cn_topic_0000001173324647_p148131050253"></a><a name="zh-cn_topic_0000001173324647_p148131050253"></a>单行输入框或者按钮的文本尺寸。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324647_row481312502519"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324647_p3813050954"><a name="zh-cn_topic_0000001173324647_p3813050954"></a><a name="zh-cn_topic_0000001173324647_p3813050954"></a>allow-scale</p>
</td>
<td class="cellrowborder" valign="top" width="20.537946205379463%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324647_p138139503518"><a name="zh-cn_topic_0000001173324647_p138139503518"></a><a name="zh-cn_topic_0000001173324647_p138139503518"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="22.757724227577242%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324647_p181455012517"><a name="zh-cn_topic_0000001173324647_p181455012517"></a><a name="zh-cn_topic_0000001173324647_p181455012517"></a>true</p>
</td>
<td class="cellrowborder" valign="top" width="7.58924107589241%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324647_p8814145015518"><a name="zh-cn_topic_0000001173324647_p8814145015518"></a><a name="zh-cn_topic_0000001173324647_p8814145015518"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="25.997400259974%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324647_p12814195013511"><a name="zh-cn_topic_0000001173324647_p12814195013511"></a><a name="zh-cn_topic_0000001173324647_p12814195013511"></a>单行输入框或者按钮的文本尺寸是否跟随系统设置字体缩放尺寸进行放大缩小。</p>
<div class="note" id="zh-cn_topic_0000001173324647_note1781416501358"><a name="zh-cn_topic_0000001173324647_note1781416501358"></a><a name="zh-cn_topic_0000001173324647_note1781416501358"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001173324647_p13814145011511"><a name="zh-cn_topic_0000001173324647_p13814145011511"></a><a name="zh-cn_topic_0000001173324647_p13814145011511"></a>如果在config描述文件中针对ability配置了fontSize的config-changes标签，则应用不会重启而直接生效。</p>
</div></div>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324647_row781413506518"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324647_p581410501158"><a name="zh-cn_topic_0000001173324647_p581410501158"></a><a name="zh-cn_topic_0000001173324647_p581410501158"></a>placeholder-color</p>
</td>
<td class="cellrowborder" valign="top" width="20.537946205379463%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324647_p1781419501555"><a name="zh-cn_topic_0000001173324647_p1781419501555"></a><a name="zh-cn_topic_0000001173324647_p1781419501555"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="22.757724227577242%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324647_p4814450854"><a name="zh-cn_topic_0000001173324647_p4814450854"></a><a name="zh-cn_topic_0000001173324647_p4814450854"></a>#99000000</p>
</td>
<td class="cellrowborder" valign="top" width="7.58924107589241%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324647_p12814350357"><a name="zh-cn_topic_0000001173324647_p12814350357"></a><a name="zh-cn_topic_0000001173324647_p12814350357"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="25.997400259974%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324647_p138140501751"><a name="zh-cn_topic_0000001173324647_p138140501751"></a><a name="zh-cn_topic_0000001173324647_p138140501751"></a>单行输入框的提示文本的颜色，type为text|email|date|time|number|password时生效。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324647_row58141650752"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324647_p1381435012518"><a name="zh-cn_topic_0000001173324647_p1381435012518"></a><a name="zh-cn_topic_0000001173324647_p1381435012518"></a>font-weight</p>
</td>
<td class="cellrowborder" valign="top" width="20.537946205379463%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324647_p98141250450"><a name="zh-cn_topic_0000001173324647_p98141250450"></a><a name="zh-cn_topic_0000001173324647_p98141250450"></a>number | string</p>
</td>
<td class="cellrowborder" valign="top" width="22.757724227577242%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324647_p198141507512"><a name="zh-cn_topic_0000001173324647_p198141507512"></a><a name="zh-cn_topic_0000001173324647_p198141507512"></a>normal</p>
</td>
<td class="cellrowborder" valign="top" width="7.58924107589241%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324647_p20814185015510"><a name="zh-cn_topic_0000001173324647_p20814185015510"></a><a name="zh-cn_topic_0000001173324647_p20814185015510"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="25.997400259974%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324647_p1281455014516"><a name="zh-cn_topic_0000001173324647_p1281455014516"></a><a name="zh-cn_topic_0000001173324647_p1281455014516"></a>单行输入框或者按钮的字体粗细，见<a href="js-components-basic-text.md#zh-cn_topic_0000001127125018_section5775351116">text组件font-weight的样式属性</a>。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324647_row1167411433019"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324647_p18674104193019"><a name="zh-cn_topic_0000001173324647_p18674104193019"></a><a name="zh-cn_topic_0000001173324647_p18674104193019"></a>caret-color<sup id="zh-cn_topic_0000001173324647_sup628114393018"><a name="zh-cn_topic_0000001173324647_sup628114393018"></a><a name="zh-cn_topic_0000001173324647_sup628114393018"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.537946205379463%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324647_p13674194173010"><a name="zh-cn_topic_0000001173324647_p13674194173010"></a><a name="zh-cn_topic_0000001173324647_p13674194173010"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="22.757724227577242%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324647_p12674164113010"><a name="zh-cn_topic_0000001173324647_p12674164113010"></a><a name="zh-cn_topic_0000001173324647_p12674164113010"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.58924107589241%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324647_p5674114183020"><a name="zh-cn_topic_0000001173324647_p5674114183020"></a><a name="zh-cn_topic_0000001173324647_p5674114183020"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="25.997400259974%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324647_p18674134153015"><a name="zh-cn_topic_0000001173324647_p18674134153015"></a><a name="zh-cn_topic_0000001173324647_p18674134153015"></a>设置输入光标的颜色。</p>
</td>
</tr>
</tbody>
</table>

## 事件<a name="zh-cn_topic_0000001173324647_section1721512551218"></a>

除支持[通用事件](js-components-common-events.md)外，还支持如下事件：

-   当input类型为text、email、date、time、number、password时，支持如下事件：

    <a name="zh-cn_topic_0000001173324647_table9215955923"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173324647_row02158552029"><th class="cellrowborder" valign="top" width="24.852485248524854%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173324647_p1121618551728"><a name="zh-cn_topic_0000001173324647_p1121618551728"></a><a name="zh-cn_topic_0000001173324647_p1121618551728"></a>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="29.552955295529554%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173324647_p182161855921"><a name="zh-cn_topic_0000001173324647_p182161855921"></a><a name="zh-cn_topic_0000001173324647_p182161855921"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="45.5945594559456%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173324647_p921685513212"><a name="zh-cn_topic_0000001173324647_p921685513212"></a><a name="zh-cn_topic_0000001173324647_p921685513212"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173324647_row102168555217"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173324647_p1221625514210"><a name="zh-cn_topic_0000001173324647_p1221625514210"></a><a name="zh-cn_topic_0000001173324647_p1221625514210"></a>change</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173324647_p8216155822"><a name="zh-cn_topic_0000001173324647_p8216155822"></a><a name="zh-cn_topic_0000001173324647_p8216155822"></a>{ value:inputValue }</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173324647_p18216135511213"><a name="zh-cn_topic_0000001173324647_p18216135511213"></a><a name="zh-cn_topic_0000001173324647_p18216135511213"></a>输入框输入内容发生变化时触发该事件，返回用户当前输入值。</p>
    <div class="note" id="zh-cn_topic_0000001173324647_note32161955422"><a name="zh-cn_topic_0000001173324647_note32161955422"></a><a name="zh-cn_topic_0000001173324647_note32161955422"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001173324647_p521616551527"><a name="zh-cn_topic_0000001173324647_p521616551527"></a><a name="zh-cn_topic_0000001173324647_p521616551527"></a>改变value属性值不会触发该回调。</p>
    </div></div>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173324647_row152166550212"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173324647_p1121695515215"><a name="zh-cn_topic_0000001173324647_p1121695515215"></a><a name="zh-cn_topic_0000001173324647_p1121695515215"></a>enterkeyclick</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173324647_p15216115511211"><a name="zh-cn_topic_0000001173324647_p15216115511211"></a><a name="zh-cn_topic_0000001173324647_p15216115511211"></a>{ value:enterKey }</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173324647_p162165551211"><a name="zh-cn_topic_0000001173324647_p162165551211"></a><a name="zh-cn_topic_0000001173324647_p162165551211"></a>软键盘enter键点击后触发该事件，返回enter按钮的类型，enterKey类型为number，可选值为：</p>
    <a name="zh-cn_topic_0000001173324647_ul121665519215"></a><a name="zh-cn_topic_0000001173324647_ul121665519215"></a><ul id="zh-cn_topic_0000001173324647_ul121665519215"><li>2：设置enterkeytype属性为go时生效。</li><li>3：设置enterkeytype属性为search时生效。</li><li>4：设置enterkeytype属性为send时生效。</li><li>5：设置enterkeytype属性为next时生效。</li><li>6：不设置enterkeytype或者设置enterkeytype属性为default、done时生效。</li></ul>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173324647_row1121715551027"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173324647_p92175551422"><a name="zh-cn_topic_0000001173324647_p92175551422"></a><a name="zh-cn_topic_0000001173324647_p92175551422"></a>translate<sup id="zh-cn_topic_0000001173324647_sup13217195510219"><a name="zh-cn_topic_0000001173324647_sup13217195510219"></a><a name="zh-cn_topic_0000001173324647_sup13217195510219"></a>5+</sup></p>
    </td>
    <td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173324647_p321795510218"><a name="zh-cn_topic_0000001173324647_p321795510218"></a><a name="zh-cn_topic_0000001173324647_p321795510218"></a>{ value: selectedText }</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173324647_p92171455627"><a name="zh-cn_topic_0000001173324647_p92171455627"></a><a name="zh-cn_topic_0000001173324647_p92171455627"></a>设置此事件后，进行文本选择操作后文本选择弹窗会出现翻译按钮，点击翻译按钮之后，触发该回调，返回选中的文本内容。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173324647_row1821711551524"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173324647_p1321711551229"><a name="zh-cn_topic_0000001173324647_p1321711551229"></a><a name="zh-cn_topic_0000001173324647_p1321711551229"></a>share<sup id="zh-cn_topic_0000001173324647_sup182171255223"><a name="zh-cn_topic_0000001173324647_sup182171255223"></a><a name="zh-cn_topic_0000001173324647_sup182171255223"></a>5+</sup></p>
    </td>
    <td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173324647_p92171555228"><a name="zh-cn_topic_0000001173324647_p92171555228"></a><a name="zh-cn_topic_0000001173324647_p92171555228"></a>{ value: selectedText }</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173324647_p122171055425"><a name="zh-cn_topic_0000001173324647_p122171055425"></a><a name="zh-cn_topic_0000001173324647_p122171055425"></a>设置此事件后，进行文本选择操作后文本选择弹窗会出现分享按钮，点击分享按钮之后，触发该回调，返回选中的文本内容。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173324647_row1921717551028"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173324647_p1821716555210"><a name="zh-cn_topic_0000001173324647_p1821716555210"></a><a name="zh-cn_topic_0000001173324647_p1821716555210"></a>search<sup id="zh-cn_topic_0000001173324647_sup20217175516211"><a name="zh-cn_topic_0000001173324647_sup20217175516211"></a><a name="zh-cn_topic_0000001173324647_sup20217175516211"></a>5+</sup></p>
    </td>
    <td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173324647_p1421715514216"><a name="zh-cn_topic_0000001173324647_p1421715514216"></a><a name="zh-cn_topic_0000001173324647_p1421715514216"></a>{ value: selectedText }</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173324647_p20217175515210"><a name="zh-cn_topic_0000001173324647_p20217175515210"></a><a name="zh-cn_topic_0000001173324647_p20217175515210"></a>设置此事件后，进行文本选择操作后文本选择弹窗会出现搜索按钮，点击搜索按钮之后，触发该回调，返回选中的文本内容。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173324647_row2021725516220"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173324647_p521715553212"><a name="zh-cn_topic_0000001173324647_p521715553212"></a><a name="zh-cn_topic_0000001173324647_p521715553212"></a>optionselect<sup id="zh-cn_topic_0000001173324647_sup122171855227"><a name="zh-cn_topic_0000001173324647_sup122171855227"></a><a name="zh-cn_topic_0000001173324647_sup122171855227"></a><span>5+</span></sup></p>
    </td>
    <td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173324647_p721885513216"><a name="zh-cn_topic_0000001173324647_p721885513216"></a><a name="zh-cn_topic_0000001173324647_p721885513216"></a>{ index:optionIndex, value: selectedText }</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173324647_p721812557212"><a name="zh-cn_topic_0000001173324647_p721812557212"></a><a name="zh-cn_topic_0000001173324647_p721812557212"></a>文本选择弹窗中设置menuoptions属性后，用户在文本选择操作后，点击菜单项后触发该回调，返回点击的菜单项序号和选中的文本内容。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173324647_row1180295735010"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173324647_p17803157175014"><a name="zh-cn_topic_0000001173324647_p17803157175014"></a><a name="zh-cn_topic_0000001173324647_p17803157175014"></a>selectchange<sup id="zh-cn_topic_0000001173324647_sup774434715119"><a name="zh-cn_topic_0000001173324647_sup774434715119"></a><a name="zh-cn_topic_0000001173324647_sup774434715119"></a>6+</sup></p>
    </td>
    <td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173324647_p13803157185013"><a name="zh-cn_topic_0000001173324647_p13803157185013"></a><a name="zh-cn_topic_0000001173324647_p13803157185013"></a>{ start: number，end: number }</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173324647_p4803155719505"><a name="zh-cn_topic_0000001173324647_p4803155719505"></a><a name="zh-cn_topic_0000001173324647_p4803155719505"></a>文本选择变化时触发事件。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   当input类型为checkbox、radio时，支持如下事件：

    <a name="zh-cn_topic_0000001173324647_table722013552211"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001173324647_row1220145519211"><th class="cellrowborder" valign="top" width="24.852485248524854%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173324647_p1220755621"><a name="zh-cn_topic_0000001173324647_p1220755621"></a><a name="zh-cn_topic_0000001173324647_p1220755621"></a>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="29.552955295529554%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173324647_p322014550213"><a name="zh-cn_topic_0000001173324647_p322014550213"></a><a name="zh-cn_topic_0000001173324647_p322014550213"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="45.5945594559456%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173324647_p322117554212"><a name="zh-cn_topic_0000001173324647_p322117554212"></a><a name="zh-cn_topic_0000001173324647_p322117554212"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001173324647_row1622118559216"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173324647_p922116551422"><a name="zh-cn_topic_0000001173324647_p922116551422"></a><a name="zh-cn_topic_0000001173324647_p922116551422"></a>change</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173324647_p1322185512210"><a name="zh-cn_topic_0000001173324647_p1322185512210"></a><a name="zh-cn_topic_0000001173324647_p1322185512210"></a>{ checked:true | false }</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173324647_p1822119551024"><a name="zh-cn_topic_0000001173324647_p1822119551024"></a><a name="zh-cn_topic_0000001173324647_p1822119551024"></a>checkbox多选框或radio单选框的checked状态发生变化时触发该事件。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 方法<a name="zh-cn_topic_0000001173324647_section47669296127"></a>

除支持[通用方法](js-components-common-methods.md)外，还支持如下方法：

<a name="zh-cn_topic_0000001173324647_t75606345ece64f818511af2963b4522d"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173324647_rf7e96304e96b4abcada899f917623b50"><th class="cellrowborder" valign="top" width="16.88%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173324647_abdd98ec01df046a7ac2f66a3fa4eda04"><a name="zh-cn_topic_0000001173324647_abdd98ec01df046a7ac2f66a3fa4eda04"></a><a name="zh-cn_topic_0000001173324647_abdd98ec01df046a7ac2f66a3fa4eda04"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="29.12%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173324647_afa86bf0c638b4860a91ea0e6255b7744"><a name="zh-cn_topic_0000001173324647_afa86bf0c638b4860a91ea0e6255b7744"></a><a name="zh-cn_topic_0000001173324647_afa86bf0c638b4860a91ea0e6255b7744"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="54%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173324647_aa7783f4706e8434493b6e941e0100652"><a name="zh-cn_topic_0000001173324647_aa7783f4706e8434493b6e941e0100652"></a><a name="zh-cn_topic_0000001173324647_aa7783f4706e8434493b6e941e0100652"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173324647_r51da7a66ad844356a54fc7d198bbc496"><td class="cellrowborder" valign="top" width="16.88%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173324647_a37c62c3017bc4b85813051fedae5523a"><a name="zh-cn_topic_0000001173324647_a37c62c3017bc4b85813051fedae5523a"></a><a name="zh-cn_topic_0000001173324647_a37c62c3017bc4b85813051fedae5523a"></a>focus</p>
</td>
<td class="cellrowborder" valign="top" width="29.12%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173324647_a0fa3cdedaab94e11b1c1df493e671084"><a name="zh-cn_topic_0000001173324647_a0fa3cdedaab94e11b1c1df493e671084"></a><a name="zh-cn_topic_0000001173324647_a0fa3cdedaab94e11b1c1df493e671084"></a>{ focus: true|false }，focus不传默认为true。</p>
</td>
<td class="cellrowborder" valign="top" width="54%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173324647_abc7c81f1669e4e27bdc255ddf7c24167"><a name="zh-cn_topic_0000001173324647_abc7c81f1669e4e27bdc255ddf7c24167"></a><a name="zh-cn_topic_0000001173324647_abc7c81f1669e4e27bdc255ddf7c24167"></a>使组件获得或者失去焦点，type为text|email|date|time|number|password时，可弹出或收起输入法。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324647_row17342754165611"><td class="cellrowborder" valign="top" width="16.88%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173324647_p1343054115615"><a name="zh-cn_topic_0000001173324647_p1343054115615"></a><a name="zh-cn_topic_0000001173324647_p1343054115615"></a>showError</p>
</td>
<td class="cellrowborder" valign="top" width="29.12%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173324647_p153431354175613"><a name="zh-cn_topic_0000001173324647_p153431354175613"></a><a name="zh-cn_topic_0000001173324647_p153431354175613"></a>{ error: string }</p>
</td>
<td class="cellrowborder" valign="top" width="54%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173324647_p1034315465618"><a name="zh-cn_topic_0000001173324647_p1034315465618"></a><a name="zh-cn_topic_0000001173324647_p1034315465618"></a>展示输入错误提示，type为text|email|date|time|number|password时生效。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324647_row4919162415418"><td class="cellrowborder" valign="top" width="16.88%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173324647_p191914240419"><a name="zh-cn_topic_0000001173324647_p191914240419"></a><a name="zh-cn_topic_0000001173324647_p191914240419"></a>delete<sup id="zh-cn_topic_0000001173324647_sup1636182514275"><a name="zh-cn_topic_0000001173324647_sup1636182514275"></a><a name="zh-cn_topic_0000001173324647_sup1636182514275"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="29.12%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173324647_p209201424104119"><a name="zh-cn_topic_0000001173324647_p209201424104119"></a><a name="zh-cn_topic_0000001173324647_p209201424104119"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="54%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173324647_p2920424124118"><a name="zh-cn_topic_0000001173324647_p2920424124118"></a><a name="zh-cn_topic_0000001173324647_p2920424124118"></a>type为text|email|date|time|number|password时，根据当前光标位置删除文本内容，如果当前输入组件没有光标，默认删除最后一个字符并展示光标。</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="zh-cn_topic_0000001173324647_section106355275448"></a>

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

    ![](figures/zh-cn_image_0000001212320071.png)

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

    ![](figures/zh-cn_image_0000001166601620.png)

3.  type为checkbox

    ```
    <!-- xxx.hml -->
    <div class="content">
      <input onchange="checkboxOnChange" checked="true"' type="checkbox"></input>
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

    ![](figures/zh-cn_image_0000001212161499.png)

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

    ![](figures/zh-cn_image_0000001212081537.png)


