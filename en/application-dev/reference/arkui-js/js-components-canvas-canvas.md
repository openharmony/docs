# canvas

The **\<canvas>** component is used for customizing drawings.

## Required Permissions

None

## Child Components

Not supported

## Attributes

Attributes in [Universal Attributes](js-components-common-attributes.md) are supported.

## Styles

Styles in [Universal Styles](js-components-common-styles.md) are supported.

## Events

Events in [Universal Events](js-components-common-events.md) are supported.

## Methods

In addition to the methods in [Universal Methods](js-components-common-methods.md), the following events are supported.

### getContext

getContext(type: '2d', options?: ContextAttrOptions): CanvasRendering2dContext

Obtains the canvas drawing context. This API cannot be called in **onInit** or **onReady**.

- Parameters

  

  | Name      | Type                                                 | Mandatory | Description                                                  |
  | --------- | ---------------------------------------------------- | --------- | ------------------------------------------------------------ |
  | type      | string                                               | Yes       | The value is set to **'2d'**, indicating that a 2D drawing object is returned. This object can be used to draw rectangles, texts, and images on the canvas component. |
  | options6+ | [ContextAttrOptions](js-components-canvas-canvas.md) | No        | Whether to enable anti-aliasing. By default, anti-aliasing is disabled. |

  **Table 1** ContextAttrOptions

  

  | Name      | Type    | Description                                                  |
  | --------- | ------- | ------------------------------------------------------------ |
  | antialias | boolean | Whether to enable anti-aliasing. The default value is **false**. |

- Return values

  

  | Type                                                         | Description                                                  |
  | ------------------------------------------------------------ | ------------------------------------------------------------ |
  | [CanvasRenderingContext2D](js-components-canvas-canvasrenderingcontext2d.md) | 2D drawing object, which can be used to draw rectangles, images, and texts on the canvas component. |

### toDataURL6+

toDataURL(type?: string, quality?: number): string

Generates a URL containing image display information.

- Parameters

  

  | Name    | Type   | Mandatory | Description                                                  |
  | ------- | ------ | --------- | ------------------------------------------------------------ |
  | type    | string | No        | Image format. The default value is **image/png**.            |
  | quality | number | No        | Image quality, which ranges from 0 to 1, when the image format is **image/jpeg** or **image/webp**. If the set value is beyond the value range, the default value **0.92** is used. |

- Return values

  

  | Type   | Description |
  | ------ | ----------- |
  | string | Image URL.  |

## Example

```
<!-- xxx.hml -->
<div>
  <canvas ref="canvas1" style="width: 200px; height: 150px; background-color: #ffff00;"></canvas>
  <input type="button" style="width: 180px; height: 60px;" value="fillStyle" onclick="handleClick" />
</div>
// xxx.js
export default {
  handleClick() {
    const el = this.$refs.canvas1;
    var dataURL = el.toDataURL();
    console.log(dataURL);
    // "data:image/png;base64,xxxxxxxx..."
  }
}
```