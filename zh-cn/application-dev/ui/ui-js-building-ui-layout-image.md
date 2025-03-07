# 添加图片区域

添加图片区域通常用[image](../reference/apis-arkui/arkui-js/js-components-basic-image.md)组件来实现，使用的方法和text组件类似。



图片资源建议放在js\default\common目录下，common目录需自行创建，详细的目录结构见[目录结构](js-framework-file.md#目录结构)。代码示例如下：


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
