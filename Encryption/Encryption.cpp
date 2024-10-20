//ENCRYPTION AND DECRYPTION OF MESSAGE
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
class secret
{
public:
	string str;
	bool flag;
	virtual void encrypt(string) = 0;
	virtual void decrypt(string) = 0;
	virtual void display() = 0;
};

class caesar : public secret
{
public:
	caesar(string s)
	{
		str = s;
		flag = false;
	}
	void encrypt(string key)
	{
		if (flag == false)
		{
			for (int i = 0; str[i] != '\0'; i++)
				str[i] = str[i] + key[0];
			flag = true;
		}
	}
	void decrypt(string key)
	{
		if (flag == true)
		{
			for (int i = 0; str[i] != '\0'; i++)
				str[i] = str[i] - key[0];
			flag = false;
		}
	}
	void display()
	{
		if (flag == true)
		{
			cout << "Message is a caesar cipher" << endl;
		}
		else
		{
			cout << str << endl;
		}
	}
};

class vigenere : public secret
{
public:
	vigenere(string s)
	{
		str = s;
		flag = false;
	}
	void encrypt(string key)
	{
		if (flag == false)
		{
			for (int i = 0, j = 0; str[i] != '\0' && key[j] != '\0'; i++, j++)
			{
				str[i] = str[i] + key[j];
				if (key[j + 1] == '\0')
					j = -1;
			}
			flag = true;
		}
	}
	void decrypt(string key)
	{
		if (flag == true)
		{
			for (int i = 0, j = 0; str[i] != '\0' && key[j] != '\0'; i++, j++)
			{
				str[i] = str[i] - key[j];
				if (key[j + 1] == '\0')
					j = -1;
			}
			flag = false;
		}
	}
	void display()
	{
		if (flag == true)
		{
			cout << "Message is a vigenere cipher" << endl;
		}
		else
		{
			cout << str << endl;
		}
	}
};

int main()
{
	class caesar c1("Music is the best");
	class vigenere v1("Music is the best");
	c1.encrypt("K");
	c1.display();
	c1.decrypt("K");
	c1.display();
	v1.encrypt("HI");
	v1.display();
	c1.decrypt("HI");
	c1.display();
	return 0;