# 合理处理高负载组件的渲染

## 简介

在应用开发中，有的页面需要在列表中加载大量的数据，就会导致组件数量较多或者嵌套层级较深，从而引起组件负载加重，绘制耗时增长。虽然可以通过组件复用避免组件重复创建，但是如果每个列表项中包含的组件较多，在滑动的时候列表项就会一次性加载大量的数据，可能引起卡顿掉帧等性能问题。

## 问题场景

在日历应用中，需要在一个List里面加载每个月的全部天数，包括公历和农历日期，这样在一个Item中就会有最少58条数据加载，也就相当于需要58个组件。当列表滑动的时候，通过[组件复用](component-recycle.md)的aboutToReuse()接口设置新的数据，就会导致可能有58个组件一起刷新，可能会引起掉帧卡顿现象。

![image-20240507183126622](figures/highly_loaded_component_render_0.gif)

## 解决思路

由于一次性加载大量数据、刷新大量组件会导致卡顿丢帧，那么减少一次性加载的数据量就是一种解决方法。但是由于业务需求，需要加载的数据总量和绘制的组件数量是不能减少的，那么只能想办法将数据进行拆分，将和数据相关的组件分成多次进行绘制。ArkTS中提供了[DisplaySync（可变帧率）](https://developer.huawei.com/consumer/cn/doc/harmonyos-references/js-apis-graphics-displaysync-0000001813575980)，支持开发者设置回调监听，可以在回调里做一些数据的处理，在每一帧中加载少量的数据，减少卡顿或者滑动动画的掉帧现象。

## 优化示例

### 常规代码

通常情况下，会在aboutToReuse()中设置新的数据，并一次性绘制所有的组件。

```ts
@Entry
@Component
struct Direct {
  ...
  // 初始化日历中一年的数据
  initCalenderData() {
    ...
  }

  aboutToAppear() {
	...
    this.initCalenderData();
  }

  build() {
    Column() {
      ...
      List() {
        LazyForEach(this.contentData, (monthItem: Month) => {
          // 每个月的日期
          ListItem() {
            ItemView({
              monthItem: monthItem,
              currentMonth: this.currentMonth,
              currentDay: this.currentDay
            })
            // 根据每月的天数设置复用ID，组件复用时会选择相同ID的组件进行复用
            .reuseId("reuse_id_" + monthItem.days.length.toString())
          }
        })
      }
      ...
  }
}
@Reusable
@Component
struct ItemView {
  @State monthItem: Month = { month: '', num: 0, days: [], lunarDays: [] };
  ...

  aboutToReuse(params: Record<string, Object>): void {
    hiTraceMeter.startTrace("reuse_" + (params.monthItem as Month).month, 1);
    this.monthItem = params.monthItem as Month;
    hiTraceMeter.finishTrace("reuse_" + (params.monthItem as Month).month, 1);
  }

  build() {
    Flex({ wrap: FlexWrap.Wrap }) {
      ...
      // 日期信息
      ForEach(this.monthItem.days, (day: number, index: number) => {
        ...
      }, (index: number): string => index.toString())
    }
    ...
  }
}
```

在上面的代码中，通过组件复用，在ItemView的aboutToReuse()接口中，将一个月的数据直接设置到状态变量monthItem中，这样下面的Flex就会收到状态变量变更的消息通知，从而刷新组件中的数据。编译运行后，进入日历页面，通过[SmartPerf Host工具](performance-optimization-using-smartperf-host.md)，开始抓取Trace，然后滑动列表到最底端，结束Trace的抓取，通过SmartPerf Host对抓取的Trace文件进行分析，选中标签和相关数据区域，可以得到图1。图中三个Actual Timeline标签分别代表应用和RenderService每帧的总耗时、应用每帧的绘制时间和RenderService层每帧的绘制时间，render_service标签表示RenderService层每帧中的绘制操作，example.display标签是应用的bundlename，表示应用在每一帧中的操作，包括创建组件、加载数据等。

图1 组件复用帧率

![image-20240507183017893](figures/highly_loaded_component_render_1.png)

通过图中信息可以看到，滑动期间的帧率是113帧，按照手机120帧来计算，滑动期间掉帧率约为5.8%。放大图1后可以看到，应用每次加载新数据时（图2中橙色部分）RenderService层都会有一帧出现异常情况（图2中黄色部分）。此处对于图中颜色区域的解释，可参考[SmartPerf Host工具](performance-optimization-using-smartperf-host.md)。

图2 绘制耗时

![image-20240507183126622](figures/highly_loaded_component_render_2.png)

将其中一部分继续放大后可以得到图3。选中Actual Timeline（render_service）标签中的146272后，可以通过箭头看到它所关联到的位置是Actual Timeline（example.display）标签中的209136和209137，即RenderService层出现的异常情况是由应用层中前面两帧里面的操作引起的。结合代码和箭头2的标签可以看到，在209135中调用了aboutToReuse接口，此时系统开始了组件复用的绘制操作。通过代码可以看到，在aboutToReuse接口将一个月的所有数据全部放入了当前被复用的组件中，并更新了所有的用于显示日期的Text组件中的数据（箭头3，diffIndexArray.lenght：35，表示有35个不同的元素），这就导致209136需要计算35个子组件的尺寸（箭头1），从而引起146272的绘制时间延长。在列表数据量较少时，其实并不会引起掉帧现象，因为每次延长帧的时间都很短，对帧率的影响较小，但是在列表数据较多时，就会因为延长帧过多，发生掉帧现象。

图3 详细耗时

![image-20240507184557969](figures/highly_loaded_component_render_3.png)

### 优化代码

通过DisplaySync中的帧回调方法，将数据拆分到每一帧中进行加载和绘制。此处只需要修改自定义子组件ItemView中加载数据的方式，所以与常规代码中相同的部分进行了省略。

首先，需要在ItemView中第一次使用时创建DisplaySync对象，设置期望帧率，添加帧回调的监听，然后进行启动。

```ts
@Reusable
@Component
struct ItemView {
  ...
  aboutToAppear(): void {
    // 创建DisplaySync对象
    this.displaySync = displaySync.create();
    // 初始化期望帧率
    let range: ExpectedFrameRateRange = {
      expected: 120,
      min: 60,
      max: 120
    };
    // 设置期望帧率
    this.displaySync.setExpectedFrameRateRange(range);
    // 设置帧回调监听
    this.displaySync.on("frame", () => {
      ...
    });
    // 开启监听帧回调
    this.displaySync.start();
    ...  
  }
  ...
}
```

然后，在监听中添加更新数据的代码。这里将每个月的数据更新拆分开来，第一步用来更新月份数据和计算总的执行步骤，最后一步将计数数据初始化，其余需要执行步骤的多少根据每次加载数据量会有所改变。

```ts
...
private temp: Month[] = [];
...
this.displaySync.on("frame", () => {
  // 数组中有数据时才开始执行
  if (this.temp.length > 0) {
    if (this.step === 0) {
      // 第一步：放入月份数据，并计算最多需要几帧完成数据操作
      hiTraceMeter.startTrace("reuse_" + this.step, 1);
      this.month = this.temp[0].month;
      this.monthNumber = this.temp[0].num;
      this.year = this.temp[0].year;
      this.maxStep = this.maxStep + Math.ceil(this.temp[0].days.length / this.MAX_EVERY_FRAME);
      hiTraceMeter.finishTrace("reuse_" + this.step, 1);
      this.step += 1;
    } else if (this.step === this.maxStep - 1) {
      // 最后一步：初始化部分计数数据
      this.temp.shift();
      this.step = 0;
      this.maxStep = 2;
    } else {
      hiTraceMeter.startTrace("reuse_" + this.step, 1);
      // 计算从所有数据中取值时的开始索引  
      let start: number = this.MAX_EVERY_FRAME * (this.step - 1);
      // 计算从所有数据中取值时的结束索引  
      let end: number = (this.MAX_EVERY_FRAME * this.step) > this.temp[0].days.length ? 
            this.temp[0].days.length : this.MAX_EVERY_FRAME * this.step;
      // 更新日期数据  
      for (let i = start; i < end; i++) {
        this.days[i] = this.temp[0].days[i];
        this.lunarDays[i] = this.temp[0].lunarDays[i];
      }
      hiTraceMeter.finishTrace("reuse_" + this.step, 1);
      this.step += 1;
    }
  }
});
...
```

最后，在aboutToReuse接口中将数据放入数组中，用于帧回调中开始执行数据更新。

```ts
aboutToReuse(params: Record<string, Object>): void {
  hiTraceMeter.startTrace("reuse_" + (params.monthItem as Month).month, 1);
  this.temp.push(params.monthItem as Month);
  hiTraceMeter.finishTrace("reuse_" + (params.monthItem as Month).month, 1);
}
```

编译运行后，使用相同的方法，查看优化后的Trace信息，如图4所示。

图4 优化后帧率

![image-20240507190154885](figures/highly_loaded_component_render_4.png)

从图4中可以看到，通过代码优化后，帧率是正常的120帧了。然后将图4中的Trace结果放大后可以看到图5，RenderService层出现的延长帧（Actual Timeline（render_service）标签中的黄色部分）明显减少了，已经不是优化前每次加载数据都会出现的情况了。

图5 优化后绘制耗时

![image-20240507190741305](figures/highly_loaded_component_render_5.png)

下面将图5中的信息继续放大一些，看一下现在每一帧里都做了什么操作，如图6所示。在211618中，开始调用aboutToReuse接口，由于只是将数据放入一个数组中，并没有更新复用组件中的数据，所以这一帧并没有发生延长现象。在211619中开始逐步更新复用组件中的数据，但是由于前一帧（211618）中并没有更新当前复用组件中的数据，所以在211619中并不需要绘制组件，所以此帧耗时依旧很短。结合代码可以看到，在211620中放入了5天的日期数据，由于前一帧（211619）只是设置了2条数据，并且只有1条会更新组件（this.month = this.temp[0].month会更新显示月份的Text），所以这一帧的绘制时间也不会超时。

图6 优化后详细耗时1

![image-20240507195613210](figures/highly_loaded_component_render_6.png)

继续看后面的Trace信息，如图7所示。和前一帧（211621）一样，此帧中更新了5天的日期数据，并且会重新测量上一帧（211621）中更新数据的5个Text组件尺寸（箭头1），而其余的组件由于数据并没有变动，所以测量被略过了（箭头2）。后面的帧是类似的，每次只会放入5天的数据，并且更新上一帧中设置的数据所关联的Text组件。由于每次更新的组件数量较少，每帧基本上都能在规定的时间内（1秒120帧，即8ms一帧）绘制完成，所以延长帧就会较少。这样不论列表中数据多还是少，都不会引起掉帧现象的发生。

图7 优化后详细耗时2

![image-20240507200236522](figures/highly_loaded_component_render_7.png)

## 总结

通过上面的示例代码和优化过程，可以看到在列表中使用组件复用时，一次性全部加载时可能会引起掉帧。虽然在数据量较少时，单帧绘制的延长并不会引起掉帧，但是数据量变多后，这种延长帧的影响就会比较明显。合理进行数据拆分后，可以有效减少延长帧的发生，从而减少掉帧引起的性能问题。

## 参考链接

[使用SmartPerf-Host分析应用性能](performance-optimization-using-smartperf-host.md)
[DisplaySync 文档](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkgraphics2d/js-apis-graphics-displaySync.md)


## FAQ

**Q：在ItemView中，为什么要给ForEach设置第三个参数？**

A：在组件复用中，如果有用到ForEach，必须设置第三个参数，即给每个数据设置一个key，否则ForEach中添加的组件不会被复用，而是会全部重新创建。

**Q：对List中每一个ListItem的子组件都设置一个DisplaySync的帧回调监听，会不会引起性能问题？**

A：并不会，通过示例中的Trace图可以看到，除了正在被复用的ItemView的DisplaySync的回调监听外，其余的监听耗时非常短，对性能的影响可以忽略不计。如图8所示。

图8 DisplaySync监听耗时

![image-20240507194742115](figures/highly_loaded_component_render_8.png)

**Q：为什么抓取到的Trace中没有示例中那么多的标签？**

A：需要通过hdc shell命令开启标签

```shell
hdc shell
param set persist.ace.debug.enabled 1
param set persist.ace.trace.enabled 1
param set persist.ace.trace.layout.enabled true
param set const.security.developermode.state true
param set persist.ace.trace.build.enabled 1
```

