# Constraints on Access Modifiers of Custom Component Member Variables

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @BlYynNe-->
<!--Designer: @VictorS67-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=3efb4ba336409dd0731ba011e1e227786db57fa2 translatedAt=2026-07-22T02:01:31.651Z pushedAt=2026-07-22T06:49:44.496Z -->

In state management V1, after encapsulating a custom component, callers often struggle to clearly identify which variables need to be passed as the component's input parameters. To address this, if you want to prevent a state variable from being initialized externally, you can use the **private** modifier to restrict external initialization of that variable. External initialization must also comply with the decorator's own rules. For details, see [Constraints](#constraints).

ArkTS validates use of the access modifiers – **private**, **public**, and **protected** – for custom component member variables. Build errors will be reported for any incompliance.

Before reading this topic, you are advised to read [State Management Overview](./arkts-state-management-overview.md).

> **NOTE**
>
> The constraints on access modifiers of custom component member variables are supported since API version 12.

## Constraints

- The regular variables (which do not involve re-rendering) and variables decorated with [\@State](./arkts-state.md), [\@Prop](./arkts-prop.md), [\@Provide](./arkts-provide-and-consume.md), or [\@BuilderParam](./arkts-builderparam.md) can be initialized externally or using local values. If you do not want a variable to be initialized externally, you can modify it with **private**. In this case, any incorrect external initialization attempt will trigger a compilation warning log.

- Variables decorated with [\@StorageLink](./arkts-appstorage.md#storagelink), [\@StorageProp](./arkts-appstorage.md#storageprop), [\@LocalStorageLink](./arkts-localstorage.md#localstoragelink), [\@LocalStorageProp](./arkts-localstorage.md#localstorageprop), or [\@Consume](./arkts-provide-and-consume.md) cannot be initialized externally. Using **public** to modify these variables conflicts with the decorators' inherent initialization rules and triggers a compilation warning log.

- Variables decorated with [\@Link](./arkts-link.md) or [\@ObjectLink](./arkts-observed-and-objectlink.md) must be initialized externally, and local initialization is prohibited. Using **private** to modify these variables conflicts with the decorators' inherent initialization rules and triggers a compilation warning log.

- Because structs do not support inheritance, none of the preceding variables can be declared as **protected**.

- [\@Require](./arkts-require.md) means that a variable decorated with \@Require must be externally initialized. When the \@Require decorator and the **private** access qualifier are simultaneously applied to variables decorated by [\@State](./arkts-state.md)/[\@Prop](./arkts-prop.md)/[\@Provide](./arkts-provide-and-consume.md)/[\@BuilderParam](./arkts-builderparam.md) or to regular member variables (ordinary variables not involved in updates), their meanings are contradictory, and a compile-time warning log will be prompted.

## Use Scenarios

1. If a member variable is decorated with both the **private** access modifier and the \@State, \@Prop, \@Provide, or \@BuilderParam decorator, initializing it through the parent component will trigger a warning log.

   **Incorrect Usage**

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
      // Using the private modifier here will trigger a warning log.
      @State private stateValue: string = 'Hello';
      // Using the private modifier here will trigger a warning log.
      @Prop private propValue: string = 'Hello';
      // Using the private modifier here will trigger a warning log.
      @Provide private provideValue: string = 'Hello';
      // Using the private modifier here will trigger a warning log.
      @BuilderParam private builderValue: () => void = this.buildTest;
      // Using the private modifier here will trigger a warning log.
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

    The following are some warning log examples:

    ```ts
    Property 'stateValue' is private and can not be initialized through the component constructor.
    Property 'propValue' is private and can not be initialized through the component constructor.
    Property 'provideValue' is private and can not be initialized through the component constructor.
    Property 'builderValue' is private and can not be initialized through the component constructor.
    Property 'regularValue' is private and can not be initialized through the component constructor.
    ```

   **Correct Usage**

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
      // Correct usage.
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

2. If a member variable is decorated with both the **public** access modifier and the \@StorageLink, \@StorageProp, \@LocalStorageLink, \@LocalStorageProp, or \@Consume decorator, a build error is reported.

   **Incorrect Usage**

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
      // Using the public modifier here will trigger a warning log.
      @LocalStorageProp('sessionLocalProp') public localPropValue: string = 'Hello';
      // Using the public modifier here will trigger a warning log.
      @LocalStorageLink('sessionLocalLink') public localLinkValue: string = 'Hello';
      // Using the public modifier here will trigger a warning log.
      @StorageProp('sessionProp') public storagePropValue: string = 'Hello';
      // Using the public modifier here will trigger a warning log.
      @StorageLink('sessionLink') public storageLinkValue: string = 'Hello';
      // Using the public modifier here will trigger a warning log.
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

   The following are some warning log examples:

    ```ts
    Property 'localPropValue' can not be decorated with both '@LocalStorageProp' and public.
    Property 'localLinkValue' can not be decorated with both '@LocalStorageLink' and public.
    Property 'storagePropValue' can not be decorated with both '@StorageProp' and public.
    Property 'storageLinkValue' can not be decorated with both '@StorageLink' and public.
    Property 'consumeValue' can not be decorated with both '@Consume' and public.
    ```

   **Correct Usage**

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
      // Correct usage
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

3. If a member variable is decorated with both the **private** access modifier and the \@Link or \@ObjectLink decorator, ArkTS performs a validation check and generates a warning log.

   **Incorrect Usage**

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
      // Using the private modifier here will trigger a warning log.
      @Link private linkValue: string;
      // Using the private modifier here will trigger a warning log.
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

   The following are some warning log examples:

    ```ts
    Property 'linkValue' can not be decorated with both '@Link' and private.
    Property 'objectLinkValue' can not be decorated with both '@ObjectLink' and private.
    ```

   **Correct Usage**

    <!-- @[PrivateWithLink_CorrectCase](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Restrictions/entry/src/main/ets/pages/privateWithLink/PrivateWithLinkCorrectCase.ets) --> 

    ``` TypeScript
    @Entry
    @Component
    struct PrivateWithLinkAccessRestrictions {
      // Correct usage.
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

4. If a member variable is decorated with the **protected** access modifier, ArkTS performs a validation check and generates a warning log.

   **Incorrect Usage**

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
     // The protected access is not allowed and an alarm is reported.
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

   The following are some warning log examples:

    ```ts
    The member attributes of a struct can not be protected.
    ```

   **Correct Usage**

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
      // Correct usage.
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

5. If a member variable is decorated with the **private** access modifier, the \@Require decorator, and the \@State, \@Prop, \@Provide, or \@BuilderParam decorator, ArkTS will perform validation and generate warning logs.

   **Incorrect Usage**

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
      // Using the private modifier here will trigger a warning log.
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

   The following are some warning log examples:

    ```ts
    Property 'propValue' can not be decorated with both '@Require' and private.
    Property 'propValue' is private and can not be initialized through the component constructor.
    ```

   **Correct Usage**

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
      // Correct usage
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