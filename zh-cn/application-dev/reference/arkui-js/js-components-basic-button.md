# button<a name="ZH-CN_TOPIC_0000001173324623"></a>

提供按钮组件，包括胶囊按钮、圆形按钮、文本按钮、弧形按钮、下载按钮。

## 子组件<a name="section9288143101012"></a>

不支持。

## 属性<a name="section2907183951110"></a>

除支持[通用属性](js-components-common-attributes.md)外，还支持如下属性：

<a name="table20633101642315"></a>
<table><thead align="left"><tr id="row663331618238"><th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.1"><p id="aa872998ac2d84843a3c5161889afffef"><a name="aa872998ac2d84843a3c5161889afffef"></a><a name="aa872998ac2d84843a3c5161889afffef"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.2"><p id="ab2111648ee0e4f6d881be8954e7acaab"><a name="ab2111648ee0e4f6d881be8954e7acaab"></a><a name="ab2111648ee0e4f6d881be8954e7acaab"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.48%" id="mcps1.1.6.1.3"><p id="ab377d1c90900478ea4ecab51e9a058af"><a name="ab377d1c90900478ea4ecab51e9a058af"></a><a name="ab377d1c90900478ea4ecab51e9a058af"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.6.1.4"><p id="p824610360217"><a name="p824610360217"></a><a name="p824610360217"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="35.76%" id="mcps1.1.6.1.5"><p id="a1d574a0044ed42ec8a2603bc82734232"><a name="a1d574a0044ed42ec8a2603bc82734232"></a><a name="a1d574a0044ed42ec8a2603bc82734232"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1515165893313"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p569785910333"><a name="p569785910333"></a><a name="p569785910333"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p26971659203314"><a name="p26971659203314"></a><a name="p26971659203314"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p869775913314"><a name="p869775913314"></a><a name="p869775913314"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p969714591338"><a name="p969714591338"></a><a name="p969714591338"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p196974598338"><a name="p196974598338"></a><a name="p196974598338"></a>不支持动态修改。如果该属性缺省，展示类胶囊型按钮，不同于胶囊类型，四边圆角可以通过border-radius分别指定，如果需要设置该属性，则可选值包括如下：</p>
<a name="ul16971659103317"></a><a name="ul16971659103317"></a><ul id="ul16971659103317"><li>capsule：胶囊型按钮，带圆角按钮，有背景色和文本；</li><li>circle：圆形按钮，支持放置图标；</li><li>text：文本按钮，仅包含文本显示；</li><li>arc：弧形按钮，仅支持智能穿戴；</li><li>download：下载按钮，额外增加下载进度条功能，仅支持手机和智慧屏。</li></ul>
</td>
</tr>
<tr id="row6883454133320"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p6698195910338"><a name="p6698195910338"></a><a name="p6698195910338"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p369814598336"><a name="p369814598336"></a><a name="p369814598336"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p269895912338"><a name="p269895912338"></a><a name="p269895912338"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p76981259193312"><a name="p76981259193312"></a><a name="p76981259193312"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p369810591333"><a name="p369810591333"></a><a name="p369810591333"></a>button的文本值。</p>
</td>
</tr>
<tr id="row8476152143316"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p16698259173318"><a name="p16698259173318"></a><a name="p16698259173318"></a>icon</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p1169818599332"><a name="p1169818599332"></a><a name="p1169818599332"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p1169855943315"><a name="p1169855943315"></a><a name="p1169855943315"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p1669865919337"><a name="p1669865919337"></a><a name="p1669865919337"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p8698135914336"><a name="p8698135914336"></a><a name="p8698135914336"></a>button的图标路径，图标格式为jpg，png和svg。</p>
</td>
</tr>
<tr id="row19478449411"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p11904175316315"><a name="p11904175316315"></a><a name="p11904175316315"></a>placement<sup id="sup220512551047"><a name="sup220512551047"></a><a name="sup220512551047"></a><span>5+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p1390413531314"><a name="p1390413531314"></a><a name="p1390413531314"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p390465317319"><a name="p390465317319"></a><a name="p390465317319"></a>end</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p1990415317319"><a name="p1990415317319"></a><a name="p1990415317319"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p1990410531316"><a name="p1990410531316"></a><a name="p1990410531316"></a>仅在type属性为缺省时生效，设置图标位于文本的位置，可选值为：</p>
<a name="ul1190565393119"></a><a name="ul1190565393119"></a><ul id="ul1190565393119"><li>start：图标位于文本起始处；</li><li>end：图标位于文本结束处；</li><li>top：图标位于文本上方；</li><li>bottom：图标位于文本下方。</li></ul>
</td>
</tr>
<tr id="row79691049103313"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p1569817594334"><a name="p1569817594334"></a><a name="p1569817594334"></a>waiting</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p369818591338"><a name="p369818591338"></a><a name="p369818591338"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p16981599336"><a name="p16981599336"></a><a name="p16981599336"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p1869875913332"><a name="p1869875913332"></a><a name="p1869875913332"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p1069813596335"><a name="p1069813596335"></a><a name="p1069813596335"></a>waiting状态，waiting为true时展现等待中转圈效果，位于文本左侧。类型为download时不生效，不支持智能穿戴。</p>
</td>
</tr>
</tbody>
</table>

