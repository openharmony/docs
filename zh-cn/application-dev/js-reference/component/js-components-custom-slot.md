# slot插槽<a name="ZH-CN_TOPIC_0000001164290730"></a>

-   [默认插槽](#zh-cn_topic_0000001127284840_section68133181214)
-   [具名插槽](#zh-cn_topic_0000001127284840_section18337143291211)

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从API Version 7 开始支持。

## 默认插槽<a name="zh-cn_topic_0000001127284840_section68133181214"></a>

自定义组件中通过slot标签来承载父组件中定义的内容，使用slot标签可以更加灵活的控制自定义组件的内容元素，使用方式如下：

```
<!-- comp.hml -->
<div class="item">  
   <text class="text-style">下面使用父组件定义的内容</text> 
   <slot></slot> 
</div>
```

引用该自定义组件方式如下：

```
<!-- xxx.hml --> 
 <element name='comp' src='../../common/component/comp.hml'></element>  
 <div class="container">  
   <comp>
     <text class="text-style">父组件中定义的内容</text> 
   </comp>  
 </div>
```

## 具名插槽<a name="zh-cn_topic_0000001127284840_section18337143291211"></a>

当自定义组件中需要使用多个插槽时，可通过对插槽命名的方式进行区分，当填充插槽内容时，通过声明插槽名称，将内容加到对应的插槽中。

```
<!-- comp.hml -->
<div class="item">  
   <text class="text-style">下面使用父组件定义的内容</text> 
   <slot name="first"></slot>
   <slot name="second"></slot> 
</div>
```

引用该自定义组件方式如下：

```
<!-- xxx.hml --> 
 <element name='comp' src='../../common/component/comp.hml'></element>  
 <div class="container">  
   <comp>
     <text class="text-style" slot="second">插入第二个插槽中</text> 
     <text class="text-style" slot="sfirst">插入第一个插槽中</text>
   </comp>  
 </div>
```

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>name 和 slot 属性不支持绑定动态数据。

