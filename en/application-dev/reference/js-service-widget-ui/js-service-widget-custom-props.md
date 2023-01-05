# Props


You can use **props** to declare attributes of a custom component. The attributes can be used by a parent component to pass parameters to a child component. An example will be provided below to show you how to pass parameters through the parent component.

## Default Value

You can set the default value for a child component attribute via **default**. The default value is used if the parent component does not have **default** set. In this case, the **props** attribute must be in object format instead of an array.



```html
<!-- comp.hml -->
<div class="container">
    <div class="row-1">
        <div class="box-1">
            <text>xiaoziti</text>
        </div>
        <div class="box-2">
            <text>{{text}}</text>
        </div>
        <div class="box-3">
            <text>{{textdata[0]}}</text>
        </div>
    </div>
    <div class="row-2" if="true">
        <button value="{{progress}}"></button>
    </div>
    <div class="row-3" if="true">
        <button onclick="buttonClicked" value="click"></button>
    </div>
</div>
```



```json
{
  "data": {
    "progress": {
      "default": "80"
    }
  },
  "props": {
    "textdata": {
      "default": ["a","b"]
    },
    "progress": {
      "default": 60
    },
    "text": {
      "default": "ha"
    }
  },
  "actions": {
    "buttonClicked": {
      "action": "proxy",
      "method": "event_1"
    }
  }
}
```



```html
<!-- xxx.hml -->
<element name='comp' src='../../common/customComponent/customComponent.hml'></element>

<div class="container">
    <comp progress="{{clicknow}}" textdata="{{texts}}" if="false" @event_1="click"></comp>
</div>
```


## Unidirectional Value Transfer

Data can be transferred only from the parent component to child components. You are not allowed to change the value passed to the child component. However, you can receive the value passed by **props** as a default value in **data**, and then change the **data** value.
