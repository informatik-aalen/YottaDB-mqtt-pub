/*
 Version 20221118
 ToDo:
 - Evtl Connection-Parameter wie host, port via init-Fkt. reingeben, dann
    koennte da auch Connect erfolgen (aber für ydb-Trigger problematisch??)
 */
#include <mosquitto.h>
#include <libyottadb.h>
//#include <stdio.h>
#include <string.h>

#define BROKER_PORT 1883
#define BROKER_HOSTNAME "localhost"

void createClientAndPublish(int count, ydb_char_t *topic, ydb_char_t *payload)
{
	static int initResult = -1;
	static struct mosquitto *client = NULL;
	static int conn_result = -1;
	
	if (conn_result != MOSQ_ERR_SUCCESS) {
		if ((initResult = mosquitto_lib_init()) != MOSQ_ERR_SUCCESS) // https://mosquitto.org/api/files/mosquitto-h.html#mosquitto_lib_init
			return;
		if((client = mosquitto_new(NULL, true, NULL)) == NULL) // https://mosquitto.org/api/files/mosquitto-h.html#mosquitto_new
			return;
		if ((conn_result = mosquitto_connect_async(client, BROKER_HOSTNAME, BROKER_PORT, 10)) != MOSQ_ERR_SUCCESS) // https://mosquitto.org/api/files/mosquitto-h.html#mosquitto_connect_async
			return;
		mosquitto_loop_start(client); // https://mosquitto.org/api/files/mosquitto-h.html#mosquitto_loop_start
	}
	if(conn_result != MOSQ_ERR_SUCCESS)
		return;
  int pub_result = mosquitto_publish( // https://mosquitto.org/api/files/mosquitto-h.html#mosquitto_publish
    client,
    NULL,
    topic,
    strlen(payload),
    payload,
    0,
    true
  );

  if(pub_result != MOSQ_ERR_SUCCESS)
    return;

  // clean up
  //mosquitto_disconnect(client);
  //mosquitto_destroy(client);
}

