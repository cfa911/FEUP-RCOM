#!/bin/bash

#criar as configuracoes TUX1 IP 172.16.30.1 / 24

#off CARD ETH0
ifconfig eth0 down

#on CARD ETH0
ifconfig eth0 up

#atribui END_IP a CARD ETH0 with MASK
ifconfig eth0 172.16.30.1/24

#display ETH0
ifconfig eth0

#cria uma rota para DEST TUX2, através d TUX4
route add -net 172.16.31.0/24 gw 172.16.30.254

#display routes
route -n
