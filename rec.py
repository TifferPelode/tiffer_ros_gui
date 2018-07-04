#!/usr/bin/env python
#coding=utf-8

import lcm
from Tiffer import weChatMess_

def handler(channel, data):
    wcM = weChatMess_.decode(data)
    print "channel is \"%s\"" % channel
    print wcM.msg#data.encode("utf-8")

lc = lcm.LCM()
sub = lc.subscribe("Tiffer", handler)

try:
    while True:
		lc.handle()
except KeyboardInterrupt:
    pass

lc.unsubscribe(sub)