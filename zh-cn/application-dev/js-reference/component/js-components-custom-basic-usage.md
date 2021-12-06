# 基本用法<a name="ZH-CN_TOPIC_0000001163932218"></a>

自定义组件是用户根据业务需求，将已有的组件组合，封装成的新组件，可以在工程中多次调用，从而提高代码的可读性。自定义组件通过element引入到宿主页面，使用方法如下：

```
<element name='comp' src='../../common/component/comp.hml'></element>
<div>
  <comp prop1='xxxx' @child1="bindParentVmMethod"></comp>
</div>
```

结合if-else使用自定义组件的示例：

```
<element name='comp1' src='../../common/component/comp1/comp1.hml'></element>
<element name='comp2' src='../../common/component/comp2/comp2.hml'></element>
<div>
  <comp1 if="{{showComp1}}" prop1='xxxx' @child1="bindParentVmMethodOne"></comp1>
  <comp2 else prop1='xxxx' @child1="bindParentVmMethodTwo"></comp2>
</div>
```

-   name属性指自定义组件名称\(非必填\)，组件名称对大小写不敏感，默认使用小写。src属性指自定义组件hml文件路径\(必填\)，若没有设置name属性，则默认使用hml文件名作为组件名。
-   事件绑定：自定义组件中绑定子组件事件使用\(on|@\)child1语法，子组件中通过this.$emit\('child1', \{ params: '传递参数' \}\)触发事件并进行传值，父组件执行bindParentVmMethod方法并接收子组件传递的参数。

    >![](../../public_sys-resources/icon-note.gif) **说明：** 
    >子组件中使用驼峰命名法命名的事件，在父组件中绑定时需要使用短横线分隔命名形式，例如：@children-event表示绑定子组件的childrenEvent事件，如 @children-event="bindParentVmMethod"。


## 对象<a name="zh-cn_topic_0000001127284892_section7681164881014"></a>

<a name="zh-cn_topic_0000001127284892_table67211828124016"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001127284892_row108577289405"><th class="cellrowborder" valign="top" width="11.091109110911091%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001127284892_p385742814403"><a name="zh-cn_topic_0000001127284892_p385742814403"></a><a name="zh-cn_topic_0000001127284892_p385742814403"></a>属性</p>
</th>
<th class="cellrowborder" valign="top" width="12.96129612961296%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001127284892_p19857192816408"><a name="zh-cn_topic_0000001127284892_p19857192816408"></a><a name="zh-cn_topic_0000001127284892_p19857192816408"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="75.94759475947595%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001127284892_p18573288402"><a name="zh-cn_topic_0000001127284892_p18573288402"></a><a name="zh-cn_topic_0000001127284892_p18573288402"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001127284892_row1085792824019"><td class="cellrowborder" valign="top" width="11.091109110911091%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001127284892_p115421323762"><a name="zh-cn_topic_0000001127284892_p115421323762"></a><a name="zh-cn_topic_0000001127284892_p115421323762"></a>data</p>
</td>
<td class="cellrowborder" valign="top" width="12.96129612961296%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001127284892_p05120283516"><a name="zh-cn_topic_0000001127284892_p05120283516"></a><a name="zh-cn_topic_0000001127284892_p05120283516"></a>Object/Function</p>
</td>
<td class="cellrowborder" valign="top" width="75.94759475947595%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001127284892_p105644412409"><a name="zh-cn_topic_0000001127284892_p105644412409"></a><a name="zh-cn_topic_0000001127284892_p105644412409"></a>页面的数据模型，类型是对象或者函数，如果类型是函数，返回值必须是对象。属性名不能以$或_开头，不要使用保留字for, if, show, tid。</p>
<p id="zh-cn_topic_0000001127284892_p356184410403"><a name="zh-cn_topic_0000001127284892_p356184410403"></a><a name="zh-cn_topic_0000001127284892_p356184410403"></a>data与private和public不能重合使用。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127284892_row3857132812406"><td class="cellrowborder" valign="top" width="11.091109110911091%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001127284892_p88572283404"><a name="zh-cn_topic_0000001127284892_p88572283404"></a><a name="zh-cn_topic_0000001127284892_p88572283404"></a>props</p>
</td>
<td class="cellrowborder" valign="top" width="12.96129612961296%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001127284892_p198571828114017"><a name="zh-cn_topic_0000001127284892_p198571828114017"></a><a name="zh-cn_topic_0000001127284892_p198571828114017"></a>Array/Object</p>
</td>
<td class="cellrowborder" valign="top" width="75.94759475947595%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001127284892_p3857192844012"><a name="zh-cn_topic_0000001127284892_p3857192844012"></a><a name="zh-cn_topic_0000001127284892_p3857192844012"></a>props用于组件之间的通信，可以通过&lt;tag xxxx='value'&gt;方式传递给组件；props名称必须用小写，不能以$或_开头，不要使用保留字for, if, show, tid。目前props的数据类型不支持Function。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127284892_row8842155461510"><td class="cellrowborder" valign="top" width="11.091109110911091%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001127284892_p17843155411153"><a name="zh-cn_topic_0000001127284892_p17843155411153"></a><a name="zh-cn_topic_0000001127284892_p17843155411153"></a>computed</p>
</td>
<td class="cellrowborder" valign="top" width="12.96129612961296%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001127284892_p1884365421515"><a name="zh-cn_topic_0000001127284892_p1884365421515"></a><a name="zh-cn_topic_0000001127284892_p1884365421515"></a>Object</p>
</td>
<td class="cellrowborder" valign="top" width="75.94759475947595%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001127284892_p6422712153413"><a name="zh-cn_topic_0000001127284892_p6422712153413"></a><a name="zh-cn_topic_0000001127284892_p6422712153413"></a>用于在读取或设置进行预先处理，计算属性的结果会被缓存。计算属性名不能以$或_开头，不要使用保留字。</p>
</td>
</tr>
</tbody>
</table>

