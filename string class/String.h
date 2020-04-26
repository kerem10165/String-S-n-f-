#pragma once
#include <iostream>
class String
{
friend std::ostream& operator<<(std::ostream&,const String&); 
friend std::istream& operator>>(std::istream&, String&);
public:

	String();

	String(const String&);
	
	String(String&&);

	String(const size_t, const char b = '\0');

	String(const char*);

	String(const char);

	const String& operator=(const char*);

	const String& operator=(const char);

	const String& operator=(const  String& );
	
	const String& operator=(String&&) noexcept;

	const String& operator+=(const String&);

	const String& operator+=(const char*);

	const String& operator+=(const char);

	const String operator+(const String&);

	const String operator+(const char*);

	const String operator+(const char);

	char operator[](int) const;
	char& operator[](int);

	bool operator==(const String&) const;
	bool operator!=(const String&) const;
	bool operator>(const String&) const;
	bool operator<(const String&) const;
	bool operator>=(const String&) const;
	bool operator<=(const String&) const;
	

	int getSize() const
	{
		return size;
	}

	~String();
	
private:
	char* dizi;
	size_t size;
	size_t lenght;
	void charAta(const char*);
};