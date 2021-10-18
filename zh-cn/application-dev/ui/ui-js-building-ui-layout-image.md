# 添加图片区域

添加图片区域通常用image组件来实现，使用的方法和text组件类似。


图片资源建议放在jsdefaultcommon目录下，common目录需自行创建。代码示例如下：


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
