# input<a name="ZH-CN_TOPIC_0000001173324647"></a>

交互式组件，包括单选框，多选框，按钮和单行文本输入框。

## 权限列表<a name="section11257113618419"></a>

无

## 子组件<a name="section9288143101012"></a>

不支持。

## 属性<a name="section2907183951110"></a>

除支持[通用属性](js-components-common-attributes.md)外，还支持如下属性：

<a name="table20633101642315"></a>
<table><thead align="left"><tr id="row663331618238"><th class="cellrowborder" valign="top" width="20.26%" id="mcps1.1.6.1.1"><p id="aa872998ac2d84843a3c5161889afffef"><a name="aa872998ac2d84843a3c5161889afffef"></a><a name="aa872998ac2d84843a3c5161889afffef"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="9.42%" id="mcps1.1.6.1.2"><p id="ab2111648ee0e4f6d881be8954e7acaab"><a name="ab2111648ee0e4f6d881be8954e7acaab"></a><a name="ab2111648ee0e4f6d881be8954e7acaab"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="14.549999999999999%" id="mcps1.1.6.1.3"><p id="ab377d1c90900478ea4ecab51e9a058af"><a name="ab377d1c90900478ea4ecab51e9a058af"></a><a name="ab377d1c90900478ea4ecab51e9a058af"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="8.01%" id="mcps1.1.6.1.4"><p id="p824610360217"><a name="p824610360217"></a><a name="p824610360217"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="47.760000000000005%" id="mcps1.1.6.1.5"><p id="a1d574a0044ed42ec8a2603bc82734232"><a name="a1d574a0044ed42ec8a2603bc82734232"></a><a name="a1d574a0044ed42ec8a2603bc82734232"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row634417439274"><td class="cellrowborder" valign="top" width="20.26%" headers="mcps1.1.6.1.1 "><p id="p72442555275"><a name="p72442555275"></a><a name="p72442555275"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="9.42%" headers="mcps1.1.6.1.2 "><p id="p324455511276"><a name="p324455511276"></a><a name="p324455511276"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="14.549999999999999%" headers="mcps1.1.6.1.3 "><p id="p16244055182716"><a name="p16244055182716"></a><a name="p16244055182716"></a>text</p>
</td>
<td class="cellrowborder" valign="top" width="8.01%" headers="mcps1.1.6.1.4 "><p id="p3244155102714"><a name="p3244155102714"></a><a name="p3244155102714"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.760000000000005%" headers="mcps1.1.6.1.5 "><p id="p924475517275"><a name="p924475517275"></a><a name="p924475517275"></a>input组件类型，可选值为<span id="ph42442055152718"><a name="ph42442055152718"></a><a name="ph42442055152718"></a>text，email，date，time，number，password，</span>button，checkbox，radio。</p>
<p id="p1524485513274"><a name="p1524485513274"></a><a name="p1524485513274"></a>其中text，email，date，time，number，password这六种类型之间支持动态切换修改。</p>
<p id="p17244175532712"><a name="p17244175532712"></a><a name="p17244175532712"></a>button，checkbox，radio不支持动态修改。可选值定义如下：</p>
<a name="ul324417555275"></a><a name="ul324417555275"></a><ul id="ul324417555275"><li>button：定义可点击的按钮；</li><li>checkbox：定义多选框；</li><li>radio：定义单选按钮，允许在多个拥有相同name值的选项中选中其中一个；</li><li>text：定义一个单行的文本字段</li><li>email：定义用于e-mail地址的字段；</li><li>date：定义 date 控件（包括年、月、日，不包括时间）；</li><li>time：定义用于输入时间的控件（不带时区）；</li><li>number：定义用于输入数字的字段；</li><li>password：定义密码字段（字段中的字符会被遮蔽）。<div class="note" id="note45664136102"><a name="note45664136102"></a><a name="note45664136102"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="p1551717289101"><a name="p1551717289101"></a><a name="p1551717289101"></a>智能穿戴仅支持button、radio、checkbox类型。</p>
</div></div>
</li></ul>
</td>
</tr>
<tr id="row43454437272"><td class="cellrowborder" valign="top" width="20.26%" headers="mcps1.1.6.1.1 "><p id="p5245185582713"><a name="p5245185582713"></a><a name="p5245185582713"></a>checked</p>
</td>
<td class="cellrowborder" valign="top" width="9.42%" headers="mcps1.1.6.1.2 "><p id="p202456551277"><a name="p202456551277"></a><a name="p202456551277"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="14.549999999999999%" headers="mcps1.1.6.1.3 "><p id="p1245165520272"><a name="p1245165520272"></a><a name="p1245165520272"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="8.01%" headers="mcps1.1.6.1.4 "><p id="p6245855172718"><a name="p6245855172718"></a><a name="p6245855172718"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.760000000000005%" headers="mcps1.1.6.1.5 "><p id="p12245115512279"><a name="p12245115512279"></a><a name="p12245115512279"></a>当前组件是否选中，仅type为checkbox和radio生效。</p>
</td>
</tr>
<tr id="row834544342712"><td class="cellrowborder" valign="top" width="20.26%" headers="mcps1.1.6.1.1 "><p id="p19245855182719"><a name="p19245855182719"></a><a name="p19245855182719"></a>name</p>
</td>
<td class="cellrowborder" valign="top" width="9.42%" headers="mcps1.1.6.1.2 "><p id="p2245955192720"><a name="p2245955192720"></a><a name="p2245955192720"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="14.549999999999999%" headers="mcps1.1.6.1.3 "><p id="p14245115502719"><a name="p14245115502719"></a><a name="p14245115502719"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.01%" headers="mcps1.1.6.1.4 "><p id="p32451755182718"><a name="p32451755182718"></a><a name="p32451755182718"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.760000000000005%" headers="mcps1.1.6.1.5 "><p id="p20245135542717"><a name="p20245135542717"></a><a name="p20245135542717"></a>input组件的名称。</p>
</td>
</tr>
<tr id="row18345124342713"><td class="cellrowborder" valign="top" width="20.26%" headers="mcps1.1.6.1.1 "><p id="p0245185592712"><a name="p0245185592712"></a><a name="p0245185592712"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="9.42%" headers="mcps1.1.6.1.2 "><p id="p1224525518275"><a name="p1224525518275"></a><a name="p1224525518275"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="14.549999999999999%" headers="mcps1.1.6.1.3 "><p id="p5245115582715"><a name="p5245115582715"></a><a name="p5245115582715"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.01%" headers="mcps1.1.6.1.4 "><p id="p624515512278"><a name="p624515512278"></a><a name="p624515512278"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.760000000000005%" headers="mcps1.1.6.1.5 "><p id="p0245255112710"><a name="p0245255112710"></a><a name="p0245255112710"></a>input组件的value值，当类型为radio时必填且相同name值的选项该值唯一。</p>
</td>
</tr>
<tr id="row1360803719278"><td class="cellrowborder" valign="top" width="20.26%" headers="mcps1.1.6.1.1 "><p id="p52451955152716"><a name="p52451955152716"></a><a name="p52451955152716"></a>placeholder</p>
</td>
<td class="cellrowborder" valign="top" width="9.42%" headers="mcps1.1.6.1.2 "><p id="p2246135512274"><a name="p2246135512274"></a><a name="p2246135512274"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="14.549999999999999%" headers="mcps1.1.6.1.3 "><p id="p12462557277"><a name="p12462557277"></a><a name="p12462557277"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.01%" headers="mcps1.1.6.1.4 "><p id="p6246125562716"><a name="p6246125562716"></a><a name="p6246125562716"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.760000000000005%" headers="mcps1.1.6.1.5 "><p id="p4246205572711"><a name="p4246205572711"></a><a name="p4246205572711"></a>设置提示文本的内容，仅在type为text|email|date|time|number|password时生效。</p>
</td>
</tr>
<tr id="row10729734112719"><td class="cellrowborder" valign="top" width="20.26%" headers="mcps1.1.6.1.1 "><p id="p524615562717"><a name="p524615562717"></a><a name="p524615562717"></a>maxlength</p>
</td>
<td class="cellrowborder" valign="top" width="9.42%" headers="mcps1.1.6.1.2 "><p id="p4246165562713"><a name="p4246165562713"></a><a name="p4246165562713"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="14.549999999999999%" headers="mcps1.1.6.1.3 "><p id="p1246135522711"><a name="p1246135522711"></a><a name="p1246135522711"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.01%" headers="mcps1.1.6.1.4 "><p id="p13246185517271"><a name="p13246185517271"></a><a name="p13246185517271"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.760000000000005%" headers="mcps1.1.6.1.5 "><p id="p1224635514274"><a name="p1224635514274"></a><a name="p1224635514274"></a>输入框可输入的最多字符数量，不填表示不限制输入框中字符数量。</p>
</td>
</tr>
<tr id="row1125513210279"><td class="cellrowborder" valign="top" width="20.26%" headers="mcps1.1.6.1.1 "><p id="p14246125513277"><a name="p14246125513277"></a><a name="p14246125513277"></a>enterkeytype</p>
</td>
<td class="cellrowborder" valign="top" width="9.42%" headers="mcps1.1.6.1.2 "><p id="p7246055112718"><a name="p7246055112718"></a><a name="p7246055112718"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="14.549999999999999%" headers="mcps1.1.6.1.3 "><p id="p1324615552276"><a name="p1324615552276"></a><a name="p1324615552276"></a>default</p>
</td>
<td class="cellrowborder" valign="top" width="8.01%" headers="mcps1.1.6.1.4 "><p id="p10246115514272"><a name="p10246115514272"></a><a name="p10246115514272"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.760000000000005%" headers="mcps1.1.6.1.5 "><p id="p1824635502717"><a name="p1824635502717"></a><a name="p1824635502717"></a>不支持动态修改。</p>
<p id="p12246255112712"><a name="p12246255112712"></a><a name="p12246255112712"></a>设置软键盘Enter按钮的类型，可选值为：</p>
<a name="ul52461055142716"></a><a name="ul52461055142716"></a><ul id="ul52461055142716"><li>default：默认</li><li>next：下一项</li><li>go：前往</li><li>done：完成</li><li>send：发送</li><li>search：搜索</li></ul>
<div class="note" id="note1524765512720"><a name="note1524765512720"></a><a name="note1524765512720"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="p124795592715"><a name="p124795592715"></a><a name="p124795592715"></a>除“next”外，点击后会自动收起软键盘。</p>
</div></div>
</td>
</tr>
<tr id="row2461329122714"><td class="cellrowborder" valign="top" width="20.26%" headers="mcps1.1.6.1.1 "><p id="p8247655162711"><a name="p8247655162711"></a><a name="p8247655162711"></a>headericon</p>
</td>
<td class="cellrowborder" valign="top" width="9.42%" headers="mcps1.1.6.1.2 "><p id="p18247145520271"><a name="p18247145520271"></a><a name="p18247145520271"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="14.549999999999999%" headers="mcps1.1.6.1.3 "><p id="p824715572713"><a name="p824715572713"></a><a name="p824715572713"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.01%" headers="mcps1.1.6.1.4 "><p id="p2247135582717"><a name="p2247135582717"></a><a name="p2247135582717"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.760000000000005%" headers="mcps1.1.6.1.5 "><p id="p20247755102711"><a name="p20247755102711"></a><a name="p20247755102711"></a>在文本输入前的图标资源路径，该图标不支持点击事件（button，checkbox和radio不生效），图标格式为jpg，png和svg。</p>
</td>
</tr>
<tr id="row16836876325"><td class="cellrowborder" valign="top" width="20.26%" headers="mcps1.1.6.1.1 "><p id="p983712712329"><a name="p983712712329"></a><a name="p983712712329"></a>showcounter<sup id="sup19271132920334"><a name="sup19271132920334"></a><a name="sup19271132920334"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="9.42%" headers="mcps1.1.6.1.2 "><p id="p178371971325"><a name="p178371971325"></a><a name="p178371971325"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="14.549999999999999%" headers="mcps1.1.6.1.3 "><p id="p28374743210"><a name="p28374743210"></a><a name="p28374743210"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="8.01%" headers="mcps1.1.6.1.4 "><p id="p6837677327"><a name="p6837677327"></a><a name="p6837677327"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.760000000000005%" headers="mcps1.1.6.1.5 "><p id="p11837472328"><a name="p11837472328"></a><a name="p11837472328"></a>文本输入框是否显示计数下标，需要配合maxlength一起使用。</p>
</td>
</tr>
<tr id="row07211971743"><td class="cellrowborder" valign="top" width="20.26%" headers="mcps1.1.6.1.1 "><p id="p177221571244"><a name="p177221571244"></a><a name="p177221571244"></a>menuoptions<sup id="sup154944401542"><a name="sup154944401542"></a><a name="sup154944401542"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="9.42%" headers="mcps1.1.6.1.2 "><p id="p8722157248"><a name="p8722157248"></a><a name="p8722157248"></a>Array&lt;<a href="#table83621954963">MenuOption</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="14.549999999999999%" headers="mcps1.1.6.1.3 "><p id="p167221878414"><a name="p167221878414"></a><a name="p167221878414"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.01%" headers="mcps1.1.6.1.4 "><p id="p197227713411"><a name="p197227713411"></a><a name="p197227713411"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.760000000000005%" headers="mcps1.1.6.1.5 "><p id="p207221573417"><a name="p207221573417"></a><a name="p207221573417"></a>设置文本选择弹框点击更多按钮之后显示的菜单项。</p>
</td>
</tr>
<tr id="row45541828184811"><td class="cellrowborder" valign="top" width="20.26%" headers="mcps1.1.6.1.1 "><p id="p95550281483"><a name="p95550281483"></a><a name="p95550281483"></a>autofocus<sup id="sup1775142235010"><a name="sup1775142235010"></a><a name="sup1775142235010"></a><span>6+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="9.42%" headers="mcps1.1.6.1.2 "><p id="p1955511286485"><a name="p1955511286485"></a><a name="p1955511286485"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="14.549999999999999%" headers="mcps1.1.6.1.3 "><p id="p6555192874812"><a name="p6555192874812"></a><a name="p6555192874812"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="8.01%" headers="mcps1.1.6.1.4 "><p id="p3555142844817"><a name="p3555142844817"></a><a name="p3555142844817"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.760000000000005%" headers="mcps1.1.6.1.5 "><p id="p135551628184820"><a name="p135551628184820"></a><a name="p135551628184820"></a>是否自动获焦。</p>
<div class="note" id="note9175194313116"><a name="note9175194313116"></a><a name="note9175194313116"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="p554143517446"><a name="p554143517446"></a><a name="p554143517446"></a>应用首页中设置不生效，可在onActive中延迟（100-500ms左右）调用focus方法实现输入框在首页中自动获焦。</p>
</div></div>
</td>
</tr>
<tr id="row1261993119486"><td class="cellrowborder" valign="top" width="20.26%" headers="mcps1.1.6.1.1 "><p id="p16196311485"><a name="p16196311485"></a><a name="p16196311485"></a>selectedstart<sup id="sup151911922125019"><a name="sup151911922125019"></a><a name="sup151911922125019"></a><span>6+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="9.42%" headers="mcps1.1.6.1.2 "><p id="p126191631104819"><a name="p126191631104819"></a><a name="p126191631104819"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="14.549999999999999%" headers="mcps1.1.6.1.3 "><p id="p7619163110489"><a name="p7619163110489"></a><a name="p7619163110489"></a>-1</p>
</td>
<td class="cellrowborder" valign="top" width="8.01%" headers="mcps1.1.6.1.4 "><p id="p1619123120488"><a name="p1619123120488"></a><a name="p1619123120488"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.760000000000005%" headers="mcps1.1.6.1.5 "><p id="p9619113118488"><a name="p9619113118488"></a><a name="p9619113118488"></a>开始选择文本时初始选择位置。</p>
</td>
</tr>
<tr id="row1823083417484"><td class="cellrowborder" valign="top" width="20.26%" headers="mcps1.1.6.1.1 "><p id="p42301334184813"><a name="p42301334184813"></a><a name="p42301334184813"></a>selectedend<sup id="sup759182155017"><a name="sup759182155017"></a><a name="sup759182155017"></a><span>6+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="9.42%" headers="mcps1.1.6.1.2 "><p id="p1523013444810"><a name="p1523013444810"></a><a name="p1523013444810"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="14.549999999999999%" headers="mcps1.1.6.1.3 "><p id="p1823053404815"><a name="p1823053404815"></a><a name="p1823053404815"></a>-1</p>
</td>
<td class="cellrowborder" valign="top" width="8.01%" headers="mcps1.1.6.1.4 "><p id="p162301434104819"><a name="p162301434104819"></a><a name="p162301434104819"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.760000000000005%" headers="mcps1.1.6.1.5 "><p id="p2023014344489"><a name="p2023014344489"></a><a name="p2023014344489"></a>开始选择文本时结尾选择位置。</p>
</td>
</tr>
<tr id="row6428183714485"><td class="cellrowborder" valign="top" width="20.26%" headers="mcps1.1.6.1.1 "><p id="p11428837134811"><a name="p11428837134811"></a><a name="p11428837134811"></a>softkeyboardenabled<sup id="sup135541120205017"><a name="sup135541120205017"></a><a name="sup135541120205017"></a><span>6+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="9.42%" headers="mcps1.1.6.1.2 "><p id="p18428837114816"><a name="p18428837114816"></a><a name="p18428837114816"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="14.549999999999999%" headers="mcps1.1.6.1.3 "><p id="p124281037144812"><a name="p124281037144812"></a><a name="p124281037144812"></a>true</p>
</td>
<td class="cellrowborder" valign="top" width="8.01%" headers="mcps1.1.6.1.4 "><p id="p842823714486"><a name="p842823714486"></a><a name="p842823714486"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.760000000000005%" headers="mcps1.1.6.1.5 "><p id="p1642873734813"><a name="p1642873734813"></a><a name="p1642873734813"></a>编辑时是否弹出系统软键盘。</p>
</td>
</tr>
<tr id="row18278391483"><td class="cellrowborder" valign="top" width="20.26%" headers="mcps1.1.6.1.1 "><p id="p10827143911483"><a name="p10827143911483"></a><a name="p10827143911483"></a>showpasswordicon<sup id="sup65401815115011"><a name="sup65401815115011"></a><a name="sup65401815115011"></a><span>6+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="9.42%" headers="mcps1.1.6.1.2 "><p id="p882719398489"><a name="p882719398489"></a><a name="p882719398489"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="14.549999999999999%" headers="mcps1.1.6.1.3 "><p id="p1082753994811"><a name="p1082753994811"></a><a name="p1082753994811"></a>true</p>
</td>
<td class="cellrowborder" valign="top" width="8.01%" headers="mcps1.1.6.1.4 "><p id="p13827183954817"><a name="p13827183954817"></a><a name="p13827183954817"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.760000000000005%" headers="mcps1.1.6.1.5 "><p id="p10828939174817"><a name="p10828939174817"></a><a name="p10828939174817"></a>是否显示密码框末尾的图标（仅type为password时生效）。</p>
</td>
</tr>
</tbody>
</table>

