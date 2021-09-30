# span<a name="ZH-CN_TOPIC_0000001209210711"></a>

-   [权限列表](#zh-cn_topic_0000001127284860_section11257113618419)
-   [子组件](#zh-cn_topic_0000001127284860_section9288143101012)
-   [属性](#zh-cn_topic_0000001127284860_section2907183951110)
-   [样式](#zh-cn_topic_0000001127284860_section5775351116)
-   [事件](#zh-cn_topic_0000001127284860_section1319514265813)
-   [方法](#zh-cn_topic_0000001127284860_section2291124515582)
-   [示例](#zh-cn_topic_0000001127284860_section1841815550582)

作为<[text](js-components-basic-text.md#ZH-CN_TOPIC_0000001163812222)\>子组件提供文本修饰能力。

## 权限列表<a name="zh-cn_topic_0000001127284860_section11257113618419"></a>

无

## 子组件<a name="zh-cn_topic_0000001127284860_section9288143101012"></a>

支持子组件<span\>。

## 属性<a name="zh-cn_topic_0000001127284860_section2907183951110"></a>

支持[通用属性](js-components-common-attributes.md#ZH-CN_TOPIC_0000001163812208)。

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>-   不支持focusable和disabled属性。

## 样式<a name="zh-cn_topic_0000001127284860_section5775351116"></a>

仅支持如下样式：

<a name="zh-cn_topic_0000001127284860_ta0a517e341374f8dbac91fcbabd0a5ff"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001127284860_r4898f887897a46fab1b4999a4f83402f"><th class="cellrowborder" valign="top" width="21.21212121212121%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001127284860_ac9b6b02cd94942a5a0de6e18b10be274"><a name="zh-cn_topic_0000001127284860_ac9b6b02cd94942a5a0de6e18b10be274"></a><a name="zh-cn_topic_0000001127284860_ac9b6b02cd94942a5a0de6e18b10be274"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="15.8015801580158%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001127284860_acdcd659d46f24eac86378824c8ee463b"><a name="zh-cn_topic_0000001127284860_acdcd659d46f24eac86378824c8ee463b"></a><a name="zh-cn_topic_0000001127284860_acdcd659d46f24eac86378824c8ee463b"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="14.231423142314231%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001127284860_a9def453e9df6412bba79b8fff70869e8"><a name="zh-cn_topic_0000001127284860_a9def453e9df6412bba79b8fff70869e8"></a><a name="zh-cn_topic_0000001127284860_a9def453e9df6412bba79b8fff70869e8"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="9.400940094009401%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001127284860_a1e15f96e33ee48b9a0e14dbee0968f8a"><a name="zh-cn_topic_0000001127284860_a1e15f96e33ee48b9a0e14dbee0968f8a"></a><a name="zh-cn_topic_0000001127284860_a1e15f96e33ee48b9a0e14dbee0968f8a"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="39.35393539353936%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001127284860_a7168bff3ff0647d88967647f6ab26d5f"><a name="zh-cn_topic_0000001127284860_a7168bff3ff0647d88967647f6ab26d5f"></a><a name="zh-cn_topic_0000001127284860_a7168bff3ff0647d88967647f6ab26d5f"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001127284860_r32272055007144f79a2dfea8a786e589"><td class="cellrowborder" valign="top" width="21.21212121212121%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127284860_afc75d8f275cc41089a4e4dc8a3fbee88"><a name="zh-cn_topic_0000001127284860_afc75d8f275cc41089a4e4dc8a3fbee88"></a><a name="zh-cn_topic_0000001127284860_afc75d8f275cc41089a4e4dc8a3fbee88"></a>color</p>
</td>
<td class="cellrowborder" valign="top" width="15.8015801580158%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127284860_abf3cdb4352d94dbb96789b9920bff09e"><a name="zh-cn_topic_0000001127284860_abf3cdb4352d94dbb96789b9920bff09e"></a><a name="zh-cn_topic_0000001127284860_abf3cdb4352d94dbb96789b9920bff09e"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="14.231423142314231%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127284860_a40a852f6f3624109acdb18b89f75be07"><a name="zh-cn_topic_0000001127284860_a40a852f6f3624109acdb18b89f75be07"></a><a name="zh-cn_topic_0000001127284860_a40a852f6f3624109acdb18b89f75be07"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="9.400940094009401%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127284860_a61aed770cf534f06a236a689df6206e0"><a name="zh-cn_topic_0000001127284860_a61aed770cf534f06a236a689df6206e0"></a><a name="zh-cn_topic_0000001127284860_a61aed770cf534f06a236a689df6206e0"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="39.35393539353936%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127284860_a745abab21c7c47afbb4343f611f13f0e"><a name="zh-cn_topic_0000001127284860_a745abab21c7c47afbb4343f611f13f0e"></a><a name="zh-cn_topic_0000001127284860_a745abab21c7c47afbb4343f611f13f0e"></a>设置文本段落的文本颜色。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127284860_r9962b94a230e482a9cc74bbb784ea7a0"><td class="cellrowborder" valign="top" width="21.21212121212121%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127284860_a50ed6c7dc89a419b8196eb32f4374eb9"><a name="zh-cn_topic_0000001127284860_a50ed6c7dc89a419b8196eb32f4374eb9"></a><a name="zh-cn_topic_0000001127284860_a50ed6c7dc89a419b8196eb32f4374eb9"></a>font-size</p>
</td>
<td class="cellrowborder" valign="top" width="15.8015801580158%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127284860_a3fef950f99bb45768f232285d9563d59"><a name="zh-cn_topic_0000001127284860_a3fef950f99bb45768f232285d9563d59"></a><a name="zh-cn_topic_0000001127284860_a3fef950f99bb45768f232285d9563d59"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="14.231423142314231%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127284860_abf03dbbc119a4a158b410a3676fe71e6"><a name="zh-cn_topic_0000001127284860_abf03dbbc119a4a158b410a3676fe71e6"></a><a name="zh-cn_topic_0000001127284860_abf03dbbc119a4a158b410a3676fe71e6"></a>30px</p>
</td>
<td class="cellrowborder" valign="top" width="9.400940094009401%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127284860_a221074f45b48460a953a19ae07181768"><a name="zh-cn_topic_0000001127284860_a221074f45b48460a953a19ae07181768"></a><a name="zh-cn_topic_0000001127284860_a221074f45b48460a953a19ae07181768"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="39.35393539353936%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127284860_a86d755d025194433a3d824ac6308dc19"><a name="zh-cn_topic_0000001127284860_a86d755d025194433a3d824ac6308dc19"></a><a name="zh-cn_topic_0000001127284860_a86d755d025194433a3d824ac6308dc19"></a>设置文本段落的文本尺寸。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127284860_row696318282019"><td class="cellrowborder" valign="top" width="21.21212121212121%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127284860_p523512225579"><a name="zh-cn_topic_0000001127284860_p523512225579"></a><a name="zh-cn_topic_0000001127284860_p523512225579"></a>allow-scale</p>
</td>
<td class="cellrowborder" valign="top" width="15.8015801580158%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127284860_p923522212570"><a name="zh-cn_topic_0000001127284860_p923522212570"></a><a name="zh-cn_topic_0000001127284860_p923522212570"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="14.231423142314231%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127284860_p11235322145714"><a name="zh-cn_topic_0000001127284860_p11235322145714"></a><a name="zh-cn_topic_0000001127284860_p11235322145714"></a>true</p>
</td>
<td class="cellrowborder" valign="top" width="9.400940094009401%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127284860_p12235112285712"><a name="zh-cn_topic_0000001127284860_p12235112285712"></a><a name="zh-cn_topic_0000001127284860_p12235112285712"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="39.35393539353936%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127284860_p1023513229570"><a name="zh-cn_topic_0000001127284860_p1023513229570"></a><a name="zh-cn_topic_0000001127284860_p1023513229570"></a>设置文本段落的文本尺寸是否跟随系统设置字体缩放尺寸进行放大缩小。</p>
<div class="note" id="zh-cn_topic_0000001127284860_note5531128463"><a name="zh-cn_topic_0000001127284860_note5531128463"></a><a name="zh-cn_topic_0000001127284860_note5531128463"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001127284860_p11531172814611"><a name="zh-cn_topic_0000001127284860_p11531172814611"></a><a name="zh-cn_topic_0000001127284860_p11531172814611"></a>如果在config描述文件中针对ability配置了fontSize的config-changes标签，则应用不会重启而直接生效。</p>
</div></div>
</td>
</tr>
<tr id="zh-cn_topic_0000001127284860_rde507e70d93643ae8a6cb2d27c6acf99"><td class="cellrowborder" valign="top" width="21.21212121212121%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127284860_ab1137579b73e4a38a6dbe7fe5d83e8e2"><a name="zh-cn_topic_0000001127284860_ab1137579b73e4a38a6dbe7fe5d83e8e2"></a><a name="zh-cn_topic_0000001127284860_ab1137579b73e4a38a6dbe7fe5d83e8e2"></a>font-style</p>
</td>
<td class="cellrowborder" valign="top" width="15.8015801580158%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127284860_ab7f6c9ddf05c44bda226d9bf186583eb"><a name="zh-cn_topic_0000001127284860_ab7f6c9ddf05c44bda226d9bf186583eb"></a><a name="zh-cn_topic_0000001127284860_ab7f6c9ddf05c44bda226d9bf186583eb"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="14.231423142314231%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127284860_a763035129469427a9b607b50c93c046d"><a name="zh-cn_topic_0000001127284860_a763035129469427a9b607b50c93c046d"></a><a name="zh-cn_topic_0000001127284860_a763035129469427a9b607b50c93c046d"></a>normal</p>
</td>
<td class="cellrowborder" valign="top" width="9.400940094009401%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127284860_abdb1cd99a9c84f31b1bb21da686ded28"><a name="zh-cn_topic_0000001127284860_abdb1cd99a9c84f31b1bb21da686ded28"></a><a name="zh-cn_topic_0000001127284860_abdb1cd99a9c84f31b1bb21da686ded28"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="39.35393539353936%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127284860_a04816275b7d249079b4a1e80f69ea86e"><a name="zh-cn_topic_0000001127284860_a04816275b7d249079b4a1e80f69ea86e"></a><a name="zh-cn_topic_0000001127284860_a04816275b7d249079b4a1e80f69ea86e"></a>设置文本段落的字体样式，见<a href="js-components-basic-text.md#zh-cn_topic_0000001127125018_section5775351116">text组件font-style的样式属性</a>。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127284860_r41ee5629370e4317a0da49957e128ade"><td class="cellrowborder" valign="top" width="21.21212121212121%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127284860_a380a51eccb244ea9a528c41348105934"><a name="zh-cn_topic_0000001127284860_a380a51eccb244ea9a528c41348105934"></a><a name="zh-cn_topic_0000001127284860_a380a51eccb244ea9a528c41348105934"></a>font-weight</p>
</td>
<td class="cellrowborder" valign="top" width="15.8015801580158%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127284860_a6998d5f15b9d47dfb5ea5d683f2945ef"><a name="zh-cn_topic_0000001127284860_a6998d5f15b9d47dfb5ea5d683f2945ef"></a><a name="zh-cn_topic_0000001127284860_a6998d5f15b9d47dfb5ea5d683f2945ef"></a>number | string</p>
</td>
<td class="cellrowborder" valign="top" width="14.231423142314231%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127284860_a9cd90194128142d6bf6a0279aa8d191e"><a name="zh-cn_topic_0000001127284860_a9cd90194128142d6bf6a0279aa8d191e"></a><a name="zh-cn_topic_0000001127284860_a9cd90194128142d6bf6a0279aa8d191e"></a>normal</p>
</td>
<td class="cellrowborder" valign="top" width="9.400940094009401%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127284860_a16edddde0d944b13a7a3567677cc913d"><a name="zh-cn_topic_0000001127284860_a16edddde0d944b13a7a3567677cc913d"></a><a name="zh-cn_topic_0000001127284860_a16edddde0d944b13a7a3567677cc913d"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="39.35393539353936%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127284860_aa1d0d3abf811468e8c3f707e1a7e5b8c"><a name="zh-cn_topic_0000001127284860_aa1d0d3abf811468e8c3f707e1a7e5b8c"></a><a name="zh-cn_topic_0000001127284860_aa1d0d3abf811468e8c3f707e1a7e5b8c"></a>设置文本段落的字体粗细，见<a href="js-components-basic-text.md#zh-cn_topic_0000001127125018_section5775351116">text组件font-weight的样式属性</a>。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127284860_r8bf92fd80ab14f6a824003dcc7f3008c"><td class="cellrowborder" valign="top" width="21.21212121212121%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127284860_ab4ed51f180194575856b899947e2c4d4"><a name="zh-cn_topic_0000001127284860_ab4ed51f180194575856b899947e2c4d4"></a><a name="zh-cn_topic_0000001127284860_ab4ed51f180194575856b899947e2c4d4"></a>text-decoration</p>
</td>
<td class="cellrowborder" valign="top" width="15.8015801580158%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127284860_ab4048c7eccf046bab1dbdd33a0739e42"><a name="zh-cn_topic_0000001127284860_ab4048c7eccf046bab1dbdd33a0739e42"></a><a name="zh-cn_topic_0000001127284860_ab4048c7eccf046bab1dbdd33a0739e42"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="14.231423142314231%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127284860_a572fe437851c45b2a91c3748dbf3c0c3"><a name="zh-cn_topic_0000001127284860_a572fe437851c45b2a91c3748dbf3c0c3"></a><a name="zh-cn_topic_0000001127284860_a572fe437851c45b2a91c3748dbf3c0c3"></a>none</p>
</td>
<td class="cellrowborder" valign="top" width="9.400940094009401%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127284860_a4e2f6f648ebc4d6d947a3edb6efe22fb"><a name="zh-cn_topic_0000001127284860_a4e2f6f648ebc4d6d947a3edb6efe22fb"></a><a name="zh-cn_topic_0000001127284860_a4e2f6f648ebc4d6d947a3edb6efe22fb"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="39.35393539353936%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127284860_aa83ac8481649423b80b326de4eb5fefb"><a name="zh-cn_topic_0000001127284860_aa83ac8481649423b80b326de4eb5fefb"></a><a name="zh-cn_topic_0000001127284860_aa83ac8481649423b80b326de4eb5fefb"></a>设置文本段落的文本修饰，见<a href="js-components-basic-text.md#zh-cn_topic_0000001127125018_section5775351116">text组件text-decoration样式属性</a>。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127284860_rc154005d2ebf483faffebbe0a509770d"><td class="cellrowborder" valign="top" width="21.21212121212121%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001127284860_a552bd7aa0bc94b118d88abf167e87a35"><a name="zh-cn_topic_0000001127284860_a552bd7aa0bc94b118d88abf167e87a35"></a><a name="zh-cn_topic_0000001127284860_a552bd7aa0bc94b118d88abf167e87a35"></a>font-family</p>
</td>
<td class="cellrowborder" valign="top" width="15.8015801580158%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001127284860_a0f5cc516346b4cbaa2d46c08bc340eeb"><a name="zh-cn_topic_0000001127284860_a0f5cc516346b4cbaa2d46c08bc340eeb"></a><a name="zh-cn_topic_0000001127284860_a0f5cc516346b4cbaa2d46c08bc340eeb"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="14.231423142314231%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001127284860_a959e67a1855241a1bb0898b2f57c7148"><a name="zh-cn_topic_0000001127284860_a959e67a1855241a1bb0898b2f57c7148"></a><a name="zh-cn_topic_0000001127284860_a959e67a1855241a1bb0898b2f57c7148"></a>sans-serif</p>
</td>
<td class="cellrowborder" valign="top" width="9.400940094009401%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001127284860_a2db078b3c8d64498af048fa12102a2a3"><a name="zh-cn_topic_0000001127284860_a2db078b3c8d64498af048fa12102a2a3"></a><a name="zh-cn_topic_0000001127284860_a2db078b3c8d64498af048fa12102a2a3"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="39.35393539353936%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001127284860_a52f159b549364d40b7c92d51aba7c1a9"><a name="zh-cn_topic_0000001127284860_a52f159b549364d40b7c92d51aba7c1a9"></a><a name="zh-cn_topic_0000001127284860_a52f159b549364d40b7c92d51aba7c1a9"></a>设置文本段落的字体列表，用逗号分隔，每个字体用字体名或者字体族名设置。列表中第一个系统中存在的或者通过<a href="js-components-common-customizing-font.md#ZH-CN_TOPIC_0000001163812210">自定义字体</a>指定的字体，会被选中作为文本的字体。</p>
</td>
</tr>
</tbody>
</table>

## 事件<a name="zh-cn_topic_0000001127284860_section1319514265813"></a>

仅支持[通用事件](js-components-common-events.md#ZH-CN_TOPIC_0000001209412119)中的click事件。

## 方法<a name="zh-cn_topic_0000001127284860_section2291124515582"></a>

不支持。

## 示例<a name="zh-cn_topic_0000001127284860_section1841815550582"></a>

```
<!-- xxx.hml -->
<div class="container">
  <text class="title">
    <span class="spanTxt">span</span>
  </text>
</div>
```

```
/* xxx.css */
.container {
  display: flex;
  justify-content: center;
  align-items: center;
}
.title {
  font-size: 30px;
  text-align: center;
  width: 100%;
  height: 100px;
}
.spanTxt{
  color: chartreuse;
  font-size: 100px;
}
```

![](figures/zh-cn_image_0000001152588626.png)

