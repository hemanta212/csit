#!/usr/bin/expect -f

# Postfix tests
spawn ./temp postfix
expect "Expression: "
send "a+b\n"
expect "a b +"
expect eof

# Postfix tests
spawn ./temp postfix
expect "Expression: "
send "a+b\n"
expect "a b +"
expect eof
