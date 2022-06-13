# Image

**Image** allows you to add an image.

## Attributes



| Name    | Type     | Default Value | Mandatory | Description                                                  |
| ------- | -------- | ------------- | --------- | ------------------------------------------------------------ |
| src     | string   | -             | Yes       | Image resource path.                                         |
| width   | \<length> | 0px           | No        | Image width.                                                 |
| height  | \<length> | 0px           | No        | Image height.                                                |
| onload  | Function | -             | No        | Called when an image is successfully loaded. This function has no parameter. |
| onerror | Function | -             | No        | Called when an image fails to be loaded. This function has no parameter. |

## Example

```
<!-- xxx.hml -->
<div>
  <canvas ref="canvas" style="width: 500px; height: 500px; "></canvas>
</div>
//xxx.js
export default {
  onShow(){
    const el =this.$refs.canvas
    var ctx =el.getContext('2d');
    var img = new Image();
    img.src = 'common/images/example.jpg';
    img.onload = function() {
    console.log('Image load success');
    ctx.drawImage(img, 0, 0, 360, 250);
   };
    img.onerror = function() {
    console.log('Image load fail');
    };
  }
}
```

![img](https://gitee.com/openharmony/docs/raw/OpenHarmony-3.1-Release/en/application-dev/reference/arkui-js/figures/1-9.png)