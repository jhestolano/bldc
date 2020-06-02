source ~/opt/PyCortexMDebug/scripts/gdb.py
svd_load cortex-m4-scb.svd
target extended-remote: 4242
b main
r
