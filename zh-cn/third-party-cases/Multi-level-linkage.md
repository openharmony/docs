# 列表的多级联动
## 场景介绍
多级联动是指根据一个列表（一级列表）的选择结果，来更新另一个列表（二级列表）的选择项，再来更新第三个列表（三级列表）的选择，以此类推。这种联动可以根据用户的实际需求，快速定位到想要的选项，提高交互体验。例如，省市县三级地区的选择、工作部门的选择，本文即为大家介绍如何开发列表的多级联动。

## 效果呈现
本例效果图如下：
![](./figures/sanji.gif)

## 运行环境

本例基于以下环境开发，开发者也可以基于其他适配的版本进行开发：
- IDE: DevEco Studio 4.0 Release
- SDK: Ohos_sdk_public 4.0.10.13 (API Version 10 Release)

## 实现思路
本例关键功能点及其实现思路如下：
- 文本选择弹窗：通过CompanyDialogController实现。

- 点击公司列表弹出对应旗下子公司的列表，点击子公司列表弹出对应的旗下部门的网格：通过ForEach的嵌套使用进行循环渲染公司列表、子公司列表、部门。

## 开发步骤
根据实现思路，具体开发步骤如下：
1. 构建列表数据。
  
    ```ts
    // LinkageData.ets
    export interface Link{
      name:string
      Subsidiary:a[]
    }
    export interface a{
      name:string,
    department:Array<string>
    }
    export const LinkageData:Link[]=[
      {
        name:"A公司",
        Subsidiary:[
          {
            name:"a子公司",
            department:[
              "技术部",
              "工程部",
              "维护部",
              "运营部",
              "售后部"
            ]
          },
          {
            name:"b子公司",
            department:[
              "行政部",
              "管理部",
              "服务部",
              "秘书部"
            ]
          },
          {
            name:"c子公司",
            department:[
              "行动部",
              "情报部",
              "信息部"
            ]
          }
        ]
      },
    ...
    ]
    ```
2. 打开自定义弹窗。通过CustomDialogController以实现自定义弹窗的打开。
 
    ```ts   
    // Index.ets
    ...
    CompanyDialogController:CustomDialogController = new CustomDialogController({
      builder:CompanyPicker({
        postA:$postA,
        company:$companyButtonTitle,
        companyStringArray:this.CompanyArray
      }),
      autoCancel:true,
      alignment:DialogAlignment.Bottom,
      customStyle:true
    })

    build() {
      Column(){
        Text(this.companyButtonTitle)
          .height(50)
          .fontSize(30)
          .borderRadius(10)
          .backgroundColor(0xFFFFFF)
          .onClick(()=>{
            this.CompanyDialogController.open();
          })
      }.width('100%').height('100%')
      .backgroundColor(Color.White)
      .padding({top:5})
    }
    ...         
    ```
3. 具体部门的选择。通过ForEach的嵌套使用循环渲染公司列表、子公司列表、部门。通过点击事件将具体部门展示到弹窗上方，点击确定后，界面显示具体部门。
   
    ```ts
    //  Index.ets
    ...
    List({space:15, initialIndex:0,scroller:this.scroller}){
      ForEach(LinkageData,(Item:Link)=>{
        ListItem() {
          Column() {
            Text(`${Item.name === '' ? Item : Item.name}`)
              .height(40)
              .fontSize(30)
              .fontColor('#000000')
              .width('100%')
              .margin({ top: 10 })
              .onClick(() => {
                if (this.isCompany === Item.name) {
                  this.isCompany = ''
                } else {
                  this.isCompany = Item.name
                }
              })
            if (this.isCompany === Item.name) {
              List({ space: 10 }) {
                ForEach(Item.Subsidiary, (ItemA: a) => {
                  ListItem() {
                    Column() {
                      Text(`${Item.name === undefined ? ItemA : ItemA.name}`)
                        .width('100%')
                        .height(20)
                        .fontSize(18)
                        .margin({ top: 4 })
                        .onClick(() => {
                          if (this.isSubsidiaryAA === ItemA.name) {
                            this.isSubsidiaryAA = ''
                          } else {
                            this.isSubsidiaryAA = ItemA.name
                          }
                        })
                        if (this.isSubsidiaryAA === ItemA.name) {
                          Grid() {
                            ForEach(ItemA.department, (departmentName: string) => {
                              GridItem() {
                                Text(`${departmentName}`)
                                  .margin({ top: 10, bottom: 10 })
                                  .fontSize(14)
                                  .maxLines(5)
                                  .fontColor(Color.Black)
                                  .borderRadius(5)
                                  .padding(5)
                                  .backgroundColor('#00FFFF')
                                  .onClick(() => {
                                    this.tempDepartment = `${Item.name}${ItemA.name}${departmentName}`
                                  })
                              }
                            })
                          }.width('100%')
                          .height(100)
                          .columnsTemplate('1fr 1fr')
                        }
                    }
                  }
                })
              }
            }
          }
        }
      })
    }
    ...
    ```
4. 自定义弹窗的关闭。
    
    ```ts
    // Index.ets
    ...
    Row(){
      Text(this.tempDepartment)
        .fontSize(14)
        .fontColor(Color.White)
        .layoutWeight(1)
        .height(40)
      Button("确定",{type:ButtonType.Normal,stateEffect:true})
        .fontSize(14)
        .fontColor(Color.White)
        .layoutWeight(1)
        .height(40)
        .onClick(()=>{
          this.company = this.tempDepartment
          if (this.controller !== undefined){
            this.controller.close()
          }
        })
    }
    ...
    ```
## 完整代码
在LinkageData.ets根据效果开发者自行进行编辑,在Index.ets在开发步骤中基本展示全部代码。
## 参考
[自定义弹窗](../application-dev/reference/apis-arkui/arkui-ts/ts-methods-custom-dialog-box.md)

[循环渲染](../application-dev/quick-start/arkts-rendering-control-foreach.md)