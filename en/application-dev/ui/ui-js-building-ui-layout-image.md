# Adding an Image


Generally, the [&lt;image&gt;](../reference/arkui-js/js-components-basic-image.md) component is used to add images on a page. The method of using this component is similar to that of using the **\<text>** component.


To reference images via the **\<image>** component, you must create the common directory under jsdefault, and then store the image files in the common directory. For details about the directory structure, see [Directory Structure](../ui/js-framework-file.md). The following sample code shows you how to add an image and set its style.

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
