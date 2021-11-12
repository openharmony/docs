# Media Query<a name="EN-US_TOPIC_0000001211727455"></a>

## Modules to Import<a name="section377963175114"></a>

```
import mediaquery from '@ohos.mediaquery'
```

## Required Permissions<a name="section1455919446525"></a>

None

## mediaquery.matchMediaSync<a name="section741924715916"></a>

matchMediaSync\(condition: string\): MediaQueryListener

Sets the media query criteria and returns the corresponding listening handle.

-   Parameters

    <a name="table69661135912"></a>
    <table><thead align="left"><tr id="row149668318915"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p7966738914"><a name="p7966738914"></a><a name="p7966738914"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p296713699"><a name="p296713699"></a><a name="p296713699"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p196718315911"><a name="p196718315911"></a><a name="p196718315911"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p9967231197"><a name="p9967231197"></a><a name="p9967231197"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row18967831393"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p39671131590"><a name="p39671131590"></a><a name="p39671131590"></a>condition</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p126051952172518"><a name="p126051952172518"></a><a name="p126051952172518"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p149671932919"><a name="p149671932919"></a><a name="p149671932919"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p19675312911"><a name="p19675312911"></a><a name="p19675312911"></a>Matching condition of a media event. For details about the condition string format, see <a href="../../nottoctopics/en-us_topic_0000001173164741.md">Media Query</a>.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table16391145317913"></a>
    <table><thead align="left"><tr id="row2391145319910"><th class="cellrowborder" valign="top" width="38.64%" id="mcps1.1.3.1.1"><p id="p13911353991"><a name="p13911353991"></a><a name="p13911353991"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.36000000000001%" id="mcps1.1.3.1.2"><p id="p193911531395"><a name="p193911531395"></a><a name="p193911531395"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1339114531391"><td class="cellrowborder" valign="top" width="38.64%" headers="mcps1.1.3.1.1 "><p id="p73929531797"><a name="p73929531797"></a><a name="p73929531797"></a>MediaQueryListener</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.36000000000001%" headers="mcps1.1.3.1.2 "><p id="p1039217531898"><a name="p1039217531898"></a><a name="p1039217531898"></a>Listening handle to a media event, which is used to register or unregister the listening callback.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    listener = mediaquery.matchMediaSync('(orientation: landscape)'); // Listen to landscape events.
    ```


## MediaQueryListener<a name="section75051320581"></a>

Media query handle, including the first query result when the handle is applied for.

### Attributes<a name="section18895184419209"></a>

<a name="table728861911417"></a>
<table><thead align="left"><tr id="row62887198149"><th class="cellrowborder" valign="top" width="11.360000000000001%" id="mcps1.1.6.1.1"><p id="p928811911410"><a name="p928811911410"></a><a name="p928811911410"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="14.62%" id="mcps1.1.6.1.2"><p id="p8288191916149"><a name="p8288191916149"></a><a name="p8288191916149"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="9.73%" id="mcps1.1.6.1.3"><p id="p14288131911418"><a name="p14288131911418"></a><a name="p14288131911418"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="9.04%" id="mcps1.1.6.1.4"><p id="p1928861921411"><a name="p1928861921411"></a><a name="p1928861921411"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="55.25%" id="mcps1.1.6.1.5"><p id="p728815191149"><a name="p728815191149"></a><a name="p728815191149"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1685020236504"><td class="cellrowborder" valign="top" width="11.360000000000001%" headers="mcps1.1.6.1.1 "><p id="p178511423205014"><a name="p178511423205014"></a><a name="p178511423205014"></a>matches</p>
</td>
<td class="cellrowborder" valign="top" width="14.62%" headers="mcps1.1.6.1.2 "><p id="p1485102317502"><a name="p1485102317502"></a><a name="p1485102317502"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="9.73%" headers="mcps1.1.6.1.3 "><p id="p8851182313502"><a name="p8851182313502"></a><a name="p8851182313502"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.1.6.1.4 "><p id="p5851132320503"><a name="p5851132320503"></a><a name="p5851132320503"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="55.25%" headers="mcps1.1.6.1.5 "><p id="p138511223195014"><a name="p138511223195014"></a><a name="p138511223195014"></a>Whether the match condition is met.</p>
</td>
</tr>
<tr id="row528891919142"><td class="cellrowborder" valign="top" width="11.360000000000001%" headers="mcps1.1.6.1.1 "><p id="p3288191991414"><a name="p3288191991414"></a><a name="p3288191991414"></a>media</p>
</td>
<td class="cellrowborder" valign="top" width="14.62%" headers="mcps1.1.6.1.2 "><p id="p3288121901418"><a name="p3288121901418"></a><a name="p3288121901418"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.73%" headers="mcps1.1.6.1.3 "><p id="p182881319191414"><a name="p182881319191414"></a><a name="p182881319191414"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.1.6.1.4 "><p id="p1928801914148"><a name="p1928801914148"></a><a name="p1928801914148"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="55.25%" headers="mcps1.1.6.1.5 "><p id="p1428811192144"><a name="p1428811192144"></a><a name="p1428811192144"></a>Matching condition of a media event.</p>
</td>
</tr>
</tbody>
</table>

### on<a name="section7716132985"></a>

on\(type: 'change', callback: Callback<MediaQueryResult\>\): void

Registers a callback with the corresponding query condition by using the handle. This callback is triggered when the media attributes change.

-   Parameters

    <a name="table32286131687"></a>
    <table><thead align="left"><tr id="row0228213582"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p52285131883"><a name="p52285131883"></a><a name="p52285131883"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="34.29%" id="mcps1.1.5.1.2"><p id="p1422811131180"><a name="p1422811131180"></a><a name="p1422811131180"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.79%" id="mcps1.1.5.1.3"><p id="p8228151310812"><a name="p8228151310812"></a><a name="p8228151310812"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="40.1%" id="mcps1.1.5.1.4"><p id="p1022816131182"><a name="p1022816131182"></a><a name="p1022816131182"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row322812133816"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1422881315812"><a name="p1422881315812"></a><a name="p1422881315812"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.29%" headers="mcps1.1.5.1.2 "><p id="p922811131387"><a name="p922811131387"></a><a name="p922811131387"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.79%" headers="mcps1.1.5.1.3 "><p id="p112281713086"><a name="p112281713086"></a><a name="p112281713086"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.1%" headers="mcps1.1.5.1.4 "><p id="p7228151310816"><a name="p7228151310816"></a><a name="p7228151310816"></a>Must enter the string <strong id="b5423143114312"><a name="b5423143114312"></a><a name="b5423143114312"></a>change</strong>.</p>
    </td>
    </tr>
    <tr id="row1022810134810"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p122281131387"><a name="p122281131387"></a><a name="p122281131387"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.29%" headers="mcps1.1.5.1.2 "><p id="p132291413386"><a name="p132291413386"></a><a name="p132291413386"></a>Callback&lt;MediaQueryResult&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.79%" headers="mcps1.1.5.1.3 "><p id="p9229121319814"><a name="p9229121319814"></a><a name="p9229121319814"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.1%" headers="mcps1.1.5.1.4 "><p id="p1822921310817"><a name="p1822921310817"></a><a name="p1822921310817"></a>Callback registered with media query.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    For details, see the  [off example](#li16426122219256).


### off<a name="section1115119201599"></a>

off\(type: 'change', callback?: Callback<MediaQueryResult\>\): void

Unregisters a callback with the corresponding query condition by using the handle, so that no callback is triggered when the media attributes change.

-   Parameters

    <a name="table14251722102517"></a>
    <table><thead align="left"><tr id="row5425112210251"><th class="cellrowborder" valign="top" width="10.9%" id="mcps1.1.5.1.1"><p id="p14257225253"><a name="p14257225253"></a><a name="p14257225253"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.17%" id="mcps1.1.5.1.2"><p id="p13425132292510"><a name="p13425132292510"></a><a name="p13425132292510"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.15%" id="mcps1.1.5.1.3"><p id="p5425172217256"><a name="p5425172217256"></a><a name="p5425172217256"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="47.78%" id="mcps1.1.5.1.4"><p id="p1425192272517"><a name="p1425192272517"></a><a name="p1425192272517"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row14425122212512"><td class="cellrowborder" valign="top" width="10.9%" headers="mcps1.1.5.1.1 "><p id="p6425102242516"><a name="p6425102242516"></a><a name="p6425102242516"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.17%" headers="mcps1.1.5.1.2 "><p id="p342512228259"><a name="p342512228259"></a><a name="p342512228259"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.15%" headers="mcps1.1.5.1.3 "><p id="p54261122192510"><a name="p54261122192510"></a><a name="p54261122192510"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="47.78%" headers="mcps1.1.5.1.4 "><p id="p5426922182516"><a name="p5426922182516"></a><a name="p5426922182516"></a>Must enter the string <strong id="b7194165223620"><a name="b7194165223620"></a><a name="b7194165223620"></a>change</strong>.</p>
    </td>
    </tr>
    <tr id="row842672252515"><td class="cellrowborder" valign="top" width="10.9%" headers="mcps1.1.5.1.1 "><p id="p3426622102515"><a name="p3426622102515"></a><a name="p3426622102515"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.17%" headers="mcps1.1.5.1.2 "><p id="p1242652272513"><a name="p1242652272513"></a><a name="p1242652272513"></a>Callback&lt;MediaQueryResult&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.15%" headers="mcps1.1.5.1.3 "><p id="p94261122162514"><a name="p94261122162514"></a><a name="p94261122162514"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="47.78%" headers="mcps1.1.5.1.4 "><p id="p104261522192514"><a name="p104261522192514"></a><a name="p104261522192514"></a>Callback to be unregistered. If the default value is used, all callbacks of the handle are unregistered.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   <a name="li16426122219256"></a>Example

    ```
    listener = mediaquery.matchMediaSync('(orientation: landscape)'); // Listens to landscape events.
    onPortrait(mediaQueryResult) {
        if (mediaQueryResult.matches) {
            // do something here
        } else {
            // do something here
        }
    }
    listener.on('change', onPortrait) // Register a callback.
    listener.off('change', onPortrait) // Unregister a callback.
    ```


## MediaQueryResult<a name="section7256173818228"></a>

### Attributes<a name="section126081122120"></a>

<a name="table1187902722312"></a>
<table><thead align="left"><tr id="row787972732314"><th class="cellrowborder" valign="top" width="11.360000000000001%" id="mcps1.1.6.1.1"><p id="p8879162762313"><a name="p8879162762313"></a><a name="p8879162762313"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="14.62%" id="mcps1.1.6.1.2"><p id="p1287992732315"><a name="p1287992732315"></a><a name="p1287992732315"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="9.73%" id="mcps1.1.6.1.3"><p id="p13879202742314"><a name="p13879202742314"></a><a name="p13879202742314"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="9.04%" id="mcps1.1.6.1.4"><p id="p3879112762317"><a name="p3879112762317"></a><a name="p3879112762317"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="55.25%" id="mcps1.1.6.1.5"><p id="p11879527112318"><a name="p11879527112318"></a><a name="p11879527112318"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row10879102720231"><td class="cellrowborder" valign="top" width="11.360000000000001%" headers="mcps1.1.6.1.1 "><p id="p158791927202314"><a name="p158791927202314"></a><a name="p158791927202314"></a>matches</p>
</td>
<td class="cellrowborder" valign="top" width="14.62%" headers="mcps1.1.6.1.2 "><p id="p087932714238"><a name="p087932714238"></a><a name="p087932714238"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="9.73%" headers="mcps1.1.6.1.3 "><p id="p18879727172317"><a name="p18879727172317"></a><a name="p18879727172317"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.1.6.1.4 "><p id="p987972717232"><a name="p987972717232"></a><a name="p987972717232"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="55.25%" headers="mcps1.1.6.1.5 "><p id="p19880162782314"><a name="p19880162782314"></a><a name="p19880162782314"></a>Whether the match condition is met.</p>
</td>
</tr>
<tr id="row1488015273234"><td class="cellrowborder" valign="top" width="11.360000000000001%" headers="mcps1.1.6.1.1 "><p id="p10880172752314"><a name="p10880172752314"></a><a name="p10880172752314"></a>media</p>
</td>
<td class="cellrowborder" valign="top" width="14.62%" headers="mcps1.1.6.1.2 "><p id="p1888052717236"><a name="p1888052717236"></a><a name="p1888052717236"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.73%" headers="mcps1.1.6.1.3 "><p id="p788072719231"><a name="p788072719231"></a><a name="p788072719231"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.1.6.1.4 "><p id="p3880202762314"><a name="p3880202762314"></a><a name="p3880202762314"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="55.25%" headers="mcps1.1.6.1.5 "><p id="p1788015272236"><a name="p1788015272236"></a><a name="p1788015272236"></a>Matching condition of a media event.</p>
</td>
</tr>
</tbody>
</table>

### Example<a name="section1120571611214"></a>

```
import mediaquery from '@ohos.mediaquery'

let portraitFunc = null

@Entry
@Component
struct MediaQueryExample {
  @State color: string = '#DB7093'
  @State text: string = 'Portrait'
  listener = mediaquery.matchMediaSync('(orientation: landscape)')

  onPortrait(mediaQueryResult) {
    if (mediaQueryResult.matches) {
      this.color = '#FFD700'
      this.text = 'Landscape'
    } else {
      this.color = '#DB7093'
      this.text = 'Portrait'
    }
  }

  aboutToAppear() {
    portraitFunc = this.onPortrait.bind(this) //bind current js instance
    this.listener.on('change', portraitFunc)
  }

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Text(this.text).fontSize(24).fontColor(this.color)
    }
    .width('100%').height('100%')
  }
}
```

![](figures/mediaquery.gif)

