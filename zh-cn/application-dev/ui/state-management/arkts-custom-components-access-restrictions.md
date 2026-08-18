# 自定义组件成员属性访问限定符使用限制
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @BlYynNe-->
<!--Designer: @VictorS67-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

在状态管理V1版本中，完成自定义组件封装后，调用方难以明确知晓应传入哪些变量作为组件的输入参数。当组件开发者不希望状态变量被外部初始化时，可以使用private访问限定符来限制当前变量不允许被外部初始化。外部初始化也需要遵循装饰器自身的规则，具体规则见[使用限制](#使用限制)。

ArkTS会对自定义组件的成员变量使用的访问限定符private/public/protected进行校验，当不按规范使用访问限定符private/public/protected时，会产生对应的告警日志。

在阅读本文档前，建议提前阅读：[状态管理概述](./arkts-state-management-overview.md)。

> **说明：**
>
> 从API version 12开始，支持自定义组件成员属性访问限定符使用限制的规则。

## 使用限制

- [\@State](./arkts-state.md)/[\@Prop](./arkts-prop.md)/[\@Provide](./arkts-provide-and-consume.md)/[\@BuilderParam](./arkts-builderparam.md)/常规成员变量(不涉及更新的普通变量)的初始化规则为可以被外部初始化，也可以使用本地值进行初始化。当组件开发者不希望当前变量被外部初始化时，可以使用private进行修饰，在这种情况下，错误进行外部初始化会有编译告警日志提示。

- [\@StorageLink](./arkts-appstorage.md#storagelink)/[\@StorageProp](./arkts-appstorage.md#storageprop)/[\@LocalStorageLink](./arkts-localstorage.md#localstoragelink)/[\@LocalStorageProp](./arkts-localstorage.md#localstorageprop)/[\@Consume](./arkts-provide-and-consume.md)变量的初始化规则为不可以被外部初始化，当组件开发者希望当前变量被外部初始化而使用public修饰时，与装饰器本身的初始化规则不符，会有编译告警日志提示。

- [\@Link](./arkts-link.md)/[\@ObjectLink](./arkts-observed-and-objectlink.md)变量的初始化规则为必须被外部初始化，禁止本地初始化。当组件开发者使用private对变量进行修饰时，与装饰器本身的初始化规则不符，会有编译告警日志提示。

- 由于struct没有继承能力，上述所有的这些变量使用protected修饰时，会有编译告警日志提示。

- [\@Require](./arkts-require.md)含义是当前被\@Require装饰的变量必须被外部初始化，当\@Require装饰器和private访问限定符同时修饰[\@State](./arkts-state.md)/[\@Prop](./arkts-prop.md)/[\@Provide](./arkts-provide-and-consume.md)/[\@BuilderParam](./arkts-builderparam.md)装饰的变量或常规成员变量(不涉及更新的普通变量)时，它们的含义是自相矛盾的，会有编译告警日志提示。

## 使用场景

1. 当成员变量被private访问限定符和\@State/\@Prop/\@Provide/\@BuilderParam装饰器同时修饰，并且通过父组件进行初始化赋值，ArkTS会进行校验并产生告警日志。

   【反例】
    <!-- @[LinkWithPrivate_ErrorCase](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Restrictions/entry/src/main/ets/pages/linkWithPrivate/LinkWithPrivateErrorCase.ets) -->
    
    ``` TypeScript
    @Entry
    @Component
    struct LinkErrorAccessRestrictions {
      @Builder
      buildTest() {
        Text('Parent builder')
      }
    
      build() {
        Column() {
          LinkErrorComponentChild({
            stateValue: 'Hello',
            propValue: 'Hello',
            provideValue: 'Hello',
            builderValue: this.buildTest,
            regularValue: 'Hello'
          })
        }
        .width('100%')
      }
    }
    
    @Component
    struct LinkErrorComponentChild {
      // 此处使用private修饰符时会出现告警日志
      @State private stateValue: string = 'Hello';
      // 此处使用private修饰符时会出现告警日志
      @Prop private propValue: string = 'Hello';
      // 此处使用private修饰符时会出现告警日志
      @Provide private provideValue: string = 'Hello';
      // 此处使用private修饰符时会出现告警日志
      @BuilderParam private builderValue: () => void = this.buildTest;
      // 此处使用private修饰符时会出现告警日志
      private regularValue: string = 'Hello';
    
      @Builder
      buildTest() {
        Text('Child builder')
      }
    
      build() {
        Column() {
          Text('Hello')
            .fontSize(50)
            .fontWeight(FontWeight.Bold)
        }
      }
    }
    ```


    编译告警日志如下：

    ```ts
    Property 'stateValue' is private and can not be initialized through the component constructor.
    Property 'propValue' is private and can not be initialized through the component constructor.
    Property 'provideValue' is private and can not be initialized through the component constructor.
    Property 'builderValue' is private and can not be initialized through the component constructor.
    Property 'regularValue' is private and can not be initialized through the component constructor.
    ```

   【正例】
    <!-- @[LinkWithPrivate_CorrectCase](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Restrictions/entry/src/main/ets/pages/linkWithPrivate/LinkWithPrivateCorrectCase.ets) --> 
    
    ``` TypeScript
    @Entry
    @Component
    struct LinkAccessRestrictions {
      @Builder
      buildTest() {
        Text('Parent builder')
      }
    
      build() {
        Column() {
          LinkComponentChild({
            stateValue: 'Hello',
            propValue: 'Hello',
            provideValue: 'Hello',
            builderValue: this.buildTest,
            regularValue: 'Hello'
          })
        }
        .width('100%')
      }
    }
    
    @Component
    struct LinkComponentChild {
      // 正确用法
      @State stateValue: string = 'Hello';
      @Prop propValue: string = 'Hello';
      @Provide provideValue: string = 'Hello';
      @BuilderParam builderValue: () => void = this.buildTest;
      regularValue: string = 'Hello';
    
      @Builder
      buildTest() {
        Text('Child builder')
      }
    
      build() {
        Column() {
          Text('Hello')
            .fontSize(50)
            .fontWeight(FontWeight.Bold)
        }
      }
    }
    ```

2. 当成员变量被public访问限定符和\@StorageLink/\@StorageProp/\@LocalStorageLink/\@LocalStorageProp/\@Consume装饰器同时修饰时，ArkTS会进行校验并产生告警日志。

   【反例】
    <!-- @[PublicWithStorageProp_ErrorCase](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Restrictions/entry/src/main/ets/pages/publicWithStorageProp/PublicWithStoragePropErrorCase.ets) -->
    
    ``` TypeScript
    @Entry
    @Component
    struct PublicErrorAccessRestrictions {
      @Provide consumeValue: string = 'Hello';
    
      build() {
        Column() {
          PublicErrorComponentChild()
        }
        .width('100%')
      }
    }
    
    @Component
    struct PublicErrorComponentChild {
      // 此处使用public修饰符时会出现告警日志
      @LocalStorageProp('sessionLocalProp') public localPropValue: string = 'Hello';
      // 此处使用public修饰符时会出现告警日志
      @LocalStorageLink('sessionLocalLink') public localLinkValue: string = 'Hello';
      // 此处使用public修饰符时会出现告警日志
      @StorageProp('sessionProp') public storagePropValue: string = 'Hello';
      // 此处使用public修饰符时会出现告警日志
      @StorageLink('sessionLink') public storageLinkValue: string = 'Hello';
      // 此处使用public修饰符时会出现告警日志
      @Consume public consumeValue: string;
    
      build() {
        Column() {
          Text('Hello')
            .fontSize(50)
            .fontWeight(FontWeight.Bold)
        }
      }
    }
    ```


   编译告警日志如下：

    ```ts
    Property 'localPropValue' can not be decorated with both '@LocalStorageProp' and public.
    Property 'localLinkValue' can not be decorated with both '@LocalStorageLink' and public.
    Property 'storagePropValue' can not be decorated with both '@StorageProp' and public.
    Property 'storageLinkValue' can not be decorated with both '@StorageLink' and public.
    Property 'consumeValue' can not be decorated with both '@Consume' and public.
    ```

   【正例】
    <!-- @[PublicWithStorageProp_CorrectCase](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Restrictions/entry/src/main/ets/pages/publicWithStorageProp/PublicWithStoragePropCorrectCase.ets) --> 
    
    ``` TypeScript
    @Entry
    @Component
    struct PublicCorrectAccessRestrictions {
      @Provide consumeValue: string = 'Hello';
    
      build() {
        Column() {
          PublicCorrectComponentChild()
        }
        .width('100%')
      }
    }
    
    @Component
    struct PublicCorrectComponentChild {
      // 正确用法
      @LocalStorageProp('sessionLocalProp') localPropValue: string = 'Hello';
      @LocalStorageLink('sessionLocalLink') localLinkValue: string = 'Hello';
      @StorageProp('sessionProp') storagePropValue: string = 'Hello';
      @StorageLink('sessionLink') storageLinkValue: string = 'Hello';
      @Consume consumeValue: string;
    
      build() {
        Column() {
          Text('Hello')
            .fontSize(50)
            .fontWeight(FontWeight.Bold)
        }
      }
    }
    ```

3. 当成员变量被private访问限定符和\@Link/\@ObjectLink装饰器同时修饰时，ArkTS会进行校验并产生告警日志。

   【反例】
    <!-- @[PrivateWithLink_ErrorCase](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Restrictions/entry/src/main/ets/pages/privateWithLink/PrivateWithLinkErrorCase.ets) -->
    
    ``` TypeScript
    @Entry
    @Component
    struct PrivateWithLinkErrorAccessRestrictions {
      @State linkValue: string = 'Hello';
      @State objectLinkValue: PrivateErrorComponentObj = new PrivateErrorComponentObj();
    
      build() {
        Column() {
          PrivateWithLinkErrorComponentChild({ linkValue: this.linkValue, objectLinkValue: this.objectLinkValue })
        }
        .width('100%')
      }
    }
    
    @Observed
    class PrivateErrorComponentObj {
      public count: number = 0;
    }
    
    @Component
    struct PrivateWithLinkErrorComponentChild {
      // 此处使用private修饰符时会出现告警日志
      @Link private linkValue: string;
      // 此处使用private修饰符时会出现告警日志
      @ObjectLink private objectLinkValue: PrivateErrorComponentObj;
    
      build() {
        Column() {
          Text('Hello')
            .fontSize(50)
            .fontWeight(FontWeight.Bold)
        }
      }
    }
    ```

   编译告警日志如下：

    ```ts
    Property 'linkValue' can not be decorated with both '@Link' and private.
    Property 'objectLinkValue' can not be decorated with both '@ObjectLink' and private.
    ```

   【正例】
    <!-- @[PrivateWithLink_CorrectCase](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Restrictions/entry/src/main/ets/pages/privateWithLink/PrivateWithLinkCorrectCase.ets) --> 
    
    ``` TypeScript
    @Entry
    @Component
    struct PrivateWithLinkAccessRestrictions {
      // 正确用法
      @State linkValue: string = 'Hello';
      @State objectLinkValue: PrivateComponentObj = new PrivateComponentObj();
    
      build() {
        Column() {
          PrivateWithLinkComponentChild({ linkValue: this.linkValue, objectLinkValue: this.objectLinkValue })
        }
        .width('100%')
      }
    }
    
    @Observed
    class PrivateComponentObj {
      public count: number = 0;
    }
    
    @Component
    struct PrivateWithLinkComponentChild {
      @Link linkValue: string;
      @ObjectLink objectLinkValue: PrivateComponentObj;
    
      build() {
        Column() {
          Text('Hello')
            .fontSize(50)
            .fontWeight(FontWeight.Bold)
        }
      }
    }
    ```

4. 当成员变量被protected访问限定符修饰时，ArkTS会进行校验并产生告警日志。

   【反例】
   <!-- @[ProtectedInStruct_ErrorCase](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Restrictions/entry/src/main/ets/pages/protectedInStruct/ProtectedInStructErrorCase.ets) -->
   
   ``` TypeScript
   @Entry
   @Component
   struct ProtectedErrorAccessRestrictions {
     build() {
       Column() {
         ProtectedErrorComponentChild({ regularValue: 'Hello' })
       }
       .width('100%')
     }
   }
   
   @Component
   struct ProtectedErrorComponentChild {
     // 此处使用protected修饰符时会出现告警日志
     protected regularValue: string = 'Hello';
   
     build() {
       Column() {
         Text('Hello')
           .fontSize(50)
           .fontWeight(FontWeight.Bold)
       }
     }
   }
   ```


   编译告警日志如下：

    ```ts
    The member attributes of a struct can not be protected.
    ```

   【正例】
    <!-- @[ProtectedInStruct_CorrectCase](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Restrictions/entry/src/main/ets/pages/protectedInStruct/ProtectedInStructCorrectCase.ets) --> 
    
    ``` TypeScript
    @Entry
    @Component
    struct ProtectedCorrectAccessRestrictions {
      build() {
        Column() {
          ProtectedCorrectComponentChild({ regularValue: 'Hello' })
        }
        .width('100%')
      }
    }
    
    @Component
    struct ProtectedCorrectComponentChild {
      // 正确用法
      regularValue: string = 'Hello';
    
      build() {
        Column() {
          Text('Hello')
            .fontSize(50)
            .fontWeight(FontWeight.Bold)
        }
      }
    }
    ```


5. 当成员变量被private访问限定符、\@Require和@State/@Prop/@Provide/@BuilderParam装饰器同时修饰时，ArkTS会进行校验并产生告警日志。

   【反例】
    <!-- @[PrivateWithRequire_ErrorCase](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Restrictions/entry/src/main/ets/pages/privateWithRequire/PrivateWithRequireErrorCase.ets) -->
    
    ``` TypeScript
    @Entry
    @Component
    struct PrivateErrorAccessRestrictions {
      build() {
        Column() {
          PrivateErrorComponentChild({ propValue: 'Hello' })
        }
        .width('100%')
      }
    }
    
    @Component
    struct PrivateErrorComponentChild {
      // 此处使用private修饰符时会出现告警日志
      @Require @Prop private propValue: string = 'Hello';
    
      build() {
        Column() {
          Text('Hello')
            .fontSize(50)
            .fontWeight(FontWeight.Bold)
        }
      }
    }
    ```


   编译告警日志如下：

    ```ts
    Property 'propValue' can not be decorated with both '@Require' and private.
    Property 'propValue' is private and can not be initialized through the component constructor.
    ```

   【正例】
    <!-- @[PrivateWithRequire_CorrectCase](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Restrictions/entry/src/main/ets/pages/privateWithRequire/PrivateWithRequireCorrectCase.ets) --> 
    
    ``` TypeScript
    @Entry
    @Component
    struct PrivateCorrectAccessRestrictions {
      build() {
        Column() {
          PrivateCorrectComponentChild({ propValue: 'Hello' })
        }
        .width('100%')
      }
    }
    
    @Component
    struct PrivateCorrectComponentChild {
      // 正确用法
      @Require @Prop propValue: string = 'Hello';
    
      build() {
        Column() {
          Text('Hello')
            .fontSize(50)
            .fontWeight(FontWeight.Bold)
        }
      }
    }
    ```
