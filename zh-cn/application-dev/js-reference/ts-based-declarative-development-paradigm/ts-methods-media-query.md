# 媒体查询<a name="ZH-CN_TOPIC_0000001211727455"></a>

## 导入模块<a name="section377963175114"></a>

```
import mediaquery from '@ohos.mediaquery'
```

## 权限<a name="section1455919446525"></a>

无

## mediaquery.matchMediaSync<a name="section741924715916"></a>

matchMediaSync\(condition: string\): MediaQueryListener

设置媒体查询的查询条件，并返回对应的监听句柄。

-   参数

    <a name="table69661135912"></a>
    <table><thead align="left"><tr id="row149668318915"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p7966738914"><a name="p7966738914"></a><a name="p7966738914"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p296713699"><a name="p296713699"></a><a name="p296713699"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p196718315911"><a name="p196718315911"></a><a name="p196718315911"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p9967231197"><a name="p9967231197"></a><a name="p9967231197"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row18967831393"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p39671131590"><a name="p39671131590"></a><a name="p39671131590"></a>condition</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p126051952172518"><a name="p126051952172518"></a><a name="p126051952172518"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p149671932919"><a name="p149671932919"></a><a name="p149671932919"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p19675312911"><a name="p19675312911"></a><a name="p19675312911"></a>媒体事件的匹配条件。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    <a name="table16391145317913"></a>
    <table><thead align="left"><tr id="row2391145319910"><th class="cellrowborder" valign="top" width="38.64%" id="mcps1.1.3.1.1"><p id="p13911353991"><a name="p13911353991"></a><a name="p13911353991"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.36000000000001%" id="mcps1.1.3.1.2"><p id="p193911531395"><a name="p193911531395"></a><a name="p193911531395"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1339114531391"><td class="cellrowborder" valign="top" width="38.64%" headers="mcps1.1.3.1.1 "><p id="p73929531797"><a name="p73929531797"></a><a name="p73929531797"></a>MediaQueryListener</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.36000000000001%" headers="mcps1.1.3.1.2 "><p id="p1039217531898"><a name="p1039217531898"></a><a name="p1039217531898"></a>媒体事件监听句柄，用于注册和去注册监听回调。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    listener = mediaquery.matchMediaSync('(orientation: landscape)'); //监听横屏事件
    ```


## MediaQueryListener<a name="section75051320581"></a>

媒体查询的句柄，并包含了申请句柄时的首次查询结果。

### 属性<a name="section18895184419209"></a>

<a name="table728861911417"></a>
<table><thead align="left"><tr id="row62887198149"><th class="cellrowborder" valign="top" width="11.360000000000001%" id="mcps1.1.6.1.1"><p id="p928811911410"><a name="p928811911410"></a><a name="p928811911410"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="14.62%" id="mcps1.1.6.1.2"><p id="p8288191916149"><a name="p8288191916149"></a><a name="p8288191916149"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.73%" id="mcps1.1.6.1.3"><p id="p14288131911418"><a name="p14288131911418"></a><a name="p14288131911418"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="9.04%" id="mcps1.1.6.1.4"><p id="p1928861921411"><a name="p1928861921411"></a><a name="p1928861921411"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="55.25%" id="mcps1.1.6.1.5"><p id="p728815191149"><a name="p728815191149"></a><a name="p728815191149"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1685020236504"><td class="cellrowborder" valign="top" width="11.360000000000001%" headers="mcps1.1.6.1.1 "><p id="p178511423205014"><a name="p178511423205014"></a><a name="p178511423205014"></a>matches</p>
</td>
<td class="cellrowborder" valign="top" width="14.62%" headers="mcps1.1.6.1.2 "><p id="p1485102317502"><a name="p1485102317502"></a><a name="p1485102317502"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="9.73%" headers="mcps1.1.6.1.3 "><p id="p8851182313502"><a name="p8851182313502"></a><a name="p8851182313502"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.1.6.1.4 "><p id="p5851132320503"><a name="p5851132320503"></a><a name="p5851132320503"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="55.25%" headers="mcps1.1.6.1.5 "><p id="p138511223195014"><a name="p138511223195014"></a><a name="p138511223195014"></a>是否符合匹配条件。</p>
</td>
</tr>
<tr id="row528891919142"><td class="cellrowborder" valign="top" width="11.360000000000001%" headers="mcps1.1.6.1.1 "><p id="p3288191991414"><a name="p3288191991414"></a><a name="p3288191991414"></a>media</p>
</td>
<td class="cellrowborder" valign="top" width="14.62%" headers="mcps1.1.6.1.2 "><p id="p3288121901418"><a name="p3288121901418"></a><a name="p3288121901418"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.73%" headers="mcps1.1.6.1.3 "><p id="p182881319191414"><a name="p182881319191414"></a><a name="p182881319191414"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.1.6.1.4 "><p id="p1928801914148"><a name="p1928801914148"></a><a name="p1928801914148"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="55.25%" headers="mcps1.1.6.1.5 "><p id="p1428811192144"><a name="p1428811192144"></a><a name="p1428811192144"></a>媒体事件的匹配条件。</p>
</td>
</tr>
</tbody>
</table>

### on<a name="section7716132985"></a>

on\(type: 'change', callback: Callback<MediaQueryResult\>\): void

通过句柄向对应的查询条件注册回调，当媒体属性发生变更时会触发该回调。

-   参数

    <a name="table32286131687"></a>
    <table><thead align="left"><tr id="row0228213582"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p52285131883"><a name="p52285131883"></a><a name="p52285131883"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="34.29%" id="mcps1.1.5.1.2"><p id="p1422811131180"><a name="p1422811131180"></a><a name="p1422811131180"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.79%" id="mcps1.1.5.1.3"><p id="p8228151310812"><a name="p8228151310812"></a><a name="p8228151310812"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="40.1%" id="mcps1.1.5.1.4"><p id="p1022816131182"><a name="p1022816131182"></a><a name="p1022816131182"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row322812133816"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1422881315812"><a name="p1422881315812"></a><a name="p1422881315812"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.29%" headers="mcps1.1.5.1.2 "><p id="p922811131387"><a name="p922811131387"></a><a name="p922811131387"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.79%" headers="mcps1.1.5.1.3 "><p id="p112281713086"><a name="p112281713086"></a><a name="p112281713086"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.1%" headers="mcps1.1.5.1.4 "><p id="p7228151310816"><a name="p7228151310816"></a><a name="p7228151310816"></a>必须填写字符串'change'。</p>
    </td>
    </tr>
    <tr id="row1022810134810"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p122281131387"><a name="p122281131387"></a><a name="p122281131387"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.29%" headers="mcps1.1.5.1.2 "><p id="p132291413386"><a name="p132291413386"></a><a name="p132291413386"></a>Callback&lt;MediaQueryResult&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.79%" headers="mcps1.1.5.1.3 "><p id="p9229121319814"><a name="p9229121319814"></a><a name="p9229121319814"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.1%" headers="mcps1.1.5.1.4 "><p id="p1822921310817"><a name="p1822921310817"></a><a name="p1822921310817"></a>向媒体查询注册的回调。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    详见[off示例](#li16426122219256)。


### off<a name="section1115119201599"></a>

off\(type: 'change', callback?: Callback<MediaQueryResult\>\): void

通过句柄向对应的查询条件去注册回调，当媒体属性发生变更时不在触发指定的回调。

-   参数

    <a name="table14251722102517"></a>
    <table><thead align="left"><tr id="row5425112210251"><th class="cellrowborder" valign="top" width="10.9%" id="mcps1.1.5.1.1"><p id="p14257225253"><a name="p14257225253"></a><a name="p14257225253"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.17%" id="mcps1.1.5.1.2"><p id="p13425132292510"><a name="p13425132292510"></a><a name="p13425132292510"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.15%" id="mcps1.1.5.1.3"><p id="p5425172217256"><a name="p5425172217256"></a><a name="p5425172217256"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="47.78%" id="mcps1.1.5.1.4"><p id="p1425192272517"><a name="p1425192272517"></a><a name="p1425192272517"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row14425122212512"><td class="cellrowborder" valign="top" width="10.9%" headers="mcps1.1.5.1.1 "><p id="p6425102242516"><a name="p6425102242516"></a><a name="p6425102242516"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.17%" headers="mcps1.1.5.1.2 "><p id="p342512228259"><a name="p342512228259"></a><a name="p342512228259"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.15%" headers="mcps1.1.5.1.3 "><p id="p54261122192510"><a name="p54261122192510"></a><a name="p54261122192510"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="47.78%" headers="mcps1.1.5.1.4 "><p id="p5426922182516"><a name="p5426922182516"></a><a name="p5426922182516"></a>必须填写字符串'change'。</p>
    </td>
    </tr>
    <tr id="row842672252515"><td class="cellrowborder" valign="top" width="10.9%" headers="mcps1.1.5.1.1 "><p id="p3426622102515"><a name="p3426622102515"></a><a name="p3426622102515"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.17%" headers="mcps1.1.5.1.2 "><p id="p1242652272513"><a name="p1242652272513"></a><a name="p1242652272513"></a>Callback&lt;MediaQueryResult&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.15%" headers="mcps1.1.5.1.3 "><p id="p94261122162514"><a name="p94261122162514"></a><a name="p94261122162514"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="47.78%" headers="mcps1.1.5.1.4 "><p id="p104261522192514"><a name="p104261522192514"></a><a name="p104261522192514"></a>需要去注册的回调，如果参数缺省则去注册该句柄下所有的回调。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   <a name="li16426122219256"></a>示例

    ```
    listener = mediaquery.matchMediaSync('(orientation: landscape)'); //监听横屏事件
    onPortrait(mediaQueryResult) {
        if (mediaQueryResult.matches) {
            // do something here
        } else {
            // do something here
        }
    }
    listener.on('change', onPortrait) // 注册回调
    listener.off('change', onPortrait) // 去注册回调
    ```


## MediaQueryResult<a name="section7256173818228"></a>

### 属性<a name="section126081122120"></a>

<a name="table1187902722312"></a>
<table><thead align="left"><tr id="row787972732314"><th class="cellrowborder" valign="top" width="11.360000000000001%" id="mcps1.1.6.1.1"><p id="p8879162762313"><a name="p8879162762313"></a><a name="p8879162762313"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="14.62%" id="mcps1.1.6.1.2"><p id="p1287992732315"><a name="p1287992732315"></a><a name="p1287992732315"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.73%" id="mcps1.1.6.1.3"><p id="p13879202742314"><a name="p13879202742314"></a><a name="p13879202742314"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="9.04%" id="mcps1.1.6.1.4"><p id="p3879112762317"><a name="p3879112762317"></a><a name="p3879112762317"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="55.25%" id="mcps1.1.6.1.5"><p id="p11879527112318"><a name="p11879527112318"></a><a name="p11879527112318"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row10879102720231"><td class="cellrowborder" valign="top" width="11.360000000000001%" headers="mcps1.1.6.1.1 "><p id="p158791927202314"><a name="p158791927202314"></a><a name="p158791927202314"></a>matches</p>
</td>
<td class="cellrowborder" valign="top" width="14.62%" headers="mcps1.1.6.1.2 "><p id="p087932714238"><a name="p087932714238"></a><a name="p087932714238"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="9.73%" headers="mcps1.1.6.1.3 "><p id="p18879727172317"><a name="p18879727172317"></a><a name="p18879727172317"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.1.6.1.4 "><p id="p987972717232"><a name="p987972717232"></a><a name="p987972717232"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="55.25%" headers="mcps1.1.6.1.5 "><p id="p19880162782314"><a name="p19880162782314"></a><a name="p19880162782314"></a>是否符合匹配条件。</p>
</td>
</tr>
<tr id="row1488015273234"><td class="cellrowborder" valign="top" width="11.360000000000001%" headers="mcps1.1.6.1.1 "><p id="p10880172752314"><a name="p10880172752314"></a><a name="p10880172752314"></a>media</p>
</td>
<td class="cellrowborder" valign="top" width="14.62%" headers="mcps1.1.6.1.2 "><p id="p1888052717236"><a name="p1888052717236"></a><a name="p1888052717236"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.73%" headers="mcps1.1.6.1.3 "><p id="p788072719231"><a name="p788072719231"></a><a name="p788072719231"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.1.6.1.4 "><p id="p3880202762314"><a name="p3880202762314"></a><a name="p3880202762314"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="55.25%" headers="mcps1.1.6.1.5 "><p id="p1788015272236"><a name="p1788015272236"></a><a name="p1788015272236"></a>媒体事件的匹配条件。</p>
</td>
</tr>
</tbody>
</table>

### 示例<a name="section1120571611214"></a>

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

![](figures/MediaQuery.gif)

