# General
YottaDB-mqtt-pub is s simple and lightweight MQTT publisher
for the native YottaDB programming language M.

# Requirements
YottaDB-mqtt-pub is based on libmosquitto. To compile properly
the mosquitto-dev-library has to be installed:

`sudo apt-get install libmosquitto-dev`

(And certainly YottaDB)

# Compiling
YottaDB-mqtt-pub is compiled using make to a shared library with name YottaDB-mqtt-pub.so.

# Interface
In YottaDB the interface for a call-out is specified by a so-called eXternal-Call-table. For example compiled in directory `/some/where/YottaDB-mqtt-pub` this must be:

```
/some/where/YottaDB-mqtt-pub/YottaDB-mqtt-pub.so

pub: void createClientAndPublish(I:ydb_char_t*, I:ydb_char_t*)
```
with filename YottaDB-mqtt-pub.xc

The Makefile will create the xc-table for you!

Before calling YottaDB an environment-variable with a special name must point to this xc-table:
```
export ydb_xc_mqtt=/some/where/YottaDB-mqtt-pub/YottaDB-mqtt-pub.xc
```
The Makefile will print out a template for copy-paste!

# MQTT-Parameters
All parameters (like host, port, protocol, ...) are hardcoded in C.
Standard is localhost:1883. As an enhancement (for future) these parameter can submitted by an intial call.
# Sending messages (Interface)
```
d &mqtt.pub("hallo","welt")
```
Parameters:

1. Topic
2. Message payload

Return:

- void

(The `mqtt`in this example points to the environment variable `ydb_xc_mqtt`, both can be changed synchronously.)


# License
This project is licensed under the terms of the MIT license:

Copyright (c) <2022> Winfried Bantel, Aalen University

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
