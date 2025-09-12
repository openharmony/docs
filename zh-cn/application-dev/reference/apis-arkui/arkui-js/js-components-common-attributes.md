# 通用属性
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @CCFFWW-->
<!--Designer: @CCFFWW-->
<!--Tester: @lxl007-->
<!--Adviser: @HelloCrease-->

>  **说明：**
>  从API version 4开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 常规属性

常规属性是指组件普遍支持的用来设置组件基本标识和外观显示特征的属性。

| 名称                        | 类型      | 默认值   | 必填   | 描述                                       |
| ------------------------- | ------- | ----- | ---- | ---------------------------------------- |
| id                        | string  | -     | 否    | 组件的唯一标识。                                 |
| style                     | string  | -     | 否    | 组件的样式声明。                                 |
| class                     | string  | -     | 否    | 组件的样式类，用于引用样式表。                          |
| ref                       | string  | -     | 否    | 用来指定指向子元素或子组件的引用信息，该引用将注册到父组件的$refs&nbsp;属性对象上。 |
| disabled                  | boolean | false | 否    | 当前组件是否被禁用，在禁用场景下，组件将无法响应用户交互。设置为true时，组件不响应交互事件。设置为false时，组件响应交互事件。            |
| data                      | string  | -     | 否    | 给当前组件设置data属性，进行相应的数据存储和读取。JS文件中：<br/>-&nbsp;在事件回调中使用&nbsp;e.target.attr.data&nbsp;读取数据，e为事件回调函数入参。<br/>-&nbsp;使用`$element`或者`$refs`获取DOM元素后，通过attr.data&nbsp;进行访问。<br/>从API&nbsp;Version&nbsp;6&nbsp;开始，建议使用data-\*。 |
| data-\*<sup>6+</sup>      | string  | -     | 否    | 给当前组件设置data-\*属性，进行相应的数据存储和读取。大小写不敏感，如data-A和data-a默认相同。JS文件中：<br/>-&nbsp;在事件回调中使用&nbsp;e.target.dataSet.a读取数据，e为事件回调函数入参。<br/>-&nbsp;使用`$element`或者`$refs`获取DOM元素后，通过dataSet.a进行访问。 |
| click-effect<sup>5+</sup> | string  | -     | 否    | 通过这个属性可以设置组件的弹性点击效果，当前支持如下三种效果：<br/>-&nbsp;spring-small：建议小面积组件设置，缩放(90%)。<br/>-&nbsp;spring-medium：建议中面积组件设置，缩放(95%)。<br/>-&nbsp;spring-large：建议大面积组件设置，缩放(95%)。 |
| dir<sup>6+</sup>          | string  | auto  | 否    | 设置元素布局模式，支持设置rtl、ltr和auto三种属性值：<br/>-&nbsp;rtl：使用从右往左布局模式。<br/>-&nbsp;ltr：使用从左往右布局模式。<br/>-&nbsp;auto：跟随系统语言环境。 |


## 渲染属性

渲染属性是指组件普遍支持的用来设置组件是否渲染的属性。

| 名称   | 类型      | 默认值  | 描述                       |
| ---- | ------- | ---- | ------------------------ |
| for  | Array   | -    | 根据设置的数据列表，展开当前元素。        |
| if   | boolean | -    | 根据设置的boolean值，添加或移除当前元素。true表示添加当前元素，false表示移除当前元素。 |
| show | boolean | -    | 根据设置的boolean值，显示或隐藏当前元素。true表示显示当前元素，false表示隐藏当前元素。 |

>  **说明：**
>  属性和样式不能混用，不能在属性字段中进行样式设置。

## 示例

### 示例1

```html
<!-- xxx.hml -->
<div id="container">
    <button class="btn" type="capsule" value="toggleDisplay" onclick="toggleDisplay"></button>
	<list class="list">
		<list-item for="{{ array }}" class="listItem">
			<text class="text" onclick="toggleShow" show="{{ visible }}"
                  if="{{ display }}">{{ $item.value }}</text>
		</list-item>
	</list>
</div>
```

```css
/* xxx.css */
#container {
    flex-direction: column;
    width: 100%;
    margin-top: 10px;
}
.text {
    font-size: 50px;
    font-weight: 500;
    margin-left: 12px;
}
.listItem {
    width: 100%;
    height: 100px;
    line-height: 60px;
    border-bottom: 1px solid #DEDEDE;
    font-size: 20px;
}
.btn{
    width: 280px;
    font-size: 26px;
    margin: 10px 0;
}
```

```js
// xxx.js
export default {
	data: {
        visible: true,
        display: true,
        title: "",
        i: 4,
        array: [
            {"value": "列表文本0"},
            {"value": "列表文本1"},
            {"value": "列表文本2"},
            {"value": "列表文本3"},
        ],
    },
    toggleShow: function() {
        this.array.push({"value": "列表文本" + this.i })
        this.i++
    },
    toggleDisplay: function() {
        this.display = !this.display
    },
}
```

![zh-cn-attributes](figures/zh-cn-attributes.gif)

### 示例2

```html
<!-- xxx.hml -->
<div class="container">
    <div>
        <text class="text1" dir='rtl' >hello world</text>
    </div>
    <div>
        <text class="text2" dir='ltr' >hello world</text>
    </div>
</div>
```

```css
/* xxx.css */
.container {
    display: flex;
    flex-direction: column;
    justify-content: center;
    align-items: center;
    width: 100%;
    height: 100%;
}
.text1{
    width: 90%;
    height: 100px;
    background-color: aqua;
}
.text2{
    width: 90%;
    height: 100px;
    background-color: blue;
}
```

![zh-cn_image1](figures/zh-cn_image1.png)