#include "TCPClient.hpp"

TCPClient tcp;

void sig_exit(int s)
{
	tcp.exit();
	exit(0);
}

int main()
{
	signal(SIGINT, sig_exit);

	tcp.setup("127.0.0.1", 11999);
	while(true)
	{
		srand(time(NULL));
		tcp.Send(to_string(rand()%25000));

		string rec = tcp.receive();
		if(rec != "")
		{
			cout << "Server Response:" << rec << endl;
		}
		sleep(1);
	}
	return 0;
}