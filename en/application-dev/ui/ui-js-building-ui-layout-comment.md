# Adding a Comment


After a user enters a comment and clicks the submit button, the content is displayed in the comment area. The user can click the delete button to delete the current comment and enter another comment again.


To set such a comment area on a page, you need to associate a click event with **\<div>**, **\<text>**, and **\<input>**. You can use the **\<input>** component to obtain the comment entered by a user, use the **\<text>** component to display the comment, and use commentText to mark the **\<text>** component (controlled by the if attribute). Associate the click event with the **\<text>** component that contains Done and Delete to update the **commentText** and **inputValue**. The following is an example:

```html
<!-- xxx.hml -->
<div class="container">
  <text class="comment-title">Comment</text>
  <div if="{{!commentText}}">
    <input class="comment" value="{{inputValue}}" onchange="updateValue()"></input>
    <text class="comment-key" onclick="update" focusable="true">Done</text>
  </div>
  <div if="{{commentText}}">
    <text class="comment-text" focusable="true">{{inputValue}}</text>
    <text class="comment-key" onclick="update" focusable="true">Delete</text>
  </div>
</div>
```


```css
/* xxx.css */
.container {
  margin-top: 24px;
  background-color: #ffffff;
}
.comment-title {
  font-size: 40px;
  color: #1a1a1a;
  font-weight: bold;
  margin-top: 40px;
  margin-bottom: 10px;
}
.comment {
  width: 550px;
  height: 100px;
  background-color: lightgrey;
}
.comment-key {
  width: 150px;
  height: 100px;
  margin-left: 20px;
  font-size: 32px;
  color: #1a1a1a;
  font-weight: bold;
}
.comment-key:focus {
  color: #007dff;
}
.comment-text {
  width: 550px;
  height: 100px;
  text-align: left;
  line-height: 35px;
  font-size: 30px;
  color: #000000;
  border-bottom-color: #bcbcbc;
  border-bottom-width: 0.5px;
}
```


```js
// xxx.js
export default {
  data: {
    inputValue: '',
    commentText: false,
  },
  update() {
    this.commentText = !this.commentText;
  },
  updateValue(e) {
    this.inputValue = e.text;
  },
}
```
