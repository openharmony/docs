# \@ComponentV2装饰器：自定义组件

为了在自定义组件中使用V2版本状态变量装饰器的能力，开发者可以使用\@ComponentV2装饰器装饰自定义组件。

>**说明：**
>
>\@ComponentV2装饰器从API version 12开始支持。
>
>当前状态管理（V2试用版）仍在逐步开发中，相关功能尚未成熟，建议开发者尝鲜试用。


## 概述

和[\@Component装饰器](arkts-create-custom-components.md)一样，\@ComponentV2装饰器用于装饰自定义组件：

- 在\@ComponentV2装饰的自定义组件中，开发者仅可以使用全新的状态变量装饰器，包括\@Local、\@Param、\@Once、\@Event、\@Provider、\@Consumer等。
- \@ComponentV2装饰的自定义组件暂不支持组件复用、LocalStorage等现有自定义组件的能力。
- 无法同时使用\@ComponentV2与\@Component装饰同一个struct结构。
- \@ComponentV2支持一个可选的boolean类型参数freezeWhenInactive，来实现[组件冻结功能](arkts-custom-components-freezeV2.md)。

- 一个简单的\@ComponentV2装饰的自定义组件应具有以下部分：

    ```ts
    @ComponentV2 // 装饰器
    struct Index { // struct声明的数据结构
      build() { // build定义的UI
      }
    }
    ```

除非特别说明，\@ComponentV2装饰的自定义组件将与\@Component装饰的自定义组件保持相同的行为。

## 限制条件

在将\@Component装饰的自定义组件与\@ComponentV2装饰的自定义组件混合使用时，以下情况的变量传递是不允许的：

- \@ComponentV2装饰的自定义组件中的非状态变量接收来自父组件传递的变量。

- 将\@State、\@Prop、\@Link、\@ObjectLink、\@Provide、\@Consume、\@StorageLink、\@StorageProp、\@LocalStorageLink、\@LocalStorageProp等装饰的对象类型的变量传递给\@ComponentV2装饰的自定义组件里的\@Param、\@Event等装饰的变量。

- 将被\@Local、\@Param、\@Event、\@Provider、\@Consumer等装饰的Array、Set、Map、Date类型的变量传递给\@Component装饰的自定义组件里的@State、\@Prop、\@ObjectLink、\@Provide等装饰的变量。

- 在\@Component装饰的自定义组件里被@Link修饰的变量，接收来自\@ComponentV2装饰的父组件传递的变量。

- 在\@Component装饰的自定义组件中使用\@State、\@Prop、\@Link、\@Provide、\@Consume、\@StorageLink、\@StorageProp、\@LocalStorageLink、\@LocalStorageProp装饰被\@ObservedV2装饰的类。

- 在\@ComponentV2装饰的自定义组件中使用\@Local、\@Param、\@Event、\@Provider()、\@Consumer()装饰被\@Observed装饰的类。