# 添加图片区域<a name="ZH-CN_TOPIC_0000001063590816"></a>

添加图片区域通常用image组件来实现，使用的方法和text组件类似。

图片资源建议放在“js  \>  default  \>  common“目录下，common目录需自行创建。代码示例如下：

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

