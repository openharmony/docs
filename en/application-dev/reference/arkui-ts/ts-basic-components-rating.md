# Rating<a name="EN-US_TOPIC_0000001192595156"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

The  **<Rating\>**  component provides a rating bar.

## Required Permissions<a name="section781125411508"></a>

None

## Child Components<a name="section53281531154915"></a>

None

## APIs<a name="section1989913519718"></a>

Rating\(options?: \{ rating: number, indicator?: boolean \}\)

-   Parameters

    <a name="table1392916196212"></a>
    <table><thead align="left"><tr id="row19306191218"><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p id="p199307193217"><a name="p199307193217"></a><a name="p199307193217"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.01%" id="mcps1.1.6.1.2"><p id="p119302191128"><a name="p119302191128"></a><a name="p119302191128"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="13%" id="mcps1.1.6.1.3"><p id="p7930141911211"><a name="p7930141911211"></a><a name="p7930141911211"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.869999999999997%" id="mcps1.1.6.1.4"><p id="p1393020194219"><a name="p1393020194219"></a><a name="p1393020194219"></a>Default Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="40.01%" id="mcps1.1.6.1.5"><p id="p693061912210"><a name="p693061912210"></a><a name="p693061912210"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1093021911217"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p119307198218"><a name="p119307198218"></a><a name="p119307198218"></a>rating</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.01%" headers="mcps1.1.6.1.2 "><p id="p129301719828"><a name="p129301719828"></a><a name="p129301719828"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="13%" headers="mcps1.1.6.1.3 "><p id="p893091913213"><a name="p893091913213"></a><a name="p893091913213"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.869999999999997%" headers="mcps1.1.6.1.4 "><p id="p421641117507"><a name="p421641117507"></a><a name="p421641117507"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.01%" headers="mcps1.1.6.1.5 "><p id="p693016198212"><a name="p693016198212"></a><a name="p693016198212"></a>Value to rate.</p>
    </td>
    </tr>
    <tr id="row199301191726"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p0930419923"><a name="p0930419923"></a><a name="p0930419923"></a>indicator</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.01%" headers="mcps1.1.6.1.2 "><p id="p1993071918217"><a name="p1993071918217"></a><a name="p1993071918217"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="13%" headers="mcps1.1.6.1.3 "><p id="p29309191029"><a name="p29309191029"></a><a name="p29309191029"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.869999999999997%" headers="mcps1.1.6.1.4 "><p id="p393019193220"><a name="p393019193220"></a><a name="p393019193220"></a>false</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.01%" headers="mcps1.1.6.1.5 "><p id="p793001918220"><a name="p793001918220"></a><a name="p793001918220"></a>Used only as an indicator and cannot be operated.</p>
    </td>
    </tr>
    </tbody>
    </table>


## Attributes<a name="section18430105671014"></a>

