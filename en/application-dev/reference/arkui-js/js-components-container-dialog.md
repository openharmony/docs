# dialog<a name="EN-US_TOPIC_0000001173324657"></a>

The  **<dialog\>**  component is a custom pop-up container.

## Required Permissions<a name="section11257113618419"></a>

None

## Child Components<a name="section9288143101012"></a>

A single child component is supported.

## Attributes<a name="section2907183951110"></a>

In addition to the attributes in  [Universal Attributes](js-components-common-attributes.md), the following attributes are supported.

<a name="tb330011ff53049a69f27cec012adf8c1"></a>
<table><thead align="left"><tr id="r4301f3a3b24c499c9bfc42b76ab785f9"><th class="cellrowborder" valign="top" width="19.598040195980403%" id="mcps1.1.6.1.1"><p id="a9ba8c579217b4b8b841b035f1d28b20e"><a name="a9ba8c579217b4b8b841b035f1d28b20e"></a><a name="a9ba8c579217b4b8b841b035f1d28b20e"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="11.178882111788822%" id="mcps1.1.6.1.2"><p id="a633002333b024497914a4b172446f14e"><a name="a633002333b024497914a4b172446f14e"></a><a name="a633002333b024497914a4b172446f14e"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="9.899010098990102%" id="mcps1.1.6.1.3"><p id="a4950f7884c6540b9ad523ac34657d952"><a name="a4950f7884c6540b9ad523ac34657d952"></a><a name="a4950f7884c6540b9ad523ac34657d952"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="7.56924307569243%" id="mcps1.1.6.1.4"><p id="p58189597166"><a name="p58189597166"></a><a name="p58189597166"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="51.754824517548236%" id="mcps1.1.6.1.5"><p id="a1313564aa9404a338447087d5918c17d"><a name="a1313564aa9404a338447087d5918c17d"></a><a name="a1313564aa9404a338447087d5918c17d"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="r06a481428e8d455fba919d3d4618be31"><td class="cellrowborder" valign="top" width="19.598040195980403%" headers="mcps1.1.6.1.1 "><p id="adb8a73146d764f2aab50fc046169ab26"><a name="adb8a73146d764f2aab50fc046169ab26"></a><a name="adb8a73146d764f2aab50fc046169ab26"></a>dragable<sup id="sup999420218191"><a name="sup999420218191"></a><a name="sup999420218191"></a>7+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="11.178882111788822%" headers="mcps1.1.6.1.2 "><p id="a06898db2627246f78e85d4fbadeee85c"><a name="a06898db2627246f78e85d4fbadeee85c"></a><a name="a06898db2627246f78e85d4fbadeee85c"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="9.899010098990102%" headers="mcps1.1.6.1.3 "><p id="ae685ead324a647bcba1bbb45c9402dd6"><a name="ae685ead324a647bcba1bbb45c9402dd6"></a><a name="ae685ead324a647bcba1bbb45c9402dd6"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.56924307569243%" headers="mcps1.1.6.1.4 "><p id="p78183594166"><a name="p78183594166"></a><a name="p78183594166"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="51.754824517548236%" headers="mcps1.1.6.1.5 "><p id="a692121725a9b4ebbae65cd22b94b672e"><a name="a692121725a9b4ebbae65cd22b94b672e"></a><a name="a692121725a9b4ebbae65cd22b94b672e"></a>Whether the pop-up can be dragged.</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>-   The  **<dialog\>**  component does not support the  **focusable**  and  **click-effect**  attributes.

## Styles<a name="section5775351116"></a>

Only the  **width**,  **height**,  **margin**,  **margin-\[left|top|right|bottom\]**, and  **margin-\[start|end\]**  styles in  [Universal Styles](js-components-common-styles.md)  are supported.

## Events<a name="section8562129182916"></a>

Events in  [Universal Events](js-components-common-events.md)  are not supported. The following table lists the supported event.

