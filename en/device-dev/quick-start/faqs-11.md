# FAQs<a name="EN-US_TOPIC_0000001114978406"></a>

-   **Symptom**

    The message "ImportError: No module named apt\_pkg" is displayed when an unidentifiable command is executed on the Linux server.


-   **Possible Causes**

    There is a compatibility issue of python3-apt.

-   **Solution**

    Reinstall python3-apt.

    ```
    sudo apt-get remove  python3-apt
    sudo apt-get install python3-apt
    ```


