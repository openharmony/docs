# 自定义组件基本用法


>  **说明：**
> 从API Version 8 开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


  自定义组件是用户根据业务需求，将已有的组件组合，封装成的新组件，可以在工程中多次调用，提高代码的可读性。自定义组件通过element引入到宿主页面，使用方法：

```html
<element name='comp' src='../../common/component/comp.hml'></element>
<div>
  <comp prop1='xxxx' @child1="bindParentVmMethod"></comp>
</div>
```

- name属性指自定义组件名称(非必填)，组件名称对大小写不敏感，默认使用小写。src属性指自定义组件hml文件路径(必填)，若没有设置name属性，则默认使用hml文件名作为组件名。

- 事件绑定：自定义组件中绑定子组件事件使用(on|\@)child1语法，子组件中通过{action:"proxy", method: "eventName"}触发事件并进行传值，父组件执行bindParentVmMethod方法并接收子组件传递的参数。


## 自定义组件配置文件标签

| 属性 | 类型 | 描述 |
| -------- | -------- | -------- |
| data | Object | 页面的数据模型，类型是对象。属性名不能以$或_开头，不要使用保留字for,&nbsp;if,&nbsp;show,&nbsp;tid。 |
| props | Array/Object | props用于组件之间的通信，可以通过&lt;tag&nbsp;xxxx='value'&gt;方式传递给组件；props名称必须用小写，不能以$或_开头，不要使用保留字for,&nbsp;if,&nbsp;show,&nbsp;tid。目前props的数据类型不支持Function。 |
