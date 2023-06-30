# CSS


Cascading Style Sheets (CSS) is a language used to describe the HML page structure. All HML components have default styles. You can customize styles for these components using CSS to design various pages.


## Size Unit

1. Logical px set by **\<length>**:
   1. The default logical width of a service widget is 150 px. The page will be scaled to fit the actual width of the screen. For example, on a screen with the actual width of 300 physical px, 100 px is rendered on 200 physical px, with the size doubled from 150 px to 300 px.
   2. If you set **autoDesignWidth** to **true**, the logical pixels are scaled based on the screen density. For example, if the screen density is 3x, 100 px will be rendered on 300 physical px. This approach is recommended when your application needs to adapt to multiple devices.

2. Percentage set by **\<percentage>**: The component size is represented by its percentage of the parent component size. For example, if the width **\<percentage>** of a component is set to **50%**, the width of the component is half of its parent component's width.


## Style Import

CSS files can be imported using the **\@import** statement. This facilitates module management and code reuse.


## Style Declaration

The **.css** file with the same name as the **.hml** file in each page directory describes the styles of components on the HML page, determining how the components will be displayed.

1. Internal style: The **style** and **class** attributes can be used to specify the component style. Example:

   ```html
   <!-- index.hml -->
   <div class="container">
     <text style="color: red">Hello World</text>
   </div>
   ```


   ```css
   /* index.css */
   .container {
     justify-content: center;
   }
   ```

2. External style files: You need to import the files. For example, create a **style.css** file in the **common** directory and import the file at the beginning of **index.css**.

   ```css
   /* style.css */
   .title {
     font-size: 50px;
   }
   ```


   ```css
   /* index.css */
   @import '../../common/style.css';
   .container {
     justify-content: center;
   }
   ```


## Selectors

A CSS selector is used to select elements for which styles need to be added to. The following table lists the supported selectors.

| Selector   | Example        | Description                     |
| ------ | ---------- | ------------------------- |
| .class | .container | Selects all components whose **class** is **container**.|
| \#id   | \#titleId  | Selects all components whose **id** is **titleId**.     |

Example:


```html
<!-- Pagelayoutexample.hml -->
<div id="containerId" class="container">
  <text id="titleId" class="title">Title</text>
  <div class="content">
    <text id="contentId">Content</text>
  </div>
</div>
```


```css
/* Pagestyleexample.css */
/* Set the style for the components whose class is title. */
.title {
  font-size: 30px;
}
/* Set the style for the components whose id is contentId. */
#contentId {
  font-size: 20px;
}
```


## Selector Specificity

The specificity rule of the selectors complies with the W3C rule, which is only available for inline styles, **id**, and **class**. (Inline styles are those declared in the **style** attribute.)

When multiple selectors point to the same element, their priorities are as follows (in descending order): inline style > **id** > **class**.
