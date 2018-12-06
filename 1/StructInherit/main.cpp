//------------------------------------------------
//头文件.h
#include <iostream.h>
//================================================
/************************************************************************/
/*  动物基类
/************************************************************************/
enum BREED{GOLDEN,CAIRN,DANDIE,SHETLAND,DOBERMAN,LAB};
struct Animal   
{
public:
	Animal():m_nAge(2),m_nWeight(20){}
	~Animal(){}
	
//Operations
public:
	int   GetAge() const {return m_nAge;} //get the age of the animal
	void  SetAge(int nAge) {m_nAge = nAge;}//set the age of the animal
	int   GetWeight()const {return m_nWeight;}//get the weight of the animal
	void  SetWeight(int nWeight){m_nWeight = nWeight;}//set the weight of the animal
//Attributes	
protected:
	int m_nAge;
	int m_nWeight;
};
/************************************************************************/
/* 
/************************************************************************/
struct Cat:public Animal
{
public:
	Cat():m_Breed(GOLDEN){}
	~Cat(){}

//Operations
public:
	BREED GetBreed()
	{
		return m_Breed;
	}
	void SetBreed(BREED breed)
	{
        m_Breed = breed;
	}
private:
    BREED m_Breed;
};
/************************************************************************/
/* 主函数
/************************************************************************/
int main()
{
	Cat  cat;
	int  nAge;
	int  nWeight;
	BREED breed;
	cat.SetAge(10);
	cat.SetWeight(100);
	cat.SetBreed(GOLDEN);

	nAge = cat.GetAge();
	nWeight = cat.GetWeight();
	breed = cat.GetBreed();

	cout<<"Age = "<<nAge<<endl;
	cout<<"Weight = "<<nWeight<<endl;
	cout<<"BREED = "<<breed<<endl;

	return 0;
}
