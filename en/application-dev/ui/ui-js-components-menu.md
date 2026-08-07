# menu Development

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @H-xinwei-->
<!--Designer: @zhanghaibo0-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=8e22c68cdd7ecb0668db21c4312cda839c2cdaa0 translatedAt=2026-08-05T10:13:57.327Z pushedAt=2026-08-06T06:30:18.436Z -->

The &lt;menu&gt; component serves as a temporary pop-up window to display operations that users can perform. For details, see [menu](../reference/apis-arkui/arkui-js/js-components-basic-menu.md).

## Creating a &lt;menu&gt; Component

Create a **&lt;menu&gt;** component in the .hml file under **pages/index** and add the **target**, **type**, and **title** attributes.

```html
<!-- xxx.hml-->
<div class="container">
  <text class="title-text" id="textId">show menu</text>
  <menu target="textId" type="click" title="title">
    <option value="Item 1">Item 1</option>
    <option value="Item 2">Item 2</option>
    <option value="Item 3">Item 3</option>
  </menu>
</div>
```

```css
/* xxx.css */
.container{
  width: 100%;
  height: 100%; 
  flex-direction: column;
  background-color: #F1F3F5;
  align-items: center;
  justify-content: center;
  width: 100%;
}
.title-text{
  font-size: 35px;
}
```

![menu-Component](figures/menu-Component.png)

> **NOTE**
> - The **&lt;menu&gt;** component supports only the [option](../reference/apis-arkui/arkui-js/js-components-basic-option.md) child component.
> 
> - The **&lt;menu&gt;** component does not support the **focusable** and **disabled** attributes.

## Setting Styles

Set the style for the **&lt;menu&gt;** component, such as the font color, size, and character spacing.

```html
<!-- xxx.hml-->
<div class="container">
  <text class="title-text" id="textId">show menu</text>
  <menu target="textId" type="click" title="title">
    <option value="Item 1">Item 1</option>
    <option value="Item 2">Item 2</option>
    <option value="Item 3">Item 3</option>
  </menu>
</div>
```

```css
/* xxx.css */
.container{
  width: 100%;
  height: 100%; 
  flex-direction: column;
  background-color: #F1F3F5;
  align-items: center;
  justify-content: center;
  width: 100%;
}
.title-text{
  font-size: 35px;
  background-color: #5a5aee;
  color: white;
  width: 70%;
  text-align: center;
  height: 85px;
  border-radius: 12px;
}
.menu{
  text-color: blue;
  font-size: 35px;
  letter-spacing: 2px;
}
option{
  color: #6a6aef;
  font-size: 30px;
}
```

![Setting-Styles-1](figures/Setting-Styles-1.png)

## Binding Events

Bind the **oncancel** event to the **&lt;menu&gt;** component. (The event is triggered when an operation is canceled.)

```html
<!-- xxx.hml-->
<div class="container">
  <text  class="title-text" id="textId" onclick="textClick">show menu</text>
  <menu  title="title" oncancel="cancel" id="menuId">
    <option value="Item 1">Item 1</option>
    <option value="Item 2">Item 2</option>
    <option value="Item 3">Item 3</option>
  </menu>
</div>
```

```css
/* xxx.css */
.container{
  width: 100%;
  height: 100%;
  flex-direction: column;
  background-color: #F1F3F5;
  width: 100%;
}
.title-text{
  font-size: 35px;
  background-color: #5a5aee;
  color: white;
  width: 70%;
  text-align: center;
  height: 85px;
  border-radius: 12px;
  margin-top: 500px;
  margin-left: 15%;
}
menu{
  text-color: blue;
  font-size: 35px;
  letter-spacing: 2px;
}
option{
  color: #6a6aef;
  font-size: 30px;
}
```

```js
// xxx.js
export default {
  cancel() {
    this.getUIContext().getPromptAction().showToast({
      message: "cancel"
    })
  },
  textClick() {
    this.$element("menuId").show({ x: 175,y: 590 });
  }
}
```

![Binding-Events](figures/Binding-Events.gif)