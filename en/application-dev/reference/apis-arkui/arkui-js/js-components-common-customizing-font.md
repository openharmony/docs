# Custom Font Styles

The custom font can be loaded from the font file in a project. The font file must be in .ttf or .otf format.

>  **NOTE**
>
>  This component is supported since API version 4. Updates will be marked with a superscript to indicate their earliest API version.


## Defining @font-face

```
@font-face {   
  font-family: font; 
  src: url('/common/font.ttf'); 
}
```

**font-family**

Customize a font.

**src**

Supported sources of custom fonts:

- Font file in the project: Specify the absolute path of the font file in the project through **url**. For details, see [File Access Rules](../../../ui/js-framework-file.md).

- You can set only one **src** attribute.


## Using font-face

You can set **font-face** in **style** and specify the name of the **font-face** using **font-family**.

**Example**

Page layout:
```html
<!-- xxx.hml -->
<div>    
  <text class="demo-text">Test the custom font.</text>  
</div>
```

Page style:

```css
/*xxx.css*/
@font-face {
  font-family: font;
  src: url("/common/font.ttf");
}
.demo-text {
  font-family: font;
}
```
