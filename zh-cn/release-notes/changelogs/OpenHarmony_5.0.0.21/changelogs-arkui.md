# ArkUI子系统Changelog

## cl.arkui.1 Toggle组件Switch样式移除宽高比1.8倍限制

**访问级别**

公开接口

**变更原因**

a)当前Toggle组件Switch样式宽高比固定1.8倍，依照UX规范移除1.8倍限制。

**变更影响**

该变更为非兼容性变更。API version 11及以前，Toggle组件Switch样式宽高比固定1.8倍。API version 12及以后，Toggle组件Switch样式宽高比没有限制。

**API Level**

12 

**变更发生版本**

从OpenHarmony SDK 5.0.0.21 版本开始。

**变更的接口/组件**

Toggle组件

**适配指导**

请查阅[Toggle组件](../../../application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-toggle.md)文档进行适配。

## cl.arkui.2  Radio组件单选项样式风格增强、支持显示自定义图标 

**访问级别**

公开接口

**变更原因**

允许用户自定义单选项的选中状态：

1.可以选择不同的样式，如圆饼样式，对勾样式，自定义图标样式。

2.用户自定义图标时，设置选中状态时图标显示，非选中状态时图标不显示。

**变更影响**

该变更为非兼容性变更。

- 变更前：默认选中状态DOT（圆圈样式）。
- 变更后：默认选中状态TICK（对勾样式）。

| DOT | TICK |
|---------|---------|
| ![](figures/radio_changelog_DOT.jpg) | ![](figures/radio_changelog_TICK.jpg) |

**API Level**

12

**变更发生版本**

从OpenHarmony SDK 5.0.0.21版本开始。

**示例：**
该示例实现了自定义选中状态
```
@Entry
@Component
struct RadioExample {
  @Builder 
  indicatorBuilder() {
    Image($r("app.media.star"))
  }
  build() {
    Flex({ direction: FlexDirection.Row, justifyContent: FlexAlign.Center, alignItems: ItemAlign.Center }) {
      Column() {
        Text('Radio1')
        Radio({ value: 'Radio1', group: 'radioGroup',
          indicatorType:RadioIndicatorType.TICK
        }).checked(true)
          .height(50)
          .width(80)
          .onChange((isChecked: boolean) => {
            console.log('Radio1 status is ' + isChecked)
          })
      }
      Column() {
        Text('Radio2')
        Radio({ value: 'Radio2', group: 'radioGroup',
          indicatorType:RadioIndicatorType.DOT
        }).checked(false)
          .height(50)
          .width(80)
          .onChange((isChecked: boolean) => {
            console.log('Radio2 status is ' + isChecked)
          })
      }
      Column() {
        Text('Radio3')
        Radio({ value: 'Radio3', group: 'radioGroup',
          indicatorType:RadioIndicatorType.CUSTOM,
          indicatorBuilder:()=>{this.indicatorBuilder()}
        }).checked(false)
          .height(50)
          .width(80)
          .onChange((isChecked: boolean) => {
            console.log('Radio3 status is ' + isChecked)
          })
      }
    }.padding({ top: 30 })
  }
}
```

**变更的接口/组件**

Radio组件

**适配指导**

请查阅[Radio组件](../../../application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-radio.md)文档进行适配。

## cl.arkui.3 文本组件的文本选择行为变更

**访问级别**

公开接口

**变更原因**

依照UX规范

**变更影响**

该变更为非兼容性变更。API version 11及以前：

a)当前Text组件长按出现菜单时，旋转屏幕，此时依旧出现菜单。

b)当前Text/TextInput/TextArea/Search/RichEditor组件长按出现菜单，进行复制行为，文本退出选中态。

c)当前TextInput/TextArea/Search/RichEditor组件在手机和平板设备上通过代码选区，只出现选中态，无手柄。

API version 12及以后：

a)当前Text组件长按出现菜单时，旋转屏幕，隐藏菜单，保持选中态。

b)当前TextInput/TextArea/Search/RichEditor组件长按出现菜单时，进行复制行为，隐藏菜单，保持选中态。

