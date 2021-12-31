# 通用属性<a name="ZH-CN_TOPIC_0000001173324641"></a>

## 常规属性<a name="section861395713012"></a>

常规属性指的是组件普遍支持的用来设置组件基本标识和外观显示特征的属性。

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="19.598040195980403%" id="mcps1.1.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="11.178882111788822%" id="mcps1.1.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.899010098990102%" id="mcps1.1.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.56924307569243%" id="mcps1.1.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="51.754824517548236%" id="mcps1.1.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="19.598040195980403%" headers="mcps1.1.6.1.1 "><p>id</p>
</td>
<td class="cellrowborder" valign="top" width="11.178882111788822%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.899010098990102%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.56924307569243%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="51.754824517548236%" headers="mcps1.1.6.1.5 "><p>组件的唯一标识。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="19.598040195980403%" headers="mcps1.1.6.1.1 "><p>style</p>
</td>
<td class="cellrowborder" valign="top" width="11.178882111788822%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.899010098990102%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.56924307569243%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="51.754824517548236%" headers="mcps1.1.6.1.5 "><p>组件的样式声明。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="19.598040195980403%" headers="mcps1.1.6.1.1 "><p>class</p>
</td>
<td class="cellrowborder" valign="top" width="11.178882111788822%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.899010098990102%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.56924307569243%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="51.754824517548236%" headers="mcps1.1.6.1.5 "><p>组件的样式类，用于引用样式表。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="19.598040195980403%" headers="mcps1.1.6.1.1 "><p>ref</p>
</td>
<td class="cellrowborder" valign="top" width="11.178882111788822%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.899010098990102%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.56924307569243%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="51.754824517548236%" headers="mcps1.1.6.1.5 "><p>用来指定指向子元素<span>或子组件</span>的引用信息，该引用将注册到父组件的$refs 属性对象上。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="19.598040195980403%" headers="mcps1.1.6.1.1 "><p>disabled</p>
</td>
<td class="cellrowborder" valign="top" width="11.178882111788822%" headers="mcps1.1.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="9.899010098990102%" headers="mcps1.1.6.1.3 "><p>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.56924307569243%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="51.754824517548236%" headers="mcps1.1.6.1.5 "><p>当前组件是否被禁用，在禁用场景下，组件将无法响应用户交互。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="19.598040195980403%" headers="mcps1.1.6.1.1 "><p>data</p>
</td>
<td class="cellrowborder" valign="top" width="11.178882111788822%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.899010098990102%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.56924307569243%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="51.754824517548236%" headers="mcps1.1.6.1.5 "><p>给当前组件设置data属性，进行相应的数据存储和读取。JS文件中：</p>
<ul><li>在事件回调中使用 e.target.attr.data 读取数据，e为事件回调函数入参。</li><li>使用$element或者$refs获取DOM元素后，通过attr.data 进行访问。</li></ul>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>从API Version 6 开始，建议使用data-*。</p>
</div></div>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="19.598040195980403%" headers="mcps1.1.6.1.1 "><p>data-*<sup>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="11.178882111788822%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.899010098990102%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.56924307569243%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="51.754824517548236%" headers="mcps1.1.6.1.5 "><p>给当前组件设置data-*属性，进行相应的数据存储和读取。大小写不敏感，如data-A和data-a默认相同。JS文件中：</p>
<ul><li>在事件回调中使用 e.target.dataSet.a读取数据，e为事件回调函数入参。</li><li>使用$element或者$refs获取DOM元素后，通过dataSet.a进行访问。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="19.598040195980403%" headers="mcps1.1.6.1.1 "><p>click-effect<sup>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="11.178882111788822%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.899010098990102%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.56924307569243%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="51.754824517548236%" headers="mcps1.1.6.1.5 "><p>通过这个属性可以设置组件的弹性点击效果，当前支持如下三种效果：</p>
<ul><li>spring-small：建议小面积组件设置，缩放(90%)。</li><li>spring-medium：建议中面积组件设置，缩放(95%)。</li><li>spring-large：建议大面积组件设置，缩放(95%)。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="19.598040195980403%" headers="mcps1.1.6.1.1 "><p>dir<sup><span>6+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="11.178882111788822%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.899010098990102%" headers="mcps1.1.6.1.3 "><p>auto</p>
</td>
<td class="cellrowborder" valign="top" width="7.56924307569243%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="51.754824517548236%" headers="mcps1.1.6.1.5 "><p>设置元素布局模式，支持设置rtl、ltr和auto三种属性值：</p>
<ul><li>rtl：使用从右往左布局模式。</li><li>ltr：使用从左往右布局模式。</li><li>auto：跟随系统语言环境。</li></ul>
</td>
</tr>
</tbody>
</table>

## 渲染属性<a name="section1894362211119"></a>

组件普遍支持的用来设置组件是否渲染的属性。

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="11%" id="mcps1.1.5.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="13%" id="mcps1.1.5.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="59%" id="mcps1.1.5.1.4"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="11%" headers="mcps1.1.5.1.1 "><p>for</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p>Array</p>
</td>
<td class="cellrowborder" valign="top" width="13%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="59%" headers="mcps1.1.5.1.4 "><p>根据设置的数据列表，展开当前元素。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="11%" headers="mcps1.1.5.1.1 "><p>if</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="13%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="59%" headers="mcps1.1.5.1.4 "><p>根据设置的boolean值，添加或移除当前元素。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="11%" headers="mcps1.1.5.1.1 "><p>show</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="13%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="59%" headers="mcps1.1.5.1.4 "><p>根据设置的boolean值，显示或隐藏当前元素。</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>属性和样式不能混用，不能在属性字段中进行样式设置。

