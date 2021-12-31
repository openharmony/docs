# popup<a name="ZH-CN_TOPIC_0000001127284822"></a>

气泡指示。在点击绑定的控件后会弹出相应的气泡提示来引导用户进行操作。

## 权限列表<a name="section11257113618419"></a>

无

## 子组件<a name="s726c642d8f514b0cb5ef8854fe6ac02c"></a>

支持单个子组件节点<sup>5+</sup>。

## 属性<a name="s7ff9da9346504b11aca7015dc689dc67"></a>

除支持[通用属性](js-components-common-attributes.md)外，还支持如下属性：↵

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
<tbody><tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>target</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>是</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>目标元素的id属性值，不支持动态切换。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>placement</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>bottom</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>弹出窗口位置。可选值为：</p>
<ul><li>left：位于目标元素左边；</li><li>right：位于目标元素右边；</li><li>top：位于目标元素上边；</li><li>bottom：位于目标元素下边；</li><li>topLeft：位于目标元素左上角；</li><li>topRight：位于目标元素右上角；</li><li>bottomLeft：位于目标元素左下角；</li><li>bottomRight：位于目标元素右下角。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>keepalive<sup><span>5+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>设置当前popup是否需要保留。设置为true时，点击屏幕区域或者页面切换气泡不会消失，需调用气泡组件的hide方法才可让气泡消失；设置为false时，点击屏幕区域或者页面切换气泡会自动消失。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>clickable<sup><span>5+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>true</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>popup是否使用点击弹窗，当设置为false时，只支持方法调用显示。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>arrowoffset<sup><span>5+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>popup箭头在弹窗处的偏移，默认居中，正值按照语言方向进行偏移，负值相反。</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>-   不支持focusable属性。

## 样式<a name="s472a5052130e49bca059adfe7bb6b96d"></a>

除支持[通用样式](js-components-common-styles.md)外，还支持如下样式：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="12.688731126887312%" id="mcps1.1.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="10.47895210478952%" id="mcps1.1.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.60913908609139%" id="mcps1.1.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="6.28937106289371%" id="mcps1.1.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="61.933806619338064%" id="mcps1.1.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="12.688731126887312%" headers="mcps1.1.6.1.1 "><p>mask-color</p>
</td>
<td class="cellrowborder" valign="top" width="10.47895210478952%" headers="mcps1.1.6.1.2 "><p>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.60913908609139%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="6.28937106289371%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="61.933806619338064%" headers="mcps1.1.6.1.5 "><p>遮罩层的颜色，默认值为全透明。</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>-   不支持position相关样式。

## 事件<a name="section1295913853210"></a>

除支持[通用事件](js-components-common-events.md)外，还支持如下事件：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="24.852485248524854%" id="mcps1.1.4.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="29.552955295529554%" id="mcps1.1.4.1.2"><p>参数</p>
</th>
<th class="cellrowborder" valign="top" width="45.5945594559456%" id="mcps1.1.4.1.3"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p>visibilitychange</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p>{ visibility: boolean }</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p>当气泡弹出和消失时会触发该回调函数。</p>
</td>
</tr>
</tbody>
</table>

## 方法<a name="section1970516568131"></a>

仅支持如下方法：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="18.459999999999997%" id="mcps1.1.4.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="30.769999999999996%" id="mcps1.1.4.1.2"><p>参数</p>
</th>
<th class="cellrowborder" valign="top" width="50.77%" id="mcps1.1.4.1.3"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="18.459999999999997%" headers="mcps1.1.4.1.1 "><p>show<sup><span>5+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="30.769999999999996%" headers="mcps1.1.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.1.4.1.3 "><p>弹出气泡提示。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.459999999999997%" headers="mcps1.1.4.1.1 "><p>hide<sup>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="30.769999999999996%" headers="mcps1.1.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.1.4.1.3 "><p>取消气泡提示。</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>1.  popup气泡弹窗属性、样式均不支持动态更新。
>2.  popup气泡弹窗的margin样式是相对于target元素进行生效的，如popup在target元素下方，此时只生效margin-top样式，popup在target元素左上方，此时只生效margin-bottom和margin-right样式。
>3.  popup的border四边样式需一致，若四边设置不一致且圆角为零，则按左、上、右、下的顺序取第一个被设置的样式，否则border不生效。
>4.  popup的target组件的click事件不生效。

## 示例<a name="section29231018162418"></a>

```
<!-- xxx.hml -->
<div class="container">
  <text id="text">Click to show the pop-up</text>
  <!-- popup supports single child of any type5+ -->
  <popup id="popup" class="popup" target="text" placement="top" keepalive="true" clickable="true" 
    arrowoffset="100px" onvisibilitychange="visibilitychange" onclick="hidepopup">
    <text class="text">Text content of the pop-up</text>
  </popup>
  <button class="button" onclick="showpopup">Click to show the pop-up</button>
</div>
```

```
/* xxx.css */
.container {
  flex-direction: column;
  align-items: center;
  padding-top: 200px;
}
.popup {
  mask-color: gray;
}
.text {
  color: white;
}
.button {
  width: 220px;
  height: 70px;
  margin-top: 50px;
}
```

```
// xxx.js
import prompt from '@system.prompt'
export default {
  visibilitychange(e) {
    prompt.showToast({
      message: 'visibility change visibility: ' + e.visibility,
        duration: 3000,
    }); 
  },
  showpopup() {
    this.$element("popup").show();
  },
  hidepopup() {
    this.$element("popup").hide();
  },
}
```

![](figures/zh-cn_image_0000001178886129.png)

