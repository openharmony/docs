# dialog<a name="ZH-CN_TOPIC_0000001173324657"></a>

自定义弹窗容器。

## 权限列表<a name="section11257113618419"></a>

无

## 子组件<a name="section9288143101012"></a>

支持单个子组件。

## 属性<a name="section2907183951110"></a>

除支持[通用属性](js-components-common-attributes.md)外，支持如下属性：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="19.598040195980403%" id="mcps1.1.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="11.178882111788822%" id="mcps1.1.6.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.899010098990102%" id="mcps1.1.6.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="7.56924307569243%" id="mcps1.1.6.1.4"><p>必填</p>
</th>
<th class="cellrowborder" valign="top" width="51.754824517548236%" id="mcps1.1.6.1.5"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="19.598040195980403%" headers="mcps1.1.6.1.1 "><p>dragable<sup><span>7+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="11.178882111788822%" headers="mcps1.1.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="9.899010098990102%" headers="mcps1.1.6.1.3 "><p>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.56924307569243%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="51.754824517548236%" headers="mcps1.1.6.1.5 "><p>设置对话框是否支持拖拽。</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>-   弹窗类组件不支持focusable、click-effect属性。

## 样式<a name="section5775351116"></a>

仅支持[通用样式](js-components-common-styles.md)中的width、height、margin、margin-\[left|top|right|bottom\]、margin-\[start|end\]样式。

## 事件<a name="section8562129182916"></a>

不支持[通用事件](js-components-common-events.md)，仅支持如下事件：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="18.459999999999997%" id="mcps1.1.4.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="30.769999999999996%" id="mcps1.1.4.1.2"><p>参数</p>
</th>
<th class="cellrowborder" valign="top" width="50.77%" id="mcps1.1.4.1.3"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="18.459999999999997%" headers="mcps1.1.4.1.1 "><p>cancel</p>
</td>
<td class="cellrowborder" valign="top" width="30.769999999999996%" headers="mcps1.1.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.1.4.1.3 "><p>用户点击非dialog区域触发取消弹窗时触发的事件。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.459999999999997%" headers="mcps1.1.4.1.1 "><p>show<sup><span>7+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="30.769999999999996%" headers="mcps1.1.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.1.4.1.3 "><p>对话框弹出时触发该事件。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.459999999999997%" headers="mcps1.1.4.1.1 "><p>close<sup><span>7+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="30.769999999999996%" headers="mcps1.1.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.1.4.1.3 "><p>对话框关闭时触发该事件。</p>
</td>
</tr>
</tbody>
</table>

## 方法<a name="section11753103216253"></a>

不支持[通用方法](js-components-common-methods.md)，仅支持如下方法。

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="18.459999999999997%" id="mcps1.1.4.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="30.769999999999996%" id="mcps1.1.4.1.2"><p>参数</p>
</th>
<th class="cellrowborder" valign="top" width="50.77%" id="mcps1.1.4.1.3"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="18.459999999999997%" headers="mcps1.1.4.1.1 "><p>show</p>
</td>
<td class="cellrowborder" valign="top" width="30.769999999999996%" headers="mcps1.1.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.1.4.1.3 "><p>弹出对话框。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.459999999999997%" headers="mcps1.1.4.1.1 "><p>close</p>
</td>
<td class="cellrowborder" valign="top" width="30.769999999999996%" headers="mcps1.1.4.1.2 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.1.4.1.3 "><p>关闭对话框。</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>dialog属性、样式均不支持动态更新。

## 示例<a name="section6663311114620"></a>

```
<!-- xxx.hml -->
<div class="doc-page">
  <div class="btn-div">
    <button type="capsule" value="Click here" class="btn" onclick="showDialog"></button>
  </div>
  <dialog id="simpledialog" dragable="true" class="dialog-main" oncancel="cancelDialog">
    <div class="dialog-div">
      <div class="inner-txt">
        <text class="txt" ondoubleclick="doubleclick">Simple dialog</text>
      </div>
      <div class="inner-btn">
        <button type="capsule" value="Cancel" onclick="cancelSchedule" class="btn-txt"></button>
        <button type="capsule" value="Confirm" onclick="setSchedule" class="btn-txt"></button>
      </div>
    </div>
  </dialog>
</div>
```

```
/* xxx.css */
.doc-page {
  flex-direction: column;
  justify-content: center;
  align-items: center;
}
.btn-div {
  width: 100%;
  height: 200px;
  flex-direction: column;
  align-items: center;
  justify-content: center;
}
.btn {
  background-color: #F2F2F2;
  text-color: #0D81F2;
}
.txt {
  color: #000000;
  font-weight: bold;
  font-size: 39px;
}
.dialog-main {
  width: 500px;
}
.dialog-div {
  flex-direction: column;
  align-items: center;
}
.inner-txt {
  width: 400px;
  height: 160px;
  flex-direction: column;
  align-items: center;
  justify-content: space-around;
}
.inner-btn {
  width: 400px;
  height: 120px;
  justify-content: space-around;
  align-items: center;
}
.btn-txt {
  background-color: #F2F2F2;
  text-color: #0D81F2;
}
```

```
// xxx.js
import prompt from '@system.prompt';
export default {
  showDialog(e) {
    this.$element('simpledialog').show()
  },
  cancelDialog(e) {
    prompt.showToast({
      message: 'Dialog cancelled'
    })
  },
  cancelSchedule(e) {
    this.$element('simpledialog').close()
    prompt.showToast({
      message: 'Successfully cancelled'
    })
  },
  setSchedule(e) {
    this.$element('simpledialog').close()
    prompt.showToast({
      message: 'Successfully confirmed'
    })
  },
  doubleclick(e){
    prompt.showToast({
      message: 'doubleclick'
    })
  }
}
```

![](figures/4.gif)

