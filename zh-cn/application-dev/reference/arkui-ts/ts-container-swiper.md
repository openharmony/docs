# Swiper<a name="ZH-CN_TOPIC_0000001237555087"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

滑动容器，提供切换子组件显示的能力。

## 权限列表<a name="section988262631714"></a>

无

## 子组件<a name="section5989144051714"></a>

可以包含子组件。

## 接口<a name="section97451749121712"></a>

Swiper\(value:\{controller?: SwiperController\}\)

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="21.18%" id="mcps1.1.6.1.2"><p>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.64%" id="mcps1.1.6.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.850000000000001%" id="mcps1.1.6.1.4"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="36.22%" id="mcps1.1.6.1.5"><p>参数描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p>controller</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.18%" headers="mcps1.1.6.1.2 "><p><a href="#section1690616710381">SwiperController</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="12.64%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.1.6.1.4 "><p>null</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.22%" headers="mcps1.1.6.1.5 "><p>给组件绑定一个控制器，用来控制组件翻页。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 属性<a name="section1738516911810"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="17.8%" id="mcps1.1.5.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="21.42%" id="mcps1.1.5.1.2"><p>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.879999999999999%" id="mcps1.1.5.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="50.9%" id="mcps1.1.5.1.4"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="17.8%" headers="mcps1.1.5.1.1 "><p>index</p>
</td>
<td class="cellrowborder" valign="top" width="21.42%" headers="mcps1.1.5.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.879999999999999%" headers="mcps1.1.5.1.3 "><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="50.9%" headers="mcps1.1.5.1.4 "><p>设置当前在容器中显示的子组件的索引值。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="17.8%" headers="mcps1.1.5.1.1 "><p>autoPlay</p>
</td>
<td class="cellrowborder" valign="top" width="21.42%" headers="mcps1.1.5.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="9.879999999999999%" headers="mcps1.1.5.1.3 "><p>false</p>
</td>
<td class="cellrowborder" valign="top" width="50.9%" headers="mcps1.1.5.1.4 "><p>子组件是否自动播放，自动播放状态下，导航点不可操作。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="17.8%" headers="mcps1.1.5.1.1 "><p>interval</p>
</td>
<td class="cellrowborder" valign="top" width="21.42%" headers="mcps1.1.5.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.879999999999999%" headers="mcps1.1.5.1.3 "><p>3000</p>
</td>
<td class="cellrowborder" valign="top" width="50.9%" headers="mcps1.1.5.1.4 "><p>使用自动播放时播放的时间间隔，单位为毫秒。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="17.8%" headers="mcps1.1.5.1.1 "><p>indicator</p>
</td>
<td class="cellrowborder" valign="top" width="21.42%" headers="mcps1.1.5.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="9.879999999999999%" headers="mcps1.1.5.1.3 "><p>true</p>
</td>
<td class="cellrowborder" valign="top" width="50.9%" headers="mcps1.1.5.1.4 "><p>是否启用导航点指示器。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="17.8%" headers="mcps1.1.5.1.1 "><p>loop</p>
</td>
<td class="cellrowborder" valign="top" width="21.42%" headers="mcps1.1.5.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="9.879999999999999%" headers="mcps1.1.5.1.3 "><p>true</p>
</td>
<td class="cellrowborder" valign="top" width="50.9%" headers="mcps1.1.5.1.4 "><p>是否开启循环。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="17.8%" headers="mcps1.1.5.1.1 "><p>duration</p>
</td>
<td class="cellrowborder" valign="top" width="21.42%" headers="mcps1.1.5.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.879999999999999%" headers="mcps1.1.5.1.3 "><p>400</p>
</td>
<td class="cellrowborder" valign="top" width="50.9%" headers="mcps1.1.5.1.4 "><p>子组件切换的动画时长，单位为毫秒。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="17.8%" headers="mcps1.1.5.1.1 "><p>vertical</p>
</td>
<td class="cellrowborder" valign="top" width="21.42%" headers="mcps1.1.5.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="9.879999999999999%" headers="mcps1.1.5.1.3 "><p>false</p>
</td>
<td class="cellrowborder" valign="top" width="50.9%" headers="mcps1.1.5.1.4 "><p>是否为纵向滑动。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="17.8%" headers="mcps1.1.5.1.1 "><p>itemSpace</p>
</td>
<td class="cellrowborder" valign="top" width="21.42%" headers="mcps1.1.5.1.2 "><p>Length</p>
</td>
<td class="cellrowborder" valign="top" width="9.879999999999999%" headers="mcps1.1.5.1.3 "><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="50.9%" headers="mcps1.1.5.1.4 "><p>设置子组件与子组件之间间隙。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="17.8%" headers="mcps1.1.5.1.1 "><p>cachedCount<sup><span>8+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="21.42%" headers="mcps1.1.5.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.879999999999999%" headers="mcps1.1.5.1.3 "><p>1</p>
</td>
<td class="cellrowborder" valign="top" width="50.9%" headers="mcps1.1.5.1.4 "><p>设置预加载子组件个数。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="17.8%" headers="mcps1.1.5.1.1 "><p>disableSwipe<sup><span>8+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="21.42%" headers="mcps1.1.5.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="9.879999999999999%" headers="mcps1.1.5.1.3 "><p>false</p>
</td>
<td class="cellrowborder" valign="top" width="50.9%" headers="mcps1.1.5.1.4 "><p>禁用组件滑动切换功能。</p>
</td>
</tr>
</tbody>
</table>

