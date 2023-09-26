# Media Subsystem ChangeLog

## cl.media.1 Playback APIs Changed

The APIs related to audio track switching are deleted.

**Change Impact**

These APIs are unavailable.

**Key API/Component Changes**

The deleted APIs are as follows:

| Class          | API                                                |
| -------------- | ------------------------------------------------------------ |
| Media.Core     | MD_KEY_LANGUAGE                                              |
| Media.AVPlayer | selectTrack(index: number): void                             |
| Media.AVPlayer | deselectTrack(index: number): void                           |
| Media.AVPlayer | getCurrentTrack(trackType: MediaType, callback: AsyncCallback\<number>): void |
| Media.AVPlayer | getCurrentTrack(trackType: MediaType): Promise\<number>      |
| Media.AVPlayer | on(type: 'trackChange', callback: (index: number, isSelect: boolean) => void): void; |
| Media.AVPlayer | off(type: 'trackChange'): void                               |
