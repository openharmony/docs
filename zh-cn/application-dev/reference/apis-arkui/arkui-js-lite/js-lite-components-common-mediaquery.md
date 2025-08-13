# 媒体查询
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @lanshouren-->
<!--SE: @lanshouren-->
<!--TSE: @liuli0427-->

>  **说明：**
>
>  - 从API version 8 开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
>  - media属性值默认为设备的真实尺寸大小、物理像素和真实的屏幕分辨率。


媒体查询（Media Query）应用十分广泛，开发者经常需要根据设备的大致类型或者特定的特征和设备参数（例如屏幕分辨率）来修改应用的样式。使用媒体查询针对设备和应用的属性信息，可以设计出相匹配的布局样式。


## CSS语法规则

使用@media来引入查询语句，具体规则如下：

```
@media [media-type] [and|or] [(media-feature)] {
  CSS-Code;
}
```

@media screen and (round-screen: true) { … } ： 当设备屏幕是圆形时条件成立

@media (max-height: 454) { … } ：范围查询，CSS level 3 写法

>  **说明：**
>
>  - 不支持&lt;=，&gt;=，&lt;，&gt;操作符;
>  - api 9开始才支持多重 () 嵌套使用；
>  - media语句整体长度不能超过 512 个字符；
>  - 单个media条件长度不能超过32个字符；


## 媒体类型

| 类型     | 说明             |
| ------ | -------------- |
| screen | 按屏幕相关参数进行媒体查询。 |


## 媒体逻辑操作

媒体逻辑操作符：and、or<sup>9+</sup>用于构成媒体查询语句，详细解释说明如下表。

**表1** 媒体逻辑操作符

| 类型              | 说明                                       |
| --------------- | ---------------------------------------- |
| and             | 将多个媒体特征（Media&nbsp;Feature）以“与”的方式连接成一个媒体查询，只有当所有媒体特征都为true，查询条件成立。另外，它还可以将媒体类型和媒体功能结合起来。<br/>例如：screen&nbsp;and&nbsp;(device-type:&nbsp;liteWearable)&nbsp;and&nbsp;(max-height:&nbsp;454)&nbsp;表示当设备类型是智能穿戴同时应用的最大高度小于等于454个像素单位时成立。 |
| or<sup>9+</sup> | 将多个媒体特征以“或”的方式连接成一个媒体查询，如果存在结果为true的媒体特征，则查询条件成立。<br/>例如：screen&nbsp;and&nbsp;(max-height:&nbsp;454) &nbsp;or&nbsp;&nbsp;（round-screen：true）表示当应用高度小于等于454个像素单位或者设备屏幕是圆形时，条件成立。 |




## 媒体特征

| 类型               | 说明                                       |
| ---------------- | ---------------------------------------- |
| height           | 应用页面显示区域的高度。                             |
| min-height       | 应用页面显示区域的最小高度。                           |
| max-height       | 应用页面显示区域的最大高度。                           |
| width            | 应用页面显示区域的宽度。                             |
| min-width        | 应用页面显示区域的最小宽度。                           |
| max-width        | 应用页面显示区域的最大宽度。                           |
| aspect-ratio     | 应用页面显示区域的宽度与高度的比值。<br/>例如：aspect-ratio: 1/2 |
| min-aspect-ratio | 应用页面显示区域的宽度与高度的最小比值。                     |
| max-aspect-ratio | 应用页面显示区域的宽度与高度的最大比值。                     |
| round-screen     | 屏幕类型，圆形屏幕为 true，&nbsp;非圆形屏幕为&nbsp;false。 |


## 通用媒体特征示例代码

多个.container中定义的属性个数及类型必须保持一致，否则可能导致显示异常。

```html
<!-- xxx.hml -->
<div>
  <div class="container">
    <text class="title">Hello World</text>
  </div>
</div>
```

```css
/* xxx.css */
.container {
  width: 300px;
  height: 600px;
  background-color: #008000;
}
.title {
    font-size: 30px;
    text-align: center;
}
@media (device-type: smartVision) {
  .container {
    width: 500px;
    height: 500px;
    background-color: #fa8072;
  }
} 
@media (device-type: liteWearable) {
  .container {
    width: 300px;
    height: 300px;
    background-color: #008b8b;
  }
} 
```
