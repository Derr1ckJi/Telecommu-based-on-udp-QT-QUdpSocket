# Telecommu-based-on-udp-QT-QUdpSocket
To realize the function of UDP telecommunication. To be concrete, create a dialog to send messages and receive messages and show that on screen.

Just wanna to use 3 different modes to send 3 different edicts. 
Inspired by WANGYUSONG.

#HOW TO IMPROVE
1.The size of the wdigets should be accordingly adjusted while the size of this interface is changed. THis is a basic require for a interface desire.
2.The Situation that the message is sent and received by yourself would be fairly rare in realistic applications. Usually two or more UDP cases would be needed to realise a telecommunication app.
3.THE MOST VITAL problem of these codes: HOW to discern the unreliable datas. UDP is one of the unreliable telecommnication techs, which means it is likely for clients to receive some trivial messages or uncorrect data. So the telecommunication protocol is applied to improve the telecommunication quality. And what we need to do is to utilize some unique marks to wrap the message. To be concrete, we r supposed to design a message header and a tail. As for the receiver, he/she need to recognize this header and then begin to deal with the following context, to decode or do something to recover the statistics that the sender want to describe.