### SwiperController<a name="section1690616710381"></a>

Swiper容器组件的控制器，可以将此对象绑定至Swiper组件，然后通过它控制翻页。

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="26.99%" id="mcps1.1.3.1.1"><p>接口名称</p>
</th>
<th class="cellrowborder" valign="top" width="73.00999999999999%" id="mcps1.1.3.1.2"><p>功能描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="26.99%" headers="mcps1.1.3.1.1 "><p>showNext():void;</p>
</td>
<td class="cellrowborder" valign="top" width="73.00999999999999%" headers="mcps1.1.3.1.2 "><p>翻至下一页。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="26.99%" headers="mcps1.1.3.1.1 "><p>showPrevious():void;</p>
</td>
<td class="cellrowborder" valign="top" width="73.00999999999999%" headers="mcps1.1.3.1.2 "><p>翻至上一页。</p>
</td>
</tr>
</tbody>
</table>

## 事件<a name="section6741113101919"></a>

<table><thead align="left"><tr><th class="cellrowborder" colspan="2" valign="top" id="mcps1.1.4.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.4.1.2"><p>功能描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p>onChange( index: number) =&gt; void</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p>当前显示的组件索引变化时触发该事件。</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section1131255321814"></a>

```
class MyDataSource implements IDataSource {
  private list: number[] = []
  private listener: DataChangeListener

  constructor(list: number[]) {
    this.list = list
  }

  totalCount(): number {
    return this.list.length
  }

  getData(index: number): any {
    return this.list[index]
  }

  registerDataChangeListener(listener: DataChangeListener): void {
    this.listener = listener
  }

  unregisterDataChangeListener() {
  }
}

@Entry
@Component
struct SwiperExample {
  private swiperController: SwiperController = new SwiperController()
  private data: MyDataSource = new MyDataSource([])

  private aboutToAppear(): void {
    let list = []
    for (var i = 1; i <= 10; i++) {
      list.push(i.toString());
    }
    this.data = new MyDataSource(list)
  }

  build() {
    Column({ space: 5 }) {
      Swiper(this.swiperController) {
        LazyForEach(this.data, (item: string) => {
          Text(item).width('90%').height(160).backgroundColor(0xAFEEEE).textAlign(TextAlign.Center).fontSize(20)
        }, item => item)
      }
      .cachedCount(2)
      .index(1)
      .autoPlay(true)
      .interval(4000)
      .indicator(true) // 默认开启指示点
      .loop(false) // 默认开启循环播放
      .duration(1000)
      .vertical(false) // 默认横向切换
      .itemSpace(0)
      .onChange((index: number) => {
        console.info(index.toString())
      })

      Flex({ justifyContent: FlexAlign.SpaceAround }) {
        Button('next')
          .onClick(() => {
            this.swiperController.showNext()
          })
        Button('preview')
          .onClick(() => {
            this.swiperController.showPrevious()
          })
      }
    }.margin({ top: 5 })
  }
}
```

![](figures/swiper.gif)

