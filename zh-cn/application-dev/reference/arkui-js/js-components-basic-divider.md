# divider<a name="ZH-CN_TOPIC_0000001127125060"></a>

提供分隔器组件，分隔不同内容块/内容元素。可用于列表或界面布局。

## 权限列表<a name="section11257113618419"></a>

无

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
<tbody><tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>vertical</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>使用水平分割线还是垂直分割线，默认水平。</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>不支持focusable、disabled属性。

## 样式<a name="section5775351116"></a>

仅支持如下样式：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="18.209640397857694%" id="mcps1.1.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="14.135424636572303%" id="mcps1.1.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="22.083014537107886%" id="mcps1.1.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="6.7999234889058915%" id="mcps1.1.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="38.77199693955624%" id="mcps1.1.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="18.209640397857694%" headers="mcps1.1.6.1.1 "><p>margin</p>
</td>
<td class="cellrowborder" valign="top" width="14.135424636572303%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="22.083014537107886%" headers="mcps1.1.6.1.3 "><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="6.7999234889058915%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="38.77199693955624%" headers="mcps1.1.6.1.5 "><p>使用简写属性设置所有的外边距属性，该属性可以有1到4个值。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.209640397857694%" headers="mcps1.1.6.1.1 "><p>margin-[left|top|right|bottom]</p>
</td>
<td class="cellrowborder" valign="top" width="14.135424636572303%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="22.083014537107886%" headers="mcps1.1.6.1.3 "><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="6.7999234889058915%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="38.77199693955624%" headers="mcps1.1.6.1.5 "><p>使用简写属性设置左、上、右、下外边距属性，类型length，单位px，默认值0。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.209640397857694%" headers="mcps1.1.6.1.1 "><p>color</p>
</td>
<td class="cellrowborder" valign="top" width="14.135424636572303%" headers="mcps1.1.6.1.2 "><p>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="22.083014537107886%" headers="mcps1.1.6.1.3 "><p>#08000000</p>
</td>
<td class="cellrowborder" valign="top" width="6.7999234889058915%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="38.77199693955624%" headers="mcps1.1.6.1.5 "><p>设置分割线颜色。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.209640397857694%" headers="mcps1.1.6.1.1 "><p>stroke-width</p>
</td>
<td class="cellrowborder" valign="top" width="14.135424636572303%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="22.083014537107886%" headers="mcps1.1.6.1.3 "><p>1</p>
</td>
<td class="cellrowborder" valign="top" width="6.7999234889058915%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="38.77199693955624%" headers="mcps1.1.6.1.5 "><p>设置分割线宽度。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.209640397857694%" headers="mcps1.1.6.1.1 "><p>display</p>
</td>
<td class="cellrowborder" valign="top" width="14.135424636572303%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="22.083014537107886%" headers="mcps1.1.6.1.3 "><p>flex</p>
</td>
<td class="cellrowborder" valign="top" width="6.7999234889058915%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="38.77199693955624%" headers="mcps1.1.6.1.5 "><p>确定分割线所产生的框的类型。值flex/none，默认值flex。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.209640397857694%" headers="mcps1.1.6.1.1 "><p>visibility</p>
</td>
<td class="cellrowborder" valign="top" width="14.135424636572303%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="22.083014537107886%" headers="mcps1.1.6.1.3 "><p>visible</p>
</td>
<td class="cellrowborder" valign="top" width="6.7999234889058915%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="38.77199693955624%" headers="mcps1.1.6.1.5 "><p>是否显示分割线。不可见的框会占用布局。visible代表显示元素，hidden代表不显示元素。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.209640397857694%" headers="mcps1.1.6.1.1 "><p>line-cap</p>
</td>
<td class="cellrowborder" valign="top" width="14.135424636572303%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="22.083014537107886%" headers="mcps1.1.6.1.3 "><p>butt</p>
</td>
<td class="cellrowborder" valign="top" width="6.7999234889058915%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="38.77199693955624%" headers="mcps1.1.6.1.5 "><p>设置分割线条的端点样式，默认为butt，可选值为：</p>
<ul><li>butt：分割线两端为平行线；</li><li>round：分割线两端额外添加半圆；</li><li>square：分割线两端额外添加半方形；</li></ul>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>round和square会额外增加一个线宽的分割线长度。</p>
</div></div>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.209640397857694%" headers="mcps1.1.6.1.1 "><p>flex</p>
</td>
<td class="cellrowborder" valign="top" width="14.135424636572303%" headers="mcps1.1.6.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="22.083014537107886%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="6.7999234889058915%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="38.77199693955624%" headers="mcps1.1.6.1.5 "><p>规定了分割线如何适应父组件中的可用空间。它作为一个简写属性，用来设置组件的flex-grow。</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>仅父容器为&lt;div&gt;、&lt;list-item&gt;、&lt;tabs&gt;时生效。</p>
</div></div>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.209640397857694%" headers="mcps1.1.6.1.1 "><p>flex-grow</p>
</td>
<td class="cellrowborder" valign="top" width="14.135424636572303%" headers="mcps1.1.6.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="22.083014537107886%" headers="mcps1.1.6.1.3 "><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="6.7999234889058915%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="38.77199693955624%" headers="mcps1.1.6.1.5 "><p>设置分割线的伸展因子，指定父组件容器主轴方向上剩余空间（容器本身大小减去所有flex项加起来的大小）的分配系数。0为不伸展。</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>仅父容器为&lt;div&gt;、&lt;list-item&gt;、&lt;tabs&gt;时生效。</p>
</div></div>
<p></p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.209640397857694%" headers="mcps1.1.6.1.1 "><p>flex-shrink</p>
</td>
<td class="cellrowborder" valign="top" width="14.135424636572303%" headers="mcps1.1.6.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="22.083014537107886%" headers="mcps1.1.6.1.3 "><p>1</p>
</td>
<td class="cellrowborder" valign="top" width="6.7999234889058915%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="38.77199693955624%" headers="mcps1.1.6.1.5 "><p>设置分割线的收缩因子，flex元素仅在默认宽度之和大于容器的时候才会发生收缩，0为不收缩。</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>仅父容器为&lt;div&gt;、&lt;list-item&gt;、&lt;tabs&gt;时生效。</p>
</div></div>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.209640397857694%" headers="mcps1.1.6.1.1 "><p>flex-basis</p>
</td>
<td class="cellrowborder" valign="top" width="14.135424636572303%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;</p>
<p></p>
</td>
<td class="cellrowborder" valign="top" width="22.083014537107886%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="6.7999234889058915%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="38.77199693955624%" headers="mcps1.1.6.1.5 "><p>设置分割线在主轴方向上的初始大小。</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>仅父容器为&lt;div&gt;、&lt;list-item&gt;、&lt;tabs&gt;时生效。</p>
</div></div>
</td>
</tr>
</tbody>
</table>

## 事件<a name="section1944813319536"></a>

不支持。

## 方法<a name="section163401342195315"></a>

不支持。

## 示例<a name="section230641814493"></a>

```
<!-- xxx.hml -->
<div class="container">   
  <div class="content">        
    <divider class="divider" vertical="false"></divider>    
  </div>
</div>
```

```
/* xxx.css */
.container {    
  margin: 20px;
  flex-direction:column;
  width:100%;
  height:100%;
  align-items:center;
}
.content{    
  width:80%;
  height:40%;
  border:1px solid #000000;
  align-items: center;
  justify-content: center;
  flex-direction:column;
}
.divider {    
  margin: 10px;
  color: #ff0000ff;
  stroke-width: 3px;
  line-cap: round;
}
```

![](figures/1.jpg)

