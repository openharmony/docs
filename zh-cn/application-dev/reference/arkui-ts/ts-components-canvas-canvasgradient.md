# CanvasGradient对象<a name="ZH-CN_TOPIC_0000001193075102"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从 API Version 8 开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

渐变对象。

## addColorStop<a name="section12691015917"></a>

addColorStop\(offset: number, color: string\): void

设置渐变断点值，包括偏移和颜色。

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="18.55185518551855%" id="mcps1.1.6.1.1"><p>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.48114811481148%" id="mcps1.1.6.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.440644064406441%" id="mcps1.1.6.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.35103510351035%" id="mcps1.1.6.1.4"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="53.17531753175317%" id="mcps1.1.6.1.5"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="18.55185518551855%" headers="mcps1.1.6.1.1 "><p>offset</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.48114811481148%" headers="mcps1.1.6.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.440644064406441%" headers="mcps1.1.6.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.35103510351035%" headers="mcps1.1.6.1.4 "><p>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="53.17531753175317%" headers="mcps1.1.6.1.5 "><p>设置渐变点距离起点的位置占总体长度的比例，范围为0到1。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="18.55185518551855%" headers="mcps1.1.6.1.1 "><p>color</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.48114811481148%" headers="mcps1.1.6.1.2 "><p>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.440644064406441%" headers="mcps1.1.6.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.35103510351035%" headers="mcps1.1.6.1.4 "><p>'ffffff'</p>
    </td>
    <td class="cellrowborder" valign="top" width="53.17531753175317%" headers="mcps1.1.6.1.5 "><p>设置渐变的颜色。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    @Entry
    @Component
    struct Page45 {
      private settings: RenderingContextSettings = new RenderingContextSettings(true)
      private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)
    
      build() {
        Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
          Canvas(this.context)
            .width('100%')
            .height('100%')
            .backgroundColor('#ffff00')
            .onReady(() =>{
              var grad = this.context.createLinearGradient(50,0, 300,100)
              grad.addColorStop(0.0, 'red')
              grad.addColorStop(0.5, 'white')
              grad.addColorStop(1.0, 'green')
              this.context.fillStyle = grad
              this.context.fillRect(0, 0, 500, 500)
            })
        }
        .width('100%')
        .height('100%')
      }
    }
    ```

    ![](figures/zh-cn_image_0000001192915130.png)


