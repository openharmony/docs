# Basic Usage<a name="EN-US_TOPIC_0000001127284892"></a>

Custom components are existing components encapsulated based on service requirements. A custom component can be invoked multiple times in a project to improve the code readability. You can introduce a custom component to the host page through  **element**  as shown in the following code snippet:

```
<element name='comp' src='../../common/component/comp.hml'></element>
<div>
  <comp prop1='xxxx' @child1="bindParentVmMethod"></comp>
</div>
```

The following is an example of using a custom component with  **if-else**:

```
<element name='comp1' src='../../common/component/comp1/comp1.hml'></element>
<element name='comp2' src='../../common/component/comp2/comp2.hml'></element>
<div>
  <comp1 if="{{showComp1}}" prop1='xxxx' @child1="bindParentVmMethodOne"></comp1>
  <comp2 else prop1='xxxx' @child1="bindParentVmMethodTwo"></comp2>
</div>
```

-   The  **name**  attribute indicates the custom component name \(optional\), which is case-insensitive and is in lowercase by default. The  **src**  attribute indicates the  **.hml**  file path \(mandatory\) of the custom component. If  **name**  is not set, the  **.hml**  file name is used as the component name by default.
-   Event binding: Use  **\(on|@\)**_child1_  syntax to bind a child component event to a custom component. In the child component, use  **this.$emit\('**_child1_**', \{params:'**_parameter to pass_**'\}\)**  for event triggering and value transferring. In the parent component, call  **bindParentVmMethod**  method and receive the parameters passed from the child component.

    >![](../../public_sys-resources/icon-note.gif) **NOTE:** 
    >For child component events that are named in camel case, convert the names to kebab case when binding the events to the parent component. For example, use  **@children-event**  instead of  **childrenEvent**:  **@children-event="bindParentVmMethod"**.


## Object<a name="section7681164881014"></a>

<a name="table67211828124016"></a>
<table><thead align="left"><tr id="row108577289405"><th class="cellrowborder" valign="top" width="11.091109110911091%" id="mcps1.1.4.1.1"><p id="p385742814403"><a name="p385742814403"></a><a name="p385742814403"></a>Attribute</p>
</th>
<th class="cellrowborder" valign="top" width="12.96129612961296%" id="mcps1.1.4.1.2"><p id="p19857192816408"><a name="p19857192816408"></a><a name="p19857192816408"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="75.94759475947595%" id="mcps1.1.4.1.3"><p id="p18573288402"><a name="p18573288402"></a><a name="p18573288402"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1085792824019"><td class="cellrowborder" valign="top" width="11.091109110911091%" headers="mcps1.1.4.1.1 "><p id="p115421323762"><a name="p115421323762"></a><a name="p115421323762"></a>data</p>
</td>
<td class="cellrowborder" valign="top" width="12.96129612961296%" headers="mcps1.1.4.1.2 "><p id="p05120283516"><a name="p05120283516"></a><a name="p05120283516"></a>Object/Function</p>
</td>
<td class="cellrowborder" valign="top" width="75.94759475947595%" headers="mcps1.1.4.1.3 "><p id="p105644412409"><a name="p105644412409"></a><a name="p105644412409"></a>Data model of the page. If the attribute is of the function type, the return value must be of the object type. The attribute name cannot start with the dollar sign ($) or underscore (_). Do not use reserved words (<strong id="b1663610842111"><a name="b1663610842111"></a><a name="b1663610842111"></a>for</strong>, <strong id="b18647087218"><a name="b18647087218"></a><a name="b18647087218"></a>if</strong>, <strong id="b565218842116"><a name="b565218842116"></a><a name="b565218842116"></a>show</strong>, and <strong id="b0657587218"><a name="b0657587218"></a><a name="b0657587218"></a>tid</strong>).</p>
<p id="p356184410403"><a name="p356184410403"></a><a name="p356184410403"></a> Do not use this attribute and <strong id="b15611312192115"><a name="b15611312192115"></a><a name="b15611312192115"></a>private</strong> or <strong id="b1571161272110"><a name="b1571161272110"></a><a name="b1571161272110"></a>public</strong> at the same time </p>
</td>
</tr>
<tr id="row3857132812406"><td class="cellrowborder" valign="top" width="11.091109110911091%" headers="mcps1.1.4.1.1 "><p id="p88572283404"><a name="p88572283404"></a><a name="p88572283404"></a>props</p>
</td>
<td class="cellrowborder" valign="top" width="12.96129612961296%" headers="mcps1.1.4.1.2 "><p id="p198571828114017"><a name="p198571828114017"></a><a name="p198571828114017"></a>Array/Object</p>
</td>
<td class="cellrowborder" valign="top" width="75.94759475947595%" headers="mcps1.1.4.1.3 "><p id="p3857192844012"><a name="p3857192844012"></a><a name="p3857192844012"></a>Used for communication between components. This attribute can be transferred to components via <strong id="b19615191652119"><a name="b19615191652119"></a><a name="b19615191652119"></a>&lt;tag xxxx='value'&gt;</strong>. A <strong id="b56261916152117"><a name="b56261916152117"></a><a name="b56261916152117"></a>props</strong> name must be in lowercase and cannot start with dollar sign ($) or underscore (_). Do not use reserved words (<strong id="b11631216152114"><a name="b11631216152114"></a><a name="b11631216152114"></a>for</strong>, <strong id="b86351216202115"><a name="b86351216202115"></a><a name="b86351216202115"></a>if</strong>, <strong id="b864018160215"><a name="b864018160215"></a><a name="b864018160215"></a>show</strong>, and <strong id="b364591612115"><a name="b364591612115"></a><a name="b364591612115"></a>tid</strong>). Currently, <strong id="b129739262211"><a name="b129739262211"></a><a name="b129739262211"></a>props</strong> does not support functions.</p>
</td>
</tr>
<tr id="row8842155461510"><td class="cellrowborder" valign="top" width="11.091109110911091%" headers="mcps1.1.4.1.1 "><p id="p17843155411153"><a name="p17843155411153"></a><a name="p17843155411153"></a>computed</p>
</td>
<td class="cellrowborder" valign="top" width="12.96129612961296%" headers="mcps1.1.4.1.2 "><p id="p1884365421515"><a name="p1884365421515"></a><a name="p1884365421515"></a>Object</p>
</td>
<td class="cellrowborder" valign="top" width="75.94759475947595%" headers="mcps1.1.4.1.3 "><p id="p6422712153413"><a name="p6422712153413"></a><a name="p6422712153413"></a>Used for pre-processing an expression for reading and setting. The result is cached. The name cannot start with a dollar sign ($) or underscore (_). Do not use reserved words.</p>
</td>
</tr>
</tbody>
</table>

