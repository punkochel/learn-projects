#include <cstdio> // Only for printf

enum {
	max_nickname = 32
};

/// A player interface
struct IPlayer {
	virtual int getId() const = 0;
	virtual int getCash() const = 0;
	virtual const char * getNickname() const = 0;
	virtual int getFractionId() const = 0;
	virtual double getHealth() const = 0;

	virtual void setCash(int value) = 0;
};

/// A player implementation
class Player : public IPlayer {
	int id;
	char nickname[max_nickname+1];
	int cash;
	int fraction_id;
	double health;
public:
	Player(int a_id, const char *a_nickname)
		: id(a_id)
		, cash(0)
		, fraction_id(0)
		, health(100.0)
	{
		for(int i = 0; a_nickname[i] && i != max_nickname; i++)
		{
			nickname[i] = a_nickname[i];
		}
	}

	int getId() const override
	{
		return id;
	}

	int getCash() const override
	{
		return cash;
	}

	const char * getNickname() const override
	{
		return nickname;
	}

	int getFractionId() const override
	{
		return fraction_id;
	}

	double getHealth() const override
	{
		return health;
	}

	void setCash(int value) override
	{
		cash = value;
	}
};

int main()
{
	Player player0(0, "Scrooge_McDuck");
	Player player1(1, "Woody_Woodpecker");

	player0.setCash(1500);
	player1.setCash(800);

	printf("PlayerInfo: ID: %d | Nick: %s | Cash: %d | Fraction: %d | Health: %.1f\n",
		player0.getId(),
		player0.getNickname(),
		player0.getCash(),
		player0.getFractionId(),
		player0.getHealth());

	printf("PlayerInfo: ID: %d | Nick: %s | Cash: %d | Fraction: %d | Health: %.1f\n",
		player1.getId(),
		player1.getNickname(),
		player1.getCash(),
		player1.getFractionId(),
		player1.getHealth());
	return 0;
}