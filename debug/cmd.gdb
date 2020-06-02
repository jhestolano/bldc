source ~/opt/PyCortexMDebug/scripts/gdb.py
svd_load ./debug/cortex-m4-scb.svd
set pagination off
set print pretty
set print array on
target extended-remote: 4242
b main
r