## 样式<a name="section5775351116"></a>

**type设置为非arc时：**

除支持[通用样式](js-components-common-styles.md)外，还支持如下样式：

<a name="table10836163016447"></a>
<table><thead align="left"><tr id="row3836113016445"><th class="cellrowborder" valign="top" width="17.458254174582542%" id="mcps1.1.6.1.1"><p id="p1383783015444"><a name="p1383783015444"></a><a name="p1383783015444"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="11.40885911408859%" id="mcps1.1.6.1.2"><p id="p9837193015448"><a name="p9837193015448"></a><a name="p9837193015448"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="19.208079192080792%" id="mcps1.1.6.1.3"><p id="p483723014446"><a name="p483723014446"></a><a name="p483723014446"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="6.639336066393361%" id="mcps1.1.6.1.4"><p id="p18371430174413"><a name="p18371430174413"></a><a name="p18371430174413"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="45.28547145285472%" id="mcps1.1.6.1.5"><p id="p1837133018449"><a name="p1837133018449"></a><a name="p1837133018449"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row683733011442"><td class="cellrowborder" valign="top" width="17.458254174582542%" headers="mcps1.1.6.1.1 "><p id="p583715302445"><a name="p583715302445"></a><a name="p583715302445"></a>text-color</p>
</td>
<td class="cellrowborder" valign="top" width="11.40885911408859%" headers="mcps1.1.6.1.2 "><p id="p3837113014448"><a name="p3837113014448"></a><a name="p3837113014448"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="19.208079192080792%" headers="mcps1.1.6.1.3 "><p id="p13837123084418"><a name="p13837123084418"></a><a name="p13837123084418"></a>#ff007dff</p>
</td>
<td class="cellrowborder" valign="top" width="6.639336066393361%" headers="mcps1.1.6.1.4 "><p id="p1883753064418"><a name="p1883753064418"></a><a name="p1883753064418"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="45.28547145285472%" headers="mcps1.1.6.1.5 "><p id="p1683719306444"><a name="p1683719306444"></a><a name="p1683719306444"></a>按钮的文本颜色。</p>
</td>
</tr>
<tr id="row198373300448"><td class="cellrowborder" valign="top" width="17.458254174582542%" headers="mcps1.1.6.1.1 "><p id="p18837130124418"><a name="p18837130124418"></a><a name="p18837130124418"></a>font-size</p>
</td>
<td class="cellrowborder" valign="top" width="11.40885911408859%" headers="mcps1.1.6.1.2 "><p id="p1283783094414"><a name="p1283783094414"></a><a name="p1283783094414"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="19.208079192080792%" headers="mcps1.1.6.1.3 "><p id="p1583717304445"><a name="p1583717304445"></a><a name="p1583717304445"></a>16px</p>
</td>
<td class="cellrowborder" valign="top" width="6.639336066393361%" headers="mcps1.1.6.1.4 "><p id="p6837133064415"><a name="p6837133064415"></a><a name="p6837133064415"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="45.28547145285472%" headers="mcps1.1.6.1.5 "><p id="p1283823019443"><a name="p1283823019443"></a><a name="p1283823019443"></a>按钮的文本尺寸。</p>
</td>
</tr>
<tr id="row1883814304447"><td class="cellrowborder" valign="top" width="17.458254174582542%" headers="mcps1.1.6.1.1 "><p id="p1883810309447"><a name="p1883810309447"></a><a name="p1883810309447"></a>allow-scale</p>
</td>
<td class="cellrowborder" valign="top" width="11.40885911408859%" headers="mcps1.1.6.1.2 "><p id="p17838130144418"><a name="p17838130144418"></a><a name="p17838130144418"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="19.208079192080792%" headers="mcps1.1.6.1.3 "><p id="p2838830124416"><a name="p2838830124416"></a><a name="p2838830124416"></a>true</p>
</td>
<td class="cellrowborder" valign="top" width="6.639336066393361%" headers="mcps1.1.6.1.4 "><p id="p88386303449"><a name="p88386303449"></a><a name="p88386303449"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="45.28547145285472%" headers="mcps1.1.6.1.5 "><p id="p7838330184418"><a name="p7838330184418"></a><a name="p7838330184418"></a>按钮的文本尺寸是否跟随系统设置字体缩放尺寸进行放大缩小。</p>
<div class="note" id="note583873013443"><a name="note583873013443"></a><a name="note583873013443"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="p1483818307443"><a name="p1483818307443"></a><a name="p1483818307443"></a>如果在config描述文件中针对ability配置了fontSize的config-changes标签，则应用不会重启而直接生效。</p>
</div></div>
</td>
</tr>
<tr id="row4838173004420"><td class="cellrowborder" valign="top" width="17.458254174582542%" headers="mcps1.1.6.1.1 "><p id="p1783843094414"><a name="p1783843094414"></a><a name="p1783843094414"></a>font-style</p>
</td>
<td class="cellrowborder" valign="top" width="11.40885911408859%" headers="mcps1.1.6.1.2 "><p id="p4838153011441"><a name="p4838153011441"></a><a name="p4838153011441"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="19.208079192080792%" headers="mcps1.1.6.1.3 "><p id="p178388308446"><a name="p178388308446"></a><a name="p178388308446"></a>normal</p>
</td>
<td class="cellrowborder" valign="top" width="6.639336066393361%" headers="mcps1.1.6.1.4 "><p id="p283853044418"><a name="p283853044418"></a><a name="p283853044418"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="45.28547145285472%" headers="mcps1.1.6.1.5 "><p id="p16838123015449"><a name="p16838123015449"></a><a name="p16838123015449"></a>按钮的字体样式。</p>
</td>
</tr>
<tr id="row1183823015441"><td class="cellrowborder" valign="top" width="17.458254174582542%" headers="mcps1.1.6.1.1 "><p id="p3838143016449"><a name="p3838143016449"></a><a name="p3838143016449"></a>font-weight</p>
</td>
<td class="cellrowborder" valign="top" width="11.40885911408859%" headers="mcps1.1.6.1.2 "><p id="p3838133004413"><a name="p3838133004413"></a><a name="p3838133004413"></a>number | string</p>
</td>
<td class="cellrowborder" valign="top" width="19.208079192080792%" headers="mcps1.1.6.1.3 "><p id="p118381430204412"><a name="p118381430204412"></a><a name="p118381430204412"></a>normal</p>
</td>
<td class="cellrowborder" valign="top" width="6.639336066393361%" headers="mcps1.1.6.1.4 "><p id="p48381730174414"><a name="p48381730174414"></a><a name="p48381730174414"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="45.28547145285472%" headers="mcps1.1.6.1.5 "><p id="p183810309449"><a name="p183810309449"></a><a name="p183810309449"></a>按钮的字体粗细。见<a href="js-components-basic-text.md#section5775351116">text组件font-weight的样式属性</a>。</p>
</td>
</tr>
<tr id="row683893044416"><td class="cellrowborder" valign="top" width="17.458254174582542%" headers="mcps1.1.6.1.1 "><p id="p1683810307443"><a name="p1683810307443"></a><a name="p1683810307443"></a>font-family</p>
</td>
<td class="cellrowborder" valign="top" width="11.40885911408859%" headers="mcps1.1.6.1.2 "><p id="p138391730124417"><a name="p138391730124417"></a><a name="p138391730124417"></a>&lt;string&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="19.208079192080792%" headers="mcps1.1.6.1.3 "><p id="p68391530154419"><a name="p68391530154419"></a><a name="p68391530154419"></a>sans-serif</p>
</td>
<td class="cellrowborder" valign="top" width="6.639336066393361%" headers="mcps1.1.6.1.4 "><p id="p38391030164415"><a name="p38391030164415"></a><a name="p38391030164415"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="45.28547145285472%" headers="mcps1.1.6.1.5 "><p id="p38395308443"><a name="p38395308443"></a><a name="p38395308443"></a>按钮的字体列表，用逗号分隔，每个字体用字体名或者字体族名设置。列表中第一个系统中存在的或者通过<a href="js-components-common-customizing-font.md">自定义字体</a>指定的字体，会被选中作为文本的字体。</p>
</td>
</tr>
<tr id="row783993094418"><td class="cellrowborder" valign="top" width="17.458254174582542%" headers="mcps1.1.6.1.1 "><p id="p78391530174414"><a name="p78391530174414"></a><a name="p78391530174414"></a>icon-width</p>
</td>
<td class="cellrowborder" valign="top" width="11.40885911408859%" headers="mcps1.1.6.1.2 "><p id="p68396304443"><a name="p68396304443"></a><a name="p68396304443"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="19.208079192080792%" headers="mcps1.1.6.1.3 "><p id="p168391130204415"><a name="p168391130204415"></a><a name="p168391130204415"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="6.639336066393361%" headers="mcps1.1.6.1.4 "><p id="p983933010448"><a name="p983933010448"></a><a name="p983933010448"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="45.28547145285472%" headers="mcps1.1.6.1.5 "><p id="p148391030114411"><a name="p148391030114411"></a><a name="p148391030114411"></a>设置圆形按钮内部图标的宽，默认填满整个圆形按钮。</p>
<div class="note" id="note1983911301443"><a name="note1983911301443"></a><a name="note1983911301443"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="p183993054416"><a name="p183993054416"></a><a name="p183993054416"></a>icon使用svg图源时必须设置该样式。</p>
</div></div>
</td>
</tr>
<tr id="row158391630184416"><td class="cellrowborder" valign="top" width="17.458254174582542%" headers="mcps1.1.6.1.1 "><p id="p6840133016442"><a name="p6840133016442"></a><a name="p6840133016442"></a>icon-height</p>
</td>
<td class="cellrowborder" valign="top" width="11.40885911408859%" headers="mcps1.1.6.1.2 "><p id="p168401830194410"><a name="p168401830194410"></a><a name="p168401830194410"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="19.208079192080792%" headers="mcps1.1.6.1.3 "><p id="p2840830164417"><a name="p2840830164417"></a><a name="p2840830164417"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="6.639336066393361%" headers="mcps1.1.6.1.4 "><p id="p4840930204420"><a name="p4840930204420"></a><a name="p4840930204420"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="45.28547145285472%" headers="mcps1.1.6.1.5 "><p id="p1084018307444"><a name="p1084018307444"></a><a name="p1084018307444"></a>设置圆形按钮内部图标的高，默认填满整个圆形按钮。</p>
<div class="note" id="note18840133012443"><a name="note18840133012443"></a><a name="note18840133012443"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="p178401630194412"><a name="p178401630194412"></a><a name="p178401630194412"></a>icon使用svg图源时必须设置该样式。</p>
</div></div>
</td>
</tr>
<tr id="row1284083054413"><td class="cellrowborder" valign="top" width="17.458254174582542%" headers="mcps1.1.6.1.1 "><p id="p4840173044413"><a name="p4840173044413"></a><a name="p4840173044413"></a>radius</p>
</td>
<td class="cellrowborder" valign="top" width="11.40885911408859%" headers="mcps1.1.6.1.2 "><p id="p18840143084414"><a name="p18840143084414"></a><a name="p18840143084414"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="19.208079192080792%" headers="mcps1.1.6.1.3 "><p id="p1584018301446"><a name="p1584018301446"></a><a name="p1584018301446"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="6.639336066393361%" headers="mcps1.1.6.1.4 "><p id="p168401030114412"><a name="p168401030114412"></a><a name="p168401030114412"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="45.28547145285472%" headers="mcps1.1.6.1.5 "><p id="p11841183004414"><a name="p11841183004414"></a><a name="p11841183004414"></a>圆形按钮半径或者胶囊按钮圆角半径。在圆形按钮类型下该样式优先于通用样式的width和height样式。</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>-   胶囊按钮（type=capsule）时，不支持border相关样式；
>-   圆形按钮（type=circle）时，不支持文本相关样式；
>-   文本按钮（type=text）时，自适应文本大小，不支持尺寸设置（radius，width，height），背景透明不支持background-color样式。

