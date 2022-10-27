# Basic Usage

Custom components are existing components encapsulated based on service requirements. A custom component can be invoked multiple times in a project to improve the code readability. You can introduce a custom component to the host page through **element** as shown in the following code snippet:
```html
<element name='comp' src='../../common/component/comp.hml'></element>
<div>
  <comp prop1='xxxx' @child1="bindParentVmMethod"></comp>
</div>
```


The following is an example of using a custom component with **if-else**:
```html
<element name='comp1' src='../../common/component/comp1/comp1.hml'></element>
<element name='comp2' src='../../common/component/comp2/comp2.hml'></element>
<div>
  <comp1 if="{{showComp1}}" prop1='xxxx' @child1="bindParentVmMethodOne"></comp1>
  <comp2 else prop1='xxxx' @child1="bindParentVmMethodTwo"></comp2>
</div>
```


- The **name** attribute indicates the custom component name (optional), which is case-insensitive and is in lowercase by default. The **src** attribute indicates the **.hml** file path (mandatory) of the custom component. If **name** is not set, the **.hml** file name is used as the component name by default.

- Event binding: Use **(on|@)***child1* syntax to bind a child component event to a custom component. In the child component, use **this.$emit('***child1***', {params:'***parameter to pass***'})** for event triggering and value transferring. In the parent component, call **bindParentVmMethod** method and receive the parameters passed from the child component.
  >  **NOTE**
  >
  >  For child component events that are named in camel case, convert the names to kebab case when binding the events to the parent component. For example, use **\@children-event** instead of **childrenEvent**: **\@children-event="bindParentVmMethod"**.

**Table 1** Objects

| Name      | Type             | Description                                      |
| -------- | --------------- | ---------------------------------------- |
| data     | Object/Function | Data model of the page. If the attribute is of the function type, the return value must be of the object type. The attribute name cannot start with a dollar sign ($) or underscore (_). Do not use reserved words (**for**, **if**, **show**, and **tid**).<br>Do not use this attribute and **private** or **public** at the same time.(Rich) |
| props    | Array/Object    | Used for communication between components. This attribute can be transferred to components via **\<tag xxxx='value'>**. A **props** name must be in lowercase and cannot start with a dollar sign ($) or underscore (\_). Do not use reserved words (**for**, **if**, **show**, and **tid**). Currently, **props** does not support functions.|
| computed | Object          | Used for pre-processing an object for reading and setting. The result is cached. The name cannot start with a dollar sign ($) or underscore (\_). Do not use reserved words.|
