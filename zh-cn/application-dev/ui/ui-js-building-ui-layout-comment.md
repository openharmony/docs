# 添加留言区域
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @fenglinbailu-->
<!--SE: @lanshouren-->
<!--TSE: @liuli0427-->

留言框的功能为：用户输入留言后点击完成，留言区域即显示留言内容。用户点击右侧的删除按钮可删除当前留言内容并重新输入。


留言区域由div、text、input关联click事件实现。开发者可以使用input组件实现输入留言的部分，使用text组件实现留言完成部分，使用commentText的状态标记此时显示的组件（通过if属性控制）。在包含文本完成和删除的text组件中关联click事件，更新commentText状态和inputValue的内容。具体的实现示例如下：


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
