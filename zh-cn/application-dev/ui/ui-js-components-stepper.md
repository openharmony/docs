# stepper开发指导
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @mayaolll-->
<!--SE: @jiangdayuan-->
<!--TSE: @lxl007-->

当一个任务需要多个步骤时，可以使用stepper组件展示当前进展。具体用法请参考[stepper API](../reference/apis-arkui/arkui-js/js-components-container-stepper.md)。


## 创建stepper组件

在pages/index目录下的hml文件中创建一个stepper组件。

```html
<!-- xxx.hml -->
<div class="container"> 
 <stepper>    
   <stepper-item>     
     <text>Step 1</text>
   </stepper-item> 
   <stepper-item>     
     <text>Step 2</text>
   </stepper-item> 
 </stepper> 
</div>
```

```css
/* xxx.css */
.container {
  width:100%;
  height:100%;
  flex-direction: column;
  justify-content: center;
  align-items: center;
  background-color: #F1F3F5;
}
text{
  width: 100%;
  height: 100%;
  text-align: center;
}
```

![zh-cn_image_0000001234289455](figures/zh-cn_image_0000001234289455.gif)


## 设置index属性

页面默认显示索引值为index的步骤。

```html
<!-- xxx.hml -->
<div class="container"> 
 <stepper index="2">    
   <stepper-item>     
     <text>stepper-item1</text>
   </stepper-item> 
   <stepper-item>     
     <text>stepper-item2</text>
   </stepper-item> 
   <stepper-item>     
     <text>stepper-item3</text>
   </stepper-item> 
  </stepper> 
</div>
```

```css
/* xxx.css */
.container {
  width:100%;
  height:100%;
  flex-direction: column;
  background-color: #F1F3F5;
}
text{
  width: 100%;
  height: 100%;
  text-align: center;
}
```

![zh-cn_image_0000001234011019](figures/zh-cn_image_0000001234011019.gif)

通过设置label属性，自定义stepper-item的提示按钮。

```html
<!-- xxx.hml -->
<div class="container"> 
 <stepper index="1">    
   <stepper-item label="{{label_1}}">     
     <text>stepper-item1</text>
   </stepper-item> 
   <stepper-item label="{{label_2}}">     
     <text>stepper-item2</text>
   </stepper-item> 
   <stepper-item label="{{label_3}}">     
     <text>stepper-item3</text>
   </stepper-item>
   <stepper-item>     
     <text>stepper-item4</text>
   </stepper-item> 
 </stepper> 
</div>
```

```css
/* xxx.css */
.container {  
  width:100%;
  height:100%;
  flex-direction: column;
  background-color: #F1F3F5;
}
text{
  width: 100%;
  height: 100%;
  text-align: center;
}
```

```js
// xxx.js
export default { 
  data: {
    label_1:{
      nextLabel: 'NEXT',      
      status: 'normal'    
    },
    label_2:{
      prevLabel: 'BACK',
      nextLabel: 'NEXT',
      status: 'normal'
    },
    label_3:{
      prevLabel: 'BACK',
      nextLabel: 'END',
      status: 'disabled'
    },
  },
}
```

![zh-cn_image_0000001163531210](figures/zh-cn_image_0000001163531210.gif)


## 设置样式

stepper组件默认填充父容器，通过border和background-color设置边框、背景色。
```html
<!-- xxx.hml -->
<div class="container" > 
  <div class="stepperContent">
    <stepper class="stepperClass">    
      <stepper-item>     
        <text>stepper-item1</text>
      </stepper-item> 
    </stepper> 
  </div>
</div>
```

```css
/* xxx.css */
.container {
  width:100%;
  height:100%;
  flex-direction: column;
  align-items: center;
  justify-content: center;
  background-color:#F1F3F5;
}
.stepperContent{
  width: 300px;
  height: 300px;
}
.stepperClass{
  border:1px solid silver ;
  background-color: white;
}
text{
  width: 100%;
  height: 100%;
  text-align: center;
}
```

![zh-cn_image_0000001234130975](figures/zh-cn_image_0000001234130975.png)


## 添加事件

stepper分别添加finish，change，next，back，skip事件。

- 当change与next或back同时存在时，会先执行next或back事件再去执行change事件。

- 重新设置index属性值时要先清除index的值再重新设置，否则检测不到值的改变。

```html
<!-- xxx.hml -->
<div class="container"  style="background-color:#F1F3F5;">
  <div >
    <stepper onfinish="stepperFinish" onchange="stepperChange" onnext="stepperNext" onback="stepperBack" onskip="stepperSkip" id="stepperId" index="{{index}}">
      <stepper-item>
        <text>stepper-item1</text>
        <button value="skip" onclick="skipClick"></button>
      </stepper-item>
      <stepper-item>
         <text>stepper-item2</text>
         <button value="skip" onclick="skipClick"></button>
      </stepper-item>
      <stepper-item>
        <text>stepper-item3</text>
      </stepper-item>
    </stepper>
  </div>
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
}
stepper-item{
  width: 100%;
  flex-direction: column;
  align-self: center;
  justify-content: center;
}
text{
  margin-top: 45%;
  justify-content: center;
  align-self: center;
  margin-bottom: 50px;
}
button{
  width: 80%;
  height: 60px;
  margin-top: 20px;
}
```

