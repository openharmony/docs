# 应用程序的数据存储<a name="ZH-CN_TOPIC_0000001119929480"></a>

**AppStorage**是应用程序中的单例对象，由UI框架在应用程序启动时创建，在应用程序退出退出时销毁，为应用程序范围内的可变状态属性提供中央存储。**AppStorage**包含整个应用程序中需要访问的所有状态属性，只要应用程序保持运行，**AppStorage**就会保存所有属性及属性值，属性值可以通过唯一的键值进行访问。

UI组件可以通过装饰器将应用程序状态数据与**AppStorage**进行同步，应用业务逻辑的实现也可以通过接口访问**AppStorage**。

**AppStorage**的选择状态属性可以与不同的数据源或数据接收器同步，这些数据源和接收器可以是设备上的本地或远程，并具有不同的功能，如数据持久性。这样的数据源和接收器可以独立于UI在业务逻辑中实现。

默认情况下，**AppStorage**中的属性是可变的，**AppStorage**还可使用不可变（只读）属性。

## AppStorage接口<a name="zh-cn_topic_0000001103218748_section89909382526"></a>

<a name="zh-cn_topic_0000001103218748_table109mcpsimp"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001103218748_row115mcpsimp"><th class="cellrowborder" valign="top" width="11.700000000000001%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001103218748_p117mcpsimp"><a name="zh-cn_topic_0000001103218748_p117mcpsimp"></a><a name="zh-cn_topic_0000001103218748_p117mcpsimp"></a>方法</p>
</th>
<th class="cellrowborder" valign="top" width="16.07%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001103218748_p119mcpsimp"><a name="zh-cn_topic_0000001103218748_p119mcpsimp"></a><a name="zh-cn_topic_0000001103218748_p119mcpsimp"></a>参数说明</p>
</th>
<th class="cellrowborder" valign="top" width="10.27%" id="mcps1.1.5.1.3"><p id="p1566112607"><a name="p1566112607"></a><a name="p1566112607"></a>返回值</p>
</th>
<th class="cellrowborder" valign="top" width="61.96%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001103218748_p121mcpsimp"><a name="zh-cn_topic_0000001103218748_p121mcpsimp"></a><a name="zh-cn_topic_0000001103218748_p121mcpsimp"></a>定义</p>
</th>
</tr>
</thead>
<tbody><tr id="row1268014533319"><td class="cellrowborder" valign="top" width="11.700000000000001%" headers="mcps1.1.5.1.1 "><p id="p1732451520330"><a name="p1732451520330"></a><a name="p1732451520330"></a>SetAndLink</p>
</td>
<td class="cellrowborder" valign="top" width="16.07%" headers="mcps1.1.5.1.2 "><p id="p5324131563315"><a name="p5324131563315"></a><a name="p5324131563315"></a>key: string,</p>
<p id="p0324161593317"><a name="p0324161593317"></a><a name="p0324161593317"></a>defaultValue: T</p>
</td>
<td class="cellrowborder" valign="top" width="10.27%" headers="mcps1.1.5.1.3 "><p id="p13324121563314"><a name="p13324121563314"></a><a name="p13324121563314"></a>@Link</p>
</td>
<td class="cellrowborder" valign="top" width="61.96%" headers="mcps1.1.5.1.4 "><p id="p332441593313"><a name="p332441593313"></a><a name="p332441593313"></a>与Link接口类似，如果当前的key保存于AppStorage，则返回该key对应的value。如果该key未被创建，则创建一个对应default值的Link返回。</p>
</td>
</tr>
<tr id="row11933202133313"><td class="cellrowborder" valign="top" width="11.700000000000001%" headers="mcps1.1.5.1.1 "><p id="p13525925193310"><a name="p13525925193310"></a><a name="p13525925193310"></a>Set</p>
</td>
<td class="cellrowborder" valign="top" width="16.07%" headers="mcps1.1.5.1.2 "><p id="p12525182583310"><a name="p12525182583310"></a><a name="p12525182583310"></a>key: string,</p>
<p id="p352582510337"><a name="p352582510337"></a><a name="p352582510337"></a>newValue: T</p>
</td>
<td class="cellrowborder" valign="top" width="10.27%" headers="mcps1.1.5.1.3 "><p id="p20525172573312"><a name="p20525172573312"></a><a name="p20525172573312"></a>void</p>
</td>
<td class="cellrowborder" valign="top" width="61.96%" headers="mcps1.1.5.1.4 "><p id="p16525325163318"><a name="p16525325163318"></a><a name="p16525325163318"></a>对已保存的key值，替换其value值。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103218748_row122mcpsimp"><td class="cellrowborder" valign="top" width="11.700000000000001%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001103218748_p124mcpsimp"><a name="zh-cn_topic_0000001103218748_p124mcpsimp"></a><a name="zh-cn_topic_0000001103218748_p124mcpsimp"></a>Link</p>
</td>
<td class="cellrowborder" valign="top" width="16.07%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001103218748_p126mcpsimp"><a name="zh-cn_topic_0000001103218748_p126mcpsimp"></a><a name="zh-cn_topic_0000001103218748_p126mcpsimp"></a>key: string</p>
</td>
<td class="cellrowborder" valign="top" width="10.27%" headers="mcps1.1.5.1.3 "><p id="p185664215018"><a name="p185664215018"></a><a name="p185664215018"></a>@Link</p>
</td>
<td class="cellrowborder" valign="top" width="61.96%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001103218748_p128mcpsimp"><a name="zh-cn_topic_0000001103218748_p128mcpsimp"></a><a name="zh-cn_topic_0000001103218748_p128mcpsimp"></a>如果存在具有给定键的数据，则返回到此属性的双向数据绑定，该双向绑定意味着变量或者组件对数据的更改将同步到<strong id="zh-cn_topic_0000001103218748_b086010478369"><a name="zh-cn_topic_0000001103218748_b086010478369"></a><a name="zh-cn_topic_0000001103218748_b086010478369"></a>AppStorage</strong>，通过<strong id="zh-cn_topic_0000001103218748_b748595013369"><a name="zh-cn_topic_0000001103218748_b748595013369"></a><a name="zh-cn_topic_0000001103218748_b748595013369"></a>AppStorage</strong>对数据的修改将同步到变量或者组件。如果具有此键的属性不存在或属性为只读，则返回<strong id="zh-cn_topic_0000001103218748_b3740185374119"><a name="zh-cn_topic_0000001103218748_b3740185374119"></a><a name="zh-cn_topic_0000001103218748_b3740185374119"></a>undefined</strong>。</p>
</td>
</tr>
<tr id="row4366154210336"><td class="cellrowborder" valign="top" width="11.700000000000001%" headers="mcps1.1.5.1.1 "><p id="p13901134873311"><a name="p13901134873311"></a><a name="p13901134873311"></a>SetAndProp</p>
</td>
<td class="cellrowborder" valign="top" width="16.07%" headers="mcps1.1.5.1.2 "><p id="p19901948193317"><a name="p19901948193317"></a><a name="p19901948193317"></a>propName: string,</p>
<p id="p39011548143315"><a name="p39011548143315"></a><a name="p39011548143315"></a>defaultValue: S</p>
</td>
<td class="cellrowborder" valign="top" width="10.27%" headers="mcps1.1.5.1.3 "><p id="p4901164853315"><a name="p4901164853315"></a><a name="p4901164853315"></a>@Prop</p>
</td>
<td class="cellrowborder" valign="top" width="61.96%" headers="mcps1.1.5.1.4 "><p id="p109011848163311"><a name="p109011848163311"></a><a name="p109011848163311"></a>与Prop接口类似，如果当前的key保存于AppStorage，则返回该key对应的value。如果该key未被创建，则创建一个对应default值的Prop返回。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103218748_row129mcpsimp"><td class="cellrowborder" valign="top" width="11.700000000000001%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001103218748_p131mcpsimp"><a name="zh-cn_topic_0000001103218748_p131mcpsimp"></a><a name="zh-cn_topic_0000001103218748_p131mcpsimp"></a>Prop</p>
</td>
<td class="cellrowborder" valign="top" width="16.07%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001103218748_p133mcpsimp"><a name="zh-cn_topic_0000001103218748_p133mcpsimp"></a><a name="zh-cn_topic_0000001103218748_p133mcpsimp"></a>key: string</p>
</td>
<td class="cellrowborder" valign="top" width="10.27%" headers="mcps1.1.5.1.3 "><p id="p55660211014"><a name="p55660211014"></a><a name="p55660211014"></a>@Prop</p>
</td>
<td class="cellrowborder" valign="top" width="61.96%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001103218748_p135mcpsimp"><a name="zh-cn_topic_0000001103218748_p135mcpsimp"></a><a name="zh-cn_topic_0000001103218748_p135mcpsimp"></a>如果存在具有给定键的属性，则返回此属性的单向数据绑定。该单向绑定意味着只能通过<strong id="zh-cn_topic_0000001103218748_b1388608184310"><a name="zh-cn_topic_0000001103218748_b1388608184310"></a><a name="zh-cn_topic_0000001103218748_b1388608184310"></a>AppStorage</strong>将属性的更改同步到变量或者组件。该方法返回的变量为不可变变量，适用于可变和不可变的状态属性，如果具有此键的属性不存在则返回<strong id="zh-cn_topic_0000001103218748_b14239023171713"><a name="zh-cn_topic_0000001103218748_b14239023171713"></a><a name="zh-cn_topic_0000001103218748_b14239023171713"></a>undefined</strong>。</p>
<div class="note" id="zh-cn_topic_0000001103218748_note1886831124618"><a name="zh-cn_topic_0000001103218748_note1886831124618"></a><a name="zh-cn_topic_0000001103218748_note1886831124618"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="p522015411452"><a name="p522015411452"></a><a name="p522015411452"></a>prop方法对应的属性值类型为简单类型。</p>
</div></div>
</td>
</tr>
<tr id="row37352099352"><td class="cellrowborder" valign="top" width="11.700000000000001%" headers="mcps1.1.5.1.1 "><p id="p4365612133519"><a name="p4365612133519"></a><a name="p4365612133519"></a>SetOrCreate</p>
</td>
<td class="cellrowborder" valign="top" width="16.07%" headers="mcps1.1.5.1.2 "><p id="p436571213357"><a name="p436571213357"></a><a name="p436571213357"></a>key: string,</p>
<p id="p8365151214356"><a name="p8365151214356"></a><a name="p8365151214356"></a>newValue: T</p>
</td>
<td class="cellrowborder" valign="top" width="10.27%" headers="mcps1.1.5.1.3 "><p id="p1336510126357"><a name="p1336510126357"></a><a name="p1336510126357"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="61.96%" headers="mcps1.1.5.1.4 "><p id="p936561273517"><a name="p936561273517"></a><a name="p936561273517"></a>如果相同名字的属性存在：如果此属性可以被更改返回true，否则返回false。</p>
<p id="p11365181233517"><a name="p11365181233517"></a><a name="p11365181233517"></a>如果相同名字的属性不存在：创建第一个赋值为defaultValue的属性，不支持null和undefined。</p>
</td>
</tr>
<tr id="row133617381341"><td class="cellrowborder" valign="top" width="11.700000000000001%" headers="mcps1.1.5.1.1 "><p id="p974634743418"><a name="p974634743418"></a><a name="p974634743418"></a>Get</p>
</td>
<td class="cellrowborder" valign="top" width="16.07%" headers="mcps1.1.5.1.2 "><p id="p177461247193415"><a name="p177461247193415"></a><a name="p177461247193415"></a>key: string</p>
</td>
<td class="cellrowborder" valign="top" width="10.27%" headers="mcps1.1.5.1.3 "><p id="p6746547103411"><a name="p6746547103411"></a><a name="p6746547103411"></a>T或undefined</p>
</td>
<td class="cellrowborder" valign="top" width="61.96%" headers="mcps1.1.5.1.4 "><p id="p18746447203410"><a name="p18746447203410"></a><a name="p18746447203410"></a>通过此接口获取对应key值的value。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103218748_row136mcpsimp"><td class="cellrowborder" valign="top" width="11.700000000000001%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001103218748_p138mcpsimp"><a name="zh-cn_topic_0000001103218748_p138mcpsimp"></a><a name="zh-cn_topic_0000001103218748_p138mcpsimp"></a>Has</p>
</td>
<td class="cellrowborder" valign="top" width="16.07%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001103218748_p140mcpsimp"><a name="zh-cn_topic_0000001103218748_p140mcpsimp"></a><a name="zh-cn_topic_0000001103218748_p140mcpsimp"></a>propName: string</p>
</td>
<td class="cellrowborder" valign="top" width="10.27%" headers="mcps1.1.5.1.3 "><p id="p125661627019"><a name="p125661627019"></a><a name="p125661627019"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="61.96%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001103218748_p142mcpsimp"><a name="zh-cn_topic_0000001103218748_p142mcpsimp"></a><a name="zh-cn_topic_0000001103218748_p142mcpsimp"></a><span>判断对应键值的属性是否存在</span>。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001103218748_row150mcpsimp"><td class="cellrowborder" valign="top" width="11.700000000000001%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001103218748_p1363415429353"><a name="zh-cn_topic_0000001103218748_p1363415429353"></a><a name="zh-cn_topic_0000001103218748_p1363415429353"></a>Keys</p>
</td>
<td class="cellrowborder" valign="top" width="16.07%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001103218748_p154mcpsimp"><a name="zh-cn_topic_0000001103218748_p154mcpsimp"></a><a name="zh-cn_topic_0000001103218748_p154mcpsimp"></a>void</p>
</td>
<td class="cellrowborder" valign="top" width="10.27%" headers="mcps1.1.5.1.3 "><p id="p19566522014"><a name="p19566522014"></a><a name="p19566522014"></a>array&lt;string&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="61.96%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001103218748_p156mcpsimp"><a name="zh-cn_topic_0000001103218748_p156mcpsimp"></a><a name="zh-cn_topic_0000001103218748_p156mcpsimp"></a>返回包含所有键的字符串数组。</p>
</td>
</tr>
<tr id="row350321491214"><td class="cellrowborder" valign="top" width="11.700000000000001%" headers="mcps1.1.5.1.1 "><p id="p17503121481216"><a name="p17503121481216"></a><a name="p17503121481216"></a>Delete</p>
</td>
<td class="cellrowborder" valign="top" width="16.07%" headers="mcps1.1.5.1.2 "><p id="p6503161417122"><a name="p6503161417122"></a><a name="p6503161417122"></a>key: string</p>
</td>
<td class="cellrowborder" valign="top" width="10.27%" headers="mcps1.1.5.1.3 "><p id="p205031814191212"><a name="p205031814191212"></a><a name="p205031814191212"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="61.96%" headers="mcps1.1.5.1.4 "><p id="p05031014141211"><a name="p05031014141211"></a><a name="p05031014141211"></a>删除key指定的键值对，如果存在且删除成功返回true，不存在或删除失败返回false。</p>
</td>
</tr>
<tr id="row12261203911401"><td class="cellrowborder" valign="top" width="11.700000000000001%" headers="mcps1.1.5.1.1 "><p id="p202611739204016"><a name="p202611739204016"></a><a name="p202611739204016"></a>Clear</p>
</td>
<td class="cellrowborder" valign="top" width="16.07%" headers="mcps1.1.5.1.2 "><p id="p526118395407"><a name="p526118395407"></a><a name="p526118395407"></a>void</p>
</td>
<td class="cellrowborder" valign="top" width="10.27%" headers="mcps1.1.5.1.3 "><p id="p326173910400"><a name="p326173910400"></a><a name="p326173910400"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="61.96%" headers="mcps1.1.5.1.4 "><p id="p22611139114012"><a name="p22611139114012"></a><a name="p22611139114012"></a>删除所有的属性，如果当前有状态变量依旧引用此属性，则返回false。</p>
</td>
</tr>
<tr id="row14209473411"><td class="cellrowborder" valign="top" width="11.700000000000001%" headers="mcps1.1.5.1.1 "><p id="p12420347194115"><a name="p12420347194115"></a><a name="p12420347194115"></a>IsMutable</p>
</td>
<td class="cellrowborder" valign="top" width="16.07%" headers="mcps1.1.5.1.2 "><p id="p10420174754114"><a name="p10420174754114"></a><a name="p10420174754114"></a>key: string</p>
</td>
<td class="cellrowborder" valign="top" width="10.27%" headers="mcps1.1.5.1.3 "><p id="p15420204714119"><a name="p15420204714119"></a><a name="p15420204714119"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="61.96%" headers="mcps1.1.5.1.4 "><p id="p1942074711417"><a name="p1942074711417"></a><a name="p1942074711417"></a>返回此属性是否存在并且是否可以改变。</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>当前接口当前仅可以处理基础类型数据，对于修改object中某一个值尚未支持。

