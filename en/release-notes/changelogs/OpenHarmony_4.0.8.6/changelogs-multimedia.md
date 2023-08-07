# Multimedia Subsystem Changelog

## cl.multimedia.1 Reference Paths Changed for the Audio/Video Encapsulation and Decapsulation Header Files

| Header File         | Original Reference Path                 | New Reference Path               |
| ------------------------------- | ------------------------------------- | ------------------------------------- |
| native_avmuxer.h | <multimedia/native_avmuxer.h> | <multimedia/player_framework/native_avmuxer.h> |
| native_avdemuxer.h  | <multimedia/native_avdemuxer.h>               | <multimedia/player_framework/native_avdemuxer.h>               |
| native_avsource.h  | <multimedia/native_avsource.h>               | <multimedia/player_framework/native_avsource.h>               |

**Change Impact**

Applications that use the involved APIs may have compatibility issues.

**Adaptation Guide**

Modify the reference paths when referencing the encapsulation and decapsulation header files.
