# option<a name="ZH-CN_TOPIC_0000001127125028"></a>

当作为<[select](js-components-basic-select.md)\>的子组件时用来展示下拉选择的具体项目。

当作为<[menu](js-components-basic-menu.md)\>的子组件时用来展示弹出菜单的具体项目。

## 权限列表<a name="section11257113618419"></a>

无

## 子组件<a name="section9288143101012"></a>

不支持。

## 属性<a name="section2907183951110"></a>

除支持[通用属性](js-components-common-attributes.md)外，还支持如下属性：↵

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
<tbody><tr id="row1518719174474"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="a883fd418b15f44aab62cb432b06673c4"><a name="a883fd418b15f44aab62cb432b06673c4"></a><a name="a883fd418b15f44aab62cb432b06673c4"></a>selected</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="afc56b8abb2534994b62d433a905471c7"><a name="afc56b8abb2534994b62d433a905471c7"></a><a name="afc56b8abb2534994b62d433a905471c7"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="ae97849073e88424bbe1d389b984956f1"><a name="ae97849073e88424bbe1d389b984956f1"></a><a name="ae97849073e88424bbe1d389b984956f1"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="a91102d93137e4b189678fa366af8fbcf"><a name="a91102d93137e4b189678fa366af8fbcf"></a><a name="a91102d93137e4b189678fa366af8fbcf"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="a17bb7bb8f011471f9527ca6bfb6ab15d"><a name="a17bb7bb8f011471f9527ca6bfb6ab15d"></a><a name="a17bb7bb8f011471f9527ca6bfb6ab15d"></a>选择项是否为下拉列表的默认项，仅在父组件是select时生效。</p>
</td>
</tr>
<tr id="row685281464718"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="a7d9da77d616d46eea405d2773043efa4"><a name="a7d9da77d616d46eea405d2773043efa4"></a><a name="a7d9da77d616d46eea405d2773043efa4"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="a160704c9307f481db3132fdc9699124e"><a name="a160704c9307f481db3132fdc9699124e"></a><a name="a160704c9307f481db3132fdc9699124e"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="a9cad6471925043e7aa7d55c4b1fae551"><a name="a9cad6471925043e7aa7d55c4b1fae551"></a><a name="a9cad6471925043e7aa7d55c4b1fae551"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="ad0233f7d2ac4447facb335d36c8acfc5"><a name="ad0233f7d2ac4447facb335d36c8acfc5"></a><a name="ad0233f7d2ac4447facb335d36c8acfc5"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p1145911181476"><a name="p1145911181476"></a><a name="p1145911181476"></a>选择项的值，作为select、menu父组件的selected事件中的返回值。</p>
<div class="note" id="note174591818114715"><a name="note174591818114715"></a><a name="note174591818114715"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="p9459218134716"><a name="p9459218134716"></a><a name="p9459218134716"></a>option选项的UI展示值需要放在标签内，如&lt;option value="10"&gt;十月&lt;/option&gt;</p>
</div></div>
</td>
</tr>
<tr id="row1221312129475"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p124597184479"><a name="p124597184479"></a><a name="p124597184479"></a>icon</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p445961814719"><a name="p445961814719"></a><a name="p445961814719"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p345971813473"><a name="p345971813473"></a><a name="p345971813473"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p1745919188470"><a name="p1745919188470"></a><a name="p1745919188470"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p164596188472"><a name="p164596188472"></a><a name="p164596188472"></a>图标资源路径，该图标展示在选项文本前，图标格式为jpg，png和svg。</p>
</td>
</tr>
</tbody>
</table>

## 样式<a name="section5775351116"></a>

支持如下样式。

