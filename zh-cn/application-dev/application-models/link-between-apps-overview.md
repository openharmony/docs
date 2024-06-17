# 应用间跳转概述

应用跳转是指从一个应用跳转至另外一个应用，传递相应的数据、执行特定的功能。通过应用跳转可以满足用户更为真实丰富的场景诉求、提升交互体验的便捷性和流畅性。


## 应用跳转的两种类型

根据拉起方应用是否向指定跳转的目标应用，可以将应用跳转分为指向性跳转与通用意图跳转。

- 指向性跳转：拉起方明确指定跳转的目标应用，来实现应用跳转。指向性跳转可以分为指定应用链接、指定Ability两种方式。

    - 指定应用链接（推荐）：通过[openLink()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextopenlink12)或[startAbility](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability)接口来指定[应用链接](#应用链接)，拉起目标应用页面。


    - 指定Ability（不推荐）：通过[startAbility](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability)接口指定具体的Ability，显式拉起目标应用页面。

    > 说明：
    >
    > API 11及以前版本，可以使用显式want拉起其他应用。从API 12开始，已不再支持三方应用使用该方式拉起其他应用。

- 通用意图跳转：拉起方只设置跳转意图、而不指定具体跳转到哪一个应用，通过调用接口来拉起满足用户意图的垂类应用。常见的通用意图跳转包括导航、分享、文件打开等高频场景，不同意图类型的跳转实现也有多种方式。


## 应用链接

### URL的基本格式

应用链接是指可以将用户引导至应用内特定位置或相关网页的URL。URL的基本格式如下：
```
scheme://host[:port]/path/
```

- scheme：协议名称，例如http、https等。
- host：域名或IP地址，例如域名`developer.huawei.com`或IP地址`127.0.0.1`；
- port：端口号，可选。例如`developer.huawei.com:80`后面的80即为端口号。
- path：路径，表示域名服务器上的目录或文件路径，例如`developer.huawei.com/consumer/`中`consumer`。

> 说明：
>
> 系统应用预留scheme统一以`ohos`开头，例如`ohosclock://`。三方应用组件配置的scheme不能与系统应用重复，否则会导致无法通过该uri拉起三方应用组件。

### 应用链接跳转的运作机制

1. 目标应用在配置文件中注册自己的URL，并对外提供URL。
2. 拉起方应用在跳转接口中传入目标应用的URL等信息。
3. 系统接收到URL等相关信息，会寻找对应匹配项，并跳转至目标应用。


### App Linking与Deep Linking的对比

如果多个应用配置了相同域名的URL信息，系统无法判别哪个是受信应用。在匹配应用链接的基础上，通过增加域名校验机制，可以从已匹配到的应用中筛选过滤出目标应用，消除应用查询和定位中产生的歧义，直达受信的目标应用。我们将这种采用域名校验机制的应用跳转方式称为“App Linking”，将未采用域名校验的应用跳转方式称为“Deep Linking”。

相比Deep Linking，App Linking具有更高的安全性和可靠性，用户体验更佳。无论应用是否已安装，App Linking都可以跳转到链接指定的内容。因此，推荐作开发者的首选App Linking方案。

| 类型 | Deep Linking | App Linking |
| -------- | -------- |-------- |
| 实现效果 | - 如果已安装目标应用，在弹出的拉起应用对话框中确认后，将跳转至目标应用。<br/> - 如果未安装目标应用，将提示16000019错误码。 | - 如果已安装目标应用，将直接拉起目标应用。如果未安装目标应用，会跳转到对应的浏览器来打开网址。应用安装完成后，打开应用即可跳转到链接指定内容。 |
| 约束限制 | - URL的Shceme可以自定义。<br/> - 无需校验域名。 | - URL的Shceme必须为https。<br/> - 需要云侧服务器进行域名校验。|
| 跳转接口 | 采用[openLink()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextopenlink12)或[startAbility](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability)接口均可。 | 只能采用[openLink()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextopenlink12)接口。|

> 说明：
>
> 特殊情况下，如果多个应用关联了同一个域名，且URL配置也相同，即存在多个通过域名校验的合法应用，则会拉起应用选择框。


## 典型场景：拉起系统应用

拉起系统应用是应用间跳转的一种典型场景。系统提供了一些能力和接口，在确保访问安全的前提下，可以让开发者快捷地实现系统应用跳转，详见[拉起系统应用](system-app-startup.md)。

