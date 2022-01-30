# Path2D<a name="EN-US_TOPIC_0000001237355081"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

**Path2D**  allows you to describe a path through an existing path. This path can be drawn through the  **stroke**  API of  **Canvas**.

## addPath<a name="section1271914475715"></a>

addPath\(path: Object\): void

Adds a path to this path.

-   Parameters

    <a name="table1948454813819"></a>
    <table><thead align="left"><tr id="row17484114816383"><th class="cellrowborder" valign="top" width="18.55185518551855%" id="mcps1.1.6.1.1"><p id="p1348494853817"><a name="p1348494853817"></a><a name="p1348494853817"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="21.922192219221923%" id="mcps1.1.6.1.2"><p id="p1148414873815"><a name="p1148414873815"></a><a name="p1148414873815"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.001000100010002%" id="mcps1.1.6.1.3"><p id="p1686893173019"><a name="p1686893173019"></a><a name="p1686893173019"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.26122612261226%" id="mcps1.1.6.1.4"><p id="p57637369302"><a name="p57637369302"></a><a name="p57637369302"></a>Default Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="37.263726372637265%" id="mcps1.1.6.1.5"><p id="p34841948133816"><a name="p34841948133816"></a><a name="p34841948133816"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1148424813816"><td class="cellrowborder" valign="top" width="18.55185518551855%" headers="mcps1.1.6.1.1 "><p id="p64848482383"><a name="p64848482383"></a><a name="p64848482383"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.922192219221923%" headers="mcps1.1.6.1.2 "><p id="p9484194817384"><a name="p9484194817384"></a><a name="p9484194817384"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.001000100010002%" headers="mcps1.1.6.1.3 "><p id="p178699310307"><a name="p178699310307"></a><a name="p178699310307"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.26122612261226%" headers="mcps1.1.6.1.4 "><p id="p1776323612308"><a name="p1776323612308"></a><a name="p1776323612308"></a>null</p>
    </td>
    <td class="cellrowborder" valign="top" width="37.263726372637265%" headers="mcps1.1.6.1.5 "><p id="p9484144883813"><a name="p9484144883813"></a><a name="p9484144883813"></a>Path to be added to this path.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    @Entry
    @Component
    struct AddPath {
      private settings: RenderingContextSettings = new RenderingContextSettings(true,true)
      private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)
    
      private path2Da: Path2D = new Path2D("M250 150 L150 350 L350 350 Z")
      private path2Db: Path2D = new Path2D()
    
      build() {
        Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
          Canvas(this.context)
            .width('100%')
            .height('100%')
            .backgroundColor('#ffff00')
            .onReady(() =>{
              this.path2Db.addPath(this.path2Da)
              this.context.stroke(this.path2Db)
            })
        }
        .width('100%')
        .height('100%')
      }
    }
    ```

    ![](figures/en-us_image_0000001192595216.png)


## closePath<a name="section1968819330812"></a>

closePath\(\): void

Moves the current point of the path back to the start point of the path, and draws a straight line between the current point and the start point. If the shape is closed or has only one point, this method does not perform any action.

-   Example

    ```
    @Entry
    @Component
    struct ClosePath {
      private settings: RenderingContextSettings = new RenderingContextSettings(true,true)
      private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)
      private path2Db: Path2D = new Path2D()
    
      build() {
        Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
          Canvas(this.context)
            .width('100%')
            .height('100%')
            .backgroundColor('#ffff00')
            .onReady(() =>{
              this.path2Db.moveTo(200, 100)
              this.path2Db.lineTo(300, 100)
              this.path2Db.lineTo(200, 200)
              this.path2Db.closePath()
              this.context.stroke(this.path2Db)
            })
        }
        .width('100%')
        .height('100%')
      }
    }
    ```

    ![](figures/unnaming-(4).png)


## moveTo<a name="section583345918819"></a>

moveTo\(x: number, y: number\): void

Moves the current coordinate point of the path to the target point, without drawing a line during the movement.

-   Parameters

    <a name="table78491916124512"></a>
    <table><thead align="left"><tr id="row14850181613456"><th class="cellrowborder" valign="top" width="18.55185518551855%" id="mcps1.1.6.1.1"><p id="p11850191612454"><a name="p11850191612454"></a><a name="p11850191612454"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="15.74157415741574%" id="mcps1.1.6.1.2"><p id="p9850416144514"><a name="p9850416144514"></a><a name="p9850416144514"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.96149614961496%" id="mcps1.1.6.1.3"><p id="p883212733119"><a name="p883212733119"></a><a name="p883212733119"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.481348134813482%" id="mcps1.1.6.1.4"><p id="p0316101217310"><a name="p0316101217310"></a><a name="p0316101217310"></a>Default Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="37.263726372637265%" id="mcps1.1.6.1.5"><p id="p1850816154519"><a name="p1850816154519"></a><a name="p1850816154519"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row6850181612455"><td class="cellrowborder" valign="top" width="18.55185518551855%" headers="mcps1.1.6.1.1 "><p id="p17850161612455"><a name="p17850161612455"></a><a name="p17850161612455"></a>x</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.74157415741574%" headers="mcps1.1.6.1.2 "><p id="p118501716164516"><a name="p118501716164516"></a><a name="p118501716164516"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.6.1.3 "><p id="p2083318743114"><a name="p2083318743114"></a><a name="p2083318743114"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.481348134813482%" headers="mcps1.1.6.1.4 "><p id="p031611121313"><a name="p031611121313"></a><a name="p031611121313"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="37.263726372637265%" headers="mcps1.1.6.1.5 "><p id="p3850181634517"><a name="p3850181634517"></a><a name="p3850181634517"></a>X-coordinate of the target point.</p>
    </td>
    </tr>
    <tr id="row12850181618452"><td class="cellrowborder" valign="top" width="18.55185518551855%" headers="mcps1.1.6.1.1 "><p id="p1185081616453"><a name="p1185081616453"></a><a name="p1185081616453"></a>y</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.74157415741574%" headers="mcps1.1.6.1.2 "><p id="p98506164455"><a name="p98506164455"></a><a name="p98506164455"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.6.1.3 "><p id="p6833107113114"><a name="p6833107113114"></a><a name="p6833107113114"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.481348134813482%" headers="mcps1.1.6.1.4 "><p id="p63161312103113"><a name="p63161312103113"></a><a name="p63161312103113"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="37.263726372637265%" headers="mcps1.1.6.1.5 "><p id="p138501116104518"><a name="p138501116104518"></a><a name="p138501116104518"></a>Y-coordinate of the target point.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    @Entry
    @Component
    struct MoveTo {
      private settings: RenderingContextSettings = new RenderingContextSettings(true,true)
      private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)
      private path2Db: Path2D = new Path2D()
    
      build() {
        Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
          Canvas(this.context)
            .width('100%')
            .height('100%')
            .backgroundColor('#ffff00')
            .onReady(() =>{
              this.path2Db.moveTo(50, 100)
              this.path2Db.lineTo(250, 100)
              this.path2Db.lineTo(150, 200)
              this.path2Db.closePath()
              this.context.stroke(this.path2Db)
            })
        }
        .width('100%')
        .height('100%')
      }
    }
    ```

    ![](figures/en-us_image_0000001237475113.png)


