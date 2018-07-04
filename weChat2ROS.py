#!/usr/bin/env python
#coding=utf-8

# license removed for brevity
import requests
import itchat

import lcm
from Tiffer import weChatMess_

@itchat.msg_register(itchat.content.TEXT)
def wcMsg(msg):
    global lc
    try:
        wcM = weChatMess_()
        wcM.msg = msg['Text']#.encode("utf-8")
        #wcM.msg = 'pp'#u'风景'
        print wcM.msg, type(wcM.msg)
        lc.publish("Tiffer", wcM.encode())
    except KeyboardInterrupt:
        itchat.logout()
        pass

if __name__ == '__main__':

    lc = lcm.LCM()

    itchat.auto_login(True)
    itchat.run()