c)当前TextInput/TextArea/Search/RichEditor组件在手机和平板设备上通过代码选区，出现选中态和手柄，用户可自定义出现菜单。

| 变更前 | 变更后 |
|---------|---------|
| ![](figures/text_before.png) | ![](figures/text_after.png) |
| ![](figures/copy_before.png) | ![](figures/copy_after.png) |
| ![](figures/selection_before.png) | ![](figures/select_after.png) |

**API Level**

12 

**变更发生版本**

从OpenHarmony SDK 5.0.0.21 版本开始。

**变更的接口/组件**

Text/TextInput/TextArea/Search/RichEditor组件。

**适配指导**

默认行为变更，无需适配，但应注意变更后的行为是否对整体应用逻辑产生影响

## c1.arkui.4 TextInput组件underline默认样式变更

**访问级别**

公开接口

**变更原因**

依照UX规范

**变更影响**

该变更为非兼容性变更。API version 11及以前，TextInput组件设置underline时，组件出现的时候无圆角，组件获焦失焦后有圆角，且圆角值不同。API version 12及以后，依照UX规范统一默认都设置无圆角。

| 变更前 | 变更后 |
|---------|---------|
| ![](figures/init.png) | ![](figures/init.png) |
| ![](figures/focus.png) | ![](figures/init.png) |
| ![](figures/blur.png) | ![](figures/init.png) |

**API Level**

12 

**变更发生版本**

从OpenHarmony SDK 5.0.0.21 版本开始。

**变更的接口/组件**

TextInput组件。

**适配指导**

默认效果变更，无需适配，但应注意变更后的默认效果是否符合开发者预期，如不符合则应自定义修改效果控制变量以达到预期

## cl.arkui.5 AlphabetIndexer组件的默认样式变更

**访问级别**

公开接口

**变更原因**

a)当前AlphabetIndexer组件的字母索引条默认字体大小为12vp，依照UX规范修改字母索引条默认字体大小到10vp。

b)当前AlphabetIndexer组件的字母索引条默认字重为Normal，依照UX规范修改字母索引条默认字重到Medium。

c)当前AlphabetIndexer组件的字母索引条选中项文字默认字体大小为12vp，依照UX规范修改字母索引条选中项文字默认字体大小到10vp。

d)当前AlphabetIndexer组件的字母索引条选中项文字默认字重为Normal，依照UX规范修改字母索引条选中项文字默认字重到Medium。

e)当前AlphabetIndexer组件的字母索引条索引项背板圆角默认为4vp，依照UX规范修改字母索引条索引项背板圆角默认为8vp。

f)当前AlphabetIndexer组件的字母索引条背板圆角默认为0vp，依照UX规范修改字母索引条索引项背板圆角默认为12vp。

g)当前AlphabetIndexer组件的字母索引条背板上下padding默认为2vp，依照UX规范修改字母索引条索引项背板上下padding默认为4vp。

h)当前AlphabetIndexer组件的字母索引条pressed状态文字背板颜色默认为'#0c182431'，依照UX规范修改字母索引条pressed状态文字背板颜色默认为'#19182431'。

i)当前AlphabetIndexer组件的弹出窗口默认背板阴影尺寸为DefaultShadowM、依照UX规范变更默认背板阴影尺寸为DefaultShadowL。

j)当前AlphabetIndexer组件的弹出窗口默认背板最大高度为336vp、依照UX规范变更弹出窗口默认背板最大高度为342vp。

k)当前AlphabetIndexer组件的弹出窗口自适应折叠模式默认背板最大高度为224vp、依照UX规范变更弹出窗口自适应折叠模式默认背板最大高度为186vp。

l)当前AlphabetIndexer组件的弹出窗口上下padding默认为0vp、依照UX规范变更弹出窗口上下padding默认为4vp。

m)当前AlphabetIndexer组件的弹出窗口背板圆角默认为16vp，依照UX规范修改弹出窗口背板圆角默认为28vp。

n)当前AlphabetIndexer组件的弹出窗口索引项默认尺寸为56vp、依照UX规范变更弹出窗口索引项默认尺寸为48vp。

