# piece<a name="ZH-CN_TOPIC_0000001209210709"></a>

-   [子组件](#zh-cn_topic_0000001173164767_section9288143101012)
-   [属性](#zh-cn_topic_0000001173164767_section2907183951110)
-   [样式](#zh-cn_topic_0000001173164767_section17756476592)
-   [事件](#zh-cn_topic_0000001173164767_section19137152119)
-   [方法](#zh-cn_topic_0000001173164767_section2279124532420)
-   [示例](#zh-cn_topic_0000001173164767_section118886119320)

一种块状的入口，可包含图片和文本。常用于展示收件人，例如：邮件收件人或信息收件人。

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从API Version 5 开始支持。

## 子组件<a name="zh-cn_topic_0000001173164767_section9288143101012"></a>

无

## 属性<a name="zh-cn_topic_0000001173164767_section2907183951110"></a>

除支持[通用属性](js-components-common-attributes.md#ZH-CN_TOPIC_0000001163812208)外，还支持如下属性：

<a name="zh-cn_topic_0000001173164767_table20633101642315"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173164767_row663331618238"><th class="cellrowborder" valign="top" width="14.5014501450145%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001173164767_a45273e2103004ff3bdd3375013e96a2a"><a name="zh-cn_topic_0000001173164767_a45273e2103004ff3bdd3375013e96a2a"></a><a name="zh-cn_topic_0000001173164767_a45273e2103004ff3bdd3375013e96a2a"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="12.62126212621262%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001173164767_ad5b10d4a60e44bb4a8bbb3b4416d7b27"><a name="zh-cn_topic_0000001173164767_ad5b10d4a60e44bb4a8bbb3b4416d7b27"></a><a name="zh-cn_topic_0000001173164767_ad5b10d4a60e44bb4a8bbb3b4416d7b27"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.03080308030803%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001173164767_ab2ae3d9f60d6475ab95ba095851a9d07"><a name="zh-cn_topic_0000001173164767_ab2ae3d9f60d6475ab95ba095851a9d07"></a><a name="zh-cn_topic_0000001173164767_ab2ae3d9f60d6475ab95ba095851a9d07"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="6.64066406640664%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001173164767_p154141646194"><a name="zh-cn_topic_0000001173164767_p154141646194"></a><a name="zh-cn_topic_0000001173164767_p154141646194"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="58.2058205820582%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001173164767_af5c3b773ed0a42e589819a6c8d257ca1"><a name="zh-cn_topic_0000001173164767_af5c3b773ed0a42e589819a6c8d257ca1"></a><a name="zh-cn_topic_0000001173164767_af5c3b773ed0a42e589819a6c8d257ca1"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173164767_row1875918426407"><td class="cellrowborder" valign="top" width="14.5014501450145%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164767_p15759174219407"><a name="zh-cn_topic_0000001173164767_p15759174219407"></a><a name="zh-cn_topic_0000001173164767_p15759174219407"></a>content</p>
</td>
<td class="cellrowborder" valign="top" width="12.62126212621262%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164767_p14759184212400"><a name="zh-cn_topic_0000001173164767_p14759184212400"></a><a name="zh-cn_topic_0000001173164767_p14759184212400"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.03080308030803%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164767_p575913424403"><a name="zh-cn_topic_0000001173164767_p575913424403"></a><a name="zh-cn_topic_0000001173164767_p575913424403"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="6.64066406640664%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164767_p24156461792"><a name="zh-cn_topic_0000001173164767_p24156461792"></a><a name="zh-cn_topic_0000001173164767_p24156461792"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="58.2058205820582%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164767_p1975944244011"><a name="zh-cn_topic_0000001173164767_p1975944244011"></a><a name="zh-cn_topic_0000001173164767_p1975944244011"></a>操作块文本内容。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164767_row1401171483915"><td class="cellrowborder" valign="top" width="14.5014501450145%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164767_p637566151211"><a name="zh-cn_topic_0000001173164767_p637566151211"></a><a name="zh-cn_topic_0000001173164767_p637566151211"></a>closable</p>
</td>
<td class="cellrowborder" valign="top" width="12.62126212621262%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164767_p134021148395"><a name="zh-cn_topic_0000001173164767_p134021148395"></a><a name="zh-cn_topic_0000001173164767_p134021148395"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.03080308030803%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164767_p1840211418393"><a name="zh-cn_topic_0000001173164767_p1840211418393"></a><a name="zh-cn_topic_0000001173164767_p1840211418393"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="6.64066406640664%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164767_p1415746595"><a name="zh-cn_topic_0000001173164767_p1415746595"></a><a name="zh-cn_topic_0000001173164767_p1415746595"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="58.2058205820582%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164767_p19402201416398"><a name="zh-cn_topic_0000001173164767_p19402201416398"></a><a name="zh-cn_topic_0000001173164767_p19402201416398"></a>设置当前操作块是否显示删除图标，当显示删除图标时，点击删除图标会触发close事件。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173164767_row78648123418"><td class="cellrowborder" valign="top" width="14.5014501450145%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001173164767_p173023953412"><a name="zh-cn_topic_0000001173164767_p173023953412"></a><a name="zh-cn_topic_0000001173164767_p173023953412"></a>icon</p>
</td>
<td class="cellrowborder" valign="top" width="12.62126212621262%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001173164767_p530216953412"><a name="zh-cn_topic_0000001173164767_p530216953412"></a><a name="zh-cn_topic_0000001173164767_p530216953412"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.03080308030803%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001173164767_p3302149133418"><a name="zh-cn_topic_0000001173164767_p3302149133418"></a><a name="zh-cn_topic_0000001173164767_p3302149133418"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="6.64066406640664%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001173164767_p103024953410"><a name="zh-cn_topic_0000001173164767_p103024953410"></a><a name="zh-cn_topic_0000001173164767_p103024953410"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="58.2058205820582%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001173164767_p230211914342"><a name="zh-cn_topic_0000001173164767_p230211914342"></a><a name="zh-cn_topic_0000001173164767_p230211914342"></a>操作块删除图标的url，支持本地。</p>
</td>
</tr>
</tbody>
</table>

## 样式<a name="zh-cn_topic_0000001173164767_section17756476592"></a>

支持[通用样式](js-components-common-styles.md#ZH-CN_TOPIC_0000001163932190)。

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>文本和图片默认在整个piece组件中居中。

## 事件<a name="zh-cn_topic_0000001173164767_section19137152119"></a>

除支持[通用事件](js-components-common-events.md#ZH-CN_TOPIC_0000001209412119)外，还支持如下事件：

<a name="zh-cn_topic_0000001173164767_table3674139193020"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173164767_row14674539123012"><th class="cellrowborder" valign="top" width="24.852485248524854%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173164767_a426b8903842d48fa8012a24ff3c997eb"><a name="zh-cn_topic_0000001173164767_a426b8903842d48fa8012a24ff3c997eb"></a><a name="zh-cn_topic_0000001173164767_a426b8903842d48fa8012a24ff3c997eb"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="29.552955295529554%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173164767_a53448ba47e5e4ae9bf7774c90820e970"><a name="zh-cn_topic_0000001173164767_a53448ba47e5e4ae9bf7774c90820e970"></a><a name="zh-cn_topic_0000001173164767_a53448ba47e5e4ae9bf7774c90820e970"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="45.5945594559456%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173164767_add489ff50c444f24b759162c7f4bad9a"><a name="zh-cn_topic_0000001173164767_add489ff50c444f24b759162c7f4bad9a"></a><a name="zh-cn_topic_0000001173164767_add489ff50c444f24b759162c7f4bad9a"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173164767_row418514431304"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173164767_p11911549133016"><a name="zh-cn_topic_0000001173164767_p11911549133016"></a><a name="zh-cn_topic_0000001173164767_p11911549133016"></a>close</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173164767_p1691204993018"><a name="zh-cn_topic_0000001173164767_p1691204993018"></a><a name="zh-cn_topic_0000001173164767_p1691204993018"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173164767_p1891114933015"><a name="zh-cn_topic_0000001173164767_p1891114933015"></a><a name="zh-cn_topic_0000001173164767_p1891114933015"></a>当piece组件点击删除图标触发，此时可以通过渲染属性if删除该组件。</p>
</td>
</tr>
</tbody>
</table>

## 方法<a name="zh-cn_topic_0000001173164767_section2279124532420"></a>

支持[通用方法](js-components-common-methods.md#ZH-CN_TOPIC_0000001209252157)。

## 示例<a name="zh-cn_topic_0000001173164767_section118886119320"></a>

```
<!-- xxx.hml-->
<div>
  <piece if="{{first}}" content="Huawei"></piece>
  <piece if="{{second}}" content="Huawei" closable="true" onclose="closeSecond"></piece>
</div>
```

```
// xxx.js
export default {
  data: {
    first: true,
    second: true
  },
  closeSecond(e) {
    this.second = false;
  }
}
```

![](figures/SVID_20210301_193525_1.gif)

