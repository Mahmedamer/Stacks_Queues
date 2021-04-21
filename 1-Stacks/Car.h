class Car
{
public:
	Car(int,int);
	~Car();
	void setCarNumber(int);
	void setEngineNumber(int);
	int getCarNumber() const;
	int getEngineNumber() const;
private:
	int CarNumber;
	int EngineNumber;
};

Car::Car(int cn, int gn)
{
	CarNumber = cn;
	EngineNumber = gn;
}

Car::~Car()
{
}

void Car::setCarNumber(int n)
{
	CarNumber = n;
}

void Car::setEngineNumber(int n)
{
	EngineNumber = n;
}

int Car::getCarNumber() const
{
	return CarNumber;
}

int Car::getEngineNumber() const
{
	return EngineNumber;
}
