#include <iostream>
#include <string>
#include <fstream>

class BinaryStream{
	std::fstream m_File;
public:
	BinaryStream();
	bool open(std::string fileName, std::string operation);
	void close();

	void write_string(const std::string&);
	std::string read_string();

	void write_bool(const bool&);
	bool read_bool();

	void write_int32(const int&);
	int read_int32();
	
	void write_int16(const short&);
	short read_int16();
};