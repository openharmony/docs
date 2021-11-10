# 装饰器<a name="ZH-CN_TOPIC_0000001110948902"></a>

装饰器**@Decorator**，被装饰的元素可以是变量声明，类定义，结构体定义，方法定义等，赋予其特殊的含义。

多个装饰器实现可以叠加到目标元素，书写在同一行上或者在多行上，推荐书写在多行上。

如下**@Component**和**@State**的使用，被**@Component**装饰的元素具备了组件化的含义，使用**@State**装饰的变量具备了状态数据的含义：

```
@Component
struct MyComponent {
    @State count: number = 0
}
```

装饰器可以书写在同一行上：

```
@Entry @Component struct MyComponent {
}
```

但更推荐书写在多行上：

```
@Entry
@Component
struct MyComponent {
}
```

## 支持的装饰器列表<a name="section5500155514324"></a>

<a name="table1571mcpsimp"></a>
<table><thead align="left"><tr id="row1577mcpsimp"><th class="cellrowborder" valign="top" width="13.16%" id="mcps1.1.4.1.1"><p id="p1579mcpsimp"><a name="p1579mcpsimp"></a><a name="p1579mcpsimp"></a>装饰器</p>
</th>
<th class="cellrowborder" valign="top" width="23.96%" id="mcps1.1.4.1.2"><p id="p1581mcpsimp"><a name="p1581mcpsimp"></a><a name="p1581mcpsimp"></a>装饰内容</p>
</th>
<th class="cellrowborder" valign="top" width="62.88%" id="mcps1.1.4.1.3"><p id="p1583mcpsimp"><a name="p1583mcpsimp"></a><a name="p1583mcpsimp"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1584mcpsimp"><td class="cellrowborder" valign="top" width="13.16%" headers="mcps1.1.4.1.1 "><p id="p1586mcpsimp"><a name="p1586mcpsimp"></a><a name="p1586mcpsimp"></a>@Component</p>
</td>
<td class="cellrowborder" valign="top" width="23.96%" headers="mcps1.1.4.1.2 "><p id="p1588mcpsimp"><a name="p1588mcpsimp"></a><a name="p1588mcpsimp"></a>struct</p>
</td>
<td class="cellrowborder" valign="top" width="62.88%" headers="mcps1.1.4.1.3 "><p id="p1590mcpsimp"><a name="p1590mcpsimp"></a><a name="p1590mcpsimp"></a>结构体在装饰后具有基于组件的能力，需要实现<strong id="b13779163015367"><a name="b13779163015367"></a><a name="b13779163015367"></a>build</strong>方法来更新UI。</p>
</td>
</tr>
<tr id="row1591mcpsimp"><td class="cellrowborder" valign="top" width="13.16%" headers="mcps1.1.4.1.1 "><p id="p1593mcpsimp"><a name="p1593mcpsimp"></a><a name="p1593mcpsimp"></a>@Entry</p>
</td>
<td class="cellrowborder" valign="top" width="23.96%" headers="mcps1.1.4.1.2 "><p id="p12728164243518"><a name="p12728164243518"></a><a name="p12728164243518"></a>struct</p>
</td>
<td class="cellrowborder" valign="top" width="62.88%" headers="mcps1.1.4.1.3 "><p id="p1597mcpsimp"><a name="p1597mcpsimp"></a><a name="p1597mcpsimp"></a>组件被装饰后作为页面的入口，页面加载时将被渲染显示。</p>
</td>
</tr>
<tr id="row1598mcpsimp"><td class="cellrowborder" valign="top" width="13.16%" headers="mcps1.1.4.1.1 "><p id="p1600mcpsimp"><a name="p1600mcpsimp"></a><a name="p1600mcpsimp"></a>@State</p>
</td>
<td class="cellrowborder" valign="top" width="23.96%" headers="mcps1.1.4.1.2 "><p id="p1602mcpsimp"><a name="p1602mcpsimp"></a><a name="p1602mcpsimp"></a>基本数据类型，类，数组</p>
</td>
<td class="cellrowborder" valign="top" width="62.88%" headers="mcps1.1.4.1.3 "><p id="p1604mcpsimp"><a name="p1604mcpsimp"></a><a name="p1604mcpsimp"></a>修饰的状态数据被修改时会触发组件的<strong id="b20907141011376"><a name="b20907141011376"></a><a name="b20907141011376"></a>build</strong>方法进行UI界面更新。</p>
</td>
</tr>
<tr id="row1605mcpsimp"><td class="cellrowborder" valign="top" width="13.16%" headers="mcps1.1.4.1.1 "><p id="p1607mcpsimp"><a name="p1607mcpsimp"></a><a name="p1607mcpsimp"></a>@Prop</p>
</td>
<td class="cellrowborder" valign="top" width="23.96%" headers="mcps1.1.4.1.2 "><p id="p1609mcpsimp"><a name="p1609mcpsimp"></a><a name="p1609mcpsimp"></a>基本数据类型</p>
</td>
<td class="cellrowborder" valign="top" width="62.88%" headers="mcps1.1.4.1.3 "><p id="p1611mcpsimp"><a name="p1611mcpsimp"></a><a name="p1611mcpsimp"></a>修改后的状态数据用于在父组件和子组件之间建立单向数据依赖关系。修改父组件关联数据时，更新当前组件的UI。</p>
</td>
</tr>
<tr id="row1612mcpsimp"><td class="cellrowborder" valign="top" width="13.16%" headers="mcps1.1.4.1.1 "><p id="p1614mcpsimp"><a name="p1614mcpsimp"></a><a name="p1614mcpsimp"></a>@Link</p>
</td>
<td class="cellrowborder" valign="top" width="23.96%" headers="mcps1.1.4.1.2 "><p id="p1616mcpsimp"><a name="p1616mcpsimp"></a><a name="p1616mcpsimp"></a>基本数据类型，类，数组</p>
</td>
<td class="cellrowborder" valign="top" width="62.88%" headers="mcps1.1.4.1.3 "><p id="p1618mcpsimp"><a name="p1618mcpsimp"></a><a name="p1618mcpsimp"></a>父子组件之间的双向数据绑定。父组件的内部状态数据作为数据源。任何一方所做的修改都会反映给另一方。</p>
</td>
</tr>
</tbody>
</table>

