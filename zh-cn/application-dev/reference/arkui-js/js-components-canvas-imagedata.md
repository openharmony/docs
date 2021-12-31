# ImageData对象<a name="ZH-CN_TOPIC_0000001127125022"></a>

ImageData对象可以存储canvas渲染的像素数据。

## 属性<a name="section661391987"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="22.872287228722872%" id="mcps1.1.4.1.1"><p>属性</p>
</th>
<th class="cellrowborder" valign="top" width="29.352935293529352%" id="mcps1.1.4.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="47.774777477747776%" id="mcps1.1.4.1.3"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="22.872287228722872%" headers="mcps1.1.4.1.1 "><p>width</p>
</td>
<td class="cellrowborder" valign="top" width="29.352935293529352%" headers="mcps1.1.4.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="47.774777477747776%" headers="mcps1.1.4.1.3 "><p>矩形区域实际像素宽度。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="22.872287228722872%" headers="mcps1.1.4.1.1 "><p>height</p>
</td>
<td class="cellrowborder" valign="top" width="29.352935293529352%" headers="mcps1.1.4.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="47.774777477747776%" headers="mcps1.1.4.1.3 "><p>矩形区域实际像素高度。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="22.872287228722872%" headers="mcps1.1.4.1.1 "><p>data</p>
</td>
<td class="cellrowborder" valign="top" width="29.352935293529352%" headers="mcps1.1.4.1.2 "><p>&lt;Uint8ClampedArray&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="47.774777477747776%" headers="mcps1.1.4.1.3 "><p>一维数组，保存了相应的颜色数据，数据值范围为0到255。</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section3302437114813"></a>

```
<!-- xxx.hml -->
<div>
  <canvas ref="canvas" style="width: 500px; height: 500px; background-color: #ffff00;"></canvas>
</div>
```

```
//xxx.js
import prompt from '@system.prompt';
export default {
  onShow() {
    const el =this.$refs.canvas;
    const ctx = el.getContext('2d');
    ctx.fillRect(0,0,200,200)
    var imageData = ctx.createImageData(1,1)
    prompt.showToast({
      message:imageData,
      duration:5000
    })
  }
}
```

