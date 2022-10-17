# Keycode

The Keycode module provides keycodes for a key device.

> **NOTE**<br>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import {KeyCode} from '@ohos.multimodalInput.keyCode'
```

## KeyCode

**System capability**: SystemCapability.MultimodalInput.Input.Core

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| KEYCODE_FN | number | Yes| No| Function (Fn) key|
| KEYCODE_UNKNOWN | number | Yes| No|  Unknown key|
| KEYCODE_HOME | number | Yes| No| Home key |
| KEYCODE_BACK | number | Yes| No|  Back key|
| KEYCODE_MEDIA_PLAY_PAUSE | number | Yes| No| Play/Pause key|
| KEYCODE_MEDIA_STOP | number | Yes| No| Stop key|
| KEYCODE_MEDIA_NEXT | number | Yes| No| Next key|
| KEYCODE_MEDIA_PREVIOUS | number | Yes| No| Previous key|
| KEYCODE_MEDIA_REWIND | number | Yes| No| Rewind key|
| KEYCODE_MEDIA_FAST_FORWARD | number | Yes| No| Fast Forward key|
| KEYCODE_VOLUME_UP | number | Yes| No| Volume Up key|
| KEYCODE_VOLUME_DOWN | number | Yes| No| Volume Down key|
| KEYCODE_POWER | number | Yes| No| Power key|
| KEYCODE_CAMERA | number | Yes| No| Camera key|
| KEYCODE_VOLUME_MUTE | number | Yes| No| Speaker Mute key|
| KEYCODE_MUTE | number | Yes| No| Mute key|
| KEYCODE_BRIGHTNESS_UP | number | Yes| No| Brightness Up key|
| KEYCODE_BRIGHTNESS_DOWN | number | Yes| No| Brightness Down key|
| KEYCODE_0 | number | Yes| No| Key 0|
| KEYCODE_1 | number | Yes| No| Key 1|
| KEYCODE_2 | number | Yes| No| Key 2|
| KEYCODE_3 | number | Yes| No| Key 3|
| KEYCODE_4 | number | Yes| No| Key 4|
| KEYCODE_5 | number | Yes| No| Key 5|
| KEYCODE_6 | number | Yes| No| Key 6|
| KEYCODE_7 | number | Yes| No| Key 7|
| KEYCODE_8 | number | Yes| No| Key 8|
| KEYCODE_9 | number | Yes| No| Key 9|
| KEYCODE_STAR | number | Yes| No| Key *|
| KEYCODE_POUND | number | Yes| No| Key #|
| KEYCODE_DPAD_UP | number | Yes| No|  Up key on D-pad|
| KEYCODE_DPAD_DOWN | number | Yes| No|  Down key on D-pad|
| KEYCODE_DPAD_LEFT | number | Yes| No|  Left key on D-pad|
| KEYCODE_DPAD_RIGHT | number | Yes| No| Right key on D-pad|
| KEYCODE_DPAD_CENTER | number | Yes| No| Center key on D-pad|
| KEYCODE_A | number | Yes| No| Key A|
| KEYCODE_B | number | Yes| No| Key B|
| KEYCODE_C | number | Yes| No| Key C|
| KEYCODE_D | number | Yes| No| Key D|
| KEYCODE_E | number | Yes| No| Key E|
| KEYCODE_F | number | Yes| No| Key F|
| KEYCODE_G | number | Yes| No| Key G|
| KEYCODE_H | number | Yes| No| Key H|
| KEYCODE_I | number | Yes| No| Key I|
| KEYCODE_J | number | Yes| No| Key J|
| KEYCODE_K | number | Yes| No| Key K|
| KEYCODE_L | number | Yes| No| Key L|
| KEYCODE_M | number | Yes| No| Key M|
| KEYCODE_N | number | Yes| No| Key N|
| KEYCODE_O | number | Yes| No| Key O|
| KEYCODE_P | number | Yes| No| Key P|
| KEYCODE_Q | number | Yes| No| Key Q|
| KEYCODE_R | number | Yes| No| Key R|
| KEYCODE_S | number | Yes| No| Key S|
| KEYCODE_T | number | Yes| No| Key T|
| KEYCODE_U | number | Yes| No| Key U|
| KEYCODE_V | number | Yes| No| Key V|
| KEYCODE_W | number | Yes| No| Key W|
| KEYCODE_X | number | Yes| No| Key X|
| KEYCODE_Y | number | Yes| No| Key Y|
| KEYCODE_Z | number | Yes| No| Key Z|
| KEYCODE_COMMA | number | Yes| No| Key ,|
| KEYCODE_PERIOD | number | Yes| No|  Key .|
| KEYCODE_ALT_LEFT | number | Yes| No| Alt+Left key|
| KEYCODE_ALT_RIGHT | number | Yes| No| Alt+Right key|
| KEYCODE_SHIFT_LEFT | number | Yes| No| Shift+Left key|
| KEYCODE_SHIFT_RIGHT | number | Yes| No| Shift+Right key|
| KEYCODE_TAB | number | Yes| No| Tab key|
| KEYCODE_SPACE | number | Yes| No| Space key|
| KEYCODE_SYM | number | Yes| No| Symbol key|
| KEYCODE_EXPLORER | number | Yes| No| Explorer key, which is used to start the explorer application|
| KEYCODE_ENVELOPE | number | Yes| No| Email key, which is used to start the email application|
| KEYCODE_ENTER | number | Yes| No| Enter key|
| KEYCODE_DEL | number | Yes| No| Delete key|
| KEYCODE_GRAVE | number | Yes| No| Key `|
| KEYCODE_MINUS | number | Yes| No| Key -|
| KEYCODE_EQUALS | number | Yes| No| Key =|
| KEYCODE_LEFT_BRACKET | number | Yes| No| Key [|
| KEYCODE_RIGHT_BRACKET | number | Yes| No| Key ]|
| KEYCODE_BACKSLASH | number | Yes| No| Key \\|
| KEYCODE_SEMICOLON | number | Yes| No| Key ;|
| KEYCODE_APOSTROPHE | number | Yes| No| Key ' |
| KEYCODE_SLASH | number | Yes| No| Key /|
| KEYCODE_AT | number | Yes| No| Key @|
| KEYCODE_PLUS | number | Yes| No| Key +|
| KEYCODE_MENU | number | Yes| No| Menu key|
| KEYCODE_PAGE_UP | number | Yes| No|  Page Up key|
| KEYCODE_PAGE_DOWN | number | Yes| No| Page Down key|
| KEYCODE_ESCAPE | number | Yes| No| ESC key|
| KEYCODE_FORWARD_DEL | number | Yes| No| Delete key|
| KEYCODE_CTRL_LEFT | number | Yes| No| Control+Left |
| KEYCODE_CTRL_RIGHT | number | Yes| No| Control+Right |
| KEYCODE_CAPS_LOCK | number | Yes| No| Caps Lock key|
| KEYCODE_SCROLL_LOCK | number | Yes| No| Scroll Lock key|
| KEYCODE_META_LEFT | number | Yes| No| Left Meta key|
| KEYCODE_META_RIGHT | number | Yes| No| Right Meta key|
| KEYCODE_FUNCTION | number | Yes| No| Function key|
| KEYCODE_SYSRQ | number | Yes| No| System Request/Print Screen key|
| KEYCODE_BREAK | number | Yes| No| Break/Pause key|
| KEYCODE_MOVE_HOME | number | Yes| No| Move to Home key|
| KEYCODE_MOVE_END | number | Yes| No| Move to End key|
| KEYCODE_INSERT | number | Yes| No| Insert key|
| KEYCODE_FORWARD | number | Yes| No| Delete key |
| KEYCODE_MEDIA_PLAY | number | Yes| No| Play key|
| KEYCODE_MEDIA_PAUSE | number | Yes| No| Pause key|
| KEYCODE_MEDIA_CLOSE | number | Yes| No| Close key|
| KEYCODE_MEDIA_EJECT | number | Yes| No| Eject key|
| KEYCODE_MEDIA_RECORD | number | Yes| No| Record key|
| KEYCODE_F1 | number | Yes| No| F1 key|
| KEYCODE_F2 | number | Yes| No| F2 key|
| KEYCODE_F3 | number | Yes| No| F3 key|
| KEYCODE_F4 | number | Yes| No| F4 key|
| KEYCODE_F5 | number | Yes| No| F5 key|
| KEYCODE_F6 | number | Yes| No| F6 key|
| KEYCODE_F7 | number | Yes| No| F7 key|
| KEYCODE_F8 | number | Yes| No| F8 key|
| KEYCODE_F9 | number | Yes| No| F9 key|
| KEYCODE_F10 | number | Yes| No| F10 key|
| KEYCODE_F11 | number | Yes| No| F11 key|
| KEYCODE_F12 | number | Yes| No| F12 key|
| KEYCODE_NUM_LOCK | number | Yes| No| Number Lock key|
| KEYCODE_NUMPAD_0 | number | Yes| No| Key 0 on numeric keypad|
| KEYCODE_NUMPAD_1 | number | Yes| No| Key 1 on numeric keypad|
| KEYCODE_NUMPAD_2 | number | Yes| No| Key 2 on numeric keypad|
| KEYCODE_NUMPAD_3 | number | Yes| No| Key 3 on numeric keypad|
| KEYCODE_NUMPAD_4 | number | Yes| No| Key 4 on numeric keypad|
| KEYCODE_NUMPAD_5 | number | Yes| No| Key 5 on numeric keypad|
| KEYCODE_NUMPAD_6 | number | Yes| No| Key 6 on numeric keypad|
| KEYCODE_NUMPAD_7 | number | Yes| No| Key 7 on numeric keypad|
| KEYCODE_NUMPAD_8 | number | Yes| No| Key 8 on numeric keypad|
| KEYCODE_NUMPAD_9 | number | Yes| No| Key 9 on numeric keypad|
| KEYCODE_NUMPAD_DIVIDE | number | Yes| No| Key / on numeric keypad|
| KEYCODE_NUMPAD_MULTIPLY | number | Yes| No| Key * on numeric keypad|
| KEYCODE_NUMPAD_SUBTRACT | number | Yes| No| Key - on numeric keypad|
| KEYCODE_NUMPAD_ADD | number | Yes| No| Key + on numeric keypad|
| KEYCODE_NUMPAD_DOT | number | Yes| No| Key . on numeric keypad|
| KEYCODE_NUMPAD_COMMA | number | Yes| No| Key , on numeric keypad|
| KEYCODE_NUMPAD_ENTER | number | Yes| No| Enter key on numeric keypad|
| KEYCODE_NUMPAD_EQUALS | number | Yes| No| Key = on numeric keypad|
| KEYCODE_NUMPAD_LEFT_PAREN | number | Yes| No| Key ( on numeric keypad|
| KEYCODE_NUMPAD_RIGHT_PAREN | number | Yes| No| Key ) on numeric keypad|
| KEYCODE_VIRTUAL_MULTITASK | number | Yes| No| Multi-task key|
| KEYCODE_SLEEP | number | Yes| No| Sleep key|
| KEYCODE_ZENKAKU_HANKAKU | number | Yes| No| Zenkaku/Hankaku key|
| KEYCODE_102ND | number | Yes| No| 102nd key|
| KEYCODE_RO | number | Yes| No| Ro key|
| KEYCODE_KATAKANA | number | Yes| No| Katakana key|
| KEYCODE_HIRAGANA | number | Yes| No| Hiragana key|
| KEYCODE_HENKAN | number | Yes| No| Henkan key|
| KEYCODE_KATAKANA_HIRAGANA | number | Yes| No| Katakana/Hiragana key|
| KEYCODE_MUHENKAN | number | Yes| No| Muhenkan key|
| KEYCODE_LINEFEED | number | Yes| No| Linefeed key|
| KEYCODE_MACRO | number | Yes| No| Macro key|
| KEYCODE_NUMPAD_PLUSMINUS | number | Yes| No| Plus/Minus key on the numeric keypad|
| KEYCODE_SCALE | number | Yes| No| Scale key|
| KEYCODE_HANGUEL | number | Yes| No| Hanguel key|
| KEYCODE_HANJA | number | Yes| No| Hanja key|
| KEYCODE_YEN | number | Yes| No| Yen key|
| KEYCODE_STOP | number | Yes| No| Stop key|
| KEYCODE_AGAIN | number | Yes| No| Again key|
| KEYCODE_PROPS | number | Yes| No| Props key|
| KEYCODE_UNDO | number | Yes| No| Undo key|
| KEYCODE_COPY | number | Yes| No| Copy key|
| KEYCODE_OPEN | number | Yes| No| Open key|
| KEYCODE_PASTE | number | Yes| No| Paste key|
| KEYCODE_FIND | number | Yes| No| Find key|
| KEYCODE_CUT | number | Yes| No| Cut key|
| KEYCODE_HELP | number | Yes| No| Help key|
| KEYCODE_CALC | number | Yes| No| Calc key, which is used to start the calculator application|
| KEYCODE_FILE | number | Yes| No| File key|
| KEYCODE_BOOKMARKS | number | Yes| No| Bookmarks key|
| KEYCODE_NEXT | number | Yes| No| Next key|
| KEYCODE_PLAYPAUSE | number | Yes| No| Play/Pause key|
| KEYCODE_PREVIOUS | number | Yes| No| Previous key|
| KEYCODE_STOPCD | number | Yes| No| Stop CD key|
| KEYCODE_CONFIG | number | Yes| No| Config key|
| KEYCODE_REFRESH | number | Yes| No| Refresh key|
| KEYCODE_EXIT | number | Yes| No| Exit key|
| KEYCODE_EDIT | number | Yes| No| Edit key|
| KEYCODE_SCROLLUP | number | Yes| No| Scroll Up key|
| KEYCODE_SCROLLDOWN | number | Yes| No| Scroll Down key|
| KEYCODE_NEW | number | Yes| No| New key|
| KEYCODE_REDO | number | Yes| No| Redo key|
| KEYCODE_CLOSE | number | Yes| No| Close key|
| KEYCODE_PLAY | number | Yes| No| Play key|
| KEYCODE_BASSBOOST | number | Yes| No| Bass Boost key|
| KEYCODE_PRINT | number | Yes| No| Print key|
| KEYCODE_CHAT | number | Yes| No| Chat key|
| KEYCODE_FINANCE | number | Yes| No| Finance key|
| KEYCODE_CANCEL | number | Yes| No| Cancel key|
| KEYCODE_KBDILLUM_TOGGLE | number | Yes| No| Keyboard Illumination Toggle key|
| KEYCODE_KBDILLUM_DOWN | number | Yes| No| Keyboard Illumination Up key|
| KEYCODE_KBDILLUM_UP | number | Yes| No| Keyboard Illumination Down key|
| KEYCODE_SEND | number | Yes| No| Send key|
| KEYCODE_REPLY | number | Yes| No| Reply key|
| KEYCODE_FORWARDMAIL | number | Yes| No| Forward Mail key|
| KEYCODE_SAVE | number | Yes| No| Save key|
| KEYCODE_DOCUMENTS | number | Yes| No| Documents key|
| KEYCODE_VIDEO_NEXT | number | Yes| No| Next Video key|
| KEYCODE_VIDEO_PREV | number | Yes| No| Previous Video key|
| KEYCODE_BRIGHTNESS_CYCLE | number | Yes| No| Brightness Cycle key|
| KEYCODE_BRIGHTNESS_ZERO | number | Yes| No| Brightness Zero key|
| KEYCODE_DISPLAY_OFF | number | Yes| No| Display Off Key|
| KEYCODE_BTN_MISC | number | Yes| No| Misc Button key|
| KEYCODE_GOTO | number | Yes| No| Goto key|
| KEYCODE_INFO | number | Yes| No| Info key|
| KEYCODE_PROGRAM | number | Yes| No| Program key|
| KEYCODE_PVR | number | Yes| No| PVR key|
| KEYCODE_SUBTITLE | number | Yes| No| Subtitle key|
| KEYCODE_FULL_SCREEN | number | Yes| No| Full Screen key|
| KEYCODE_KEYBOARD | number | Yes| No| Keyboard|
| KEYCODE_ASPECT_RATIO | number | Yes| No| Aspect Ratio key|
| KEYCODE_PC | number | Yes| No| Port Control key|
| KEYCODE_TV | number | Yes| No| TV key|
| KEYCODE_TV2 | number | Yes| No| TV key 2|
| KEYCODE_VCR | number | Yes| No| VCR key|
| KEYCODE_VCR2 | number | Yes| No| VCR key 2|
| KEYCODE_SAT | number | Yes| No| SAT key|
| KEYCODE_CD | number | Yes| No| CD key|
| KEYCODE_TAPE | number | Yes| No| Tape key|
| KEYCODE_TUNER | number | Yes| No| Tuner key|
| KEYCODE_PLAYER | number | Yes| No| Player key|
| KEYCODE_DVD | number | Yes| No| DVD key|
| KEYCODE_AUDIO | number | Yes| No| Audio key|
| KEYCODE_VIDEO | number | Yes| No| Video key|
| KEYCODE_MEMO | number | Yes| No| Memo key|
| KEYCODE_CALENDAR | number | Yes| No| Calendar key|
| KEYCODE_RED | number | Yes| No| Red indicator|
| KEYCODE_GREEN | number | Yes| No| Green indicator|
| KEYCODE_YELLOW | number | Yes| No| Yellow indicator|
| KEYCODE_BLUE | number | Yes| No| Blue indicator|
| KEYCODE_CHANNELUP | number | Yes| No| Channel Up key|
| KEYCODE_CHANNELDOWN | number | Yes| No| Channel Down key|
| KEYCODE_LAST | number | Yes| No| Last key|
| KEYCODE_RESTART | number | Yes| No| Restart key|
| KEYCODE_SLOW | number | Yes| No| Slow key|
| KEYCODE_SHUFFLE | number | Yes| No| Shuffle key|
| KEYCODE_VIDEOPHONE | number | Yes| No| Videophone key|
| KEYCODE_GAMES | number | Yes| No| Games key|
| KEYCODE_ZOOMIN | number | Yes| No| Zoom-in key|
| KEYCODE_ZOOMOUT | number | Yes| No| Zoom-out key|
| KEYCODE_ZOOMRESET | number | Yes| No| Zoom Reset key|
| KEYCODE_WORDPROCESSOR | number | Yes| No| Word Processor key|
| KEYCODE_EDITOR | number | Yes| No| Editor key|
| KEYCODE_SPREADSHEET | number | Yes| No| Spreadsheet key|
| KEYCODE_GRAPHICSEDITOR | number | Yes| No| Graphics Editor key|
| KEYCODE_PRESENTATION | number | Yes| No| Presentation key|
| KEYCODE_DATABASE | number | Yes| No| Database key|
| KEYCODE_NEWS | number | Yes| No| News key|
| KEYCODE_VOICEMAIL | number | Yes| No| Voicemail key|
| KEYCODE_ADDRESSBOOK | number | Yes| No| Addressbook key|
| KEYCODE_MESSENGER | number | Yes| No| Messenger key|
| KEYCODE_BRIGHTNESS_TOGGLE | number | Yes| No| Brightness Toggle key|
| KEYCODE_SPELLCHECK | number | Yes| No| Spell Check key|
| KEYCODE_COFFEE | number | Yes| No| Coffee key, which is used to launch screen lock or screen saver|
| KEYCODE_MEDIA_REPEAT | number | Yes| No| Media Repeat key|
| KEYCODE_IMAGES | number | Yes| No| Images key|
| KEYCODE_BUTTONCONFIG | number | Yes| No| Button Configuration key|
| KEYCODE_TASKMANAGER | number | Yes| No| Task Manager key|
| KEYCODE_JOURNAL | number | Yes| No| Log key|
| KEYCODE_CONTROLPANEL | number | Yes| No| Control Panel key|
| KEYCODE_APPSELECT | number | Yes| No| App Select key|
| KEYCODE_SCREENSAVER | number | Yes| No| Screen Saver key|
| KEYCODE_ASSISTANT | number | Yes| No| Assistant key|
| KEYCODE_KBD_LAYOUT_NEXT | number | Yes| No| Next Keyboard Layout key|
| KEYCODE_BRIGHTNESS_MIN | number | Yes| No| Min Brightness key|
| KEYCODE_BRIGHTNESS_MAX | number | Yes| No| Max Brightness key|
| KEYCODE_KBDINPUTASSIST_PREV | number | Yes| No| Keyboard Input-assisted Previous key|
| KEYCODE_KBDINPUTASSIST_NEXT | number | Yes| No| Keyboard Input-assisted Next key|
| KEYCODE_KBDINPUTASSIST_PREVGROUP | number | Yes| No| Keyboard Input-assisted Previous Group key|
| KEYCODE_KBDINPUTASSIST_NEXTGROUP | number | Yes| No| Keyboard Input-assisted Next Group key|
| KEYCODE_KBDINPUTASSIST_ACCEPT | number | Yes| No| Keyboard Input-assisted Accept key|
| KEYCODE_KBDINPUTASSIST_CANCEL | number | Yes| No| Keyboard Input-assisted Cancel key|
| KEYCODE_FRONT | number | Yes| No| Front key, which is used to launch the windshield defogger|
| KEYCODE_SETUP | number | Yes| No| Setup key|
| KEYCODE_WAKEUP | number | Yes| No| Wakeup key|
| KEYCODE_SENDFILE | number | Yes| No| Send File key|
| KEYCODE_DELETEFILE | number | Yes| No| Delete File key|
| KEYCODE_XFER | number | Yes| No| XFER key, which is used to start file transfer|
| KEYCODE_PROG1 | number | Yes| No| Program key 1|
| KEYCODE_PROG2 | number | Yes| No| Program key 2|
| KEYCODE_MSDOS | number | Yes| No| MS-DOS key|
| KEYCODE_SCREENLOCK | number | Yes| No| Screen Lock key|
| KEYCODE_DIRECTION_ROTATE_DISPLAY | number | Yes| No| Directional Rotation Display key|
| KEYCODE_CYCLEWINDOWS | number | Yes| No| Windows Cycle key|
| KEYCODE_COMPUTER | number | Yes| No| Key |
| KEYCODE_EJECTCLOSECD | number | Yes| No| Eject CD key|
| KEYCODE_ISO | number | Yes| No| ISO key|
| KEYCODE_MOVE | number | Yes| No| Move key|
| KEYCODE_F13 | number | Yes| No| F13 key|
| KEYCODE_F14 | number | Yes| No| F14 key|
| KEYCODE_F15 | number | Yes| No| F15 key|
| KEYCODE_F16 | number | Yes| No| F16 key|
| KEYCODE_F17 | number | Yes| No| F17 key|
| KEYCODE_F18 | number | Yes| No| F18 key|
| KEYCODE_F19 | number | Yes| No| F19 key|
| KEYCODE_F20 | number | Yes| No| F20 key|
| KEYCODE_F21 | number | Yes| No| F21 key|
| KEYCODE_F22 | number | Yes| No| F22 key|
| KEYCODE_F23 | number | Yes| No| F23 key|
| KEYCODE_F24 | number | Yes| No| F24 key|
| KEYCODE_PROG3 | number | Yes| No| Program key 3|
| KEYCODE_PROG4 | number | Yes| No| Program key 4|
| KEYCODE_DASHBOARD | number | Yes| No| Dashboard|
| KEYCODE_SUSPEND | number | Yes| No| Suspend key|
| KEYCODE_HP | number | Yes| No| HP key|
| KEYCODE_SOUND | number | Yes| No| Sound key|
| KEYCODE_QUESTION | number | Yes| No| Question key|
| KEYCODE_CONNECT | number | Yes| No| Connect key|
| KEYCODE_SPORT | number | Yes| No| Sport key|
| KEYCODE_SHOP | number | Yes| No| Shop key|
| KEYCODE_ALTERASE | number | Yes| No| Alternate key|
| KEYCODE_SWITCHVIDEOMODE | number | Yes| No| Switch Video Mode key (monitor, LCD, and TV, etc.)|
| KEYCODE_BATTERY | number | Yes| No| Battery key|
| KEYCODE_BLUETOOTH | number | Yes| No| Bluetooth key|
| KEYCODE_WLAN | number | Yes| No| WLAN key|
| KEYCODE_UWB | number | Yes| No| Ultra-wideband key|
| KEYCODE_WWAN_WIMAX | number | Yes| No| WWAN WiMAX key|
| KEYCODE_RFKILL | number | Yes| No| RF Kill key|
| KEYCODE_CHANNEL | number | Yes| No| Channel key|
| KEYCODE_BTN_0 | number | Yes| No| Key 0|
| KEYCODE_BTN_1 | number | Yes| No| Button 1|
| KEYCODE_BTN_2 | number | Yes| No| Button 2|
| KEYCODE_BTN_3 | number | Yes| No| Button 3|
| KEYCODE_BTN_4 | number | Yes| No| Button 4|
| KEYCODE_BTN_5 | number | Yes| No| Button 5|
| KEYCODE_BTN_6 | number | Yes| No| Button 6|
| KEYCODE_BTN_7 | number | Yes| No| Button 7|
| KEYCODE_BTN_8 | number | Yes| No| Button 8|
| KEYCODE_BTN_9 | number | Yes| No| Button 9|
