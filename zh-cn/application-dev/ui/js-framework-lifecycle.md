# 生命周期
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @mayaolll-->
<!--SE: @jiangdayuan-->
<!--TSE: @lxl007-->

## 应用生命周期

在app.js中可以定义如下应用生命周期函数：

| 属性 | 类型 | 描述 | 触发时机 |
| -------- | -------- | -------- | -------- |
| onCreate | ()&nbsp;=&gt;&nbsp;void | 应用创建 | 当应用创建时调用。 |
| onShow<sup>6+</sup> | ()&nbsp;=&gt;&nbsp;void | 应用处于前台 | 当应用处于前台时触发。 |
| onHide<sup>6+</sup> | ()&nbsp;=&gt;&nbsp;void | 应用处于后台 | 当应用处于后台时触发。 |
| onDestroy | ()&nbsp;=&gt;&nbsp;void | 应用销毁 | 当应用退出时触发。 |


## 页面生命周期

在页面JS文件中可以定义如下页面生命周期函数：

| 属性 | 类型 | 描述 | 触发时机 |
| -------- | -------- | -------- | -------- |
| onInit | ()&nbsp;=&gt;&nbsp;void | 页面初始化 | 页面数据初始化完成时触发，只触发一次。 |
| onReady | ()&nbsp;=&gt;&nbsp;void | 页面创建完成 | 页面创建完成时触发，只触发一次。 |
| onShow | ()&nbsp;=&gt;&nbsp;void | 页面显示 | 页面显示时触发。 |
| onHide | ()&nbsp;=&gt;&nbsp;void | 页面消失 | 页面消失时触发。 |
| onDestroy | ()&nbsp;=&gt;&nbsp;void | 页面销毁 | 页面销毁时触发。 |
| onBackPress | ()&nbsp;=&gt;&nbsp;boolean | 返回按钮动作 | 当用户点击返回按钮时触发。<br/>-&nbsp;返回true表示页面自己处理返回逻辑。<br/>-&nbsp;返回false表示使用默认的返回逻辑。<br/>-&nbsp;不返回值会作为false处理。 |
| onActive()<sup>5+</sup> | ()&nbsp;=&gt;&nbsp;void | 页面激活 | 页面激活时触发。 |
| onInactive()<sup>5+</sup> | ()&nbsp;=&gt;&nbsp;void | 页面暂停 | 页面暂停时触发。 |
| onNewRequest()<sup>5+</sup> | ()&nbsp;=&gt;&nbsp;void | FA重新请求 | FA已经启动时收到新的请求后触发。 |

页面A的生命周期接口的调用顺序
- 打开页面A：onInit() -&gt; onReady() -&gt; onShow()

- 在页面A打开页面B：onHide()

- 从页面B返回页面A：onShow()

- 退出页面A：onBackPress() -&gt; onHide() -&gt; onDestroy()

- 页面隐藏到后台运行：onInactive() -&gt; onHide()

- 页面从后台运行恢复到前台：onShow() -&gt; onActive()

![zh-cn_image_0000001147417424](figures/zh-cn_image_0000001147417424.png)


