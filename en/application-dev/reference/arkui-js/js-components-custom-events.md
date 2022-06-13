# Custom Events

The following example describes how to define a child component  **comp**:

```
<!-- comp.hml -->
<div class="item">  
   <text class="text-style" onclick="childClicked">Click here to view the hidden text.</text> 
   <text class="text-style" if="{{showObj}}">hello world</text> 
</div>
```

```
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

```
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

The following example describes how to introduce the child component:

```
<!-- xxx.hml --> 
<element name='comp' src='../../common/component/comp.hml'></element>  
<div class="container">  
  <comp @event-type1="textClicked"></comp>  
</div>
```

```
/* xxx.css */
.container {  
  background-color: #f8f8ff;  
  flex: 1;  
  flex-direction: column;  
  align-content: center; 
} 
```

```
// xxx.js
export default {    
  textClicked () {},  
}
```

