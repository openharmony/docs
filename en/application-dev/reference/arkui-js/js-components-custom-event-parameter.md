# Event Parameter

A child component can also pass parameters to an upper-layer component through the bound event. The following example describes how to pass parameters through the custom event:

```
<!-- comp.hml -->
<div class="item">  
   <text class="text-style" onclick="childClicked">Click here to view the hidden text.</text> 
   <text class="text-style" if="{{showObj}}">hello world</text> 
</div>
```

```
// comp.js
export default { 
  childClicked () {
     this.$emit('eventType1', {text: 'Receive the parameters from the child component.'});
    this.showObj = !this.showObj;
  },
}
```

In the following example, the child component passes the  **text**  parameter to the parent component, and the parent component obtains the parameter through  **e.detail**:

```
<!-- xxx.hml -->
<div class="container">  
   <text>Parent component: {{text}}</text> 
   <comp @event-type1="textClicked"></comp>  
</div>
```

```
// xxx.js
export default { 
  data: {
     text: 'Start',
  },
  textClicked (e) {
    this.text = e.detail.text;
  },
}
```