## lineTo<a name="section11118291297"></a>

lineTo\(x: number, y: number\): void

Draws a straight line from the current point to the target point.

-   Parameters

    <a name="table174093224819"></a>
    <table><thead align="left"><tr id="row187401432134818"><th class="cellrowborder" valign="top" width="18.55185518551855%" id="mcps1.1.6.1.1"><p id="p374173224817"><a name="p374173224817"></a><a name="p374173224817"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.471647164716472%" id="mcps1.1.6.1.2"><p id="p2741183219482"><a name="p2741183219482"></a><a name="p2741183219482"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.771277127712771%" id="mcps1.1.6.1.3"><p id="p46781745173116"><a name="p46781745173116"></a><a name="p46781745173116"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.941494149414941%" id="mcps1.1.6.1.4"><p id="p15973165013111"><a name="p15973165013111"></a><a name="p15973165013111"></a>Default Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="37.263726372637265%" id="mcps1.1.6.1.5"><p id="p1774112327488"><a name="p1774112327488"></a><a name="p1774112327488"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1741143284810"><td class="cellrowborder" valign="top" width="18.55185518551855%" headers="mcps1.1.6.1.1 "><p id="p19741103254812"><a name="p19741103254812"></a><a name="p19741103254812"></a>x</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.471647164716472%" headers="mcps1.1.6.1.2 "><p id="p57411832154812"><a name="p57411832154812"></a><a name="p57411832154812"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.771277127712771%" headers="mcps1.1.6.1.3 "><p id="p12678114510313"><a name="p12678114510313"></a><a name="p12678114510313"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.941494149414941%" headers="mcps1.1.6.1.4 "><p id="p997325033116"><a name="p997325033116"></a><a name="p997325033116"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="37.263726372637265%" headers="mcps1.1.6.1.5 "><p id="p1474119322489"><a name="p1474119322489"></a><a name="p1474119322489"></a>X-coordinate of the target point.</p>
    </td>
    </tr>
    <tr id="row97411532144814"><td class="cellrowborder" valign="top" width="18.55185518551855%" headers="mcps1.1.6.1.1 "><p id="p14741193212488"><a name="p14741193212488"></a><a name="p14741193212488"></a>y</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.471647164716472%" headers="mcps1.1.6.1.2 "><p id="p127411332174814"><a name="p127411332174814"></a><a name="p127411332174814"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.771277127712771%" headers="mcps1.1.6.1.3 "><p id="p667811458313"><a name="p667811458313"></a><a name="p667811458313"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.941494149414941%" headers="mcps1.1.6.1.4 "><p id="p597325073116"><a name="p597325073116"></a><a name="p597325073116"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="37.263726372637265%" headers="mcps1.1.6.1.5 "><p id="p137412326481"><a name="p137412326481"></a><a name="p137412326481"></a>Y-coordinate of the target point.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    @Entry
    @Component
    struct LineTo {
      private settings: RenderingContextSettings = new RenderingContextSettings(true,true)
      private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)
      private path2Db: Path2D = new Path2D()
    
      build() {
        Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
          Canvas(this.context)
            .width('100%')
            .height('100%')
            .backgroundColor('#ffff00')
            .onReady(() =>{
              this.path2Db.moveTo(100, 100)
              this.path2Db.lineTo(100, 200)
              this.path2Db.lineTo(200, 200)
              this.path2Db.lineTo(200, 100)
              this.path2Db.closePath()
              this.context.stroke(this.path2Db)
            })
        }
        .width('100%')
        .height('100%')
      }
    }
    ```

    ![](figures/unnaming-(3).png)


## bezierCurveTo<a name="section5704481695"></a>

bezierCurveTo\(cp1x: number, cp1y: number, cp2x: number, cp2y: number, x: number, y: number\): void

Draws a cubic bezier curve on the canvas.

-   Parameters

    <a name="table5241185218495"></a>
    <table><thead align="left"><tr id="row1224175215491"><th class="cellrowborder" valign="top" width="28.51%" id="mcps1.1.6.1.1"><p id="p192411529491"><a name="p192411529491"></a><a name="p192411529491"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="15.989999999999998%" id="mcps1.1.6.1.2"><p id="p4241052154910"><a name="p4241052154910"></a><a name="p4241052154910"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.23%" id="mcps1.1.6.1.3"><p id="p452542112326"><a name="p452542112326"></a><a name="p452542112326"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.76%" id="mcps1.1.6.1.4"><p id="p0586326143220"><a name="p0586326143220"></a><a name="p0586326143220"></a>Default Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="28.51%" id="mcps1.1.6.1.5"><p id="p5241052114911"><a name="p5241052114911"></a><a name="p5241052114911"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row624113524497"><td class="cellrowborder" valign="top" width="28.51%" headers="mcps1.1.6.1.1 "><p id="p6241135213493"><a name="p6241135213493"></a><a name="p6241135213493"></a>cp1x</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.989999999999998%" headers="mcps1.1.6.1.2 "><p id="p22422529499"><a name="p22422529499"></a><a name="p22422529499"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.23%" headers="mcps1.1.6.1.3 "><p id="p1452592123212"><a name="p1452592123212"></a><a name="p1452592123212"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.76%" headers="mcps1.1.6.1.4 "><p id="p1058722611324"><a name="p1058722611324"></a><a name="p1058722611324"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.51%" headers="mcps1.1.6.1.5 "><p id="p172421052114919"><a name="p172421052114919"></a><a name="p172421052114919"></a>X-coordinate of the first parameter of the bezier curve.</p>
    </td>
    </tr>
    <tr id="row924225212492"><td class="cellrowborder" valign="top" width="28.51%" headers="mcps1.1.6.1.1 "><p id="p4242115213499"><a name="p4242115213499"></a><a name="p4242115213499"></a>cp1y</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.989999999999998%" headers="mcps1.1.6.1.2 "><p id="p7242195234910"><a name="p7242195234910"></a><a name="p7242195234910"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.23%" headers="mcps1.1.6.1.3 "><p id="p17525621143214"><a name="p17525621143214"></a><a name="p17525621143214"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.76%" headers="mcps1.1.6.1.4 "><p id="p14587426183211"><a name="p14587426183211"></a><a name="p14587426183211"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.51%" headers="mcps1.1.6.1.5 "><p id="p524211522496"><a name="p524211522496"></a><a name="p524211522496"></a>Y-coordinate of the first parameter of the bezier curve.</p>
    </td>
    </tr>
    <tr id="row1924210522498"><td class="cellrowborder" valign="top" width="28.51%" headers="mcps1.1.6.1.1 "><p id="p624214522499"><a name="p624214522499"></a><a name="p624214522499"></a>cp2x</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.989999999999998%" headers="mcps1.1.6.1.2 "><p id="p15242175214914"><a name="p15242175214914"></a><a name="p15242175214914"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.23%" headers="mcps1.1.6.1.3 "><p id="p185251621163216"><a name="p185251621163216"></a><a name="p185251621163216"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.76%" headers="mcps1.1.6.1.4 "><p id="p75871926133217"><a name="p75871926133217"></a><a name="p75871926133217"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.51%" headers="mcps1.1.6.1.5 "><p id="p524275215490"><a name="p524275215490"></a><a name="p524275215490"></a>X-coordinate of the second parameter of the bezier curve.</p>
    </td>
    </tr>
    <tr id="row1024285214912"><td class="cellrowborder" valign="top" width="28.51%" headers="mcps1.1.6.1.1 "><p id="p3242175211491"><a name="p3242175211491"></a><a name="p3242175211491"></a>cp2y</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.989999999999998%" headers="mcps1.1.6.1.2 "><p id="p624205215497"><a name="p624205215497"></a><a name="p624205215497"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.23%" headers="mcps1.1.6.1.3 "><p id="p9525182173216"><a name="p9525182173216"></a><a name="p9525182173216"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.76%" headers="mcps1.1.6.1.4 "><p id="p5587162653219"><a name="p5587162653219"></a><a name="p5587162653219"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.51%" headers="mcps1.1.6.1.5 "><p id="p124214527499"><a name="p124214527499"></a><a name="p124214527499"></a>Y-coordinate of the second parameter of the bezier curve.</p>
    </td>
    </tr>
    <tr id="row11242175210494"><td class="cellrowborder" valign="top" width="28.51%" headers="mcps1.1.6.1.1 "><p id="p8242185217497"><a name="p8242185217497"></a><a name="p8242185217497"></a>x</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.989999999999998%" headers="mcps1.1.6.1.2 "><p id="p11242125219493"><a name="p11242125219493"></a><a name="p11242125219493"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.23%" headers="mcps1.1.6.1.3 "><p id="p352542118324"><a name="p352542118324"></a><a name="p352542118324"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.76%" headers="mcps1.1.6.1.4 "><p id="p3587112653218"><a name="p3587112653218"></a><a name="p3587112653218"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.51%" headers="mcps1.1.6.1.5 "><p id="p122428527495"><a name="p122428527495"></a><a name="p122428527495"></a>X-coordinate of the end point on the bezier curve.</p>
    </td>
    </tr>
    <tr id="row02433524498"><td class="cellrowborder" valign="top" width="28.51%" headers="mcps1.1.6.1.1 "><p id="p924345217491"><a name="p924345217491"></a><a name="p924345217491"></a>y</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.989999999999998%" headers="mcps1.1.6.1.2 "><p id="p1243135224912"><a name="p1243135224912"></a><a name="p1243135224912"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.23%" headers="mcps1.1.6.1.3 "><p id="p14525132112322"><a name="p14525132112322"></a><a name="p14525132112322"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.76%" headers="mcps1.1.6.1.4 "><p id="p05873264327"><a name="p05873264327"></a><a name="p05873264327"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.51%" headers="mcps1.1.6.1.5 "><p id="p3243135254915"><a name="p3243135254915"></a><a name="p3243135254915"></a>Y-coordinate of the end point on the bezier curve.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    @Entry
    @Component
    struct BezierCurveTo {
      private settings: RenderingContextSettings = new RenderingContextSettings(true,true)
      private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)
      private path2Db: Path2D = new Path2D()
    
      build() {
        Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
          Canvas(this.context)
            .width('100%')
            .height('100%')
            .backgroundColor('#ffff00')
            .onReady(() =>{
              this.path2Db.moveTo(10, 10)
              this.path2Db.bezierCurveTo(20, 100, 200, 100, 200, 20);this.context.stroke(this.path2Db)
            })
        }
        .width('100%')
        .height('100%')
      }
    }
    ```

    ![](figures/en-us_image_0000001192915158.png)


