#ifndef MQTT_RPC_MQTT_RPC_ERROR_ENUM_INC
#define MQTT_RPC_MQTT_RPC_ERROR_ENUM_INC

namespace mqtt_rpc {

enum MqttRpcErrorEnum {
	MQTT_CLIENT_STATUS_IS_DISCONNECTED = 1,
	MQTT_CLIENT_STATUS_IS_CONNECTED = 2,
	MQTT_CLIENT_STATUS_IS_CONNECTING = 3,
	MQTT_RPC_CLIENT_SUBSCRIBE_TOPIC_IS_NULL = 4,
	MQTT_RPC_CLIENT_PUBLISH_TOPIC_IS_NULL = 5,
	MQTT_RPC_PACKET_TOO_SHORT = 6,
	MQTT_RPC_PACKET_INVALID_FIX_HEADER = 7,
	MQTT_RPC_PACKET_INVALID_VARIABLE_HEADER = 8,
};

}	// mqtt_rpc

#endif