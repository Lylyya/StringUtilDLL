#include "StdAfx.h"
#include "StringUtil.h"
#include <algorithm> 
#include <string>

const string StringUtil::BLANK;




void StringUtil::toLowerCase(string& str)
{//��д��ĸת����Сд��ĸ

	std::transform(
		str.begin(),
		str.end(),
		str.begin(),
		tolower);
}

void toUpperCase(string& str) 
{//Сд��ĸת���ɴ�д��ĸ

	std::transform(
		str.begin(),
		str.end(),
		str.begin(),
		toupper);
}

bool StringUtil::startsWith(const string& str, const string& pattern, bool lowerCase)
{//��������־
	size_t thisLen = str.length();
	size_t patternLen = pattern.length();
	if (thisLen < patternLen || patternLen == 0)
		return false;

	string startOfThis = str.substr(0, patternLen);
	if (lowerCase)
		toLowerCase(startOfThis);

	return (startOfThis == pattern);
}
bool StringUtil::endsWith(const string& str, const string& pattern, bool lowerCase)
{//������β��־
	size_t thisLen = str.length();
	size_t patternLen = pattern.length();
	if (thisLen < patternLen || patternLen == 0)
		return false;

	string endOfThis = str.substr(thisLen - patternLen, patternLen);
	if (lowerCase)
		toLowerCase(endOfThis);

	return (endOfThis == pattern);
}

string StringUtil::standardisePath(const string& init)
{//·����׼����\ת����/

	string path = init;

	std::replace( path.begin(), path.end(), '\\', '/' );
	if( path[path.length() - 1] != '/' )
		path += '/';

	return path;
}

void StringUtil::splitFilename(const string& qualifiedName, string& outBasename, string& outPath)
{//�����ļ���
	string path = qualifiedName;
	// Replace \ with / first
	std::replace( path.begin(), path.end(), '\\', '/' );
	// split based on final /
	size_t i = path.find_last_of('/');

	if (i == string::npos)
	{
		outPath.clear();
		outBasename = qualifiedName;
	}
	else
	{
		outBasename = path.substr(i+1, path.size() - i - 1);
		outPath = path.substr(0, i+1);
	}

}

void StringUtil::splitBaseFilename(const string& fullName, string& outBasename, string& outExtention)
{//�����ļ�����ȥ����չ��
	size_t i = fullName.find_last_of(".");
	if (i == string::npos)
	{
		outExtention.clear();
		outBasename = fullName;
	}
	else
	{
		outExtention = fullName.substr(i+1);
		outBasename = fullName.substr(0, i);
	}
}


void StringUtil::splitFullFilename(	const string& qualifiedName,string& outBasename, string& outExtention, string& outPath )
{//���������ļ���
	string fullName;
	splitFilename( qualifiedName, fullName, outPath );
	splitBaseFilename( fullName, outBasename, outExtention );
}

std::vector<string> StringUtil::split( const string& str, const string& delims, unsigned int maxSplits)
{//���ݸ����ַ����ָ�
	std::vector<string> ret;
	// Pre-allocate some space for performance
	ret.reserve(maxSplits ? maxSplits+1 : 10);    // 10 is guessed capacity for most case

	unsigned int numSplits = 0;

	// ʹ��STL���� 
	size_t start, pos;
	start = 0;
	do 
	{
		pos = str.find_first_of(delims, start);
		if (pos == start)
		{
			// ʲôҲ����
			start = pos + 1;
		}
		else if (pos == string::npos || (maxSplits && numSplits == maxSplits))
		{
			// ���������ַ���
			ret.push_back( str.substr(start) );
			break;
		}
		else
		{
			// ���Ƶ������
			ret.push_back( str.substr(start, pos - start) );
			start = pos + 1;
		}
		// ������һ������
		start = str.find_first_not_of(delims, start);
		++numSplits;

	} while (pos != string::npos);



	return ret;
}



string& StringUtil::decode(const LPCWSTR str)
{	
	char sdes[2048];	
	static std::string result;	

	int wlen = WideCharToMultiByte(CP_ACP, 0, str, -1, NULL, 0, NULL, NULL);	
	char* nstr = new char[wlen];	
	WideCharToMultiByte(CP_ACP, 0, str, -1, nstr, wlen, NULL, NULL);
	strcpy(sdes, nstr);	
	delete nstr;
	result = sdes;
	return result;
}



wstring& StringUtil::decode(const LPCSTR str)
{	
	wchar_t sdes[2048];
	static std::wstring result;	

	int len = MultiByteToWideChar(CP_ACP, 0, str, -1, NULL, 0);
	wchar_t* wcstr = new wchar_t[len];	
	MultiByteToWideChar(CP_ACP, 0, str, -1, wcstr, len);	
	wcscpy(sdes, wcstr);
	delete wcstr;
	result = sdes;
	return result;
}

string StringUtil::getPathStrA()
{
	char szPath[MAX_PATH];
	GetModuleFileNameA( NULL, szPath, MAX_PATH );
	std::string lastPath=szPath;
	size_t lastpoint = lastPath.find_last_of("\\");
	return lastPath.substr(0,lastpoint+1);

}

wstring StringUtil::getwPathStrW()
{
	wchar_t szPath[MAX_PATH];
	GetModuleFileNameW( NULL, szPath, MAX_PATH );
	std::wstring lastPath=szPath;
	size_t lastpoint = lastPath.find_last_of(L"\\");
	return lastPath.substr(0,lastpoint+1);

}

