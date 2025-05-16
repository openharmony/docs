# 动画样式


组件支持通过style或css设置动态的旋转、平移及缩放效果。


| 名称                        | 类型                                 | 默认值         | 描述                                       |
| ------------------------- | ---------------------------------- | ----------- | ---------------------------------------- |
| transform                 | string                             | -           | 详见表1。                                    |
| animation-name            | string                             | -           | 指定\@keyframes，详见表2。                      |
| animation-delay           | &lt;time&gt;                       | 0           | 定义动画播放的延迟时间。支持的单位为[s(秒)\|ms(毫秒)&nbsp;]，默认单位为ms，格式为：1000ms或1s。 |
| animation-duration        | &lt;time&gt;                       | 0           | 定义一个动画周期。支持的单位为[s(秒)\|ms(毫秒)&nbsp;]，默认单位为ms，格式为：1000ms或1s。<br/>**说明：**<br/>animation-duration&nbsp;样式必须设置，否则时长为&nbsp;0，则不会播放动画。 |
| animation-iteration-count | number&nbsp;&nbsp;\|&nbsp;infinite | 1           | 定义动画播放的次数，默认播放一次，可通过设置为infinite无限次播放。    |
| animation-timing-function | string                             | <br/>linear | 描述动画执行的速度曲线，用于使动画更为平滑。<br/>可选项有：<br/>-&nbsp;linear：表示动画从头到尾的速度都是相同的。<br/>-&nbsp;ease-in：表示动画以低速开始，cubic-bezier(0.42,&nbsp;0.0,&nbsp;1.0,&nbsp;1.0)。<br/>-&nbsp;ease-out：表示动画以低速结束，cubic-bezier(0.0,&nbsp;0.0,&nbsp;0.58,&nbsp;1.0)。<br/>-&nbsp;ease-in-out：表示动画以低速开始和结束，cubic-bezier(0.42,&nbsp;0.0,&nbsp;0.58,&nbsp;1.0)。 |
| animation-fill-mode       | string                             | none        | 指定动画开始和结束的状态：<br/>-&nbsp;none：在动画执行之前和之后都不会应用任何样式到目标上。<br/>-&nbsp;forwards：在动画结束后，目标将保留动画结束时的状态（在最后一个关键帧中定义）。 |


  **表1** transform操作说明

| 名称         | 类型                                   | 描述         |
| ---------- | ------------------------------------ | ---------- |
| translateX | &lt;length&gt;                       | X轴方向平移动画属性 |
| translateY | &lt;length&gt;                       | Y轴方向平移动画属性 |
| rotate     | &lt;deg&gt;&nbsp;\|&nbsp;&lt;rad&gt; | 旋转动画属性     |

>  **说明：**
>
>  轻量级智能穿戴仅支持原始大小的图片进行旋转。


  **表2** \@keyframes属性说明

| 名称               | 类型             | 默认值  | 描述                 |
| ---------------- | -------------- | ---- | ------------------ |
| background-color | &lt;color&gt;  | -    | 动画执行后应用到组件上的背景颜色。  |
| width            | &lt;length&gt; | -    | 动画执行后应用到组件上的宽度值。   |
| height           | &lt;length&gt; | -    | 动画执行后应用到组件上的高度值。   |
| transform        | string         | -    | 定义应用在组件上的变换类型，见表1。 |


对于不支持起始值或终止值缺省的情况，可以通过from和to显示指定起始和结束。示例：


```css
@keyframes Go
{
   from {
     background-color: #f76160;
   }
   to {
     background-color: #09ba07;
   }
}
```


![动画样式demo1](figures/动画样式demo1.gif)





>  **说明：**
>
>  \@keyframes的from/to不支持动态绑定。
