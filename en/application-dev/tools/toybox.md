# Toybox

Toybox is a lightweight collection of Linux command line utilities. It combines many common Linux command line utilities into a single executable file.

## Prerequisites

### Usage 1

- Connect the device properly.
- Run the **hdc shell** command to enter the command line execution mode.

### Usage 2

- Enter the application sandbox.

> **NOTE**
>
>Due to permission control, if the commands are run in a process, directory, or file that is not authorized, the command execution fails.
>
>In the case of such a failure, check the authorization status. You can find the error information in the log.

## Command Description

Toybox can be executed in either of the following ways:

- Use **toybox cmd [arg...]**.
- Create a symbolic link from cmd to Toybox and directly call cmd.

A symbolic link has been created in the system. You can directly use the commands.

| Command| Parameter| Description|
| :- | :- | :- |
| --help | NA | Displays the command help.|
| --long | NA | Displays all supported commands along with their respective installation path.|
| NA | NA | Displays all supported commands.|

### Help Command

Format: help [-ah] [command]

| Parameter| Description|
| :- | :- |
| command | Displays the command help.|

| Option| Description|
| :- | :- |
| -a | Displays the help information about all commands.|
| -h | Displays the help information in HTML format.|

### Math Calculation and Random Number

| Command| Description|
| :- | :- |
| factor     | Factors an integer.<br>usage: factor NUMBER... |
| mcookie    | Generates a 128-bit strong random number.<br>usage: mcookie [-vV] |
| uuidgen    | Creates and prints a new RFC4122 random UUID.<br>usage: uuidgen |

### Terminal Operations

| Command| Description|
| :- | :- |
| nohup | Runs a command independent of the terminal.<br>usage: nohup [COMMAND [ARGS...]] |
| reset | Resets the terminal.<br>usage: reset |
| clear | Clears the terminal.<br>usage: clear |

### sh Logical Commands

| Command| Description|
| :- | :- |
| false | Returns a non-zero value.<br>usage: false |
| sh    | shell command interpreter.|
| test  | Returns **true** or **false** by performing tests. If no parameter is carried, **false** is returned.<br>usage: test [-bcdefghLPrSsuwx PATH] [-nz STRING] [-t FD] [X ?? Y] |
| true  | Returns zero.<br>usage: true |
| yes   | Outputs lines repeatedly until it is killed. If no parameter is carried, **y** is returned.<br>usage: yes [args...] |

### System Call Operations (Query Only)

| Command| Description|
| :- | :- |
| hostname | Obtains the current host name.<br>usage: hostname [-bdsf] [-F FILENAME] [newname] |
| nproc    | Prints the number of processors.<br>usage: nproc [--all] |
| printenv | Prints environment variables.<br>usage: printenv [-0] [env\_var...] |
| uname    | Prints system information.<br>usage: uname [-asnrvm] |
| iotop    | Ranks processes by I/O.<br>usage: iotop [-AaKObq] [-n NUMBER] [-d SECONDS] [-p PID,] [-u USER,] |
| env      | Sets the environment for command execution or lists environment variables.<br>usage: env [-i] [-u NAME] [NAME=VALUE...] [COMMAND [ARG...]] |

### Time and Date

| Command| Description|
| :- | :- |
| cal    | Prints a calendar.<br>usage: cal [[month] year] |
| date   | Obtains the current date and time.<br>usage: date [-u] [-r FILE] [-d DATE] [+DISPLAY\_FORMAT] [-D  SET\_FORMAT] [SET] |
| sleep  | Waits before exiting. The value can be a decimal. The optional suffix can be "m" (minute), "h" (hour), "d" (day), or "s" (second, default value).<br>usage: sleep DURATION... |
| time   | Runs the command line and reports the real time, user time, and system time (in seconds). The real time is the wall clock time, the user time is the actual CPU time spend in user-mode, and the system time is the actual CPU time sped in the kernel.<br>usage: time [-pv] COMMAND [ARGS...] |
| uptime | Displays the current time, how long the system has been running, the number of users, and the average system load in the past 1, 5, and 15 minutes.<br>usage: uptime [-ps] |
| usleep | Pauses for a given number of microseconds.<br>usage: usleep MICROSECONDS |

