# stepper-item<a name="ZH-CN_TOPIC_0000001127125034"></a>

步骤导航器子组件，作为步骤导航器某一个步骤的内容展示组件。

## 权限列表<a name="section11257113618419"></a>

无

## 子组件<a name="section9288143101012"></a>

支持。

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
<tbody><tr><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p>label</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p><a href="#table119681501422">Label</a></p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p>自定义步骤导航器底部步骤提示文本按钮属性，不支持动态修改。如果没有定义该属性，步骤导航器在中文语言环境下，使用“返回”和“下一步”文本按钮，在非中文语言环境下，使用“BACK”和“NEXT”文本按钮。针对第一个步骤，没有回退文本按钮，针对最后一个步骤，下一步文本按钮文本使用“开始”（中文语言）或者“START”（非中文语言）。</p>
</td>
</tr>
</tbody>
</table>

**表 1**  Label对象定义

<a name="table119681501422"></a>
<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="11.06%" id="mcps1.2.5.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="9.08%" id="mcps1.2.5.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.450000000000001%" id="mcps1.2.5.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="71.41%" id="mcps1.2.5.1.4"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="11.06%" headers="mcps1.2.5.1.1 "><p>prevLabel</p>
</td>
<td class="cellrowborder" valign="top" width="9.08%" headers="mcps1.2.5.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.450000000000001%" headers="mcps1.2.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="71.41%" headers="mcps1.2.5.1.4 "><p>步骤导航器底部回退文本按钮的描述文本。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="11.06%" headers="mcps1.2.5.1.1 "><p>nextLabel</p>
</td>
<td class="cellrowborder" valign="top" width="9.08%" headers="mcps1.2.5.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.450000000000001%" headers="mcps1.2.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="71.41%" headers="mcps1.2.5.1.4 "><p>步骤导航器底部下一步文本按钮的描述文本。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="11.06%" headers="mcps1.2.5.1.1 "><p>status</p>
</td>
<td class="cellrowborder" valign="top" width="9.08%" headers="mcps1.2.5.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.450000000000001%" headers="mcps1.2.5.1.3 "><p>normal</p>
</td>
<td class="cellrowborder" valign="top" width="71.41%" headers="mcps1.2.5.1.4 "><p>步骤导航器当前步骤的初始状态，可选值为：</p>
<ul><li>normal：正常状态，右侧文本按钮正常显示，可点击进入下一个步骤。</li></ul>
<ul><li>disabled：不可用状态，右侧文本按钮灰度显示，不可点击进入下一个步骤。</li></ul>
<ul><li>waiting：等待状态，右侧文本按钮不显示，使用等待进度条，不可点击进入下一个步骤。</li></ul>
</td>
</tr>
</tbody>
</table>

## 样式<a name="section1326042123512"></a>

除支持[通用样式](js-components-common-styles.md)外，还支持如下样式：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="23.11768823117688%" id="mcps1.1.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="20.477952204779523%" id="mcps1.1.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.869113088691131%" id="mcps1.1.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.519248075192481%" id="mcps1.1.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="40.01599840015999%" id="mcps1.1.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>color</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>文本颜色。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>font-size</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>文本大小。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>allow-scale</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p>true</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>文本尺寸是否跟随系统设置字体缩放尺寸进行放大缩小。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>font-style</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p>normal</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>文本字体样式，可选值为：</p>
<ul><li>normal: 标准的字体样式；</li><li>italic: 斜体的字体样式。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>font-weight</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p>number|string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p>normal</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>文本字体粗细，number类型取值[100, 900]的整数（被100整除），默认为400，取值越大，字体越粗。string类型取值为：lighter、normal、bold、bolder。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>text-decoration</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p>none</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>文本修饰，可选值为：</p>
<ul><li>underline: 文本下划线修饰。</li><li>line-through: 穿过文本的修饰线。</li><li>none: 标准文本。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p>font-family</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p>sans-serif</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p>字体列表，用逗号分隔，每个字体用字体名或者字体族名设置。列表中第一个系统中存在的或者通过<a href="js-components-common-customizing-font.md">自定义字体</a>指定的字体，会被选中作为文本的字体。</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>-   不支持长宽样式，宽和父容器stepper一样，高是父容器stepper减去底部导航按钮的高度。
>-   不支持posit样式。

## 事件<a name="section121081858163714"></a>

除支持[通用事件](js-components-common-events.md)外，还支持如下事件：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="24.852485248524854%" id="mcps1.1.4.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="29.552955295529554%" id="mcps1.1.4.1.2"><p>参数</p>
</th>
<th class="cellrowborder" valign="top" width="45.5945594559456%" id="mcps1.1.4.1.3"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p>appear</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p>当该步骤出现时触发。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p>disappear</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p>当该步骤消失时触发。</p>
</td>
</tr>
</tbody>
</table>

## 方法<a name="section2279124532420"></a>

不支持[通用方法](js-components-common-methods.md)。

## 示例<a name="section10326712123215"></a>

详见[stepper示例](js-components-container-stepper.md)。

