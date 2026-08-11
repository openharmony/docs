# 全屏模态转场
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hehongyang3-->
<!--Designer: @hehongyang3-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->

通过bindContentCover属性为组件绑定全屏模态页面，在模态页面显示和隐藏时可通过设置转场参数（ModalTransition或TransitionEffect）显示过渡动效。

>  **说明：**
>
> - 从API version 10开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 本模块接口仅可在Stage模型下使用。
>
> - 不支持横竖屏切换。
>
> - 不支持路由跳转。

## bindContentCover

bindContentCover(isShow: boolean, builder: CustomBuilder, type?: ModalTransition): T

给组件绑定全屏模态页面，通过isShow参数控制模态页面的显示与隐藏。模态页面内容自定义，显示方式可设置无动画转场、上下切换转场以及透明度渐变转场。

> **说明：**
>
> 该接口不支持在[attributeModifier](ts-universal-attributes-attribute-modifier.md#attributemodifier)中调用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名  | 类型                                        | 必填 | 说明                                                         |
| ------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| isShow  | boolean                        | 是   | 是否显示全屏模态页面。<br>-true：显示全屏模态页面。<br>-false：隐藏全屏模态页面。<br>从API version 10开始，该参数支持[$$](../../../ui/state-management/arkts-two-way-sync.md)双向绑定变量。<br>从API version 18开始，该参数支持[!!](../../../ui/state-management/arkts-new-binding.md#系统组件参数双向绑定)双向绑定变量。|
| builder | [CustomBuilder](ts-types.md#custombuilder8) | 是   | 配置全屏模态页面内容。builder中的根节点需唯一。<!--RP1--><!--RP1End-->                           |
| type | [ModalTransition](ts-universal-attributes-sheet-transition.md#modaltransition) | 否   | 全屏模态页面的系统转场方式。<br>取值原则：DEFAULT-上下切换过渡，NONE-无动画过渡，ALPHA-透明渐变过渡。<br> 默认值：ModalTransition.DEFAULT，即上下切换过渡。<br>**说明：**<br> 与transition同时设置时，此属性不生效，仅transition生效。                                 |

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| T | 返回当前组件，用于链式调用。 |

## bindContentCover

bindContentCover(isShow: boolean, builder: CustomBuilder, options?: ContentCoverOptions): T

给组件绑定全屏模态页面，通过isShow参数控制模态页面的显示与隐藏。模态页面内容与转场方式均可自定义设置。

> **说明：**
>
> 该接口不支持在[attributeModifier](ts-universal-attributes-attribute-modifier.md#attributemodifier)中调用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名  | 类型                                        | 必填 | 说明                                                         |
| ------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| isShow  | boolean                        | 是   | 是否显示全屏模态页面。<br>-true：显示全屏模态页面。<br>-false：隐藏全屏模态页面。<br>从API version 10开始，该参数支持[$$](../../../ui/state-management/arkts-two-way-sync.md)双向绑定变量。<br>从API version 18开始，该参数支持[!!](../../../ui/state-management/arkts-new-binding.md#系统组件参数双向绑定)双向绑定变量。|
| builder | [CustomBuilder](ts-types.md#custombuilder8) | 是   | 配置全屏模态页面内容。                                       |
| options | [ContentCoverOptions](#contentcoveroptions) | 否 | 配置全屏模态页面的可选属性。不传入此参数时，各可选属性使用各自默认值。 |

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| T | 返回当前组件，用于链式调用。 |

## ContentCoverOptions
继承自[BindOptions](ts-universal-attributes-sheet-transition.md#bindoptions)。

全屏模态页面内容选项。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称              | 类型                                       | 只读 |  可选   | 说明            |
| --------------- | ---------------------------------------- | ---- | ---- | ------------- |
| modalTransition | [ModalTransition](ts-universal-attributes-sheet-transition.md#modaltransition) | 否 | 是    | 全屏模态页面的系统转场方式。<br>取值原则：DEFAULT-上下切换过渡，NONE-无动画过渡，ALPHA-透明渐变过渡。<br> 默认值：ModalTransition.DEFAULT。<br>**说明：**<br> 与transition同时设置时，此属性不生效，仅transition生效。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。  |
| onWillDismiss<sup>12+</sup> | [Callback](./ts-types.md#callback12)&lt;[DismissContentCoverAction](#dismisscontentcoveraction12类型说明)&gt; | 否 | 是   | 全屏模态页面交互式关闭回调函数。<br>**说明：**<br>当用户通过返回键等操作触发关闭全屏模态页面时，如果注册该回调函数，则不会立刻关闭。在回调函数中可以通过reason得到拦截关闭页面的操作类型，从而根据原因选择是否关闭全屏模态页面。如需关闭，须在回调中调用DismissContentCoverAction.dismiss()方法；如不调用dismiss()，全屏模态页面将保持打开状态不会关闭。在onWillDismiss回调中，不能再做onWillDismiss拦截。 <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| transition<sup>12+</sup> | [TransitionEffect](ts-transition-animation-component.md#transitioneffect10对象说明) | 否 | 是   | 全屏模态页面的自定义转场方式。<br>**说明：**<br>未设置时默认不使用自定义转场，使用modalTransition的系统转场方式，与modalTransition同时设置时，仅transition生效，modalTransition属性不生效。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| enableSafeArea<sup>20+</sup> | boolean  | 否 | 是  | 全屏模态是否适配安全区域，true表示全屏模态适配安全区域，将内容限制在安全区域内，避让导航条和状态栏，false表示不适配安全区域，全屏模态页面内容不受安全区域限制，不避让导航条和状态栏，不做处理，和之前的样式保持一致。默认值为false。  <br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。 |

## DismissContentCoverAction<sup>12+</sup>类型说明

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称              | 类型                                       | 只读 | 可选   | 说明            |
| --------------- | -------------------- | -------------------- | ---- | ------------- |
| dismiss | [Callback](./ts-types.md#callback12)\<void> | 否 | 否    | 全屏模态页面关闭回调函数。须在onWillDismiss回调中调用此方法以关闭全屏模态页面；未调用时，全屏模态页面将保持打开状态不关闭。 |
| reason | [DismissReason](ts-universal-attributes-popup.md#dismissreason12枚举说明) | 否 | 否    | 返回本次拦截全屏模态页面退出的事件原因。  |

## 示例

### 示例1（使用全屏模态转场）

该示例主要演示通过bindContentCover来实现全屏模态转场。

```ts
// xxx.ets
@Entry
@Component
struct ModalTransitionExample {
  @State isShow: boolean = false;
  @State isShow2: boolean = false;

  @Builder
  myBuilder2() {
    Column() {
      Button('close modal 2')
        .margin(10)
        .fontSize(20)
        .onClick(() => {
          this.isShow2 = false;
        })
    }
    .width('100%')
    .height('100%')
  }

  @Builder
  myBuilder() {
    Column() {
      Button("transition modal 2")
        .margin(10)
        .fontSize(20)
        .onClick(() => {
          this.isShow2 = true;
        }).bindContentCover(this.isShow2, this.myBuilder2(), {
        modalTransition: ModalTransition.NONE,
        backgroundColor: Color.Orange,
        onWillAppear: () => {
          console.info('BindContentCover onWillAppear.');
        },
        onAppear: () => {
          console.info("BindContentCover onAppear.");
        },
        onWillDisappear: () => {
          console.info("BindContentCover onWillDisappear.");
        },
        onDisappear: () => {
          console.info("BindContentCover onDisappear.");
        }
      })

      Button("close modal 1")
        .margin(10)
        .fontSize(20)
        .onClick(() => {
          this.isShow = false;
        })
    }
    .width('100%')
    .height('100%')
    .justifyContent(FlexAlign.Center)
  }

  build() {
    Column() {
      Button("transition modal 1")
        .onClick(() => {
          this.isShow = true;
        })
        .fontSize(20)
        .margin(10)
        .bindContentCover(this.isShow, this.myBuilder(), {
          modalTransition: ModalTransition.NONE,
          backgroundColor: Color.Pink,
          onWillAppear: () => {
            console.info("BindContentCover onWillAppear.");
          },
          onAppear: () => {
            console.info("BindContentCover onAppear.");
          },
          onWillDisappear: () => {
            console.info("BindContentCover onWillDisappear.");
          },
          onDisappear: () => {
            console.info("BindContentCover onDisappear.");
          }
        })
    }
    .justifyContent(FlexAlign.Center)
    .backgroundColor("#ff49c8ab")
    .width('100%')
    .height('100%')
  }
}
```

![fullScreenModalNone1](figures/fullScreenModalNone1.gif)

### 示例2（自定义转场动画）

全屏模态无动画转场模式下，自定义转场动画。

```ts
// xxx.ets
import { curves } from '@kit.ArkUI';

@Entry
@Component
struct ModalTransitionExample {
  @State @Watch("isShow1Change") isShow: boolean = false;
  @State @Watch("isShow2Change") isShow2: boolean = false;
  @State scale1: number = 1;
  @State scale2: number = 1;

  isShow1Change() {
    this.isShow ? this.scale1 = 0.95 : this.scale1 = 1;
  }

  isShow2Change() {
    this.isShow2 ? this.scale2 = 0.95 : this.scale2 = 1;
  }

  @Builder
  myBuilder2() {
    Column() {
      Button('close modal 2')
        .margin(10)
        .fontSize(20)
        .onClick(() => {
          this.isShow2 = false;
        })
    }
    .width('100%')
    .height('100%')
  }

  @Builder
  myBuilder() {
    Column() {
      Button('transition modal 2')
        .margin(10)
        .fontSize(20)
        .onClick(() => {
          this.isShow2 = true;
        }).bindContentCover(this.isShow2, this.myBuilder2(), {
        modalTransition: ModalTransition.NONE,
        backgroundColor: Color.Orange,
        onWillAppear: () => {
          console.info("BindContentCover onWillAppear.");
        },
        onAppear: () => {
          console.info("BindContentCover onAppear.");
        },
        onWillDisappear: () => {
          console.info("BindContentCover onWillDisappear.");
        },
        onDisappear: () => {
          console.info("BindContentCover onDisappear.");
        }
      })

      Button('close modal 1')
        .margin(10)
        .fontSize(20)
        .onClick(() => {
          this.isShow = false;
        })
    }
    .width('100%')
    .height('100%')
    .justifyContent(FlexAlign.Center)
    .scale({ x: this.scale2, y: this.scale2 })
    .animation({ curve: curves.springMotion() })
  }

  build() {
    Column() {
      Button("transition modal 1")
        .onClick(() => {
          this.isShow = true;
        })
        .fontSize(20)
        .margin(10)
        .bindContentCover(this.isShow, this.myBuilder(), {
          modalTransition: ModalTransition.NONE,
          backgroundColor: Color.Pink,
          onWillAppear: () => {
            console.info("BindContentCover onWillAppear.");
          },
          onAppear: () => {
            console.info("BindContentCover onAppear.");
          },
          onWillDisappear: () => {
            console.info("BindContentCover onWillDisappear.");
          },
          onDisappear: () => {
            console.info("BindContentCover onDisappear.");
          }
        })
    }
    .justifyContent(FlexAlign.Center)
    .backgroundColor("#ff49c8ab")
    .width('100%')
    .height('100%')
    .scale({ x: this.scale1, y: this.scale1 })
    .animation({ curve: curves.springMotion() })
  }
}
```

![fullScreenModalNone2](figures/fullScreenModalNone2.gif)

### 示例3（上下切换转场）

全屏模态上下切换转场。

```ts
// xxx.ets
@Entry
@Component
struct ModalTransitionExample {
  @State isShow: boolean = false;
  @State isShow2: boolean = false;

  @Builder
  myBuilder2() {
    Column() {
      Button('close modal 2')
        .margin(10)
        .fontSize(20)
        .onClick(() => {
          this.isShow2 = false;
        })
    }
    .width('100%')
    .height('100%')
  }

  @Builder
  myBuilder() {
    Column() {
      Button('transition modal 2')
        .margin(10)
        .fontSize(20)
        .onClick(() => {
          this.isShow2 = true;
        }).bindContentCover(this.isShow2, this.myBuilder2(), {
        modalTransition: ModalTransition.DEFAULT,
        backgroundColor: Color.Gray,
        onWillAppear: () => {
          console.info("BindContentCover onWillAppear.");
        },
        onAppear: () => {
          console.info("BindContentCover onAppear.");
        },
        onWillDisappear: () => {
          console.info("BindContentCover onWillDisappear.");
        },
        onDisappear: () => {
          console.info("BindContentCover onDisappear.");
        }
      })

      Button('close modal 1')
        .margin(10)
        .fontSize(20)
        .onClick(() => {
          this.isShow = false;
        })
    }
    .width('100%')
    .height('100%')
    .justifyContent(FlexAlign.Center)
  }

  build() {
    Column() {
      Button("transition modal 1")
        .onClick(() => {
          this.isShow = true;
        })
        .fontSize(20)
        .margin(10)
        .bindContentCover(this.isShow, this.myBuilder(), {
          modalTransition: ModalTransition.DEFAULT,
          backgroundColor: Color.Pink,
          onWillAppear: () => {
            console.info("BindContentCover onWillAppear.");
          },
          onAppear: () => {
            console.info("BindContentCover onAppear.");
          },
          onWillDisappear: () => {
            console.info("BindContentCover onWillDisappear.");
          },
          onDisappear: () => {
            console.info("BindContentCover onDisappear.");
          }
        })
    }
    .justifyContent(FlexAlign.Center)
    .backgroundColor(Color.White)
    .width('100%')
    .height('100%')
  }
}
```

![fullScreenModalDefault](figures/fullScreenModalDefault.gif)

### 示例4（透明度渐变转场）

全屏模态透明度渐变转场。

```ts
// xxx.ets
@Entry
@Component
struct ModalTransitionExample {
  @State isShow: boolean = false;
  @State isShow2: boolean = false;

  @Builder
  myBuilder2() {
    Column() {
      Button('close modal 2')
        .margin(10)
        .fontSize(20)
        .onClick(() => {
          this.isShow2 = false;
        })
    }
    .width('100%')
    .height('100%')
    .justifyContent(FlexAlign.Center)
  }

  @Builder
  myBuilder() {
    Column() {
      Button('transition modal 2')
        .margin(10)
        .fontSize(20)
        .onClick(() => {
          this.isShow2 = true;
        }).bindContentCover(this.isShow2, this.myBuilder2(), {
        modalTransition: ModalTransition.ALPHA,
        backgroundColor: Color.Gray,
        onWillAppear: () => {
          console.info("BindContentCover onWillAppear.");
        },
        onAppear: () => {
          console.info("BindContentCover onAppear.");
        },
        onWillDisappear: () => {
          console.info("BindContentCover onWillDisappear.");
        },
        onDisappear: () => {
          console.info("BindContentCover onDisappear.");
        }
      })

      Button('close modal 1')
        .margin(10)
        .fontSize(20)
        .onClick(() => {
          this.isShow = false;
        })
    }
    .width('100%')
    .height('100%')
    .justifyContent(FlexAlign.Center)
  }

  build() {
    Column() {
      Button("transition modal 1")
        .onClick(() => {
          this.isShow = true;
        })
        .fontSize(20)
        .margin(10)
        .bindContentCover(this.isShow, this.myBuilder(), {
          modalTransition: ModalTransition.ALPHA,
          backgroundColor: Color.Pink,
          onWillAppear: () => {
            console.info("BindContentCover onWillAppear.");
          },
          onAppear: () => {
            console.info("BindContentCover onAppear.");
          },
          onWillDisappear: () => {
            console.info("BindContentCover onWillDisappear.");
          },
          onDisappear: () => {
            console.info("BindContentCover onDisappear.");
          }
        })
    }
    .justifyContent(FlexAlign.Center)
    .backgroundColor(Color.White)
    .width('100%')
    .height('100%')
  }
}
```

![fullScreenModalAlpha](figures/fullScreenModalAlpha.gif)

### 示例5（设置不同效果的自定义转场）

该示例主要演示全屏模态旋转、平移等自定义转场。

```ts
// xxx.ets
@Entry
@Component
struct ModalTransitionExample {
  @State isShow: boolean = false;
  @State isShow2: boolean = false;

  @Builder
  myBuilder2() {
    Column() {
      Button("Close Modal 2")
        .margin(10)
        .fontSize(20)
        .onClick(() => {
          this.isShow2 = false;
        })
    }
    .width('100%')
    .height('100%')
    .justifyContent(FlexAlign.Center)
  }

  @Builder
  myBuilder() {
    Column() {
      Button("Transition Modal 2")
        .margin(10)
        .fontSize(20)
        .onClick(() => {
          this.isShow2 = true;
        })
        .bindContentCover(
          this.isShow2,
          this.myBuilder2(),
          {
            modalTransition: ModalTransition.DEFAULT,
            backgroundColor: Color.Gray,
            transition: TransitionEffect.SLIDE.animation({ duration: 5000, curve: Curve.LinearOutSlowIn }),
            // 处理关闭原因后调用dismiss()关闭模态
            onWillDismiss: ((dismissContentCoverAction: DismissContentCoverAction) => {
              if (dismissContentCoverAction.reason === DismissReason.PRESS_BACK) {
                console.info("BindContentCover dismiss reason is back pressed");
              }
              dismissContentCoverAction.dismiss();
            }),
            onAppear: () => {
              console.info("BindContentCover onAppear.");
            },
            // 模态消失时同步状态变量
            onDisappear: () => {
              this.isShow2 = false;
              console.info("BindContentCover onDisappear.");
            }
          })

      Button("Close Modal 1")
        .margin(10)
        .fontSize(20)
        .onClick(() => {
          this.isShow = false;
        })
    }
    .width('100%')
    .height('100%')
    .justifyContent(FlexAlign.Center)
  }

  build() {
    Column() {
      Button("Transition Modal 1")
        .onClick(() => {
          this.isShow = true;
        })
        .fontSize(20)
        .margin(10)
        .bindContentCover(
          this.isShow,
          this.myBuilder(),
          {
            modalTransition: ModalTransition.DEFAULT,
            backgroundColor: Color.Pink,
            transition: TransitionEffect.asymmetric(
              TransitionEffect.OPACITY.animation({ duration: 1100 }).combine(
                TransitionEffect.rotate({ z: 1, angle: 180 }).animation({ delay: 1000, duration: 1000 }))
              ,
              TransitionEffect.OPACITY.animation({ duration: 1200 }).combine(
                TransitionEffect.rotate({ z: 1, angle: 180 }).animation({ duration: 1300 }))
            ),
            onWillDismiss: ((dismissContentCoverAction: DismissContentCoverAction) => {
              if (dismissContentCoverAction.reason === DismissReason.PRESS_BACK) {
                console.info("back pressed");
              }
              dismissContentCoverAction.dismiss();
            }),
            onAppear: () => {
              console.info("BindContentCover onAppear.");
            },
            onDisappear: () => {
              this.isShow = false;
              console.info("BindContentCover onDisappear.");
            }
          })
    }
    .justifyContent(FlexAlign.Center)
    .backgroundColor(Color.White)
    .width('100%')
    .height('100%')
  }
}
```

![fullScreenModalTransition](figures/fullScreenModalTransition.gif)

### 示例6（设置全屏模态适配安全区）

从API version 20开始，该示例主要演示设置enableSafeArea为true后全屏模态适配安全区的内容效果。全屏模态容器的背景色为浅蓝色，内容颜色为灰色，内容在安全区内布局。

```ts
// xxx.ets
@Entry
@Component
struct SafeAreaController {
  @State isShow: boolean = false;
  @State isSafeArea: boolean | undefined = true;
  @State heightMode: string = '100%';

  @Builder
  myBuilder() {
    Column() {
      Column() {
        Button("Content")
          .fontSize(20)
      }
      .width('100%')
      .height('50%')
      .borderRadius(10)
      .borderStyle(BorderStyle.Dotted)
      .borderWidth(2)
      Column() {
        Button("Content")
          .margin({top:340})
          .fontSize(20)
      }
      .width('100%')
      .height('50%')
      .borderRadius(10)
      .borderStyle(BorderStyle.Dotted)
      .borderWidth(2)
    }
    .backgroundColor(Color.Grey)
    .justifyContent(FlexAlign.Center)
    .width('100%')
    .height(this.heightMode)
  }
  build() {
    Column() {
      Button("Open ContentCover")
        .onClick(() => this.isShow = true)
        .fontSize(20)
        .margin(10)
        .bindContentCover(this.isShow, this.myBuilder(), {
          modalTransition: ModalTransition.ALPHA,
          backgroundColor: 0xFF87CEEB,
          // 动态设置安全区域模式
          enableSafeArea: this.isSafeArea
        })
    }
    .justifyContent(FlexAlign.Center)
    .width('100%')
    .height('100%')
  }
}
```

![enableSafeArea](figures/enableSafeArea.png)
