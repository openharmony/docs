# Custom Events


Custom components support custom events, whose **action** is **proxy** and name is specified by **method**. A service widget page that uses a custom component can register an event callback corresponding to the custom event name. When the custom event in the custom component is triggered, the registered callback will be invoked.


>  **NOTE**
>
>  The event name cannot contain uppercase letters.


## Example of the **comp** Subcomponent


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


## Example of the Service Widget Page


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
