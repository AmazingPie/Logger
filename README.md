# Logger
A simple c++ logger library with basic logging functions to optional output streams

[Features/Notes]
- Currently only two output streams are available (console and .txt files) however more are planned for the future.

- Also has three priority levels (Error, Warn/Warning and Info) to allow for some more control over how each log message is displayed
which adds ([ERROR], [WARN] or [INFO]) onto the message. Additionally if outputing to a file then error messages will be put into a
crash log while the other messages are put into a runtime log to separate critical errors that will often relate to the crash or errors
in the programs execution.
