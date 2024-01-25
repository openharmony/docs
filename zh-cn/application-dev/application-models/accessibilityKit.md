# Accessibility Kit简介

“Accessibility”译作“信息无障碍”，是指任何人在任何情况下都能平等、方便地获取信息并利用信息。其目的是缩小全社会不同阶层、不同地区、不同年龄、不同健康状况的人群在信息理解、信息交互、信息利用方面的数字鸿沟，使其更加方便地参与社会生活，享受数字发展带来的便利。

Accessibility Kit（无障碍开发服务）提供扩展服务的开放能力，三方可基于此开放能力开发出类似读屏软件的扩展服务，同时也为三方应用提供开放能力，使三方应用可以更好的适配扩展服务，以更好的服务于障碍人群和障碍场景。例如利用读屏软件，用户可以“听见”当前屏幕内容。

## 能力范围

1、为三方应用提供获取扩展服务列表、扩展服务启用状态、发送无障碍事件等能力。

2、为扩展服务提供扩展服务框架，允许三方开发类似读屏软件的扩展服务。

## 框架原理

无障碍扩展服务框架提供在三方应用和和扩展服务之间交换信息的标准机制。扩展服务通过AAkit向AAMS发出查询或操作请求，AAMS通过ASACkit向三方应用执行查询或操作请求，并将执行结果返回给扩展服务。

![AccessibilityFramework](figures/AccessibilityFramework.png)

1. Accessibility App：基于无障碍扩展服务框架开发的扩展服务，如视障用户使用的读屏App。
2. Tartget App：被Accessibility App辅助的三方应用。
3. AccessibilityAbilityManagerService（AAMS）：无障碍扩展服务框架主服务，用于对Accessibility App生命周期进行管理，同时为Accessibility App和Target App提供信息交互的桥梁。
4. AccessibilityAbility（AAkit）：Accessibility App利用AAkit构建扩展服务Ability运行环境，并为Accessibility App提供可查询和操作Target App的接口，如查询节点信息、对节点执行点击/长按操作等。
5. AccessibilitySystemAbilityClient（ASACkit）：Target App通过ASACkit向AAMS发送无障碍事件，如内容变化事件等，同时响应Accessibility App通过AAMS请求的指令，如查询节点信息、对节点执行点击/长按操作等。
