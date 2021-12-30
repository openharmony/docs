# image<a name="ZH-CN_TOPIC_0000001173164699"></a>

图片组件，用来渲染展示图片。

## 子组件<a name="section9288143101012"></a>

不支持。

## 属性<a name="section2907183951110"></a>

除支持[通用属性](js-components-common-attributes.md)外，还支持如下属性：

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
<tbody><tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>src</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p><span>图片的路径，支持本地路径，图片格式包括png、jpg、bmp、svg和gif。</span></p>
<p>支持Base64字符串<sup><span>6+</span></sup>。格式为data:image/[png | jpeg | bmp | webp];base64, [base64 data], 其中[base64 data]为Base64字符串数据。</p>
<p>支持dataability://的路径前缀，用于访问通过data ability提供的图片路径<sup><span>6+</span></sup>。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>alt</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>占位图，当指定图片在加载中时显示。</p>
</td>
</tr>
</tbody>
</table>

## 样式<a name="section45171131134215"></a>

除支持[通用样式](js-components-common-styles.md)外，还支持如下属性：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="23.16768323167683%" id="mcps1.1.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="20.427957204279572%" id="mcps1.1.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.869113088691131%" id="mcps1.1.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.519248075192481%" id="mcps1.1.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="40.01599840015999%" id="mcps1.1.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="23.16768323167683%" headers="mcps1.1.6.1.1 "><p>object-fit</p>
</td>
<td class="cellrowborder" valign="top" width="20.427957204279572%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p>cover</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>设置图片的缩放类型。可选值类型说明请见<a href="#table175851535113711">object-fit 类型说明</a>。（不支持svg格式）</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.16768323167683%" headers="mcps1.1.6.1.1 "><p>match-text-direction</p>
</td>
<td class="cellrowborder" valign="top" width="20.427957204279572%" headers="mcps1.1.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>图片是否跟随文字方向。（不支持svg格式）</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.16768323167683%" headers="mcps1.1.6.1.1 "><p>fit-original-size</p>
</td>
<td class="cellrowborder" valign="top" width="20.427957204279572%" headers="mcps1.1.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>image组件在未设置宽高的情况下是否适应图源尺寸（该属性为true时object-fit属性不生效），svg类型图源不支持该属性。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.16768323167683%" headers="mcps1.1.6.1.1 "><p>object-position<sup>7+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.427957204279572%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p>0px 0px</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>设置图片在组件内展示的位置。</p>
<p>设置类型有两种：</p>
<p>1. 像素，单位px，示例 15px 15px 代表X轴或者Y轴移动的位置</p>
<p>2. 字符，可选值：</p>
<ul><li>left 图片显示在组件左侧；</li><li>top 图片显示在组件顶部位置；</li><li>right 图片显示在组件右侧位置；</li><li>bottom图片显示在组件底部位置。</li></ul>
</td>
</tr>
</tbody>
</table>

**表 1**  object-fit 类型说明

<a name="table175851535113711"></a>
<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="15.02%" id="mcps1.2.3.1.1"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="84.98%" id="mcps1.2.3.1.2"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.2.3.1.1 "><p>cover</p>
</td>
<td class="cellrowborder" valign="top" width="84.98%" headers="mcps1.2.3.1.2 "><p>保持宽高比进行缩小或者放大，使得图片两边都大于或等于显示边界，居中显示。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.2.3.1.1 "><p>contain</p>
</td>
<td class="cellrowborder" valign="top" width="84.98%" headers="mcps1.2.3.1.2 "><p>保持宽高比进行缩小或者放大，使得图片完全显示在显示边界内，居中显示。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.2.3.1.1 "><p>fill</p>
</td>
<td class="cellrowborder" valign="top" width="84.98%" headers="mcps1.2.3.1.2 "><p>不保持宽高比进行放大缩小，使得图片填充满显示边界。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.2.3.1.1 "><p>none</p>
</td>
<td class="cellrowborder" valign="top" width="84.98%" headers="mcps1.2.3.1.2 "><p>保持原有尺寸进行居中显示。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.2.3.1.1 "><p>scale-down</p>
</td>
<td class="cellrowborder" valign="top" width="84.98%" headers="mcps1.2.3.1.2 "><p>保持宽高比居中显示，图片缩小或者保持不变。</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>使用svg图片资源时：
>-   建议设置image组件的长宽，否则在父组件的长或宽为无穷大的场景下，svg资源将不会绘制；
>-   如果svg描述中未指定相应的长宽，则svg将会填满image组件区域；
>-   如果svg描述中指定了相应的长宽，和image组件本身的长宽效果如下：
>1.  如果image组件本身的长宽小于svg中的长宽，svg会被裁切，仅显示左上角部分；
>2.  如果image组件本身的长宽大于svg中的长宽，svg会被放置在image组件的左上角，image组件其他部分显示空白。

## 事件<a name="section3892191911214"></a>

除支持[通用事件](js-components-common-events.md)外，还支持如下事件：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="24.91249124912491%" id="mcps1.1.4.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="29.492949294929495%" id="mcps1.1.4.1.2"><p>参数</p>
</th>
<th class="cellrowborder" valign="top" width="45.5945594559456%" id="mcps1.1.4.1.3"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="24.91249124912491%" headers="mcps1.1.4.1.1 "><p>complete(Rich)</p>
</td>
<td class="cellrowborder" valign="top" width="29.492949294929495%" headers="mcps1.1.4.1.2 "><p>{ width：width， height：height }</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p>图片成功加载时触发该回调，返回成功加载的图源尺寸。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="24.91249124912491%" headers="mcps1.1.4.1.1 "><p>error(Rich)</p>
</td>
<td class="cellrowborder" valign="top" width="29.492949294929495%" headers="mcps1.1.4.1.2 "><p>{ width：width， height：height }</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p>图片加载出现异常时触发该回调，异常时长宽为零。</p>
</td>
</tr>
</tbody>
</table>

## 方法<a name="section2279124532420"></a>

支持[通用方法](js-components-common-methods.md)。

## 示例<a name="section321147145519"></a>

```
<!-- xxx.hml -->
<div class="container">
  <image src="common/images/hw_right.png" style="width: 300px; height: 300px; object-fit:{{fit}}; object-position: center center; border: 1px solid red; ">
  </image>
  <select class="selects" onchange="change_fit">
    <option for="{{fits}}" value="{{$item}}">{{$item}}</option>
  </select>
</div>
```

```
/* xxx.css */
.container {
  justify-content: center;
  align-items: center;
  flex-direction: column;
  
  
}
.selects{
  margin-top: 20px;
  width:300px;
  border:1px solid #808080;
  border-radius: 10px;
}
```

```
// xxx.js
export default {
  data: {
    fit:"cover",
    fits: ["cover", "contain", "fill", "none", "scale-down"],
  },
  change_fit(e) {
    this.fit = e.newValue;
  },
}
```

![](figures/GIF.gif)