## quadraticCurveTo<a name="section1031101112107"></a>

quadraticCurveTo\(cpx: number, cpy: number, x: number ,y: number\): void

Draws a quadratic curve on the canvas.

-   Parameters

    <a name="table815416567500"></a>
    <table><thead align="left"><tr id="row915445619508"><th class="cellrowborder" valign="top" width="28.51%" id="mcps1.1.6.1.1"><p id="p1815412561507"><a name="p1815412561507"></a><a name="p1815412561507"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.2"><p id="p3154195613509"><a name="p3154195613509"></a><a name="p3154195613509"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.21%" id="mcps1.1.6.1.3"><p id="p1692151183314"><a name="p1692151183314"></a><a name="p1692151183314"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="19.66%" id="mcps1.1.6.1.4"><p id="p22841853333"><a name="p22841853333"></a><a name="p22841853333"></a>Default Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="28.51%" id="mcps1.1.6.1.5"><p id="p6154456135016"><a name="p6154456135016"></a><a name="p6154456135016"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row51543567505"><td class="cellrowborder" valign="top" width="28.51%" headers="mcps1.1.6.1.1 "><p id="p111544569503"><a name="p111544569503"></a><a name="p111544569503"></a>cpx</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.2 "><p id="p1315419563508"><a name="p1315419563508"></a><a name="p1315419563508"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.21%" headers="mcps1.1.6.1.3 "><p id="p109319117331"><a name="p109319117331"></a><a name="p109319117331"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.66%" headers="mcps1.1.6.1.4 "><p id="p8284185163318"><a name="p8284185163318"></a><a name="p8284185163318"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.51%" headers="mcps1.1.6.1.5 "><p id="p10154105675010"><a name="p10154105675010"></a><a name="p10154105675010"></a>X-coordinate of the bezier curve parameter.</p>
    </td>
    </tr>
    <tr id="row4154175618504"><td class="cellrowborder" valign="top" width="28.51%" headers="mcps1.1.6.1.1 "><p id="p1615410566508"><a name="p1615410566508"></a><a name="p1615410566508"></a>cpy</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.2 "><p id="p31540568507"><a name="p31540568507"></a><a name="p31540568507"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.21%" headers="mcps1.1.6.1.3 "><p id="p593111103311"><a name="p593111103311"></a><a name="p593111103311"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.66%" headers="mcps1.1.6.1.4 "><p id="p22841516333"><a name="p22841516333"></a><a name="p22841516333"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.51%" headers="mcps1.1.6.1.5 "><p id="p8154165685013"><a name="p8154165685013"></a><a name="p8154165685013"></a>Y-coordinate of the bezier curve parameter.</p>
    </td>
    </tr>
    <tr id="row11548564504"><td class="cellrowborder" valign="top" width="28.51%" headers="mcps1.1.6.1.1 "><p id="p41551856175018"><a name="p41551856175018"></a><a name="p41551856175018"></a>x</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.2 "><p id="p1515575685013"><a name="p1515575685013"></a><a name="p1515575685013"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.21%" headers="mcps1.1.6.1.3 "><p id="p109319117335"><a name="p109319117335"></a><a name="p109319117335"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.66%" headers="mcps1.1.6.1.4 "><p id="p328475123317"><a name="p328475123317"></a><a name="p328475123317"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.51%" headers="mcps1.1.6.1.5 "><p id="p9155115610507"><a name="p9155115610507"></a><a name="p9155115610507"></a>X-coordinate of the end point on the bezier curve.</p>
    </td>
    </tr>
    <tr id="row1115555665015"><td class="cellrowborder" valign="top" width="28.51%" headers="mcps1.1.6.1.1 "><p id="p18155105685012"><a name="p18155105685012"></a><a name="p18155105685012"></a>y</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.2 "><p id="p20155856135019"><a name="p20155856135019"></a><a name="p20155856135019"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.21%" headers="mcps1.1.6.1.3 "><p id="p99313110338"><a name="p99313110338"></a><a name="p99313110338"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.66%" headers="mcps1.1.6.1.4 "><p id="p1284125103320"><a name="p1284125103320"></a><a name="p1284125103320"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.51%" headers="mcps1.1.6.1.5 "><p id="p5155156125013"><a name="p5155156125013"></a><a name="p5155156125013"></a>Y-coordinate of the end point on the bezier curve.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    @Entry
    @Component
    struct QuadraticCurveTo {
      private settings: RenderingContextSettings = new RenderingContextSettings(true,true)
      private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)
      private path2Db: Path2D = new Path2D()
    
      build() {
        Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
          Canvas(this.context)
            .width('100%')
            .height('100%')
            .backgroundColor('#ffff00')
            .onReady(() =>{
              this.path2Db.moveTo(10, 10)
              this.path2Db.quadraticCurveTo(100, 100, 200, 20)
              this.context.stroke(this.path2Db)
          })
        }
        .width('100%')
        .height('100%')
      }
    }
    ```

    ![](figures/en-us_image_0000001237555151.png)


## arc<a name="section17961639151011"></a>

arc\(x: number, y: number, radius: number, startAngle: number, endAngle: number, anticlockwise?: number\): void

Draws an arc on the canvas.

-   Parameters

    <a name="table1050139185219"></a>
    <table><thead align="left"><tr id="row250129165211"><th class="cellrowborder" valign="top" width="28.51%" id="mcps1.1.6.1.1"><p id="p185016935213"><a name="p185016935213"></a><a name="p185016935213"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.48%" id="mcps1.1.6.1.2"><p id="p250111935212"><a name="p250111935212"></a><a name="p250111935212"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.05%" id="mcps1.1.6.1.3"><p id="p16774837173311"><a name="p16774837173311"></a><a name="p16774837173311"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.45%" id="mcps1.1.6.1.4"><p id="p17003422334"><a name="p17003422334"></a><a name="p17003422334"></a>Default Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="28.51%" id="mcps1.1.6.1.5"><p id="p7501997528"><a name="p7501997528"></a><a name="p7501997528"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row850189195216"><td class="cellrowborder" valign="top" width="28.51%" headers="mcps1.1.6.1.1 "><p id="p175011099524"><a name="p175011099524"></a><a name="p175011099524"></a>x</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.48%" headers="mcps1.1.6.1.2 "><p id="p14501390521"><a name="p14501390521"></a><a name="p14501390521"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.05%" headers="mcps1.1.6.1.3 "><p id="p1977453710330"><a name="p1977453710330"></a><a name="p1977453710330"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.45%" headers="mcps1.1.6.1.4 "><p id="p27004428338"><a name="p27004428338"></a><a name="p27004428338"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.51%" headers="mcps1.1.6.1.5 "><p id="p85027935216"><a name="p85027935216"></a><a name="p85027935216"></a>X-coordinate of the center point of the arc.</p>
    </td>
    </tr>
    <tr id="row350216985214"><td class="cellrowborder" valign="top" width="28.51%" headers="mcps1.1.6.1.1 "><p id="p55026925210"><a name="p55026925210"></a><a name="p55026925210"></a>y</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.48%" headers="mcps1.1.6.1.2 "><p id="p75021291525"><a name="p75021291525"></a><a name="p75021291525"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.05%" headers="mcps1.1.6.1.3 "><p id="p6774173716338"><a name="p6774173716338"></a><a name="p6774173716338"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.45%" headers="mcps1.1.6.1.4 "><p id="p16700164216336"><a name="p16700164216336"></a><a name="p16700164216336"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.51%" headers="mcps1.1.6.1.5 "><p id="p18502193521"><a name="p18502193521"></a><a name="p18502193521"></a>Y-coordinate of the center point of the arc.</p>
    </td>
    </tr>
    <tr id="row2502169185215"><td class="cellrowborder" valign="top" width="28.51%" headers="mcps1.1.6.1.1 "><p id="p150211925210"><a name="p150211925210"></a><a name="p150211925210"></a>radius</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.48%" headers="mcps1.1.6.1.2 "><p id="p550211913528"><a name="p550211913528"></a><a name="p550211913528"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.05%" headers="mcps1.1.6.1.3 "><p id="p3774133713319"><a name="p3774133713319"></a><a name="p3774133713319"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.45%" headers="mcps1.1.6.1.4 "><p id="p1870004220332"><a name="p1870004220332"></a><a name="p1870004220332"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.51%" headers="mcps1.1.6.1.5 "><p id="p13502169135212"><a name="p13502169135212"></a><a name="p13502169135212"></a>Radius of the arc.</p>
    </td>
    </tr>
    <tr id="row550212975211"><td class="cellrowborder" valign="top" width="28.51%" headers="mcps1.1.6.1.1 "><p id="p1350212985217"><a name="p1350212985217"></a><a name="p1350212985217"></a>startAngle</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.48%" headers="mcps1.1.6.1.2 "><p id="p85029985211"><a name="p85029985211"></a><a name="p85029985211"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.05%" headers="mcps1.1.6.1.3 "><p id="p277473783315"><a name="p277473783315"></a><a name="p277473783315"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.45%" headers="mcps1.1.6.1.4 "><p id="p1670020427339"><a name="p1670020427339"></a><a name="p1670020427339"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.51%" headers="mcps1.1.6.1.5 "><p id="p165021920526"><a name="p165021920526"></a><a name="p165021920526"></a>Start radian of the arc.</p>
    </td>
    </tr>
    <tr id="row25022912524"><td class="cellrowborder" valign="top" width="28.51%" headers="mcps1.1.6.1.1 "><p id="p105021912522"><a name="p105021912522"></a><a name="p105021912522"></a>endAngle</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.48%" headers="mcps1.1.6.1.2 "><p id="p150219925218"><a name="p150219925218"></a><a name="p150219925218"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.05%" headers="mcps1.1.6.1.3 "><p id="p4774537113317"><a name="p4774537113317"></a><a name="p4774537113317"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.45%" headers="mcps1.1.6.1.4 "><p id="p1570094216339"><a name="p1570094216339"></a><a name="p1570094216339"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.51%" headers="mcps1.1.6.1.5 "><p id="p550213945213"><a name="p550213945213"></a><a name="p550213945213"></a>End radian of the arc.</p>
    </td>
    </tr>
    <tr id="row250218913526"><td class="cellrowborder" valign="top" width="28.51%" headers="mcps1.1.6.1.1 "><p id="p850216913520"><a name="p850216913520"></a><a name="p850216913520"></a>anticlockwise</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.48%" headers="mcps1.1.6.1.2 "><p id="p1850219914524"><a name="p1850219914524"></a><a name="p1850219914524"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.05%" headers="mcps1.1.6.1.3 "><p id="p1377411371333"><a name="p1377411371333"></a><a name="p1377411371333"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.45%" headers="mcps1.1.6.1.4 "><p id="p9700154210333"><a name="p9700154210333"></a><a name="p9700154210333"></a>false</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.51%" headers="mcps1.1.6.1.5 "><p id="p105031691522"><a name="p105031691522"></a><a name="p105031691522"></a>Whether to draw the arc counterclockwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    @Entry
    @Component
    struct Arc {
      private settings: RenderingContextSettings = new RenderingContextSettings(true,true)
      private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)
      private path2Db: Path2D = new Path2D()
    
      build() {
        Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
          Canvas(this.context)
            .width('100%')
            .height('100%')
            .backgroundColor('#ffff00')
            .onReady(() =>{
              this.path2Db.arc(100, 75, 50, 0, 6.28);this.context.stroke(this.path2Db)
            })
        }
        .width('100%')
        .height('100%')
      }
    }
    ```

    ![](figures/en-us_image_0000001192595214.png)


