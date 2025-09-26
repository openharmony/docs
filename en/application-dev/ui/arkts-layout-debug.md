# Debugging UI Display Exceptions

This topic outlines effective methods for identifying and resolving UI display exceptions, illustrated with practical case studies.

## Identifying UI Display Exceptions

UI display exceptions are typically diagnosed by inspecting layout data. This involves obtaining either the full component tree using the **getInspectorTree** API or specific node attributes via the **getRectangleById** API.

**Component tree**

Since API version 9, the [getInspectorTree](../reference/apis-arkui/arkui-ts/ts-universal-attributes-component-id.md#getinspectortree9) API provides access to the component tree along with its attributes.

**Single Node**

Since API version 10, the [getRectangleById](../reference/apis-arkui/arkts-apis-uicontext-componentutils.md#getrectanglebyid) API allows you to obtain properties of an individual component, including size, position, translation, scale, rotation, and affine transformation matrix.

## Resolving UI Display Exceptions

The following example illustrates how to address a specific UI display exception.

### Abnormal Coordinates or Dimensions Returned by ComponentUtils.getRectangleById for the tabBar Component

**Symptom**

When the visibility of the **tabBar** component is dynamically controlled, the coordinates or dimensions obtained via **ComponentUtils.getRectangleById** may be inaccurate. For example, if the component is hidden by setting its width to 0, the reported coordinates may default to the center of the screen. After the component is made visible again, these incorrect coordinates may persist.

**Possible Causes**

- If the synchronous API is invoked while the component's width is temporarily set to 0, the layout engine may default to centering the node, resulting in incorrect coordinates.
- If the API is called before the layout has been fully rendered, such as immediately after toggling visibility, the returned layout data may be stale or incomplete.

**Solution**

- Call the API at the correct time: Ensure the layout has been fully rendered before querying component attributes. For example, after restoring the **tabBar** display, use a delay mechanism to wait for layout stabilization before obtaining coordinates.
- Listen for layout changes: Use the component's **onAreaChange** callback to trigger coordinate retrieval only after the layout has updated and stabilized.
- Validate obtained data: After obtaining coordinates, verify the component's dimensions. Discard results where width or height is zero, as these indicate invalid or incomplete layout data.


**Code Example**

```ts
import { ComponentUtils } from '@kit.ArkUI';

@Entry
@Component
struct Page {
  @State currentIndex: number = 0;
  @State msg: string = 'info';
  @State pivotX: number = 0;
  @State pivotY: number = 0;
  @State pivotShow: boolean = false;
  @State tabBarShow: boolean = true;

  private controller : TabsController = new TabsController();
  private uiContext : UIContext | undefined = undefined;
  private componentUtils : ComponentUtils | undefined = undefined;
  private componentId : string = 'tab-pink';
  private flag : boolean = false;
  private baseX : number = 0;
  private baseY : number = 0;

  @Builder
  tabBuilder(index: number, name: string) {
    Column() {
      Text(name)
        .fontSize(16)
        .fontWeight(this.currentIndex === index ? 500 : 400)
        .fontColor(this.currentIndex === index ? '#007DFF': '#182431')
        .lineHeight(22)
    }
    .id(`tab-${name}`)
    .width('100%')
    .height('100%')
    .borderStyle(BorderStyle.Solid)
    .borderWidth(1)
  }

  aboutToAppear(): void {
    this.uiContext = this.getUIContext();
    this.componentUtils = this.getUIContext().getComponentUtils();
  }

  getRectInfo(id?: string) : string {
    let componentId : string = id??this.componentId;
    let info = this.componentUtils?.getRectangleById(componentId);
    let infoStr : string = '';
    if (info) {
      infoStr = 'Size: ' + JSON.stringify(info.size) + ', WindowOffset: ' + JSON.stringify(info.windowOffset);
    }
    return infoStr;
  }

  getBasePosition() : void {
    if (this.flag) {
      return;
    }
    let info = this.componentUtils?.getRectangleById('root-stack');
    if (info) {
      this.baseX = info.windowOffset.x;
      this.baseY = info.windowOffset.y;
      this.msg = `${this.componentId}: ` + this.getRectInfo(this.componentId) + `, pivot: {x: ${this.pivotX}, y: ${this.pivotY}}`;
      this.flag = true;
    }
  }

  onDidBuild(): void {
  }

  build() {
    Stack() {
      Column() {
        Text(this.msg)
          .fontSize(20)
          .border({ width: 5, color: Color.Brown })
          .width('100%')
          .height('30%')
          .margin({ top: 50 })
        Row() {
          Button('Rect')
            .onClick(() => {
              this.msg = JSON.stringify(this.componentUtils?.getRectangleById('tab-pink'))
            })
            .width('33%')
          Button('replay')
            .onClick(() => {
              this.pivotShow = false;
              this.tabBarShow = false;
              this.pivotShow = true;
              setTimeout(() => {
                this.tabBarShow = true
              }, 100)
            })
            .width('33%')
          Button('pivot')
            .onClick(() => {
              this.pivotShow = !this.pivotShow;
            })
            .width('33%')
        }
        .width('100%')
        .height('10%')
        .justifyContent(FlexAlign.SpaceEvenly)
        Tabs({ barPosition: BarPosition.End, index: this.currentIndex, controller: this.controller }) {
          TabContent() {
            Column()
              .width('100%')
              .height('100%')
              .backgroundColor('#00CB87')
          }
          .tabBar(this.tabBuilder(0, 'green'))
          TabContent() {
            Column()
              .width('100%')
              .height('100%')
              .backgroundColor('#007DFF')
          }
          .tabBar(this.tabBuilder(1, 'blue'))
          TabContent() {
            Column()
              .width('100%')
              .height('100%')
              .backgroundColor('#FFBF00')
          }
          .tabBar(this.tabBuilder(2, 'yellow'))
          .width('25%')
          TabContent() {
            Column()
              .width('100%')
              .height('100%')
              .backgroundColor('#E67C92')
          }
          .tabBar(this.tabBuilder(3, 'pink'))
        }
        .expandSafeArea([SafeAreaType.CUTOUT, SafeAreaType.SYSTEM, SafeAreaType.KEYBOARD],
          [SafeAreaEdge.TOP, SafeAreaEdge.BOTTOM])
        .barWidth(this.tabBarShow ? '100%' : 0)
        .width('100%')
        .height('40%')
        .barHeight(44)
        .vertical(false)
        .barMode(BarMode.Fixed)
        .backgroundColor('#F1F2F3')
        .onChange((index: number) => {
          this.currentIndex = index;
          if (index == 3) {
            this.pivotShow = false;
          }
        })
        .animation({ duration: 100, curve: Curve.Linear })
      }
      .id('col')
      .width('100%')
      .height('100%')
      .justifyContent(FlexAlign.SpaceBetween)
      if (this.pivotShow) {
        Text('X')
          .width(18)
          .height(18)
          .textAlign(TextAlign.Center)
          .borderRadius(9)
          .fontColor(Color.White)
          .backgroundColor(Color.Red)
          .position({ x: this.uiContext?.px2vp(this.pivotX), y: this.uiContext?.px2vp(this.pivotY) })
          .onAreaChange(() => {
            let info = this.componentUtils?.getRectangleById(this.componentId);
            if (info) {
              this.getBasePosition();
              this.pivotX = info.windowOffset.x - this.baseX;
              this.pivotY = info.windowOffset.y - this.baseY;
              this.msg = `${this.componentId}: ` + this.getRectInfo(this.componentId) + `, pivot: {x: ${this.pivotX}, y: ${this.pivotY}}`;
            }
          })
      }
    }
    .id('root-stack')
  }
}
```
