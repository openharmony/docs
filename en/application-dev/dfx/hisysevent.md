# hisysevent

hisysevent is a preinstalled tool that helps you subscribe to real-time system events and query historical system events. To use this tool, access the target device with [hdc](hdc.md) and then run **hisysevent** commands in the command-line interface (CLI).

## Subscribing to Real-Time System Events

- Run the **hisysevent -r** command to subscribe to system events.

   ![](figures/hisysevent-r.png)

- To specify the type of system event to subscribe to, use the **-g** option.

  > **NOTE**
  >
  > With the **-g** option, four event types are available: **FAULT**, **STATISTIC**, **SECURITY**, and **BEHAVIOR**.
  >
  > If no event type is specified, hisysevent subscribes to all types of system events.

  Example: Subscribe to system events of the **FAULT** type.

  ![](figures/hisysevent-r-g.png)

- To subscribe to system events by event domain and event name, use the **-o**, **-n**, and **-c** options. **-o** specifies the event domain, **-n** specifies the event name, and **-c** specifies the rule for matching the domain and name of system events.

  > **NOTE**
  >
  > With the **-c** option, four matching rules are available: **WHOLE_WORD**, **PREFIX**, and **REGULAR**.
  >
  > If no matching rule is specified, hisysevent uses the default **WHOLE_WORD** matching rule.

  Example 1: With the whole word matching rule, subscribe to the system event that matches the domain of **AAFWK** and event name of **CONNECT_SERVICE**.

  ![](figures/hisysevent-r-o-wholeword.png)

  Example 2: With the prefix matching rule, subscribe to system events that match the domain prefix of **AAF** and event name prefix of **CONNECT**.

  ![](figures/hisysevent-r-o-prefix.png)

  Example 3: With the regular expression matching rule, subscribe to system events whose domain matches the **AA\*** regular expression and whose event name matches the **CONNE\*** regular expression.

  ![](figures/hisysevent-r-o-regular.png)

- To subscribe to system events by event tag, use the **-t** and **-c** options. **-t** specifies the event tag, and **-c** specifies the rule for matching event tags.

  Example 1: With the whole word matching rule, subscribe to system events whose tag is **ability**.

  ![](figures/hisysevent-r-t-wholeword.png)

  Example 2: With the prefix matching rule, subscribe to system events whose tag prefix is **aabili**.

  ![](figures/hisysevent-r-t-prefix.png)

  Example 3: With the regular expression matching rule, subscribe to system events whose tag matches the **abi\*** regular expression.

  ![](figures/hisysevent-r-t-regular.png)

## Querying Historical System Events

- Run the **hisysevent -l** command to query system events that have been flushed to disks.

  ![](figures/hisysevent-l.png)

- To specify the type of system event to query, use the **-g** option.

  > **NOTE**
  >
  > With the **-g** option, four event types are available: **FAULT**, **STATISTIC**, **SECURITY**, and **BEHAVIOR**.
  >
  > If no event type is specified, hisysevent queries all types of system events.

  Example: Query system events of the **SECURITY** type.

  ![](figures/hisysevent-l-g.png)

- To query historical system events within the specified period of time, use the **-s** and **-e** options. **-s** specifies the original start timestamp, and **-e** the original end timestamp.

  > **NOTE**
  >
  > The original start timestamp is accurate to milliseconds. 

  Example: Query all system events whose start timestamp is 1708604541551 and end timestamp is 1708604558551.

  ![](figures/hisysevent-l-s-e.png)

- To query historical system events within the specified period of time, you can also use the **-S** and **-E** options. **-S** specifies the original start timestamp in the specified time format, and **-e** the original end timestamp in the specified time format.

  > **NOTE**
  >
  > The timestamp format is YYYY-MM-DD hh:mm:ss.

  Example: Query all system events whose start timestamp is 2024-02-22 20:22:21 and end timestamp is 2024-02-22 20:22:38.

  ![](figures/hisysevent-l-S-E-format.png)

- To query system events by event domain and event name, use the **-o**, **-n**, and **-c** options. **-o** specifies the event domain, **-n** specifies the event name, and **-c** specifies the rule for matching the domain and name of system events.

  > **NOTE**
  >
  > For query of historical system events with the **-c** option, only the **WHOLE_WORD** matching rule is available.
  >
  > If no matching rule is specified, hisysevent uses the default **WHOLE_WORD** matching rule.

  Example 1: With the whole word matching rule, query the system event that matches the domain of **AAFWK** and event name of **CONNECT_SERVICE**.

  ![](figures/hisysevent-l-o-n-c.png)

- To set the maximum number of historical events that can be queried, use the **-m** option.

  > **NOTE**
  >
> If no maximum number is specified with the **-m** option, hisysevent queries a maximum of 10,000 system events by default.
  
![](figures/hisysevent-l-m.png)
  
  ![](figures/hisysevent-l-wc-l.png)

## System Event Validity Check

To enable system event validity check, use the **-v** option.

If system event validity check is enabled, invalid content contained in system events will be highlighted in red.

> **NOTE**
>
> "Invalid content" is defined as follows:
>
> 1. Custom parameter key that is not configured
> 2. Type mismatch

Example: A system event whose event domain is **ACE** and event name is **INTERACTION_APP_JANK** does not contain the **DURITION** and **DISPLAY_ANIMATOR** parameters in the [system event configuration](../../device-dev/subsystems/subsys-dfx-hisysevent-logging-config.md). If these parameters are contained in the event flushed to the disk, they will be highlighted in red when system event validity check is enabled.

![](figures/hisysevent-v.png)
