#pragma once

#ifndef _STRINGUTIL_H_
#define _STRINGUTIL_H_ 

#define _FileExport __declspec( dllexport )

#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <string>
#include <list>
#include <map>
#include <vector>
#include <algorithm> 

using namespace std;

typedef std::map<string, bool> UnaryOptionList;
typedef std::map<string, string> BinaryOptionList;
//
class _FileExport StringUtil
{
public:

	//���ò���
	static void parseOpts(UnaryOptionList& unOpts, BinaryOptionList& binOpts);

	//���Ҳ���
	static int findCommandLineOpts(int numargs, char** argv, UnaryOptionList& unaryOptList, BinaryOptionList& binOptList);

	//��д��ĸת����Сд��ĸ
	static void toLowerCase(string& str);

	//Сд��ĸת���ɴ�д��ĸ
	static void toUpperCase(string& str);

	//�����������
	static bool startsWith(const string& str, const string& pattern, bool lowerCase = true);

	//�������ڽ�β
	static bool endsWith(const string& str, const string& pattern, bool lowerCase = true);

	//·�����׼������
	static string standardisePath(const string& init);

	//�����ļ�����·��
	static void splitFilename(const string& qualifiedName, string& outBasename, string& outPath);

	//�����ļ�������չ��
	static void splitBaseFilename(const string& fullName, string& outBasename, string& outExtention);

	//���������ļ���
	static void splitFullFilename(	const string& qualifiedName,string& outBasename, string& outExtention, string& outPath );

	//�ָ��ַ���
	static std::vector<string> split( const string& str, const string& delims, unsigned int maxSplits = 0);


	//����ַ���
	static const string BLANK;
	static string& decode(const LPCWSTR str);

	static wstring& decode(const LPCSTR str);

	static string getPathStrA();

	static wstring getwPathStrW();
	static void StringUtilLog(const string& logData, const string& filePath="" );
	

};

#endif	
