# Basic Usage<a name="EN-US_TOPIC_0000001162494627"></a>

-   [Object](#en-us_topic_0000001058988954_section7681164881014)

Custom components are existing components encapsulated based on service requirements. A custom component can be invoked multiple times in a project to improve the code readability. You can introduce a custom component to the host page through  **element**  as shown in the following code snippet:

```
<element name='comp' src='../../common/component/comp.hml'></element>
<div>
  <comp prop1='xxxx' @child1="bindParentVmMethod"></comp>
</div>
```

-   The  **name**  attribute indicates the custom component name \(optional\), which is case-insensitive and is in lowercase by default. The  **src**  attribute indicates the  **.hml**  file path \(mandatory\) of the custom component. If  **name**  is not set, the  **.hml**  file name is used as the component name by default.
-   Event binding: Use  **\(on|@\)**_child1_  in the custom component to bind a child component event. In the child component, use  **this.$emit\('**_child1_**', \{params:'**_parameter to pass_**'\}\)**  to trigger the bound event and pass the parameter value. In the parent component, call  **bindParentVmMethod**  and receive the parameter passed from the child component.

    >![](public_sys-resources/icon-note.gif) **NOTE:** 
    >For child component events that are named in camel case, convert the names to kebab case when binding the events to the parent component. For example, use  **@children-event**  instead of  **childrenEvent**:  **@children-event="bindParentVmMethod"**.


## Object<a name="en-us_topic_0000001058988954_section7681164881014"></a>

<a name="en-us_topic_0000001058988954_table67211828124016"></a>
<table><thead align="left"><tr id="en-us_topic_0000001058988954_row108577289405"><th class="cellrowborder" valign="top" width="11.091109110911091%" id="mcps1.1.4.1.1"><p id="en-us_topic_0000001058988954_p385742814403"><a name="en-us_topic_0000001058988954_p385742814403"></a><a name="en-us_topic_0000001058988954_p385742814403"></a>Attribute</p>
</th>
<th class="cellrowborder" valign="top" width="12.96129612961296%" id="mcps1.1.4.1.2"><p id="en-us_topic_0000001058988954_p19857192816408"><a name="en-us_topic_0000001058988954_p19857192816408"></a><a name="en-us_topic_0000001058988954_p19857192816408"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="75.94759475947595%" id="mcps1.1.4.1.3"><p id="en-us_topic_0000001058988954_p18573288402"><a name="en-us_topic_0000001058988954_p18573288402"></a><a name="en-us_topic_0000001058988954_p18573288402"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001058988954_row1085792824019"><td class="cellrowborder" valign="top" width="11.091109110911091%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058988954_p115421323762"><a name="en-us_topic_0000001058988954_p115421323762"></a><a name="en-us_topic_0000001058988954_p115421323762"></a>data</p>
</td>
<td class="cellrowborder" valign="top" width="12.96129612961296%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058988954_p05120283516"><a name="en-us_topic_0000001058988954_p05120283516"></a><a name="en-us_topic_0000001058988954_p05120283516"></a>Object/Function</p>
</td>
<td class="cellrowborder" valign="top" width="75.94759475947595%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058988954_p105644412409"><a name="en-us_topic_0000001058988954_p105644412409"></a><a name="en-us_topic_0000001058988954_p105644412409"></a>Data model of the page. If the attribute is of the function type, the return value must be of the object type. The attribute name cannot start with the dollar sign ($) or underscore (_). Do not use reserved words (<strong id="en-us_topic_0000001058988954_b1663610842111"><a name="en-us_topic_0000001058988954_b1663610842111"></a><a name="en-us_topic_0000001058988954_b1663610842111"></a>for</strong>, <strong id="en-us_topic_0000001058988954_b18647087218"><a name="en-us_topic_0000001058988954_b18647087218"></a><a name="en-us_topic_0000001058988954_b18647087218"></a>if</strong>, <strong id="en-us_topic_0000001058988954_b565218842116"><a name="en-us_topic_0000001058988954_b565218842116"></a><a name="en-us_topic_0000001058988954_b565218842116"></a>show</strong>, and <strong id="en-us_topic_0000001058988954_b0657587218"><a name="en-us_topic_0000001058988954_b0657587218"></a><a name="en-us_topic_0000001058988954_b0657587218"></a>tid</strong>).</p>
<p id="en-us_topic_0000001058988954_p356184410403"><a name="en-us_topic_0000001058988954_p356184410403"></a><a name="en-us_topic_0000001058988954_p356184410403"></a> Do not use this attribute and <strong id="en-us_topic_0000001058988954_b15611312192115"><a name="en-us_topic_0000001058988954_b15611312192115"></a><a name="en-us_topic_0000001058988954_b15611312192115"></a>private</strong> or <strong id="en-us_topic_0000001058988954_b1571161272110"><a name="en-us_topic_0000001058988954_b1571161272110"></a><a name="en-us_topic_0000001058988954_b1571161272110"></a>public</strong> at the same time </p>
</td>
</tr>
<tr id="en-us_topic_0000001058988954_row3857132812406"><td class="cellrowborder" valign="top" width="11.091109110911091%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058988954_p88572283404"><a name="en-us_topic_0000001058988954_p88572283404"></a><a name="en-us_topic_0000001058988954_p88572283404"></a>props</p>
</td>
<td class="cellrowborder" valign="top" width="12.96129612961296%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058988954_p198571828114017"><a name="en-us_topic_0000001058988954_p198571828114017"></a><a name="en-us_topic_0000001058988954_p198571828114017"></a>Array/Object</p>
</td>
<td class="cellrowborder" valign="top" width="75.94759475947595%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058988954_p3857192844012"><a name="en-us_topic_0000001058988954_p3857192844012"></a><a name="en-us_topic_0000001058988954_p3857192844012"></a>Used for communication between components. This attribute can be transferred to components via <strong id="en-us_topic_0000001058988954_b19615191652119"><a name="en-us_topic_0000001058988954_b19615191652119"></a><a name="en-us_topic_0000001058988954_b19615191652119"></a>&lt;tag xxxx='value'&gt;</strong>. A <strong id="en-us_topic_0000001058988954_b56261916152117"><a name="en-us_topic_0000001058988954_b56261916152117"></a><a name="en-us_topic_0000001058988954_b56261916152117"></a>props</strong> name must be in lowercase and cannot start with dollar sign ($) or underscore (_). Do not use reserved words (<strong id="en-us_topic_0000001058988954_b11631216152114"><a name="en-us_topic_0000001058988954_b11631216152114"></a><a name="en-us_topic_0000001058988954_b11631216152114"></a>for</strong>, <strong id="en-us_topic_0000001058988954_b86351216202115"><a name="en-us_topic_0000001058988954_b86351216202115"></a><a name="en-us_topic_0000001058988954_b86351216202115"></a>if</strong>, <strong id="en-us_topic_0000001058988954_b864018160215"><a name="en-us_topic_0000001058988954_b864018160215"></a><a name="en-us_topic_0000001058988954_b864018160215"></a>show</strong>, and <strong id="en-us_topic_0000001058988954_b364591612115"><a name="en-us_topic_0000001058988954_b364591612115"></a><a name="en-us_topic_0000001058988954_b364591612115"></a>tid</strong>). Currently, <strong id="en-us_topic_0000001058988954_b129739262211"><a name="en-us_topic_0000001058988954_b129739262211"></a><a name="en-us_topic_0000001058988954_b129739262211"></a>props</strong> does not support functions.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058988954_row8842155461510"><td class="cellrowborder" valign="top" width="11.091109110911091%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058988954_p17843155411153"><a name="en-us_topic_0000001058988954_p17843155411153"></a><a name="en-us_topic_0000001058988954_p17843155411153"></a>computed</p>
</td>
<td class="cellrowborder" valign="top" width="12.96129612961296%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058988954_p1884365421515"><a name="en-us_topic_0000001058988954_p1884365421515"></a><a name="en-us_topic_0000001058988954_p1884365421515"></a>Object</p>
</td>
<td class="cellrowborder" valign="top" width="75.94759475947595%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058988954_p6422712153413"><a name="en-us_topic_0000001058988954_p6422712153413"></a><a name="en-us_topic_0000001058988954_p6422712153413"></a>Used for pre-processing an expression for reading and setting. The result is cached. The name cannot start with a dollar sign ($) or underscore (_). Do not use reserved words.</p>
</td>
</tr>
</tbody>
</table>

