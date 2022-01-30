# Swiper<a name="EN-US_TOPIC_0000001237555087"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

The  **<Swiper\>**  component provides a container that allows users to switch among child components by swiping operations.

## Required Permissions<a name="section988262631714"></a>

None

## Child Components<a name="section5989144051714"></a>

This component can contain child components.

## APIs<a name="section97451749121712"></a>

Swiper\(value:\{controller?: SwiperController\}\)

-   Parameters

    <a name="table4435141419293"></a>
    <table><thead align="left"><tr id="row11435161419299"><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p id="p4436181415299"><a name="p4436181415299"></a><a name="p4436181415299"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="21.18%" id="mcps1.1.6.1.2"><p id="p7436714142919"><a name="p7436714142919"></a><a name="p7436714142919"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.64%" id="mcps1.1.6.1.3"><p id="p114361814162918"><a name="p114361814162918"></a><a name="p114361814162918"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.850000000000001%" id="mcps1.1.6.1.4"><p id="p3436214132910"><a name="p3436214132910"></a><a name="p3436214132910"></a>Default Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="36.22%" id="mcps1.1.6.1.5"><p id="p9436191410294"><a name="p9436191410294"></a><a name="p9436191410294"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row174369146296"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p443661416299"><a name="p443661416299"></a><a name="p443661416299"></a>controller</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.18%" headers="mcps1.1.6.1.2 "><p id="p15436014132918"><a name="p15436014132918"></a><a name="p15436014132918"></a><a href="#section1690616710381">SwiperController</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="12.64%" headers="mcps1.1.6.1.3 "><p id="p5436314202914"><a name="p5436314202914"></a><a name="p5436314202914"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.1.6.1.4 "><p id="p543613144290"><a name="p543613144290"></a><a name="p543613144290"></a>null</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.22%" headers="mcps1.1.6.1.5 "><p id="p1843614141293"><a name="p1843614141293"></a><a name="p1843614141293"></a>Controller bound to the component to control the page switching.</p>
    </td>
    </tr>
    </tbody>
    </table>


## Attributes<a name="section1738516911810"></a>

