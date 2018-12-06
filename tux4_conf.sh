#!/bin/bash

#off CARD ETH0 e ETH1
ifconfig eth0 down
ifconfig eth1 down

#on CARDS ETH0 e ETH1
ifconfig eth0 up
ifconfig eth1 up

#atribui END_IP as CARDS ETH0 e ETH1 
ifconfig eth0 172.16.30.254/24
ifconfig eth1 172.16.31.253/24

#display CARDS
ifconfig

#configurara TUX4 como router com IP_FORWARD
echo 1 > /proc/sys/net/ipv4/ip_forward
echo 0 > /proc/sys/net/ipv4/icmp_echo_ignore_broadcasts

#display ROUTES
route -n


