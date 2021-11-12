# form<a name="EN-US_TOPIC_0000001127284848"></a>

The  **<form\>**  component allows the content in  **input**  elements to be submitted and reset.

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>This component is supported since API version 6.

## Required Permissions<a name="section11257113618419"></a>

None

## Child Component<a name="section9288143101012"></a>

Supported

## Attribute<a name="section2907183951110"></a>

Attributes in  [Universal Attributes](js-components-common-attributes.md)  are supported.

## Style<a name="section10683162023215"></a>

Styles in  [Universal Styles](js-components-common-styles.md)  are supported.

## Event<a name="section77341431152917"></a>

In addition to the events in  [Universal Events](js-components-common-events.md), the following events are supported.

<a name="table1180610218398"></a>
<table><thead align="left"><tr id="row8806162153917"><th class="cellrowborder" valign="top" width="22.7022702270227%" id="mcps1.1.4.1.1"><p id="p0807112143914"><a name="p0807112143914"></a><a name="p0807112143914"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="16.881688168816883%" id="mcps1.1.4.1.2"><p id="p380752110397"><a name="p380752110397"></a><a name="p380752110397"></a>Parameters</p>
</th>
<th class="cellrowborder" valign="top" width="60.41604160416041%" id="mcps1.1.4.1.3"><p id="p118071121183910"><a name="p118071121183910"></a><a name="p118071121183910"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row380713217397"><td class="cellrowborder" valign="top" width="22.7022702270227%" headers="mcps1.1.4.1.1 "><p id="p19132135593918"><a name="p19132135593918"></a><a name="p19132135593918"></a>submit</p>
</td>
<td class="cellrowborder" valign="top" width="16.881688168816883%" headers="mcps1.1.4.1.2 "><p id="p17807152183918"><a name="p17807152183918"></a><a name="p17807152183918"></a><a href="#table195257111418">FormResult</a></p>
</td>
<td class="cellrowborder" valign="top" width="60.41604160416041%" headers="mcps1.1.4.1.3 "><p id="p8807102116392"><a name="p8807102116392"></a><a name="p8807102116392"></a>Triggered when the Submit button is touched.</p>
</td>
</tr>
<tr id="row38502504218"><td class="cellrowborder" valign="top" width="22.7022702270227%" headers="mcps1.1.4.1.1 "><p id="p1085019519428"><a name="p1085019519428"></a><a name="p1085019519428"></a>reset</p>
</td>
<td class="cellrowborder" valign="top" width="16.881688168816883%" headers="mcps1.1.4.1.2 "><p id="p108501958427"><a name="p108501958427"></a><a name="p108501958427"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="60.41604160416041%" headers="mcps1.1.4.1.3 "><p id="p2850758423"><a name="p2850758423"></a><a name="p2850758423"></a>Triggered when the Reset button is clicked.</p>
</td>
</tr>
</tbody>
</table>

**Table  1**  FormResult

<a name="table195257111418"></a>
<table><thead align="left"><tr id="row55251211114111"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p2052551119411"><a name="p2052551119411"></a><a name="p2052551119411"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p2525141116412"><a name="p2525141116412"></a><a name="p2525141116412"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p55251011134114"><a name="p55251011134114"></a><a name="p55251011134114"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row352501115412"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p15525191113412"><a name="p15525191113412"></a><a name="p15525191113412"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p145256112413"><a name="p145256112413"></a><a name="p145256112413"></a>Object</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1852512118411"><a name="p1852512118411"></a><a name="p1852512118411"></a>Values of <strong id="b194181133618"><a name="b194181133618"></a><a name="b194181133618"></a>name</strong> and <strong id="b1690145461"><a name="b1690145461"></a><a name="b1690145461"></a>value</strong> of the input element.</p>
</td>
</tr>
</tbody>
</table>

## Method<a name="section2279124532420"></a>

Methods in  [Universal Methods](js-components-common-methods.md)  are supported.

## Example:<a name="section1241545010391"></a>

```
<!-- xxx.hml -->
<form onsubmit='onSubmit' onreset='onReset'>
    <label>Option 1</label>
  <input type='radio' name='radioGroup' value='radio1'></input>
    <label>Option 2</label>
  <input type='radio' name='radioGroup' value='radio2'></input>
    <text>Input text</text>
  <input type='text' name='user'></input>
  <input type='submit'>Submit</input>
  <input type='reset'>Reset</input>
</form>
```

```
// xxx.js
export default{
  onSubmit(result) {
    console.log(result.value.radioGroup) // radio1 or radio2
    console.log(result.value.user) // text input value
  },
  onReset() {
    console.log('reset all value')
  }
}
```