<a name="table1854mcpsimp"></a>
<table><thead align="left"><tr id="row1861mcpsimp"><th class="cellrowborder" valign="top" width="17.8%" id="mcps1.1.5.1.1"><p id="p1863mcpsimp"><a name="p1863mcpsimp"></a><a name="p1863mcpsimp"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="21.42%" id="mcps1.1.5.1.2"><p id="p1865mcpsimp"><a name="p1865mcpsimp"></a><a name="p1865mcpsimp"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="9.879999999999999%" id="mcps1.1.5.1.3"><p id="p1867mcpsimp"><a name="p1867mcpsimp"></a><a name="p1867mcpsimp"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="50.9%" id="mcps1.1.5.1.4"><p id="p1869mcpsimp"><a name="p1869mcpsimp"></a><a name="p1869mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1870mcpsimp"><td class="cellrowborder" valign="top" width="17.8%" headers="mcps1.1.5.1.1 "><p id="p1872mcpsimp"><a name="p1872mcpsimp"></a><a name="p1872mcpsimp"></a>index</p>
</td>
<td class="cellrowborder" valign="top" width="21.42%" headers="mcps1.1.5.1.2 "><p id="p1874mcpsimp"><a name="p1874mcpsimp"></a><a name="p1874mcpsimp"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.879999999999999%" headers="mcps1.1.5.1.3 "><p id="p1876mcpsimp"><a name="p1876mcpsimp"></a><a name="p1876mcpsimp"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="50.9%" headers="mcps1.1.5.1.4 "><p id="p1878mcpsimp"><a name="p1878mcpsimp"></a><a name="p1878mcpsimp"></a>Index of the child component currently displayed in the container.</p>
</td>
</tr>
<tr id="row1879mcpsimp"><td class="cellrowborder" valign="top" width="17.8%" headers="mcps1.1.5.1.1 "><p id="p1881mcpsimp"><a name="p1881mcpsimp"></a><a name="p1881mcpsimp"></a>autoPlay</p>
</td>
<td class="cellrowborder" valign="top" width="21.42%" headers="mcps1.1.5.1.2 "><p id="p1883mcpsimp"><a name="p1883mcpsimp"></a><a name="p1883mcpsimp"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="9.879999999999999%" headers="mcps1.1.5.1.3 "><p id="p1885mcpsimp"><a name="p1885mcpsimp"></a><a name="p1885mcpsimp"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="50.9%" headers="mcps1.1.5.1.4 "><p id="p1887mcpsimp"><a name="p1887mcpsimp"></a><a name="p1887mcpsimp"></a>Whether to enable automatic playback for child component switching. If this attribute is <strong id="b6689142301013"><a name="b6689142301013"></a><a name="b6689142301013"></a>true</strong>, the indicator dots do not take effect.</p>
</td>
</tr>
<tr id="row1888mcpsimp"><td class="cellrowborder" valign="top" width="17.8%" headers="mcps1.1.5.1.1 "><p id="p1890mcpsimp"><a name="p1890mcpsimp"></a><a name="p1890mcpsimp"></a>interval</p>
</td>
<td class="cellrowborder" valign="top" width="21.42%" headers="mcps1.1.5.1.2 "><p id="p1892mcpsimp"><a name="p1892mcpsimp"></a><a name="p1892mcpsimp"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.879999999999999%" headers="mcps1.1.5.1.3 "><p id="p1894mcpsimp"><a name="p1894mcpsimp"></a><a name="p1894mcpsimp"></a>3000</p>
</td>
<td class="cellrowborder" valign="top" width="50.9%" headers="mcps1.1.5.1.4 "><p id="p1896mcpsimp"><a name="p1896mcpsimp"></a><a name="p1896mcpsimp"></a>Interval for automatic playback, in ms.</p>
</td>
</tr>
<tr id="row1897mcpsimp"><td class="cellrowborder" valign="top" width="17.8%" headers="mcps1.1.5.1.1 "><p id="p1899mcpsimp"><a name="p1899mcpsimp"></a><a name="p1899mcpsimp"></a>indicator</p>
</td>
<td class="cellrowborder" valign="top" width="21.42%" headers="mcps1.1.5.1.2 "><p id="p1901mcpsimp"><a name="p1901mcpsimp"></a><a name="p1901mcpsimp"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="9.879999999999999%" headers="mcps1.1.5.1.3 "><p id="p1903mcpsimp"><a name="p1903mcpsimp"></a><a name="p1903mcpsimp"></a>true</p>
</td>
<td class="cellrowborder" valign="top" width="50.9%" headers="mcps1.1.5.1.4 "><p id="p1905mcpsimp"><a name="p1905mcpsimp"></a><a name="p1905mcpsimp"></a>Whether to enable the navigation dots.</p>
</td>
</tr>
<tr id="row1906mcpsimp"><td class="cellrowborder" valign="top" width="17.8%" headers="mcps1.1.5.1.1 "><p id="p1908mcpsimp"><a name="p1908mcpsimp"></a><a name="p1908mcpsimp"></a>loop</p>
</td>
<td class="cellrowborder" valign="top" width="21.42%" headers="mcps1.1.5.1.2 "><p id="p1910mcpsimp"><a name="p1910mcpsimp"></a><a name="p1910mcpsimp"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="9.879999999999999%" headers="mcps1.1.5.1.3 "><p id="p1912mcpsimp"><a name="p1912mcpsimp"></a><a name="p1912mcpsimp"></a>true</p>
</td>
<td class="cellrowborder" valign="top" width="50.9%" headers="mcps1.1.5.1.4 "><p id="p1914mcpsimp"><a name="p1914mcpsimp"></a><a name="p1914mcpsimp"></a>Whether to enable loop playback.</p>
</td>
</tr>
<tr id="row1915mcpsimp"><td class="cellrowborder" valign="top" width="17.8%" headers="mcps1.1.5.1.1 "><p id="p1917mcpsimp"><a name="p1917mcpsimp"></a><a name="p1917mcpsimp"></a>duration</p>
</td>
<td class="cellrowborder" valign="top" width="21.42%" headers="mcps1.1.5.1.2 "><p id="p1919mcpsimp"><a name="p1919mcpsimp"></a><a name="p1919mcpsimp"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.879999999999999%" headers="mcps1.1.5.1.3 "><p id="p1921mcpsimp"><a name="p1921mcpsimp"></a><a name="p1921mcpsimp"></a>400</p>
</td>
<td class="cellrowborder" valign="top" width="50.9%" headers="mcps1.1.5.1.4 "><p id="p1923mcpsimp"><a name="p1923mcpsimp"></a><a name="p1923mcpsimp"></a>Duration of the animation for switching child components, in ms.</p>
</td>
</tr>
<tr id="row1924mcpsimp"><td class="cellrowborder" valign="top" width="17.8%" headers="mcps1.1.5.1.1 "><p id="p1926mcpsimp"><a name="p1926mcpsimp"></a><a name="p1926mcpsimp"></a>vertical</p>
</td>
<td class="cellrowborder" valign="top" width="21.42%" headers="mcps1.1.5.1.2 "><p id="p1928mcpsimp"><a name="p1928mcpsimp"></a><a name="p1928mcpsimp"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="9.879999999999999%" headers="mcps1.1.5.1.3 "><p id="p1930mcpsimp"><a name="p1930mcpsimp"></a><a name="p1930mcpsimp"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="50.9%" headers="mcps1.1.5.1.4 "><p id="p1932mcpsimp"><a name="p1932mcpsimp"></a><a name="p1932mcpsimp"></a>Whether vertical swiping is used.</p>
</td>
</tr>
<tr id="row14115155203919"><td class="cellrowborder" valign="top" width="17.8%" headers="mcps1.1.5.1.1 "><p id="p201151554390"><a name="p201151554390"></a><a name="p201151554390"></a>itemSpace</p>
</td>
<td class="cellrowborder" valign="top" width="21.42%" headers="mcps1.1.5.1.2 "><p id="p496921564018"><a name="p496921564018"></a><a name="p496921564018"></a>Length</p>
</td>
<td class="cellrowborder" valign="top" width="9.879999999999999%" headers="mcps1.1.5.1.3 "><p id="p51152057396"><a name="p51152057396"></a><a name="p51152057396"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="50.9%" headers="mcps1.1.5.1.4 "><p id="p311565183912"><a name="p311565183912"></a><a name="p311565183912"></a>Space between child components.</p>
</td>
</tr>
<tr id="row11729145111242"><td class="cellrowborder" valign="top" width="17.8%" headers="mcps1.1.5.1.1 "><p id="p3385105013241"><a name="p3385105013241"></a><a name="p3385105013241"></a>cachedCount<sup id="sup133053694910"><a name="sup133053694910"></a><a name="sup133053694910"></a>8+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="21.42%" headers="mcps1.1.5.1.2 "><p id="p8385550182413"><a name="p8385550182413"></a><a name="p8385550182413"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.879999999999999%" headers="mcps1.1.5.1.3 "><p id="p193851950152410"><a name="p193851950152410"></a><a name="p193851950152410"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="50.9%" headers="mcps1.1.5.1.4 "><p id="p438514506244"><a name="p438514506244"></a><a name="p438514506244"></a>Number of child components to be cached.</p>
</td>
</tr>
<tr id="row1672211307014"><td class="cellrowborder" valign="top" width="17.8%" headers="mcps1.1.5.1.1 "><p id="p1872373020010"><a name="p1872373020010"></a><a name="p1872373020010"></a>disableSwipe<sup id="sup25031942182615"><a name="sup25031942182615"></a><a name="sup25031942182615"></a>8+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="21.42%" headers="mcps1.1.5.1.2 "><p id="p472317301805"><a name="p472317301805"></a><a name="p472317301805"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="9.879999999999999%" headers="mcps1.1.5.1.3 "><p id="p57248301909"><a name="p57248301909"></a><a name="p57248301909"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="50.9%" headers="mcps1.1.5.1.4 "><p id="p2724173010017"><a name="p2724173010017"></a><a name="p2724173010017"></a>Whether to disable the swipe feature.</p>
</td>
</tr>
</tbody>
</table>

