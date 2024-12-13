# Adding an Image

Generally, the [\<image>](../reference/apis-arkui/arkui-js/js-components-basic-image.md) component is used to add images on a page. The method of using this component is similar to that of using the **Text** component.



To reference images via the **\<image>** component, you are advised to store the image files under **js\default\common**. (You need to create the **common** directory on your own.) For details about the directory structure, see [Directory Structure](../ui/js-framework-file.md#directory-structure). The following sample code shows you how to add an image and set its style.


```html
<!-- xxx.hml -->
<image class="img" src="{{middleImage}}"></image>
```


```css
/* xxx.css */
.img {  
  margin-top: 30px;
  margin-bottom: 30px;
  height: 385px;
}
```


```js
// xxx.js
export default {
  data: {
    middleImage: '/common/ice.png',
  },
}
```
