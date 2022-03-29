# Adding an Image


Generally, the [&lt;image&gt;](../reference/arkui-js/js-components-basic-image.md)component is used to add images on a page. The method of using this component is similar to that of using the &lt;text&gt; component.


To reference images via the &lt;image&gt; component, you must create the common directory under jsdefault, and then store the image files in the common directory. For details about the directory structure, see [Directory Structure](js-framework-file.md). The following sample code shows you how to add an image and set its style.

```
<!-- xxx.hml -->
<image class="img" src="{{middleImage}}"></image>
```

```
/* xxx.css */
.img {  
  margin-top: 30px;
  margin-bottom: 30px;
  height: 385px;
}
```

```
// xxx.js
export default {
  data: {
    middleImage: '/common/ice.png',
  },
}
```
