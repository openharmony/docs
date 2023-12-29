# 运行时动态加载页面提升性能

## 简介

应用在加载页面时，如果引入大量暂不需要加载的模块，会因过多模块导致页面加载缓慢。比如当页面在使用Navigation组件时，主页默认先加载所有页面，此时若包含大量子页面，仅加载主页这一项就需要很长时间，但这些复杂的子页面与主页渲染无关。
本文推荐使用动态加载解决上述问题，不在应用程序加载时就将所有模块都加载进来，而是按需加载模块，增加应用灵活性，提升应用性能。

## 场景示例

| 主页                                       | 子页面                                        |
|------------------------------------------|--------------------------------------------|
| ![主页](./figures/dynamic-import-home.png) | ![子页面](./figures/dynamic-import-pages.png) |

下面示例应用通过Navigation组件常规加载与动态加载的对比，介绍如何在跳转时触发加载方法，实现按需加载子模块。

### 常规加载

开发者使用Navigation组件时，通常会在主页引入各子页面组件，在按钮中添加方法实现跳转。下述代码展示常规加载示例，通过import引入子组件。

1. 加载模块引入子页面，Navigation组件使用这些子模块实现跳转子页面功能，但用户进入主页时并不会马上使用到这些模块，存在冗余加载影响性能的可能。
    ```ts
    import { pageOne, pageOneData } from './pageOne';
    import { pageTwo, pagesTwoData } from './pageTwo';
    ...
    import router from '@ohos.router';
    ```
2. 主页通过Navigation组件实现点击Button跳转到不同的子页面。
    ```ts
    @Provide('pathInfos') pageInfos: NavPathStack = new NavPathStack();
    
    @Builder
    PageMap(name: string) {
      if (name === 'pageOne') {
        pageOne(new pagesOneData(name, this.pageInfos));
      } else if (name === 'pageTwo') {
        pageTwo(new pagesTwoData(name, this.pageInfos));
      }
      ...
    }
    
    build() {
      Navigation(this.pageInfos) {
        Button('返回', { stateEffect: true, type: ButtonType.Capsule })
          .onClick(() => {
             router.back();
          })
        Column() {
          Button('pageOne', { stateEffect: true, type: ButtonType.Capsule })
            .onClick(() => {
               this.pageInfos.pushPath({ name: 'pageOne' }); // 将name指定的NavDestination页面信息入栈
            })
          Button('pageTwo', { stateEffect: true, type: ButtonType.Capsule })
            .onClick(() => {
               this.pageInfos.pushPath({ name: 'pageTwo' });
            })
          ...
        }
      }.title('主页').navDestination(this.PageMap)
    }
    ```

### 动态加载

当子组件较多、较复杂时，由于Navigation组件一次性加载所有模块，使用常规加载会导致主页加载缓慢。为了减少主页渲染时间，可以使用动态加载，在实际页面跳转时再按需动态引入子组件，优化用户的首次加载速度体验。以下是动态加载实现步骤：

1. 将需要被动态加载的组件pageOne组件用PageOneLoader函数封装，当PageOneLoader被调用时，会渲染pageOne页面。
    ```ts
    import { pageOne } from './pageOne';
    
    @Builder
    export function PageOneLoader() {
      pageOne();
    }
    ```
2. 由于在Navigation的PageMap中navDestination无法直接动态加载组件（import是函数，组件中无法引用函数），此处采用声明 @BuilderParam PageOneLoader 函数，在点击时初始化此函数，此时navDestination中可以调用 this.PageOneLoader() 从而加载组件pageOne。 
在主页DynamicHome实现动态加载pageOne的步骤如下：  
   a) 在主页DynamicHome中定义组件加载函数 `@BuilderParam PageOneLoader: () => void` ，用来承接await import异步导入pageOneLoader的结果。
    ```ts
    @BuilderParam PageOneLoader: () => void;
    ```
   b) 定义异步函数，点击时为PageOneLoader初始化。
    ```ts
    async loadPageOne(key: string){
      if (key === "pageOne") {
        let PageObj: ESObject = await import("../pages/PageOneLoader");
        this.PageOneLoader = PageObj.PageOneLoader;
      }
    }
    ```
   c) 点击按钮触发点击函数，调用loadPageOne，此时真正的初始化 @BuilderParam PageOneLoader ，并使用Navigation加载组件。
    ```ts
    private onEntryClick(): void {
      try {
        this.loadPageOne('pageOne');
        this.pageInfos.clear();
        this.pageInfos.pushPathByName('pageOne', '');
        logger.info('DynamicImport Success');
      } catch (error) {
        logger.info('DynamicImport Fail');
      }
    }
    ```
   d) 触发PageMap中已经被初始化的PageOneLoader函数，动态加载pageOne组件。
    ```ts
    @Builder
    PageMap(name: string) {
      if (name === 'pageOne') {
        this.PageOneLoader();
      }
    }
    ```
完整的DynamicHome主页代码如下：
```ts
import router from '@ohos.router';
import { logger } from '../../ets/utils/Logger';

@Entry
@Component
struct DynamicHome {
  @Provide('pathInfos') pageInfos: NavPathStack = new NavPathStack();
  @State active: boolean = false;
  @BuilderParam PageOneLoader: () => void;

  @Builder
  PageMap(name: string) {
    if (name === 'pageOne') {
      this.PageOneLoader();
    }
  }

  build() {
    Navigation(this.pageInfos) {
      Column() {
        Button('返回', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            router.back();
          })
        Button('PageOne-动态', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.onEntryClick();
          })
      }
    }.title('HOME').navDestination(this.PageMap)
  }

  async loadPageOne(key: String) {
    if (key === "pageOne") {
      let PageObj: ESObject = await import("../pages/PageOneLoader");
      this.PageOneLoader = PageObj.PageOneLoader;
    }
  }

  // 触发动态加载
  private onEntryClick(): void {
    try {
      this.loadPageOne('pageOne');
      this.pageInfos.clear();
      this.pageInfos.pushPathByName('pageOne', '');
      logger.info('DynamicImport Success');
    } catch (error) {
      logger.info('DynamicImport Fail');
    }
  }
}
```
当子页面逐渐增多时，Navigation组件使用常规加载会因默认加载所有子页面导致性能开销增大，主页内存占用增加，加载时间变长。此时改用动态加载不再提前加载子页面，可以有效地避免这些任务阻塞主线程，从而降低整体资源消耗，提高主页的加载速度。
