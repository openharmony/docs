# badge<a name="ZH-CN_TOPIC_0000001173324629"></a>

应用中如果有需用户关注的新事件提醒，可以采用新事件标记来标识。

## 权限列表<a name="section11257113618419"></a>

无

## 子组件<a name="section9288143101012"></a>

支持单个子组件。

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>仅支持单子组件节点，如果使用多子组件节点，默认使用第一个子组件节点。

## 属性<a name="section1355418214459"></a>

除支持[通用属性](js-components-common-attributes.md)外，还支持如下属性：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="12.61%" id="mcps1.1.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="14.21%" id="mcps1.1.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="42.54%" id="mcps1.1.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>placement</p>
</td>
<td class="cellrowborder" valign="top" width="12.61%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="14.21%" headers="mcps1.1.6.1.3 "><p>rightTop</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.54%" headers="mcps1.1.6.1.5 "><p>事件提醒的数字标记或者圆点标记的位置，可选值为：</p>
<ul><li>right：位于组件右边框。</li><li>rightTop：位于组件边框右上角。</li><li>left：位于组件左边框。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>count</p>
</td>
<td class="cellrowborder" valign="top" width="12.61%" headers="mcps1.1.6.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="14.21%" headers="mcps1.1.6.1.3 "><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.54%" headers="mcps1.1.6.1.5 "><p>设置提醒的消息数，默认为0。当设置相应的提醒消息数大于0时，消息提醒会变成数字标记类型，未设置消息数或者消息数不大于0时，消息提醒将采用圆点标记。</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>当数字设置为大于maxcount时，将使用maxcount显示。</p>
<p>count属性最大支持整数值为2147483647。</p>
</div></div>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>visible</p>
</td>
<td class="cellrowborder" valign="top" width="12.61%" headers="mcps1.1.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="14.21%" headers="mcps1.1.6.1.3 "><p>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.54%" headers="mcps1.1.6.1.5 "><p>是否显示消息提醒，当收到新信息提醒时可以设置该属性为true，显示相应的消息提醒，如果需要使用数字标记类型，同时需要设置相应的count属性。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>maxcount</p>
</td>
<td class="cellrowborder" valign="top" width="12.61%" headers="mcps1.1.6.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="14.21%" headers="mcps1.1.6.1.3 "><p>99</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.54%" headers="mcps1.1.6.1.5 "><p>最大消息数限制，当收到新信息提醒大于该限制时，标识数字会进行省略，仅显示maxcount+。</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>maxcount属性最大支持整数值为2147483647。</p>
</div></div>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>config</p>
</td>
<td class="cellrowborder" valign="top" width="12.61%" headers="mcps1.1.6.1.2 "><p><a href="../../nottoctopics/zh-cn_topic_0000001177114381.md#zh-cn_topic_0000001101866256_table525042221515">BadgeConfig</a></p>
</td>
<td class="cellrowborder" valign="top" width="14.21%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.54%" headers="mcps1.1.6.1.5 "><p>设置新事件标记相关配置属性。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>label<sup><span>6+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="12.61%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="14.21%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="42.54%" headers="mcps1.1.6.1.5 "><p>设置新事件提醒的文本值。</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>使用该属性时，count和maxcount属性不生效。</p>
</div></div>
</td>
</tr>
</tbody>
</table>

**表 1**  BadgeConfig

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="15.370000000000001%" id="mcps1.2.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="13.62%" id="mcps1.2.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="12.46%" id="mcps1.2.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.22%" id="mcps1.2.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="51.33%" id="mcps1.2.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="15.370000000000001%" headers="mcps1.2.6.1.1 "><p>badgeColor</p>
</td>
<td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.2.6.1.2 "><p>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.46%" headers="mcps1.2.6.1.3 "><p>#fa2a2d</p>
</td>
<td class="cellrowborder" valign="top" width="7.22%" headers="mcps1.2.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="51.33%" headers="mcps1.2.6.1.5 "><p>新事件标记背景色。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="15.370000000000001%" headers="mcps1.2.6.1.1 "><p>textColor</p>
</td>
<td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.2.6.1.2 "><p>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.46%" headers="mcps1.2.6.1.3 "><p>#ffffff</p>
</td>
<td class="cellrowborder" valign="top" width="7.22%" headers="mcps1.2.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="51.33%" headers="mcps1.2.6.1.5 "><p>数字标记的数字文本颜色。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="15.370000000000001%" headers="mcps1.2.6.1.1 "><p>textSize</p>
</td>
<td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.2.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.46%" headers="mcps1.2.6.1.3 "><p>10px</p>
</td>
<td class="cellrowborder" valign="top" width="7.22%" headers="mcps1.2.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="51.33%" headers="mcps1.2.6.1.5 "><p>数字标记的数字文本大小。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="15.370000000000001%" headers="mcps1.2.6.1.1 "><p>badgeSize</p>
</td>
<td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.2.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.46%" headers="mcps1.2.6.1.3 "><p>6px</p>
</td>
<td class="cellrowborder" valign="top" width="7.22%" headers="mcps1.2.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="51.33%" headers="mcps1.2.6.1.5 "><p>圆点标记的默认大小</p>
</td>
</tr>
</tbody>
</table>

## 样式<a name="section5775351116"></a>

支持[通用样式](js-components-common-styles.md)。

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>badge组件的子组件大小不能超过badge组件本身的大小，否则子组件不会绘制。

## 事件<a name="section43461940193518"></a>

支持[通用事件](js-components-common-events.md)。

## 方法<a name="section2279124532420"></a>

支持[通用方法](js-components-common-methods.md)。

## 示例<a name="section3510104413431"></a>

```
<!-- xxx.hml -->
<div class="container">
  <badge class="badge" config="{{badgeconfig}}" visible="true" count="100" maxcount="99">
    <text class="text1">example</text>
  </badge>
  <badge class="badge" visible="true" count="0">
    <text class="text2">example</text>
  </badge>
</div>
```

```
/* xxx.css */
.container {
  flex-direction: column;
  width: 100%;
  align-items: center;
}
.badge {
  width: 50%;
  margin-top: 100px;
}
.text1 {
  background-color: #f9a01e;
  font-size: 50px;
}
.text2 {
  background-color: #46b1e3;
  font-size: 50px;
}
```

```
// xxx.js
export default {
  data:{
    badgeconfig:{
      badgeColor:"#0a59f7",
      textColor:"#ffffff",
    }
  }
}
```

![](figures/捕获.png)

