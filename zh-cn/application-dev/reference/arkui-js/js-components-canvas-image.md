# Image对象<a name="ZH-CN_TOPIC_0000001173164737"></a>

图片对象。

## 属性<a name="section1968021961113"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="21.8%" id="mcps1.1.6.1.1"><p>属性</p>
</th>
<th class="cellrowborder" valign="top" width="22.34%" id="mcps1.1.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="7.9799999999999995%" id="mcps1.1.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="11.73%" id="mcps1.1.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="36.15%" id="mcps1.1.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="21.8%" headers="mcps1.1.6.1.1 "><p>src</p>
</td>
<td class="cellrowborder" valign="top" width="22.34%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="7.9799999999999995%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="11.73%" headers="mcps1.1.6.1.4 "><p>是</p>
</td>
<td class="cellrowborder" valign="top" width="36.15%" headers="mcps1.1.6.1.5 "><p>图片资源的路径。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="21.8%" headers="mcps1.1.6.1.1 "><p>width</p>
</td>
<td class="cellrowborder" valign="top" width="22.34%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="7.9799999999999995%" headers="mcps1.1.6.1.3 "><p>0px</p>
</td>
<td class="cellrowborder" valign="top" width="11.73%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="36.15%" headers="mcps1.1.6.1.5 "><p>图片的宽度。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="21.8%" headers="mcps1.1.6.1.1 "><p>height</p>
</td>
<td class="cellrowborder" valign="top" width="22.34%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="7.9799999999999995%" headers="mcps1.1.6.1.3 "><p>0px</p>
</td>
<td class="cellrowborder" valign="top" width="11.73%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="36.15%" headers="mcps1.1.6.1.5 "><p>图片的高度。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="21.8%" headers="mcps1.1.6.1.1 "><p>onload</p>
</td>
<td class="cellrowborder" valign="top" width="22.34%" headers="mcps1.1.6.1.2 "><p>Function</p>
</td>
<td class="cellrowborder" valign="top" width="7.9799999999999995%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="11.73%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="36.15%" headers="mcps1.1.6.1.5 "><p>图片加载成功后触发该事件，无参数。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="21.8%" headers="mcps1.1.6.1.1 "><p>onerror</p>
</td>
<td class="cellrowborder" valign="top" width="22.34%" headers="mcps1.1.6.1.2 "><p>Function</p>
</td>
<td class="cellrowborder" valign="top" width="7.9799999999999995%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="11.73%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="36.15%" headers="mcps1.1.6.1.5 "><p>图片加载失败后触发该事件，无参数。</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section13457717134912"></a>

```
<!-- xxx.hml -->
<div>
  <canvas ref="canvas" style="width: 500px; height: 500px; "></canvas>
</div>
```

```
//xxx.js
export default {
  onShow(){
    const el =this.$refs.canvas
    var ctx =el.getContext('2d');  
    var img = new Image();
    img.src = 'common/images/example.jpg';
    img.onload = function() {
    console.log('Image load success');
    ctx.drawImage(img, 0, 0, 360, 250);
   };
    img.onerror = function() {
    console.log('Image load fail');
    };
  }
}
```

![](figures/1-2.png)

