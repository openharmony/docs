# stepper<a name="EN-US_TOPIC_0000001173324583"></a>

The  **<stepper\>**  component provides a step navigator. When multiple steps are required to complete a task, you can use the  **<stepper\>**  component to navigate your users through the whole process.

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>This component is supported since API version 5.

## Permission List<a name="section11257113618419"></a>

None

## Child Component<a name="section9288143101012"></a>

Only the  **<stepper-item\>**  component is supported.

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>Steps in the  **<stepper\>**  are sorted according to the sequence of its  **<stepper-item\>**  child components.

## Attribute<a name="section191521418142311"></a>

In addition to the attributes in  [Universal Attributes](js-components-common-attributes.md), the following attributes are supported.

<a name="table20633101642315"></a>
<table><thead align="left"><tr id="row663331618238"><th class="cellrowborder" valign="top" width="25.040000000000003%" id="mcps1.1.5.1.1"><p id="a45273e2103004ff3bdd3375013e96a2a"><a name="a45273e2103004ff3bdd3375013e96a2a"></a><a name="a45273e2103004ff3bdd3375013e96a2a"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="25.11%" id="mcps1.1.5.1.2"><p id="ad5b10d4a60e44bb4a8bbb3b4416d7b27"><a name="ad5b10d4a60e44bb4a8bbb3b4416d7b27"></a><a name="ad5b10d4a60e44bb4a8bbb3b4416d7b27"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="11.18%" id="mcps1.1.5.1.3"><p id="ab2ae3d9f60d6475ab95ba095851a9d07"><a name="ab2ae3d9f60d6475ab95ba095851a9d07"></a><a name="ab2ae3d9f60d6475ab95ba095851a9d07"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="38.67%" id="mcps1.1.5.1.4"><p id="af5c3b773ed0a42e589819a6c8d257ca1"><a name="af5c3b773ed0a42e589819a6c8d257ca1"></a><a name="af5c3b773ed0a42e589819a6c8d257ca1"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row9173122818343"><td class="cellrowborder" valign="top" width="25.040000000000003%" headers="mcps1.1.5.1.1 "><p id="p1517410284349"><a name="p1517410284349"></a><a name="p1517410284349"></a>index</p>
</td>
<td class="cellrowborder" valign="top" width="25.11%" headers="mcps1.1.5.1.2 "><p id="p1174172823415"><a name="p1174172823415"></a><a name="p1174172823415"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.18%" headers="mcps1.1.5.1.3 "><p id="p19174112863417"><a name="p19174112863417"></a><a name="p19174112863417"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="38.67%" headers="mcps1.1.5.1.4 "><p id="p7174328203414"><a name="p7174328203414"></a><a name="p7174328203414"></a>Index of the <strong id="b1432325813342"><a name="b1432325813342"></a><a name="b1432325813342"></a>&lt;stepper-item&gt;</strong> child component that is currently displayed.</p>
</td>
</tr>
</tbody>
</table>

## Style<a name="section72591594253"></a>

Styles in  [Universal Styles](js-components-common-styles.md)  are supported.

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>By default, the  **<stepper\>**  component fills entire space of its container. To optimize user experience, it is recommended that the container should be as large as the application window in size, or should be the root component.

## Event<a name="section69611614182911"></a>

In addition to the events in  [Universal Events](js-components-common-events.md), the following events are supported.

