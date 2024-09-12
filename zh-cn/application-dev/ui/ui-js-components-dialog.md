# dialog开发指导

dialog组件用于创建自定义弹窗，通常用来展示用户当前需要或用户必须关注的信息或操作。具体用法请参考[dialog API](../reference/apis-arkui/arkui-js/js-components-container-dialog.md)。


## 创建dialog组件

在pages/index目录下的hml文件中创建一个dialog组件，并添加Button组件来触发dialog。dialog组件仅支持width、height、margin、margin-[left|top|right|bottom]、margin-[start|end]样式。
```html
<!-- xxx.hml -->
<div class="doc-page">
  <dialog class="dialogClass" id="dialogId" dragable="true">
    <div class="content">
      <text>this is a dialog</text>
    </div>
  </dialog>
  <button value="click me" onclick="opendialog"></button>
</div>
```

```css
/* xxx.css */
.doc-page {
  width:100%;
  height:100%;
  flex-direction: column;
  align-items: center;
  justify-content: center;
  background-color: #F1F3F5;
}
.dialogClass{
  width: 80%;
  height: 250px;
  margin-start: 1%;
}
.content{
  width: 100%;
  height: 250px;
  justify-content: center;
  background-color: #e8ebec;
  border-radius: 20px;
}
text{
  width: 100%;
  height: 100%;
  text-align: center;
}
button{
  width: 70%;
  height: 60px;
}
```

```js
// xxx.js
export default {
  //Touch to open the dialog box.
  opendialog(){
    this.$element('dialogId').show()
  },
}
```

![zh-cn_image_0000001211246571](figures/zh-cn_image_0000001211246571.gif)


## 设置弹窗响应

开发者点击页面上非dialog的区域时，将触发cancel事件而关闭弹窗。同时也可以通过对dialog添加show和close方法来显示和关闭弹窗。


```html
<!-- xxx.hml -->
<div class="doc-page">
  <dialog class="dialogClass" id="dialogId" oncancel="canceldialog">
    <div class="dialogDiv">
      <text>dialog</text>
      <button value="confirm" onclick="confirmClick"></button>
    </div>
  </dialog>
  <button value="click me" onclick="opendialog"></button>
</div>
```


```css
/* xxx.css */
.doc-page {
  width:100%;
  height:100%;
  flex-direction: column;
  align-items: center;
  justify-content: center;
  background-color: #F1F3F5;
}
.dialogClass{
  width: 80%;
  height: 300px;
  margin-start: 1%;
}
.dialogDiv{
  width: 100%;
  flex-direction: column;
  justify-content: center;
  align-self: center;
}
text{
  height: 100px;
  align-self: center;
}
button{
  align-self: center;
  margin-top: 20px;
  width: 60%;
  height: 80px;
}
```


```js
// xxx.js
import promptAction from '@ohos.promptAction';
export default {
  canceldialog(e){
    promptAction.showToast({
      message: 'dialogCancel'
    })
  },
  opendialog(){
    this.$element('dialogId').show()
     promptAction.showToast({
      message: 'dialogShow'
    })
  },
  confirmClick(e) {
    this.$element('dialogId').close()
    promptAction.showToast({
      message: 'dialogClose'
    })
  },
}
```


![zh-cn_image_0000001163229150](figures/zh-cn_image_0000001163229150.gif)


> **说明：**
> - 仅支持单个子组件。
>
> - dialog属性、样式均不支持动态更新。
>
> - dialog组件不支持focusable、click-effect属性。


## 场景示例


在本场景中，开发者可以通过dialog组件实现一个日程表。弹窗在打开状态下，利用[Textarea组件](../reference/apis-arkui/arkui-js/js-components-basic-textarea.md)输入当前日程，点击确认按钮后获取当前时间并保存输入文本。最后以列表形式将各日程进行展示。