**表 1**  MenuOption<sup>5+</sup>

<a name="table83621954963"></a>
<table><thead align="left"><tr id="row536212545619"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p143621541967"><a name="p143621541967"></a><a name="p143621541967"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p936215541620"><a name="p936215541620"></a><a name="p936215541620"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p23626541665"><a name="p23626541665"></a><a name="p23626541665"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row5362254461"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p33631541265"><a name="p33631541265"></a><a name="p33631541265"></a>icon</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p536311543619"><a name="p536311543619"></a><a name="p536311543619"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p73631954762"><a name="p73631954762"></a><a name="p73631954762"></a>菜单选项中的图标路径。</p>
</td>
</tr>
<tr id="row136319547613"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p12363654367"><a name="p12363654367"></a><a name="p12363654367"></a>content</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p1936312549617"><a name="p1936312549617"></a><a name="p1936312549617"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1036311548616"><a name="p1036311548616"></a><a name="p1036311548616"></a>菜单选项中的文本内容。</p>
</td>
</tr>
</tbody>
</table>

## 样式<a name="section066012492913"></a>

除支持[通用样式](js-components-common-styles.md)外，还支持如下样式：

<a name="table168129500519"></a>
<table><thead align="left"><tr id="row3812115020515"><th class="cellrowborder" valign="top" width="23.11768823117688%" id="mcps1.1.6.1.1"><p id="p178128502053"><a name="p178128502053"></a><a name="p178128502053"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="20.537946205379463%" id="mcps1.1.6.1.2"><p id="p781295016511"><a name="p781295016511"></a><a name="p781295016511"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="22.757724227577242%" id="mcps1.1.6.1.3"><p id="p178126501150"><a name="p178126501150"></a><a name="p178126501150"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.58924107589241%" id="mcps1.1.6.1.4"><p id="p19812950754"><a name="p19812950754"></a><a name="p19812950754"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="25.997400259974%" id="mcps1.1.6.1.5"><p id="p381218501456"><a name="p381218501456"></a><a name="p381218501456"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row581317501655"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p12813750459"><a name="p12813750459"></a><a name="p12813750459"></a>color</p>
</td>
<td class="cellrowborder" valign="top" width="20.537946205379463%" headers="mcps1.1.6.1.2 "><p id="p148132501751"><a name="p148132501751"></a><a name="p148132501751"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="22.757724227577242%" headers="mcps1.1.6.1.3 "><p id="p16813350256"><a name="p16813350256"></a><a name="p16813350256"></a>#e6000000</p>
</td>
<td class="cellrowborder" valign="top" width="7.58924107589241%" headers="mcps1.1.6.1.4 "><p id="p1481311501514"><a name="p1481311501514"></a><a name="p1481311501514"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="25.997400259974%" headers="mcps1.1.6.1.5 "><p id="p138135501758"><a name="p138135501758"></a><a name="p138135501758"></a>单行输入框或者按钮的文本颜色。</p>
</td>
</tr>
<tr id="row13813175013515"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p118131250153"><a name="p118131250153"></a><a name="p118131250153"></a>font-size</p>
</td>
<td class="cellrowborder" valign="top" width="20.537946205379463%" headers="mcps1.1.6.1.2 "><p id="p19813155013512"><a name="p19813155013512"></a><a name="p19813155013512"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="22.757724227577242%" headers="mcps1.1.6.1.3 "><p id="p88134501155"><a name="p88134501155"></a><a name="p88134501155"></a>16px</p>
</td>
<td class="cellrowborder" valign="top" width="7.58924107589241%" headers="mcps1.1.6.1.4 "><p id="p381305019519"><a name="p381305019519"></a><a name="p381305019519"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="25.997400259974%" headers="mcps1.1.6.1.5 "><p id="p148131050253"><a name="p148131050253"></a><a name="p148131050253"></a>单行输入框或者按钮的文本尺寸。</p>
</td>
</tr>
<tr id="row481312502519"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p3813050954"><a name="p3813050954"></a><a name="p3813050954"></a>allow-scale</p>
</td>
<td class="cellrowborder" valign="top" width="20.537946205379463%" headers="mcps1.1.6.1.2 "><p id="p138139503518"><a name="p138139503518"></a><a name="p138139503518"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="22.757724227577242%" headers="mcps1.1.6.1.3 "><p id="p181455012517"><a name="p181455012517"></a><a name="p181455012517"></a>true</p>
</td>
<td class="cellrowborder" valign="top" width="7.58924107589241%" headers="mcps1.1.6.1.4 "><p id="p8814145015518"><a name="p8814145015518"></a><a name="p8814145015518"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="25.997400259974%" headers="mcps1.1.6.1.5 "><p id="p12814195013511"><a name="p12814195013511"></a><a name="p12814195013511"></a>单行输入框或者按钮的文本尺寸是否跟随系统设置字体缩放尺寸进行放大缩小。</p>
<div class="note" id="note1781416501358"><a name="note1781416501358"></a><a name="note1781416501358"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="p13814145011511"><a name="p13814145011511"></a><a name="p13814145011511"></a>如果在config描述文件中针对ability配置了fontSize的config-changes标签，则应用不会重启而直接生效。</p>
</div></div>
</td>
</tr>
<tr id="row781413506518"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p581410501158"><a name="p581410501158"></a><a name="p581410501158"></a>placeholder-color</p>
</td>
<td class="cellrowborder" valign="top" width="20.537946205379463%" headers="mcps1.1.6.1.2 "><p id="p1781419501555"><a name="p1781419501555"></a><a name="p1781419501555"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="22.757724227577242%" headers="mcps1.1.6.1.3 "><p id="p4814450854"><a name="p4814450854"></a><a name="p4814450854"></a>#99000000</p>
</td>
<td class="cellrowborder" valign="top" width="7.58924107589241%" headers="mcps1.1.6.1.4 "><p id="p12814350357"><a name="p12814350357"></a><a name="p12814350357"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="25.997400259974%" headers="mcps1.1.6.1.5 "><p id="p138140501751"><a name="p138140501751"></a><a name="p138140501751"></a>单行输入框的提示文本的颜色，type为text|email|date|time|number|password时生效。</p>
</td>
</tr>
<tr id="row58141650752"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p1381435012518"><a name="p1381435012518"></a><a name="p1381435012518"></a>font-weight</p>
</td>
<td class="cellrowborder" valign="top" width="20.537946205379463%" headers="mcps1.1.6.1.2 "><p id="p98141250450"><a name="p98141250450"></a><a name="p98141250450"></a>number | string</p>
</td>
<td class="cellrowborder" valign="top" width="22.757724227577242%" headers="mcps1.1.6.1.3 "><p id="p198141507512"><a name="p198141507512"></a><a name="p198141507512"></a>normal</p>
</td>
<td class="cellrowborder" valign="top" width="7.58924107589241%" headers="mcps1.1.6.1.4 "><p id="p20814185015510"><a name="p20814185015510"></a><a name="p20814185015510"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="25.997400259974%" headers="mcps1.1.6.1.5 "><p id="p1281455014516"><a name="p1281455014516"></a><a name="p1281455014516"></a>单行输入框或者按钮的字体粗细，见<a href="js-components-basic-text.md#section5775351116">text组件font-weight的样式属性</a>。</p>
</td>
</tr>
<tr id="row1167411433019"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p18674104193019"><a name="p18674104193019"></a><a name="p18674104193019"></a>caret-color<sup id="sup628114393018"><a name="sup628114393018"></a><a name="sup628114393018"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.537946205379463%" headers="mcps1.1.6.1.2 "><p id="p13674194173010"><a name="p13674194173010"></a><a name="p13674194173010"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="22.757724227577242%" headers="mcps1.1.6.1.3 "><p id="p12674164113010"><a name="p12674164113010"></a><a name="p12674164113010"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.58924107589241%" headers="mcps1.1.6.1.4 "><p id="p5674114183020"><a name="p5674114183020"></a><a name="p5674114183020"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="25.997400259974%" headers="mcps1.1.6.1.5 "><p id="p18674134153015"><a name="p18674134153015"></a><a name="p18674134153015"></a>设置输入光标的颜色。</p>
</td>
</tr>
</tbody>
</table>

