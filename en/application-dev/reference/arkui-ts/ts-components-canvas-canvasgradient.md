# CanvasGradient<a name="EN-US_TOPIC_0000001193075102"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

**CanvasGradient**  provides a gradient object.

## addColorStop<a name="section12691015917"></a>

addColorStop\(offset: number, color: string\): void

Adds a color stop for the  **CanvasGradient**  object based on the specified offset and gradient color.

-   Parameters

    <a name="table1032173253712"></a>
    <table><thead align="left"><tr id="row166643263712"><th class="cellrowborder" valign="top" width="18.55185518551855%" id="mcps1.1.6.1.1"><p id="p1966932123714"><a name="p1966932123714"></a><a name="p1966932123714"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.48114811481148%" id="mcps1.1.6.1.2"><p id="p10661232173710"><a name="p10661232173710"></a><a name="p10661232173710"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.440644064406441%" id="mcps1.1.6.1.3"><p id="p1613216534368"><a name="p1613216534368"></a><a name="p1613216534368"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.35103510351035%" id="mcps1.1.6.1.4"><p id="p1435194883610"><a name="p1435194883610"></a><a name="p1435194883610"></a>Default Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="53.17531753175317%" id="mcps1.1.6.1.5"><p id="p66673283719"><a name="p66673283719"></a><a name="p66673283719"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1166193243714"><td class="cellrowborder" valign="top" width="18.55185518551855%" headers="mcps1.1.6.1.1 "><p id="p96673263717"><a name="p96673263717"></a><a name="p96673263717"></a>offset</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.48114811481148%" headers="mcps1.1.6.1.2 "><p id="p1674323372"><a name="p1674323372"></a><a name="p1674323372"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.440644064406441%" headers="mcps1.1.6.1.3 "><p id="p213216535366"><a name="p213216535366"></a><a name="p213216535366"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.35103510351035%" headers="mcps1.1.6.1.4 "><p id="p17436194873615"><a name="p17436194873615"></a><a name="p17436194873615"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="53.17531753175317%" headers="mcps1.1.6.1.5 "><p id="p12672326374"><a name="p12672326374"></a><a name="p12672326374"></a>Proportion of the distance between the color stop and the start point to the total length. The value ranges from 0 to 1.</p>
    </td>
    </tr>
    <tr id="row146783253715"><td class="cellrowborder" valign="top" width="18.55185518551855%" headers="mcps1.1.6.1.1 "><p id="p46773203715"><a name="p46773203715"></a><a name="p46773203715"></a>color</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.48114811481148%" headers="mcps1.1.6.1.2 "><p id="p1967173213712"><a name="p1967173213712"></a><a name="p1967173213712"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.440644064406441%" headers="mcps1.1.6.1.3 "><p id="p1813214531367"><a name="p1813214531367"></a><a name="p1813214531367"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.35103510351035%" headers="mcps1.1.6.1.4 "><p id="p94361648183610"><a name="p94361648183610"></a><a name="p94361648183610"></a>'ffffff'</p>
    </td>
    <td class="cellrowborder" valign="top" width="53.17531753175317%" headers="mcps1.1.6.1.5 "><p id="p1467123233710"><a name="p1467123233710"></a><a name="p1467123233710"></a>Gradient color to set.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    @Entry
    @Component
    struct Page45 {
      private settings: RenderingContextSettings = new RenderingContextSettings(true,true)
      private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)
      private gra:CanvasGradient = new CanvasGradient()
    
      build() {
        Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
          Canvas(this.context)
            .width('100%')
            .height('100%')
            .backgroundColor('#ffff00')
            .onReady(() =>{
              var grad = this.context.createLinearGradient(50,0, 300,100)
              this.gra.addColorStop(0.0, 'red')
              this.gra.addColorStop(0.5, 'white')
              this.gra.addColorStop(1.0, 'green')
              this.context.fillStyle = grad
              this.context.fillRect(0, 0, 500, 500)
            })
        }
        .width('100%')
        .height('100%')
      }
    }
    ```

    ![](figures/en-us_image_0000001192915130.png)


