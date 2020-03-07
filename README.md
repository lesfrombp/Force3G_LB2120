# Force3G_LB2120

I have only tested this with my LB2120, so this might work with others. I also wrote a C program, but it's not really necessary.


The LB2120 doesnt allow a user to choose whether they want to use 3G or 4G/LTE. It also only supports a few bands, and the LTE bands where I live must be very congested. I average a .7Mbps download speed. I noticed that when I added a new APN, it would briefly connect to 3G, with speeds averaging 10Mbps. But it would reconnect back to LTE after a few minutes. This got me wondering if I could figure out how to fix this. After a few hours, I have it locked to 3G and its now running at a usable speed.


You need set Enable Diagnostics to On in the modems GUI. This allows you to telnet into the device through port 5510.
Then you can do telnet 192.168.5.1 5510
It should respond with "Connected to 192.168.5.1"
Type AT$QCNSP=2,0,2 and press Enter
It should respond with "OK"
You will notice your modem rebooting.
You will now be locked to 3G.

To undo this, just reboot the device or you can send AT$QCNSP=0,0,0


https://imgur.com/a/9ExOadW - Shows I am connected to LTE before this process

https://imgur.com/a/aCvTNqq - Speed on LTE

https://imgur.com/a/xn2XBEN - Shows I am connected to 3G

https://imgur.com/a/ohkZBfc - Speed on 3G

https://imgur.com/a/UlIBign - This is what your terminal should look like. The red boxes is what you will be typing