## 事件<a name="section1721512551218"></a>

除支持[通用事件](js-components-common-events.md)外，还支持如下事件：

-   当input类型为text、email、date、time、number、password时，支持如下事件：

    <a name="table9215955923"></a>
    <table><thead align="left"><tr id="row02158552029"><th class="cellrowborder" valign="top" width="24.852485248524854%" id="mcps1.1.4.1.1"><p id="p1121618551728"><a name="p1121618551728"></a><a name="p1121618551728"></a>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="29.552955295529554%" id="mcps1.1.4.1.2"><p id="p182161855921"><a name="p182161855921"></a><a name="p182161855921"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="45.5945594559456%" id="mcps1.1.4.1.3"><p id="p921685513212"><a name="p921685513212"></a><a name="p921685513212"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row102168555217"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p1221625514210"><a name="p1221625514210"></a><a name="p1221625514210"></a>change</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p8216155822"><a name="p8216155822"></a><a name="p8216155822"></a>{ value:inputValue }</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p18216135511213"><a name="p18216135511213"></a><a name="p18216135511213"></a>输入框输入内容发生变化时触发该事件，返回用户当前输入值。</p>
    <div class="note" id="note32161955422"><a name="note32161955422"></a><a name="note32161955422"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="p521616551527"><a name="p521616551527"></a><a name="p521616551527"></a>改变value属性值不会触发该回调。</p>
    </div></div>
    </td>
    </tr>
    <tr id="row152166550212"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p1121695515215"><a name="p1121695515215"></a><a name="p1121695515215"></a>enterkeyclick</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p15216115511211"><a name="p15216115511211"></a><a name="p15216115511211"></a>{ value:enterKey }</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p162165551211"><a name="p162165551211"></a><a name="p162165551211"></a>软键盘enter键点击后触发该事件，返回enter按钮的类型，enterKey类型为number，可选值为：</p>
    <a name="ul121665519215"></a><a name="ul121665519215"></a><ul id="ul121665519215"><li>2：设置enterkeytype属性为go时生效。</li><li>3：设置enterkeytype属性为search时生效。</li><li>4：设置enterkeytype属性为send时生效。</li><li>5：设置enterkeytype属性为next时生效。</li><li>6：不设置enterkeytype或者设置enterkeytype属性为default、done时生效。</li></ul>
    </td>
    </tr>
    <tr id="row1121715551027"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p92175551422"><a name="p92175551422"></a><a name="p92175551422"></a>translate<sup id="sup13217195510219"><a name="sup13217195510219"></a><a name="sup13217195510219"></a>5+</sup></p>
    </td>
    <td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p321795510218"><a name="p321795510218"></a><a name="p321795510218"></a>{ value: selectedText }</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p92171455627"><a name="p92171455627"></a><a name="p92171455627"></a>设置此事件后，进行文本选择操作后文本选择弹窗会出现翻译按钮，点击翻译按钮之后，触发该回调，返回选中的文本内容。</p>
    </td>
    </tr>
    <tr id="row1821711551524"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p1321711551229"><a name="p1321711551229"></a><a name="p1321711551229"></a>share<sup id="sup182171255223"><a name="sup182171255223"></a><a name="sup182171255223"></a>5+</sup></p>
    </td>
    <td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p92171555228"><a name="p92171555228"></a><a name="p92171555228"></a>{ value: selectedText }</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p122171055425"><a name="p122171055425"></a><a name="p122171055425"></a>设置此事件后，进行文本选择操作后文本选择弹窗会出现分享按钮，点击分享按钮之后，触发该回调，返回选中的文本内容。</p>
    </td>
    </tr>
    <tr id="row1921717551028"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p1821716555210"><a name="p1821716555210"></a><a name="p1821716555210"></a>search<sup id="sup20217175516211"><a name="sup20217175516211"></a><a name="sup20217175516211"></a>5+</sup></p>
    </td>
    <td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p1421715514216"><a name="p1421715514216"></a><a name="p1421715514216"></a>{ value: selectedText }</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p20217175515210"><a name="p20217175515210"></a><a name="p20217175515210"></a>设置此事件后，进行文本选择操作后文本选择弹窗会出现搜索按钮，点击搜索按钮之后，触发该回调，返回选中的文本内容。</p>
    </td>
    </tr>
    <tr id="row2021725516220"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p521715553212"><a name="p521715553212"></a><a name="p521715553212"></a>optionselect<sup id="sup122171855227"><a name="sup122171855227"></a><a name="sup122171855227"></a><span>5+</span></sup></p>
    </td>
    <td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p721885513216"><a name="p721885513216"></a><a name="p721885513216"></a>{ index:optionIndex, value: selectedText }</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p721812557212"><a name="p721812557212"></a><a name="p721812557212"></a>文本选择弹窗中设置menuoptions属性后，用户在文本选择操作后，点击菜单项后触发该回调，返回点击的菜单项序号和选中的文本内容。</p>
    </td>
    </tr>
    <tr id="row1180295735010"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p17803157175014"><a name="p17803157175014"></a><a name="p17803157175014"></a>selectchange<sup id="sup774434715119"><a name="sup774434715119"></a><a name="sup774434715119"></a>6+</sup></p>
    </td>
    <td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p13803157185013"><a name="p13803157185013"></a><a name="p13803157185013"></a>{ start: number，end: number }</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p4803155719505"><a name="p4803155719505"></a><a name="p4803155719505"></a>文本选择变化时触发事件。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   当input类型为checkbox、radio时，支持如下事件：

    <a name="table722013552211"></a>
    <table><thead align="left"><tr id="row1220145519211"><th class="cellrowborder" valign="top" width="24.852485248524854%" id="mcps1.1.4.1.1"><p id="p1220755621"><a name="p1220755621"></a><a name="p1220755621"></a>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="29.552955295529554%" id="mcps1.1.4.1.2"><p id="p322014550213"><a name="p322014550213"></a><a name="p322014550213"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="45.5945594559456%" id="mcps1.1.4.1.3"><p id="p322117554212"><a name="p322117554212"></a><a name="p322117554212"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1622118559216"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p922116551422"><a name="p922116551422"></a><a name="p922116551422"></a>change</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p1322185512210"><a name="p1322185512210"></a><a name="p1322185512210"></a>{ checked:true | false }</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p1822119551024"><a name="p1822119551024"></a><a name="p1822119551024"></a>checkbox多选框或radio单选框的checked状态发生变化时触发该事件。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 方法<a name="section47669296127"></a>

