#include "MyUtility.h"

//��õ�ǰϵͳʱ��
string MyUtility::getCurrentTime(){
	time_t t;
	time(&t);
	char tmp[64];
	strftime(tmp, sizeof(tmp), "%Y-%m-%d %x", localtime((&t)));
	string timeStr  =  tmp;
	return timeStr;
}

//��Win32ƽ̨�£���GBK����ת��ΪUTF-8
string MyUtility::gbk_2_utf8(const string text){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) //��������
	//�������õ�һЩ��ֻ��win32ƽ̨���е�һЩ���

	//����Lambda���ʽ����stringת����wstring
	wstring tes = [=](){
		setlocale(LC_ALL, "chs");
		const char* _Source = text.c_str();
		size_t _Dsize = text.size() + 1;
		wchar_t *_Dest = new wchar_t[_Dsize];
		mbstowcs(_Dest, _Source, _Dsize);
		std::wstring result = _Dest;
		delete[]_Dest;
		setlocale(LC_ALL, "C");
		return result;
	}();

	int asciSize = WideCharToMultiByte(CP_UTF8, 0, tes.c_str(), tes.size(), NULL, 0, NULL, NULL);
	if(asciSize == ERROR_NO_UNICODE_TRANSLATION || asciSize==0){
		return string();
	}

	char *resultString = new char[asciSize];
	int conveResult = WideCharToMultiByte(CP_UTF8, 0, tes.c_str(), tes.size(), resultString, asciSize, NULL, NULL);
	if (conveResult != asciSize){
		return string();
	}
	string buffer = "";
	buffer.append(resultString,asciSize);
	delete[] resultString;
	return buffer;
#else
	return text;
#endif
}