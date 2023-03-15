# help


## Command Function

This command is used to display all commands in the OS and some Toybox commands.


## Syntax

help


## Parameters

None.


## Usage Guidelines

You can run **help** to display all commands in the current OS.


## Example

Run **help**.


## Output

All commands in the system:

  
```
After shell prompt "OHOS # ":
Use `<cmd> [args ...]` to run built-in shell commands listed above.
Use `exec <cmd> [args ...]` or `./<cmd> [args ...]` to run external commands.

OHOS:/$ help
***shell commands:*
arp          cat          cat_logmpp   cd           chgrp        chmod
chown        cp           cpup         date         dhclient     dmesg
dns          format       free         help         hi3881       hwi
ifconfig     ipdebug      kill         log          ls           lsfd
memcheck     mkdir        mount        netstat      oom          panicreset
partinfo     partition    ping         ping6        pmm          pwd
reset        rm           rmdir        sem          shm          stack
statfs       su           swtmr        sync         systeminfo   task
telnet       touch        umount       uname        v2p          vmm
watch        writeproc
After shell prompt "OHOS # ":
Use `<cmd> [args ...]` to run built-in shell commands listed above.
Use `exec <cmd> [args ...]` or `./<cmd> [args ...]` to run external commands.
***toybox commands:
chgrp chmod chown cp date du free help ifconfig kill ls mkdir mount
mv ping ps reboot rm rmdir top touch umount uname
Use `toybox help [command]` to show usage information for a specific command.
Use `shell` to enter interactive legacy shell.
Use `alias` to display command aliases.
```
