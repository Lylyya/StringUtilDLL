#pragma once
#ifndef _STRINGUTIL_H_
#define _STRINGUTIL_H_ 

#include <vector>
#include <iostream>
using namespace std;

class __declspec( dllexport ) StringUtil
{
public:

	//大写字母转换成小写字母
	static void toLowerCase(string& str);

	//小写字母转换成大写字母
	static void toUpperCase(string& str);

	//参照物在起点
	static bool startsWith(const string& str, const string& pattern, bool lowerCase = true);

	//参照物在结尾
	static bool endsWith(const string& str, const string& pattern, bool lowerCase = true);

	//路径标标准化函数
	static string standardisePath(const string& init);

	//分离文件名与路径
	static void splitFilename(const string& qualifiedName, string& outBasename, string& outPath);

	//分离文件名与扩展名
	static void splitBaseFilename(const string& fullName, string& outBasename, string& outExtention);

	//分离完整文件名
	static void splitFullFilename(	const string& qualifiedName,string& outBasename, string& outExtention, string& outPath );

	//分割字符串
	static std::vector<string> split( const string& str, const string& delims, unsigned int maxSplits = 0);


	//恒空字符串
	static const string BLANK;

	static string& decode(const LPCWSTR str);

	static wstring& decode(const LPCSTR str);

	static string getPathStrA();

	static wstring getwPathStrW();




};

#endif	
