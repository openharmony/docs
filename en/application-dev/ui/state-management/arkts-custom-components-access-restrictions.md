# Constraints on Access Modifiers of Custom Component Member Variables

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

- Variables decorated by [\@Require](./arkts-require.md) must be initialized externally. Therefore, using \@Require and **private** together to decorate regular variables (which do not involve re-rendering) and variables decorated by [\@State](./arkts-state.md), [\@Prop](./arkts-prop.md), [\@Provide](./arkts-provide-and-consume.md), or [\@BuilderParam](./arkts-builderparam.md) is not allowed.

## Use Scenarios

1. If a member variable is decorated with both the **private** access modifier and the \@State, \@Prop, \@Provide, or \@BuilderParam decorator, initializing it through the parent component will trigger a warning log.

    **Incorrect Usage**
    ```ts
    @Entry
    @Component
    struct AccessRestrictions {
      @Builder
      buildTest() {
        Text('Parent builder')
      }
    
      build() {
        Column() {
          ComponentsChild({
            state_value: 'Hello',
            prop_value: 'Hello',
            provide_value: 'Hello',
            builder_value: this.buildTest,
            regular_value: 'Hello'
          })
        }
        .width('100%')
      }
    }

    @Component
    struct ComponentsChild {
      // Using the private modifier here will trigger a warning log.
      @State private state_value: string = 'Hello';
      // Using the private modifier here will trigger a warning log.
      @Prop private prop_value: string = 'Hello';
      // Using the private modifier here will trigger a warning log.
      @Provide private provide_value: string = 'Hello';
      // Using the private modifier here will trigger a warning log.
      @BuilderParam private builder_value: () => void = this.buildTest;
      // Using the private modifier here will trigger a warning log.
      private regular_value: string = 'Hello';
    
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
    Property 'state_value' is private and can not be initialized through the component constructor.
    Property 'prop_value' is private and can not be initialized through the component constructor.
    Property 'provide_value' is private and can not be initialized through the component constructor.
    Property 'builder_value' is private and can not be initialized through the component constructor.
    Property 'regular_value' is private and can not be initialized through the component constructor.
    ```

    **Correct Usage**
    ```ts
    @Entry
    @Component
    struct AccessRestrictions {
      @Builder
      buildTest() {
        Text('Parent builder')
      }
    
      build() {
        Column() {
          ComponentsChild({
            state_value: 'Hello',
            prop_value: 'Hello',
            provide_value: 'Hello',
            builder_value: this.buildTest,
            regular_value: 'Hello'
          })
        }
        .width('100%')
      }
    }

    @Component
    struct ComponentsChild {
      @State state_value: string = 'Hello';
      @Prop prop_value: string = 'Hello';
      @Provide provide_value: string = 'Hello';
      @BuilderParam builder_value: () => void = this.buildTest;
      regular_value: string = 'Hello';
    
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

2. If a member variable is decorated with both the **public** access modifier and the \@StorageLink, \@StorageProp, \@LocalStorageLink, \@LocalStorageProp, or \@Consume decorator, initializing it through the parent component will trigger a warning log.

    **Incorrect Usage**
    ```ts
    @Entry
    @Component
    struct AccessRestrictions {
      @Provide consume_value: string = 'Hello';
      build() {
        Column() {
          ComponentChild()
        }
        .width('100%')
      }
    }

    @Component
    struct ComponentChild {
      // Using the public modifier here will trigger a warning log.
      @LocalStorageProp('sessionLocalProp') public local_prop_value: string = 'Hello';
      // Using the public modifier here will trigger a warning log.
      @LocalStorageLink('sessionLocalLink') public local_link_value: string = 'Hello';
      // Using the public modifier here will trigger a warning log.
      @StorageProp('sessionProp') public storage_prop_value: string = 'Hello';
      // Using the public modifier here will trigger a warning log.
      @StorageLink('sessionLink') public storage_link_value: string = 'Hello';
      // Using the public modifier here will trigger a warning log.
      @Consume public consume_value: string;
      
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
    Property 'local_prop_value' can not be decorated with both @LocalStorageProp and public.
    Property 'local_link_value' can not be decorated with both @LocalStorageLink and public.
    Property 'storage_prop_value' can not be decorated with both @StorageProp and public.
    Property 'storage_link_value' can not be decorated with both @StorageLink and public.
    Property 'consume_value' can not be decorated with both @Consume and public.
    ```
    
    **Correct Usage**
    ```ts
    @Entry
    @Component
    struct AccessRestrictions {
      @Provide consume_value: string = 'Hello';
      build() {
        Column() {
          ComponentChild()
        }
        .width('100%')
      }
    }

    @Component
    struct ComponentChild {
      @LocalStorageProp('sessionLocalProp') local_prop_value: string = 'Hello';
      @LocalStorageLink('sessionLocalLink') local_link_value: string = 'Hello';
      @StorageProp('sessionProp') storage_prop_value: string = 'Hello';
      @StorageLink('sessionLink') storage_link_value: string = 'Hello';
      @Consume consume_value: string;
      build() {
        Column() {
          Text('Hello')
            .fontSize(50)
            .fontWeight(FontWeight.Bold)
        }
      }
    }
    ```

3. If a member variable is decorated by both the **private** access modifier and the \@Link or \@ObjectLink decorator, initializing it through the parent component will trigger a warning log.

    **Incorrect Usage**
    ```ts
    @Entry
    @Component
    struct AccessRestrictions {
      @State link_value: string = 'Hello';
      @State objectLink_value: ComponentObj = new ComponentObj();
      build() {
        Column() {
          ComponentChild({link_value: this.link_value, objectLink_value: this.objectLink_value})
        }
        .width('100%')
      }
    }
    
    @Observed
    class ComponentObj {
      count: number = 0;
    }
    @Component
    struct ComponentChild {
      // Using the private modifier here will trigger a warning log.
      @Link private link_value: string;
      // Using the private modifier here will trigger a warning log.
      @ObjectLink private objectLink_value: ComponentObj;
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
    Property 'link_value' can not be decorated with both @Link and private.
    Property 'objectLink_value' can not be decorated with both @ObjectLink and private.
    ```
    
    **Correct Usage**
    ```ts
    @Entry
    @Component
    struct AccessRestrictions {
      @State link_value: string = 'Hello';
      @State objectLink_value: ComponentObj = new ComponentObj();
      build() {
        Column() {
          ComponentChild({link_value: this.link_value, objectLink_value: this.objectLink_value})
        }
        .width('100%')
      }
    }

    @Observed
    class ComponentObj {
      count: number = 0;
    }
    @Component
    struct ComponentChild {
      @Link link_value: string;
      @ObjectLink objectLink_value: ComponentObj;
      build() {
        Column() {
          Text('Hello')
            .fontSize(50)
            .fontWeight(FontWeight.Bold)
        }
      }
    }
    ```

4. If a member variable is decorated with the **protected** access modifier, initializing it through the parent component will trigger a warning log.

    **Incorrect Usage**
    ```ts
    @Entry
    @Component
    struct AccessRestrictions {
      build() {
        Column() {
          ComponentChild({regular_value: 'Hello'})
        }
        .width('100%')
      }
    }
    
    @Component
    struct ComponentChild {
      // The protected access is not allowed and an alarm is reported.
      protected regular_value: string = 'Hello';
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
    ```ts
    @Entry
    @Component
    struct AccessRestrictions {
      build() {
        Column() {
          ComponentChild({regular_value: 'Hello'})
        }
        .width('100%')
      }
    }

    @Component
    struct ComponentChild {
      regular_value: string = 'Hello';
      build() {
        Column() {
          Text('Hello')
            .fontSize(50)
            .fontWeight(FontWeight.Bold)
        }
      }
    }
    ```

5. If a member variable is decorated with the **private** access modifier, the \@Require decorator, and any of the \@State, \@Prop, \@Provide, and \@BuilderParam decorators, initializing it through the parent component will trigger a warning log.

    **Incorrect Usage**
    ```ts
    @Entry
    @Component
    struct AccessRestrictions {
      build() {
        Column() {
          ComponentChild({prop_value: 'Hello'})
        }
        .width('100%')
      }
    }
    @Component
    struct ComponentChild {
      // Using the private modifier here will trigger a warning log.
      @Require @Prop private prop_value: string = 'Hello';
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
    Property 'prop_value' can not be decorated with both @Require and private.
    Property 'prop_value' is private and can not be initialized through the component constructor.
    ```
    
    **Correct Usage**
    ```ts
    @Entry
    @Component
    struct AccessRestrictions {
      build() {
        Column() {
          ComponentChild({prop_value: 'Hello'})
        }
        .width('100%')
      }
    }
    @Component
    struct ComponentChild {
      @Require @Prop prop_value: string = 'Hello';
      build() {
        Column() {
          Text('Hello')
            .fontSize(50)
            .fontWeight(FontWeight.Bold)
        }
      }
    }
    ```
