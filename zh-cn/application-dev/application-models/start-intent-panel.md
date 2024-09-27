# 拉起指定类型的应用

## 使用场景
开发者可通过特定的业务类型如导航、金融、邮件等，调用startAbilityByType接口拉起对应的垂域面板，该面板将展示目标方接入的垂域应用，由用户选择打开指定应用以实现相应的垂类意图。垂域面板为调用方提供统一的安全、可信的目标方应用，同时降低调用方的接入成本。  

![](./figures/process-start-intent-panel.png)


## 接口说明

[UIAbilityContext.startAbilityByType](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartabilitybytype11)和[UIExtensionContentSession.startAbilityByType](../reference/apis-ability-kit/js-apis-app-ability-uiExtensionContentSession.md#uiextensioncontentsessionstartabilitybytype11)接口支持基于业务类型拉起垂域面板。调用方通过指定业务类型即可拉起对应的垂域面板，在垂域面板上将展示目标方接入的垂域应用。


系统会根据调用方在startAbilityByType接口传入的type与wantParams.sceneType取值，按照如下映射关系，匹配到在module.json5配置文件中声明了对应[linkFeature](../quick-start/module-configuration-file.md#skills标签)的目标应用。


| 支持的功能 | 调用方（startAbilityByType接口入参）  |  目标方（配置文件linkFeature取值） | 
| ------------ | ------------ |   ------------ |
| 路线规划功能 |- type：navigation <br/> - wantParams.sceneType：1 | RoutePlan |
|导航功能 |- type：navigation <br/> - wantParams.sceneType：2 | Navigation|
|位置搜索功能 |- type：navigation <br/> - wantParams.sceneType：3 | PlaceSearch|
|转账汇款功能 |- type：finance <br/> - wantParams.sceneType：1 |Transfer|
|信用卡还款功能 |- type：finance <br/> - wantParams.sceneType：2 |CreditCardRepayment|
|撰写邮件功能|- type：mail <br/> - wantParams.sceneType：1|ComposeMail|










