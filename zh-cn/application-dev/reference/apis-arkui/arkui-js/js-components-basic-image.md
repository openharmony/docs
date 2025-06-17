# image

>  **说明：**
>  从API version 4开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

图片组件，用来渲染展示图片。


## 子组件

不支持。


## 属性

除支持[通用属性](js-components-common-attributes.md)外，还支持如下属性：

| 名称   | 类型     | 默认值  | 必填   | 描述                                       |
| ---- | ------ | ---- | ---- | ---------------------------------------- |
| src  | string | -    | 否    | 图片的路径，支持本地路径，图片格式包括png、jpg、bmp、svg和gif。<br/>- 支持Base64字符串<sup>6+</sup>。格式为data:image/[png&nbsp;\|&nbsp;jpeg&nbsp;\|&nbsp;bmp&nbsp;\|&nbsp;webp];base64,&nbsp;[base64&nbsp;data],&nbsp;其中[base64&nbsp;data]为Base64字符串数据。<br/>- 支持dataability://的路径前缀，用于访问通过data&nbsp;ability提供的图片路径<sup>6+</sup>。 |
| alt  | string | -    | 否    | 占位图，当指定图片在加载中时显示。                        |


## 样式

除支持[通用样式](js-components-common-styles.md)外，还支持如下属性：

| 名称                           | 类型      | 默认值          | 必填   | 描述                                       |
| ---------------------------- | ------- | ------------ | ---- | ---------------------------------------- |
| object-fit                   | string  | cover        | 否    | 设置图片的缩放类型，不支持svg格式。可选值类型说明请见object-fit类型说明。 |
| match-text-direction         | boolean | false        | 否    | 图片是否跟随文字方向，不支持svg格式。<br/>默认值：false，表示图片不跟随文字方向。                  |
| fit-original-size            | boolean | false        | 否    | [image](js-components-basic-image.md#image)组件在未设置宽高的情况下是否适应图源尺寸，该属性为true时object-fit属性不生效，svg类型图源不支持该属性。<br/>默认值：false，表示[image](js-components-basic-image.md#image)组件在未设置宽高的情况下不适应图源尺寸。 |
| object-position<sup>7+</sup> | string  | 0px&nbsp;0px | 否    | 设置图片在组件内展示的位置。<br/>设置类型有两种：<br/>1.&nbsp;像素，单位px，示例&nbsp;15px&nbsp;15px&nbsp;代表X轴或者Y轴移动的位置。<br/>2.&nbsp;字符，可选值：<br/>-&nbsp;left&nbsp;图片显示在组件左侧。<br/>-&nbsp;top&nbsp;图片显示在组件顶部位置。<br/>-&nbsp;right&nbsp;图片显示在组件右侧位置。<br/>-&nbsp;bottom 图片显示在组件底部位置。 |

**表1** object-fit 类型说明

| 类型         | 描述                                   |
| ---------- | ------------------------------------ |
| cover      | 保持宽高比进行缩小或者放大，使得图片两边都大于或等于显示边界，居中显示。 |
| contain    | 保持宽高比进行缩小或者放大，使得图片完全显示在显示边界内，居中显示。   |
| fill       | 不保持宽高比进行放大缩小，使得图片填充满显示边界。            |
| none       | 保持原有尺寸进行居中显示。                        |
| scale-down | 保持宽高比居中显示，图片缩小或者保持不变。                |

>  **说明：**
>  使用svg图片资源时：
>
>  - 建议设置image组件的长宽，否则在父组件的长或宽为无穷大的场景下，svg资源将不会绘制。
>
>  - 如果svg描述中未指定相应的长宽，则svg将会填满image组件区域。
>
>  - 如果svg描述中指定了相应的长宽，和image组件本身的长宽效果如下：
>
>    1. 如果image组件本身的长宽小于svg中的长宽，svg会被裁切，仅显示左上角部分。
>
>    2. 如果image组件本身的长宽大于svg中的长宽，svg会被放置在image组件的左上角，image组件其他部分显示空白。
>
>  - 图片设置svg图源时，支持的标签范围有限，目前支持的svg标签包括svg、rect、circle、ellipse、path、line、polyline、polygon、animate、animateMotion、animateTransform。


## 事件

除支持[通用事件](js-components-common-events.md)外，还支持如下事件：

| 名称       | 参数                                       | 描述                        |
| -------- | ---------------------------------------- | ------------------------- |
| complete | {<br>&nbsp;width：width，<br>&nbsp;height：height<br>&nbsp;} | 图片成功加载时触发该回调，返回成功加载的图源尺寸。 |
| error    | {<br>&nbsp;width：width，<br>&nbsp;height：height<br>&nbsp;} | 图片加载出现异常时触发该回调，异常时长宽为零。   |

## 方法

支持[通用方法](js-components-common-methods.md)。


## 示例

```html
<!-- xxx.hml -->
<div class="container">
  <image src="common/images/example.png" style="width: 300px; height: 300px; object-fit:{{fit}}; object-position: center center; border: 1px solid red;">
  </image>
  <select class="selects" onchange="change_fit"><option for="{{fits}}" value="{{$item}}">{{$item}}</option></select>
</div>
```

```css
/* xxx.css */
.container {
  justify-content: center;
  align-items: center;
  flex-direction: column;
}
.selects{
  margin-top: 20px;
  width:300px;
  border:1px solid #808080;
  border-radius: 10px;
}
```

```js
// xxx.js
export default {
  data: {
    fit:"cover",
    fits: ["cover", "contain", "fill", "none", "scale-down"],
  },
  change_fit(e) {
    this.fit = e.newValue;
  },
}
```

![zh-cn_image_0000001127284936](figures/zh-cn_image_0000001127284936.gif)


