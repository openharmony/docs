# 自定义组件生命周期回调函数<a name="ZH-CN_TOPIC_0000001110948896"></a>

自定义组件的生命周期回调函数用于通知用户该自定义组件的生命周期，这些回调函数是私有的，在运行时由开发框架在特定的时间进行调用，不能从应用程序中手动调用这些回调函数。

## 生命周期回调函数定义<a name="section1597015432486"></a>

<a name="table56583904911"></a>
<table><thead align="left"><tr id="row146581198495"><th class="cellrowborder" valign="top" width="14.84%" id="mcps1.1.3.1.1"><p id="p19658139114912"><a name="p19658139114912"></a><a name="p19658139114912"></a>函数名</p>
</th>
<th class="cellrowborder" valign="top" width="85.16%" id="mcps1.1.3.1.2"><p id="p06581592499"><a name="p06581592499"></a><a name="p06581592499"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row11658109194919"><td class="cellrowborder" valign="top" width="14.84%" headers="mcps1.1.3.1.1 "><p id="p9658109154912"><a name="p9658109154912"></a><a name="p9658109154912"></a>aboutToAppear</p>
</td>
<td class="cellrowborder" valign="top" width="85.16%" headers="mcps1.1.3.1.2 "><p id="p17851645015"><a name="p17851645015"></a><a name="p17851645015"></a>函数在创建自定义组件的新实例后，在执行其<strong id="b58116885014"><a name="b58116885014"></a><a name="b58116885014"></a>build</strong>函数之前执行。</p>
<p id="p7658596490"><a name="p7658596490"></a><a name="p7658596490"></a>允许在<strong id="b121176287506"><a name="b121176287506"></a><a name="b121176287506"></a>aboutToAppear</strong>函数中改变状态变量，这些更改将在后续执行build函数中生效。</p>
</td>
</tr>
<tr id="row1465811913499"><td class="cellrowborder" valign="top" width="14.84%" headers="mcps1.1.3.1.1 "><p id="p1665939124911"><a name="p1665939124911"></a><a name="p1665939124911"></a>aboutToDisappear</p>
</td>
<td class="cellrowborder" valign="top" width="85.16%" headers="mcps1.1.3.1.2 "><p id="p182511622115113"><a name="p182511622115113"></a><a name="p182511622115113"></a>函数在自定义组件析构消耗之前执行。</p>
<p id="p15659199144918"><a name="p15659199144918"></a><a name="p15659199144918"></a>不允许在<strong id="b164581128165112"><a name="b164581128165112"></a><a name="b164581128165112"></a>aboutToDisappear</strong>函数中改变状态变量，特别是<strong id="b7957050165118"><a name="b7957050165118"></a><a name="b7957050165118"></a>@Link</strong>变量的修改可能会导致应用程序行为不稳定。</p>
</td>
</tr>
<tr id="row1930416179282"><td class="cellrowborder" valign="top" width="14.84%" headers="mcps1.1.3.1.1 "><p id="p1430441792819"><a name="p1430441792819"></a><a name="p1430441792819"></a>onPageShow</p>
</td>
<td class="cellrowborder" valign="top" width="85.16%" headers="mcps1.1.3.1.2 "><p id="p16304131722812"><a name="p16304131722812"></a><a name="p16304131722812"></a>当此页面显示时触发一次。包括路由过程、应用进入前后台等场景，仅@Entry修饰的自定义组件生效。</p>
</td>
</tr>
<tr id="row124040130281"><td class="cellrowborder" valign="top" width="14.84%" headers="mcps1.1.3.1.1 "><p id="p5404191372818"><a name="p5404191372818"></a><a name="p5404191372818"></a>onPageHide</p>
</td>
<td class="cellrowborder" valign="top" width="85.16%" headers="mcps1.1.3.1.2 "><p id="p1740410136287"><a name="p1740410136287"></a><a name="p1740410136287"></a>当此页面消失时触发一次。包括路由过程、应用进入前后台等场景，仅@Entry修饰的自定义组件生效。</p>
</td>
</tr>
<tr id="row914614415143"><td class="cellrowborder" valign="top" width="14.84%" headers="mcps1.1.3.1.1 "><p id="p1420710493489"><a name="p1420710493489"></a><a name="p1420710493489"></a>onBackPress</p>
</td>
<td class="cellrowborder" valign="top" width="85.16%" headers="mcps1.1.3.1.2 "><p id="p1020714916483"><a name="p1020714916483"></a><a name="p1020714916483"></a>当用户点击返回按钮时触发，，仅@Entry修饰的自定义组件生效。</p>
<a name="ul02081949144816"></a><a name="ul02081949144816"></a><ul id="ul02081949144816"><li>返回true表示页面自己处理返回逻辑, 不进行页面路由。</li><li>返回false表示使用默认的返回逻辑。</li><li>不返回值会作为false处理。</li></ul>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section462551935217"></a>

```
@Component
struct CountDownTimerComponent {
    @State countDownFrom: number = 10
    private timerId: number = -1

    private aboutToAppear(): void  {
        this.timerId = setInterval(() => {
            if (this.countDownFrom <= 1) {
                clearTimeout(this.timerId)
            }
            this.countDownFrom -= 1
        }, 1000) // decr counter by 1 every second
    }

    private aboutToDisappear(): void {
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

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>-   允许在生命周期函数中使用**Promise**和异步回调函数，比如网络资源获取，定时器设置等；
>-   不允许在生命周期函数中使用**async await**。

