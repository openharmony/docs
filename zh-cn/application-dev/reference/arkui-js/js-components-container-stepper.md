# stepper

>  **说明：**
>  从API version 5开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

步骤导航器。当完成一个任务需要多个步骤时，可以使用步骤导航器展示当前进展。


## 权限列表

无


## 子组件

仅支持&lt;stepper-item&gt;子组件。

>  **说明：**
>  步骤导航器内的步骤顺序按照子组件&lt;stepper-item&gt;的顺序进行排序。


## 属性

除支持[通用属性](../arkui-js/js-components-common-attributes.md)外，还支持如下属性：

| 名称    | 类型     | 默认值  | 描述                             |
| ----- | ------ | ---- | ------------------------------ |
| index | number | -    | 设置步骤导航器步骤显示第几个stepper-item子组件。 |


## 样式

支持[通用样式](../arkui-js/js-components-common-styles.md)。

>  **说明：**
>  stepper组件默认占满父容器大小，建议父组件使用应用窗口大小（或者父组件为根节点）来优化体验。


## 事件

除支持[通用事件](../arkui-js/js-components-common-events.md)外，还支持如下事件：

| 名称     | 参数                                       | 描述                                       |
| ------ | ---------------------------------------- | ---------------------------------------- |
| finish | 无                                        | 当步骤导航器最后一个步骤完成时触发该事件。                    |
| skip   | 无                                        | 当通过setNextButtonStatus方法设置当前步骤导航器可跳过时，点击右侧跳过按钮触发该事件。 |
| change | {&nbsp;prevIndex：prevIndex,&nbsp;index:&nbsp;index} | 当步骤导航器点击左边或者右边文本按钮进行步骤切换时触发该事件，prevIndex表示老步骤的序号，index表示新步骤的序号。 |
| next   | {&nbsp;index：index,&nbsp;pendingIndex:&nbsp;pendingIndex&nbsp;} | 当用户点击下一步按钮时触发该事件，index表示当前步骤序号，pendingIndex表示将要跳转的序号，该事件有返回值，返回值格式为：{&nbsp;pendingIndex：pendingIndex&nbsp;}，可以通过指定pendingIndex来修改下一个步骤使用哪个stepper-item子组件。 |
| back   | {&nbsp;index：index,&nbsp;pendingIndex:&nbsp;pendingIndex&nbsp;} | 当用户点击上一步按钮时触发该事件，index表示当前步骤序号，pendingIndex表示将要跳转的序号，该事件有返回值，返回值格式为Object：{&nbsp;pendingIndex：pendingIndex&nbsp;}，可以通过指定pendingIndex来修改上一个步骤使用哪个stepper-item子组件。 |


## 方法

除支持[通用方法](../arkui-js/js-components-common-methods.md)外，支持如下方法：

| 名称                  | 参数                                       | 描述                                       |
| ------------------- | ---------------------------------------- | ---------------------------------------- |
| setNextButtonStatus | {&nbsp;status:&nbsp;string,&nbsp;label:&nbsp;label&nbsp;} | 设置当前步骤导航器下一步文本按钮的状态，参数中status类型为string，可选值为：<br/>-&nbsp;normal：正常状态，下一步文本按钮正常显示，可点击进入下一个步骤；<br/>-&nbsp;disabled：不可用状态，下一步文本按钮灰度显示，不可点击进入下一个步骤；<br/>-&nbsp;waiting：等待状态，下一步文本按钮不显示，使用等待进度条，不可点击进入下一个步骤。<br/>-&nbsp;skip：跳过状态，下一步文本按钮显示跳过按钮，点击时会跳过剩下步骤。 |


## 示例

```html
<!-- xxx.hml -->
<div class = "container">
  <stepper class="stepper" id="mystepper" index="0"  onnext="nextclick" onback="backclick">
    <stepper-item class ="stepperItem" label="{{label_1}}">
      <div class = "stepperItemContent" >
        <text>First screen</text>
      </div>
      <button type="capsule" class ="button" value="setRightButtonStatus" onclick="setRightButton"></button>
    </stepper-item>
    <stepper-item class ="stepperItem" label="{{label_2}}">
      <div class = "stepperItemContent" >
        <text>Second screen</text>
      </div>
      <button type="capsule" class ="button" value="setRightButtonStatus" onclick="setRightButton"></button>
    </stepper-item>
    <stepper-item class ="stepperItem" label="{{label_3}}">
      <div class = "stepperItemContent" >
        <text>Third screen</text>
      </div>
      <button type="capsule" class ="button" value="setRightButtonStatus" onclick="setRightButton"></button>
    </stepper-item>
  </stepper>
</div>
```

```css
/* xxx.css */
.container {
  margin-top: 20px;
  flex-direction: column;
  align-items: center;
  height: 300px;
}
.stepperItem {
  width: 100%;
  flex-direction: column;
  align-items: center;
}
.stepperItemContent {
  font-size: 50px;
  justify-content: center;
}
.button {
  width: 60%;
  margin-top: 30px;
  justify-content: center;
}
```

```js
// xxx.js
export default {
  data: {
    label_1:
    {
       prevLabel: 'BACK',
       nextLabel: 'NEXT',
       status: 'normal'
     },
     label_2:
     {
       prevLabel: 'BACK',
       nextLabel: 'NEXT',
       status: 'normal'
     },
     label_3:
     {
        prevLabel: 'BACK',
        nextLabel: 'NEXT',
        status: 'normal'
     },
  },
  setRightButton(e) {
    this.$element('mystepper').setNextButtonStatus({status: 'skip', label: 'SKIP'});
  },
  nextclick(e) {
    var index = {
      pendingIndex: e.pendingIndex
    }
    return index;
  },
  backclick(e) {
    var index = {
        pendingIndex: e.pendingIndex
    }
    return index;
  },
}
```

![zh-cn_image_0000001127125114](figures/zh-cn_image_0000001127125114.gif)