### Login User Operations (Query Only)

| Command| Description|
| :- | :- |
| groups  | Prints the group to which the user belongs.<br>usage: groups [user] |
| id      | Prints the user and group ID.<br>usage: id [-nGgru] [USER...] |
| logname | Prints the current user name.<br>usage: logname |
| who     | Prints information about logged in users.<br>usage: who |
| whoami  | Prints the current user name.<br>usage: whoami |

### Process Operations

In the case of hdc shell, only the **pidof**, **ps**, **watch**, and **xargs** commands are supported.<br>
In the case of an application sandbox, process operations can be performed only in the namespace of the current application.
> **NOTE**
>
>If the commands listed below are run in a process that is not authorized, the command execution fails.

| Command| Description|
| :- | :- |
| kill | Sends a signal to a process.<br>usage: kill [-l [SIGNAL] \| -s SIGNAL \| -SIGNAL] PID... |
| killall | Sends a signal (**Term** by default) to all processes with the given name.<br>usage: killall [-l] [-iqv] [-SIGNAL \|-s SIGNAL ]  PROCESS\_NAME... |
| pidof   | Prints the PIDs of all processes with the given name.<br>usage: pidof [-s] [-o omitpid[,omitpid...]] [NAME]... |
| pkill   | Kills a process by process name.<br>usage: pkill [-fnovx]  [-SIGNAL\|-l SIGNAL] [PATTERN] [-G GID,] [-g PGRP,] [-P PPID,] [-s SID,] [-t  TERM,] [-U UID,] [-u EUID,] |
| ps      | Lists processes.<br>usage: ps [-AadefLlnwZ] [-gG GROUP,] [-k FIELD,] [-o FIELD,] [-p PID,] [-t  TTY,] [-uU USER,] |
| pwdx    | Prints the working directory of the process.<br>usage: pwdx PID... |
| timeout | Runs a command in a child process and if the command execution is not complete within a time limit, sends a signal. The value of **DURATION** can be a decimal. The optional suffix can be "m" (minute), "h" (hour), "d" (day), or "s" (second, default value).<br>usage: timeout [-k DURATION] [-s SIGNAL] DURATION COMMAND... |
| top     | Displays process information in real time.<br>usage: top [-Hbq] [-k FIELD,] [-o FIELD,] [-s SORT] [-n NUMBER] [-m LINES]  [-d SECONDS] [-p PID,] [-u USER,] |
| iotop   | Displays process information in real time and ranks them by I/O.<br>usage: iotop [-AaKObq] [-n NUMBER] [-d SECONDS] [-p PID,] [-u USER,] |
| watch   | Runs the specified commands at a given interval (specified by **-n**, in seconds) and displays the execution result. You can press **Q** to exit the command execution.<br>usage: watch [-teb] [-n SEC] COMMAND ARGS |
| xargs   | Runs the command line one or more times, carrying parameters from the standard input device.<br>usage: xargs [-0prt] [-s NUM] [-n NUM] [-E STR]  COMMAND... |

### Device Node Operations (Query Only)

| Command| Description|
| :- | :- |
| df    | Displays the total, used, and free disk space of each file system passed in. If no parameter is carried, all loaded file systems are displayed.<br>usage: df [-HPkhi] [-t type] [FILESYSTEM...] |
| du    | Displays the disk usage with files and directories.<br>usage: du [-d N] [-askxHLlmc] [file...] |
| free  | Displays the total, available, and used amount of physical memory and swap space.<br>usage: free [-bkmgt] |
| mount | Mounts a new file system to the directory. If no parameter is carried, the existing mounts are displayed.<br>usage: mount [-afFrsvw] [-t TYPE] [-o OPTION,] [[DEVICE] DIR] |

### File Operations (Available for Files in the Current Application Sandbox Only)

