#include "String.h"


String::String()
{
	dizi = new char{ '\0' };
	size = 0;
	lenght = 1;
}

String::String(const String& other)
{
	if (this != &other)
	{
		if (other.dizi)
		{
			size = other.size;
			lenght = other.lenght;
			if (size > 0)
			{
				dizi = new char[lenght];
				memcpy(dizi, other.dizi, sizeof(char) * (lenght));
			}
			else if(size == 0)
			{
				dizi = new char;
				*dizi = *other.dizi;
			}
		}
		else
		{
			dizi = new char{ '\0' };
			size = 0;
			lenght = 1;
		}
	}

	else
	{
		throw("kendine esitleme yapamazsin");
	}
}

String::String(String&& other)
{
	if (this != &other)
	{
		dizi = other.dizi;
		size = other.size;
		lenght = other.lenght;
		other.dizi = nullptr;
		other.size = 0;
	}
}

String::String(const size_t a, const char b)
{
	size = a;
	lenght = a + 1;
	dizi = new char[lenght];
	for (int i = 0; i < size; ++i)
	{
		memcpy(dizi + i, &b, sizeof(char));
	}

	dizi[size] = '\0';
}


String::String(const char* a)
{
	charAta(a);
}

String::String(const char a)
{
	dizi = new char[2];
	dizi[0] = a;
	dizi[size] = '\0';
	size = 1;
	lenght = 2;
}

const String& String::operator=(const char* a)
{
	if (dizi)
	{
		if (size == 0)
		{
			delete dizi;
		}

		else if (size > 0)
		{
			delete[] dizi;
		}
	}

	charAta(a);

	return *this;
}

const String& String::operator=(const char a)
{
	if (dizi)
	{
		if (size == 0)
		{
			delete dizi;
		}

		else if (size > 0)
		{
			delete[] dizi;
		}
	}

	size = 1;
	lenght = 2;

	dizi = new char[lenght];

	dizi[0] = a;
	dizi[size] = '\0';

	return *this;
}

const String& String::operator=(const String& other)
{
	if (this != &other)
	{
		if (other.dizi)
		{
			if (dizi)
			{
				if (size == 0)
				{
					delete dizi;
				}

				else if (size > 0)
				{
					delete[] dizi;
				}
			}

			size = other.size;
			lenght = other.lenght;

			if (size == 0)
			{
				dizi = new char;
				*dizi = *other.dizi;
				return *this;
			}

			if (size > 0)
			{
				dizi = new char[lenght];
				memcpy(dizi, other.dizi, sizeof(char) * (lenght));
				return *this;
			}
		}

		else
		{
			if (dizi)
			{
				if (size == 0)
				{
					delete dizi;
				}

				else if (size > 0)
				{
					delete[] dizi;
				}
			}

			dizi = new char{ '\0' };
			size = 0;
			lenght = 1;
		}
	}

	else
	{
		throw("kendi kendine atama yapamazsin");
	}

	return *this;
}

const String& String::operator=(String&& other) noexcept
{
	if (other.dizi)
	{
		dizi = other.dizi;
		other.dizi = nullptr;
		size = other.size;
		lenght = other.lenght;
		other.size = 0;
		other.lenght = 0;
	}

	return *this;
}

const String& String::operator+=(const String& other)
{
	char* temp;
	int size_temp;

	if (dizi)
	{
		if (this == &other)
		{
			if (size == 0)
			{
				delete dizi;
				dizi = new char{'\0'};
				return *this;
			}
			else
			{
				temp = new char[size];
				memcpy(temp, dizi, size);
				delete[] dizi;
				dizi = new char[size + lenght];
				memcpy(dizi, temp, size);
				memcpy(dizi+size, temp, size);
				size = 2*size;
				lenght = size + 1;
				dizi[size] = '\0';
				delete[] temp;
				return *this;
			}
		}
		
		else
		{
			if (other.dizi)
			{
				if (size == 0)
				{
					if (other.size == 0)
					{
						delete dizi;
						dizi = new char{ '\0' };
						return *this;
					}

					else if(other.size > 0)
					{
						delete dizi;
						size = other.size;
						lenght = other.lenght;
						dizi = new char[lenght];
						memcpy(dizi, other.dizi, lenght);
						return *this;
					}
				}

				else
				{
					temp = new char;
					delete temp;
					if (size == 1)
					{
						temp = new char;
						size_temp = size;
					}
					else if (size > 1)
					{
						temp = new char[size];
						size_temp = size;
					}
					memcpy(temp, dizi, size);
					delete[] dizi;
					size = size + other.size;
					lenght = size_temp + other.lenght;
					dizi = new char[lenght];

					memcpy(dizi, temp, size_temp);
					memcpy(dizi+size_temp, other.dizi, other.lenght);
					dizi[size] = '\0';
					if (size_temp == 1)
					{
						delete temp;
					}
					else
					{
						delete[] temp;
					}
				}
			}
		}
	}
	
	return *this;
}

