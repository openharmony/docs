# ArkUI子系统Changelog

## cl.arkui.1 弹窗类组件适配系统窗口安全区

**访问级别**

公开接口

**变更原因**

系统类型窗口下，弹窗类组件未避让安全区，导致弹窗显示内容与状态栏、导航条发生重叠

**变更影响**

该变更不涉及应用适配

变更前：系统类型窗口下，弹窗类组件未避让安全区，显示内容与状态栏、导航条重叠

变更后：系统类型窗口下，弹窗类组件避让安全区，显示内容与状态栏、导航条不重叠


| 组件 | 变更前 | 变更后 |
| :---: | :---: | :---: |
| Menu (无预览图) | <img width=150px src="figures/avoidSafeArea/menu1_1.png"> <br> <img width=150px src="figures/avoidSafeArea/menu2_1.png"> | <img width=150px src="figures/avoidSafeArea/menu1_2.png"> <br> <img width=150px src="figures/avoidSafeArea/menu2_2.png"> |
| Menu (有预览图) | <img width=150px src="figures/avoidSafeArea/menu3_1.png"> <br> <img width=150px src="figures/avoidSafeArea/menu4_1.png"> | <img width=150px src="figures/avoidSafeArea/menu3_2.png"> <br> <img width=150px src="figures/avoidSafeArea/menu4_2.png"> |
| Popup | <img width=150px src="figures/avoidSafeArea/popup1_1.png"> <br> <img width=150px src="figures/avoidSafeArea/popup2_1.png"> | <img width=150px src="figures/avoidSafeArea/popup1_2.png"> <br> <img width=150px src="figures/avoidSafeArea/popup2_2.png"> |
| Dialog | <img width=150px src="figures/avoidSafeArea/dialog1_1.png"> <br> <img width=150px src="figures/avoidSafeArea/dialog2_1.png"> | <img width=150px src="figures/avoidSafeArea/dialog1_2.png"> <br> <img width=150px src="figures/avoidSafeArea/dialog2_2.png"> |
| Toast | <img width=150px src="figures/avoidSafeArea/toast1_1.png"> <br> <img width=150px src="figures/avoidSafeArea/toast2_1.png"> | <img width=150px src="figures/avoidSafeArea/toast1_2.png"> <br> <img width=150px src="figures/avoidSafeArea/toast2_2.png"> |

**起始API Level**

Menu: API 7

Popup: API 7

Dialog: API 7

Toast: API 9

**变更发生版本**

从OpenHarmony SDK 5.1.0.50开始。

**变更的接口/组件**

Menu组件、Dialog组件、Popup组件、Toast组件。

**适配指导**

默认避让行为变更，无需适配，但应注意变更后的默认效果是否符合开发者预期，如不符合则应自定义修改效果控制变量以达到预期。