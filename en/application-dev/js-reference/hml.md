# HML<a name="EN-US_TOPIC_0000001115974722"></a>

-   [HML Page Structure](#en-us_topic_0000001059340504_section1062764791514)
-   [Data Binding](#en-us_topic_0000001059340504_s8821c158917c48098219013e69129d1b)
-   [Event Binding](#en-us_topic_0000001059340504_s30850b61328e4359910467ab33b3e07d)
-   [Loop Rendering](#en-us_topic_0000001059340504_sb777d6d807fa43fea9be400b2600425b)
-   [Conditional Rendering](#en-us_topic_0000001059340504_sf7f6eab2105a4030a1f34149417d6fc5)
-   [Logic Control Block](#en-us_topic_0000001059340504_s185169def14340fcbb12c3375cb0f0bb)
-   [Template Reference](#en-us_topic_0000001059340504_section1388145672114)

The OpenHarmony Markup Language \(HML\) is an HTML-like language that allows you to build pages based on components and events. Pages built using HML have advanced capabilities such as  logic control, data binding, event binding, loop rendering, and conditional rendering.

## HML Page Structure<a name="en-us_topic_0000001059340504_section1062764791514"></a>

```
<!-- xxx.hml -->
<div class="item-container">
  <text class="item-title">Image Show</text>
  <div class="item-content">
    <image src="/common/xxx.png" class="image"></image>
  </div>
</div>
```

## Data Binding<a name="en-us_topic_0000001059340504_s8821c158917c48098219013e69129d1b"></a>

```
<!-- xxx.hml -->
<div onclick="changeText">
  <text> {{content[1]}} </text>
</div>
```

```
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

>![](public_sys-resources/icon-note.gif) **NOTE:** 
>-   To make the array data modification take effect, use the  **splice**  method to change array items.
>-   ECMAScript 6.0 syntax is not supported in HML.

## Event Binding<a name="en-us_topic_0000001059340504_s30850b61328e4359910467ab33b3e07d"></a>

The callback bound to an event receives an event object parameter, which can be used to obtain the event information.

```
<!-- xxx.hml -->
<div>
  <!-- Bind an event using @. -->
  <div @click="clickfunc"></div>
  <!-- Bind an event using on. -->
  <div onclick="clickfunc"></div>
  <!-- Bind an event callback for event bubbling.5+ -->
  <div on:touchstart.bubble="touchstartfunc"></div>
 <!-- Bind the event callback for event capturing.5+ -->
  <div on:touchstart.capture="touchstartfunc"></div>
  <!-- on:{event} is equivalent to on:{event}.bubble.5+ --> 
  <div on:touchstart="touchstartfunc"></div>
  <!-- Bind the event callback, but stop the event form bubbling upwards. 5+
  <div grab:touchstart.bubble="touchstartfunc"></div>
  <!-- Bind the event callback, but stop the event from being captured during downward transfer.5+ -->
  <div grab:touchstart.capture="touchstartfunc"></div>
  <!-- grab:{event} is equivalent to grab:{event}.bubble.5+ -->
  <div grab:touchstart="touchstartfunc"></div>
</div>
```

```
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

-   Example Code

    ```
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

    ```
    /* xxx.js */
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

    ```
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


## Loop Rendering<a name="en-us_topic_0000001059340504_sb777d6d807fa43fea9be400b2600425b"></a>

```
<!-- xxx.hml -->
<div class="array-container">
  <!-- div loop rendering -->
  <!-- By default, $item indicates the element in the array, and $idx indicates the index of the element in the array. -->
  <div for="{{array}}" tid="id" onclick="changeText">
    <text>{{$idx}}.{{$item.name}}</text>
  </div>
  <!-- Define the name for an element variable. -->
  <div for="{{value in array}}" tid="id" onclick="changeText">    
    <text>{{$idx}}.{{value.name}}</text>
  </div>
  <!-- Define an element variable and its index name. -->
  <div for="{{(index, value) in array}}" tid="id" onclick="changeText">    
    <text>{{index}}.{{value.name}}</text>
  </div>
</div>
```

```
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

The  **tid**  attribute accelerates the  **for**  loop and improves the re-rendering efficiency when data in a loop changes.

The  **tid**  attribute specifies the unique ID of each element in the array. If it is not specified, the index of each element in the array is used as the ID. For example,  **tid="id"**  indicates that the  **id**  attribute of each element is its unique ID.

The  **for**  loop supports the following statements:

-   for="array":  **array**  is an array object, whose element variable is  **$item**  by default.
-   for="v in array":  **v**  is a custom element variable, whose index is  **$idx**  by default.
-   for="\(i, v\) in array":  **i**  indicates the element index, and  **v**  indicates the element variable. All elements of the array object will be looped through.

>![](public_sys-resources/icon-note.gif) **NOTE:** 
>-   Each element in the array must have the data attribute specified by  **tid**. Otherwise, an exception may occur.
>-   The attribute specified by  **tid**  in the array must be unique. Otherwise, performance loss occurs. In the above example, only  **id**  and  **name**  can be used as  **tid**  because they are unique fields.
>-   The  **tid**  field does not support expressions.

## Conditional Rendering<a name="en-us_topic_0000001059340504_sf7f6eab2105a4030a1f34149417d6fc5"></a>

There are two ways to implement conditional rendering:  **if-elif-else**  or  **show**. In  **if-elif-else**, when the  **if**  statement evaluates to  **false**, the component is not built in the VDOM and is not rendered. For  **show**, when show is  **false**, the component is not rendered but is built in the VDOM. In addition, the  **if-elif-else**  statements must be used in sibling nodes. Otherwise, the compilation fails. The following example uses both ways to implement conditional rendering:

```
<!-- xxx.hml -->
<div class="container">
  <button class="btn" type="capsule" value="toggleShow" onclick="toggleShow"></button>
  <button class="btn" type="capsule" value="toggleDisplay" onclick="toggleDisplay"></button>
  <text if="{{show}}"> Hello-One </text>
  <text elif="{{display}}"> Hello-Two </text>
  <text else> Hello-World </text>
</div>
```

```
// xxx.css
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

```
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

In the optimized rendering \(**show**\), if  **show**  is  **true**, the node is rendered properly; if it is  **false**, the display style will be  **none**.

```
<!-- xxx.hml -->
<div class="container">
  <button class="btn" type="capsule" value="toggle" onclick="toggle"></button>
  <text show="{{visible}}" > Hello World </text>
</div>
```

```
// xxx.css
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

```
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

>![](public_sys-resources/icon-note.gif) **NOTE:** 
>Do not use  **for**  and  **if**  attributes at the same time in an element.

## Logic Control Block<a name="en-us_topic_0000001059340504_s185169def14340fcbb12c3375cb0f0bb"></a>

**<block\>**  makes loop rendering and conditional rendering more flexible. A  **<block\>**  will not be compiled as a real component. Note that the  **<block\>**  tag supports only the  **for**  and  **if**  attributes.

```
<!-- xxx.hml -->
<list>
  <block for="glasses">
    <list-item type="glasses">
      <text>{{$item.name}}</text>
    </list-item>
    <block for="$item.kinds">
      <list-item type="kind">
        <text>{{$item.color}}</text>
      </list-item>
    </block>
  </block>
</list>
```

```
// xxx.js
export default {
  data: {
    glasses: [
      {name:'sunglasses', kinds:[{name:'XXX',color:'XXX'},{name:'XXX',color:'XXX'}]},
      {name:'nearsightedness mirror', kinds:[{name:'XXX',color:'XXX'}]},
    ],
  },
}
```

## Template Reference<a name="en-us_topic_0000001059340504_section1388145672114"></a>

HML supports using elements to reference template files. For details, see  [Custom Components](basic-usage.md#EN-US_TOPIC_0000001162494627).

```
<!-- template.hml -->
<div class="item"> 
  <text>Name: {{name}}</text>
  <text>Age: {{age}}</text>
</div>
```

```
<!-- index.hml -->
<element name='comp' src='../../common/template.hml'></element>
<div>
  <comp name="Tony" age="18"></comp>
</div>
```

