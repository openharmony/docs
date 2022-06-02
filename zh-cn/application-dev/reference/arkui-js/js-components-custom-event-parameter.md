# 事件参数

子组件也可以通过绑定的事件向上传递参数，在自定义事件上添加传递参数的示例如下：


```html
<!-- comp.hml -->
<div class="item">  
   <text class="text-style" onclick="childClicked">点击这里查看隐藏文本</text> 
   <text class="text-style" if="{{showObj}}">hello world</text> 
</div>
```


```js
// comp.js
export default { 
  childClicked () {
    this.$emit('eventType1', {text: '收到子组件参数'});
    this.showObj = !this.showObj;
  },
}
```


子组件向上传递参数text，父组件接收时通过e.detail来获取参数：


```html
<!-- xxx.hml -->
<div class="container">  
   <text>父组件：{{text}}</text> 
   <comp @event-type1="textClicked"></comp>  
</div>
```


```js
// xxx.js
export default { 
  data: {
    text: '开始',
  },
  textClicked (e) {
    this.text = e.detail.text;
  },
}
```
