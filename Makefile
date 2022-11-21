ydb=$(shell pkg-config --variable=prefix yottadb)
a_dir=$(shell pwd)

YottaDB-mqtt-pub.so: YottaDB-mqtt-pub.c
	gcc  -o YottaDB-mqtt-pub.so -Wall -Werror -fpic -shared YottaDB-mqtt-pub.c -I$(ydb) -lmosquitto
	@echo "$(a_dir)/YottaDB-mqtt-pub.so" > YottaDB-mqtt-pub.xc
	@echo "" >> YottaDB-mqtt-pub.xc
	@echo "pub: void createClientAndPublish(I:ydb_char_t*, I:ydb_char_t*)" >> YottaDB-mqtt-pub.xc
	@echo -e '\nnow type:'
	@echo "export ydb_xc_mqtt=$(a_dir)/YottaDB-mqtt-pub.xc"
	@echo 'afterwards start ydb and type:'
	@echo 'd &mqtt.pub("hallo","welt")'

clean-all:
	rm -f mqttClient.so YottaDB-mqtt-pub.xc

