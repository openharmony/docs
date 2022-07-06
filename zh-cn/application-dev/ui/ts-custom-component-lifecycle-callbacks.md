# 自定义组件生命周期回调函数

自定义组件的生命周期回调函数用于通知用户该自定义组件的生命周期，这些回调函数是私有的，在运行时由开发框架在特定的时间进行调用，不能从应用程序中手动调用这些回调函数。


## 生命周期回调函数定义

| 函数名 | 描述 |
| -------- | -------- |
| aboutToAppear | 函数在创建自定义组件的新实例后，在执行其build函数之前执行。允许在aboutToAppear函数中改变状态变量，更改将在后续执行build函数中生效。 |
| aboutToDisappear | 函数在自定义组件析构消耗之前执行。不允许在aboutToDisappear函数中改变状态变量，特别是@Link变量的修改可能会导致应用程序行为不稳定。 |
| onPageShow | 页面显示时触发一次，包括路由过程、应用进入前后台等场景，仅@Entry修饰的自定义组件生效。 |
| onPageHide | 页面消失时触发一次，包括路由过程、应用进入前后台等场景，仅@Entry修饰的自定义组件生效。 |
| onBackPress | 当用户点击返回按钮时触发，仅\@Entry修饰的自定义组件生效。<br/>-&nbsp;返回true表示页面自己处理返回逻辑,&nbsp;不进行页面路由。<br/>-&nbsp;返回false表示使用默认的返回逻辑。<br/>-&nbsp;不返回值会作为false处理。 |


## 示例

```
@Entry
@Component
struct CountDownTimerComponent {
    @State countDownFrom: number = 10
    private timerId: number = -1

    aboutToAppear(): void  {
        this.timerId = setInterval(() => {
            if (this.countDownFrom <= 1) {
                clearTimeout(this.timerId)
            }
            this.countDownFrom -= 1
        }, 1000) // decr counter by 1 every second
    }

    aboutToDisappear(): void {
        if (this.timerId > 0) {
            clearTimeout(this.timerId)
            this.timerId = -1
        }
    }

    build() {
        Text(`${this.countDownFrom} sec left`)
    }
}
```

上述示例表明，生命周期函数对于允许CountDownTimerComponent管理其计时器资源至关重要，类似的函数也包括异步从网络请求加载资源。


> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> - 允许在生命周期函数中使用Promise和异步回调函数，比如网络资源获取，定时器设置等；
> 
> - 不允许在生命周期函数中使用async await。
