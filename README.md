There is a simple C++ virus example.
Actually I've just modified the code from [this page](https://ru-sfera.pw/threads/isxodnik-virusa-na-c-virus-dlja-ms-word.61/) just for fun.

How does it work?
1. It copies self to Windows and System32 dirs
2. It tries to add self to Windows Startup, but it does not work on Win11 version. Maybe it works on Win7 or Win8
3. It launches the endless loop with Sleep(10_000) call every iteration. In the loop it prints 'amogus' word everywhere :)

That's it. Actually, nothing scary is here, but it was interesting to code it.