const String& String::operator+=(const char* a)
{
	String nesne = a;
	*this += nesne;
	return *this;
}

const String& String::operator+=(const char a)
{
	String nesne = a;
	*this += nesne;
	return *this;
}

const String String::operator+(const String& other)
{
	String tut = *this;
	tut += other;
	return tut;
}

const String String::operator+(const char* a)
{
	String tut = *this;
	tut += a;
	return tut;
}

const String String::operator+(const char a)
{
	String tut = *this;
	tut += a;
	return tut;
}

char String::operator[](int i) const
{
	return dizi[i];
}

char& String::operator[](int i)
{
	return dizi[i];
}

String::~String()
{
	if (dizi)
	{
		if (size == 0)
		{
			delete dizi;
		}

		else if (size > 0)
		{
			delete[] dizi;
		}
	}
}

inline void String::charAta(const char* a)
{
	bool flag = true;

	size_t i = 0;

	while (a[i] != '\0')
	{
		size = i + 1;
		lenght = i + 2;
		flag = false;
		++i;
	}

	if (flag)
	{
		dizi = new char{ '\0' };
		size = 0;
		lenght = 1;
	}

	else
	{
		dizi = new char[lenght];
		memcpy(dizi, a, sizeof(char) * (lenght));
	}
}

bool String::operator==(const String& other) const
{
	if (this == &other)
	{
		return true;
	}

	else
	{
		if (size != other.size)
		{
			return false;
		}
		else
		{
			for (int i = 0; i < size; i++)
			{
				if (dizi[i] != other.dizi[i])
				{
					return false;
				}
			}
		}
	}

	return true;
}

bool String::operator!=(const String& other) const
{
	return !(*this == other);
}


bool String::operator>(const String& other) const
{
	if (size < other.size)
	{
		return false;
	}

	for (int i = 0; i < other.size; i++)
	{
		if (dizi[i] < other.dizi[i])
		{
			return false;
		}
	}

	return true;
}

bool String::operator<(const String& other) const
{
	if (size > other.size)
	{
		return false;
	}

	for (int i = 0; i < size; i++)
	{
		if (dizi[i] > other.dizi[i])
		{
			return false;
		}
	}

	return true;
}

bool String::operator>=(const String& other) const
{
	return ((*this>other) && (*this == other));
}

bool String::operator<=(const String& other) const
{
	return ((*this < other) && (*this == other));
}

std::ostream& operator<<(std::ostream& yaz, const String& nesne)
{
	yaz << nesne.dizi;

	return yaz;
}

std::istream& operator>>(std::istream& al, String& nesne)
{
	if (nesne.size == 0)
	{
		delete nesne.dizi;
	}

	else
	{
		delete[] nesne.dizi;
	}

	nesne.dizi = new char[50];
	int maxlenght = 50;

	for (int i = 0; i < maxlenght; i++)
	{
		al.get(nesne.dizi[i]);
		if (nesne.dizi[i] == (char)10)
		{
			nesne.dizi[i] = '\0';
			nesne.size = i;
			nesne.lenght = i + 1;
			break;
		}
		if (i == maxlenght -1)
		{
			char* temp = new char[maxlenght + 50];
			memcpy(temp, nesne.dizi, maxlenght);
			delete[] nesne.dizi;
			nesne.dizi = new char[maxlenght + 50];
			maxlenght += 50;
			memcpy(nesne.dizi, temp, maxlenght);
			delete[] temp;
		}
	}

	char* temp = new char[nesne.lenght];
	memcpy(temp, nesne.dizi, nesne.lenght);
	delete[] nesne.dizi;
	nesne.dizi = new char[nesne.lenght];
	memcpy(nesne.dizi, temp, nesne.lenght);
	delete[] temp;

	return al;
}
