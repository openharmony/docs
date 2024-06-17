# CSS


Cascading Style Sheets (CSS) is a language used to describe the HML page structure. All HML components have default styles. You can customize styles for these components using CSS to design various pages.


## Style Import

CSS files can be imported using the **\@import** statement. This facilitates module management and code reuse.


## Style Declaration

The **.css** file with the same name as the **.hml** file in each page directory describes the styles of components on the HML page, determining how the components will be displayed.

1. Internal style: The **style** and **class** attributes can be used to specify the component style. Sample code:

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

| Selector   | Example                   | Description                                 |
| ------ | --------------------- | ------------------------------------- |
| .class | .container            | Selects all components whose **class** is **container**.            |
| \#id   | \#titleId             | Selects all components whose **id** is **titleId**.                 |
| ,      | .title, .content | Selects all components whose **class** is **title** or **content**.|

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
/* Page style xxx.css */
/* Set the style for the components whose class is title. */
.title {
  font-size: 30px;
}
/* Set the style for the components whose id is contentId. */
#contentId {
  font-size: 20px;
}
/* Set padding for all components of the title or content class to 5 px. */
.title, .content {
  padding: 5px;
}

```


## Pseudo-classes

A CSS pseudo-class is a keyword added to a selector that specifies a special state of the selected elements.



| Name      | Available Components                               | Description                                      |
| -------- | ----------------------------------- | ---------------------------------------- |
| :active  | <br>input[type="button"]           | Selects the element activated by a user, for example, a pressed button. Only the **background-color** and **background-image** attributes can be set for the pseudo-class selector on lite wearables.|
| :checked | input[type="checkbox", type="radio"]| Selects the element whose **checked** attribute is **true**. Only the **background-color** and **background-image** attributes can be set for the pseudo-class selector on lite wearables.|

The following is an example for you to use the **:active** pseudo-class to control the style when a user presses the button. 


```html
<!-- index.hml -->
<div class="container">
  <input type="button" class="button" value="Button"></input>
</div>
```


```css
/* index.css */
.button:active {
  background-color: #888888;/* After the button is activated, the background color is changed to #888888. */
}
```


## Precompiled Styles

Precompilation is a program that uses specific syntax to generate CSS files. It provides variables and calculation, helping you define component styles more conveniently. Currently, Less, Sass, and Scss are supported. To use precompiled styles, change the suffix of the original **.css** file. For example, change **index.css** to **index.less**, **index.sass**, or **index.scss**.

- The following **index.less** file is changed from **index.css**.

  ```css
  /* index.less */
  /* Define a variable. */
  @colorBackground: #000000;
  .container {
      background-color: @colorBackground; /* Use the variable defined in the .less file. */
  }
  ```

- Reference a precompiled style file. For example, if the **style.scss** file is located in the **common** directory, change the original **index.css** file to **index.scss** and import **style.scss**.

  ```css
  /* style.scss */
  /* Define a variable. */
  $colorBackground: #000000;
  ```

  Reference the precompiled style file in **index.scss**:


  ```css
  /* index.scss */
  /* Import style.scss. */
  @import '../../common/style.scss';
  .container {
    background-color: $colorBackground; /* Use the variable defined in style.scss. */
  }
  ```


  >  **NOTE**
  >
  >  Place precompiled style files in the **common** directory.
