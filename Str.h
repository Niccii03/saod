class Str 
{
	char* m_pszText;
public:
	Str()//класс str
	{
		m_pszText = new char[1] {0};
	}
	Str(const char* p)//Конструктор инициализации 
	{
		if (p) 
		{
			m_pszText = new char[strlen(p) + 1];
			strcpy_s(m_pszText, strlen(p) + 1, p);
		}
		else
			m_pszText = new char[1] {0};
	}
	operator const char* ()const //оператор преобразования типа
	{
		return m_pszText; 
	}
	Str(const Str& s)//конструктор копирования
	{
		m_pszText = new char[strlen(s.m_pszText) + 1];
		strcpy_s(m_pszText, strlen(s.m_pszText) + 1, s.m_pszText);
	}
	const Str& operator = (const Str& s) //присваивание
	{
		if (&s == this) 
			return *this;
		delete[] m_pszText;
		m_pszText = new char[strlen(s.m_pszText) + 1];
		strcpy_s(m_pszText, strlen(s.m_pszText) + 1, s.m_pszText);
		return *this;
	}
	Str& operator +=(const char* sz)
	{
		int len1 = strlen(m_pszText);
		int len2 = strlen(sz);
		int len = len1 + len2 + 1;
		char* new_buf = new char[len];
		for (int i = 0; i < len1; i++)
			new_buf[i] = m_pszText[i];
		for (int i = len1; i < len; i++)
			new_buf[i] = sz[i-len1];
		//strcpy_s(new_buf, len1, m_pszText);
		//strcpy_s(new_buf, len, sz);
		//new_buf[len - 1] = 0;
		delete[] m_pszText;
		m_pszText = new_buf;
		return *this;
	}
	Str operator +(const char* sz) const
	{
		size_t len1 = strlen(m_pszText);
		size_t len2 = strlen(sz);
		int len = len1 + len2 + 1;
		char* new_str = new char[len];
		for (int i = 0; i < len1; i++)
			new_str[i] = m_pszText[i];
		for (int i = len1; i < len; i++)
			new_str[i] = sz[i - len1];
		/*memcpy(new_str, m_pszText, len1);
		memcpy(new_str + len1, sz, len2);*/
		new_str[len - 1] = 0;
		return Str(new_str);	
	}
	~Str() { delete[] m_pszText; }
};
