# Style Inheritance

> **NOTE**
>
> The APIs of this module are supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.

A custom component has the **inherit-class** attribute, which is defined in the following table.

| Name           | Type    | Default Value | Mandatory  | Description                              |
| ------------- | ------ | ---- | ---- | -------------------------------- |
| inherit-class | string | -    | No   | Class styles inherited from the parent component, separated by spaces.|

To enable a custom component to inherit the styles of its parent component, set the **inherit-calss** attribute for the custom component.

The example below is a code snippet in the HML file of the parent component that references a custom component named **comp**. This component uses the **inherit-class** attribute to inherit the styles of its parent component: **parent-class1** and **parent-class2**.

```html
<!-- xxx.hml -->
<element name='comp' src='../../common/component/comp.hml'></element>

<div class="container">
    <comp inherit-class="parent-class1 parent-class2" ></comp>
</div>
```

Code snippet in the CSS file of the parent component:

```css
/* xxx.css */
.parent-class1 {
    background-color:red;
    border:2px;
}
.parent-class2 {
    background-color:green;
    border:2px;
}
```

Code snippet in the HML file of the custom component, where **parent-class1** and **parent-class2** are styles inherited from the parent component:

```html
<!--comp.hml-->
<div class="item">
    <text class="parent-class1">Style 1 inherited from the parent component</text>
    <text class="parent-class2">Style 2 inherited from the parent component</text>
</div>
```