**type设置为arc时：**

除支持[通用样式](js-components-common-styles.md)中background-color、opacity、display、visibility、position、\[left|top|right|bottom外，还支持如下样式：

<a name="table3882649131618"></a>
<table><thead align="left"><tr id="row6883249141619"><th class="cellrowborder" valign="top" width="23.11768823117688%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001059340528_a14a0c012a26248cfbec6b13dcc4f2cbe"><a name="zh-cn_topic_0000001059340528_a14a0c012a26248cfbec6b13dcc4f2cbe"></a><a name="zh-cn_topic_0000001059340528_a14a0c012a26248cfbec6b13dcc4f2cbe"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="20.477952204779523%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001059340528_a8dc328a555a74157a00de86181fc3a7b"><a name="zh-cn_topic_0000001059340528_a8dc328a555a74157a00de86181fc3a7b"></a><a name="zh-cn_topic_0000001059340528_a8dc328a555a74157a00de86181fc3a7b"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.869113088691131%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001059340528_a41a31e48d0c74ad4982add2655515c82"><a name="zh-cn_topic_0000001059340528_a41a31e48d0c74ad4982add2655515c82"></a><a name="zh-cn_topic_0000001059340528_a41a31e48d0c74ad4982add2655515c82"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.519248075192481%" id="mcps1.1.6.1.4"><p id="p988314919169"><a name="p988314919169"></a><a name="p988314919169"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="40.01599840015999%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001059340528_af7a726e456f7485c87bd4e0527bc6584"><a name="zh-cn_topic_0000001059340528_af7a726e456f7485c87bd4e0527bc6584"></a><a name="zh-cn_topic_0000001059340528_af7a726e456f7485c87bd4e0527bc6584"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row8424144919409"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p165029502409"><a name="p165029502409"></a><a name="p165029502409"></a>text-color</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p1450225084018"><a name="p1450225084018"></a><a name="p1450225084018"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p0502175044017"><a name="p0502175044017"></a><a name="p0502175044017"></a>#de0000</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p35021750134015"><a name="p35021750134015"></a><a name="p35021750134015"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p4502145044012"><a name="p4502145044012"></a><a name="p4502145044012"></a>弧形按钮的文本颜色。</p>
</td>
</tr>
<tr id="row10425349104012"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p950385020402"><a name="p950385020402"></a><a name="p950385020402"></a>font-size</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p15032505401"><a name="p15032505401"></a><a name="p15032505401"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p75037503405"><a name="p75037503405"></a><a name="p75037503405"></a>37.5px</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p10503850144017"><a name="p10503850144017"></a><a name="p10503850144017"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p8503150114014"><a name="p8503150114014"></a><a name="p8503150114014"></a>弧形按钮的文本尺寸。</p>
</td>
</tr>
<tr id="row542518490406"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p18503250164012"><a name="p18503250164012"></a><a name="p18503250164012"></a>allow-scale</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p1650315010404"><a name="p1650315010404"></a><a name="p1650315010404"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p1250419505407"><a name="p1250419505407"></a><a name="p1250419505407"></a>true</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p2504125017408"><a name="p2504125017408"></a><a name="p2504125017408"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p75041650194011"><a name="p75041650194011"></a><a name="p75041650194011"></a>弧形按钮的文本尺寸是否跟随系统设置字体缩放尺寸进行放大缩小。</p>
</td>
</tr>
<tr id="row1642514912402"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p050445014400"><a name="p050445014400"></a><a name="p050445014400"></a>font-style</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p250418501403"><a name="p250418501403"></a><a name="p250418501403"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p18504155015409"><a name="p18504155015409"></a><a name="p18504155015409"></a>normal</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p175041150194017"><a name="p175041150194017"></a><a name="p175041150194017"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p1850485012408"><a name="p1850485012408"></a><a name="p1850485012408"></a>弧形按钮的字体样式。</p>
</td>
</tr>
<tr id="row187569336406"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p2504550124019"><a name="p2504550124019"></a><a name="p2504550124019"></a>font-weight</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p950411503408"><a name="p950411503408"></a><a name="p950411503408"></a>number | string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p155041050164019"><a name="p155041050164019"></a><a name="p155041050164019"></a>normal</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p2505185020407"><a name="p2505185020407"></a><a name="p2505185020407"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p1750515044020"><a name="p1750515044020"></a><a name="p1750515044020"></a>弧形按钮的字体粗细。见<a href="js-components-basic-text.md#section5775351116">text组件font-weight的样式属性</a>。</p>
</td>
</tr>
<tr id="row8251631144012"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p750565004010"><a name="p750565004010"></a><a name="p750565004010"></a>font-family</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p125059504401"><a name="p125059504401"></a><a name="p125059504401"></a>&lt;string&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p115051650154015"><a name="p115051650154015"></a><a name="p115051650154015"></a>sans-serif</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p45051350164012"><a name="p45051350164012"></a><a name="p45051350164012"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p9505195015402"><a name="p9505195015402"></a><a name="p9505195015402"></a>按钮的字体列表，用逗号分隔，每个字体用字体名或者字体族名设置。列表中第一个系统中存在的或者通过<a href="js-components-common-customizing-font.md">自定义字体</a>指定的字体，会被选中作为文本的字体。</p>
</td>
</tr>
</tbody>
</table>

## 事件<a name="section71081937192815"></a>

支持[通用事件](js-components-common-events.md)。

## 方法<a name="section47669296127"></a>

支持[通用方法](js-components-common-methods.md)。

类型为download时，支持如下方法：

<a name="t75606345ece64f818511af2963b4522d"></a>
<table><thead align="left"><tr id="rf7e96304e96b4abcada899f917623b50"><th class="cellrowborder" valign="top" width="17.18%" id="mcps1.1.4.1.1"><p id="abdd98ec01df046a7ac2f66a3fa4eda04"><a name="abdd98ec01df046a7ac2f66a3fa4eda04"></a><a name="abdd98ec01df046a7ac2f66a3fa4eda04"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="28.82%" id="mcps1.1.4.1.2"><p id="afa86bf0c638b4860a91ea0e6255b7744"><a name="afa86bf0c638b4860a91ea0e6255b7744"></a><a name="afa86bf0c638b4860a91ea0e6255b7744"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="54%" id="mcps1.1.4.1.3"><p id="aa7783f4706e8434493b6e941e0100652"><a name="aa7783f4706e8434493b6e941e0100652"></a><a name="aa7783f4706e8434493b6e941e0100652"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="r51da7a66ad844356a54fc7d198bbc496"><td class="cellrowborder" valign="top" width="17.18%" headers="mcps1.1.4.1.1 "><p id="a37c62c3017bc4b85813051fedae5523a"><a name="a37c62c3017bc4b85813051fedae5523a"></a><a name="a37c62c3017bc4b85813051fedae5523a"></a>setProgress</p>
</td>
<td class="cellrowborder" valign="top" width="28.82%" headers="mcps1.1.4.1.2 "><p id="a0fa3cdedaab94e11b1c1df493e671084"><a name="a0fa3cdedaab94e11b1c1df493e671084"></a><a name="a0fa3cdedaab94e11b1c1df493e671084"></a>{ progress:percent }</p>
</td>
<td class="cellrowborder" valign="top" width="54%" headers="mcps1.1.4.1.3 "><p id="p157114142914"><a name="p157114142914"></a><a name="p157114142914"></a>设定下载按钮进度条进度，取值位于0-100区间内，当设置的值大于0时，下载按钮展现进度条。当设置的值大于等于100时，取消进度条显示。</p>
<div class="note" id="note11137355291"><a name="note11137355291"></a><a name="note11137355291"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="p19137355592"><a name="p19137355592"></a><a name="p19137355592"></a>浮在进度条上的文字通过value值进行变更。</p>
</div></div>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section16867208402"></a>

```
<!-- xxx.hml -->
<div class="div-button">
  <button class="first" type="capsule" value="Capsule button"></button>
  <button class="button circle" type="circle" icon="common/ic_add_default.png"></button>
  <button class="button text" type="text">Text button</button>
  <button class="button download" type="download" id="download-btn"
    onclick="progress">{{downloadText}}</button>
  <button class="last" type="capsule" waiting="true">Loading</button>
</div>
```

```
/* xxx.css */ 
.div-button {
  flex-direction: column;
  align-items: center;
}
.first{
  background-color: #F2F2F2;
  text-color: #0D81F2;
}
.button {
  margin-top: 15px;
}
.last{
  background-color: #F2F2F2;
  text-color: #969696;
  margin-top: 15px;
  width: 280px;
  height:72px;
}
.button:waiting {
  width: 280px;
}
.circle {
  background-color: #007dff;
  radius: 72px;
  icon-width: 72px;
  icon-height: 72px;
}
.text {
  text-color: red;
  font-size: 40px;
  font-weight: 900;
  font-family: sans-serif;
  font-style: normal;
}
.download {
  width: 280px;
  text-color: white;
  background-color: #007dff;
}
```

```
// xxx.js 
export default {
  data: {
    count: 5,
    downloadText: "Download"
  },
  progress(e) {
    this.count+= 10;
    this.downloadText = this.count+ "%";
    this.$element('download-btn').setProgress({ progress: this.count});
    if (this.count>= 100) {
      this.downloadText = "Done";
    }
  }
}
```

![](figures/zh-cn_image_0000001127125132.png)

