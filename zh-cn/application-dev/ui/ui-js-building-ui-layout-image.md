# 添加图片区域

添加图片区域通常用[image](../js-reference/js-based-web-like-development-paradigm/js-components-basic-image.md)组件来实现，使用的方法和text组件类似。


图片资源建议放在jsdefaultcommon目录下，common目录需自行创建，详细的目录结构见[目录结构](../js-reference/js-based-web-like-development-paradigm/js-framework-file.md#目录结构)。代码示例如下：


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