o)当前AlphabetIndexer组件的弹出窗口索引项间隔为0vp、依照UX规范变更弹出窗口索引项间隔为4vp。

p)当前AlphabetIndexer组件的弹出窗口索引项背板圆角默认为0vp，依照UX规范修改弹出窗口索引项背板圆角默认为24vp。

q)当前AlphabetIndexer组件的弹出窗口背板颜色默认为'#FFFFFFFF'，依照UX规范修改弹出窗口背板颜色默认为'#66808080'。

r)当前AlphabetIndexer组件的弹出窗口字母部分背板颜色默认为'#FFFFFFFF'，依照UX规范修改弹出窗口字母部分背板颜色默认为'#0c182431'。

s)当前AlphabetIndexer组件的弹出窗口非字母部分背板颜色默认为'#FFFFFFFF'，依照UX规范修改弹出窗口非字母部分背板颜色默认为'#00000000'。

t)当前AlphabetIndexer组件的弹出窗口非字母部分点击时背板颜色默认为0x1A000000，依照UX规范修改弹出窗口非字母部分背板颜色默认为'#0c182431'。

u)当前AlphabetIndexer组件的弹出窗口背板模糊材质默认为NONE，依照UX规范修改弹出窗口背板模糊材质默认为COMPONENT_REGULAR。

**变更影响**

该变更为非兼容性变更。API version 11及以前，采用当前默认值。API version 12及以后，采用修改后默认值。

**API Level**

12 

**变更发生版本**

从OpenHarmony SDK 5.0.0.21 版本开始。

**变更的接口/组件**

AlphabetIndexer组件

**适配指导**

请查阅[AlphabetIndexer组件](../../../application-dev/reference/apis-arkui/arkui-ts/ts-container-alphabet-indexer.md)文档进行适配。

## cl.arkui.6  AlphabetIndexer组件允许用户自定义AlphabetIndexer的样式风格 

**访问级别**

公开接口

**变更原因**

允许用户自定义AlphabetIndexer的样式风格：

1、设置AlphabetIndexer索引项背板圆角、AlphabetIndexer背板圆角自适应变化

2、设置AlphabetIndexer提示弹窗索引项背板圆角、AlphabetIndexer提示弹窗背板圆角自适应变化

3、设置AlphabetIndexer提示弹窗首个索引项背板颜色

4、设置AlphabetIndexer提示弹窗背板模糊风格

**变更影响**

该变更为非兼容性变更。

API version 11及以前，不允许用户自定义AlphabetIndexer索引项背板圆角、提示弹窗索引项背板圆角、提示弹窗首个索引项背板颜色、提示弹窗背板模糊风格。

![AlphabetIndexerBefore](figures/AlphabetIndexerBefore.gif)

API version 12及以后，允许用户自定义AlphabetIndexer索引项背板圆角、提示弹窗索引项背板圆角、提示弹窗首个索引项背板颜色、提示弹窗背板模糊风格。

![AlphabetIndexerAfter](figures/AlphabetIndexerAfter.gif)

**API Level**

12

**变更发生版本**

从OpenHarmony SDK 5.0.0.21 版本开始。

**示例：**

