# CanvasGradient

**CanvasGradient** provides a gradient object.

## addColorStop

addColorStop(offset: number, color: string): void

Adds a color stop for the** CanvasGradient** object based on the specified offset and gradient color.

- Parameters

  

  | Name   | Type   | Description                                                  |
  | ------ | ------ | ------------------------------------------------------------ |
  | offset | number | Proportion of the distance between the color stop and the start point to the total length. The value ranges from 0 to 1. |
  | color  | string | Gradient color to set.                                       |

- Example Code

  ```
  <!-- xxx.hml -->
  <div>
    <canvas ref="canvas" style="width: 500px; height: 500px; background-color: #ffff00;"></canvas>
    <input type="button" style="width: 180px; height: 60px;" value="fillStyle" onclick="handleClick" />
  </div>
  ```

  ```
  // xxx.js
  export default {
    handleClick() {
      const el =this.$refs.canvas;
      const ctx =el.getContext('2d');
      const gradient = ctx.createLinearGradient(0,0,100,0);
      gradient.addColorStop(0,'#00ffff');
      gradient.addColorStop(1,'#ffff00');
    }
  }
  ```

  ![img](figures/en-us_image_0000001152610806.png)