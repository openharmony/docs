# @Decorator<a name="EN-US_TOPIC_0000001110948902"></a>

**@Decorator**  can be applied to variable declarations, class definitions, structure definitions, or method definitions.

Multiple decorator implementations can be superimposed on the target element and written on the same line or multiple lines. It is recommended that the implementation be written on multiple lines.

In the example below, the elements decorated by  **@Component**  take on the form of a component, and the variables decorated by  **@State**  have the meaning of the state data.

```
@Component
struct MyComponent {
    @State count: number = 0
}
```

Multiple decorator implementations can be written on the same line.

```
@Entry @Component struct MyComponent {
}
```

However, you are advised to write the decorator implementations on multiple lines.

```
@Entry
@Component
struct MyComponent {
}
```

## Supported Decorators<a name="section5500155514324"></a>

<a name="table1571mcpsimp"></a>
<table><thead align="left"><tr id="row1577mcpsimp"><th class="cellrowborder" valign="top" width="13.16%" id="mcps1.1.4.1.1"><p id="p1579mcpsimp"><a name="p1579mcpsimp"></a><a name="p1579mcpsimp"></a>Decorator</p>
</th>
<th class="cellrowborder" valign="top" width="23.96%" id="mcps1.1.4.1.2"><p id="p1581mcpsimp"><a name="p1581mcpsimp"></a><a name="p1581mcpsimp"></a>Decorates...</p>
</th>
<th class="cellrowborder" valign="top" width="62.88%" id="mcps1.1.4.1.3"><p id="p1583mcpsimp"><a name="p1583mcpsimp"></a><a name="p1583mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1584mcpsimp"><td class="cellrowborder" valign="top" width="13.16%" headers="mcps1.1.4.1.1 "><p id="p1586mcpsimp"><a name="p1586mcpsimp"></a><a name="p1586mcpsimp"></a>@Component</p>
</td>
<td class="cellrowborder" valign="top" width="23.96%" headers="mcps1.1.4.1.2 "><p id="p1588mcpsimp"><a name="p1588mcpsimp"></a><a name="p1588mcpsimp"></a>struct</p>
</td>
<td class="cellrowborder" valign="top" width="62.88%" headers="mcps1.1.4.1.3 "><p id="p1590mcpsimp"><a name="p1590mcpsimp"></a><a name="p1590mcpsimp"></a>The decorated structure has the component-based capability. The <strong id="b151410144016"><a name="b151410144016"></a><a name="b151410144016"></a>build</strong> method must be implemented to update the UI.</p>
</td>
</tr>
<tr id="row1591mcpsimp"><td class="cellrowborder" valign="top" width="13.16%" headers="mcps1.1.4.1.1 "><p id="p1593mcpsimp"><a name="p1593mcpsimp"></a><a name="p1593mcpsimp"></a>@Entry</p>
</td>
<td class="cellrowborder" valign="top" width="23.96%" headers="mcps1.1.4.1.2 "><p id="p12728164243518"><a name="p12728164243518"></a><a name="p12728164243518"></a>struct</p>
</td>
<td class="cellrowborder" valign="top" width="62.88%" headers="mcps1.1.4.1.3 "><p id="p1597mcpsimp"><a name="p1597mcpsimp"></a><a name="p1597mcpsimp"></a>The decorated component is used as the entry of a page. The component is rendered and displayed when the page is loaded.</p>
</td>
</tr>
<tr id="row1598mcpsimp"><td class="cellrowborder" valign="top" width="13.16%" headers="mcps1.1.4.1.1 "><p id="p1600mcpsimp"><a name="p1600mcpsimp"></a><a name="p1600mcpsimp"></a>@State</p>
</td>
<td class="cellrowborder" valign="top" width="23.96%" headers="mcps1.1.4.1.2 "><p id="p1602mcpsimp"><a name="p1602mcpsimp"></a><a name="p1602mcpsimp"></a>Primitive types, classes, and arrays</p>
</td>
<td class="cellrowborder" valign="top" width="62.88%" headers="mcps1.1.4.1.3 "><p id="p1604mcpsimp"><a name="p1604mcpsimp"></a><a name="p1604mcpsimp"></a>If the decorated state data is modified, the <strong id="b9877114516116"><a name="b9877114516116"></a><a name="b9877114516116"></a>build</strong> method of the component will be called to update the UI.</p>
</td>
</tr>
<tr id="row1605mcpsimp"><td class="cellrowborder" valign="top" width="13.16%" headers="mcps1.1.4.1.1 "><p id="p1607mcpsimp"><a name="p1607mcpsimp"></a><a name="p1607mcpsimp"></a>@Prop</p>
</td>
<td class="cellrowborder" valign="top" width="23.96%" headers="mcps1.1.4.1.2 "><p id="p1609mcpsimp"><a name="p1609mcpsimp"></a><a name="p1609mcpsimp"></a>Primitive types</p>
</td>
<td class="cellrowborder" valign="top" width="62.88%" headers="mcps1.1.4.1.3 "><p id="p1611mcpsimp"><a name="p1611mcpsimp"></a><a name="p1611mcpsimp"></a>The modified state data is used to establish a unidirectional data dependency between the parent component and the child component. When the data associated with the parent component is modified, the UI of the current component is updated.</p>
</td>
</tr>
<tr id="row1612mcpsimp"><td class="cellrowborder" valign="top" width="13.16%" headers="mcps1.1.4.1.1 "><p id="p1614mcpsimp"><a name="p1614mcpsimp"></a><a name="p1614mcpsimp"></a>@Link</p>
</td>
<td class="cellrowborder" valign="top" width="23.96%" headers="mcps1.1.4.1.2 "><p id="p1616mcpsimp"><a name="p1616mcpsimp"></a><a name="p1616mcpsimp"></a>Primitive types, classes, and arrays</p>
</td>
<td class="cellrowborder" valign="top" width="62.88%" headers="mcps1.1.4.1.3 "><p id="p1618mcpsimp"><a name="p1618mcpsimp"></a><a name="p1618mcpsimp"></a>This decorator is used for bidirectional data binding between parent and child components. The internal state data of the parent component is used as the data source. Any changes made to one component will be reflected to the other.</p>
</td>
</tr>
</tbody>
</table>