## AppStorage与组件同步<a name="section1315514223716"></a>

在[管理组件拥有的状态](ts-component-states-state.md)中，已经定义了如何将组件的状态变量与父组件或祖先组件中的**@State**装饰的状态变量同步，主要包括**@Prop**、**@Link**、**@Consume**。

本章节将定义如何将组件变量与**AppStorage**同步，主要提供**@StorageLink**和**@StorageProp**装饰器。

### @StorageLink装饰器<a name="section959881683812"></a>

组件通过使用**@StorageLink\(key\)**装饰的状态变量，与**AppStorage**建立双向数据绑定，**key**为**AppStorage**中的属性键值。当创建包含**@StorageLink**的状态变量的组件时，该状态变量的值将使用**AppStorage**中的值进行初始化。在UI组件中对**@StorageLink**的状态变量所做的更改将同步到**AppStorage**，并从**AppStorage**同步到任何其他绑定实例中，如**PersistentStorage**或其他绑定的UI组件。

### @StorageProp装饰器<a name="section9866110193918"></a>

组件通过使用**@StorageProp\(key\)**装饰的状态变量，将与**AppStorage**建立单向数据绑定，**key**标识AppStorage中的属性键值。当创建包含**@StoageProp**的状态变量的组件时，该状态变量的值将使用**AppStorage**中的值进行初始化。**AppStorage**中的属性值的更改会导致绑定的UI组件进行状态更新。

## 示例<a name="zh-cn_topic_0000001103218748_section195112274815"></a>

```
let varA = AppStorage.Link('varA')
let envLang = AppStorage.Prop('languageCode')

@Entry
@Component
struct ComponentA {
  @StorageLink('varA') varA: number = 2
  @StorageProp('languageCode') lang: string = 'en'
  private label: string = 'count'

  private aboutToAppear() {
    this.label = (this.lang === 'zh') ? '数' : 'Count'
  }

  build() {
    Row({ space: 20 }) {

      Button(`${this.label}: ${this.varA}`)
        .onClick(() => {
          AppStorage.Set<number>('varA', AppStorage.Get<number>('varA') + 1)
        })
      Button(`lang: ${this.lang}`)
        .onClick(() => {
          if (this.lang === 'zh') {
            AppStorage.Set<string>('languageCode', 'en')
          } else {
            AppStorage.Set<string>('languageCode', 'zh')
          }
          this.label = (this.lang === 'zh') ? '数' : 'Count'
        })
    }
  }
}
```

每次开发者单击Count按钮时，this.varA变量值都会增加，此变量与AppStorage中的varA同步。每次用户单击当前语言按钮时，修改AppStorage中的languageCode，此修改会同步给this.lang变量。

