# slot

>  **NOTE**
>
>  The APIs of this module are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Default Slot

You can use the **\<slot>** tag to create a slot inside a custom component to fill the content defined in the parent component. The sample code is as follows:

```html
<!-- comp.hml -->
<div class="item">  
   <text class="text-style">The following uses the content defined in the parent component.</text> 
   <slot></slot> 
</div>
```

The following references the custom component:
```html
<!-- xxx.hml --> 
 <element name='comp' src='../common/component/comp.hml'></element>  
 <div class="container">  
   <comp>
     <text class="text-style">Content defined in the parent component</text>
   </comp>  
 </div>
```


## Named Slot

When multiple slots are needed inside a custom component, you can name them, so that you can specify the slot in which you want to fill content by setting the **\<name>** attribute.

```html
<!-- comp.hml -->
<div class="item">  
   <text class="text-style">The following uses the content defined in the parent component.</text> 
   <slot name="first"></slot>
   <slot name="second"></slot> 
</div>
```

The following references the custom component:
```html
<!-- xxx.hml --> 
 <element name='comp' src='../common/component/comp.hml'></element>  
 <div class="container">  
   <comp>
     <text class="text-style" slot="second">Fill in the second slot.</text> 
     <text class="text-style" slot="first">Fill in the first slot.</text>
   </comp>  
 </div>
```

>  **NOTE**
>
>  **\<name>** and **\<slot>** do not support dynamic data binding.
