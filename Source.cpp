#include "stdio.h"
#include "iostream"
#include "math.h"

using namespace std;


class Transaction
{
public:
	int UserID;
	float Amount;
	Transaction()
	{
	}
	~Transaction()
	{
	}
	virtual void Report() = 0;

};

class Withdraw : public Transaction
{
public:
	Withdraw()
	{
	}
	void Report()
	{
		printf("------------------------------------------------\n");
		printf("Transaction Type: Withdraw\n");
		printf("User ID: %d\n", UserID);
		printf("Amount: $%f\n", Amount);
		printf("------------------------------------------------\n");
	}
};

class Deposit : public Transaction
{
public:
	Deposit()
	{
	}
	void Report()
	{
		printf("------------------------------------------------\n");
		printf("Transaction Type: Withdraw\n");
		printf("User ID: %d\n", UserID);
		printf("Amount: $%f\n", Amount);
		printf("------------------------------------------------\n");
	}
};

class Transfer : public Transaction
{
public:
	Transfer()
	{
	}
	void Report()
	{
		printf("------------------------------------------------\n");
		printf("Transaction Type: Transfer\n");
		printf("User ID: %d\n", UserID);
		printf("Amount: $%f\n", Amount);
		printf("------------------------------------------------\n");
	}
};

class User
{
public:
	int ID;
	int numTrans;


	Transaction* t[100];
	User()
	{
		numTrans = 0;
	}
	~User()
	{
		for (int i = 0; i < numTrans; i++)
			delete t[i];
	}
};

class UI
{
public:
	User* u[100];
	int size;
	int current;
	bool exit;
	bool match;
	int select;
	int tempid;
	
	UI()
	{
		size = 0;
		exit = false;
		current = 0;
		match = false;
		tempid = 0;
	}
	~UI()
	{
		for (int i = 0; i < size; i++)
			delete u[i];
	}
	void ProcessID()
	{
		match = false;
		printf("What is your ID number?\n");
		scanf_s("%d", &tempid);
		printf("------------------------------------------------\n");

		while (match == false)
		{
			for (int i = 0; i < size; i++)
			{
				if (tempid == u[i]->ID)
				{
					current = i;
					match = true;
				}
			}
			if (match == false)
			{
				current = size;
				u[current] = new User();
				u[current]->ID = tempid;
				size++;
				match = true;
			}
		}
	}
	void Run()
	{
		ProcessID();

		while (exit == false)
		{
			printf("What would you like to do?\n1-Withdraw\n2-Deposit\n3-Transfer\n4-Print Report\n5-Change Users\n6-Exit\n7-Just Saying Hi\n8-Divest in corrupt bank\n");
			scanf_s("%d", &select);
			printf("------------------------------------------------\n");

			//Withdraw
			if (select == 1)
			{
				u[current]->t[u[current]->numTrans] = new Withdraw();
				printf("How much would you like to withdraw?\n");
				scanf_s("%f", &u[current]->t[u[current]->numTrans]->Amount);
				u[current]->t[u[current]->numTrans]->UserID = u[current]->ID;
				u[current]->numTrans++;
				printf("------------------------------------------------\n");
			}

			//Deposit
			else if (select == 2)
			{
				u[current]->t[u[current]->numTrans] = new Deposit();
				printf("How much would you like to deposit?\n");
				scanf_s("%f", &u[current]->t[u[current]->numTrans]->Amount);
				u[current]->t[u[current]->numTrans]->UserID = u[current]->ID;
				u[current]->numTrans++;
				printf("------------------------------------------------\n");
			}

			//Transfer
			else if (select == 3)
			{
				u[current]->t[u[current]->numTrans] = new Transfer();
				printf("How much would you like to transfer?\n");
				scanf_s("%f", &u[current]->t[u[current]->numTrans]->Amount);
				u[current]->t[u[current]->numTrans]->UserID = u[current]->ID;
				u[current]->numTrans++;
				printf("------------------------------------------------\n");
			}

			//Report
			else if (select == 4)
			{

				printf("User ID: %d \n", u[current]->ID);
				printf("Number of transactions: %d \n", u[current]->numTrans);
				for (int i = 0; i < u[current]->numTrans; i++)
				{
					u[current]->t[i]->Report();
				}
			}

			//Switch User
			else if (select == 5)
			{
				ProcessID();
			}

			//Exit
			else if (select == 6)
			{
				exit = true;
			}
			else if (select == 7)
			{
				printf("Howdy\n");
			}
			else if (select == 7)
			{
				int yn = 0;
				printf("Are you sure?\n1-Yes\n2-No\n");
				scanf_s("%d", &yn);
				if (yn == 1)
				{
					printf("Are you sure you're sure?\n1-Yes\n2-No\n");
					scanf_s("%d", &yn);
					if (yn == 1)
					{
						printf("Are you sure you're sure you're sure?\n1-Yes\n2-No\n");
						scanf_s("%d", &yn);
						if (yn == 1)
						{
							printf("Ok then, have a nice life\n");
							ProcessID();
						}
						else
						{
							break;
						}

					}
					else
						break;
				}
				
				

			}
		}
	}
};

void main()
{
	UI ui;
	ui.Run();

}

