//
// Created by Ahmed Yakout on 5/9/17.
//

#ifndef SIC_ASSEMBLER_ASSEMBLER_DRIVER_H__
#define SIC_ASSEMBLER_ASSEMBLER_DRIVER_H__

#include <string>

class assembler_driver {
private:
	static const std::string SOURCE_FILE_EXTENSION;
	static const std::string LISTING_FILE_EXTENSION;
	static const std::string ITERMEDIATE_FILE_EXTENSION;

	std::string file_name;
	std::string file_path;
public:
	assembler_driver(std::string, std::string);
	~assembler_driver();

	void assemble();
};


#endif // SIC_ASSEMBLER_ASSEMBLER_DRIVER_H__