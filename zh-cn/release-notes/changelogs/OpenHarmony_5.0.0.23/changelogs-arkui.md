# ArkUI子系统Changelog

## cl.arkui.1 AlphabetIndexer组件的默认样式变更

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

从OpenHarmony SDK 5.0.0.23 版本开始。

**变更的接口/组件**

AlphabetIndexer组件

**适配指导**

请查阅[AlphabetIndexer组件](../../../application-dev/reference/apis-arkui/arkui-ts/ts-container-alphabet-indexer.md)文档进行适配。

## cl.arkui.2  AlphabetIndexer组件允许用户自定义AlphabetIndexer的样式风格 

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

从OpenHarmony SDK 5.0.0.23 版本开始。

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
