# Freezing a Custom Component

When a custom component decorated by @ComponentV2 is inactive, it can be frozen so that its state variable does not respond to updates. That is, the @Monitor decorated method is not called, and the node associated with the state variable is not re-rendered. You can use the **freezeWhenInactive** attribute to specify whether to freeze a custom component. If no parameter is passed in, the feature is disabled. This feature works in following scenarios: page routing, **TabContent**, and **Navigation**.


> **NOTE**
>
> Custom component freezing is supported since API version 12.
> 
> Different from freezing the @Component decorated components, custom components decorated by @ComponentV2 do not support freezing the cached list items in the **LazyForEach** scenario.


## Use Scenarios

### Page Routing

- When page A calls the **router.pushUrl** API to jump to page B, page A is hidden and invisible. In this case, if the state variable on page A is updated, page A is not re-rendered.

- The freezing feature does not work when the application is running in the background.

Page A:

```ts
import { router } from '@kit.ArkUI';

@ObservedV2
export class Book {
  @Trace page: number = 100;

  constructor(page: number) {
    this.page = page;
  }

  @Monitor("page")
  onPageChange(monitor: IMonitor) {
    console.log(`Page change : ${this.page}`);
  }
}

export let book: Book = new Book(100);

@Entry
@ComponentV2({ freezeWhenInactive: true })
export struct FirstTest {
  build() {
    Column() {
      Text(`From fist Page ${book.page}`).fontSize(50)
      Button('first page + 1').fontSize(30)
        .onClick(() => {
          book.page += 1;
        })
      Button('go to next page').fontSize(30)
        .onClick(() => {
          router.pushUrl({ url: 'pages/Page' });
        })
    }
  }
}
```

Page B:

```ts
import { router } from '@kit.ArkUI';
import { book } from './Index';

@Entry
@ComponentV2({ freezeWhenInactive: true })
struct SecondTest {
  build() {
    Column() {
      Text(`second Page ${book.page}`).fontSize(50)
      Button('Back')
        .onClick(() => {
          router.back();
        })
      Button('second page + 2').fontSize(30)
        .onClick(() => {
          book.page += 2;
        })

    }
  }
}
```

In the preceding example:

1. When the button **first page + 1** on page A is clicked, the **page** property of the **book** variable is updated, and the @Monitor decorated **onPageChange** method is called.

2. Through **router.pushUrl({url: 'pages/Page'})**, page B is displayed, and page A is hidden with its state changing from active to inactive.

3. When the button **second page + 2** on page B is clicked, the @Monitor decorated **onPageChange** method is called.

4. When the **back** button is clicked, page B is destroyed, and page A changes from inactive to active. At this time, the **Text** component is updated.


### TabContent

- You can freeze invisible **TabContent** components in the **Tabs** container so that they do not trigger UI re-rendering.

- During initial rendering, only the **TabContent** component that is being displayed is created. All **TabContent** components are created only after all of them have been switched to.

```ts
@Entry
@ComponentV2
struct TabContentTest {
  @Local message: number = 0;
  @Local data: number[] = [0, 1];

  build() {
    Row() {
      Column() {
        Button('change message').onClick(() => {
          this.message++;
        })

        Tabs() {
          ForEach(this.data, (item: number) => {
            TabContent() {
              FreezeChild({ message: this.message, index: item })
            }.tabBar(`tab${item}`)
          }, (item: number) => item.toString())
        }
      }
      .width('100%')
    }
    .height('100%')
  }
}

@ComponentV2({ freezeWhenInactive: true })
struct FreezeChild {
  @Param message: number = 0;
  @Param index: number = 0;

  @Monitor('message') onMessageUpdated(mon: IMonitor) {
    console.info(`FreezeChild message callback func ${this.message}, index: ${this.index}`);
  }

  build() {
    Text("message" + `${this.message}, index: ${this.index}`)
      .fontSize(50)
      .fontWeight(FontWeight.Bold)
  }
}
```

In the preceding example:

1. When **change message** is clicked, the value of **message** changes, and the @Monitor decorated **onMessageUpdated** method of the **TabContent** component being displayed is called.

2. When **two** is clicked to switch to another **TabContent** component, the component switches from inactive to active, and the corresponding @Monitor decorated **onMessageUpdated** method is called.

3. When **change message** is clicked again, the value of **message** changes, and only the @Monitor decorated **onMessageUpdated** method of the **TabContent** component being displayed is called.


### Navigation

- You can freeze an invisible page so that it does not trigger UI re-rendering. When the user returns to this page, a re-render is triggered through an @Monitor decorated callback.

