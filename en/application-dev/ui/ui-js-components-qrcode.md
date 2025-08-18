# &lt;qrcode&gt; Development


The **&lt;qrcode&gt;** component is used to generate and display a QR code. For details, see [qrcode](../reference/apis-arkui/arkui-js/js-components-basic-qrcode.md).


## Creating a &lt;qrcode&gt; Component

Create a **&lt;qrcode&gt;** component in the .hml file under **pages/index**.


```html
<!-- xxx.hml-->
<div class="container">
  <qrcode value="Hello"></qrcode>
</div>
```


```css
/* xxx.css */
.container {
  width: 100%;
  height: 100%;
  flex-direction: column;
  align-items: center;
  justify-content: center;
  background-color: #F1F3F5;
}
```

![en-us_image_0000001275803133](figures/en-us_image_0000001275803133.png)

> **NOTE**
>
> The **value** parameter must be set.


## Setting the Component Type

Set the **type** attribute to select the QR code type from rectangle and circle.


```html
<!-- xxx.hml-->
<div class="container">
  <select onchange="setType">
    <option for="{{bcol_list}}" value="{{$item}}">{{$item}}</option>
  </select>
  <qrcode value="Hello" type="{{qr_type}}"></qrcode>
</div>
```


```css
/* xxx.css */
.container {
  width: 100%;
  height: 100%;
  flex-direction: column;
  align-items: center;
  justify-content: center;
  background-color: #F1F3F5;
}
select{
  margin-top: 50px;
  margin-bottom: 50px;
}
```


```js
// index.js
export default {
  data: {
    qr_type: 'rect',
    bcol_list: ['rect','circle']
  },
  setType(e) {
    this.qr_type = e.newValue 
  },
}
```

![en-us_image_0000001275922965](figures/en-us_image_0000001275922965.gif)


## Setting Styles

Set the **color** and **background-color** attributes to set the color and background color of a QR code.


```html
<!-- xxx.hml-->
<div class="container">
  <qrcode value="Hello" type="rect"></qrcode>
</div>
```


```css
/* xxx.css */
.container {
  width: 100%;
  height: 100%;
  flex-direction: column;
  align-items: center;
  justify-content: center;
  background-color: #F1F3F5;
}
qrcode{
  width: 300px;
  height: 300px;
 color: blue;  background-color: #ffffff;
}
```

![en-us_image_0000001231683116](figures/en-us_image_0000001231683116.png)

> **NOTE**
> - If the values of **width** and **height** are different, the smaller value is used as the length of the QR code. The generated QR code is center displayed.
> 
> - If either **width** or **height** is set, the value is used as the length of the QR code. If neither of them is set, the default length of 200 px is used.
> 


## Example Scenario

In this example, you can bind a QR code to a text box, and change the QR code by replacing the content in the text box.


```html
<!-- xxx.hml-->
<div class="container">
  <input style="margin-bottom: 100px;" onchange="change"></input>
  <qrcode value="{{textVal}}"></qrcode>
</div>
```


```css
/* xxx.css */
.container {
  width: 100%;
  height: 100%;
  flex-direction: column;
  align-items: center;
  justify-content: center;
  background-color: #F1F3F5;
}
qrcode{
  width: 400px;
  height: 400px;
}
```


```js
// index.js
export default{
  data: {
    textVal: ''
  },
  change(e){
    this.textVal = e.value
  }
}
```

![en-us_image_0000001232002972](figures/en-us_image_0000001232002972.gif)
