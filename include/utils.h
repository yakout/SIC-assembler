//
// Created by Ahmed Yakout on 5/11/17.
//

#ifndef SIC_ASSEMBLER_UTILS_H__
#define SIC_ASSEMBLER_UTILS_H__

namespace utils {
	/**
	 * Since c++11 doesn't have make_unique() implementation, this is very simple one to use.
	 * make_unique() is available in c++14.
	 */
	template<typename T, typename ...Args>
	std::unique_ptr<T> make_unique( Args&& ...args ) {
		return std::unique_ptr<T>( new T( std::forward<Args>(args)... ) );
	}

}

#endif // SIC_ASSEMBLER_UTILS_H__



