# 基础知识


Svg组件主要作为svg画布的根节点使用，也可以在svg中嵌套使用。具体用法请参考[Svg](../reference/arkui-js/js-components-svg.md)。


> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> - 从API version 7开始支持。
> 
> - svg父组件或者svg组件需要定义宽高值，否则不进行绘制。


## 创建Svg组件

在pages/index目录下的hml文件中创建一个Svg组件。


```
<!-- xxx.hml -->
<div class="container">
  <svg width="400" height="400">  </svg>
</div>
```


```
/* xxx.css */
.container{
  width: 100%;
  height: 100%;
  flex-direction: column;
  align-items: center;
  justify-content: center;
  background-color: #F1F3F5;
}
svg{
  background-color: blue;
}
```

![zh-cn_image_0000001218280036](figures/zh-cn_image_0000001218280036.png)


## 设置属性

通过设置width、height、x、y和viewBox属性为Svg设置宽度、高度、x轴坐标、y轴坐标和Svg视口。


```
<!-- xxx.hml -->
<div class="container">
  <svg width="400" height="400" viewBox="0 0 100 100">    <svg class="rect" width="100" height="100" x="20" y="10">    </svg>  </svg>
</div>
```


```
/* xxx.css */
.container{
  width: 100%;
  height: 100%;
  flex-direction: column;
  align-items: center;
  justify-content: center;
  background-color: #F1F3F5;
}
svg{
  background-color: yellow;
}
.rect{
  background-color: red;
}
```

![zh-cn_image_0000001218599996](figures/zh-cn_image_0000001218599996.png)

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> - x和y设置的的是当前Svg的x轴和y轴坐标，如果当前Svg为根节点，x轴和y轴属性无效。
> 
> - viewBox的宽高和svg的宽高不一致，会以中心对齐进行缩放。


## 相关实例

针对Svg开发，有以下相关实例可供参考：

- [`JsSvg`：可缩放矢量图形（JS）（API8）](https://gitee.com/openharmony/app_samples/tree/master/UI/JsSvg)