```
@Entry
@Component
struct AlphabetIndexerSample {
  private arrayA: string[] = ['安']
  private arrayB: string[] = ['卜', '白', '包', '毕', '丙']
  private arrayC: string[] = ['曹', '成', '陈', '催']
  private arrayL: string[] = ['刘', '李', '楼', '梁', '雷', '吕', '柳', '卢']
  private value: string[] = ['#', 'A', 'B', 'C', 'D', 'E', 'F', 'G',
    'H', 'I', 'J', 'K', 'L', 'M', 'N',
    'O', 'P', 'Q', 'R', 'S', 'T', 'U',
    'V', 'W', 'X', 'Y', 'Z']

  build() {
    Stack({ alignContent: Alignment.Start }) {
      Row() {
        List({ space: 20, initialIndex: 0 }){}
        .width('50%')
        .height('100%')

        AlphabetIndexer({ arrayValue: this.value, selected: 0 })
          .popupBackground(0xD2B48C) // 弹出框背景颜色
          .popupBackgroundBlurStyle(BlurStyle.COMPONENT_ULTRA_THICK) // 设置AlphabetIndexer提示弹窗背板模糊风格
          .popupTitleBackground(0x00FF00) // 设置AlphabetIndexer提示弹窗首个索引项背板颜色
          .popupItemBorderRadius(20) // 设置AlphabetIndexer提示弹窗索引项背板圆角
          .itemBorderRadius(5) // 设置AlphabetIndexer索引项背板圆角
          .onSelect((index: number) => {
            console.info(this.value[index] + ' Selected!')
          })
          .onRequestPopupData((index: number) => {
            if (this.value[index] == 'A') {
              return this.arrayA // 当选中A时，弹出框里面的提示文本列表显示A对应的列表arrayA，选中B、C、L时也同样
            } else if (this.value[index] == 'B') {
              return this.arrayB
            } else if (this.value[index] == 'C') {
              return this.arrayC
            } else if (this.value[index] == 'L') {
              return this.arrayL
            } else {
              return [] // 选中其余子母项时，提示文本列表为空
            }
          })
          .onPopupSelect((index: number) => {
            console.info('onPopupSelected:' + index)
          })
      }
      .width('100%')
      .height('100%')
    }
  }
}
```

**变更的接口/组件**

AlphabetIndexer组件

**适配指导**

请查阅[AlphabetIndexer组件](../../../application-dev/reference/apis-arkui/arkui-ts/ts-container-alphabet-indexer.md)文档进行适配。

## cl.arkui.7 Menu组件header、footer对齐方式变更

**访问级别**

公开接口

**变更原因**
UX样式变更

**变更影响**

该变更为兼容性变更。变更前，header、footer与菜单文本左对齐。变更后，header、footer与左侧图标左对齐。

**API Level**

起始level 9，在API 12进行版本隔离。

**变更发生版本**

从OpenHarmony SDK 5.0.0.21 版本开始。

**变更的接口/组件**

Menu组件。

**适配指导**

UX默认行为变更，无需适配。

## cl.arkui.8 Menu组件上下安全边距变更

**访问级别**

公开接口

**变更原因**
UX样式变更

**变更影响**

该变更为兼容性变更。变更前，菜单布局避让顶部状态栏与底部导航条后，上下再保留48vp的边距。变更后，菜单布局避让顶部状态栏与底部导航条后，上方保留16vp的边距，下方保留4vp的边距。

**API Level**

在API 12进行版本隔离

**变更发生版本**

从OpenHarmony SDK 5.0.0.21 版本开始。

**变更的接口/组件**

Menu组件。

**适配指导**

UX默认行为变更，无需适配。

## cl.arkui.9 DatePickerDialog列宽比例、picker上下间距、内容与弹窗边距样式变更

**访问级别**

公开接口

**变更原因**

UX样式变更。

**变更影响**

该变更为非兼容性变更。

a) DatePickerDialog列宽比例变更

变更前：年/月/日选择器列宽比例为1：1：1；展示时间时，日月/上下午/时/分 选择器列宽比例为12：7：7：7。

变更后：年/月/日选择器列宽比例为3：2：2；展示时间时，日月/上下午/时/分 选择器列宽比例为4：3：2：2。

b) DatePickerDialog内容与弹窗左右边界间距变更

变更前：内容与弹窗左右边界无间距。

变更后：内容与弹窗左右边界有24vp间距。

c) DatePickerDialog中picker上下间距变更

变更前：dialog中datePicker无上下间距。

变更后：dialog中datePicker上下间距为8vp。

如下图所示为变更前后效果对比：

| 变更前 | 变更后 |
|---------|---------|
| ![](figures/DatePickerDialog_Before.jpg) | ![](figures/DatePickerDialog_After.jpg) |
| ![](figures/DatePickerDialogWithTime_Before.jpg) | ![](figures/DatePickerDialogWithTime_After.jpg) |

**API Level**

API Level 8，在API 12进行版本隔离

**变更发生版本**

从OpenHarmony SDK 5.0.0.21开始。

**适配指导**

默认样式变更调整，无需适配。

