# 音乐专辑页


本小节将以音乐专辑页为例，介绍如何使用自适应布局能力和响应式布局能力适配不同尺寸窗口。


## 页面设计

音乐专辑页的页面设计如下。

  | sm | md | lg | 
| -------- | -------- | -------- |
| ![zh-cn_image_0000001381013985](figures/zh-cn_image_0000001381013985.png) | ![zh-cn_image_0000001381133197](figures/zh-cn_image_0000001381133197.png) | ![zh-cn_image_0000001329813432](figures/zh-cn_image_0000001329813432.png) | 

同样观察音乐专辑的页面设计，不同断点下的页面设计有较多相似的地方。

据此，我们可以将页面分拆为多个组成部分。

1. 标题栏

2. 歌单封面

3. 歌单列表

4. 播放控制栏

  | sm | md | lg | 
| -------- | -------- | -------- |
| ![zh-cn_image_0000001380933349](figures/zh-cn_image_0000001380933349.jpg) | ![zh-cn_image_0000001330133330](figures/zh-cn_image_0000001330133330.jpg) | ![zh-cn_image_0000001381013989](figures/zh-cn_image_0000001381013989.jpg) | 


## 标题栏

不同断点下，标题栏始终只显示“返回按钮”、“歌单”以及“更多按钮”，但“歌单”与“更多按钮”之间的间距不同。由于不同断点下标题栏的背景色也有较大差异，因此无法使用拉伸能力实现，此场景更适合使用栅格实现。我们可以将标题栏划分为“返回按钮及歌单”和“更多按钮”两部分，这两部分在不同断点下占据的列数如下图所示。另外，还可以借助OnBreakpointChange事件，调整不同断点下这两部分的背景色。

  |  | sm | md | lg | 
| -------- | -------- | -------- | -------- |
| 效果图 | ![zh-cn_image_0000001329817776](figures/zh-cn_image_0000001329817776.png) | ![zh-cn_image_0000001381018337](figures/zh-cn_image_0000001381018337.png) | ![zh-cn_image_0000001381137517](figures/zh-cn_image_0000001381137517.jpg) | 
| 栅格布局图 | ![zh-cn_image_0000001330137692](figures/zh-cn_image_0000001330137692.png) | ![zh-cn_image_0000001329977740](figures/zh-cn_image_0000001329977740.png) | ![zh-cn_image_0000001329658136](figures/zh-cn_image_0000001329658136.png) | 

  
```ts
@Component
export struct Header {
  @State moreBackgroundColor: Resource = $r('app.color.play_list_cover_background_color');
  build() {
    GridRow() {
      GridCol({span: {sm:6, md: 6, lg:4}}) {
        Row() {
          Image($r('app.media.ic_back')).height('24vp').width('24vp')
        }
        .width('100%')
        .height('50vp')
        .justifyContent(FlexAlign.Start)
        .alignItems(VerticalAlign.Center)
        .padding({left:$r('app.float.default_margin')})
        .backgroundColor($r('app.color.play_list_cover_background_color'))
      }
      GridCol({span: {sm:6, md: 6, lg:8}}) {
        Row() {
          Image($r('app.media.ic_add')).height('24vp').width('24vp')
        }
        .width('100%')
        .height('50vp')
        .justifyContent(FlexAlign.End)
        .alignItems(VerticalAlign.Center)
        .padding({right:$r('app.float.default_margin')})
        .backgroundColor(this.moreBackgroundColor)
      }
    }.onBreakpointChange((currentBreakpoint) => {
      // 调整不同断点下返回按钮及歌单的背景色
      if (currentBreakpoint === 'sm') {
        this.moreBackgroundColor = $r('app.color.play_list_cover_background_color');
      } else {
        this.moreBackgroundColor = $r('app.color.play_list_songs_background_color');
      }
    }).height('100%').width('100%')
  }
}
```


## 歌单封面

歌单封面由封面图片、歌单介绍及常用操作三部分组成，这三部分的布局在md和lg断点下完全相同，但在sm断点下有较大差异。此场景同样可以用栅格实现。

  |  | sm | md/lg | 