<a name="table181736291110"></a>
<table><thead align="left"><tr id="row1117442161117"><th class="cellrowborder" valign="top" width="13.84%" id="mcps1.1.5.1.1"><p id="p2017411217117"><a name="p2017411217117"></a><a name="p2017411217117"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="19.77%" id="mcps1.1.5.1.2"><p id="p1517432171118"><a name="p1517432171118"></a><a name="p1517432171118"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="10.38%" id="mcps1.1.5.1.3"><p id="p11174326110"><a name="p11174326110"></a><a name="p11174326110"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="56.010000000000005%" id="mcps1.1.5.1.4"><p id="p20174826118"><a name="p20174826118"></a><a name="p20174826118"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1007mcpsimp"><td class="cellrowborder" valign="top" width="13.84%" headers="mcps1.1.5.1.1 "><p id="p04101229003"><a name="p04101229003"></a><a name="p04101229003"></a>stars</p>
</td>
<td class="cellrowborder" valign="top" width="19.77%" headers="mcps1.1.5.1.2 "><p id="p1011mcpsimp"><a name="p1011mcpsimp"></a><a name="p1011mcpsimp"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.38%" headers="mcps1.1.5.1.3 "><p id="p1013mcpsimp"><a name="p1013mcpsimp"></a><a name="p1013mcpsimp"></a>5</p>
</td>
<td class="cellrowborder" valign="top" width="56.010000000000005%" headers="mcps1.1.5.1.4 "><p id="p3126411302"><a name="p3126411302"></a><a name="p3126411302"></a>Total number of stars.</p>
</td>
</tr>
<tr id="row173321411165311"><td class="cellrowborder" valign="top" width="13.84%" headers="mcps1.1.5.1.1 "><p id="p351415454015"><a name="p351415454015"></a><a name="p351415454015"></a>stepSize</p>
</td>
<td class="cellrowborder" valign="top" width="19.77%" headers="mcps1.1.5.1.2 "><p id="p43327112538"><a name="p43327112538"></a><a name="p43327112538"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.38%" headers="mcps1.1.5.1.3 "><p id="p193322011185315"><a name="p193322011185315"></a><a name="p193322011185315"></a>0.5</p>
</td>
<td class="cellrowborder" valign="top" width="56.010000000000005%" headers="mcps1.1.5.1.4 "><p id="p68256235554"><a name="p68256235554"></a><a name="p68256235554"></a>Step of an operation.</p>
</td>
</tr>
<tr id="row4821201513537"><td class="cellrowborder" valign="top" width="13.84%" headers="mcps1.1.5.1.1 "><p id="p2822615195315"><a name="p2822615195315"></a><a name="p2822615195315"></a>starStyle</p>
</td>
<td class="cellrowborder" valign="top" width="19.77%" headers="mcps1.1.5.1.2 "><p id="p112697110520"><a name="p112697110520"></a><a name="p112697110520"></a>{</p>
<p id="p101214416375"><a name="p101214416375"></a><a name="p101214416375"></a>backgroundUri: string,</p>
<p id="p38258993711"><a name="p38258993711"></a><a name="p38258993711"></a>foregroundUri: string,</p>
<p id="p88411654514"><a name="p88411654514"></a><a name="p88411654514"></a>secondaryUri?: string</p>
<p id="p198221415155318"><a name="p198221415155318"></a><a name="p198221415155318"></a>}</p>
</td>
<td class="cellrowborder" valign="top" width="10.38%" headers="mcps1.1.5.1.3 "><p id="p192321429143611"><a name="p192321429143611"></a><a name="p192321429143611"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="56.010000000000005%" headers="mcps1.1.5.1.4 "><p id="p1349715591831"><a name="p1349715591831"></a><a name="p1349715591831"></a><strong id="b596754622914"><a name="b596754622914"></a><a name="b596754622914"></a>backgroundSrc</strong>: image link of the unselected star. You can customize the image or use the default image. Only local images are supported.</p>
<p id="p166841745114110"><a name="p166841745114110"></a><a name="p166841745114110"></a><strong id="b61077216812"><a name="b61077216812"></a><a name="b61077216812"></a>foregroundSrc</strong>: image path of the selected star. You can customize the image or use the default image. Only local images are supported.</p>
<p id="p668494524114"><a name="p668494524114"></a><a name="p668494524114"></a><strong id="b496620252810"><a name="b496620252810"></a><a name="b496620252810"></a>secondarySrc</strong>: image path of the partially selected star. You can customize the image or use the default image. Only local images are supported.</p>
</td>
</tr>
</tbody>
</table>

## Events<a name="section449664852016"></a>

<a name="table952mcpsimp"></a>
<table><thead align="left"><tr id="row959mcpsimp"><th class="cellrowborder" colspan="2" valign="top" id="mcps1.1.4.1.1"><p id="p963mcpsimp"><a name="p963mcpsimp"></a><a name="p963mcpsimp"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.4.1.2"><p id="p967mcpsimp"><a name="p967mcpsimp"></a><a name="p967mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row163041291058"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p id="p1352619001912"><a name="p1352619001912"></a><a name="p1352619001912"></a>onChange(callback:(value: number) =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p18583122017217"><a name="p18583122017217"></a><a name="p18583122017217"></a>Triggered when the rating value changes.</p>
</td>
</tr>
</tbody>
</table>

## Example<a name="section13800193662114"></a>

```
@Entry
@Component
struct RatingExample {
  @State rating: number = 1
  @State indicator: boolean = false

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceBetween }) {
      Text('current score is ' + this.rating).fontSize(20)
      Rating({ rating: this.rating, indicator: this.indicator })
        .stars(5)
        .stepSize(0.5)
        .onChange((value: number) => {
          this.rating = value
        })
    }.width(350).height(200).padding(35)
  }
}
```

![](figures/rating.gif)