| Command| Description|
| :- | :- |
| base64    | Uses the Base64 algorithm for encryption and decryption.<br>usage: base64 [-di] [-w COLUMNS] [FILE...] |
| basename  | Returns the non-directory portion of a path name after removing its suffix.<br>usage: basename [-a] [-s SUFFIX] NAME... \| NAME [SUFFIX] |
| cat       | Copies (Concatenates) a file to the standard output device. If no file is specified, the command reads from the standard input device. "-" indicates a standard input device.<br>usage: cat [-etuv] [FILE...] |
| chmod     | Changes the access mode of a file (recursively with -R).<br>usage: chmod [-R] MODE FILE... |
| cksum     | Outputs the checksum, length, and file name of a file using 32 bit CRC algorithm. If no file is specified, the command reads from the standard input device. "-" indicates a standard input device.<br>usage: cksum [-IPLN] [FILE...] |
| cmp       | Compares the contents of two files. (If only one file is specified, the command compares the file contents with the contents of the standard input device). You can specify whether to skip a certain number of bytes at the beginning.<br>usage: cmp [-l] [-s] FILE1 [FILE2 [SKIP1 [SKIP2]]] |
| comm      | Reads the contents from **FILE1** and **FILE2** in sequence and outputs three text columns: lines only in FILE1; lines only in FILE2; and lines in both files. "-" indicates a standard input device.<br>usage: comm [-123] FILE1 FILE2  |
| count     | Copies the standard input device to the standard output device and displays a simple progress indicator to the standard error output **stderr**.<br>usage: count |
| cp        | Copies the contents from **SOURCE** to **DEST**. If there are multiple sources, **DEST** must be a directory.<br>usage: cp [--preserve=motcxa] [-adlnrsvfipRHLP] SOURCE...  [DEST] |
| cpio      | Copies the contents into and out of the **cpio** archive in the format specified by **newc**.<br>usage: cpio -{o\|t\|i\|p DEST} [-v] [--verbose] [-F FILE] [--no-preserve-owner] [ignored: -mdu -H newc] |
| crc32     | Outputs the CRC32 checksum of each file.<br>usage: crc32 [file...] |
| cut       | Prints selected parts of lines from each file to the standard output device. Each selection list is separated by a comma and can be a number (counting from 1) or a dash-separated range (inclusive, where X- indicates from Xst byte to the end byte of a line, and -X indicates from the 1st byte to Xst byte of a line.) By default, the selection ranges are sorted and collated. You can the **-d** option to prevent that.<br>usage: cut [-Ds] [-bcCfF LIST] [-dO DELIM] [FILE...] |
| dd        |  Converts and copies a file. It can be used to create disk mirroring, back up data, and convert character encoding.<br>usage: dd [if=FILE] [of=FILE] [ibs=N] [obs=N] [iflag=FLAGS] [oflag=FLAGS][bs=N] [count=N] [seek=N] [skip=N][conv=notrunc\|noerror\|sync\|fsync] [status=noxfer\|none] |
| dirname   | Displays the directory portion of a path.<br>usage: dirname PATH... |
| dos2unix  | Converts the newline format in a file from DOS "\\r\\n" to Unix "\\n". If no file is specified, the command reads from the standard input device. "-" indicates a standard input device.<br>usage: dos2unix [FILE...] |
| echo      | Writes each parameter to the standard output device. Each parameter is separated by a space followed by a newline.<br>usage: echo [-neE] [args...] |
| egrep     | Displays the lines that match a regular expression. If **-e** is not specified, the first parameter is the regular expression to match. If no file is specified (or the file name is "-"), the command reads the information from the standard input device. If a match is found, 0 is returned. If no match is found, 1 is returned. If an error occurs during the command execution, 2 is returned.<br>usage: egrep [-EFrivwcloqsHbhn] [-ABC NUM] [-m MAX] [-e REGEX]... [-MS  PATTERN]... [-f REGFILE] [FILE]... |
| expand    | Expands tabs to spaces according to tabstops.<br>usage: expand [-t TABLIST] [FILE...] |
| fgrep     | Displays the lines that match a regular expression. If **-e** is not specified, the first parameter is the regular expression to match. If no file is specified (or the file name is "-"), the command reads the information from the standard input device. If a match is found, 0 is returned. If no match is found, 1 is returned. If an error occurs during the command execution, 2 is returned.<br>usage: fgrep [-EFrivwcloqsHbhn] [-ABC NUM] [-m MAX] [-e REGEX]... [-MS  PATTERN]... [-f REGFILE] [FILE]... |
| file      | Checks a file and describes its content type.<br>usage: file [-bhLs] [file...] |
| find      | Finds a file in the directory. By default, "." is used for match, and all files are matched. If **-print** is specified, the command displays the path names of files that match.<br>usage: find [-HL] [DIR...] [<options>] |
| fmt       | Reformats the input to a wordwrap of a given line length, preserves the existing indentation level, and writes it to the standard output device.<br>usage: fmt [-w WIDTH] [FILE...] |
| grep      | Displays the lines that match a regular expression.<br>usage: grep [-EFrivwcloqsHbhn] [-ABC NUM] [-m MAX] [-e REGEX]... [-MS  PATTERN]... [-f REGFILE] [FILE]... |
| gunzip    | Decompress a file. If no file is specified, the command decompresses the standard input device as a standard output device. After the command is successfully executed, the input file is deleted and replaced with a new file without the file name extension .gz.<br>usage: gunzip [-cfkt] [FILE...] |
| head      | Copies the first line in a file to the standard output device. If no file is specified, the command reads from the standard input device. "-" indicates a standard input device.<br>usage: head [-n number] [file...] |
| ls        | Lists the files or folders in the current directory.<br>usage: ls [-ACFHLRSZacdfhiklmnpqrstux1] [--color[=auto]] [directory...] |
| lsattr    | Lists the file attributes on the Linux file system. The flag letters are defined in the chattr help.<br>usage: lsattr [-Radlv] [Files...] |
| lsof      | Lists all open files that belong to the active processes, or lists the processes that use the listed file.<br>usage: lsof [-lt] [-p PID1,PID2,...] [FILE...] |
| md5sum    | Calculates the hash of each input file. If no file is specified, the command reads from the standard input device. Each input file outputs a line of hash followed by a file name.<br>usage: md5sum [-bcs] [FILE]... |
| mkdir     | Creates one or more directories.<br>usage: mkdir [-vp] [-m mode] [dirname...] |
| mktemp    | Safely creates a new file **DIR/TEMPLATE** and prints its name.<br>usage: mktemp [-dqu] [-p DIR] [TEMPLATE] |
| mv        | Moves or renames a file.<br>usage: mv [-fivn] SOURCE... DEST |
| nl        | Displays a file with the number of lines.<br>usage: nl [-E] [-l #] [-b MODE] [-n STYLE] [-s SEPARATOR] [-v #] [-w WIDTH]  [FILE...] |
| od        | Dumps data in octal/hexadecimal format.<br>usage: od [-bcdosxv] [-j #] [-N #] [-w #] [-A doxn] [-t acdfoux[#]] |
| paste     | Merges corresponding lines from each input file.<br>usage: paste [-s] [-d DELIMITERS] [FILE...] |
| patch     | Applies a diff file to one or more files.<br>usage: patch [-d DIR] [-i file] [-p depth] [-Rlsu] [--dry-run] |
| pgrep     | Searches for processes. **PATTERN** is the extended regular expression to be checked against the command name.<br>usage: pgrep [-clfnovx] [-d DELIM] [-L SIGNAL] [PATTERN] [-G GID,] [-g  PGRP,] [-P PPID,] [-s SID,] [-t TERM,] [-U UID,] [-u EUID,] |
| printf    | Uses the C printf syntax to format and print information based on the value of **Format**. (For cdeEfgGiosuxX, \\ is escaped to abefnrtv0, \\OCTAL, or \\xHEX.)<br>usage: printf FORMAT [ARGUMENT...] |
| pwd       | Prints the working (current) directory.<br>usage: pwd [-L\|-P] |
| readahead | Preloads a file to the disk cache.<br>usage: readahead FILE... |
| readlink  | Prints what the symbolic link points to if no options are carried. If it is not a symbolic link, an error is returned.<br>usage: readlink FILE... |
| realpath  | Displays the standard absolute path name.<br>usage: realpath FILE... |
| rev       | Outputs each line reversely. If no file is specified, the command reads from the standard input device.<br>usage: rev [FILE...] |
| rm        | Removes each parameter from the file system.<br>usage: rm [-fiRrv] FILE... |
| rmdir     | Removes one or more directories.<br>usage: rmdir [-p] [dirname...] |
| sed       | Stream editor that applies the edit script to the input line.<br>usage: sed [-inrszE] [-e SCRIPT]...\|SCRIPT [-f SCRIPT\_FILE]... [FILE...] |
| seq       | Counts in ascending order from the beginning (specified by **first**) to the end (specified by **last**). If no parameter is carried, the default value is 1.  The parameter can be a negative number or a floating point number.<br>usage: seq [-w\|-f fmt\_str] [-s sep\_str] [first] [increment] last |
| sort      | Sorts all lines of text from the input file (or standard input device) to the standard output device.<br>usage: sort [-Mbcdfginrsuz] [FILE...] [-k#[,#[x]] [-t X]] [-o FILE] |
| split     | Copies input (or standard input device) data to a series of output (or "x") files with alphabetically increasing suffix (aa, ab, ac, ... az, ba, bb...).<br>usage: split [-a SUFFIX\_LEN] [-b BYTES] [-l LINES] [INPUT [OUTPUT]] |
| stat      | Displays the status of a file or file system.<br>usage: stat [-tfL] [-c FORMAT] FILE... |
| strings   | Displays printable strings in a binary file.<br>usage: strings [-fo] [-t oxd] [-n LEN] [FILE...] |
| tac       | Outputs lines in reverse order.<br>usage: tac [FILE...] |
| tail      | Copies the last line in a file to the standard output device. "-" indicates a standard input device.<br>usage: tail [-n\|c NUMBER] [-f] [FILE...] |
| tar       | Creates, extracts, or lists files in a .tar file.<br>usage: tar [-cxt] [-fvohmjkOS] [-XTCf NAME] [FILE...] |
| tee       | Copies the standard input device to each listed file, and also to the standard output device. The file name "-" is synonymous with the standard output device.<br>usage: tee [-ai] [FILE...] |
| touch     | Update the access and modification time of each file to the current time.<br>usage: touch [-amch] [-d DATE] [-t TIME] [-r FILE] FILE... |
| truncate  | Sets the length of the file, sparsely expanding if necessary.<br>usage: truncate [-c] -s SIZE file... |
| uniq      | Reports or filters output duplicate lines in a file.<br>usage: uniq [-cduiz] [-w MAXCHARS] [-f FIELDS] [-s CHAR] [INFILE [OUTFILE]] |
| unix2dos  | Converts the newline format from Unix "\\n" to DOS "\\r\\n". If no file is specified, the command reads from the standard input device. "-" is a synonym for standard input devices.<br>usage: unix2dos [FILE...] |
| unlink    | Deletes a file.<br>usage: unlink FILE |
| uudecode  | Decodes a file from the standard input device (or INFILE).<br>usage: uudecode [-o OUTFILE] [INFILE] |
| uuencode  | Uuencode the standard input device (or INFILE) to the standard output device, with **ENCODE\_FILENAME** in the output.<br>usage: uuencode [-m] [INFILE] ENCODE\_FILENAME |
| wc        | Counts the number of lines, words, and characters in the input.<br>usage: wc -lwcm [FILE...] |
| which     | Search **\$PATH** for executable files that match the specified file name.<br>usage: which [-a] filename ... |
| xxd       | Hexdumps a file to the standard output device. If no file is specified, the command reads from the standard input device.<br>usage: xxd [-c n] [-g n] [-i] [-l n] [-o n] [-p] [-r] [-s n] [file] |
| zcat      |Decompress the file to the standard output device. It is similar to **gzip-dc**.<br> usage: zcat [FILE...] |