| -------- | -------- | -------- |
| 效果图 | ![zh-cn_image_0000001329660244](figures/zh-cn_image_0000001329660244.jpg) | ![zh-cn_image_0000001381379829](figures/zh-cn_image_0000001381379829.png) | 
| 栅格布局图 | ![zh-cn_image_0000001381220165](figures/zh-cn_image_0000001381220165.png) | ![zh-cn_image_0000001381220169](figures/zh-cn_image_0000001381220169.png) | 

  
```ts
import { optionList } from '../model/SongList'

@Component
export default struct PlayListCover {
    @State imgHeight: number = 0;
    @StorageProp('coverMargin') coverMargin: number = 0;
    @StorageProp('currentBreakpoint') currentBreakpoint: string = 'sm';
    @StorageProp('fontSize') fontSize: number = 0;

    @Builder
    CoverImage() {
      Stack({ alignContent: Alignment.BottomStart }) {
        Image($r('app.media.pic_album'))
          .width('100%')
          .aspectRatio(1)
          .borderRadius(8)
          .onAreaChange((oldArea: Area, newArea: Area) => {
            this.imgHeight = newArea.height as number
          })
        Text($r('app.string.collection_num'))
          .letterSpacing(1)
          .fontColor('#fff')
          .fontSize(this.fontSize - 4)
          .translate({ x: 10, y: '-100%' })
      }
      .width('100%')
      .height('100%')
      .aspectRatio(1)
    }

    @Builder
    CoverIntroduction() {
      Column() {
        Text($r('app.string.list_name'))
          .opacity(0.9)
          .fontWeight(500)
          .fontColor('#556B89')
          .fontSize(this.fontSize + 2)
          .margin({ bottom: 10 })

        Text($r('app.string.playlist_Introduction'))
          .opacity(0.6)
          .width('100%')
          .fontWeight(400)
          .fontColor('#556B89')
          .fontSize(this.fontSize - 2)
      }
      .width('100%')
      .height(this.currentBreakpoint === 'sm' ? this.imgHeight : 70)
      .alignItems(HorizontalAlign.Start)
      .justifyContent(FlexAlign.Center)
      .padding({ left: this.currentBreakpoint === 'sm' ? 20 : 0 })
      .margin({
        top: this.currentBreakpoint === 'sm' ? 0 : 30,
        bottom: this.currentBreakpoint === 'sm' ? 0 : 20
      })
    }

    @Builder
    CoverOptions() {
      Row() {
        ForEach(optionList, item => {
          Column({ space: 4 }) {
            Image(item.image).height(30).width(30)
            Text(item.text)
              .fontColor('#556B89')
              .fontSize(this.fontSize - 1)
          }
        })
      }
      .width('100%')
      .height(70)
      .padding({
        left: this.currentBreakpoint === 'sm' ? 20 : 0,
        right: this.currentBreakpoint === 'sm' ? 20 : 0
      })
      .margin({
        top: this.currentBreakpoint === 'sm' ? 15 : 0,
        bottom: this.currentBreakpoint === 'sm' ? 15 : 0
      })
      .justifyContent(FlexAlign.SpaceBetween)
    }
  build() {
    Column() {
      // 借助栅格组件实现总体布局
      GridRow() {
        // 歌单图片
        GridCol({ span: { sm: 4, md: 10 }, offset: { sm: 0, md: 1, lg: 1 } }) {
          this.CoverImage()
        }
        // 歌单介绍
        GridCol({ span: { sm: 8, md: 10 }, offset: { sm: 0, md: 2, lg: 2 } }) {
          this.CoverIntroduction()
        }
        // 歌单操作
        GridCol({ span: { sm: 12, md: 10 }, offset: { sm: 0, md: 2, lg: 2 } }) {
          this.CoverOptions()
        }.margin({
          top: this.currentBreakpoint === 'sm' ? 15 : 0,
          bottom: this.currentBreakpoint === 'sm' ? 15 : 0
        })
      }
      .margin({ left: this.coverMargin, right: this.coverMargin })
    }
    .height('100%')
    .padding({ top: this.currentBreakpoint === 'sm' ? 50 : 70 })
  }
}
```


## 歌单列表

不同断点下，歌单列表的样式基本一致，但sm和md断点下是歌单列表是单列显示，lg断点下是双列显示。可以通过[List组件](../../reference/apis-arkui/arkui-ts/ts-container-list.md)的lanes属性实现这一效果。

  
```ts
import { songList } from '../model/SongList';
import MyDataSource from '../model/SongModule'

@Component
export default struct PlayList {
  @StorageProp('currentBreakpoint') currentBreakpoint: string = 'sm';
  @StorageProp('fontSize') fontSize: number = 0;
  @Consume coverHeight: number;
   @Builder
  PlayAll() {
    Row() {
      Image($r("app.media.ic_play_all"))
        .height(23)
        .width(23)
      Text($r('app.string.play_all'))
        .maxLines(1)
        .padding({ left: 10 })
        .fontColor('#000000')
        .fontSize(this.fontSize)
      Blank()
      Image($r('app.media.ic_order_play'))
        .width(24)
        .height(24)
        .margin({ right: 16 })
      Image($r('app.media.ic_sort_list'))
        .height(24)
        .width(24)
    }
    .height(60)
    .width('100%')
    .padding({ left: 12, right: 12 })
  }

  @Builder
  SongItem(title: string, label: Resource, singer: string) {
    Row() {
      Column() {
        Text(title)
          .fontColor('#000000')
          .fontSize(this.fontSize)
          .margin({ bottom: 4 })
        Row() {
          Image(label)
            .width(16)
            .height(16)
            .margin({ right: 4 })
          Text(singer)
            .opacity(0.38)
            .fontColor('#000000')
            .fontSize(this.fontSize - 4)
        }
      }
      .alignItems(HorizontalAlign.Start)

      Blank()
      Image($r('app.media.ic_list_more'))
        .height(24)
        .width(24)
    }
    .height(60)
    .width('100%')
  }
  build() {
    Column() {
      this.PlayAll()
      Scroll() {
        List() {
          LazyForEach(new MyDataSource(songList), item => {
            ListItem() {
              this.SongItem(item.title, item.label, item.singer)
            }
          })
        }
        .width('100%')
        .height('100%')
        // 配置不同断点下歌单列表的列数
        .lanes(this.currentBreakpoint === 'lg' ? 2 : 1)
      }
      .backgroundColor('#fff')
      .margin({ top: 50, bottom: this.currentBreakpoint === 'sm' ? this.coverHeight : 0 })
    }
    .padding({top: 50,bottom: 48})
  }
}
```


