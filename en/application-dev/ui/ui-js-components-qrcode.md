# qrcode Development

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @Zhang-Dong-hui-->
<!--Designer: @xiangyuan6-->
<!--Tester: @jiaoaozihao-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=9a5da59cdf4f4c3dc0f87035f85ddf06f80ecfc4 translatedAt=2026-08-05T10:13:42.659Z pushedAt=2026-08-06T07:16:40.228Z -->

The **\<qrcode>** component is used to generate and display a QR code. For details, see [qrcode](../reference/apis-arkui/arkui-js/js-components-basic-qrcode.md).

## Creating a \<qrcode> Component

Create a **\<qrcode>** component in the .hml file under **pages/index**.

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

![qrcode-Component](figures/qrcode-Component.png)

> **NOTE**
>
> The **value** attribute is mandatory and must be specified.

## Setting the Component Type

Set the **type** attribute to select the QR code type, such as rectangle or circle.

```html
<!-- xxx.hml-->
<div class="container">
  <select onchange="settype">
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
  settype(e) {
    this.qr_type = e.newValue 
  },
}
```

![Component-Type](figures/Component-Type.gif)

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

![Setting-Styles](figures/Setting-Styles.png)

> **NOTE**
> - If the values of **width** and **height** are different, the smaller value is used as the length of the QR code. The generated QR code is displayed centrally.
>
> - If either **width** or **height** is set, the value is used as the length of the QR code. If neither of them is set, the default length of 200 px is used.
>

## Example Scenarios

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
export default {
  data: {
    textVal: ''
  },
  change(e){
    this.textVal = e.value
  }
}
```

![Example-Scenarios](figures/Example-Scenarios.gif)