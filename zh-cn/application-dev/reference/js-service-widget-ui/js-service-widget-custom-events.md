# 自定义事件


自定义组件内支持自定义事件，该事件的标识需要action类型指定为proxy，事件名则通过method指定。使用该自定义组件的卡片页面可以通过该事件名注册相应的事件回调，当自定义组件内该自定义事件触发时，会触发卡片页面上注册的回调事件。


>  **说明：**
>
>  事件名不支持大写字母。


## 子组件comp示例：


```html
<!-- comp.hml -->
<div class="container">
    <div class="row-3" if="true">
        <button onclick="buttonClicked" value="click"></button>
    </div>
</div>
```



```css
/* comp.css */
.container {
    flex-direction:column;
    background-color: green;
    width: 100%;
    height: 100%;
}

.row-3 {
    width: 100%;
    height: 50px;
    background-color: orange;
    font-size:15px;
}
```



```json
{
    "data": {
    },
    "actions": {
        "buttonClicked": {
            "action": "proxy",        
            "method":"event_1"
        }
    }
}
```


## 卡片页面示例


```html
<!-- xxx.hml --> 
<element name='comp' src='../../common/customComponent/customComponent.hml'></element>

<div class="container">
    <comp @event_1="click"></comp>
    <button value="parentClick" @click="buttonClick"></button>
</div>
```



```css
/* xxx.css */
.container {
  background-color: red;
  height: 500px;
  width: 500px;
}
```



```json
{
  "data": {
  },
  "actions": {
    "click": {
      "action": "message",
      "params": {
        "message": "click event"
      }
    },
    "buttonClick": {
      "action": "message",
      "params": {
        "message": "click event 2"
      }
    }
  }
}
```
