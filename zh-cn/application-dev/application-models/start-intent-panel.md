# 拉起指定类型的应用

## 使用场景
开发者可通过特定的业务类型如导航、金融、邮件等，调用startAbilityByType接口拉起对应的垂域面板，该面板将展示目标方接入的垂域应用，由用户选择打开指定应用以实现相应的垂类意图。垂域面板为调用方提供统一的安全、可信的目标方应用，同时降低调用方的接入成本。  

![](./figures/process-start-intent-panel.png)


## 接口说明

[UIAbilityContext.startAbilityByType](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartabilitybytype11)和[UIExtensionContentSession.startAbilityByType](../reference/apis-ability-kit/js-apis-app-ability-uiExtensionContentSession.md#uiextensioncontentsessionstartabilitybytype11)接口支持基于业务类型拉起垂域面板。调用方通过指定业务类型即可拉起对应的垂域面板，在垂域面板上将展示目标方接入的垂域应用。










