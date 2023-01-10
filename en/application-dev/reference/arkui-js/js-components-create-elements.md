# Dynamic Component Creation

You can dynamically add components with specified attributes and styles to pages.

>  **NOTE**
>
>  This API is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


## createElement

createElement(tag: string): Element

Creates a component object.

**Parameters**

| Name    | Type      | Mandatory  | Description     |
| ------- | ------------ | ---- | ------- |
| tag | string | Yes   | Component name.|

**Return value**

| Type       | Description           |
| ----------- | ------------- |
| Element | Component object corresponding to the value of **tag**.|

```js
let newImage = dom.createElement('image')
```


## setAttribute

setAttribute(name: string, value: string): void

Dynamically sets the attributes of this component.

**Parameters**

| Name    | Type      | Mandatory  | Description     |
| ------- | ------------ | ---- | ------- |
| name | string | Yes   | Attribute name.|
| value | string | Yes   | Attribute value.|

```js
newImage.setAttribute('src', 'common/testImage.jpg')
```


## setStyle

setStyle(name: string, value: string): boolean

Dynamically sets the style of this component.

**Parameters**

| Name    | Type      | Mandatory  | Description     |
| ------- | ------------ | ---- | ------- |
| name | string |  Yes   | Style name.|
| value | string |  Yes   | Style value.|

**Return value**

| Type       | Description           |
| ----------- | ------------- |
| boolean | Returns **true** if the setting is successful; returns **false** otherwise.|

```js
newImage.setStyle('width', '120px')
```


## addChild

addChild(child: Element): void

Adds a dynamically created component to the parent component.

**Parameters**

| Name    | Type      | Mandatory  | Description   |
| ------- | ------------ | ---- | ------- |
| child | Element | Yes   | Component object.|

```js
newDiv.addChild(newImage)
```


## Example

```html
<!-- xxx.hml -->
<div class="container">
  <div id="parentDiv" class="parent"></div>
  <button onclick="appendDiv" class="btn">Dynamically create a <div> component.</button>
  <button onclick="appendImage" class="btn">Dynamically create an <image> component and add it to the newly created <div> component.</button>
</div>
```

```css
/* xxx.css */
.container {
  flex-direction: column;
  align-items: center;
  width: 100%;
}

.parent {
  flex-direction: column;
}

.btn {
  width: 70%;
  height: 60px;
  margin: 15px;
}
```

```js
// xxx.js
let newDiv = null
let newImage = null

export default {
  appendDiv() {
    let parent = this.$element('parentDiv')
    newDiv = dom.createElement('div')
    newDiv.setStyle('width', '150px')
    newDiv.setStyle('height', '150px')
    newDiv.setStyle('backgroundColor', '#AEEEEE')
    newDiv.setStyle('marginTop', '15px')
    parent.addChild(newDiv)
  },
  appendImage() {
    newImage = dom.createElement('image')
    newImage.setAttribute('src', 'common/testImage.jpg')
    newImage.setStyle('width', '120px')
    newImage.setStyle('height', '120px')
    newDiv.addChild(newImage)
  }
}
```
