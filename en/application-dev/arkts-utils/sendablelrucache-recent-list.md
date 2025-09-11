# Obtaining the Recently Accessed List
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @lijiamin2025-->
<!--Designer: @weng-changcheng-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @ge-yafang-->

To quickly access the recently used [Sendable](arkts-sendable.md) objects, ArkTS introduces [SendableLruCache](../reference/apis-arkts/arkts-apis-arkts-utils-SendableLruCache.md) since API version 18. With this class, you can add, delete, and obtain Sendable objects from a SendableLruCache instance to quickly access the recently used Sendable objects. This topic describes how to use SendableLruCache to obtain the recently accessed list. It uses a bookshelf as an example. Every time a user opens a book, the book information is updated to the recently accessed list. When the user accesses the bookshelf next time, the list of books that the user has looked at is displayed.

> **NOTE**
>
> SendableLruCache instances must be locked to prevent data inconsistency caused by concurrent operations from multiple threads.
> Only Sendable objects can be put into a SendableLruCache instance.

1. Create a SendableLruCache instance and set its maximum capacity based on service requirements.<br>
   In this example, the maximum capacity of the SendableLruCache instance is set to 4, the Sendable class is used for management, and the Sendable class instance is exported.

   ```ts
   // LruCache.ets

   import { ArkTSUtils } from '@kit.ArkTS';

   // Use the 'use shared' marker to mark a module shareable.
   "use shared"

   // The SendableClass instance can be shared across different threads.
   @Sendable
   class SendableClass {
     // Lock the SendableLruCache instances to prevent data inconsistency caused by concurrent operations from multiple threads.
     lock_: ArkTSUtils.locks.AsyncLock = new ArkTSUtils.locks.AsyncLock();
     books_: ArkTSUtils.SendableLruCache<string, string> = new ArkTSUtils.SendableLruCache<string, string>(4);

     constructor() {
       this.books_.put("fourth", "Book4");
       this.books_.put("third", "Book3");
       this.books_.put("second", "Book2");
       this.books_.put("first", "Book1");
     }

     // Wrap the put, get, and keys methods and perform the lock operation.
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

2. In the same directory as the **Index.ets** page, create four book pages. Each page shows its own book information. Register the path of each page in the **main_pages.json** file under **src/main/resources/base/profile/**.

   ```ts
   // Book1.ets

   @Entry
   @Component
   struct Index1 {
     @State message: string = 'Hello World!';

     build() {
       RelativeContainer() {
         Text("Content of book 1")
           .id('first book')
           .fontSize(20)
           .padding(10)
           .fontWeight(FontWeight.Bold)
           .alignRules({
             center: { anchor: 'container', align: VerticalAlign.Center },
             middle: { anchor: 'container', align: HorizontalAlign.Center }
           })
         Button('Back')
           .fontSize(20)
           .padding(10)
           .fontWeight(FontWeight.Bold)
           .position({ x: "50%" })
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
         Text("Content of book 2")
           .id('second book')
           .fontSize(20)
           .padding(10)
           .fontWeight(FontWeight.Bold)
           .alignRules({
             center: { anchor: 'container', align: VerticalAlign.Center },
             middle: { anchor: 'container', align: HorizontalAlign.Center }
           })
         Button('Back')
           .fontSize(20)
           .padding(10)
           .fontWeight(FontWeight.Bold)
           .position({ x: "50%" })
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
         Text("Content of book 3")
           .id('third book')
           .fontSize(20)
           .padding(10)
           .fontWeight(FontWeight.Bold)
           .alignRules({
             center: { anchor: 'container', align: VerticalAlign.Center },
             middle: { anchor: 'container', align: HorizontalAlign.Center }
           })
         Button('Back')
           .fontSize(20)
           .padding(10)
           .fontWeight(FontWeight.Bold)
           .position({ x: "50%" })
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
         Text("Content of book 4")
           .id('fourth book')
           .fontSize(20)
           .padding(10)
           .fontWeight(FontWeight.Bold)
           .alignRules({
             center: { anchor: 'container', align: VerticalAlign.Center },
             middle: { anchor: 'container', align: HorizontalAlign.Center }
           })
         Button('Back')
           .fontSize(20)
           .padding(10)
           .fontWeight(FontWeight.Bold)
           .position({ x: "50%" })
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

3. Each time a user accesses the bookshelf page, the application displays the list of recently accessed books.

   ```ts
   // Index.ets

   import { taskpool } from '@kit.ArkTS';
   import { lruCache } from './LruCache'

   @Concurrent
   async function updateBooks(key: string, value: string) {
     // Update the latest access list in the child thread.
     await lruCache.put(key, value);
   }

   @Entry
   @Component
   struct Index {
     @State message: string = 'Bookshelf'
     @State books: string[] = [];

     async aboutToAppear () {
       // The application automatically obtains the list of recently accessed books.
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
             // Obtain the bound book information.
             let value = await lruCache.get(this.books[3]);
             // Update the recently accessed list.
             taskpool.execute(updateBooks, this.books[3], value);
             this.getUIContext().getRouter().pushUrl({ url: 'pages/' + value });
           })
         Button(this.books[2])
           .fontSize(20)
           .padding(10)
           .fontWeight(FontWeight.Bold)
           .onClick(async () => {
             // Obtain the bound book information.
             let value = await lruCache.get(this.books[2]);
             // Update the recently accessed list.
             taskpool.execute(updateBooks, this.books[2], value);
             this.getUIContext().getRouter().pushUrl({ url: 'pages/' + value });
           })
         Button(this.books[1])
           .fontSize(20)
           .padding(10)
           .fontWeight(FontWeight.Bold)
           .onClick(async () => {
             // Obtain the bound book information.
             let value = await lruCache.get(this.books[1]);
             // Update the recently accessed list.
             taskpool.execute(updateBooks, this.books[1], value);
             this.getUIContext().getRouter().pushUrl({ url: 'pages/' + value });
           })
         Button(this.books[0])
           .fontSize(20)
           .padding(10)
           .fontWeight(FontWeight.Bold)
           .onClick(async () => {
             // Obtain the bound book information.
             let value = await lruCache.get(this.books[0]);
             // Update the recently accessed list.
             taskpool.execute(updateBooks, this.books[0], value);
             this.getUIContext().getRouter().pushUrl({ url: 'pages/' + value });
           })
       }
       .height('100%')
       .width('100%')
     }
   }
   ```