## arcTo<a name="section172971709119"></a>

arcTo\(x1: number, y1: number, x2: number, y2: number, radius: number\): void

Draws an arc based on the radius and points on the arc.

-   Parameters

    <a name="table584265819528"></a>
    <table><thead align="left"><tr id="row198421584521"><th class="cellrowborder" valign="top" width="28.51%" id="mcps1.1.6.1.1"><p id="p12842115815217"><a name="p12842115815217"></a><a name="p12842115815217"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.96%" id="mcps1.1.6.1.2"><p id="p38431558175217"><a name="p38431558175217"></a><a name="p38431558175217"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.96%" id="mcps1.1.6.1.3"><p id="p53815225340"><a name="p53815225340"></a><a name="p53815225340"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.5%" id="mcps1.1.6.1.4"><p id="p15724182563420"><a name="p15724182563420"></a><a name="p15724182563420"></a>Default Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="31.069999999999997%" id="mcps1.1.6.1.5"><p id="p8843195812520"><a name="p8843195812520"></a><a name="p8843195812520"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row148431358115213"><td class="cellrowborder" valign="top" width="28.51%" headers="mcps1.1.6.1.1 "><p id="p384345875215"><a name="p384345875215"></a><a name="p384345875215"></a>x1</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.96%" headers="mcps1.1.6.1.2 "><p id="p984325805212"><a name="p984325805212"></a><a name="p984325805212"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.96%" headers="mcps1.1.6.1.3 "><p id="p1238622163419"><a name="p1238622163419"></a><a name="p1238622163419"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.1.6.1.4 "><p id="p272482517343"><a name="p272482517343"></a><a name="p272482517343"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="31.069999999999997%" headers="mcps1.1.6.1.5 "><p id="p178438582527"><a name="p178438582527"></a><a name="p178438582527"></a>X-coordinate of the first point on the arc.</p>
    </td>
    </tr>
    <tr id="row1984385813525"><td class="cellrowborder" valign="top" width="28.51%" headers="mcps1.1.6.1.1 "><p id="p16843958185217"><a name="p16843958185217"></a><a name="p16843958185217"></a>y1</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.96%" headers="mcps1.1.6.1.2 "><p id="p168431058165216"><a name="p168431058165216"></a><a name="p168431058165216"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.96%" headers="mcps1.1.6.1.3 "><p id="p13862233412"><a name="p13862233412"></a><a name="p13862233412"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.1.6.1.4 "><p id="p167241725143419"><a name="p167241725143419"></a><a name="p167241725143419"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="31.069999999999997%" headers="mcps1.1.6.1.5 "><p id="p12843205813522"><a name="p12843205813522"></a><a name="p12843205813522"></a>Y-coordinate of the first point on the arc.</p>
    </td>
    </tr>
    <tr id="row88431558115211"><td class="cellrowborder" valign="top" width="28.51%" headers="mcps1.1.6.1.1 "><p id="p88431058105211"><a name="p88431058105211"></a><a name="p88431058105211"></a>x2</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.96%" headers="mcps1.1.6.1.2 "><p id="p1984315875217"><a name="p1984315875217"></a><a name="p1984315875217"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.96%" headers="mcps1.1.6.1.3 "><p id="p1538132215346"><a name="p1538132215346"></a><a name="p1538132215346"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.1.6.1.4 "><p id="p2724172593420"><a name="p2724172593420"></a><a name="p2724172593420"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="31.069999999999997%" headers="mcps1.1.6.1.5 "><p id="p158431558185211"><a name="p158431558185211"></a><a name="p158431558185211"></a>X-coordinate of the second point on the arc.</p>
    </td>
    </tr>
    <tr id="row198431858125217"><td class="cellrowborder" valign="top" width="28.51%" headers="mcps1.1.6.1.1 "><p id="p1484420584525"><a name="p1484420584525"></a><a name="p1484420584525"></a>y2</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.96%" headers="mcps1.1.6.1.2 "><p id="p084495885213"><a name="p084495885213"></a><a name="p084495885213"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.96%" headers="mcps1.1.6.1.3 "><p id="p1638182217349"><a name="p1638182217349"></a><a name="p1638182217349"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.1.6.1.4 "><p id="p10724122553420"><a name="p10724122553420"></a><a name="p10724122553420"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="31.069999999999997%" headers="mcps1.1.6.1.5 "><p id="p1684418583522"><a name="p1684418583522"></a><a name="p1684418583522"></a>Y-coordinate of the second point on the arc.</p>
    </td>
    </tr>
    <tr id="row11844358155211"><td class="cellrowborder" valign="top" width="28.51%" headers="mcps1.1.6.1.1 "><p id="p8844155865219"><a name="p8844155865219"></a><a name="p8844155865219"></a>radius</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.96%" headers="mcps1.1.6.1.2 "><p id="p1984410581525"><a name="p1984410581525"></a><a name="p1984410581525"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.96%" headers="mcps1.1.6.1.3 "><p id="p1238132211346"><a name="p1238132211346"></a><a name="p1238132211346"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.1.6.1.4 "><p id="p872418257346"><a name="p872418257346"></a><a name="p872418257346"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="31.069999999999997%" headers="mcps1.1.6.1.5 "><p id="p17844155815220"><a name="p17844155815220"></a><a name="p17844155815220"></a>Radius of the arc.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    @Entry
    @Component
    struct ArcTo {
      private settings: RenderingContextSettings = new RenderingContextSettings(true,true)
      private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)
      private path2Db: Path2D = new Path2D()
    
      build() {
        Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
          Canvas(this.context)
            .width('100%')
            .height('100%')
            .backgroundColor('#ffff00')
            .onReady(() =>{
              this.path2Db.arcTo(150, 20, 150, 70, 50)
              this.context.stroke(this.path2Db)
            })
        }
        .width('100%')
        .height('100%')
      }
    }
    ```

    ![](figures/en-us_image_0000001192755172.png)


## ellipse<a name="section1144192321119"></a>

ellipse\(x: number, y: number, radiusX: number, radiusY: number, rotation: number, startAngle: number, endAngle: number, anticlockwise?: number\): void

Draws an ellipse in the specified rectangular region.

-   Parameters

    <a name="table51461805541"></a>
    <table><thead align="left"><tr id="row181461109541"><th class="cellrowborder" valign="top" width="22.759999999999998%" id="mcps1.1.6.1.1"><p id="p014716035415"><a name="p014716035415"></a><a name="p014716035415"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.360000000000001%" id="mcps1.1.6.1.2"><p id="p171472055413"><a name="p171472055413"></a><a name="p171472055413"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.120000000000001%" id="mcps1.1.6.1.3"><p id="p19211176153517"><a name="p19211176153517"></a><a name="p19211176153517"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.83%" id="mcps1.1.6.1.4"><p id="p1331191912353"><a name="p1331191912353"></a><a name="p1331191912353"></a>Default Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="39.93%" id="mcps1.1.6.1.5"><p id="p1814718035418"><a name="p1814718035418"></a><a name="p1814718035418"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1114714015418"><td class="cellrowborder" valign="top" width="22.759999999999998%" headers="mcps1.1.6.1.1 "><p id="p81478015543"><a name="p81478015543"></a><a name="p81478015543"></a>x</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.360000000000001%" headers="mcps1.1.6.1.2 "><p id="p71470013548"><a name="p71470013548"></a><a name="p71470013548"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.120000000000001%" headers="mcps1.1.6.1.3 "><p id="p1221110613512"><a name="p1221110613512"></a><a name="p1221110613512"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.83%" headers="mcps1.1.6.1.4 "><p id="p431419173513"><a name="p431419173513"></a><a name="p431419173513"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="39.93%" headers="mcps1.1.6.1.5 "><p id="p714720125410"><a name="p714720125410"></a><a name="p714720125410"></a>X-coordinate of the ellipse center.</p>
    </td>
    </tr>
    <tr id="row1114710018548"><td class="cellrowborder" valign="top" width="22.759999999999998%" headers="mcps1.1.6.1.1 "><p id="p1214718010544"><a name="p1214718010544"></a><a name="p1214718010544"></a>y</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.360000000000001%" headers="mcps1.1.6.1.2 "><p id="p314760175411"><a name="p314760175411"></a><a name="p314760175411"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.120000000000001%" headers="mcps1.1.6.1.3 "><p id="p1211865356"><a name="p1211865356"></a><a name="p1211865356"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.83%" headers="mcps1.1.6.1.4 "><p id="p113116194359"><a name="p113116194359"></a><a name="p113116194359"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="39.93%" headers="mcps1.1.6.1.5 "><p id="p014730105419"><a name="p014730105419"></a><a name="p014730105419"></a>Y-coordinate of the ellipse center.</p>
    </td>
    </tr>
    <tr id="row2147709540"><td class="cellrowborder" valign="top" width="22.759999999999998%" headers="mcps1.1.6.1.1 "><p id="p201478045416"><a name="p201478045416"></a><a name="p201478045416"></a>radiusX</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.360000000000001%" headers="mcps1.1.6.1.2 "><p id="p14147205540"><a name="p14147205540"></a><a name="p14147205540"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.120000000000001%" headers="mcps1.1.6.1.3 "><p id="p192121765354"><a name="p192121765354"></a><a name="p192121765354"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.83%" headers="mcps1.1.6.1.4 "><p id="p163191916356"><a name="p163191916356"></a><a name="p163191916356"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="39.93%" headers="mcps1.1.6.1.5 "><p id="p151475013547"><a name="p151475013547"></a><a name="p151475013547"></a>Ellipse radius on the x-axis.</p>
    </td>
    </tr>
    <tr id="row61474012544"><td class="cellrowborder" valign="top" width="22.759999999999998%" headers="mcps1.1.6.1.1 "><p id="p51477018543"><a name="p51477018543"></a><a name="p51477018543"></a>radiusY</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.360000000000001%" headers="mcps1.1.6.1.2 "><p id="p14148150205416"><a name="p14148150205416"></a><a name="p14148150205416"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.120000000000001%" headers="mcps1.1.6.1.3 "><p id="p19212765350"><a name="p19212765350"></a><a name="p19212765350"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.83%" headers="mcps1.1.6.1.4 "><p id="p7311619193518"><a name="p7311619193518"></a><a name="p7311619193518"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="39.93%" headers="mcps1.1.6.1.5 "><p id="p181481705544"><a name="p181481705544"></a><a name="p181481705544"></a>Ellipse radius on the y-axis.</p>
    </td>
    </tr>
    <tr id="row201484005417"><td class="cellrowborder" valign="top" width="22.759999999999998%" headers="mcps1.1.6.1.1 "><p id="p161483075416"><a name="p161483075416"></a><a name="p161483075416"></a>rotation</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.360000000000001%" headers="mcps1.1.6.1.2 "><p id="p1148502548"><a name="p1148502548"></a><a name="p1148502548"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.120000000000001%" headers="mcps1.1.6.1.3 "><p id="p182128612356"><a name="p182128612356"></a><a name="p182128612356"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.83%" headers="mcps1.1.6.1.4 "><p id="p1331161943510"><a name="p1331161943510"></a><a name="p1331161943510"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="39.93%" headers="mcps1.1.6.1.5 "><p id="p514820005414"><a name="p514820005414"></a><a name="p514820005414"></a>Rotation angle of the ellipse, in radians.</p>
    </td>
    </tr>
    <tr id="row181481704549"><td class="cellrowborder" valign="top" width="22.759999999999998%" headers="mcps1.1.6.1.1 "><p id="p1814850165416"><a name="p1814850165416"></a><a name="p1814850165416"></a>startAngle</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.360000000000001%" headers="mcps1.1.6.1.2 "><p id="p1914815025414"><a name="p1914815025414"></a><a name="p1914815025414"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.120000000000001%" headers="mcps1.1.6.1.3 "><p id="p1221211615358"><a name="p1221211615358"></a><a name="p1221211615358"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.83%" headers="mcps1.1.6.1.4 "><p id="p331219183512"><a name="p331219183512"></a><a name="p331219183512"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="39.93%" headers="mcps1.1.6.1.5 "><p id="p51481906547"><a name="p51481906547"></a><a name="p51481906547"></a>Angle of the start point for drawing the ellipse, in radians.</p>
    </td>
    </tr>
    <tr id="row1148150125412"><td class="cellrowborder" valign="top" width="22.759999999999998%" headers="mcps1.1.6.1.1 "><p id="p131483019542"><a name="p131483019542"></a><a name="p131483019542"></a>endAngle</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.360000000000001%" headers="mcps1.1.6.1.2 "><p id="p14148190155418"><a name="p14148190155418"></a><a name="p14148190155418"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.120000000000001%" headers="mcps1.1.6.1.3 "><p id="p14212126173518"><a name="p14212126173518"></a><a name="p14212126173518"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.83%" headers="mcps1.1.6.1.4 "><p id="p83217194351"><a name="p83217194351"></a><a name="p83217194351"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="39.93%" headers="mcps1.1.6.1.5 "><p id="p1114812095411"><a name="p1114812095411"></a><a name="p1114812095411"></a>Angle of the end point for drawing the ellipse, in radians.</p>
    </td>
    </tr>
    <tr id="row4148206542"><td class="cellrowborder" valign="top" width="22.759999999999998%" headers="mcps1.1.6.1.1 "><p id="p1114817035417"><a name="p1114817035417"></a><a name="p1114817035417"></a>anticlockwise</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.360000000000001%" headers="mcps1.1.6.1.2 "><p id="p3148130105411"><a name="p3148130105411"></a><a name="p3148130105411"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.120000000000001%" headers="mcps1.1.6.1.3 "><p id="p17212186193514"><a name="p17212186193514"></a><a name="p17212186193514"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.83%" headers="mcps1.1.6.1.4 "><p id="p1233919123511"><a name="p1233919123511"></a><a name="p1233919123511"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="39.93%" headers="mcps1.1.6.1.5 "><p id="p914910015410"><a name="p914910015410"></a><a name="p914910015410"></a>Whether to draw the ellipse in the counterclockwise direction. The value <strong id="b18230305015"><a name="b18230305015"></a><a name="b18230305015"></a>0</strong> means to draw the ellipse in the clockwise direction, and <strong id="b11243301405"><a name="b11243301405"></a><a name="b11243301405"></a>1</strong> means to draw the ellipse in the counterclockwise direction. This parameter is optional. The default value is <strong id="b15932059101415"><a name="b15932059101415"></a><a name="b15932059101415"></a>0</strong>.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    @Entry
    @Component
    struct Ellipse {
      private settings: RenderingContextSettings = new RenderingContextSettings(true,true)
      private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)
      private path2Db: Path2D = new Path2D()
    
      build() {
        Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
          Canvas(this.context)
            .width('100%')
            .height('100%')
            .backgroundColor('#ffff00')
            .onReady(() =>{
              this.path2Db.ellipse(200, 200, 50, 100, Math.PI * 0.25, Math.PI * 0.5, Math.PI, true)
              this.context.stroke(this.path2Db)
            })
        }
        .width('100%')
        .height('100%')
      }
    }
    ```

    ![](figures/en-us_image_0000001193075154.png)