```html
<!-- xxx.hml -->
<div class="doc-page">
  <text style="margin-top: 60px;margin-left: 30px;">
    <span>{{date}} events</span>
  </text>
  <div class="btndiv">
    <button type="circle" class="btn" onclick="addschedule">+</button>
  </div>
<!--  for Render events data  -->
  <list style="width: 100%;">
    <list-item type="item" for="schedulelist" style="width:100%;height: 200px;">
      <div class="schedulediv">
        <text class="text1">{{date}}  event</text>
        <text class="text2">{{$item.schedule}}</text>
      </div>
    </list-item>
  </list>
  <dialog id="datedialog" oncancel="canceldialog" >
    <div class="dialogdiv">
      <div class="innertxt">
        <text class="text3">{{date}}</text>
        <text class="text4">New event</text>
      </div>
      <textarea placeholder="Event information" onchange="getschedule" class="area" extend="true"></textarea>
      <div class="innerbtn">
        <button type="text" value="Cancel" onclick="cancelschedule" class="btntxt"></button>
        <button type="text" value="OK" onclick="setschedule" class="btntxt"></button>
      </div>
    </div>
  </dialog>
</div>
```


```css
/* xxx.css */
.doc-page {
  flex-direction: column;
  background-color: #F1F3F5;
}
.btndiv {
  width: 100%;
  height: 200px;
  flex-direction: column;
  align-items: center;
  justify-content: center;
}
.btn {
  radius:60px;
  font-size: 100px;
  background-color: #1E90FF;
}
.schedulediv {
  width: 100%;
  height: 200px;
  flex-direction: column;
  justify-content: space-around;
  padding-left: 55px;
}
.text1 {
  color: #000000;
  font-weight: bold;
  font-size: 39px;
}
.text2 {
  color: #a9a9a9;
  font-size: 30px;
}
.dialogdiv {
  flex-direction: column;
  align-items: center;
}
.innertxt {
  width: 320px;
  height: 160px;
  flex-direction: column;
  align-items: center;
  justify-content: space-around;
}
.text3 {
  font-family: serif;
  color: #1E90FF;
  font-size: 38px;
}
.text4 {
  color: #a9a9a9;
  font-size: 33px;
}
.area {
  width: 320px;
  border-bottom: 1px solid #1E90FF;
}
.innerbtn {
  width: 320px;
  height: 120px;
  justify-content: space-around;
}
.btntxt {
  text-color: #1E90FF;
}
```


```js
// xxx.js
var info = null;
import promptAction from '@ohos.promptAction';
export default {
  data: {
    curYear:'',
    curMonth:'',
    curDay:'',
    date:'',
    schedule:'',
    schedulelist:[]
  },
  onInit() {
    // Obtain the current date. 
    var date = new Date();
    this.curYear = date.getFullYear();
    this.curMonth = date.getMonth() + 1;
    this.curDay = date.getDate();
    this.date = this.curYear + '-' + this.curMonth + '-' + this.curDay;
    this.schedulelist = []
  },
  addschedule(e) {
    this.$element('datedialog').show()
  },
  canceldialog(e) {
    promptAction.showToast({
      message: 'Event setting canceled.'
    })
  },
  getschedule(e) {
    info = e.value
  },
  cancelschedule(e) {
    this.$element('datedialog').close()
    promptAction.showToast({
      message: 'Event setting canceled.'
    })
  },
//    Touch OK to save the data.
  setschedule(e) {
    if (e.text === '') {
      this.schedule = info
    } else {
      this.schedule = info
      var addItem =  {schedule: this.schedule,}
      this.schedulelist.push(addItem)
    }
    this.$element('datedialog').close()
  }
}
```


![zh-cn_image_0000001234329527](figures/zh-cn_image_0000001234329527.gif)


## 相关实例

针对dialog开发，有以下相关实例可供参考：

- [弹窗基本使用（JS）（API9）](https://gitee.com/openharmony/codelabs/tree/master/JSUI/DialogDemo)
