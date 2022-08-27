# Adding Interactions

You can make the UI interactive by binding events to components. This section describes how to bind **\<div>**, **\<text>**, and **\<image>** components to click events to build a thumb up button, as shown in the following figure.

**Figure 1** Thumb up button effect

![en-us_image_0000001267647901](figures/en-us_image_0000001267647901.gif)


The thumb up button is implemented by binding a click event to a &lt;div&gt; component. The \<div> component contains an **\<image>** component and a \<text> component.


- The **\<image>** component is used to display unselected and selected (highlighted) thumbs up images. The click event function alternately updates the paths of the images that are liked and not liked.

- The **\<text>** component is used to display the number of thumbs up. The number is updated in the function of the click event.


The click event calls the **likeClick()** function defined in the .js file. You can change the value of **isPressed** to update the image component. If the value of **isPressed** is **true**, the number of thumbs up is incremented by 1. The **likeClick()** function takes effect on the **\<div>** component in the .hml file. The style of each child component for the thumbs up button is set in the .css file. The following is an example:


```html
<!-- xxx.hml -->
<!-- Thumb up button -->
<div>
  <div class="like" onclick="likeClick">
    <image class="like-img" src="{{likeImage}}" focusable="true"></image>
    <text class="like-num" focusable="true">{{total}}</text>
  </div>
</div>
```


```css
/* xxx.css */
.like {
  width: 104px;
  height: 54px;
  border: 2px solid #bcbcbc;
  justify-content: space-between;
  align-items: center;
  margin-left: 72px;
  border-radius: 8px;
}
.like-img {
  width: 33px;
  height: 33px;
  margin-left: 14px;
}
.like-num {
  color: #bcbcbc;
  font-size: 20px;
  margin-right: 17px;
}
```


```js
// xxx.js
export default {
  data: {
    likeImage: '/common/unLike.png',
    isPressed: false,
    total: 20,
  },
  likeClick() {
    var temp;
    if (!this.isPressed) {
      temp = this.total + 1;
      this.likeImage = '/common/like.png';
    } else {
      temp = this.total - 1;
      this.likeImage = '/common/unLike.png';
    }
    this.total = temp;
    this.isPressed = !this.isPressed;
  },
}
```


ArkUI also provides many form components, such as switches, tags, and pickers, for you to flexibly lay out pages and improve their interactions with users. For details, see **Container Components**.