## rect<a name="section49087439119"></a>

rect\(x: number, y: number, width: number, height: number\): void

Creates a rectangle.

-   Parameters

    <a name="table92131548185610"></a>
    <table><thead align="left"><tr id="row9238348185613"><th class="cellrowborder" valign="top" width="28.51%" id="mcps1.1.6.1.1"><p id="p723854810561"><a name="p723854810561"></a><a name="p723854810561"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.78%" id="mcps1.1.6.1.2"><p id="p2238144885615"><a name="p2238144885615"></a><a name="p2238144885615"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.750000000000002%" id="mcps1.1.6.1.3"><p id="p19964591352"><a name="p19964591352"></a><a name="p19964591352"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.45%" id="mcps1.1.6.1.4"><p id="p11572146367"><a name="p11572146367"></a><a name="p11572146367"></a>Default Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="28.51%" id="mcps1.1.6.1.5"><p id="p223814486561"><a name="p223814486561"></a><a name="p223814486561"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row5238104813569"><td class="cellrowborder" valign="top" width="28.51%" headers="mcps1.1.6.1.1 "><p id="p1423864816566"><a name="p1423864816566"></a><a name="p1423864816566"></a>x</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.78%" headers="mcps1.1.6.1.2 "><p id="p3238194814560"><a name="p3238194814560"></a><a name="p3238194814560"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.750000000000002%" headers="mcps1.1.6.1.3 "><p id="p199961759123515"><a name="p199961759123515"></a><a name="p199961759123515"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.45%" headers="mcps1.1.6.1.4 "><p id="p35722411369"><a name="p35722411369"></a><a name="p35722411369"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.51%" headers="mcps1.1.6.1.5 "><p id="p9238204818566"><a name="p9238204818566"></a><a name="p9238204818566"></a>X-coordinate of the upper left corner of the rectangle.</p>
    </td>
    </tr>
    <tr id="row1423884816562"><td class="cellrowborder" valign="top" width="28.51%" headers="mcps1.1.6.1.1 "><p id="p132383488563"><a name="p132383488563"></a><a name="p132383488563"></a>y</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.78%" headers="mcps1.1.6.1.2 "><p id="p02395487560"><a name="p02395487560"></a><a name="p02395487560"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.750000000000002%" headers="mcps1.1.6.1.3 "><p id="p1099725973514"><a name="p1099725973514"></a><a name="p1099725973514"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.45%" headers="mcps1.1.6.1.4 "><p id="p8572242364"><a name="p8572242364"></a><a name="p8572242364"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.51%" headers="mcps1.1.6.1.5 "><p id="p523934819568"><a name="p523934819568"></a><a name="p523934819568"></a>Y-coordinate of the upper left corner of the rectangle.</p>
    </td>
    </tr>
    <tr id="row723954815563"><td class="cellrowborder" valign="top" width="28.51%" headers="mcps1.1.6.1.1 "><p id="p182391481565"><a name="p182391481565"></a><a name="p182391481565"></a>width</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.78%" headers="mcps1.1.6.1.2 "><p id="p142391648145610"><a name="p142391648145610"></a><a name="p142391648145610"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.750000000000002%" headers="mcps1.1.6.1.3 "><p id="p89971559153512"><a name="p89971559153512"></a><a name="p89971559153512"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.45%" headers="mcps1.1.6.1.4 "><p id="p65728483617"><a name="p65728483617"></a><a name="p65728483617"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.51%" headers="mcps1.1.6.1.5 "><p id="p523919486569"><a name="p523919486569"></a><a name="p523919486569"></a>Width of the rectangle.</p>
    </td>
    </tr>
    <tr id="row1723924885618"><td class="cellrowborder" valign="top" width="28.51%" headers="mcps1.1.6.1.1 "><p id="p1923934820561"><a name="p1923934820561"></a><a name="p1923934820561"></a>height</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.78%" headers="mcps1.1.6.1.2 "><p id="p13239448135615"><a name="p13239448135615"></a><a name="p13239448135615"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.750000000000002%" headers="mcps1.1.6.1.3 "><p id="p69971159193519"><a name="p69971159193519"></a><a name="p69971159193519"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.45%" headers="mcps1.1.6.1.4 "><p id="p115727413366"><a name="p115727413366"></a><a name="p115727413366"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.51%" headers="mcps1.1.6.1.5 "><p id="p523924819568"><a name="p523924819568"></a><a name="p523924819568"></a>Height of the rectangle.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    @Entry
    @Component
    struct Rect {
      private settings: RenderingContextSettings = new RenderingContextSettings(true,true)
      private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)
      private path2Db: Path2D = new Path2D()
    
      build() {
        Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
          Canvas(this.context)
            .width('100%')
            .height('100%')
            .backgroundColor('#ffff00')
            .onReady(() =>{
              this.path2Db.rect(20, 20, 100, 100);this.context.stroke(this.path2Db)
            })
        }
        .width('100%')
        .height('100%')
      }
    }
    ```

    ![](figures/en-us_image_0000001192755174.png)