<a name="table836435619510"></a>
<table><thead align="left"><tr id="row153658563517"><th class="cellrowborder" valign="top" width="10.481048104810482%" id="mcps1.1.4.1.1"><p id="a0ff86a4560fa46bfbeb711d109869422"><a name="a0ff86a4560fa46bfbeb711d109869422"></a><a name="a0ff86a4560fa46bfbeb711d109869422"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="41.91419141914191%" id="mcps1.1.4.1.2"><p id="a4c85eb8ca18b4169a25c4a9263fa63ed"><a name="a4c85eb8ca18b4169a25c4a9263fa63ed"></a><a name="a4c85eb8ca18b4169a25c4a9263fa63ed"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="47.6047604760476%" id="mcps1.1.4.1.3"><p id="ab30b2353efa245fbad4d2aaa2ee33def"><a name="ab30b2353efa245fbad4d2aaa2ee33def"></a><a name="ab30b2353efa245fbad4d2aaa2ee33def"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row990553521718"><td class="cellrowborder" valign="top" width="10.481048104810482%" headers="mcps1.1.4.1.1 "><p id="p1390619353170"><a name="p1390619353170"></a><a name="p1390619353170"></a>finish</p>
</td>
<td class="cellrowborder" valign="top" width="41.91419141914191%" headers="mcps1.1.4.1.2 "><p id="p7906113541716"><a name="p7906113541716"></a><a name="p7906113541716"></a>None</p>
</td>
<td class="cellrowborder" valign="top" width="47.6047604760476%" headers="mcps1.1.4.1.3 "><p id="p7906113531711"><a name="p7906113531711"></a><a name="p7906113531711"></a>Triggered when the last step on the navigator is complete.</p>
</td>
</tr>
<tr id="row24211338161718"><td class="cellrowborder" valign="top" width="10.481048104810482%" headers="mcps1.1.4.1.1 "><p id="p2421113881715"><a name="p2421113881715"></a><a name="p2421113881715"></a>skip</p>
</td>
<td class="cellrowborder" valign="top" width="41.91419141914191%" headers="mcps1.1.4.1.2 "><p id="p16421133841719"><a name="p16421133841719"></a><a name="p16421133841719"></a>None</p>
</td>
<td class="cellrowborder" valign="top" width="47.6047604760476%" headers="mcps1.1.4.1.3 "><p id="p1342113381171"><a name="p1342113381171"></a><a name="p1342113381171"></a>Triggered when users click the skip button, which works only if you have called <strong id="b494641310465"><a name="b494641310465"></a><a name="b494641310465"></a>setNextButtonStatus</strong> method to allow users to skip all steps.</p>
</td>
</tr>
<tr id="row153591438186"><td class="cellrowborder" valign="top" width="10.481048104810482%" headers="mcps1.1.4.1.1 "><p id="p163591032182"><a name="p163591032182"></a><a name="p163591032182"></a>change</p>
</td>
<td class="cellrowborder" valign="top" width="41.91419141914191%" headers="mcps1.1.4.1.2 "><p id="p1535910381819"><a name="p1535910381819"></a><a name="p1535910381819"></a>{ prevIndex: prevIndex, index: index}</p>
</td>
<td class="cellrowborder" valign="top" width="47.6047604760476%" headers="mcps1.1.4.1.3 "><p id="p113602034189"><a name="p113602034189"></a><a name="p113602034189"></a>Triggered when users click the left or right (text) button of the step navigator to switch between steps. <strong id="b108361233105012"><a name="b108361233105012"></a><a name="b108361233105012"></a>prevIndex</strong> indicates the index of the previous step, and <strong id="b1014617216510"><a name="b1014617216510"></a><a name="b1014617216510"></a>index</strong> indicates that of the current step.</p>
</td>
</tr>
<tr id="row6686131145112"><td class="cellrowborder" valign="top" width="10.481048104810482%" headers="mcps1.1.4.1.1 "><p id="p126879113514"><a name="p126879113514"></a><a name="p126879113514"></a>next</p>
</td>
<td class="cellrowborder" valign="top" width="41.91419141914191%" headers="mcps1.1.4.1.2 "><p id="p06871911115113"><a name="p06871911115113"></a><a name="p06871911115113"></a>{ index: index, pendingIndex: pendingIndex }</p>
</td>
<td class="cellrowborder" valign="top" width="47.6047604760476%" headers="mcps1.1.4.1.3 "><p id="p18140235202411"><a name="p18140235202411"></a><a name="p18140235202411"></a>Triggered when users click the next (text) button. <strong id="b155446175519"><a name="b155446175519"></a><a name="b155446175519"></a>index</strong> indicates the index of the current step, and <strong id="b16471726587"><a name="b16471726587"></a><a name="b16471726587"></a>pendingIndex</strong> indicates that of the step to go. The return value is in <strong id="b20759101845911"><a name="b20759101845911"></a><a name="b20759101845911"></a>{pendingIndex:</strong><em id="i13961625125919"><a name="i13961625125919"></a><a name="i13961625125919"></a> pendingIndex</em><strong id="b1882982055918"><a name="b1882982055918"></a><a name="b1882982055918"></a>}</strong> format. You can use <strong id="b79512405598"><a name="b79512405598"></a><a name="b79512405598"></a>pendingIndex</strong> to specify a <strong id="b1235062917016"><a name="b1235062917016"></a><a name="b1235062917016"></a>&lt;stepper-item&gt;</strong> child component as the next step to go.</p>
</td>
</tr>
<tr id="row914118186514"><td class="cellrowborder" valign="top" width="10.481048104810482%" headers="mcps1.1.4.1.1 "><p id="p1414151817510"><a name="p1414151817510"></a><a name="p1414151817510"></a>back</p>
</td>
<td class="cellrowborder" valign="top" width="41.91419141914191%" headers="mcps1.1.4.1.2 "><p id="p16910122113429"><a name="p16910122113429"></a><a name="p16910122113429"></a>{ index: index, pendingIndex: pendingIndex }</p>
</td>
<td class="cellrowborder" valign="top" width="47.6047604760476%" headers="mcps1.1.4.1.3 "><p id="p714261895119"><a name="p714261895119"></a><a name="p714261895119"></a>Triggered when users click the previous (text) button. <strong id="b1620921210312"><a name="b1620921210312"></a><a name="b1620921210312"></a>index</strong> indicates the index of the current step, and <strong id="b1621511211318"><a name="b1621511211318"></a><a name="b1621511211318"></a>pendingIndex</strong> indicates that of the step to go. The return value is in Object:{ <strong id="b102171121532"><a name="b102171121532"></a><a name="b102171121532"></a>{pendingIndex:</strong><em id="i42187121636"><a name="i42187121636"></a><a name="i42187121636"></a> pendingIndex</em><strong id="b1622051211313"><a name="b1622051211313"></a><a name="b1622051211313"></a>}</strong> format. You can use <strong id="b822118128316"><a name="b822118128316"></a><a name="b822118128316"></a>pendingIndex</strong> to specify a <strong id="b192236121235"><a name="b192236121235"></a><a name="b192236121235"></a>&lt;stepper-item&gt;</strong> child component as the previous step.</p>
</td>
</tr>
</tbody>
</table>

## Method<a name="section1954212182148"></a>

In addition to the methods in  [Universal Methods](js-components-common-methods.md), the following events are supported.

<a name="table12793153991411"></a>
<table><thead align="left"><tr id="row15793239141412"><th class="cellrowborder" valign="top" width="19.561956195619562%" id="mcps1.1.4.1.1"><p id="p9794143915141"><a name="p9794143915141"></a><a name="p9794143915141"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="24.102410241024103%" id="mcps1.1.4.1.2"><p id="p107942395147"><a name="p107942395147"></a><a name="p107942395147"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="56.33563356335634%" id="mcps1.1.4.1.3"><p id="p11794133913143"><a name="p11794133913143"></a><a name="p11794133913143"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row157940399145"><td class="cellrowborder" valign="top" width="19.561956195619562%" headers="mcps1.1.4.1.1 "><p id="p1479453913144"><a name="p1479453913144"></a><a name="p1479453913144"></a>setNextButtonStatus</p>
</td>
<td class="cellrowborder" valign="top" width="24.102410241024103%" headers="mcps1.1.4.1.2 "><p id="p10794163914147"><a name="p10794163914147"></a><a name="p10794163914147"></a>{ status: string, label: label }</p>
</td>
<td class="cellrowborder" valign="top" width="56.33563356335634%" headers="mcps1.1.4.1.3 "><p id="p12794143917141"><a name="p12794143917141"></a><a name="p12794143917141"></a>Sets the status of the next (text) button in this step navigator. Available <strong id="b29094326514"><a name="b29094326514"></a><a name="b29094326514"></a>status</strong> values are as follows:</p>
<a name="ol12242138121713"></a><a name="ol12242138121713"></a><ol id="ol12242138121713"><li><strong id="b1032161115214"><a name="b1032161115214"></a><a name="b1032161115214"></a>normal</strong>: The next button is displayed normally and can navigate users to the next step when it is clicked.</li><li><strong id="b1661325920517"><a name="b1661325920517"></a><a name="b1661325920517"></a>disabled</strong>: The next button is grayed out and unavailable.</li><li><strong id="b873175710711"><a name="b873175710711"></a><a name="b873175710711"></a>waiting</strong>: The next button is not displayed, and a process bar is displayed instead.</li><li><strong id="b1990819331594"><a name="b1990819331594"></a><a name="b1990819331594"></a>skip</strong>: The skip button is displayed to allow users to skip all remaining steps.</li></ol>
</td>
</tr>
</tbody>
</table>

## Example Code<a name="section15374183712313"></a>

```
<!-- xxx.hml -->
<div class = "container">
  <stepper class="stepper" id="mystepper" index="0"  onnext="nextclick" onback="backclick">
    <stepper-item class ="stepperItem" label="{{label_1}}">
      <div class = "stepperItemContent" >
        <text class = "text">First screen</text>
      </div>
      <button type="capsule" class ="button" value="setRightButtonStatus" onclick="setRightButton"></button>
    </stepper-item>
    <stepper-item class ="stepperItem" label="{{label_2}}">
      <div class = "stepperItemContent" >
        <text class = "text">Second screen</text>
      </div>
      <button type="capsule" class ="button" value="setRightButtonStatus" onclick="setRightButton"></button>
    </stepper-item>
    <stepper-item class ="stepperItem" label="{{label_3}}">
      <div class = "stepperItemContent" >
        <text class = "text">Third screen</text>
      </div>
      <button type="capsule" class ="button" value="setRightButtonStatus" onclick="setRightButton"></button>
    </stepper-item>
  </stepper>
</div>
```

```
/* xxx.css */
.container {
  margin-top: 20px;
  flex-direction: column;
  align-items: center;
  height: 300px;
}
.stepperItem {
  flex-direction: column;
  align-items: center;
}
.stepperItemContent {
  color: #0000ff;
  font-size: 50px;
  justify-content: center;
}
.button {
  width: 60%;
  margin-top: 30px;
  justify-content: center;
}
```

```
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

![](figures/en-us_image_0000001127125114.gif)

