# 媒体查询<a name="ZH-CN_TOPIC_0000001237555091"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

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

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p>condition</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p>媒体事件的匹配条件。条件字符串格式: 参考<a href="../../nottoctopics/zh-cn_topic_0000001173164741.md">媒体查询</a>。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="38.64%" id="mcps1.1.3.1.1"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.36000000000001%" id="mcps1.1.3.1.2"><p>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="38.64%" headers="mcps1.1.3.1.1 "><p>MediaQueryListener</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.36000000000001%" headers="mcps1.1.3.1.2 "><p>媒体事件监听句柄，用于注册和去注册监听回调。</p>
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

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="11.360000000000001%" id="mcps1.1.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="14.62%" id="mcps1.1.6.1.2"><p>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.73%" id="mcps1.1.6.1.3"><p>可读</p>
</th>
<th class="cellrowborder" valign="top" width="9.04%" id="mcps1.1.6.1.4"><p>可写</p>
</th>
<th class="cellrowborder" valign="top" width="55.25%" id="mcps1.1.6.1.5"><p>说明</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="11.360000000000001%" headers="mcps1.1.6.1.1 "><p>matches</p>
</td>
<td class="cellrowborder" valign="top" width="14.62%" headers="mcps1.1.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="9.73%" headers="mcps1.1.6.1.3 "><p>是</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="55.25%" headers="mcps1.1.6.1.5 "><p>是否符合匹配条件。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="11.360000000000001%" headers="mcps1.1.6.1.1 "><p>media</p>
</td>
<td class="cellrowborder" valign="top" width="14.62%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.73%" headers="mcps1.1.6.1.3 "><p>是</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="55.25%" headers="mcps1.1.6.1.5 "><p>媒体事件的匹配条件。</p>
</td>
</tr>
</tbody>
</table>

### on<a name="section7716132985"></a>

on\(type: 'change', callback: Callback<MediaQueryResult\>\): void

通过句柄向对应的查询条件注册回调，当媒体属性发生变更时会触发该回调。

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="34.29%" id="mcps1.1.5.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.79%" id="mcps1.1.5.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="40.1%" id="mcps1.1.5.1.4"><p>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.29%" headers="mcps1.1.5.1.2 "><p>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.79%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.1%" headers="mcps1.1.5.1.4 "><p>必须填写字符串'change'。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.29%" headers="mcps1.1.5.1.2 "><p>Callback&lt;MediaQueryResult&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.79%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.1%" headers="mcps1.1.5.1.4 "><p>向媒体查询注册的回调</p>
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

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="10.9%" id="mcps1.1.5.1.1"><p>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.17%" id="mcps1.1.5.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.15%" id="mcps1.1.5.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="47.78%" id="mcps1.1.5.1.4"><p>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="10.9%" headers="mcps1.1.5.1.1 "><p>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.17%" headers="mcps1.1.5.1.2 "><p>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.15%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="47.78%" headers="mcps1.1.5.1.4 "><p>必须填写字符串'change'。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="10.9%" headers="mcps1.1.5.1.1 "><p>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.17%" headers="mcps1.1.5.1.2 "><p>Callback&lt;MediaQueryResult&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.15%" headers="mcps1.1.5.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="47.78%" headers="mcps1.1.5.1.4 "><p>需要去注册的回调，如果参数缺省则去注册该句柄下所有的回调。</p>
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

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="11.360000000000001%" id="mcps1.1.6.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="14.62%" id="mcps1.1.6.1.2"><p>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.73%" id="mcps1.1.6.1.3"><p>可读</p>
</th>
<th class="cellrowborder" valign="top" width="9.04%" id="mcps1.1.6.1.4"><p>可写</p>
</th>
<th class="cellrowborder" valign="top" width="55.25%" id="mcps1.1.6.1.5"><p>说明</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="11.360000000000001%" headers="mcps1.1.6.1.1 "><p>matches</p>
</td>
<td class="cellrowborder" valign="top" width="14.62%" headers="mcps1.1.6.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="9.73%" headers="mcps1.1.6.1.3 "><p>是</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="55.25%" headers="mcps1.1.6.1.5 "><p>是否符合匹配条件。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="11.360000000000001%" headers="mcps1.1.6.1.1 "><p>media</p>
</td>
<td class="cellrowborder" valign="top" width="14.62%" headers="mcps1.1.6.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.73%" headers="mcps1.1.6.1.3 "><p>是</p>
</td>
<td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.1.6.1.4 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" width="55.25%" headers="mcps1.1.6.1.5 "><p>媒体事件的匹配条件。</p>
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

