​	

# 继承样式 <sup>9+</sup>

> ![icon-note.gif](D:/git/doc/docs/zh-cn/application-dev/reference/arkui-js/public_sys-resources/icon-note.gif) **说明：**
> 从api version 9开始支持。

自定义组件具有inhert-class属性，定义如下：

| 名称                      | 类型   | 默认值 | 必填 | 描述                                                   |
| ------------------------- | ------ | ------ | ---- | ------------------------------------------------------ |
| inhert-class<sup>9+</sup> | string | -      | 否   | 从父组件继承的class样式，多个class样式之间用空格分隔。 |

可以通过设置inhert-calss属性来继承父组件的样式，代码示例如下：

自定义组件的hml文件，其中fatherclass1和fatherclass2是从父组件继承的样式。

```js
<!--comp.hml-->
<div class="item">
    <text class="fatherclass1">继承父组件的样式1</text>
    <text class="fatherclass2">继承父组件的样式2</text>
</div>
```



父页面的hml文件，其中comp自定组件通过inhert-class属性，继承了父组件的fatherclass1和fatherclass2样式。

```html
<!-- xxx.hml -->
<element name='comp' src='../../common/component/comp.hml'></element>

<div class="container">
    <comp inhert-class="fatherclass1 fatherclass2" ></comp>
</div>
```



父页面的css文件

```html
// xxx.css
.fatherclass1 {
    background-color:red;
    border:2px;
}
.fatherclass2 {
    background-color:green;
    border:2px;
}
```



<div class="container">
    <comp title="自定义组件" inhert-class="fatherclass1" ></comp>
</div>
