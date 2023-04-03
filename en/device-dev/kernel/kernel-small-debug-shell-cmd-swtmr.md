# swtmr


## Command Function

This command is used to query information about system software timers.


## Syntax

swtmr [_ID_]


## Parameters

**Table 1** Parameter description

| Parameter| Description| Value Range|
| -------- | -------- | -------- |
| ID | Specifies the ID of a software timer.| [0, 0xFFFFFFFF] |


## Usage Guidelines

- If no parameter is specified, information about all software timers is displayed.

- If the **ID** parameter is specified, information about the specified software timer is displayed.


## Example

Run the following commands:

- swtmr

- swtmr 1


## Output

Example 1: information about all software timers

```
OHOS # swtmr
SwTmrID     State    Mode    Interval  Count   Arg         handlerAddr
----------  -------  ------- --------- ------- ----------  --------
0x00000000  Ticking  Period   100      77      0x40802a50  0x4037b8a0
SwTmrID     State    Mode    Interval  Count   Arg         handlerAddr
----------  -------  ------- --------- ------- ----------  --------
0x00000001  Ticking  Period   1000     876     0x00000000  0x4037fc04
SwTmrID     State    Mode    Interval  Count   Arg         handlerAddr
----------  -------  ------- --------- ------- ----------  --------
0x00000002  Ticking  Period   100      76      0x00000000  0x403727f4
SwTmrID     State    Mode    Interval  Count   Arg         handlerAddr
----------  -------  ------- --------- ------- ----------  --------
0x00000016  Ticking  NSD      10       6       0x8021e000  0x401fe7d8
SwTmrID     State    Mode    Interval  Count   Arg         handlerAddr
----------  -------  ------- --------- ------- ----------  --------
0x00000079  Ticking  NSD      30000    1749    0x406189d8  0x40160e1c
```

Example 2: information about software timer 1

```
OHOS # swtmr 1
SwTmrID     State    Mode    Interval  Count   Arg         handlerAddr
----------  -------  ------- --------- ------- ----------  --------
0x00000001  Ticking  Period   1000     841     0x00000000  0x4037fc04
```

  **Table 2** Output description

| Parameter| Description|
| -------- | -------- |
| SwTmrID | ID of the software timer.|
| State | Status of the software timer.<br>The status may be **UnUsed**, **Created**, or **Ticking**.|
| Mode | Mode of the software timer.<br>The value can be **Once**, **Period**, or **NSD** (one-shot timer that will not be automatically deleted after the timer has expired).|
| Interval | Number of ticks for the software timer.|
| Count | Number of times that the software timer has been used.|
| Arg | Input parameter.|
| handlerAddr | Address of the callback.|

> **NOTE**<br>
> - The **ID** value can be in decimal or hexadecimal format.
> 
> - If the **ID** value is within the range of [0, *Number of current software timers - 1*], the status of the specified software timer is returned. Otherwise, an error code is returned.
