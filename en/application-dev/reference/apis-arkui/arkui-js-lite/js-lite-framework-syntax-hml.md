# HML


HML is an HTML-like language that allows you to build pages based on components and events. Pages built using HML have advanced capabilities such as data binding, event binding, loop rendering, and conditional rendering.


## HML Page Structure


```html
<!-- xxx.hml -->
<div class="item-container">
  <text class="item-title">Image Show</text>
  <div class="item-content">
    <image src="/common/xxx.png" class="image"></image>
  </div>
</div>
```


## Data Binding


```html
<!-- xxx.hml -->
<div onclick="changeText">
  <text> {{content[1]}} </text>
</div>
```


```js
// xxx.js
export default {
  data: {
    content: ['Hello World!', 'Welcome to my world!']
  },
  changeText: function() {
    this.content.splice(1, 1, this.content[0]);
  }
}
```

>  **NOTE**
>  - To make the array data modification take effect, use the **splice** method to change array items.
>
>  - ECMAScript 6.0 syntax is not supported in HML.


## Event Binding

The callback bound to an event receives an event object parameter, which can be used to obtain the event information.


```html
<!-- xxx.hml -->
<div>
  <!-- Bind an event using @. -->
  <div @click="clickfunc"></div>
  <!-- Bind an event using on. -->
  <div onclick="clickfunc"></div>
  <!--  Bind an event using on.<sup>5+</sup> This statement is not recommended. -->
  <div onclick="clickfunc"></div>
  <!-- Bind an event callback for event bubbling.<sup>5+</sup>-->
  <div on:click.bubble="clickfunc"></div>
  <!-- on:{event} is equivalent to on:{event}.bubble.<sup>5+</sup> -->
  <div on:click="clickfunc"></div>
  <!-- Bind an event callback, but stop the event from bubbling upwards.<sup>5+</sup> -->
  <div grab:click.bubble="clickfunc"></div>
  <!-- grab:{event} is equivalent to grab:{event}.bubble.<sup>5+</sup> -->
  <div grab:click="clickfunc"></div>
</div>
```


```js
// xxx.js
export default {
  data: {
    obj: '',
  },
  clickfunc: function(e) {
    this.obj = 'Hello World';
    console.log(e);
  },
}
```

>  **NOTE**
>
>  Event bubbling is supported since API version 5. After you upgrade the SDK and run an existing JavaScript application, events bound using a traditional statement (such as **onclick**) will not bubble. However, if you use the new SDK to repack the JavaScript application, such events will bubble. To avoid service logic errors, replace the traditional statement with one supported by the new SDK. For example, replace **onclick** with **grab:click**.

**Example**

```html
<!-- xxx.hml -->
<div class="container">
  <text class="title">{{count}}</text>
  <div class="box">
    <input type="button" class="btn" value="increase" onclick="increase" />
    <input type="button" class="btn" value="decrease" @click="decrease" />
    <!-- Pass additional parameters. -->
    <input type="button" class="btn" value="double" @click="multiply(2)" />
    <input type="button" class="btn" value="decuple" @click="multiply(10)" />
    <input type="button" class="btn" value="square" @click="multiply(count)" />
  </div>
</div>
```


```js
// xxx.js 
export default {
  data: {
    count: 0
  },
  increase() {
    this.count++;
  },
  decrease() {
    this.count--;
  },
  multiply(multiplier) {
    this.count = multiplier * this.count;
  }
};
```


```css
/* xxx.css */
.container {
    display: flex;
    flex-direction: column;
    justify-content: center;
    align-items: center;
    left: 0px;
    top: 0px;
    width: 454px;
    height: 454px;
}
.title {
    font-size: 30px;
    text-align: center;
    width: 200px;
    height: 100px;
}
.box {
    width: 454px;
    height: 200px;
    justify-content: center;
    align-items: center;
    flex-wrap: wrap;
}
.btn {
    width: 200px;
    border-radius: 0;
    margin-top: 10px;
    margin-left: 10px;
}
```


## Loop Rendering


