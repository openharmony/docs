# Props


自定义组件可以通过props声明属性，父组件通过设置属性向子组件传递参数。通过父组件向下传递参数的示例如下：

## 添加默认值

子组件可以通过固定值default设置默认值，当父组件没有设置该属性时，将使用其默认值。此情况下props属性必须为对象形式，不能用数组形式，示例如下：



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


## 数据单向性

父子组件之间数据的传递是单向的，只能从父组件传递给子组件，子组件不能直接修改父组件传递下来的值，可以将props传入的值用data接收后作为默认值，再对data的值进行修改。

更多说明请参考[props](../arkui-js/js-components-custom-props.md)。