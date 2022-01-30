# HiSysEvent Tool Usage<a name="EN-US_TOPIC_0000001231614021"></a>

## Overview<a name="section1886702718521"></a>

The HiSysEvent tool is a command line tool preconfigured in the system. You can specify search criteria to query system events that meet your requirement. Using this tool, you can debug event logging during development or query system events for fault locating.

## Usage<a name="section1210623418527"></a>

1.  Run the HiSysEvent tool.

    The tool is preconfigured in the  **/system/bin**  directory. You can run the following command in any directory:

    ```
    hisysevent [-r | -l [-s <time> -e <time> -m <count>]]
    -r    get real hisysevent log.
    -l -s <begin time> -e <end time> -m <max hisysevent count>
    get history hisysevent log, begin time should not be earlier than end time.
    ```

2.  To query real-time system events, run the following command:

    ```
    hisysevent -r
    ```

    When a system event is received, the event will be printed on the console.

3.  To query historical system events, run the following command:

    ```
    hisysevent -l -s <begin time> -e <end time> -m <max hisysevent count>
    ```

    In the preceding command, parameters  **-s**  and  **-e**  specify the start time and end time, respectively. If  **-s**  or  **-e**  is not specified, there is no limitation for the start time or end time.

    Parameter  **-m**  specifies the maximum number of event records that can be returned in this query.


