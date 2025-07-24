# Panel

该组件在ArkTS1.1中已标记为废弃，并在ArkTS1.2中不再支持。

ArkTS1.1组件声明：[Panel](../reference/apis-arkui/arkui-ts/ts-container-panel.md)

替代的ArkTS1.2组件声明：[bindSheet(isShow: Optional<boolean>, builder: CustomBuilder, options?: SheetOptions): T](../reference/apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#bindsheet)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
@Entry
@Component
struct Index {
  @State panel_show: boolean = false;

  build(){
    Column(){
      Button("panel_show")
        .onClick(()=>{
          this.panel_show = !this.panel_show;
        })
      Panel(this.panel_show) {
        Text("Panel")
      }
      .show(this.panel_show)
      .type(PanelType.Foldable)
      .mode(PanelMode.Half)
      .dragBar(true)
      .halfHeight(500)
      .showCloseIcon(true)
      .onChange((width: number, height: number, mode: PanelMode) => {
        console.info(`width:${width},height:${height},mode:${mode}`);
      })
      .onHeightChange((height: number) => {
        console.info(`height:${height}`);
      })
    }
  }
}
```

ArkTS1.2

<!--code_no_check-->
```ts
@Entry
@Component
struct Index {
  @State sheet_show: boolean = false;

  @Builder
  SheetBuilder() {
    Text("bindsheet")
  }

  build(){
    Button("sheet_show")
      .onClick(()=>{
        this.sheet_show = !this.sheet_show;
      })
      .bindSheet(this.sheet_show, this.SheetBuilder,
        {
          dragBar: true,
          detents: [500, 650],
          showClose: true,
          onHeightDidChange: (value: number) => {
            console.info(`onHeightDidChange value:${value}`);
          },
          onWidthDidChange: (value: number) => {
            console.info(`onWidthDidChange value:${value}`);
          },
          onDetentsDidChange: (value: number) => {
            console.info(`onDetentsDidChange value:${value}`);
          },
          onTypeDidChange: (sheetType: SheetType) => {
            console.info(`onTypeDidChange sheetType:${sheetType}`);
          }
        } as SheetOptions)
  }
}
```