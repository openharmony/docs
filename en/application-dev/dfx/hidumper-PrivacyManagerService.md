# PrivacyManagerService

<!--Kit: Ability Kit-->
<!--Subsystem: Security-->
<!--Owner: @xia-bubai-->
<!--Designer: @linshuqing; @hehehe-li-->
<!--Tester: @leiyuqian-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=29e260f563a6938128441a49bbd0187a9e19c522 translatedAt=2026-07-31T01:29:52.145Z pushedAt=2026-07-31T07:14:16.762Z -->

PrivacyManagerService is a command line capability developed based on [hidumper](hidumper.md) for access control. It can display basic access control information and obtain the usage records of sensitive permissions.

## Environment Setup

Set up the environment by referring to [Environment Setup](hidumper.md#environment-setup).

## Obtaining Help Information

To view the help information, run the following command:

```shell
hidumper -s PrivacyManagerService -a '-h'
```

 **Example**

```text

-------------------------------[ability]-------------------------------


----------------------------------PrivacyManagerService----------------------------------
Privacy Dump:
Usage:
       -h: command help
       -t <TOKEN_ID>: according to specific token id dump permission used records
```

## Obtaining Sensitive Permission Usage Records

You can view sensitive permission usage records by app process token ID using the following command.

```shell
hidumper -s PrivacyManagerService -a '-t <tokenId>'
```

You can run the [atm-tool](../tools/atm-tool.md#dump) command to query the token ID required by the command.

 **Example**

```text
hidumper -s PrivacyManagerService -a '-t 536992218'

-------------------------------[ability]-------------------------------


----------------------------------PrivacyManagerService----------------------------------
Privacy Dump:
{
  "permissionRecord": [
    {
      "bundleName": "com.ohos.camera",
      "isRemote": false,
      "permissionName": "ohos.permission.READ_IMAGEVIDEO",
      "lastAccessTime": 1508577149393,
      "lastAccessDuration": 0,
      "accessCount": 2
    }
  ]
}
```