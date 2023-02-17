# memcheck


## Command Function

This command is used to check whether the dynamically allocated memory block is complete and whether nodes in the memory pool are damaged due to out-of-bounds memory access.


## Syntax

memcheck


## Parameters

None.


## Usage Guidelines

- If all nodes in the memory pool are complete, "system memcheck over, all passed!" is displayed.

- If a node in the memory pool is incomplete, information about the memory block of the corrupted node is displayed.


## Example

Run **memcheck**.

Run **memcheck**, and memory overwriting occurs.


## Output

Example 1: No error is detected.

```
OHOS # memcheck
system memcheck over, all passed!
```

Example 2: Memory overwriting is detected.

```
[L0S DLnkCheckMenl 349, memory check
stFreeNodeInfo.pstPrev:0x7e0d31f3 is out of legal mem range[0x80ba5f40, 0х83d00000]
cur node: 0x81f2ce0c
pre node: 0x81f28a98
pre node was allocated by task:sofia
uwEхcTуpe = 0х2
puмExcBuffAddr pc = 0x803ad7a4
puwExcBuffAddr lr = 0x803ad7a4
puwExcBuffAddr sp = 0х80cb7de0
puwExcBuffAddr fp = 0x80cb7dec
***backtrace begin***
traceback 0 -- lr = 0х8037cb84
traceback 0 -- fp = 0х80cb7e1c
traceback 1 -- lr = 0х8037033c
traceback 1 -- fp = 0х80cb7e24
traceback 2 -- lr = 0x8000d108
traceback 2 -- fp = 0х80cb7e94
traceback 3 -- lr = 0х8037c7ac
traceback 3 -- fp = 0х80cb7ea4
traceback 4 -- lr = 0x803ad9e8
traceback 4 -- fp = 9x11111111
```
