# 自定义事件

子组件comp定义如下：


```html
<!-- comp.hml -->
<div class="item">  
   <text class="text-style" onclick="childClicked">点击这里查看隐藏文本</text> 
   <text class="text-style" if="{{showObj}}">hello world</text> 
</div>
```


```css
/* comp.css */
.item {  
  width: 700px;   
  flex-direction: column;   
  height: 300px;   
  align-items: center;   
  margin-top: 100px;  
} 
.text-style { 
  font-weight: 500; 
  font-family: Courier; 
  font-size: 40px;
}
```


```js
// comp.js
export default { 
  data: {  
    showObj: false,  
  },  
  childClicked () {  
    this.$emit('eventType1'); 
    this.showObj = !this.showObj;  
  },  
}
```


引入子组件的示例如下：


```html
<!-- xxx.hml --> 
<element name='comp' src='../../common/component/comp.hml'></element>  
<div class="container">  
  <comp @event-type1="textClicked"></comp>  
</div>
```


```css
/* xxx.css */
.container {  
  background-color: #f8f8ff;  
  flex: 1;  
  flex-direction: column;  
  align-content: center; 
} 
```


```js
// xxx.js
export default {    
  textClicked () {},  
}
```
