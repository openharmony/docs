# Flex


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The **&lt;Flex&gt;** component allows for an elastic layout.


## Required Permissions

None


## Child Components

This component can contain child components.


## APIs

Flex(options?: { direction?: FlexDirection, wrap?: FlexWrap,  justifyContent?: FlexAlign, alignItems?: ItemAlign, alignContent?: FlexAlign })

Creates a standard **&lt;Flex&gt;** component.

- Parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | direction | FlexDirection | No | FlexDirection.Row | Direction&nbsp;in&nbsp;which&nbsp;child&nbsp;components&nbsp;are&nbsp;arranged&nbsp;in&nbsp;the&nbsp;**&lt;Flex&gt;**&nbsp;component,&nbsp;that&nbsp;is,&nbsp;the&nbsp;direction&nbsp;of&nbsp;the&nbsp;main&nbsp;axis. |
  | wrap | FlexWrap | No | FlexWrap.NoWrap | Whether&nbsp;the&nbsp;**&lt;Flex&gt;**&nbsp;component&nbsp;has&nbsp;a&nbsp;single&nbsp;line&nbsp;or&nbsp;multiple&nbsp;lines. |
  | justifyContent | FlexAlign | No | FlexAlign.Start | Alignment&nbsp;mode&nbsp;of&nbsp;the&nbsp;child&nbsp;components&nbsp;in&nbsp;the&nbsp;**&lt;Flex&gt;**&nbsp;component&nbsp;along&nbsp;the&nbsp;main&nbsp;axis. |
  | alignItems | [ItemAlign](ts-appendix-enums.md#itemalign-enums) | No | ItemAlign.Stretch | Alignment&nbsp;mode&nbsp;of&nbsp;the&nbsp;child&nbsp;components&nbsp;in&nbsp;the&nbsp;**&lt;Flex&gt;**&nbsp;component&nbsp;along&nbsp;the&nbsp;cross&nbsp;axis. |
  | alignContent | FlexAlign | No | FlexAlign.Start | Alignment&nbsp;mode&nbsp;of&nbsp;the&nbsp;child&nbsp;components&nbsp;in&nbsp;a&nbsp;multi-line&nbsp;**&lt;Flex&gt;**&nbsp;component&nbsp;along&nbsp;the&nbsp;cross&nbsp;axis.&nbsp;This&nbsp;parameter&nbsp;is&nbsp;valid&nbsp;only&nbsp;when&nbsp;**wrap**&nbsp;is&nbsp;set&nbsp;to&nbsp;**Wrap**&nbsp;or&nbsp;**WrapReverse**. |

- FlexDirection enums
    | Name | Description | 
  | -------- | -------- |
  | Row | The&nbsp;child&nbsp;components&nbsp;are&nbsp;arranged&nbsp;in&nbsp;the&nbsp;same&nbsp;direction&nbsp;as&nbsp;the&nbsp;main&nbsp;axis&nbsp;runs&nbsp;along&nbsp;the&nbsp;rows. | 
  | RowReverse | The&nbsp;child&nbsp;components&nbsp;are&nbsp;arranged&nbsp;opposite&nbsp;to&nbsp;the&nbsp;**Row**&nbsp;direction. | 
  | Column | The&nbsp;child&nbsp;components&nbsp;are&nbsp;arranged&nbsp;in&nbsp;the&nbsp;same&nbsp;direction&nbsp;as&nbsp;the&nbsp;main&nbsp;axis&nbsp;runs&nbsp;down&nbsp;the&nbsp;columns. | 
  | ColumnReverse | The&nbsp;child&nbsp;components&nbsp;are&nbsp;arranged&nbsp;opposite&nbsp;to&nbsp;the&nbsp;**Column**&nbsp;direction. | 

- FlexWrap enums
    | Name | Description | 
  | -------- | -------- |
  | NoWrap | The&nbsp;child&nbsp;components&nbsp;in&nbsp;the&nbsp;**&lt;Flex&gt;**&nbsp;component&nbsp;are&nbsp;arranged&nbsp;in&nbsp;a&nbsp;single&nbsp;line,&nbsp;and&nbsp;they&nbsp;may&nbsp;overflow. | 
  | Wrap | The&nbsp;child&nbsp;components&nbsp;in&nbsp;the&nbsp;**&lt;Flex&gt;**&nbsp;component&nbsp;are&nbsp;arranged&nbsp;in&nbsp;multiple&nbsp;lines,&nbsp;and&nbsp;they&nbsp;may&nbsp;overflow. | 
  | WrapReverse | The&nbsp;child&nbsp;components&nbsp;in&nbsp;the&nbsp;**&lt;Flex&gt;**&nbsp;component&nbsp;are&nbsp;reversely&nbsp;arranged&nbsp;in&nbsp;multiple&nbsp;lines,&nbsp;and&nbsp;they&nbsp;may&nbsp;overflow. | 

- FlexAlign enums
    | Name | Description | 
  | -------- | -------- |
  | Start | The&nbsp;child&nbsp;components&nbsp;are&nbsp;aligned&nbsp;with&nbsp;the&nbsp;start&nbsp;edge&nbsp;of&nbsp;the&nbsp;main&nbsp;axis.&nbsp;The&nbsp;first&nbsp;component&nbsp;is&nbsp;aligned&nbsp;with&nbsp;the&nbsp;main-start,&nbsp;and&nbsp;subsequent&nbsp;components&nbsp;are&nbsp;aligned&nbsp;with&nbsp;the&nbsp;previous&nbsp;one. | 
  | Center | The&nbsp;child&nbsp;components&nbsp;are&nbsp;aligned&nbsp;in&nbsp;the&nbsp;center&nbsp;of&nbsp;the&nbsp;main&nbsp;axis.&nbsp;The&nbsp;space&nbsp;between&nbsp;the&nbsp;first&nbsp;component&nbsp;and&nbsp;the&nbsp;main-start&nbsp;is&nbsp;the&nbsp;same&nbsp;as&nbsp;that&nbsp;between&nbsp;the&nbsp;last&nbsp;component&nbsp;and&nbsp;the&nbsp;main-end. | 
  | End | The&nbsp;child&nbsp;components&nbsp;are&nbsp;aligned&nbsp;with&nbsp;the&nbsp;end&nbsp;edge&nbsp;of&nbsp;the&nbsp;main&nbsp;axis.&nbsp;The&nbsp;last&nbsp;component&nbsp;is&nbsp;aligned&nbsp;with&nbsp;the&nbsp;main-end,&nbsp;and&nbsp;other&nbsp;components&nbsp;are&nbsp;aligned&nbsp;with&nbsp;the&nbsp;next&nbsp;one. | 
  | SpaceBetween | The&nbsp;child&nbsp;components&nbsp;are&nbsp;evenly&nbsp;distributed&nbsp;along&nbsp;the&nbsp;main&nbsp;axis.&nbsp;The&nbsp;first&nbsp;component&nbsp;is&nbsp;aligned&nbsp;with&nbsp;the&nbsp;main-start,&nbsp;the&nbsp;last&nbsp;component&nbsp;is&nbsp;aligned&nbsp;with&nbsp;the&nbsp;main-end,&nbsp;and&nbsp;the&nbsp;remaining&nbsp;components&nbsp;are&nbsp;distributed&nbsp;so&nbsp;that&nbsp;the&nbsp;space&nbsp;between&nbsp;any&nbsp;two&nbsp;adjacent&nbsp;components&nbsp;is&nbsp;the&nbsp;same. | 
  | SpaceAround | The&nbsp;child&nbsp;components&nbsp;are&nbsp;evenly&nbsp;distributed&nbsp;along&nbsp;the&nbsp;main&nbsp;axis,&nbsp;with&nbsp;a&nbsp;half-size&nbsp;space&nbsp;on&nbsp;either&nbsp;end.&nbsp;The&nbsp;space&nbsp;between&nbsp;any&nbsp;two&nbsp;adjacent&nbsp;components&nbsp;is&nbsp;the&nbsp;same.&nbsp;The&nbsp;space&nbsp;between&nbsp;the&nbsp;first&nbsp;component&nbsp;and&nbsp;main-start,&nbsp;and&nbsp;that&nbsp;between&nbsp;the&nbsp;last&nbsp;component&nbsp;and&nbsp;cross-main&nbsp;are&nbsp;both&nbsp;half&nbsp;the&nbsp;size&nbsp;of&nbsp;the&nbsp;space&nbsp;between&nbsp;two&nbsp;adjacent&nbsp;components. | 
  | SpaceEvenly | The&nbsp;child&nbsp;components&nbsp;are&nbsp;equally&nbsp;distributed&nbsp;along&nbsp;the&nbsp;main&nbsp;axis.&nbsp;The&nbsp;space&nbsp;between&nbsp;the&nbsp;first&nbsp;component&nbsp;and&nbsp;main-start,&nbsp;the&nbsp;space&nbsp;between&nbsp;the&nbsp;last&nbsp;component&nbsp;and&nbsp;main-end,&nbsp;and&nbsp;the&nbsp;space&nbsp;between&nbsp;two&nbsp;adjacent&nbsp;components&nbsp;are&nbsp;the&nbsp;same. | 


## Example


```
// Example 01
@Entry
@Component
struct FlexExample1 {
  build() {
    Column() {
      Column({ space: 5 }) {
        Text('direction:Row').fontSize(9).fontColor(0xCCCCCC).width('90%')
        Flex({ direction: FlexDirection.Row }) {
          Text('1').width('20%').height(50).backgroundColor(0xF5DEB3)
          Text('2').width('20%').height(50).backgroundColor(0xD2B48C)
          Text('3').width('20%').height(50).backgroundColor(0xF5DEB3)
          Text('4').width('20%').height(50).backgroundColor(0xD2B48C)
        }
        .height(70)
        .width('90%')
        .padding(10)
        .backgroundColor(0xAFEEEE)

        Text('direction:RowReverse').fontSize(9).fontColor(0xCCCCCC).width('90%')
        Flex({ direction: FlexDirection.RowReverse }) {
          Text('1').width('20%').height(50).backgroundColor(0xF5DEB3)
          Text('2').width('20%').height(50).backgroundColor(0xD2B48C)
          Text('3').width('20%').height(50).backgroundColor(0xF5DEB3)
          Text('4').width('20%').height(50).backgroundColor(0xD2B48C)
        }
        .height(70)
        .width('90%')
        .padding(10)
        .backgroundColor(0xAFEEEE)

        Text('direction:Column').fontSize(9).fontColor(0xCCCCCC).width('90%')
        Flex({ direction: FlexDirection.Column }) {
          Text('1').width('100%').height(40).backgroundColor(0xF5DEB3)
          Text('2').width('100%').height(40).backgroundColor(0xD2B48C)
          Text('3').width('100%').height(40).backgroundColor(0xF5DEB3)
          Text('4').width('100%').height(40).backgroundColor(0xD2B48C)
        }
        .height(160)
        .width('90%')
        .padding(10)
        .backgroundColor(0xAFEEEE)

        Text('direction:ColumnReverse').fontSize(9).fontColor(0xCCCCCC).width('90%')
        Flex({ direction: FlexDirection.ColumnReverse }) {
          Text('1').width('100%').height(40).backgroundColor(0xF5DEB3)
          Text('2').width('100%').height(40).backgroundColor(0xD2B48C)
          Text('3').width('100%').height(40).backgroundColor(0xF5DEB3)
          Text('4').width('100%').height(40).backgroundColor(0xD2B48C)
        }
        .height(160)
        .width('90%')
        .padding(10)
        .backgroundColor(0xAFEEEE)
      }.width('100%').margin({ top: 5 })
    }.width('100%')
  }
}
```

![en-us_image_0000001256978365](figures/en-us_image_0000001256978365.gif)


```
// Example 02
@Entry
@Component
struct FlexExample2 {
  build() {
    Column() {
      Column({ space: 5 }) {
        Text('Wrap').fontSize(9).fontColor(0xCCCCCC).width('90%')
        Flex({ wrap: FlexWrap.Wrap }) {
          Text('1').width('50%').height(50).backgroundColor(0xF5DEB3)
          Text('2').width('50%').height(50).backgroundColor(0xD2B48C)
          Text('3').width('50%').height(50).backgroundColor(0xD2B48C)
        }
        .width('90%')
        .padding(10)
        .backgroundColor(0xAFEEEE)

        Text('NoWrap').fontSize(9).fontColor(0xCCCCCC).width('90%')
        Flex({ wrap: FlexWrap.NoWrap }) {
          Text('1').width('50%').height(50).backgroundColor(0xF5DEB3)
          Text('2').width('50%').height(50).backgroundColor(0xD2B48C)
          Text('3').width('50%').height(50).backgroundColor(0xF5DEB3)
        }
        .width('90%')
        .padding(10)
        .backgroundColor(0xAFEEEE)

        Text('WrapReverse').fontSize(9).fontColor(0xCCCCCC).width('90%')
        Flex({ wrap: FlexWrap.WrapReverse , direction:FlexDirection.Row }) {
          Text('1').width('50%').height(50).backgroundColor(0xF5DEB3)
          Text('2').width('50%').height(50).backgroundColor(0xD2B48C)
          Text('3').width('50%').height(50).backgroundColor(0xD2B48C)
        }
        .width('90%')
        .height(120)
        .padding(10)
        .backgroundColor(0xAFEEEE)
      }.width('100%').margin({ top: 5 })
    }.width('100%')
  }
}
```

![en-us_image_0000001211898500](figures/en-us_image_0000001211898500.png)


```
// Example 03
@Component
struct JustifyContentFlex {
  @Prop justifyContent : number

  build() {
    Flex({ justifyContent: this.justifyContent }) {
      Text('1').width('20%').height(50).backgroundColor(0xF5DEB3)
      Text('2').width('20%').height(50).backgroundColor(0xD2B48C)
      Text('3').width('20%').height(50).backgroundColor(0xF5DEB3)
    }
    .width('90%')
    .padding(10)
    .backgroundColor(0xAFEEEE)
  }
}

@Entry
@Component
struct FlexExample3 {
  build() {
    Column() {
      Column({ space: 5 }) {
        Text('justifyContent:Start').fontSize(9).fontColor(0xCCCCCC).width('90%')
        JustifyContentFlex({ justifyContent: FlexAlign.Start })

        Text('justifyContent:Center').fontSize(9).fontColor(0xCCCCCC).width('90%')
        JustifyContentFlex({ justifyContent: FlexAlign.Center })

        Text('justifyContent:End').fontSize(9).fontColor(0xCCCCCC).width('90%')
        JustifyContentFlex({ justifyContent: FlexAlign.End })

        Text('justifyContent:SpaceBetween').fontSize(9).fontColor(0xCCCCCC).width('90%')
        JustifyContentFlex({ justifyContent: FlexAlign.SpaceBetween })

        Text('justifyContent:SpaceAround').fontSize(9).fontColor(0xCCCCCC).width('90%')
        JustifyContentFlex({ justifyContent: FlexAlign.SpaceAround })

        Text('justifyContent:SpaceEvenly').fontSize(9).fontColor(0xCCCCCC).width('90%')
        JustifyContentFlex({ justifyContent: FlexAlign.SpaceEvenly })
      }.width('100%').margin({ top: 5 })
    }.width('100%')
  }
}
```

![en-us_image_0000001212218462](figures/en-us_image_0000001212218462.gif)


```
// Example 04
@Component
struct AlignItemsFlex {
  @Prop alignItems : number

  build() {
    Flex({ alignItems: this.alignItems }) {
      Text('1').width('33%').height(30).backgroundColor(0xF5DEB3)
      Text('2').width('33%').height(40).backgroundColor(0xD2B48C)
      Text('3').width('33%').height(50).backgroundColor(0xF5DEB3)
    }
    .size({width: '90%', height: 80})
    .padding(10)
    .backgroundColor(0xAFEEEE)
  }
}

@Entry
@Component
struct FlexExample4 {
  build() {
    Column() {
      Column({ space: 5 }) {
        Text('alignItems:Auto').fontSize(9).fontColor(0xCCCCCC).width('90%')
        AlignItemsFlex({ alignItems: ItemAlign.Auto })

        Text('alignItems:Start').fontSize(9).fontColor(0xCCCCCC).width('90%')
        AlignItemsFlex({ alignItems: ItemAlign.Start })

        Text('alignItems:Center').fontSize(9).fontColor(0xCCCCCC).width('90%')
        AlignItemsFlex({ alignItems: ItemAlign.Center })

        Text('alignItems:End').fontSize(9).fontColor(0xCCCCCC).width('90%')
        AlignItemsFlex({ alignItems: ItemAlign.End })

        Text('alignItems:Stretch').fontSize(9).fontColor(0xCCCCCC).width('90%')
        AlignItemsFlex({ alignItems: ItemAlign.Stretch })

        Text('alignItems:Baseline').fontSize(9).fontColor(0xCCCCCC).width('90%')
        AlignItemsFlex({ alignItems: ItemAlign.Baseline })
      }.width('100%').margin({ top: 5 })
    }.width('100%')
  }
}
```

![en-us_image_0000001257138371](figures/en-us_image_0000001257138371.jpg)

![en-us_image_0000001212378426](figures/en-us_image_0000001212378426.gif)


```
// Example 05
@Component
struct AlignContentFlex {
  @Prop alignContent: number

  build() {
    Flex({ wrap: FlexWrap.Wrap, alignContent: this.alignContent }) {
      Text('1').width('50%').height(20).backgroundColor(0xF5DEB3)
      Text('2').width('50%').height(20).backgroundColor(0xD2B48C)
      Text('3').width('50%').height(20).backgroundColor(0xD2B48C)
    }
    .size({ width: '90%', height: 90 })
    .padding(10)
    .backgroundColor(0xAFEEEE)
  }
}

@Entry
@Component
struct FlexExample5 {
  build() {
    Column() {
      Column({ space: 5 }) {
        Text('alignContent:Start').fontSize(9).fontColor(0xCCCCCC).width('90%')
        AlignContentFlex({ alignContent: FlexAlign.Start })

        Text('alignContent:Center').fontSize(9).fontColor(0xCCCCCC).width('90%')
        AlignContentFlex({ alignContent: FlexAlign.Center })

        Text('alignContent:End').fontSize(9).fontColor(0xCCCCCC).width('90%')
        AlignContentFlex({ alignContent: FlexAlign.End })

        Text('alignContent:SpaceBetween').fontSize(9).fontColor(0xCCCCCC).width('90%')
        AlignContentFlex({ alignContent: FlexAlign.SpaceBetween })

        Text('alignContent:SpaceAround').fontSize(9).fontColor(0xCCCCCC).width('90%')
        AlignContentFlex({ alignContent: FlexAlign.SpaceAround })

        Text('alignContent:SpaceEvenly').fontSize(9).fontColor(0xCCCCCC).width('90%')
        AlignContentFlex({ alignContent: FlexAlign.SpaceEvenly })
      }.width('100%').margin({ top: 5 })
    }.width('100%')
  }
}
```

![en-us_image_0000001256858413](figures/en-us_image_0000001256858413.gif)
