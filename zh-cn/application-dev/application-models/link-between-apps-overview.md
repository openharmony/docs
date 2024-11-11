# 应用间跳转概述

应用跳转是指从一个应用跳转至另外一个应用，传递相应的数据、执行特定的功能。通过应用跳转可以满足用户更为真实丰富的场景诉求、提升交互体验的便捷性和流畅性。

## 应用场景
应用间跳转在社交分享、推广营销等场景广泛使用。举例如下：

- **社交分享：** 在社交软件中分享位置链接/美食推荐链接/购物链接/游戏链接等，可以通过该链接快速跳转到匹配的导航App/美食App/购物App/游戏App等。
- **推广营销：** 在视频类App/社交类App/浏览器App等广告投放平台中，嵌入需要推广的链接（该链接可能以链接、卡片、视频等形式呈现），通过该链接信息可以跳转到目标应用的指定页面；也可以在推送短信、发送邮件时，在正文中携带需要推广的链接，通过该链接信息可以跳转到目标应用的指定页面。


## 应用跳转的两种类型


- [拉起指定应用](app-startup-overview.md)：拉起方应用明确指定跳转的目标应用，来实现应用跳转。指向性跳转可以分为指定应用链接、指定Ability两种方式。

    > **说明：**
    >
    > API 11及以前版本，可以通过指定Ability拉起其他应用。从API 12开始，已不再支持三方应用使用该方式拉起其他应用。本章节重点介绍通过指定应用链接的方式拉起应用。

    - 指定应用链接（推荐）：通过[openLink](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextopenlink12)或[startAbility](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability)接口来指定[应用链接](app-startup-overview.md#应用链接)，拉起目标应用页面。


    - 指定Ability（不推荐）：通过[startAbility](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability)接口指定具体的Ability（即显式Want方式），拉起目标应用页面。



- [拉起指定类型的应用](start-intent-panel.md)：拉起方应用通过指定应用类型，拉起垂类应用面板。该面板将展示目标方接入的垂域应用，由用户选择打开指定应用。




## 典型场景：拉起系统应用

拉起系统应用是应用间跳转的一种典型场景。系统提供了一些能力和接口，在确保访问安全的前提下，可以让开发者快捷地实现系统应用跳转，详见[拉起系统应用](system-app-startup.md)。