## 播放控制栏

在不同断点下，播放控制栏显示的内容完全一致，唯一的区别是歌曲信息与播放控制按钮之间的间距有差异，这是典型的拉伸能力的使用场景。

  
```ts
@Component
export default struct Player {
  @StorageProp('fontSize') fontSize: number = 0;
  build() {
    Row() {
      Image($r('app.media.pic_album')).height(32).width(32).margin({right: 12})
      Column() {
        Text($r('app.string.song_name'))
          .fontColor('#000000')
          .fontSize(this.fontSize - 1)
        Row() {
          Image($r('app.media.ic_vip'))
            .height(16)
            .width(16)
            .margin({ right: 4 })
          Text($r('app.string.singer'))
            .fontColor('#000000')
            .fontSize(this.fontSize - 4)
            .opacity(0.38)
        }
      }
      .alignItems(HorizontalAlign.Start)
      // 通过Blank组件实现拉伸能力
      Blank()
      Image($r('app.media.icon_play')).height(26).width(26).margin({right: 16})
      Image($r('app.media.ic_next')).height(24).width(24).margin({right: 16})
      Image($r('app.media.ic_Music_list')).height(24).width(24)
    }
    .width('100%')
    .height(48)
    .backgroundColor('#D8D8D8')
    .alignItems(VerticalAlign.Center)
    .padding({left: 16, right: 16})
  }
}
```


## 运行效果

将页面中的四部分组合在一起，即可显示完整的页面。

其中歌单封面和歌单列表这两部分的相对位置，在sm断点下是上下排布，在md和lg断点下是左右排布，也可以用栅格来实现目标效果。

  |  | sm | md | lg | 
| -------- | -------- | -------- | -------- |
| 效果图 | ![zh-cn_image_0000001381026609](figures/zh-cn_image_0000001381026609.jpg) | ![zh-cn_image_0000001381145789](figures/zh-cn_image_0000001381145789.jpg) | ![zh-cn_image_0000001329666380](figures/zh-cn_image_0000001329666380.jpg) | 
| 栅格布局图 | ![zh-cn_image_0000001330145976](figures/zh-cn_image_0000001330145976.png) | ![zh-cn_image_0000001381385985](figures/zh-cn_image_0000001381385985.png) | ![zh-cn_image_0000001381226321](figures/zh-cn_image_0000001381226321.png) | 

  
```ts
import PlayListCover from '../common/PlayListCover';
import PlayList from '../common/PlayList';

@Component
export default struct Content {
  // ...
  build() {
    GridRow() {
      // 歌单封面
      GridCol({ span: { xs: 12, sm: 12, md: 6, lg: 4 } }) {
        PlayListCover()
      }
      // 歌单列表
      GridCol({ span: { xs: 12, sm: 12, md: 6, lg: 8 } }) {
        PlayList()
      }
    }
    .height('100%')
  }
}
```

最后将页面各部分组合在一起即可。

  
```ts

import Header from '../common/Header';
import Player from '../common/Player';
import Content from '../common/Content';

@Entry
@Component
struct Index {
  build() {
    Column() {
      // 标题栏
      Header()
      // 歌单
      Content()
      // 播放控制栏
      Player()
    }.width('100%').height('100%')
  }
}
```

音乐专辑页面的运行效果如下所示。

  | sm | md | lg | 
| -------- | -------- | -------- |
| ![MusicAlbum_sm_running](figures/MusicAlbum_sm_running.png) | ![MusicAlbum_md_running](figures/MusicAlbum_md_running.png) | ![MusicAlbum_lg_running](figures/MusicAlbum_lg_running.png) | 

## 相关实例

针对音乐专辑应用，有以下相关实例可供参考：

- [典型页面场景：音乐专辑页（ArkTS）（API9）](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-5.0.0-Release/code/SuperFeature/MultiDeviceAppDev/MusicAlbum)

