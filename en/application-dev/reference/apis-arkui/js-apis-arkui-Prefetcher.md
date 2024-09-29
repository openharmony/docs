# @ohos.arkui.Prefetcher (Prefetching)
Used in conjunction with **LazyForEach**, the **Prefetcher** module provides content prefetching capabilities for container components such as **List**, **Grid**, **Waterfall**, and **Swiper** during scrolling, to enhance the user browsing experience.

>  **NOTE**
>  The initial APIs of this module are supported since API version 12. Updates will be marked with a superscript to indicate their earliest API version.


## IPrefetcher
Implement this API to provide prefetching capabilities.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### setDataSource
setDataSource(dataSource: IDataSourcePrefetching): void;

Sets the prefetching-capable data source to bind to the **Prefetcher** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name       | Type                                               | Mandatory| Description        |
|------------|---------------------------------------------------|----|------------|
| dataSource | [IDataSourcePrefetching](#idatasourceprefetching) | Yes | Prefetching-capable data source.|

```typescript
class MyPrefetcher implements IPrefetcher {
  private dataSource?: IDataSourcePrefetching;
  
  setDataSource(dataSource: IDataSourcePrefetching): void {
    this.dataSource = dataSource;
  }
}
```

### visibleAreaChanged
visibleAreaChanged(minVisible: number, maxVisible: number): void

Called when the boundaries of the visible area change. It works with the **List**, **Grid**, **Waterfall**, and **Swiper** components.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name       | Type    | Mandatory| Description       |
|------------|--------|----|-----------|
| minVisible | number | Yes | Upper bound of the visible area.|
| maxVisible | number | Yes | Lower bound of the visible area.|

```typescript
class MyPrefetcher implements IPrefetcher {
  private dataSource?: IDataSourcePrefetching;

  visibleAreaChanged(minVisible: number, maxVisible: number): void {
    this.dataSource?.prefetch(minVisible);
  }
}
```

## BasicPrefetcher
As a fundamental implementation of **IPrefetcher**, offers an intelligent data prefetching algorithm that decides which data items to prefetch based on real-time changes in the visible area on the screen and variations in the prefetch duration. It can also determine which prefetch requests should be canceled based on the user's scrolling actions.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### constructor
constructor(dataSource?: IDataSourcePrefetching)

A constructor used to create a **DataSource** instance.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name       | Type                                               | Mandatory| Description        |
|------------|---------------------------------------------------|----|------------|
| dataSource | [IDataSourcePrefetching](#idatasourceprefetching) | No | Prefetching-capable data source.|

### setDataSource
setDataSource(dataSource: IDataSourcePrefetching): void;

Sets the prefetching-capable data source to bind to the **Prefetcher** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name       | Type                                               | Mandatory| Description        |
|------------|---------------------------------------------------|----|------------|
| dataSource | [IDataSourcePrefetching](#idatasourceprefetching) | Yes | Prefetching-capable data source.|

### visibleAreaChanged
visibleAreaChanged(minVisible: number, maxVisible: number): void

Called when the boundaries of the visible area change. It works with the **List**, **Grid**, **Waterfall**, and **Swiper** components.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name       | Type    | Mandatory| Description       |
|------------|--------|----|-----------|
| minVisible | number | Yes | Upper bound of the visible area.|
| maxVisible | number | Yes | Lower bound of the visible area.|

## IDataSourcePrefetching

Implements a prefetching-capable data source.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### prefetch
**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type    | Mandatory| Description      |
|-------|--------|----|----------|
| index | number | Yes | Index of the data item to be prefetched.|

### cancel
**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type    | Mandatory| Description        |
|-------|--------|----|------------|
| index | number | Yes | Index of the data item whose prefetching should be canceled.|

When list content moves off the screen (for example, during fast scrolling scenarios), once the prefetching algorithm determines which items outside the screen can have their prefetching canceled, this API is called. For instance, if the HTTP framework supports request cancellation, network requests initiated in the **prefetch** API can be canceled here.

## Example

```typescript
import { BasicPrefetcher, IDataSourcePrefetching } from '@kit.ArkUI';
import { image } from '@kit.ImageKit';

const ITEMS_ON_SCREEN = 8;

@Entry
@Component
struct PrefetcherDemoComponent {
  private readonly dataSource = new MyDataSource(2000, 500);
  private readonly prefetcher = new BasicPrefetcher(this.dataSource);

  build() {
    Column() {
      List() {
        LazyForEach(this.dataSource, (item: PictureItem) => {
          ListItem() {
            PictureItemComponent({ info: item })
              .height(`${100 / ITEMS_ON_SCREEN}%`)
          }
        }, (item: PictureItem) => item.title)
      }
      .onScrollIndex((start: number, end: number) => {
        this.prefetcher.visibleAreaChanged(start, end);
      })
    }
  }
}

@Component
struct PictureItemComponent {
  @ObjectLink info: PictureItem;

  build() {
    Row() {
      Image(this.info.imagePixelMap)
        .objectFit(ImageFit.Contain)
        .width('40%')
      Text(this.info.title)
        .width('60%')
    }
  }
}

@Observed
class PictureItem {
  readonly color: number;
  title: string;
  imagePixelMap: image.PixelMap | undefined;
  key: string;

  constructor(color: number, title: string) {
    this.color = color;
    this.title = title;
    this.key = title;
  }
}

type ItemIndex = number;
type TimerId = number;

class MyDataSource implements IDataSourcePrefetching {
  private readonly items: PictureItem[];
  private readonly fetchDelayMs: number;
  private readonly fetches: Map<ItemIndex, TimerId> = new Map();

  constructor(numItems: number, fetchDelayMs: number) {
    this.items = [];
    this.fetchDelayMs = fetchDelayMs;
    for (let i = 0; i < numItems; i++) {
      const item = new PictureItem(getRandomColor(), `Item ${i}`)
      this.items.push(item);
    }
  }

  async prefetch(index: number): Promise<void> {
    const item = this.items[index];
    if (item.imagePixelMap) {
      return;
    }

    // Perform time-consuming operations.
    return new Promise<void>(resolve => {
      const timeoutId = setTimeout(async () => {
        this.fetches.delete(index);
        const bitmap = create10x10Bitmap(item.color);
        const imageSource: image.ImageSource = image.createImageSource(bitmap);
        item.imagePixelMap = await imageSource.createPixelMap();
        resolve();
      }, this.fetchDelayMs);

      this.fetches.set(index, timeoutId)
    });
  }

  cancel(index: number): void {
    const timerId = this.fetches.get(index);
    if (timerId) {
      this.fetches.delete(index);
      clearTimeout(timerId);
    }
  }

  totalCount(): number {
    return this.items.length;
  }

  getData(index: number): PictureItem {
    return this.items[index];
  }

  registerDataChangeListener(_: DataChangeListener): void {
  }

  unregisterDataChangeListener(_: DataChangeListener): void {
  }
}

function getRandomColor(): number {
  const maxColorCode = 256;
  const r = Math.floor(Math.random() * maxColorCode);
  const g = Math.floor(Math.random() * maxColorCode);
  const b = Math.floor(Math.random() * maxColorCode);

  return (r * 256 + g) * 256 + b;
}

function create10x10Bitmap(color: number): ArrayBuffer {
  const height = 10;
  const width = 10;

  const fileHeaderLength = 14;
  const bitmapInfoLength = 40;
  const headerLength = fileHeaderLength + bitmapInfoLength;
  const pixelSize = (width * 3 + 2) * height;

  let length = pixelSize + headerLength;

  const buffer = new ArrayBuffer(length);
  const view16 = new Uint16Array(buffer);

  view16[0] = 0x4D42;
  view16[1] = length & 0xffff;
  view16[2] = length >> 16;
  view16[5] = headerLength;

  let offset = 7;
  view16[offset++] = bitmapInfoLength & 0xffff;
  view16[offset++] = bitmapInfoLength >> 16;
  view16[offset++] = width & 0xffff;
  view16[offset++] = width >> 16;
  view16[offset++] = height & 0xffff;
  view16[offset++] = height >> 16;
  view16[offset++] = 1;
  view16[offset++] = 24;

  const b = color & 0xff;
  const g = (color >> 8) & 0xff;
  const r = color >> 16;
  offset = headerLength;
  const view8 = new Uint8Array(buffer);
  for (let y = 0; y < height; y++) {
    for (let x = 0; x < width; x++) {
      view8[offset++] = b;
      view8[offset++] = g;
      view8[offset++] = r;
    }
    offset += 2;
  }

  return buffer;
}
```