除支持[通用方法](js-components-common-methods.md)外，还支持如下方法：

<a name="t75606345ece64f818511af2963b4522d"></a>
<table><thead align="left"><tr id="rf7e96304e96b4abcada899f917623b50"><th class="cellrowborder" valign="top" width="16.88%" id="mcps1.1.4.1.1"><p id="abdd98ec01df046a7ac2f66a3fa4eda04"><a name="abdd98ec01df046a7ac2f66a3fa4eda04"></a><a name="abdd98ec01df046a7ac2f66a3fa4eda04"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="29.12%" id="mcps1.1.4.1.2"><p id="afa86bf0c638b4860a91ea0e6255b7744"><a name="afa86bf0c638b4860a91ea0e6255b7744"></a><a name="afa86bf0c638b4860a91ea0e6255b7744"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="54%" id="mcps1.1.4.1.3"><p id="aa7783f4706e8434493b6e941e0100652"><a name="aa7783f4706e8434493b6e941e0100652"></a><a name="aa7783f4706e8434493b6e941e0100652"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="r51da7a66ad844356a54fc7d198bbc496"><td class="cellrowborder" valign="top" width="16.88%" headers="mcps1.1.4.1.1 "><p id="a37c62c3017bc4b85813051fedae5523a"><a name="a37c62c3017bc4b85813051fedae5523a"></a><a name="a37c62c3017bc4b85813051fedae5523a"></a>focus</p>
</td>
<td class="cellrowborder" valign="top" width="29.12%" headers="mcps1.1.4.1.2 "><p id="a0fa3cdedaab94e11b1c1df493e671084"><a name="a0fa3cdedaab94e11b1c1df493e671084"></a><a name="a0fa3cdedaab94e11b1c1df493e671084"></a>{ focus: true|false }，focus不传默认为true。</p>
</td>
<td class="cellrowborder" valign="top" width="54%" headers="mcps1.1.4.1.3 "><p id="abc7c81f1669e4e27bdc255ddf7c24167"><a name="abc7c81f1669e4e27bdc255ddf7c24167"></a><a name="abc7c81f1669e4e27bdc255ddf7c24167"></a>使组件获得或者失去焦点，type为text|email|date|time|number|password时，可弹出或收起输入法。</p>
</td>
</tr>
<tr id="row17342754165611"><td class="cellrowborder" valign="top" width="16.88%" headers="mcps1.1.4.1.1 "><p id="p1343054115615"><a name="p1343054115615"></a><a name="p1343054115615"></a>showError</p>
</td>
<td class="cellrowborder" valign="top" width="29.12%" headers="mcps1.1.4.1.2 "><p id="p153431354175613"><a name="p153431354175613"></a><a name="p153431354175613"></a>{ error: string }</p>
</td>
<td class="cellrowborder" valign="top" width="54%" headers="mcps1.1.4.1.3 "><p id="p1034315465618"><a name="p1034315465618"></a><a name="p1034315465618"></a>展示输入错误提示，type为text|email|date|time|number|password时生效。</p>
</td>
</tr>
<tr id="row4919162415418"><td class="cellrowborder" valign="top" width="16.88%" headers="mcps1.1.4.1.1 "><p id="p191914240419"><a name="p191914240419"></a><a name="p191914240419"></a>delete<sup id="sup1636182514275"><a name="sup1636182514275"></a><a name="sup1636182514275"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="29.12%" headers="mcps1.1.4.1.2 "><p id="p209201424104119"><a name="p209201424104119"></a><a name="p209201424104119"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="54%" headers="mcps1.1.4.1.3 "><p id="p2920424124118"><a name="p2920424124118"></a><a name="p2920424124118"></a>type为text|email|date|time|number|password时，根据当前光标位置删除文本内容，如果当前输入组件没有光标，默认删除最后一个字符并展示光标。</p>
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

    ![](figures/zh-cn_image_0000001173324749.png)

4.  type为radio

    ```
    <!-- xxx.hml -->
    <div class="content">
      <input type="radio" checked='true' name="radioSample" value="radio1" onchange="onRadioChange('radio1')"></input>
      <input type="radio" checked='false' name="radioSample" value="radio2" onchange="onRadioChange('radio2')"></input>
      <input type="radio" checked='false' name="radioSample" value="radio3" onchange="onRadioChange('radio3')"></input>
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


