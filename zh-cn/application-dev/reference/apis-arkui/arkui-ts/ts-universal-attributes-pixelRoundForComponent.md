# 组件级像素取整
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhangwentao96-->
<!--Designer: @fenglinbailu-->
<!--Tester: @liuli0427-->
<!--Adviser: @Brilliantry_Rui-->

组件级像素取整的目标是将像素取整功能作为组件的属性，从而在组件层面实现系统像素取整的开启或关闭。

>  **说明：**
>
> - 本模块从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块接口仅可在Stage模型下使用。

## pixelRound

pixelRound(value: PixelRoundPolicy): T

指定当前组件在指定方向上的像素取整对齐方式，使用后组件边界坐标将按指定策略取整，从而避免因浮点数绘制产生的视觉异常（如1px缝隙、组件重叠、分割线消失）。从API version 12开始，某方向不设置时默认在该方向进行四舍五入取整。

> **说明：**
> 
> - 在API version 11，本接口采用半像素对齐方式（即0\~0.25取0，0.25\~0.75取0.5，0.75\~1.0取1）。该方式通过保留0.5像素值来减少连续取整可能带来的累积误差。从API version 12开始，未设置取整策略的方向默认采用四舍五入的取整方式，并支持通过PixelRoundCalcPolicy.NO_FORCE_ROUND关闭指定方向的像素取整。
>
> - 从API version 12开始，该接口支持在[attributeModifier](ts-universal-attributes-attribute-modifier.md#attributemodifier)中调用。

正常计算时，上下方向与组件高度相对应。在从左到右的布局中，start对应左方向、end对应右方向；在镜像布局（从右到左）中则相反。左右方向与组件宽度相对应。为方便描述将两组方向称为左上和右下。

- 计算当前组件左上角坐标： 左上角相对于父容器偏移量。
- 计算当前组件右下角坐标： 左上角相对于父容器偏移量 + 组件自身尺寸。
- 重新计算当前组件尺寸： 右下角坐标取整 - 左上角坐标取整（API version 11采用半像素对齐方式，API version 12采用四舍五入方式）。

**卡片能力：** 从API version 11开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| value | [PixelRoundPolicy](#pixelroundpolicy) | 是 | 当前组件边界的取整策略。[PixelRoundPolicy](#pixelroundpolicy)包含start、top、end、bottom四个可选属性，分别对应组件前部、上部、尾部、底部边界。每个属性可设置[PixelRoundCalcPolicy](ts-appendix-enums.md#pixelroundcalcpolicy11)枚举值。设置PixelRoundCalcPolicy.NO_FORCE_ROUND可关闭对应方向上的像素取整，未设置的属性默认按四舍五入规则取整。<br>**说明：**<br>该属性用于因浮点数绘制产生视觉异常的场景。从API version 12开始，采用四舍五入的取整方式；API version 11为半像素对齐方式。取整结果不仅和组件的宽高有关，也与组件的位置有关。即使设置的组件宽高相同，由于以浮点数描述的组件位置不同，舍入后组件的最终宽高也可能不同。|

**返回值：**

| 类型 | 说明 |
| --- | --- |
|  T | 返回当前组件，支持链式调用。 |

## PixelRoundPolicy

当前组件边界的取整策略。

**卡片能力：** 从API version 11开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| start | [PixelRoundCalcPolicy](ts-appendix-enums.md#pixelroundcalcpolicy11) |否| 是 | 组件前部边界取整策略。<br>从API version 12开始，默认按四舍五入规则取整。不设置[pixelRound](#pixelround)或者设置PixelRoundCalcPolicy枚举以外的值时采用默认值。|
| top | [PixelRoundCalcPolicy](ts-appendix-enums.md#pixelroundcalcpolicy11) |否| 是 | 组件上部边界取整策略。<br>从API version 12开始，默认按四舍五入规则取整。不设置[pixelRound](#pixelround)或者设置PixelRoundCalcPolicy枚举以外的值时采用默认值。|
| end | [PixelRoundCalcPolicy](ts-appendix-enums.md#pixelroundcalcpolicy11) |否| 是 | 组件尾部边界取整策略。<br>从API version 12开始，默认按四舍五入规则取整。不设置[pixelRound](#pixelround)或者设置PixelRoundCalcPolicy枚举以外的值时采用默认值。|
| bottom | [PixelRoundCalcPolicy](ts-appendix-enums.md#pixelroundcalcpolicy11) |否| 是 | 组件底部边界取整策略。<br>从API version 12开始，默认按四舍五入规则取整。不设置[pixelRound](#pixelround)或者设置PixelRoundCalcPolicy枚举以外的值时采用默认值。|

> **说明：**<br>常见问题的解决方法请参考[常见问题](#常见问题)章节。

## 常见问题

| 问题描述                                                     | 解决方法                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| 子容器100%填充父容器，在偏移量与大小刚好使父容器向上取整而子组件向下取整时，父容器会露出1px。 | 1. 子组件向露出方向采用ceil取整方式。<br>2. 同时关闭父子组件的像素取整。 |
| 使用List组件并设置分割线，在特定场景下分割线消失。           | 1. 在List组件上设置2px的space。<br>2. 关闭相应组件上的像素取整。 |
| 特定设备上出现重叠。                                         | 1. 在List组件上设置2px的space。<br>2. 关闭相应组件上的像素取整。<br>3. 通过@ohos.mediaquery（媒体查询）获取设备的dpi进行定制化适配。 |
| 组件渲染时带有动画且有轻微抖动。                             | 关闭相应组件上的像素取整。                                   |
| 容器内布局紧凑且子组件大小不一致。                           | 关闭相应组件上的像素取整。                                   |

## 示例

当父组件出现1px的缝隙时，应利用pixelRound来指导布局调整。

```ts
@Entry
@Component
struct PixelRoundExample {
    // 状态变量：记录父组件的当前宽度，用于演示浮点数宽度变化
    @State curWidth : number = 300;

    build() {
        Column() {
            Button() {
                Text(this.curWidth.toString())
            }
            .onClick(() => {
                // 每次点击增加0.1px，模拟浮点数宽度
                this.curWidth += 0.1;
            })
            .height(200)
            .width(200)
            .backgroundColor('rgb(213, 213, 213)')

            Blank().height(20)

            Row() {
                // 子组件：100%填充父容器
                Row() {
                }
                .width('100%')
                .height('100%')
                .backgroundColor(Color.Yellow)
                // 关闭子组件start和end方向的像素取整
                .pixelRound({
                    start : PixelRoundCalcPolicy.NO_FORCE_ROUND,
                    end : PixelRoundCalcPolicy.NO_FORCE_ROUND,
                })
            }
            .width(this.curWidth.toString() + 'px')
            .height('300.6px') // 使用浮点数高度测试上下方向的取整表现
            .backgroundColor(Color.Red)
            // 关闭父组件start和end方向的像素取整
            .pixelRound({
                start : PixelRoundCalcPolicy.NO_FORCE_ROUND,
                end : PixelRoundCalcPolicy.NO_FORCE_ROUND,
            })
        }
        .width('100%')
        .height('100%')
        .backgroundColor('#ffe5e5e5')
    }
}
```

在本示例中，父子组件的start和end方向均通过设置PixelRoundCalcPolicy.NO_FORCE_ROUND关闭了像素取整功能。初始状态表现为正常。用户可通过点击按钮来增加父组件的宽度，以此测试在不同浮点数宽度下的表现差异。测试中会发现，当父组件达到特定宽度时，右侧会出现1px的缝隙。同样地，适当调整示例代码后（将start/end替换为top/bottom），也可进行上下方向的测试，以观察类似现象。

**图1** 使用pixelRound指导布局效果图

![image-pixel-round-enable.png](figures/image-pixel-round-enable.png)

**图2** 不使用pixelRound指导布局效果图

![image-pixel-round-disable.png](figures/image-pixel-round-disable.png)
