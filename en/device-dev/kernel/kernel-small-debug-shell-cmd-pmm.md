# pmm


## Command Function

This command is used to check the usage of the physical pages of the system memory and the page cache.


## Syntax

pmm


## Parameters

None.


## Usage Guidelines

This command is available only in the **Debug** version.


## Example

Run **pmm**.


## Output

Usage of physical pages:

```
OHOS # pmm
 phys_seg      base         size        free_pages
 --------      -------      ----------  ---------
 0x4065552c    0x809b0000   0x07550000      22344
order = 0, free_count = 16
order = 1, free_count = 12
order = 2, free_count = 8
order = 3, free_count = 6
order = 4, free_count = 13
order = 5, free_count = 16
order = 6, free_count = 12
order = 7, free_count = 4
order = 8, free_count = 79
active   anon   0
inactive anon   0
active   file   1385
inactice file   84
pmm pages: total = 30032, used = 7688, free = 22344
pathCache number = 325
pathCache memory size = 17621(B)
Vnode number = 67
Vnode memory size = 10720(B)
```

**Table 1** Output description

| Parameter| Description|
| -------- | -------- |
| phys_seg | Address of the physical page control block.|
| base | First physical page address, that is, start address of the physical page memory.|
| size | Size of the physical page memory.|
| free_pages | Number of free physical pages.|
| active&nbsp;anon | Number of active anonymous pages in the page cache.|
| inactive&nbsp;anon | Number of inactive anonymous pages in the page cache.|
| active&nbsp;file | Number of active file pages in the page cache.|
| inactive&nbsp;file | Number of inactive file pages in the page cache.|
| pmm&nbsp;pages | **total** indicates the total number of physical pages. <br/>**used** indicates the number of used physical pages. <br/>**free** indicates the number of idle physical pages. |