<a name="table20562102982910"></a>
<table><thead align="left"><tr id="row9562162932910"><th class="cellrowborder" valign="top" width="18.459999999999997%" id="mcps1.1.4.1.1"><p id="p195626291296"><a name="p195626291296"></a><a name="p195626291296"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="30.769999999999996%" id="mcps1.1.4.1.2"><p id="p185622029202914"><a name="p185622029202914"></a><a name="p185622029202914"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="50.77%" id="mcps1.1.4.1.3"><p id="p9562132915297"><a name="p9562132915297"></a><a name="p9562132915297"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row7562729142911"><td class="cellrowborder" valign="top" width="18.459999999999997%" headers="mcps1.1.4.1.1 "><p id="p145622291299"><a name="p145622291299"></a><a name="p145622291299"></a>cancel</p>
</td>
<td class="cellrowborder" valign="top" width="30.769999999999996%" headers="mcps1.1.4.1.2 "><p id="p356210295295"><a name="p356210295295"></a><a name="p356210295295"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.1.4.1.3 "><p id="p55621629122916"><a name="p55621629122916"></a><a name="p55621629122916"></a>Triggered when a user taps a non-dialog area to cancel the pop-up.</p>
</td>
</tr>
<tr id="row154462392615"><td class="cellrowborder" valign="top" width="18.459999999999997%" headers="mcps1.1.4.1.1 "><p id="p84461834266"><a name="p84461834266"></a><a name="p84461834266"></a>show<sup id="sup2397204717198"><a name="sup2397204717198"></a><a name="sup2397204717198"></a>7+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="30.769999999999996%" headers="mcps1.1.4.1.2 "><p id="p164468315263"><a name="p164468315263"></a><a name="p164468315263"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.1.4.1.3 "><p id="p204465311269"><a name="p204465311269"></a><a name="p204465311269"></a>Triggered when the pop-up is displayed.</p>
</td>
</tr>
<tr id="row28470175299"><td class="cellrowborder" valign="top" width="18.459999999999997%" headers="mcps1.1.4.1.1 "><p id="p2848161792917"><a name="p2848161792917"></a><a name="p2848161792917"></a>close<sup id="sup4231174871918"><a name="sup4231174871918"></a><a name="sup4231174871918"></a>7+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="30.769999999999996%" headers="mcps1.1.4.1.2 "><p id="p128481917132913"><a name="p128481917132913"></a><a name="p128481917132913"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.1.4.1.3 "><p id="p5848121742920"><a name="p5848121742920"></a><a name="p5848121742920"></a>Triggered when the pop-up is closed.</p>
</td>
</tr>
</tbody>
</table>

## Methods<a name="section11753103216253"></a>

Methods in  [Universal Methods](js-components-common-methods.md)  are not supported. The following table lists the supported methods.

<a name="table20753173210251"></a>
<table><thead align="left"><tr id="row575363214257"><th class="cellrowborder" valign="top" width="18.459999999999997%" id="mcps1.1.4.1.1"><p id="p157531032112517"><a name="p157531032112517"></a><a name="p157531032112517"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="30.769999999999996%" id="mcps1.1.4.1.2"><p id="p77531632132518"><a name="p77531632132518"></a><a name="p77531632132518"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="50.77%" id="mcps1.1.4.1.3"><p id="p147531232132512"><a name="p147531232132512"></a><a name="p147531232132512"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row15753113210251"><td class="cellrowborder" valign="top" width="18.459999999999997%" headers="mcps1.1.4.1.1 "><p id="p2314135812511"><a name="p2314135812511"></a><a name="p2314135812511"></a>show</p>
</td>
<td class="cellrowborder" valign="top" width="30.769999999999996%" headers="mcps1.1.4.1.2 "><p id="p7314115819256"><a name="p7314115819256"></a><a name="p7314115819256"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.1.4.1.3 "><p id="p0314958162512"><a name="p0314958162512"></a><a name="p0314958162512"></a>Shows a dialog box.</p>
</td>
</tr>
<tr id="row393410526251"><td class="cellrowborder" valign="top" width="18.459999999999997%" headers="mcps1.1.4.1.1 "><p id="p7314358182512"><a name="p7314358182512"></a><a name="p7314358182512"></a>close</p>
</td>
<td class="cellrowborder" valign="top" width="30.769999999999996%" headers="mcps1.1.4.1.2 "><p id="p1231455814253"><a name="p1231455814253"></a><a name="p1231455814253"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.1.4.1.3 "><p id="p10314105842512"><a name="p10314105842512"></a><a name="p10314105842512"></a>Closes a dialog box.</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>Attributes and styles of a  **<dialog\>**  component cannot be dynamically updated.

## Example Code<a name="section6663311114620"></a>

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

