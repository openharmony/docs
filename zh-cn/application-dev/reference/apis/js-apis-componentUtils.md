# @ohos.componentUtils (componentUtils)

提供获取组件绘制区域坐标和大小的能力。

> **说明：**
>
> 从API Version 10开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> 本模块功能依赖UI的执行上下文，不可在UI上下文不明确的地方使用，参见[UIContext](./js-apis-arkui-UIContext.md#uicontext)说明。 
>
> 从API version 10开始，可以通过使用UIContext中的[getComponentUtils](./js-apis-arkui-UIContext.md#getcomponentutils)方法获取当前UI上下文关联的ComponentUtils对象。该接口需要在目标组件布局、完成以后获取目标组件区域大小信息，建议在[@ohos.arkui.inspector(布局回调)](js-apis-arkui-inspector.md)接收到布局完成的通知以后使用该接口。

## 导入模块

```js
import componentUtils from '@ohos.componentUtils'
```
## componentUtils.getRectangleById

getRectangleById(id: string): ComponentInfo

根据组件ID获取组件实例对象, 通过组件实例对象将获取的坐标位置和大小同步返回给开发者。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型   | 必填 | 说明       |
| ------ | ------ | ---- | ---------- |
| id     | string | 是   | 指定组件id。 |

**返回值：** 

| 类型   | 说明       |
| ------ | ---------- |
| [ComponentInfo](#componentinfo) | 组件大小、位置、平移缩放旋转及仿射矩阵属性信息。 |

**示例：**

```js
let modePosition = componentUtils.getRectangleById("onClick");
```

## ComponentInfo

| 名称           | 类型             | 说明                         |
| ---------------|------------     | -----------------------------|
| size           | [Size](#size) | 组件大小。                    |
| localOffset    | [Offset](#offset) | 组件相对于父组件信息。         |
| windowOffset   | [Offset](#offset) | 组件相对于窗口信息。           |
| screenOffset   | [Offset](#offset) | 组件相对于屏幕信息。           |
| translate      | [TranslateResult](#translateresult) | 组件平移信息。                |
| scale          | [ScaleResult](#scaleresult) | 组件缩放信息。                |
| rotate         | [RotateResult](#rotateresult) | 组件旋转信息。                |
| transform      | [Matrix4Result](#matrix4result) | 仿射矩阵信息，根据入参创建的四阶矩阵对象。  |

### Size 

| 名称     | 类型 | 说明                               |
| -------- | ---- | ----------------------------------|
| width    | number | 组件宽度。                         |
| height   | number | 组件高度。                         |

### Offset

| 名称     | 类型 | 说明                               |
| --------| ---- | -----------------------------------|
| x       | number | x点坐标。                           |
| y       | number | y点坐标。                           |

### TranslateResult

| 名称     | 类型 | 说明                               |
| --------| ---- | -----------------------------------|
| x       | number | x轴平移距离。                       |
| y       | number | y轴平移距离。                       |
| z       | number | z轴平移距离。                       |

### ScaleResult

| 名称     | 类型 | 说明                               |
| --------| ---- | -----------------------------------|
| x       | number | x轴缩放倍数。                       |
| y       | number | y轴缩放倍数。                       |
| z       | number | z轴缩放倍数。                       |
| centerX | number | 变换中心点x轴坐标。                  |
| centerY | number | 变换中心点y轴坐标。。                |

### RotateResult

| 名称     | 类型 | 说明                               |
| --------| ---- | -----------------------------------|
| x       | number | 旋转轴向量x坐标。                   |
| y       | number | 旋转轴向量y坐标。                   |
| z       | number | 旋转轴向量z坐标。                   |
| angle   | number | 旋转角度。                          |
| centerX | number | 变换中心点x轴坐标。                 |
| centerY | number | 变换中心点y轴坐标。                 |

### Matrix4Result

| 名称     | 类型 | 说明                               |
| --------| ---- | -----------------------------------|
| number  | number | x轴缩放值，单位矩阵默认为1。         |
| number  | number | 第2个值，xyz轴旋转会影响这个值。 |
| number  | number | 第3个值，xyz轴旋转会影响这个值。 |
| number  | number | 无实际意义。                        |
| number  | number | 第5个值，xyz轴旋转会影响这个值。 |
| number  | number | y轴缩放值，单位矩阵默认为1。          |
| number  | number | 第7个值，xyz轴旋转会影响这个值。 |
| number  | number | 无实际意义。                        |
| number  | number | 第9个值，xyz轴旋转会影响这个值。 |
| number  | number | 第10个值，xyz轴旋转会影响这个值。 |
| number  | number | z轴缩放值，单位矩阵默认为1。         |
| number  | number | 无实际意义。                       |
| number  | number | x轴平移值，单位矩阵默认为0。  |
| number  | number | y轴平移值，单位矩阵默认为0。 |
| number  | number | z轴平移值，单位矩阵默认为0。 |
| number  | number | 齐次坐标下生效，产生透视投影效果。   |

**示例：**

  ```js
import matrix4 from '@ohos.matrix4';
import componentUtils from '@ohos.componentUtils';

@Entry
@Component
struct Utils{
  private getComponentRect(key) {
    console.info("Mode Key: " + key);
    let modePosition = componentUtils.getRectangleById(key);

    let localOffsetWidth = modePosition.size.width;
    let localOffsetHeight = modePosition.size.height;
    let localOffsetX = modePosition.localOffset.x;
    let localOffsetY = modePosition.localOffset.y;

    let windowOffsetX = modePosition.windowOffset.x;
    let windowOffsetY = modePosition.windowOffset.y;

    let screenOffsetX = modePosition.screenOffset.x;
    let screenOffsetY = modePosition.screenOffset.y;

    let translateX = modePosition.translate.x;
    let translateY = modePosition.translate.y;
    let translateZ = modePosition.translate.z;

    let scaleX = modePosition.scale.x;
    let scaleY = modePosition.scale.y;
    let scaleZ = modePosition.scale.z;
    let scaleCenterX = modePosition.scale.centerX;
    let scaleCenterY = modePosition.scale.centerY;

    let rotateX = modePosition.rotate.x;
    let rotateY = modePosition.rotate.y;
    let rotateZ = modePosition.rotate.z;
    let rotateCenterX = modePosition.rotate.centerX;
    let rotateCenterY = modePosition.rotate.centerY;
    let rotateAngle = modePosition.rotate.angle;

    let Matrix4_1 = modePosition.transform[0];
    let Matrix4_2 = modePosition.transform[1];
    let Matrix4_3 = modePosition.transform[2];
    let Matrix4_4 = modePosition.transform[3];
    let Matrix4_5 = modePosition.transform[4];
    let Matrix4_6 = modePosition.transform[5];
    let Matrix4_7 = modePosition.transform[6];
    let Matrix4_8 = modePosition.transform[7];
    let Matrix4_9 = modePosition.transform[8];
    let Matrix4_10 = modePosition.transform[9];
    let Matrix4_11 = modePosition.transform[10];
    let Matrix4_12 = modePosition.transform[11];
    let Matrix4_13 = modePosition.transform[12];
    let Matrix4_14 = modePosition.transform[13];
    let Matrix4_15 = modePosition.transform[14];
    let Matrix4_16 = modePosition.transform[15];
    console.info("[getRectangleById] current component obj is: " + modePosition );
  }
  @State x: number = 120;
  @State y: number = 10;
  @State z: number = 100;
  private matrix1 = matrix4.identity().translate({ x: this.x, y: this.y, z: this.z });
  build() {
    Column() {
        Image($r("app.media.icon"))
          .transform(this.matrix1)
          .translate({ x: 100, y: 10, z: 50})
          .scale({ x: 2, y: 0.5, z: 1 })
          .rotate({
            x: 1,
            y: 1,
            z: 1,
            centerX: '50%',
            centerY: '50%',
            angle: 300
          })
          .width("40%")
          .height(100)
          .key("image_01")
      Button() {
        Text('getRectangleById').fontSize(40).fontWeight(FontWeight.Bold);
      }.margin({ top: 20 })
      .onClick(() => {
        this.getComponentRect("image_01");
      }).id('onClick');
    }
  }
}
  ```