### SwiperController<a name="section1690616710381"></a>

Controller of the  **<Swiper\>**  component. You can bind this object to the  **<Swiper\>**  component and use it to control page switching.

<a name="table1891034201817"></a>
<table><thead align="left"><tr id="row158903416183"><th class="cellrowborder" valign="top" width="26.99%" id="mcps1.1.3.1.1"><p id="p178953411181"><a name="p178953411181"></a><a name="p178953411181"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="73.00999999999999%" id="mcps1.1.3.1.2"><p id="p989133421817"><a name="p989133421817"></a><a name="p989133421817"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row790163451817"><td class="cellrowborder" valign="top" width="26.99%" headers="mcps1.1.3.1.1 "><p id="p190173416184"><a name="p190173416184"></a><a name="p190173416184"></a>showNext():void;</p>
</td>
<td class="cellrowborder" valign="top" width="73.00999999999999%" headers="mcps1.1.3.1.2 "><p id="p10660111011194"><a name="p10660111011194"></a><a name="p10660111011194"></a>Turns to the next page.</p>
</td>
</tr>
<tr id="row1894121571918"><td class="cellrowborder" valign="top" width="26.99%" headers="mcps1.1.3.1.1 "><p id="p16941121517191"><a name="p16941121517191"></a><a name="p16941121517191"></a>showPrevious():void;</p>
</td>
<td class="cellrowborder" valign="top" width="73.00999999999999%" headers="mcps1.1.3.1.2 "><p id="p29423156194"><a name="p29423156194"></a><a name="p29423156194"></a>Turns to the previous page.</p>
</td>
</tr>
</tbody>
</table>

## Events<a name="section6741113101919"></a>

<a name="table1934mcpsimp"></a>
<table><thead align="left"><tr id="row1940mcpsimp"><th class="cellrowborder" colspan="2" valign="top" id="mcps1.1.4.1.1"><p id="p276mcpsimp"><a name="p276mcpsimp"></a><a name="p276mcpsimp"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.4.1.2"><p id="p1946mcpsimp"><a name="p1946mcpsimp"></a><a name="p1946mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1947mcpsimp"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p id="p1949mcpsimp"><a name="p1949mcpsimp"></a><a name="p1949mcpsimp"></a>onChange( index: number) =&gt; void</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p1953mcpsimp"><a name="p1953mcpsimp"></a><a name="p1953mcpsimp"></a>Triggered when the index of the currently displayed component changes.</p>
</td>
</tr>
</tbody>
</table>

## Example<a name="section1131255321814"></a>

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
      .indicator(true) // Navigation dots are enabled by default.
      .loop(false) // Loop playback is enabled by default.
      .duration(1000)
      .vertical(false) // Horizontal swiping is enabled by default.
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

