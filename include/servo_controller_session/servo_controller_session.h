#include <session/session.h>
#include <base/rpc.h>

namespace Servo_Controller {

	struct Session : public Genode::Session
	{
		static const char *service_name() {return "Servo Controller"; }

		virtual void say_hello() = 0;
		virtual void set_target(unsigned char channel, unsigned short target) = 0;
		virtual int get_position(unsigned char channel) = 0;

		/* return-type, fn-name, parameters */
		GENODE_RPC(Rpc_say_hello, void, say_hello);
		GENODE_RPC(Rpc_set_target, void, set_target, unsigned char, unsigned short);
		GENODE_RPC(Rpc_get_position, int, get_position, unsigned char);
		GENODE_RPC_INTERFACE(Rpc_say_hello, Rpc_set_target, Rpc_get_position);
	};
}