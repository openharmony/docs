# ImageAnimator

提供帧动画组件来实现逐帧播放图片的能力，可以配置需要播放的图片列表，每张图片可以配置时长。

>  **说明：**
>
> 该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。




## 子组件

无


## 接口

ImageAnimator()


## 属性

| 参数名称     | 参数类型                  | 必填      | 参数描述                   |
| ---------- | ----------------------- | -------- | -------- |
| images     | Array&lt;ImageFrameInfo&gt; | 否   | 设置图片帧信息集合。每一帧的帧信息(ImageFrameInfo)包含图片路径、图片大小、图片位置和图片播放时长信息，详见ImageFrameInfo属性说明。<br/>默认值：[]  |
| state      | [AnimationStatus](ts-appendix-enums.md#animationstatus) | 否    | 默认为初始状态，用于控制播放状态。<br/>默认值：AnimationStatus.Initial |
| duration   | number  | 否    | 单位为毫秒，默认时长为1000ms；duration为0时，不播放图片；值的改变只会在下一次循环开始时生效；当images中任意一帧图片设置了单独的duration后，该属性设置无效。<br/>默认值：1000 |
| reverse    | boolean | 否    | 设置播放顺序。false表示从第1张图片播放到最后1张图片；&nbsp;true表示从最后1张图片播放到第1张图片。<br/>默认值：false |
| fixedSize  | boolean | 否    | 设置图片大小是否固定为组件大小。&nbsp;true表示图片大小与组件大小一致，此时设置图片的width&nbsp;、height&nbsp;、top&nbsp;和left属性是无效的。false表示每一张图片的width&nbsp;、height&nbsp;、top和left属性都要单独设置。<br/>默认值：true |
| preDecode  | number  | 否    | 是否启用预解码，默认值为0，即不启用预解码，如该值设为2，则播放当前页时会提前加载后面两张图片至缓存以提升性能。<br/>默认值：0 |
| fillMode   | [FillMode](ts-appendix-enums.md#fillmode) | 否    | 设置动画开始前和结束后的状态，可选值参见FillMode说明。<br/>默认值：FillMode. Forwards |
| iterations | number  | 否    | 默认播放一次，设置为-1时表示无限次播放。<br/>默认值：1 |

- ImageFrameInfo属性说明

| 参数名称   | 参数类型   | 必填 | 参数描述 |
| -------- | -------------- | -------- | -------- |
| src      | string \| [Resource](ts-types.md#resource)<sup>9+</sup> | 是    | 图片路径，图片格式为svg，png和jpg，从API Version9开始支持[Resource](ts-types.md#resource)类型的路径。|
| width    | [Length](ts-types.md#length)  | 否  | 图片宽度。<br/>默认值：0          |
| height   | [Length](ts-types.md#length)  | 否  | 图片高度。<br/>默认值：0             |
| top      | [Length](ts-types.md#length)  | 否  | 图片相对于组件左上角的纵向坐标。<br/>默认值：0    |
| left     | [Length](ts-types.md#length)  | 否  | 图片相对于组件左上角的横向坐标。<br/>默认值：0    |
| duration | number          | 否     | 每一帧图片的播放时长，单位毫秒。<br/>默认值：0               |


## 事件

| 名称 | 功能描述 |
| -------- | -------- |
| onStart(event:&nbsp;()&nbsp;=&gt;&nbsp;void)  | 状态回调，动画开始播放时触发。 |
| onPause(event:&nbsp;()&nbsp;=&gt;&nbsp;void)  | 状态回调，动画暂停播放时触发。 |
| onRepeat(event:&nbsp;()&nbsp;=&gt;&nbsp;void) | 状态回调，动画重新播放时触发。 |
| onCancel(event:&nbsp;()&nbsp;=&gt;&nbsp;void) | 状态回调，动画取消播放时触发。 |
| onFinish(event:&nbsp;()&nbsp;=&gt;&nbsp;void) | 状态回调，动画播放完成时触发。 |


## 示例

```ts
// xxx.ets
@Entry
@Component
struct ImageAnimatorExample {
  @State state: AnimationStatus = AnimationStatus.Initial
  @State reverse: boolean = false
  @State iterations: number = 1

  build() {
    Column({ space:5 }) {
      ImageAnimator()
        .images([
          { 
            // comment文件夹与pages同级
            src: '/comment/bg1.jpg',
            duration: 500,
            width: 325,
            height: 200,
            top: 0,
            left: 0
          },
          {
            src: '/comment/bg2.jpg',
            duration: 500,
            width: 325,
            height: 200,
            top: 0,
            left: 0
          },
          {
            src: $r('app.media.bg3'),
            duration: 500,
            width: 325,
            height: 200,
            top: 0,
            left: 0
          },
          {
            src: $rawfile('bg4.jpg'),
            duration: 500,
            width: 325,
            height: 200,
            top: 0,
            left: 0
          }
        ])
        .state(this.state).reverse(this.reverse).fixedSize(false).preDecode(2)
        .fillMode(FillMode.None).iterations(this.iterations).width(325).height(210)
        .margin({top:100})
        .onStart(() => { // 当帧动画开始播放后触发
          console.info('Start')
        })
        .onPause(() => {
          console.info('Pause')
        })
        .onRepeat(() => {
          console.info('Repeat')
        })
        .onCancel(() => {
          console.info('Cancel')
        })
        .onFinish(() => { // 当帧动画播放完成后触发
          this.state = AnimationStatus.Stopped
          console.info('Finish')
        })
      Row() {
        Button('start').width(100).padding(5).onClick(() => {
          this.state = AnimationStatus.Running
        })
        Button('pause').width(100).padding(5).onClick(() => {
          this.state = AnimationStatus.Paused
        })
        Button('stop').width(100).padding(5).onClick(() => {
          this.state = AnimationStatus.Stopped
        })
      }
      Row() {
        Button('reverse').width(100).padding(5).onClick(() => {
          this.reverse = !this.reverse
        })
        Button('once').width(100).padding(5).onClick(() => {
          this.iterations = 1
        })
        Button('iteration').width(100).padding(5).onClick(() => {
          this.iterations = -1
        })
      }
    }.width('100%').height('100%').backgroundColor(0xF1F3F5)
  }
}
```

![zh-cn_image_0000001219662643](figures/zh-cn_image_0000001219662643.gif)
