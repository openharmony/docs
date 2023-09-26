# multimedia子系统ChangeLog

## cl.multimedia.1 音视频封装/解封装头文件引用路径变更

| 封装解封装头文件          | 原引用路径                  | 现引用路径                |
| ------------------------------- | ------------------------------------- | ------------------------------------- |
| native_avmuxer.h | <multimedia/native_avmuxer.h> | <multimedia/player_framework/native_avmuxer.h> |
| native_avdemuxer.h  | <multimedia/native_avdemuxer.h>               | <multimedia/player_framework/native_avdemuxer.h>               |
| native_avsource.h  | <multimedia/native_avsource.h>               | <multimedia/player_framework/native_avsource.h>               |

**变更影响**

对于已发布的SDK，可能影响三方应用的兼容性。

**适配指导**

开发人员需要在引用封装解封装头文件时，修改头文件引用路径。
