#!/bin/bash

#off CARD ETH0
ifconfig eth0 down

#on CARD ETH0
ifconfig eth0 up

#atribui END_IP a CARD ETH0
ifconfig eth0 172.16.31.1/24

#display CARD ETH0
ifconfig eth0


#cria uma Rota para DEST TUX1, atraves da TUX4
route add -net 172.16.30.0/24 gw 172.16.31.253
#display routes
route -n