<a name="t2420cc4f2a7a48afbeb83cb4e0d3c481"></a>
<table><thead align="left"><tr id="r0684f76f60eb45279db68f515f4bf61c"><th class="cellrowborder" valign="top" width="18.81188118811881%" id="mcps1.1.6.1.1"><p id="a483bf3731e274a69a3318680ab8d294d"><a name="a483bf3731e274a69a3318680ab8d294d"></a><a name="a483bf3731e274a69a3318680ab8d294d"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="24.752475247524753%" id="mcps1.1.6.1.2"><p id="a668752fdd289488894b824c67145a35a"><a name="a668752fdd289488894b824c67145a35a"></a><a name="a668752fdd289488894b824c67145a35a"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="15.841584158415841%" id="mcps1.1.6.1.3"><p id="af7492efe635a4c36ae86a2ddea34b1bd"><a name="af7492efe635a4c36ae86a2ddea34b1bd"></a><a name="af7492efe635a4c36ae86a2ddea34b1bd"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="9.900990099009901%" id="mcps1.1.6.1.4"><p id="a003e28cad63a485b9eebb109f46c7309"><a name="a003e28cad63a485b9eebb109f46c7309"></a><a name="a003e28cad63a485b9eebb109f46c7309"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="30.693069306930692%" id="mcps1.1.6.1.5"><p id="a8f798a93681e4bd2a9965529fb6bc20f"><a name="a8f798a93681e4bd2a9965529fb6bc20f"></a><a name="a8f798a93681e4bd2a9965529fb6bc20f"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="rabeceb58645f41759ef590abd1094c11"><td class="cellrowborder" valign="top" width="18.81188118811881%" headers="mcps1.1.6.1.1 "><p id="a61b4d670b9de4435ba57801f6f7a937e"><a name="a61b4d670b9de4435ba57801f6f7a937e"></a><a name="a61b4d670b9de4435ba57801f6f7a937e"></a>color</p>
</td>
<td class="cellrowborder" valign="top" width="24.752475247524753%" headers="mcps1.1.6.1.2 "><p id="a9599239e7edf405e9930713ee7191e15"><a name="a9599239e7edf405e9930713ee7191e15"></a><a name="a9599239e7edf405e9930713ee7191e15"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.6.1.3 "><p id="ad470728c1d9146afb164db59bf59c473"><a name="ad470728c1d9146afb164db59bf59c473"></a><a name="ad470728c1d9146afb164db59bf59c473"></a>#e6000000</p>
</td>
<td class="cellrowborder" valign="top" width="9.900990099009901%" headers="mcps1.1.6.1.4 "><p id="a00dda7f922aa4782b4ed6a92a98d5d1b"><a name="a00dda7f922aa4782b4ed6a92a98d5d1b"></a><a name="a00dda7f922aa4782b4ed6a92a98d5d1b"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="30.693069306930692%" headers="mcps1.1.6.1.5 "><p id="a64508ed81c5b4b3ca9def0fefae31f36"><a name="a64508ed81c5b4b3ca9def0fefae31f36"></a><a name="a64508ed81c5b4b3ca9def0fefae31f36"></a>选择项的文本颜色。</p>
</td>
</tr>
<tr id="rc7beaf0e35194f4b821333f3aa91aefc"><td class="cellrowborder" valign="top" width="18.81188118811881%" headers="mcps1.1.6.1.1 "><p id="a71b1da3d23d54fd6bfbba190ca91b4da"><a name="a71b1da3d23d54fd6bfbba190ca91b4da"></a><a name="a71b1da3d23d54fd6bfbba190ca91b4da"></a>font-size</p>
</td>
<td class="cellrowborder" valign="top" width="24.752475247524753%" headers="mcps1.1.6.1.2 "><p id="a3c24ccd1f1274cb5ba9496ed322fa6e4"><a name="a3c24ccd1f1274cb5ba9496ed322fa6e4"></a><a name="a3c24ccd1f1274cb5ba9496ed322fa6e4"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.6.1.3 "><p id="adec9bcad945f4c0da077f460787a55b3"><a name="adec9bcad945f4c0da077f460787a55b3"></a><a name="adec9bcad945f4c0da077f460787a55b3"></a>16px</p>
</td>
<td class="cellrowborder" valign="top" width="9.900990099009901%" headers="mcps1.1.6.1.4 "><p id="a955d1ce0c7824017aa55b4c1a629e63d"><a name="a955d1ce0c7824017aa55b4c1a629e63d"></a><a name="a955d1ce0c7824017aa55b4c1a629e63d"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="30.693069306930692%" headers="mcps1.1.6.1.5 "><p id="a0d0c0048474b4540bc4bc2dd11775ac6"><a name="a0d0c0048474b4540bc4bc2dd11775ac6"></a><a name="a0d0c0048474b4540bc4bc2dd11775ac6"></a>选择项的文本尺寸。</p>
</td>
</tr>
<tr id="row810552892"><td class="cellrowborder" valign="top" width="18.81188118811881%" headers="mcps1.1.6.1.1 "><p id="p523512225579"><a name="p523512225579"></a><a name="p523512225579"></a>allow-scale</p>
</td>
<td class="cellrowborder" valign="top" width="24.752475247524753%" headers="mcps1.1.6.1.2 "><p id="p923522212570"><a name="p923522212570"></a><a name="p923522212570"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.6.1.3 "><p id="p11235322145714"><a name="p11235322145714"></a><a name="p11235322145714"></a>true</p>
</td>
<td class="cellrowborder" valign="top" width="9.900990099009901%" headers="mcps1.1.6.1.4 "><p id="p12235112285712"><a name="p12235112285712"></a><a name="p12235112285712"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="30.693069306930692%" headers="mcps1.1.6.1.5 "><p id="p1023513229570"><a name="p1023513229570"></a><a name="p1023513229570"></a>选择项的文本尺寸是否跟随系统设置字体缩放尺寸进行放大缩小。</p>
<div class="note" id="note1467145631615"><a name="note1467145631615"></a><a name="note1467145631615"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="p126785616164"><a name="p126785616164"></a><a name="p126785616164"></a>如果在config描述文件中针对ability配置了fontSize的config-changes标签，则应用不会重启而直接生效。</p>
</div></div>
</td>
</tr>
<tr id="rdf236cf1bf6e427e9f1eda9b51897b65"><td class="cellrowborder" valign="top" width="18.81188118811881%" headers="mcps1.1.6.1.1 "><p id="aaa79d478172148f49b57a9b61bb1c2aa"><a name="aaa79d478172148f49b57a9b61bb1c2aa"></a><a name="aaa79d478172148f49b57a9b61bb1c2aa"></a>font-weight</p>
</td>
<td class="cellrowborder" valign="top" width="24.752475247524753%" headers="mcps1.1.6.1.2 "><p id="aaa011c1dbd094e6f9d00109bcba267c0"><a name="aaa011c1dbd094e6f9d00109bcba267c0"></a><a name="aaa011c1dbd094e6f9d00109bcba267c0"></a>number | string</p>
</td>
<td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.6.1.3 "><p id="a6f998aca924d438b89f36ffbb2c4d32d"><a name="a6f998aca924d438b89f36ffbb2c4d32d"></a><a name="a6f998aca924d438b89f36ffbb2c4d32d"></a>normal</p>
</td>
<td class="cellrowborder" valign="top" width="9.900990099009901%" headers="mcps1.1.6.1.4 "><p id="af2332b705d6447acb25117940e7f3c30"><a name="af2332b705d6447acb25117940e7f3c30"></a><a name="af2332b705d6447acb25117940e7f3c30"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="30.693069306930692%" headers="mcps1.1.6.1.5 "><p id="aaba88a62d1484a5a884cfc516e68f949"><a name="aaba88a62d1484a5a884cfc516e68f949"></a><a name="aaba88a62d1484a5a884cfc516e68f949"></a>选择项的字体粗细，见<a href="js-components-basic-text.md#section5775351116">text组件font-weight的样式属性</a>。</p>
</td>
</tr>
<tr id="re1d34ad1822943cebad252df6e510f95"><td class="cellrowborder" valign="top" width="18.81188118811881%" headers="mcps1.1.6.1.1 "><p id="af8be974b93b0494f98525507cef59575"><a name="af8be974b93b0494f98525507cef59575"></a><a name="af8be974b93b0494f98525507cef59575"></a>text-decoration</p>
</td>
<td class="cellrowborder" valign="top" width="24.752475247524753%" headers="mcps1.1.6.1.2 "><p id="a292b2c30ba414fd2b2ad98140f566fb7"><a name="a292b2c30ba414fd2b2ad98140f566fb7"></a><a name="a292b2c30ba414fd2b2ad98140f566fb7"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.6.1.3 "><p id="a37a3613403c7436d959537a24cce65aa"><a name="a37a3613403c7436d959537a24cce65aa"></a><a name="a37a3613403c7436d959537a24cce65aa"></a>none</p>
</td>
<td class="cellrowborder" valign="top" width="9.900990099009901%" headers="mcps1.1.6.1.4 "><p id="a6d9989e17ccc41fc98a868e93bcba305"><a name="a6d9989e17ccc41fc98a868e93bcba305"></a><a name="a6d9989e17ccc41fc98a868e93bcba305"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="30.693069306930692%" headers="mcps1.1.6.1.5 "><p id="aad7a14f50e664992800a990ae4261aa0"><a name="aad7a14f50e664992800a990ae4261aa0"></a><a name="aad7a14f50e664992800a990ae4261aa0"></a>选择项的文本修饰，见<a href="js-components-basic-text.md#section5775351116">text组件text-decoration的样式属性</a>。</p>
</td>
</tr>
<tr id="r551b8b3310cd41c6988d4ea426fdbe15"><td class="cellrowborder" valign="top" width="18.81188118811881%" headers="mcps1.1.6.1.1 "><p id="a382bf204a52142229c5fdaafee11b0ac"><a name="a382bf204a52142229c5fdaafee11b0ac"></a><a name="a382bf204a52142229c5fdaafee11b0ac"></a>font-family</p>
</td>
<td class="cellrowborder" valign="top" width="24.752475247524753%" headers="mcps1.1.6.1.2 "><p id="af4c827c5dc8640c7b71cef3ab10a8c8a"><a name="af4c827c5dc8640c7b71cef3ab10a8c8a"></a><a name="af4c827c5dc8640c7b71cef3ab10a8c8a"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.6.1.3 "><p id="aae19b2b84b70411ca6ebb975825547fc"><a name="aae19b2b84b70411ca6ebb975825547fc"></a><a name="aae19b2b84b70411ca6ebb975825547fc"></a>sans-serif</p>
</td>
<td class="cellrowborder" valign="top" width="9.900990099009901%" headers="mcps1.1.6.1.4 "><p id="acd71bec57fbc44b5afea10134cdae523"><a name="acd71bec57fbc44b5afea10134cdae523"></a><a name="acd71bec57fbc44b5afea10134cdae523"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="30.693069306930692%" headers="mcps1.1.6.1.5 "><p id="a0b6365c7b9874a8796099aa02f73cde2"><a name="a0b6365c7b9874a8796099aa02f73cde2"></a><a name="a0b6365c7b9874a8796099aa02f73cde2"></a>选择项的字体列表，用逗号分隔，每个字体用字体名或者字体族名设置。列表中第一个系统中存在的或者通过<a href="js-components-common-customizing-font.md">自定义字体</a>指定的字体，会被选中作为文本的字体。</p>
</td>
</tr>
</tbody>
</table>

## 事件<a name="section1013173520328"></a>

不支持。

## 方法<a name="section45101363326"></a>

不支持。

## 示例<a name="section7566164416325"></a>

详见[menu示例](js-components-basic-menu.md#section54636714136)。

