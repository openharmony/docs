# 基本用法<a name="ZH-CN_TOPIC_0000001127284892"></a>

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


**表 1**  对象

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="11.091109110911091%" id="mcps1.2.4.1.1"><p>属性</p>
</th>
<th class="cellrowborder" valign="top" width="18.02180218021802%" id="mcps1.2.4.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="70.88708870887088%" id="mcps1.2.4.1.3"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="11.091109110911091%" headers="mcps1.2.4.1.1 "><p>data</p>
</td>
<td class="cellrowborder" valign="top" width="18.02180218021802%" headers="mcps1.2.4.1.2 "><p>Object/Function</p>
</td>
<td class="cellrowborder" valign="top" width="70.88708870887088%" headers="mcps1.2.4.1.3 "><p>页面的数据模型，类型是对象或者函数，如果类型是函数，返回值必须是对象。属性名不能以$或_开头，不要使用保留字for, if, show, tid。</p>
<p>data与private和public不能重合使用。(Rich)</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="11.091109110911091%" headers="mcps1.2.4.1.1 "><p>props</p>
</td>
<td class="cellrowborder" valign="top" width="18.02180218021802%" headers="mcps1.2.4.1.2 "><p>Array/Object</p>
</td>
<td class="cellrowborder" valign="top" width="70.88708870887088%" headers="mcps1.2.4.1.3 "><p>props用于组件之间的通信，可以通过&lt;tag xxxx='value'&gt;方式传递给组件；props名称必须用小写，不能以$或_开头，不要使用保留字for, if, show, tid。目前props的数据类型不支持Function。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="11.091109110911091%" headers="mcps1.2.4.1.1 "><p>computed</p>
</td>
<td class="cellrowborder" valign="top" width="18.02180218021802%" headers="mcps1.2.4.1.2 "><p>Object</p>
</td>
<td class="cellrowborder" valign="top" width="70.88708870887088%" headers="mcps1.2.4.1.3 "><p>计算属性，用于在读取或设置时，进行预先处理，其结果会被缓存。计算属性名不能以$或_开头，不要使用保留字。</p>
</td>
</tr>
</tbody>
</table>