```html
<!-- xxx.hml -->
<div class="array-container">
  <!-- div loop rendering -->
  <!-- By default, $item indicates the element in the array, and $idx indicates the index of the element in the array. -->
    <div class="item-container" for="{{array}}" tid="id" onclick="changeText">
        <text>{{$idx}}.{{$item.name}}</text>
    </div>
  <!-- Define the name for an element variable. -->
    <div class="item-container" for="{{value in array}}" tid="id" onclick="changeText">
        <text>{{$idx}}.{{value.name}}</text>
    </div>
  <!-- Define an element variable and its index name. -->
    <div class="item-container" for="{{(index, value) in array}}" tid="id" onclick="changeText">
        <text>{{index}}.{{value.name}}</text>
    </div>
</div>
```


```js
// xxx.js
export default {
  data: {
    array: [
      {id: 1, name: 'jack', age: 18}, 
      {id: 2, name: 'tony', age: 18},
    ],
  },
  changeText: function() {
    if (this.array[1].name === "tony"){
      this.array.splice(1, 1, {id:2, name: 'Isabella', age: 18});
    } else {
      this.array.splice(2, 1, {id:3, name: 'Bary', age: 18});
    }
  },
}
```


```css
.array-container {
    width: 100%;
    height: 100%;
    justify-content: center;
    align-items: center;
    flex-direction: column;
}

.item-container {
    margin-top: 10px;
    width: 200px;
    height: 50px;
    flex-direction: column;
}
```


The **tid** attribute accelerates the **for** loop and improves the re-rendering efficiency when data in a loop changes. The **tid** attribute specifies the unique ID of each element in the array. If it is not specified, the index of each element in the array is used as the ID. For example, **tid="id"** indicates that the **id** attribute of each element is its unique ID. The **for** loop supports the following statements:

- for="array": **array** is an array object, whose element variable is **$item** by default.

- for="v in array": **v** is a custom element variable, whose index is **$idx** by default.

- for="(i, v) in array": **i** indicates the element index, and **v** indicates the element variable. All elements of the array object will be looped through.

>  **NOTE**
>
> - Each element in the array must have the data attribute specified by **tid**. Otherwise, an exception may occur.
>
> - The attribute specified by **tid** in the array must be unique. Otherwise, performance loss occurs. In the above example, only **id** and **name** can be used as **tid** because they are unique fields.
>
> - The **tid** field does not support expressions.


## Conditional Rendering

There are two ways to implement conditional rendering: **if-elif-else** or **show**. In **if-elif-else**, when the **if** statement evaluates to **false**, the component is not built in the VDOM and is not rendered. For **show**, when show is **false**, the component is not rendered but is built in the VDOM. In addition, the **if-elif-else** statements must be used in sibling nodes. Otherwise, the compilation fails. The following example uses both ways to implement conditional rendering:


```html
<!-- xxx.hml -->
<div class="container">
  <button class="btn" type="capsule" value="toggleShow" onclick="toggleShow"></button>
  <button class="btn" type="capsule" value="toggleDisplay" onclick="toggleDisplay"></button>
  <text if="{{show}}"> Hello-One </text>
  <text elif="{{display}}"> Hello-Two </text>
  <text else> Hello-World </text>
</div>
```


```css
/* xxx.css */
.container{
  flex-direction: column;
  align-items: center;
}
.btn{
  width: 280px;
  font-size: 26px;
  margin: 10px 0;
}
```


```js
// xxx.js
export default {
  data: {
    show: false,
    display: true,
  },
  toggleShow: function() {
    this.show = !this.show;
  },
  toggleDisplay: function() {
    this.display = !this.display;
  }
}
```

In the optimized rendering (**show**), if **show** is **true**, the node is rendered properly; if it is **false**, the display style will be **none**.


```html
<!-- xxx.hml -->
<div class="container">
  <button class="btn" type="capsule" value="toggle" onclick="toggle"></button>
  <text show="{{visible}}" > Hello World </text>
</div>
```


```css
/* xxx.css */
.container{
  flex-direction: column;
  align-items: center;
}
.btn{
  width: 280px;
  font-size: 26px;
  margin: 10px 0;
}
```


```js
// xxx.js
export default {
  data: {
    visible: false,
  },
  toggle: function() {
    this.visible = !this.visible;
  },
}
```

>  **NOTE**
>
>  Do not use **for** and **if** attributes at the same time in an element.
