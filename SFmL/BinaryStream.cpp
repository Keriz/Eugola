#include "BinaryStream.h"

using namespace std;

BinaryStream::BinaryStream()
{

}

bool BinaryStream::open(string fileName, string operation)
{
	if (operation == "w")
	{
		m_File.open(fileName, ios::out | ios::app | ios::binary);
	}

	else if (operation == "r")
	{
		m_File.open(fileName, ios::in | ios::binary);
	}

	return m_File.is_open();
}

void BinaryStream::write_string(const string& str)
{
	char len = str.size();
	m_File.write(reinterpret_cast<const char*>(&len), sizeof(len));
	m_File.write(str.c_str(),len);
}

string BinaryStream::read_string()
{
	string str;

	char len;
	m_File.read(reinterpret_cast<char*>( &len ), sizeof(len) );
	if (len > 0)
	{
		char* buf = new char[len];
		m_File.read(buf,len);
		str.append(buf,len);
		delete[] buf;
	}
	return str;
}

void BinaryStream::write_bool(const bool& bo)
{
	m_File.write((char*)&bo,sizeof(bool));
}

bool BinaryStream::read_bool()
{
	bool bo;

	m_File.read(reinterpret_cast<char*>( &bo ), sizeof(bool) );

	return bo;
}

void BinaryStream::write_int32(const int& int32)
{
	m_File.write((char*)&int32,sizeof(int));
}

int BinaryStream::read_int32()
{
	int int32;

	m_File.read(reinterpret_cast<char*>( &int32 ), sizeof(int) );

	return int32;
}

void BinaryStream::write_int16(const short& int16)
{
	m_File.write((char*)&int16,sizeof(short));
}

short BinaryStream::read_int16()
{
	short int16;

	m_File.read(reinterpret_cast<char*>( &int16 ), sizeof(short) );

	return int16;
}

void BinaryStream::close()
{
	m_File.close();
}