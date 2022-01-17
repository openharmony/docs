# rating<a name="ZH-CN_TOPIC_0000001173324645"></a>

评分条，表示用户使用感受的衡量标准条。

## 权限列表<a name="section11257113618419"></a>

无

## 子组件<a name="section9288143101012"></a>

不支持。

## 属性<a name="section2907183951110"></a>

除支持[通用属性](js-components-common-attributes.md)外，还支持如下属性：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="23.18%" id="mcps1.1.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="13.66%" id="mcps1.1.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.46%" id="mcps1.1.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="9.22%" id="mcps1.1.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="44.48%" id="mcps1.1.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="23.18%" headers="mcps1.1.6.1.1 "><p>numstars</p>
</td>
<td class="cellrowborder" valign="top" width="13.66%" headers="mcps1.1.6.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.46%" headers="mcps1.1.6.1.3 "><p>5</p>
</td>
<td class="cellrowborder" valign="top" width="9.22%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="44.48%" headers="mcps1.1.6.1.5 "><p>设置评分条的星级总数。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.18%" headers="mcps1.1.6.1.1 "><p>rating</p>
</td>
<td class="cellrowborder" valign="top" width="13.66%" headers="mcps1.1.6.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.46%" headers="mcps1.1.6.1.3 "><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="9.22%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="44.48%" headers="mcps1.1.6.1.5 "><p>设置评分条当前评星数。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.18%" headers="mcps1.1.6.1.1 "><p>stepsize</p>
</td>
<td class="cellrowborder" valign="top" width="13.66%" headers="mcps1.1.6.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.46%" headers="mcps1.1.6.1.3 "><p>0.5</p>
</td>
<td class="cellrowborder" valign="top" width="9.22%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="44.48%" headers="mcps1.1.6.1.5 "><p>设置评分条的评星步长。</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>仅手机和平板设备支持</p>
</div></div>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.18%" headers="mcps1.1.6.1.1 "><p>indicator</p>
</td>
<td class="cellrowborder" valign="top" width="13.66%" headers="mcps1.1.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="9.46%" headers="mcps1.1.6.1.3 "><p>false</p>
</td>
<td class="cellrowborder" valign="top" width="9.22%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="44.48%" headers="mcps1.1.6.1.5 "><p>设置评分条是否作为一个指示器，此时用户不可操作。</p>
</td>
</tr>
</tbody>
</table>

## 样式<a name="section5775351116"></a>

除支持[通用样式](js-components-common-styles.md)外，还支持如下样式：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="20.71792820717928%" id="mcps1.1.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="20.80791920807919%" id="mcps1.1.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.93890610938906%" id="mcps1.1.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.519248075192481%" id="mcps1.1.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="40.01599840015999%" id="mcps1.1.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="20.71792820717928%" headers="mcps1.1.6.1.1 "><p>star-background</p>
</td>
<td class="cellrowborder" valign="top" width="20.80791920807919%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.93890610938906%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>设置单个星级未选中的背景图片，只支持本地路径图片，图片格式为png和jpg。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="20.71792820717928%" headers="mcps1.1.6.1.1 "><p>star-foreground</p>
</td>
<td class="cellrowborder" valign="top" width="20.80791920807919%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.93890610938906%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>设置单个星级选中的前景图片，只支持本地路径图片，图片格式为png和jpg。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="20.71792820717928%" headers="mcps1.1.6.1.1 "><p>star-secondary</p>
</td>
<td class="cellrowborder" valign="top" width="20.80791920807919%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.93890610938906%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>设置单个星级部分选中的次级背景图片，该图片会覆盖背景图片，只支持本地路径图片，图片格式为png和jpg。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="20.71792820717928%" headers="mcps1.1.6.1.1 "><p>width</p>
</td>
<td class="cellrowborder" valign="top" width="20.80791920807919%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;|&lt;percentage&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.93890610938906%" headers="mcps1.1.6.1.3 "><p>120px</p>
<p>60px（不可操作）</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>默认值是在未设置自定义资源和评分星数时，使用5个星和默认资源下的宽度值。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="20.71792820717928%" headers="mcps1.1.6.1.1 "><p>height</p>
</td>
<td class="cellrowborder" valign="top" width="20.80791920807919%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;|&lt;percentage&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.93890610938906%" headers="mcps1.1.6.1.3 "><p>24px</p>
<p>12px（不可操作）</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>默认值是在未设置自定义资源和评分星数时，使用5个星和默认资源下的高度值。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="20.71792820717928%" headers="mcps1.1.6.1.1 "><p>rtl-flip</p>
</td>
<td class="cellrowborder" valign="top" width="20.80791920807919%" headers="mcps1.1.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.93890610938906%" headers="mcps1.1.6.1.3 "><p>true</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>在RTL文字方向下是否自动翻转图源。</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>star-background，star-secondary，star-foreground三个星级图源必须全部设置，否则默认的星级颜色为灰色，以此提示图源设置错误。

## 事件<a name="section124498406719"></a>

除支持[通用事件](js-components-common-events.md)外，还支持如下事件：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="24.852485248524854%" id="mcps1.1.4.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="22.48224822482248%" id="mcps1.1.4.1.2"><p>参数</p>
</th>
<th class="cellrowborder" valign="top" width="52.665266526652665%" id="mcps1.1.4.1.3"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p>change</p>
</td>
<td class="cellrowborder" valign="top" width="22.48224822482248%" headers="mcps1.1.4.1.2 "><p>{ rating:  number }</p>
</td>
<td class="cellrowborder" valign="top" width="52.665266526652665%" headers="mcps1.1.4.1.3 "><p>评分条的评星发生改变时触发该回调。</p>
</td>
</tr>
</tbody>
</table>

## 方法<a name="section2279124532420"></a>

支持[通用方法](js-components-common-methods.md)。

## 示例<a name="section1715414253487"></a>

```
<!-- xxx.hml -->
<div class="container">
  <rating numstars="5" rating="5" @change="changeRating" id="rating">
  </rating>
</div>
```

```
/* xxx.css */
.container {
  display: flex;
  justify-content: center;
  align-items: center;
}
rating {
  width: 200px;
}
```

```
// xxx.js
import prompt from '@system.prompt';
export default {
    changeRating(e){
        prompt.showToast({
            message: e.rating
        });
    }
}
```

![](figures/zh-cn_image_0000001198670487.png)

