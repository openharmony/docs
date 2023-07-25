# 媒体子系统ChangeLog

## cl.media.1 播放功能接口变更

删除音轨切换相关接口。

**变更影响**

删除音轨切换相关接口，相关接口不可使用。

**关键的接口/组件变更**

删除接口如下：

| 类名           | 删除接口声明                                                 |
| -------------- | ------------------------------------------------------------ |
| Media.Core     | MD_KEY_LANGUAGE                                              |
| Media.AVPlayer | selectTrack(index: number): void                             |
| Media.AVPlayer | deselectTrack(index: number): void                           |
| Media.AVPlayer | getCurrentTrack(trackType: MediaType, callback: AsyncCallback\<number>): void |
| Media.AVPlayer | getCurrentTrack(trackType: MediaType): Promise\<number>      |
| Media.AVPlayer | on(type: 'trackChange', callback: (index: number, isSelect: boolean) => void): void; |
| Media.AVPlayer | off(type: 'trackChange'): void                               |

