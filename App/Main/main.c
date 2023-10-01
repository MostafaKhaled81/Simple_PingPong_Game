#include "Ping_pong.h"

#define F_CPU 16000000U
#include <util/delay.h>


int main(void)
{
	PingPong_Init();
	while (1)
	{
		PingPong_Start();
	}
}