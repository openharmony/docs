# button<a name="ZH-CN_TOPIC_0000001209570697"></a>

-   [子组件](#zh-cn_topic_0000001173324623_section9288143101012)
-   [属性](#zh-cn_topic_0000001173324623_section2907183951110)
-   [样式](#zh-cn_topic_0000001173324623_section5775351116)
-   [事件](#zh-cn_topic_0000001173324623_section71081937192815)
-   [方法](#zh-cn_topic_0000001173324623_section47669296127)
-   [示例](#zh-cn_topic_0000001173324623_section16867208402)

提供按钮组件，包括胶囊按钮、圆形按钮、文本按钮、弧形按钮、下载按钮。

## 子组件<a name="zh-cn_topic_0000001173324623_section9288143101012"></a>

不支持。

## 属性<a name="zh-cn_topic_0000001173324623_section2907183951110"></a>

除支持[通用属性](js-components-common-attributes.md#ZH-CN_TOPIC_0000001163812208)外，还支持如下属性：

<a name="zh-cn_topic_0000001173324623_table20633101642315"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173324623_row663331618238"><th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001173324623_aa872998ac2d84843a3c5161889afffef"><a name="zh-cn_topic_0000001173324623_aa872998ac2d84843a3c5161889afffef"></a><a name="zh-cn_topic_0000001173324623_aa872998ac2d84843a3c5161889afffef"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001173324623_ab2111648ee0e4f6d881be8954e7acaab"><a name="zh-cn_topic_0000001173324623_ab2111648ee0e4f6d881be8954e7acaab"></a><a name="zh-cn_topic_0000001173324623_ab2111648ee0e4f6d881be8954e7acaab"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.48%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001173324623_ab377d1c90900478ea4ecab51e9a058af"><a name="zh-cn_topic_0000001173324623_ab377d1c90900478ea4ecab51e9a058af"></a><a name="zh-cn_topic_0000001173324623_ab377d1c90900478ea4ecab51e9a058af"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001173324623_p824610360217"><a name="zh-cn_topic_0000001173324623_p824610360217"></a><a name="zh-cn_topic_0000001173324623_p824610360217"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="35.76%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001173324623_a1d574a0044ed42ec8a2603bc82734232"><a name="zh-cn_topic_0000001173324623_a1d574a0044ed42ec8a2603bc82734232"></a><a name="zh-cn_topic_0000001173324623_a1d574a0044ed42ec8a2603bc82734232"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173324623_row1515165893313"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324623_p569785910333"><a name="zh-cn_topic_0000001173324623_p569785910333"></a><a name="zh-cn_topic_0000001173324623_p569785910333"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324623_p26971659203314"><a name="zh-cn_topic_0000001173324623_p26971659203314"></a><a name="zh-cn_topic_0000001173324623_p26971659203314"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324623_p869775913314"><a name="zh-cn_topic_0000001173324623_p869775913314"></a><a name="zh-cn_topic_0000001173324623_p869775913314"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324623_p969714591338"><a name="zh-cn_topic_0000001173324623_p969714591338"></a><a name="zh-cn_topic_0000001173324623_p969714591338"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324623_p196974598338"><a name="zh-cn_topic_0000001173324623_p196974598338"></a><a name="zh-cn_topic_0000001173324623_p196974598338"></a>不支持动态修改。如果该属性缺省，展示类胶囊型按钮，不同于胶囊类型，四边圆角可以通过border-radius分别指定，如果需要设置该属性，则可选值包括如下：</p>
<a name="zh-cn_topic_0000001173324623_ul16971659103317"></a><a name="zh-cn_topic_0000001173324623_ul16971659103317"></a><ul id="zh-cn_topic_0000001173324623_ul16971659103317"><li>capsule：胶囊型按钮，带圆角按钮，有背景色和文本；</li><li>circle：圆形按钮，支持放置图标；</li><li>text：文本按钮，仅包含文本显示；</li><li>arc：弧形按钮，仅支持智能穿戴；</li><li>download：下载按钮，额外增加下载进度条功能，仅支持手机和智慧屏。</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324623_row6883454133320"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324623_p6698195910338"><a name="zh-cn_topic_0000001173324623_p6698195910338"></a><a name="zh-cn_topic_0000001173324623_p6698195910338"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324623_p369814598336"><a name="zh-cn_topic_0000001173324623_p369814598336"></a><a name="zh-cn_topic_0000001173324623_p369814598336"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324623_p269895912338"><a name="zh-cn_topic_0000001173324623_p269895912338"></a><a name="zh-cn_topic_0000001173324623_p269895912338"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324623_p76981259193312"><a name="zh-cn_topic_0000001173324623_p76981259193312"></a><a name="zh-cn_topic_0000001173324623_p76981259193312"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324623_p369810591333"><a name="zh-cn_topic_0000001173324623_p369810591333"></a><a name="zh-cn_topic_0000001173324623_p369810591333"></a>button的文本值，circle类型不生效。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324623_row8476152143316"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324623_p16698259173318"><a name="zh-cn_topic_0000001173324623_p16698259173318"></a><a name="zh-cn_topic_0000001173324623_p16698259173318"></a>icon</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324623_p1169818599332"><a name="zh-cn_topic_0000001173324623_p1169818599332"></a><a name="zh-cn_topic_0000001173324623_p1169818599332"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324623_p1169855943315"><a name="zh-cn_topic_0000001173324623_p1169855943315"></a><a name="zh-cn_topic_0000001173324623_p1169855943315"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324623_p1669865919337"><a name="zh-cn_topic_0000001173324623_p1669865919337"></a><a name="zh-cn_topic_0000001173324623_p1669865919337"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324623_p8698135914336"><a name="zh-cn_topic_0000001173324623_p8698135914336"></a><a name="zh-cn_topic_0000001173324623_p8698135914336"></a>button的图标路径，图标格式为jpg，png和svg。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324623_row19478449411"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324623_p11904175316315"><a name="zh-cn_topic_0000001173324623_p11904175316315"></a><a name="zh-cn_topic_0000001173324623_p11904175316315"></a>placement<sup id="zh-cn_topic_0000001173324623_sup220512551047"><a name="zh-cn_topic_0000001173324623_sup220512551047"></a><a name="zh-cn_topic_0000001173324623_sup220512551047"></a><span>5+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324623_p1390413531314"><a name="zh-cn_topic_0000001173324623_p1390413531314"></a><a name="zh-cn_topic_0000001173324623_p1390413531314"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324623_p390465317319"><a name="zh-cn_topic_0000001173324623_p390465317319"></a><a name="zh-cn_topic_0000001173324623_p390465317319"></a>end</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324623_p1990415317319"><a name="zh-cn_topic_0000001173324623_p1990415317319"></a><a name="zh-cn_topic_0000001173324623_p1990415317319"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324623_p1990410531316"><a name="zh-cn_topic_0000001173324623_p1990410531316"></a><a name="zh-cn_topic_0000001173324623_p1990410531316"></a>仅在type属性为缺省时生效，设置图标位于文本的位置，可选值为：</p>
<a name="zh-cn_topic_0000001173324623_ul1190565393119"></a><a name="zh-cn_topic_0000001173324623_ul1190565393119"></a><ul id="zh-cn_topic_0000001173324623_ul1190565393119"><li>start：图标位于文本起始处；</li><li>end：图标位于文本结束处；</li><li>top：图标位于文本上方；</li><li>bottom：图标位于文本下方。</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324623_row79691049103313"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324623_p1569817594334"><a name="zh-cn_topic_0000001173324623_p1569817594334"></a><a name="zh-cn_topic_0000001173324623_p1569817594334"></a>waiting</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324623_p369818591338"><a name="zh-cn_topic_0000001173324623_p369818591338"></a><a name="zh-cn_topic_0000001173324623_p369818591338"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324623_p16981599336"><a name="zh-cn_topic_0000001173324623_p16981599336"></a><a name="zh-cn_topic_0000001173324623_p16981599336"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324623_p1869875913332"><a name="zh-cn_topic_0000001173324623_p1869875913332"></a><a name="zh-cn_topic_0000001173324623_p1869875913332"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324623_p1069813596335"><a name="zh-cn_topic_0000001173324623_p1069813596335"></a><a name="zh-cn_topic_0000001173324623_p1069813596335"></a>waiting状态，waiting为true时展现等待中转圈效果，位于文本左侧。类型为download时不生效，不支持智能穿戴。</p>
</td>
</tr>
</tbody>
</table>

## 样式<a name="zh-cn_topic_0000001173324623_section5775351116"></a>

**type设置为非arc时：**

除支持[通用样式](js-components-common-styles.md#ZH-CN_TOPIC_0000001163932190)外，还支持如下样式：

<a name="zh-cn_topic_0000001173324623_table10836163016447"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173324623_row3836113016445"><th class="cellrowborder" valign="top" width="17.458254174582542%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001173324623_p1383783015444"><a name="zh-cn_topic_0000001173324623_p1383783015444"></a><a name="zh-cn_topic_0000001173324623_p1383783015444"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="11.40885911408859%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001173324623_p9837193015448"><a name="zh-cn_topic_0000001173324623_p9837193015448"></a><a name="zh-cn_topic_0000001173324623_p9837193015448"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="19.208079192080792%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001173324623_p483723014446"><a name="zh-cn_topic_0000001173324623_p483723014446"></a><a name="zh-cn_topic_0000001173324623_p483723014446"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="6.639336066393361%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001173324623_p18371430174413"><a name="zh-cn_topic_0000001173324623_p18371430174413"></a><a name="zh-cn_topic_0000001173324623_p18371430174413"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="45.28547145285472%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001173324623_p1837133018449"><a name="zh-cn_topic_0000001173324623_p1837133018449"></a><a name="zh-cn_topic_0000001173324623_p1837133018449"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173324623_row683733011442"><td class="cellrowborder" valign="top" width="17.458254174582542%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324623_p583715302445"><a name="zh-cn_topic_0000001173324623_p583715302445"></a><a name="zh-cn_topic_0000001173324623_p583715302445"></a>text-color</p>
</td>
<td class="cellrowborder" valign="top" width="11.40885911408859%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324623_p3837113014448"><a name="zh-cn_topic_0000001173324623_p3837113014448"></a><a name="zh-cn_topic_0000001173324623_p3837113014448"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="19.208079192080792%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324623_p13837123084418"><a name="zh-cn_topic_0000001173324623_p13837123084418"></a><a name="zh-cn_topic_0000001173324623_p13837123084418"></a>#ff007dff</p>
</td>
<td class="cellrowborder" valign="top" width="6.639336066393361%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324623_p1883753064418"><a name="zh-cn_topic_0000001173324623_p1883753064418"></a><a name="zh-cn_topic_0000001173324623_p1883753064418"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="45.28547145285472%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324623_p1683719306444"><a name="zh-cn_topic_0000001173324623_p1683719306444"></a><a name="zh-cn_topic_0000001173324623_p1683719306444"></a>按钮的文本颜色。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324623_row198373300448"><td class="cellrowborder" valign="top" width="17.458254174582542%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324623_p18837130124418"><a name="zh-cn_topic_0000001173324623_p18837130124418"></a><a name="zh-cn_topic_0000001173324623_p18837130124418"></a>font-size</p>
</td>
<td class="cellrowborder" valign="top" width="11.40885911408859%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324623_p1283783094414"><a name="zh-cn_topic_0000001173324623_p1283783094414"></a><a name="zh-cn_topic_0000001173324623_p1283783094414"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="19.208079192080792%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324623_p1583717304445"><a name="zh-cn_topic_0000001173324623_p1583717304445"></a><a name="zh-cn_topic_0000001173324623_p1583717304445"></a>16px</p>
</td>
<td class="cellrowborder" valign="top" width="6.639336066393361%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324623_p6837133064415"><a name="zh-cn_topic_0000001173324623_p6837133064415"></a><a name="zh-cn_topic_0000001173324623_p6837133064415"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="45.28547145285472%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324623_p1283823019443"><a name="zh-cn_topic_0000001173324623_p1283823019443"></a><a name="zh-cn_topic_0000001173324623_p1283823019443"></a>按钮的文本尺寸。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324623_row1883814304447"><td class="cellrowborder" valign="top" width="17.458254174582542%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324623_p1883810309447"><a name="zh-cn_topic_0000001173324623_p1883810309447"></a><a name="zh-cn_topic_0000001173324623_p1883810309447"></a>allow-scale</p>
</td>
<td class="cellrowborder" valign="top" width="11.40885911408859%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324623_p17838130144418"><a name="zh-cn_topic_0000001173324623_p17838130144418"></a><a name="zh-cn_topic_0000001173324623_p17838130144418"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="19.208079192080792%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324623_p2838830124416"><a name="zh-cn_topic_0000001173324623_p2838830124416"></a><a name="zh-cn_topic_0000001173324623_p2838830124416"></a>true</p>
</td>
<td class="cellrowborder" valign="top" width="6.639336066393361%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324623_p88386303449"><a name="zh-cn_topic_0000001173324623_p88386303449"></a><a name="zh-cn_topic_0000001173324623_p88386303449"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="45.28547145285472%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324623_p7838330184418"><a name="zh-cn_topic_0000001173324623_p7838330184418"></a><a name="zh-cn_topic_0000001173324623_p7838330184418"></a>按钮的文本尺寸是否跟随系统设置字体缩放尺寸进行放大缩小。</p>
<div class="note" id="zh-cn_topic_0000001173324623_note583873013443"><a name="zh-cn_topic_0000001173324623_note583873013443"></a><a name="zh-cn_topic_0000001173324623_note583873013443"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001173324623_p1483818307443"><a name="zh-cn_topic_0000001173324623_p1483818307443"></a><a name="zh-cn_topic_0000001173324623_p1483818307443"></a>如果在config描述文件中针对ability配置了fontSize的config-changes标签，则应用不会重启而直接生效。</p>
</div></div>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324623_row4838173004420"><td class="cellrowborder" valign="top" width="17.458254174582542%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324623_p1783843094414"><a name="zh-cn_topic_0000001173324623_p1783843094414"></a><a name="zh-cn_topic_0000001173324623_p1783843094414"></a>font-style</p>
</td>
<td class="cellrowborder" valign="top" width="11.40885911408859%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324623_p4838153011441"><a name="zh-cn_topic_0000001173324623_p4838153011441"></a><a name="zh-cn_topic_0000001173324623_p4838153011441"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="19.208079192080792%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324623_p178388308446"><a name="zh-cn_topic_0000001173324623_p178388308446"></a><a name="zh-cn_topic_0000001173324623_p178388308446"></a>normal</p>
</td>
<td class="cellrowborder" valign="top" width="6.639336066393361%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324623_p283853044418"><a name="zh-cn_topic_0000001173324623_p283853044418"></a><a name="zh-cn_topic_0000001173324623_p283853044418"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="45.28547145285472%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324623_p16838123015449"><a name="zh-cn_topic_0000001173324623_p16838123015449"></a><a name="zh-cn_topic_0000001173324623_p16838123015449"></a>按钮的字体样式。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324623_row1183823015441"><td class="cellrowborder" valign="top" width="17.458254174582542%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324623_p3838143016449"><a name="zh-cn_topic_0000001173324623_p3838143016449"></a><a name="zh-cn_topic_0000001173324623_p3838143016449"></a>font-weight</p>
</td>
<td class="cellrowborder" valign="top" width="11.40885911408859%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324623_p3838133004413"><a name="zh-cn_topic_0000001173324623_p3838133004413"></a><a name="zh-cn_topic_0000001173324623_p3838133004413"></a>number | string</p>
</td>
<td class="cellrowborder" valign="top" width="19.208079192080792%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324623_p118381430204412"><a name="zh-cn_topic_0000001173324623_p118381430204412"></a><a name="zh-cn_topic_0000001173324623_p118381430204412"></a>normal</p>
</td>
<td class="cellrowborder" valign="top" width="6.639336066393361%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324623_p48381730174414"><a name="zh-cn_topic_0000001173324623_p48381730174414"></a><a name="zh-cn_topic_0000001173324623_p48381730174414"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="45.28547145285472%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324623_p183810309449"><a name="zh-cn_topic_0000001173324623_p183810309449"></a><a name="zh-cn_topic_0000001173324623_p183810309449"></a>按钮的字体粗细。见<a href="js-components-basic-text.md#zh-cn_topic_0000001127125018_section5775351116">text组件font-weight的样式属性</a>。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324623_row683893044416"><td class="cellrowborder" valign="top" width="17.458254174582542%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324623_p1683810307443"><a name="zh-cn_topic_0000001173324623_p1683810307443"></a><a name="zh-cn_topic_0000001173324623_p1683810307443"></a>font-family</p>
</td>
<td class="cellrowborder" valign="top" width="11.40885911408859%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324623_p138391730124417"><a name="zh-cn_topic_0000001173324623_p138391730124417"></a><a name="zh-cn_topic_0000001173324623_p138391730124417"></a>&lt;string&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="19.208079192080792%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324623_p68391530154419"><a name="zh-cn_topic_0000001173324623_p68391530154419"></a><a name="zh-cn_topic_0000001173324623_p68391530154419"></a>sans-serif</p>
</td>
<td class="cellrowborder" valign="top" width="6.639336066393361%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324623_p38391030164415"><a name="zh-cn_topic_0000001173324623_p38391030164415"></a><a name="zh-cn_topic_0000001173324623_p38391030164415"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="45.28547145285472%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324623_p38395308443"><a name="zh-cn_topic_0000001173324623_p38395308443"></a><a name="zh-cn_topic_0000001173324623_p38395308443"></a>按钮的字体列表，用逗号分隔，每个字体用字体名或者字体族名设置。列表中第一个系统中存在的或者通过<a href="js-components-common-customizing-font.md#ZH-CN_TOPIC_0000001163812210">自定义字体</a>指定的字体，会被选中作为文本的字体。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324623_row783993094418"><td class="cellrowborder" valign="top" width="17.458254174582542%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324623_p78391530174414"><a name="zh-cn_topic_0000001173324623_p78391530174414"></a><a name="zh-cn_topic_0000001173324623_p78391530174414"></a>icon-width</p>
</td>
<td class="cellrowborder" valign="top" width="11.40885911408859%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324623_p68396304443"><a name="zh-cn_topic_0000001173324623_p68396304443"></a><a name="zh-cn_topic_0000001173324623_p68396304443"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="19.208079192080792%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324623_p168391130204415"><a name="zh-cn_topic_0000001173324623_p168391130204415"></a><a name="zh-cn_topic_0000001173324623_p168391130204415"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="6.639336066393361%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324623_p983933010448"><a name="zh-cn_topic_0000001173324623_p983933010448"></a><a name="zh-cn_topic_0000001173324623_p983933010448"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="45.28547145285472%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324623_p148391030114411"><a name="zh-cn_topic_0000001173324623_p148391030114411"></a><a name="zh-cn_topic_0000001173324623_p148391030114411"></a>设置圆形按钮内部图标的宽，默认填满整个圆形按钮。</p>
<div class="note" id="zh-cn_topic_0000001173324623_note1983911301443"><a name="zh-cn_topic_0000001173324623_note1983911301443"></a><a name="zh-cn_topic_0000001173324623_note1983911301443"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001173324623_p183993054416"><a name="zh-cn_topic_0000001173324623_p183993054416"></a><a name="zh-cn_topic_0000001173324623_p183993054416"></a>icon使用svg图源时必须设置该样式。</p>
</div></div>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324623_row158391630184416"><td class="cellrowborder" valign="top" width="17.458254174582542%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324623_p6840133016442"><a name="zh-cn_topic_0000001173324623_p6840133016442"></a><a name="zh-cn_topic_0000001173324623_p6840133016442"></a>icon-height</p>
</td>
<td class="cellrowborder" valign="top" width="11.40885911408859%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324623_p168401830194410"><a name="zh-cn_topic_0000001173324623_p168401830194410"></a><a name="zh-cn_topic_0000001173324623_p168401830194410"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="19.208079192080792%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324623_p2840830164417"><a name="zh-cn_topic_0000001173324623_p2840830164417"></a><a name="zh-cn_topic_0000001173324623_p2840830164417"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="6.639336066393361%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324623_p4840930204420"><a name="zh-cn_topic_0000001173324623_p4840930204420"></a><a name="zh-cn_topic_0000001173324623_p4840930204420"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="45.28547145285472%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324623_p1084018307444"><a name="zh-cn_topic_0000001173324623_p1084018307444"></a><a name="zh-cn_topic_0000001173324623_p1084018307444"></a>设置圆形按钮内部图标的高，默认填满整个圆形按钮。</p>
<div class="note" id="zh-cn_topic_0000001173324623_note18840133012443"><a name="zh-cn_topic_0000001173324623_note18840133012443"></a><a name="zh-cn_topic_0000001173324623_note18840133012443"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001173324623_p178401630194412"><a name="zh-cn_topic_0000001173324623_p178401630194412"></a><a name="zh-cn_topic_0000001173324623_p178401630194412"></a>icon使用svg图源时必须设置该样式。</p>
</div></div>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324623_row1284083054413"><td class="cellrowborder" valign="top" width="17.458254174582542%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324623_p4840173044413"><a name="zh-cn_topic_0000001173324623_p4840173044413"></a><a name="zh-cn_topic_0000001173324623_p4840173044413"></a>radius</p>
</td>
<td class="cellrowborder" valign="top" width="11.40885911408859%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324623_p18840143084414"><a name="zh-cn_topic_0000001173324623_p18840143084414"></a><a name="zh-cn_topic_0000001173324623_p18840143084414"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="19.208079192080792%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324623_p1584018301446"><a name="zh-cn_topic_0000001173324623_p1584018301446"></a><a name="zh-cn_topic_0000001173324623_p1584018301446"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="6.639336066393361%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324623_p168401030114412"><a name="zh-cn_topic_0000001173324623_p168401030114412"></a><a name="zh-cn_topic_0000001173324623_p168401030114412"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="45.28547145285472%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324623_p11841183004414"><a name="zh-cn_topic_0000001173324623_p11841183004414"></a><a name="zh-cn_topic_0000001173324623_p11841183004414"></a>圆形按钮半径或者胶囊按钮圆角半径。在圆形按钮类型下该样式优先于通用样式的width和height样式。</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>-   胶囊按钮（type=capsule）时，不支持border相关样式；
>-   圆形按钮（type=circle）时，不支持文本相关样式；
>-   文本按钮（type=text）时，自适应文本大小，不支持尺寸设置（radius，width，height），背景透明不支持background-color样式。

**type设置为arc时：**

除支持[通用样式](js-components-common-styles.md#ZH-CN_TOPIC_0000001163932190)中background-color、opacity、display、visibility、position、\[left|top|right|bottom外，还支持如下样式：

<a name="zh-cn_topic_0000001173324623_table3882649131618"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173324623_row6883249141619"><th class="cellrowborder" valign="top" width="23.11768823117688%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001173324623_zh-cn_topic_0000001059340528_a14a0c012a26248cfbec6b13dcc4f2cbe"><a name="zh-cn_topic_0000001173324623_zh-cn_topic_0000001059340528_a14a0c012a26248cfbec6b13dcc4f2cbe"></a><a name="zh-cn_topic_0000001173324623_zh-cn_topic_0000001059340528_a14a0c012a26248cfbec6b13dcc4f2cbe"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="20.477952204779523%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001173324623_zh-cn_topic_0000001059340528_a8dc328a555a74157a00de86181fc3a7b"><a name="zh-cn_topic_0000001173324623_zh-cn_topic_0000001059340528_a8dc328a555a74157a00de86181fc3a7b"></a><a name="zh-cn_topic_0000001173324623_zh-cn_topic_0000001059340528_a8dc328a555a74157a00de86181fc3a7b"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.869113088691131%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001173324623_zh-cn_topic_0000001059340528_a41a31e48d0c74ad4982add2655515c82"><a name="zh-cn_topic_0000001173324623_zh-cn_topic_0000001059340528_a41a31e48d0c74ad4982add2655515c82"></a><a name="zh-cn_topic_0000001173324623_zh-cn_topic_0000001059340528_a41a31e48d0c74ad4982add2655515c82"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.519248075192481%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001173324623_p988314919169"><a name="zh-cn_topic_0000001173324623_p988314919169"></a><a name="zh-cn_topic_0000001173324623_p988314919169"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="40.01599840015999%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001173324623_zh-cn_topic_0000001059340528_af7a726e456f7485c87bd4e0527bc6584"><a name="zh-cn_topic_0000001173324623_zh-cn_topic_0000001059340528_af7a726e456f7485c87bd4e0527bc6584"></a><a name="zh-cn_topic_0000001173324623_zh-cn_topic_0000001059340528_af7a726e456f7485c87bd4e0527bc6584"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173324623_row8424144919409"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324623_p165029502409"><a name="zh-cn_topic_0000001173324623_p165029502409"></a><a name="zh-cn_topic_0000001173324623_p165029502409"></a>text-color</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324623_p1450225084018"><a name="zh-cn_topic_0000001173324623_p1450225084018"></a><a name="zh-cn_topic_0000001173324623_p1450225084018"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324623_p0502175044017"><a name="zh-cn_topic_0000001173324623_p0502175044017"></a><a name="zh-cn_topic_0000001173324623_p0502175044017"></a>#de0000</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324623_p35021750134015"><a name="zh-cn_topic_0000001173324623_p35021750134015"></a><a name="zh-cn_topic_0000001173324623_p35021750134015"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324623_p4502145044012"><a name="zh-cn_topic_0000001173324623_p4502145044012"></a><a name="zh-cn_topic_0000001173324623_p4502145044012"></a>弧形按钮的文本颜色。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324623_row10425349104012"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324623_p950385020402"><a name="zh-cn_topic_0000001173324623_p950385020402"></a><a name="zh-cn_topic_0000001173324623_p950385020402"></a>font-size</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324623_p15032505401"><a name="zh-cn_topic_0000001173324623_p15032505401"></a><a name="zh-cn_topic_0000001173324623_p15032505401"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324623_p75037503405"><a name="zh-cn_topic_0000001173324623_p75037503405"></a><a name="zh-cn_topic_0000001173324623_p75037503405"></a>37.5px</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324623_p10503850144017"><a name="zh-cn_topic_0000001173324623_p10503850144017"></a><a name="zh-cn_topic_0000001173324623_p10503850144017"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324623_p8503150114014"><a name="zh-cn_topic_0000001173324623_p8503150114014"></a><a name="zh-cn_topic_0000001173324623_p8503150114014"></a>弧形按钮的文本尺寸。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324623_row542518490406"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324623_p18503250164012"><a name="zh-cn_topic_0000001173324623_p18503250164012"></a><a name="zh-cn_topic_0000001173324623_p18503250164012"></a>allow-scale</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324623_p1650315010404"><a name="zh-cn_topic_0000001173324623_p1650315010404"></a><a name="zh-cn_topic_0000001173324623_p1650315010404"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324623_p1250419505407"><a name="zh-cn_topic_0000001173324623_p1250419505407"></a><a name="zh-cn_topic_0000001173324623_p1250419505407"></a>true</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324623_p2504125017408"><a name="zh-cn_topic_0000001173324623_p2504125017408"></a><a name="zh-cn_topic_0000001173324623_p2504125017408"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324623_p75041650194011"><a name="zh-cn_topic_0000001173324623_p75041650194011"></a><a name="zh-cn_topic_0000001173324623_p75041650194011"></a>弧形按钮的文本尺寸是否跟随系统设置字体缩放尺寸进行放大缩小。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324623_row1642514912402"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324623_p050445014400"><a name="zh-cn_topic_0000001173324623_p050445014400"></a><a name="zh-cn_topic_0000001173324623_p050445014400"></a>font-style</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324623_p250418501403"><a name="zh-cn_topic_0000001173324623_p250418501403"></a><a name="zh-cn_topic_0000001173324623_p250418501403"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324623_p18504155015409"><a name="zh-cn_topic_0000001173324623_p18504155015409"></a><a name="zh-cn_topic_0000001173324623_p18504155015409"></a>normal</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324623_p175041150194017"><a name="zh-cn_topic_0000001173324623_p175041150194017"></a><a name="zh-cn_topic_0000001173324623_p175041150194017"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324623_p1850485012408"><a name="zh-cn_topic_0000001173324623_p1850485012408"></a><a name="zh-cn_topic_0000001173324623_p1850485012408"></a>弧形按钮的字体样式。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324623_row187569336406"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324623_p2504550124019"><a name="zh-cn_topic_0000001173324623_p2504550124019"></a><a name="zh-cn_topic_0000001173324623_p2504550124019"></a>font-weight</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324623_p950411503408"><a name="zh-cn_topic_0000001173324623_p950411503408"></a><a name="zh-cn_topic_0000001173324623_p950411503408"></a>number | string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324623_p155041050164019"><a name="zh-cn_topic_0000001173324623_p155041050164019"></a><a name="zh-cn_topic_0000001173324623_p155041050164019"></a>normal</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324623_p2505185020407"><a name="zh-cn_topic_0000001173324623_p2505185020407"></a><a name="zh-cn_topic_0000001173324623_p2505185020407"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324623_p1750515044020"><a name="zh-cn_topic_0000001173324623_p1750515044020"></a><a name="zh-cn_topic_0000001173324623_p1750515044020"></a>弧形按钮的字体粗细。见<a href="js-components-basic-text.md#zh-cn_topic_0000001127125018_section5775351116">text组件font-weight的样式属性</a>。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324623_row8251631144012"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173324623_p750565004010"><a name="zh-cn_topic_0000001173324623_p750565004010"></a><a name="zh-cn_topic_0000001173324623_p750565004010"></a>font-family</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173324623_p125059504401"><a name="zh-cn_topic_0000001173324623_p125059504401"></a><a name="zh-cn_topic_0000001173324623_p125059504401"></a>&lt;string&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173324623_p115051650154015"><a name="zh-cn_topic_0000001173324623_p115051650154015"></a><a name="zh-cn_topic_0000001173324623_p115051650154015"></a>sans-serif</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173324623_p45051350164012"><a name="zh-cn_topic_0000001173324623_p45051350164012"></a><a name="zh-cn_topic_0000001173324623_p45051350164012"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173324623_p9505195015402"><a name="zh-cn_topic_0000001173324623_p9505195015402"></a><a name="zh-cn_topic_0000001173324623_p9505195015402"></a>按钮的字体列表，用逗号分隔，每个字体用字体名或者字体族名设置。列表中第一个系统中存在的或者通过<a href="js-components-common-customizing-font.md#ZH-CN_TOPIC_0000001163812210">自定义字体</a>指定的字体，会被选中作为文本的字体。</p>
</td>
</tr>
</tbody>
</table>

## 事件<a name="zh-cn_topic_0000001173324623_section71081937192815"></a>

支持[通用事件](js-components-common-events.md#ZH-CN_TOPIC_0000001209412119)。

## 方法<a name="zh-cn_topic_0000001173324623_section47669296127"></a>

支持[通用方法](js-components-common-methods.md#ZH-CN_TOPIC_0000001209252157)。

类型为download时，支持如下方法：

<a name="zh-cn_topic_0000001173324623_t75606345ece64f818511af2963b4522d"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173324623_rf7e96304e96b4abcada899f917623b50"><th class="cellrowborder" valign="top" width="17.18%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173324623_abdd98ec01df046a7ac2f66a3fa4eda04"><a name="zh-cn_topic_0000001173324623_abdd98ec01df046a7ac2f66a3fa4eda04"></a><a name="zh-cn_topic_0000001173324623_abdd98ec01df046a7ac2f66a3fa4eda04"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="28.82%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173324623_afa86bf0c638b4860a91ea0e6255b7744"><a name="zh-cn_topic_0000001173324623_afa86bf0c638b4860a91ea0e6255b7744"></a><a name="zh-cn_topic_0000001173324623_afa86bf0c638b4860a91ea0e6255b7744"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="54%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173324623_aa7783f4706e8434493b6e941e0100652"><a name="zh-cn_topic_0000001173324623_aa7783f4706e8434493b6e941e0100652"></a><a name="zh-cn_topic_0000001173324623_aa7783f4706e8434493b6e941e0100652"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173324623_r51da7a66ad844356a54fc7d198bbc496"><td class="cellrowborder" valign="top" width="17.18%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173324623_a37c62c3017bc4b85813051fedae5523a"><a name="zh-cn_topic_0000001173324623_a37c62c3017bc4b85813051fedae5523a"></a><a name="zh-cn_topic_0000001173324623_a37c62c3017bc4b85813051fedae5523a"></a>setProgress</p>
</td>
<td class="cellrowborder" valign="top" width="28.82%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173324623_a0fa3cdedaab94e11b1c1df493e671084"><a name="zh-cn_topic_0000001173324623_a0fa3cdedaab94e11b1c1df493e671084"></a><a name="zh-cn_topic_0000001173324623_a0fa3cdedaab94e11b1c1df493e671084"></a>{ progress:percent }</p>
</td>
<td class="cellrowborder" valign="top" width="54%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173324623_p157114142914"><a name="zh-cn_topic_0000001173324623_p157114142914"></a><a name="zh-cn_topic_0000001173324623_p157114142914"></a>设定下载按钮进度条进度，取值位于0-100区间内，当设置的值大于0时，下载按钮展现进度条。当设置的值大于等于100时，取消进度条显示。</p>
<div class="note" id="zh-cn_topic_0000001173324623_note11137355291"><a name="zh-cn_topic_0000001173324623_note11137355291"></a><a name="zh-cn_topic_0000001173324623_note11137355291"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001173324623_p19137355592"><a name="zh-cn_topic_0000001173324623_p19137355592"></a><a name="zh-cn_topic_0000001173324623_p19137355592"></a>浮在进度条上的文字通过value值进行变更。</p>
</div></div>
</td>
</tr>
</tbody>
</table>

## 示例<a name="zh-cn_topic_0000001173324623_section16867208402"></a>

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
    progress: 5,
    downloadText: "Download"
  },
  progress(e) {
    this.progress += 10;
    this.downloadText = this.progress + "%";
    this.$element('download-btn').setProgress({ progress: this.progress });
    if (this.progress >= 100) {
      this.downloadText = "Done";
    }
  }
}
```

![](figures/zh-cn_image_0000001127125132.png)