```ts
@Entry
@ComponentV2
struct MyNavigationTestStack {
  @Provider('pageInfo') pageInfo: NavPathStack = new NavPathStack();
  @Local message: number = 0;

  @Monitor('message') info() {
    console.info(`freeze-test MyNavigation message callback ${this.message}`);
  }

  @Builder
  PageMap(name: string) {
    if (name === 'pageOne') {
      pageOneStack({ message: this.message })
    } else if (name === 'pageTwo') {
      pageTwoStack({ message: this.message })
    } else if (name === 'pageThree') {
      pageThreeStack({ message: this.message })
    }
  }

  build() {
    Column() {
      Button('change message')
        .onClick(() => {
          this.message++;
        })
      Navigation(this.pageInfo) {
        Column() {
          Button('Next Page', { stateEffect: true, type: ButtonType.Capsule })
            .onClick(() => {
              this.pageInfo.pushPath({ name: 'pageOne' }); // Push the navigation destination page specified by name to the navigation stack.
            })
        }
      }.title('NavIndex')
      .navDestination(this.PageMap)
      .mode(NavigationMode.Stack)
    }
  }
}

@ComponentV2
struct pageOneStack {
  @Consumer('pageInfo') pageInfo: NavPathStack = new NavPathStack();
  @Local index: number = 1;
  @Param message: number = 0;

  build() {
    NavDestination() {
      Column() {
        NavigationContentMsgStack({ message: this.message, index: this.index })
        Text("cur stack size:" + `${this.pageInfo.size()}`)
          .fontSize(30)
        Button('Next Page', { stateEffect: true, type: ButtonType.Capsule })
          .onClick(() => {
            this.pageInfo.pushPathByName('pageTwo', null);
          })
        Button('Back Page', { stateEffect: true, type: ButtonType.Capsule })
          .onClick(() => {
            this.pageInfo.pop();
          })
      }.width('100%').height('100%')
    }.title('pageOne')
    .onBackPressed(() => {
      this.pageInfo.pop();
      return true;
    })
  }
}

@ComponentV2
struct pageTwoStack {
  @Consumer('pageInfo') pageInfo: NavPathStack = new NavPathStack();
  @Local index: number = 2;
  @Param message: number = 0;

  build() {
    NavDestination() {
      Column() {
        NavigationContentMsgStack({ message: this.message, index: this.index })
        Text("cur stack size:" + `${this.pageInfo.size()}`)
          .fontSize(30)
        Button('Next Page', { stateEffect: true, type: ButtonType.Capsule })
          .onClick(() => {
            this.pageInfo.pushPathByName('pageThree', null);
          })
        Button('Back Page', { stateEffect: true, type: ButtonType.Capsule })
          .onClick(() => {
            this.pageInfo.pop();
          })
      }
    }.title('pageTwo')
    .onBackPressed(() => {
      this.pageInfo.pop();
      return true;
    })
  }
}

@ComponentV2
struct pageThreeStack {
  @Consumer('pageInfo') pageInfo: NavPathStack = new NavPathStack();
  @Local index: number = 3;
  @Param message: number = 0;

  build() {
    NavDestination() {
      Column() {
        NavigationContentMsgStack({ message: this.message, index: this.index })
        Text("cur stack size:" + `${this.pageInfo.size()}`)
          .fontSize(30)
        Button('Next Page', { stateEffect: true, type: ButtonType.Capsule })
          .height(40)
          .onClick(() => {
            this.pageInfo.pushPathByName('pageOne', null);
          })
        Button('Back Page', { stateEffect: true, type: ButtonType.Capsule })
          .height(40)
          .onClick(() => {
            this.pageInfo.pop();
          })
      }
    }.title('pageThree')
    .onBackPressed(() => {
      this.pageInfo.pop();
      return true;
    })
  }
}

@ComponentV2({ freezeWhenInactive: true })
struct NavigationContentMsgStack {
  @Param message: number = 0;
  @Param index: number = 0;

  @Monitor('message') info() {
    console.info(`freeze-test NavigationContent message callback ${this.message}`);
    console.info(`freeze-test ---- called by content ${this.index}`);
  }

  build() {
    Column() {
      Text("msg:" + `${this.message}`)
        .fontSize(30)
    }
  }
}
```

In the preceding example:

1. When **change message** is clicked, the value of **message** changes, and the @Monitor decorated **info** method of the **MyNavigationTestStack** component being displayed is called.

2. When **Next Page** is clicked, the page is switched to **PageOne** and the **pageOneStack** node is created.

3. When **change message** is clicked again, the value of **message** changes, and only the @Monitor decorated **info** method of the **NavigationContentMsgStack** child component in **pageOneStack** is called.

4. When **Next Page** is clicked, the page is switched to **PageTwo** and the **pageTwoStack** node is created.

5. When **change message** is clicked again, the value of **message** changes, and only the @Monitor decorated **info** method of the **NavigationContentMsgStack** child component in **pageTwoStack** is called.

6. When **Next Page** is clicked, the page is switched to **PageThree** and the **pageThreeStack** node is created.

7. When **change message** is clicked again, the value of **message** changes, and only the @Monitor decorated **info** method of the **NavigationContentMsgStack** child component in **pageThreeStack** is called.

8. When **Back Page** is clicked, the page is switched to **PageTwo**. At this time, only the @Monitor decorated **info** method of the **NavigationContentMsgStack** child component in **pageTwoStack** is called.

9. When **Back Page** is clicked, the page is switched to **PageOne** page. At this time, only the @Monitor decorated **info** method of the **NavigationContentMsgStack** child component in **pageOneStack** is called.

10. When **Back Page** is clicked, the page is switched to the initial page.
