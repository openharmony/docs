# 键值

按键设备键值。

>  **说明：**
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import {KeyCode} from '@ohos.multimodalInput.keyCode';
```

## KeyCode

**系统能力**：SystemCapability.MultimodalInput.Input.Core

| 名称                               | 类型   | 可读   | 可写   | 说明                          |
| -------------------------------- | ------ | ---- | ---- | --------------------------- |
| KEYCODE_FN                       | number | 是    | 否    | 功能（Fn）键                     |
| KEYCODE_UNKNOWN                  | number | 是    | 否    | 未知按键                        |
| KEYCODE_HOME                     | number | 是    | 否    | 功能（Home）键                  |
| KEYCODE_BACK                     | number | 是    | 否    | 返回键                         |
| KEYCODE_MEDIA_PLAY_PAUSE         | number | 是    | 否    | 多媒体键 播放/暂停                  |
| KEYCODE_MEDIA_STOP               | number | 是    | 否    | 多媒体键 停止                     |
| KEYCODE_MEDIA_NEXT               | number | 是    | 否    | 多媒体键 下一首                    |
| KEYCODE_MEDIA_PREVIOUS           | number | 是    | 否    | 多媒体键 上一首                    |
| KEYCODE_MEDIA_REWIND             | number | 是    | 否    | 多媒体键 快退                     |
| KEYCODE_MEDIA_FAST_FORWARD       | number | 是    | 否    | 多媒体键 快进                     |
| KEYCODE_VOLUME_UP                | number | 是    | 否    | 音量增加键                       |
| KEYCODE_VOLUME_DOWN              | number | 是    | 否    | 音量减小键                       |
| KEYCODE_POWER                    | number | 是    | 否    | 电源键                         |
| KEYCODE_CAMERA                   | number | 是    | 否    | 拍照键                         |
| KEYCODE_VOLUME_MUTE              | number | 是    | 否    | 扬声器静音键                      |
| KEYCODE_MUTE                     | number | 是    | 否    | 话筒静音键                       |
| KEYCODE_BRIGHTNESS_UP            | number | 是    | 否    | 亮度调节按键 调亮                   |
| KEYCODE_BRIGHTNESS_DOWN          | number | 是    | 否    | 亮度调节按键 调暗                   |
| KEYCODE_0                        | number | 是    | 否    | 按键'0'                       |
| KEYCODE_1                        | number | 是    | 否    | 按键'1'                       |
| KEYCODE_2                        | number | 是    | 否    | 按键'2'                       |
| KEYCODE_3                        | number | 是    | 否    | 按键'3'                       |
| KEYCODE_4                        | number | 是    | 否    | 按键'4'                       |
| KEYCODE_5                        | number | 是    | 否    | 按键'5'                       |
| KEYCODE_6                        | number | 是    | 否    | 按键'6'                       |
| KEYCODE_7                        | number | 是    | 否    | 按键'7'                       |
| KEYCODE_8                        | number | 是    | 否    | 按键'8'                       |
| KEYCODE_9                        | number | 是    | 否    | 按键'9'                       |
| KEYCODE_STAR                     | number | 是    | 否    | 按键'*'                       |
| KEYCODE_POUND                    | number | 是    | 否    | 按键'#'                       |
| KEYCODE_DPAD_UP                  | number | 是    | 否    | 导航键 向上                      |
| KEYCODE_DPAD_DOWN                | number | 是    | 否    | 导航键 向下                      |
| KEYCODE_DPAD_LEFT                | number | 是    | 否    | 导航键 向左                      |
| KEYCODE_DPAD_RIGHT               | number | 是    | 否    | 导航键 向右                      |
| KEYCODE_DPAD_CENTER              | number | 是    | 否    | 导航键 确定键                     |
| KEYCODE_A                        | number | 是    | 否    | 按键'A'                       |
| KEYCODE_B                        | number | 是    | 否    | 按键'B'                       |
| KEYCODE_C                        | number | 是    | 否    | 按键'C'                       |
| KEYCODE_D                        | number | 是    | 否    | 按键'D'                       |
| KEYCODE_E                        | number | 是    | 否    | 按键'E'                       |
| KEYCODE_F                        | number | 是    | 否    | 按键'F'                       |
| KEYCODE_G                        | number | 是    | 否    | 按键'G'                       |
| KEYCODE_H                        | number | 是    | 否    | 按键'H'                       |
| KEYCODE_I                        | number | 是    | 否    | 按键'I'                       |
| KEYCODE_J                        | number | 是    | 否    | 按键'J'                       |
| KEYCODE_K                        | number | 是    | 否    | 按键'K'                       |
| KEYCODE_L                        | number | 是    | 否    | 按键'L'                       |
| KEYCODE_M                        | number | 是    | 否    | 按键'M'                       |
| KEYCODE_N                        | number | 是    | 否    | 按键'N'                       |
| KEYCODE_O                        | number | 是    | 否    | 按键'O'                       |
| KEYCODE_P                        | number | 是    | 否    | 按键'P'                       |
| KEYCODE_Q                        | number | 是    | 否    | 按键'Q'                       |
| KEYCODE_R                        | number | 是    | 否    | 按键'R'                       |
| KEYCODE_S                        | number | 是    | 否    | 按键'S'                       |
| KEYCODE_T                        | number | 是    | 否    | 按键'T'                       |
| KEYCODE_U                        | number | 是    | 否    | 按键'U'                       |
| KEYCODE_V                        | number | 是    | 否    | 按键'V'                       |
| KEYCODE_W                        | number | 是    | 否    | 按键'W'                       |
| KEYCODE_X                        | number | 是    | 否    | 按键'X'                       |
| KEYCODE_Y                        | number | 是    | 否    | 按键'Y'                       |
| KEYCODE_Z                        | number | 是    | 否    | 按键'Z'                       |
| KEYCODE_COMMA                    | number | 是    | 否    | 按键','                       |
| KEYCODE_PERIOD                   | number | 是    | 否    | 按键'.'                       |
| KEYCODE_ALT_LEFT                 | number | 是    | 否    | 左Alt键                    |
| KEYCODE_ALT_RIGHT                | number | 是    | 否    | 右Alt键                  |
| KEYCODE_SHIFT_LEFT               | number | 是    | 否    | 左Shift键                |
| KEYCODE_SHIFT_RIGHT              | number | 是    | 否    | 右Shift键                 |
| KEYCODE_TAB                      | number | 是    | 否    | Tab键                        |
| KEYCODE_SPACE                    | number | 是    | 否    | 空格键                         |
| KEYCODE_SYM                      | number | 是    | 否    | 符号修改器按键                     |
| KEYCODE_EXPLORER                 | number | 是    | 否    | 浏览器功能键，此键用于启动浏览器应用程序。       |
| KEYCODE_ENVELOPE                 | number | 是    | 否    | 电子邮件功能键，此键用于启动电子邮件应用程序。     |
| KEYCODE_ENTER                    | number | 是    | 否    | 回车键                         |
| KEYCODE_DEL                      | number | 是    | 否    | 退格键                         |
| KEYCODE_GRAVE                    | number | 是    | 否    | 按键'`'                       |
| KEYCODE_MINUS                    | number | 是    | 否    | 按键'-'                       |
| KEYCODE_EQUALS                   | number | 是    | 否    | 按键'='                       |
| KEYCODE_LEFT_BRACKET             | number | 是    | 否    | 按键'['                       |
| KEYCODE_RIGHT_BRACKET            | number | 是    | 否    | 按键']'                       |
| KEYCODE_BACKSLASH                | number | 是    | 否    | 按键'\\'                       |
| KEYCODE_SEMICOLON                | number | 是    | 否    | 按键';'                       |
| KEYCODE_APOSTROPHE               | number | 是    | 否    | 按键''' (单引号)                 |
| KEYCODE_SLASH                    | number | 是    | 否    | 按键'/'                       |
| KEYCODE_AT                       | number | 是    | 否    | 按键'@'                       |
| KEYCODE_PLUS                     | number | 是    | 否    | 按键'+'                       |
| KEYCODE_MENU                     | number | 是    | 否    | 菜单键                         |
| KEYCODE_PAGE_UP                  | number | 是    | 否    | 向上翻页键                       |
| KEYCODE_PAGE_DOWN                | number | 是    | 否    | 向下翻页键                       |
| KEYCODE_ESCAPE                   | number | 是    | 否    | ESC键                        |
| KEYCODE_FORWARD_DEL              | number | 是    | 否    | 删除键                         |
| KEYCODE_CTRL_LEFT                | number | 是    | 否    | 左Ctrl键                |
| KEYCODE_CTRL_RIGHT               | number | 是    | 否    | 右Ctrl键               |
| KEYCODE_CAPS_LOCK                | number | 是    | 否    | 大写锁定键                       |
| KEYCODE_SCROLL_LOCK              | number | 是    | 否    | 滚动锁定键                       |
| KEYCODE_META_LEFT                | number | 是    | 否    | 左元修改器键                      |
| KEYCODE_META_RIGHT               | number | 是    | 否    | 右元修改器键                      |
| KEYCODE_FUNCTION                 | number | 是    | 否    | 功能键                      |
| KEYCODE_SYSRQ                    | number | 是    | 否    | 系统请求/打印屏幕键                  |
| KEYCODE_BREAK                    | number | 是    | 否    | Break/Pause键                |
| KEYCODE_MOVE_HOME                | number | 是    | 否    | 光标移动到开始键                    |
| KEYCODE_MOVE_END                 | number | 是    | 否    | 光标移动到末尾键                    |
| KEYCODE_INSERT                   | number | 是    | 否    | 插入键                         |
| KEYCODE_FORWARD                  | number | 是    | 否    | 前进键                         |
| KEYCODE_MEDIA_PLAY               | number | 是    | 否    | 多媒体键 播放                     |
| KEYCODE_MEDIA_PAUSE              | number | 是    | 否    | 多媒体键 暂停                     |
| KEYCODE_MEDIA_CLOSE              | number | 是    | 否    | 多媒体键 关闭                     |
| KEYCODE_MEDIA_EJECT              | number | 是    | 否    | 多媒体键 弹出                     |
| KEYCODE_MEDIA_RECORD             | number | 是    | 否    | 多媒体键 录音                     |
| KEYCODE_F1                       | number | 是    | 否    | 按键'F1'                      |
| KEYCODE_F2                       | number | 是    | 否    | 按键'F2'                      |
| KEYCODE_F3                       | number | 是    | 否    | 按键'F3'                      |
| KEYCODE_F4                       | number | 是    | 否    | 按键'F4'                      |
| KEYCODE_F5                       | number | 是    | 否    | 按键'F5'                      |
| KEYCODE_F6                       | number | 是    | 否    | 按键'F6'                      |
| KEYCODE_F7                       | number | 是    | 否    | 按键'F7'                      |
| KEYCODE_F8                       | number | 是    | 否    | 按键'F8'                      |
| KEYCODE_F9                       | number | 是    | 否    | 按键'F9'                      |
| KEYCODE_F10                      | number | 是    | 否    | 按键'F10'                     |
| KEYCODE_F11                      | number | 是    | 否    | 按键'F11'                     |
| KEYCODE_F12                      | number | 是    | 否    | 按键'F12'                     |
| KEYCODE_NUM_LOCK                 | number | 是    | 否    | 小键盘锁                        |
| KEYCODE_NUMPAD_0                 | number | 是    | 否    | 小键盘按键'0'                    |
| KEYCODE_NUMPAD_1                 | number | 是    | 否    | 小键盘按键'1'                    |
| KEYCODE_NUMPAD_2                 | number | 是    | 否    | 小键盘按键'2'                    |
| KEYCODE_NUMPAD_3                 | number | 是    | 否    | 小键盘按键'3'                    |
| KEYCODE_NUMPAD_4                 | number | 是    | 否    | 小键盘按键'4'                    |
| KEYCODE_NUMPAD_5                 | number | 是    | 否    | 小键盘按键'5'                    |
| KEYCODE_NUMPAD_6                 | number | 是    | 否    | 小键盘按键'6'                    |
| KEYCODE_NUMPAD_7                 | number | 是    | 否    | 小键盘按键'7'                    |
| KEYCODE_NUMPAD_8                 | number | 是    | 否    | 小键盘按键'8'                    |
| KEYCODE_NUMPAD_9                 | number | 是    | 否    | 小键盘按键'9'                    |
| KEYCODE_NUMPAD_DIVIDE            | number | 是    | 否    | 小键盘按键'/'                    |
| KEYCODE_NUMPAD_MULTIPLY          | number | 是    | 否    | 小键盘按键'*'                    |
| KEYCODE_NUMPAD_SUBTRACT          | number | 是    | 否    | 小键盘按键'-'                    |
| KEYCODE_NUMPAD_ADD               | number | 是    | 否    | 小键盘按键'+'                    |
| KEYCODE_NUMPAD_DOT               | number | 是    | 否    | 小键盘按键'.'                    |
| KEYCODE_NUMPAD_COMMA             | number | 是    | 否    | 小键盘按键','                    |
| KEYCODE_NUMPAD_ENTER             | number | 是    | 否    | 小键盘按键回车                     |
| KEYCODE_NUMPAD_EQUALS            | number | 是    | 否    | 小键盘按键'='                    |
| KEYCODE_NUMPAD_LEFT_PAREN        | number | 是    | 否    | 小键盘按键'('                    |
| KEYCODE_NUMPAD_RIGHT_PAREN       | number | 是    | 否    | 小键盘按键')'                    |
| KEYCODE_VIRTUAL_MULTITASK        | number | 是    | 否    | 虚拟多任务键                      |
| KEYCODE_SLEEP                    | number | 是    | 否    | 睡眠键                         |
| KEYCODE_ZENKAKU_HANKAKU          | number | 是    | 否    | 日文全宽/半宽键                    |
| KEYCODE_102ND                    | number | 是    | 否    | 102nd按键                     |
| KEYCODE_RO                       | number | 是    | 否    | 日文Ro键                       |
| KEYCODE_KATAKANA                 | number | 是    | 否    | 日文片假名键                      |
| KEYCODE_HIRAGANA                 | number | 是    | 否    | 日文平假名键                      |
| KEYCODE_HENKAN                   | number | 是    | 否    | 日文转换键                       |
| KEYCODE_KATAKANA_HIRAGANA        | number | 是    | 否    | 日语片假名/平假名键                  |
| KEYCODE_MUHENKAN                 | number | 是    | 否    | 日文非转换键                      |
| KEYCODE_LINEFEED                 | number | 是    | 否    | 换行键                         |
| KEYCODE_MACRO                    | number | 是    | 否    | 宏键                          |
| KEYCODE_NUMPAD_PLUSMINUS         | number | 是    | 否    | 数字键盘上的加号/减号键                |
| KEYCODE_SCALE                    | number | 是    | 否    | 扩展键                         |
| KEYCODE_HANGUEL                  | number | 是    | 否    | 日文韩语键                       |
| KEYCODE_HANJA                    | number | 是    | 否    | 日文汉语键                       |
| KEYCODE_YEN                      | number | 是    | 否    | 日元键                         |
| KEYCODE_STOP                     | number | 是    | 否    | 停止键                         |
| KEYCODE_AGAIN                    | number | 是    | 否    | 重复键                         |
| KEYCODE_PROPS                    | number | 是    | 否    | 道具键                         |
| KEYCODE_UNDO                     | number | 是    | 否    | 撤消键                         |
| KEYCODE_COPY                     | number | 是    | 否    | 复制键                         |
| KEYCODE_OPEN                     | number | 是    | 否    | 打开键                         |
| KEYCODE_PASTE                    | number | 是    | 否    | 粘贴键                         |
| KEYCODE_FIND                     | number | 是    | 否    | 查找键                         |
| KEYCODE_CUT                      | number | 是    | 否    | 剪切键                         |
| KEYCODE_HELP                     | number | 是    | 否    | 帮助键                         |
| KEYCODE_CALC                     | number | 是    | 否    | 计算器特殊功能键，用于启动计算器应用程序        |
| KEYCODE_FILE                     | number | 是    | 否    | 文件按键                        |
| KEYCODE_BOOKMARKS                | number | 是    | 否    | 书签键                         |
| KEYCODE_NEXT                     | number | 是    | 否    | 下一个按键                       |
| KEYCODE_PLAYPAUSE                | number | 是    | 否    | 播放/暂停键                      |
| KEYCODE_PREVIOUS                 | number | 是    | 否    | 上一个按键                       |
| KEYCODE_STOPCD                   | number | 是    | 否    | CD停止键                       |
| KEYCODE_CONFIG                   | number | 是    | 否    | 配置键                         |
| KEYCODE_REFRESH                  | number | 是    | 否    | 刷新键                         |
| KEYCODE_EXIT                     | number | 是    | 否    | 退出键                         |
| KEYCODE_EDIT                     | number | 是    | 否    | 编辑键                         |
| KEYCODE_SCROLLUP                 | number | 是    | 否    | 向上滚动键                       |
| KEYCODE_SCROLLDOWN               | number | 是    | 否    | 向下滚动键                       |
| KEYCODE_NEW                      | number | 是    | 否    | 新建键                         |
| KEYCODE_REDO                     | number | 是    | 否    | 恢复键                         |
| KEYCODE_CLOSE                    | number | 是    | 否    | 关闭键                         |
| KEYCODE_PLAY                     | number | 是    | 否    | 播放键                         |
| KEYCODE_BASSBOOST                | number | 是    | 否    | 低音增强键                       |
| KEYCODE_PRINT                    | number | 是    | 否    | 打印键                         |
| KEYCODE_CHAT                     | number | 是    | 否    | 聊天键                         |
| KEYCODE_FINANCE                  | number | 是    | 否    | 金融键                         |
| KEYCODE_CANCEL                   | number | 是    | 否    | 取消键                         |
| KEYCODE_KBDILLUM_TOGGLE          | number | 是    | 否    | 键盘灯光切换键                     |
| KEYCODE_KBDILLUM_DOWN            | number | 是    | 否    | 键盘灯光调亮键                     |
| KEYCODE_KBDILLUM_UP              | number | 是    | 否    | 键盘灯光调暗键                     |
| KEYCODE_SEND                     | number | 是    | 否    | 发送键                         |
| KEYCODE_REPLY                    | number | 是    | 否    | 答复键                         |
| KEYCODE_FORWARDMAIL              | number | 是    | 否    | 邮件转发键                       |
| KEYCODE_SAVE                     | number | 是    | 否    | 保存键                         |
| KEYCODE_DOCUMENTS                | number | 是    | 否    | 文件键                         |
| KEYCODE_VIDEO_NEXT               | number | 是    | 否    | 下一个视频键                      |
| KEYCODE_VIDEO_PREV               | number | 是    | 否    | 上一个视频键                      |
| KEYCODE_BRIGHTNESS_CYCLE         | number | 是    | 否    | 背光渐变键                       |
| KEYCODE_BRIGHTNESS_ZERO          | number | 是    | 否    | 亮度调节为0键                     |
| KEYCODE_DISPLAY_OFF              | number | 是    | 否    | 显示关闭键                       |
| KEYCODE_BTN_MISC                 | number | 是    | 否    | 游戏手柄上的各种按键                  |
| KEYCODE_GOTO                     | number | 是    | 否    | 进入键                         |
| KEYCODE_INFO                     | number | 是    | 否    | 信息查看键                       |
| KEYCODE_PROGRAM                  | number | 是    | 否    | 程序键                         |
| KEYCODE_PVR                      | number | 是    | 否    | 个人录像机(PVR)键                 |
| KEYCODE_SUBTITLE                 | number | 是    | 否    | 字幕键                         |
| KEYCODE_FULL_SCREEN              | number | 是    | 否    | 全屏键                         |
| KEYCODE_KEYBOARD                 | number | 是    | 否    | 键盘                          |
| KEYCODE_ASPECT_RATIO             | number | 是    | 否    | 屏幕纵横比调节键                    |
| KEYCODE_PC                       | number | 是    | 否    | 端口控制键                       |
| KEYCODE_TV                       | number | 是    | 否    | TV键                         |
| KEYCODE_TV2                      | number | 是    | 否    | TV键2                        |
| KEYCODE_VCR                      | number | 是    | 否    | 录像机开启键                      |
| KEYCODE_VCR2                     | number | 是    | 否    | 录像机开启键2                     |
| KEYCODE_SAT                      | number | 是    | 否    | SIM卡应用工具包（SAT）键             |
| KEYCODE_CD                       | number | 是    | 否    | CD键                         |
| KEYCODE_TAPE                     | number | 是    | 否    | 磁带键                         |
| KEYCODE_TUNER                    | number | 是    | 否    | 调谐器键                        |
| KEYCODE_PLAYER                   | number | 是    | 否    | 播放器键                        |
| KEYCODE_DVD                      | number | 是    | 否    | DVD键                        |
| KEYCODE_AUDIO                    | number | 是    | 否    | 音频键                         |
| KEYCODE_VIDEO                    | number | 是    | 否    | 视频键                         |
| KEYCODE_MEMO                     | number | 是    | 否    | 备忘录键                        |
| KEYCODE_CALENDAR                 | number | 是    | 否    | 日历键                         |
| KEYCODE_RED                      | number | 是    | 否    | 红色指示器                       |
| KEYCODE_GREEN                    | number | 是    | 否    | 绿色指示器                       |
| KEYCODE_YELLOW                   | number | 是    | 否    | 黄色指示器                       |
| KEYCODE_BLUE                     | number | 是    | 否    | 蓝色指示器                       |
| KEYCODE_CHANNELUP                | number | 是    | 否    | 频道向上键                       |
| KEYCODE_CHANNELDOWN              | number | 是    | 否    | 频道向下键                       |
| KEYCODE_LAST                     | number | 是    | 否    | 末尾键                         |
| KEYCODE_RESTART                  | number | 是    | 否    | 重启键                         |
| KEYCODE_SLOW                     | number | 是    | 否    | 慢速键                         |
| KEYCODE_SHUFFLE                  | number | 是    | 否    | 随机播放键                       |
| KEYCODE_VIDEOPHONE               | number | 是    | 否    | 可视电话键                       |
| KEYCODE_GAMES                    | number | 是    | 否    | 游戏键                         |
| KEYCODE_ZOOMIN                   | number | 是    | 否    | 放大键                         |
| KEYCODE_ZOOMOUT                  | number | 是    | 否    | 缩小键                         |
| KEYCODE_ZOOMRESET                | number | 是    | 否    | 缩放重置键                       |
| KEYCODE_WORDPROCESSOR            | number | 是    | 否    | 文字处理键                       |
| KEYCODE_EDITOR                   | number | 是    | 否    | 编辑器键                        |
| KEYCODE_SPREADSHEET              | number | 是    | 否    | 电子表格键                       |
| KEYCODE_GRAPHICSEDITOR           | number | 是    | 否    | 图形编辑器键                      |
| KEYCODE_PRESENTATION             | number | 是    | 否    | 演示文稿键                       |
| KEYCODE_DATABASE                 | number | 是    | 否    | 数据库键标                       |
| KEYCODE_NEWS                     | number | 是    | 否    | 新闻键                         |
| KEYCODE_VOICEMAIL                | number | 是    | 否    | 语音信箱                        |
| KEYCODE_ADDRESSBOOK              | number | 是    | 否    | 通讯簿                         |
| KEYCODE_MESSENGER                | number | 是    | 否    | 通信键                         |
| KEYCODE_BRIGHTNESS_TOGGLE        | number | 是    | 否    | 亮度切换键                       |
| KEYCODE_SPELLCHECK               | number | 是    | 否    | AL拼写检查                      |
| KEYCODE_COFFEE                   | number | 是    | 否    | 终端锁/屏幕保护程序                  |
| KEYCODE_MEDIA_REPEAT             | number | 是    | 否    | 媒体循环键                       |
| KEYCODE_IMAGES                   | number | 是    | 否    | 图像键                         |
| KEYCODE_BUTTONCONFIG             | number | 是    | 否    | 按键配置键                       |
| KEYCODE_TASKMANAGER              | number | 是    | 否    | 任务管理器                       |
| KEYCODE_JOURNAL                  | number | 是    | 否    | 日志按键                        |
| KEYCODE_CONTROLPANEL             | number | 是    | 否    | 控制面板键                       |
| KEYCODE_APPSELECT                | number | 是    | 否    | 应用程序选择键                     |
| KEYCODE_SCREENSAVER              | number | 是    | 否    | 屏幕保护程序键                     |
| KEYCODE_ASSISTANT                | number | 是    | 否    | 辅助键                         |
| KEYCODE_KBD_LAYOUT_NEXT          | number | 是    | 否    | 下一个键盘布局键                    |
| KEYCODE_BRIGHTNESS_MIN           | number | 是    | 否    | 最小亮度键                       |
| KEYCODE_BRIGHTNESS_MAX           | number | 是    | 否    | 最大亮度键                       |
| KEYCODE_KBDINPUTASSIST_PREV      | number | 是    | 否    | 键盘输入Assist_Previous         |
| KEYCODE_KBDINPUTASSIST_NEXT      | number | 是    | 否    | 键盘输入Assist_Next             |
| KEYCODE_KBDINPUTASSIST_PREVGROUP | number | 是    | 否    | 键盘输入Assist_Previous         |
| KEYCODE_KBDINPUTASSIST_NEXTGROUP | number | 是    | 否    | 键盘输入Assist_Next             |
| KEYCODE_KBDINPUTASSIST_ACCEPT    | number | 是    | 否    | 键盘输入Assist_Accept           |
| KEYCODE_KBDINPUTASSIST_CANCEL    | number | 是    | 否    | 键盘输入Assist_Cancel           |
| KEYCODE_FRONT                    | number | 是    | 否    | 挡风玻璃除雾器开关                   |
| KEYCODE_SETUP                    | number | 是    | 否    | 设置键                         |
| KEYCODE_WAKEUP                   | number | 是    | 否    | 唤醒键                         |
| KEYCODE_SENDFILE                 | number | 是    | 否    | 发送文件按键                      |
| KEYCODE_DELETEFILE               | number | 是    | 否    | 删除文件按键                      |
| KEYCODE_XFER                     | number | 是    | 否    | 文件传输(XFER)按键                |
| KEYCODE_PROG1                    | number | 是    | 否    | 程序键1                        |
| KEYCODE_PROG2                    | number | 是    | 否    | 程序键2                        |
| KEYCODE_MSDOS                    | number | 是    | 否    | MS-DOS键（微软磁盘操作系统            |
| KEYCODE_SCREENLOCK               | number | 是    | 否    | 屏幕锁定键                       |
| KEYCODE_DIRECTION_ROTATE_DISPLAY | number | 是    | 否    | 方向旋转显示键                     |
| KEYCODE_CYCLEWINDOWS             | number | 是    | 否    | Windows循环键                  |
| KEYCODE_COMPUTER                 | number | 是    | 否    | 按键                          |
| KEYCODE_EJECTCLOSECD             | number | 是    | 否    | 弹出CD键                       |
| KEYCODE_ISO                      | number | 是    | 否    | ISO键                        |
| KEYCODE_MOVE                     | number | 是    | 否    | 移动键                         |
| KEYCODE_F13                      | number | 是    | 否    | 按键'F13'                     |
| KEYCODE_F14                      | number | 是    | 否    | 按键'F14'                     |
| KEYCODE_F15                      | number | 是    | 否    | 按键'F15'                     |
| KEYCODE_F16                      | number | 是    | 否    | 按键'F16'                     |
| KEYCODE_F17                      | number | 是    | 否    | 按键'F17'                     |
| KEYCODE_F18                      | number | 是    | 否    | 按键'F18'                     |
| KEYCODE_F19                      | number | 是    | 否    | 按键'F19'                     |
| KEYCODE_F20                      | number | 是    | 否    | 按键'F20'                     |
| KEYCODE_F21                      | number | 是    | 否    | 按键'F21'                     |
| KEYCODE_F22                      | number | 是    | 否    | 按键'F22'                     |
| KEYCODE_F23                      | number | 是    | 否    | 按键'F23'                     |
| KEYCODE_F24                      | number | 是    | 否    | 按键'F24'                     |
| KEYCODE_PROG3                    | number | 是    | 否    | 程序键3                        |
| KEYCODE_PROG4                    | number | 是    | 否    | 程序键4                        |
| KEYCODE_DASHBOARD                | number | 是    | 否    | 仪表板                         |
| KEYCODE_SUSPEND                  | number | 是    | 否    | 挂起键                         |
| KEYCODE_HP                       | number | 是    | 否    | 高阶路径键                       |
| KEYCODE_SOUND                    | number | 是    | 否    | 音量键                         |
| KEYCODE_QUESTION                 | number | 是    | 否    | 疑问按键                        |
| KEYCODE_CONNECT                  | number | 是    | 否    | 连接键                         |
| KEYCODE_SPORT                    | number | 是    | 否    | 运动按键                        |
| KEYCODE_SHOP                     | number | 是    | 否    | 商城键                         |
| KEYCODE_ALTERASE                 | number | 是    | 否    | 交替键                         |
| KEYCODE_SWITCHVIDEOMODE          | number | 是    | 否    | 在可用视频之间循环输出（监视器/LCD/TV输出/等） |
| KEYCODE_BATTERY                  | number | 是    | 否    | 电池按键                        |
| KEYCODE_BLUETOOTH                | number | 是    | 否    | 蓝牙按键                        |
| KEYCODE_WLAN                     | number | 是    | 否    | 无线局域网                       |
| KEYCODE_UWB                      | number | 是    | 否    | 超宽带（UWB）                    |
| KEYCODE_WWAN_WIMAX               | number | 是    | 否    | WWAN WiMAX按键                |
| KEYCODE_RFKILL                   | number | 是    | 否    | 控制所有收音机的键                   |
| KEYCODE_CHANNEL                  | number | 是    | 否    | 向上频道键                       |
| KEYCODE_BTN_0                    | number | 是    | 否    | 按键0                         |
| KEYCODE_BTN_1                    | number | 是    | 否    | 按键1                         |
| KEYCODE_BTN_2                    | number | 是    | 否    | 按键2                         |
| KEYCODE_BTN_3                    | number | 是    | 否    | 按键3                         |
| KEYCODE_BTN_4                    | number | 是    | 否    | 按键4                         |
| KEYCODE_BTN_5                    | number | 是    | 否    | 按键5                         |
| KEYCODE_BTN_6                    | number | 是    | 否    | 按键6                         |
| KEYCODE_BTN_7                    | number | 是    | 否    | 按键7                         |
| KEYCODE_BTN_8                    | number | 是    | 否    | 按键8                         |
| KEYCODE_BTN_9                    | number | 是    | 否    | 按键9                         |