```js
// xxx.js
import promptAction from '@ohos.promptAction';
export default {
  data: {
    index:0,
  },
   stepperSkip(){
    this.index = null;
    this.index=2;
  },
   skipClick(){
    this.$element('stepperId').setNextButtonStatus({status: 'skip', label: 'SKIP'});
  },
  stepperFinish(){
    promptAction.showToast({
      message: 'All Finished'
    })
  },
  stepperChange(e){
    console.log("stepperChange"+e.index)
    promptAction.showToast({
      // index表示当前步骤的序号
      message: 'Previous step: '+e.prevIndex+"-------Current step:"+e.index
    })
  },
  stepperNext(e){
    console.log("stepperNext"+e.index)
    promptAction.showToast({
      // pendingIndex表示将要跳转的序号
      message: 'Current step:'+e.index+"-------Next step:"+e.pendingIndex
    })
    var index = {pendingIndex:e.pendingIndex }
    return index;
  },
  stepperBack(e){
    console.log("stepperBack"+e.index)
    var index = {pendingIndex: e.pendingIndex }
    return index;
  }
}
```

![zh-cn_image_0000001189089950](figures/zh-cn_image_0000001189089950.gif)


## 场景示例

在本场景中，开发者可以在界面上点击选择并实时显示选择结果，点击下一步按钮后可动态修改页面的字体颜色和字体大小。

用stepper组件实现分步，再创建[Toggle](../reference/apis-arkui/arkui-js/js-components-basic-toggle.md)组件实现选择显示功能，再使用[Select](../reference/apis-arkui/arkui-js/js-components-basic-select.md)组件实现改变选中值动态修改字体颜色或大小。

```html
<!-- xxx.hml -->
<div class="container">
  <stepper id="mystep" index="0" onfinish="back" style="text-color: indigo;">
    <stepper-item label="{{label1}}">
      <div style="flex-direction: column;padding: 0px 10px;">
        <text class="text" style="margin-top: 10%;text-align: center;width: 100%;">Select error types:</text>
        <text style="margin-top: 20px;padding: 10px">
          <span>{{error}}</span>
        </text>
        <div style="justify-content: space-around;flex-wrap: wrap;">
          <toggle for="{{togglelist1}}" value="{{$item}}" class="tog" onchange="multiTog({{$item}})"></toggle>
        </div>
      </div>
    </stepper-item>
    <stepper-item label="{{label2}}">
      <div style="flex-direction: column;align-items: center;">
        <text class="txt" style="margin-top: 10%;">Toggle</text>
        <div style="justify-content: space-around;flex-wrap: wrap;margin-top:10%">
          <toggle class="tog" for="{{togglelist1}}" value="{{$item}}" style="text-color: {{tcolor}};font-size: {{tsize}}; font-style: {{tstyle}};font-weight: {{tweight}};font-family: {{tfamily}};">
          </toggle>
        </div>
        <div style="flex-wrap: wrap;width: 700px;margin-top:10%">
          <div style="flex-direction: column;width: 350px;height: 185px;align-items: center;">
            <text class="txt">text-color</text>
            <select onchange="settcolor">
              <option for="{{color_list}}" value="{{$item}}">{{$item}}</option>
            </select>
          </div>
          <div style="flex-direction: column;width: 350px;height: 185px;align-items: center;">
            <text class="txt">font-size</text>
            <select onchange="settsize">
              <option for="{{size_list}}" value="{{$item}}">{{$item}}</option>
            </select>
          </div>
        </div>
      </div>
    </stepper-item>
  </stepper>
</div>
```

```css
/* xxx.css */
.container {
  width:100%;
  height:100%;
  flex-direction: column;
  align-items: center;
  justify-content: center;
  background-color:#F1F3F5;
}
.dvd {
  stroke-width: 8px;
  color: orangered;
  margin: 65px;
}
.tog{
  margin-right: 20px;
  margin-top: 30px;
}
```

```js
// xxx.js
import promptAction from '@ohos.promptAction';
import router from '@ohos.router';
let myset = new Set();
export default {
  data: {
    error: '',
    tcolor:'#FF4500',
    color_list:['#FF4500','#5F9EA0','#0000FF'],
    tsize: '12px',
    size_list: ['12px', '30px', '8px', '50px'],
    label1: {
      prevLabel: 'The text on the left of the starting step is invalid.',
      nextLabel: 'Toggle'
    },
    label2: {
      prevLabel: 'toggle',
      nextLabel: 'END'
    },
    togglelist1:['Program error', 'Software', 'System', 'Application'],
  },
  multiTog(arg, e) {
    this.error = ' '
    if (e.checked) {
      myset.add(arg)
    } else {
      myset.delete(arg)
    }
    for (let item of myset) {
      this.error += item + ' '
    }
  },
  settcolor(e) {
    this.tcolor = e.newValue
  },
  settsize(e) {
    this.tsize = e.newValue
  }
}
```

![zh-cn_image_0000001189249862](figures/zh-cn_image_0000001189249862.gif)