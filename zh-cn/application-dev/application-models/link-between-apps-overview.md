# 应用间跳转概述

应用跳转是指从一个应用跳转至另外一个应用，传递相应的数据、执行特定的功能。通过应用跳转可以满足用户更为真实丰富的场景诉求、提升交互体验的便捷性和流畅性。


## 应用跳转的两种类型

根据拉起方应用是否向指定跳转的目标应用，可以将应用跳转分为指向性跳转与通用意图跳转。

- 指向性跳转：拉起方应用明确指定跳转的目标应用，来实现应用跳转。指向性跳转可以分为指定应用链接、指定Ability两种方式。

    - 指定应用链接（推荐）：通过[openLink()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextopenlink12)或[startAbility](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability)接口来指定[应用链接](#应用链接)，拉起目标应用页面。


    - 指定Ability（不推荐）：通过[startAbility](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability)接口指定具体的Ability，显式拉起目标应用页面。

    > 说明：
    >
    > API 11及以前版本，可以使用显式want拉起其他应用。从API 12开始，已不再支持三方应用使用该方式拉起其他应用。

- 通用意图跳转：拉起方应用只申明跳转意图、而不指定具体跳转到哪一个应用，通过调用接口来拉起满足用户意图的垂类应用面板，该面板将展示目标方接入的垂域应用，由用户选择打开指定应用。

    常见的通用意图跳转包括导航、分享、文件打开等高频场景，不同意图类型的跳转实现也有多种方式。

    - [导航](start-intent-panel.md)：支持导航、地点搜索、路线规划
    - [文件打开](file-processing-apps-startup.md)：打开特定类型的文件<!--RP1-->
    <!--RP1End-->

## 应用链接

### URL的基本格式

应用链接是指可以将用户引导至应用内特定位置或相关网页的URL。URL的基本格式如下：
```
scheme://host[:port]/path/
```

- scheme：协议名称。例如http、https等。
- host：域名或IP地址。例如域名`developer.huawei.com`或IP地址`127.0.0.1`；
- port：端口号。例如`developer.huawei.com:80`后面的80即为端口号。
- path：路径，表示域名服务器上的目录或文件路径。例如`developer.huawei.com/consumer/`中`consumer`。

> **说明：**
> 
> 系统应用预留scheme统一以`ohos`开头，例如`ohosclock://`。三方应用组件配置的scheme不能与系统应用重复，否则会导致无法通过该uri拉起三方应用组件。 
> 
> 如果多个应用的URL配置相同，应用跳转时匹配到同多个应用，则会拉起应用选择框。为了更好的用户体验，开发者可以通过链接的path字段去区分同一域名下的不同应用，如链接<https://www.test.com/path1>拉起目标应用1，链接<https://www.test.com/path2>拉起目标应用2。

### 应用链接跳转的运作机制

1. 目标应用在配置文件中注册自己的URL，并对外提供URL。
2. 拉起方应用在跳转接口中传入目标应用的URL等信息。
3. 系统接收到URL等相关信息，会寻找对应匹配项，并跳转至目标应用。


### Deep Linking与App Linking的对比

**Deep Linking**：是一种通过链接跳转至应用特定页面的技术，其特点是支持开发者定义任意形式的scheme。

**App Linking**：是一种特定类型的Deep Linking，其限定了scheme必须为https，同时通过增加域名校验机制，可以从已匹配到的应用中筛选过滤出目标应用，消除应用查询和定位中产生的歧义，直达受信的目标应用。

相比Deep Linking，App Linking具有更高的安全性和可靠性，用户体验更佳，推荐作开发者的首选App Linking方案。

| 类型 | Deep Linking | App Linking |
| -------- | -------- |-------- |
| 实现效果 | - 如果已安装目标应用，将直接拉起目标应用。<br/> - 如果未安装目标应用，将提示16000019错误码。 | - 如果已安装目标应用，将直接拉起目标应用。<br/> - 如果未安装目标应用，会跳转到对应的浏览器来打开网址。 |
| 约束限制 | - URL的Shceme可以自定义。<br/> - 无需校验域名。 | - URL的Shceme必须为https。<br/> - 需要云侧服务器进行域名校验。|
| 安全性 | 缺乏域名校验机制，容易被其他应用所仿冒。| 通过域名校验机制，可以匹配到受信的目标应用。|



## 典型场景：拉起系统应用

拉起系统应用是应用间跳转的一种典型场景。系统提供了一些能力和接口，在确保访问安全的前提下，可以让开发者快捷地实现系统应用跳转，详见[拉起系统应用](system-app-startup.md)。

