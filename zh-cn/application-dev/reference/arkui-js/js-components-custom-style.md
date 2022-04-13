​	

# 继承样式 <sup>9+</sup>

自定义组件可以通过设置inhert-class属性来继承父组件的样式。目前只支持class选择器，多个class之间用空格分隔。

代码示例如下：

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
