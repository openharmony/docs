# Stepper<a name="EN-US_TOPIC_0000001237475075"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

The **<Stepper\>** component provides a step navigator.

## Applicable Devices<a name="section322851519172"></a>

<a name="table857714145377"></a>
<table><thead align="left"><tr id="row55778146373"><th class="cellrowborder" valign="top" width="23.66106080206986%" id="mcps1.1.5.1.1"><p id="p7577141417376"><a name="p7577141417376"></a><a name="p7577141417376"></a>Phone</p>
</th>
<th class="cellrowborder" valign="top" width="26.3130659767141%" id="mcps1.1.5.1.2"><p id="p487719816463"><a name="p487719816463"></a><a name="p487719816463"></a>Tablet</p>
</th>
<th class="cellrowborder" valign="top" width="24.63130659767141%" id="mcps1.1.5.1.3"><p id="p135771614203720"><a name="p135771614203720"></a><a name="p135771614203720"></a>Smart TV</p>
</th>
<th class="cellrowborder" valign="top" width="25.39456662354463%" id="mcps1.1.5.1.4"><p id="p25772014133712"><a name="p25772014133712"></a><a name="p25772014133712"></a>Wearable</p>
</th>
</tr>
</thead>
<tbody><tr id="row8578151423715"><td class="cellrowborder" valign="top" width="23.66106080206986%" headers="mcps1.1.5.1.1 "><p id="p65782014203718"><a name="p65782014203718"></a><a name="p65782014203718"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="26.3130659767141%" headers="mcps1.1.5.1.2 "><p id="p148771182469"><a name="p148771182469"></a><a name="p148771182469"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="24.63130659767141%" headers="mcps1.1.5.1.3 "><p id="p45783141377"><a name="p45783141377"></a><a name="p45783141377"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="25.39456662354463%" headers="mcps1.1.5.1.4 "><p id="p11578161443718"><a name="p11578161443718"></a><a name="p11578161443718"></a>No</p>
</td>
</tr>
</tbody>
</table>

## Required Permissions<a name="section988262631714"></a>

None

## Child Components<a name="section5989144051714"></a>

Only the child component  [StepperItem](ts-container-stepperitem.md)  is supported.

## APIs<a name="section121394874010"></a>

Stepper\(value?: \{ index?: number \}\)

-   Parameters

    <a name="table193606194544"></a>
    <table><thead align="left"><tr id="row536071910541"><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p id="p436112199544"><a name="p436112199544"></a><a name="p436112199544"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="19.3%" id="mcps1.1.6.1.2"><p id="p19361319115410"><a name="p19361319115410"></a><a name="p19361319115410"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.77%" id="mcps1.1.6.1.3"><p id="p9361201975417"><a name="p9361201975417"></a><a name="p9361201975417"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="18.6%" id="mcps1.1.6.1.4"><p id="p43611199542"><a name="p43611199542"></a><a name="p43611199542"></a>Default Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="36.22%" id="mcps1.1.6.1.5"><p id="p1136141975419"><a name="p1136141975419"></a><a name="p1136141975419"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1860154012417"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p108611240343"><a name="p108611240343"></a><a name="p108611240343"></a>index</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.3%" headers="mcps1.1.6.1.2 "><p id="p17861154015414"><a name="p17861154015414"></a><a name="p17861154015414"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.77%" headers="mcps1.1.6.1.3 "><p id="p986119408419"><a name="p986119408419"></a><a name="p986119408419"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.6%" headers="mcps1.1.6.1.4 "><p id="p1186174019416"><a name="p1186174019416"></a><a name="p1186174019416"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.22%" headers="mcps1.1.6.1.5 "><p id="p1817710477247"><a name="p1817710477247"></a><a name="p1817710477247"></a>Index of the <strong id="b419913377265"><a name="b419913377265"></a><a name="b419913377265"></a>&lt;StepperItem&gt;</strong> child component that is currently displayed.</p>
    </td>
    </tr>
    </tbody>
    </table>


## Attributes<a name="section1328124354614"></a>

None

## Events<a name="section39758242515"></a>

<a name="table8357154384818"></a>
<table><thead align="left"><tr id="row193571443174812"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1421714614914"><a name="p1421714614914"></a><a name="p1421714614914"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2021510618499"><a name="p2021510618499"></a><a name="p2021510618499"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row183583433482"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p27916611253"><a name="p27916611253"></a><a name="p27916611253"></a>onFinish(callback: () =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p279466258"><a name="p279466258"></a><a name="p279466258"></a>Triggered when the **nextLabel** of the last stepper item in the stepper is clicked.</p>
</td>
</tr>
<tr id="row19673142511492"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p9791660257"><a name="p9791660257"></a><a name="p9791660257"></a>onSkip(callback: () =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p197946102518"><a name="p197946102518"></a><a name="p197946102518"></a>Triggered when the current stepper item is **ItemState.Skip** and the **nextLabel** is clicked.</p>
</td>
</tr>
<tr id="row10943194817521"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p147915662519"><a name="p147915662519"></a><a name="p147915662519"></a>onChange(callback: (prevIndex?: number, index?: number) =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p3795613254"><a name="p3795613254"></a><a name="p3795613254"></a>Triggered when the text button on the left or right is clicked to switch between steps.</p>
<a name="ul695894120615"></a><a name="ul695894120615"></a><ul id="ul695894120615"><li>**prevIndex**: index of the step page before the switching. </li><li>**index**: index of the step page after the switching, that is, index of the previous or next page.</li></ul>
</td>
</tr>
</tbody>
</table>

## Example<a name="section1512314422316"></a>

```
@Entry
@Component
struct StepperExample {
  @State currentIndex: number = 0
  @State firstState: ItemState = ItemState.Normal
  @State secondState: ItemState = ItemState.Normal

  build() {
    Stepper({
      index: this.currentIndex
    }) {
      StepperItem() {
        Text('Page One')
          .fontSize(35)
          .fontColor(Color.Blue)
          .width(200)
          .lineHeight(50)
          .margin({top:250})
      }
      .nextLabel('')
      .position({x: '35%', y: 0})
      StepperItem() {
        Text('Page Two')
          .fontSize(35)
          .fontColor(Color.Blue)
          .width(200)
          .lineHeight(50)
          .margin({top:250})
          .onClick(()=>{
            this.firstState = this.firstState === ItemState.Skip ? ItemState.Normal : ItemState.Skip
          })
      }
      .nextLabel('Next')
      .prevLabel('Previous')
      .status(this.firstState)
      .position({x: '35%', y: 0})
      StepperItem() {
        Text('Page Three')
          .fontSize(35)
          .fontColor(Color.Blue)
          .width(200)
          .lineHeight(50)
          .margin({top:250})
          .onClick(()=>{
            this.secondState = this.secondState === ItemState.Waiting ? ItemState.Normal : ItemState.Waiting
          })
      }
      .position({x: '35%', y: 0})
      .status(this.secondState)
      StepperItem() {
        Text('Page four')
          .fontSize(35)
          .fontColor(Color.Blue)
          .width(200)
          .lineHeight(50)
          .margin({top:250})
      }
      .position({x: '35%', y: 0})
      .nextLabel('Finish')
    }
    .onFinish(() => {
      console.log('onFinish')
    })
    .onSkip(() => {
      console.log('onSkip')
    })
    .onChange((prevIndex: number, index: number) => {
      this.currentIndex = index
    })
    .align(Alignment.Center)
  }
}
```

![](figures/en-us_image_0000001239788885.gif)
