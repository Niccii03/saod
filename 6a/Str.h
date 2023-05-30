#pragma once
#include <memory>
class Str
{

	char* m_pszText;



public:
	Str substr(int off, int len) const {
		if (off >= strlen(m_pszText) || len <= 0) {
			return Str();
		}

		if (off < 0) {
			off = 0;
		}

		if (len > strlen(m_pszText) - off) {
			len = strlen(m_pszText) - off;
		}

		char* temp = new char[len + 1];
		strncpy_s(temp, len + 1, m_pszText + off, len);
		temp[len] = '\0';
		Str result(temp);
		delete[] temp;
		return result;
	}
	Str(int x) {
		char buf[64];
		_itoa_s(x, buf, 64, 10);
		m_pszText = new char[strlen(buf) + 1];
		strcpy_s(m_pszText, strlen(buf) + 1, buf);
	}

	Str(const char* p)
	{
		if (p) {
			m_pszText = new char[strlen(p) + 1];
			strcpy_s(m_pszText, strlen(p) + 1, p);
		}
		else
			m_pszText = new char[1] {0};
	}
	Str(const Str& s)
	{
		m_pszText = new char[strlen(s.m_pszText) + 1];
		strcpy_s(m_pszText,
			strlen(s.m_pszText) + 1,
			s.m_pszText);
	}
	const Str& operator = (const Str& s)
	{
		if (&s == this) return *this;
		delete[] m_pszText;
		m_pszText = new char[strlen(s.m_pszText) + 1];
		strcpy_s(m_pszText,
			strlen(s.m_pszText) + 1,
			s.m_pszText);
		return *this;
	}
	Str& operator +=(const char* sz)
	{
		size_t orig_size = strlen(m_pszText);
		size_t new_size = orig_size + strlen(sz);
		char* temp = new char[new_size + 1];
		strcpy_s(temp, new_size + 1, m_pszText);
		strcat_s(temp, new_size + 1, sz);
		delete[] m_pszText;
		m_pszText = temp;
		return *this;
	}


	Str()
	{
		m_pszText = new char[1] {0};
	}

	operator const char* ()const { return m_pszText; }
	~Str() { delete[]m_pszText; }
	Str operator +(const char* sz) const {
		size_t lenSz = strlen(sz);
		size_t lenThis = strlen(m_pszText);
		size_t lenTotal = lenSz + lenThis;
		char* buffer = new char[lenTotal + 1];
		strcpy_s(buffer, lenTotal + 1, m_pszText);
		strcat_s(buffer, lenTotal + 1, sz);
		Str result(buffer);
		delete[] buffer;
		return result;
	}

};

