
@echo off
set /a i=0
setlocal enabledelayedexpansion
for /d %%k in (*) do (
    set /a i+=1
    ren %%k !i!
)
