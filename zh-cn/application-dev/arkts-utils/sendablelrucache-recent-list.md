# 获取最近访问列表

为了快速访问最近使用的[Sendable](arkts-sendable.md)对象，从API version 18开始，ArkTS引入了[SendableLruCache](../reference/apis-arkts/js-apis-arkts-utils.md#sendablelrucachek-v18)。开发者可以通过向SendableLruCache实例中添加、删除和获取Sendable对象，实现快速访问最近使用的Sendable对象。本文提供使用SendableLruCache实现获取最近使用列表的开发指导，以书架为例，每次打开一本图书后，需将图书信息更新到最近访问列表中，并在下次访问书架页面时显示最近访问的图书列表。

> **说明：**
>
> 使用SendableLruCache实例对象时需加锁，避免多线程同时操作导致数据不一致。
> 存放到SendableLruCache实例中的对象应为Sendable对象。

1. 创建SendableLruCache实例对象，并根据业务需求预设最大容量。<br/>
   此例设置SendableLruCache实例的最大容量为4，用SendableClass类来管理，并导出SendableClass类实例对象。

   ```ts
   // LruCache.ets

   import { ArkTSUtils } from '@kit.ArkTS';

   // 使用use shared标记为共享模块。
   "use shared"

   // SendableClass实例对象在不同线程间可共享。
   @Sendable
   class SendableClass {
     // 使用SendableLruCache实例对象时需加锁，避免多线程同时操作导致数据不一致。
     lock_: ArkTSUtils.locks.AsyncLock = new ArkTSUtils.locks.AsyncLock();
     books_: ArkTSUtils.SendableLruCache<string, string> = new ArkTSUtils.SendableLruCache<string, string>(4);

     constructor() {
       this.books_.put("fourth", "Book4");
       this.books_.put("third", "Book3");
       this.books_.put("second", "Book2");
       this.books_.put("first", "Book1");
     }

     // 封装put、get、keys方法，加锁操作。
     public async put(key: string, value: string) {
       await this.lock_.lockAsync(() => {
         this.books_.put(key, value);
       })
     }

     public async get(key: string): Promise<string | undefined> {
       return this.lock_.lockAsync(() => {
         return this.books_.get(key);
       });
     }

     public async keys(): Promise<string[]> {
       return this.lock_.lockAsync(() => {
         return this.books_.keys();
       });
     }
   }

   export let lruCache = new SendableClass();
   ```

2. 在Index.ets页面同目录下创建4个图书页面，每个页面显示相应的图书信息，并将每个页面的路径注册到`src/main/resources/base/profile/main_pages.json`文件中。

   ```ts
   // Book1.ets

   @Entry
   @Component
   struct Index1 {
     @State message: string = 'Hello World!';

     build() {
       RelativeContainer() {
         Text("第一本书的内容")
           .id('first book')
           .fontSize(20)
           .padding(10)
           .fontWeight(FontWeight.Bold)
           .alignRules({
             center: { anchor: 'container', align: VerticalAlign.Center },
             middle: { anchor: 'container', align: HorizontalAlign.Center }
           })
         Button("返回")
           .fontSize(20)
           .padding(10)
           .fontWeight(FontWeight.Bold)
           .onClick(() => {
             this.getUIContext().getRouter().pushUrl({ url: 'pages/Index' });
           })
       }
       .height('100%')
       .width('100%')
     }
   }
   ```
   ```ts
   // Book2.ets

   @Entry
   @Component
   struct Index2 {
     @State message: string = 'Hello World!';

     build() {
       RelativeContainer() {
         Text("第二本书的内容")
           .id('second book')
           .fontSize(20)
           .padding(10)
           .fontWeight(FontWeight.Bold)
           .alignRules({
             center: { anchor: 'container', align: VerticalAlign.Center },
             middle: { anchor: 'container', align: HorizontalAlign.Center }
           })
         Button("返回")
           .fontSize(20)
           .padding(10)
           .fontWeight(FontWeight.Bold)
           .onClick(() => {
             this.getUIContext().getRouter().pushUrl({ url: 'pages/Index' });
           })
       }
       .height('100%')
       .width('100%')
     }
   }
   ```
   ```ts
   // Book3.ets

   @Entry
   @Component
   struct Index3 {
     @State message: string = 'Hello World!';

     build() {
       RelativeContainer() {
         Text("第三本书的内容")
           .id('third book')
           .fontSize(20)
           .padding(10)
           .fontWeight(FontWeight.Bold)
           .alignRules({
             center: { anchor: 'container', align: VerticalAlign.Center },
             middle: { anchor: 'container', align: HorizontalAlign.Center }
           })
         Button("返回")
           .fontSize(20)
           .padding(10)
           .fontWeight(FontWeight.Bold)
           .onClick(() => {
             this.getUIContext().getRouter().pushUrl({ url: 'pages/Index' });
           })
       }
       .height('100%')
       .width('100%')
     }
   }
   ```
   ```ts
   // Book4.ets

   @Entry
   @Component
   struct Index4 {
     @State message: string = 'Hello World!';

     build() {
       RelativeContainer() {
         Text("第四本书的内容")
           .id('fourth book')
           .fontSize(20)
           .padding(10)
           .fontWeight(FontWeight.Bold)
           .alignRules({
             center: { anchor: 'container', align: VerticalAlign.Center },
             middle: { anchor: 'container', align: HorizontalAlign.Center }
           })
         Button("返回")
           .fontSize(20)
           .padding(10)
           .fontWeight(FontWeight.Bold)
           .onClick(() => {
             this.getUIContext().getRouter().pushUrl({ url: 'pages/Index' });
           })
       }
       .height('100%')
       .width('100%')
     }
   }
   ```
   ```json
   // main_pages.json

   {
     "src": [
       "pages/Index",
       "pages/Book1",
       "pages/Book2",
       "pages/Book3",
       "pages/Book4"
     ]
   }
   ```

3. 访问书架页面时，自动展示最近访问的图书列表。

   ```ts
   // Index.ets

   import { taskpool } from '@kit.ArkTS';
   import { lruCache } from './LruCache'

   @Concurrent
   async function updateBooks(key: string, value: string) {
     // 在子线程更新最近访问列表
     await lruCache.put(key, value);
   }

   @Entry
   @Component
   struct Index {
     @State message: string = '书架';
     @State books: string[] = [];

     async aboutToAppear () {
       // 自动获取最近访问的图书列表
       this.books = await lruCache.keys();
     }

     build() {
       Column({ space: 1 }) {
         Text(this.message)
           .id('HelloWorld')
           .fontSize(50)
           .fontWeight(FontWeight.Bold)
           .alignRules({
             center: { anchor: 'container', align: VerticalAlign.Center },
             middle: { anchor: 'container', align: HorizontalAlign.Center }
           })
         Button(this.books[3])
           .fontSize(20)
           .padding(10)
           .fontWeight(FontWeight.Bold)
           .onClick(async () => {
             // 获取绑定的图书信息
             let value = await lruCache.get(this.books[3]);
             // 更新最近访问列表
             taskpool.execute(updateBooks, this.books[3], value);
             this.getUIContext().getRouter().pushUrl({ url: 'pages/' + value });
           })
         Button(this.books[2])
           .fontSize(20)
           .padding(10)
           .fontWeight(FontWeight.Bold)
           .onClick(async () => {
             // 获取绑定的图书信息
             let value = await lruCache.get(this.books[2]);
             // 更新最近访问列表
             taskpool.execute(updateBooks, this.books[2], value);
             this.getUIContext().getRouter().pushUrl({ url: 'pages/' + value });
           })
         Button(this.books[1])
           .fontSize(20)
           .padding(10)
           .fontWeight(FontWeight.Bold)
           .onClick(async () => {
             // 获取绑定的图书信息
             let value = await lruCache.get(this.books[1]);
             // 更新最近访问列表
             taskpool.execute(updateBooks, this.books[1], value);
             this.getUIContext().getRouter().pushUrl({ url: 'pages/' + value });
           })
         Button(this.books[0])
           .fontSize(20)
           .padding(10)
           .fontWeight(FontWeight.Bold)
           .onClick(async () => {
             // 获取绑定的图书信息
             let value = await lruCache.get(this.books[0]);
             // 更新最近访问列表
             taskpool.execute(updateBooks, this.books[0], value);
             this.getUIContext().getRouter().pushUrl({ url: 'pages/' + value });
           })
       }
       .height('100%')
       .width('100%')
     }
   }
   ```