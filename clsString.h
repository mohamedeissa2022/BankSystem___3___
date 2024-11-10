#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class clsString
{
	string value;
	char* CharArr;

public:
	clsString() {
		value = "";
	}
	clsString(string value) {
		this->value = value;
	}
	void setValue(string value) {
		this->value = value;
	}
	string getValue() {
		return value;
	}
	__declspec(property(get = getValue, put = setValue))string Value;
	static string ToUpperCase(string v) {
		string valueConverted = "";
		for (size_t i = 0; i < v.length(); i++)
		{
			if (islower(v[i])) {
				valueConverted += toupper(v[i]);
			}
			else
			{
				valueConverted += v[i];
			}
		}
		return valueConverted;
	}
	string ToUpperCase() {
		return ToUpperCase(value);
	}
	static string ToLowerCase(string v) {
		string valueConverted = "";
		for (size_t i = 0; i < v.length(); i++)
		{
			if (isupper(v[i])) {
				valueConverted += tolower(v[i]);
			}
			else
			{
				valueConverted += v[i];
			}
		}
		return valueConverted;
	}
	string ToLowerCase() {
		return ToLowerCase(value);
	}
	static vector<string> split(string t1, string token)
	{
		vector<string> vSpliter;
		short pos = 0;
		string word = "";
		while ((pos = t1.find(token)) != string::npos)
		{
			vSpliter.push_back(t1.substr(0, pos));
			t1.erase(0, pos + token.length());
		}
		if (t1 != "")
		{
			vSpliter.push_back(t1);
		}
		return vSpliter;
	}
	vector<string> split(string token)
	{
		return split(value, token);
	}
	static string trim(string v) {
		string val = "";
		for (size_t i = 0; i < v.length(); i++)
		{
			if (v[i] == ' ') {
				continue;
			}
			val += v[i];
		}
		v = val;
		val.clear();
		return v;
	}
	string trim() {
		value = trim(value);
		return value;
	}
	static string subString(string v, short fromIndex, short toIndex)
	{
		string val;
		if (fromIndex >= 0 && toIndex <= v.length()) {
			for (size_t i = fromIndex; i <= toIndex; i++)
			{
				val += v[i];
			}
			return val;
		}
		else
		{
			return "Error fromIndex var Or toIndex var\n";

		}

	}
	string subString(short fromIndex, short toIndex)
	{
		return subString(value, fromIndex, toIndex);
	}
	static bool Equals(string a1, string a2) {
		if (a1 == a2)return true;
		return false;
	}
	bool Equals(string a2) {
		return Equals(value, a2);
	}
	static string Compare(string a1, string a2) {
		if (a1 == a2)
			return a1;
		else if (a1 != a2)
			if (a1.length() > a2.length())return a1;
			else if (a2 != a1)
				if (a2.length() > a1.length())return a2;
	}
	string Compare(string a2) {
		return Compare(value, a2);
	}
	static string Join(string s1, string s2) {
		return s1 + s2;
	}
	string Join(string s2) {
		return Join(value, s2);
	}

	//static string Reverse(string s1) {
	   // for (size_t i = 0; i <= s1.length(); i++)
	   // {
		  //  s1[i]=s1[s1.length()-i];
	   // }
	   // s1.clear();
	   // return s1;
	//}

	// string Reverse() {
	   // return Reverse(value);
	//}


	string Append(string s1) {
		value = value + s1;
		return  value;
	}

	static char* ToCharArray(string s1, short Strlength) {
		char* CharArr = new char[Strlength];
		for (size_t i = 0; i < s1.length(); i++)
		{
			CharArr[i] = s1[i];
		}
		return CharArr;
	}
	char* ToCharArray() {
		return ToCharArray(value, value.length());
	}


	static short getCharsArrayLength(string s1)
	{
		return s1.length();
	}
	short getCharsArrayLength()
	{
		return getCharsArrayLength(value);
	}

	bool isUpperCase(char value) {
		for (short a = value; a <= 'Z'; a++) {
			if (a <= 'Z' && a >= 'A')return true;
		}
		return false;
	}




	bool isLowerCase(char value) {
		for (short i = 97; i <= 122; i++)
			if (value >= i && value <= 122)return 1;//Lower Case
		return 0;
	}



	static bool isDigit(char value) {
		for (short from = '0'; from <= '9'; from++) {
			if (value == from)return 1;
		}
		return 0;
	}



	bool isPunct(char value)
	{
		bool isPunct1 = false;
		for (short from = 33; from <= 126; from++) {
			if (from >= '0' && from <= '9')continue;//digits 
			if (from >= 'a' && from <= 'z')continue;//lower case chars 
			if (from >= 'A' && from <= 'Z')continue;//upper case chars 
			cout << (char)from;
			if (value == from) {
				isPunct1 = true;
				break;
			}
		}
		cout << endl;
		return isPunct1;
	}


	static short CountStringWord(string s1) {
		string word;
		string delim = " ";
		short c = 0;
		short pos = 0;
		while ((pos = s1.find(delim)) != string::npos)
		{

			word = s1.substr(0, pos);//0,5=abcde 
			if (word != "")c++;

			s1.erase(0, pos + delim.length());
		}
		//if (s1 != "")c+=1;
		return c + 1;
	}


	short CountStringWord() {

		return CountStringWord(value);
	}



	static string Trim_Left_String(string t1) {
		short c = 0;
		for (short i = 0; i < t1.length(); i++)
		{
			if (t1[i] != ' ') {
				return t1.substr(i, t1.length() - i);
			}
		}
		return "";
	}

	void Trim_Left_String() {
		value = Trim_Left_String(value);
	}

	static string Trim_Right_String(string t1) {
		short c = 0;
		for (short i = t1.length() - 1; i >= 0; i--)
		{
			if (t1[i] != ' ') {
				return t1.substr(0, i + 1);
			}
		}
		return "";
	}

	void Trim_Right_String() {

		value = Trim_Right_String(value);
	}

	static string Trim(string t1) {
		return Trim_Left_String(Trim_Right_String(t1));
	}

	void Trim() {
		value = Trim_Left_String(Trim_Right_String(value));
	}




	static bool isVowel(char let) {
		let = tolower(let);
		return (let == 'a')
			? true : (let == 'e')
			? true : (let == 'i')
			? true : (let == 'o')
			? true : (let == 'u')
			? true : false;
	}
	static short CountVowels(string text) {
		short c = 0;
		for (short i = 0; i < text.length(); i++)
		{
			if (isVowel(text[i])) {
				c++;
			}
		}
		return c;
	}

	void CountVowels() {
		value = CountVowels(value);
	}

	static string ReverseWords(string words) {
		string buildReverseWords = "";
		vector<string>vSplit = split(words, " ");
		vector<string>::iterator iter1 = vSplit.end() - 1;


		while (iter1 != vSplit.begin())
		{
			//ex:mohamed eissa abd ekmaksod
			buildReverseWords += *iter1 + " ";
			--iter1;
		}


		return buildReverseWords.substr(0, buildReverseWords.length() - 1);
	}
	void ReverseWords() {
		value = ReverseWords(value);
	}

	static short CountLetter(string t1, char let, bool Match = true) {

		short c = 0;
		for (short i = 0; i < t1.length(); i++)
		{

			if (Match) {
				if (let == t1[i])c++;
			}
			else
			{
				if (toupper(t1.at(i)) == toupper(let))c++;
			}
		}
		return c;
	}

	short CountLetter(char let, bool Match = true) {
		return CountLetter(value, let, Match);
	}

	void invertLetter(char& let) {
		if (islower(let))let = toupper(let);
		else let = tolower(let);
	}
	static string convertVectorToString(vector<string> vString) {
		string builder = "";
		for (vector<string>::iterator it = vString.begin(); it != vString.end() - 1; it++)
		{
			builder += *it + " ";
		}
		return builder.substr(0, builder.length() - 1);
	}

	static string FindAndRepalceWord(string words, string to_repalce, string replace) {

		short word_to_replaceCount = to_repalce.length();

		vector<string> vSplit = split(words, " ");

		string builder = "";

		for (vector<string>::iterator it = vSplit.begin(); it != vSplit.end() - 1; it++)
		{
			if (to_repalce == *it) {

				*it = replace;

			}
		}


		return convertVectorToString(vSplit);
	}

	void FindAndRepalceWord(string to_repalce, string replace) {
		value = FindAndRepalceWord(value, to_repalce, replace);
	}


	static unsigned short Length(string t1) {
		return t1.length();
	}

	unsigned short Length() {
		return Length(value);
	}

	static string replaceWordStringUsingBuiltInFun(string text, string StringToReplace, string sReplace) {

		short pos = text.find(StringToReplace);
		while (pos != string::npos)
		{
			text = text.replace(pos, StringToReplace.length(), sReplace);
			pos = text.find(StringToReplace);
		}
		return text;
	}

	void replaceWordStringUsingBuiltInFun(string StringToReplace, string sReplace) {
		value = replaceWordStringUsingBuiltInFun(value, StringToReplace, sReplace);
	}

	bool isMatchCase(string text)
	{
		short c = 0, c2 = 0;
		for (short i = 0; i < text.length(); i++)
		{
			if (isupper(text.at(i)))++c;//Mohammed
			else
			{
				++c2;
			}
		}
		if (c == text.length() || c2 == text.length())//Mohamed
			return true;
		else
			return false;
	}



	static string UpperAllString(string s1) {
		for (short i = 0; i < s1.length(); i++)
		{
			s1.at(i) = toupper(s1.at(i));
		}
		return s1;
	}

	void UpperAllString() {
		value = UpperAllString(value);
	}

	static string joinString(string vJoin[], short arrLength, string sebreter) {
		string join = "";
		for (short i = 0; i < arrLength; i++)
		{
			join += vJoin[i] + sebreter;
		}
		join.erase(join.length() - sebreter.length(), join.length());
		return join;
	}

	static string joinString(vector<string> vJoin, string sebreter) {
		string join = "";
		for (string& item : vJoin) {
			join += item + sebreter;
		}
		join.erase(join.length() - sebreter.length(), join.length());
		return join;

	}

	void joinString(string sebreter)
	{
		value = joinString(split(value, sebreter), sebreter);
	}
	static string CustomReplaceWordsInTheString(string text, string StringToReplace, string sReplace, bool matchCase = true) {

		vector<string> vSplit = split(text, " ");

		for (string& s : vSplit)
		{
			if (matchCase) {
				if (s == StringToReplace) {
					s = sReplace;
				}
			}
			else
			{
				if (UpperAllString(s) == UpperAllString(StringToReplace)) {
					s = sReplace;
				}
			}
		}
		return joinString(vSplit, " ");

	}

	void CustomReplaceWordsInTheString(string StringToReplace, string sReplace, bool matchCase = true) {
		value = CustomReplaceWordsInTheString(value, StringToReplace, sReplace, matchCase);
	}


	static string RemovePunctuations(string s1) {
		string builder = "";
		for (short i = 0; i < s1.length(); i++)
		{
			if (!ispunct(s1[i])) {//
				builder += s1[i];
			}

		}
		return builder;
	}

	void RemovePunctuations() {
		value = RemovePunctuations(value);
	}


	static string getAllDigits(string t1)
	{
		string Numbers = "";
		for (size_t i = 0; i < t1.length(); i++)
		{
			if (isDigit(t1[i]))
				Numbers += t1[i];
			Numbers += " ";
		}
		return Numbers;
	}
	void getAllDigits() {
		value = getAllDigits(value);
	}

	~clsString() {
		delete[]CharArr;
	}

};

